// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM3GLOBALSTATE_H
#define WM3GLOBALSTATE_H

#include "Wm3FoundationLIB.h"
#include "Wm3Object.h"

namespace Wm3
{

class WM3_ITEM GlobalState : public Object
{
    WM3_DECLARE_RTTI;
    WM3_DECLARE_NAME_ID;
    WM3_DECLARE_STREAM;

public:
    // abstract base class
    virtual ~GlobalState ();

    // supported global states
    enum // Type
    {
        ALPHA,
        CULL,
        DITHER,
        FOG,
        MATERIAL,
        SHADE,
        WIREFRAME,
        ZBUFFER,
        MAX_STATE
    };

    virtual int GetGlobalStateType () const = 0;

    // default states
    static Pointer<GlobalState> Default[MAX_STATE];

protected:
    GlobalState ();
};

WM3_REGISTER_STREAM(GlobalState);
typedef Pointer<GlobalState> GlobalStatePtr;

}

#endif

