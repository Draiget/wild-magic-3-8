// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM3CLODTERRAINVERTEX_H
#define WM3CLODTERRAINVERTEX_H

#include "Wm3FoundationLIB.h"
#include "Wm3System.h"

namespace Wm3
{

class WM3_ITEM ClodTerrainVertex
{
public:
    ClodTerrainVertex ();

    void SetDependent (int i, ClodTerrainVertex* pkDependent);
    ClodTerrainVertex* GetDependent (int i);
    bool GetEnabled () const;
    void Enable ();
    void Disable ();

protected:
    ClodTerrainVertex* m_akDependent[2];
    bool m_bEnabled;
};

#include "Wm3ClodTerrainVertex.inl"

}

#endif

