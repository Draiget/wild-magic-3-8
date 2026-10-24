// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#include "BSplineFitDiscrete.h"

WM3_WINDOW_APPLICATION(BSplineFitDiscrete);

//----------------------------------------------------------------------------
BSplineFitDiscrete::BSplineFitDiscrete ()
    :
    WindowApplication3("BSplineFitDiscrete",0,0,640,480,ColorRGB::WHITE)
{
    m_pkBSpline = 0;
    m_akSample = 0;
}
//----------------------------------------------------------------------------
bool BSplineFitDiscrete::OnInitialize ()
{
    if (!WindowApplication3::OnInitialize())
    {
        return false;
    }

    m_spkCamera->SetFrustum(-0.055f,0.055f,-0.04125f,0.04125f,0.1f,100.0f);
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
void BSplineFitDiscrete::OnTerminate ()
{
    WM3_DELETE m_pkBSpline;
    m_spkScene = 0;
    m_spkEffect = 0;
    WindowApplication3::OnTerminate();
}
//----------------------------------------------------------------------------
void BSplineFitDiscrete::OnIdle ()
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
        m_pkRenderer->Draw(8,16,ColorRGBA::BLACK,m_acMessage);
        m_pkRenderer->EndScene();
    }
    m_pkRenderer->DisplayBackBuffer();

    UpdateFrameCount();
}
//----------------------------------------------------------------------------
bool BSplineFitDiscrete::OnKeyDown (unsigned char ucKey, int iX, int iY)
{
    if (WindowApplication3::OnKeyDown(ucKey,iX,iY))
    {
        return true;
    }

    switch (ucKey)
    {
    case 'd':  // reduce the degree
        if (m_iDegree > 1)
        {
            m_iDegree--;
            CreateBSplinePolyline();
        }
        return true;

    case 'D':  // increase the degree
        m_iDegree++;
        CreateBSplinePolyline();
        return true;

    case 's':  // (small) reduce the number of control points by 1
        if (m_iCtrlQuantity - 1 > m_iDegree+1)
        {
            m_iCtrlQuantity--;
            CreateBSplinePolyline();
        }
        return true;

    case 'S':  // (small) increase the number of control points by 1
        if (m_iCtrlQuantity + 1 < m_iSampleQuantity)
        {
            m_iCtrlQuantity++;
            CreateBSplinePolyline();
        }
        return true;

    case 'm':  // (medium) reduce the number of control points by 10
        if (m_iCtrlQuantity - 10 > m_iDegree+1)
        {
            m_iCtrlQuantity -= 10;
            CreateBSplinePolyline();
        }
        return true;

    case 'M':  // (medium) increase the number of control points by 10
        if (m_iCtrlQuantity + 10 < m_iSampleQuantity)
        {
            m_iCtrlQuantity += 10;
            CreateBSplinePolyline();
        }
        return true;

    case 'l':  // (large) reduce the number of control points by 100
        if (m_iCtrlQuantity - 100 > m_iDegree+1)
        {
            m_iCtrlQuantity -= 100;
            CreateBSplinePolyline();
        }
        return true;

    case 'L':  // (large) increase the number of control points by 100
        if (m_iCtrlQuantity + 100 < m_iSampleQuantity)
        {
            m_iCtrlQuantity += 100;
            CreateBSplinePolyline();
        }
        return true;
    }

    return false;
}
//----------------------------------------------------------------------------
void BSplineFitDiscrete::CreateScene ()
{
    m_spkScene = WM3_NEW Node(2);

    // Generate a spiral curve on a sphere and visualize as a randomly
    // colored polyline.
    m_iSampleQuantity = 1000;
    m_akSample = WM3_NEW Vector3f[m_iSampleQuantity];
    ColorRGB* akColor = WM3_NEW ColorRGB[m_iSampleQuantity];
    float fMult = 2.0f/(m_iSampleQuantity - 1), fT;
    int i;
    for (i = 0; i < m_iSampleQuantity; i++)
    {
        fT = -1.0f + fMult*i;
        float fAngle = 2.0f*Mathf::TWO_PI*fT;
        float fAmplitude = 1.0f - fT*fT;

        m_akSample[i].X() = fAmplitude*Mathf::Cos(fAngle);
        m_akSample[i].Y() = fAmplitude*Mathf::Sin(fAngle);
        m_akSample[i].Z() = fT;
        m_akSample[i].Normalize();

        akColor[i].R() = Mathf::UnitRandom();
        akColor[i].G() = 0.0f;
        akColor[i].B() = 0.0f;
    }

    Vector3fArray* pkVertices = WM3_NEW Vector3fArray(m_iSampleQuantity,
        m_akSample);

    ColorRGBArray* pkColors = WM3_NEW ColorRGBArray(m_iSampleQuantity,
        akColor);
    VertexColorEffect* pkEffect = WM3_NEW VertexColorEffect(pkColors);

    Polyline* pkPLine = WM3_NEW Polyline(pkVertices,false,true);
    pkPLine->SetEffect(pkEffect);
    m_spkScene->AttachChild(pkPLine);

    // Generate a least-squares fit to the spiral.  The degree and number of
    // control points can be modified during run time.
    m_iDegree = 3;
    m_iCtrlQuantity = m_iSampleQuantity/2;

    // Use blue colors for the fitted curve.
    ColorRGB* akNewColor = WM3_NEW ColorRGB[m_iSampleQuantity];
    for (i = 0; i < m_iSampleQuantity; i++)
    {
        akNewColor[i].R() = 0.0f;
        akNewColor[i].G() = 0.0f;
        akNewColor[i].B() = akColor[i].R();
    }
    pkColors = WM3_NEW ColorRGBArray(m_iSampleQuantity,akNewColor);
    m_spkEffect = WM3_NEW VertexColorEffect(pkColors);

    CreateBSplinePolyline();
}
//----------------------------------------------------------------------------
void BSplineFitDiscrete::CreateBSplinePolyline ()
{
    WM3_DELETE m_pkBSpline;

    // Create the curve from the current parameters.
    m_pkBSpline = WM3_NEW BSplineFitf(3,m_iSampleQuantity,
        (const float*)m_akSample,m_iDegree,m_iCtrlQuantity);

    // Sample it the same number of times as the original data.
    Vector3f* akResample = WM3_NEW Vector3f[m_iSampleQuantity];
    float fMult = 1.0f/(m_iSampleQuantity - 1);
    int i;
    for (i = 0; i < m_iSampleQuantity; i++)
    {
        float fT = fMult*i;
        m_pkBSpline->GetPosition(fT,(float*)akResample[i]);
    }

    // Compute error measurements.
    float fAvrError = 0.0f;
    float fRMSError = 0.0f;
    for (i = 0; i < m_iSampleQuantity; i++)
    {
        Vector3f kDiff = m_akSample[i] - akResample[i];
        float fSqrLength = kDiff.SquaredLength();
        fRMSError += fSqrLength;
        float fLength = Mathf::Sqrt(fSqrLength);
        fAvrError += fLength;
    }
    fAvrError /= (float)m_iSampleQuantity;
    fRMSError /= (float)m_iSampleQuantity;
    fRMSError = Mathf::Sqrt(fRMSError);

    Vector3fArray* pkVertices = WM3_NEW Vector3fArray(m_iSampleQuantity,
        akResample);

    Polyline* pkPLine = WM3_NEW Polyline(pkVertices,false,true);
    pkPLine->SetEffect(m_spkEffect);
    m_spkScene->SetChild(1,pkPLine);

    m_spkScene->UpdateGS();
    m_spkScene->UpdateRS();

    System::Sprintf(m_acMessage,MESSAGE_SIZE,
        "samples = %d, degree = %d, controls = %d, avr error = %f, "
        "rms error = %f",m_iSampleQuantity,m_iDegree,m_iCtrlQuantity,
        fAvrError,fRMSError);
}
//----------------------------------------------------------------------------

