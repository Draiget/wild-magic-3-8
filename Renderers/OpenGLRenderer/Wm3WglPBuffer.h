// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM3WGLPBUFFER_H
#define WM3WGLPBUFFER_H

#include "Wm3OpenGLRendererLIB.h"
#include "Wm3Main.h"
#include "Wm3PBuffer.h"
#include "Wm3WglExtensions.h"

namespace Wm3
{

class Renderer;

class WM3_RENDERER_ITEM WglPBuffer : public PBuffer
{
    WM3_DECLARE_INITIALIZE;

public:
    WglPBuffer (const BufferParams& rkBufferParams, int iWidth, int iHeight,
        Renderer* pkRenderer);
    virtual ~WglPBuffer ();

    bool InitializeBuffer ();
    void TerminateBuffer ();

    virtual void Enable ();
    virtual void Disable ();
    virtual void Bind ();
    virtual void Release ();
    virtual void CopyToTarget (bool bRelease) const;

    HPBUFFERARB GetPBuffer ();
    HDC GetDC ();
    HGLRC GetRC ();

protected:
    HPBUFFERARB m_hPBuffer;
    HDC m_hDC;
    HGLRC m_hRC;

    // factory functions
    static PBuffer* Create (const BufferParams& rkBufferParams, int iWidth,
        int iHeight, Renderer* pkRenderer);
    static void Destroy (PBuffer* pkBuffer);
};

WM3_REGISTER_INITIALIZE(WglPBuffer);

}

#endif

