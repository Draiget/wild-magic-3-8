// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef CONFORMALMAPPING_H
#define CONFORMALMAPPING_H

#include "Wm3WindowApplication3.h"
using namespace Wm3;

class ConformalMapping : public WindowApplication3
{
    WM3_DECLARE_INITIALIZE;

public:
    ConformalMapping ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnIdle ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);

protected:
    void ScaleToCube (float fExtreme);
    void PseudocolorVertices ();
    void DoMapping ();

    NodePtr m_spkScene;
    WireframeStatePtr m_spkWireframe;
    NodePtr m_spkMeshTree, m_spkSphereTree;
    TriMeshPtr m_spkMesh;
    TriMeshPtr m_spkSphere;

    float m_fExtreme;
};

WM3_REGISTER_INITIALIZE(ConformalMapping);

#endif

