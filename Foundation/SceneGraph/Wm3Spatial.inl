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
inline void Spatial::SetParent (Spatial* pkParent)
{
    m_pkParent = pkParent;
}
//----------------------------------------------------------------------------
inline Spatial* Spatial::GetParent ()
{
    return m_pkParent;
}
//----------------------------------------------------------------------------
inline void Spatial::SetEffect (Effect* pkEffect)
{
    m_spkEffect = pkEffect;
}
//----------------------------------------------------------------------------
inline Effect* Spatial::GetEffect () const
{
    return m_spkEffect;
}
//----------------------------------------------------------------------------

