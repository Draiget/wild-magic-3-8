// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#include "SimpleViewer.h"

WM3_WINDOW_APPLICATION(SimpleViewer);

//----------------------------------------------------------------------------
SimpleViewer::SimpleViewer ()
    :
    WindowApplication3("SimpleViewer",0,0,640,480,ColorRGB(0.5f,0.0f,1.0f))
{
    m_dAnimTime = 0.0;
    m_dAnimDelta = 0.01;
    m_bDoAnimation = false;
    m_acPicked[0] = 0;
}
//----------------------------------------------------------------------------
bool SimpleViewer::OnInitialize ()
{
    if (!WindowApplication3::OnInitialize())
    {
        return false;
    }

    // load the model
    char* acInFile = 0;
    if (!TheCommand->Filename(acInFile))
    {
        return false;
    }

    Stream kStream;
    Spatial* pkModel;
    if (kStream.Load(acInFile))
    {
        pkModel = DynamicCast<Spatial>(kStream.GetObjectAt(0));
        if (!pkModel)
        {
            WM3_DELETE[] acInFile;
            return false;
        }
    }
    else
    {
        WM3_DELETE[] acInFile;
        return false;
    }

    // create scene
    m_spkScene = WM3_NEW Node;
    m_spkWireframe = WM3_NEW WireframeState;
    m_spkScene->SetGlobalState(m_spkWireframe);
    m_spkScene->SetGlobalState(WM3_NEW ZBufferState);
    Node* pkTrnNode = WM3_NEW Node;
    m_spkScene->AttachChild(pkTrnNode);
    pkTrnNode->AttachChild(pkModel);

    // add light to illuminate material-based subobjects
    Light* pkALight = WM3_NEW Light(Light::LT_AMBIENT);
    pkALight->Ambient = ColorRGBA::WHITE;
    m_spkScene->SetLight(pkALight);

    // TEMP for TureChick
    //CullState* pkCS = WM3_NEW CullState;
    //pkCS->FrontFace = CullState::FT_CW;
    //m_spkScene->SetGlobalState(pkCS);

    // center-and-fit scene in the view frustum
    m_spkScene->UpdateGS();
    pkTrnNode->Local.SetTranslate(-m_spkScene->WorldBound->GetCenter());
    float fRadius = m_spkScene->WorldBound->GetRadius();
    m_spkCamera->SetFrustum(-0.55f,0.55f,-0.4125f,0.4125f,1.0f,100000.0f);
    Vector3f kCDir(0.0f,1.0f,0.0f);
    Vector3f kCUp(0.0f,0.0f,1.0f);
    Vector3f kCRight = kCDir.Cross(kCUp);
    Vector3f kCLoc = -3.0f*fRadius*kCDir;
    m_spkCamera->SetFrame(kCLoc,kCDir,kCUp,kCRight);

    // set up scene
    m_spkScene->UpdateGS(m_dAnimTime);
    m_spkScene->UpdateRS();

    //Stream kOStream;
    //kOStream.Insert(m_spkScene);
    //kOStream.Save("TureChikRun.wmof");

    InitializeCameraMotion(0.01f*fRadius,0.01f);
    InitializeObjectMotion(m_spkScene);
    return true;
}
//----------------------------------------------------------------------------
void SimpleViewer::OnTerminate ()
{
    m_spkScene = 0;
    m_spkWireframe = 0;
    WindowApplication3::OnTerminate();
}
//----------------------------------------------------------------------------
void SimpleViewer::OnIdle ()
{
    MeasureTime();

    MoveCamera();
    if (MoveObject())
    {
        m_spkScene->UpdateGS();
    }

    if (m_bDoAnimation)
    {
        m_spkScene->UpdateGS(m_dAnimTime);
        m_dAnimTime += m_dAnimDelta;
    }

    m_pkRenderer->ClearBuffers();
    if (m_pkRenderer->BeginScene())
    {
        m_pkRenderer->DrawScene(m_spkScene);
        DrawFrameRate(8,GetHeight()-8,ColorRGBA::WHITE);
        if ( m_acPicked[0] != 0 )
            m_pkRenderer->Draw(320,GetHeight()-8,ColorRGBA::WHITE,m_acPicked);
        m_pkRenderer->EndScene();
    }
    m_pkRenderer->DisplayBackBuffer();

    UpdateFrameCount();
}
//----------------------------------------------------------------------------
bool SimpleViewer::OnKeyDown (unsigned char ucKey, int iX, int iY)
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

    case 'A':
        m_dAnimTime = 0.0;
        return true;
    case 'a':
        m_bDoAnimation = !m_bDoAnimation;
        return true;
    }

    return false;
}
//----------------------------------------------------------------------------
bool SimpleViewer::OnMouseClick (int iButton, int iState, int iX, int iY,
    unsigned int uiModifiers)
{
    if (iState == MOUSE_DOWN && (uiModifiers & MODIFIER_CONTROL) != 0)
    {
        // do a picking operation
        Ray3f kRay;
        m_spkCamera->GetPickRay(iX,iY,GetWidth(),GetHeight(),kRay);
        Spatial::PickArray kResults;
        m_spkScene->DoPick(kRay,kResults);

        // display the selected object's name
        if (kResults.GetQuantity() > 0)
        {
            Spatial::PickRecord* pkClosest = Spatial::GetClosest(kResults);
            Spatial* pkIObject = pkClosest->IObject;
            assert(pkIObject->GetName().GetLength() > 0);
            System::Strcpy(m_acPicked,PICKED_SIZE,pkIObject->GetName());
            for (int i = 0; i < kResults.GetQuantity(); i++)
            {
                WM3_DELETE kResults[i];
            }
        }
        else
        {
            m_acPicked[0] = 0;
        }
        return true;
    }

    return WindowApplication3::OnMouseClick(iButton,iState,iX,iY,uiModifiers);
}
//----------------------------------------------------------------------------

