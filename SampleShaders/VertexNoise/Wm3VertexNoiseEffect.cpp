// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#include "Wm3VertexNoiseEffect.h"
#include "Wm3VertexNoiseVShader.h"
using namespace Wm3;

WM3_IMPLEMENT_RTTI(Wm3,VertexNoiseEffect,ShaderEffect);
WM3_IMPLEMENT_STREAM(VertexNoiseEffect);
WM3_IMPLEMENT_DEFAULT_STREAM(VertexNoiseEffect,ShaderEffect);
WM3_IMPLEMENT_DEFAULT_NAME_ID(VertexNoiseEffect,ShaderEffect);

//----------------------------------------------------------------------------
VertexNoiseEffect::VertexNoiseEffect()
{
    VShader = WM3_NEW VertexNoiseVShader;
}
//----------------------------------------------------------------------------
VertexNoiseEffect::~VertexNoiseEffect ()
{
}
//----------------------------------------------------------------------------
Effect* VertexNoiseEffect::Clone ()
{
    VertexNoiseEffect* pkClone = WM3_NEW VertexNoiseEffect;
    DoCloning(pkClone);
    return pkClone;
}
//----------------------------------------------------------------------------
void VertexNoiseEffect::DoCloning (Effect* pkEffect)
{
    ShaderEffect::DoCloning(pkEffect);
}
//----------------------------------------------------------------------------

