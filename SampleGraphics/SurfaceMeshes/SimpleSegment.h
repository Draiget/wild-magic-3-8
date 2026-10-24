// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef SIMPLESEGMENT_H
#define SIMPLESEGMENT_H

#include "Wm3CurveSegment.h"

namespace Wm3
{

class SimpleSegment : public CurveSegment
{
    WM3_DECLARE_RTTI;
    WM3_DECLARE_NAME_ID;
    WM3_DECLARE_STREAM;

public:
    SimpleSegment ();
    virtual ~SimpleSegment ();

    float Amplitude, Frequency, Height;

    // position and derivatives up to third order
    virtual Vector3f P (float fU) const;
    virtual Vector3f PU (float fU) const;
    virtual Vector3f PUU (float fU) const;
    virtual Vector3f PUUU (float fU) const;
};

WM3_REGISTER_STREAM(SimpleSegment);
typedef Pointer<SimpleSegment> SimpleSegmentPtr;

}

#endif

