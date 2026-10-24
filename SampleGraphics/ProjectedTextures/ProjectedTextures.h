// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef PROJECTEDTEXTURES_H
#define PROJECTEDTEXTURES_H

#include "Wm3WindowApplication3.h"
using namespace Wm3;

class ProjectedTextures : public WindowApplication3
{
    WM3_DECLARE_INITIALIZE;

public:
    ProjectedTextures ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnIdle ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);

protected:
    NodePtr CreateModel ();

    NodePtr m_spkScene;

private:
    void TestStream ();
};

WM3_REGISTER_INITIALIZE(ProjectedTextures);

#endif

