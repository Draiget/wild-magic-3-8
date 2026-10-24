// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM3PIXELSHADER_H
#define WM3PIXELSHADER_H

#include "Wm3FoundationLIB.h"
#include "Wm3Shader.h"

namespace Wm3
{

class WM3_ITEM PixelShader : public Shader
{
    WM3_DECLARE_RTTI;
    WM3_DECLARE_NAME_ID;
    WM3_DECLARE_STREAM;

public:
    PixelShader ();
    virtual ~PixelShader ();
};

WM3_REGISTER_STREAM(PixelShader);
typedef Pointer<PixelShader> PixelShaderPtr;

}

#endif

