// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM3COLORRGBAARRAY_H
#define WM3COLORRGBAARRAY_H

#include "Wm3FoundationLIB.h"
#include "Wm3TSharedArray.h"
#include "Wm3ColorRGBA.h"

namespace Wm3
{
typedef TSharedArray<ColorRGBA> ColorRGBAArray;
typedef Pointer<ColorRGBAArray> ColorRGBAArrayPtr;
WM3_REGISTER_STREAM(ColorRGBAArray);
}

#endif

