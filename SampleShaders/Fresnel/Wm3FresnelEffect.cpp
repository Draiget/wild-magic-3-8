// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#include "Wm3FresnelEffect.h"
#include "Wm3FresnelVShader.h"
#include "Wm3FresnelPShader.h"
using namespace Wm3;

WM3_IMPLEMENT_RTTI(Wm3,FresnelEffect,ShaderEffect);
WM3_IMPLEMENT_STREAM(FresnelEffect);
WM3_IMPLEMENT_DEFAULT_STREAM(FresnelEffect,ShaderEffect);
WM3_IMPLEMENT_DEFAULT_NAME_ID(FresnelEffect,ShaderEffect);

//----------------------------------------------------------------------------
FresnelEffect::FresnelEffect ()
{
    VShader = WM3_NEW FresnelVShader;
    PShader = WM3_NEW FresnelPShader;
}
//----------------------------------------------------------------------------
FresnelEffect::~FresnelEffect ()
{
}
//----------------------------------------------------------------------------
Effect* FresnelEffect::Clone ()
{
    FresnelEffect* pkClone = WM3_NEW FresnelEffect;
    DoCloning(pkClone);
    return pkClone;
}
//----------------------------------------------------------------------------
void FresnelEffect::DoCloning (Effect* pkEffect)
{
    ShaderEffect::DoCloning(pkEffect);
}
//----------------------------------------------------------------------------

