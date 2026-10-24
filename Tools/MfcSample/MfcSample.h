// MfcSample.h : main header file for the MfcSample application
//
#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

// begin Wild Magic specific
#include <vector>
class CMfcSampleView;
// end Wild Magic specific

// CMfcSampleApp:
// See MfcSample.cpp for the implementation of this class
//

// begin Wild Magic specific
#include "Wm3WglRenderer.h"
// end Wild Magic specific

class CMfcSampleApp : public CWinApp
{
public:
	CMfcSampleApp();

    // begin Wild Magic specific
    void AddView (CMfcSampleView* pvView);
    void RemoveView (CMfcSampleView* pvView);
    std::vector<CMfcSampleView*> m_kViews;
    // end Wild Magic specific

// Overrides
public:
	virtual BOOL InitInstance();

    // begin Wild Magic specific
	virtual int ExitInstance();
	virtual BOOL OnIdle(LONG lCount);
    // end Wild Magic specific

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMfcSampleApp theApp;