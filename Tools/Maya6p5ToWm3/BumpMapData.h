// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef BUMPMAPDATA_H
#define BUMPMAPDATA_H

// This class is a "struct" class to hold the data necessary to create a
// BumpMapEffect.  The reason this class is needed is because the creation
// of the effect is deferred until it is known if (and which) light needs
// to be used with the BumpMap.

#include <maya/MString.h>
#include "Wm3TriMesh.h"
using namespace Wm3;

class BumpMapData
{
public:
    ImagePtr Primary;
    Vector2fArrayPtr PrimaryUVs;
    ImagePtr NormalMap;
    Vector2fArrayPtr NormalUVs;
    ColorRGBArrayPtr Colors;

    // A handle to the trimesh this bumpmap should be attached to.
    int MeshKey;

    bool Modulated;
    MString Name;
};

#endif

