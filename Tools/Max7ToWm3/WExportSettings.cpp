// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#include "WExportSettings.h"

//----------------------------------------------------------------------------
WExportSettings::WExportSettings ()
{
    // object settings
    IncludeObjects = TRUE;
    IncludeCameras = FALSE;
    IncludeLights = TRUE;
    IncludeMeshes = TRUE;

    // mesh settings
    IncludeMaterials = TRUE;
    IncludeTexCoords = TRUE;
    IncludeNormals = TRUE;
    IncludeVertexColors = FALSE;
    GenerateMaps = TRUE;

    // modifier settings    
    IncludeModifiers = TRUE;
    IncludeSkins = TRUE;

    // animation settings
    IncludeCurrentFrame = TRUE;
    IncludeKeyFrames = FALSE;
    IncludeAllFrames = FALSE;
    UseLocalTime = TRUE;
    StartFrame = 0;
    EndFrame = 0;
}
//----------------------------------------------------------------------------




