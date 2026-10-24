// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM3SMARTPOINTER_H
#define WM3SMARTPOINTER_H

#include "Wm3FoundationLIB.h"
#include "Wm3System.h"

namespace Wm3
{

template <class T>
class Pointer
{
public:
    // construction and destruction
    Pointer (T* pkObject = 0);
    Pointer (const Pointer& rkPointer);
    ~Pointer ();

    // implicit conversions
    operator T* () const;
    T& operator* () const;
    T* operator-> () const;

    // assignment
    Pointer& operator= (T* pkObject);
    Pointer& operator= (const Pointer& rkReference);

    // comparisons
    bool operator== (T* pkObject) const;
    bool operator!= (T* pkObject) const;
    bool operator== (const Pointer& rkReference) const;
    bool operator!= (const Pointer& rkReference) const;

protected:
    // the shared object
    T* m_pkObject;
};

#include "Wm3SmartPointer.inl"

}

#endif

