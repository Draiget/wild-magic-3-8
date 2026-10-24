// ChildFrm.cpp : implementation of the CChildFrame class
//
#include "stdafx.h"
#include "MfcSample.h"

#include "ChildFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildFrame

IMPLEMENT_DYNCREATE(CChildFrame, CMDIChildWnd)

BEGIN_MESSAGE_MAP(CChildFrame, CMDIChildWnd)
END_MESSAGE_MAP()


// CChildFrame construction/destruction

CChildFrame::CChildFrame()
{
	// TODO: add member initialization code here
}

CChildFrame::~CChildFrame()
{
}

// CChildFrame diagnostics

#ifdef _DEBUG
void CChildFrame::AssertValid() const
{
	CMDIChildWnd::AssertValid();
}

void CChildFrame::Dump(CDumpContext& dc) const
{
	CMDIChildWnd::Dump(dc);
}

#endif //_DEBUG


// CChildFrame message handlers

//----------------------------------------------------------------------------
// begin Wild Magic specific
//----------------------------------------------------------------------------
BOOL CChildFrame::PreCreateWindow(CREATESTRUCT& cs)
{
    // If these numbers are changed here, they need to be changed in
    // CDisplayView::OnInitialUpdate.
	cs.cx = 320;
	cs.cy = 240;
	return CMDIChildWnd::PreCreateWindow(cs);
}
//----------------------------------------------------------------------------
// end Wild Magic specific
//----------------------------------------------------------------------------
