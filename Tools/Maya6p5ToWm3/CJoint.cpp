// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#include <maya/MDagPath.h>
#include "Exporter.h"

//----------------------------------------------------------------------------
void Exporter::CJoint (const MFnDagNode& rkDagNode)
{
    // Joints are derived from Maya Transform objects.  Thus, we will create
    // them as Nodes and special case the few additions that Joints have
    // within CTransform(...).
    CTransform(rkDagNode);

    // ...and then put their full dag path (instead of name()) into the
    // hashmap for deferred skin controller creation.  The full info is
    // needed because the node names might not be unique.

    const char* acName = rkDagNode.dagPath().fullPathName().asChar();

    // Must have at least a world and this node that just got added.
    assert(m_kParentStack.GetQuantity() > 1);

    // Top of the parent stack will be the node that was just created in
    // CTransform(...).
    Spatial* pkSpat = m_kParentStack[m_kParentStack.GetQuantity()-1];
    if (pkSpat->IsDerived(Node::TYPE))
    {
        Node* pkNode = StaticCast<Node>(pkSpat);
        m_kJointHash.Insert(acName,pkNode);
    }
    else
    {
        DisplayError("Joint is not a node.  Not adding to joint hash.");
    }
}
//----------------------------------------------------------------------------

