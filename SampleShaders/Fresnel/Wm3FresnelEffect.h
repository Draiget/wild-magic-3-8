// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM3FRESNELEFFECT_H
#define WM3FRESNELEFFECT_H

#include "Wm3ShaderEffect.h"

namespace Wm3
{

class FresnelEffect : public ShaderEffect
{
    WM3_DECLARE_RTTI;
    WM3_DECLARE_NAME_ID;
    WM3_DECLARE_STREAM;

public:
    FresnelEffect ();
    virtual ~FresnelEffect ();

    // create a clone of the effect
    virtual Effect* Clone ();

protected:
    // streaming
    virtual void DoCloning (Effect* pkClone);
};

WM3_REGISTER_STREAM(FresnelEffect);
typedef Pointer<FresnelEffect> FresnelEffectPtr;

}

#endif

