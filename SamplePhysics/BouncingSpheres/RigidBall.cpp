// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#include "RigidBall.h"
#include "Wm3StandardMesh.h"
#include "Wm3TextureEffect.h"

//----------------------------------------------------------------------------
RigidBall::RigidBall (float fRadius)
{
    m_fRadius = fRadius;
    Moved = false;

    StandardMesh kSM;
    kSM.UVs(true,false);
    m_spkMesh = kSM.Sphere(16,16,m_fRadius);

    Texture* pkTexture = WM3_NEW Texture(Image::Load(
        System::GetPath("../../Data/Wmif/","BallTexture.wmif")));

    TextureEffect* pkEffect = WM3_NEW TextureEffect(pkTexture,kSM.GetUVs());
    m_spkMesh->SetEffect(pkEffect);
}
//----------------------------------------------------------------------------
float RigidBall::GetRadius () const
{ 
    return m_fRadius; 
}
//----------------------------------------------------------------------------
TriMeshPtr& RigidBall::Mesh ()
{
    return m_spkMesh;
}
//----------------------------------------------------------------------------

