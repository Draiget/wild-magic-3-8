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
#include "Wm3GlxRenderer.h"
#include "Wm3GlxPBuffer.h"
#include "Wm3GlxBitmapFont.h"
using namespace Wm3;

//----------------------------------------------------------------------------
GlxRenderer::GlxRenderer (Display* pkDisplay,
    const BufferParams& rkBufferParams, int iWidth, int iHeight)
    :
    OpenGLRenderer(rkBufferParams,iWidth,iHeight)
{
    assert(m_iWidth > 0 && m_iHeight > 0);
    if (m_iWidth <= 0 || m_iHeight <= 0)
    {
        m_bIsConstructed = false;
        return;
    }

    m_pkDisplay = pkDisplay;
    m_ulWindow = 0;  // set by the application after window creation
    m_iWidth = iWidth;
    m_iHeight = iHeight;
    m_iSaveWidth = m_iWidth;
    m_iSaveHeight = m_iHeight;

    // Select the attributes for the frame buffer.
    int aiAttributes[256];

    // The color buffer is RGBA888 on Linux, but RGB888 on SGI.
    int iPos = 0;
    aiAttributes[iPos++] = GLX_RGBA;
#ifndef __sgi
    aiAttributes[iPos++] = GLX_RED_SIZE;
    aiAttributes[iPos++] = 8;
    aiAttributes[iPos++] = GLX_GREEN_SIZE;
    aiAttributes[iPos++] = 8;
    aiAttributes[iPos++] = GLX_BLUE_SIZE;
    aiAttributes[iPos++] = 8;
    aiAttributes[iPos++] = GLX_ALPHA_SIZE;
    aiAttributes[iPos++] = 8;
#else
    aiAttributes[iPos++] = GLX_RED_SIZE;
    aiAttributes[iPos++] = 1;
    aiAttributes[iPos++] = GLX_GREEN_SIZE;
    aiAttributes[iPos++] = 1;
    aiAttributes[iPos++] = GLX_BLUE_SIZE;
    aiAttributes[iPos++] = 1;
#endif

    // Request a depth buffer.
    if (m_kBufferParams.Depth != BufferParams::BP_DEPTH_NONE)
    {
        aiAttributes[iPos++] = GLX_DEPTH_SIZE;
#ifndef __sgi
        if (m_kBufferParams.Depth == BufferParams::BP_DEPTH_16)
        {
            aiAttributes[iPos++] = 16;
        }
        else if (m_kBufferParams.Depth == BufferParams::BP_DEPTH_24)
        {
            aiAttributes[iPos++] = 24;
        }
        else // m_kBufferParams.Depth == BufferParams::BP_DEPTH_32
        {
            aiAttributes[iPos++] = 32;
        }
#else
        aiAttributes[iPos++] = 12;
#endif
    }

#ifndef __sgi
    // Request a stencil buffer.
    if (m_kBufferParams.Stencil == BufferParams::BP_STENCIL_8)
    {
        aiAttributes[iPos++] = GLX_STENCIL_SIZE;
        aiAttributes[iPos++] = 8;
    }
#endif

    // Request buffering.
    if (m_kBufferParams.Buffering == BufferParams::BP_BUFFERED_DOUBLE)
    {
        aiAttributes[iPos++] = GLX_DOUBLEBUFFER;
#ifndef __sgi
        aiAttributes[iPos++] = 1;
#endif
    }

    // Request sampling.
    if (m_kBufferParams.Sampling != BufferParams::BP_SAMPLING_NONE)
    {
        aiAttributes[iPos++] = GLX_SAMPLE_BUFFERS_ARB;
        aiAttributes[iPos++] = 1;
        aiAttributes[iPos++] = GLX_SAMPLES_ARB;
        if (m_kBufferParams.Sampling == BufferParams::BP_SAMPLING_2)
        {
            aiAttributes[iPos++] = 2;
        }
        else  // m_kBufferParams.Sampling == BufferParams::BP_SAMPLING_4
        {
            aiAttributes[iPos++] = 4;
        }
    }

    // Currently no support for render-to-texture on GLX.
    m_kBufferParams.TextureTarget = BufferParams::BP_TEXTURE_TARGET_NONE;

    // The list is zero terminated.
    aiAttributes[iPos] = 0;

    // Get an OpenGL-capable visual.
    int iScreen = DefaultScreen(m_pkDisplay);
    m_pkVisual = glXChooseVisual(m_pkDisplay,iScreen,aiAttributes);
    assert(m_pkVisual);
    if (!m_pkVisual)
    {
        m_pkDisplay = 0;
        m_pkVisual = 0;
        m_ulWindow = 0;
        m_kContext = 0;
        m_bIsConstructed = false;
        return;
    }

    // Create an OpenGL rendering context.
    GLXContext kSharedList = 0;
    Bool bDirectRender = True;
    m_kContext = glXCreateContext(m_pkDisplay,m_pkVisual,kSharedList,
        bDirectRender);
    if (!m_kContext)
    {
        m_pkDisplay = 0;
        m_pkVisual = 0;
        m_ulWindow = 0;
        m_kContext = 0;
        m_bIsConstructed = false;
        return;
    }

    m_bIsConstructed = true;
}
//----------------------------------------------------------------------------
void GlxRenderer::FinishConstruction (Window ulWindow)
{
    // Bind the rendering context to the window.
    m_ulWindow = ulWindow;
    if (!glXMakeCurrent(m_pkDisplay,m_ulWindow,m_kContext))
    {
        m_bIsConstructed = false;
    }

    InitializeOpenGL();
    InitializeGlx();
    InitializeState();
}
//----------------------------------------------------------------------------
void GlxRenderer::ToggleFullscreen ()
{
    // TO DO.  How to make full screen GLX window?

    //OpenGLRenderer::ToggleFullscreen();
    //
    //if ( m_bFullscreen )
    //{
    //    m_iSaveWidth = m_iWidth;
    //    m_iSaveHeight = m_iHeight;
    //    glutFullScreen();
    //}
    //else
    //{
    //    glutPositionWindow(24,24);
    //    glutReshapeWindow(m_iSaveWidth,m_iSaveHeight);
    //    Resize(m_iSaveWidth,m_iSaveHeight);
    //}
}
//----------------------------------------------------------------------------
void GlxRenderer::DisplayBackBuffer ()
{
    glXSwapBuffers(m_pkDisplay,m_ulWindow);
}
//----------------------------------------------------------------------------
void GlxRenderer::DrawCharacter (const BitmapFont& rkFont, char cChar)
{
    unsigned int uiIndex = (unsigned int)cChar;
    const BitmapFontChar* pkBFC = rkFont.Chars[uiIndex];

    // save unpack state
    GLint iSwapBytes, iLSBFirst, iRowLength, iSkipRows, iSkipPixels;
    GLint iAlignment;
    glGetIntegerv(GL_UNPACK_SWAP_BYTES,&iSwapBytes);
    glGetIntegerv(GL_UNPACK_LSB_FIRST,&iLSBFirst);
    glGetIntegerv(GL_UNPACK_ROW_LENGTH,&iRowLength);
    glGetIntegerv(GL_UNPACK_SKIP_ROWS,&iSkipRows);
    glGetIntegerv(GL_UNPACK_SKIP_PIXELS,&iSkipPixels);
    glGetIntegerv(GL_UNPACK_ALIGNMENT,&iAlignment);

    glPixelStorei(GL_UNPACK_SWAP_BYTES,GL_FALSE);
    glPixelStorei(GL_UNPACK_LSB_FIRST,GL_FALSE);
    glPixelStorei(GL_UNPACK_ROW_LENGTH,0);
    glPixelStorei(GL_UNPACK_SKIP_ROWS,0);
    glPixelStorei(GL_UNPACK_SKIP_PIXELS,0);
    glPixelStorei(GL_UNPACK_ALIGNMENT,1);
    glBitmap(pkBFC->XSize,pkBFC->YSize,(float)pkBFC->XOrigin,
        (float)pkBFC->YOrigin,(float)pkBFC->XSize,0.0f,
        (const GLubyte*)pkBFC->Bitmap);

    // restore unpack state
    glPixelStorei(GL_UNPACK_SWAP_BYTES,iSwapBytes);
    glPixelStorei(GL_UNPACK_LSB_FIRST,iLSBFirst);
    glPixelStorei(GL_UNPACK_ROW_LENGTH,iRowLength);
    glPixelStorei(GL_UNPACK_SKIP_ROWS,iSkipRows);
    glPixelStorei(GL_UNPACK_SKIP_PIXELS,iSkipPixels);
    glPixelStorei(GL_UNPACK_ALIGNMENT,iAlignment);
}
//----------------------------------------------------------------------------
void GlxRenderer::Draw (int iX, int iY, const ColorRGBA& rkColor,
    const char* acText)
{
    assert(acText);

    // switch to orthogonal view
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    glOrtho(-0.5f,m_iWidth-0.5f,-0.5f,m_iHeight-0.5f,-1.0f,1.0f);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();

    // disable depth, lighting, and texturing
    GLboolean bDepthTest = glIsEnabled(GL_DEPTH_TEST);
    GLboolean bLighting = glIsEnabled(GL_LIGHTING);
    GLboolean bTexture2D = glIsEnabled(GL_TEXTURE_2D);
    if (bDepthTest)
    {
        glDisable(GL_DEPTH_TEST);
    }
    if (bLighting)
    {
        glDisable(GL_LIGHTING);
    }
    if (bTexture2D)
    {
        glDisable(GL_TEXTURE_2D);
    }

    // set the text color
    glColor4fv((const float*)rkColor);

    // draw text string (use right-handed coordinates)
    glRasterPos3i(iX,m_iHeight-1-iY,0);
    int iLength = (int)strlen(acText);
    for (int i = 0; i < iLength; i++)
    {
        DrawCharacter(g_kVerdana_S16B0I0,acText[i]);
    }

    // restore depth, lighting, and texturing
    if (bDepthTest)
    {
        glEnable(GL_DEPTH_TEST);
    }
    if (bLighting)
    {
        glEnable(GL_LIGHTING);
    }
    if (bTexture2D)
    {
        glEnable(GL_TEXTURE_2D);
    }

    // restore matrices
    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);

    // restore projective view
    OnFrustumChange();
}
//----------------------------------------------------------------------------
