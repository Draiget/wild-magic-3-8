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

GLenum OpenGLRenderer::ms_aeFrontFace[CullState::FT_QUANTITY] =
{
    GL_CCW,
    GL_CW
};

GLenum OpenGLRenderer::ms_aeCullFace[CullState::CT_QUANTITY] =
{
    GL_FRONT,
    GL_BACK
};

//----------------------------------------------------------------------------
void OpenGLRenderer::SetCullState (CullState* pkState)
{
    if (pkState->Enabled)
    {
        glEnable(GL_CULL_FACE);
    }
    else
    {
        glDisable(GL_CULL_FACE);
    }

    glFrontFace(ms_aeFrontFace[pkState->FrontFace]);

    if (!m_bReverseCullFace)
    {
        glCullFace(ms_aeCullFace[pkState->CullFace]);
    }
    else
    {
        if (ms_aeCullFace[pkState->CullFace] == GL_BACK)
        {
            glCullFace(GL_FRONT);
        }
        else
        {
            glCullFace(GL_BACK);
        }
    }
}
//----------------------------------------------------------------------------

