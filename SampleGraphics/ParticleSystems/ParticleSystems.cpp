// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#include "ParticleSystems.h"
#include "BloodCellController.h"

WM3_WINDOW_APPLICATION(ParticleSystems);

//----------------------------------------------------------------------------
ParticleSystems::ParticleSystems ()
    :
    WindowApplication3("ParticleSystems",0,0,640,480,ColorRGB(0.5f,0.0f,1.0f))
{
}
//----------------------------------------------------------------------------
bool ParticleSystems::OnInitialize ()
{
    if (!WindowApplication3::OnInitialize())
    {
        return false;
    }

    // set up camera
    m_spkCamera->SetFrustum(-0.55f,0.55f,-0.4125f,0.4125f,1.0f,1000.0f);
    Vector3f kCLoc(4.0f,0.0f,0.0f);
    Vector3f kCDir(-1.0f,0.0f,0.0f);
    Vector3f kCUp(0.0f,0.0f,1.0f);
    Vector3f kCRight = kCDir.Cross(kCUp);
    m_spkCamera->SetFrame(kCLoc,kCDir,kCUp,kCRight);

    // set up scene
    m_spkScene = WM3_NEW Node;
    m_spkWireframe = WM3_NEW WireframeState;
    m_spkScene->SetGlobalState(m_spkWireframe);
    m_spkScene->AttachChild(CreateParticles());

    // initial update of objects
    m_spkScene->UpdateGS();
    m_spkScene->UpdateRS();

    InitializeCameraMotion(0.001f,0.001f);
    InitializeObjectMotion(m_spkScene);
    return true;
}
//----------------------------------------------------------------------------
void ParticleSystems::OnTerminate ()
{
    m_spkScene = 0;
    m_spkWireframe = 0;
    WindowApplication3::OnTerminate();
}
//----------------------------------------------------------------------------
void ParticleSystems::OnIdle ()
{
    MeasureTime();

    MoveCamera();
    MoveObject();
    m_spkScene->UpdateGS(System::GetTime());

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
bool ParticleSystems::OnKeyDown (unsigned char ucKey, int iX, int iY)
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

    case 's':
    case 'S':
        TestStream();
        return true;
    }

    return false;
}
//----------------------------------------------------------------------------
Image* ParticleSystems::CreateImage ()
{
    // create an image with transparency
    int iWidth = 32, iHeight = 32;
    float fFactor = 1.0f/(iWidth*iWidth + iHeight*iHeight);
    unsigned char* aucData = WM3_NEW unsigned char[4*iWidth*iHeight];
    int i = 0;
    for (int iY = 0; iY < iHeight; iY++)
    {
        for (int iX = 0; iX < iWidth; iX++)
        {
            aucData[i++] = 255;
            aucData[i++] = 0;
            aucData[i++] = 0;

            int iDX = 2*iX - iWidth;
            int iDY = 2*iY - iHeight;
            float fValue = fFactor*(iDX*iDX + iDY*iDY);
            assert(0.0f <= fValue && fValue <= 1.0f);
            if (fValue < 0.125f)
            {
                fValue = Mathf::Cos(4.0f*Mathf::PI*fValue);
            }
            else
            {
                fValue = 0.0f;
            }
            aucData[i++] = (unsigned char)(255.0f*fValue);
        }
    }

    return WM3_NEW Image(Image::IT_RGBA8888,iWidth,iHeight,aucData,
        "BloodCell.wmif");
}
//----------------------------------------------------------------------------
Particles* ParticleSystems::CreateParticles ()
{
    const int iVQuantity = 32;
    Vector3f* akVertex = WM3_NEW Vector3f[iVQuantity];
    float* afSize = WM3_NEW float[iVQuantity];
    for (int i = 0; i < iVQuantity; i++)
    {
        akVertex[i].X() = Mathf::SymmetricRandom();
        akVertex[i].Y() = Mathf::SymmetricRandom();
        akVertex[i].Z() = Mathf::SymmetricRandom();
        afSize[i] = 0.25f*Mathf::UnitRandom();
    }
    Vector3fArray* pkVertices = WM3_NEW Vector3fArray(iVQuantity,akVertex);
    FloatArray* pkSizes = WM3_NEW FloatArray(iVQuantity,afSize);

    Particles* pkParticles = WM3_NEW Particles(pkVertices,pkSizes,false);

    Vector2f* akUV = WM3_NEW Vector2f[4];
    akUV[0] = Vector2f(0.0f,0.0f);
    akUV[1] = Vector2f(1.0f,0.0f);
    akUV[2] = Vector2f(1.0f,1.0f);
    akUV[3] = Vector2f(0.0f,1.0f);
    Vector2fArray* pkUVs = WM3_NEW Vector2fArray(4,akUV);

    Texture* pkTexture = WM3_NEW Texture(CreateImage());
    Effect* pkEffect = WM3_NEW TextureEffect(pkTexture,pkUVs);
    pkParticles->SetEffect(pkEffect);

    AlphaState* pkAS = WM3_NEW AlphaState;
    pkAS->BlendEnabled = true;
    pkParticles->SetGlobalState(pkAS);

    ZBufferState* pkZS = WM3_NEW ZBufferState;
    pkZS->Enabled = false;
    pkParticles->SetGlobalState(pkZS);

    pkParticles->SetController(WM3_NEW BloodCellController);

    return pkParticles;
}
//----------------------------------------------------------------------------
void ParticleSystems::TestStream ()
{
    Stream kOStream;
    kOStream.Insert(m_spkScene);
    kOStream.Save("ParticleSystems.wmof");

    Stream kIStream;
    kIStream.Load("ParticleSystems.wmof");
    NodePtr spkScene = (Node*)kIStream.GetObjectAt(0);
}
//----------------------------------------------------------------------------

