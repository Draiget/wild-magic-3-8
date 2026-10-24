// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef GEODESICPATHS_H
#define GEODESICPATHS_H

#include "Wm3WindowApplication2.h"
using namespace Wm3;

class GeodesicPaths : public WindowApplication2
{
    WM3_DECLARE_INITIALIZE;

public:
    GeodesicPaths ();
    virtual ~GeodesicPaths ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnDisplay ();
    virtual void ScreenOverlay ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);

protected:
    void ComputeTruePath ();
    void ComputeApprPath (bool bSubdivide);
    void ComputeApprLength ();
    void ParamToXY (const GVectorf& rkParam, int& riX, int& riY);
    void XYToParam (int iX, int iY, GVectorf& rkParam);
    static void RefineCallback ();

    EllipsoidGeodesicf m_kEG;
    GVectorf m_kParam0, m_kParam1;
    float m_fXMin, m_fXMax, m_fXDelta;
    float m_fYMin, m_fYMax, m_fYDelta;

    int m_iTrueQuantity;
    GVectorf* m_akTruePoint;
    float m_fTrueDistance;

    int m_iApprQuantity;
    int m_iCurrApprQuantity;
    GVectorf* m_akApprPoint;
    float m_fApprDistance;
};

WM3_REGISTER_INITIALIZE(GeodesicPaths);

#endif

