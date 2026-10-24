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
#include "Wm3WglPBuffer.h"
#include "Wm3WglRenderer.h"
using namespace Wm3;

WM3_IMPLEMENT_INITIALIZE(WglPBuffer);

//----------------------------------------------------------------------------
void WglPBuffer::Initialize ()
{
    ms_oCreate = &WglPBuffer::Create;
    ms_oDestroy = &WglPBuffer::Destroy;
}
//----------------------------------------------------------------------------
PBuffer* WglPBuffer::Create (const BufferParams& rkBufferParams, int iWidth,
    int iHeight, Renderer* pkRenderer)
{
    // Check to see if the pbuffer and render-to-texture extensions are
    // supported.
    if (Wm3Exists_WGL_ARB_pbuffer != WM3_EXT_FULLY_EXISTS
    ||  Wm3Exists_WGL_ARB_render_texture != WM3_EXT_FULLY_EXISTS)
    {
        return 0;
    }

    if (iWidth > 0 && iHeight > 0 && pkRenderer)
    {
        WglPBuffer* pkBuffer = WM3_NEW WglPBuffer(rkBufferParams,iWidth,
            iHeight,pkRenderer);

        if (pkBuffer->InitializeBuffer())
        {
            return pkBuffer;
        }

        WM3_DELETE pkBuffer;
    }
    return 0;
}
//----------------------------------------------------------------------------
void WglPBuffer::Destroy (PBuffer* pkBuffer)
{
    ((WglPBuffer*)pkBuffer)->TerminateBuffer();
    WM3_DELETE pkBuffer;
}
//----------------------------------------------------------------------------
WglPBuffer::WglPBuffer (const BufferParams& rkBufferParams, int iWidth,
    int iHeight, Renderer* pkRenderer)
    :
    PBuffer(rkBufferParams,iWidth,iHeight,pkRenderer)
{
    m_hPBuffer = 0;
    m_hDC = 0;
    m_hRC = 0;
}
//----------------------------------------------------------------------------
WglPBuffer::~WglPBuffer ()
{
}
//----------------------------------------------------------------------------
bool WglPBuffer::InitializeBuffer ()
{
    WglRenderer* pkRenderer = (WglRenderer*)m_pkRenderer;
    BufferParams::TextureTargetType eTarget = m_kBufferParams.TextureTarget;

    // Set the desired attributes for the pbuffer's pixel format.

    // The pbuffer will be used with OpenGL.
    int aiAttributes[256];
    int iPos = 0;
    aiAttributes[iPos++] = WGL_SUPPORT_OPENGL_ARB;
    aiAttributes[iPos++] = 1;

    // Enable rendering to pbuffers.
    aiAttributes[iPos++] = WGL_DRAW_TO_PBUFFER_ARB;
    aiAttributes[iPos++] = 1;

    // The color buffer is RGBA8888.
    aiAttributes[iPos++] = WGL_PIXEL_TYPE_ARB;
    aiAttributes[iPos++] = WGL_TYPE_RGBA_ARB;
    aiAttributes[iPos++] = WGL_RED_BITS_ARB;
    aiAttributes[iPos++] = 8;
    aiAttributes[iPos++] = WGL_GREEN_BITS_ARB;
    aiAttributes[iPos++] = 8;
    aiAttributes[iPos++] = WGL_BLUE_BITS_ARB;
    aiAttributes[iPos++] = 8;
    aiAttributes[iPos++] = WGL_ALPHA_BITS_ARB;
    aiAttributes[iPos++] = 8;

    // Request a depth buffer.
    if (m_kBufferParams.Depth != BufferParams::BP_DEPTH_NONE)
    {
        aiAttributes[iPos++] = WGL_DEPTH_BITS_ARB;
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
    }

    // Request a stencil buffer.
    if (m_kBufferParams.Stencil == BufferParams::BP_STENCIL_8)
    {
        aiAttributes[iPos++] = WGL_STENCIL_BITS_ARB;
        aiAttributes[iPos++] = 8;
    }

    // Request buffering.
    if (m_kBufferParams.Buffering == BufferParams::BP_BUFFERED_DOUBLE)
    {
        aiAttributes[iPos++] = WGL_DOUBLE_BUFFER_ARB;
        aiAttributes[iPos++] = 1;
    }

    // Request sampling.
    if (m_kBufferParams.Sampling != BufferParams::BP_SAMPLING_NONE)
    {
        aiAttributes[iPos++] = WGL_SAMPLE_BUFFERS_ARB;
        aiAttributes[iPos++] = 1;
        aiAttributes[iPos++] = WGL_SAMPLES_ARB;
        if (m_kBufferParams.Sampling == BufferParams::BP_SAMPLING_2)
        {
            aiAttributes[iPos++] = 2;
        }
        else  // m_kBufferParams.Sampling == BufferParams::BP_SAMPLING_4
        {
            aiAttributes[iPos++] = 4;
        }
    }

    // Use the pbuffer as a texture.
    if (eTarget != BufferParams::BP_TEXTURE_TARGET_NONE)
    {
        aiAttributes[iPos++] = WGL_BIND_TO_TEXTURE_RGBA_ARB;
        aiAttributes[iPos++] = 1;
    }

    // The list is zero terminated.
    aiAttributes[iPos] = 0;

    int iPixelFormat;
    unsigned int uiNumFormats = 0;
    BOOL bSuccessful = wglChoosePixelFormatARB(pkRenderer->GetDC(),
        aiAttributes,0,1,&iPixelFormat,&uiNumFormats);
    assert(bSuccessful);
    if (!bSuccessful)
    {
        return false;
    }
    assert(uiNumFormats > 0);
    if (uiNumFormats == 0)
    {
        return false;
    }

    // Set the pbuffer's attributes.
    iPos = 0;

    // If the requested width and height cannot be satisfied, allocate a
    // different size buffer.
    aiAttributes[iPos++] = WGL_PBUFFER_LARGEST_ARB;
    aiAttributes[iPos++] = 1;

    // Select the texture target.
    if (eTarget != BufferParams::BP_TEXTURE_TARGET_NONE)
    {
        // The texture target is RGBA.
        aiAttributes[iPos++] = WGL_TEXTURE_FORMAT_ARB;
        aiAttributes[iPos++] = WGL_TEXTURE_RGBA_ARB;

        switch (eTarget)
        {
        case BufferParams::BP_TEXTURE_TARGET_2D:
            aiAttributes[iPos++] = WGL_TEXTURE_TARGET_ARB;
            aiAttributes[iPos++] = WGL_TEXTURE_2D_ARB;
            break;
        case BufferParams::BP_TEXTURE_TARGET_2D_MIPMAP:
            aiAttributes[iPos++] = WGL_TEXTURE_TARGET_ARB;
            aiAttributes[iPos++] = WGL_TEXTURE_2D_ARB;
            aiAttributes[iPos++] = WGL_MIPMAP_TEXTURE_ARB;
            aiAttributes[iPos++] = 1;
            break;
        case BufferParams::BP_TEXTURE_TARGET_CUBE:
            aiAttributes[iPos++] = WGL_TEXTURE_TARGET_ARB;
            aiAttributes[iPos++] = WGL_TEXTURE_CUBE_MAP_ARB;
            break;
        case BufferParams::BP_TEXTURE_TARGET_CUBE_MIPMAP:
            aiAttributes[iPos++] = WGL_TEXTURE_TARGET_ARB;
            aiAttributes[iPos++] = WGL_TEXTURE_CUBE_MAP_ARB;
            aiAttributes[iPos++] = WGL_MIPMAP_TEXTURE_ARB;
            aiAttributes[iPos++] = 1;
            break;
        }
    }

    // The list is zero terminated.
    aiAttributes[iPos] = 0;

    // Create the pbuffer.
    m_hPBuffer = wglCreatePbufferARB(pkRenderer->GetDC(),iPixelFormat,
        m_iWidth,m_iHeight,aiAttributes);
    assert(m_hPBuffer);
    if (!m_hPBuffer)
    {
        return false;
    }

    m_hDC = wglGetPbufferDCARB(m_hPBuffer);
    if (!m_hDC)
    {
        wglReleasePbufferDCARB(m_hPBuffer,m_hDC);
        wglDestroyPbufferARB(m_hPBuffer);
        m_hPBuffer = 0;
        return false;
    }

    m_hRC = wglCreateContext(m_hDC);
    if (!m_hRC)
    {
        wglReleasePbufferDCARB(m_hPBuffer,m_hDC);
        wglDestroyPbufferARB(m_hPBuffer);
        m_hPBuffer = 0;
        return false;
    }

    if (!wglShareLists(wglGetCurrentContext(),m_hRC))
    {
        wglDeleteContext(m_hRC);
        wglReleasePbufferDCARB(m_hPBuffer,m_hDC);
        wglDestroyPbufferARB(m_hPBuffer);
        m_hPBuffer = 0;
        return false;
    }

    // Verify the the pbuffer has the requested width and height.
    int iWidth, iHeight;
    wglQueryPbufferARB(m_hPBuffer,WGL_PBUFFER_WIDTH_ARB,&iWidth);
    wglQueryPbufferARB(m_hPBuffer,WGL_PBUFFER_HEIGHT_ARB,&iHeight);
    if (iWidth != m_iWidth || iHeight != m_iHeight)
    {
        wglDeleteContext(m_hRC);
        wglReleasePbufferDCARB(m_hPBuffer,m_hDC);
        wglDestroyPbufferARB(m_hPBuffer);
        m_hPBuffer = 0;
        return false;
    }

    // Initialize some pbuffer state.
    wglMakeCurrent(m_hDC,m_hRC);
    pkRenderer->InitializeState();
    glDrawBuffer(GL_FRONT);
    glReadBuffer(GL_FRONT);
    glViewport(0,0,m_iWidth,m_iHeight);
    pkRenderer->OnFrustumChange ();
    pkRenderer->OnFrameChange ();

    // Make the main renderer current.
    wglMakeCurrent(pkRenderer->GetDC(),pkRenderer->GetRC());
    pkRenderer->OnViewPortChange();
    pkRenderer->OnFrustumChange ();
    pkRenderer->OnFrameChange ();

    // Create the texture for the render target.
    GLuint uiID;
    glGenTextures((GLsizei)1,&uiID);
    m_pkTarget->BIArray.Bind(pkRenderer,sizeof(GLuint),&uiID);
    glBindTexture(GL_TEXTURE_2D,uiID);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,
        pkRenderer->ms_aeTextureFilter[m_pkTarget->Filter]);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,
        pkRenderer->ms_aeTextureMipmap[m_pkTarget->Mipmap]);

    return true;
}
//----------------------------------------------------------------------------
void WglPBuffer::TerminateBuffer ()
{
    assert(m_hPBuffer && m_hDC && m_hRC);

    m_pkRenderer->ReleaseTexture(m_pkTarget);

    wglReleaseTexImageARB(m_hPBuffer, WGL_FRONT_LEFT_ARB);
    wglDeleteContext(m_hRC);
    wglReleasePbufferDCARB(m_hPBuffer,m_hDC);
    wglDestroyPbufferARB(m_hPBuffer);
}
//----------------------------------------------------------------------------
void WglPBuffer::Enable ()
{
    // Set the pbuffer's context to be the current one.
    if (wglMakeCurrent(m_hDC,m_hRC))
    {
        WglRenderer* pkRenderer = (WglRenderer*)m_pkRenderer;
        glDrawBuffer(GL_FRONT);
        glViewport(0,0,m_iWidth,m_iHeight);
        pkRenderer->OnFrustumChange();
        pkRenderer->OnFrameChange();
    }
}
//----------------------------------------------------------------------------
void WglPBuffer::Disable ()
{
    // Set the back buffer's context to be the current one.
    WglRenderer* pkRenderer = (WglRenderer*)m_pkRenderer;
    if (wglMakeCurrent(pkRenderer->m_hWindowDC,pkRenderer->m_hWindowRC))
    {
        glDrawBuffer(GL_BACK);
        pkRenderer->InitializeState();
        pkRenderer->OnViewPortChange();
        pkRenderer->OnFrustumChange ();
        pkRenderer->OnFrameChange ();
    }
}
//----------------------------------------------------------------------------
void WglPBuffer::Bind ()
{
    // Bind the pbuffer to the offscreen texture.
    BufferParams::TextureTargetType eTarget = m_kBufferParams.TextureTarget;
    if (eTarget != BufferParams::BP_TEXTURE_TARGET_NONE)
    {
        WglRenderer* pkRenderer = (WglRenderer*)m_pkRenderer;
        GLuint uiID;
        pkRenderer->m_pkTarget->BIArray.GetID(pkRenderer,sizeof(GLuint),
            &uiID);
        glBindTexture(GL_TEXTURE_2D,uiID);

        wglBindTexImageARB(m_hPBuffer,WGL_FRONT_LEFT_ARB);
    }
}
//----------------------------------------------------------------------------
void WglPBuffer::Release ()
{
    // Release the offscreen texture from the pbuffer.
    BufferParams::TextureTargetType eTarget = m_kBufferParams.TextureTarget;
    if (eTarget != BufferParams::BP_TEXTURE_TARGET_NONE)
    {
        wglReleaseTexImageARB(m_hPBuffer,WGL_FRONT_LEFT_ARB);
    }
}
//----------------------------------------------------------------------------
void WglPBuffer::CopyToTarget (bool bRelease) const
{
    PBuffer::CopyToTarget(bRelease);
    unsigned char* aucData = m_pkTarget->GetImage()->GetData();
    glReadPixels(0,0,m_iWidth,m_iHeight,GL_RGBA,GL_UNSIGNED_BYTE,
        (void*)aucData);
}
//----------------------------------------------------------------------------
HPBUFFERARB WglPBuffer::GetPBuffer ()
{
    return m_hPBuffer;
}
//----------------------------------------------------------------------------
HDC WglPBuffer::GetDC ()
{
    return m_hDC;
}
//----------------------------------------------------------------------------
HGLRC WglPBuffer::GetRC ()
{
    return m_hRC;
}
//----------------------------------------------------------------------------

