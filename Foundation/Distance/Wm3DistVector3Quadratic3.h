// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM3DISTVECTOR3QUADRATIC3_H
#define WM3DISTVECTOR3QUADRATIC3_H

#include "Wm3Distance.h"
#include "Wm3Quadratic3.h"
#include "Wm3Polynomial1.h"

namespace Wm3
{

template <class Real>
class WM3_ITEM DistVector3Quadratic3 : public Distance<Real,Vector3<Real> >
{
public:
    DistVector3Quadratic3 (const Vector3<Real>& rkVector,
        const Quadratic3<Real>& rkQuadratic);

    // object access
    const Vector3<Real>& GetVector () const;
    const Quadratic3<Real>& GetQuadratic () const;

    // static distance queries
    virtual Real Get ();
    virtual Real GetSquared ();

    // function calculations for dynamic distance queries
    virtual Real Get (Real fT, const Vector3<Real>& rkVelocity0,
        const Vector3<Real>& rkVelocity1);
    virtual Real GetSquared (Real fT, const Vector3<Real>& rkVelocity0,
        const Vector3<Real>& rkVelocity1);

private:
    using Distance<Real,Vector3<Real> >::m_kClosestPoint0;
    using Distance<Real,Vector3<Real> >::m_kClosestPoint1;

    static void ComputePoly (Real afA[3], Real afB[3], Real afD[3], Real fC,
        Polynomial1<Real>& rkPoly);

    const Vector3<Real>& m_rkVector;
    const Quadratic3<Real>& m_rkQuadratic;
};

typedef DistVector3Quadratic3<float> DistVector3Quadratic3f;
typedef DistVector3Quadratic3<double> DistVector3Quadratic3d;

}

#endif

