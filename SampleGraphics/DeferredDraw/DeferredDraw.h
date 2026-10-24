// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef DEFERREDDRAW_H
#define DEFERREDDRAW_H

#include "Wm3WindowApplication3.h"
using namespace Wm3;

class DeferredDraw : public WindowApplication3
{
    WM3_DECLARE_INITIALIZE;

public:
    DeferredDraw ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnIdle ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);

protected:
    Node* CreateModel ();
    Node* CreateFlat ();
    NodePtr m_spkScene;
    TextureEffectPtr m_spkTEffect;
    EnvironmentMapEffectPtr m_spkEMEffect;
};

WM3_REGISTER_INITIALIZE(DeferredDraw);

#endif

