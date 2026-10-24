// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#include "InstanceData.h"

//----------------------------------------------------------------------------
InstanceData::InstanceData ()
{
}
//----------------------------------------------------------------------------
InstanceData::~InstanceData ()
{
    Spats.RemoveAll();
}
//----------------------------------------------------------------------------
InstanceData::InstanceData (Spatial* pkFirst)
{
    Spats.Append(pkFirst);
}
//----------------------------------------------------------------------------
InstanceData& InstanceData::operator= (const InstanceData& rkData)
{
    for (int i = 0; i < rkData.Spats.GetQuantity(); i++)
    {
        Spats.Append(rkData.Spats[i]);
    }

    return *this;
}
//----------------------------------------------------------------------------
Spatial* InstanceData::GetFirst ()
{
    return (Spats.GetQuantity() > 0 ? Spats[0] : 0);
}
//----------------------------------------------------------------------------

