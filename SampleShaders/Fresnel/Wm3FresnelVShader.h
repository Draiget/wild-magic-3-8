// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM3FRESNELVSHADER_H
#define WM3FRESNELVSHADER_H

#include "Wm3VertexShader.h"

namespace Wm3
{

class FresnelVShader : public VertexShader
{
    WM3_DECLARE_RTTI;
    WM3_DECLARE_NAME_ID;
    WM3_DECLARE_STREAM;

public:
    FresnelVShader ();
    virtual ~FresnelVShader ();

private:
    static const char* ms_aacProgram[Renderer::RT_QUANTITY];
};

WM3_REGISTER_STREAM(FresnelVShader);
typedef Pointer<FresnelVShader> FresnelVShaderPtr;

}

#endif

