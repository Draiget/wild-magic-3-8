// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef INSTANCEDATA_H
#define INSTANCEDATA_H

#include "Wm3Spatial.h"
using namespace Wm3;

// Instance Data is mostly a "struct" class to hold information relating
// to a single Maya object and any instances it might have.

class InstanceData
{
public:
    InstanceData (Spatial* pkFirst);
    InstanceData ();
    ~InstanceData ();

    // An array of spatial objects created for a Maya object.  If a Maya
    // object is not instanced, then this array will be length one.
    TArray<Spatial*> Spats;

    // Convenience functions
    InstanceData& operator= (const InstanceData& rkData);

    // Return the first object in the array.
    Spatial* GetFirst ();
};

#endif

