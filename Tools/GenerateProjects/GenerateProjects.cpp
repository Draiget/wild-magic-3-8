// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#include <Rpc.h>
#include <cassert>
#include <fstream>
#include <iostream>
using namespace std;

//#define CREATE_XCODE_TEMPLATE

extern int g_iTemplateVC80Length;
extern char* g_aacTemplateVC80[];

#ifndef CREATE_XCODE_TEMPLATE
extern int g_iTemplateXC15Length;
extern char* g_aacTemplateXC15[];
#endif

//----------------------------------------------------------------------------
void Usage ()
{
    cout << "usage: GenerateProjects projectname" << endl;
}
//----------------------------------------------------------------------------
char* GetGuidString ()
{
    UUID kGuid;
    RPC_STATUS kStatus = UuidCreate(&kGuid);
    if (kStatus != RPC_S_OK)
    {
        return 0;
    }

    unsigned char* aucString = 0;
    kStatus = UuidToString(&kGuid,&aucString);
    if (kStatus != RPC_S_OK || !aucString)
    {
        return 0;
    }

    char* acString = (char*)aucString;
    const size_t uiSize = strlen(acString) + 1;
    char* acCopy = new char[uiSize];

#if _MSC_VER >= 1400
    strcpy_s(acCopy,uiSize,acString);
#else
    strcpy(acCopy,acString);
#endif

    RpcStringFree(&aucString);

    return acCopy;
}
//----------------------------------------------------------------------------
bool GenerateVC80 (const char* acProjectName)
{
    char* acGuid = GetGuidString();
    if (!acGuid)
    {
        return false;
    }

    const size_t uiSize = 512;
    char acProjectFile[uiSize];
#if _MSC_VER >= 1400
    sprintf_s(acProjectFile,uiSize,"%s_VC80.vcproj",acProjectName);
#else
    sprintf(acProjectFile,"%s_VC80.vcproj",acProjectName);
#endif
    ofstream kOStr(acProjectFile);
    if (!kOStr)
    {
        return false;
    }

    char acString[uiSize];

    for (int iLine = 0; iLine < g_iTemplateVC80Length; iLine++)
    {
#if _MSC_VER >= 1400
        strcpy_s(acString,uiSize,g_aacTemplateVC80[iLine]);
#else
        strcpy(acString,g_aacTemplateVC80[iLine]);
#endif

        char* acSub;
        int iIndex, i;

        acSub = strstr(acString,"PROJECTNAME");
        if (acSub)
        {
            iIndex = (int)(acSub - acString);
            for (i = 0; i < iIndex; i++)
            {
                kOStr << acString[i];
            }

            kOStr << acProjectName;
            acSub += strlen("PROJECTNAME");
            kOStr << acSub << endl;
            continue;
        }

        acSub = strstr(acString,"GENERATEDGUID");
        if (acSub)
        {
            iIndex = (int)(acSub - acString);
            for (i = 0; i < iIndex; i++)
            {
                kOStr << acString[i];
            }

            kOStr << acGuid;

            acSub += strlen("GENERATEDGUID");
            kOStr << acSub << endl;
            continue;
        }

        kOStr << acString << endl;
    }

    kOStr.close();
    delete[] acGuid;
    return true;
}
//----------------------------------------------------------------------------
#ifndef CREATE_XCODE_TEMPLATE
bool GenerateXC15 (const char* acProjName)
{
    // open the output project file
    ofstream kOStr("project.pbxproj");
    assert(kOStr);
    if (!kOStr)
    {
        return false;
    }

    // substitute
    const size_t uiSize = 1024;
    char acString[uiSize];
    for (int iLine = 0; iLine < g_iTemplateXC15Length; iLine++)
    {
#if _MSC_VER >= 1400
        strcpy_s(acString,uiSize,g_aacTemplateXC15[iLine]);
#else
        strcpy(acString,g_aacTemplateXC15[iLine]);
#endif

        char* acSub = strstr(acString,"WM3APPNAME");
        int iIndex, i;
        if (acSub)
        {
            iIndex = (int)(acSub - acString);
            for (i = 0; i < iIndex; i++)
            {
                kOStr << acString[i];
            }

            kOStr << acProjName;

            acSub += strlen("WM3APPNAME");
            kOStr << acSub << endl;
            continue;
        }

        kOStr << acString << endl;
    }

    kOStr.close();
    return true;
}
#endif
//----------------------------------------------------------------------------
#ifdef CREATE_XCODE_TEMPLATE
void CreateXCodeTemplate ()
{
    ifstream kIStr("TemplatePBXPROJ.txt");
    assert(kIStr);
    ofstream kOStr("TemplateXC15.cpp");
    assert(kOStr);

    kOStr << "#ifndef CREATE_XCODE_TEMPLATE" << endl;
    kOStr << "int g_iTemplateXC15Length = 1039;" << endl;
    kOStr << "char* g_aacTemplateXC15[1039] =" << endl;
    kOStr << "{" << endl;

    const int iSize = 1024;
    char acString[iSize];
    for (int iLine = 1; iLine <= 1039; iLine++)
    {
        kIStr.getline(acString,iSize);
        kOStr << '\"';
        for (int i = 0; i < (int)strlen(acString); i++)
        {
            char cChar = acString[i];
            if (cChar == '\\')
            {
                kOStr << '\\' << '\\';
            }
            else if (cChar == '\"')
            {
                kOStr << '\\' << '\"';
            }
            else
            {
                kOStr << cChar;
            }
        }
        kOStr << '\"';
        if (iLine < 1039)
        {
            kOStr << ',';
        }
        kOStr << endl;
    }
    kOStr << "};" << endl;
    kOStr << "#endif" << endl;

    kIStr.close();
    kOStr.close();
}
#endif
//----------------------------------------------------------------------------
int main (int iQuantity, char** apcArgument)
{
    if (iQuantity != 2)
    {
        cout << "Incorrect number of command line arguments." << endl << endl;
        Usage();
        return -1;
    }

    const char* acSourceName = apcArgument[1];

    GenerateVC80(acSourceName);

    // Xcode 1.5
#ifdef CREATE_XCODE_TEMPLATE
    CreateXCodeTemplate();
#else
    GenerateXC15(acSourceName);
#endif

    return 0;
}
//----------------------------------------------------------------------------

