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
#include "Wm3IntrPlane3Sphere3.h"

namespace Wm3
{
//----------------------------------------------------------------------------
template <class Real>
IntrPlane3Sphere3<Real>::IntrPlane3Sphere3 (const Plane3<Real>& rkPlane,
    const Sphere3<Real>& rkSphere)
    :
    m_rkPlane(rkPlane),
    m_rkSphere(rkSphere)
{
}
//----------------------------------------------------------------------------
template <class Real>
const Plane3<Real>& IntrPlane3Sphere3<Real>::GetPlane () const
{
    return m_rkPlane;
}
//----------------------------------------------------------------------------
template <class Real>
const Sphere3<Real>& IntrPlane3Sphere3<Real>::GetSphere () const
{
    return m_rkSphere;
}
//----------------------------------------------------------------------------
template <class Real>
bool IntrPlane3Sphere3<Real>::Test ()
{
    Real fSignedDistance = m_rkPlane.DistanceTo(m_rkSphere.Center);
    return Math<Real>::FAbs(fSignedDistance) <= m_rkSphere.Radius;
}
//----------------------------------------------------------------------------
template <class Real>
bool IntrPlane3Sphere3<Real>::Find ()
{
    Real fSignedDistance = m_rkPlane.DistanceTo(m_rkSphere.Center);
    Real fDistance = Math<Real>::FAbs(fSignedDistance);
    if (fDistance <= m_rkSphere.Radius)
    {
        Real fSqrRadius = m_rkSphere.Radius*m_rkSphere.Radius;
        Real fSqrDistance = fDistance*fDistance;

        // Theoretically, r - d >= 0, which implies r^2 - d^2 >= 0.  Use the
        // absolute value to guard against numerical round-off errors that
        // might cause r^2 - d^2 to be slightly negative.
        Real fCircleRadius = Math<Real>::Sqrt(Math<Real>::FAbs(fSqrRadius -
            fSqrDistance));

        if (fCircleRadius > Math<Real>::ZERO_TOLERANCE)
        {
            m_kIntersectionCircle.Center = m_rkSphere.Center -
                fSignedDistance*m_rkPlane.Normal;
            m_kIntersectionCircle.Radius = fCircleRadius;
            m_kIntersectionCircle.N = m_rkPlane.Normal;
            Vector3<Real>::GenerateOrthonormalBasis(m_kIntersectionCircle.U,
                m_kIntersectionCircle.V,m_kIntersectionCircle.N,true);

            m_iIntersectionType = IT_OTHER;
        }
        else
        {
            // The plane is nearly tangent to the sphere, so let's call it a
            // tangency.
            m_kIntersectionPoint = m_rkSphere.Center -
                fSignedDistance*m_rkPlane.Normal;

            m_iIntersectionType = IT_POINT;
        }
    }
    else
    {
        m_iIntersectionType = IT_EMPTY;
    }

    return m_iIntersectionType != IT_EMPTY;
}
//----------------------------------------------------------------------------
template <class Real>
const Vector3<Real>& IntrPlane3Sphere3<Real>::GetIntersectionPoint () const
{
    return m_kIntersectionPoint;
}
//----------------------------------------------------------------------------
template <class Real>
const Circle3<Real>& IntrPlane3Sphere3<Real>::GetIntersectionCircle () const
{
    return m_kIntersectionCircle;
}
//----------------------------------------------------------------------------
template <class Real>
bool IntrPlane3Sphere3<Real>::SphereIsCulled () const
{
    Real fSignedDistance = m_rkPlane.DistanceTo(m_rkSphere.Center);
    return fSignedDistance <= -m_rkSphere.Radius;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// explicit instantiation
//----------------------------------------------------------------------------
template WM3_ITEM
class IntrPlane3Sphere3<float>;

template WM3_ITEM
class IntrPlane3Sphere3<double>;
//----------------------------------------------------------------------------
}

