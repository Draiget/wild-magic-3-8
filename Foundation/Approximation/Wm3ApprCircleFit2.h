// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM3APPRCIRCLEFIT2_H
#define WM3APPRCIRCLEFIT2_H

#include "Wm3FoundationLIB.h"
#include "Wm3Circle2.h"

namespace Wm3
{

// Least-squares fit of a circle to a set of points.  Successful fit is
// indicated by return value of 'true'.  If return value is false, number of
// iterations was exceeded.  Try increasing the maximum number of iterations.
//
// If bInitialCenterIsAverage is set to 'true', the initial guess for the
// circle center is the average of the data points.  If the data points are
// clustered along a small arc, CircleFit2 is very slow to converge.  If
// bInitialCenterIsAverage is set to 'false', the initial guess for the
// circle center is computed using a least-squares estimate of the
// coefficients for a quadratic equation that represents a circle.  This
// approach tends to converge rapidly.

template <class Real> WM3_ITEM
bool CircleFit2 (int iQuantity, const Vector2<Real>* akPoint,
    int iMaxIterations, Circle2<Real>& rkCircle,
    bool bInitialCenterIsAverage);

}

#endif

