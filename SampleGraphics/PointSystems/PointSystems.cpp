// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#include "PointSystems.h"
#include "RandomController.h"

WM3_WINDOW_APPLICATION(PointSystems);

//----------------------------------------------------------------------------
PointSystems::PointSystems ()
    :
    WindowApplication3("PointSystems",0,0,640,480,
        ColorRGB(0.75f,0.75f,0.75f))
{
}
//----------------------------------------------------------------------------
bool PointSystems::OnInitialize ()
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
    m_spkScene = WM3_NEW Node(1);

    int iVQuantity = 1024;
    Vector3f* akVertex = WM3_NEW Vector3f[iVQuantity];
    ColorRGB* akColor = WM3_NEW ColorRGB[iVQuantity];
    for (int i = 0; i < iVQuantity; i++)
    {
        akVertex[i].X() = Mathf::SymmetricRandom();
        akVertex[i].Y() = Mathf::SymmetricRandom();
        akVertex[i].Z() = Mathf::SymmetricRandom();
        akColor[i].R() = Mathf::UnitRandom();
        akColor[i].G() = Mathf::UnitRandom();
        akColor[i].B() = Mathf::UnitRandom();
    }

    Vector3fArray* pkVertices = WM3_NEW Vector3fArray(iVQuantity,akVertex);
    ColorRGBArray* pkColors = WM3_NEW ColorRGBArray(iVQuantity,akColor);
    Polypoint* pkPoints = WM3_NEW Polypoint(pkVertices);
    Effect* pkEffect = WM3_NEW VertexColorEffect(pkColors);
    pkPoints->SetEffect(pkEffect);

    pkPoints->SetController(WM3_NEW RandomController);

    m_spkScene->AttachChild(pkPoints);

    // initial update of objects
    m_spkScene->UpdateGS();
    m_spkScene->UpdateRS();

    InitializeCameraMotion(0.001f,0.001f);
    InitializeObjectMotion(m_spkScene);
    return true;
}
//----------------------------------------------------------------------------
void PointSystems::OnTerminate ()
{
    m_spkScene = 0;
    WindowApplication3::OnTerminate();
}
//----------------------------------------------------------------------------
void PointSystems::OnIdle ()
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
bool PointSystems::OnKeyDown (unsigned char ucKey, int iX, int iY)
{
    if (WindowApplication3::OnKeyDown(ucKey,iX,iY))
    {
        return true;
    }

    switch (ucKey)
    {
    case 's':
    case 'S':
        TestStream();
        return true;
    }

    return false;
}
//----------------------------------------------------------------------------
void PointSystems::TestStream ()
{
    Stream kOStream;
    kOStream.Insert(m_spkScene);
    kOStream.Save("PointSystems.wmof");

    Stream kIStream;
    kIStream.Load("PointSystems.wmof");
    NodePtr spkScene = (Node*)kIStream.GetObjectAt(0);
}
//----------------------------------------------------------------------------

