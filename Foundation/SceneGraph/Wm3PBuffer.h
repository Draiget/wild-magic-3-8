// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM3PBUFFER_H
#define WM3PBUFFER_H

#include "Wm3FoundationLIB.h"
#include "Wm3BufferParams.h"

namespace Wm3
{

class Renderer;
class Texture;

class WM3_ITEM PBuffer
{
public:
    // Abstract base class.  The PBuffer::Create and PBuffer::Destroy
    // functions form a factory.
    static PBuffer* Create (const BufferParams& rkBufferParams, int iWidth,
        int iHeight, Renderer* pkRenderer);
    static void Destroy (PBuffer* pkBuffer);

    PBuffer (const BufferParams& rkBufferParams, int iWidth, int iHeight,
        Renderer* pkRenderer);
    virtual ~PBuffer ();

    virtual void Enable () = 0;
    virtual void Disable () = 0;
    virtual void Bind () = 0;
    virtual void Release () = 0;
    virtual void CopyToTarget (bool bRelease) const;

    const BufferParams& GetBufferParams () const;
    void SetRenderer (Renderer* pkRenderer);
    Renderer* GetRenderer ();
    Texture* GetTarget ();
    int GetWidth () const;
    int GetHeight () const;

protected:
    BufferParams m_kBufferParams;
    Renderer* m_pkRenderer;
    Texture* m_pkTarget;
    int m_iWidth;
    int m_iHeight;

    // The pbuffer factory.  Each derived class implements a Creator and a
    // Destroyer and assigns the function pointers to the static data members
    // declared here.  Since only one derived class exists on a platform,
    // there is no chance of one derived class overwriting another's function
    // pointers.
    typedef PBuffer* (*Creator)(const BufferParams&, int, int, Renderer*);
    typedef void (*Destroyer)(PBuffer*);
    static Creator ms_oCreate;
    static Destroyer ms_oDestroy;
};

}

#endif

