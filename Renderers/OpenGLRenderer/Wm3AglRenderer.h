// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM3AGLRENDERER_H
#define WM3AGLRENDERER_H

#include "Wm3OpenGLRendererLIB.h"
#include "Wm3OpenGLRenderer.h"
#include <AGL/agl.h>
#include <Carbon/Carbon.h>
#include <DrawSprocket/DrawSprocket.h>

namespace Wm3
{

class WM3_RENDERER_ITEM AglRenderer : public OpenGLRenderer
{
public:
    // construction and destruction
    AglRenderer (AGLDevice hDevice, WindowRef pkWindow,
        const BufferParams& rkBufferParams, int iX, int iY,
        int iWidth, int iHeight);

    virtual ~AglRenderer ();

    virtual void Resize (int iWidth, int iHeight);
    virtual void ToggleFullscreen ();

    virtual bool BeginScene ();
    virtual void DisplayBackBuffer ();

    virtual int LoadFont (const char* acFace, int iSize, bool bBold,
        bool bItalic);

    // window parameters
    AGLDevice GetDevice () { return m_hAglDevice; }
    WindowRef GetWindow () { return m_pkAglWindow; }
    AGLDrawable GetDrawable () { return m_pkAglDrawable; }
    AGLContext GetContext () { return m_pkAglContext; }

private:
    // Offscreen buffer management.  Access to protected Renderer calls.
    friend class AglPBuffer;

    // set up drawing area
    void SetUpBufferRect ();

    // display error message and terminate
    void FatalErrorMessage (const char* acMessage);

    // display parameters
    AGLDevice m_hAglDevice;
    WindowRef m_pkAglWindow;
    AGLDrawable m_pkAglDrawable;
    AGLContext m_pkAglContext;
    AGLDrawable m_pkFullScreenDrawable;
    DSpContextReference m_pkDSpContext;
    Boolean m_bFullScreen;

    // font management
    GWorldPtr m_pkBack;

    // fullscreen/window support
    int m_iX, m_iY;
    int m_iSaveWidth, m_iSaveHeight;

    static Boolean ms_bDSpStarted;
};

}

#endif


