// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#include "ScreenPolygons.h"

WM3_WINDOW_APPLICATION(ScreenPolygons);

//----------------------------------------------------------------------------
ScreenPolygons::ScreenPolygons ()
    :
    WindowApplication3("ScreenPolygons",0,0,640,480,ColorRGB(0.5f,0.0f,1.0f))
{
    m_dAnimTime = 0.0;
    m_dAnimTimeDelta = 0.01;
}
//----------------------------------------------------------------------------
bool ScreenPolygons::OnInitialize ()
{
    if (!WindowApplication3::OnInitialize())
    {
        return false;
    }

    // camera and view frustum
    m_spkCamera->SetFrustum(-0.55f,0.55f,-0.4125f,0.4125f,1.0f,1000.0f);
    Vector3f kCLoc(80.0f,0.0f,23.0f);
    Vector3f kCDir(-1.0f,0.0f,0.0f);
    Vector3f kCUp(0.0f,0.0f,1.0f);
    Vector3f kCRight = kCDir.Cross(kCUp);
    m_spkCamera->SetFrame(kCLoc,kCDir,kCUp,kCRight);

    // load the biped just for a model to display
    Stream kIStream;
    kIStream.Load(System::GetPath("../../Data/Wmof/","SkinnedBiped.wmof"));
    m_spkScene = DynamicCast<Node>(kIStream.GetObjectAt(0));
    m_spkScene->SetGlobalState(WM3_NEW ZBufferState);

    // the biped has only materials, so a light is needed
    Light* pkLight = WM3_NEW Light(Light::LT_DIRECTIONAL);
    pkLight->Ambient = ColorRGBA(0.5f,0.5f,0.5f,1.0f);
    pkLight->Diffuse = pkLight->Ambient;
    pkLight->Specular = ColorRGBA::BLACK;
    pkLight->SetDirection(kCDir);
    pkLight->UpdateGS();
    m_spkScene->SetLight(pkLight);

    // background is a screen polygon (z = 1)
    Vector2f* akVertex = WM3_NEW Vector2f[4];
    akVertex[0] = Vector2f(0.0f,0.0f);
    akVertex[1] = Vector2f(1.0f,0.0f);
    akVertex[2] = Vector2f(1.0f,1.0f);
    akVertex[3] = Vector2f(0.0f,1.0f);
    m_spkBackPoly = WM3_NEW ScreenPolygon(4,akVertex,false);

    // texture the background
    Texture* pkTexture = WM3_NEW Texture(
        Image::Load(System::GetPath("../../Data/Wmif/","RedSky.wmif")));
    pkTexture->Filter = Texture::FM_LINEAR;
    pkTexture->Mipmap = Texture::MM_NEAREST;
    Vector2f* akUV = WM3_NEW Vector2f[4];
    akUV[0] = Vector2f(0.0f,0.0f);
    akUV[1] = Vector2f(1.0f,0.0f);
    akUV[2] = Vector2f(1.0f,1.0f);
    akUV[3] = Vector2f(0.0f,1.0f);
    Vector2fArrayPtr spkUVs = WM3_NEW Vector2fArray(4,akUV);
    TextureEffect* pkEffect = WM3_NEW TextureEffect(pkTexture,spkUVs);
    m_spkBackPoly->SetEffect(pkEffect);

    // part of foreground is a screen polygon (z = 0)
    akVertex = WM3_NEW Vector2f[5];
    akVertex[0] = Vector2f(0.0f,0.0f);
    akVertex[1] = Vector2f(0.5f,0.0f);
    akVertex[2] = Vector2f(0.75f,0.5f);
    akVertex[3] = Vector2f(0.5f,0.75f);
    akVertex[4] = Vector2f(0.0f,0.5f);
    m_spkForePoly = WM3_NEW ScreenPolygon(5,akVertex,true);

    // add a texture to the foreground
    pkTexture = WM3_NEW Texture(Image::Load(
        System::GetPath("../../Data/Wmif/","Flower.wmif")));
    pkTexture->Filter = Texture::FM_LINEAR;
    pkTexture->Mipmap = Texture::MM_NEAREST;
    akUV = WM3_NEW Vector2f[5];
    akUV[0] = Vector2f(0.0f,0.0f);
    akUV[1] = Vector2f(0.67f,0.0f);
    akUV[2] = Vector2f(1.0f,0.67f);
    akUV[3] = Vector2f(0.67f,1.0f);
    akUV[4] = Vector2f(0.0f,0.67f);
    spkUVs = WM3_NEW Vector2fArray(5,akUV);
    pkEffect = WM3_NEW TextureEffect(pkTexture,spkUVs);
    m_spkForePoly->SetEffect(pkEffect);

    // make the foreground semitransparent
    AlphaState* pkAS = WM3_NEW AlphaState;
    pkAS->BlendEnabled = true;
    m_spkForePoly->SetGlobalState(pkAS);

    // add wireframe to see where the screen polygons are positioned
    m_spkWireframe = WM3_NEW WireframeState;
    m_spkBackPoly->SetGlobalState(m_spkWireframe);
    m_spkForePoly->SetGlobalState(m_spkWireframe);

    // initial update of objects
    m_spkBackPoly->UpdateGS();
    m_spkBackPoly->UpdateRS();
    m_spkForePoly->UpdateGS();
    m_spkForePoly->UpdateRS();
    m_spkScene->UpdateGS();
    m_spkScene->UpdateRS();

    InitializeCameraMotion(0.01f,0.01f);
    InitializeObjectMotion(m_spkScene);
    return true;
}
//----------------------------------------------------------------------------
void ScreenPolygons::OnTerminate ()
{
    m_spkScene = 0;
    m_spkBackPoly = 0;
    m_spkForePoly = 0;
    m_spkWireframe = 0;
    WindowApplication3::OnTerminate();
}
//----------------------------------------------------------------------------
void ScreenPolygons::OnIdle ()
{
    MeasureTime();

    MoveCamera();
    if (MoveObject())
    {
        m_spkScene->UpdateGS();
    }

    m_pkRenderer->ClearZBuffer();
    if (m_pkRenderer->BeginScene())
    {
        // draw background polygon first
        m_pkRenderer->Draw(m_spkBackPoly);

        m_pkRenderer->DrawScene(m_spkScene);

        // draw foreground polygon last
        m_pkRenderer->Draw(m_spkForePoly);

        // text goes on top of foreground polygon
        DrawFrameRate(8,GetHeight()-8,ColorRGBA::WHITE);

        m_pkRenderer->EndScene();
    }
    m_pkRenderer->DisplayBackBuffer();

    UpdateFrameCount();
}
//----------------------------------------------------------------------------
bool ScreenPolygons::OnKeyDown (unsigned char ucKey, int iX, int iY)
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
void ScreenPolygons::TestStream ()
{
    Stream kOStream;
    kOStream.Insert(m_spkScene);
    kOStream.Save("ScreenPolygons.wmof");

    Stream kIStream;
    kIStream.Load("ScreenPolygons.wmof");
    NodePtr spkScene = (Node*)kIStream.GetObjectAt(0);
}
//----------------------------------------------------------------------------

