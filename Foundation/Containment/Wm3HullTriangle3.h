// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM3HULLTRIANGLE3_H
#define WM3HULLTRIANGLE3_H

#include "Wm3FoundationLIB.h"
#include "Wm3Query3.h"

namespace Wm3
{

template <class Real>
class WM3_ITEM HullTriangle3
{
public:
    HullTriangle3 (int iV0, int iV1, int iV2);

    int GetSign (int i, const Query3<Real>* pkQuery);

    void AttachTo (HullTriangle3* pkAdj0, HullTriangle3* pkAdj1,
        HullTriangle3* pkAdj2);

    int DetachFrom (int iAdj, HullTriangle3* pkAdj);

    int V[3];
    HullTriangle3* A[3];
    int Sign;
    int Time;
    bool OnStack;
};

}

#endif

