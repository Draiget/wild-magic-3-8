// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef BEZIERTENSORPATCH_H
#define BEZIERTENSORPATCH_H

#include "Wm3Vector2.h"

class BezierTensorPatch
{
public:
    BezierTensorPatch (int iXDegree, int iYDegree);
    ~BezierTensorPatch ();

    int GetDegree (int i) const;
    int GetControlQuantity (int i) const;
    void SetControl (int iX, int iY, const Wm3::Vector2f& rkCtrl);
    Wm3::Vector2f GetControl (int iX, int iY) const;

    Wm3::Vector2f Evaluate (const Wm3::Vector2f& rkParam) const;

private:
    int m_aiDegree[2];                  // d[i] >= 1
    int m_aiNumCtrl[2];                 // numCtrl[i] = d[i]+1
    Wm3::Vector2f** m_aakCtrl;          // ctrl[numCtrl[0]][numCtrl[1]]
    mutable Wm3::Vector2f* m_akTmpX;    // tmpX[numCtrl[0]]
    mutable Wm3::Vector2f* m_akTmpY;    // tmpX[numCtrl[1]]
};

#endif

