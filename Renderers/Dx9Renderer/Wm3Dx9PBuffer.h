// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM3DX9PBUFFER_H
#define WM3DX9PBUFFER_H

// TO DO.  Implement this class.

#include "Wm3Dx9RendererLIB.h"
#include "Wm3Main.h"
#include "Wm3PBuffer.h"

namespace Wm3
{

class Renderer;

class WM3_RENDERER_ITEM Dx9PBuffer : public PBuffer
{
    WM3_DECLARE_INITIALIZE;

public:
    Dx9PBuffer (const BufferParams& rkBufferParams, int iWidth, int iHeight,
        Renderer* pkRenderer);
    virtual ~Dx9PBuffer ();

    bool InitializeBuffer ();
    void TerminateBuffer ();

    virtual void Enable ();
    virtual void Disable ();
    virtual void Bind ();
    virtual void Release ();
    virtual void CopyToTarget (bool bRelease) const;

protected:
    // factory functions
    static PBuffer* Create (const BufferParams& rkBufferParams, int iWidth,
        int iHeight, Renderer* pkRenderer);
    static void Destroy (PBuffer* pkBuffer);
};

WM3_REGISTER_INITIALIZE(Dx9PBuffer);

}

#endif

