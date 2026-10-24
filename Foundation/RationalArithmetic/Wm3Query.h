// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM3QUERY_H
#define WM3QUERY_H

#include "Wm3FoundationLIB.h"

namespace Wm3
{

class Query
{
public:
    // abstract base class
    virtual ~Query ();

    // run-time type information
    enum Type
    {
        QT_INT64,
        QT_INTEGER,
        QT_RATIONAL,
        QT_REAL,
        QT_FILTERED
    };

    virtual Type GetType () const = 0;

protected:
    Query ();
};

#include "Wm3Query.inl"

}

#endif

