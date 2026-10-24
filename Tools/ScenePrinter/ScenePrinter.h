// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef SCENEPRINTER_H
#define SCENEPRINTER_H

#include "Wm3ConsoleApplication.h"
using namespace Wm3;

class ScenePrinter : public ConsoleApplication
{
    WM3_DECLARE_INITIALIZE;

public:
    virtual int Main (int iQuantity, char** apcArgument);

protected:
    void Usage ();
};

WM3_REGISTER_INITIALIZE(ScenePrinter);

#endif

