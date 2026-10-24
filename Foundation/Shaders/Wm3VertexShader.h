// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM3VERTEXSHADER_H
#define WM3VERTEXSHADER_H

#include "Wm3FoundationLIB.h"
#include "Wm3Shader.h"

namespace Wm3
{

class WM3_ITEM VertexShader : public Shader
{
    WM3_DECLARE_RTTI;
    WM3_DECLARE_NAME_ID;
    WM3_DECLARE_STREAM;

public:
    VertexShader ();
    virtual ~VertexShader ();
};

WM3_REGISTER_STREAM(VertexShader);
typedef Pointer<VertexShader> VertexShaderPtr;

}

#endif

