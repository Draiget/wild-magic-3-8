// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#include "ImageLoader.h"
#include "Wm3System.h"
using namespace Wm3;

//----------------------------------------------------------------------------
ImageLoader::ImageLoader (const char* acFileName, int& riWidth, int& riHeight,
    int& riBitsPerPixel, unsigned char*& raucData)
{
    // file buffer
    m_acBuffer = 0;
    m_iLength = 0;
    m_bLoaded = false;

    // start with a null image
    riWidth = 0;
    riHeight = 0;
    riBitsPerPixel = 0;
    raucData = 0;

    // looking for extension of ".tga" or ".bmp"
    const char* acExt = strrchr(acFileName,'.');
    if ( !acExt || strlen(acExt) != 4 )
        return;

    if ( 't' == tolower(acExt[1])
    &&   'g' == tolower(acExt[2])
    &&   'a' == tolower(acExt[3]) )
    {
        if ( !System::Load(acFileName,m_acBuffer,m_iLength) )
        {
            m_bLoaded = false;
            return;
        }

        m_bLoaded = LoadTGA(riWidth,riHeight,riBitsPerPixel,raucData);
        return;
    }

    if ( 'b' == tolower(acExt[1])
    &&   'm' == tolower(acExt[2])
    &&   'p' == tolower(acExt[3]) )
    {
        if ( !System::Load(acFileName,m_acBuffer,m_iLength) )
        {
            m_bLoaded = false;
            return;
        }

        m_bLoaded = LoadBMP(riWidth,riHeight,riBitsPerPixel,raucData);
        return;
    }
}
//----------------------------------------------------------------------------
ImageLoader::~ImageLoader ()
{
    delete[] m_acBuffer;
}
//----------------------------------------------------------------------------
ImageLoader::operator bool() const
{
    return m_bLoaded;
}
//----------------------------------------------------------------------------
bool ImageLoader::LoadTGA (int& riWidth, int& riHeight, int& riBitsPerPixel,
    unsigned char*& raucImageData)
{
    // The file header is 12 bytes and the TGA description block is 6 bytes.
    // The file had better be at least 18 bytes in size.
    const int iHeaderSize = 12, iDescSize = 6;
    if ( m_iLength < iHeaderSize + iDescSize )
        return false;

    // We require uncompressed TGA.
    unsigned char aucTGAHeader[iHeaderSize]= {0,0,2,0,0,0,0,0,0,0,0,0};
    if ( memcmp(m_acBuffer,aucTGAHeader,iHeaderSize) != 0 )
        return false;

    // Extract image description.  Verify that the file is big enough to
    // contain the image.
    unsigned char* aucTGADesc = (unsigned char*)(m_acBuffer+iHeaderSize);
    riWidth = 256*aucTGADesc[1] + aucTGADesc[0];
    riHeight = 256*aucTGADesc[3] + aucTGADesc[2];
    riBitsPerPixel = aucTGADesc[4];
    int iBytesPerPixel = riBitsPerPixel >> 3;
    int iImageSize = riWidth*riHeight*iBytesPerPixel;
    if ( m_iLength < iHeaderSize + iDescSize + iImageSize )
        return false;

    // Get image data.
    unsigned char* aucTGAImage =
        (unsigned char*)(m_acBuffer+iHeaderSize+iDescSize);
    raucImageData = new unsigned char[iImageSize];
    memcpy(raucImageData,aucTGAImage,sizeof(unsigned char)*iImageSize);

    // Swap red and blue components.
    unsigned char* pucBuffer = raucImageData;
    for (int i = 0; i < iImageSize; i += iBytesPerPixel)
    {
        unsigned char ucSave = pucBuffer[i];
        pucBuffer[i] = pucBuffer[i+2];
        pucBuffer[i+2] = ucSave;
    }

    return true;
}
//----------------------------------------------------------------------------
bool ImageLoader::LoadBMP (int& riWidth, int& riHeight, int& riBitsPerPixel,
    unsigned char*& raucData)
{
    char* pcCurrent = m_acBuffer;

    // *****
    // BITMAPFILEHEADER struct
    //   WORD  type  (must be "BM")
    //   DWORD size  (file size in bytes)
    //   WORD  reserved1
    //   WORD  reserved2
    //   DWORD offset

    // BMP files start with "BM"
    int iMarker1 = (int)*pcCurrent++;
    int iMarker2 = (int)*pcCurrent++;
    if ( iMarker1 != 66 || iMarker2 != 77 )
        return false;

    // get file size
    unsigned int uiFileSize;
    System::Read4le(pcCurrent,1,&uiFileSize);
    pcCurrent += 4;

    // skip two reserved WORDs, each 16-bit quantities
    pcCurrent += 4;

    // get offset of image data from bitmap header
    unsigned int uiOffset;
    System::Read4le(pcCurrent,1,&uiOffset);
    pcCurrent += 4;
    // *****

    // *****
    // BITMAPINFOHEADER struct
    //   DWORD size = sizeof(BITMAPHEADERINFO) = 40
    //   LONG  width
    //   LONG  height
    //   WORD  planes  (must be 1)
    //   WORD  bitCount
    //   DWORD compression
    //   DWORD sizeImage
    //   LONG  xPelsPerMeter
    //   LONG  yPelsPerMeter
    //   DWORD colorsUsed
    //   DWORD colorsImportant

    // get BITMAPINFOHEADER size
    unsigned int uiHeaderSize;
    System::Read4le(pcCurrent,1,&uiHeaderSize);
    pcCurrent += sizeof(unsigned int);
    if ( uiHeaderSize != 40 )
        return false;

    // get width and height of image
    System::Read4le(pcCurrent,1,&riWidth);
    pcCurrent += sizeof(int);
    System::Read4le(pcCurrent,1,&riHeight);
    pcCurrent += sizeof(int);

    // get number of color planes
    unsigned short usPlanes;
    System::Read2le(pcCurrent,1,&usPlanes);
    pcCurrent += sizeof(unsigned short);
    if ( usPlanes != 1 )
        return false;

    // get number of bits per pixel
    unsigned short usBPP;
    System::Read2le(pcCurrent,1,&usBPP);
    pcCurrent += sizeof(unsigned short);
    if ( usBPP != 24 )
    {
        // only 24-bit BMP supported at the moment
        return false;
    }

    riBitsPerPixel = (int)usBPP;

    // get BMP compression type
    unsigned int uiCompression;  // 0 = BI_RGB, 1 = BI_RLE8, 2 = BI_RLE4
    System::Read4le(pcCurrent,1,&uiCompression);
    pcCurrent += sizeof(unsigned int);
    if ( uiCompression > 0 )
    {
        // only uncompressed data supported at the moment
        return false;
    }

    // get image size
    unsigned int uiImageSize;
    System::Read4le(pcCurrent,1,&uiImageSize);
    pcCurrent += sizeof(unsigned int);

    // skip x pels per meter, y pels per meter, colors used, colors important
    pcCurrent += 16;

    // allocate the image data
    raucData = new unsigned char[3*riWidth*riHeight];

    // skip to end of offset block
    pcCurrent = m_acBuffer + uiOffset;

    // get the image data
    int iThreeWidth = 3*riWidth;
    int iSkip = iThreeWidth % 4;
    for (int iY = 0; iY < riHeight; iY++)
    {
        int iIndex = iThreeWidth*iY;
        for (int iX = 0; iX < riWidth; iX++)
        {
            int iBase = iIndex + 3*iX + 2;
            raucData[iBase--] = (unsigned char)*pcCurrent++;
            raucData[iBase--] = (unsigned char)*pcCurrent++;
            raucData[iBase  ] = (unsigned char)*pcCurrent++;
        }                                             
        pcCurrent += iSkip;
    }

    return true;
}
//----------------------------------------------------------------------------



