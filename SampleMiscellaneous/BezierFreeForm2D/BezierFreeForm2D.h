// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef BEZIERFREEFORM2D_H
#define BEZIERFREEFORM2D_H

#include "Wm3WindowApplication2.h"
#include "BezierTensorPatch.h"
using namespace Wm3;

class BezierFreeForm2D : public WindowApplication2
{
    WM3_DECLARE_INITIALIZE;

public:
    BezierFreeForm2D ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnDisplay ();

    // Allows user to drag control points.
    virtual bool OnMouseClick (int iButton, int iState, int iX, int iY,
        unsigned int uiModifiers);
    virtual bool OnMotion (int iButton, int iX, int iY,
        unsigned int uiModifiers);

protected:
    float ScreenToControl (int iScreen) const;
    int ControlToScreen (float fControl) const;
    Vector2f Evaluate (const Vector2f& rkParam) const;
    void SelectVertex (int iXMouse, int iYMouse);

    // The image to map to the free-form region.
    Image* m_pkImage;

    // A surface patch with numCtrl[0]-by-numCtrl[1] control points.
    BezierTensorPatch* m_pkPatch;

    // The control points that define the free-form region on the screen.
    int** m_aaiCtrlX;  // ctrlX[numCtrl[1]][numCtrl[0]]
    int** m_aaiCtrlY;  // ctrlY[numCtrl[1]][numCtrl[0]]

    // Support for dragging the control points.
    bool m_bMouseDown;
    int m_iXCurr, m_iYCurr;
};

WM3_REGISTER_INITIALIZE(BezierFreeForm2D);

#endif

