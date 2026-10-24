// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM3DISTLINE2LINE2_H
#define WM3DISTLINE2LINE2_H

#include "Wm3FoundationLIB.h"
#include "Wm3Distance.h"
#include "Wm3Line2.h"

namespace Wm3
{

template <class Real>
class WM3_ITEM DistLine2Line2 : public Distance<Real,Vector2<Real> >
{
public:
    DistLine2Line2 (const Line2<Real>& rkLine0, const Line2<Real>& rkLine1);

    // object access
    const Line2<Real>& GetLine0 () const;
    const Line2<Real>& GetLine1 () const;

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

    const Line2<Real>& m_rkLine0;
    const Line2<Real>& m_rkLine1;
};

typedef DistLine2Line2<float> DistLine2Line2f;
typedef DistLine2Line2<double> DistLine2Line2d;

}

#endif

