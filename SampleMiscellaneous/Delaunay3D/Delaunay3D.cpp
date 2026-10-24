// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#include "Delaunay3D.h"

WM3_WINDOW_APPLICATION(Delaunay3D);

//----------------------------------------------------------------------------
Delaunay3D::Delaunay3D ()
    :
    WindowApplication3("Delaunay3D",0,0,640,480,ColorRGB::WHITE)
{
    m_pkDel = 0;
}
//----------------------------------------------------------------------------
bool Delaunay3D::OnInitialize ()
{
    if (!WindowApplication3::OnInitialize())
    {
        return false;
    }

    m_spkCamera->SetFrustum(-0.055f,0.055f,-0.04125f,0.04125f,0.1f,10000.0f);
    Vector3f kCDir(0.0f,0.0f,1.0f);
    Vector3f kCUp(0.0f,1.0f,0.0f);
    Vector3f kCRight = kCDir.Cross(kCUp);
    Vector3f kCLoc(0.0f,0.0f,-4.0f);
    m_spkCamera->SetFrame(kCLoc,kCDir,kCUp,kCRight);

    CreateScene();

    InitializeCameraMotion(0.1f,0.01f);
    InitializeObjectMotion(m_spkScene);
    return true;
}
//----------------------------------------------------------------------------
void Delaunay3D::OnTerminate ()
{
    m_spkScene = 0;
    WM3_DELETE m_pkDel;
    WindowApplication3::OnTerminate();
}
//----------------------------------------------------------------------------
void Delaunay3D::OnIdle ()
{
    MeasureTime();

    MoveCamera();
    if (MoveObject())
    {
        m_spkScene->UpdateGS();
    }

    m_pkRenderer->ClearBuffers();
    if (m_pkRenderer->BeginScene())
    {
        m_pkRenderer->DrawScene(m_spkScene);
        m_pkRenderer->EndScene();
    }
    m_pkRenderer->DisplayBackBuffer();

    UpdateFrameCount();
}
//----------------------------------------------------------------------------
bool Delaunay3D::OnKeyDown (unsigned char ucKey, int iX, int iY)
{
    if (WindowApplication3::OnKeyDown(ucKey,iX,iY))
    {
        return true;
    }

    switch (ucKey)
    {
    case 's':
    case 'S':
        DoSearch();
        return true;
    }

    return false;
}
//----------------------------------------------------------------------------
void Delaunay3D::CreateScene ()
{
    int i, iVQuantity;
    Vector3f* akVertex;
#if 0
    // test a cube
    iVQuantity = 8;
    akVertex = WM3_NEW Vector3f[iVQuantity];
    akVertex[0] = Vector3f(0.0f,0.0f,0.0f);
    akVertex[1] = Vector3f(1.0f,0.0f,0.0f);
    akVertex[2] = Vector3f(1.0f,1.0f,0.0f);
    akVertex[3] = Vector3f(0.0f,1.0f,0.0f);
    akVertex[4] = Vector3f(0.0f,0.0f,1.0f);
    akVertex[5] = Vector3f(1.0f,0.0f,1.0f);
    akVertex[6] = Vector3f(1.0f,1.0f,1.0f);
    akVertex[7] = Vector3f(0.0f,1.0f,1.0f);
#endif
#if 1
    // randomly generated points
    iVQuantity = 128;
    akVertex = WM3_NEW Vector3f[iVQuantity];
    akVertex[0] = Vector3f::ZERO;
    for (i = 1; i < iVQuantity; i++)
    {
        akVertex[i].X() = Mathf::SymmetricRandom();
        akVertex[i].Y() = Mathf::SymmetricRandom();
        akVertex[i].Z() = Mathf::SymmetricRandom();
    }
#endif

    m_kMin = akVertex[0];
    m_kMax = akVertex[0];
    for (i = 1; i < iVQuantity; i++)
    {
        float fX = akVertex[i].X();
        if (fX < m_kMin.X())
        {
            m_kMin.X() = fX;
        }
        else if (fX > m_kMax.X())
        {
            m_kMax.X() = fX;
        }

        float fY = akVertex[i].Y();
        if (fY < m_kMin.Y())
        {
            m_kMin.Y() = fY;
        }
        else if (fY > m_kMax.Y())
        {
            m_kMax.Y() = fY;
        }

        float fZ = akVertex[i].Z();
        if (fZ < m_kMin.Z())
        {
            m_kMin.Z() = fZ;
        }
        else if (fZ > m_kMax.Z())
        {
            m_kMax.Z() = fZ;
        }
    }

    m_pkDel = WM3_NEW Delaunay3f(iVQuantity,akVertex,0.001f,true,
        Query::QT_INT64);

    m_spkScene = WM3_NEW Node;
    CullState* pkCS = WM3_NEW CullState;
    pkCS->Enabled = false;
    m_spkScene->SetGlobalState(pkCS);

    m_spkScene->AttachChild(CreateSphere());
    for (int j = 0; j < m_pkDel->GetSimplexQuantity(); j++)
    {
        m_spkScene->AttachChild(CreateTetra(j));
    }

    m_spkScene->UpdateGS();
    m_spkScene->UpdateRS();
}
//----------------------------------------------------------------------------
TriMesh* Delaunay3D::CreateSphere () const
{
    StandardMesh kSM;
    TriMesh* pkMesh = kSM.Sphere(8,8,0.01f);
    int iVQuantity = pkMesh->Vertices->GetQuantity();
    ColorRGB* akColor = WM3_NEW ColorRGB[iVQuantity];
    memset(akColor,0,iVQuantity*sizeof(ColorRGB));
    ColorRGBArray* pkColors = WM3_NEW ColorRGBArray(iVQuantity,akColor);
    VertexColorEffect* pkEffect = WM3_NEW VertexColorEffect(pkColors);
    pkMesh->SetEffect(pkEffect);
    pkMesh->ForceCull = true;
    return pkMesh;
}
//----------------------------------------------------------------------------
TriMesh* Delaunay3D::CreateTetra (int iIndex) const
{
    const Vector3f* akTVertex = m_pkDel->GetVertices();
    const int* aiTIndex = m_pkDel->GetIndices();

    Vector3f* akVertex = WM3_NEW Vector3f[4];
    akVertex[0] = akTVertex[aiTIndex[4*iIndex  ]];
    akVertex[1] = akTVertex[aiTIndex[4*iIndex+1]];
    akVertex[2] = akTVertex[aiTIndex[4*iIndex+2]];
    akVertex[3] = akTVertex[aiTIndex[4*iIndex+3]];
    Vector3fArray* pkVertices = WM3_NEW Vector3fArray(4,akVertex);

    int* aiIndex = WM3_NEW int[12];
    aiIndex[ 0] = 0;  aiIndex[ 1] = 1;  aiIndex[ 2] = 2;
    aiIndex[ 3] = 0;  aiIndex[ 4] = 3;  aiIndex[ 5] = 1;
    aiIndex[ 6] = 0;  aiIndex[ 7] = 2;  aiIndex[ 8] = 3;
    aiIndex[ 9] = 3;  aiIndex[10] = 2;  aiIndex[11] = 1;
    IntArray* pkIndices = WM3_NEW IntArray(12,aiIndex);

    TriMesh* pkTetra = WM3_NEW TriMesh(pkVertices,pkIndices,false);

    // wireframe
    WireframeState* pkWS = WM3_NEW WireframeState;
    pkWS->Enabled = true;
    pkTetra->SetGlobalState(pkWS);

    // alpha blending for when the tetra is solid
    AlphaState* pkAS = WM3_NEW AlphaState;
    pkAS->BlendEnabled = true;
    pkTetra->SetGlobalState(pkAS);

    // light gray vertex colors
    ColorRGBA* akColor = WM3_NEW ColorRGBA[4];
    for (int i = 0; i < 4; i++)
        akColor[i] = ColorRGBA(0.75f,0.75f,0.75f,1.0f);
    ColorRGBAArray* pkColors = WM3_NEW ColorRGBAArray(4,akColor);
    VertexColorEffect* pkEffect = WM3_NEW VertexColorEffect(pkColors);
    pkTetra->SetEffect(pkEffect);

    return pkTetra;
}
//----------------------------------------------------------------------------
void Delaunay3D::ChangeTetraStatus (int iIndex, const ColorRGBA& rkColor,
    bool bWireframe)
{
    Spatial* pkTetra = m_spkScene->GetChild(1+iIndex);
    assert(DynamicCast<TriMesh>(pkTetra));

    Effect* pkEffect = pkTetra->GetEffect();
    assert(pkEffect);
    ColorRGBA* akColor = pkEffect->ColorRGBAs->GetData();
    for (int i = 0; i < 4; i++)
    {
        akColor[i] = rkColor;
    }

    WireframeState* pkWS =
        (WireframeState*)pkTetra->GetGlobalState(GlobalState::WIREFRAME);
    assert(pkWS);
    pkWS->Enabled = bWireframe;
}
//----------------------------------------------------------------------------
void Delaunay3D::ChangeLastTetraStatus (int iIndex, int iVOpposite,
    const ColorRGBA& rkColor, const ColorRGBA& rkOppositeColor)
{
    Spatial* pkTetra = m_spkScene->GetChild(1+iIndex);
    assert(DynamicCast<TriMesh>(pkTetra));

    Effect* pkEffect = pkTetra->GetEffect();
    assert(pkEffect);
    ColorRGBA* akColor = pkEffect->ColorRGBAs->GetData();
    for (int i = 0; i < 4; i++)
    {
        if (i != iVOpposite)
        {
            akColor[i] = rkColor;
        }
        else
        {
            akColor[i] = rkOppositeColor;
        }
    }

    WireframeState* pkWS =
        (WireframeState*)pkTetra->GetGlobalState(GlobalState::WIREFRAME);
    assert(pkWS);
    pkWS->Enabled = false;
}
//----------------------------------------------------------------------------
void Delaunay3D::DoSearch ()
{
    // make all tetra wireframe
    int i;
    for (i = 0; i < m_pkDel->GetSimplexQuantity(); i++)
    {
        ChangeTetraStatus(i,ColorRGBA(0.75f,0.75f,0.75f,1.0f),true);
    }

    // generate random point in AABB of data set
    Vector3f kRandom;
    kRandom.X() = Mathf::IntervalRandom(m_kMin.X(),m_kMax.X());
    kRandom.Y() = Mathf::IntervalRandom(m_kMin.Y(),m_kMax.Y());
    kRandom.Z() = Mathf::IntervalRandom(m_kMin.Z(),m_kMax.Z());

    // move sphere to this location
    Spatial* pkSphere = m_spkScene->GetChild(0);
    pkSphere->ForceCull = false;
    pkSphere->Local.SetTranslate(kRandom);
    pkSphere->UpdateGS();

    if (m_pkDel->GetContainingTetrahedron(kRandom) >= 0)
    {
        // make all tetra on the path solid
        for (i = 0; i <= m_pkDel->GetPathLast(); i++)
        {
            int iIndex = m_pkDel->GetPath()[i];
            float fRed, fBlue;
            if (m_pkDel->GetPathLast() > 0)
            {
                fRed = i/(float)m_pkDel->GetPathLast();
                fBlue = 1.0f - fRed;
            }
            else
            {
                fRed = 1.0f;
                fBlue = 0.0f;
            }
            ChangeTetraStatus(iIndex,ColorRGBA(fRed,0.0f,fBlue,0.5f),false);
        }
    }
    else
    {
        // The point is outside the convex hull.  Change the wireframe
        // color for the last visited face in the search path.
        int iIndex = m_pkDel->GetPath()[m_pkDel->GetPathLast()];
        int iV0, iV1, iV2, iV3;
        int iVOpposite = m_pkDel->GetLastFace(iV0,iV1,iV2,iV3);
        ChangeLastTetraStatus(iIndex,iVOpposite,
            ColorRGBA(0.0f,1.0f,0.0f,0.5f),ColorRGBA(0.0f,0.25f,0.0f,0.5f));
    }
}
//----------------------------------------------------------------------------

