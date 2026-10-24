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
#include "Wm3FogState.h"
using namespace Wm3;

WM3_IMPLEMENT_RTTI(Wm3,FogState,GlobalState);
WM3_IMPLEMENT_STREAM(FogState);
WM3_IMPLEMENT_DEFAULT_NAME_ID(FogState,GlobalState);
WM3_IMPLEMENT_INITIALIZE(FogState);
WM3_IMPLEMENT_TERMINATE(FogState);

//----------------------------------------------------------------------------
void FogState::Initialize ()
{
    Default[FOG] = WM3_NEW FogState;
}
//----------------------------------------------------------------------------
void FogState::Terminate ()
{
    Default[FOG] = 0;
}
//----------------------------------------------------------------------------
FogState::FogState ()
    :
    Color(ColorRGBA::BLACK)
{
    Enabled = false;
    Start = 0.0f;
    End = 1.0f;
    Density = 1.0f;
    DensityFunction = DF_LINEAR;
    ApplyFunction = AF_PER_VERTEX;
}
//----------------------------------------------------------------------------
FogState::~FogState ()
{
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// streaming
//----------------------------------------------------------------------------
void FogState::Load (Stream& rkStream, Stream::Link* pkLink)
{
    WM3_BEGIN_DEBUG_STREAM_LOAD;

    GlobalState::Load(rkStream,pkLink);

    // native data
    rkStream.Read(Enabled);
    rkStream.Read(Start);
    rkStream.Read(End);
    rkStream.Read(Density);
    rkStream.Read(Color);
    rkStream.Read(DensityFunction);
    rkStream.Read(ApplyFunction);

    WM3_END_DEBUG_STREAM_LOAD(FogState);
}
//----------------------------------------------------------------------------
void FogState::Link (Stream& rkStream, Stream::Link* pkLink)
{
    GlobalState::Link(rkStream,pkLink);
}
//----------------------------------------------------------------------------
bool FogState::Register (Stream& rkStream) const
{
    return GlobalState::Register(rkStream);
}
//----------------------------------------------------------------------------
void FogState::Save (Stream& rkStream) const
{
    WM3_BEGIN_DEBUG_STREAM_SAVE;

    GlobalState::Save(rkStream);

    // native data
    rkStream.Write(Enabled);
    rkStream.Write(Start);
    rkStream.Write(End);
    rkStream.Write(Density);
    rkStream.Write(Color);
    rkStream.Write(DensityFunction);
    rkStream.Write(ApplyFunction);

    WM3_END_DEBUG_STREAM_SAVE(FogState);
}
//----------------------------------------------------------------------------
StringTree* FogState::SaveStrings (const char*)
{
    StringTree* pkTree = WM3_NEW StringTree(8,1);

    // strings
    pkTree->SetString(0,Format(&TYPE,GetName()));
    pkTree->SetString(1,Format("enabled =",Enabled));
    pkTree->SetString(2,Format("start =",Start));
    pkTree->SetString(3,Format("end =",End));
    pkTree->SetString(4,Format("density =",Density));
    pkTree->SetString(5,Format("color =",Color));

    char* acString = 0;
    switch (DensityFunction)
    {
    case DF_LINEAR:
        acString = Format("density func = LINEAR");
        break;
    case DF_EXP:
        acString = Format("density func = EXP");
        break;
    case DF_EXPSQR:
        acString = Format("density func = EXPSQR");
        break;
    default:  // DF_QUANTITY
        break;
    };
    pkTree->SetString(6,acString);

    acString = 0;
    switch (ApplyFunction)
    {
    case AF_PER_VERTEX:
        acString = Format("apply func = VERTEX");
        break;
    case AF_PER_PIXEL:
        acString = Format("apply func = PIXEL");
        break;
    default:  // AF_QUANTITY
        break;
    };
    pkTree->SetString(7,acString);

    // children
    pkTree->SetChild(0,GlobalState::SaveStrings());

    return pkTree;
}
//----------------------------------------------------------------------------
int FogState::GetMemoryUsed () const
{
    return sizeof(FogState) - sizeof(GlobalState) +
        GlobalState::GetMemoryUsed();
}
//----------------------------------------------------------------------------
int FogState::GetDiskUsed (const StreamVersion& rkVersion) const
{
    return GlobalState::GetDiskUsed(rkVersion) +
        sizeof(char) + // Enabled
        sizeof(Start) +
        sizeof(End) +
        sizeof(Density) +
        sizeof(Color) +
        sizeof(DensityFunction) +
        sizeof(ApplyFunction);
}
//----------------------------------------------------------------------------

