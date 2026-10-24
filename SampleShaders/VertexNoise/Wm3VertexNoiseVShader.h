// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM3VERTEXNOISEVSHADER_H
#define WM3VERTEXNOISEVSHADER_H

#include "Wm3VertexShader.h"

namespace Wm3
{

class VertexNoiseVShader : public VertexShader
{
    WM3_DECLARE_RTTI;
    WM3_DECLARE_NAME_ID;
    WM3_DECLARE_STREAM;

public:
    VertexNoiseVShader ();
    virtual ~VertexNoiseVShader ();

    void SetNoiseTranslate (const Vector4f& rkNoiseTranslate);
    Vector4f GetNoiseTranslate () const;
    void SetNoiseScale (float fNoiseScale);
    float GetNoiseScale () const;
    void SetDisplacement (float fDisplacement);
    float GetDisplacement () const;
    void SetPg (int i, const Vector4f& rkData);
    Vector4f GetPg (int i) const;
    void SetBaseColor (const Vector4f& rkBaseColor);
    Vector4f GetBaseColor () const;

private:
    static const char* ms_aacProgram[Renderer::RT_QUANTITY];
};

WM3_REGISTER_STREAM(VertexNoiseVShader);
typedef Pointer<VertexNoiseVShader> VertexNoiseVShaderPtr;

#include "Wm3VertexNoiseVShader.inl"

}

#endif

