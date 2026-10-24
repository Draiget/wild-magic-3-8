// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM3GLXRENDERER_H
#define WM3GLXRENDERER_H

#include "Wm3OpenGLRendererLIB.h"
#include "Wm3OpenGLRenderer.h"
#include "Wm3GlxExtensions.h"

namespace Wm3
{

class BitmapFont;

class WM3_RENDERER_ITEM GlxRenderer : public OpenGLRenderer
{
public:
    // construction and destruction
    GlxRenderer (Display* pkDisplay, const BufferParams& rkBufferParams,
        int iWidth, int iHeight);

    virtual void ToggleFullscreen ();
    virtual void DisplayBackBuffer ();
    virtual void Draw (int iX, int iY, const ColorRGBA& rkColor,
        const char* acText);

    // TO DO. Implement these
    virtual int LoadFont (const char* acFace, int iSize, bool bBold,
        bool bItalic) { return -1; }
    virtual void UnloadFont (int iFontID) { /**/ }

    Display* GetDisplay () { return m_pkDisplay; }
    XVisualInfo* GetVisual () { return m_pkVisual; }
    Window GetWindow () { return m_ulWindow; }
    GLXContext GetContext () { return m_kContext; }

private:
    // Offscreen buffer management.  Access to protected Renderer calls.
    friend class GlxPBuffer;

    // text drawing
    void DrawCharacter (const BitmapFont& rkFont, char cChar);

    // window parameters
    Display* m_pkDisplay;
    XVisualInfo* m_pkVisual;
    Window m_ulWindow;
    GLXContext m_kContext;

    // fullscreen/window support
    int m_iSaveWidth, m_iSaveHeight;

    bool m_bIsConstructed;

// internal use
public:
    // For the application layer and pbuffers.
    void FinishConstruction (Window ulWindow);
    bool IsConstructed () const { return m_bIsConstructed; }
};

}

#endif


