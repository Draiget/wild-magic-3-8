// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WMATERIALTREE_H
#define WMATERIALTREE_H

#include "Wm3MaterialState.h"
#include "WTextureTree.h"
#include <vector>

class WMaterialTree
{
public:
    WMaterialTree (Wm3::MaterialState* pkMState = NULL);

    // material subtree
    void SetMChildQuantity (int iQuantity);
    int GetMChildQuantity () const;
    void SetMaterial (Wm3::MaterialStatePtr spkMState);
    Wm3::MaterialStatePtr GetMaterial () const;
    WMaterialTree& GetMChild (int i);

    // texture subtree
    void SetTChildQuantity (int iQuantity);
    int GetTChildQuantity () const;
    Wm3::TexturePtr GetTexture (int i);
    WTextureTree& GetTChild (int i);

private:
    Wm3::MaterialStatePtr m_spkMState;
    std::vector<WMaterialTree> m_kMChild;
    std::vector<WTextureTree> m_kTChild;
};

#endif




