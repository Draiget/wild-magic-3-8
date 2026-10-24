// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

//----------------------------------------------------------------------------
template <class Real>
Arc2<Real>::Arc2 ()
{
    // uninitialized
}
//----------------------------------------------------------------------------
template <class Real>
Arc2<Real>::Arc2 (const Vector2<Real>& rkCenter, Real fRadius,
    const Vector2<Real>& rkEnd0, const Vector2<Real>& rkEnd1)
    :
    Circle2<Real>(rkCenter,fRadius),
    End0(rkEnd0),
    End1(rkEnd1)
{
}
//----------------------------------------------------------------------------
template <class Real>
bool Arc2<Real>::Contains (const Vector2<Real>& rkP) const
{
    // Assert: |P-C| = R where P is the input point, C is the circle center,
    // and R is the circle radius.  For P to be on the arc from A to B, it
    // must be on the side of the plane containing A with normal N = Perp(B-A)
    // where Perp(u,v) = (v,-u).

    Vector2<Real> kPmE0 = rkP - End0;
    Vector2<Real> kE1mE0 = End1 - End0;
    Real fDotPerp = kPmE0.DotPerp(kE1mE0);
    return fDotPerp >= (Real)0.0;
}
//----------------------------------------------------------------------------
template <class Real>
Real Arc2<Real>::GetAngleEnd0 () const
{
    Vector2<Real> kDiff = End0 - Center;
    Real fAngle;

    if (kDiff != Vector2<Real>::ZERO)
    {
        // This angle is in (-pi,pi].  To have an angle in [0,2*pi), we can
        // just use the current angle if it is in [0,pi], but we must add
        // 2*pi to the current angle if it is in (-pi,0).
        fAngle = Math<Real>::ATan2(kDiff.Y(),kDiff.X());
        if (fAngle < (Real)0.0)
        {
            fAngle += Math<Real>::TWO_PI;
        }
    }
    else
    {
        // diff = (0,0), return an angle of 0 since atan2 is undefined
        fAngle = (Real)0.0;
    }

    return fAngle;
}
//----------------------------------------------------------------------------
template <class Real>
Real Arc2<Real>::GetAngleEnd1 () const
{
    Vector2<Real> kDiff = End1 - Center;
    Real fAngle;

    if (kDiff != Vector2<Real>::ZERO)
    {
        // This angle is in (-pi,pi].  To have an angle in [0,2*pi), we can
        // just use the current angle if it is in [0,pi], but we must add
        // 2*pi to the current angle if it is in (-pi,0).
        fAngle = Math<Real>::ATan2(kDiff.Y(),kDiff.X());
        if (fAngle < (Real)0.0)
        {
            fAngle += Math<Real>::TWO_PI;
        }
    }
    else
    {
        // diff = (0,0), return an angle of 0 since atan2 is undefined
        fAngle = (Real)0.0;
    }

    return fAngle;
}
//----------------------------------------------------------------------------
template <class Real>
Real Arc2<Real>::GetAngle () const
{
    Real fAngle = GetAngleEnd1() - GetAngleEnd0();
    if (fAngle < (Real)0.0)
    {
        fAngle += Math<Real>::TWO_PI;
    }
    return fAngle;
}
//----------------------------------------------------------------------------

