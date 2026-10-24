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
inline int Stream::GetOrderedQuantity () const
{
    return m_kOrdered.GetQuantity();
}
//----------------------------------------------------------------------------
inline Object* Stream::GetOrderedObject (int i) const
{
    assert(0 <= i && i < m_kOrdered.GetQuantity());
    return m_kOrdered[i];
}
//----------------------------------------------------------------------------
inline int Stream::GetBufferSize () const
{
    return m_iBufferSize;
}
//----------------------------------------------------------------------------
inline int Stream::GetBufferNext () const
{
    return m_iBufferNext;
}
//----------------------------------------------------------------------------
inline StreamVersion Stream::GetVersion () const
{
    return m_kVersion;
}
//----------------------------------------------------------------------------

