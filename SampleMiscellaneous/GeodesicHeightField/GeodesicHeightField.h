// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef GEODESICHEIGHTFIELD_H
#define GEODESICHEIGHTFIELD_H

#include "Wm3WindowApplication3.h"
#include "Wm3BSplineGeodesic.h"
using namespace Wm3;

class GeodesicHeightField : public WindowApplication3
{
    WM3_DECLARE_INITIALIZE;

public:
    GeodesicHeightField ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnIdle ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);
    virtual bool OnMouseClick (int iButton, int iState, int iX, int iY,
        unsigned int uiModifiers);

protected:
    void CreateScene ();
    void DrawLine (int iX0, int iY0, int iX1, int iY1,
        int iWidth, unsigned char* aucData);
    void ComputeDistanceCurvature ();
    static void RefineCallback ();

    NodePtr m_spkScene;
    WireframeStatePtr m_spkWireframe;
    TriMeshPtr m_spkMesh;
    TexturePtr m_spkTexture;

    BSplineRectangled* m_pkSurface;
    BSplineGeodesicd* m_pkGeodesic;

    int m_iSelected;
    int m_aiXIntr[2], m_aiYIntr[2];
    GVectord m_akPoint[2];
    int m_iPQuantity;
    GVectord* m_akPath;

    double m_dDistance, m_dCurvature;
};

WM3_REGISTER_INITIALIZE(GeodesicHeightField);

#endif

