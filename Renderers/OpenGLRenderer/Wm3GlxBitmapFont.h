// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM3GLXBITMAPFONT_H
#define WM3GLXBITMAPFONT_H

#include "Wm3OpenGLRendererLIB.h"

namespace Wm3
{

class WM3_RENDERER_ITEM BitmapFontChar
{
public:
    BitmapFontChar (int iXOrigin, int iYOrigin, int iXSize, int iYSize,
        const unsigned char* aucBitmap)
    {
        XOrigin = iXOrigin;
        YOrigin = iYOrigin;
        XSize = iXSize;
        YSize = iYSize;
        Bitmap = aucBitmap;
    }

    int XOrigin, YOrigin, XSize, YSize;
    const unsigned char* Bitmap;
};

class WM3_RENDERER_ITEM BitmapFont
{
public:
    BitmapFont (const char* acName, int iQuantity,
        const BitmapFontChar* const* pkChars)
    {
        Name = acName;
        Quantity = iQuantity;
        Chars = pkChars;
    }

    const char* Name;
    int Quantity;
    const BitmapFontChar* const* Chars;
};

extern const BitmapFont g_kVerdana_S16B0I0;

}

#endif

