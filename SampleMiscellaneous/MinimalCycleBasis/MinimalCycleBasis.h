// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef MINIMALCYCLEBASIS_H
#define MINIMALCYCLEBASIS_H

#include "Wm3WindowApplication2.h"
#include "Wm3PlanarGraph.h"
#include <vector>
using namespace Wm3;

class MinimalCycleBasis : public WindowApplication2
{
    WM3_DECLARE_INITIALIZE;

public:
    MinimalCycleBasis ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnDisplay ();

protected:
    typedef PlanarGraph<IVector2> Graph;
    Graph m_kGraph;
    std::vector<Graph::Primitive*> m_kPrimitives;
    Color* m_akColor;
};

WM3_REGISTER_INITIALIZE(MinimalCycleBasis);

#endif

