// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#include <windows.h>
#include "Wm3Foundation.h"
using namespace Wm3;
using namespace std;

//----------------------------------------------------------------------------
void Usage ()
{
    cout << endl;
    cout << "To convert Windows BITMAP format to Wild Magic Image" << endl;
    cout << "Format (wmif), use" << endl;
    cout << "    Bmp24ToWmif myfile.bmp [myfile.alpha.bmp]" << endl;
    cout << "The BITMAP myfile.bmp is a 24-bit image that stores RGB" << endl;
    cout << "components.  If you want an alpha channel, supply" << endl;
    cout << "myfile.alpha.bmp, a 24-bit BITMAP image that is gray" << endl;
    cout << "scale (R = G = B).  The common channel value is used as" << endl;
    cout << "the alpha channel of the output image, myfile.wmif." << endl;
}
//----------------------------------------------------------------------------
int GetImage (const char* acBMPName, int& riWidth, int& riHeight,
    unsigned char*& raucData)
{
    riWidth = 0;
    riHeight = 0;
    raucData = 0;

    HBITMAP hImage = (HBITMAP) LoadImage(NULL,acBMPName,IMAGE_BITMAP,0,0,
        LR_LOADFROMFILE | LR_CREATEDIBSECTION);

    if (!hImage)
    {
        return -2;
    }

    DIBSECTION dibSection;
    GetObject(hImage,sizeof(DIBSECTION),&dibSection);

    riWidth = dibSection.dsBm.bmWidth;
    riHeight = dibSection.dsBm.bmHeight;
    if (dibSection.dsBm.bmBitsPixel != 24)
    {
        return -3;
    }

    // Windows pads the rows of the BMP to be 4-byte aligned.
    int iRowSize = 3*riWidth;
    if ((iRowSize % 4) != 0)
    {
        iRowSize += 4 - (riWidth % 4);
    }

    // allocate the WMIF image
    raucData = WM3_NEW unsigned char[3*riWidth*riHeight];
    memset(raucData,0,3*riWidth*riHeight);

    // Windows BMP stores BGR, need to invert to RGB.
    unsigned char* aucOldRow = (unsigned char*)dibSection.dsBm.bmBits;
    unsigned char* aucNewRow = raucData;
    for (int iY = 0; iY < riHeight; iY++)
    {
        System::Memcpy(aucNewRow,3*riWidth,aucOldRow,3*riWidth);
        for (int iX = 0; iX < riWidth; iX++)
        {
            unsigned char ucB = aucNewRow[3*iX  ];
            unsigned char ucR = aucNewRow[3*iX+2];
            aucNewRow[3*iX  ] = ucR;
            aucNewRow[3*iX+2] = ucB;
        }
        aucOldRow += iRowSize;
        aucNewRow += 3*riWidth;
    }

    DeleteObject(hImage);

    return 0;
}
//----------------------------------------------------------------------------
int main (int iArgQuantity, char** aacArgument)
{
    if (iArgQuantity <= 1)
    {
        Usage();
        return -1;
    }

    // get RGB input file
    const char* acRGBFile = aacArgument[1];
    int iRGBWidth, iRGBHeight;
    unsigned char* aucRGBData;
    int iErrorCode = GetImage(acRGBFile,iRGBWidth,iRGBHeight,aucRGBData);
    if (iErrorCode != 0)
    {
        WM3_DELETE[] aucRGBData;
        return iErrorCode;
    }

    // The input file is SomeFile.bmp.  Allocate enough space to change
    // this to SomeFile.wmif.
    const size_t uiDstSize = strlen(acRGBFile) + 2;
    char* acWmifName = new char[uiDstSize];
    System::Strcpy(acWmifName,uiDstSize,acRGBFile);
    char* acWmifFileExt = acWmifName + uiDstSize - 5;
    acWmifFileExt[0] = 'w';
    acWmifFileExt[1] = 'm';
    acWmifFileExt[2] = 'i';
    acWmifFileExt[3] = 'f';
    acWmifFileExt[4] = 0;

    if (iArgQuantity <= 2)
    {
        // create and save the RGB image to disk
        Image* pkRGBImage = WM3_NEW Image(Image::IT_RGB888,iRGBWidth,
            iRGBHeight,aucRGBData,NULL,false);
        if (!pkRGBImage)
        {
            WM3_DELETE[] aucRGBData;
            return -4;
        }
        if (!pkRGBImage->Save(acWmifName))
        {
            WM3_DELETE pkRGBImage;
            return -5;
        }
        WM3_DELETE pkRGBImage;
        return 0;
    }

    // get A input file
    const char* acAFile = aacArgument[2];
    int iAWidth, iAHeight;
    unsigned char* aucAData;
    iErrorCode = GetImage(acAFile,iAWidth,iAHeight,aucAData);
    if (iErrorCode != 0)
    {
        WM3_DELETE[] aucRGBData;
        WM3_DELETE[] aucAData;
        return iErrorCode;
    }
    if (iAWidth != iRGBWidth || iAHeight != iRGBHeight)
    {
        WM3_DELETE[] aucRGBData;
        WM3_DELETE[] aucAData;
        return -6;
    }

    int iWidth = iRGBWidth, iHeight = iRGBHeight;
    int iQuantity = iWidth*iHeight;
    unsigned char* aucData = WM3_NEW unsigned char[4*iQuantity];
    for (int i = 0; i < iQuantity; i++)
    {
        aucData[4*i  ] = aucRGBData[3*i  ];
        aucData[4*i+1] = aucRGBData[3*i+1];
        aucData[4*i+2] = aucRGBData[3*i+2];
        aucData[4*i+3] = aucAData[3*i];  // use the R channel for alpha
    }
    WM3_DELETE[] aucRGBData;
    WM3_DELETE[] aucAData;

    Image* pkRGBAImage = WM3_NEW Image(Image::IT_RGBA8888,iWidth,iHeight,
        aucData,NULL,false);
    if (!pkRGBAImage)
    {
        WM3_DELETE[] aucData;
        return -7;
    }
    if (!pkRGBAImage->Save(acWmifName))
    {
        WM3_DELETE pkRGBAImage;
        return -8;
    }
    WM3_DELETE pkRGBAImage;
    return 0;
}
//----------------------------------------------------------------------------

