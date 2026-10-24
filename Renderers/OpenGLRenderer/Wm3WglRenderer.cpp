// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#include "Wm3OpenGLRendererPCH.h"
#include "Wm3WglRenderer.h"
#include "Wm3WglPBuffer.h"
using namespace Wm3;

//----------------------------------------------------------------------------
WglRenderer::WglRenderer (HWND hWnd, const BufferParams& rkBufferParams,
    int iWidth, int iHeight, int iPixelFormat)
    :
    OpenGLRenderer(rkBufferParams,iWidth,iHeight)
{
    assert(m_iWidth > 0 && m_iHeight > 0);
    m_iSaveWidth = m_iWidth;
    m_iSaveHeight = m_iHeight;

    m_hWnd = hWnd;
    m_hWindowDC = ::GetDC(m_hWnd);

    // select format for drawing surface
    PIXELFORMATDESCRIPTOR kPFD;
    memset(&kPFD,0,sizeof(PIXELFORMATDESCRIPTOR));
    kPFD.nSize = sizeof(PIXELFORMATDESCRIPTOR);
    kPFD.nVersion = 1;
    kPFD.dwFlags =
        PFD_DRAW_TO_WINDOW |
        PFD_SUPPORT_OPENGL |
        PFD_GENERIC_ACCELERATED;
    if (m_kBufferParams.Buffering == BufferParams::BP_BUFFERED_DOUBLE)
    {
        kPFD.dwFlags |= PFD_DOUBLEBUFFER;
    }

    // m_kBufferParams.Format is ignored, always create 32-bit RGBA buffer
    kPFD.iPixelType = PFD_TYPE_RGBA;
    kPFD.cColorBits = 32;

    switch (m_kBufferParams.Depth)
    {
    case BufferParams::BP_DEPTH_NONE:  kPFD.cDepthBits =  0;  break;
    case BufferParams::BP_DEPTH_16:    kPFD.cDepthBits = 16;  break;
    case BufferParams::BP_DEPTH_24:    kPFD.cDepthBits = 24;  break;
    case BufferParams::BP_DEPTH_32:    kPFD.cDepthBits = 32;  break;
    default:                           kPFD.cDepthBits = 16;  break;
    }

    if (m_kBufferParams.Stencil == BufferParams::BP_STENCIL_8)
    {
        kPFD.cStencilBits = 8;
    }
    else
    {
        kPFD.cStencilBits = 0;
    }

    // set the pixel format for the rendering context
    bool bFirstTime = (iPixelFormat == 0 ? true : false);
    if (bFirstTime)
    {
        // First time creation.  If multisampling is requested, a second
        // creation will occur and the input pixel format will be supplied
        // directly to SetPixelFormat.
        iPixelFormat = ChoosePixelFormat(m_hWindowDC,&kPFD);
        if (iPixelFormat == 0)
        {
            return;
        }
    }

    BOOL bSuccess = SetPixelFormat(m_hWindowDC,iPixelFormat,&kPFD);
    if (!bSuccess)
    {
        return;
    }

    // create an OpenGL context
    m_hWindowRC = wglCreateContext(m_hWindowDC);
    if (!m_hWindowRC)
    {
        return;
    }

    bSuccess = wglMakeCurrent(m_hWindowDC,m_hWindowRC);
    if (!bSuccess)
    {
        return;
    }

    if (bFirstTime)
    {
        // Load the function pointers for the OpenGL extensions.  This only
        // needs to occur once.
        InitializeOpenGL();
        InitializeWgl();
    }

    // disable the wait for vertical sync
    if (wglSwapIntervalEXT)
    {
        wglSwapIntervalEXT(0);
    }

    // use the system font as default
    DisplayListInfo kInfo;
    int iFirstChar = int(' ');
    kInfo.Quantity = 127 - iFirstChar;
    kInfo.Start = glGenLists(kInfo.Quantity);
    kInfo.Base = kInfo.Start - iFirstChar;
    m_kDLInfo.Append(kInfo);
    m_hOldFont = SelectObject(m_hWindowDC,GetStockObject(SYSTEM_FONT)); 
    wglUseFontBitmaps(m_hWindowDC,iFirstChar,kInfo.Quantity,kInfo.Start);

    InitializeState();
}
//----------------------------------------------------------------------------
WglRenderer::~WglRenderer ()
{
    for (int i = 0; i < m_kDLInfo.GetQuantity(); i++)
    {
        DisplayListInfo kInfo = m_kDLInfo[i];
        glDeleteLists(kInfo.Start,kInfo.Quantity);
    }

    if (m_hWindowRC)
    {
        wglDeleteContext(m_hWindowRC);
    }

    if (m_hWindowDC)
    {
        SelectObject(m_hWindowDC,m_hOldFont);
        ReleaseDC(m_hWnd,m_hWindowDC);
    }
}
//----------------------------------------------------------------------------
void WglRenderer::ToggleFullscreen ()
{
    OpenGLRenderer::ToggleFullscreen();
    glFinish();

    DWORD dwStyle = WS_OVERLAPPEDWINDOW | WS_CLIPSIBLINGS | WS_CLIPCHILDREN;

    UINT uiFlags = SWP_NOACTIVATE | SWP_NOOWNERZORDER |
        SWP_NOSENDCHANGING | SWP_NOZORDER;

    RECT kRect;

    if (m_bFullscreen)
    {
        m_iSaveWidth = m_iWidth;
        m_iSaveHeight = m_iHeight;
        GetWindowRect(GetDesktopWindow(),&kRect);
        AdjustWindowRect(&kRect,dwStyle,FALSE);
    }
    else
    {
        m_iWidth = m_iSaveWidth;
        m_iHeight = m_iSaveHeight;

        kRect.left = 0;
        kRect.top = 0;
        kRect.right = m_iWidth-1;
        kRect.bottom = m_iHeight-1;
        AdjustWindowRect(&kRect,dwStyle,FALSE);

        kRect.right -= kRect.left;
        kRect.left = 0;
        kRect.bottom -= kRect.top;
        kRect.top = 0;
    }

    SetWindowPos(m_hWnd,HWND_TOP,kRect.left,kRect.top,
        kRect.right-kRect.left,kRect.bottom-kRect.top,uiFlags);
}
//----------------------------------------------------------------------------
void WglRenderer::DisplayBackBuffer ()
{
    SwapBuffers(m_hWindowDC);
}
//----------------------------------------------------------------------------
int WglRenderer::LoadFont (const char* acFace, int iSize, bool bBold,
    bool bItalic)
{
    int iWeight = (bBold ? FW_BOLD : FW_REGULAR);
        
    HFONT hFont = CreateFont(iSize,0,0,0,iWeight,(DWORD)bItalic,FALSE,
        FALSE,DEFAULT_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,
        ANTIALIASED_QUALITY,VARIABLE_PITCH,acFace);
    
    if (!hFont)
    {
        return -1;
    }

    DisplayListInfo kInfo;
    int iFirstChar = int(' ');
    kInfo.Quantity = 127 - iFirstChar;
    kInfo.Start = glGenLists(kInfo.Quantity) ;
    kInfo.Base = kInfo.Start - iFirstChar;
    m_kDLInfo.Append(kInfo);

    SelectObject(m_hWindowDC,hFont); 
    wglUseFontBitmaps(m_hWindowDC,iFirstChar,kInfo.Quantity,kInfo.Start);
    DeleteObject(hFont);
    return m_kDLInfo.GetQuantity()-1;
}
//----------------------------------------------------------------------------

