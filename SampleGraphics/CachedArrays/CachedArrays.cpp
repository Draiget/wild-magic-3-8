// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#include "CachedArrays.h"

WM3_WINDOW_APPLICATION(CachedArrays);

//----------------------------------------------------------------------------
CachedArrays::CachedArrays ()
    :
    WindowApplication3("CachedArrays",0,0,640,480,ColorRGB(0.5f,0.0f,1.0f))
{
}
//----------------------------------------------------------------------------
bool CachedArrays::OnInitialize ()
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
void CachedArrays::OnTerminate ()
{
    m_spkScene = 0;
    m_spkSwitch = 0;
    m_spkWireframe = 0;
    WindowApplication3::OnTerminate();
}
//----------------------------------------------------------------------------
void CachedArrays::OnIdle ()
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
bool CachedArrays::OnKeyDown (unsigned char ucKey, int iX, int iY)
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
        ResetTime();
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
    case '0':
        m_spkSwitch->SetActiveChild(0);
        ResetTime();
        return true;
    case '1':
        m_spkSwitch->SetActiveChild(1);
        ResetTime();
        return true;
    case '2':
        m_spkSwitch->SetActiveChild(2);
        ResetTime();
        return true;
    case '3':
        m_spkSwitch->SetActiveChild(3);
        ResetTime();
        return true;
    }

    return false;
}
//----------------------------------------------------------------------------
void CachedArrays::CreateScene ()
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
    int iZSamples = 128;
    int iRadialSamples = 128;
    StandardMesh kSM;

    // create a sphere mesh with cached arrays
    kSM.Vertices(false).Indices(false).UVs(true,false);
    pkMesh = kSM.Sphere(iZSamples,iRadialSamples,1.0f);
    pkEffect = WM3_NEW TextureEffect(pkTexture,kSM.GetUVs());
    pkMesh->SetEffect(pkEffect);
    pkMesh->Local.SetTranslate(Vector3f(+0.25f,0.0f,0.0f));
    m_spkSwitch->AttachChild(pkMesh);

    // create a sphere mesh with cached arrays
    kSM.Vertices(false).Indices(true).UVs(true,false);
    pkMesh = kSM.Sphere(iZSamples,iRadialSamples,1.0f);
    pkEffect = WM3_NEW TextureEffect(pkTexture,kSM.GetUVs());
    pkMesh->SetEffect(pkEffect);
    pkMesh->Local.SetTranslate(Vector3f(+0.25f,0.0f,0.0f));
    m_spkSwitch->AttachChild(pkMesh);

    // create a sphere mesh with cached arrays
    kSM.Vertices(true).Indices(false).UVs(true,true);
    pkMesh = kSM.Sphere(iZSamples,iRadialSamples,1.0f);
    pkEffect = WM3_NEW TextureEffect(pkTexture,kSM.GetUVs());
    pkMesh->SetEffect(pkEffect);
    pkMesh->Local.SetTranslate(Vector3f(+0.25f,0.0f,0.0f));
    m_spkSwitch->AttachChild(pkMesh);

    // create a sphere mesh with cached arrays
    kSM.Vertices(true).Indices(true).UVs(true,true);
    pkMesh = kSM.Sphere(iZSamples,iRadialSamples,1.0f);
    pkEffect = WM3_NEW TextureEffect(pkTexture,kSM.GetUVs());
    pkMesh->SetEffect(pkEffect);
    pkMesh->Local.SetTranslate(Vector3f(+0.25f,0.0f,0.0f));
    m_spkSwitch->AttachChild(pkMesh);

    // set the active child (otherwise it is invalid)
    m_spkSwitch->SetActiveChild(0);
}
//----------------------------------------------------------------------------
void CachedArrays::TestStream ()
{
    Stream kOStream;
    kOStream.Insert(m_spkScene);
    kOStream.Save("CachedArrays.wmof");

    Stream kIStream;
    kIStream.Load("CachedArrays.wmof");
    NodePtr spkScene = (Node*)kIStream.GetObjectAt(0);
}
//----------------------------------------------------------------------------

