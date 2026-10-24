// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM3DISTVECTOR3TETRAHEDRON3_H
#define WM3DISTVECTOR3TETRAHEDRON3_H

#include "Wm3FoundationLIB.h"
#include "Wm3Distance.h"
#include "Wm3Tetrahedron3.h"

namespace Wm3
{

template <class Real>
class WM3_ITEM DistVector3Tetrahedron3 : public Distance<Real,Vector3<Real> >
{
public:
    DistVector3Tetrahedron3 (const Vector3<Real>& rkVector,
        const Tetrahedron3<Real>& rkTetrahedron);

    // object access
    const Vector3<Real>& GetVector () const;
    const Tetrahedron3<Real>& GetTetrahedron () const;

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

    const Vector3<Real>& m_rkVector;
    const Tetrahedron3<Real>& m_rkTetrahedron;
};

typedef DistVector3Tetrahedron3<float> DistVector3Tetrahedron3f;
typedef DistVector3Tetrahedron3<double> DistVector3Tetrahedron3d;

}

#endif

