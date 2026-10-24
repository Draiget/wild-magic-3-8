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
#include "Wm3Main.h"
#include "Wm3Object.h"
using namespace Wm3;

Main::InitializerArray* Main::ms_pkInitializers = 0;
Main::TerminatorArray* Main::ms_pkTerminators = 0;
int Main::ms_iStartObjects = 0;
int Main::ms_iFinalObjects = 0;

//----------------------------------------------------------------------------
void Main::AddInitializer (Initializer oInitialize)
{
    if (!ms_pkInitializers)
    {
        ms_pkInitializers = WM3_NEW InitializerArray(IT_MAXQUANTITY,IT_GROWBY);
    }

    ms_pkInitializers->Append(oInitialize);
}
//----------------------------------------------------------------------------
void Main::Initialize ()
{
    bool bCountIsCorrect = true;

    // objects should not be created pre-initialize
    if (Object::InUse)
    {
        bCountIsCorrect = false;
        Object::PrintInUse("AppLog.txt",
            "Objects were created before pre-main initialization");
    }

    assert(bCountIsCorrect);

    if (ms_pkInitializers)
    {
        for (int i = 0; i < ms_pkInitializers->GetQuantity(); i++)
        {
            (*ms_pkInitializers)[i]();
        }
    }

    WM3_DELETE ms_pkInitializers;
    ms_pkInitializers = 0;

    // number of objects created during initialization
    if (Object::InUse)
    {
        ms_iStartObjects = Object::InUse->GetQuantity();
    }
    else
    {
        ms_iStartObjects = 0;
    }
}
//----------------------------------------------------------------------------
void Main::AddTerminator (Terminator oTerminate)
{
    if (!ms_pkTerminators)
    {
        ms_pkTerminators = WM3_NEW TerminatorArray(IT_MAXQUANTITY,IT_GROWBY);
    }

    ms_pkTerminators->Append(oTerminate);
}
//----------------------------------------------------------------------------
void Main::Terminate ()
{
    bool bCountIsCorrect = true;

    // all objects created during the application should be deleted by now
    if (Object::InUse)
    {
        ms_iFinalObjects = Object::InUse->GetQuantity();
    }
    else
    {
        ms_iFinalObjects = 0;
    }

    if (ms_iStartObjects != ms_iFinalObjects)
    {
        bCountIsCorrect = false;
        Object::PrintInUse("AppLog.txt",
            "Not all objects were deleted before post-main termination");
    }

    if (ms_pkTerminators)
    {
        for (int i = 0; i < ms_pkTerminators->GetQuantity(); i++)
        {
            (*ms_pkTerminators)[i]();
        }
    }

    WM3_DELETE ms_pkTerminators;
    ms_pkTerminators = 0;

    if (bCountIsCorrect)
    {
        // objects should not be deleted post-terminate
        if (Object::InUse)
        {
            ms_iFinalObjects = Object::InUse->GetQuantity();
        }
        else
        {
            ms_iFinalObjects = 0;
        }

        if (ms_iFinalObjects != 0)
        {
            bCountIsCorrect = false;
            Object::PrintInUse("AppLog.txt",
                "Objects were deleted after post-main termination");
        }
    }

    assert(bCountIsCorrect);

    // Now that the object leak detection system has completed its tasks,
    // delete the hash table to free up memory so that the debug memory
    // system will not flag it as a leak.
    WM3_DELETE Object::InUse;
    Object::InUse = 0;
}
//----------------------------------------------------------------------------

