// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#include "Wm3FoundationPCH.h"
#include "Wm3IntpVectorField2.h"

namespace Wm3
{
//----------------------------------------------------------------------------
template <class Real>
IntpVectorField2<Real>::IntpVectorField2 (int iQuantity,
    Vector2<Real>* akInput, Vector2<Real>* akOutput, bool bOwner,
    Query::Type eQueryType)
{
    // Repackage the output vectors into individual components.  This is
    // required because of the format that the quadratic interpolator expects
    // for its input data.
    Real* afXOutput = WM3_NEW Real[iQuantity];
    Real* afYOutput = WM3_NEW Real[iQuantity];
    for (int i = 0; i < iQuantity; i++)
    {
        afXOutput[i] = akOutput[i].X();
        afYOutput[i] = akOutput[i].Y();
    }

    if (bOwner)
    {
        WM3_DELETE[] akOutput;
    }

    // common triangulator for the interpolators
    m_pkDel = WM3_NEW Delaunay2<Real>(iQuantity,akInput,(Real)0.001,bOwner,
        eQueryType);

    // Create interpolator for x-coordinate of vector field.
    m_pkXInterp = WM3_NEW IntpQdrNonuniform2<Real>(*m_pkDel,afXOutput,true);

    // Create interpolator for y-coordinate of vector field, but share the
    // already created triangulation for the x-interpolator.
    m_pkYInterp = WM3_NEW IntpQdrNonuniform2<Real>(*m_pkDel,afYOutput,true);
}
//----------------------------------------------------------------------------
template <class Real>
IntpVectorField2<Real>::~IntpVectorField2 ()
{
    WM3_DELETE m_pkDel;
    WM3_DELETE m_pkXInterp;
    WM3_DELETE m_pkYInterp;
}
//----------------------------------------------------------------------------
template <class Real>
bool IntpVectorField2<Real>::Evaluate (const Vector2<Real>& rkInput,
    Vector2<Real>& rkOutput)
{
    Real fXDeriv, fYDeriv;
    return m_pkXInterp->Evaluate(rkInput,rkOutput.X(),fXDeriv,fYDeriv)
        && m_pkYInterp->Evaluate(rkInput,rkOutput.Y(),fXDeriv,fYDeriv);
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// explicit instantiation
//----------------------------------------------------------------------------
template WM3_ITEM
class IntpVectorField2<float>;

template WM3_ITEM
class IntpVectorField2<double>;
//----------------------------------------------------------------------------
}

