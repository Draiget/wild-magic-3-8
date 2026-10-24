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
#include "Wm3GlossMapEffect.h"
using namespace Wm3;

//----------------------------------------------------------------------------
void OpenGLRenderer::DrawGlossMap ()
{
    assert(m_pkGeometry->GeometryType == Geometry::GT_TRIMESH);
    assert(DynamicCast<GlossMapEffect>(m_pkGeometry->GetEffect()));
    GlossMapEffect* pkGMEffect = (GlossMapEffect*)m_pkGeometry->GetEffect();

    // First pass:  No textures.  Lighting, materials, colors only.  Only
    // the specular color is drawn.
    SetGlobalState(m_pkGeometry->States);
    EnableLighting(EL_SPECULAR);
    EnableVertices();

    if (m_bAllowNormals && m_pkGeometry->Normals)
    {
        EnableNormals();
    }

    if (m_bAllowColors && m_pkLocalEffect)
    {
        if (m_pkLocalEffect->ColorRGBAs)
        {
            EnableColorRGBAs();
        }
        else if (m_pkLocalEffect->ColorRGBs )
        {
            EnableColorRGBs();
        }
    }

    // set up the model-to-world transformation
    SetWorldTransformation();

    // draw the object
    DrawElements();

    // restore the model-to-world transformation
    RestoreWorldTransformation();

    // Second pass:  Light the object with ambient and diffuse colors.  Blend
    // with the texture so that
    //   color_destination = color_source + src_alpha * color_destination
    // The idea is that any texture value with alpha value of one will appear
    // to be specular.
    SetGlobalState(m_pkGeometry->States);
    glEnable(GL_BLEND);
    glBlendFunc(GL_ONE,GL_SRC_ALPHA);
    EnableLighting(EL_AMBIENT | EL_DIFFUSE);

    // enable the gloss map texture
    EnableTexture(0,0,pkGMEffect);

    // set up the model-to-world transformation
    SetWorldTransformation();

    // draw the object
    DrawElements();

    // restore the model-to-world transformation
    RestoreWorldTransformation();

    // disable the gloss map texture
    DisableTexture(0,0,pkGMEffect);

    if (m_bAllowColors && m_pkLocalEffect)
    {
        if (m_pkLocalEffect->ColorRGBAs)
        {
            DisableColorRGBAs();
        }
        else if (m_pkLocalEffect->ColorRGBs)
        {
            DisableColorRGBs();
        }
    }

    if (m_bAllowNormals && m_pkGeometry->Normals)
    {
        DisableNormals();
    }

    DisableVertices();
    DisableLighting();

    // restore the default alpha state
    GlobalState* pkAState = GlobalState::Default[GlobalState::ALPHA];
    SetAlphaState((AlphaState*)pkAState);
}
//----------------------------------------------------------------------------

