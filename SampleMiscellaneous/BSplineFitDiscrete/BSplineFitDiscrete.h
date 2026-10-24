// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef BSPLINEFITDISCRETE_H
#define BSPLINEFITDISCRETE_H

#include "Wm3WindowApplication3.h"
#include "Wm3BSplineFit.h"
using namespace Wm3;

class BSplineFitDiscrete : public WindowApplication3
{
    WM3_DECLARE_INITIALIZE;

public:
    BSplineFitDiscrete ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnIdle ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);

protected:
    void CreateScene ();
    void CreateBSplinePolyline ();

    NodePtr m_spkScene;
    VertexColorEffectPtr m_spkEffect;

    int m_iSampleQuantity;
    Vector3f* m_akSample;
    int m_iDegree;
    int m_iCtrlQuantity;
    BSplineFitf* m_pkBSpline;

    enum { MESSAGE_SIZE = 128 };
    char m_acMessage[MESSAGE_SIZE];
};

WM3_REGISTER_INITIALIZE(BSplineFitDiscrete);

#endif

