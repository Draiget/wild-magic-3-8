// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef CONVEXHULL2D_H
#define CONVEXHULL2D_H

#include "Wm3WindowApplication2.h"
using namespace Wm3;

class ConvexHull2D : public WindowApplication2
{
    WM3_DECLARE_INITIALIZE;

public:
    ConvexHull2D ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnDisplay ();
    virtual void ScreenOverlay ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);

protected:
    void GenerateHull0D ();
    void GenerateHull1D ();
    void GenerateHull2D ();
    void GenerateHullManyCollinear ();
    void RegenerateHull ();
    int UnitToScreen (float fValue);

    const float m_fEpsilon;
    Query::Type m_eQueryType;
    ConvexHullf* m_pkHull;
    int m_iVQuantity;
    Vector2f* m_akVertex;
};

WM3_REGISTER_INITIALIZE(ConvexHull2D);

#endif

