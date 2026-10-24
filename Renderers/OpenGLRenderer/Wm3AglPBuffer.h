// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM3AGLPBUFFER_H
#define WM3AGLPBUFFER_H

#include "Wm3OpenGLRendererLIB.h"
#include "Wm3OpenGLExtensions.h"
#include "Wm3Main.h"
#include "Wm3PBuffer.h"
#include <AGL/agl.h>

namespace Wm3
{

class WM3_RENDERER_ITEM AglPBuffer : public PBuffer
{
    WM3_DECLARE_INITIALIZE;

public:
    AglPBuffer (const BufferParams& rkBufferParams, int iWidth, int iHeight,
        Renderer* pkRenderer);
    virtual ~AglPBuffer ();

    bool InitializeBuffer ();
    void TerminateBuffer ();

    virtual void Enable ();
    virtual void Disable ();
    virtual void Bind ();
    virtual void Release ();
    virtual void CopyToTarget (bool bRelease) const;

    AGLDevice GetDevice ();
    AGLContext GetContext ();
    AGLPixelFormat GetFormat ();
    AGLPbuffer GetPBuffer ();

protected:
    AGLDevice m_hDevice;
    AGLContext m_pkContext;
    AGLPixelFormat m_kFormat;
    AGLPbuffer m_pkPBuffer;

    // factory functions
    static PBuffer* Create (const BufferParams& rkBufferParams, int iWidth,
        int iHeight, Renderer* pkRenderer);
    static void Destroy (PBuffer* pkBuffer);
};

WM3_REGISTER_INITIALIZE(AglPBuffer);

}

#endif


