// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM3CONTELLIPSE2_H
#define WM3CONTELLIPSE2_H

#include "Wm3FoundationLIB.h"
#include "Wm3Ellipse2.h"
#include "Wm3Line2.h"

namespace Wm3
{

// The input points are fit with a Gaussian distribution.  The center C of the
// ellipsoid is chosen to be the mean of the distribution.  The axes of the
// ellipsoid are chosen to be the eigenvectors of the covariance matrix M.
// The shape of the ellipsoid is determined by the absolute values of the
// eigenvalues.
//
// WARNING.  The construction is ill-conditioned if the points are (nearly)
// collinear.  In this case M has a (nearly) zero eigenvalue, so inverting M
// is problematic.
template <class Real> WM3_ITEM
Ellipse2<Real> ContEllipse (int iQuantity, const Vector2<Real>* akPoint);

// Project an ellipse onto a line.  The projection interval is [min,max]
// and corresponds to the line segment P+t*D, where min <= t <= max.
template <class Real> WM3_ITEM
void ProjectEllipse (const Ellipse2<Real>& rkEllipse,
    const Line2<Real>& rkLine, Real& rfMin, Real& rfMax);

// Construct a bounding ellipse for the two input ellipses.
template <class Real> WM3_ITEM
const Ellipse2<Real> MergeEllipses (const Ellipse2<Real>& rkEllipse0,
    const Ellipse2<Real>& rkEllipse1);

}

#endif

