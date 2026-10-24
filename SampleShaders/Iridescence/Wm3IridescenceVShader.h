// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM3IRIDESCENCEVSHADER_H
#define WM3IRIDESCENCEVSHADER_H

#include "Wm3VertexShader.h"

namespace Wm3
{

class IridescenceVShader : public VertexShader
{
    WM3_DECLARE_RTTI;
    WM3_DECLARE_NAME_ID;
    WM3_DECLARE_STREAM;

public:
    IridescenceVShader ();
    virtual ~IridescenceVShader ();

    void SetInterpolateFactor (float fInterpolateFactor);
    float GetInterpolateFactor () const;

private:
    static const char* ms_aacProgram[Renderer::RT_QUANTITY];
};

WM3_REGISTER_STREAM(IridescenceVShader);
typedef Pointer<IridescenceVShader> IridescenceVShaderPtr;

#include "Wm3IridescenceVShader.inl"

}

#endif

