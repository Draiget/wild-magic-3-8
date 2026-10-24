// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#include "WClassDesc.h"
#include "Max7ToWm3.h"
#include "resource.h"
#include "WSceneExport.h"

Class_ID WClassDesc::ID(0x554dbc9c,0x8f17519);
WClassDesc WClassDesc::TheDescription;

//----------------------------------------------------------------------------
WClassDesc::WClassDesc ()
{
}
//----------------------------------------------------------------------------
int WClassDesc::IsPublic () 
{ 
    return TRUE; 
}
//----------------------------------------------------------------------------
void* WClassDesc::Create (BOOL) 
{ 
    return new WSceneExport; 
}
//----------------------------------------------------------------------------
const TCHAR* WClassDesc::ClassName () 
{ 
    return Max7ToWm3::ThePlugin.GetResourceString(IDS_CLASS_NAME); 
}
//----------------------------------------------------------------------------
SClass_ID WClassDesc::SuperClassID () 
{ 
    return SCENE_EXPORT_CLASS_ID; 
}
//----------------------------------------------------------------------------
Class_ID WClassDesc:: ClassID () 
{ 
    return ID;
}
//----------------------------------------------------------------------------
const TCHAR* WClassDesc::Category ()
{ 
    return Max7ToWm3::ThePlugin.GetResourceString(IDS_CATEGORY); 
}
//----------------------------------------------------------------------------
const TCHAR* WClassDesc::InternalName () 
{ 
    return Max7ToWm3::ThePlugin.GetResourceString(IDS_INTERNALNAME); 
}
//----------------------------------------------------------------------------
HINSTANCE WClassDesc::HInstance () 
{ 
    return Max7ToWm3::ThePlugin.GetInstance(); 
}
//----------------------------------------------------------------------------




