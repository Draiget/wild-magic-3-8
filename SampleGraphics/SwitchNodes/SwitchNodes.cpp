// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#include "SwitchNodes.h"

WM3_WINDOW_APPLICATION(SwitchNodes);

//----------------------------------------------------------------------------
SwitchNodes::SwitchNodes ()
    :
    WindowApplication3("SwitchNodes",0,0,640,480,ColorRGB(0.5f,0.0f,1.0f))
{
}
//----------------------------------------------------------------------------
bool SwitchNodes::OnInitialize ()
{
    if (!WindowApplication3::OnInitialize())
    {
        return false;
    }

    CreateScene();

    // set camera
    m_spkCamera->SetFrustum(-0.55f,0.55f,-0.4125f,0.4125f,1.0f,100.0f);
    float fCos = 0.866025f, fSin = 0.5f;
    Vector3f kCLoc(0.0f,-4.0f,2.0f);
    Vector3f kCDir(0.0f,fCos,-fSin);
    Vector3f kCUp(0.0f,fSin,fCos);
    Vector3f kCRight = kCDir.Cross(kCUp);
    m_spkCamera->SetFrame(kCLoc,kCDir,kCUp,kCRight);

    // initial update of objects
    m_spkScene->UpdateGS();
    m_spkScene->UpdateRS();

    InitializeCameraMotion(0.01f,0.001f);
    InitializeObjectMotion(m_spkScene);
    return true;
}
//----------------------------------------------------------------------------
void SwitchNodes::OnTerminate ()
{
    m_spkScene = 0;
    m_spkSwitch = 0;
    m_spkWireframe = 0;
    WindowApplication3::OnTerminate();
}
//----------------------------------------------------------------------------
void SwitchNodes::OnIdle ()
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
        DrawFrameRate(8,GetHeight()-8,ColorRGBA::WHITE);
        m_pkRenderer->EndScene();
    }
    m_pkRenderer->DisplayBackBuffer();

    UpdateFrameCount();
}
//----------------------------------------------------------------------------
bool SwitchNodes::OnKeyDown (unsigned char ucKey, int iX, int iY)
{
    if (WindowApplication3::OnKeyDown(ucKey,iX,iY))
    {
        return true;
    }

    switch (ucKey)
    {
    case 'c':
    case 'C':
    {
        int iChild = m_spkSwitch->GetActiveChild();
        if (++iChild == m_spkSwitch->GetQuantity())
        {
            iChild = 0;
        }
        m_spkSwitch->SetActiveChild(iChild);
        return true;
    }
    case 'w':
    case 'W':
        m_spkWireframe->Enabled = !m_spkWireframe->Enabled;
        return true;
    case 's':
    case 'S':
        TestStream();
        return true;
    }

    return false;
}
//----------------------------------------------------------------------------
void SwitchNodes::CreateScene ()
{
    m_spkScene = WM3_NEW Node;
    m_spkWireframe = WM3_NEW WireframeState;
    m_spkScene->SetGlobalState(m_spkWireframe);

    m_spkSwitch = WM3_NEW SwitchNode;
    m_spkScene->AttachChild(m_spkSwitch);

    // texture to be shared by all objects
    Texture* pkTexture = WM3_NEW Texture(Image::Load(
        System::GetPath("../../Data/Wmif/","Flower.wmif")));
    Effect* pkEffect;
    TriMesh* pkMesh;

    // mesh creator
    StandardMesh kSM;
    kSM.UVs(true,false);

    // create a rectangle mesh (child 0)
    pkMesh = kSM.Rectangle(4,4,1.0f,1.0f);
    pkEffect = WM3_NEW TextureEffect(pkTexture,kSM.GetUVs());
    pkMesh->SetEffect(pkEffect);
    m_spkSwitch->AttachChild(pkMesh);

    // create a disk mesh (child 1)
    pkMesh = kSM.Disk(8,16,1.0f);
    pkEffect = WM3_NEW TextureEffect(pkTexture,kSM.GetUVs());
    pkMesh->SetEffect(pkEffect);
    m_spkSwitch->AttachChild(pkMesh);

    // create a box mesh (child 2)
    pkMesh = kSM.Box(1.0f,0.5f,0.25f);
    pkEffect = WM3_NEW TextureEffect(pkTexture,kSM.GetUVs());
    pkMesh->SetEffect(pkEffect);
    m_spkSwitch->AttachChild(pkMesh);

    // create a closed cylinder mesh (child 3)
    pkMesh = kSM.Cylinder(8,16,1.0f,2.0f,false);
    pkEffect = WM3_NEW TextureEffect(pkTexture,kSM.GetUVs());
    pkMesh->SetEffect(pkEffect);
    m_spkSwitch->AttachChild(pkMesh);

    // create a sphere mesh (child 4)
    pkMesh = kSM.Sphere(32,16,1.0f);
    pkEffect = WM3_NEW TextureEffect(pkTexture,kSM.GetUVs());
    pkMesh->SetEffect(pkEffect);
    m_spkSwitch->AttachChild(pkMesh);

    // create a torus mesh (child 5)
    pkMesh = kSM.Torus(16,16,1.0f,0.25f);
    pkEffect = WM3_NEW TextureEffect(pkTexture,kSM.GetUVs());
    pkMesh->SetEffect(pkEffect);
    m_spkSwitch->AttachChild(pkMesh);

    // create a tetrahedron (child 6)
    pkMesh = kSM.Tetrahedron();
    pkEffect = WM3_NEW TextureEffect(pkTexture,kSM.GetUVs());
    pkMesh->SetEffect(pkEffect);
    m_spkSwitch->AttachChild(pkMesh);

    // create a hexahedron (child 7)
    pkMesh = kSM.Hexahedron();
    pkEffect = WM3_NEW TextureEffect(pkTexture,kSM.GetUVs());
    pkMesh->SetEffect(pkEffect);
    m_spkSwitch->AttachChild(pkMesh);

    // create an octahedron (child 8)
    pkMesh = kSM.Octahedron();
    pkEffect = WM3_NEW TextureEffect(pkTexture,kSM.GetUVs());
    pkMesh->SetEffect(pkEffect);
    m_spkSwitch->AttachChild(pkMesh);

    // create a dodecahedron (child 9)
    pkMesh = kSM.Dodecahedron();
    pkEffect = WM3_NEW TextureEffect(pkTexture,kSM.GetUVs());
    pkMesh->SetEffect(pkEffect);
    m_spkSwitch->AttachChild(pkMesh);

    // create an icosahedron (child 10)
    pkMesh = kSM.Icosahedron();
    pkEffect = WM3_NEW TextureEffect(pkTexture,kSM.GetUVs());
    pkMesh->SetEffect(pkEffect);
    m_spkSwitch->AttachChild(pkMesh);

    // set the active child (otherwise it is invalid)
    m_spkSwitch->SetActiveChild(0);
}
//----------------------------------------------------------------------------
void SwitchNodes::TestStream ()
{
    Stream kOStream;
    kOStream.Insert(m_spkScene);
    kOStream.Save("SwitchNodes.wmof");

    Stream kIStream;
    kIStream.Load("SwitchNodes.wmof");
    NodePtr spkScene = (Node*)kIStream.GetObjectAt(0);
}
//----------------------------------------------------------------------------

