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
#include "Wm3ExtremalQuery3.h"

namespace Wm3
{
//----------------------------------------------------------------------------
template <class Real>
ExtremalQuery3<Real>::ExtremalQuery3 (
    const ConvexPolyhedron3<Real>& rkPolytope)
    :
    m_rkPolytope(rkPolytope)
{
    // Create the triangle normals.
    const Vector3<Real>* akVertex = m_rkPolytope.GetVertices();
    int iTQuantity = m_rkPolytope.GetTQuantity();
    const int* piIndex = m_rkPolytope.GetIndices();
    m_akFaceNormal = WM3_NEW Vector3<Real>[iTQuantity];
    for (int i = 0; i < iTQuantity; i++)
    {
        const Vector3<Real>& rkV0 = akVertex[*piIndex++];
        const Vector3<Real>& rkV1 = akVertex[*piIndex++];
        const Vector3<Real>& rkV2 = akVertex[*piIndex++];
        Vector3<Real> kEdge1 = rkV1 - rkV0;
        Vector3<Real> kEdge2 = rkV2 - rkV0;
        m_akFaceNormal[i] = kEdge1.UnitCross(kEdge2);
    }
}
//----------------------------------------------------------------------------
template <class Real>
ExtremalQuery3<Real>::~ExtremalQuery3 ()
{
    WM3_DELETE[] m_akFaceNormal;
}
//----------------------------------------------------------------------------
template <class Real>
const ConvexPolyhedron3<Real>& ExtremalQuery3<Real>::GetPolytope () const
{
    return m_rkPolytope;
}
//----------------------------------------------------------------------------
template <class Real>
const Vector3<Real>* ExtremalQuery3<Real>::GetFaceNormals () const
{
    return m_akFaceNormal;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// explicit instantiation
//----------------------------------------------------------------------------
template WM3_ITEM
class ExtremalQuery3<float>;

template WM3_ITEM
class ExtremalQuery3<double>;
//----------------------------------------------------------------------------
}

