// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#include "Wm3Renderer.h"

namespace Wm3
{

// This function is separated from the other template functions to avoid a
// circular header dependency (destructor uses the Renderer class).  The
// other functions are inlined, but this file is included in the specific
// typedef'd CachedArray classes.
template <class T>
TCachedArray<T>::~TCachedArray ()
{
    // Inform all renderers using this array that it is being destroyed.
    // This allows the renderer to free up any associated resources.
    const TArray<BindInfo>& rkArray = BIArray.GetArray();
    for (int i = 0; i < rkArray.GetQuantity(); i++)
        rkArray[i].User->ReleaseArray(this);
}

}




