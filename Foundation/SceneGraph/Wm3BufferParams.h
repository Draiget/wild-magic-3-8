// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM3BUFFERPARAMS_H
#define WM3BUFFERPARAMS_H

#include "Wm3FoundationLIB.h"
#include "Wm3System.h"

namespace Wm3
{

class WM3_ITEM BufferParams
{
public:
    enum WM3_ITEM FormatType
    {
        BP_FORMAT_RGBA
    };

    enum WM3_ITEM DepthType
    {
        BP_DEPTH_NONE,
        BP_DEPTH_16,
        BP_DEPTH_24,
        BP_DEPTH_32
    };

    enum WM3_ITEM StencilType
    {
        BP_STENCIL_NONE,
        BP_STENCIL_8
    };

    enum WM3_ITEM BufferedType
    {
        BP_BUFFERED_SINGLE,
        BP_BUFFERED_DOUBLE
    };

    enum WM3_ITEM SamplingType
    {
        BP_SAMPLING_NONE,
        BP_SAMPLING_2,
        BP_SAMPLING_4
    };

    enum WM3_ITEM TextureTargetType
    {
        BP_TEXTURE_TARGET_NONE,
        BP_TEXTURE_TARGET_2D,
        BP_TEXTURE_TARGET_2D_MIPMAP,
        BP_TEXTURE_TARGET_CUBE,
        BP_TEXTURE_TARGET_CUBE_MIPMAP
    };

    FormatType Format;
    DepthType Depth;
    StencilType Stencil;
    BufferedType Buffering;
    SamplingType Sampling;
    TextureTargetType TextureTarget;

    BufferParams ()
    {
        Format = BP_FORMAT_RGBA;
        Depth = BP_DEPTH_16;
        Stencil = BP_STENCIL_8;
        Buffering = BP_BUFFERED_DOUBLE;
        Sampling = BP_SAMPLING_NONE;
        TextureTarget = BP_TEXTURE_TARGET_NONE;
    }
};

}

#endif

