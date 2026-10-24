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
#include "Wm3EllipsoidGeodesic.h"
#include "Wm3Math.h"

namespace Wm3
{
//----------------------------------------------------------------------------
template <class Real>
EllipsoidGeodesic<Real>::EllipsoidGeodesic (Real fXExtent, Real fYExtent,
    Real fZExtent)
    :
    RiemannianGeodesic<Real>(2)
{
    m_fXExtent = fXExtent;
    m_fYExtent = fYExtent;
    m_fZExtent = fZExtent;
}
//----------------------------------------------------------------------------
template <class Real>
EllipsoidGeodesic<Real>::~EllipsoidGeodesic ()
{
}
//----------------------------------------------------------------------------
template <class Real>
Vector3<Real> EllipsoidGeodesic<Real>::ComputePosition (
    const GVector<Real>& rkPoint)
{
    Real fCos0 = Math<Real>::Cos(rkPoint[0]);
    Real fSin0 = Math<Real>::Sin(rkPoint[0]);
    Real fCos1 = Math<Real>::Cos(rkPoint[1]);
    Real fSin1 = Math<Real>::Sin(rkPoint[1]);

    return Vector3<Real>(
        m_fXExtent*fCos0*fSin1,
        m_fYExtent*fSin0*fSin1,
        m_fZExtent*fCos1
    );
}
//----------------------------------------------------------------------------
template <class Real>
void EllipsoidGeodesic<Real>::ComputeMetric (const GVector<Real>& rkPoint)
{
    Real fCos0 = Math<Real>::Cos(rkPoint[0]);
    Real fSin0 = Math<Real>::Sin(rkPoint[0]);
    Real fCos1 = Math<Real>::Cos(rkPoint[1]);
    Real fSin1 = Math<Real>::Sin(rkPoint[1]);

    Vector3<Real> kDer0(
        -m_fXExtent*fSin0*fSin1,
        m_fYExtent*fCos0*fSin1,
        (Real)0.0);

    Vector3<Real> kDer1(
        m_fXExtent*fCos0*fCos1,
        m_fYExtent*fSin0*fCos1,
        -m_fZExtent*fSin1);

    m_kMetric[0][0] = kDer0.Dot(kDer0);
    m_kMetric[0][1] = kDer0.Dot(kDer1);
    m_kMetric[1][0] = m_kMetric[0][1];
    m_kMetric[1][1] = kDer1.Dot(kDer1);
}
//----------------------------------------------------------------------------
template <class Real>
void EllipsoidGeodesic<Real>::ComputeChristoffel1 (
    const GVector<Real>& rkPoint)
{
    Real fCos0 = Math<Real>::Cos(rkPoint[0]);
    Real fSin0 = Math<Real>::Sin(rkPoint[0]);
    Real fCos1 = Math<Real>::Cos(rkPoint[1]);
    Real fSin1 = Math<Real>::Sin(rkPoint[1]);

    Vector3<Real> kDer0(
        -m_fXExtent*fSin0*fSin1,
        m_fYExtent*fCos0*fSin1,
        (Real)0.0);

    Vector3<Real> kDer1(
        m_fXExtent*fCos0*fCos1,
        m_fYExtent*fSin0*fCos1,
        -m_fZExtent*fSin1);

    Vector3<Real> kDer00(
        -m_fXExtent*fCos0*fSin1,
        -m_fYExtent*fSin0*fSin1,
        (Real)0.0);

    Vector3<Real> kDer01(
        -m_fXExtent*fSin0*fCos1,
        m_fYExtent*fCos0*fCos1,
        (Real)0.0);

    Vector3<Real> kDer11(
        -m_fXExtent*fCos0*fSin1,
        -m_fYExtent*fSin0*fSin1,
        -m_fZExtent*fCos1);

    m_akChristoffel1[0][0][0] = kDer00.Dot(kDer0);
    m_akChristoffel1[0][0][1] = kDer01.Dot(kDer0);
    m_akChristoffel1[0][1][0] = m_akChristoffel1[0][0][1];
    m_akChristoffel1[0][1][1] = kDer11.Dot(kDer0);

    m_akChristoffel1[1][0][0] = kDer00.Dot(kDer1);
    m_akChristoffel1[1][0][1] = kDer01.Dot(kDer1);
    m_akChristoffel1[1][1][0] = m_akChristoffel1[1][0][1];
    m_akChristoffel1[1][1][1] = kDer11.Dot(kDer1);
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// explicit instantiation
//----------------------------------------------------------------------------
template WM3_ITEM
class EllipsoidGeodesic<float>;

template WM3_ITEM
class EllipsoidGeodesic<double>;
}
//----------------------------------------------------------------------------

