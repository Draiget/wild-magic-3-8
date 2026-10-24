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
#include "Wm3MaterialState.h"
using namespace Wm3;

WM3_IMPLEMENT_RTTI(Wm3,MaterialState,GlobalState);
WM3_IMPLEMENT_STREAM(MaterialState);
WM3_IMPLEMENT_DEFAULT_NAME_ID(MaterialState,GlobalState);
WM3_IMPLEMENT_INITIALIZE(MaterialState);
WM3_IMPLEMENT_TERMINATE(MaterialState);

//----------------------------------------------------------------------------
void MaterialState::Initialize ()
{
    Default[MATERIAL] = WM3_NEW MaterialState;
}
//----------------------------------------------------------------------------
void MaterialState::Terminate ()
{
    Default[MATERIAL] = 0;
}
//----------------------------------------------------------------------------
MaterialState::MaterialState ()
    :
    Emissive(ColorRGBA::BLACK),
    Ambient(0.2f,0.2f,0.2f,1.0f),
    Diffuse(0.8f,0.8f,0.8f,1.0f),
    Specular(ColorRGBA::BLACK)
{
    Shininess = 1.0f;
}
//----------------------------------------------------------------------------
MaterialState::~MaterialState ()
{
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// streaming
//----------------------------------------------------------------------------
void MaterialState::Load (Stream& rkStream, Stream::Link* pkLink)
{
    WM3_BEGIN_DEBUG_STREAM_LOAD;

    GlobalState::Load(rkStream,pkLink);

    // native data
    rkStream.Read(Emissive);
    rkStream.Read(Ambient);
    rkStream.Read(Diffuse);
    rkStream.Read(Specular);
    rkStream.Read(Shininess);

    WM3_END_DEBUG_STREAM_LOAD(MaterialState);
}
//----------------------------------------------------------------------------
void MaterialState::Link (Stream& rkStream, Stream::Link* pkLink)
{
    GlobalState::Link(rkStream,pkLink);
}
//----------------------------------------------------------------------------
bool MaterialState::Register (Stream& rkStream) const
{
    return GlobalState::Register(rkStream);
}
//----------------------------------------------------------------------------
void MaterialState::Save (Stream& rkStream) const
{
    WM3_BEGIN_DEBUG_STREAM_SAVE;

    GlobalState::Save(rkStream);

    // native data
    rkStream.Write(Emissive);
    rkStream.Write(Ambient);
    rkStream.Write(Diffuse);
    rkStream.Write(Specular);
    rkStream.Write(Shininess);

    WM3_END_DEBUG_STREAM_SAVE(MaterialState);
}
//----------------------------------------------------------------------------
StringTree* MaterialState::SaveStrings (const char*)
{
    StringTree* pkTree = WM3_NEW StringTree(6,1);

    // strings
    pkTree->SetString(0,Format(&TYPE,GetName()));
    pkTree->SetString(1,Format("emissive =",Emissive));
    pkTree->SetString(2,Format("ambient =",Ambient));
    pkTree->SetString(3,Format("diffuse =",Diffuse));
    pkTree->SetString(4,Format("specular =",Specular));
    pkTree->SetString(5,Format("shininess =",Shininess));

    // children
    pkTree->SetChild(0,GlobalState::SaveStrings());

    return pkTree;
}
//----------------------------------------------------------------------------
int MaterialState::GetMemoryUsed () const
{
    return sizeof(MaterialState) - sizeof(GlobalState) +
        GlobalState::GetMemoryUsed();
}
//----------------------------------------------------------------------------
int MaterialState::GetDiskUsed (const StreamVersion& rkVersion) const
{
    return GlobalState::GetDiskUsed(rkVersion) +
        sizeof(Emissive) +
        sizeof(Ambient) +
        sizeof(Diffuse) +
        sizeof(Specular) +
        sizeof(Shininess);
}
//----------------------------------------------------------------------------

