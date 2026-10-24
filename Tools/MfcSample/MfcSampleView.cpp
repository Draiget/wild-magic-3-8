// MfcSampleView.cpp : implementation of the CMfcSampleView class
//

#include "stdafx.h"
#include "MfcSample.h"

#include "MfcSampleDoc.h"
#include "MfcSampleView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMfcSampleView

IMPLEMENT_DYNCREATE(CMfcSampleView, CView)

BEGIN_MESSAGE_MAP(CMfcSampleView, CView)
    // Standard printing commands
    ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
    ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
    ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMfcSampleView construction/destruction

BOOL CMfcSampleView::PreCreateWindow(CREATESTRUCT& cs)
{
    // TODO: Modify the Window class or styles here by modifying
    //  the CREATESTRUCT cs

    return CView::PreCreateWindow(cs);
}

// CMfcSampleView drawing

void CMfcSampleView::OnDraw(CDC* /*pDC*/)
{
    CMfcSampleDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);
    if (!pDoc)
        return;

    // TODO: add draw code for native data here
}


// CMfcSampleView printing

BOOL CMfcSampleView::OnPreparePrinting(CPrintInfo* pInfo)
{
    // default preparation
    return DoPreparePrinting(pInfo);
}

void CMfcSampleView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
    // TODO: add extra initialization before printing
}

void CMfcSampleView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
    // TODO: add cleanup after printing
}


// CMfcSampleView diagnostics

#ifdef _DEBUG
void CMfcSampleView::AssertValid() const
{
    CView::AssertValid();
}

void CMfcSampleView::Dump(CDumpContext& dc) const
{
    CView::Dump(dc);
}

// non-debug version is inline
CMfcSampleDoc* CMfcSampleView::GetDocument() const
{
    ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMfcSampleDoc)));
    return (CMfcSampleDoc*)m_pDocument;
}
#endif //_DEBUG


// CMfcSampleView message handlers

//----------------------------------------------------------------------------
// begin Wild Magic specific
//----------------------------------------------------------------------------
#include "Wm3WglRenderer.h"
//----------------------------------------------------------------------------
CMfcSampleView::CMfcSampleView()
{
    m_pkRenderer = 0;
}
//----------------------------------------------------------------------------
CMfcSampleView::~CMfcSampleView()
{
    theApp.RemoveView(this);

    // This must occur before camera destruction.
    if ( m_pkRenderer )
        m_pkRenderer->SetCamera(0);

    m_spkCamera = 0;
    m_spkScene = 0;

    // This must occur after camera destructionn.
    delete m_pkRenderer;
    m_pkRenderer = 0;
}
//----------------------------------------------------------------------------
void CMfcSampleView::OnInitialUpdate ()
{
    // Register the view with the application object so that the view gets
    // updated during idle time.
    theApp.AddView(this);

    // If these numbers are changed here, they need to be changed in
    // CChildFrame::PreCreateWindow.
    int iWidth = 320, iHeight = 240;

    // create an OpenGL renderer
    m_pkRenderer = new WglRenderer(m_hWnd,BufferParams(),iWidth,iHeight);
    m_pkRenderer->SetBackgroundColor(ColorRGB(0.5f,0.0f,1.0f));

    // get the scene graph
    CMfcSampleDoc& doc = *GetDocument();
    m_spkScene = doc.m_spkScene;

    // create a camera
    m_spkCamera = new Camera;
    m_pkRenderer->SetCamera(m_spkCamera);
    m_spkCamera->SetFrustum(-0.55f,0.55f,-0.4125f,0.4125f,1.0f,1000.0f);
    Vector3f kCDir(0.0f,1.0f,0.0f);
    Vector3f kCUp(0.0f,0.0f,1.0f);
    Vector3f kCRight = kCDir.Cross(kCUp);

    Vector3f kCLoc;
    if ( m_spkScene )
        kCLoc = -3.0f*m_spkScene->WorldBound->GetRadius()*kCDir;
    else
        kCLoc = Vector3f::ZERO;

    m_spkCamera->SetFrame(kCLoc,kCDir,kCUp,kCRight);
}
//----------------------------------------------------------------------------
void CMfcSampleView::OnIdle ()
{
    if ( m_pkRenderer )
    {
        m_pkRenderer->ClearBuffers();
        if ( m_pkRenderer->BeginScene() )
        {
            m_pkRenderer->DrawScene(m_spkScene);
            m_pkRenderer->EndScene();
        }
        m_pkRenderer->DisplayBackBuffer();
    }
}
//----------------------------------------------------------------------------
// end Wild Magic specific
//----------------------------------------------------------------------------
