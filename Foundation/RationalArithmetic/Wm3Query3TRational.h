// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM3QUERY3TRATIONAL_H
#define WM3QUERY3TRATIONAL_H

#include "Wm3FoundationLIB.h"
#include "Wm3Query3.h"
#include "Wm3RVector3.h"

namespace Wm3
{

template <class Real>
class Query3TRational : public Query3<Real>
{
public:
    // The components of the input vertices are represented exactly as
    // rational values.
    Query3TRational (int iVQuantity, const Vector3<Real>* akVertex);
    virtual ~Query3TRational ();

    // run-time type information
    virtual Query::Type GetType () const;

    // Queries about the relation of a point to various geometric objects.

    // returns
    //   +1, on positive side of plane
    //   -1, on negative side of line
    //    0, on the plane
    virtual int ToPlane (int i, int iV0, int iV1, int iV2) const;
    virtual int ToPlane (const Vector3<Real>& rkP, int iV0, int iV1, int iV2)
        const;

    // returns
    //   +1, outside tetrahedron
    //   -1, inside tetrahedron
    //    0, on tetrahedron
    virtual int ToTetrahedron (int i, int iV0, int iV1, int iV2, int iV3)
        const;
    virtual int ToTetrahedron (const Vector3<Real>& rkP, int iV0, int iV1,
        int iV2, int iV3) const;

    // returns
    //   +1, outside circumsphere of tetrahedron
    //   -1, inside circumsphere of tetrahedron
    //    0, on circumsphere of tetrahedron
    virtual int ToCircumsphere (int i, int iV0, int iV1, int iV2, int iV3)
        const;
    virtual int ToCircumsphere (const Vector3<Real>& rkP, int iV0, int iV1,
        int iV2, int iV3) const;

private:
    using Query3<Real>::m_iVQuantity;
    using Query3<Real>::m_akVertex;

    // Caching for rational representations of the input.  The conversion of
    // floating-point numbers to TRational form is slow, so it is better to
    // keep track of which values have been converted.
    typedef TRational<8*sizeof(Real)> Rational;
    typedef RVector3<8*sizeof(Real)> RVector;
    mutable RVector* m_akRVertex;
    mutable bool* m_abEvaluated;

    void Convert (int iQuantity, int* aiIndex) const;

    int ToPlane (const RVector& rkRP, int iV0, int iV1, int iV2) const;
    int ToTetrahedron (const RVector& rkRP, int iV0, int iV1, int iV2,
        int iV3) const;
    int ToCircumsphere (const RVector& rkRP, int iV0, int iV1, int iV2,
        int iV3) const;

    static Rational Dot (Rational& rkX0, Rational& rkY0, Rational& rkZ0,
        Rational& rkX1, Rational& rkY1, Rational& rkZ1);

    static Rational Det3 (Rational& rkX0, Rational& rkY0, Rational& rkZ0,
        Rational& rkX1, Rational& rkY1, Rational& rkZ1, Rational& rkX2,
        Rational& rkY2, Rational& rkZ2);

    static Rational Det4 (Rational& rkX0, Rational& rkY0, Rational& rkZ0,
        Rational& rkW0, Rational& rkX1, Rational& rkY1, Rational& rkZ1,
        Rational& rkW1, Rational& rkX2, Rational& rkY2, Rational& rkZ2,
        Rational& rkW2, Rational& rkX3, Rational& rkY3, Rational& rkZ3,
        Rational& rkW3);
};

#include "Wm3Query3TRational.inl"

typedef Query3TRational<float> Query3TRationalf;
typedef Query3TRational<double> Query3TRationald;

}

#endif

