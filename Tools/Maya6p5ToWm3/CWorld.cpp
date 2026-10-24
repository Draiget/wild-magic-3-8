// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#include "Exporter.h"

//----------------------------------------------------------------------------
void Exporter::CWorld (const MFnDagNode& rkDagNode)
{
    // root node of scene (only one of them)
    if (m_spkWMScene)
    {
        DisplayError("Scene already created before this world node!"\
            "  Ignoring this world node.");
        return;
    }

    int iChildQuantity = (int)rkDagNode.childCount();
    if (iChildQuantity <= 0)
    {
        DisplayError("Root node has no children.");
    }

    // set up some state
    bool m_bParentVisible = true;
    bool m_bTexturesEnabled = true;
    bool m_bMaterialsEnabled = true;

    Node* pkNode =  new Node(iChildQuantity);
    pkNode->SetName(rkDagNode.name().asChar());
    m_spkWMScene = pkNode;
    AttachToParent(rkDagNode,pkNode);
}
//----------------------------------------------------------------------------

