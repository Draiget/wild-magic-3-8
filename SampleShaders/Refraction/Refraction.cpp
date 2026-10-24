// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#include "Refraction.h"

WM3_WINDOW_APPLICATION(Refraction);

//----------------------------------------------------------------------------
Refraction::Refraction ()
    :
    WindowApplication3("Refraction",0,0,480,480,ColorRGB(0.5f,0.0f,1.0f))
{
}
//----------------------------------------------------------------------------
bool Refraction::OnInitialize ()
{
    if (!WindowApplication3::OnInitialize())
    {
        return false;
    }

    m_spkCamera->SetFrustum(-0.4125f,0.4125f,-0.4125f,0.4125f,1.0f,10000.0f);
    Vector3f kCDir(1.0f,0.0f,0.0f);
    Vector3f kCUp(0.0f,0.0f,1.0f);
    Vector3f kCRight = kCDir.Cross(kCUp);
    Vector3f kCLoc = Vector3f(-250.0f,0.0f,0.0f);
    m_spkCamera->SetFrame(kCLoc,kCDir,kCUp,kCRight);

    CreateScene();

    m_spkScene->UpdateGS(0.0f);
    m_spkScene->UpdateRS();

    InitializeCameraMotion(0.1f,0.001f);
    InitializeObjectMotion(m_spkScene);
    return true;
}
//----------------------------------------------------------------------------
void Refraction::OnTerminate ()
{
    m_spkScene = 0;
    m_spkTrnNode = 0;
    m_spkEffect = 0;
    m_spkSPoly = 0;
    WindowApplication3::OnTerminate();
}
//----------------------------------------------------------------------------
void Refraction::OnIdle ()
{
    MeasureTime();

    if (MoveObject())
    {
        m_spkScene->UpdateGS(0.0f);
    }

    m_pkRenderer->ClearBuffers();
    if (m_pkRenderer->BeginScene())
    {
        m_pkRenderer->Draw(m_spkSPoly);
        m_pkRenderer->DrawScene(m_spkScene);
        DrawFrameRate(8,GetHeight()-8,ColorRGBA::WHITE);
        m_pkRenderer->EndScene();
    }
    m_pkRenderer->DisplayBackBuffer();

    UpdateFrameCount();
}
//----------------------------------------------------------------------------
bool Refraction::OnKeyDown (unsigned char ucKey, int iX, int iY)
{
    if (WindowApplication3::OnKeyDown(ucKey,iX,iY))
    {
        return true;
    }

    switch (ucKey)
    {
    case ' ':
        m_bReflection = !m_bReflection;
        if ( m_bReflection )
            m_spkEffect->SetFresnelConstants(Vector4f(0.1f,0.1f,0.2f,0.0f));
        else
            m_spkEffect->SetFresnelConstants(Vector4f(0.0f,0.0f,0.0f,0.0f));
        return true;
    case '+':
    case '=':
        m_fRIndex += 0.1f;
        m_spkEffect->SetIndexOfRefraction(m_fRIndex);
        return true;
    case '-':
    case '_':
        m_fRIndex -= 0.1f;
        m_spkEffect->SetIndexOfRefraction(m_fRIndex);
        return true;
    }

    return false;
}
//----------------------------------------------------------------------------
void Refraction::CreateScene ()
{
    m_spkScene = WM3_NEW Node;
    m_spkTrnNode = WM3_NEW Node;
    m_spkScene->AttachChild(m_spkTrnNode);

    // load the face model
    Stream kStream;
    bool bLoaded = kStream.Load(
        System::GetPath("../../Data/Wmof/","Face.wmof"));
    assert(bLoaded);
    (void)bLoaded;  // avoid warning in release build
    TriMesh* pkFace = DynamicCast<TriMesh>(kStream.GetObjectAt(0));
    assert( pkFace );

    // The face is centered at the origin.  The front of the face is visible
    // to an observer positioned on the negative y-axis and looking at the
    // origin.  The face orientation is such that the bottom to top of the
    // face is in the positive z-direction.  The environment mapping of the
    // shader program, reflection.cg, is in the x-direction.  This requires
    // positioning the face so that its front is visible looking in the
    // positive x-direction.  The camera must be positioned and oriented
    // accordingly.
    Matrix3f kZRot(Vector3f::UNIT_Z,-Mathf::HALF_PI);
    pkFace->Local.SetRotate(kZRot);

    m_spkTrnNode->AttachChild(pkFace);

    // create a background screen polygon
    Vector2f* akVertex = WM3_NEW Vector2f[4];
    akVertex[0] = Vector2f(0.0f,0.0f);
    akVertex[1] = Vector2f(1.0f,0.0f);
    akVertex[2] = Vector2f(1.0f,1.0f);
    akVertex[3] = Vector2f(0.0f,1.0f);
    m_spkSPoly = WM3_NEW ScreenPolygon(4,akVertex,false);

    Vector2f* akUV = WM3_NEW Vector2f[4];
    akUV[0] = Vector2f(0.0f,1.0f);
    akUV[1] = Vector2f(1.0f,1.0f);
    akUV[2] = Vector2f(1.0f,0.0f);
    akUV[3] = Vector2f(0.0f,0.0f);
    Vector2fArray* pkUVs = WM3_NEW Vector2fArray(4,akUV);

    Texture* pkTexture = WM3_NEW Texture(Image::Load(
        System::GetPath("../../Data/Wmif/","TilesDisks.wmif")));

    TextureEffect* pkEffect = WM3_NEW TextureEffect(pkTexture,pkUVs);
    m_spkSPoly->SetEffect(pkEffect);

    // create a refraction effect for the face
    Image* pkEnvironment = Image::Load(
        System::GetPath("../../Data/Wmif/","TilesEnvironment.wmif"));

    Image* pkReflection = Image::Load(
        System::GetPath("../../Data/Wmif/","TilesReflection.wmif"));

    m_spkEffect = WM3_NEW RefractionEffect(pkEnvironment,pkReflection);
    pkFace->SetEffect(m_spkEffect);

    // A negative index is not really physically correct, but it makes the
    // object appear to refract what is underneath it.
    m_fRIndex = -0.4f;
    m_bReflection = true;
    m_spkEffect->SetIndexOfRefraction(-0.4f);
    m_spkEffect->SetFresnelConstants(Vector4f(0.1f,0.1f,0.2f,0.0f));
}
//----------------------------------------------------------------------------

