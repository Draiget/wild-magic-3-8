// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#include "Wm3FoundationPCH.h"
#include "Wm3GlobalState.h"
using namespace Wm3;

WM3_IMPLEMENT_RTTI(Wm3,GlobalState,Object);
WM3_IMPLEMENT_ABSTRACT_STREAM(GlobalState);
WM3_IMPLEMENT_DEFAULT_STREAM(GlobalState,Object);
WM3_IMPLEMENT_DEFAULT_NAME_ID(GlobalState,Object);

GlobalStatePtr GlobalState::Default[GlobalState::MAX_STATE];

//----------------------------------------------------------------------------
GlobalState::GlobalState ()
{
}
//----------------------------------------------------------------------------
GlobalState::~GlobalState ()
{
}
//----------------------------------------------------------------------------

