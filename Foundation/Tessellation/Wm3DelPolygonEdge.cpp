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
#include "Wm3DelPolygonEdge.h"

namespace Wm3
{
//----------------------------------------------------------------------------
template <class Real>
DelPolygonEdge<Real>::DelPolygonEdge (int iV0, int iV1, int iNullIndex,
    DelTriangle<Real>* pkTri)
    :
    VEManifoldMesh::Edge(iV0,iV1)
{
    NullIndex = iNullIndex;
    Tri = pkTri;
}
//----------------------------------------------------------------------------
template <class Real>
VEManifoldMesh::EPtr DelPolygonEdge<Real>::ECreator (int iV0, int iV1)
{
    return WM3_NEW DelPolygonEdge<Real>(iV0,iV1,0,0);
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// explicit instantiation
//----------------------------------------------------------------------------
template WM3_ITEM
class DelPolygonEdge<float>;

template WM3_ITEM
class DelPolygonEdge<double>;
//----------------------------------------------------------------------------
}

