// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM3INTRPLANE3SPHERE3_H
#define WM3INTRPLANE3SPHERE3_H

#include "Wm3FoundationLIB.h"
#include "Wm3Intersector.h"
#include "Wm3Plane3.h"
#include "Wm3Sphere3.h"
#include "Wm3Circle3.h"

namespace Wm3
{

template <class Real>
class WM3_ITEM IntrPlane3Sphere3 : public Intersector<Real,Vector3<Real> >
{
public:
    IntrPlane3Sphere3 (const Plane3<Real>& rkPlane,
        const Sphere3<Real>& rkSphere);

    // object access
    const Plane3<Real>& GetPlane () const;
    const Sphere3<Real>& GetSphere () const;

    // Static intersection queries.
    virtual bool Test ();
    virtual bool Find ();

    // The intersection set is a single point when the plane is tangent to
    // the sphere.  Use this function when GetIntersectionType() returns
    // IT_POINT.
    const Vector3<Real>& GetIntersectionPoint () const;

    // The intersection set is a circle whenn the plane cuts through the
    // sphere.  Use this function when GetIntersectionType() returns
    // IT_OTHER.
    const Circle3<Real>& GetIntersectionCircle () const;

    // Culling support.  The view frustum is assumed to be on the positive
    // side of the plane.  The sphere is culled if it is on the negative
    // side of the plane.
    bool SphereIsCulled () const;

protected:
    using Intersector<Real,Vector3<Real> >::IT_EMPTY;
    using Intersector<Real,Vector3<Real> >::IT_POINT;
    using Intersector<Real,Vector3<Real> >::IT_OTHER;  // circle
    using Intersector<Real,Vector3<Real> >::m_iIntersectionType;

    // the objects to intersect
    const Plane3<Real>& m_rkPlane;
    const Sphere3<Real>& m_rkSphere;

    // information about the intersection set
    Vector3<Real> m_kIntersectionPoint;
    Circle3<Real> m_kIntersectionCircle;
};

typedef IntrPlane3Sphere3<float> IntrPlane3Sphere3f;
typedef IntrPlane3Sphere3<double> IntrPlane3Sphere3d;

}

#endif

