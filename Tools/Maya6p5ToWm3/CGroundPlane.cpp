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
void Exporter::CGroundPlane (const MFnDagNode& rkDagNode)
{
    // TO DO. This object type does not show up in the Maya SDK.  The *.ma
    // files appear to ignore the node.  However, in a data set I tested, the
    // Transform parent was not the identity matrix.  So, not certain what to
    // do with this.  Just create a dummy node for now.

    // ignore for now
    DisplayInfo("Ignoring Ground Plane.");
    return;

    assert(rkDagNode.childCount() == 0);

    Node* pkNode = new Node;
    const char* acDagType = "GroundPlane: ";
    const char* acDagName = rkDagNode.name().asChar();
    size_t uiSize = strlen(acDagType) + strlen(acDagName) + 1;
    char* acName = new char[uiSize];
    System::Strcpy(acName,uiSize,acDagType);
    System::Strcat(acName,uiSize,acDagName);
    pkNode->SetName(acName);

    AttachToParent(rkDagNode,pkNode);
}
//----------------------------------------------------------------------------

