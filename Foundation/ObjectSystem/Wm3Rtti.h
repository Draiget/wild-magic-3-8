// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM3RTTI_H
#define WM3RTTI_H

#include "Wm3FoundationLIB.h"
#include "Wm3System.h"
#include "Wm3Rtti.mcr"

namespace Wm3
{

class WM3_ITEM Rtti
{
public:
    // The name must be unique among all objects in the system.  In the Wm3
    // namespace, a class Foo should use "Wm3.Foo".  If an application has
    // another namespace, SomeName, then the name should be "SomeName.Foo".
    Rtti (const char* acName, const Rtti* pkBaseType);
    ~Rtti ();

    const char* GetName () const;
    int GetDiskUsed () const;

    bool IsExactly (const Rtti& rkType) const;
    bool IsDerived (const Rtti& rkType) const;

private:
    const char* m_acName;
    const Rtti* m_pkBaseType;
};

#include "Wm3Rtti.inl"

}

#endif

