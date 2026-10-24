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
#include "Wm3DistLine3Triangle3.h"
#include "Wm3DistLine3Segment3.h"

namespace Wm3
{
//----------------------------------------------------------------------------
template <class Real>
DistLine3Triangle3<Real>::DistLine3Triangle3 (const Line3<Real>& rkLine,
    const Triangle3<Real>& rkTriangle)
    :
    m_rkLine(rkLine),
    m_rkTriangle(rkTriangle)
{
}
//----------------------------------------------------------------------------
template <class Real>
const Line3<Real>& DistLine3Triangle3<Real>::GetLine () const
{
    return m_rkLine;
}
//----------------------------------------------------------------------------
template <class Real>
const Triangle3<Real>& DistLine3Triangle3<Real>::GetTriangle () const
{
    return m_rkTriangle;
}
//----------------------------------------------------------------------------
template <class Real>
Real DistLine3Triangle3<Real>::Get ()
{
    Real fSqrDist = GetSquared();
    return Math<Real>::Sqrt(fSqrDist);
}
//----------------------------------------------------------------------------
template <class Real>
Real DistLine3Triangle3<Real>::GetSquared ()
{
    // Test if line intersects triangle.  If so, the squared distance is zero.
    Vector3<Real> kDiff = m_rkTriangle.V[0] - m_rkLine.Origin;
    Vector3<Real> kEdge0 = m_rkTriangle.V[1] - m_rkTriangle.V[0];
    Vector3<Real> kEdge1 = m_rkTriangle.V[2] - m_rkTriangle.V[0];
    Real fA00 = (Real)1.0;  // m_rkLine.Direction.Dot(m_rkLine.Direction)
    Real fA01 = -m_rkLine.Direction.Dot(kEdge0);
    Real fA02 = -m_rkLine.Direction.Dot(kEdge1);
    Real fA11 = kEdge0.SquaredLength();
    Real fA12 = kEdge0.Dot(kEdge1);
    Real fA22 = kEdge1.Dot(kEdge1);
    Real fB0  = -kDiff.Dot(m_rkLine.Direction);
    Real fB1  = kDiff.Dot(kEdge0);
    Real fB2  = kDiff.Dot(kEdge1);

    // Set up for a relative error test on the angle between ray direction
    // and triangle normal to determine parallel/nonparallel status.
    Vector3<Real> kNormal = kEdge0.UnitCross(kEdge1);
    Real fDot = kNormal.Dot(m_rkLine.Direction);
    if (Math<Real>::FAbs(fDot) >= Math<Real>::ZERO_TOLERANCE)
    {
        // The line and triangle are not parallel, so the line intersects
        // the plane of the triangle.
        Real fCof00 = fA11*fA22-fA12*fA12;
        Real fCof01 = fA02*fA12-fA01*fA22;
        Real fCof02 = fA01*fA12-fA02*fA11;
        Real fCof11 = fA00*fA22-fA02*fA02;
        Real fCof12 = fA02*fA01-fA00*fA12;
        Real fCof22 = fA00*fA11-fA01*fA01;
        Real fInvDet = ((Real)1.0)/(fA00*fCof00+fA01*fCof01+fA02*fCof02);
        Real fRhs0 = -fB0*fInvDet;
        Real fRhs1 = -fB1*fInvDet;
        Real fRhs2 = -fB2*fInvDet;

        // Line parameter for the point of intersection.
        m_fLineParameter = fCof00*fRhs0+fCof01*fRhs1+fCof02*fRhs2;

        // Plane parameters for the point of intersection.
        m_afTriangleBary[1] = fCof01*fRhs0+fCof11*fRhs1+fCof12*fRhs2;
        m_afTriangleBary[2] = fCof02*fRhs0+fCof12*fRhs1+fCof22*fRhs2;
        m_afTriangleBary[0] = (Real)1.0 - m_afTriangleBary[1] -
            m_afTriangleBary[2];

        if (m_afTriangleBary[0] >= (Real)0.0 
        &&  m_afTriangleBary[1] >= (Real)0.0
        &&  m_afTriangleBary[2] >= (Real)0.0)
        {
            // The intersection point is inside or on the triangle.
            m_kClosestPoint0 = m_rkLine.Origin +
                m_fLineParameter*m_rkLine.Direction;

            m_kClosestPoint1 = m_rkTriangle.V[0] + m_afTriangleBary[1]*kEdge0
                + m_afTriangleBary[2]*kEdge1;

            return (Real)0.0;
        }
    }

    // Either (1) the line is not parallel to the triangle and the point of
    // intersection of the line and the plane of the triangle is outside the
    // triangle or (2) the line and triangle are parallel.  Regardless, the
    // closest point on the triangle is on an edge of the triangle.  Compare
    // the line to all three edges of the triangle.
    Real fSqrDist = Math<Real>::MAX_REAL;
    for (int i0 = 2, i1 = 0; i1 < 3; i0 = i1++)
    {
        Segment3<Real> kEdge;
        kEdge.Origin = ((Real)0.5)*(m_rkTriangle.V[i0] + m_rkTriangle.V[i1]);
        kEdge.Direction = m_rkTriangle.V[i1] - m_rkTriangle.V[i0];
        kEdge.Extent = ((Real)0.5)*kEdge.Direction.Normalize();
        DistLine3Segment3<Real> kLSDist(m_rkLine,kEdge);
        Real fSqrDistTmp = kLSDist.GetSquared();
        if (fSqrDistTmp < fSqrDist)
        {
            m_kClosestPoint0 = kLSDist.GetClosestPoint0();
            m_kClosestPoint1 = kLSDist.GetClosestPoint1();

            m_fLineParameter = kLSDist.GetLineParameter();
            Real fRatio = kLSDist.GetSegmentParameter()/kEdge.Extent;
            m_afTriangleBary[i0] = ((Real)0.5)*((Real)1.0 - fRatio);
            m_afTriangleBary[i1] = (Real)1.0 - m_afTriangleBary[i0];
            m_afTriangleBary[3-i0-i1] = (Real)0.0;

            fSqrDist = fSqrDistTmp;
        }
    }
    return fSqrDist;
}
//----------------------------------------------------------------------------
template <class Real>
Real DistLine3Triangle3<Real>::Get (Real fT, const Vector3<Real>& rkVelocity0,
    const Vector3<Real>& rkVelocity1)
{
    Vector3<Real> kMOrigin = m_rkLine.Origin + fT*rkVelocity0;
    Vector3<Real> kMV0 = m_rkTriangle.V[0] + fT*rkVelocity1;
    Vector3<Real> kMV1 = m_rkTriangle.V[1] + fT*rkVelocity1;
    Vector3<Real> kMV2 = m_rkTriangle.V[2] + fT*rkVelocity1;
    Line3<Real> kMLine(kMOrigin,m_rkLine.Direction);
    Triangle3<Real> kMTriangle(kMV0,kMV1,kMV2);
    return DistLine3Triangle3<Real>(kMLine,kMTriangle).Get();
}
//----------------------------------------------------------------------------
template <class Real>
Real DistLine3Triangle3<Real>::GetSquared (Real fT,
    const Vector3<Real>& rkVelocity0, const Vector3<Real>& rkVelocity1)
{
    Vector3<Real> kMOrigin = m_rkLine.Origin + fT*rkVelocity0;
    Vector3<Real> kMV0 = m_rkTriangle.V[0] + fT*rkVelocity1;
    Vector3<Real> kMV1 = m_rkTriangle.V[1] + fT*rkVelocity1;
    Vector3<Real> kMV2 = m_rkTriangle.V[2] + fT*rkVelocity1;
    Line3<Real> kMLine(kMOrigin,m_rkLine.Direction);
    Triangle3<Real> kMTriangle(kMV0,kMV1,kMV2);
    return DistLine3Triangle3<Real>(kMLine,kMTriangle).GetSquared();
}
//----------------------------------------------------------------------------
template <class Real>
Real DistLine3Triangle3<Real>::GetLineParameter () const
{
    return m_fLineParameter;
}
//----------------------------------------------------------------------------
template <class Real>
Real DistLine3Triangle3<Real>::GetTriangleBary (int i) const
{
    assert(0 <= i && i < 3);
    return m_afTriangleBary[i];
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// explicit instantiation
//----------------------------------------------------------------------------
template WM3_ITEM
class DistLine3Triangle3<float>;

template WM3_ITEM
class DistLine3Triangle3<double>;
//----------------------------------------------------------------------------
}

