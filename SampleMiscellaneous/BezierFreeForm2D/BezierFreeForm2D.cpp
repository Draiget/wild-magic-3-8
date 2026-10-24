// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#include "BezierFreeForm2D.h"

WM3_WINDOW_APPLICATION(BezierFreeForm2D);

static const int gs_iSize = 256;

//----------------------------------------------------------------------------
BezierFreeForm2D::BezierFreeForm2D ()
    :
    WindowApplication2("BezierFreeForm2D",0,0,gs_iSize,gs_iSize,
        ColorRGB::WHITE)
{
    m_aaiCtrlX = 0;
    m_aaiCtrlY = 0;
    m_pkPatch = 0;

    m_pkImage = 0;
    m_bMouseDown = false;
    m_iXCurr = -1;
    m_iYCurr = -1;
}
//----------------------------------------------------------------------------
bool BezierFreeForm2D::OnInitialize ()
{
    if (!WindowApplication2::OnInitialize())
    {
        return false;
    }

    // source bitmap
    m_pkImage = Image::Load(
        System::GetPath("../../Data/Wmif/","Magician.wmif"));
    assert(m_pkImage && m_pkImage->GetFormat() == Image::IT_RGB888);

    // EXAMPLE.  X degree is 3, Y degree is 3.
    int iXDegree = 3;
    int iYDegree = 3;
    m_pkPatch = WM3_NEW BezierTensorPatch(iXDegree,iYDegree);

    // The default control points produce the identity function.
    Allocate<int>(iXDegree+1,iYDegree+1,m_aaiCtrlX);
    Allocate<int>(iXDegree+1,iYDegree+1,m_aaiCtrlY);
    float fXMult = 1.0f/(float)iXDegree;
    float fYMult = 1.0f/(float)iYDegree;
    float fXScrOrig = 0.25f*(float)gs_iSize;
    float fYScrOrig = 0.25f*(float)gs_iSize;
    float fXScrMult = 0.5f*fXMult*(float)gs_iSize;
    float fYScrMult = 0.5f*fYMult*(float)gs_iSize;
    for (int iY = 0; iY <= iYDegree; iY++)
    {
        float fYValue = fYMult*(float)iY;
        float fYSrcValue = fYScrOrig + fYScrMult*(float)iY;
        for (int iX = 0; iX <= iXDegree; iX++)
        {
            float fXValue = fXMult*(float)iX;
            float fXSrcValue = fXScrOrig + fXScrMult*(float)iX;
            m_aaiCtrlX[iY][iX] = (int)fXSrcValue;
            m_aaiCtrlY[iY][iX] = (int)fYSrcValue;
            m_pkPatch->SetControl(iX,iY,Vector2f(fXValue,fYValue));
        }
    }

    DoFlip(true);
    OnDisplay();
    return true;
}
//----------------------------------------------------------------------------
void BezierFreeForm2D::OnTerminate ()
{
    Deallocate<int>(m_aaiCtrlX);
    Deallocate<int>(m_aaiCtrlY);
    WM3_DELETE m_pkPatch;

    WM3_DELETE m_pkImage;
    WindowApplication2::OnTerminate();
}
//----------------------------------------------------------------------------
void BezierFreeForm2D::OnDisplay ()
{
    ClearScreen();

    int iWImage = m_pkImage->GetWidth();
    int iHImage = m_pkImage->GetHeight();
    unsigned char* aucData = m_pkImage->GetData();

    const int iNumSamples = 2*gs_iSize;
    const float fInvNumSamples = 1.0f/(float)iNumSamples;
    Vector2f kParam;
    for (int iT = 0; iT < iNumSamples; iT++)
    {
        int iYImage = iT*iHImage/iNumSamples;
        kParam.Y() = fInvNumSamples*iT;
        for (int iS = 0; iS < iNumSamples; iS++)
        {
            int iXImage = iS*iWImage/iNumSamples;
            kParam.X() = fInvNumSamples*iS;
            Vector2f kResult = m_pkPatch->Evaluate(kParam);

            int iX = ControlToScreen(kResult.X());
            int iY = ControlToScreen(kResult.Y());

            int iIndex = 3*(iXImage + iWImage*iYImage);
            unsigned char ucR = aucData[iIndex++];
            unsigned char ucG = aucData[iIndex++];
            unsigned char ucB = aucData[iIndex++];

            SetPixel(iX,iY,Color(ucR,ucG,ucB));
        }
    }

    // draw the control points
    const int iThick = 2;
    for (int iY = 0; iY <= m_pkPatch->GetDegree(1); iY++)
    {
        for (int iX = 0; iX <= m_pkPatch->GetDegree(0); iX++)
        {
            for (int iDY = -iThick; iDY <= iThick; iDY++)
            {
                for (int iDX = -iThick; iDX <= iThick; iDX++)
                {
                    SetPixel(m_aaiCtrlX[iY][iX]+iDX,m_aaiCtrlY[iY][iX]+iDY,
                        Color(0,255,0));
                }
            }
        }
    }

    WindowApplication2::OnDisplay();
}
//----------------------------------------------------------------------------
bool BezierFreeForm2D::OnMouseClick (int iButton, int iState, int iX,
    int iY, unsigned int)
{
    if (iButton != MOUSE_LEFT_BUTTON)
    {
        return false;
    }

    // Handle the flip in y that is used for drawing.
    iY = gs_iSize - 1 - iY;

    if (iState == MOUSE_DOWN)
    {
        m_bMouseDown = true;
        SelectVertex(iX,iY);
        return true;
    }

    if (iState == MOUSE_UP)
    {
        m_bMouseDown = false;
        if (m_iXCurr >= 0 && m_iYCurr >= 0
        &&  0 <= iX && iX < GetWidth() && 0 <= iY && iY < GetHeight())
        {
            m_aaiCtrlX[m_iYCurr][m_iXCurr] = iX;
            m_aaiCtrlY[m_iYCurr][m_iXCurr] = iY;
            m_pkPatch->SetControl(m_iXCurr,m_iYCurr,
                Vector2f(ScreenToControl(iX),ScreenToControl(iY)));
            OnDisplay();
        }
        return true;
    }

    return false;
}
//----------------------------------------------------------------------------
bool BezierFreeForm2D::OnMotion (int, int iX, int iY, unsigned int)
{
    if (m_bMouseDown)
    {
        // Handle the flip in y that is used for drawing.
        iY = gs_iSize - 1 - iY;

        if (m_iXCurr >= 0 && m_iYCurr >= 0
        &&  0 <= iX && iX < GetWidth() && 0 <= iY && iY < GetHeight())
        {
            m_aaiCtrlX[m_iYCurr][m_iXCurr] = iX;
            m_aaiCtrlY[m_iYCurr][m_iXCurr] = iY;
            m_pkPatch->SetControl(m_iXCurr,m_iYCurr,
                Vector2f(ScreenToControl(iX),ScreenToControl(iY)));
            OnDisplay();
        }
        return true;
    }
    return false;
}
//----------------------------------------------------------------------------
float BezierFreeForm2D::ScreenToControl (int iScreen) const
{
    return 2*iScreen/(float)gs_iSize - 0.5f;
}
//----------------------------------------------------------------------------
int BezierFreeForm2D::ControlToScreen (float fControl) const
{
    return (int)(gs_iSize*(0.5f*fControl + 0.25f));
}
//----------------------------------------------------------------------------
void BezierFreeForm2D::SelectVertex (int iXMouse, int iYMouse)
{
    // Identify vertex within 5 pixels of mouse click.
    const int iPixels = 5;
    m_iXCurr = -1;
    m_iYCurr = -1;
    for (int iY = 0; iY <= m_pkPatch->GetDegree(1); iY++)
    {
        for (int iX = 0; iX <= m_pkPatch->GetDegree(0); iX++)
        {
            int iDX = iXMouse - m_aaiCtrlX[iY][iX];
            int iDY = iYMouse - m_aaiCtrlY[iY][iX];
            if (abs(iDX) <= iPixels && abs(iDY) <= iPixels)
            {
                m_iXCurr = iX;
                m_iYCurr = iY;
                return;
            }
        }
    }
}
//----------------------------------------------------------------------------

