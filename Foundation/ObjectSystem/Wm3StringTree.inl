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
inline int StringTree::GetStringQuantity () const
{
    return m_kStrings.GetQuantity();
}
//----------------------------------------------------------------------------
inline char* StringTree::GetString (int i)
{
    if (0 <= i && i < m_kStrings.GetQuantity())
    {
        return m_kStrings[i];
    }

    return 0;
}
//----------------------------------------------------------------------------
inline int StringTree::GetChildQuantity () const
{
    return m_kChildren.GetQuantity();
}
//----------------------------------------------------------------------------
inline StringTree* StringTree::GetChild (int i)
{
    if (0 <= i && i < m_kChildren.GetQuantity())
    {
        return m_kChildren[i];
    }

    return 0;
}
//----------------------------------------------------------------------------
template <class T>
StringTree* Format (const char* acTitle, int iQuantity, const T* atValue)
{
    StringTree* pkTree = WM3_NEW StringTree(1,1);
    pkTree->SetString(0,Format(acTitle));

    StringTree* pkSubtree = WM3_NEW StringTree(iQuantity+1,0);
    pkSubtree->SetString(0,Format("quantity =",iQuantity));
    for (int i = 0; i < iQuantity; i++)
    {
        const size_t uiSize = 256;
        char acPrefix[uiSize];
        System::Sprintf(acPrefix,uiSize,"%d: ",i);
        T tValue = atValue[i];
        pkSubtree->SetString(i+1,Format(acPrefix,tValue));
    }

    pkTree->SetChild(0,pkSubtree);

    return pkTree;
}
//----------------------------------------------------------------------------

