// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM3TCACHEDARRAY_H
#define WM3TCACHEDARRAY_H

#include "Wm3FoundationLIB.h"
#include "Wm3TSharedArray.h"
#include "Wm3BindInfo.h"
#include "Wm3Renderer.h"

namespace Wm3
{

template <class T>
class TCachedArray : public TSharedArray<T>
{
    WM3_DECLARE_TEMPLATE_RTTI;
    WM3_DECLARE_NAME_ID;
    WM3_DECLARE_TEMPLATE_STREAM;

public:
    TCachedArray (int iQuantity = 0, T* atArray = 0);
    virtual ~TCachedArray ();

private:
    using TSharedArray<T>::FACTORY_MAP_SIZE;
    using TSharedArray<T>::ms_pkFactory;

    // prevent these from being called
    TCachedArray (const TCachedArray& rkCArray);
    TCachedArray& operator= (const TCachedArray& rkCArray);

// internal use
public:
    // store renderer-specific information for binding/unbinding arrays
    BindInfoArray BIArray;
};

#include "Wm3TCachedArray.inl"

}

#endif

