// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#include "PlanarReflections.h"

WM3_WINDOW_APPLICATION(PlanarReflections);

//----------------------------------------------------------------------------
PlanarReflections::PlanarReflections ()
    :
    WindowApplication3("PlanarReflections",0,0,640,480,
        ColorRGB(0.5f,0.0f,1.0f))
{
    m_dAnimTime = 0.0;
    m_dAnimTimeDelta = 0.01;
}
//----------------------------------------------------------------------------
bool PlanarReflections::OnInitialize ()
{
    if (!WindowApplication3::OnInitialize())
    {
        return false;
    }

    // Scene
    //     BipedNode (attach PlanarReflectionEffect)
    //     FloorMesh (attach TextureEffect)
    //     WallMesh  (attach TextureEffect)

    m_spkScene = WM3_NEW Node(3);
    m_spkScene->SetGlobalState(WM3_NEW ZBufferState);
    m_spkWireframe = WM3_NEW WireframeState;
    m_spkScene->SetGlobalState(m_spkWireframe);

    LoadBiped();
    CreatePlanes();
    CreatePlanarReflection();
    m_spkScene->Local.SetRotate(Matrix3f().FromAxisAngle(Vector3f::UNIT_Z,
        0.75f));

    // set up camera
    m_spkCamera->SetFrustum(-0.55f,0.55f,-0.4125f,0.4125f,1.0f,1000.0f);
    Vector3f kCLoc(180.0f,0.0f,23.0f);
    Vector3f kCDir(-1.0f,0.0f,0.0f);
    Vector3f kCUp(0.0f,0.0f,1.0f);
    Vector3f kCRight = kCDir.Cross(kCUp);
    m_spkCamera->SetFrame(kCLoc,kCDir,kCUp,kCRight);

    Light* pkLight = WM3_NEW Light(Light::LT_DIRECTIONAL);
    pkLight->Ambient = ColorRGBA(0.5f,0.5f,0.5f,1.0f);
    pkLight->Diffuse = pkLight->Ambient;
    pkLight->Specular = ColorRGBA::BLACK;
    pkLight->SetDirection(kCDir);
    pkLight->UpdateGS();
    m_spkScene->SetLight(pkLight);

    // initial update of objects
    m_spkScene->UpdateGS();
    m_spkScene->UpdateRS();

    InitializeCameraMotion(0.1f,0.01f);
    InitializeObjectMotion(m_spkScene);
    return true;
}
//----------------------------------------------------------------------------
void PlanarReflections::OnTerminate ()
{
    m_spkScene = 0;
    m_spkBiped = 0;
    m_spkPlane0 = 0;
    m_spkPlane1 = 0;
    m_spkWireframe = 0;
    WindowApplication3::OnTerminate();
}
//----------------------------------------------------------------------------
void PlanarReflections::OnIdle ()
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
bool PlanarReflections::OnKeyDown (unsigned char ucKey, int iX, int iY)
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

    case 'g':
        m_dAnimTime += m_dAnimTimeDelta;
        m_spkScene->UpdateGS(m_dAnimTime);
        return true;
    case 'G':
        m_dAnimTime = 0.0;
        m_spkScene->UpdateGS(m_dAnimTime);
        return true;

    case 's':
    case 'S':
        TestStream();
        return true;
    }

    return false;
}
//----------------------------------------------------------------------------
void PlanarReflections::LoadBiped ()
{
    Stream kIStream;
    kIStream.Load(System::GetPath("../../Data/Wmof/","SkinnedBiped.wmof"));
    m_spkBiped = (Node*)kIStream.GetObjectAt(0);
    m_spkScene->AttachChild(m_spkBiped);
}
//----------------------------------------------------------------------------
void PlanarReflections::CreatePlanes ()
{
    // create the floor mesh
    float fXValue = 128.0f;
    float fYValue = 256.0f;
    float fZValue = 0.0f;
    Vector3f* akVertex = WM3_NEW Vector3f[4];
    akVertex[0] = Vector3f(-fXValue,-fYValue,fZValue);
    akVertex[1] = Vector3f(+fXValue,-fYValue,fZValue);
    akVertex[2] = Vector3f(+fXValue,+fYValue,fZValue);
    akVertex[3] = Vector3f(-fXValue,+fYValue,fZValue);
    Vector3fArray* pkVertices = WM3_NEW Vector3fArray(4,akVertex);

    int* aiIndex = WM3_NEW int[6];
    aiIndex[0] = 0;  aiIndex[1] = 1;  aiIndex[2] = 2;
    aiIndex[3] = 0;  aiIndex[4] = 2;  aiIndex[5] = 3;
    IntArray* pkIndices = WM3_NEW IntArray(6,aiIndex);

    m_spkPlane0 = WM3_NEW TriMesh(pkVertices,pkIndices,false);

    // create a texture effect for the plane
    unsigned char* aucData = WM3_NEW unsigned char[4*sizeof(int)];
    unsigned int uiColor = System::MakeRGBA(0x8F,0x7F,0x00,0xFF);
    unsigned int* auiData = (unsigned int*)aucData;
    auiData[0] = uiColor;
    auiData[1] = uiColor;
    auiData[2] = uiColor;
    auiData[3] = uiColor;
    Image* pkImage = WM3_NEW Image(Image::IT_RGBA8888,2,2,aucData);

    Vector2f* akUV = WM3_NEW Vector2f[4];
    akUV[0] = Vector2f(0.0f,0.0f);
    akUV[1] = Vector2f(1.0f,0.0f);
    akUV[2] = Vector2f(1.0f,1.0f);
    akUV[3] = Vector2f(0.0f,1.0f);
    Vector2fArray* pkUVs = WM3_NEW Vector2fArray(4,akUV);

    Texture* pkTexture0 = WM3_NEW Texture(pkImage);
    TextureEffect* pkEffect = WM3_NEW TextureEffect(pkTexture0,pkUVs);
    m_spkPlane0->SetEffect(pkEffect);

    m_spkScene->AttachChild(m_spkPlane0);

    // create the wall mesh
    fXValue = -128.0f;
    fYValue = 256.0f;
    fZValue = 128.0f;
    akVertex = WM3_NEW Vector3f[4];
    akVertex[0] = Vector3f(fXValue,-fYValue,0.0f);
    akVertex[1] = Vector3f(fXValue,+fYValue,0.0f);
    akVertex[2] = Vector3f(fXValue,+fYValue,fZValue);
    akVertex[3] = Vector3f(fXValue,-fYValue,fZValue);
    pkVertices = WM3_NEW Vector3fArray(4,akVertex);

    m_spkPlane1 = WM3_NEW TriMesh(pkVertices,pkIndices,false);

    // create a texture effect for the plane
    aucData = WM3_NEW unsigned char[4*sizeof(int)];
    uiColor = System::MakeRGBA(0x7F,0x7F,0x7F,0xFF);
    auiData = (unsigned int*)aucData;
    auiData[0] = uiColor;
    auiData[1] = uiColor;
    auiData[2] = uiColor;
    auiData[3] = uiColor;
    pkImage = WM3_NEW Image(Image::IT_RGBA8888,2,2,aucData);

    Texture* pkTexture1 = WM3_NEW Texture(pkImage);
    pkEffect = WM3_NEW TextureEffect(pkTexture1,pkUVs);
    m_spkPlane1->SetEffect(pkEffect);

    m_spkScene->AttachChild(m_spkPlane1);
}
//----------------------------------------------------------------------------
void PlanarReflections::CreatePlanarReflection ()
{
    PlanarReflectionEffect* pkEffect = WM3_NEW PlanarReflectionEffect(2);
    pkEffect->SetPlane(0,m_spkPlane0);
    pkEffect->SetReflectance(0,0.1f);
    pkEffect->SetPlane(1,m_spkPlane1);
    pkEffect->SetReflectance(1,0.5f);
    m_spkBiped->SetEffect(pkEffect);
}
//----------------------------------------------------------------------------
void PlanarReflections::TestStream ()
{
    Stream kOStream;
    kOStream.Insert(m_spkScene);
    kOStream.Save("PlanarReflections.wmof");

    Stream kIStream;
    kIStream.Load("PlanarReflections.wmof");
    NodePtr spkScene = (Node*)kIStream.GetObjectAt(0);
}
//----------------------------------------------------------------------------

