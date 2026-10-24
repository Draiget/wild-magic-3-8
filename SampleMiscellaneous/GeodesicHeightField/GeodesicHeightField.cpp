// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#include "GeodesicHeightField.h"

WM3_WINDOW_APPLICATION(GeodesicHeightField);

//----------------------------------------------------------------------------
GeodesicHeightField::GeodesicHeightField ()
    :
    WindowApplication3("GeodesicHeightField",0,0,640,480,
        ColorRGB(0.9f,0.9f,0.9f))
{
    m_pkSurface = 0;
    m_pkGeodesic = 0;
    m_iSelected = 0;
    m_akPoint[0].SetSize(2);
    m_akPoint[1].SetSize(2);
    m_dDistance = 1.0;
    m_dCurvature = 0.0;
}
//----------------------------------------------------------------------------
bool GeodesicHeightField::OnInitialize ()
{
    if (!WindowApplication3::OnInitialize())
    {
        return false;
    }

    // set camera
    m_spkCamera->SetFrustum(-0.055f,0.055f,-0.04125f,0.04125f,0.1f,100.0f);
    Vector3f kCLoc(0.0f,-4.0f,1.0f);
    Vector3f kCDir(0.0f,1.0f,0.0f);
    Vector3f kCUp(0.0f,0.0f,1.0f);
    Vector3f kCRight = kCDir.Cross(kCUp);
    m_spkCamera->SetFrame(kCLoc,kCDir,kCUp,kCRight);

    CreateScene();

    // initial update of objects
    m_spkScene->UpdateGS();
    m_spkScene->UpdateRS();

    InitializeCameraMotion(0.01f,0.01f);
    InitializeObjectMotion(m_spkScene);
    return true;
}
//----------------------------------------------------------------------------
void GeodesicHeightField::OnTerminate ()
{
    WM3_DELETE m_pkSurface;
    WM3_DELETE m_pkGeodesic;

    m_spkScene = 0;
    m_spkWireframe = 0;
    m_spkMesh = 0;
    m_spkTexture = 0;

    WindowApplication3::OnTerminate();
}
//----------------------------------------------------------------------------
void GeodesicHeightField::OnIdle ()
{
    MeasureTime();

    MoveCamera();
    if (MoveObject())
    {
        m_spkScene->UpdateGS();
    }

    if (m_iSelected == 2)
    {
        // draw approximate path
        int iCurrQuantity = m_pkGeodesic->GetCurrentQuantity();
        if (iCurrQuantity == 0)
        {
            iCurrQuantity = m_iPQuantity;
        }

        Image* pkImage = m_spkTexture->GetImage();
        memset(pkImage->GetData(),0xFF,3*pkImage->GetQuantity());

        int iX0 = (int)(pkImage->GetWidth()*m_akPath[0][0] + 0.5);
        int iY0 = (int)(pkImage->GetHeight()*m_akPath[0][1] + 0.5);
        for (int i = 1; i < iCurrQuantity; i++)
        {
            int iX1 = (int)(pkImage->GetWidth()*m_akPath[i][0] + 0.5);
            int iY1 = (int)(pkImage->GetHeight()*m_akPath[i][1] + 0.5);
            DrawLine(iX0,iY0,iX1,iY1,pkImage->GetWidth(),pkImage->GetData());
            iX0 = iX1;
            iY0 = iY1;
        }

        // Force the texture image to be reloaded in VRAM.
        m_pkRenderer->ReleaseTexture(m_spkTexture);
    }

    m_pkRenderer->ClearBuffers();
    if (m_pkRenderer->BeginScene())
    {
        m_pkRenderer->DrawScene(m_spkScene);
        DrawFrameRate(8,GetHeight()-8,ColorRGBA::BLACK);

        const size_t uiSize = 256;
        char acMsg[uiSize];
        System::Sprintf(acMsg,uiSize,
            "sub = %d, ref = %d, len = %15.12lf, avgcrv = %15.12lf",
            m_pkGeodesic->GetSubdivisionStep(),
            m_pkGeodesic->GetRefinementStep(),
            m_dDistance, m_dCurvature/m_dDistance);
        m_pkRenderer->Draw(8,16,ColorRGBA::BLACK,acMsg);

        m_pkRenderer->EndScene();
    }
    m_pkRenderer->DisplayBackBuffer();

    UpdateFrameCount();
}
//----------------------------------------------------------------------------
bool GeodesicHeightField::OnKeyDown (unsigned char ucKey, int iX, int iY)
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
bool GeodesicHeightField::OnMouseClick (int iButton, int iState, int iX,
    int iY, unsigned int uiModifiers)
{
    if ((uiModifiers & MODIFIER_SHIFT) == 0)
    {
        return WindowApplication3::OnMouseClick(iButton,iState,iX,iY,
            uiModifiers);
    }

    if (iState != MOUSE_DOWN || iButton != MOUSE_LEFT_BUTTON)
    {
        return false;
    }

    // Do a picking operation.
    Ray3f kRay;
    m_spkCamera->GetPickRay(iX,iY,GetWidth(),GetHeight(),kRay);
    Spatial::PickArray kResults;
    m_spkScene->DoPick(kRay,kResults);

    if (kResults.GetQuantity() > 0)
    {
        Spatial::PickRecord* pkClosest = Spatial::GetClosest(kResults);
        TriMesh* pkMesh = DynamicCast<TriMesh>(pkClosest->IObject);
        assert(pkMesh == m_spkMesh);
        (void)pkMesh;  // avoid warning in release build
        TriMesh::PickRecord* pkRecord = (TriMesh::PickRecord*)pkClosest;

        // Get the texture coordinates for the point of intersection.
        int iTriangle = pkRecord->Triangle;
        int i0 = 3*iTriangle, i1 = i0+1, i2 = i0+2;
        const int* aiIndex = m_spkMesh->Indices->GetData();
        int iV0 = aiIndex[i0];
        int iV1 = aiIndex[i1];
        int iV2 = aiIndex[i2];

        Effect* pkEffect = m_spkMesh->GetEffect();
        Vector2f* akUV = pkEffect->UVs[0]->GetData();
        Vector2f kIntr =
            akUV[iV0]*pkRecord->Bary0 +
            akUV[iV1]*pkRecord->Bary1 +
            akUV[iV2]*pkRecord->Bary2;

        // Save the point.
        m_akPoint[m_iSelected][0] = (double)kIntr.X();
        m_akPoint[m_iSelected][1] = (double)kIntr.Y();

        // Clear the texture image to white.
        Image* pkImage = m_spkTexture->GetImage();
        unsigned char* aucData = pkImage->GetData();
        memset(aucData,0xFF,3*pkImage->GetQuantity());

        // Get an end point.
        int iX = (int)(pkImage->GetWidth()*kIntr.X() + 0.5);
        int iY = (int)(pkImage->GetHeight()*kIntr.Y() + 0.5);
        m_aiXIntr[m_iSelected] = iX;
        m_aiYIntr[m_iSelected] = iY;
        m_iSelected++;

        // Mark the end points in black.
        int i;
        for (i = 0; i < m_iSelected; i++)
        {
            int iIndex = 3*(m_aiXIntr[i]+pkImage->GetWidth()*m_aiYIntr[i]);
            aucData[iIndex++] = 0;
            aucData[iIndex++] = 0;
            aucData[iIndex++] = 0;
        }

        if (m_iSelected == 2)
        {
            m_pkGeodesic->ComputeGeodesic(m_akPoint[0],m_akPoint[1],
                m_iPQuantity,m_akPath);

            m_iSelected = 0;
        }

        // Force the texture image to be reloaded in VRAM.
        m_pkRenderer->ReleaseTexture(m_spkTexture);

        for (i = 0; i < kResults.GetQuantity(); i++)
        {
            WM3_DELETE kResults[i];
        }
    }

    return true;
}
//----------------------------------------------------------------------------
void GeodesicHeightField::CreateScene ()
{
    m_spkScene = WM3_NEW Node;
    m_spkWireframe = WM3_NEW WireframeState;
    m_spkScene->SetGlobalState(m_spkWireframe);

    // Create the ground.  It covers a square with vertices (1,1,0), (1,-1,0),
    // (-1,1,0), and (-1,-1,0).
    const int iXSize = 64;
    const int iYSize = 64;
    const float fXExtent = 1.0f;
    const float fYExtent = 1.0f;
    StandardMesh kSM;
    kSM.Vertices(true).Normals(true,true).UVs(true,true);
    m_spkMesh = kSM.Rectangle(iXSize,iYSize,fXExtent,fYExtent);

    // Add a texture.
    const int iTXSize = 512;
    const int iTYSize = 512;
    const int iTQuantity = 3*iTXSize*iTYSize;
    unsigned char* aucData = WM3_NEW unsigned char[iTQuantity];
    memset(aucData,0xFF,iTQuantity);
    Image* pkImage = WM3_NEW Image(Image::IT_RGB888,iTXSize,iTYSize,aucData);
    m_spkTexture = WM3_NEW Texture(pkImage);
    m_spkTexture->Apply = Texture::AM_MODULATE;
    m_spkTexture->Filter = Texture::FM_LINEAR;
    m_spkTexture->Mipmap = Texture::MM_LINEAR_LINEAR;
    TextureEffect* pkEffect = WM3_NEW TextureEffect(m_spkTexture,
        kSM.GetUVs());
    m_spkMesh->SetEffect(pkEffect);

    // Create a B-Spline height field.  The heights of the control point are
    // defined in an input file.  The input file is structured as
    //
    // numUCtrlPoints numVCtrlPoints UDegree VDegree
    // z[0][0] z[0][1] ... z[0][numV-1]
    // z[1][0] z[1][1] ... z[1][numV_1]
    // :
    // z[numU-1][0] z[numU-1][1] ... z[numU-1][numV-1]

    std::ifstream kIStr(System::GetPath("","ControlPoints.txt"));
    assert(kIStr);
    int iNumUCtrlPoints, iNumVCtrlPoints, iUDegree, iVDegree;
    double dHeight;
    kIStr >> iNumUCtrlPoints;
    kIStr >> iNumVCtrlPoints;
    kIStr >> iUDegree;
    kIStr >> iVDegree;
    Vector3d** aakCtrlPoint;
    Allocate(iNumUCtrlPoints,iNumVCtrlPoints,aakCtrlPoint);

    for (int iU = 0; iU < iNumUCtrlPoints; iU++)
    {
        double dU = (double)(fXExtent*(-1.0f + 2.0f*iU/(iNumUCtrlPoints-1)));
        for (int iV = 0; iV < iNumVCtrlPoints; iV++)
        {
            double dV =
                (double)(fYExtent*(-1.0f + 2.0f*iV/(iNumVCtrlPoints-1)));

            kIStr >> dHeight;
            aakCtrlPoint[iU][iV] = Vector3d(dU,dV,dHeight);
        }
    }
    kIStr.close();

    m_pkSurface = WM3_NEW BSplineRectangled(iNumUCtrlPoints,iNumVCtrlPoints,
        aakCtrlPoint,iUDegree,iVDegree,false,false,true,true);

    Deallocate(aakCtrlPoint);

    int iVQuantity = m_spkMesh->Vertices->GetQuantity();
    Vector3f* akVertex = m_spkMesh->Vertices->GetData();
    int i;
    for (i = 0; i < iVQuantity; i++)
    {
        double dU = (double)((akVertex[i].X()+fXExtent)/(2.0f*fXExtent));
        double dV = (double)((akVertex[i].Y()+fYExtent)/(2.0f*fYExtent));
        akVertex[i].Z() = (float)m_pkSurface->P(dU,dV).Z();
    }
    m_spkMesh->UpdateMS(true);

    // Light the surface.
    Light* pkLight0 = WM3_NEW Light(Light::LT_DIRECTIONAL);
    pkLight0->SetDirection(Vector3f(0.0f,0.0f,-1.0f));
    pkLight0->Ambient = ColorRGBA::WHITE;
    pkLight0->Diffuse = ColorRGBA::WHITE;
    pkLight0->Specular = ColorRGBA::BLACK;
    pkLight0->UpdateGS();
    m_spkScene->SetLight(pkLight0);

    Light* pkLight1 = WM3_NEW Light(Light::LT_DIRECTIONAL);
    pkLight1->SetDirection(Vector3f(0.0f,0.0f,1.0f));
    pkLight1->Ambient = ColorRGBA::WHITE;
    pkLight1->Diffuse = ColorRGBA::WHITE;
    pkLight1->Specular = ColorRGBA::BLACK;
    pkLight1->UpdateGS();
    m_spkScene->SetLight(pkLight1);

    MaterialState* pkMaterial = WM3_NEW MaterialState;
    pkMaterial->Emissive = ColorRGBA::BLACK;
    pkMaterial->Ambient = ColorRGBA(0.24725f,0.2245f,0.0645f,1.0f);
    pkMaterial->Diffuse = ColorRGBA(0.34615f,0.3143f,0.0903f,1.0f);
    pkMaterial->Specular = ColorRGBA(0.797357f,0.723991f,0.208006f,1.0f);
    pkMaterial->Shininess = 83.2f;
    m_spkMesh->SetGlobalState(pkMaterial);

    CullState* pkCS = WM3_NEW CullState;
    pkCS->Enabled = false;
    m_spkMesh->SetGlobalState(pkCS);

    m_spkScene->AttachChild(m_spkMesh);

    // Create the geodesic calculator.
    m_pkGeodesic = WM3_NEW BSplineGeodesicd(*m_pkSurface);
    m_pkGeodesic->Subdivisions = 8;
    m_pkGeodesic->Refinements = 1;
    m_pkGeodesic->SearchRadius = 0.1;
    m_pkGeodesic->RefineCallback = &GeodesicHeightField::RefineCallback;

    m_iPQuantity = (1 << m_pkGeodesic->Subdivisions) + 1;
    m_akPath = WM3_NEW GVectord[m_iPQuantity];
    for (i = 0; i < m_iPQuantity; i++)
    {
        m_akPath[i].SetSize(2);
    }
}
//----------------------------------------------------------------------------
void GeodesicHeightField::DrawLine (int iX0, int iY0, int iX1, int iY1,
    int iWidth, unsigned char* aucData)
{
    // starting point of line
    int iX = iX0, iY = iY0;

    // direction of line
    int iDx = iX1-iX0, iDy = iY1-iY0;

    // increment or decrement depending on direction of line
    int iSx = (iDx > 0 ? 1 : (iDx < 0 ? -1 : 0));
    int iSy = (iDy > 0 ? 1 : (iDy < 0 ? -1 : 0));

    // decision parameters for voxel selection
    if (iDx < 0)
    {
        iDx = -iDx;
    }
    if (iDy < 0)
    {
        iDy = -iDy;
    }
    int iAx = 2*iDx, iAy = 2*iDy;
    int iDecX, iDecY;

    // determine largest direction component, single-step related variable
    int iMax = iDx, iVar = 0;
    if (iDy > iMax)
    {
        iVar = 1;
    }

    // traverse Bresenham line
    int iIndex;
    switch (iVar)
    {
    case 0:  // single-step in x-direction
        iDecY = iAy - iDx;
        for (/**/; /**/; iX += iSx, iDecY += iAy)
        {
            // process pixel
            iIndex = 3*(iX + iWidth*iY);
            aucData[iIndex++] = 0;
            aucData[iIndex++] = 0;
            aucData[iIndex++] = 0;

            // take Bresenham step
            if (iX == iX1)
            {
                break;
            }
            if (iDecY >= 0)
            {
                iDecY -= iAx;
                iY += iSy;
            }
        }
        break;
    case 1:  // single-step in y-direction
        iDecX = iAx - iDy;
        for (/**/; /**/; iY += iSy, iDecX += iAx)
        {
            // process pixel
            iIndex = 3*(iX + iWidth*iY);
            aucData[iIndex++] = 0;
            aucData[iIndex++] = 0;
            aucData[iIndex++] = 0;

            // take Bresenham step
            if (iY == iY1)
            {
                break;
            }
            if (iDecX >= 0)
            {
                iDecX -= iAy;
                iX += iSx;
            }
        }
        break;
    }
}
//----------------------------------------------------------------------------
void GeodesicHeightField::ComputeDistanceCurvature ()
{
    int iCurrQuantity = m_pkGeodesic->GetCurrentQuantity();
    if (iCurrQuantity == 0)
    {
        iCurrQuantity = m_iPQuantity;
    }

    m_dDistance = m_pkGeodesic->ComputeTotalLength(iCurrQuantity,m_akPath);
    m_dCurvature = m_pkGeodesic->ComputeTotalCurvature(iCurrQuantity,
        m_akPath);
}
//----------------------------------------------------------------------------
void GeodesicHeightField::RefineCallback ()
{
    GeodesicHeightField* pkApp = (GeodesicHeightField*)TheApplication;
    pkApp->ComputeDistanceCurvature();
    pkApp->OnDisplay();
}
//----------------------------------------------------------------------------

