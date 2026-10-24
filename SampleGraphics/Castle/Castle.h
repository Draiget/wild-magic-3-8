// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef CASTLE_H
#define CASTLE_H

#include "Wm3WindowApplication3.h"
using namespace Wm3;

class Castle : public WindowApplication3
{
    WM3_DECLARE_INITIALIZE;

public:
    Castle ();
    virtual ~Castle ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnIdle ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);
    virtual bool OnMouseClick (int iButton, int iState, int iX, int iY,
        unsigned int uiModifiers);

protected:
    // arrange for camera to be fixed distance above the nearest object
    void AdjustVerticalDistance ();
    virtual void MoveForward ();
    virtual void MoveBackward ();
    float m_fVerticalDistance;

    void SetAllWireframe (Spatial* pkSpatial);
    void ToggleAllWireframe (Spatial* pkSpatial);

    NodePtr m_spkScene;
    NodePtr m_spkModel;

    // name of picked object
    enum { PICKED_SIZE = 1024 };
    char m_acPicked[PICKED_SIZE];

    // pick ray parameters
    bool AllowMotion (float fSign);
    int m_iNumRays;
    float m_fHalfAngle;
    float* m_afCos;
    float* m_afSin;
    float* m_afTolerance;
};

WM3_REGISTER_INITIALIZE(Castle);

#endif

