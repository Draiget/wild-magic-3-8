// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#include "Wm3ApplicationPCH.h"
#include "Wm3Application.h"
using namespace Wm3;

Application::EntryPoint Application::Run = 0;
Command* Application::TheCommand = 0;
Application* Application::TheApplication = 0;

//----------------------------------------------------------------------------
Application::Application ()
{
    memset(m_acExtraData,0,APP_EXTRA_DATA_QUANTITY*sizeof(char));
    m_bLaunchFileDialog = false;
}
//----------------------------------------------------------------------------
Application::~Application ()
{
}
//----------------------------------------------------------------------------
void Application::SetExtraData (int iIndex, int iSize, const void* pvData)
{
    if (0 <= iIndex && iIndex < APP_EXTRA_DATA_QUANTITY - iSize)
    {
        memcpy(m_acExtraData,pvData,iSize);
    }
}
//----------------------------------------------------------------------------
void Application::GetExtraData (int iIndex, int iSize, void* pvData) const
{
    if (0 <= iIndex && iIndex < APP_EXTRA_DATA_QUANTITY - iSize)
    {
        memcpy(pvData,m_acExtraData,iSize);
    }
}
//----------------------------------------------------------------------------
bool Application::LaunchFileDialog () const
{
    return m_bLaunchFileDialog;
}
//----------------------------------------------------------------------------
int main (int iQuantity, char** apcArgument)
{
    Main::Initialize();

    int iExitCode = 0;
    if (Application::Run)
    {
        Application::TheCommand = WM3_NEW Command(iQuantity,apcArgument);
        iExitCode = Application::Run(iQuantity,apcArgument);
        WM3_DELETE Application::TheCommand;
        Application::TheCommand = 0;
    }
    else
    {
        iExitCode = INT_MAX;
    }

    Main::Terminate();

    WM3_DELETE Application::TheApplication;
    Application::TheApplication = 0;

#ifdef WM3_MEMORY_MANAGER
#ifdef _DEBUG
    Memory::GenerateReport("MemoryReportDebug.txt");
#else
    Memory::GenerateReport("MemoryReportRelease.txt");
#endif
#endif

    return iExitCode;
}
//----------------------------------------------------------------------------

