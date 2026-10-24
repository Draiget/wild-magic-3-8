// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#include <cassert>
#include <cstdarg>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

//----------------------------------------------------------------------------
FILE* FOPEN (const char* acFilename, const char* acMode)
{
#if _MSC_VER >= 1400
    FILE* pkFile;
    errno_t uiError = fopen_s(&pkFile,acFilename,acMode);
    if (uiError == 0)
    {
        return pkFile;
    }
    else
    {
        return 0;
    }
#else
    return fopen(acFilename,acMode);
#endif
}
//----------------------------------------------------------------------------
int SPRINTF (char* acDst, size_t uiDstSize, const char* acFormat, ...)
{
    if (!acDst || uiDstSize == 0 || !acFormat)
    {
        return -1;
    }

    va_list acArgs;
    va_start(acArgs,acFormat);

#if _MSC_VER >= 1400
    int iNumWritten = vsprintf_s(acDst,uiDstSize,acFormat,acArgs);
#else
    int iNumWritten = vsprintf(acDst,acFormat,acArgs);
#endif

    va_end(acArgs);
    return iNumWritten;
}
//----------------------------------------------------------------------------
char* STRCPY (char* acDst, size_t uiDstSize, const char* acSrc)
{
#if _MSC_VER >= 1400
    errno_t uiError = strcpy_s(acDst,uiDstSize,acSrc);
    if (uiError == 0)
    {
        return acDst;
    }
    else
    {
        return 0;
    }
#else
    if (!acDst || uiDstSize == 0 || !acSrc)
    {
        // Be consistent with the behavior of strcpy_s.
        return 0;
    }

    size_t uiSrcLen = strlen(acSrc);
    if (uiSrcLen + 1 > uiDstSize)
    {
        // The source string is too large to copy to the destination.  To
        // be consistent with strcpy_s, return null as an indication that the
        // copy failed.
        return 0;
    }
    strncpy(acDst,acSrc,uiSrcLen);
    acDst[uiSrcLen] = 0;
    return acDst;
#endif
}
//----------------------------------------------------------------------------
static void CreateOglExtensions ()
{
    const size_t uiMaxSize = 4096;
    char* acLine = new char[uiMaxSize];
    char* acTmp = new char[uiMaxSize];
    char* pcResult;
    char* pcRetType;
    char* pcSignature;
    char* pcFunction;
    char* acFCopy;
    int i;

    FILE* pkHFile = FOPEN("Wm3OpenGLExtensions.h","wt");
    FILE* pkCFile = FOPEN("Wm3OpenGLExtensions.c","wt");

    // write the starting text in the H file
    FILE* pkIFile = FOPEN("OglExtHStart.txt","rt");
    while (fgets(acLine,(int)uiMaxSize,pkIFile))
    {
        fputs(acLine,pkHFile);
    }
    fclose(pkIFile);

    // write the starting text in the C file
    pkIFile = FOPEN("OglExtCStart.txt","rt");
    while (fgets(acLine,(int)uiMaxSize,pkIFile))
    {
        fputs(acLine,pkCFile);
    }
    fclose(pkIFile);

    std::vector<char*> kExtension;
    pkIFile = FOPEN("OglExt.txt","rt");
    while ((pcResult = fgets(acLine,(int)uiMaxSize,pkIFile)) != 0)
    {
        // skip blank lines
        while (pcResult && acLine[0] != '{')
        {
            pcResult = fgets(acLine,(int)uiMaxSize,pkIFile);
        }

        // get extension name
        assert(strlen(acLine) >= 5 && strncmp(acLine,"{ GL_",5) == 0);
        char* acExtension = &acLine[2];
        char* pcEnd = strpbrk(acExtension," \t\n");
        assert(pcEnd);
        *pcEnd = 0;

        // save extension for initialization function
        size_t uiSize = strlen(acExtension) + 1;
        char* acECopy = new char[uiSize];
        STRCPY(acECopy,uiSize,acExtension);
        kExtension.push_back(acECopy);

        std::vector<char*> kFunction;
        uiSize = strlen(acExtension) + 1;
        acECopy = new char[uiSize];
        STRCPY(acECopy,uiSize,acExtension);
        kFunction.push_back(acECopy);
        int iNumFunctions = 0;

        // start extension block in H file
        fputs("\n",pkHFile);
        fputs("/*----------------------------------------------------------"
            "----------------*/\n",pkHFile);
        SPRINTF(acTmp,uiMaxSize,"WM3_EXTERN int Wm3Exists_%s;\n",
            acExtension);
        fputs(acTmp,pkHFile);
        SPRINTF(acTmp,uiMaxSize,"WM3_EXTERN int Wm3NumFunctions_%s;\n",
            acExtension);
        fputs(acTmp,pkHFile);
        SPRINTF(acTmp,uiMaxSize,"#ifndef %s\n",acExtension);
        fputs(acTmp,pkHFile);
        SPRINTF(acTmp,uiMaxSize,"#define %s\n",acExtension);
        fputs(acTmp,pkHFile);
        SPRINTF(acTmp,uiMaxSize,"#define WM3_DEFINED_%s\n",acExtension);
        fputs(acTmp,pkHFile);

        // start extension block in C file
        fputs("\n",pkCFile);
        fputs("/*----------------------------------------------------------"
            "----------------*/\n",pkCFile);
        SPRINTF(acTmp,uiMaxSize,"int Wm3Exists_%s;\n",acExtension);
        fputs(acTmp,pkCFile);
        SPRINTF(acTmp,uiMaxSize,"int Wm3NumFunctions_%s;\n",acExtension);
        fputs(acTmp,pkCFile);
        SPRINTF(acTmp,uiMaxSize,"#ifdef WM3_DEFINED_%s\n",acExtension);
        fputs(acTmp,pkCFile);

        // get extension information
        bool bFirstDefine = true;
        bool bFirstTypedef = true;
        bool bFirstPrototype = true;
        while (true)
        {
            pcResult = fgets(acLine,(int)uiMaxSize,pkIFile);
            assert(pcResult);

            if (acLine[0] == '}')
            {
                // end of extension block
                break;
            }

            assert(acLine[0] == '@');

            switch (acLine[1])
            {
            case 'v':  // verbatim
                fputs(&acLine[3],pkHFile);
                break;

            case 'f':  // function pointer definition
                iNumFunctions++;

                // return type of function
                assert(acLine[3] != ' ');
                pcRetType = &acLine[3];

                // function name
                pcFunction = pcRetType;
                while (*pcFunction != 'g' || *(pcFunction+1) != 'l')
                {
                    pcFunction++;
                }
                pcFunction--;
                *pcFunction = 0;
                pcFunction++;

                // signature of function
                pcSignature = pcFunction;
                while (*pcSignature != ' ')
                {
                    pcSignature++;
                }
                *pcSignature = 0;
                pcSignature++;

                // H file information
                fputs("\n",pkHFile);
                SPRINTF(acTmp,uiMaxSize,"typedef %s (APIENTRY* pfn_%s) %s",
                    pcRetType,pcFunction,pcSignature);
                fputs(acTmp,pkHFile);
                SPRINTF(acTmp,uiMaxSize,"WM3_EXTERN pfn_%s Wm3%s;\n",
                    pcFunction,pcFunction);
                fputs(acTmp,pkHFile);
                SPRINTF(acTmp,uiMaxSize,"#define %s Wm3%s\n",pcFunction,
                    pcFunction);
                fputs(acTmp,pkHFile);

                // C file information
                uiSize = strlen(pcFunction) + 1;
                acFCopy = new char[uiSize];
                STRCPY(acFCopy,uiSize,pcFunction);
                kFunction.push_back(acFCopy);

                SPRINTF(acTmp,uiMaxSize,"pfn_%s Wm3%s = 0;\n",pcFunction,
                    pcFunction);
                fputs(acTmp,pkCFile);
                break;

            case 'p':  // function prototype (OpenGL 1.1)
                iNumFunctions++;

                // return type of function
                assert(acLine[3] != ' ');
                pcRetType = &acLine[3];

                // function name
                pcFunction = pcRetType;
                while (*pcFunction != 'g' || *(pcFunction+1) != 'l')
                {
                    pcFunction++;
                }
                pcFunction--;
                *pcFunction = 0;
                pcFunction++;

                // signature of function
                pcSignature = pcFunction;
                while (*pcSignature != ' ')
                {
                    pcSignature++;
                }
                *pcSignature = 0;
                pcSignature++;

                // H file information
                SPRINTF(acTmp,uiMaxSize,"WINGDIAPI %s APIENTRY %s %s",
                    pcRetType,pcFunction,pcSignature);
                fputs(acTmp,pkHFile);
                break;

            default:
                assert(false);
                break;
            }
        }

        // end of extension block in H file
        fputs("#endif\n",pkHFile);

        // end of extension block in C file
        if (kFunction.size() > 1)
        {
            fputs("\n",pkCFile);
        }

        SPRINTF(acTmp,uiMaxSize,"static void Init_%s ()\n",kFunction[0]);
        fputs(acTmp,pkCFile);
        fputs("{\n",pkCFile);

        if (kFunction.size() == 1)
        {
            // all prototypes (GL_VERSION_1_1)
            SPRINTF(acTmp,uiMaxSize,"    Wm3NumFunctions_%s = %d;\n",
                kFunction[0],iNumFunctions);
            fputs(acTmp,pkCFile);

            SPRINTF(acTmp,uiMaxSize,
                "    Wm3Exists_%s = WM3_EXT_FULLY_EXISTS;\n",kFunction[0]);
            fputs(acTmp,pkCFile);
        }
        else
        {
            SPRINTF(acTmp,uiMaxSize,
                "    Wm3NumFunctions_%s = 0;\n\n",kFunction[0]);
            fputs(acTmp,pkCFile);
            for (i = 1; i <= iNumFunctions; i++)
            {
                SPRINTF(acTmp,uiMaxSize,
                    "    Wm3%s = (pfn_%s)GetFunctionPointer(\"%s\");\n",
                    kFunction[i],kFunction[i],kFunction[i]);
                fputs(acTmp,pkCFile);

                SPRINTF(acTmp,uiMaxSize,"    if ( Wm3%s )\n",kFunction[i]);
                fputs(acTmp,pkCFile);

                SPRINTF(acTmp,uiMaxSize,"        ++Wm3NumFunctions_%s;\n\n",
                    kFunction[0]);
                fputs(acTmp,pkCFile);
            }
            SPRINTF(acTmp,uiMaxSize,"    if ( Wm3NumFunctions_%s == %d )\n",
                kFunction[0],iNumFunctions);
            fputs(acTmp,pkCFile);
            SPRINTF(acTmp,uiMaxSize,
                "        Wm3Exists_%s = WM3_EXT_FULLY_EXISTS;\n",
                kFunction[0]);
            fputs(acTmp,pkCFile);
            fputs("    else\n",pkCFile);
            SPRINTF(acTmp,uiMaxSize,
                "        Wm3Exists_%s = WM3_EXT_PARTIALLY_EXISTS;\n",
                kFunction[0]);
            fputs(acTmp,pkCFile);
        }
        fputs("}\n",pkCFile);

        fputs("#else\n",pkCFile);

        SPRINTF(acTmp,uiMaxSize,"static void Init_%s ()\n",kFunction[0]);
        fputs(acTmp,pkCFile);
        fputs("{\n",pkCFile);
        SPRINTF(acTmp,uiMaxSize,"    Wm3NumFunctions_%s = 0;\n",
            kFunction[0]);
        fputs(acTmp,pkCFile);
        SPRINTF(acTmp,uiMaxSize,
            "    Wm3Exists_%s = WM3_EXT_DOES_NOT_EXIST;\n",kFunction[0]);
        fputs(acTmp,pkCFile);
        fputs("}\n",pkCFile);

        fputs("#endif\n",pkCFile);

        for (i = 0; i < (int)kFunction.size(); i++)
        {
            delete kFunction[i];
        }
    }
    fclose(pkIFile);

    // initialization function
    fputs("\n",pkCFile);
    fputs("/*--------------------------------------------------------------"
        "------------*/\n",pkCFile);
    fputs("void InitializeOpenGL ()\n",pkCFile);
    fputs("{\n",pkCFile);
    for (i = 0; i < (int)kExtension.size(); i++)
    {
        SPRINTF(acTmp,uiMaxSize,"    Init_%s();\n",kExtension[i]);
        fputs(acTmp,pkCFile);
    }
    fputs("}\n",pkCFile);
    fputs("/*--------------------------------------------------------------"
        "------------*/\n",pkCFile);

    pkIFile = FOPEN("OglExtHFinal.txt","rt");
    while (fgets(acLine,(int)uiMaxSize,pkIFile))
    {
        fputs(acLine,pkHFile);
    }
    fclose(pkIFile);

    fclose(pkCFile);
    fclose(pkHFile);

    delete[] acTmp;
    delete[] acLine;
}
//----------------------------------------------------------------------------
static void CreateWglExtensions ()
{
    const size_t uiMaxSize = 4096;
    char* acLine = new char[uiMaxSize];
    char* acTmp = new char[uiMaxSize];
    char* pcResult;
    char* pcRetType;
    char* pcSignature;
    char* pcFunction;
    char* acFCopy;
    int i;

    FILE* pkHFile = FOPEN("Wm3WglExtensions.h","wt");
    FILE* pkCFile = FOPEN("Wm3WglExtensions.c","wt");

    // write the starting text in the H file
    FILE* pkIFile = FOPEN("WglExtHStart.txt","rt");
    while (fgets(acLine,(int)uiMaxSize,pkIFile))
    {
        fputs(acLine,pkHFile);
    }
    fclose(pkIFile);

    // write the starting text in the C file
    pkIFile = FOPEN("WglExtCStart.txt","rt");
    while (fgets(acLine,(int)uiMaxSize,pkIFile))
    {
        fputs(acLine,pkCFile);
    }
    fclose(pkIFile);

    std::vector<char*> kExtension;
    pkIFile = FOPEN("WglExt.txt","rt");
    while ((pcResult = fgets(acLine,(int)uiMaxSize,pkIFile)) != 0)
    {
        // skip blank lines
        while (pcResult && acLine[0] != '{')
        {
            pcResult = fgets(acLine,(int)uiMaxSize,pkIFile);
        }

        // get extension name
        assert(strlen(acLine) >= 6 && strncmp(acLine,"{ WGL_",6) == 0);
        char* acExtension = &acLine[2];
        char* pcEnd = strpbrk(acExtension," \t\n");
        assert(pcEnd);
        *pcEnd = 0;

        // save extension for initialization function
        size_t uiSize = strlen(acExtension) + 1;
        char* acECopy = new char[uiSize];
        STRCPY(acECopy,uiSize,acExtension);
        kExtension.push_back(acECopy);

        std::vector<char*> kFunction;
        uiSize = strlen(acExtension) + 1;
        acECopy = new char[uiSize];
        STRCPY(acECopy,uiSize,acExtension);
        kFunction.push_back(acECopy);
        int iNumFunctions = 0;

        // start extension block in H file
        fputs("\n",pkHFile);
        fputs("/*----------------------------------------------------------"
            "----------------*/\n",pkHFile);
        SPRINTF(acTmp,uiMaxSize,"WM3_EXTERN int Wm3Exists_%s;\n",
            acExtension);
        fputs(acTmp,pkHFile);
        SPRINTF(acTmp,uiMaxSize,"WM3_EXTERN int Wm3NumFunctions_%s;\n",
            acExtension);
        fputs(acTmp,pkHFile);
        SPRINTF(acTmp,uiMaxSize,"#ifndef %s\n",acExtension);
        fputs(acTmp,pkHFile);
        SPRINTF(acTmp,uiMaxSize,"#define %s\n",acExtension);
        fputs(acTmp,pkHFile);
        SPRINTF(acTmp,uiMaxSize,"#define WM3_DEFINED_%s\n",acExtension);
        fputs(acTmp,pkHFile);

        // start extension block in C file
        fputs("\n",pkCFile);
        fputs("/*----------------------------------------------------------"
            "----------------*/\n",pkCFile);
        SPRINTF(acTmp,uiMaxSize,"int Wm3Exists_%s;\n",acExtension);
        fputs(acTmp,pkCFile);
        SPRINTF(acTmp,uiMaxSize,"int Wm3NumFunctions_%s;\n",acExtension);
        fputs(acTmp,pkCFile);
        SPRINTF(acTmp,uiMaxSize,"#ifdef WM3_DEFINED_%s\n",acExtension);
        fputs(acTmp,pkCFile);

        // get extension information
        bool bFirstDefine = true;
        bool bFirstTypedef = true;
        bool bFirstPrototype = true;
        while (true)
        {
            pcResult = fgets(acLine,(int)uiMaxSize,pkIFile);
            assert(pcResult);

            if (acLine[0] == '}')
            {
                // end of extension block
                break;
            }

            assert(acLine[0] == '@');

            switch (acLine[1])
            {
            case 'v':  // verbatim
                fputs(&acLine[3],pkHFile);
                break;

            case 'f':  // function pointer definition
                iNumFunctions++;

                // return type of function
                assert(acLine[3] != ' ');
                pcRetType = &acLine[3];

                // function name
                pcFunction = pcRetType;
                while (*pcFunction != 'w'
                ||     *(pcFunction+1) != 'g'
                ||     *(pcFunction+2) != 'l')
                {
                    pcFunction++;
                }
                pcFunction--;
                *pcFunction = 0;
                pcFunction++;

                // signature of function
                pcSignature = pcFunction;
                while (*pcSignature != ' ')
                {
                    pcSignature++;
                }
                *pcSignature = 0;
                pcSignature++;

                // H file information
                fputs("\n",pkHFile);
                SPRINTF(acTmp,uiMaxSize,"typedef %s (WINAPI* pfn_%s) %s",
                    pcRetType,pcFunction,pcSignature);
                fputs(acTmp,pkHFile);
                SPRINTF(acTmp,uiMaxSize,"WM3_EXTERN pfn_%s Wm3%s;\n",
                    pcFunction,pcFunction);
                fputs(acTmp,pkHFile);
                SPRINTF(acTmp,uiMaxSize,"#define %s Wm3%s\n",pcFunction,
                    pcFunction);
                fputs(acTmp,pkHFile);

                // C file information
                uiSize = strlen(pcFunction) + 1;
                acFCopy = new char[uiSize];
                STRCPY(acFCopy,uiSize,pcFunction);
                kFunction.push_back(acFCopy);

                SPRINTF(acTmp,uiMaxSize,"pfn_%s Wm3%s = 0;\n",pcFunction,
                    pcFunction);
                fputs(acTmp,pkCFile);
                break;

            default:
                assert(false);
                break;
            }
        }

        // end of extension block in H file
        fputs("#endif\n",pkHFile);

        // end of extension block in C file
        fputs("\n",pkCFile);

        SPRINTF(acTmp,uiMaxSize,"static void Init_%s ()\n",kFunction[0]);
        fputs(acTmp,pkCFile);
        fputs("{\n",pkCFile);

        SPRINTF(acTmp,uiMaxSize,"    Wm3NumFunctions_%s = 0;\n\n",
            kFunction[0]);
        fputs(acTmp,pkCFile);
        for (i = 1; i <= iNumFunctions; i++)
        {
            SPRINTF(acTmp,uiMaxSize,
                "    Wm3%s = (pfn_%s)GetFunctionPointer(\"%s\");\n",
                kFunction[i],kFunction[i],kFunction[i]);
            fputs(acTmp,pkCFile);

            SPRINTF(acTmp,uiMaxSize,"    if ( Wm3%s )\n",kFunction[i]);
            fputs(acTmp,pkCFile);

            SPRINTF(acTmp,uiMaxSize,"        ++Wm3NumFunctions_%s;\n\n",
                kFunction[0]);
            fputs(acTmp,pkCFile);
        }
        SPRINTF(acTmp,uiMaxSize,"    if ( Wm3NumFunctions_%s == %d )\n",
            kFunction[0],iNumFunctions);
        fputs(acTmp,pkCFile);
        SPRINTF(acTmp,uiMaxSize,
            "        Wm3Exists_%s = WM3_EXT_FULLY_EXISTS;\n",kFunction[0]);
        fputs(acTmp,pkCFile);
        fputs("    else\n",pkCFile);
        SPRINTF(acTmp,uiMaxSize,
            "        Wm3Exists_%s = WM3_EXT_PARTIALLY_EXISTS;\n",
            kFunction[0]);
        fputs(acTmp,pkCFile);

        fputs("}\n",pkCFile);

        fputs("#else\n",pkCFile);

        SPRINTF(acTmp,uiMaxSize,"static void Init_%s ()\n",kFunction[0]);
        fputs(acTmp,pkCFile);
        fputs("{\n",pkCFile);
        SPRINTF(acTmp,uiMaxSize,"    Wm3NumFunctions_%s = 0;\n",kFunction[0]);
        fputs(acTmp,pkCFile);
        SPRINTF(acTmp,uiMaxSize,
            "    Wm3Exists_%s = WM3_EXT_DOES_NOT_EXIST;\n",kFunction[0]);
        fputs(acTmp,pkCFile);
        fputs("}\n",pkCFile);

        fputs("#endif\n",pkCFile);

        for (i = 0; i < (int)kFunction.size(); i++)
        {
            delete kFunction[i];
        }
    }
    fclose(pkIFile);

    // initialization function
    fputs("\n",pkCFile);
    fputs("/*--------------------------------------------------------------"
        "------------*/\n",pkCFile);
    fputs("void InitializeWgl ()\n",pkCFile);
    fputs("{\n",pkCFile);
    for (i = 0; i < (int)kExtension.size(); i++)
    {
        SPRINTF(acTmp,uiMaxSize,"    Init_%s();\n",kExtension[i]);
        fputs(acTmp,pkCFile);
    }
    fputs("}\n",pkCFile);
    fputs("/*--------------------------------------------------------------"
        "------------*/\n",pkCFile);
    fputs("#endif\n",pkCFile);

    pkIFile = FOPEN("WglExtHFinal.txt","rt");
    while (fgets(acLine,(int)uiMaxSize,pkIFile))
    {
        fputs(acLine,pkHFile);
    }
    fclose(pkIFile);

    fclose(pkCFile);
    fclose(pkHFile);

    delete[] acTmp;
    delete[] acLine;
}
//----------------------------------------------------------------------------
static void CreateGlxExtensions ()
{
    const size_t uiMaxSize = 4096;
    char* acLine = new char[uiMaxSize];
    char* acTmp = new char[uiMaxSize];
    char* pcResult;
    char* pcRetType;
    char* pcSignature;
    char* pcFunction;
    char* acFCopy;
    int i;

    FILE* pkHFile = FOPEN("Wm3GlxExtensions.h","wt");
    FILE* pkCFile = FOPEN("Wm3GlxExtensions.c","wt");

    // write the starting text in the H file
    FILE* pkIFile = FOPEN("GlxExtHStart.txt","rt");
    while (fgets(acLine,(int)uiMaxSize,pkIFile))
    {
        fputs(acLine,pkHFile);
    }
    fclose(pkIFile);

    // write the starting text in the C file
    pkIFile = FOPEN("GlxExtCStart.txt","rt");
    while (fgets(acLine,(int)uiMaxSize,pkIFile))
    {
        fputs(acLine,pkCFile);
    }
    fclose(pkIFile);

    std::vector<char*> kExtension;
    pkIFile = FOPEN("GlxExt.txt","rt");
    while ((pcResult = fgets(acLine,(int)uiMaxSize,pkIFile)) != 0)
    {
        // skip blank lines
        while (pcResult && acLine[0] != '{')
        {
            pcResult = fgets(acLine,(int)uiMaxSize,pkIFile);
        }

        // get extension name
        assert(strlen(acLine) >= 6 && strncmp(acLine,"{ GLX_",6) == 0);
        char* acExtension = &acLine[2];
        char* pcEnd = strpbrk(acExtension," \t\n");
        assert(pcEnd);
        *pcEnd = 0;

        // save extension for initialization function
        size_t uiSize = strlen(acExtension) + 1;
        char* acECopy = new char[uiSize];
        STRCPY(acECopy,uiSize,acExtension);
        kExtension.push_back(acECopy);

        std::vector<char*> kFunction;
        uiSize = strlen(acExtension) + 1;
        acECopy = new char[uiSize];
        STRCPY(acECopy,uiSize,acExtension);
        kFunction.push_back(acECopy);
        int iNumFunctions = 0;

        // start extension block in H file
        fputs("\n",pkHFile);
        fputs("/*----------------------------------------------------------"
            "----------------*/\n",pkHFile);
        SPRINTF(acTmp,uiMaxSize,"WM3_EXTERN int Wm3Exists_%s;\n",acExtension);
        fputs(acTmp,pkHFile);
        SPRINTF(acTmp,uiMaxSize,
            "WM3_EXTERN int Wm3NumFunctions_%s;\n",acExtension);
        fputs(acTmp,pkHFile);
        SPRINTF(acTmp,uiMaxSize,"#ifndef %s\n",acExtension);
        fputs(acTmp,pkHFile);
        SPRINTF(acTmp,uiMaxSize,"#define %s\n",acExtension);
        fputs(acTmp,pkHFile);
        SPRINTF(acTmp,uiMaxSize,"#define WM3_DEFINED_%s\n",acExtension);
        fputs(acTmp,pkHFile);

        // start extension block in C file
        fputs("\n",pkCFile);
        fputs("/*----------------------------------------------------------"
            "----------------*/\n",pkCFile);
        SPRINTF(acTmp,uiMaxSize,"int Wm3Exists_%s;\n",acExtension);
        fputs(acTmp,pkCFile);
        SPRINTF(acTmp,uiMaxSize,"int Wm3NumFunctions_%s;\n",acExtension);
        fputs(acTmp,pkCFile);
        SPRINTF(acTmp,uiMaxSize,"#ifdef WM3_DEFINED_%s\n",acExtension);
        fputs(acTmp,pkCFile);

        // get extension information
        bool bFirstDefine = true;
        bool bFirstTypedef = true;
        bool bFirstPrototype = true;
        while (true)
        {
            pcResult = fgets(acLine,(int)uiMaxSize,pkIFile);
            assert(pcResult);

            if (acLine[0] == '}')
            {
                // end of extension block
                break;
            }

            assert(acLine[0] == '@');

            switch (acLine[1])
            {
            case 'v':  // verbatim
                fputs(&acLine[3],pkHFile);
                break;

            case 'f':  // function pointer definition
                iNumFunctions++;

                // return type of function
                assert(acLine[3] != ' ');
                pcRetType = &acLine[3];

                // function name
                pcFunction = pcRetType;
                while (*pcFunction != 'g'
                ||     *(pcFunction+1) != 'l'
                ||     *(pcFunction+2) != 'X')
                {
                    pcFunction++;
                }
                pcFunction--;
                *pcFunction = 0;
                pcFunction++;

                // signature of function
                pcSignature = pcFunction;
                while (*pcSignature != ' ')
                {
                    pcSignature++;
                }
                *pcSignature = 0;
                pcSignature++;

                // H file information
                fputs("\n",pkHFile);
                SPRINTF(acTmp,uiMaxSize,"typedef %s (* pfn_%s) %s",
                    pcRetType,pcFunction,pcSignature);
                fputs(acTmp,pkHFile);
                SPRINTF(acTmp,uiMaxSize,"WM3_EXTERN pfn_%s Wm3%s;\n",
                    pcFunction,pcFunction);
                fputs(acTmp,pkHFile);
                SPRINTF(acTmp,uiMaxSize,"#define %s Wm3%s\n",pcFunction,
                    pcFunction);
                fputs(acTmp,pkHFile);

                // C file information
                uiSize = strlen(pcFunction) + 1;
                acFCopy = new char[uiSize];
                STRCPY(acFCopy,uiSize,pcFunction);
                kFunction.push_back(acFCopy);

                SPRINTF(acTmp,uiMaxSize,"pfn_%s Wm3%s = 0;\n",pcFunction,
                    pcFunction);
                fputs(acTmp,pkCFile);
                break;

            case 'p':  // function prototype
                iNumFunctions++;

                // return type of function
                assert( acLine[3] != ' ');
                pcRetType = &acLine[3];

                // function name
                pcFunction = pcRetType;
                while (*pcFunction != 'g'
                ||     *(pcFunction+1) != 'l'
                ||     *(pcFunction+2) != 'X')
                {
                    pcFunction++;
                }
                pcFunction--;
                *pcFunction = 0;
                pcFunction++;

                // signature of function
                pcSignature = pcFunction;
                while (*pcSignature != ' ')
                {
                    pcSignature++;
                }
                *pcSignature = 0;
                pcSignature++;

                // H file information
                SPRINTF(acTmp,uiMaxSize,"WM3_EXTERN %s %s %s",pcRetType,
                    pcFunction,pcSignature);
                fputs(acTmp,pkHFile);
                break;

            default:
                assert(false);
                break;
            }
        }

        // end of extension block in H file
        fputs("#endif\n",pkHFile);

        // end of extension block in C file
        if (kFunction.size() > 1)
        {
            fputs("\n",pkCFile);
        }

        SPRINTF(acTmp,uiMaxSize,"static void Init_%s ()\n",kFunction[0]);
        fputs(acTmp,pkCFile);
        fputs("{\n",pkCFile);

        if (kFunction.size() == 1)
        {
            // all prototypes
            SPRINTF(acTmp,uiMaxSize,"    Wm3NumFunctions_%s = %d;\n",
                kFunction[0],iNumFunctions);
            fputs(acTmp,pkCFile);

            SPRINTF(acTmp,uiMaxSize,
                "    Wm3Exists_%s = WM3_EXT_FULLY_EXISTS;\n",kFunction[0]);
            fputs(acTmp,pkCFile);
        }
        else
        {
            SPRINTF(acTmp,uiMaxSize,
                "    Wm3NumFunctions_%s = 0;\n\n",kFunction[0]);
            fputs(acTmp,pkCFile);
            for (i = 1; i <= iNumFunctions; i++)
            {
                SPRINTF(acTmp,uiMaxSize,
                    "    Wm3%s = (pfn_%s)GetFunctionPointer(\"%s\");\n",
                    kFunction[i],kFunction[i],kFunction[i]);
                fputs(acTmp,pkCFile);

                SPRINTF(acTmp,uiMaxSize,"    if ( Wm3%s )\n",kFunction[i]);
                fputs(acTmp,pkCFile);

                SPRINTF(acTmp,uiMaxSize,"        ++Wm3NumFunctions_%s;\n\n",
                    kFunction[0]);
                fputs(acTmp,pkCFile);
            }
            SPRINTF(acTmp,uiMaxSize,"    if ( Wm3NumFunctions_%s == %d )\n",
                kFunction[0],iNumFunctions);
            fputs(acTmp,pkCFile);
            SPRINTF(acTmp,uiMaxSize,
                "        Wm3Exists_%s = WM3_EXT_FULLY_EXISTS;\n",
                kFunction[0]);
            fputs(acTmp,pkCFile);
            fputs("    else\n",pkCFile);
            SPRINTF(acTmp,uiMaxSize,
                "        Wm3Exists_%s = WM3_EXT_PARTIALLY_EXISTS;\n",
                kFunction[0]);
            fputs(acTmp,pkCFile);
        }
        fputs("}\n",pkCFile);

        fputs("#else\n",pkCFile);

        SPRINTF(acTmp,uiMaxSize,"static void Init_%s ()\n",kFunction[0]);
        fputs(acTmp,pkCFile);
        fputs("{\n",pkCFile);
        SPRINTF(acTmp,uiMaxSize,"    Wm3NumFunctions_%s = 0;\n",kFunction[0]);
        fputs(acTmp,pkCFile);
        SPRINTF(acTmp,uiMaxSize,
            "    Wm3Exists_%s = WM3_EXT_DOES_NOT_EXIST;\n",kFunction[0]);
        fputs(acTmp,pkCFile);
        fputs("}\n",pkCFile);

        fputs("#endif\n",pkCFile);

        for (i = 0; i < (int)kFunction.size(); i++)
        {
            delete kFunction[i];
        }
    }
    fclose(pkIFile);

    // initialization function
    fputs("\n",pkCFile);
    fputs("/*--------------------------------------------------------------"
        "------------*/\n",pkCFile);
    fputs("void InitializeGlx ()\n",pkCFile);
    fputs("{\n",pkCFile);
    for (i = 0; i < (int)kExtension.size(); i++)
    {
        SPRINTF(acTmp,uiMaxSize,"    Init_%s();\n",kExtension[i]);
        fputs(acTmp,pkCFile);
    }
    fputs("}\n",pkCFile);
    fputs("/*--------------------------------------------------------------"
        "------------*/\n",pkCFile);
    fputs("#endif\n",pkCFile);

    pkIFile = FOPEN("GlxExtHFinal.txt","rt");
    while (fgets(acLine,(int)uiMaxSize,pkIFile))
    {
        fputs(acLine,pkHFile);
    }
    fclose(pkIFile);

    fclose(pkCFile);
    fclose(pkHFile);

    delete[] acTmp;
    delete[] acLine;
}
//----------------------------------------------------------------------------
int main ()
{
    CreateOglExtensions();
    CreateWglExtensions();
    CreateGlxExtensions();
    return 0;
}
//----------------------------------------------------------------------------

