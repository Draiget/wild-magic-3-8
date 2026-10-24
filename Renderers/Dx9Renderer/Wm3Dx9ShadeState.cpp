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

DWORD Dx9Renderer::ms_adwShadeMode[ShadeState::SM_QUANTITY] =
{
    D3DSHADE_FLAT,      // ShadeState::SM_FLAT
    D3DSHADE_GOURAUD,   // ShadeState::SM_SMOOTH
};

//----------------------------------------------------------------------------
void Dx9Renderer::SetShadeState (ShadeState* pkState)
{
    ms_hResult = m_pqDevice->SetRenderState(D3DRS_SHADEMODE,
        ms_adwShadeMode[pkState->Shade]);
    assert(SUCCEEDED(ms_hResult));
}
//----------------------------------------------------------------------------

