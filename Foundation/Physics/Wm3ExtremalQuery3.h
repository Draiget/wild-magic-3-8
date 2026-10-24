// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM3EXTREMALQUERY3_H
#define WM3EXTREMALQUERY3_H

#include "Wm3FoundationLIB.h"
#include "Wm3ConvexPolyhedron3.h"

namespace Wm3
{

template <class Real>
class WM3_ITEM ExtremalQuery3
{
public:
    // Abstract base class.
    virtual ~ExtremalQuery3 ();

    // Compute the extreme vertices in the specified direction and return the
    // indices of the vertices in the polyhedron vertex array.
    virtual void GetExtremeVertices (const Vector3<Real>& rkDirection,
        int& riPositiveDirection, int& riNegativeDirection) = 0;

    const ConvexPolyhedron3<Real>& GetPolytope () const;
    const Vector3<Real>* GetFaceNormals () const;

protected:
    ExtremalQuery3 (const ConvexPolyhedron3<Real>& rkPolytope);

    const ConvexPolyhedron3<Real>& m_rkPolytope;
    Vector3<Real>* m_akFaceNormal;
};

typedef ExtremalQuery3<float> ExtremalQuery3f;
typedef ExtremalQuery3<double> ExtremalQuery3d;

}

#endif

