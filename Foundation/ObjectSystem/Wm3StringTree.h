// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM3STRINGTREE_H
#define WM3STRINGTREE_H

#include "Wm3FoundationLIB.h"
#include "Wm3System.h"
#include "Wm3Line3.h"
#include "Wm3Matrix2.h"
#include "Wm3Matrix3.h"
#include "Wm3Matrix4.h"
#include "Wm3Plane3.h"
#include "Wm3Quaternion.h"

namespace Wm3
{

class BoundingVolume;
class ColorRGBA;
class ColorRGB;
class Rtti;

class WM3_ITEM StringTree
{
public:
    // construction and destruction
    StringTree (int iStringQuantity, int iChildQuantity);
    ~StringTree ();

    // strings
    int GetStringQuantity () const;
    void SetString (int i, char* acString);
    char* GetString (int i);

    // children
    int GetChildQuantity () const;
    void SetChild (int i, StringTree* pkChild);
    StringTree* GetChild (int i);

    // streaming
    bool Save (const char* acFilename, int iTabSize = 4);

    static void FormatFloat (float fValue, size_t uiStringSize,
        char* acString);
    static void FormatDouble (double dValue, size_t uiStringSize,
        char* acString);

private:
    // streaming (recursive)
    void Save (FILE* pkOFile, int iLevel, int iTabSize);

    TArray<char*> m_kStrings;
    TArray<StringTree*> m_kChildren;
};


// string creation helpers (native types)
WM3_ITEM char* Format (const Rtti* pkRTTI, const char* acName);
WM3_ITEM char* Format (const char* acString);

WM3_ITEM char* Format (const char* acPrefix, bool bValue);
WM3_ITEM char* Format (const char* acPrefix, char cValue);
WM3_ITEM char* Format (const char* acPrefix, unsigned char ucValue);
WM3_ITEM char* Format (const char* acPrefix, short sValue);
WM3_ITEM char* Format (const char* acPrefix, unsigned short usValue);
WM3_ITEM char* Format (const char* acPrefix, int iValue);
WM3_ITEM char* Format (const char* acPrefix, unsigned int uiValue);
WM3_ITEM char* Format (const char* acPrefix, long lValue);
WM3_ITEM char* Format (const char* acPrefix, unsigned long ulValue);
WM3_ITEM char* Format (const char* acPrefix, float fValue);
WM3_ITEM char* Format (const char* acPrefix, double dValue);
WM3_ITEM char* Format (const char* acPrefix, void* pvValue);
WM3_ITEM char* Format (const char* acPrefix, const char* acValue);

WM3_ITEM char* Format (const char* acPrefix, const BoundingVolume* pkValue);
WM3_ITEM char* Format (const char* acPrefix, const ColorRGBA& rkValue);
WM3_ITEM char* Format (const char* acPrefix, const ColorRGB& rkValue);
WM3_ITEM char* Format (const char* acPrefix, const Line3f& rkValue);
WM3_ITEM char* Format (const char* acPrefix, const Matrix2f& rkValue);
WM3_ITEM char* Format (const char* acPrefix, const Matrix3f& rkValue);
WM3_ITEM char* Format (const char* acPrefix, const Matrix4f& rkValue);
WM3_ITEM char* Format (const char* acPrefix, const Plane3f& rkValue);
WM3_ITEM char* Format (const char* acPrefix, const Quaternionf& rkValue);
WM3_ITEM char* Format (const char* acPrefix, const Vector2f& rkValue);
WM3_ITEM char* Format (const char* acPrefix, const Vector3f& rkValue);
WM3_ITEM char* Format (const char* acPrefix, const Vector4f& rkValue);
WM3_ITEM char* Format (const char* acPrefix, const Line3d& rkValue);
WM3_ITEM char* Format (const char* acPrefix, const Matrix2d& rkValue);
WM3_ITEM char* Format (const char* acPrefix, const Matrix3d& rkValue);
WM3_ITEM char* Format (const char* acPrefix, const Matrix4d& rkValue);
WM3_ITEM char* Format (const char* acPrefix, const Plane3d& rkValue);
WM3_ITEM char* Format (const char* acPrefix, const Quaterniond& rkValue);
WM3_ITEM char* Format (const char* acPrefix, const Vector2d& rkValue);
WM3_ITEM char* Format (const char* acPrefix, const Vector3d& rkValue);
WM3_ITEM char* Format (const char* acPrefix, const Vector4d& rkValue);

template <class T>
StringTree* Format (const char* acTitle, int iQuantity, const T* atValue);

#include "Wm3StringTree.inl"

}

#endif

