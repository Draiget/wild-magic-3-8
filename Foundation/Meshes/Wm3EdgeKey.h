// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM3EDGEKEY_H
#define WM3EDGEKEY_H

#include "Wm3FoundationLIB.h"
#include "Wm3System.h"

namespace Wm3
{

class WM3_ITEM EdgeKey
{
public:
    EdgeKey (int iV0 = -1, int iV1 = -1);

    bool operator< (const EdgeKey& rkKey) const;

    int V[2];
};

#include "Wm3EdgeKey.inl"

}

#endif

