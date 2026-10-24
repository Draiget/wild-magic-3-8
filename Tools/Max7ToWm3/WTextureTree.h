// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WTEXTURETREE_H
#define WTEXTURETREE_H

#include "Wm3Texture.h"
#include <vector>

class WTextureTree
{
public:
    WTextureTree ();

    void SetTexture (Wm3::TexturePtr spkTexture);
    Wm3::TexturePtr GetTexture ();
    void SetChildQuantity (int iQuantity);
    int GetChildQuantity () const;
    WTextureTree& GetChild (int i);

private:
    Wm3::TexturePtr m_spkTexture;
    std::vector<WTextureTree> m_kChild;
};

#endif




