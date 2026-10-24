// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#include "Wm3FoundationPCH.h"
#include "Wm3DelPolyhedronFace.h"

namespace Wm3
{
//----------------------------------------------------------------------------
template <class Real>
DelPolyhedronFace<Real>::DelPolyhedronFace (int iV0, int iV1, int iV2,
    int iNullIndex, DelTetrahedron<Real>* pkTetra)
    :
    ETManifoldMesh::Triangle(iV0,iV1,iV2)
{
    NullIndex = iNullIndex;
    Tetra = pkTetra;
}
//----------------------------------------------------------------------------
template <class Real>
ETManifoldMesh::TPtr DelPolyhedronFace<Real>::TCreator (int iV0, int iV1,
    int iV2)
{
    return WM3_NEW DelPolyhedronFace<Real>(iV0,iV1,iV2,0,0);
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// explicit instantiation
//----------------------------------------------------------------------------
template WM3_ITEM
class DelPolyhedronFace<float>;

template WM3_ITEM
class DelPolyhedronFace<double>;
//----------------------------------------------------------------------------
}

