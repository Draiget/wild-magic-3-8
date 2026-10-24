// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

//----------------------------------------------------------------------------
template <class Real>
Triangle2<Real>::Triangle2 ()
{
    // uninitialized
}
//----------------------------------------------------------------------------
template <class Real>
Triangle2<Real>::Triangle2 (const Vector2<Real>& rkV0,
    const Vector2<Real>& rkV1, const Vector2<Real>& rkV2)
{
    V[0] = rkV0;
    V[1] = rkV1;
    V[2] = rkV2;
}
//----------------------------------------------------------------------------
template <class Real>
Triangle2<Real>::Triangle2 (const Vector2<Real> akV[3])
{
    for (int i = 0; i < 3; i++)
    {
        V[i] = akV[i];
    }
}
//----------------------------------------------------------------------------

