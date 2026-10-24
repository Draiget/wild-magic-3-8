// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#include "MaterialAlpha.h"

WM3_WINDOW_APPLICATION(MaterialAlpha);

//----------------------------------------------------------------------------
MaterialAlpha::MaterialAlpha ()
    :
    WindowApplication3("MaterialAlpha",0,0,640,480,ColorRGB::WHITE)
{
}
//----------------------------------------------------------------------------
bool MaterialAlpha::OnInitialize ()
{
    if (!WindowApplication3::OnInitialize())
    {
        return false;
    }

    CreateScene();

    // center-and-fit
    m_spkScene->UpdateGS();
    m_spkScene->GetChild(0)->Local.SetTranslate(
        -m_spkScene->WorldBound->GetCenter());
    m_spkCamera->SetFrustum(-0.55f,0.55f,-0.4125f,0.4125f,1.0f,100.0f);
    Vector3f kCDir(0.0f,0.0f,1.0f);
    Vector3f kCUp(0.0f,1.0f,0.0f);
    Vector3f kCRight = kCDir.Cross(kCUp);
    Vector3f kCLoc = -2.0f*m_spkScene->WorldBound->GetRadius()*kCDir;
    m_spkCamera->SetFrame(kCLoc,kCDir,kCUp,kCRight);

    // initial update of objects
    m_spkScene->UpdateGS();
    m_spkScene->UpdateRS();

    InitializeCameraMotion(0.01f,0.001f);
    InitializeObjectMotion(m_spkScene);
    return true;
}
//----------------------------------------------------------------------------
void MaterialAlpha::OnTerminate ()
{
    m_spkScene = 0;
    m_spkMaterial = 0;
    m_spkWireframe = 0;
    m_spkLight = 0;
    WindowApplication3::OnTerminate();
}
//----------------------------------------------------------------------------
void MaterialAlpha::OnIdle ()
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
bool MaterialAlpha::OnKeyDown (unsigned char ucKey, int iX, int iY)
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
    case '+':
    case '=':
        m_spkMaterial->Diffuse.A() += 0.1f;
        if (m_spkMaterial->Diffuse.A() > 1.0f)
        {
            m_spkMaterial->Diffuse.A() = 1.0f;
        }
        return true;
    case '-':
    case '_':
        m_spkMaterial->Diffuse.A() -= 0.1f;
        if (m_spkMaterial->Diffuse.A() < 0.0f)
        {
            m_spkMaterial->Diffuse.A() = 0.0f;
        }
        return true;
    case 'l':
    case 'L':
        m_spkLight->On = !m_spkLight->On;
        return true;
    case 's':
    case 'S':
        TestStream();
        return true;
    }

    return false;
}
//----------------------------------------------------------------------------
void MaterialAlpha::CreateScene ()
{
    m_spkScene = WM3_NEW Node;
    m_spkWireframe = WM3_NEW WireframeState;
    m_spkScene->SetGlobalState(m_spkWireframe);

    Node* pkTrnNode = WM3_NEW Node;
    m_spkScene->AttachChild(pkTrnNode);

    // vertices
    Vector3f* akVertex = WM3_NEW Vector3f[4];
    akVertex[0] = Vector3f(-1.0f,-1.0f,0.0f);
    akVertex[1] = Vector3f(-1.0f, 1.0f,0.0f);
    akVertex[2] = Vector3f( 1.0f, 1.0f,0.0f);
    akVertex[3] = Vector3f( 1.0f,-1.0f,0.0f);
    Vector3fArray* pkVertices = WM3_NEW Vector3fArray(4,akVertex);

    // indices
    int* aiIndex = WM3_NEW int[6];
    aiIndex[0] = 0;  aiIndex[1] = 1; aiIndex[2] = 3;
    aiIndex[3] = 3;  aiIndex[4] = 1; aiIndex[5] = 2;
    IntArray* pkIndices = WM3_NEW IntArray(6,aiIndex);

    // square with door texture
    TriMesh* pkBSquare = WM3_NEW TriMesh(pkVertices,pkIndices,false);
    pkTrnNode->AttachChild(pkBSquare);
    //pkBSquare->ForceCull = true;

    // create a texture effect
    Vector2f* akUV = WM3_NEW Vector2f[4];
    akUV[0] = Vector2f(0.0f,0.0f);
    akUV[1] = Vector2f(1.0f,0.0f);
    akUV[2] = Vector2f(1.0f,1.0f);
    akUV[3] = Vector2f(0.0f,1.0f);
    Vector2fArray* pkUVs = WM3_NEW Vector2fArray(4,akUV);

    Texture* pkTexture = WM3_NEW Texture(
        Image::Load(System::GetPath("../../Data/Wmif/","Door.wmif")));
    pkTexture->Apply = Texture::AM_REPLACE;
    Effect* pkEffect = WM3_NEW TextureEffect(pkTexture,pkUVs);
    pkBSquare->SetEffect(pkEffect);

    // Create a square with
    //   1. material that has diffuse alpha less than one
    //   2. alpha state to enable blending
    //   3. texture
    // The texture is combined with the material to produce a semitransparent
    // effect on the TSquare.  You should be able to see BSquare through it.
    TriMesh* pkTSquare = WM3_NEW TriMesh(pkVertices,pkIndices,false);
    pkTrnNode->AttachChild(pkTSquare);
    pkTSquare->Local.SetTranslate(Vector3f(0.5f,0.5f,-0.1f));

    // create a material whose alpha may be less than one
    m_spkMaterial = WM3_NEW MaterialState;
    m_spkMaterial->Emissive = ColorRGBA(0.0f,0.0f,0.0f,1.0f);
    m_spkMaterial->Ambient = ColorRGBA(0.5f,0.5f,0.5f,1.0f);
    m_spkMaterial->Diffuse = ColorRGBA(0.0f,0.0f,1.0f,0.5f);
    m_spkMaterial->Specular = ColorRGBA(0.8f,0.8f,0.8f,1.0f);
    m_spkMaterial->Shininess = 0.0f;
    pkTSquare->SetGlobalState(m_spkMaterial);

    // blending needs to be enabled for material alpha
    AlphaState* pkAS = WM3_NEW AlphaState;
    pkAS->BlendEnabled = true;
    pkTSquare->SetGlobalState(pkAS);

    // add a texture on top of it
    pkTSquare->SetEffect(pkEffect);

    // Create an ambient light.  If you turn the light off, the
    // semitransparent effect of the material+texture on TSquare no longer
    // works.
    m_spkLight = WM3_NEW Light(Light::LT_AMBIENT);
    m_spkLight->Ambient = ColorRGBA(0.25f,0.25f,0.25f,1.0f);
    m_spkLight->Diffuse = ColorRGBA::WHITE;
    m_spkLight->Specular = ColorRGBA::BLACK;
    m_spkLight->On = true;
    m_spkLight->UpdateGS();
    m_spkScene->SetLight(m_spkLight);
}
//----------------------------------------------------------------------------
void MaterialAlpha::TestStream ()
{
    Stream kOStream;
    kOStream.Insert(m_spkScene);
    kOStream.Save("MaterialAlpha.wmof");

    Stream kIStream;
    kIStream.Load("MaterialAlpha.wmof");
    NodePtr spkScene = (Node*)kIStream.GetObjectAt(0);
}
//----------------------------------------------------------------------------

