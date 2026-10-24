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
#include "Wm3GlxPBuffer.h"
#include "Wm3GlxRenderer.h"
using namespace Wm3;

WM3_IMPLEMENT_INITIALIZE(GlxPBuffer);

//----------------------------------------------------------------------------
void GlxPBuffer::Initialize ()
{
    ms_oCreate = &GlxPBuffer::Create;
    ms_oDestroy = &GlxPBuffer::Destroy;
}
//----------------------------------------------------------------------------
PBuffer* GlxPBuffer::Create (const BufferParams& rkBufferParams, int iWidth,
    int iHeight, Renderer* pkRenderer)
{
    // Check to see if the pbuffer extensions are supported.
    if ( Wm3Exists_GLX_VERSION_1_3 != WM3_EXT_FULLY_EXISTS
    ||   Wm3Exists_GLX_SGIX_fbconfig != WM3_EXT_FULLY_EXISTS )
    {
        return 0;
    }

    if ( iWidth > 0 && iHeight > 0 && pkRenderer )
    {
        GlxPBuffer* pkBuffer = WM3_NEW GlxPBuffer(rkBufferParams,iWidth,
            iHeight,pkRenderer);

        if ( pkBuffer->InitializeBuffer() )
            return pkBuffer;

        WM3_DELETE pkBuffer;
    }
    return 0;
}
//----------------------------------------------------------------------------
void GlxPBuffer::Destroy (PBuffer* pkBuffer)
{
    ((GlxPBuffer*)pkBuffer)->TerminateBuffer();
    WM3_DELETE pkBuffer;
}
//----------------------------------------------------------------------------
GlxPBuffer::GlxPBuffer (const BufferParams& rkBufferParams, int iWidth,
    int iHeight, Renderer* pkRenderer)
    :
    PBuffer(rkBufferParams,iWidth,iHeight,pkRenderer)
{
    m_hPBuffer = 0;
    m_pkDisplay = 0;
    m_pkContext = 0;
}
//----------------------------------------------------------------------------
GlxPBuffer::~GlxPBuffer ()
{
}
//----------------------------------------------------------------------------
bool GlxPBuffer::InitializeBuffer ()
{
    // Get the display and screen information associated with the renderer.
    GlxRenderer* pkRenderer = (GlxRenderer*)m_pkRenderer;
    m_pkDisplay = pkRenderer->GetDisplay();
    int iScreen = DefaultScreen(m_pkDisplay);

    // Set the pbuffer's attributes.
    int aiBAttributes[256];
    int iPos = 0;
    aiBAttributes[iPos++] = GLX_WIDTH;
    aiBAttributes[iPos++] = m_iWidth;
    aiBAttributes[iPos++] = GLX_HEIGHT;
    aiBAttributes[iPos++] = m_iHeight;
    aiBAttributes[iPos]   = 0;  // list is zero terminated

    // Create a pbuffer from 'scratch'.
    int aiFAttributes[256];
    iPos = 0;
    aiFAttributes[iPos++] = GLX_DRAWABLE_TYPE;
    aiFAttributes[iPos++] = GLX_PBUFFER_BIT;
    aiFAttributes[iPos++] = GLX_RENDER_TYPE;
    aiFAttributes[iPos++] = GLX_RGBA_BIT;

    // The color buffer is RGBA8888.
    aiFAttributes[iPos++] = GLX_RED_SIZE;
    aiFAttributes[iPos++] = 8;
    aiFAttributes[iPos++] = GLX_GREEN_SIZE;
    aiFAttributes[iPos++] = 8;
    aiFAttributes[iPos++] = GLX_BLUE_SIZE;
    aiFAttributes[iPos++] = 8;
    aiFAttributes[iPos++] = GLX_ALPHA_SIZE;
    aiFAttributes[iPos++] = 8;

    // Request a depth buffer.
    if ( m_kBufferParams.Depth != BufferParams::BP_DEPTH_NONE )
    {
        aiFAttributes[iPos++] = GLX_DEPTH_SIZE;
        if ( m_kBufferParams.Depth == BufferParams::BP_DEPTH_16 )
            aiFAttributes[iPos++] = 16;
        else if ( m_kBufferParams.Depth == BufferParams::BP_DEPTH_24 )
            aiFAttributes[iPos++] = 24;
        else // m_kBufferParams.Depth == BufferParams::BP_DEPTH_32
            aiFAttributes[iPos++] = 32;
    }

    // Request a stencil buffer.
    if ( m_kBufferParams.Stencil == BufferParams::BP_STENCIL_8 )
    {
        aiFAttributes[iPos++] = GLX_STENCIL_SIZE;
        aiFAttributes[iPos++] = 8;
    }

    // Request buffering.
    if ( m_kBufferParams.Buffering == BufferParams::BP_BUFFERED_DOUBLE )
    {
        aiFAttributes[iPos++] = GLX_DOUBLEBUFFER;
        aiFAttributes[iPos++] = 1;
    }

    // Request sampling.
    if ( m_kBufferParams.Sampling != BufferParams::BP_SAMPLING_NONE )
    {
        aiFAttributes[iPos++] = GLX_SAMPLE_BUFFERS_ARB;
        aiFAttributes[iPos++] = 1;
        aiFAttributes[iPos++] = GLX_SAMPLES_ARB;
        if ( m_kBufferParams.Sampling == BufferParams::BP_SAMPLING_2 )
            aiFAttributes[iPos++] = 2;
        else  // m_kBufferParams.Sampling == BufferParams::BP_SAMPLING_4
            aiFAttributes[iPos++] = 4;
    }

    // Currently no support for render-to-texture on GLX.
    m_kBufferParams.TextureTarget = BufferParams::BP_TEXTURE_TARGET_NONE;

    // The list is zero terminated.
    aiFAttributes[iPos] = 0;

    int iConfigCount;
    GLXFBConfigSGIX* akConfig = glXChooseFBConfigSGIX(m_pkDisplay,iScreen,
        aiFAttributes,&iConfigCount);
    if ( !akConfig || iConfigCount <= 0 )
        return false;

    // Create the context.
    m_pkContext = glXCreateContextWithConfigSGIX(m_pkDisplay,akConfig[0],
        GLX_RGBA_TYPE,pkRenderer->GetContext(),True);
    if ( !m_pkContext )
        return false;

    // Create the pbuffer.
    m_hPBuffer = glXCreateGLXPbufferSGIX(m_pkDisplay,akConfig[0],m_iWidth,
        m_iHeight,aiBAttributes);
    if ( !m_hPBuffer )
        return false;

    // Verify the the pbuffer has the requested width and height.
    unsigned int uiWidth, uiHeight;
    glXQueryGLXPbufferSGIX(m_pkDisplay,m_hPBuffer,GLX_WIDTH,&uiWidth);
    glXQueryGLXPbufferSGIX(m_pkDisplay,m_hPBuffer,GLX_HEIGHT,&uiHeight);
    if ( (int)uiWidth != m_iWidth || (int)uiHeight != m_iHeight )
        return false;

    // Initialize some pbuffer state.
    glXMakeCurrent(m_pkDisplay,m_hPBuffer,m_pkContext);
    pkRenderer->InitializeState();
    glDrawBuffer(GL_FRONT);
    glReadBuffer(GL_FRONT);
    glViewport(0,0,m_iWidth,m_iHeight);
    pkRenderer->OnFrustumChange ();
    pkRenderer->OnFrameChange ();

    // Make the main renderer current.
    glXMakeCurrent(pkRenderer->GetDisplay(),pkRenderer->GetWindow(),
        pkRenderer->GetContext());
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
void GlxPBuffer::TerminateBuffer ()
{
    assert( m_pkDisplay && m_pkContext && m_hPBuffer );

    m_pkRenderer->ReleaseTexture(m_pkTarget);

    glXDestroyContext(m_pkDisplay,m_pkContext);
    glXDestroyGLXPbufferSGIX(m_pkDisplay,m_hPBuffer);
}
//----------------------------------------------------------------------------
void GlxPBuffer::Enable ()
{
    // Set the pbuffer's context to be the current one.
    if ( glXMakeCurrent(m_pkDisplay,m_hPBuffer,m_pkContext) )
    {
        GlxRenderer* pkRenderer = (GlxRenderer*)m_pkRenderer;
        glDrawBuffer(GL_FRONT);
        glViewport(0,0,m_iWidth,m_iHeight);
        pkRenderer->OnFrustumChange();
        pkRenderer->OnFrameChange();
    }
}
//----------------------------------------------------------------------------
void GlxPBuffer::Disable ()
{
    // Set the back buffer's context to be the current one.
    GlxRenderer* pkRenderer = (GlxRenderer*)m_pkRenderer;
    Display* pkDisplay = pkRenderer->GetDisplay();
    GLXDrawable ulWindow = pkRenderer->GetWindow();
    GLXContext kContext = pkRenderer->GetContext();
    if ( glXMakeCurrent(pkDisplay,ulWindow,kContext) )
    {
        glDrawBuffer(GL_BACK);
        pkRenderer->InitializeState();
        pkRenderer->OnViewPortChange();
        pkRenderer->OnFrustumChange ();
        pkRenderer->OnFrameChange ();
    }
}
//----------------------------------------------------------------------------
void GlxPBuffer::Bind ()
{
    // The GLX renderer does not currently support render to texture.
}
//----------------------------------------------------------------------------
void GlxPBuffer::Release ()
{
    // The GLX renderer does not currently support render to texture.
}
//----------------------------------------------------------------------------
void GlxPBuffer::CopyToTarget (bool bRelease) const
{
    PBuffer::CopyToTarget(bRelease);
    unsigned char* aucData = m_pkTarget->GetImage()->GetData();
    glReadPixels(0,0,m_iWidth,m_iHeight,GL_RGBA,GL_UNSIGNED_BYTE,
        (void*)aucData);
}
//----------------------------------------------------------------------------
GLXPbuffer GlxPBuffer::GetPBuffer ()
{
    return m_hPBuffer;
}
//----------------------------------------------------------------------------
Display* GlxPBuffer::GetDisplay ()
{
    return m_pkDisplay;
}
//----------------------------------------------------------------------------
GLXContext GlxPBuffer::GetContext ()
{
    return m_pkContext;
}
//----------------------------------------------------------------------------


