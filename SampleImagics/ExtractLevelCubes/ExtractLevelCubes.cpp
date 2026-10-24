// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#include "ExtractLevelCubes.h"

WM3_WINDOW_APPLICATION(ExtractLevelCubes);

//----------------------------------------------------------------------------
ExtractLevelCubes::ExtractLevelCubes ()
    :
    WindowApplication3("ExtractLevelCubes",0,0,640,480,
        ColorRGB(0.5f,0.0f,1.0f))
{
}
//----------------------------------------------------------------------------
bool ExtractLevelCubes::OnInitialize ()
{
    if (!WindowApplication3::OnInitialize())
    {
        return false;
    }

    if (!CreateModel())
    {
        return true;
    }

    // create turret
    m_spkScene = WM3_NEW Node(1);
    m_spkTrnNode = WM3_NEW Node(1);
    m_spkScene->AttachChild(m_spkTrnNode);
    m_spkTrnNode->AttachChild(m_spkModel);
    m_spkScene->UpdateGS(0.0f);
    m_spkTrnNode->Local.SetTranslate(-m_spkScene->WorldBound->GetCenter());

    // center-and-fit camera parameters
    m_spkCamera->SetFrustum(-0.55f,0.55f,-0.4125f,0.4125f,1.0f,1000.0f);
    Vector3f kCDir(0.0f,0.0f,1.0f);
    Vector3f kCUp(0.0f,1.0f,0.0f);
    Vector3f kCRight = kCDir.Cross(kCUp);
    Vector3f kCLoc = -3.0f*m_spkScene->WorldBound->GetRadius()*kCDir;
    m_spkCamera->SetFrame(kCLoc,kCDir,kCUp,kCRight);

    // initial update of objects
    m_spkScene->UpdateGS(0.0f);
    m_spkScene->UpdateRS();

    InitializeCameraMotion(5.0f,0.1f);
    InitializeObjectMotion(m_spkScene);
    return true;
}
//----------------------------------------------------------------------------
void ExtractLevelCubes::OnTerminate ()
{
    m_spkScene = 0;
    m_spkTrnNode = 0;
    m_spkModel = 0;
    m_spkWireframe = 0;
    WindowApplication3::OnTerminate();
}
//----------------------------------------------------------------------------
void ExtractLevelCubes::OnIdle ()
{
    MeasureTime();

    MoveCamera();
    if (MoveObject())
    {
        m_spkScene->UpdateGS(0.0f);
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
bool ExtractLevelCubes::OnKeyDown (unsigned char ucKey, int iX, int iY)
{
    if (WindowApplication3::OnKeyDown(ucKey,iX,iY))
    {
        return true;
    }

    switch (ucKey)
    {
    case 'w':
    case 'W':
        m_spkWireframe->Enabled = !m_spkWireframe->Enabled;
        return true;
    }

    return false;
}
//----------------------------------------------------------------------------
bool ExtractLevelCubes::CreateModel ()
{
    // extract a level surface (image is 97x97x116)
    ImageInt3D kImage(System::GetPath("../../Data/Im/","Molecule.im"));
    if (kImage.GetDimensions() == 0)
    {
        return false;
    }

    ExtractSurfaceCubes kESC(kImage.GetBound(0),kImage.GetBound(1),
        kImage.GetBound(2),(int*)kImage.GetData());

    std::vector<Vector3f> kVA, kNA;
    std::vector<TriangleKey> kTA;

    kESC.ExtractContour(64.5f,kVA,kTA);
    kESC.MakeUnique(kVA,kTA);
    kESC.OrientTriangles(kVA,kTA,false);
    kESC.ComputeNormals(kVA,kTA,kNA);

    // create a triangle mesh for the surface
    int iVQuantity = (int)kVA.size();
    Vector3f* akVertex = WM3_NEW Vector3f[iVQuantity];
    memcpy(akVertex,&kVA.front(),iVQuantity*sizeof(Vector3f));
    Vector3fArray* pkVertices = WM3_NEW Vector3fArray(iVQuantity,akVertex);

    Vector3f* akNormal = WM3_NEW Vector3f[iVQuantity];
    memcpy(akNormal,&kNA.front(),iVQuantity*sizeof(Vector3f));
    Vector3fArray* pkNormals = WM3_NEW Vector3fArray(iVQuantity,akNormal);

    int iTQuantity = (int)kTA.size(), iIQuantity = 3*iTQuantity;
    int* aiIndex = WM3_NEW int[iIQuantity];
    int* piIndex = aiIndex;
    for (int i = 0; i < iTQuantity; i++)
    {
        *piIndex++ = kTA[i].V[0];
        *piIndex++ = kTA[i].V[1];
        *piIndex++ = kTA[i].V[2];
    }
    IntArray* pkIndices = WM3_NEW IntArray(iIQuantity,aiIndex);

    m_spkModel = WM3_NEW TriMesh(pkVertices,pkIndices,false);
    m_spkModel->Normals = pkNormals;

    // wireframe
    m_spkWireframe = WM3_NEW WireframeState;
    m_spkModel->SetGlobalState(m_spkWireframe);

    // material
    MaterialState* pkMS = WM3_NEW MaterialState;
    pkMS->Emissive = ColorRGBA(0.0f,0.0f,0.0f,1.0f);
    pkMS->Ambient = ColorRGBA(0.5f,0.5f,0.5f,1.0f);
    pkMS->Diffuse = ColorRGBA(0.99607f,0.83920f,0.67059f,1.0f);
    pkMS->Specular = ColorRGBA(0.8f,0.8f,0.8f,1.0f);
    pkMS->Shininess = 4.0f;
    m_spkModel->SetGlobalState(pkMS);

    // lights
    ColorRGBA kAmbient(0.25f,0.25f,0.25f,1.0f);
    ColorRGBA kDiffuse(0.5f,0.5f,0.5f,1.0f);
    ColorRGBA kSpecular(0.1f,0.1f,0.1f,1.0f);

    Light* pkLight = WM3_NEW Light(Light::LT_AMBIENT);
    pkLight->Ambient = kAmbient;
    pkLight->Diffuse = kDiffuse;
    pkLight->Specular = kSpecular;
    m_spkModel->SetLight(pkLight);

    pkLight = WM3_NEW Light(Light::LT_DIRECTIONAL);
    pkLight->Ambient = kAmbient;
    pkLight->Diffuse = kDiffuse;
    pkLight->Specular = kSpecular;
    pkLight->SetDirection(Vector3f::UNIT_Z);
    m_spkModel->SetLight(pkLight);

    return true;
}
//----------------------------------------------------------------------------

