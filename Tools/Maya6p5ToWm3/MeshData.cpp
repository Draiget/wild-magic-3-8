// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#include "MeshData.h"

//----------------------------------------------------------------------------
MeshData::MeshData ()
{
    m_iNumOrigVert = 0;
    m_spkVertMap = 0;
}
//----------------------------------------------------------------------------
MeshData::MeshData (int iNumOrigVert, IntArrayPtr spkVertMap)
{
    m_iNumOrigVert = iNumOrigVert;
    m_spkVertMap = spkVertMap;
}
//----------------------------------------------------------------------------
MeshData::~MeshData ()
{
    m_spkVertMap = 0;
}
//----------------------------------------------------------------------------
MeshData& MeshData::operator= (const MeshData& rkData)
{
    m_iNumOrigVert = rkData.m_iNumOrigVert;
    m_spkVertMap = rkData.m_spkVertMap;
    return *this;
}
//----------------------------------------------------------------------------
int MeshData::GetNumOrigVerts ()
{
    return m_iNumOrigVert;
}
//----------------------------------------------------------------------------
int MeshData::GetMapping (int iIndex)
{
    return ((*m_spkVertMap)[iIndex]);
}
//----------------------------------------------------------------------------

