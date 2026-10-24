// MfcSampleDoc.h : interface of the CMfcSampleDoc class
//


#pragma once

// begin Wild Magic specific
#include "Wm3Foundation.h"
using namespace Wm3;
// end Wild Magic specific

class CMfcSampleDoc : public CDocument
{
protected: // create from serialization only
	CMfcSampleDoc();
	DECLARE_DYNCREATE(CMfcSampleDoc)

// Attributes
public:
    // begin Wild Magic specific
    NodePtr m_spkScene;
    // end Wild Magic specific

// Operations
public:

// Overrides
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

    // begin Wild Magic specific
	virtual BOOL OnOpenDocument (LPCTSTR lpszPathName);
	virtual void OnCloseDocument ();
    // end Wild Magic specific

// Implementation
public:
	virtual ~CMfcSampleDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};


