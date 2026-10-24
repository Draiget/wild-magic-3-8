// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#include "Wm3Dx9RendererPCH.h"
#include "Wm3Dx9PBuffer.h"
#include "Wm3Dx9Renderer.h"
using namespace Wm3;

// TO DO.  Implement this class.

WM3_IMPLEMENT_INITIALIZE(Dx9PBuffer);

//----------------------------------------------------------------------------
void Dx9PBuffer::Initialize ()
{
    ms_oCreate = &Dx9PBuffer::Create;
    ms_oDestroy = &Dx9PBuffer::Destroy;
}
//----------------------------------------------------------------------------
PBuffer* Dx9PBuffer::Create (const BufferParams& rkBufferParams, int iWidth,
    int iHeight, Renderer* pkRenderer)
{
    if (iWidth > 0 && iHeight > 0 && pkRenderer)
    {
        Dx9PBuffer* pkBuffer = WM3_NEW Dx9PBuffer(rkBufferParams,iWidth,
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
void Dx9PBuffer::Destroy (PBuffer* pkBuffer)
{
    ((Dx9PBuffer*)pkBuffer)->TerminateBuffer();
    WM3_DELETE pkBuffer;
}
//----------------------------------------------------------------------------
Dx9PBuffer::Dx9PBuffer (const BufferParams& rkBufferParams, int iWidth,
    int iHeight, Renderer* pkRenderer)
    :
    PBuffer(rkBufferParams,iWidth,iHeight,pkRenderer)
{
}
//----------------------------------------------------------------------------
Dx9PBuffer::~Dx9PBuffer ()
{
}
//----------------------------------------------------------------------------
bool Dx9PBuffer::InitializeBuffer ()
{
    return false;
}
//----------------------------------------------------------------------------
void Dx9PBuffer::TerminateBuffer ()
{
}
//----------------------------------------------------------------------------
void Dx9PBuffer::Enable ()
{
}
//----------------------------------------------------------------------------
void Dx9PBuffer::Disable ()
{
}
//----------------------------------------------------------------------------
void Dx9PBuffer::Bind ()
{
}
//----------------------------------------------------------------------------
void Dx9PBuffer::Release ()
{
}
//----------------------------------------------------------------------------
void Dx9PBuffer::CopyToTarget (bool bRelease) const
{
}
//----------------------------------------------------------------------------

