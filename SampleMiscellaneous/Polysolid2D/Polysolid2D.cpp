// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#include "Polysolid2D.h"

WM3_WINDOW_APPLICATION(Polysolid2D);

const int g_iSize = 256;

//----------------------------------------------------------------------------
Polysolid2D::Polysolid2D ()
    :
    WindowApplication2("Polysolid2D",0,0,g_iSize,g_iSize,ColorRGB::WHITE)
{
    m_pkActive = 0;
}
//----------------------------------------------------------------------------
Polysolid2D::~Polysolid2D ()
{
}
//----------------------------------------------------------------------------
bool Polysolid2D::OnInitialize ()
{
    if (!WindowApplication2::OnInitialize())
    {
        return false;
    }

#if 0
    ConstructPolygon(m_kPoly0);
    ConstructPentagon(m_kPoly1);
#endif
#if 0
    ConstructSquare(m_kPoly0);
    ConstructSShape(m_kPoly1);
#endif
#if 1
    ConstructPolyWithHoles(m_kPoly0);
    ConstructPentagon(m_kPoly1);
#endif
#if 0
    ConstructAnotherSquare(m_kPoly0);
    ConstructAnotherOne(m_kPoly1);
#endif
    m_kIntersection = m_kPoly0 & m_kPoly1;
    m_kUnion = m_kPoly0 | m_kPoly1;
    m_kDifferenceAmB = m_kPoly0 - m_kPoly1;
    m_kDifferenceBmA = m_kPoly1 - m_kPoly0;
    m_kExclusiveOr = m_kPoly0 ^ m_kPoly1;

    DoFlip(true);
    OnDisplay();
    return true;
}
//----------------------------------------------------------------------------
void Polysolid2D::OnTerminate ()
{
    WindowApplication2::OnTerminate();
}
//----------------------------------------------------------------------------
void Polysolid2D::OnDisplay ()
{
    ClearScreen();

    DrawPolysolid(m_kPoly0,Color(255,0,0));
    DrawPolysolid(m_kPoly1,Color(0,255,0));
    if (m_pkActive)
    {
        DrawPolysolid(*m_pkActive,Color(0,0,255));
    }
            
    WindowApplication2::OnDisplay();
}
//----------------------------------------------------------------------------
bool Polysolid2D::OnKeyDown (unsigned char ucKey, int iX, int iY)
{
    if (WindowApplication2::OnKeyDown(ucKey,iX,iY))
    {
        return true;
    }

    switch (ucKey)
    {
    case 'p':
    case 'P':
        m_pkActive = 0;
        OnDisplay();
        return true;
    case 'u':
    case 'U':
        m_pkActive = &m_kUnion;
        OnDisplay();
        return true;
    case 'i':
    case 'I':
        m_pkActive = &m_kIntersection;
        OnDisplay();
        return true;
    case 'd':
    case 'D':
        m_pkActive = &m_kDifferenceAmB;
        OnDisplay();
        return true;
    case 'e':
    case 'E':
        m_pkActive = &m_kDifferenceBmA;
        OnDisplay();
        return true;
    case 'x':
    case 'X':
        m_pkActive = &m_kExclusiveOr;
        OnDisplay();
        return true;
    }

    return false;
}
//----------------------------------------------------------------------------
bool Polysolid2D::OnMouseClick (int iButton, int iState, int iX, int iY,
    unsigned int uiModifiers)
{
    if (iState != MOUSE_DOWN || iButton != MOUSE_LEFT_BUTTON)
    {
        return false;
    }

    OnDisplay();
    return true;
}
//----------------------------------------------------------------------------
void Polysolid2D::ConstructPolygon (Polysolid2& rkPoly)
{
    RPoint2 kStart, kR0, kR1;

    kR0.X() = kStart.X() = g_iSize/8;
    kR0.Y() = kStart.Y() = g_iSize/8;
    kR1.X() = kR0.X();
    kR1.Y() = 7*g_iSize/8;
    rkPoly.InsertEdge(kR0,kR1);

    kR0 = kR1;
    kR1.X() = 7*g_iSize/8;
    kR1.Y() = kR0.Y();
    rkPoly.InsertEdge(kR0,kR1);

    kR0 = kR1;
    kR1.X() = kR0.X();
    kR1.Y() = 5*g_iSize/8;
    rkPoly.InsertEdge(kR0,kR1);

    kR0 = kR1;
    kR1.X() = 5*g_iSize/8;
    kR1.Y() = kR0.Y();
    rkPoly.InsertEdge(kR0,kR1);

    kR0 = kR1;
    kR1.X() = kR0.X();
    kR1.Y() = 6*g_iSize/8;
    rkPoly.InsertEdge(kR0,kR1);

    kR0 = kR1;
    kR1.X() = 2*g_iSize/8;
    kR1.Y() = kR0.Y();
    rkPoly.InsertEdge(kR0,kR1);

    kR0 = kR1;
    kR1.X() = kR0.X();
    kR1.Y() = 3*g_iSize/8;
    rkPoly.InsertEdge(kR0,kR1);

    kR0 = kR1;
    kR1.X() = 3*g_iSize/8;
    kR1.Y() = kR0.Y();
    rkPoly.InsertEdge(kR0,kR1);

    kR0 = kR1;
    kR1.X() = kR0.X();
    kR1.Y() = g_iSize/8;
    rkPoly.InsertEdge(kR0,kR1);

    kR0 = kR1;
    kR1 = kStart;
    rkPoly.InsertEdge(kR0,kR1);
}
//---------------------------------------------------------------------------
void Polysolid2D::ConstructPentagon (Polysolid2& rkPoly)
{
    double dAngle = -2.0*Mathd::PI/5.0;
    double dRadius = 0.35*g_iSize;
    double dXCenter = g_iSize/2.0, dYCenter = g_iSize/2.0;

    RPoint2 kStart, kR0, kR1;
    kR0.X() = kStart.X() = (int)(dXCenter+dRadius);
    kR0.Y() = kStart.Y() = (int)(dYCenter);
    kR1.X() = (int)(dXCenter + dRadius*Mathd::Cos(dAngle));
    kR1.Y() = (int)(dYCenter + dRadius*Mathd::Sin(dAngle));
    rkPoly.InsertEdge(kR0,kR1);

    kR0 = kR1;
    kR1.X() = (int)(dXCenter + dRadius*Mathd::Cos(2.0*dAngle));
    kR1.Y() = (int)(dYCenter + dRadius*Mathd::Sin(2.0*dAngle));
    rkPoly.InsertEdge(kR0,kR1);

    kR0 = kR1;
    kR1.X() = (int)(dXCenter + dRadius*Mathd::Cos(3.0*dAngle));
    kR1.Y() = (int)(dYCenter + dRadius*Mathd::Sin(3.0*dAngle));
    rkPoly.InsertEdge(kR0,kR1);

    kR0 = kR1;
    kR1.X() = (int)(dXCenter + dRadius*Mathd::Cos(4.0*dAngle));
    kR1.Y() = (int)(dYCenter + dRadius*Mathd::Sin(4.0*dAngle));
    rkPoly.InsertEdge(kR0,kR1);

    kR0 = kR1;
    kR1 = kStart;
    rkPoly.InsertEdge(kR0,kR1);
}
//---------------------------------------------------------------------------
void Polysolid2D::ConstructSquare (Polysolid2& rkPoly)
{
    RPoint2 kR0, kR1;

    kR0.X() = 2*g_iSize/8;
    kR0.Y() = 2*g_iSize/8;
    kR1.X() = kR0.X();
    kR1.Y() = 6*g_iSize/8;
    rkPoly.InsertEdge(kR0,kR1);

    kR0 = kR1;
    kR1.X() = 6*g_iSize/8;
    kR1.Y() = kR0.Y();
    rkPoly.InsertEdge(kR0,kR1);

    kR0 = kR1;
    kR1.X() = kR0.X();
    kR1.Y() = 2*g_iSize/8;
    rkPoly.InsertEdge(kR0,kR1);

    kR0 = kR1;
    kR1.X() = 2*g_iSize/8;
    kR1.Y() = 2*g_iSize/8;
    rkPoly.InsertEdge(kR0,kR1);
}
//---------------------------------------------------------------------------
void Polysolid2D::ConstructSShape (Polysolid2& rkPoly)
{
    RPoint2 kR0, kR1;

    kR0.X() = 6*g_iSize/8;
    kR0.Y() = (int)(2.5*g_iSize/8);
    kR1.X() = kR0.X();
    kR1.Y() = 3*g_iSize/8;
    rkPoly.InsertEdge(kR0,kR1);

    kR0 = kR1;
    kR1.X() = (int)(6.5*g_iSize/8);
    kR1.Y() = kR0.Y();
    rkPoly.InsertEdge(kR0,kR1);

    kR0 = kR1;
    kR1.X() = kR0.X();
    kR1.Y() = (int)(3.25*g_iSize/8);
    rkPoly.InsertEdge(kR0,kR1);

    kR0 = kR1;
    kR1.X() = 5*g_iSize/8;
    kR1.Y() = kR0.Y();
    rkPoly.InsertEdge(kR0,kR1);

    kR0 = kR1;
    kR1.X() = kR0.X();
    kR1.Y() = (int)(5.5*g_iSize/8);
    rkPoly.InsertEdge(kR0,kR1);

    kR0 = kR1;
    kR1.X() = 6*g_iSize/8;
    kR1.Y() = kR0.Y();
    rkPoly.InsertEdge(kR0,kR1);

    kR0 = kR1;
    kR1.X() = kR0.X();
    kR1.Y() = (int)(4.75*g_iSize/8);
    rkPoly.InsertEdge(kR0,kR1);

    kR0 = kR1;
    kR1.X() = (int)(5.5*g_iSize/8);
    kR1.Y() = kR0.Y();
    rkPoly.InsertEdge(kR0,kR1);

    kR0 = kR1;
    kR1.X() = kR0.X();
    kR1.Y() = 4*g_iSize/8;
    rkPoly.InsertEdge(kR0,kR1);

    kR0 = kR1;
    kR1.X() = 7*g_iSize/8;
    kR1.Y() = kR0.Y();
    rkPoly.InsertEdge(kR0,kR1);

    kR0 = kR1;
    kR1.X() = kR0.X();
    kR1.Y() = (int)(2.5*g_iSize/8);
    rkPoly.InsertEdge(kR0,kR1);

    kR0 = kR1;
    kR1.X() = 6*g_iSize/8;
    kR1.Y() = kR0.Y();
    rkPoly.InsertEdge(kR0,kR1);
}
//---------------------------------------------------------------------------
void Polysolid2D::ConstructPolyWithHoles (Polysolid2& rkPoly)
{
    RPoint2 kR0, kR1;

    // outer boundary
    kR0.X() = g_iSize/8;
    kR0.Y() = g_iSize/8;
    kR1.X() = kR0.X();
    kR1.Y() = 7*g_iSize/8;
    rkPoly.InsertEdge(kR0,kR1);

    kR0 = kR1;
    kR1.X() = 7*g_iSize/8;
    kR1.Y() = g_iSize/8;
    rkPoly.InsertEdge(kR0,kR1);

    kR0 = kR1;
    kR1.X() = g_iSize/8;
    kR1.Y() = g_iSize/8;
    rkPoly.InsertEdge(kR0,kR1);

    // inner hole
    kR0.X() = 2*g_iSize/8;
    kR0.Y() = 3*g_iSize/16;
    kR1.X() = 3*g_iSize/8;
    kR1.Y() = kR0.Y();
    rkPoly.InsertEdge(kR0,kR1);

    kR0 = kR1;
    kR1.X() = kR0.X();
    kR1.Y() = 3*g_iSize/8;
    rkPoly.InsertEdge(kR0,kR1);

    kR0 = kR1;
    kR1.X() = 2*g_iSize/8;
    kR1.Y() = 3*g_iSize/16;
    rkPoly.InsertEdge(kR0,kR1);
}
//---------------------------------------------------------------------------
void Polysolid2D::ConstructAnotherSquare (Polysolid2& rkPoly)
{
    RPoint2 kR0, kR1;

    // clockwise: (16,16),(16,128),(128,128),(128,16),(16,16)

    kR0.X() = 16;
    kR0.Y() = 16;
    kR1.X() = 16;
    kR1.Y() = 128;
    rkPoly.InsertEdge(kR0,kR1);

    kR0 = kR1;
    kR1.X() = 128;
    kR1.Y() = 128;
    rkPoly.InsertEdge(kR0,kR1);

    kR0 = kR1;
    kR1.X() = 128;
    kR1.Y() = 16;
    rkPoly.InsertEdge(kR0,kR1);

    kR0 = kR1;
    kR1.X() = 16;
    kR1.Y() = 16;
    rkPoly.InsertEdge(kR0,kR1);
}
//---------------------------------------------------------------------------
void Polysolid2D::ConstructAnotherOne (Polysolid2& rkPoly)
{
    RPoint2 kR0, kR1;

    // clockwise: (128,64),(16,64),(16,128),(256,128),(128,64)

    kR0.X() = 128;
    kR0.Y() = 64;
    kR1.X() = 16;
    kR1.Y() = 64;
    rkPoly.InsertEdge(kR0,kR1);

    kR0 = kR1;
    kR1.X() = 16;
    kR1.Y() = 128;
    rkPoly.InsertEdge(kR0,kR1);

    kR0 = kR1;
    kR1.X() = 256;
    kR1.Y() = 128;
    rkPoly.InsertEdge(kR0,kR1);

    kR0 = kR1;
    kR1.X() = 128;
    kR1.Y() = 64;
    rkPoly.InsertEdge(kR0,kR1);
}
//---------------------------------------------------------------------------
void Polysolid2D::DrawPolysolid (Polysolid2& rkPoly, Color kColor)
{
    const Polysolid2::ESet& rkESet = rkPoly.GetEdges();
    Polysolid2::ESet::const_iterator pkIter;
    for (pkIter = rkESet.begin(); pkIter != rkESet.end(); pkIter++)
    {
        const RPoint2& rkPosition0 = pkIter->GetVertex(0)->Position;
        const RPoint2& rkPosition1 = pkIter->GetVertex(1)->Position;

        int x0 = (int)rkPosition0.X().ToFloat();
        int y0 = g_iSize-1-(int)rkPosition0.Y().ToFloat();
        int x1 = (int)rkPosition1.X().ToFloat();
        int y1 = g_iSize-1-(int)rkPosition1.Y().ToFloat();

        DrawLine(x0,y0,x1,y1,kColor);
    }
}
//---------------------------------------------------------------------------

