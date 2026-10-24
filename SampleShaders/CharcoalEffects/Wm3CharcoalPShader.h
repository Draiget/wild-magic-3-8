// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM3CHARCOALPSHADER_H
#define WM3CHARCOALPSHADER_H

#include "Wm3PixelShader.h"

namespace Wm3
{

class CharcoalPShader : public PixelShader
{
    WM3_DECLARE_RTTI;
    WM3_DECLARE_NAME_ID;
    WM3_DECLARE_STREAM;

public:
    CharcoalPShader ();
    virtual ~CharcoalPShader ();

    void SetSmudgeFactor (float fSmudgeFactor);
    float GetSmudgeFactor () const;
    void SetPaperFactor (float fPaperFactor);
    float GetPaperFactor () const;

private:
    static const char* ms_aacProgram[Renderer::RT_QUANTITY];
};

WM3_REGISTER_STREAM(CharcoalPShader);
typedef Pointer<CharcoalPShader> CharcoalPShaderPtr;

#include "Wm3CharcoalPShader.inl"

}

#endif

