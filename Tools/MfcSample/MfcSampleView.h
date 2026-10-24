// MfcSampleView.h : interface of the CMfcSampleView class
//


#pragma once

// begin Wild Magic specific
#include "Wm3Foundation.h"
using namespace Wm3;
// end Wild Magic specific

class CMfcSampleView : public CView
{
protected: // create from serialization only
	CMfcSampleView();
	DECLARE_DYNCREATE(CMfcSampleView)

// Attributes
public:
	CMfcSampleDoc* GetDocument() const;

    // begin Wild Magic specific
    Renderer* m_pkRenderer;
    CameraPtr m_spkCamera;
    NodePtr m_spkScene;
    // end Wild Magic specific

// Operations
public:

    // begin Wild Magic specific
    void OnIdle ();
    // end Wild Magic specific

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
    virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

    // begin Wild Magic specific
    virtual void OnInitialUpdate();
    // end Wild Magic specific

protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CMfcSampleView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MfcSampleView.cpp
inline CMfcSampleDoc* CMfcSampleView::GetDocument() const
   { return reinterpret_cast<CMfcSampleDoc*>(m_pDocument); }
#endif

