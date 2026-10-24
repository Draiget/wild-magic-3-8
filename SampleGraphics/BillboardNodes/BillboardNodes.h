// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef BILLBOARDNODES_H
#define BILLBOARDNODES_H

#include "Wm3WindowApplication3.h"
using namespace Wm3;

class BillboardNodes : public WindowApplication3
{
    WM3_DECLARE_INITIALIZE;

public:
    BillboardNodes ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnIdle ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);

protected:
    void CreateScene ();

    NodePtr m_spkScene;
    BillboardNodePtr m_spkBillboard0, m_spkBillboard1;
    WireframeStatePtr m_spkWireframe;

private:
    void TestStream ();
};

WM3_REGISTER_INITIALIZE(BillboardNodes);

#endif

