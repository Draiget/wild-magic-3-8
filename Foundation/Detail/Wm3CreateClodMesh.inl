// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

//----------------------------------------------------------------------------
template <class T>
void ReorderAttributes (CreateClodMesh& rkCCM, T*& ratVertexAttribute)
{
    int iVQuantity = rkCCM.GetVQuantity();
    const int* aiVOrdered = rkCCM.GetVOrdered();

    T* atNewVertexAttribute = WM3_NEW T[iVQuantity];
    for (int i = 0; i < iVQuantity; i++)
    {
        atNewVertexAttribute[i] = ratVertexAttribute[aiVOrdered[i]];
    }

    size_t uiSize = iVQuantity*sizeof(T);
    System::Memcpy(ratVertexAttribute,uiSize,atNewVertexAttribute,uiSize);
    WM3_DELETE[] atNewVertexAttribute;
}
//----------------------------------------------------------------------------

