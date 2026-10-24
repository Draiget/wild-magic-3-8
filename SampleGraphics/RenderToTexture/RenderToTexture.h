// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef RENDERTOTEXTURE_H
#define RENDERTOTEXTURE_H

#include "Wm3WindowApplication3.h"
using namespace Wm3;

class RenderToTexture : public WindowApplication3
{
    WM3_DECLARE_INITIALIZE;

public:
    RenderToTexture ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnIdle ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);

protected:
    Node* CreateModel ();
    NodePtr m_spkScene;
    WireframeStatePtr m_spkWireframe;
    TextureEffectPtr m_spkTEffect;
    EnvironmentMapEffectPtr m_spkEMEffect;

    ScreenPolygonPtr m_spkSPolygon;
    TexturePtr m_spkRenderTarget;
};

WM3_REGISTER_INITIALIZE(RenderToTexture);

#endif

