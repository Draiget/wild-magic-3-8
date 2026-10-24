// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef RIGIDBALL_H
#define RIGIDBALL_H

#include "Wm3RigidBody.h"
#include "Wm3TriMesh.h"
using namespace Wm3;

class RigidBall : public RigidBodyf
{
public:
    RigidBall (float fRadius = 1.0f);

    TriMeshPtr& Mesh ();
    float GetRadius () const;

    bool Moved;

private:
    TriMeshPtr m_spkMesh;
    float m_fRadius;
};

#endif

