// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM3MESHCURVATURE_H
#define WM3MESHCURVATURE_H

#include "Wm3FoundationLIB.h"
#include "Wm3Matrix3.h"
#include "Wm3Matrix2.h"

namespace Wm3
{

template <class Real>
class WM3_ITEM MeshCurvature
{
public:
    // The caller is responsible for deleting the input arrays.
    MeshCurvature (int iVQuantity, const Vector3<Real>* akVertex,
        int iTQuantity, const int* aiIndex);

    virtual ~MeshCurvature ();

    // input values from the constructor
    int GetVQuantity () const;
    const Vector3<Real>* GetVertices () const;
    int GetTQuantity () const;
    const int* GetIndices () const;

    // derived quantites from the input mesh
    const Vector3<Real>* GetNormals () const;
    const Real* GetMinCurvatures () const;
    const Real* GetMaxCurvatures () const;
    const Vector3<Real>* GetMinDirections () const;
    const Vector3<Real>* GetMaxDirections () const;

protected:
    int m_iVQuantity;
    const Vector3<Real>* m_akVertex;
    int m_iTQuantity;
    const int* m_aiIndex;

    Vector3<Real>* m_akNormal;
    Real* m_afMinCurvature;
    Real* m_afMaxCurvature;
    Vector3<Real>* m_akMinDirection;
    Vector3<Real>* m_akMaxDirection;
};

typedef MeshCurvature<float> MeshCurvaturef;
typedef MeshCurvature<double> MeshCurvatured;

}

#endif

