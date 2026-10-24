// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#include "Loader3dS.h"
using namespace Wm3;

//----------------------------------------------------------------------------
// To convert from 3D Studio Max's 3ds format to Wild Magic's wmof format:
//   3dsToWmof model.3ds model.wmof
//
// Any texture images needed by the 3ds file must be located in the same
// directory as the 3ds file, must have been converted to a .wmif format
// image, and must replace the old image filename extension with .wmif.
//----------------------------------------------------------------------------
int main (int iQuantity, char** aacArgument)
{
    if (iQuantity != 3)
    {
        return -1;
    }

    Loader3ds kLoader;
    if (!kLoader.LoadFile(aacArgument[1]))
    {
        return -2;
    }

    NodePtr spkScene = kLoader.LoadSceneGraph(true);

    Stream kOStream;
    kOStream.Insert(spkScene);
    kOStream.Save(aacArgument[2]);

#ifdef WM3_MEMORY_MANAGER
#ifdef _DEBUG
    Memory::GenerateReport("MemoryReportDebug.txt");
#else
    Memory::GenerateReport("MemoryReportRelease.txt");
#endif
#endif

    return 0;
}
//----------------------------------------------------------------------------

