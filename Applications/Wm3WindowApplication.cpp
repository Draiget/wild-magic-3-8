// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#include "Wm3ApplicationPCH.h"
#include "Wm3WindowApplication.h"
using namespace Wm3;

//----------------------------------------------------------------------------
WindowApplication::WindowApplication (const char* acWindowTitle,
    int iXPosition, int iYPosition, int iWidth, int iHeight,
    const ColorRGB& rkBackgroundColor)
    :
    m_acWindowTitle(acWindowTitle),
    m_iXPosition(iXPosition),
    m_iYPosition(iYPosition),
    m_iWidth(iWidth),
    m_iHeight(iHeight),
    m_kBackgroundColor(rkBackgroundColor)
{
    m_iWindowID = 0;
    m_pkRenderer = 0;
}
//----------------------------------------------------------------------------
WindowApplication::~WindowApplication ()
{
}
//----------------------------------------------------------------------------
int WindowApplication::Run (int iQuantity, char** apcArgument)
{
    WindowApplication* pkTheApp = (WindowApplication*)TheApplication;
    return pkTheApp->Main(iQuantity,apcArgument);
}
//----------------------------------------------------------------------------
bool WindowApplication::OnInitialize ()
{
    m_pkRenderer->SetBackgroundColor(m_kBackgroundColor);
    return true;
}
//----------------------------------------------------------------------------
void WindowApplication::OnTerminate ()
{
    WM3_DELETE m_pkRenderer;
    m_pkRenderer = 0;
}
//----------------------------------------------------------------------------
void WindowApplication::OnMove (int iX, int iY)
{
    m_iXPosition = iX;
    m_iYPosition = iY;
}
//----------------------------------------------------------------------------
void WindowApplication::OnResize (int iWidth, int iHeight)
{
    if (iWidth > 0 && iHeight > 0)
    {
        if (m_pkRenderer)
        {
            m_pkRenderer->Resize(iWidth,iHeight);
        }

        m_iWidth = iWidth;
        m_iHeight = iHeight;
    }
}
//----------------------------------------------------------------------------

