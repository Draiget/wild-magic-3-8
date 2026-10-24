// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM3TEXTURE_H
#define WM3TEXTURE_H

#include "Wm3FoundationLIB.h"
#include "Wm3BindInfo.h"
#include "Wm3ColorRGBA.h"
#include "Wm3Image.h"
#include "Wm3Vector2Array.h"

namespace Wm3
{

class Renderer;

class WM3_ITEM Texture : public Object
{
    WM3_DECLARE_RTTI;
    WM3_DECLARE_NAME_ID;
    WM3_DECLARE_STREAM;

public:
    Texture (Image* pkImage = 0);
    virtual ~Texture ();

    enum // CorrectionMode
    {
        CM_AFFINE,
        CM_PERSPECTIVE,
        CM_QUANTITY
    };

    enum // ApplyMode
    {
        AM_REPLACE,
        AM_DECAL,
        AM_MODULATE,
        AM_BLEND,
        AM_ADD,
        AM_COMBINE,
        AM_QUANTITY
    };

    enum // ApplyCombineFunction
    {
        ACF_REPLACE,
        ACF_MODULATE,
        ACF_ADD,
        ACF_ADD_SIGNED,
        ACF_SUBTRACT,
        ACF_INTERPOLATE,
        ACF_DOT3_RGB,
        ACF_DOT3_RGBA,
        ACF_QUANTITY
    };

    enum // ApplyCombineSrc
    {
        ACS_TEXTURE,
        ACS_PRIMARY_COLOR,
        ACS_CONSTANT,
        ACS_PREVIOUS,
        ACS_QUANTITY
    };

    enum // ApplyCombineOperand
    {
        ACO_SRC_COLOR,
        ACO_ONE_MINUS_SRC_COLOR,
        ACO_SRC_ALPHA,
        ACO_ONE_MINUS_SRC_ALPHA,
        ACO_QUANTITY
    };

    enum // ApplyCombineScale
    {
        ACSC_ONE,
        ACSC_TWO,
        ACSC_FOUR,
        ACSC_QUANTITY
    };

    enum // WrapMode
    {
        WM_CLAMP,
        WM_REPEAT,
        WM_CLAMP_BORDER,
        WM_CLAMP_EDGE,
        WM_QUANTITY
    };

    enum // FilterMode
    {
        FM_NEAREST,
        FM_LINEAR,
        FM_QUANTITY
    };

    enum // MipmapMode
    {
        MM_NEAREST,
        MM_LINEAR,
        MM_NEAREST_NEAREST,
        MM_NEAREST_LINEAR,
        MM_LINEAR_NEAREST,
        MM_LINEAR_LINEAR,
        MM_QUANTITY
    };

    enum // TexGenMode
    {
        TG_NONE,
        TG_ENVIRONMENT_MAP,
        TG_PROJECTED_TEXTURE,
        TG_QUANTITY
    };

    // texture image
    void SetImage (ImagePtr spkImage);
    ImagePtr GetImage () const;

    // If you change any of the texture state information, call this function
    // to make sure that the texture is unbound from the renderer to release
    // resources, and to allow the modified texture to be rebound to the
    // renderer.  The SetImage(...) function calls this automatically, but
    // you are responsible for calling Changed() when other state information
    // changes.
    void Changed ();

    // texture state information
    int Correction;         // default: CM_PERSPECTIVE
    int Apply;              // default: AM_REPLACE
    int CoordU;             // default: WM_CLAMP_EDGE
    int CoordV;             // default: WM_CLAMP_EDGE
    int Filter;             // default: FM_LINEAR
    int Mipmap;             // default: MM_LINEAR_LINEAR
    int Texgen;             // default: TG_NONE
    ColorRGBA BlendColor;   // default: ColorRGBA(0,0,0,0)
    ColorRGBA BorderColor;  // default: ColorRGBA::INVALID

    // the following are only relevant if the apply mode is AM_COMBINE
    int CombineFuncRGB;     // default: ACF_REPLACE
    int CombineFuncAlpha;   // default: ACF_REPLACE
    int CombineSrc0RGB;     // default: ACS_TEXTURE
    int CombineSrc1RGB;     // default: ACS_TEXTURE
    int CombineSrc2RGB;     // default: ACS_TEXTURE
    int CombineSrc0Alpha;   // default: ACS_TEXTURE
    int CombineSrc1Alpha;   // default: ACS_TEXTURE
    int CombineSrc2Alpha;   // default: ACS_TEXTURE
    int CombineOp0RGB;      // default: ACO_SRC_COLOR
    int CombineOp1RGB;      // default: ACO_SRC_COLOR
    int CombineOp2RGB;      // default: ACO_SRC_COLOR
    int CombineOp0Alpha;    // default: ACO_SRC_COLOR
    int CombineOp1Alpha;    // default: ACO_SRC_COLOR
    int CombineOp2Alpha;    // default: ACO_SRC_COLOR
    int CombineScaleRGB;    // default: ACSC_ONE
    int CombineScaleAlpha;  // default: ACSC_ONE

protected:
    // texture image
    ImagePtr m_spkImage;

// internal use
public:
    // store renderer-specific information for binding/unbinding textures
    BindInfoArray BIArray;

    // This is used as an index into an array of offscreen buffers that are
    // specific to the renderer's platform.  The default value is -1,
    // indicating that the texture is not associated with an offscreen buffer.
    int m_iOffscreenIndex;
};

WM3_REGISTER_STREAM(Texture);
typedef Pointer<Texture> TexturePtr;
#include "Wm3Texture.inl"

}

#endif

