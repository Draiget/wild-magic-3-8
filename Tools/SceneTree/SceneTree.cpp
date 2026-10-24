// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#include "Wm3Foundation.h"
#include "TreeControl.h"
using namespace Wm3;

//----------------------------------------------------------------------------
static char* ProcessCommand (char* acArgument)
{
    size_t uiLength = strlen(acArgument);

    // strip off quotes if command line was built from double-clicking a file
    size_t uiSize = uiLength + 1;
    char* acProcessed = new char[uiSize];
    if (acArgument[0] == '\"')
    {
        // remove leading quote
        System::Strcpy(acProcessed,uiSize,acArgument+1);

        // remove trailing quote
        if (acArgument[uiLength-1] == '\"')
        {
            acProcessed[uiLength-2] = '\0';
        }
    }
    else
    {
        System::Strcpy(acProcessed,uiSize,acArgument);
    }

    return acProcessed;
}
//----------------------------------------------------------------------------
static int Run (HINSTANCE hInstance, LPSTR acIFile)
{
    if ( !acIFile || strlen(acIFile) <= 0 )
        return -1;

    char* acModIFile = ProcessCommand(acIFile);

    Stream kStream;
    bool bLoaded = kStream.Load(acModIFile);
    if ( !bLoaded )
    {
        delete[] acModIFile;
        return -2;
    }

    TreeControl kTree(hInstance,0,kStream,acModIFile,0,0,640,480);
    delete[] acModIFile;

    MSG kMsg;
    BOOL bRet;
    while ( (bRet = GetMessage(&kMsg,0,0,0)) != 0 )
    {
        if ( bRet == -1 )
            break;

        if ( !TranslateAccelerator(0,0,&kMsg) )
        {
            TranslateMessage(&kMsg);
            DispatchMessage(&kMsg);
        }
    }

    return 0;
}
//----------------------------------------------------------------------------
int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE, LPSTR acIFile, int)
{
    Main::Initialize();
    int iResult = Run(hInstance,acIFile);
    Main::Terminate();
    return iResult;
}
//----------------------------------------------------------------------------




