// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#include "Wm3FoundationPCH.h"
#include "Wm3CollapseRecord.h"
using namespace Wm3;

//----------------------------------------------------------------------------
CollapseRecord::CollapseRecord (int iVKeep, int iVThrow, int iVQuantity,
    int iTQuantity)
{
    VKeep = iVKeep;
    VThrow = iVThrow;
    VQuantity = iVQuantity;
    TQuantity = iTQuantity;
    IQuantity = 0;
    Indices = 0;
}
//----------------------------------------------------------------------------
CollapseRecord::~CollapseRecord ()
{
    WM3_DELETE[] Indices;
}
//----------------------------------------------------------------------------
void CollapseRecord::Read (Stream& rkStream)
{
    rkStream.Read(VKeep);
    rkStream.Read(VThrow);
    rkStream.Read(VQuantity);
    rkStream.Read(TQuantity);
    rkStream.Read(IQuantity);
    if (IQuantity > 0)
    {
        Indices = WM3_NEW int[IQuantity];
        rkStream.Read(IQuantity,Indices);
    }
    else
    {
        Indices = 0;
    }
}
//----------------------------------------------------------------------------
void CollapseRecord::Write (Stream& rkStream)
{
    rkStream.Write(VKeep);
    rkStream.Write(VThrow);
    rkStream.Write(VQuantity);
    rkStream.Write(TQuantity);
    rkStream.Write(IQuantity);
    if (IQuantity > 0)
    {
        rkStream.Write(IQuantity,Indices);
    }
}
//----------------------------------------------------------------------------
int CollapseRecord::GetMemoryUsed () const
{
    return sizeof(CollapseRecord) + IQuantity*sizeof(Indices[0]);
}
//----------------------------------------------------------------------------
int CollapseRecord::GetDiskUsed () const
{
    return sizeof(VKeep) + sizeof(VThrow) + sizeof(VQuantity) +
        sizeof(TQuantity) + sizeof(IQuantity) + IQuantity*sizeof(Indices[0]);
}
//----------------------------------------------------------------------------

