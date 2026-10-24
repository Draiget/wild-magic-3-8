// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef IMAGELOADER_H
#define IMAGELOADER_H

class ImageLoader
{
public:
    // A simple image loader for TGA and 24-bit BMP.  Its usage is
    //
    // const char* acFileName = "myfile.ext";  // "ext" in {"tga","bmp"}
    // int iWidth, iHeight, iBitsPerPixel;
    // unsigned char* aucData;
    // bool bLoaded = ImageLoader(acFileName,iWidth,iHeight,iBitsPerPixel,
    //     aucData);

    ImageLoader (const char* acFileName, int& riWidth, int& riHeight,
        int& riBitsPerPixel, unsigned char*& raucData);

    ~ImageLoader ();

    operator bool() const;

private:
    bool LoadTGA (int& riWidth, int& riHeight, int& riBitsPerPixel,
        unsigned char*& raucData);

    bool LoadBMP (int& riWidth, int& riHeight, int& riBitsPerPixel,
        unsigned char*& raucData);

    char* m_acBuffer;
    int m_iLength;
    bool m_bLoaded;
};

#endif



