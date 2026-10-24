// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM3CONTCYLINDER3_H
#define WM3CONTCYLINDER3_H

#include "Wm3FoundationLIB.h"
#include "Wm3Cylinder3.h"

namespace Wm3
{

// Compute the cylinder axis segment using least-squares fit.  The radius is
// the maximum distance from points to the axis.  The height is determined by
// projection of points onto the axis and determining the containing interval.
template <class Real> WM3_ITEM
Cylinder3<Real> ContCylinder (int iQuantity, const Vector3<Real>* akPoint);

}

#endif

