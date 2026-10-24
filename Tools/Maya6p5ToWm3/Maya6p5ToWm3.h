// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef MAYA6P5TOWM3_H
#define MAYA6P5TOWM3_H

#include <maya/MStatus.h>
#include <maya/MObject.h>
#include <maya/MPxFileTranslator.h>
#include <maya/MArgList.h>
#include <maya/MFileObject.h>
#include <maya/MFStream.h>

class Maya6p5ToWm3 : public MPxFileTranslator
{
public:
    Maya6p5ToWm3 ();
    ~Maya6p5ToWm3 ();

    virtual MStatus writer (const MFileObject& rkFile,
        const MString& rkOptions, FileAccessMode eMode);

    virtual bool haveReadMethod () const;
    virtual bool haveWriteMethod () const;
    virtual MString defaultExtension () const;
    virtual MString filter () const;
    virtual MFileKind identifyFile (const MFileObject& rkFileName,
        const char* acBuffer, short sSize) const;

    static void* creator ();
    MStatus doIt (const MArgList& rkArgs);
};

#endif

