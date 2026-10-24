// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef MULTIATTRIBUTEMESH_H
#define MULTIATTRIBUTEMESH_H

#include "Vertex.h"
#include "MeshData.h"
#include "Wm3TriMesh.h"
#include "Wm3Vector2Array.h"
#include "Wm3TArray.h"
using namespace Wm3;

// Usage:
//
// MultiattributeMesh kMAMesh;
// AddVertexLoc(0,spatial information)
// AddVertexLoc(1,spatial information)
// AddVertexLoc(2,spatial information)
// ...
// int iV0 = kMAMesh.UpdateVertexInfo(0,face specific info);
// int iV1 = kMAMesh.UpdateVertexInfo(1,face specific info);
// int iV2 = kMAMesh.UpdateVertexInfo(2,face specific info);
// kMAMesh.AddTriangle(iV0,iV1,iV2);
//
// Repeat the last four lines for each triangle.

class MultiattributeMesh
{
public:
    MultiattributeMesh ();
    void Reset ();

    // Adds spatial data into array at this location.
    void AddVertexLoc (int iV, const Vertex& rkVertex);

    // Adds UV/normal info, returning vertex index.  This may create "extra"
    // vertices if the vertex has multivalued information.
    int UpdateVertexInfo (int iV, const Vertex& rkVertex);

    void AddTriangle (int iV0, int iV1, int iV2);
    TriMesh* GetMesh (Vector2fArray*& rpkUV0, Vector2fArray*& rpkUV1,
        Vector2fArray*& rpkUV2, Vector2fArray*& rpkUV3);

    MeshData GetData ();

    enum { MAX_TEX_COORDS = 4 };

protected:
    TArray<Vertex> m_kVerts;
    int m_iVNext;
    TArray<int> m_kConnect;

    // Original verts -- ones created by AddVertexLoc, and not ones created
    // as a result of discontinuous information in AddVertexInfo
    int iOriginalVerts;

    // m_kVerts[i] was created from vertex 
    // m_kVerts[m_kVertMapping[i-OriginalVerts]] if i >= iOriginalVerts
    TArray<int> m_kVertMapping;
};

#endif

