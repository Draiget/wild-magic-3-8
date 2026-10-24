// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM3DELTETRAHEDRON_H
#define WM3DELTETRAHEDRON_H

#include "Wm3FoundationLIB.h"
#include "Wm3Query3.h"

namespace Wm3
{

template <class Real>
class WM3_ITEM DelTetrahedron
{
public:
    DelTetrahedron (int iV0, int iV1, int iV2, int iV3);

    bool IsInsertionComponent (int i, DelTetrahedron* pkAdj,
        const Query3<Real>* pkQuery, const int* aiSupervertex);
    int DetachFrom (int iAdj, DelTetrahedron* pkAdj);

    int V[4];
    DelTetrahedron* A[4];
    int Time;
    bool IsComponent;
    bool OnStack;
};

typedef DelTetrahedron<float> DelTetrahedronf;
typedef DelTetrahedron<double> DelTetrahedrond;

}

#endif

