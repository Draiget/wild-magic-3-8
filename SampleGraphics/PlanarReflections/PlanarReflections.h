// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef PLANARREFLECTIONS_H
#define PLANARREFLECTIONS_H

#include "Wm3WindowApplication3.h"
using namespace Wm3;

class PlanarReflections : public WindowApplication3
{
    WM3_DECLARE_INITIALIZE;

public:
    PlanarReflections ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnIdle ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);

protected:
    void LoadBiped ();
    void CreatePlanes ();
    void CreatePlanarReflection ();

    NodePtr m_spkScene;
    NodePtr m_spkBiped;
    TriMeshPtr m_spkPlane0, m_spkPlane1;
    WireframeStatePtr m_spkWireframe;

    double m_dAnimTime, m_dAnimTimeDelta;

private:
    void TestStream ();
};

WM3_REGISTER_INITIALIZE(PlanarReflections);

#endif

