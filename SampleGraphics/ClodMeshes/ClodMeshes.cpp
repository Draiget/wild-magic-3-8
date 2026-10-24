// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#include "ClodMeshes.h"

WM3_WINDOW_APPLICATION(ClodMeshes);

//----------------------------------------------------------------------------
ClodMeshes::ClodMeshes ()
    :
    WindowApplication3("ClodMeshes",0,0,640,480,ColorRGB(0.9f,0.9f,0.9f))
{
}
//----------------------------------------------------------------------------
bool ClodMeshes::OnInitialize ()
{
    if (!WindowApplication3::OnInitialize())
    {
        return false;
    }

    m_spkScene = WM3_NEW Node;
    Node* pkTrnNode = WM3_NEW Node;
    m_spkScene->AttachChild(pkTrnNode);
    m_spkWireframe = WM3_NEW WireframeState;
    m_spkScene->SetGlobalState(m_spkWireframe);

    // load trimesh face and clodify it
    Stream kIStream;
    kIStream.Load(System::GetPath("../../Data/Wmof/","Face.wmof"));
    TriMeshPtr spkMesh = StaticCast<TriMesh>(kIStream.GetObjectAt(0));

    int iVQuantity = spkMesh->Vertices->GetQuantity();
    int iTQuantity = spkMesh->GetTriangleQuantity();
    Vector3f* akVertex = WM3_NEW Vector3f[iVQuantity];
    int* aiIndex = WM3_NEW int[3*iTQuantity];
    memcpy(akVertex,spkMesh->Vertices->GetData(),iVQuantity*sizeof(Vector3f));
    memcpy(aiIndex,spkMesh->Indices->GetData(),3*iTQuantity*sizeof(int));

    int iCQuantity = 0;
    CollapseRecord* akCRecord = 0;
    CreateClodMesh kCCM(iVQuantity,akVertex,iTQuantity,aiIndex,iCQuantity,
        akCRecord);
    Vector3fArray* spkVertices = WM3_NEW Vector3fArray(iVQuantity,akVertex);
    IntArray* spkIndices = WM3_NEW IntArray(3*iTQuantity,aiIndex);

    m_spkClod = WM3_NEW ClodMesh(spkVertices,spkIndices,true,iCQuantity,
        akCRecord);

    m_spkClod->Local = spkMesh->Local;
    pkTrnNode->AttachChild(m_spkClod);

    // create a material
    MaterialState* pkMaterial = WM3_NEW MaterialState;
    pkMaterial->Emissive = ColorRGBA(0.0f,0.0f,0.0f,1.0f);
    pkMaterial->Ambient = ColorRGBA(0.5f,0.5f,0.5f,1.0f);
    pkMaterial->Diffuse = ColorRGBA(0.99607f,0.83920f,0.67059f,1.0f);
    pkMaterial->Specular = ColorRGBA(0.8f,0.8f,0.8f,1.0f);
    pkMaterial->Shininess = 0.0f;
    m_spkScene->SetGlobalState(pkMaterial);

    // create a directional light
    Light* pkLight = WM3_NEW Light(Light::LT_DIRECTIONAL);
    pkLight->Ambient = ColorRGBA(0.25f,0.25f,0.25f,1.0f);
    pkLight->Diffuse = ColorRGBA::WHITE;
    pkLight->Specular = ColorRGBA::BLACK;
    pkLight->On = true;
    pkLight->SetDirection(Vector3f::UNIT_Y);
    pkLight->UpdateGS();
    m_spkScene->SetLight(pkLight);

    // center-and-fit scene in the view frustum
    m_spkScene->UpdateGS();
    pkTrnNode->Local.SetTranslate(-m_spkScene->WorldBound->GetCenter());
    m_spkCamera->SetFrustum(-0.55f,0.55f,-0.4125f,0.4125f,1.0f,10000.0f);
    Vector3f kCDir(0.0f,1.0f,0.0f);
    Vector3f kCUp(0.0f,0.0f,1.0f);
    Vector3f kCRight = kCDir.Cross(kCUp);
    Vector3f kCLoc = -3.0f*m_spkScene->WorldBound->GetRadius()*kCDir;
    m_spkCamera->SetFrame(kCLoc,kCDir,kCUp,kCRight);

    // initial update of objects
    m_spkScene->UpdateGS();
    m_spkScene->UpdateRS();

    InitializeCameraMotion(1.0f,0.001f);
    InitializeObjectMotion(m_spkScene);
    return true;
}
//----------------------------------------------------------------------------
void ClodMeshes::OnTerminate ()
{
    m_spkScene = 0;
    m_spkClod = 0;
    m_spkWireframe = 0;
    WindowApplication3::OnTerminate();
}
//----------------------------------------------------------------------------
void ClodMeshes::OnIdle ()
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
        DrawFrameRate(8,GetHeight()-8,ColorRGBA::BLACK);
        DrawTriangleQuantity(128,GetHeight()-8,ColorRGBA::BLACK);
        m_pkRenderer->EndScene();
    }
    m_pkRenderer->DisplayBackBuffer();

    UpdateFrameCount();
}
//----------------------------------------------------------------------------
void ClodMeshes::DrawTriangleQuantity (int iX, int iY,
    const ColorRGBA& rkColor)
{
    if (m_spkClod && m_pkRenderer)
    {
        const size_t uiSize = 32;
        char acMessage[uiSize];
        System::Sprintf(acMessage,uiSize,"triangles: %d",
            m_spkClod->GetTriangleQuantity());
        m_pkRenderer->Draw(iX,iY,rkColor,acMessage);
    }
}
//----------------------------------------------------------------------------
bool ClodMeshes::OnKeyDown (unsigned char ucKey, int iX, int iY)
{
    if (WindowApplication3::OnKeyDown(ucKey,iX,iY))
    {
        return true;
    }

    switch (ucKey)
    {
    case '-':  // decrease triangle quantity
    case '_':
        if (m_spkClod->TargetRecord() < m_spkClod->GetRecordQuantity()-1)
        {
            m_spkClod->TargetRecord()++;
        }
        m_spkClod->UpdateGS();
        return true;

    case '+':  // increase triangle quantity
    case '=':
        if (m_spkClod->TargetRecord() > 0)
        {
            m_spkClod->TargetRecord()--;
        }
        m_spkClod->UpdateGS();
        return true;

    case 'c':  // toggle between half and full resolution
    case 'C':
        if (m_spkClod->TargetRecord() != 0)
        {
            m_spkClod->TargetRecord() = 0;
        }
        else
        {
            m_spkClod->TargetRecord() = 500;
        }
        m_spkClod->UpdateGS();
        return true;

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
void ClodMeshes::MoveForward ()
{
    WindowApplication3::MoveForward();

    Vector3f kDiff = m_spkScene->WorldBound->GetCenter()
        - m_spkCamera->GetWorldLocation();
    float fDepth = kDiff.Dot(m_spkCamera->GetWorldDVector());
    if (fDepth <= m_spkCamera->GetDMin())
    {
        m_spkClod->TargetRecord() = 0;
    }
    else if (fDepth >= m_spkCamera->GetDMax())
    {
        m_spkClod->TargetRecord() = m_spkClod->GetRecordQuantity() - 1;
    }
    else
    {
        // distance along camera direction controls triangle quantity
        float fN = m_spkCamera->GetDMin();
        float fF = m_spkCamera->GetDMax();
        float fRatio = (fDepth - fN)/(fF - fN);

        // allow nonlinear drop-off
        fRatio = Mathf::Pow(fRatio,0.5f);

        int iMaxIndex = m_spkClod->GetRecordQuantity() - 1;
        int iIndex = (int)(iMaxIndex*fRatio);
        m_spkClod->TargetRecord() = iIndex;
    }
}
//----------------------------------------------------------------------------
void ClodMeshes::MoveBackward ()
{
    WindowApplication3::MoveBackward();

    Vector3f kDiff = m_spkScene->WorldBound->GetCenter()
        - m_spkCamera->GetWorldLocation();
    float fDepth = kDiff.Dot(m_spkCamera->GetWorldDVector());
    if (fDepth <= m_spkCamera->GetDMin())
    {
        m_spkClod->TargetRecord() = 0;
    }
    else if (fDepth >= m_spkCamera->GetDMax())
    {
        m_spkClod->TargetRecord() = m_spkClod->GetRecordQuantity() - 1;
    }
    else
    {
        // distance along camera direction controls triangle quantity
        float fN = m_spkCamera->GetDMin();
        float fF = m_spkCamera->GetDMax();
        float fRatio = (fDepth - fN)/(fF - fN);

        // allow nonlinear drop-off
        fRatio = Mathf::Pow(fRatio,0.5f);

        int iMaxIndex = m_spkClod->GetRecordQuantity() - 1;
        int iIndex = (int)(iMaxIndex*fRatio);
        m_spkClod->TargetRecord() = iIndex;
    }
}
//----------------------------------------------------------------------------
void ClodMeshes::TestStream ()
{
    Stream kOStream;
    kOStream.Insert(m_spkScene);
    kOStream.Save("ClodMeshes.wmof");

    Stream kIStream;
    kIStream.Load("ClodMeshes.wmof");
    NodePtr spkScene = (Node*)kIStream.GetObjectAt(0);
}
//----------------------------------------------------------------------------

