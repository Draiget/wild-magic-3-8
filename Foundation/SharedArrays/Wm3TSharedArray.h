// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM3TSHAREDARRAY_H
#define WM3TSHAREDARRAY_H

#include "Wm3FoundationLIB.h"
#include "Wm3Object.h"

namespace Wm3
{

template <class T>
class TSharedArray : public Object
{
    WM3_DECLARE_TEMPLATE_RTTI;
    WM3_DECLARE_NAME_ID;
    WM3_DECLARE_TEMPLATE_STREAM;

public:
    TSharedArray (int iQuantity = 0, T* atArray = 0);
    TSharedArray (const TSharedArray& rkShared);
    virtual ~TSharedArray ();

    TSharedArray& operator= (const TSharedArray& rkShared);

    int GetQuantity () const;
    T* GetData () const;
    operator const T* () const;
    operator T* ();
    const T& operator[] (int i) const;
    T& operator[] (int i);

    // This will not cause a reallocation of the array.  The idea is to
    // allow only some of the data to be considered valid.  The caller is
    // responsible for remembering the total quantity that was passed to the
    // constructor.
    void SetActiveQuantity (int iActiveQuantity);

protected:
    int m_iQuantity;
    T* m_atArray;
};

#include "Wm3TSharedArray.inl"

}

#endif

