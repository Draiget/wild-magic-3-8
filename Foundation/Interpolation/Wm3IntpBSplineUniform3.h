// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM3INTPBSPLINEUNIFORM3_H
#define WM3INTPBSPLINEUNIFORM3_H

#include "Wm3FoundationLIB.h"
#include "Wm3IntpBSplineUniform.h"

namespace Wm3
{

template <class Real>
class WM3_ITEM IntpBSplineUniform3 : public IntpBSplineUniform<Real>
{
public:
    // Construction.  IntpBSplineUniform3 accepts responsibility for
    // deleting the input array afData.
    IntpBSplineUniform3 (int iDegree, const int* aiDim, Real* afData);

    int Index (int iX, int iY, int iZ) const;

    // spline evaluation for function interpolation (no derivatives)
    Real operator() (Real fX, Real fY, Real fZ);
    virtual Real operator() (Real* afX);

    // spline evaluation, derivative counts given in iDx, iDy, iDz, aiDx[]
    Real operator() (int iDx, int iDy, int iDz, Real fX, Real fY, Real fZ);
    virtual Real operator() (int* aiDx, Real* afX);

private:
    using IntpBSplineUniform<Real>::m_iDegree;
    using IntpBSplineUniform<Real>::m_iDp1;
    using IntpBSplineUniform<Real>::m_iDp1ToN;
    using IntpBSplineUniform<Real>::m_aiDim;
    using IntpBSplineUniform<Real>::m_afData;
    using IntpBSplineUniform<Real>::m_aiGridMin;
    using IntpBSplineUniform<Real>::m_aiGridMax;
    using IntpBSplineUniform<Real>::m_aiBase;
    using IntpBSplineUniform<Real>::m_aiOldBase;
    using IntpBSplineUniform<Real>::m_aafMatrix;
    using IntpBSplineUniform<Real>::m_afCache;
    using IntpBSplineUniform<Real>::m_afInter;
    using IntpBSplineUniform<Real>::m_aafPoly;
    using IntpBSplineUniform<Real>::m_afProduct;
    using IntpBSplineUniform<Real>::m_aiSkip;
    using IntpBSplineUniform<Real>::m_oEvaluateCallback;

    void EvaluateUnknownData ();
    void ComputeIntermediate ();
};

typedef IntpBSplineUniform3<float> IntpBSplineUniform3f;
typedef IntpBSplineUniform3<double> IntpBSplineUniform3d;

}

#endif

