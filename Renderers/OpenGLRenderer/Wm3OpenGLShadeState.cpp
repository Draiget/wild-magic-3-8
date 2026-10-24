// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#include "Wm3OpenGLRendererPCH.h"
#include "Wm3OpenGLRenderer.h"
using namespace Wm3;

GLenum OpenGLRenderer::ms_aeShade[ShadeState::SM_QUANTITY] =
{
    GL_FLAT,
    GL_SMOOTH
};

//----------------------------------------------------------------------------
void OpenGLRenderer::SetShadeState (ShadeState* pkState)
{
    glShadeModel(ms_aeShade[pkState->Shade]);
}
//----------------------------------------------------------------------------

