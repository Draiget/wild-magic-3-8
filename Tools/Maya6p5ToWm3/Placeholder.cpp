// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#include <maya/MGlobal.h>
#include "Exporter.h"

//----------------------------------------------------------------------------
void Exporter::Placeholder (const MFnDagNode& rkDagNode)
{
    // Add a Node to the Wild Magic scene whose name indicates the type of
    // the dag node.  This is just a placeholder until the function that
    // handles the dag node type is implemented.

    DisplayWarning(("Unsupported node: " +  rkDagNode.name()).asChar());

    Node* pkNode = new Node;
    const char* acDagType = "Placeholder: ";
    const char* acDagName = rkDagNode.name().asChar();
    size_t uiSize = strlen(acDagType) + strlen(acDagName) + 1;
    char* acName = new char[uiSize];
    System::Strcpy(acName,uiSize,acDagType);
    System::Strcat(acName,uiSize,acDagName);
    pkNode->SetName(acName);
    AttachToParent(rkDagNode,pkNode);
}
//----------------------------------------------------------------------------

