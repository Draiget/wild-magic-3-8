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
#include "Wm3CullState.h"
using namespace Wm3;

WM3_IMPLEMENT_RTTI(Wm3,CullState,GlobalState);
WM3_IMPLEMENT_STREAM(CullState);
WM3_IMPLEMENT_DEFAULT_NAME_ID(CullState,GlobalState);
WM3_IMPLEMENT_INITIALIZE(CullState);
WM3_IMPLEMENT_TERMINATE(CullState);

//----------------------------------------------------------------------------
void CullState::Initialize ()
{
    Default[CULL] = WM3_NEW CullState;
}
//----------------------------------------------------------------------------
void CullState::Terminate ()
{
    Default[CULL] = 0;
}
//----------------------------------------------------------------------------
CullState::CullState ()
{
    Enabled = true;
    FrontFace = FT_CCW;
    CullFace = CT_BACK;
}
//----------------------------------------------------------------------------
CullState::~CullState ()
{
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// streaming
//----------------------------------------------------------------------------
void CullState::Load (Stream& rkStream, Stream::Link* pkLink)
{
    WM3_BEGIN_DEBUG_STREAM_LOAD;

    GlobalState::Load(rkStream,pkLink);

    // native data
    rkStream.Read(Enabled);
    rkStream.Read(FrontFace);
    rkStream.Read(CullFace);

    WM3_END_DEBUG_STREAM_LOAD(CullState);
}
//----------------------------------------------------------------------------
void CullState::Link (Stream& rkStream, Stream::Link* pkLink)
{
    GlobalState::Link(rkStream,pkLink);
}
//----------------------------------------------------------------------------
bool CullState::Register (Stream& rkStream) const
{
    return GlobalState::Register(rkStream);
}
//----------------------------------------------------------------------------
void CullState::Save (Stream& rkStream) const
{
    WM3_BEGIN_DEBUG_STREAM_SAVE;

    GlobalState::Save(rkStream);

    // native data
    rkStream.Write(Enabled);
    rkStream.Write(FrontFace);
    rkStream.Write(CullFace);

    WM3_END_DEBUG_STREAM_SAVE(CullState);
}
//----------------------------------------------------------------------------
StringTree* CullState::SaveStrings (const char*)
{
    StringTree* pkTree = WM3_NEW StringTree(4,1);

    // strings
    pkTree->SetString(0,Format(&TYPE,GetName()));
    pkTree->SetString(1,Format("enabled =",Enabled));

    char* acString = 0;
    switch (FrontFace)
    {
    case FT_CCW:
        acString = Format("front face = CCW");
        break;
    case FT_CW:
        acString = Format("front face = CW");
        break;
    default:  // FT_QUANTITY
        break;
    }
    pkTree->SetString(2,acString);

    acString = 0;
    switch (CullFace)
    {
    case CT_FRONT:
        acString = Format("cull face = FRONT");
        break;
    case CT_BACK:
        acString = Format("cull face = BACK");
        break;
    default:  // CT_QUANTITY
        break;
    }
    pkTree->SetString(3,acString);

    // children
    pkTree->SetChild(0,GlobalState::SaveStrings());

    return pkTree;
}
//----------------------------------------------------------------------------
int CullState::GetMemoryUsed () const
{
    return sizeof(CullState) - sizeof(GlobalState) +
        GlobalState::GetMemoryUsed();
}
//----------------------------------------------------------------------------
int CullState::GetDiskUsed (const StreamVersion& rkVersion) const
{
    return GlobalState::GetDiskUsed(rkVersion) +
        sizeof(char) + // Enabled
        sizeof(FrontFace) +
        sizeof(CullFace);
}
//----------------------------------------------------------------------------

