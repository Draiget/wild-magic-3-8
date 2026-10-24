// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef CHARCOALEFFECTS_H
#define CHARCOALEFFECTS_H

#include "Wm3WindowApplication3.h"
#include "Wm3CharcoalEffect.h"
using namespace Wm3;

class CharcoalEffects : public WindowApplication3
{
    WM3_DECLARE_INITIALIZE;

public:
    CharcoalEffects ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnIdle ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);

protected:
    void CreateScene ();
    void AttachShader (Spatial* pkObject);
    void UpdateConstants ();

    NodePtr m_spkScene;
    CharcoalEffectPtr m_spkEffect;
    bool m_bSmudge, m_bDisplayPaper, m_bDisplayLighting;

private:
    void TestStream ();
};

WM3_REGISTER_INITIALIZE(CharcoalEffects);

#endif

