// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM3DELTRIANGLE_H
#define WM3DELTRIANGLE_H

#include "Wm3FoundationLIB.h"
#include "Wm3Query2.h"

namespace Wm3
{

template <class Real>
class WM3_ITEM DelTriangle
{
public:
    DelTriangle (int iV0, int iV1, int iV2);

    bool IsInsertionComponent (int i, DelTriangle* pkAdj,
        const Query2<Real>* pkQuery, const int* aiSupervertex);
    int DetachFrom (int iAdj, DelTriangle* pkAdj);

    int V[3];
    DelTriangle* A[3];
    int Time;
    bool IsComponent;
    bool OnStack;
};

typedef DelTriangle<float> DelTrianglef;
typedef DelTriangle<double> DelTriangled;

}

#endif

