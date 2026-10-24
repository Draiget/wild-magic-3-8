// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM3EXTREMALQUERY3PRJ_H
#define WM3EXTREMALQUERY3PRJ_H

#include "Wm3FoundationLIB.h"
#include "Wm3ExtremalQuery3.h"

namespace Wm3
{

template <class Real>
class WM3_ITEM ExtremalQuery3PRJ : public ExtremalQuery3<Real>
{
public:
    ExtremalQuery3PRJ (const ConvexPolyhedron3<Real>& rkPolytope);
    virtual ~ExtremalQuery3PRJ ();

    // Compute the extreme vertices in the specified direction and return the
    // indices of the vertices in the polyhedron vertex array.
    virtual void GetExtremeVertices (const Vector3<Real>& rkDirection,
        int& riPositiveDirection, int& riNegativeDirection);

private:
    using ExtremalQuery3<Real>::m_rkPolytope;

    Vector3<Real> m_kCentroid;
};

typedef ExtremalQuery3PRJ<float> ExtremalQuery3PRJf;
typedef ExtremalQuery3PRJ<double> ExtremalQuery3PRJd;

}

#endif

