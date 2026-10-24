// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM3INTPAKIMAUNIFORM1_H
#define WM3INTPAKIMAUNIFORM1_H

#include "Wm3FoundationLIB.h"
#include "Wm3IntpAkima1.h"

namespace Wm3
{

template <class Real>
class WM3_ITEM IntpAkimaUniform1 : public IntpAkima1<Real>
{
public:
    // Construction and destruction.  IntpAkimaUniform1 accepts
    // responsibility for deleting the input array.  The interpolator is for
    // uniformly spaced x-values.
    IntpAkimaUniform1 (int iQuantity, Real fXMin, Real fXSpacing, Real* afF);
    virtual ~IntpAkimaUniform1 ();

    virtual Real GetXMin () const;
    virtual Real GetXMax () const;
    Real GetXSpacing () const;

protected:
    using IntpAkima1<Real>::m_iQuantity;
    using IntpAkima1<Real>::m_akPoly;

    virtual bool Lookup (Real fX, int& riIndex, Real& rfDX) const;

    Real m_fXMin, m_fXMax, m_fXSpacing;
};

typedef IntpAkimaUniform1<float> IntpAkimaUniform1f;
typedef IntpAkimaUniform1<double> IntpAkimaUniform1d;

}

#endif

