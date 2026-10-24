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
#include "Wm3SphereBVTree.h"
#include "Wm3ApprLineFit3.h"
#include "Wm3ContSphere3.h"
using namespace Wm3;

WM3_IMPLEMENT_INITIALIZE(SphereBVTree);

//----------------------------------------------------------------------------
void SphereBVTree::Initialize ()
{
    ms_aoCreateModelBound[BoundingVolume::BV_SPHERE] =
        &SphereBVTree::CreateModelBound;

    ms_aoCreateWorldBound[BoundingVolume::BV_SPHERE] =
        &SphereBVTree::CreateWorldBound;
}
//----------------------------------------------------------------------------
SphereBVTree::SphereBVTree (const TriMesh* pkMesh, int iMaxTrisPerLeaf,
    bool bStoreInteriorTris)
    :
    BoundingVolumeTree(BoundingVolume::BV_SPHERE,pkMesh,iMaxTrisPerLeaf,
        bStoreInteriorTris)
{
}
//----------------------------------------------------------------------------
BoundingVolume* SphereBVTree::CreateModelBound (const TriMesh* pkMesh, int i0,
    int i1, int* aiISplit, Line3f& rkLine)
{
    // tag vertices that are used in the submesh
    int iVQuantity = pkMesh->Vertices->GetQuantity();
    Vector3f* akVertex = pkMesh->Vertices->GetData();
    const int* aiIndex = pkMesh->Indices->GetData();
    bool* abValid = WM3_NEW bool[iVQuantity];
    memset(abValid,0,iVQuantity*sizeof(bool));
    for (int i = i0; i <= i1; i++)
    {
        int j = 3*aiISplit[i];
        abValid[aiIndex[j++]] = true;
        abValid[aiIndex[j++]] = true;
        abValid[aiIndex[j++]] = true;
    }

    SphereBV* pkModelBound = WM3_NEW SphereBV;
    pkModelBound->Sphere() = ContSphereAverage<float>(iVQuantity,akVertex,
        abValid);
    WM3_DELETE[] abValid;

    rkLine = OrthogonalLineFit3<float>(iVQuantity,akVertex,abValid);
    return pkModelBound;
}
//----------------------------------------------------------------------------
BoundingVolume* SphereBVTree::CreateWorldBound ()
{
    return WM3_NEW SphereBV;
}
//----------------------------------------------------------------------------

