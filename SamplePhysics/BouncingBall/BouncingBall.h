// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef BOUNCINGBALL_H
#define BOUNCINGBALL_H

#include "Wm3WindowApplication3.h"
#include "DeformableBall.h"
using namespace Wm3;

class BouncingBall : public WindowApplication3
{
    WM3_DECLARE_INITIALIZE;

public:
    BouncingBall ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnIdle ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);

protected:
    void CreateBall ();
    void CreateFloor ();
    void CreateWall ();
    void DoPhysical ();
    void DoVisual ();

    // representation of body
    DeformableBall* m_pkBall;

    // simulated clock
    float m_fSimTime, m_fSimDelta;

    // the scene graph
    NodePtr m_spkScene, m_spkBall;
    TriMeshPtr m_spkFloor, m_spkWall;
    WireframeStatePtr m_spkWireframeState;
};

WM3_REGISTER_INITIALIZE(BouncingBall);

#endif

