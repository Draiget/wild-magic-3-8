/*
Geometric Tools, Inc.
http://www.geometrictools.com
Copyright (c) 1998-2005.  All Rights Reserved

The Wild Magic Library (WM3) source code is supplied under the terms of
the license agreement
    http://www.geometrictools.com/License/WildMagic3License.pdf
and may not be copied or disclosed except in accordance with the terms
of that agreement.

This file evolved by modifications from a version of wglext.h that was
downloaded from the site listed in the license below.  The version of the
file is: WGL_WGLEXT_VERSION 6
*/

/*
** License Applicability. Except to the extent portions of this file are
** made subject to an alternative license as permitted in the SGI Free
** Software License B, Version 1.1 (the "License"), the contents of this
** file are subject only to the provisions of the License. You may not use
** this file except in compliance with the License. You may obtain a copy
** of the License at Silicon Graphics, Inc., attn: Legal Services, 1600
** Amphitheatre Parkway, Mountain View, CA 94043-1351, or at:
** 
** http://oss.sgi.com/projects/FreeB
** 
** Note that, as provided in the License, the Software is distributed on an
** "AS IS" basis, with ALL EXPRESS AND IMPLIED WARRANTIES AND CONDITIONS
** DISCLAIMED, INCLUDING, WITHOUT LIMITATION, ANY IMPLIED WARRANTIES AND
** CONDITIONS OF MERCHANTABILITY, SATISFACTORY QUALITY, FITNESS FOR A
** PARTICULAR PURPOSE, AND NON-INFRINGEMENT.
** 
** Original Code. The Original Code is: OpenGL Sample Implementation,
** Version 1.2.1, released January 26, 2000, developed by Silicon Graphics,
** Inc. The Original Code is Copyright (c) 1991-2004 Silicon Graphics, Inc.
** Copyright in any portions created by third parties is as indicated
** elsewhere herein. All Rights Reserved.
** 
** Additional Notice Provisions: This software was created using the
** OpenGL(R) version 1.2.1 Sample Implementation published by SGI, but has
** not been independently verified as being compliant with the OpenGL(R)
** version 1.2.1 Specification.
*/

#ifndef WM3WGLEXTENSIONS_H
#define WM3WGLEXTENSIONS_H

#include "Wm3OpenGLRendererLIB.h"
#include "Wm3OpenGLExtensions.h"

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN 1
#endif
#include <windows.h>

#ifdef __cplusplus
extern "C" {
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_WGL_ARB_buffer_region;
WM3_EXTERN int Wm3NumFunctions_WGL_ARB_buffer_region;
#ifndef WGL_ARB_buffer_region
#define WGL_ARB_buffer_region
#define WM3_DEFINED_WGL_ARB_buffer_region
#define WGL_FRONT_COLOR_BUFFER_BIT_ARB 0x00000001
#define WGL_BACK_COLOR_BUFFER_BIT_ARB  0x00000002
#define WGL_DEPTH_BUFFER_BIT_ARB       0x00000004
#define WGL_STENCIL_BUFFER_BIT_ARB     0x00000008

typedef HANDLE (WINAPI* pfn_wglCreateBufferRegionARB) (HDC, int, UINT);
WM3_EXTERN pfn_wglCreateBufferRegionARB Wm3wglCreateBufferRegionARB;
#define wglCreateBufferRegionARB Wm3wglCreateBufferRegionARB

typedef VOID (WINAPI* pfn_wglDeleteBufferRegionARB) (HANDLE);
WM3_EXTERN pfn_wglDeleteBufferRegionARB Wm3wglDeleteBufferRegionARB;
#define wglDeleteBufferRegionARB Wm3wglDeleteBufferRegionARB

typedef BOOL (WINAPI* pfn_wglSaveBufferRegionARB) (HANDLE, int, int, int, int);
WM3_EXTERN pfn_wglSaveBufferRegionARB Wm3wglSaveBufferRegionARB;
#define wglSaveBufferRegionARB Wm3wglSaveBufferRegionARB

typedef BOOL (WINAPI* pfn_wglRestoreBufferRegionARB) (HANDLE, int, int, int, int, int, int);
WM3_EXTERN pfn_wglRestoreBufferRegionARB Wm3wglRestoreBufferRegionARB;
#define wglRestoreBufferRegionARB Wm3wglRestoreBufferRegionARB
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_WGL_ARB_multisample;
WM3_EXTERN int Wm3NumFunctions_WGL_ARB_multisample;
#ifndef WGL_ARB_multisample
#define WGL_ARB_multisample
#define WM3_DEFINED_WGL_ARB_multisample
#define WGL_SAMPLE_BUFFERS_ARB         0x2041
#define WGL_SAMPLES_ARB                0x2042
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_WGL_ARB_extensions_string;
WM3_EXTERN int Wm3NumFunctions_WGL_ARB_extensions_string;
#ifndef WGL_ARB_extensions_string
#define WGL_ARB_extensions_string
#define WM3_DEFINED_WGL_ARB_extensions_string

typedef const char* (WINAPI* pfn_wglGetExtensionsStringARB) (HDC);
WM3_EXTERN pfn_wglGetExtensionsStringARB Wm3wglGetExtensionsStringARB;
#define wglGetExtensionsStringARB Wm3wglGetExtensionsStringARB
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_WGL_ARB_pixel_format;
WM3_EXTERN int Wm3NumFunctions_WGL_ARB_pixel_format;
#ifndef WGL_ARB_pixel_format
#define WGL_ARB_pixel_format
#define WM3_DEFINED_WGL_ARB_pixel_format
#define WGL_NUMBER_PIXEL_FORMATS_ARB    0x2000
#define WGL_DRAW_TO_WINDOW_ARB          0x2001
#define WGL_DRAW_TO_BITMAP_ARB          0x2002
#define WGL_ACCELERATION_ARB            0x2003
#define WGL_NEED_PALETTE_ARB            0x2004
#define WGL_NEED_SYSTEM_PALETTE_ARB     0x2005
#define WGL_SWAP_LAYER_BUFFERS_ARB      0x2006
#define WGL_SWAP_METHOD_ARB             0x2007
#define WGL_NUMBER_OVERLAYS_ARB         0x2008
#define WGL_NUMBER_UNDERLAYS_ARB        0x2009
#define WGL_TRANSPARENT_ARB             0x200A
#define WGL_TRANSPARENT_RED_VALUE_ARB   0x2037
#define WGL_TRANSPARENT_GREEN_VALUE_ARB 0x2038
#define WGL_TRANSPARENT_BLUE_VALUE_ARB  0x2039
#define WGL_TRANSPARENT_ALPHA_VALUE_ARB 0x203A
#define WGL_TRANSPARENT_INDEX_VALUE_ARB 0x203B
#define WGL_SHARE_DEPTH_ARB             0x200C
#define WGL_SHARE_STENCIL_ARB           0x200D
#define WGL_SHARE_ACCUM_ARB             0x200E
#define WGL_SUPPORT_GDI_ARB             0x200F
#define WGL_SUPPORT_OPENGL_ARB          0x2010
#define WGL_DOUBLE_BUFFER_ARB           0x2011
#define WGL_STEREO_ARB                  0x2012
#define WGL_PIXEL_TYPE_ARB              0x2013
#define WGL_COLOR_BITS_ARB              0x2014
#define WGL_RED_BITS_ARB                0x2015
#define WGL_RED_SHIFT_ARB               0x2016
#define WGL_GREEN_BITS_ARB              0x2017
#define WGL_GREEN_SHIFT_ARB             0x2018
#define WGL_BLUE_BITS_ARB               0x2019
#define WGL_BLUE_SHIFT_ARB              0x201A
#define WGL_ALPHA_BITS_ARB              0x201B
#define WGL_ALPHA_SHIFT_ARB             0x201C
#define WGL_ACCUM_BITS_ARB              0x201D
#define WGL_ACCUM_RED_BITS_ARB          0x201E
#define WGL_ACCUM_GREEN_BITS_ARB        0x201F
#define WGL_ACCUM_BLUE_BITS_ARB         0x2020
#define WGL_ACCUM_ALPHA_BITS_ARB        0x2021
#define WGL_DEPTH_BITS_ARB              0x2022
#define WGL_STENCIL_BITS_ARB            0x2023
#define WGL_AUX_BUFFERS_ARB             0x2024
#define WGL_NO_ACCELERATION_ARB         0x2025
#define WGL_GENERIC_ACCELERATION_ARB    0x2026
#define WGL_FULL_ACCELERATION_ARB       0x2027
#define WGL_SWAP_EXCHANGE_ARB           0x2028
#define WGL_SWAP_COPY_ARB               0x2029
#define WGL_SWAP_UNDEFINED_ARB          0x202A
#define WGL_TYPE_RGBA_ARB               0x202B
#define WGL_TYPE_COLORINDEX_ARB         0x202C

typedef BOOL (WINAPI* pfn_wglGetPixelFormatAttribivARB) (HDC, int, int, UINT, const int*, int*);
WM3_EXTERN pfn_wglGetPixelFormatAttribivARB Wm3wglGetPixelFormatAttribivARB;
#define wglGetPixelFormatAttribivARB Wm3wglGetPixelFormatAttribivARB

typedef BOOL (WINAPI* pfn_wglGetPixelFormatAttribfvARB) (HDC, int, int, UINT, const int*, FLOAT*);
WM3_EXTERN pfn_wglGetPixelFormatAttribfvARB Wm3wglGetPixelFormatAttribfvARB;
#define wglGetPixelFormatAttribfvARB Wm3wglGetPixelFormatAttribfvARB

typedef BOOL (WINAPI* pfn_wglChoosePixelFormatARB) (HDC, const int*, const FLOAT*, UINT, int*, UINT*);
WM3_EXTERN pfn_wglChoosePixelFormatARB Wm3wglChoosePixelFormatARB;
#define wglChoosePixelFormatARB Wm3wglChoosePixelFormatARB
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_WGL_ARB_make_current_read;
WM3_EXTERN int Wm3NumFunctions_WGL_ARB_make_current_read;
#ifndef WGL_ARB_make_current_read
#define WGL_ARB_make_current_read
#define WM3_DEFINED_WGL_ARB_make_current_read
#define ERROR_INVALID_PIXEL_TYPE_ARB            0x2043
#define ERROR_INCOMPATIBLE_DEVICE_CONTEXTS_ARB  0x2054

typedef BOOL (WINAPI* pfn_wglMakeContextCurrentARB) (HDC, HDC, HGLRC);
WM3_EXTERN pfn_wglMakeContextCurrentARB Wm3wglMakeContextCurrentARB;
#define wglMakeContextCurrentARB Wm3wglMakeContextCurrentARB

typedef HDC (WINAPI* pfn_wglGetCurrentReadDCARB) (void);
WM3_EXTERN pfn_wglGetCurrentReadDCARB Wm3wglGetCurrentReadDCARB;
#define wglGetCurrentReadDCARB Wm3wglGetCurrentReadDCARB
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_WGL_ARB_pbuffer;
WM3_EXTERN int Wm3NumFunctions_WGL_ARB_pbuffer;
#ifndef WGL_ARB_pbuffer
#define WGL_ARB_pbuffer
#define WM3_DEFINED_WGL_ARB_pbuffer
#define WGL_DRAW_TO_PBUFFER_ARB        0x202D
#define WGL_MAX_PBUFFER_PIXELS_ARB     0x202E
#define WGL_MAX_PBUFFER_WIDTH_ARB      0x202F
#define WGL_MAX_PBUFFER_HEIGHT_ARB     0x2030
#define WGL_PBUFFER_LARGEST_ARB        0x2033
#define WGL_PBUFFER_WIDTH_ARB          0x2034
#define WGL_PBUFFER_HEIGHT_ARB         0x2035
#define WGL_PBUFFER_LOST_ARB           0x2036
DECLARE_HANDLE(HPBUFFERARB);

typedef HPBUFFERARB (WINAPI* pfn_wglCreatePbufferARB) (HDC, int, int, int, const int*);
WM3_EXTERN pfn_wglCreatePbufferARB Wm3wglCreatePbufferARB;
#define wglCreatePbufferARB Wm3wglCreatePbufferARB

typedef HDC (WINAPI* pfn_wglGetPbufferDCARB) (HPBUFFERARB);
WM3_EXTERN pfn_wglGetPbufferDCARB Wm3wglGetPbufferDCARB;
#define wglGetPbufferDCARB Wm3wglGetPbufferDCARB

typedef int (WINAPI* pfn_wglReleasePbufferDCARB) (HPBUFFERARB, HDC);
WM3_EXTERN pfn_wglReleasePbufferDCARB Wm3wglReleasePbufferDCARB;
#define wglReleasePbufferDCARB Wm3wglReleasePbufferDCARB

typedef BOOL (WINAPI* pfn_wglDestroyPbufferARB) (HPBUFFERARB);
WM3_EXTERN pfn_wglDestroyPbufferARB Wm3wglDestroyPbufferARB;
#define wglDestroyPbufferARB Wm3wglDestroyPbufferARB

typedef BOOL (WINAPI* pfn_wglQueryPbufferARB) (HPBUFFERARB, int, int*);
WM3_EXTERN pfn_wglQueryPbufferARB Wm3wglQueryPbufferARB;
#define wglQueryPbufferARB Wm3wglQueryPbufferARB
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_WGL_ARB_render_texture;
WM3_EXTERN int Wm3NumFunctions_WGL_ARB_render_texture;
#ifndef WGL_ARB_render_texture
#define WGL_ARB_render_texture
#define WM3_DEFINED_WGL_ARB_render_texture
#define WGL_BIND_TO_TEXTURE_RGB_ARB         0x2070
#define WGL_BIND_TO_TEXTURE_RGBA_ARB        0x2071
#define WGL_TEXTURE_FORMAT_ARB              0x2072
#define WGL_TEXTURE_TARGET_ARB              0x2073
#define WGL_MIPMAP_TEXTURE_ARB              0x2074
#define WGL_TEXTURE_RGB_ARB                 0x2075
#define WGL_TEXTURE_RGBA_ARB                0x2076
#define WGL_NO_TEXTURE_ARB                  0x2077
#define WGL_TEXTURE_CUBE_MAP_ARB            0x2078
#define WGL_TEXTURE_1D_ARB                  0x2079
#define WGL_TEXTURE_2D_ARB                  0x207A
#define WGL_MIPMAP_LEVEL_ARB                0x207B
#define WGL_CUBE_MAP_FACE_ARB               0x207C
#define WGL_TEXTURE_CUBE_MAP_POSITIVE_X_ARB 0x207D
#define WGL_TEXTURE_CUBE_MAP_NEGATIVE_X_ARB 0x207E
#define WGL_TEXTURE_CUBE_MAP_POSITIVE_Y_ARB 0x207F
#define WGL_TEXTURE_CUBE_MAP_NEGATIVE_Y_ARB 0x2080
#define WGL_TEXTURE_CUBE_MAP_POSITIVE_Z_ARB 0x2081
#define WGL_TEXTURE_CUBE_MAP_NEGATIVE_Z_ARB 0x2082
#define WGL_FRONT_LEFT_ARB                  0x2083
#define WGL_FRONT_RIGHT_ARB                 0x2084
#define WGL_BACK_LEFT_ARB                   0x2085
#define WGL_BACK_RIGHT_ARB                  0x2086
#define WGL_AUX0_ARB                        0x2087
#define WGL_AUX1_ARB                        0x2088
#define WGL_AUX2_ARB                        0x2089
#define WGL_AUX3_ARB                        0x208A
#define WGL_AUX4_ARB                        0x208B
#define WGL_AUX5_ARB                        0x208C
#define WGL_AUX6_ARB                        0x208D
#define WGL_AUX7_ARB                        0x208E
#define WGL_AUX8_ARB                        0x208F
#define WGL_AUX9_ARB                        0x2090

typedef BOOL (WINAPI* pfn_wglBindTexImageARB) (HPBUFFERARB, int);
WM3_EXTERN pfn_wglBindTexImageARB Wm3wglBindTexImageARB;
#define wglBindTexImageARB Wm3wglBindTexImageARB

typedef BOOL (WINAPI* pfn_wglReleaseTexImageARB) (HPBUFFERARB, int);
WM3_EXTERN pfn_wglReleaseTexImageARB Wm3wglReleaseTexImageARB;
#define wglReleaseTexImageARB Wm3wglReleaseTexImageARB

typedef BOOL (WINAPI* pfn_wglSetPbufferAttribARB) (HPBUFFERARB, const int*);
WM3_EXTERN pfn_wglSetPbufferAttribARB Wm3wglSetPbufferAttribARB;
#define wglSetPbufferAttribARB Wm3wglSetPbufferAttribARB
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_WGL_ARB_pixel_format_float;
WM3_EXTERN int Wm3NumFunctions_WGL_ARB_pixel_format_float;
#ifndef WGL_ARB_pixel_format_float
#define WGL_ARB_pixel_format_float
#define WM3_DEFINED_WGL_ARB_pixel_format_float
#define WGL_TYPE_RGBA_FLOAT_ARB        0x21A0
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_WGL_EXT_make_current_read;
WM3_EXTERN int Wm3NumFunctions_WGL_EXT_make_current_read;
#ifndef WGL_EXT_make_current_read
#define WGL_EXT_make_current_read
#define WM3_DEFINED_WGL_EXT_make_current_read
#define ERROR_INVALID_PIXEL_TYPE_EXT   0x2043

typedef BOOL (WINAPI* pfn_wglMakeContextCurrentEXT) (HDC, HDC, HGLRC);
WM3_EXTERN pfn_wglMakeContextCurrentEXT Wm3wglMakeContextCurrentEXT;
#define wglMakeContextCurrentEXT Wm3wglMakeContextCurrentEXT

typedef HDC (WINAPI* pfn_wglGetCurrentReadDCEXT) (void);
WM3_EXTERN pfn_wglGetCurrentReadDCEXT Wm3wglGetCurrentReadDCEXT;
#define wglGetCurrentReadDCEXT Wm3wglGetCurrentReadDCEXT
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_WGL_EXT_pixel_format;
WM3_EXTERN int Wm3NumFunctions_WGL_EXT_pixel_format;
#ifndef WGL_EXT_pixel_format
#define WGL_EXT_pixel_format
#define WM3_DEFINED_WGL_EXT_pixel_format
#define WGL_NUMBER_PIXEL_FORMATS_EXT   0x2000
#define WGL_DRAW_TO_WINDOW_EXT         0x2001
#define WGL_DRAW_TO_BITMAP_EXT         0x2002
#define WGL_ACCELERATION_EXT           0x2003
#define WGL_NEED_PALETTE_EXT           0x2004
#define WGL_NEED_SYSTEM_PALETTE_EXT    0x2005
#define WGL_SWAP_LAYER_BUFFERS_EXT     0x2006
#define WGL_SWAP_METHOD_EXT            0x2007
#define WGL_NUMBER_OVERLAYS_EXT        0x2008
#define WGL_NUMBER_UNDERLAYS_EXT       0x2009
#define WGL_TRANSPARENT_EXT            0x200A
#define WGL_TRANSPARENT_VALUE_EXT      0x200B
#define WGL_SHARE_DEPTH_EXT            0x200C
#define WGL_SHARE_STENCIL_EXT          0x200D
#define WGL_SHARE_ACCUM_EXT            0x200E
#define WGL_SUPPORT_GDI_EXT            0x200F
#define WGL_SUPPORT_OPENGL_EXT         0x2010
#define WGL_DOUBLE_BUFFER_EXT          0x2011
#define WGL_STEREO_EXT                 0x2012
#define WGL_PIXEL_TYPE_EXT             0x2013
#define WGL_COLOR_BITS_EXT             0x2014
#define WGL_RED_BITS_EXT               0x2015
#define WGL_RED_SHIFT_EXT              0x2016
#define WGL_GREEN_BITS_EXT             0x2017
#define WGL_GREEN_SHIFT_EXT            0x2018
#define WGL_BLUE_BITS_EXT              0x2019
#define WGL_BLUE_SHIFT_EXT             0x201A
#define WGL_ALPHA_BITS_EXT             0x201B
#define WGL_ALPHA_SHIFT_EXT            0x201C
#define WGL_ACCUM_BITS_EXT             0x201D
#define WGL_ACCUM_RED_BITS_EXT         0x201E
#define WGL_ACCUM_GREEN_BITS_EXT       0x201F
#define WGL_ACCUM_BLUE_BITS_EXT        0x2020
#define WGL_ACCUM_ALPHA_BITS_EXT       0x2021
#define WGL_DEPTH_BITS_EXT             0x2022
#define WGL_STENCIL_BITS_EXT           0x2023
#define WGL_AUX_BUFFERS_EXT            0x2024
#define WGL_NO_ACCELERATION_EXT        0x2025
#define WGL_GENERIC_ACCELERATION_EXT   0x2026
#define WGL_FULL_ACCELERATION_EXT      0x2027
#define WGL_SWAP_EXCHANGE_EXT          0x2028
#define WGL_SWAP_COPY_EXT              0x2029
#define WGL_SWAP_UNDEFINED_EXT         0x202A
#define WGL_TYPE_RGBA_EXT              0x202B
#define WGL_TYPE_COLORINDEX_EXT        0x202C

typedef BOOL (WINAPI* pfn_wglGetPixelFormatAttribivEXT) (HDC, int, int, UINT, int*, int*);
WM3_EXTERN pfn_wglGetPixelFormatAttribivEXT Wm3wglGetPixelFormatAttribivEXT;
#define wglGetPixelFormatAttribivEXT Wm3wglGetPixelFormatAttribivEXT

typedef BOOL (WINAPI* pfn_wglGetPixelFormatAttribfvEXT) (HDC, int, int, UINT, int*, FLOAT*);
WM3_EXTERN pfn_wglGetPixelFormatAttribfvEXT Wm3wglGetPixelFormatAttribfvEXT;
#define wglGetPixelFormatAttribfvEXT Wm3wglGetPixelFormatAttribfvEXT

typedef BOOL (WINAPI* pfn_wglChoosePixelFormatEXT) (HDC, const int*, const FLOAT*, UINT, int*, UINT*);
WM3_EXTERN pfn_wglChoosePixelFormatEXT Wm3wglChoosePixelFormatEXT;
#define wglChoosePixelFormatEXT Wm3wglChoosePixelFormatEXT
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_WGL_EXT_pbuffer;
WM3_EXTERN int Wm3NumFunctions_WGL_EXT_pbuffer;
#ifndef WGL_EXT_pbuffer
#define WGL_EXT_pbuffer
#define WM3_DEFINED_WGL_EXT_pbuffer
#define WGL_DRAW_TO_PBUFFER_EXT        0x202D
#define WGL_MAX_PBUFFER_PIXELS_EXT     0x202E
#define WGL_MAX_PBUFFER_WIDTH_EXT      0x202F
#define WGL_MAX_PBUFFER_HEIGHT_EXT     0x2030
#define WGL_OPTIMAL_PBUFFER_WIDTH_EXT  0x2031
#define WGL_OPTIMAL_PBUFFER_HEIGHT_EXT 0x2032
#define WGL_PBUFFER_LARGEST_EXT        0x2033
#define WGL_PBUFFER_WIDTH_EXT          0x2034
#define WGL_PBUFFER_HEIGHT_EXT         0x2035
DECLARE_HANDLE(HPBUFFEREXT);

typedef HPBUFFEREXT (WINAPI* pfn_wglCreatePbufferEXT) (HDC, int, int, int, const int*);
WM3_EXTERN pfn_wglCreatePbufferEXT Wm3wglCreatePbufferEXT;
#define wglCreatePbufferEXT Wm3wglCreatePbufferEXT

typedef HDC (WINAPI* pfn_wglGetPbufferDCEXT) (HPBUFFEREXT);
WM3_EXTERN pfn_wglGetPbufferDCEXT Wm3wglGetPbufferDCEXT;
#define wglGetPbufferDCEXT Wm3wglGetPbufferDCEXT

typedef int (WINAPI* pfn_wglReleasePbufferDCEXT) (HPBUFFEREXT, HDC);
WM3_EXTERN pfn_wglReleasePbufferDCEXT Wm3wglReleasePbufferDCEXT;
#define wglReleasePbufferDCEXT Wm3wglReleasePbufferDCEXT

typedef BOOL (WINAPI* pfn_wglDestroyPbufferEXT) (HPBUFFEREXT);
WM3_EXTERN pfn_wglDestroyPbufferEXT Wm3wglDestroyPbufferEXT;
#define wglDestroyPbufferEXT Wm3wglDestroyPbufferEXT

typedef BOOL (WINAPI* pfn_wglQueryPbufferEXT) (HPBUFFEREXT, int, int*);
WM3_EXTERN pfn_wglQueryPbufferEXT Wm3wglQueryPbufferEXT;
#define wglQueryPbufferEXT Wm3wglQueryPbufferEXT
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_WGL_EXT_depth_float;
WM3_EXTERN int Wm3NumFunctions_WGL_EXT_depth_float;
#ifndef WGL_EXT_depth_float
#define WGL_EXT_depth_float
#define WM3_DEFINED_WGL_EXT_depth_float
#define WGL_DEPTH_FLOAT_EXT            0x2040
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_WGL_3DFX_multisample;
WM3_EXTERN int Wm3NumFunctions_WGL_3DFX_multisample;
#ifndef WGL_3DFX_multisample
#define WGL_3DFX_multisample
#define WM3_DEFINED_WGL_3DFX_multisample
#define WGL_SAMPLE_BUFFERS_3DFX        0x2060
#define WGL_SAMPLES_3DFX               0x2061
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_WGL_EXT_multisample;
WM3_EXTERN int Wm3NumFunctions_WGL_EXT_multisample;
#ifndef WGL_EXT_multisample
#define WGL_EXT_multisample
#define WM3_DEFINED_WGL_EXT_multisample
#define WGL_SAMPLE_BUFFERS_EXT         0x2041
#define WGL_SAMPLES_EXT                0x2042
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_WGL_I3D_digital_video_control;
WM3_EXTERN int Wm3NumFunctions_WGL_I3D_digital_video_control;
#ifndef WGL_I3D_digital_video_control
#define WGL_I3D_digital_video_control
#define WM3_DEFINED_WGL_I3D_digital_video_control
#define WGL_DIGITAL_VIDEO_CURSOR_ALPHA_FRAMEBUFFER_I3D  0x2050
#define WGL_DIGITAL_VIDEO_CURSOR_ALPHA_VALUE_I3D        0x2051
#define WGL_DIGITAL_VIDEO_CURSOR_INCLUDED_I3D           0x2052
#define WGL_DIGITAL_VIDEO_GAMMA_CORRECTED_I3D           0x2053

typedef BOOL (WINAPI* pfn_wglGetDigitalVideoParametersI3D) (HDC, int, int*);
WM3_EXTERN pfn_wglGetDigitalVideoParametersI3D Wm3wglGetDigitalVideoParametersI3D;
#define wglGetDigitalVideoParametersI3D Wm3wglGetDigitalVideoParametersI3D

typedef BOOL (WINAPI* pfn_wglSetDigitalVideoParametersI3D) (HDC, int, const int*);
WM3_EXTERN pfn_wglSetDigitalVideoParametersI3D Wm3wglSetDigitalVideoParametersI3D;
#define wglSetDigitalVideoParametersI3D Wm3wglSetDigitalVideoParametersI3D
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_WGL_I3D_gamma;
WM3_EXTERN int Wm3NumFunctions_WGL_I3D_gamma;
#ifndef WGL_I3D_gamma
#define WGL_I3D_gamma
#define WM3_DEFINED_WGL_I3D_gamma
#define WGL_GAMMA_TABLE_SIZE_I3D       0x204E
#define WGL_GAMMA_EXCLUDE_DESKTOP_I3D  0x204F

typedef BOOL (WINAPI* pfn_wglGetGammaTableParametersI3D) (HDC, int, int*);
WM3_EXTERN pfn_wglGetGammaTableParametersI3D Wm3wglGetGammaTableParametersI3D;
#define wglGetGammaTableParametersI3D Wm3wglGetGammaTableParametersI3D

typedef BOOL (WINAPI* pfn_wglSetGammaTableParametersI3D) (HDC, int, const int*);
WM3_EXTERN pfn_wglSetGammaTableParametersI3D Wm3wglSetGammaTableParametersI3D;
#define wglSetGammaTableParametersI3D Wm3wglSetGammaTableParametersI3D

typedef BOOL (WINAPI* pfn_wglGetGammaTableI3D) (HDC, int, USHORT*, USHORT*, USHORT*);
WM3_EXTERN pfn_wglGetGammaTableI3D Wm3wglGetGammaTableI3D;
#define wglGetGammaTableI3D Wm3wglGetGammaTableI3D

typedef BOOL (WINAPI* pfn_wglSetGammaTableI3D) (HDC, int, const USHORT*, const USHORT*, const USHORT*);
WM3_EXTERN pfn_wglSetGammaTableI3D Wm3wglSetGammaTableI3D;
#define wglSetGammaTableI3D Wm3wglSetGammaTableI3D
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_WGL_I3D_genlock;
WM3_EXTERN int Wm3NumFunctions_WGL_I3D_genlock;
#ifndef WGL_I3D_genlock
#define WGL_I3D_genlock
#define WM3_DEFINED_WGL_I3D_genlock
#define WGL_GENLOCK_SOURCE_MULTIVIEW_I3D        0x2044
#define WGL_GENLOCK_SOURCE_EXTENAL_SYNC_I3D     0x2045
#define WGL_GENLOCK_SOURCE_EXTENAL_FIELD_I3D    0x2046
#define WGL_GENLOCK_SOURCE_EXTENAL_TTL_I3D      0x2047
#define WGL_GENLOCK_SOURCE_DIGITAL_SYNC_I3D     0x2048
#define WGL_GENLOCK_SOURCE_DIGITAL_FIELD_I3D    0x2049
#define WGL_GENLOCK_SOURCE_EDGE_FALLING_I3D     0x204A
#define WGL_GENLOCK_SOURCE_EDGE_RISING_I3D      0x204B
#define WGL_GENLOCK_SOURCE_EDGE_BOTH_I3D        0x204C

typedef BOOL (WINAPI* pfn_wglEnableGenlockI3D) (HDC);
WM3_EXTERN pfn_wglEnableGenlockI3D Wm3wglEnableGenlockI3D;
#define wglEnableGenlockI3D Wm3wglEnableGenlockI3D

typedef BOOL (WINAPI* pfn_wglDisableGenlockI3D) (HDC);
WM3_EXTERN pfn_wglDisableGenlockI3D Wm3wglDisableGenlockI3D;
#define wglDisableGenlockI3D Wm3wglDisableGenlockI3D

typedef BOOL (WINAPI* pfn_wglIsEnabledGenlockI3D) (HDC, BOOL*);
WM3_EXTERN pfn_wglIsEnabledGenlockI3D Wm3wglIsEnabledGenlockI3D;
#define wglIsEnabledGenlockI3D Wm3wglIsEnabledGenlockI3D

typedef BOOL (WINAPI* pfn_wglGenlockSourceI3D) (HDC, UINT);
WM3_EXTERN pfn_wglGenlockSourceI3D Wm3wglGenlockSourceI3D;
#define wglGenlockSourceI3D Wm3wglGenlockSourceI3D

typedef BOOL (WINAPI* pfn_wglGetGenlockSourceI3D) (HDC, UINT*);
WM3_EXTERN pfn_wglGetGenlockSourceI3D Wm3wglGetGenlockSourceI3D;
#define wglGetGenlockSourceI3D Wm3wglGetGenlockSourceI3D

typedef BOOL (WINAPI* pfn_wglGenlockSourceEdgeI3D) (HDC, UINT);
WM3_EXTERN pfn_wglGenlockSourceEdgeI3D Wm3wglGenlockSourceEdgeI3D;
#define wglGenlockSourceEdgeI3D Wm3wglGenlockSourceEdgeI3D

typedef BOOL (WINAPI* pfn_wglGetGenlockSourceEdgeI3D) (HDC, UINT*);
WM3_EXTERN pfn_wglGetGenlockSourceEdgeI3D Wm3wglGetGenlockSourceEdgeI3D;
#define wglGetGenlockSourceEdgeI3D Wm3wglGetGenlockSourceEdgeI3D

typedef BOOL (WINAPI* pfn_wglGenlockSampleRateI3D) (HDC, UINT);
WM3_EXTERN pfn_wglGenlockSampleRateI3D Wm3wglGenlockSampleRateI3D;
#define wglGenlockSampleRateI3D Wm3wglGenlockSampleRateI3D

typedef BOOL (WINAPI* pfn_wglGetGenlockSampleRateI3D) (HDC, UINT*);
WM3_EXTERN pfn_wglGetGenlockSampleRateI3D Wm3wglGetGenlockSampleRateI3D;
#define wglGetGenlockSampleRateI3D Wm3wglGetGenlockSampleRateI3D

typedef BOOL (WINAPI* pfn_wglGenlockSourceDelayI3D) (HDC, UINT);
WM3_EXTERN pfn_wglGenlockSourceDelayI3D Wm3wglGenlockSourceDelayI3D;
#define wglGenlockSourceDelayI3D Wm3wglGenlockSourceDelayI3D

typedef BOOL (WINAPI* pfn_wglGetGenlockSourceDelayI3D) (HDC, UINT*);
WM3_EXTERN pfn_wglGetGenlockSourceDelayI3D Wm3wglGetGenlockSourceDelayI3D;
#define wglGetGenlockSourceDelayI3D Wm3wglGetGenlockSourceDelayI3D

typedef BOOL (WINAPI* pfn_wglQueryGenlockMaxSourceDelayI3D) (HDC, UINT*, UINT*);
WM3_EXTERN pfn_wglQueryGenlockMaxSourceDelayI3D Wm3wglQueryGenlockMaxSourceDelayI3D;
#define wglQueryGenlockMaxSourceDelayI3D Wm3wglQueryGenlockMaxSourceDelayI3D
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_WGL_I3D_image_buffer;
WM3_EXTERN int Wm3NumFunctions_WGL_I3D_image_buffer;
#ifndef WGL_I3D_image_buffer
#define WGL_I3D_image_buffer
#define WM3_DEFINED_WGL_I3D_image_buffer
#define WGL_IMAGE_BUFFER_MIN_ACCESS_I3D 0x00000001
#define WGL_IMAGE_BUFFER_LOCK_I3D       0x00000002

typedef LPVOID (WINAPI* pfn_wglCreateImageBufferI3D) (HDC, DWORD, UINT);
WM3_EXTERN pfn_wglCreateImageBufferI3D Wm3wglCreateImageBufferI3D;
#define wglCreateImageBufferI3D Wm3wglCreateImageBufferI3D

typedef BOOL (WINAPI* pfn_wglDestroyImageBufferI3D) (HDC, LPVOID);
WM3_EXTERN pfn_wglDestroyImageBufferI3D Wm3wglDestroyImageBufferI3D;
#define wglDestroyImageBufferI3D Wm3wglDestroyImageBufferI3D

typedef BOOL (WINAPI* pfn_wglAssociateImageBufferEventsI3D) (HDC, const HANDLE*, const LPVOID*, const DWORD*, UINT);
WM3_EXTERN pfn_wglAssociateImageBufferEventsI3D Wm3wglAssociateImageBufferEventsI3D;
#define wglAssociateImageBufferEventsI3D Wm3wglAssociateImageBufferEventsI3D

typedef BOOL (WINAPI* pfn_wglReleaseImageBufferEventsI3D) (HDC, const LPVOID*, UINT);
WM3_EXTERN pfn_wglReleaseImageBufferEventsI3D Wm3wglReleaseImageBufferEventsI3D;
#define wglReleaseImageBufferEventsI3D Wm3wglReleaseImageBufferEventsI3D
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_WGL_I3D_swap_frame_lock;
WM3_EXTERN int Wm3NumFunctions_WGL_I3D_swap_frame_lock;
#ifndef WGL_I3D_swap_frame_lock
#define WGL_I3D_swap_frame_lock
#define WM3_DEFINED_WGL_I3D_swap_frame_lock

typedef BOOL (WINAPI* pfn_wglEnableFrameLockI3D) (void);
WM3_EXTERN pfn_wglEnableFrameLockI3D Wm3wglEnableFrameLockI3D;
#define wglEnableFrameLockI3D Wm3wglEnableFrameLockI3D

typedef BOOL (WINAPI* pfn_wglDisableFrameLockI3D) (void);
WM3_EXTERN pfn_wglDisableFrameLockI3D Wm3wglDisableFrameLockI3D;
#define wglDisableFrameLockI3D Wm3wglDisableFrameLockI3D

typedef BOOL (WINAPI* pfn_wglIsEnabledFrameLockI3D) (BOOL*);
WM3_EXTERN pfn_wglIsEnabledFrameLockI3D Wm3wglIsEnabledFrameLockI3D;
#define wglIsEnabledFrameLockI3D Wm3wglIsEnabledFrameLockI3D

typedef BOOL (WINAPI* pfn_wglQueryFrameLockMasterI3D) (BOOL*);
WM3_EXTERN pfn_wglQueryFrameLockMasterI3D Wm3wglQueryFrameLockMasterI3D;
#define wglQueryFrameLockMasterI3D Wm3wglQueryFrameLockMasterI3D
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_WGL_I3D_swap_frame_usage;
WM3_EXTERN int Wm3NumFunctions_WGL_I3D_swap_frame_usage;
#ifndef WGL_I3D_swap_frame_usage
#define WGL_I3D_swap_frame_usage
#define WM3_DEFINED_WGL_I3D_swap_frame_usage

typedef BOOL (WINAPI* pfn_wglGetFrameUsageI3D) (float*);
WM3_EXTERN pfn_wglGetFrameUsageI3D Wm3wglGetFrameUsageI3D;
#define wglGetFrameUsageI3D Wm3wglGetFrameUsageI3D

typedef BOOL (WINAPI* pfn_wglBeginFrameTrackingI3D) (void);
WM3_EXTERN pfn_wglBeginFrameTrackingI3D Wm3wglBeginFrameTrackingI3D;
#define wglBeginFrameTrackingI3D Wm3wglBeginFrameTrackingI3D

typedef BOOL (WINAPI* pfn_wglEndFrameTrackingI3D) (void);
WM3_EXTERN pfn_wglEndFrameTrackingI3D Wm3wglEndFrameTrackingI3D;
#define wglEndFrameTrackingI3D Wm3wglEndFrameTrackingI3D

typedef BOOL (WINAPI* pfn_wglQueryFrameTrackingI3D) (DWORD*, DWORD*, float*);
WM3_EXTERN pfn_wglQueryFrameTrackingI3D Wm3wglQueryFrameTrackingI3D;
#define wglQueryFrameTrackingI3D Wm3wglQueryFrameTrackingI3D
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_WGL_NV_render_depth_texture;
WM3_EXTERN int Wm3NumFunctions_WGL_NV_render_depth_texture;
#ifndef WGL_NV_render_depth_texture
#define WGL_NV_render_depth_texture
#define WM3_DEFINED_WGL_NV_render_depth_texture
#define WGL_BIND_TO_TEXTURE_DEPTH_NV            0x20A3
#define WGL_BIND_TO_TEXTURE_RECTANGLE_DEPTH_NV  0x20A4
#define WGL_DEPTH_TEXTURE_FORMAT_NV             0x20A5
#define WGL_TEXTURE_DEPTH_COMPONENT_NV          0x20A6
#define WGL_DEPTH_COMPONENT_NV                  0x20A7
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_WGL_NV_render_texture_rectangle;
WM3_EXTERN int Wm3NumFunctions_WGL_NV_render_texture_rectangle;
#ifndef WGL_NV_render_texture_rectangle
#define WGL_NV_render_texture_rectangle
#define WM3_DEFINED_WGL_NV_render_texture_rectangle
#define WGL_BIND_TO_TEXTURE_RECTANGLE_RGB_NV    0x20A0
#define WGL_BIND_TO_TEXTURE_RECTANGLE_RGBA_NV   0x20A1
#define WGL_TEXTURE_RECTANGLE_NV                0x20A2
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_WGL_ATI_pixel_format_float;
WM3_EXTERN int Wm3NumFunctions_WGL_ATI_pixel_format_float;
#ifndef WGL_ATI_pixel_format_float
#define WGL_ATI_pixel_format_float
#define WM3_DEFINED_WGL_ATI_pixel_format_float
#define WGL_TYPE_RGBA_FLOAT_ATI        0x21A0
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_WGL_NV_float_buffer;
WM3_EXTERN int Wm3NumFunctions_WGL_NV_float_buffer;
#ifndef WGL_NV_float_buffer
#define WGL_NV_float_buffer
#define WM3_DEFINED_WGL_NV_float_buffer
#define WGL_FLOAT_COMPONENTS_NV                     0x20B0
#define WGL_BIND_TO_TEXTURE_RECTANGLE_FLOAT_R_NV    0x20B1
#define WGL_BIND_TO_TEXTURE_RECTANGLE_FLOAT_RG_NV   0x20B2
#define WGL_BIND_TO_TEXTURE_RECTANGLE_FLOAT_RGB_NV  0x20B3
#define WGL_BIND_TO_TEXTURE_RECTANGLE_FLOAT_RGBA_NV 0x20B4
#define WGL_TEXTURE_FLOAT_R_NV                      0x20B5
#define WGL_TEXTURE_FLOAT_RG_NV                     0x20B6
#define WGL_TEXTURE_FLOAT_RGB_NV                    0x20B7
#define WGL_TEXTURE_FLOAT_RGBA_NV                   0x20B8
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_WGL_EXT_display_color_table;
WM3_EXTERN int Wm3NumFunctions_WGL_EXT_display_color_table;
#ifndef WGL_EXT_display_color_table
#define WGL_EXT_display_color_table
#define WM3_DEFINED_WGL_EXT_display_color_table

typedef GLboolean (WINAPI* pfn_wglCreateDisplayColorTableEXT) (GLushort);
WM3_EXTERN pfn_wglCreateDisplayColorTableEXT Wm3wglCreateDisplayColorTableEXT;
#define wglCreateDisplayColorTableEXT Wm3wglCreateDisplayColorTableEXT

typedef GLboolean (WINAPI* pfn_wglLoadDisplayColorTableEXT) (const GLushort*, GLuint);
WM3_EXTERN pfn_wglLoadDisplayColorTableEXT Wm3wglLoadDisplayColorTableEXT;
#define wglLoadDisplayColorTableEXT Wm3wglLoadDisplayColorTableEXT

typedef GLboolean (WINAPI* pfn_wglBindDisplayColorTableEXT) (GLushort);
WM3_EXTERN pfn_wglBindDisplayColorTableEXT Wm3wglBindDisplayColorTableEXT;
#define wglBindDisplayColorTableEXT Wm3wglBindDisplayColorTableEXT

typedef VOID (WINAPI* pfn_wglDestroyDisplayColorTableEXT) (GLushort);
WM3_EXTERN pfn_wglDestroyDisplayColorTableEXT Wm3wglDestroyDisplayColorTableEXT;
#define wglDestroyDisplayColorTableEXT Wm3wglDestroyDisplayColorTableEXT
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_WGL_EXT_extensions_string;
WM3_EXTERN int Wm3NumFunctions_WGL_EXT_extensions_string;
#ifndef WGL_EXT_extensions_string
#define WGL_EXT_extensions_string
#define WM3_DEFINED_WGL_EXT_extensions_string

typedef const char* (WINAPI* pfn_wglGetExtensionsStringEXT) (void);
WM3_EXTERN pfn_wglGetExtensionsStringEXT Wm3wglGetExtensionsStringEXT;
#define wglGetExtensionsStringEXT Wm3wglGetExtensionsStringEXT
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_WGL_EXT_swap_control;
WM3_EXTERN int Wm3NumFunctions_WGL_EXT_swap_control;
#ifndef WGL_EXT_swap_control
#define WGL_EXT_swap_control
#define WM3_DEFINED_WGL_EXT_swap_control

typedef BOOL (WINAPI* pfn_wglSwapIntervalEXT) (int);
WM3_EXTERN pfn_wglSwapIntervalEXT Wm3wglSwapIntervalEXT;
#define wglSwapIntervalEXT Wm3wglSwapIntervalEXT

typedef int (WINAPI* pfn_wglGetSwapIntervalEXT) (void);
WM3_EXTERN pfn_wglGetSwapIntervalEXT Wm3wglGetSwapIntervalEXT;
#define wglGetSwapIntervalEXT Wm3wglGetSwapIntervalEXT
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_WGL_NV_vertex_array_range;
WM3_EXTERN int Wm3NumFunctions_WGL_NV_vertex_array_range;
#ifndef WGL_NV_vertex_array_range
#define WGL_NV_vertex_array_range
#define WM3_DEFINED_WGL_NV_vertex_array_range

typedef void* (WINAPI* pfn_wglAllocateMemoryNV) (GLsizei, GLfloat, GLfloat, GLfloat);
WM3_EXTERN pfn_wglAllocateMemoryNV Wm3wglAllocateMemoryNV;
#define wglAllocateMemoryNV Wm3wglAllocateMemoryNV

typedef void (WINAPI* pfn_wglFreeMemoryNV) (void*);
WM3_EXTERN pfn_wglFreeMemoryNV Wm3wglFreeMemoryNV;
#define wglFreeMemoryNV Wm3wglFreeMemoryNV
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_WGL_OML_sync_control;
WM3_EXTERN int Wm3NumFunctions_WGL_OML_sync_control;
#ifndef WGL_OML_sync_control
#define WGL_OML_sync_control
#define WM3_DEFINED_WGL_OML_sync_control

typedef BOOL (WINAPI* pfn_wglGetSyncValuesOML) (HDC, INT64*, INT64*, INT64*);
WM3_EXTERN pfn_wglGetSyncValuesOML Wm3wglGetSyncValuesOML;
#define wglGetSyncValuesOML Wm3wglGetSyncValuesOML

typedef BOOL (WINAPI* pfn_wglGetMscRateOML) (HDC, INT32*, INT32*);
WM3_EXTERN pfn_wglGetMscRateOML Wm3wglGetMscRateOML;
#define wglGetMscRateOML Wm3wglGetMscRateOML

typedef INT64 (WINAPI* pfn_wglSwapBuffersMscOML) (HDC, INT64, INT64, INT64);
WM3_EXTERN pfn_wglSwapBuffersMscOML Wm3wglSwapBuffersMscOML;
#define wglSwapBuffersMscOML Wm3wglSwapBuffersMscOML

typedef INT64 (WINAPI* pfn_wglSwapLayerBuffersMscOML) (HDC, int, INT64, INT64, INT64);
WM3_EXTERN pfn_wglSwapLayerBuffersMscOML Wm3wglSwapLayerBuffersMscOML;
#define wglSwapLayerBuffersMscOML Wm3wglSwapLayerBuffersMscOML

typedef BOOL (WINAPI* pfn_wglWaitForMscOML) (HDC, INT64, INT64, INT64, INT64*, INT64*, INT64*);
WM3_EXTERN pfn_wglWaitForMscOML Wm3wglWaitForMscOML;
#define wglWaitForMscOML Wm3wglWaitForMscOML

typedef BOOL (WINAPI* pfn_wglWaitForSbcOML) (HDC, INT64, INT64*, INT64*, INT64*);
WM3_EXTERN pfn_wglWaitForSbcOML Wm3wglWaitForSbcOML;
#define wglWaitForSbcOML Wm3wglWaitForSbcOML
#endif

/*--------------------------------------------------------------------------*/
void InitializeWgl ();
/*--------------------------------------------------------------------------*/

#ifdef __cplusplus
}
#endif

#ifdef WM3_DEFINED_WINAPI
#undef WM3_DEFINED_WINAPI
#undef WINAPI
#endif

#endif
