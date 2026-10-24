// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef PORTALS_H
#define PORTALS_H

#include "Wm3WindowApplication3.h"
using namespace Wm3;

class Portals : public WindowApplication3
{
    WM3_DECLARE_INITIALIZE;

public:
    Portals ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnIdle ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);

protected:
    static void CreateCenterCube (ImagePtr& rspkFloor, ImagePtr& rspkCeiling,
        ImagePtr& rspkWall, ImagePtr& rspkPicture0, ImagePtr& rspkPicture1,
        ImagePtr& rspkPicture2, ImagePtr& rspkPicture3, Node*& rpkCube,
        Portal**& rapkPortal);

    static void CreateAxisConnector (ImagePtr& rspkFloor,
        ImagePtr& rspkCeiling, ImagePtr& rspkWall, Node*& rpkCube,
        Portal**& rapkPortal);

    static void CreateEndCube (ImagePtr& rspkFloor, ImagePtr& rspkCeiling,
        ImagePtr& rspkWall, Node*& rpkCube, Portal**& rapkPortal);

    static void CreateDiagonalConnector (ImagePtr& rspkFloor,
        ImagePtr& rspkCeiling, ImagePtr& rspkWall, Node*& rpkCube,
        Portal**& rapkPortal);

    TriMesh* CreateOutside ();
    bool InitializeTextures ();
    ConvexRegionManager* CreateBspTree ();

    NodePtr m_spkScene;
    WireframeStatePtr m_spkWireframe;
    ImagePtr m_spkFloor, m_spkCeiling, m_spkWall1, m_spkWall2;
    ImagePtr m_spkAgate, m_spkBark, m_spkSky, m_spkWater;

private:
    void TestStream ();
};

WM3_REGISTER_INITIALIZE(Portals);

#endif

