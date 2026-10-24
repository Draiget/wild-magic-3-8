// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM3DISTRAY2RAY2_H
#define WM3DISTRAY2RAY2_H

#include "Wm3FoundationLIB.h"
#include "Wm3Distance.h"
#include "Wm3Ray2.h"

namespace Wm3
{

template <class Real>
class WM3_ITEM DistRay2Ray2 : public Distance<Real,Vector2<Real> >
{
public:
    DistRay2Ray2 (const Ray2<Real>& rkRay0, const Ray2<Real>& rkRay1);

    // object access
    const Ray2<Real>& GetRay0 () const;
    const Ray2<Real>& GetRay1 () const;

    // static distance queries
    virtual Real Get ();
    virtual Real GetSquared ();

    // function calculations for dynamic distance queries
    virtual Real Get (Real fT, const Vector2<Real>& rkVelocity0,
        const Vector2<Real>& rkVelocity1);
    virtual Real GetSquared (Real fT, const Vector2<Real>& rkVelocity0,
        const Vector2<Real>& rkVelocity1);

private:
    using Distance<Real,Vector2<Real> >::m_kClosestPoint0;
    using Distance<Real,Vector2<Real> >::m_kClosestPoint1;

    const Ray2<Real>& m_rkRay0;
    const Ray2<Real>& m_rkRay1;
};

typedef DistRay2Ray2<float> DistRay2Ray2f;
typedef DistRay2Ray2<double> DistRay2Ray2d;

}

#endif

