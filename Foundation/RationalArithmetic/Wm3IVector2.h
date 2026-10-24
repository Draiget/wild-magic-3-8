// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM3IVECTOR2_H
#define WM3IVECTOR2_H

#include "Wm3FoundationLIB.h"
#include "Wm3TIVector.h"

namespace Wm3
{

class IVector2 : public TIVector<2>
{
public:
    // construction
    IVector2 ();
    IVector2 (const IVector2& rkV);

#ifdef WM3_USING_VC70
    IVector2 (const TIVector<2>& rkV)
    {
        m_aiTuple[0] = rkV[0];
        m_aiTuple[1] = rkV[1];
    }
#else
    IVector2 (const TIVector<2>& rkV);
#endif

    IVector2 (const Integer64& riX, const Integer64& riY);

    // member access
    Integer64 X () const;
    Integer64& X ();
    Integer64 Y () const;
    Integer64& Y ();

    // assignment
    IVector2& operator= (const IVector2& rkV);

#ifdef WM3_USING_VC70
    IVector2& operator= (const TIVector<2>& rkV)
    {
        m_aiTuple[0] = rkV[0];
        m_aiTuple[1] = rkV[1];
        return *this;
    }
#else
    IVector2& operator= (const TIVector<2>& rkV);
#endif

    // returns Dot(this,V)
    Integer64 Dot (const IVector2& rkV) const;

    // returns (y,-x)
    IVector2 Perp () const;

    // returns Cross((x,y,0),(V.x,V.y,0)) = x*V.y - y*V.x
    Integer64 Kross (const IVector2& rkV) const;

protected:
    using TIVector<2>::m_aiTuple;
};

#include "Wm3IVector2.inl"

}

#endif

