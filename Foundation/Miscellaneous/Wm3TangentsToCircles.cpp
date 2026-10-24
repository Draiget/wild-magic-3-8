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
#include "Wm3TangentsToCircles.h"

namespace Wm3
{
//----------------------------------------------------------------------------
template <class Real>
static void GetDirections (const Vector2<Real>& rkW, Real fA,
    Vector2<Real>& rkDir0, Vector2<Real>& rkDir1)
{
    Real fA2 = fA*fA;
    Real fWx2 = rkW.X()*rkW.X();
    Real fWy2 = rkW.Y()*rkW.Y();
    Real fC2 = fWx2 + fWy2;
    Real fMHalfInvC2 = ((Real)-0.5)/fC2;
    Real fC0, fC1, fDiscr, fRoot, fInv;

    if (Math<Real>::FAbs(rkW.X()) >= Math<Real>::FAbs(rkW.Y()))
    {
        fC0 = fA2 - fWx2;
        fC1 = -((Real)2.0)*fA*rkW.Y();
        fDiscr = fC1*fC1 - ((Real)4.0)*fC0*fC2;
        fRoot = Math<Real>::Sqrt(Math<Real>::FAbs(fDiscr));
        fInv = ((Real)1.0)/rkW.X();
        rkDir0.Y() = (fC1 + fRoot)*fMHalfInvC2;
        rkDir0.X() = (fA - rkW.Y()*rkDir0.Y())*fInv;
        rkDir1.Y() = (fC1 - fRoot)*fMHalfInvC2;
        rkDir1.X() = (fA - rkW.Y()*rkDir1.Y())*fInv;
    }
    else
    {
        fC0 = fA2 - fWy2;
        fC1 = -((Real)2.0)*fA*rkW.X();
        fDiscr = fC1*fC1 - ((Real)4.0)*fC0*fC2;
        fRoot = Math<Real>::Sqrt(Math<Real>::FAbs(fDiscr));
        fInv = ((Real)1.0)/rkW.Y();
        rkDir0.X() = (fC1 + fRoot)*fMHalfInvC2;
        rkDir0.Y() = (fA - rkW.X()*rkDir0.X())*fInv;
        rkDir1.X() = (fC1 - fRoot)*fMHalfInvC2;
        rkDir1.Y() = (fA - rkW.X()*rkDir1.X())*fInv;
    }
}
//----------------------------------------------------------------------------
template <class Real>
bool GetTangentsToCircles (const Circle2<Real>& rkCircle0,
    const Circle2<Real>& rkCircle1, Line2<Real> akLine[4])
{
    Vector2<Real> kW = rkCircle1.Center - rkCircle0.Center;
    Real fWLenSqr = kW.SquaredLength();
    Real fRSum = rkCircle0.Radius + rkCircle1.Radius;
    if (fWLenSqr <= fRSum*fRSum)
    {
        // circles are either intersecting or nested
        return false;
    }

    Real fR0Sqr = rkCircle0.Radius*rkCircle0.Radius;
    Real fTmp, fA;

    Real fRDiff = rkCircle1.Radius - rkCircle0.Radius;
    if (Math<Real>::FAbs(fRDiff) >= Math<Real>::ZERO_TOLERANCE)
    {
        // solve (R1^2-R0^2)*s^2 + 2*R0^2*s - R0^2 = 0.
        Real fR1Sqr = rkCircle1.Radius*rkCircle1.Radius;
        Real fC0 = -fR0Sqr;
        Real fC1 = ((Real)2.0)*fR0Sqr;
        Real fC2 = rkCircle1.Radius*rkCircle1.Radius - fR0Sqr;
        Real fMHalfInvC2 = ((Real)-0.5)/fC2;
        Real fDiscr = Math<Real>::FAbs(fC1*fC1 - ((Real)4.0)*fC0*fC2);
        Real fRoot = Math<Real>::Sqrt(fDiscr);
        Real fS, fOmS;

        // first root
        fS = (fC1 + fRoot)*fMHalfInvC2;
        akLine[0].Origin = rkCircle0.Center + fS*kW;
        akLine[1].Origin = akLine[0].Origin;
        if (fS >= (Real)0.5)
        {
            fTmp = Math<Real>::FAbs(fWLenSqr - fR0Sqr/(fS*fS));
            fA = Math<Real>::Sqrt(fTmp);
        }
        else
        {
            fOmS = (Real)1.0 - fS;
            fTmp = Math<Real>::FAbs(fWLenSqr - fR1Sqr/(fOmS*fOmS));
            fA = Math<Real>::Sqrt(fTmp);
        }
        GetDirections(kW,fA,akLine[0].Direction,akLine[1].Direction);

        // second root
        fS = (fC1 - fRoot)*fMHalfInvC2;
        akLine[2].Origin = rkCircle0.Center + fS*kW;
        akLine[3].Origin = akLine[2].Origin;
        if (fS >= (Real)0.5)
        {
            fTmp = Math<Real>::FAbs(fWLenSqr - fR0Sqr/(fS*fS));
            fA = Math<Real>::Sqrt(fTmp);
        }
        else
        {
            fOmS = (Real)1.0 - fS;
            fTmp = Math<Real>::FAbs(fWLenSqr - fR1Sqr/(fOmS*fOmS));
            fA = Math<Real>::Sqrt(fTmp);
        }
        GetDirections(kW,fA,akLine[2].Direction,akLine[3].Direction);
    }
    else
    {
        // circles effectively have same radius

        // midpoint of circle centers
        Vector2<Real> kMid = ((Real)0.5)*(rkCircle0.Center+rkCircle1.Center);

        // tangent lines passing through midpoint
        fTmp = Math<Real>::FAbs(fWLenSqr - ((Real)4.0)*fR0Sqr);
        fA = Math<Real>::Sqrt(fTmp);
        GetDirections(kW,fA,akLine[0].Direction,akLine[1].Direction);
        akLine[0].Origin = kMid;
        akLine[1].Origin = kMid;

        // normalize W
        kW /= Math<Real>::Sqrt(fWLenSqr);

        // tangent lines parallel to normalized W
        //   1.  D = W
        //   2.  a. P = mid+R0*perp(W), perp(a,b) = (b,-a)
        //       b. P = mid-R0*perp(W)
        akLine[2].Origin.X() = kMid.X() + rkCircle0.Radius*kW.Y();
        akLine[2].Origin.Y() = kMid.Y() - rkCircle0.Radius*kW.X();
        akLine[2].Direction = kW;
        akLine[3].Origin.X() = kMid.X() - rkCircle0.Radius*kW.Y();
        akLine[3].Origin.Y() = kMid.Y() + rkCircle0.Radius*kW.X();
        akLine[3].Direction = kW;
    }

    return true;
}
//----------------------------------------------------------------------------
template <class Real>
void GetTangentsToCircles (const Circle2<Real>& rkCircle0,
    const Circle2<Real>& rkCircle1, int& riQuantity, Line2<Real> akLine[4])
{
    riQuantity = 0;

    Vector2<Real> kW = rkCircle1.Center - rkCircle0.Center;
    Real fWLenSqr = kW.SquaredLength();
    Real fWLen = Math<Real>::Sqrt(fWLenSqr);
    if (fWLen <= Math<Real>::ZERO_TOLERANCE)
    {
        // The circles have the same center, so they have no tangents in
        // common or they have infinitely many in common (same circle).
        // Just report this as no tangents in common.
        return;
    }

    Real fRSum = rkCircle0.Radius + rkCircle1.Radius;
    Real fR0Sqr = rkCircle0.Radius*rkCircle0.Radius;
    Real fTmp, fA;

    Real fRDiff = rkCircle1.Radius - rkCircle0.Radius;
    if (Math<Real>::FAbs(fRDiff) >= Math<Real>::ZERO_TOLERANCE)
    {
        // solve (R1^2-R0^2)*s^2 + 2*R0^2*s - R0^2 = 0.
        Real fR1Sqr = rkCircle1.Radius*rkCircle1.Radius;
        Real fC0 = -fR0Sqr;
        Real fC1 = ((Real)2.0)*fR0Sqr;
        Real fC2 = rkCircle1.Radius*rkCircle1.Radius - fR0Sqr;
        Real fMHalfInvC2 = ((Real)-0.5)/fC2;
        Real fDiscr = fC1*fC1 - ((Real)4.0)*fC0*fC2;
        if (fDiscr < (Real)0.0)
        {
            // circles are nested, no tangents
            return;
        }
        Real fRoot = Math<Real>::Sqrt(fDiscr);
        Real fS, fOmS;

        // first root
        fS = (fC1 + fRoot)*fMHalfInvC2;
        if (fS >= (Real)0.5)
        {
            fTmp = fWLenSqr - fR0Sqr/(fS*fS);
            if (fTmp >= (Real)0.0)
            {
                fA = Math<Real>::Sqrt(fTmp);
                akLine[0].Origin = rkCircle0.Center + fS*kW;
                akLine[1].Origin = akLine[0].Origin;
                GetDirections(kW,fA,akLine[0].Direction,akLine[1].Direction);
                riQuantity = 2;
            }
        }
        else
        {
            fOmS = (Real)1.0 - fS;
            fTmp = fWLenSqr - fR1Sqr/(fOmS*fOmS);
            if (fTmp >= (Real)0.0)
            {
                fA = Math<Real>::Sqrt(fTmp);
                akLine[0].Origin = rkCircle0.Center + fS*kW;
                akLine[1].Origin = akLine[0].Origin;
                GetDirections(kW,fA,akLine[0].Direction,akLine[1].Direction);
                riQuantity = 2;
            }
        }

        // second root
        fS = (fC1 - fRoot)*fMHalfInvC2;
        if (fS >= (Real)0.5)
        {
            fTmp = fWLenSqr - fR0Sqr/(fS*fS);
            if (fTmp >= (Real)0.0)
            {
                fA = Math<Real>::Sqrt(fTmp);
                akLine[riQuantity].Origin = rkCircle0.Center + fS*kW;
                akLine[riQuantity+1].Origin = akLine[riQuantity].Origin;
                GetDirections(kW,fA,akLine[riQuantity].Direction,
                    akLine[riQuantity+1].Direction);
                riQuantity += 2;
            }
        }
        else
        {
            fOmS = (Real)1.0 - fS;
            fTmp = fWLenSqr - fR1Sqr/(fOmS*fOmS);
            if (fTmp >= (Real)0.0)
            {
                fA = Math<Real>::Sqrt(fTmp);
                akLine[riQuantity].Origin = rkCircle0.Center + fS*kW;
                akLine[riQuantity+1].Origin = akLine[riQuantity].Origin;
                GetDirections(kW,fA,akLine[riQuantity].Direction,
                    akLine[riQuantity+1].Direction);
                riQuantity += 2;
            }
        }
    }
    else
    {
        // circles effectively have same radius

        // midpoint of circle centers
        Vector2<Real> kMid = ((Real)0.5)*(rkCircle0.Center+rkCircle1.Center);

        // tangent lines passing through midpoint
        fTmp = fWLenSqr - ((Real)4.0)*fR0Sqr;
        if (fTmp >= (Real)0.0)
        {
            fA = Math<Real>::Sqrt(fTmp);
            akLine[0].Origin = kMid;
            akLine[1].Origin = kMid;
            GetDirections(kW,fA,akLine[0].Direction,akLine[1].Direction);
            riQuantity = 2;
        }

        // normalize W
        kW /= fWLen;

        // tangent lines parallel to normalized W
        //   1.  D = W
        //   2.  a. P = mid+R0*perp(W), perp(a,b) = (b,-a)
        //       b. P = mid-R0*perp(W)
        akLine[riQuantity].Origin.X() = kMid.X() + rkCircle0.Radius*kW.Y();
        akLine[riQuantity].Origin.Y() = kMid.Y() - rkCircle0.Radius*kW.X();
        akLine[riQuantity].Direction = kW;
        akLine[riQuantity+1].Origin.X() = kMid.X() - rkCircle0.Radius*kW.Y();
        akLine[riQuantity+1].Origin.Y() = kMid.Y() + rkCircle0.Radius*kW.X();
        akLine[riQuantity+1].Direction = kW;
        riQuantity += 2;
    }
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// explicit instantiation
//----------------------------------------------------------------------------
template WM3_ITEM
bool GetTangentsToCircles<float> (const Circle2<float>&,
    const Circle2<float>&, Line2<float>[4]);

template WM3_ITEM
void GetTangentsToCircles<float> (const Circle2<float>&,
    const Circle2<float>&, int&, Line2<float>[4]);

template WM3_ITEM
bool GetTangentsToCircles<double> (const Circle2<double>&,
    const Circle2<double>&, Line2<double>[4]);

template WM3_ITEM
void GetTangentsToCircles<double> (const Circle2<double>&,
    const Circle2<double>&, int&, Line2<double>[4]);
//----------------------------------------------------------------------------
}

