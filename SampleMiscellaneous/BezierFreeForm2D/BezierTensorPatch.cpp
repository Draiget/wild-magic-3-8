// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#include "BezierTensorPatch.h"
using namespace Wm3;

//----------------------------------------------------------------------------
BezierTensorPatch::BezierTensorPatch (int iXDegree, int iYDegree)
{
    assert(iXDegree >= 1 && iYDegree >= 1);

    m_aiDegree[0] = iXDegree;
    m_aiDegree[1] = iYDegree;
    m_aiNumCtrl[0] = m_aiDegree[0] + 1;
    m_aiNumCtrl[1] = m_aiDegree[1] + 1;
    Allocate<Vector2f>(m_aiNumCtrl[0],m_aiNumCtrl[1],m_aakCtrl);
    m_akTmpX = WM3_NEW Vector2f[m_aiNumCtrl[0]];
    m_akTmpY = WM3_NEW Vector2f[m_aiNumCtrl[1]];
}
//----------------------------------------------------------------------------
BezierTensorPatch::~BezierTensorPatch ()
{
    Deallocate<Vector2f>(m_aakCtrl);
    WM3_DELETE[] m_akTmpX;
    WM3_DELETE[] m_akTmpY;
}
//----------------------------------------------------------------------------
int BezierTensorPatch::GetDegree (int i) const
{
    assert(0 <= i && i < 2);
    return m_aiDegree[i];
}
//----------------------------------------------------------------------------
int BezierTensorPatch::GetControlQuantity (int i) const
{
    assert(0 <= i && i < 2);
    return m_aiNumCtrl[i];
}
//----------------------------------------------------------------------------
void BezierTensorPatch::SetControl (int iX, int iY, const Vector2f& rkCtrl)
{
    assert(0 <= iX && iX < m_aiNumCtrl[0]);
    assert(0 <= iY && iY < m_aiNumCtrl[1]);
    m_aakCtrl[iY][iX] = rkCtrl;
}
//----------------------------------------------------------------------------
Vector2f BezierTensorPatch::GetControl (int iX, int iY) const
{
    assert(0 <= iX && iX < m_aiNumCtrl[0]);
    assert(0 <= iY && iY < m_aiNumCtrl[1]);
    return m_aakCtrl[iY][iX];
}
//----------------------------------------------------------------------------
Vector2f BezierTensorPatch::Evaluate (const Vector2f& rkParam) const
{
    float fS = rkParam.X();
    float fT = rkParam.Y();
    float fOmS = 1.0f - fS;
    float fOmT = 1.0f - fT;

    const size_t uiSize = m_aiNumCtrl[0]*sizeof(Vector2f);
    int iSup, iSub;
    for (int iRow = 0; iRow <= m_aiDegree[1]; iRow++)
    {
        System::Memcpy(m_akTmpX,uiSize,m_aakCtrl[iRow],uiSize);
        for (iSup = 1; iSup <= m_aiDegree[0]; iSup++)
        {
            for (iSub = 0; iSub + iSup <= m_aiDegree[0]; iSub++)
            {
                m_akTmpX[iSub] = fOmS*m_akTmpX[iSub] + fS*m_akTmpX[iSub+1];
            }
        }
        m_akTmpY[iRow] = m_akTmpX[0];
    }

    for (iSup = 1; iSup <= m_aiDegree[1]; iSup++)
    {
        for (iSub = 0; iSub + iSup <= m_aiDegree[1]; iSub++)
        {
            m_akTmpY[iSub] = fOmT*m_akTmpY[iSub] + fT*m_akTmpY[iSub+1];
        }
    }

    return m_akTmpY[0];
}
//----------------------------------------------------------------------------

