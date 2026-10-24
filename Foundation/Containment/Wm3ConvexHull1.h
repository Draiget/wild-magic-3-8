// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM3CONVEXHULL1_H
#define WM3CONVEXHULL1_H

// A fancy class to compute the minimum and maximum of a collection of
// real-valued numbers, but this provides some convenience for ConvexHull2 and
// ConvexHull3 when the input point set has intrinsic dimension smaller than
// the containing space.  The interface of ConvexHull1 is also the model for
// those of ConvexHull2 and ConvexHull3.

#include "Wm3FoundationLIB.h"
#include "Wm3ConvexHull.h"

namespace Wm3
{

template <class Real>
class WM3_ITEM ConvexHull1 : public ConvexHull<Real>
{
public:
    // The input to the constructor is the array of vertices you want to sort.
    // If you want ConvexHull1 to delete the array during destruction, set
    // bOwner to 'true'.  Otherwise, you own the array and must delete it
    // yourself.  TO DO:  The computation type is currently ignored by this
    // class.  Add support for the various types later.
    ConvexHull1 (int iVertexQuantity, Real* afVertex, Real fEpsilon,
        bool bOwner, Query::Type eQueryType);
    virtual ~ConvexHull1 ();

    // The input vertex array.
    const Real* GetVertices () const;

    // Support for streaming to/from disk.
    ConvexHull1 (const char* acFilename);
    bool Load (const char* acFilename);
    bool Save (const char* acFilename) const;

private:
    using ConvexHull<Real>::m_iVertexQuantity;
    using ConvexHull<Real>::m_iDimension;
    using ConvexHull<Real>::m_iSimplexQuantity;
    using ConvexHull<Real>::m_aiIndex;
    using ConvexHull<Real>::m_fEpsilon;
    using ConvexHull<Real>::m_bOwner;

    Real* m_afVertex;

    class WM3_ITEM SortedVertex
    {
    public:
        Real Value;
        int Index;

        bool operator< (const SortedVertex& rkProj) const
        {
            return Value < rkProj.Value;
        }
    };
};

typedef ConvexHull1<float> ConvexHull1f;
typedef ConvexHull1<double> ConvexHull1d;

}

#endif

