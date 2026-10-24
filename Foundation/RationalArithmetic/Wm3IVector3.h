// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM3IVECTOR3_H
#define WM3IVECTOR3_H

#include "Wm3FoundationLIB.h"
#include "Wm3TIVector.h"

namespace Wm3
{

class IVector3 : public TIVector<3>
{
public:
    // construction
    IVector3 ();
    IVector3 (const IVector3& rkV);

#ifdef WM3_USING_VC70
    IVector3 (const TIVector<3>& rkV)
    {
        m_aiTuple[0] = rkV[0];
        m_aiTuple[1] = rkV[1];
        m_aiTuple[2] = rkV[2];
    }
#else
    IVector3 (const TIVector<3>& rkV);
#endif

    IVector3 (const Integer64& riX, const Integer64& riY,
        const Integer64& riZ);

    // member access
    Integer64 X () const;
    Integer64& X ();
    Integer64 Y () const;
    Integer64& Y ();
    Integer64 Z () const;
    Integer64& Z ();

    // assignment
    IVector3& operator= (const IVector3& rkV);

#ifdef WM3_USING_VC70
    IVector3& operator= (const TIVector<3>& rkV)
    {
        m_aiTuple[0] = rkV[0];
        m_aiTuple[1] = rkV[1];
        m_aiTuple[2] = rkV[2];
        return *this;
    }
#else
    IVector3& operator= (const TIVector<3>& rkV);
#endif

    // returns Dot(this,V)
    Integer64 Dot (const IVector3& rkV) const;

    // returns Cross(this,V)
    IVector3 Cross (const IVector3& rkV) const;

    // returns Dot(this,Cross(U,V))
    Integer64 TripleScalar (const IVector3& rkU, const IVector3& rkV) const;

protected:
    using TIVector<3>::m_aiTuple;
};

#include "Wm3IVector3.inl"

}

#endif

