// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#include "Wm3Dx9RendererPCH.h"
#include "Wm3Dx9Renderer.h"
using namespace Wm3;

//----------------------------------------------------------------------------
int Dx9Renderer::LoadFont (const char* acFace, int iSize, bool bBold,
    bool bItalic)
{
    // Find the first unused font location
    int iLoc;
    for (iLoc = 0; iLoc < m_kFontArray.GetQuantity(); iLoc++)
    {
        if (!m_kFontArray[iLoc])
        {
            break;
        }
    }

    IFontPtr pqFont;
    DWORD dwWeight = (bBold ? FW_BOLD : FW_REGULAR);

    ms_hResult = D3DXCreateFont(m_pqDevice,iSize,0,dwWeight,0,(DWORD)bItalic,
        DEFAULT_CHARSET,OUT_DEFAULT_PRECIS,ANTIALIASED_QUALITY,VARIABLE_PITCH,
        acFace,&pqFont);

    assert(SUCCEEDED(ms_hResult));

    // Put into the font array
    if (iLoc == m_kFontArray.GetQuantity())
    {
        m_kFontArray.Append(pqFont);
    }
    else
    {
        m_kFontArray[iLoc] = pqFont;
    }

    return iLoc;
}
//----------------------------------------------------------------------------
void Dx9Renderer::UnloadFont (int iFontID)
{
    // You may not unload the default font (id = 0).
    if (1 <= iFontID && iFontID < m_kFontArray.GetQuantity())
    {
        m_kFontArray[iFontID].Release();
    }
}
//----------------------------------------------------------------------------
bool Dx9Renderer::SelectFont (int iFontID)
{
    if (0 <= iFontID && iFontID < m_kFontArray.GetQuantity())
    {
        if (m_kFontArray[iFontID])
        {
            m_iFontID = iFontID;
            return true;
        }
    }
    return false;
}
//----------------------------------------------------------------------------
void Dx9Renderer::Draw (int iX, int iY, const ColorRGBA& rkColor,
    const char* acText)
{
    assert(acText);
    if (!acText)
    {
        return;
    }

    RECT kText;
    kText.bottom = iY;
    kText.top = iY;
    kText.left = iX;
    kText.right = iX;

    D3DCOLOR kColor = D3DCOLOR_COLORVALUE(rkColor.R(),rkColor.G(),rkColor.B(),
        rkColor.A());

    ms_hResult = m_kFontArray[m_iFontID]->DrawText(0,acText,-1,&kText,
        DT_LEFT | DT_BOTTOM | DT_CALCRECT,kColor);
    assert(SUCCEEDED(ms_hResult));

    ms_hResult = m_kFontArray[m_iFontID]->DrawText(0,acText,-1,&kText,
        DT_LEFT | DT_BOTTOM,kColor);
    assert(SUCCEEDED(ms_hResult));
}
//----------------------------------------------------------------------------

