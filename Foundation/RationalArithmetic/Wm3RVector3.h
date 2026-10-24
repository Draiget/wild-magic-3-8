// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM3RVECTOR3_H
#define WM3RVECTOR3_H

#include "Wm3FoundationLIB.h"
#include "Wm3TRVector.h"

namespace Wm3
{

template <int ISIZE>
class RVector3 : public TRVector<3,ISIZE>
{
public:
    // construction
    RVector3 ();
    RVector3 (const RVector3& rkV);

#ifdef WM3_USING_VC70
    RVector3 (const TRVector<3,ISIZE>& rkV)
    {
        // The inline body is here because of an apparent MSVC++ .NET 2002
        // compiler bug.  If placed in the *.inl file, the compiler complains:
        //
        //   error C2244: 'Wm3::RVector3<>::__ctor' : unable to match function
        //       definition to an existing declaration
        //   definition
        //       'Wm3::RVector3<>::RVector3(const Wm3::TRVector<3,> &)'
        //   existing declarations
        //       'Wm3::RVector3<>::RVector3(const Wm3::TRational<> &,
        //                                  const Wm3::TRational<> &)'
        //       'Wm3::RVector3<>::RVector3(const Wm3::TRVector<3,> &)'
        //       'Wm3::RVector3<>::RVector3(const Wm3::RVector3<> &)'
        //       'Wm3::RVector3<>::RVector3(void)'
        // The "definition" is in the "existing declarations" list, so I do
        // not know what the compiler is complaining about.

        m_akTuple[0] = rkV[0];
        m_akTuple[1] = rkV[1];
        m_akTuple[2] = rkV[2];
    }
#else
    RVector3 (const TRVector<3,ISIZE>& rkV);
#endif

    RVector3 (const TRational<ISIZE>& rkX, const TRational<ISIZE>& rkY,
        const TRational<ISIZE>& rkZ);

    // member access
    TRational<ISIZE> X () const;
    TRational<ISIZE>& X ();
    TRational<ISIZE> Y () const;
    TRational<ISIZE>& Y ();
    TRational<ISIZE> Z () const;
    TRational<ISIZE>& Z ();

    // assignment
    RVector3& operator= (const RVector3& rkV);

#ifdef WM3_USING_VC70
    RVector3& operator= (const TRVector<3,ISIZE>& rkV)
    {
        // The inline body is here because of an apparent MSVC++ .NET 2002
        // compiler bug.  If placed in the *.inl file, the compiler complains:
        //
        //   error C2244: 'Wm3::RVector3<>::operator`='' : unable to match
        //       function definition to an existing declaration
        //   definition
        //       'Wm3::RVector3<> &Wm3::RVector3<>::operator =(
        //            const Wm3::TRVector<3,> &)'
        //   existing declarations
        //       'Wm3::RVector3<> &Wm3::RVector3<>::operator =(
        //            const Wm3::TRVector<3,> &)'
        //       'Wm3::RVector3<> &Wm3::RVector3<>::operator =(
        //            const Wm3::RVector3<> &)'

        m_akTuple[0] = rkV[0];
        m_akTuple[1] = rkV[1];
        m_akTuple[2] = rkV[2];
        return *this;
    }
#else
    RVector3& operator= (const TRVector<3,ISIZE>& rkV);
#endif

    // returns Dot(this,V)
    TRational<ISIZE> Dot (const RVector3& rkV) const;

    // returns Cross(this,V)
    RVector3 Cross (const RVector3& rkV) const;

    // returns Dot(this,Cross(U,V))
    TRational<ISIZE> TripleScalar (const RVector3& rkU, const RVector3& rkV)
        const;

protected:
    using TRVector<3,ISIZE>::m_akTuple;
};

#include "Wm3RVector3.inl"

}

#endif

