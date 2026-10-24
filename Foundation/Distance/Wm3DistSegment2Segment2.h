// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM3DISTSEGMENT2SEGMENT2_H
#define WM3DISTSEGMENT2SEGMENT2_H

#include "Wm3FoundationLIB.h"
#include "Wm3Distance.h"
#include "Wm3Segment2.h"

namespace Wm3
{

template <class Real>
class WM3_ITEM DistSegment2Segment2 : public Distance<Real,Vector2<Real> >
{
public:
    DistSegment2Segment2 (const Segment2<Real>& rkSegment0,
        const Segment2<Real>& rkSegment1);

    // object access
    const Segment2<Real>& GetSegment0 () const;
    const Segment2<Real>& GetSegment1 () const;

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

    const Segment2<Real>& m_rkSegment0;
    const Segment2<Real>& m_rkSegment1;
};

typedef DistSegment2Segment2<float> DistSegment2Segment2f;
typedef DistSegment2Segment2<double> DistSegment2Segment2d;

}

#endif

