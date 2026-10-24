// MfcSampleDoc.cpp : implementation of the CMfcSampleDoc class
//

#include "stdafx.h"
#include "MfcSample.h"

#include "MfcSampleDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMfcSampleDoc

IMPLEMENT_DYNCREATE(CMfcSampleDoc, CDocument)

BEGIN_MESSAGE_MAP(CMfcSampleDoc, CDocument)
END_MESSAGE_MAP()


// CMfcSampleDoc construction/destruction

CMfcSampleDoc::CMfcSampleDoc()
{
	// TODO: add one-time construction code here

}

CMfcSampleDoc::~CMfcSampleDoc()
{
}


// CMfcSampleDoc serialization

void CMfcSampleDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}


// CMfcSampleDoc diagnostics

#ifdef _DEBUG
void CMfcSampleDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMfcSampleDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMfcSampleDoc commands

//----------------------------------------------------------------------------
// begin Wild Magic specific
//----------------------------------------------------------------------------
BOOL CMfcSampleDoc::OnNewDocument()
{
	return FALSE;
}
//----------------------------------------------------------------------------
BOOL CMfcSampleDoc::OnOpenDocument (LPCTSTR lpszPathName) 
{
    Stream kStream;
    bool bLoaded = kStream.Load(lpszPathName);
    if ( !bLoaded )
        return FALSE;

    Spatial* pkModel = DynamicCast<Spatial>(kStream.GetObjectAt(0));
    if ( !pkModel )
        return FALSE;

    // create scene graph
    m_spkScene = new Node;
    Node* pkTrnNode = new Node;
    m_spkScene->AttachChild(pkTrnNode);
    pkTrnNode->AttachChild(pkModel);

    // Translate scene by its world bound center so that the new world bound
    // is centered at the origin.
    m_spkScene->UpdateGS();
    pkTrnNode->Local.SetTranslate(-m_spkScene->WorldBound->GetCenter());

    m_spkScene->UpdateGS();
    m_spkScene->UpdateRS();

    return TRUE;
}
//----------------------------------------------------------------------------
void CMfcSampleDoc::OnCloseDocument () 
{
    m_spkScene = 0;
    CDocument::OnCloseDocument();
}
//----------------------------------------------------------------------------
// end Wild Magic specific
//----------------------------------------------------------------------------
