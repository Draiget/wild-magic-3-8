// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM3VEMANIFOLDMESH_H
#define WM3VEMANIFOLDMESH_H

#include "Wm3FoundationLIB.h"
#include "Wm3System.h"
#include <map>

namespace Wm3
{

class WM3_ITEM VEManifoldMesh
{
public:
    // vertex data types
    class Vertex;
    typedef Vertex* VPtr;
    typedef const Vertex* VCPtr;
    typedef VPtr (*VCreator)(int);
    typedef std::map<int,Vertex*> VMap;
    typedef VMap::iterator VMapIterator;
    typedef VMap::const_iterator VMapCIterator;

    // edge data types
    class Edge;
    typedef Edge* EPtr;
    typedef const Edge* ECPtr;
    typedef EPtr (*ECreator)(int,int);
    typedef std::map<std::pair<int,int>,Edge*> EMap;
    typedef EMap::iterator EMapIterator;
    typedef EMap::const_iterator EMapCIterator;

    // vertex object
    class WM3_ITEM Vertex
    {
    public:
        Vertex (int iV);
        virtual ~Vertex ();

        int V;
        EPtr E[2];
    };

    // edge object
    class WM3_ITEM Edge
    {
    public:
        Edge (int iV0, int iV1);
        virtual ~Edge ();

        // vertices, listed as a directed edge <V[0],V[1]>
        int V[2];

        // adjacent edges
        //   E[0] points to edge sharing V[0]
        //   E[1] points to edge sharing V[1]
        EPtr E[2];
    };


    // construction and destruction
    VEManifoldMesh (VCreator oVCreator = 0, ECreator oECreator = 0);
    virtual ~VEManifoldMesh ();

    // member access
    const VMap& GetVertices () const;
    const EMap& GetEdges () const;

    // mesh manipulation
    EPtr InsertEdge (int iV0, int iV1);
    bool RemoveEdge (int iV0, int iV1);

    // manifold mesh is closed if each vertex is shared twice
    bool IsClosed () const;

    void Print (const char* acFilename);

protected:
    // vertices
    static VPtr CreateVertex (int iV0);
    VCreator m_oVCreator;
    VMap m_kVMap;

    // edges
    static EPtr CreateEdge (int iV0, int iV1);
    ECreator m_oECreator;
    EMap m_kEMap;
};

#include "Wm3VEManifoldMesh.inl"

}

#endif

