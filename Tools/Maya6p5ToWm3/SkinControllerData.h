// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef SKINCONTROLLERDATA_H
#define SKINCONTROLLERDATA_H

// This class is a "struct" class to hold the data necessary to create a
// Skin Controller.  It has everything except the bones list.  In its
// place is an array of Strings which will be used to match up with
// the joint list.

#include "Wm3TriMesh.h"
#include "Wm3String.h"
using namespace Wm3;

class SkinControllerData
{
public:
    SkinControllerData ();
    ~SkinControllerData ();

    // data handles
    TriMesh* Mesh;
    int VertexQuantity;
    int BoneQuantity;
    float** Weight;
    Vector3f** Offset;

    // needs to be deleted
    String* Bones;
};

#endif

