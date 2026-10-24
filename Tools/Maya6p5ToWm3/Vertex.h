// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef VERTEX_H
#define VERTEX_H

class Vertex
{
public:
    Vertex ();
    Vertex (float fPx, float fPy, float fPz, float fNx, float fNy, float fNz,
        float fR, float fG, float fB, float fA, float fU0, float fV0,
        float fU1, float fV1, float fU2, float fV2, float fU3, float fV3);

    Vertex (const Vertex& rkV);
    Vertex& operator= (const Vertex& rkV);

    float& operator[] (int i);
    float operator[] (int i) const;
    bool operator< (const Vertex& rkV) const;
    bool operator== (const Vertex& rkV) const;

    enum { MAXVALUES = 18 };

private:
    // Packed array of position (Vector3), normal (Vector3),
    // color (ColorRGB), alpha (float), uv0 (Vector2), uv1 (Vector2),
    // uv2 (Vector2), uv3 (Vector2).  The total number of float values is 18.
    float m_afValue[MAXVALUES];
};

#include "Vertex.inl"

#endif

