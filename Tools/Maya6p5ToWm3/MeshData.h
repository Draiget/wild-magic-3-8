// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef MESHDATA_H
#define MESHDATA_H

#include <maya/MString.h>
#include "Wm3IntArray.h"
using namespace Wm3;

// This class is a "struct" class to hold data about meshes.  This data
// contains the mappings from "new vertices" to original Maya vertices.

class MeshData
{
public:
    MeshData ();
    MeshData (int iNumOrigVert, IntArrayPtr spkVertMap);
    ~MeshData ();

    MeshData& operator= (const MeshData& rkData);

    int GetNumOrigVerts ();
    int GetMapping (int iIndex);

protected:
    // The number of vertices in the original mesh, before any splitting.
    int m_iNumOrigVert;

    // A mapping from original vertices to old vertices.  If akVert is an
    // array of vertices, then akVert[i] maps to
    // index m_aiVertMap[i-m_iNumOrigVert].  If i < m_iNumOrigVert, then
    // akVert[i] is an original vertex.
    IntArrayPtr m_spkVertMap;
};

#endif

