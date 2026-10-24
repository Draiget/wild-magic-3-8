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
#include "Wm3AglPBuffer.h"
#include "Wm3AglRenderer.h"
using namespace Wm3;

WM3_IMPLEMENT_INITIALIZE(AglPBuffer);

//----------------------------------------------------------------------------
void AglPBuffer::Initialize ()
{
    ms_oCreate = &AglPBuffer::Create;
    ms_oDestroy = &AglPBuffer::Destroy;
}
//----------------------------------------------------------------------------
PBuffer* AglPBuffer::Create (const BufferParams& rkBufferParams, int iWidth,
    int iHeight, Renderer* pkRenderer)
{
    // PBuffers are supported on Mac OS 10.3 or later.
    if ( !OpenGLRenderer::ExtensionSupported("GL_APPLE_pixel_buffer") )
        return 0;

    if ( iWidth > 0 && iHeight > 0 && pkRenderer )
    {
        AglPBuffer* pkBuffer = WM3_NEW AglPBuffer(rkBufferParams,iWidth,
            iHeight,pkRenderer);

        if ( pkBuffer->InitializeBuffer() )
            return pkBuffer;

        WM3_DELETE pkBuffer;
    }
    return 0;
}
//----------------------------------------------------------------------------
void AglPBuffer::Destroy (PBuffer* pkBuffer)
{
    ((AglPBuffer*)pkBuffer)->TerminateBuffer();
    WM3_DELETE pkBuffer;
}
//----------------------------------------------------------------------------
AglPBuffer::AglPBuffer (const BufferParams& rkBufferParams, int iWidth,
    int iHeight, Renderer* pkRenderer)
    :
    PBuffer(rkBufferParams,iWidth,iHeight,pkRenderer)
{
    m_hDevice = 0;
    m_pkContext = 0;
    m_pkPBuffer = 0;
}
//----------------------------------------------------------------------------
AglPBuffer::~AglPBuffer ()
{
}
//----------------------------------------------------------------------------
bool AglPBuffer::InitializeBuffer ()
{
    AglRenderer* pkRenderer = (AglRenderer*)m_pkRenderer;
    m_hDevice = pkRenderer->GetDevice();

    // Set the desired attributes for the pbuffer's pixel format.
    int aiAttributes[32];
    int iPos = 0;

    aiAttributes[iPos++] = AGL_ACCELERATED;
    aiAttributes[iPos++] = AGL_NO_RECOVERY;

    // The color buffer is RGBA8888.
    aiAttributes[iPos++] = AGL_RGBA;
    aiAttributes[iPos++] = AGL_RED_SIZE;
    aiAttributes[iPos++] = 8;
    aiAttributes[iPos++] = AGL_GREEN_SIZE;
    aiAttributes[iPos++] = 8;
    aiAttributes[iPos++] = AGL_BLUE_SIZE;
    aiAttributes[iPos++] = 8;
    aiAttributes[iPos++] = AGL_ALPHA_SIZE;
    aiAttributes[iPos++] = 8;

    // Request a depth buffer.
    if ( m_kBufferParams.Depth != BufferParams::BP_DEPTH_NONE )
    {
        aiAttributes[iPos++] = AGL_DEPTH_SIZE;
        if ( m_kBufferParams.Depth == BufferParams::BP_DEPTH_16 )
            aiAttributes[iPos++] = 16;
        else if ( m_kBufferParams.Depth == BufferParams::BP_DEPTH_24 )
            aiAttributes[iPos++] = 24;
        else // m_kBufferParams.Depth == BufferParams::BP_DEPTH_32
            aiAttributes[iPos++] = 32;
    }

    // Request a stencil buffer.
    if ( m_kBufferParams.Stencil == BufferParams::BP_STENCIL_8 )
    {
        aiAttributes[iPos++] = AGL_STENCIL_SIZE;
        aiAttributes[iPos++] = 8;
    }

    // Request buffering.
    if ( m_kBufferParams.Buffering == BufferParams::BP_BUFFERED_DOUBLE )
        aiAttributes[iPos++] = AGL_DOUBLEBUFFER;

    // Request sampling.
    if ( m_kBufferParams.Sampling != BufferParams::BP_SAMPLING_NONE )
    {
        aiAttributes[iPos++] = AGL_SAMPLE_BUFFERS_ARB;
        aiAttributes[iPos++] = 1;
        aiAttributes[iPos++] = AGL_SAMPLES_ARB;
        if ( m_kBufferParams.Sampling == BufferParams::BP_SAMPLING_2 )
            aiAttributes[iPos++] = 2;
        else  // m_kBufferParams.Sampling == BufferParams::BP_SAMPLING_4
            aiAttributes[iPos++] = 4;
    }

    // The list is zero terminated.
    aiAttributes[iPos] = AGL_NONE;

    m_kFormat = aglChoosePixelFormat(&m_hDevice,1,aiAttributes);
    if ( !m_kFormat )
    {
        std::cout << "choose pixel format failed" << std::endl;
        return false;
    }

    m_pkContext = aglCreateContext(m_kFormat,pkRenderer->GetContext());
    if ( !m_pkContext )
    {
        std::cout << "create context failed" << std::endl;
        return false;
    }

    // Set up the texture target type.
    GLenum eTarget;
    long lMaxLevel;
    int iTmp = 0;
    switch ( m_kBufferParams.TextureTarget )
    {
    case BufferParams::BP_TEXTURE_TARGET_2D:
        eTarget = GL_TEXTURE_2D;
        lMaxLevel = 0L;
        break;
    case BufferParams::BP_TEXTURE_TARGET_2D_MIPMAP:
        eTarget = GL_TEXTURE_2D;
        iTmp = m_iWidth;
        for (lMaxLevel = 0L; lMaxLevel < 32L; lMaxLevel++)
        {
            if ( iTmp == 1 )
                break;

            iTmp >>= 1;
        }
        break;
    case BufferParams::BP_TEXTURE_TARGET_CUBE:
        eTarget = GL_TEXTURE_CUBE_MAP;
        lMaxLevel = 0;
        break;
    case BufferParams::BP_TEXTURE_TARGET_CUBE_MIPMAP:
        eTarget = GL_TEXTURE_CUBE_MAP;
        for (lMaxLevel = 0L; lMaxLevel < 32L; lMaxLevel++)
        {
            if ( iTmp == 1 )
                break;

            iTmp >>= 1;
        }
        break;
    default:  // BP_TEXTURE_TARGET_NONE
        // TO DO.  If no texture target is desired, it appears AGL does not
        // have the capability to say so in the aglCreatePBuffer call.
        eTarget = GL_TEXTURE_2D;
        lMaxLevel = 0L;
        break;
    }

    if ( !aglCreatePBuffer(m_iWidth,m_iHeight,eTarget,GL_RGBA,lMaxLevel,
        &m_pkPBuffer) )
    {
        std::cout << "create pbuffer failed" << std::endl;
        return false;
    }

    // Initialize some pbuffer state.
    if ( !aglSetCurrentContext(m_pkContext) )
    {
        std::cout << "set pbuffer context failed" << std::endl;
        return false;
    }

    pkRenderer->InitializeState();
    glDrawBuffer(GL_FRONT);
    glReadBuffer(GL_FRONT);
    glViewport(0,0,m_iWidth,m_iHeight);
    pkRenderer->OnFrustumChange ();
    pkRenderer->OnFrameChange ();

    // Make the main renderer current.
    if ( !aglSetCurrentContext(pkRenderer->GetContext()) )
    {
        std::cout << "set main context failed" << std::endl;
        return false;
    }

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
void AglPBuffer::TerminateBuffer ()
{
    assert ( m_hDevice && m_pkContext && m_pkPBuffer );

    m_pkRenderer->ReleaseTexture(m_pkTarget);

    aglDestroyPBuffer(m_pkPBuffer);
    aglDestroyPixelFormat(m_kFormat);
    aglDestroyContext(m_pkContext);
}
//----------------------------------------------------------------------------
void AglPBuffer::Enable ()
{
    // Set the pbuffer's context to be the current one.
    if ( aglSetCurrentContext(m_pkContext) )
    {
        AglRenderer* pkRenderer = (AglRenderer*)m_pkRenderer;
        GLint iFace = 0;
        GLint iLevel = 0;
        GLint iScreen = aglGetVirtualScreen(pkRenderer->GetContext());
        if ( aglSetPBuffer(m_pkContext,m_pkPBuffer,iFace,iLevel,iScreen) )
        {
            glDrawBuffer(GL_FRONT);
            glViewport(0,0,m_iWidth,m_iHeight);
            pkRenderer->OnFrustumChange();
            pkRenderer->OnFrameChange();
        }
    }
}
//----------------------------------------------------------------------------
void AglPBuffer::Disable ()
{
    glFinish();

    // Set the main renderer to be the active one.  The first call is a
    // workaround for a bug workaround for Mac OS X 10.3.0 to 10.3.4.
    if ( aglSetCurrentContext(0) )
    {
        AglRenderer* pkRenderer = (AglRenderer*)m_pkRenderer;
        if ( aglSetCurrentContext(pkRenderer->GetContext()) )
        {
            glDrawBuffer(GL_BACK);
            pkRenderer->InitializeState();
            pkRenderer->OnViewPortChange();
            pkRenderer->OnFrustumChange ();
            pkRenderer->OnFrameChange ();
        }
    }
}
//----------------------------------------------------------------------------
void AglPBuffer::Bind ()
{
    // Bind the pbuffer to the offscreen texture.
    BufferParams::TextureTargetType eTarget = m_kBufferParams.TextureTarget;
    if ( eTarget != BufferParams::BP_TEXTURE_TARGET_NONE )
    {
        AglRenderer* pkRenderer = (AglRenderer*)m_pkRenderer;
        GLuint uiID;
        pkRenderer->m_pkTarget->BIArray.GetID(pkRenderer,sizeof(GLuint),
            &uiID);
        glBindTexture(GL_TEXTURE_2D,uiID);

        aglTexImagePBuffer(pkRenderer->GetContext(),m_pkPBuffer,GL_FRONT);
    }
}
//----------------------------------------------------------------------------
void AglPBuffer::Release ()
{
    // Release the offscreen texture from the pbuffer.  AGL appears not to
    // have this concept.
}
//----------------------------------------------------------------------------
void AglPBuffer::CopyToTarget (bool bRelease) const
{
    PBuffer::CopyToTarget(bRelease);
    unsigned char* aucData = m_pkTarget->GetImage()->GetData();
    glReadPixels(0,0,m_iWidth,m_iHeight,GL_RGBA,GL_UNSIGNED_BYTE,
        (void*)aucData);
}
//----------------------------------------------------------------------------
AGLDevice AglPBuffer::GetDevice ()
{
    return m_hDevice;
}
//----------------------------------------------------------------------------
AGLContext AglPBuffer::GetContext ()
{
    return m_pkContext;
}
//----------------------------------------------------------------------------
AGLPixelFormat AglPBuffer::GetFormat ()
{
    return m_kFormat;
}
//----------------------------------------------------------------------------
AGLPbuffer AglPBuffer::GetPBuffer ()
{
    return m_pkPBuffer;
}
//----------------------------------------------------------------------------


