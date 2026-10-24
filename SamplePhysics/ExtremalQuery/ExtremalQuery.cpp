// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#include "ExtremalQuery.h"
#include "Wm3ExtremalQuery3BSP.h"
#include "Wm3ExtremalQuery3PRJ.h"

WM3_WINDOW_APPLICATION(ExtremalQuery);

//----------------------------------------------------------------------------
ExtremalQuery::ExtremalQuery ()
    :
    WindowApplication3("ExtremalQuery",0,0,640,480,ColorRGB(0.8f,0.8f,0.8f))
{
    m_pkConvexPolyhedron = 0;
    m_pkExtremalQuery = 0;
}
//----------------------------------------------------------------------------
bool ExtremalQuery::OnInitialize ()
{
    if (!WindowApplication3::OnInitialize())
    {
        return false;
    }

    // Set up an orthogonal camera.  This projection type is used to make it
    // clear that the displayed extreme points really are extreme!  (The
    // perspective projection is deceptive.)
    m_spkCamera->SetFrustum(-2.0,2.0f,-1.5f,1.5f,1.0f,1000.0f);
    Vector3f kCLoc(4.0f,0.0f,0.0f);
    Vector3f kCDir(-1.0f,0.0f,0.0f);
    Vector3f kCUp(0.0f,0.0f,1.0f);
    Vector3f kCRight = kCDir.Cross(kCUp);
    m_spkCamera->SetFrame(kCLoc,kCDir,kCUp,kCRight);
    m_spkCamera->Perspective = false;

    // set up scene
    CreateScene();

    // initial update of objects
    m_spkScene->UpdateGS();
    m_spkScene->UpdateRS();

    InitializeObjectMotion(m_spkScene);
    return true;
}
//----------------------------------------------------------------------------
void ExtremalQuery::OnTerminate ()
{
    WM3_DELETE m_pkConvexPolyhedron;
    WM3_DELETE m_pkExtremalQuery;

    m_spkScene = 0;
    m_spkWireframe = 0;
    m_spkCull = 0;
    m_spkMaxSphere = 0;
    m_spkMinSphere = 0;
    WindowApplication3::OnTerminate();
}
//----------------------------------------------------------------------------
void ExtremalQuery::OnIdle ()
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
bool ExtremalQuery::OnKeyDown (unsigned char ucKey, int iX, int iY)
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
bool ExtremalQuery::OnMotion (int iButton, int iX, int iY,
    unsigned int uiModifiers)
{
    WindowApplication3::OnMotion(iButton,iX,iY,uiModifiers);
    UpdateExtremePoints();
    return true;
}
//----------------------------------------------------------------------------
void ExtremalQuery::CreateScene ()
{
    m_spkScene = WM3_NEW Node(1);
    m_spkWireframe = WM3_NEW WireframeState;
    m_spkScene->SetGlobalState(m_spkWireframe);
    m_spkCull = WM3_NEW CullState;
    m_spkCull->Enabled = false;
    m_spkScene->SetGlobalState(m_spkCull);

    const int iPQuantity = 32;
    CreateConvexPolyhedron(iPQuantity);
    m_spkScene->AttachChild(CreateVisualConvexPolyhedron());

    // Use small spheres to show the extreme points in the camera's right
    // direction.
    StandardMesh kSM;

    // maximum sphere
    m_spkMaxSphere = kSM.Sphere(8,8,0.05f);
    int iVQuantity = m_spkMaxSphere->Vertices->GetQuantity();
    ColorRGB* akColor = WM3_NEW ColorRGB[iVQuantity];
    memset(akColor,0,iVQuantity*sizeof(ColorRGB));
    ColorRGBArray* pkColors = WM3_NEW ColorRGBArray(iVQuantity,akColor);
    VertexColorEffect* pkEffect = WM3_NEW VertexColorEffect(pkColors);
    m_spkMaxSphere->SetEffect(pkEffect);
    m_spkScene->AttachChild(m_spkMaxSphere);

    // minimum sphere
    m_spkMinSphere = kSM.Sphere(8,8,0.05f);
    iVQuantity = m_spkMinSphere->Vertices->GetQuantity();
    akColor = WM3_NEW ColorRGB[iVQuantity];
    memset(akColor,0,iVQuantity*sizeof(ColorRGB));
    pkColors = WM3_NEW ColorRGBArray(iVQuantity,akColor);
    pkEffect = WM3_NEW VertexColorEffect(pkColors);
    m_spkMinSphere->SetEffect(pkEffect);
    m_spkScene->AttachChild(m_spkMinSphere);

    UpdateExtremePoints();
}
//----------------------------------------------------------------------------
void ExtremalQuery::CreateConvexPolyhedron (int iVQuantity)
{
    // Create the convex hull of a randomly generated set of points on the
    // unit sphere.
    Vector3f* akVertex = WM3_NEW Vector3f[iVQuantity];
    int i, j;
    for (i = 0; i < iVQuantity; i++)
    {
        for (j = 0; j < 3; j++)
        {
            akVertex[i][j] = Mathf::SymmetricRandom();
        }
        akVertex[i].Normalize();
    }

    ConvexHull3f kHull(iVQuantity,akVertex,0.001f,false,Query::QT_INT64);
    assert(kHull.GetDimension() == 3);
    int iIQuantity = 3*kHull.GetSimplexQuantity();
    int* aiIndex = WM3_NEW int[iIQuantity];
    memcpy(aiIndex,kHull.GetIndices(),iIQuantity*sizeof(int));

    m_pkConvexPolyhedron = WM3_NEW ConvexPolyhedron3f(iVQuantity,akVertex,
        iIQuantity/3,aiIndex,0,true);

    // Only one of these lines should be uncommented.
    //m_pkExtremalQuery = WM3_NEW ExtremalQuery3PRJf(*m_pkConvexPolyhedron);
    m_pkExtremalQuery = WM3_NEW ExtremalQuery3BSPf(*m_pkConvexPolyhedron);
}
//----------------------------------------------------------------------------
Node* ExtremalQuery::CreateVisualConvexPolyhedron ()
{
    const Vector3f* akVertex = m_pkConvexPolyhedron->GetVertices();
    int iTQuantity = m_pkConvexPolyhedron->GetTQuantity();
    int iIQuantity = 3*iTQuantity;
    const int* aiIndex = m_pkConvexPolyhedron->GetIndices();

    // Visualize the convex polyhedron as a collection of face-colored
    // triangles.
    Vector3f* akMVertex = WM3_NEW Vector3f[iIQuantity];
    int* aiMIndex = WM3_NEW int[iIQuantity];
    int i;
    for (i = 0; i < iIQuantity; i++)
    {
        akMVertex[i] = akVertex[aiIndex[i]];
        aiMIndex[i] = i;
    }
    Vector3fArray* pkVertices = WM3_NEW Vector3fArray(iIQuantity,akMVertex);
    IntArray* pkIndices = WM3_NEW IntArray(iIQuantity,aiMIndex);
    TriMesh* pkMesh = WM3_NEW TriMesh(pkVertices,pkIndices,false);

    // Use randomly generated vertex colors.
    ColorRGB* akColor = WM3_NEW ColorRGB[iIQuantity];
    for (i = 0; i < iTQuantity; i++)
    {
        ColorRGB kColor;
        for (int j = 0; j < 3; j++)
        {
            kColor[j] = Mathf::UnitRandom();
        }

        akColor[3*i  ] = kColor;
        akColor[3*i+1] = kColor;
        akColor[3*i+2] = kColor;
    }
    ColorRGBArray* pkColors = WM3_NEW ColorRGBArray(iIQuantity,akColor);
    VertexColorEffect* pkEffect = WM3_NEW VertexColorEffect(pkColors);
    pkMesh->SetEffect(pkEffect);

    Node* pkRoot = WM3_NEW Node(1);
    pkRoot->AttachChild(pkMesh);

    return pkRoot;
}
//----------------------------------------------------------------------------
void ExtremalQuery::UpdateExtremePoints ()
{
    Vector3f kDirection = m_spkScene->World.InvertVector(
        m_spkCamera->GetWorldRVector());

    int iPosDir, iNegDir;
    m_pkExtremalQuery->GetExtremeVertices(kDirection,iPosDir,iNegDir);

    Vector3f kExtreme = m_pkConvexPolyhedron->GetVertex(iPosDir);
    m_spkMaxSphere->Local.SetTranslate(kExtreme);

    kExtreme = m_pkConvexPolyhedron->GetVertex(iNegDir);
    m_spkMinSphere->Local.SetTranslate(kExtreme);

    m_spkScene->UpdateGS();
}
//----------------------------------------------------------------------------

