/*
Geometric Tools, Inc.
http://www.geometrictools.com
Copyright (c) 1998-2005.  All Rights Reserved

The Wild Magic Library (WM3) source code is supplied under the terms of
the license agreement
    http://www.geometrictools.com/License/WildMagic3License.pdf
and may not be copied or disclosed except in accordance with the terms
of that agreement.

This file evolved by modifications from a version of glext.h that was
downloaded from the site listed in the license below.  The version of the
file is: GL_GLEXT_VERSION 27
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

#ifndef WM3OPENGLEXTENSIONS_H
#define WM3OPENGLEXTENSIONS_H

#include "Wm3OpenGLRendererLIB.h"

/*
In order to get the extension mechanism to work on multiple platforms, you
have to go to great pains to unravel the mess that is gl.h, glu.h, and
glext.h.  The _WIN32 situation is fairly easy to handle because gl.h only
supports OpenGL 1.1.  However, Fedora Core 3 Linux has a gl.h that supports
OpenGL 1.3 and it includes glext.h which ships with the Linux tools.  The
following block of code is used to prevent gl.h from being included on Linux.
The OpenGL definitions are, therefore, provided by this extension wrapper.
This block of code and the definitions in the GL_VERSION_1_1 block are not
necessary on _WIN32.
*/
#if defined(__gl_h_) || defined(__GL_H__)
#error gl.h included before Wm3OpenGLExtensions.h
#endif
#if defined(__glext_h_) || defined(__GLEXT_H_)
#error glext.h included before Wm3OpenGLExtensions.h
#endif
#if defined(__gl_ATI_h_)
#error glATI.h included before Wm3OpenGLExtensions.h
#endif

#define __gl_h_
#define __GL_H__
#define __glext_h_
#define __GLEXT_H_
#define __gl_ATI_h_

/*--------------------------------------------------------------------------*/
#if defined(_WIN32)

/*
Normally you need to include windows.h before gl.h and glu.h.  However,
this file defines a lot of symbols that can cause problems with application
code.  In particular, Developer Studio complains about the application
function WindowApplication::GetCharWidth in Wm3GlutApplication.cpp, stating
that it conflicts with GetCharWidthA.  The relevant symbols are instead
defined here:
  gl.h needs APIENTRY, WINGDIAPI
  glu.h needs APIENTRY, CALLBACK, wchar_t
*/

#ifndef APIENTRY
#define WM3_DEFINED_APIENTRY
#if (defined(_MSC_VER) && (_MSC_VER >= 800)) || defined(_STDCALL_SUPPORTED) || defined(MINGW)
#define APIENTRY __stdcall
#else
#define APIENTRY
#endif
#endif

#ifndef CALLBACK
#define WM3_DEFINED_CALLBACK
#if (defined(_MSC_VER) && (_MSC_VER >= 800)) || defined(_STDCALL_SUPPORTED)
#define CALLBACK __stdcall
#else
#define CALLBACK
#endif
#endif

#ifndef WINGDIAPI
#define WM3_DEFINED_WINGDIAPI
#define WINGDIAPI __declspec(dllimport)
#endif

#ifndef _WCHAR_T_DEFINED
typedef unsigned short wchar_t;
#define _WCHAR_T_DEFINED
#endif

#ifdef WM3_RENDERER_DLL_EXPORT
#define WM3_EXTERN extern __declspec(dllexport)
#else
#ifdef WM3_RENDERER_DLL_IMPORT
#define WM3_EXTERN extern __declspec(dllimport)
#else
#define WM3_EXTERN extern
#endif
#endif

#ifdef MINGW
#ifndef GLAPI
#define WM3_DEFINED_GLAPI
#define GLAPI extern
#endif
#endif

#else  // Apple, Linux
#define APIENTRY
#define CALLBACK
#define WINGDIAPI extern
#define WM3_EXTERN extern
#endif

#ifdef __cplusplus
#include <cstddef>
extern "C" {
#else
#include <stddef.h>
#endif

#define WM3_EXT_FULLY_EXISTS     2
#define WM3_EXT_PARTIALLY_EXISTS 1
#define WM3_EXT_DOES_NOT_EXIST   0

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_VERSION_1_1;
WM3_EXTERN int Wm3NumFunctions_GL_VERSION_1_1;
#ifndef GL_VERSION_1_1
#define GL_VERSION_1_1
#define WM3_DEFINED_GL_VERSION_1_1
#define GL_ACCUM                            0x0100
#define GL_LOAD                             0x0101
#define GL_RETURN                           0x0102
#define GL_MULT                             0x0103
#define GL_ADD                              0x0104
#define GL_NEVER                            0x0200
#define GL_LESS                             0x0201
#define GL_EQUAL                            0x0202
#define GL_LEQUAL                           0x0203
#define GL_GREATER                          0x0204
#define GL_NOTEQUAL                         0x0205
#define GL_GEQUAL                           0x0206
#define GL_ALWAYS                           0x0207
#define GL_CURRENT_BIT                      0x00000001
#define GL_POINT_BIT                        0x00000002
#define GL_LINE_BIT                         0x00000004
#define GL_POLYGON_BIT                      0x00000008
#define GL_POLYGON_STIPPLE_BIT              0x00000010
#define GL_PIXEL_MODE_BIT                   0x00000020
#define GL_LIGHTING_BIT                     0x00000040
#define GL_FOG_BIT                          0x00000080
#define GL_DEPTH_BUFFER_BIT                 0x00000100
#define GL_ACCUM_BUFFER_BIT                 0x00000200
#define GL_STENCIL_BUFFER_BIT               0x00000400
#define GL_VIEWPORT_BIT                     0x00000800
#define GL_TRANSFORM_BIT                    0x00001000
#define GL_ENABLE_BIT                       0x00002000
#define GL_COLOR_BUFFER_BIT                 0x00004000
#define GL_HINT_BIT                         0x00008000
#define GL_EVAL_BIT                         0x00010000
#define GL_LIST_BIT                         0x00020000
#define GL_TEXTURE_BIT                      0x00040000
#define GL_SCISSOR_BIT                      0x00080000
#define GL_ALL_ATTRIB_BITS                  0x000fffff
#define GL_POINTS                           0x0000
#define GL_LINES                            0x0001
#define GL_LINE_LOOP                        0x0002
#define GL_LINE_STRIP                       0x0003
#define GL_TRIANGLES                        0x0004
#define GL_TRIANGLE_STRIP                   0x0005
#define GL_TRIANGLE_FAN                     0x0006
#define GL_QUADS                            0x0007
#define GL_QUAD_STRIP                       0x0008
#define GL_POLYGON                          0x0009
#define GL_ZERO                             0
#define GL_ONE                              1
#define GL_SRC_COLOR                        0x0300
#define GL_ONE_MINUS_SRC_COLOR              0x0301
#define GL_SRC_ALPHA                        0x0302
#define GL_ONE_MINUS_SRC_ALPHA              0x0303
#define GL_DST_ALPHA                        0x0304
#define GL_ONE_MINUS_DST_ALPHA              0x0305
#define GL_DST_COLOR                        0x0306
#define GL_ONE_MINUS_DST_COLOR              0x0307
#define GL_SRC_ALPHA_SATURATE               0x0308
#define GL_TRUE                             1
#define GL_FALSE                            0
#define GL_CLIP_PLANE0                      0x3000
#define GL_CLIP_PLANE1                      0x3001
#define GL_CLIP_PLANE2                      0x3002
#define GL_CLIP_PLANE3                      0x3003
#define GL_CLIP_PLANE4                      0x3004
#define GL_CLIP_PLANE5                      0x3005
#define GL_BYTE                             0x1400
#define GL_UNSIGNED_BYTE                    0x1401
#define GL_SHORT                            0x1402
#define GL_UNSIGNED_SHORT                   0x1403
#define GL_INT                              0x1404
#define GL_UNSIGNED_INT                     0x1405
#define GL_FLOAT                            0x1406
#define GL_2_BYTES                          0x1407
#define GL_3_BYTES                          0x1408
#define GL_4_BYTES                          0x1409
#define GL_DOUBLE                           0x140A
#define GL_NONE                             0
#define GL_FRONT_LEFT                       0x0400
#define GL_FRONT_RIGHT                      0x0401
#define GL_BACK_LEFT                        0x0402
#define GL_BACK_RIGHT                       0x0403
#define GL_FRONT                            0x0404
#define GL_BACK                             0x0405
#define GL_LEFT                             0x0406
#define GL_RIGHT                            0x0407
#define GL_FRONT_AND_BACK                   0x0408
#define GL_AUX0                             0x0409
#define GL_AUX1                             0x040A
#define GL_AUX2                             0x040B
#define GL_AUX3                             0x040C
#define GL_NO_ERROR                         0
#define GL_INVALID_ENUM                     0x0500
#define GL_INVALID_VALUE                    0x0501
#define GL_INVALID_OPERATION                0x0502
#define GL_STACK_OVERFLOW                   0x0503
#define GL_STACK_UNDERFLOW                  0x0504
#define GL_OUT_OF_MEMORY                    0x0505
#define GL_2D                               0x0600
#define GL_3D                               0x0601
#define GL_3D_COLOR                         0x0602
#define GL_3D_COLOR_TEXTURE                 0x0603
#define GL_4D_COLOR_TEXTURE                 0x0604
#define GL_PASS_THROUGH_TOKEN               0x0700
#define GL_POINT_TOKEN                      0x0701
#define GL_LINE_TOKEN                       0x0702
#define GL_POLYGON_TOKEN                    0x0703
#define GL_BITMAP_TOKEN                     0x0704
#define GL_DRAW_PIXEL_TOKEN                 0x0705
#define GL_COPY_PIXEL_TOKEN                 0x0706
#define GL_LINE_RESET_TOKEN                 0x0707
#define GL_EXP                              0x0800
#define GL_EXP2                             0x0801
#define GL_CW                               0x0900
#define GL_CCW                              0x0901
#define GL_COEFF                            0x0A00
#define GL_ORDER                            0x0A01
#define GL_DOMAIN                           0x0A02
#define GL_CURRENT_COLOR                    0x0B00
#define GL_CURRENT_INDEX                    0x0B01
#define GL_CURRENT_NORMAL                   0x0B02
#define GL_CURRENT_TEXTURE_COORDS           0x0B03
#define GL_CURRENT_RASTER_COLOR             0x0B04
#define GL_CURRENT_RASTER_INDEX             0x0B05
#define GL_CURRENT_RASTER_TEXTURE_COORDS    0x0B06
#define GL_CURRENT_RASTER_POSITION          0x0B07
#define GL_CURRENT_RASTER_POSITION_VALID    0x0B08
#define GL_CURRENT_RASTER_DISTANCE          0x0B09
#define GL_POINT_SMOOTH                     0x0B10
#define GL_POINT_SIZE                       0x0B11
#define GL_POINT_SIZE_RANGE                 0x0B12
#define GL_POINT_SIZE_GRANULARITY           0x0B13
#define GL_LINE_SMOOTH                      0x0B20
#define GL_LINE_WIDTH                       0x0B21
#define GL_LINE_WIDTH_RANGE                 0x0B22
#define GL_LINE_WIDTH_GRANULARITY           0x0B23
#define GL_LINE_STIPPLE                     0x0B24
#define GL_LINE_STIPPLE_PATTERN             0x0B25
#define GL_LINE_STIPPLE_REPEAT              0x0B26
#define GL_LIST_MODE                        0x0B30
#define GL_MAX_LIST_NESTING                 0x0B31
#define GL_LIST_BASE                        0x0B32
#define GL_LIST_INDEX                       0x0B33
#define GL_POLYGON_MODE                     0x0B40
#define GL_POLYGON_SMOOTH                   0x0B41
#define GL_POLYGON_STIPPLE                  0x0B42
#define GL_EDGE_FLAG                        0x0B43
#define GL_CULL_FACE                        0x0B44
#define GL_CULL_FACE_MODE                   0x0B45
#define GL_FRONT_FACE                       0x0B46
#define GL_LIGHTING                         0x0B50
#define GL_LIGHT_MODEL_LOCAL_VIEWER         0x0B51
#define GL_LIGHT_MODEL_TWO_SIDE             0x0B52
#define GL_LIGHT_MODEL_AMBIENT              0x0B53
#define GL_SHADE_MODEL                      0x0B54
#define GL_COLOR_MATERIAL_FACE              0x0B55
#define GL_COLOR_MATERIAL_PARAMETER         0x0B56
#define GL_COLOR_MATERIAL                   0x0B57
#define GL_FOG                              0x0B60
#define GL_FOG_INDEX                        0x0B61
#define GL_FOG_DENSITY                      0x0B62
#define GL_FOG_START                        0x0B63
#define GL_FOG_END                          0x0B64
#define GL_FOG_MODE                         0x0B65
#define GL_FOG_COLOR                        0x0B66
#define GL_DEPTH_RANGE                      0x0B70
#define GL_DEPTH_TEST                       0x0B71
#define GL_DEPTH_WRITEMASK                  0x0B72
#define GL_DEPTH_CLEAR_VALUE                0x0B73
#define GL_DEPTH_FUNC                       0x0B74
#define GL_ACCUM_CLEAR_VALUE                0x0B80
#define GL_STENCIL_TEST                     0x0B90
#define GL_STENCIL_CLEAR_VALUE              0x0B91
#define GL_STENCIL_FUNC                     0x0B92
#define GL_STENCIL_VALUE_MASK               0x0B93
#define GL_STENCIL_FAIL                     0x0B94
#define GL_STENCIL_PASS_DEPTH_FAIL          0x0B95
#define GL_STENCIL_PASS_DEPTH_PASS          0x0B96
#define GL_STENCIL_REF                      0x0B97
#define GL_STENCIL_WRITEMASK                0x0B98
#define GL_MATRIX_MODE                      0x0BA0
#define GL_NORMALIZE                        0x0BA1
#define GL_VIEWPORT                         0x0BA2
#define GL_MODELVIEW_STACK_DEPTH            0x0BA3
#define GL_PROJECTION_STACK_DEPTH           0x0BA4
#define GL_TEXTURE_STACK_DEPTH              0x0BA5
#define GL_MODELVIEW_MATRIX                 0x0BA6
#define GL_PROJECTION_MATRIX                0x0BA7
#define GL_TEXTURE_MATRIX                   0x0BA8
#define GL_ATTRIB_STACK_DEPTH               0x0BB0
#define GL_CLIENT_ATTRIB_STACK_DEPTH        0x0BB1
#define GL_ALPHA_TEST                       0x0BC0
#define GL_ALPHA_TEST_FUNC                  0x0BC1
#define GL_ALPHA_TEST_REF                   0x0BC2
#define GL_DITHER                           0x0BD0
#define GL_BLEND_DST                        0x0BE0
#define GL_BLEND_SRC                        0x0BE1
#define GL_BLEND                            0x0BE2
#define GL_LOGIC_OP_MODE                    0x0BF0
#define GL_INDEX_LOGIC_OP                   0x0BF1
#define GL_COLOR_LOGIC_OP                   0x0BF2
#define GL_AUX_BUFFERS                      0x0C00
#define GL_DRAW_BUFFER                      0x0C01
#define GL_READ_BUFFER                      0x0C02
#define GL_SCISSOR_BOX                      0x0C10
#define GL_SCISSOR_TEST                     0x0C11
#define GL_INDEX_CLEAR_VALUE                0x0C20
#define GL_INDEX_WRITEMASK                  0x0C21
#define GL_COLOR_CLEAR_VALUE                0x0C22
#define GL_COLOR_WRITEMASK                  0x0C23
#define GL_INDEX_MODE                       0x0C30
#define GL_RGBA_MODE                        0x0C31
#define GL_DOUBLEBUFFER                     0x0C32
#define GL_STEREO                           0x0C33
#define GL_RENDER_MODE                      0x0C40
#define GL_PERSPECTIVE_CORRECTION_HINT      0x0C50
#define GL_POINT_SMOOTH_HINT                0x0C51
#define GL_LINE_SMOOTH_HINT                 0x0C52
#define GL_POLYGON_SMOOTH_HINT              0x0C53
#define GL_FOG_HINT                         0x0C54
#define GL_TEXTURE_GEN_S                    0x0C60
#define GL_TEXTURE_GEN_T                    0x0C61
#define GL_TEXTURE_GEN_R                    0x0C62
#define GL_TEXTURE_GEN_Q                    0x0C63
#define GL_PIXEL_MAP_I_TO_I                 0x0C70
#define GL_PIXEL_MAP_S_TO_S                 0x0C71
#define GL_PIXEL_MAP_I_TO_R                 0x0C72
#define GL_PIXEL_MAP_I_TO_G                 0x0C73
#define GL_PIXEL_MAP_I_TO_B                 0x0C74
#define GL_PIXEL_MAP_I_TO_A                 0x0C75
#define GL_PIXEL_MAP_R_TO_R                 0x0C76
#define GL_PIXEL_MAP_G_TO_G                 0x0C77
#define GL_PIXEL_MAP_B_TO_B                 0x0C78
#define GL_PIXEL_MAP_A_TO_A                 0x0C79
#define GL_PIXEL_MAP_I_TO_I_SIZE            0x0CB0
#define GL_PIXEL_MAP_S_TO_S_SIZE            0x0CB1
#define GL_PIXEL_MAP_I_TO_R_SIZE            0x0CB2
#define GL_PIXEL_MAP_I_TO_G_SIZE            0x0CB3
#define GL_PIXEL_MAP_I_TO_B_SIZE            0x0CB4
#define GL_PIXEL_MAP_I_TO_A_SIZE            0x0CB5
#define GL_PIXEL_MAP_R_TO_R_SIZE            0x0CB6
#define GL_PIXEL_MAP_G_TO_G_SIZE            0x0CB7
#define GL_PIXEL_MAP_B_TO_B_SIZE            0x0CB8
#define GL_PIXEL_MAP_A_TO_A_SIZE            0x0CB9
#define GL_UNPACK_SWAP_BYTES                0x0CF0
#define GL_UNPACK_LSB_FIRST                 0x0CF1
#define GL_UNPACK_ROW_LENGTH                0x0CF2
#define GL_UNPACK_SKIP_ROWS                 0x0CF3
#define GL_UNPACK_SKIP_PIXELS               0x0CF4
#define GL_UNPACK_ALIGNMENT                 0x0CF5
#define GL_PACK_SWAP_BYTES                  0x0D00
#define GL_PACK_LSB_FIRST                   0x0D01
#define GL_PACK_ROW_LENGTH                  0x0D02
#define GL_PACK_SKIP_ROWS                   0x0D03
#define GL_PACK_SKIP_PIXELS                 0x0D04
#define GL_PACK_ALIGNMENT                   0x0D05
#define GL_MAP_COLOR                        0x0D10
#define GL_MAP_STENCIL                      0x0D11
#define GL_INDEX_SHIFT                      0x0D12
#define GL_INDEX_OFFSET                     0x0D13
#define GL_RED_SCALE                        0x0D14
#define GL_RED_BIAS                         0x0D15
#define GL_ZOOM_X                           0x0D16
#define GL_ZOOM_Y                           0x0D17
#define GL_GREEN_SCALE                      0x0D18
#define GL_GREEN_BIAS                       0x0D19
#define GL_BLUE_SCALE                       0x0D1A
#define GL_BLUE_BIAS                        0x0D1B
#define GL_ALPHA_SCALE                      0x0D1C
#define GL_ALPHA_BIAS                       0x0D1D
#define GL_DEPTH_SCALE                      0x0D1E
#define GL_DEPTH_BIAS                       0x0D1F
#define GL_MAX_EVAL_ORDER                   0x0D30
#define GL_MAX_LIGHTS                       0x0D31
#define GL_MAX_CLIP_PLANES                  0x0D32
#define GL_MAX_TEXTURE_SIZE                 0x0D33
#define GL_MAX_PIXEL_MAP_TABLE              0x0D34
#define GL_MAX_ATTRIB_STACK_DEPTH           0x0D35
#define GL_MAX_MODELVIEW_STACK_DEPTH        0x0D36
#define GL_MAX_NAME_STACK_DEPTH             0x0D37
#define GL_MAX_PROJECTION_STACK_DEPTH       0x0D38
#define GL_MAX_TEXTURE_STACK_DEPTH          0x0D39
#define GL_MAX_VIEWPORT_DIMS                0x0D3A
#define GL_MAX_CLIENT_ATTRIB_STACK_DEPTH    0x0D3B
#define GL_SUBPIXEL_BITS                    0x0D50
#define GL_INDEX_BITS                       0x0D51
#define GL_RED_BITS                         0x0D52
#define GL_GREEN_BITS                       0x0D53
#define GL_BLUE_BITS                        0x0D54
#define GL_ALPHA_BITS                       0x0D55
#define GL_DEPTH_BITS                       0x0D56
#define GL_STENCIL_BITS                     0x0D57
#define GL_ACCUM_RED_BITS                   0x0D58
#define GL_ACCUM_GREEN_BITS                 0x0D59
#define GL_ACCUM_BLUE_BITS                  0x0D5A
#define GL_ACCUM_ALPHA_BITS                 0x0D5B
#define GL_NAME_STACK_DEPTH                 0x0D70
#define GL_AUTO_NORMAL                      0x0D80
#define GL_MAP1_COLOR_4                     0x0D90
#define GL_MAP1_INDEX                       0x0D91
#define GL_MAP1_NORMAL                      0x0D92
#define GL_MAP1_TEXTURE_COORD_1             0x0D93
#define GL_MAP1_TEXTURE_COORD_2             0x0D94
#define GL_MAP1_TEXTURE_COORD_3             0x0D95
#define GL_MAP1_TEXTURE_COORD_4             0x0D96
#define GL_MAP1_VERTEX_3                    0x0D97
#define GL_MAP1_VERTEX_4                    0x0D98
#define GL_MAP2_COLOR_4                     0x0DB0
#define GL_MAP2_INDEX                       0x0DB1
#define GL_MAP2_NORMAL                      0x0DB2
#define GL_MAP2_TEXTURE_COORD_1             0x0DB3
#define GL_MAP2_TEXTURE_COORD_2             0x0DB4
#define GL_MAP2_TEXTURE_COORD_3             0x0DB5
#define GL_MAP2_TEXTURE_COORD_4             0x0DB6
#define GL_MAP2_VERTEX_3                    0x0DB7
#define GL_MAP2_VERTEX_4                    0x0DB8
#define GL_MAP1_GRID_DOMAIN                 0x0DD0
#define GL_MAP1_GRID_SEGMENTS               0x0DD1
#define GL_MAP2_GRID_DOMAIN                 0x0DD2
#define GL_MAP2_GRID_SEGMENTS               0x0DD3
#define GL_TEXTURE_1D                       0x0DE0
#define GL_TEXTURE_2D                       0x0DE1
#define GL_FEEDBACK_BUFFER_POINTER          0x0DF0
#define GL_FEEDBACK_BUFFER_SIZE             0x0DF1
#define GL_FEEDBACK_BUFFER_TYPE             0x0DF2
#define GL_SELECTION_BUFFER_POINTER         0x0DF3
#define GL_SELECTION_BUFFER_SIZE            0x0DF4
#define GL_TEXTURE_WIDTH                    0x1000
#define GL_TEXTURE_HEIGHT                   0x1001
#define GL_TEXTURE_INTERNAL_FORMAT          0x1003
#define GL_TEXTURE_BORDER_COLOR             0x1004
#define GL_TEXTURE_BORDER                   0x1005
#define GL_DONT_CARE                        0x1100
#define GL_FASTEST                          0x1101
#define GL_NICEST                           0x1102
#define GL_LIGHT0                           0x4000
#define GL_LIGHT1                           0x4001
#define GL_LIGHT2                           0x4002
#define GL_LIGHT3                           0x4003
#define GL_LIGHT4                           0x4004
#define GL_LIGHT5                           0x4005
#define GL_LIGHT6                           0x4006
#define GL_LIGHT7                           0x4007
#define GL_AMBIENT                          0x1200
#define GL_DIFFUSE                          0x1201
#define GL_SPECULAR                         0x1202
#define GL_POSITION                         0x1203
#define GL_SPOT_DIRECTION                   0x1204
#define GL_SPOT_EXPONENT                    0x1205
#define GL_SPOT_CUTOFF                      0x1206
#define GL_CONSTANT_ATTENUATION             0x1207
#define GL_LINEAR_ATTENUATION               0x1208
#define GL_QUADRATIC_ATTENUATION            0x1209
#define GL_COMPILE                          0x1300
#define GL_COMPILE_AND_EXECUTE              0x1301
#define GL_CLEAR                            0x1500
#define GL_AND                              0x1501
#define GL_AND_REVERSE                      0x1502
#define GL_COPY                             0x1503
#define GL_AND_INVERTED                     0x1504
#define GL_NOOP                             0x1505
#define GL_XOR                              0x1506
#define GL_OR                               0x1507
#define GL_NOR                              0x1508
#define GL_EQUIV                            0x1509
#define GL_INVERT                           0x150A
#define GL_OR_REVERSE                       0x150B
#define GL_COPY_INVERTED                    0x150C
#define GL_OR_INVERTED                      0x150D
#define GL_NAND                             0x150E
#define GL_SET                              0x150F
#define GL_EMISSION                         0x1600
#define GL_SHININESS                        0x1601
#define GL_AMBIENT_AND_DIFFUSE              0x1602
#define GL_COLOR_INDEXES                    0x1603
#define GL_MODELVIEW                        0x1700
#define GL_PROJECTION                       0x1701
#define GL_TEXTURE                          0x1702
#define GL_COLOR                            0x1800
#define GL_DEPTH                            0x1801
#define GL_STENCIL                          0x1802
#define GL_COLOR_INDEX                      0x1900
#define GL_STENCIL_INDEX                    0x1901
#define GL_DEPTH_COMPONENT                  0x1902
#define GL_RED                              0x1903
#define GL_GREEN                            0x1904
#define GL_BLUE                             0x1905
#define GL_ALPHA                            0x1906
#define GL_RGB                              0x1907
#define GL_RGBA                             0x1908
#define GL_LUMINANCE                        0x1909
#define GL_LUMINANCE_ALPHA                  0x190A
#define GL_BITMAP                           0x1A00
#define GL_POINT                            0x1B00
#define GL_LINE                             0x1B01
#define GL_FILL                             0x1B02
#define GL_RENDER                           0x1C00
#define GL_FEEDBACK                         0x1C01
#define GL_SELECT                           0x1C02
#define GL_FLAT                             0x1D00
#define GL_SMOOTH                           0x1D01
#define GL_KEEP                             0x1E00
#define GL_REPLACE                          0x1E01
#define GL_INCR                             0x1E02
#define GL_DECR                             0x1E03
#define GL_VENDOR                           0x1F00
#define GL_RENDERER                         0x1F01
#define GL_VERSION                          0x1F02
#define GL_EXTENSIONS                       0x1F03
#define GL_S                                0x2000
#define GL_T                                0x2001
#define GL_R                                0x2002
#define GL_Q                                0x2003
#define GL_MODULATE                         0x2100
#define GL_DECAL                            0x2101
#define GL_TEXTURE_ENV_MODE                 0x2200
#define GL_TEXTURE_ENV_COLOR                0x2201
#define GL_TEXTURE_ENV                      0x2300
#define GL_EYE_LINEAR                       0x2400
#define GL_OBJECT_LINEAR                    0x2401
#define GL_SPHERE_MAP                       0x2402
#define GL_TEXTURE_GEN_MODE                 0x2500
#define GL_OBJECT_PLANE                     0x2501
#define GL_EYE_PLANE                        0x2502
#define GL_NEAREST                          0x2600
#define GL_LINEAR                           0x2601
#define GL_NEAREST_MIPMAP_NEAREST           0x2700
#define GL_LINEAR_MIPMAP_NEAREST            0x2701
#define GL_NEAREST_MIPMAP_LINEAR            0x2702
#define GL_LINEAR_MIPMAP_LINEAR             0x2703
#define GL_TEXTURE_MAG_FILTER               0x2800
#define GL_TEXTURE_MIN_FILTER               0x2801
#define GL_TEXTURE_WRAP_S                   0x2802
#define GL_TEXTURE_WRAP_T                   0x2803
#define GL_CLAMP                            0x2900
#define GL_REPEAT                           0x2901
#define GL_CLIENT_PIXEL_STORE_BIT           0x00000001
#define GL_CLIENT_VERTEX_ARRAY_BIT          0x00000002
#define GL_CLIENT_ALL_ATTRIB_BITS           0xffffffff
#define GL_POLYGON_OFFSET_FACTOR            0x8038
#define GL_POLYGON_OFFSET_UNITS             0x2A00
#define GL_POLYGON_OFFSET_POINT             0x2A01
#define GL_POLYGON_OFFSET_LINE              0x2A02
#define GL_POLYGON_OFFSET_FILL              0x8037
#define GL_ALPHA4                           0x803B
#define GL_ALPHA8                           0x803C
#define GL_ALPHA12                          0x803D
#define GL_ALPHA16                          0x803E
#define GL_LUMINANCE4                       0x803F
#define GL_LUMINANCE8                       0x8040
#define GL_LUMINANCE12                      0x8041
#define GL_LUMINANCE16                      0x8042
#define GL_LUMINANCE4_ALPHA4                0x8043
#define GL_LUMINANCE6_ALPHA2                0x8044
#define GL_LUMINANCE8_ALPHA8                0x8045
#define GL_LUMINANCE12_ALPHA4               0x8046
#define GL_LUMINANCE12_ALPHA12              0x8047
#define GL_LUMINANCE16_ALPHA16              0x8048
#define GL_INTENSITY                        0x8049
#define GL_INTENSITY4                       0x804A
#define GL_INTENSITY8                       0x804B
#define GL_INTENSITY12                      0x804C
#define GL_INTENSITY16                      0x804D
#define GL_R3_G3_B2                         0x2A10
#define GL_RGB4                             0x804F
#define GL_RGB5                             0x8050
#define GL_RGB8                             0x8051
#define GL_RGB10                            0x8052
#define GL_RGB12                            0x8053
#define GL_RGB16                            0x8054
#define GL_RGBA2                            0x8055
#define GL_RGBA4                            0x8056
#define GL_RGB5_A1                          0x8057
#define GL_RGBA8                            0x8058
#define GL_RGB10_A2                         0x8059
#define GL_RGBA12                           0x805A
#define GL_RGBA16                           0x805B
#define GL_TEXTURE_RED_SIZE                 0x805C
#define GL_TEXTURE_GREEN_SIZE               0x805D
#define GL_TEXTURE_BLUE_SIZE                0x805E
#define GL_TEXTURE_ALPHA_SIZE               0x805F
#define GL_TEXTURE_LUMINANCE_SIZE           0x8060
#define GL_TEXTURE_INTENSITY_SIZE           0x8061
#define GL_PROXY_TEXTURE_1D                 0x8063
#define GL_PROXY_TEXTURE_2D                 0x8064
#define GL_TEXTURE_PRIORITY                 0x8066
#define GL_TEXTURE_RESIDENT                 0x8067
#define GL_TEXTURE_BINDING_1D               0x8068
#define GL_TEXTURE_BINDING_2D               0x8069
#define GL_VERTEX_ARRAY                     0x8074
#define GL_NORMAL_ARRAY                     0x8075
#define GL_COLOR_ARRAY                      0x8076
#define GL_INDEX_ARRAY                      0x8077
#define GL_TEXTURE_COORD_ARRAY              0x8078
#define GL_EDGE_FLAG_ARRAY                  0x8079
#define GL_VERTEX_ARRAY_SIZE                0x807A
#define GL_VERTEX_ARRAY_TYPE                0x807B
#define GL_VERTEX_ARRAY_STRIDE              0x807C
#define GL_NORMAL_ARRAY_TYPE                0x807E
#define GL_NORMAL_ARRAY_STRIDE              0x807F
#define GL_COLOR_ARRAY_SIZE                 0x8081
#define GL_COLOR_ARRAY_TYPE                 0x8082
#define GL_COLOR_ARRAY_STRIDE               0x8083
#define GL_INDEX_ARRAY_TYPE                 0x8085
#define GL_INDEX_ARRAY_STRIDE               0x8086
#define GL_TEXTURE_COORD_ARRAY_SIZE         0x8088
#define GL_TEXTURE_COORD_ARRAY_TYPE         0x8089
#define GL_TEXTURE_COORD_ARRAY_STRIDE       0x808A
#define GL_EDGE_FLAG_ARRAY_STRIDE           0x808C
#define GL_VERTEX_ARRAY_POINTER             0x808E
#define GL_NORMAL_ARRAY_POINTER             0x808F
#define GL_COLOR_ARRAY_POINTER              0x8090
#define GL_INDEX_ARRAY_POINTER              0x8091
#define GL_TEXTURE_COORD_ARRAY_POINTER      0x8092
#define GL_EDGE_FLAG_ARRAY_POINTER          0x8093
#define GL_V2F                              0x2A20
#define GL_V3F                              0x2A21
#define GL_C4UB_V2F                         0x2A22
#define GL_C4UB_V3F                         0x2A23
#define GL_C3F_V3F                          0x2A24
#define GL_N3F_V3F                          0x2A25
#define GL_C4F_N3F_V3F                      0x2A26
#define GL_T2F_V3F                          0x2A27
#define GL_T4F_V4F                          0x2A28
#define GL_T2F_C4UB_V3F                     0x2A29
#define GL_T2F_C3F_V3F                      0x2A2A
#define GL_T2F_N3F_V3F                      0x2A2B
#define GL_T2F_C4F_N3F_V3F                  0x2A2C
#define GL_T4F_C4F_N3F_V4F                  0x2A2D
#define GL_LOGIC_OP                         GL_INDEX_LOGIC_OP
#define GL_TEXTURE_COMPONENTS               GL_TEXTURE_INTERNAL_FORMAT
#define GL_COLOR_INDEX1_EXT                 0x80E2
#define GL_COLOR_INDEX2_EXT                 0x80E3
#define GL_COLOR_INDEX4_EXT                 0x80E4
#define GL_COLOR_INDEX8_EXT                 0x80E5
#define GL_COLOR_INDEX12_EXT                0x80E6
#define GL_COLOR_INDEX16_EXT                0x80E7
typedef unsigned int GLenum;
typedef unsigned char GLboolean;
typedef unsigned int GLbitfield;
typedef signed char GLbyte;
typedef short GLshort;
typedef int GLint;
typedef int GLsizei;
typedef unsigned char GLubyte;
typedef unsigned short GLushort;
typedef unsigned int GLuint;
typedef float GLfloat;
typedef float GLclampf;
typedef double GLdouble;
typedef double GLclampd;
typedef void GLvoid;
WINGDIAPI void APIENTRY glAccum (GLenum, GLfloat);
WINGDIAPI void APIENTRY glAlphaFunc (GLenum, GLclampf);
WINGDIAPI GLboolean APIENTRY glAreTexturesResident (GLsizei, const GLuint*, GLboolean*);
WINGDIAPI void APIENTRY glArrayElement (GLint);
WINGDIAPI void APIENTRY glBegin (GLenum);
WINGDIAPI void APIENTRY glBindTexture (GLenum, GLuint);
WINGDIAPI void APIENTRY glBitmap (GLsizei, GLsizei, GLfloat, GLfloat, GLfloat, GLfloat, const GLubyte*);
WINGDIAPI void APIENTRY glBlendFunc (GLenum, GLenum);
WINGDIAPI void APIENTRY glCallList (GLuint);
WINGDIAPI void APIENTRY glCallLists (GLsizei, GLenum, const GLvoid*);
WINGDIAPI void APIENTRY glClear (GLbitfield);
WINGDIAPI void APIENTRY glClearAccum (GLfloat, GLfloat, GLfloat, GLfloat);
WINGDIAPI void APIENTRY glClearColor (GLclampf, GLclampf, GLclampf, GLclampf);
WINGDIAPI void APIENTRY glClearDepth (GLclampd);
WINGDIAPI void APIENTRY glClearIndex (GLfloat);
WINGDIAPI void APIENTRY glClearStencil (GLint);
WINGDIAPI void APIENTRY glClipPlane (GLenum, const GLdouble*);
WINGDIAPI void APIENTRY glColor3b (GLbyte, GLbyte, GLbyte);
WINGDIAPI void APIENTRY glColor3bv (const GLbyte*);
WINGDIAPI void APIENTRY glColor3d (GLdouble, GLdouble, GLdouble);
WINGDIAPI void APIENTRY glColor3dv (const GLdouble*);
WINGDIAPI void APIENTRY glColor3f (GLfloat, GLfloat, GLfloat);
WINGDIAPI void APIENTRY glColor3fv (const GLfloat*);
WINGDIAPI void APIENTRY glColor3i (GLint, GLint, GLint);
WINGDIAPI void APIENTRY glColor3iv (const GLint*);
WINGDIAPI void APIENTRY glColor3s (GLshort, GLshort, GLshort);
WINGDIAPI void APIENTRY glColor3sv (const GLshort*);
WINGDIAPI void APIENTRY glColor3ub (GLubyte, GLubyte, GLubyte);
WINGDIAPI void APIENTRY glColor3ubv (const GLubyte*);
WINGDIAPI void APIENTRY glColor3ui (GLuint, GLuint, GLuint);
WINGDIAPI void APIENTRY glColor3uiv (const GLuint*);
WINGDIAPI void APIENTRY glColor3us (GLushort, GLushort, GLushort);
WINGDIAPI void APIENTRY glColor3usv (const GLushort*);
WINGDIAPI void APIENTRY glColor4b (GLbyte, GLbyte, GLbyte, GLbyte);
WINGDIAPI void APIENTRY glColor4bv (const GLbyte*);
WINGDIAPI void APIENTRY glColor4d (GLdouble, GLdouble, GLdouble, GLdouble);
WINGDIAPI void APIENTRY glColor4dv (const GLdouble*);
WINGDIAPI void APIENTRY glColor4f (GLfloat, GLfloat, GLfloat, GLfloat);
WINGDIAPI void APIENTRY glColor4fv (const GLfloat*);
WINGDIAPI void APIENTRY glColor4i (GLint, GLint, GLint, GLint);
WINGDIAPI void APIENTRY glColor4iv (const GLint*);
WINGDIAPI void APIENTRY glColor4s (GLshort, GLshort, GLshort, GLshort);
WINGDIAPI void APIENTRY glColor4sv (const GLshort*);
WINGDIAPI void APIENTRY glColor4ub (GLubyte, GLubyte, GLubyte, GLubyte);
WINGDIAPI void APIENTRY glColor4ubv (const GLubyte*);
WINGDIAPI void APIENTRY glColor4ui (GLuint, GLuint, GLuint, GLuint);
WINGDIAPI void APIENTRY glColor4uiv (const GLuint*);
WINGDIAPI void APIENTRY glColor4us (GLushort, GLushort, GLushort, GLushort);
WINGDIAPI void APIENTRY glColor4usv (const GLushort*);
WINGDIAPI void APIENTRY glColorMask (GLboolean, GLboolean, GLboolean, GLboolean);
WINGDIAPI void APIENTRY glColorMaterial (GLenum, GLenum);
WINGDIAPI void APIENTRY glColorPointer (GLint, GLenum, GLsizei, const GLvoid*);
WINGDIAPI void APIENTRY glCopyPixels (GLint, GLint, GLsizei, GLsizei, GLenum);
WINGDIAPI void APIENTRY glCopyTexImage1D (GLenum, GLint, GLenum, GLint, GLint, GLsizei, GLint);
WINGDIAPI void APIENTRY glCopyTexImage2D (GLenum, GLint, GLenum, GLint, GLint, GLsizei, GLsizei, GLint);
WINGDIAPI void APIENTRY glCopyTexSubImage1D (GLenum, GLint, GLint, GLint, GLint, GLsizei);
WINGDIAPI void APIENTRY glCopyTexSubImage2D (GLenum, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei);
WINGDIAPI void APIENTRY glCullFace (GLenum);
WINGDIAPI void APIENTRY glDeleteLists (GLuint, GLsizei);
WINGDIAPI void APIENTRY glDeleteTextures (GLsizei, const GLuint*);
WINGDIAPI void APIENTRY glDepthFunc (GLenum);
WINGDIAPI void APIENTRY glDepthMask (GLboolean);
WINGDIAPI void APIENTRY glDepthRange (GLclampd, GLclampd);
WINGDIAPI void APIENTRY glDisable (GLenum);
WINGDIAPI void APIENTRY glDisableClientState (GLenum);
WINGDIAPI void APIENTRY glDrawArrays (GLenum, GLint, GLsizei);
WINGDIAPI void APIENTRY glDrawBuffer (GLenum);
WINGDIAPI void APIENTRY glDrawElements (GLenum, GLsizei, GLenum, const GLvoid*);
WINGDIAPI void APIENTRY glDrawPixels (GLsizei, GLsizei, GLenum, GLenum, const GLvoid*);
WINGDIAPI void APIENTRY glEdgeFlag (GLboolean);
WINGDIAPI void APIENTRY glEdgeFlagPointer (GLsizei, const GLvoid*);
WINGDIAPI void APIENTRY glEdgeFlagv (const GLboolean*);
WINGDIAPI void APIENTRY glEnable (GLenum);
WINGDIAPI void APIENTRY glEnableClientState (GLenum);
WINGDIAPI void APIENTRY glEnd (void);
WINGDIAPI void APIENTRY glEndList (void);
WINGDIAPI void APIENTRY glEvalCoord1d (GLdouble);
WINGDIAPI void APIENTRY glEvalCoord1dv (const GLdouble*);
WINGDIAPI void APIENTRY glEvalCoord1f (GLfloat);
WINGDIAPI void APIENTRY glEvalCoord1fv (const GLfloat*);
WINGDIAPI void APIENTRY glEvalCoord2d (GLdouble, GLdouble);
WINGDIAPI void APIENTRY glEvalCoord2dv (const GLdouble*);
WINGDIAPI void APIENTRY glEvalCoord2f (GLfloat, GLfloat);
WINGDIAPI void APIENTRY glEvalCoord2fv (const GLfloat*);
WINGDIAPI void APIENTRY glEvalMesh1 (GLenum, GLint, GLint);
WINGDIAPI void APIENTRY glEvalMesh2 (GLenum, GLint, GLint, GLint, GLint);
WINGDIAPI void APIENTRY glEvalPoint1 (GLint);
WINGDIAPI void APIENTRY glEvalPoint2 (GLint, GLint);
WINGDIAPI void APIENTRY glFeedbackBuffer (GLsizei, GLenum, GLfloat*);
WINGDIAPI void APIENTRY glFinish (void);
WINGDIAPI void APIENTRY glFlush (void);
WINGDIAPI void APIENTRY glFogf (GLenum, GLfloat);
WINGDIAPI void APIENTRY glFogfv (GLenum, const GLfloat*);
WINGDIAPI void APIENTRY glFogi (GLenum, GLint);
WINGDIAPI void APIENTRY glFogiv (GLenum, const GLint*);
WINGDIAPI void APIENTRY glFrontFace (GLenum);
WINGDIAPI void APIENTRY glFrustum (GLdouble, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble);
WINGDIAPI GLuint APIENTRY glGenLists (GLsizei);
WINGDIAPI void APIENTRY glGenTextures (GLsizei, GLuint*);
WINGDIAPI void APIENTRY glGetBooleanv (GLenum, GLboolean*);
WINGDIAPI void APIENTRY glGetClipPlane (GLenum, GLdouble*);
WINGDIAPI void APIENTRY glGetDoublev (GLenum, GLdouble*);
WINGDIAPI GLenum APIENTRY glGetError (void);
WINGDIAPI void APIENTRY glGetFloatv (GLenum, GLfloat*);
WINGDIAPI void APIENTRY glGetIntegerv (GLenum, GLint*);
WINGDIAPI void APIENTRY glGetLightfv (GLenum, GLenum, GLfloat*);
WINGDIAPI void APIENTRY glGetLightiv (GLenum, GLenum, GLint*);
WINGDIAPI void APIENTRY glGetMapdv (GLenum, GLenum, GLdouble*);
WINGDIAPI void APIENTRY glGetMapfv (GLenum, GLenum, GLfloat*);
WINGDIAPI void APIENTRY glGetMapiv (GLenum, GLenum, GLint*);
WINGDIAPI void APIENTRY glGetMaterialfv (GLenum, GLenum, GLfloat*);
WINGDIAPI void APIENTRY glGetMaterialiv (GLenum, GLenum, GLint*);
WINGDIAPI void APIENTRY glGetPixelMapfv (GLenum, GLfloat*);
WINGDIAPI void APIENTRY glGetPixelMapuiv (GLenum, GLuint*);
WINGDIAPI void APIENTRY glGetPixelMapusv (GLenum, GLushort*);
WINGDIAPI void APIENTRY glGetPointerv (GLenum, GLvoid**);
WINGDIAPI void APIENTRY glGetPolygonStipple (GLubyte*);
WINGDIAPI const GLubyte* APIENTRY glGetString (GLenum);
WINGDIAPI void APIENTRY glGetTexEnvfv (GLenum, GLenum, GLfloat*);
WINGDIAPI void APIENTRY glGetTexEnviv (GLenum, GLenum, GLint*);
WINGDIAPI void APIENTRY glGetTexGendv (GLenum, GLenum, GLdouble*);
WINGDIAPI void APIENTRY glGetTexGenfv (GLenum, GLenum, GLfloat*);
WINGDIAPI void APIENTRY glGetTexGeniv (GLenum, GLenum, GLint*);
WINGDIAPI void APIENTRY glGetTexImage (GLenum, GLint, GLenum, GLenum, GLvoid*);
WINGDIAPI void APIENTRY glGetTexLevelParameterfv (GLenum, GLint, GLenum, GLfloat*);
WINGDIAPI void APIENTRY glGetTexLevelParameteriv (GLenum, GLint, GLenum, GLint*);
WINGDIAPI void APIENTRY glGetTexParameterfv (GLenum, GLenum, GLfloat*);
WINGDIAPI void APIENTRY glGetTexParameteriv (GLenum, GLenum, GLint*);
WINGDIAPI void APIENTRY glHint (GLenum, GLenum);
WINGDIAPI void APIENTRY glIndexMask (GLuint);
WINGDIAPI void APIENTRY glIndexPointer (GLenum, GLsizei, const GLvoid*);
WINGDIAPI void APIENTRY glIndexd (GLdouble);
WINGDIAPI void APIENTRY glIndexdv (const GLdouble*);
WINGDIAPI void APIENTRY glIndexf (GLfloat);
WINGDIAPI void APIENTRY glIndexfv (const GLfloat*);
WINGDIAPI void APIENTRY glIndexi (GLint);
WINGDIAPI void APIENTRY glIndexiv (const GLint*);
WINGDIAPI void APIENTRY glIndexs (GLshort);
WINGDIAPI void APIENTRY glIndexsv (const GLshort*);
WINGDIAPI void APIENTRY glIndexub (GLubyte);
WINGDIAPI void APIENTRY glIndexubv (const GLubyte*);
WINGDIAPI void APIENTRY glInitNames (void);
WINGDIAPI void APIENTRY glInterleavedArrays (GLenum, GLsizei, const GLvoid*);
WINGDIAPI GLboolean APIENTRY glIsEnabled (GLenum);
WINGDIAPI GLboolean APIENTRY glIsList (GLuint);
WINGDIAPI GLboolean APIENTRY glIsTexture (GLuint);
WINGDIAPI void APIENTRY glLightModelf (GLenum, GLfloat);
WINGDIAPI void APIENTRY glLightModelfv (GLenum, const GLfloat*);
WINGDIAPI void APIENTRY glLightModeli (GLenum, GLint);
WINGDIAPI void APIENTRY glLightModeliv (GLenum, const GLint*);
WINGDIAPI void APIENTRY glLightf (GLenum, GLenum, GLfloat);
WINGDIAPI void APIENTRY glLightfv (GLenum, GLenum, const GLfloat*);
WINGDIAPI void APIENTRY glLighti (GLenum, GLenum, GLint);
WINGDIAPI void APIENTRY glLightiv (GLenum, GLenum, const GLint*);
WINGDIAPI void APIENTRY glLineStipple (GLint, GLushort);
WINGDIAPI void APIENTRY glLineWidth (GLfloat);
WINGDIAPI void APIENTRY glListBase (GLuint);
WINGDIAPI void APIENTRY glLoadIdentity (void);
WINGDIAPI void APIENTRY glLoadMatrixd (const GLdouble*);
WINGDIAPI void APIENTRY glLoadMatrixf (const GLfloat*);
WINGDIAPI void APIENTRY glLoadName (GLuint);
WINGDIAPI void APIENTRY glLogicOp (GLenum);
WINGDIAPI void APIENTRY glMap1d (GLenum, GLdouble, GLdouble, GLint, GLint, const GLdouble*);
WINGDIAPI void APIENTRY glMap1f (GLenum, GLfloat, GLfloat, GLint, GLint, const GLfloat*);
WINGDIAPI void APIENTRY glMap2d (GLenum, GLdouble, GLdouble, GLint, GLint, GLdouble, GLdouble, GLint, GLint, const GLdouble*);
WINGDIAPI void APIENTRY glMap2f (GLenum, GLfloat, GLfloat, GLint, GLint, GLfloat, GLfloat, GLint, GLint, const GLfloat*);
WINGDIAPI void APIENTRY glMapGrid1d (GLint, GLdouble, GLdouble);
WINGDIAPI void APIENTRY glMapGrid1f (GLint, GLfloat, GLfloat);
WINGDIAPI void APIENTRY glMapGrid2d (GLint, GLdouble, GLdouble, GLint, GLdouble, GLdouble);
WINGDIAPI void APIENTRY glMapGrid2f (GLint, GLfloat, GLfloat, GLint, GLfloat, GLfloat);
WINGDIAPI void APIENTRY glMaterialf (GLenum, GLenum, GLfloat);
WINGDIAPI void APIENTRY glMaterialfv (GLenum, GLenum, const GLfloat*);
WINGDIAPI void APIENTRY glMateriali (GLenum, GLenum, GLint);
WINGDIAPI void APIENTRY glMaterialiv (GLenum, GLenum, const GLint*);
WINGDIAPI void APIENTRY glMatrixMode (GLenum);
WINGDIAPI void APIENTRY glMultMatrixd (const GLdouble*);
WINGDIAPI void APIENTRY glMultMatrixf (const GLfloat*);
WINGDIAPI void APIENTRY glNewList (GLuint, GLenum);
WINGDIAPI void APIENTRY glNormal3b (GLbyte, GLbyte, GLbyte);
WINGDIAPI void APIENTRY glNormal3bv (const GLbyte*);
WINGDIAPI void APIENTRY glNormal3d (GLdouble, GLdouble, GLdouble);
WINGDIAPI void APIENTRY glNormal3dv (const GLdouble*);
WINGDIAPI void APIENTRY glNormal3f (GLfloat, GLfloat, GLfloat);
WINGDIAPI void APIENTRY glNormal3fv (const GLfloat*);
WINGDIAPI void APIENTRY glNormal3i (GLint, GLint, GLint);
WINGDIAPI void APIENTRY glNormal3iv (const GLint*);
WINGDIAPI void APIENTRY glNormal3s (GLshort, GLshort, GLshort);
WINGDIAPI void APIENTRY glNormal3sv (const GLshort*);
WINGDIAPI void APIENTRY glNormalPointer (GLenum, GLsizei, const GLvoid*);
WINGDIAPI void APIENTRY glOrtho (GLdouble, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble);
WINGDIAPI void APIENTRY glPassThrough (GLfloat);
WINGDIAPI void APIENTRY glPixelMapfv (GLenum, GLsizei, const GLfloat*);
WINGDIAPI void APIENTRY glPixelMapuiv (GLenum, GLsizei, const GLuint*);
WINGDIAPI void APIENTRY glPixelMapusv (GLenum, GLsizei, const GLushort*);
WINGDIAPI void APIENTRY glPixelStoref (GLenum, GLfloat);
WINGDIAPI void APIENTRY glPixelStorei (GLenum, GLint);
WINGDIAPI void APIENTRY glPixelTransferf (GLenum, GLfloat);
WINGDIAPI void APIENTRY glPixelTransferi (GLenum, GLint);
WINGDIAPI void APIENTRY glPixelZoom (GLfloat, GLfloat);
WINGDIAPI void APIENTRY glPointSize (GLfloat);
WINGDIAPI void APIENTRY glPolygonMode (GLenum, GLenum);
WINGDIAPI void APIENTRY glPolygonOffset (GLfloat, GLfloat);
WINGDIAPI void APIENTRY glPolygonStipple (const GLubyte*);
WINGDIAPI void APIENTRY glPopAttrib (void);
WINGDIAPI void APIENTRY glPopClientAttrib (void);
WINGDIAPI void APIENTRY glPopMatrix (void);
WINGDIAPI void APIENTRY glPopName (void);
WINGDIAPI void APIENTRY glPrioritizeTextures (GLsizei, const GLuint*, const GLclampf*);
WINGDIAPI void APIENTRY glPushAttrib (GLbitfield);
WINGDIAPI void APIENTRY glPushClientAttrib (GLbitfield);
WINGDIAPI void APIENTRY glPushMatrix (void);
WINGDIAPI void APIENTRY glPushName (GLuint);
WINGDIAPI void APIENTRY glRasterPos2d (GLdouble, GLdouble);
WINGDIAPI void APIENTRY glRasterPos2dv (const GLdouble*);
WINGDIAPI void APIENTRY glRasterPos2f (GLfloat, GLfloat);
WINGDIAPI void APIENTRY glRasterPos2fv (const GLfloat*);
WINGDIAPI void APIENTRY glRasterPos2i (GLint, GLint);
WINGDIAPI void APIENTRY glRasterPos2iv (const GLint*);
WINGDIAPI void APIENTRY glRasterPos2s (GLshort, GLshort);
WINGDIAPI void APIENTRY glRasterPos2sv (const GLshort *);
WINGDIAPI void APIENTRY glRasterPos3d (GLdouble, GLdouble, GLdouble);
WINGDIAPI void APIENTRY glRasterPos3dv (const GLdouble*);
WINGDIAPI void APIENTRY glRasterPos3f (GLfloat, GLfloat, GLfloat);
WINGDIAPI void APIENTRY glRasterPos3fv (const GLfloat*);
WINGDIAPI void APIENTRY glRasterPos3i (GLint, GLint, GLint);
WINGDIAPI void APIENTRY glRasterPos3iv (const GLint*);
WINGDIAPI void APIENTRY glRasterPos3s (GLshort, GLshort, GLshort);
WINGDIAPI void APIENTRY glRasterPos3sv (const GLshort*);
WINGDIAPI void APIENTRY glRasterPos4d (GLdouble, GLdouble, GLdouble, GLdouble);
WINGDIAPI void APIENTRY glRasterPos4dv (const GLdouble*);
WINGDIAPI void APIENTRY glRasterPos4f (GLfloat, GLfloat, GLfloat, GLfloat);
WINGDIAPI void APIENTRY glRasterPos4fv (const GLfloat*);
WINGDIAPI void APIENTRY glRasterPos4i (GLint, GLint, GLint, GLint);
WINGDIAPI void APIENTRY glRasterPos4iv (const GLint*);
WINGDIAPI void APIENTRY glRasterPos4s (GLshort, GLshort, GLshort, GLshort);
WINGDIAPI void APIENTRY glRasterPos4sv (const GLshort*);
WINGDIAPI void APIENTRY glReadBuffer (GLenum);
WINGDIAPI void APIENTRY glReadPixels (GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, GLvoid*);
WINGDIAPI void APIENTRY glRectd (GLdouble, GLdouble, GLdouble, GLdouble);
WINGDIAPI void APIENTRY glRectdv (const GLdouble*, const GLdouble*);
WINGDIAPI void APIENTRY glRectf (GLfloat, GLfloat, GLfloat, GLfloat);
WINGDIAPI void APIENTRY glRectfv (const GLfloat*, const GLfloat*);
WINGDIAPI void APIENTRY glRecti (GLint, GLint, GLint, GLint);
WINGDIAPI void APIENTRY glRectiv (const GLint*, const GLint*);
WINGDIAPI void APIENTRY glRects (GLshort, GLshort, GLshort, GLshort);
WINGDIAPI void APIENTRY glRectsv (const GLshort*, const GLshort*);
WINGDIAPI GLint APIENTRY glRenderMode (GLenum);
WINGDIAPI void APIENTRY glRotated (GLdouble, GLdouble, GLdouble, GLdouble);
WINGDIAPI void APIENTRY glRotatef (GLfloat, GLfloat, GLfloat, GLfloat);
WINGDIAPI void APIENTRY glScaled (GLdouble, GLdouble, GLdouble);
WINGDIAPI void APIENTRY glScalef (GLfloat, GLfloat, GLfloat);
WINGDIAPI void APIENTRY glScissor (GLint, GLint, GLsizei, GLsizei);
WINGDIAPI void APIENTRY glSelectBuffer (GLsizei, GLuint*);
WINGDIAPI void APIENTRY glShadeModel (GLenum);
WINGDIAPI void APIENTRY glStencilFunc (GLenum, GLint, GLuint);
WINGDIAPI void APIENTRY glStencilMask (GLuint);
WINGDIAPI void APIENTRY glStencilOp (GLenum, GLenum, GLenum);
WINGDIAPI void APIENTRY glTexCoord1d (GLdouble);
WINGDIAPI void APIENTRY glTexCoord1dv (const GLdouble*);
WINGDIAPI void APIENTRY glTexCoord1f (GLfloat);
WINGDIAPI void APIENTRY glTexCoord1fv (const GLfloat*);
WINGDIAPI void APIENTRY glTexCoord1i (GLint);
WINGDIAPI void APIENTRY glTexCoord1iv (const GLint*);
WINGDIAPI void APIENTRY glTexCoord1s (GLshort);
WINGDIAPI void APIENTRY glTexCoord1sv (const GLshort*);
WINGDIAPI void APIENTRY glTexCoord2d (GLdouble, GLdouble);
WINGDIAPI void APIENTRY glTexCoord2dv (const GLdouble*);
WINGDIAPI void APIENTRY glTexCoord2f (GLfloat, GLfloat);
WINGDIAPI void APIENTRY glTexCoord2fv (const GLfloat*);
WINGDIAPI void APIENTRY glTexCoord2i (GLint, GLint);
WINGDIAPI void APIENTRY glTexCoord2iv (const GLint*);
WINGDIAPI void APIENTRY glTexCoord2s (GLshort, GLshort);
WINGDIAPI void APIENTRY glTexCoord2sv (const GLshort*);
WINGDIAPI void APIENTRY glTexCoord3d (GLdouble, GLdouble, GLdouble);
WINGDIAPI void APIENTRY glTexCoord3dv (const GLdouble*);
WINGDIAPI void APIENTRY glTexCoord3f (GLfloat, GLfloat, GLfloat);
WINGDIAPI void APIENTRY glTexCoord3fv (const GLfloat*);
WINGDIAPI void APIENTRY glTexCoord3i (GLint, GLint, GLint);
WINGDIAPI void APIENTRY glTexCoord3iv (const GLint*);
WINGDIAPI void APIENTRY glTexCoord3s (GLshort, GLshort, GLshort);
WINGDIAPI void APIENTRY glTexCoord3sv (const GLshort*);
WINGDIAPI void APIENTRY glTexCoord4d (GLdouble, GLdouble, GLdouble, GLdouble);
WINGDIAPI void APIENTRY glTexCoord4dv (const GLdouble*);
WINGDIAPI void APIENTRY glTexCoord4f (GLfloat, GLfloat, GLfloat, GLfloat);
WINGDIAPI void APIENTRY glTexCoord4fv (const GLfloat*);
WINGDIAPI void APIENTRY glTexCoord4i (GLint, GLint, GLint, GLint);
WINGDIAPI void APIENTRY glTexCoord4iv (const GLint*);
WINGDIAPI void APIENTRY glTexCoord4s (GLshort, GLshort, GLshort, GLshort);
WINGDIAPI void APIENTRY glTexCoord4sv (const GLshort*);
WINGDIAPI void APIENTRY glTexCoordPointer (GLint, GLenum, GLsizei, const GLvoid*);
WINGDIAPI void APIENTRY glTexEnvf (GLenum, GLenum, GLfloat);
WINGDIAPI void APIENTRY glTexEnvfv (GLenum, GLenum, const GLfloat*);
WINGDIAPI void APIENTRY glTexEnvi (GLenum, GLenum, GLint);
WINGDIAPI void APIENTRY glTexEnviv (GLenum, GLenum, const GLint*);
WINGDIAPI void APIENTRY glTexGend (GLenum, GLenum, GLdouble);
WINGDIAPI void APIENTRY glTexGendv (GLenum, GLenum, const GLdouble*);
WINGDIAPI void APIENTRY glTexGenf (GLenum, GLenum, GLfloat);
WINGDIAPI void APIENTRY glTexGenfv (GLenum, GLenum, const GLfloat*);
WINGDIAPI void APIENTRY glTexGeni (GLenum, GLenum, GLint);
WINGDIAPI void APIENTRY glTexGeniv (GLenum, GLenum, const GLint*);
WINGDIAPI void APIENTRY glTexImage1D (GLenum, GLint, GLint, GLsizei, GLint, GLenum, GLenum, const GLvoid*);
WINGDIAPI void APIENTRY glTexImage2D (GLenum, GLint, GLint, GLsizei, GLsizei, GLint, GLenum, GLenum, const GLvoid*);
WINGDIAPI void APIENTRY glTexParameterf (GLenum, GLenum, GLfloat);
WINGDIAPI void APIENTRY glTexParameterfv (GLenum, GLenum, const GLfloat*);
WINGDIAPI void APIENTRY glTexParameteri (GLenum, GLenum, GLint);
WINGDIAPI void APIENTRY glTexParameteriv (GLenum, GLenum, const GLint*);
WINGDIAPI void APIENTRY glTexSubImage1D (GLenum, GLint, GLint, GLsizei, GLenum, GLenum, const GLvoid*);
WINGDIAPI void APIENTRY glTexSubImage2D (GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, const GLvoid*);
WINGDIAPI void APIENTRY glTranslated (GLdouble, GLdouble, GLdouble);
WINGDIAPI void APIENTRY glTranslatef (GLfloat, GLfloat, GLfloat);
WINGDIAPI void APIENTRY glVertex2d (GLdouble, GLdouble);
WINGDIAPI void APIENTRY glVertex2dv (const GLdouble*);
WINGDIAPI void APIENTRY glVertex2f (GLfloat, GLfloat);
WINGDIAPI void APIENTRY glVertex2fv (const GLfloat*);
WINGDIAPI void APIENTRY glVertex2i (GLint, GLint);
WINGDIAPI void APIENTRY glVertex2iv (const GLint*);
WINGDIAPI void APIENTRY glVertex2s (GLshort, GLshort);
WINGDIAPI void APIENTRY glVertex2sv (const GLshort*);
WINGDIAPI void APIENTRY glVertex3d (GLdouble, GLdouble, GLdouble);
WINGDIAPI void APIENTRY glVertex3dv (const GLdouble*);
WINGDIAPI void APIENTRY glVertex3f (GLfloat, GLfloat, GLfloat);
WINGDIAPI void APIENTRY glVertex3fv (const GLfloat*);
WINGDIAPI void APIENTRY glVertex3i (GLint, GLint, GLint);
WINGDIAPI void APIENTRY glVertex3iv (const GLint*);
WINGDIAPI void APIENTRY glVertex3s (GLshort, GLshort, GLshort);
WINGDIAPI void APIENTRY glVertex3sv (const GLshort*);
WINGDIAPI void APIENTRY glVertex4d (GLdouble, GLdouble, GLdouble, GLdouble);
WINGDIAPI void APIENTRY glVertex4dv (const GLdouble*);
WINGDIAPI void APIENTRY glVertex4f (GLfloat, GLfloat, GLfloat, GLfloat);
WINGDIAPI void APIENTRY glVertex4fv (const GLfloat*);
WINGDIAPI void APIENTRY glVertex4i (GLint, GLint, GLint, GLint);
WINGDIAPI void APIENTRY glVertex4iv (const GLint*);
WINGDIAPI void APIENTRY glVertex4s (GLshort, GLshort, GLshort, GLshort);
WINGDIAPI void APIENTRY glVertex4sv (const GLshort*);
WINGDIAPI void APIENTRY glVertexPointer (GLint, GLenum, GLsizei, const GLvoid*);
WINGDIAPI void APIENTRY glViewport (GLint, GLint, GLsizei, GLsizei);
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_VERSION_1_2;
WM3_EXTERN int Wm3NumFunctions_GL_VERSION_1_2;
#ifndef GL_VERSION_1_2
#define GL_VERSION_1_2
#define WM3_DEFINED_GL_VERSION_1_2
#define GL_UNSIGNED_BYTE_3_3_2            0x8032
#define GL_UNSIGNED_SHORT_4_4_4_4         0x8033
#define GL_UNSIGNED_SHORT_5_5_5_1         0x8034
#define GL_UNSIGNED_INT_8_8_8_8           0x8035
#define GL_UNSIGNED_INT_10_10_10_2        0x8036
#define GL_RESCALE_NORMAL                 0x803A
#define GL_TEXTURE_BINDING_3D             0x806A
#define GL_PACK_SKIP_IMAGES               0x806B
#define GL_PACK_IMAGE_HEIGHT              0x806C
#define GL_UNPACK_SKIP_IMAGES             0x806D
#define GL_UNPACK_IMAGE_HEIGHT            0x806E
#define GL_TEXTURE_3D                     0x806F
#define GL_PROXY_TEXTURE_3D               0x8070
#define GL_TEXTURE_DEPTH                  0x8071
#define GL_TEXTURE_WRAP_R                 0x8072
#define GL_MAX_3D_TEXTURE_SIZE            0x8073
#define GL_UNSIGNED_BYTE_2_3_3_REV        0x8362
#define GL_UNSIGNED_SHORT_5_6_5           0x8363
#define GL_UNSIGNED_SHORT_5_6_5_REV       0x8364
#define GL_UNSIGNED_SHORT_4_4_4_4_REV     0x8365
#define GL_UNSIGNED_SHORT_1_5_5_5_REV     0x8366
#define GL_UNSIGNED_INT_8_8_8_8_REV       0x8367
#define GL_UNSIGNED_INT_2_10_10_10_REV    0x8368
#define GL_BGR                            0x80E0
#define GL_BGRA                           0x80E1
#define GL_MAX_ELEMENTS_VERTICES          0x80E8
#define GL_MAX_ELEMENTS_INDICES           0x80E9
#define GL_CLAMP_TO_EDGE                  0x812F
#define GL_TEXTURE_MIN_LOD                0x813A
#define GL_TEXTURE_MAX_LOD                0x813B
#define GL_TEXTURE_BASE_LEVEL             0x813C
#define GL_TEXTURE_MAX_LEVEL              0x813D
#define GL_LIGHT_MODEL_COLOR_CONTROL      0x81F8
#define GL_SINGLE_COLOR                   0x81F9
#define GL_SEPARATE_SPECULAR_COLOR        0x81FA
#define GL_SMOOTH_POINT_SIZE_RANGE        0x0B12
#define GL_SMOOTH_POINT_SIZE_GRANULARITY  0x0B13
#define GL_SMOOTH_LINE_WIDTH_RANGE        0x0B22
#define GL_SMOOTH_LINE_WIDTH_GRANULARITY  0x0B23
#define GL_ALIASED_POINT_SIZE_RANGE       0x846D
#define GL_ALIASED_LINE_WIDTH_RANGE       0x846E

typedef void (APIENTRY* pfn_glBlendColor) (GLclampf, GLclampf, GLclampf, GLclampf);
WM3_EXTERN pfn_glBlendColor Wm3glBlendColor;
#define glBlendColor Wm3glBlendColor

typedef void (APIENTRY* pfn_glBlendEquation) (GLenum);
WM3_EXTERN pfn_glBlendEquation Wm3glBlendEquation;
#define glBlendEquation Wm3glBlendEquation

typedef void (APIENTRY* pfn_glDrawRangeElements) (GLenum, GLuint, GLuint, GLsizei, GLenum, const GLvoid*);
WM3_EXTERN pfn_glDrawRangeElements Wm3glDrawRangeElements;
#define glDrawRangeElements Wm3glDrawRangeElements

typedef void (APIENTRY* pfn_glColorTable) (GLenum, GLenum, GLsizei, GLenum, GLenum, const GLvoid*);
WM3_EXTERN pfn_glColorTable Wm3glColorTable;
#define glColorTable Wm3glColorTable

typedef void (APIENTRY* pfn_glColorTableParameterfv) (GLenum, GLenum, const GLfloat*);
WM3_EXTERN pfn_glColorTableParameterfv Wm3glColorTableParameterfv;
#define glColorTableParameterfv Wm3glColorTableParameterfv

typedef void (APIENTRY* pfn_glColorTableParameteriv) (GLenum, GLenum, const GLint*);
WM3_EXTERN pfn_glColorTableParameteriv Wm3glColorTableParameteriv;
#define glColorTableParameteriv Wm3glColorTableParameteriv

typedef void (APIENTRY* pfn_glCopyColorTable) (GLenum, GLenum, GLint, GLint, GLsizei);
WM3_EXTERN pfn_glCopyColorTable Wm3glCopyColorTable;
#define glCopyColorTable Wm3glCopyColorTable

typedef void (APIENTRY* pfn_glGetColorTable) (GLenum, GLenum, GLenum, GLvoid*);
WM3_EXTERN pfn_glGetColorTable Wm3glGetColorTable;
#define glGetColorTable Wm3glGetColorTable

typedef void (APIENTRY* pfn_glGetColorTableParameterfv) (GLenum, GLenum, GLfloat*);
WM3_EXTERN pfn_glGetColorTableParameterfv Wm3glGetColorTableParameterfv;
#define glGetColorTableParameterfv Wm3glGetColorTableParameterfv

typedef void (APIENTRY* pfn_glGetColorTableParameteriv) (GLenum, GLenum, GLint*);
WM3_EXTERN pfn_glGetColorTableParameteriv Wm3glGetColorTableParameteriv;
#define glGetColorTableParameteriv Wm3glGetColorTableParameteriv

typedef void (APIENTRY* pfn_glColorSubTable) (GLenum, GLsizei, GLsizei, GLenum, GLenum, const GLvoid*);
WM3_EXTERN pfn_glColorSubTable Wm3glColorSubTable;
#define glColorSubTable Wm3glColorSubTable

typedef void (APIENTRY* pfn_glCopyColorSubTable) (GLenum, GLsizei, GLint, GLint, GLsizei);
WM3_EXTERN pfn_glCopyColorSubTable Wm3glCopyColorSubTable;
#define glCopyColorSubTable Wm3glCopyColorSubTable

typedef void (APIENTRY* pfn_glConvolutionFilter1D) (GLenum, GLenum, GLsizei, GLenum, GLenum, const GLvoid*);
WM3_EXTERN pfn_glConvolutionFilter1D Wm3glConvolutionFilter1D;
#define glConvolutionFilter1D Wm3glConvolutionFilter1D

typedef void (APIENTRY* pfn_glConvolutionFilter2D) (GLenum, GLenum, GLsizei, GLsizei, GLenum, GLenum, const GLvoid*);
WM3_EXTERN pfn_glConvolutionFilter2D Wm3glConvolutionFilter2D;
#define glConvolutionFilter2D Wm3glConvolutionFilter2D

typedef void (APIENTRY* pfn_glConvolutionParameterf) (GLenum, GLenum, GLfloat);
WM3_EXTERN pfn_glConvolutionParameterf Wm3glConvolutionParameterf;
#define glConvolutionParameterf Wm3glConvolutionParameterf

typedef void (APIENTRY* pfn_glConvolutionParameterfv) (GLenum, GLenum, const GLfloat*);
WM3_EXTERN pfn_glConvolutionParameterfv Wm3glConvolutionParameterfv;
#define glConvolutionParameterfv Wm3glConvolutionParameterfv

typedef void (APIENTRY* pfn_glConvolutionParameteri) (GLenum, GLenum, GLint);
WM3_EXTERN pfn_glConvolutionParameteri Wm3glConvolutionParameteri;
#define glConvolutionParameteri Wm3glConvolutionParameteri

typedef void (APIENTRY* pfn_glConvolutionParameteriv) (GLenum, GLenum, const GLint*);
WM3_EXTERN pfn_glConvolutionParameteriv Wm3glConvolutionParameteriv;
#define glConvolutionParameteriv Wm3glConvolutionParameteriv

typedef void (APIENTRY* pfn_glCopyConvolutionFilter1D) (GLenum, GLenum, GLint, GLint, GLsizei);
WM3_EXTERN pfn_glCopyConvolutionFilter1D Wm3glCopyConvolutionFilter1D;
#define glCopyConvolutionFilter1D Wm3glCopyConvolutionFilter1D

typedef void (APIENTRY* pfn_glCopyConvolutionFilter2D) (GLenum, GLenum, GLint, GLint, GLsizei, GLsizei);
WM3_EXTERN pfn_glCopyConvolutionFilter2D Wm3glCopyConvolutionFilter2D;
#define glCopyConvolutionFilter2D Wm3glCopyConvolutionFilter2D

typedef void (APIENTRY* pfn_glGetConvolutionFilter) (GLenum, GLenum, GLenum, GLvoid*);
WM3_EXTERN pfn_glGetConvolutionFilter Wm3glGetConvolutionFilter;
#define glGetConvolutionFilter Wm3glGetConvolutionFilter

typedef void (APIENTRY* pfn_glGetConvolutionParameterfv) (GLenum, GLenum, GLfloat*);
WM3_EXTERN pfn_glGetConvolutionParameterfv Wm3glGetConvolutionParameterfv;
#define glGetConvolutionParameterfv Wm3glGetConvolutionParameterfv

typedef void (APIENTRY* pfn_glGetConvolutionParameteriv) (GLenum, GLenum, GLint*);
WM3_EXTERN pfn_glGetConvolutionParameteriv Wm3glGetConvolutionParameteriv;
#define glGetConvolutionParameteriv Wm3glGetConvolutionParameteriv

typedef void (APIENTRY* pfn_glGetSeparableFilter) (GLenum, GLenum, GLenum, GLvoid*, GLvoid*, GLvoid*);
WM3_EXTERN pfn_glGetSeparableFilter Wm3glGetSeparableFilter;
#define glGetSeparableFilter Wm3glGetSeparableFilter

typedef void (APIENTRY* pfn_glSeparableFilter2D) (GLenum, GLenum, GLsizei, GLsizei, GLenum, GLenum, const GLvoid*, const GLvoid*);
WM3_EXTERN pfn_glSeparableFilter2D Wm3glSeparableFilter2D;
#define glSeparableFilter2D Wm3glSeparableFilter2D

typedef void (APIENTRY* pfn_glGetHistogram) (GLenum, GLboolean, GLenum, GLenum, GLvoid*);
WM3_EXTERN pfn_glGetHistogram Wm3glGetHistogram;
#define glGetHistogram Wm3glGetHistogram

typedef void (APIENTRY* pfn_glGetHistogramParameterfv) (GLenum, GLenum, GLfloat*);
WM3_EXTERN pfn_glGetHistogramParameterfv Wm3glGetHistogramParameterfv;
#define glGetHistogramParameterfv Wm3glGetHistogramParameterfv

typedef void (APIENTRY* pfn_glGetHistogramParameteriv) (GLenum, GLenum, GLint*);
WM3_EXTERN pfn_glGetHistogramParameteriv Wm3glGetHistogramParameteriv;
#define glGetHistogramParameteriv Wm3glGetHistogramParameteriv

typedef void (APIENTRY* pfn_glGetMinmax) (GLenum, GLboolean, GLenum, GLenum, GLvoid*);
WM3_EXTERN pfn_glGetMinmax Wm3glGetMinmax;
#define glGetMinmax Wm3glGetMinmax

typedef void (APIENTRY* pfn_glGetMinmaxParameterfv) (GLenum, GLenum, GLfloat*);
WM3_EXTERN pfn_glGetMinmaxParameterfv Wm3glGetMinmaxParameterfv;
#define glGetMinmaxParameterfv Wm3glGetMinmaxParameterfv

typedef void (APIENTRY* pfn_glGetMinmaxParameteriv) (GLenum, GLenum, GLint*);
WM3_EXTERN pfn_glGetMinmaxParameteriv Wm3glGetMinmaxParameteriv;
#define glGetMinmaxParameteriv Wm3glGetMinmaxParameteriv

typedef void (APIENTRY* pfn_glHistogram) (GLenum, GLsizei, GLenum, GLboolean);
WM3_EXTERN pfn_glHistogram Wm3glHistogram;
#define glHistogram Wm3glHistogram

typedef void (APIENTRY* pfn_glMinmax) (GLenum, GLenum, GLboolean);
WM3_EXTERN pfn_glMinmax Wm3glMinmax;
#define glMinmax Wm3glMinmax

typedef void (APIENTRY* pfn_glResetHistogram) (GLenum);
WM3_EXTERN pfn_glResetHistogram Wm3glResetHistogram;
#define glResetHistogram Wm3glResetHistogram

typedef void (APIENTRY* pfn_glResetMinmax) (GLenum);
WM3_EXTERN pfn_glResetMinmax Wm3glResetMinmax;
#define glResetMinmax Wm3glResetMinmax

typedef void (APIENTRY* pfn_glTexImage3D) (GLenum, GLint, GLint, GLsizei, GLsizei, GLsizei, GLint, GLenum, GLenum, const GLvoid*);
WM3_EXTERN pfn_glTexImage3D Wm3glTexImage3D;
#define glTexImage3D Wm3glTexImage3D

typedef void (APIENTRY* pfn_glTexSubImage3D) (GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLenum, const GLvoid*);
WM3_EXTERN pfn_glTexSubImage3D Wm3glTexSubImage3D;
#define glTexSubImage3D Wm3glTexSubImage3D

typedef void (APIENTRY* pfn_glCopyTexSubImage3D) (GLenum, GLint, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei);
WM3_EXTERN pfn_glCopyTexSubImage3D Wm3glCopyTexSubImage3D;
#define glCopyTexSubImage3D Wm3glCopyTexSubImage3D
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_VERSION_1_3;
WM3_EXTERN int Wm3NumFunctions_GL_VERSION_1_3;
#ifndef GL_VERSION_1_3
#define GL_VERSION_1_3
#define WM3_DEFINED_GL_VERSION_1_3
#define GL_TEXTURE0                       0x84C0
#define GL_TEXTURE1                       0x84C1
#define GL_TEXTURE2                       0x84C2
#define GL_TEXTURE3                       0x84C3
#define GL_TEXTURE4                       0x84C4
#define GL_TEXTURE5                       0x84C5
#define GL_TEXTURE6                       0x84C6
#define GL_TEXTURE7                       0x84C7
#define GL_TEXTURE8                       0x84C8
#define GL_TEXTURE9                       0x84C9
#define GL_TEXTURE10                      0x84CA
#define GL_TEXTURE11                      0x84CB
#define GL_TEXTURE12                      0x84CC
#define GL_TEXTURE13                      0x84CD
#define GL_TEXTURE14                      0x84CE
#define GL_TEXTURE15                      0x84CF
#define GL_TEXTURE16                      0x84D0
#define GL_TEXTURE17                      0x84D1
#define GL_TEXTURE18                      0x84D2
#define GL_TEXTURE19                      0x84D3
#define GL_TEXTURE20                      0x84D4
#define GL_TEXTURE21                      0x84D5
#define GL_TEXTURE22                      0x84D6
#define GL_TEXTURE23                      0x84D7
#define GL_TEXTURE24                      0x84D8
#define GL_TEXTURE25                      0x84D9
#define GL_TEXTURE26                      0x84DA
#define GL_TEXTURE27                      0x84DB
#define GL_TEXTURE28                      0x84DC
#define GL_TEXTURE29                      0x84DD
#define GL_TEXTURE30                      0x84DE
#define GL_TEXTURE31                      0x84DF
#define GL_ACTIVE_TEXTURE                 0x84E0
#define GL_CLIENT_ACTIVE_TEXTURE          0x84E1
#define GL_MAX_TEXTURE_UNITS              0x84E2
#define GL_TRANSPOSE_MODELVIEW_MATRIX     0x84E3
#define GL_TRANSPOSE_PROJECTION_MATRIX    0x84E4
#define GL_TRANSPOSE_TEXTURE_MATRIX       0x84E5
#define GL_TRANSPOSE_COLOR_MATRIX         0x84E6
#define GL_MULTISAMPLE                    0x809D
#define GL_SAMPLE_ALPHA_TO_COVERAGE       0x809E
#define GL_SAMPLE_ALPHA_TO_ONE            0x809F
#define GL_SAMPLE_COVERAGE                0x80A0
#define GL_SAMPLE_BUFFERS                 0x80A8
#define GL_SAMPLES                        0x80A9
#define GL_SAMPLE_COVERAGE_VALUE          0x80AA
#define GL_SAMPLE_COVERAGE_INVERT         0x80AB
#define GL_MULTISAMPLE_BIT                0x20000000
#define GL_NORMAL_MAP                     0x8511
#define GL_REFLECTION_MAP                 0x8512
#define GL_TEXTURE_CUBE_MAP               0x8513
#define GL_TEXTURE_BINDING_CUBE_MAP       0x8514
#define GL_TEXTURE_CUBE_MAP_POSITIVE_X    0x8515
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_X    0x8516
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Y    0x8517
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Y    0x8518
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Z    0x8519
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Z    0x851A
#define GL_PROXY_TEXTURE_CUBE_MAP         0x851B
#define GL_MAX_CUBE_MAP_TEXTURE_SIZE      0x851C
#define GL_COMPRESSED_ALPHA               0x84E9
#define GL_COMPRESSED_LUMINANCE           0x84EA
#define GL_COMPRESSED_LUMINANCE_ALPHA     0x84EB
#define GL_COMPRESSED_INTENSITY           0x84EC
#define GL_COMPRESSED_RGB                 0x84ED
#define GL_COMPRESSED_RGBA                0x84EE
#define GL_TEXTURE_COMPRESSION_HINT       0x84EF
#define GL_TEXTURE_COMPRESSED_IMAGE_SIZE  0x86A0
#define GL_TEXTURE_COMPRESSED             0x86A1
#define GL_NUM_COMPRESSED_TEXTURE_FORMATS 0x86A2
#define GL_COMPRESSED_TEXTURE_FORMATS     0x86A3
#define GL_CLAMP_TO_BORDER                0x812D
#define GL_COMBINE                        0x8570
#define GL_COMBINE_RGB                    0x8571
#define GL_COMBINE_ALPHA                  0x8572
#define GL_SOURCE0_RGB                    0x8580
#define GL_SOURCE1_RGB                    0x8581
#define GL_SOURCE2_RGB                    0x8582
#define GL_SOURCE0_ALPHA                  0x8588
#define GL_SOURCE1_ALPHA                  0x8589
#define GL_SOURCE2_ALPHA                  0x858A
#define GL_OPERAND0_RGB                   0x8590
#define GL_OPERAND1_RGB                   0x8591
#define GL_OPERAND2_RGB                   0x8592
#define GL_OPERAND0_ALPHA                 0x8598
#define GL_OPERAND1_ALPHA                 0x8599
#define GL_OPERAND2_ALPHA                 0x859A
#define GL_RGB_SCALE                      0x8573
#define GL_ADD_SIGNED                     0x8574
#define GL_INTERPOLATE                    0x8575
#define GL_SUBTRACT                       0x84E7
#define GL_CONSTANT                       0x8576
#define GL_PRIMARY_COLOR                  0x8577
#define GL_PREVIOUS                       0x8578
#define GL_DOT3_RGB                       0x86AE
#define GL_DOT3_RGBA                      0x86AF

typedef void (APIENTRY* pfn_glActiveTexture) (GLenum);
WM3_EXTERN pfn_glActiveTexture Wm3glActiveTexture;
#define glActiveTexture Wm3glActiveTexture

typedef void (APIENTRY* pfn_glClientActiveTexture) (GLenum);
WM3_EXTERN pfn_glClientActiveTexture Wm3glClientActiveTexture;
#define glClientActiveTexture Wm3glClientActiveTexture

typedef void (APIENTRY* pfn_glMultiTexCoord1d) (GLenum, GLdouble);
WM3_EXTERN pfn_glMultiTexCoord1d Wm3glMultiTexCoord1d;
#define glMultiTexCoord1d Wm3glMultiTexCoord1d

typedef void (APIENTRY* pfn_glMultiTexCoord1dv) (GLenum, const GLdouble*);
WM3_EXTERN pfn_glMultiTexCoord1dv Wm3glMultiTexCoord1dv;
#define glMultiTexCoord1dv Wm3glMultiTexCoord1dv

typedef void (APIENTRY* pfn_glMultiTexCoord1f) (GLenum, GLfloat);
WM3_EXTERN pfn_glMultiTexCoord1f Wm3glMultiTexCoord1f;
#define glMultiTexCoord1f Wm3glMultiTexCoord1f

typedef void (APIENTRY* pfn_glMultiTexCoord1fv) (GLenum, const GLfloat*);
WM3_EXTERN pfn_glMultiTexCoord1fv Wm3glMultiTexCoord1fv;
#define glMultiTexCoord1fv Wm3glMultiTexCoord1fv

typedef void (APIENTRY* pfn_glMultiTexCoord1i) (GLenum, GLint);
WM3_EXTERN pfn_glMultiTexCoord1i Wm3glMultiTexCoord1i;
#define glMultiTexCoord1i Wm3glMultiTexCoord1i

typedef void (APIENTRY* pfn_glMultiTexCoord1iv) (GLenum, const GLint*);
WM3_EXTERN pfn_glMultiTexCoord1iv Wm3glMultiTexCoord1iv;
#define glMultiTexCoord1iv Wm3glMultiTexCoord1iv

typedef void (APIENTRY* pfn_glMultiTexCoord1s) (GLenum, GLshort);
WM3_EXTERN pfn_glMultiTexCoord1s Wm3glMultiTexCoord1s;
#define glMultiTexCoord1s Wm3glMultiTexCoord1s

typedef void (APIENTRY* pfn_glMultiTexCoord1sv) (GLenum, const GLshort*);
WM3_EXTERN pfn_glMultiTexCoord1sv Wm3glMultiTexCoord1sv;
#define glMultiTexCoord1sv Wm3glMultiTexCoord1sv

typedef void (APIENTRY* pfn_glMultiTexCoord2d) (GLenum, GLdouble, GLdouble);
WM3_EXTERN pfn_glMultiTexCoord2d Wm3glMultiTexCoord2d;
#define glMultiTexCoord2d Wm3glMultiTexCoord2d

typedef void (APIENTRY* pfn_glMultiTexCoord2dv) (GLenum, const GLdouble*);
WM3_EXTERN pfn_glMultiTexCoord2dv Wm3glMultiTexCoord2dv;
#define glMultiTexCoord2dv Wm3glMultiTexCoord2dv

typedef void (APIENTRY* pfn_glMultiTexCoord2f) (GLenum, GLfloat, GLfloat);
WM3_EXTERN pfn_glMultiTexCoord2f Wm3glMultiTexCoord2f;
#define glMultiTexCoord2f Wm3glMultiTexCoord2f

typedef void (APIENTRY* pfn_glMultiTexCoord2fv) (GLenum, const GLfloat*);
WM3_EXTERN pfn_glMultiTexCoord2fv Wm3glMultiTexCoord2fv;
#define glMultiTexCoord2fv Wm3glMultiTexCoord2fv

typedef void (APIENTRY* pfn_glMultiTexCoord2i) (GLenum, GLint, GLint);
WM3_EXTERN pfn_glMultiTexCoord2i Wm3glMultiTexCoord2i;
#define glMultiTexCoord2i Wm3glMultiTexCoord2i

typedef void (APIENTRY* pfn_glMultiTexCoord2iv) (GLenum, const GLint*);
WM3_EXTERN pfn_glMultiTexCoord2iv Wm3glMultiTexCoord2iv;
#define glMultiTexCoord2iv Wm3glMultiTexCoord2iv

typedef void (APIENTRY* pfn_glMultiTexCoord2s) (GLenum, GLshort, GLshort);
WM3_EXTERN pfn_glMultiTexCoord2s Wm3glMultiTexCoord2s;
#define glMultiTexCoord2s Wm3glMultiTexCoord2s

typedef void (APIENTRY* pfn_glMultiTexCoord2sv) (GLenum, const GLshort*);
WM3_EXTERN pfn_glMultiTexCoord2sv Wm3glMultiTexCoord2sv;
#define glMultiTexCoord2sv Wm3glMultiTexCoord2sv

typedef void (APIENTRY* pfn_glMultiTexCoord3d) (GLenum, GLdouble, GLdouble, GLdouble);
WM3_EXTERN pfn_glMultiTexCoord3d Wm3glMultiTexCoord3d;
#define glMultiTexCoord3d Wm3glMultiTexCoord3d

typedef void (APIENTRY* pfn_glMultiTexCoord3dv) (GLenum, const GLdouble*);
WM3_EXTERN pfn_glMultiTexCoord3dv Wm3glMultiTexCoord3dv;
#define glMultiTexCoord3dv Wm3glMultiTexCoord3dv

typedef void (APIENTRY* pfn_glMultiTexCoord3f) (GLenum, GLfloat, GLfloat, GLfloat);
WM3_EXTERN pfn_glMultiTexCoord3f Wm3glMultiTexCoord3f;
#define glMultiTexCoord3f Wm3glMultiTexCoord3f

typedef void (APIENTRY* pfn_glMultiTexCoord3fv) (GLenum, const GLfloat*);
WM3_EXTERN pfn_glMultiTexCoord3fv Wm3glMultiTexCoord3fv;
#define glMultiTexCoord3fv Wm3glMultiTexCoord3fv

typedef void (APIENTRY* pfn_glMultiTexCoord3i) (GLenum, GLint, GLint, GLint);
WM3_EXTERN pfn_glMultiTexCoord3i Wm3glMultiTexCoord3i;
#define glMultiTexCoord3i Wm3glMultiTexCoord3i

typedef void (APIENTRY* pfn_glMultiTexCoord3iv) (GLenum, const GLint*);
WM3_EXTERN pfn_glMultiTexCoord3iv Wm3glMultiTexCoord3iv;
#define glMultiTexCoord3iv Wm3glMultiTexCoord3iv

typedef void (APIENTRY* pfn_glMultiTexCoord3s) (GLenum, GLshort, GLshort, GLshort);
WM3_EXTERN pfn_glMultiTexCoord3s Wm3glMultiTexCoord3s;
#define glMultiTexCoord3s Wm3glMultiTexCoord3s

typedef void (APIENTRY* pfn_glMultiTexCoord3sv) (GLenum, const GLshort*);
WM3_EXTERN pfn_glMultiTexCoord3sv Wm3glMultiTexCoord3sv;
#define glMultiTexCoord3sv Wm3glMultiTexCoord3sv

typedef void (APIENTRY* pfn_glMultiTexCoord4d) (GLenum, GLdouble, GLdouble, GLdouble, GLdouble);
WM3_EXTERN pfn_glMultiTexCoord4d Wm3glMultiTexCoord4d;
#define glMultiTexCoord4d Wm3glMultiTexCoord4d

typedef void (APIENTRY* pfn_glMultiTexCoord4dv) (GLenum, const GLdouble*);
WM3_EXTERN pfn_glMultiTexCoord4dv Wm3glMultiTexCoord4dv;
#define glMultiTexCoord4dv Wm3glMultiTexCoord4dv

typedef void (APIENTRY* pfn_glMultiTexCoord4f) (GLenum, GLfloat, GLfloat, GLfloat, GLfloat);
WM3_EXTERN pfn_glMultiTexCoord4f Wm3glMultiTexCoord4f;
#define glMultiTexCoord4f Wm3glMultiTexCoord4f

typedef void (APIENTRY* pfn_glMultiTexCoord4fv) (GLenum, const GLfloat*);
WM3_EXTERN pfn_glMultiTexCoord4fv Wm3glMultiTexCoord4fv;
#define glMultiTexCoord4fv Wm3glMultiTexCoord4fv

typedef void (APIENTRY* pfn_glMultiTexCoord4i) (GLenum, GLint, GLint, GLint, GLint);
WM3_EXTERN pfn_glMultiTexCoord4i Wm3glMultiTexCoord4i;
#define glMultiTexCoord4i Wm3glMultiTexCoord4i

typedef void (APIENTRY* pfn_glMultiTexCoord4iv) (GLenum, const GLint*);
WM3_EXTERN pfn_glMultiTexCoord4iv Wm3glMultiTexCoord4iv;
#define glMultiTexCoord4iv Wm3glMultiTexCoord4iv

typedef void (APIENTRY* pfn_glMultiTexCoord4s) (GLenum, GLshort, GLshort, GLshort, GLshort);
WM3_EXTERN pfn_glMultiTexCoord4s Wm3glMultiTexCoord4s;
#define glMultiTexCoord4s Wm3glMultiTexCoord4s

typedef void (APIENTRY* pfn_glMultiTexCoord4sv) (GLenum, const GLshort*);
WM3_EXTERN pfn_glMultiTexCoord4sv Wm3glMultiTexCoord4sv;
#define glMultiTexCoord4sv Wm3glMultiTexCoord4sv

typedef void (APIENTRY* pfn_glLoadTransposeMatrixf) (const GLfloat*);
WM3_EXTERN pfn_glLoadTransposeMatrixf Wm3glLoadTransposeMatrixf;
#define glLoadTransposeMatrixf Wm3glLoadTransposeMatrixf

typedef void (APIENTRY* pfn_glLoadTransposeMatrixd) (const GLdouble*);
WM3_EXTERN pfn_glLoadTransposeMatrixd Wm3glLoadTransposeMatrixd;
#define glLoadTransposeMatrixd Wm3glLoadTransposeMatrixd

typedef void (APIENTRY* pfn_glMultTransposeMatrixf) (const GLfloat*);
WM3_EXTERN pfn_glMultTransposeMatrixf Wm3glMultTransposeMatrixf;
#define glMultTransposeMatrixf Wm3glMultTransposeMatrixf

typedef void (APIENTRY* pfn_glMultTransposeMatrixd) (const GLdouble*);
WM3_EXTERN pfn_glMultTransposeMatrixd Wm3glMultTransposeMatrixd;
#define glMultTransposeMatrixd Wm3glMultTransposeMatrixd

typedef void (APIENTRY* pfn_glSampleCoverage) (GLclampf, GLboolean);
WM3_EXTERN pfn_glSampleCoverage Wm3glSampleCoverage;
#define glSampleCoverage Wm3glSampleCoverage

typedef void (APIENTRY* pfn_glCompressedTexImage3D) (GLenum, GLint, GLenum, GLsizei, GLsizei, GLsizei, GLint, GLsizei, const GLvoid*);
WM3_EXTERN pfn_glCompressedTexImage3D Wm3glCompressedTexImage3D;
#define glCompressedTexImage3D Wm3glCompressedTexImage3D

typedef void (APIENTRY* pfn_glCompressedTexImage2D) (GLenum, GLint, GLenum, GLsizei, GLsizei, GLint, GLsizei, const GLvoid*);
WM3_EXTERN pfn_glCompressedTexImage2D Wm3glCompressedTexImage2D;
#define glCompressedTexImage2D Wm3glCompressedTexImage2D

typedef void (APIENTRY* pfn_glCompressedTexImage1D) (GLenum, GLint, GLenum, GLsizei, GLint, GLsizei, const GLvoid*);
WM3_EXTERN pfn_glCompressedTexImage1D Wm3glCompressedTexImage1D;
#define glCompressedTexImage1D Wm3glCompressedTexImage1D

typedef void (APIENTRY* pfn_glCompressedTexSubImage3D) (GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLsizei, const GLvoid*);
WM3_EXTERN pfn_glCompressedTexSubImage3D Wm3glCompressedTexSubImage3D;
#define glCompressedTexSubImage3D Wm3glCompressedTexSubImage3D

typedef void (APIENTRY* pfn_glCompressedTexSubImage2D) (GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLsizei, const GLvoid*);
WM3_EXTERN pfn_glCompressedTexSubImage2D Wm3glCompressedTexSubImage2D;
#define glCompressedTexSubImage2D Wm3glCompressedTexSubImage2D

typedef void (APIENTRY* pfn_glCompressedTexSubImage1D) (GLenum, GLint, GLint, GLsizei, GLenum, GLsizei, const GLvoid*);
WM3_EXTERN pfn_glCompressedTexSubImage1D Wm3glCompressedTexSubImage1D;
#define glCompressedTexSubImage1D Wm3glCompressedTexSubImage1D

typedef void (APIENTRY* pfn_glGetCompressedTexImage) (GLenum, GLint, GLvoid*);
WM3_EXTERN pfn_glGetCompressedTexImage Wm3glGetCompressedTexImage;
#define glGetCompressedTexImage Wm3glGetCompressedTexImage
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_VERSION_1_4;
WM3_EXTERN int Wm3NumFunctions_GL_VERSION_1_4;
#ifndef GL_VERSION_1_4
#define GL_VERSION_1_4
#define WM3_DEFINED_GL_VERSION_1_4
#define GL_BLEND_DST_RGB                  0x80C8
#define GL_BLEND_SRC_RGB                  0x80C9
#define GL_BLEND_DST_ALPHA                0x80CA
#define GL_BLEND_SRC_ALPHA                0x80CB
#define GL_POINT_SIZE_MIN                 0x8126
#define GL_POINT_SIZE_MAX                 0x8127
#define GL_POINT_FADE_THRESHOLD_SIZE      0x8128
#define GL_POINT_DISTANCE_ATTENUATION     0x8129
#define GL_GENERATE_MIPMAP                0x8191
#define GL_GENERATE_MIPMAP_HINT           0x8192
#define GL_DEPTH_COMPONENT16              0x81A5
#define GL_DEPTH_COMPONENT24              0x81A6
#define GL_DEPTH_COMPONENT32              0x81A7
#define GL_MIRRORED_REPEAT                0x8370
#define GL_FOG_COORDINATE_SOURCE          0x8450
#define GL_FOG_COORDINATE                 0x8451
#define GL_FRAGMENT_DEPTH                 0x8452
#define GL_CURRENT_FOG_COORDINATE         0x8453
#define GL_FOG_COORDINATE_ARRAY_TYPE      0x8454
#define GL_FOG_COORDINATE_ARRAY_STRIDE    0x8455
#define GL_FOG_COORDINATE_ARRAY_POINTER   0x8456
#define GL_FOG_COORDINATE_ARRAY           0x8457
#define GL_COLOR_SUM                      0x8458
#define GL_CURRENT_SECONDARY_COLOR        0x8459
#define GL_SECONDARY_COLOR_ARRAY_SIZE     0x845A
#define GL_SECONDARY_COLOR_ARRAY_TYPE     0x845B
#define GL_SECONDARY_COLOR_ARRAY_STRIDE   0x845C
#define GL_SECONDARY_COLOR_ARRAY_POINTER  0x845D
#define GL_SECONDARY_COLOR_ARRAY          0x845E
#define GL_MAX_TEXTURE_LOD_BIAS           0x84FD
#define GL_TEXTURE_FILTER_CONTROL         0x8500
#define GL_TEXTURE_LOD_BIAS               0x8501
#define GL_INCR_WRAP                      0x8507
#define GL_DECR_WRAP                      0x8508
#define GL_TEXTURE_DEPTH_SIZE             0x884A
#define GL_DEPTH_TEXTURE_MODE             0x884B
#define GL_TEXTURE_COMPARE_MODE           0x884C
#define GL_TEXTURE_COMPARE_FUNC           0x884D
#define GL_COMPARE_R_TO_TEXTURE           0x884E

typedef void (APIENTRY* pfn_glBlendFuncSeparate) (GLenum, GLenum, GLenum, GLenum);
WM3_EXTERN pfn_glBlendFuncSeparate Wm3glBlendFuncSeparate;
#define glBlendFuncSeparate Wm3glBlendFuncSeparate

typedef void (APIENTRY* pfn_glFogCoordf) (GLfloat);
WM3_EXTERN pfn_glFogCoordf Wm3glFogCoordf;
#define glFogCoordf Wm3glFogCoordf

typedef void (APIENTRY* pfn_glFogCoordfv) (const GLfloat*);
WM3_EXTERN pfn_glFogCoordfv Wm3glFogCoordfv;
#define glFogCoordfv Wm3glFogCoordfv

typedef void (APIENTRY* pfn_glFogCoordd) (GLdouble);
WM3_EXTERN pfn_glFogCoordd Wm3glFogCoordd;
#define glFogCoordd Wm3glFogCoordd

typedef void (APIENTRY* pfn_glFogCoorddv) (const GLdouble*);
WM3_EXTERN pfn_glFogCoorddv Wm3glFogCoorddv;
#define glFogCoorddv Wm3glFogCoorddv

typedef void (APIENTRY* pfn_glFogCoordPointer) (GLenum, GLsizei, const GLvoid*);
WM3_EXTERN pfn_glFogCoordPointer Wm3glFogCoordPointer;
#define glFogCoordPointer Wm3glFogCoordPointer

typedef void (APIENTRY* pfn_glMultiDrawArrays) (GLenum, GLint*, GLsizei*, GLsizei);
WM3_EXTERN pfn_glMultiDrawArrays Wm3glMultiDrawArrays;
#define glMultiDrawArrays Wm3glMultiDrawArrays

typedef void (APIENTRY* pfn_glMultiDrawElements) (GLenum, const GLsizei*, GLenum, const GLvoid**, GLsizei);
WM3_EXTERN pfn_glMultiDrawElements Wm3glMultiDrawElements;
#define glMultiDrawElements Wm3glMultiDrawElements

typedef void (APIENTRY* pfn_glPointParameterf) (GLenum, GLfloat);
WM3_EXTERN pfn_glPointParameterf Wm3glPointParameterf;
#define glPointParameterf Wm3glPointParameterf

typedef void (APIENTRY* pfn_glPointParameterfv) (GLenum, const GLfloat*);
WM3_EXTERN pfn_glPointParameterfv Wm3glPointParameterfv;
#define glPointParameterfv Wm3glPointParameterfv

typedef void (APIENTRY* pfn_glPointParameteri) (GLenum, GLint);
WM3_EXTERN pfn_glPointParameteri Wm3glPointParameteri;
#define glPointParameteri Wm3glPointParameteri

typedef void (APIENTRY* pfn_glPointParameteriv) (GLenum, const GLint*);
WM3_EXTERN pfn_glPointParameteriv Wm3glPointParameteriv;
#define glPointParameteriv Wm3glPointParameteriv

typedef void (APIENTRY* pfn_glSecondaryColor3b) (GLbyte, GLbyte, GLbyte);
WM3_EXTERN pfn_glSecondaryColor3b Wm3glSecondaryColor3b;
#define glSecondaryColor3b Wm3glSecondaryColor3b

typedef void (APIENTRY* pfn_glSecondaryColor3bv) (const GLbyte*);
WM3_EXTERN pfn_glSecondaryColor3bv Wm3glSecondaryColor3bv;
#define glSecondaryColor3bv Wm3glSecondaryColor3bv

typedef void (APIENTRY* pfn_glSecondaryColor3d) (GLdouble, GLdouble, GLdouble);
WM3_EXTERN pfn_glSecondaryColor3d Wm3glSecondaryColor3d;
#define glSecondaryColor3d Wm3glSecondaryColor3d

typedef void (APIENTRY* pfn_glSecondaryColor3dv) (const GLdouble*);
WM3_EXTERN pfn_glSecondaryColor3dv Wm3glSecondaryColor3dv;
#define glSecondaryColor3dv Wm3glSecondaryColor3dv

typedef void (APIENTRY* pfn_glSecondaryColor3f) (GLfloat, GLfloat, GLfloat);
WM3_EXTERN pfn_glSecondaryColor3f Wm3glSecondaryColor3f;
#define glSecondaryColor3f Wm3glSecondaryColor3f

typedef void (APIENTRY* pfn_glSecondaryColor3fv) (const GLfloat*);
WM3_EXTERN pfn_glSecondaryColor3fv Wm3glSecondaryColor3fv;
#define glSecondaryColor3fv Wm3glSecondaryColor3fv

typedef void (APIENTRY* pfn_glSecondaryColor3i) (GLint, GLint, GLint);
WM3_EXTERN pfn_glSecondaryColor3i Wm3glSecondaryColor3i;
#define glSecondaryColor3i Wm3glSecondaryColor3i

typedef void (APIENTRY* pfn_glSecondaryColor3iv) (const GLint*);
WM3_EXTERN pfn_glSecondaryColor3iv Wm3glSecondaryColor3iv;
#define glSecondaryColor3iv Wm3glSecondaryColor3iv

typedef void (APIENTRY* pfn_glSecondaryColor3s) (GLshort, GLshort, GLshort);
WM3_EXTERN pfn_glSecondaryColor3s Wm3glSecondaryColor3s;
#define glSecondaryColor3s Wm3glSecondaryColor3s

typedef void (APIENTRY* pfn_glSecondaryColor3sv) (const GLshort*);
WM3_EXTERN pfn_glSecondaryColor3sv Wm3glSecondaryColor3sv;
#define glSecondaryColor3sv Wm3glSecondaryColor3sv

typedef void (APIENTRY* pfn_glSecondaryColor3ub) (GLubyte, GLubyte, GLubyte);
WM3_EXTERN pfn_glSecondaryColor3ub Wm3glSecondaryColor3ub;
#define glSecondaryColor3ub Wm3glSecondaryColor3ub

typedef void (APIENTRY* pfn_glSecondaryColor3ubv) (const GLubyte*);
WM3_EXTERN pfn_glSecondaryColor3ubv Wm3glSecondaryColor3ubv;
#define glSecondaryColor3ubv Wm3glSecondaryColor3ubv

typedef void (APIENTRY* pfn_glSecondaryColor3ui) (GLuint, GLuint, GLuint);
WM3_EXTERN pfn_glSecondaryColor3ui Wm3glSecondaryColor3ui;
#define glSecondaryColor3ui Wm3glSecondaryColor3ui

typedef void (APIENTRY* pfn_glSecondaryColor3uiv) (const GLuint*);
WM3_EXTERN pfn_glSecondaryColor3uiv Wm3glSecondaryColor3uiv;
#define glSecondaryColor3uiv Wm3glSecondaryColor3uiv

typedef void (APIENTRY* pfn_glSecondaryColor3us) (GLushort, GLushort, GLushort);
WM3_EXTERN pfn_glSecondaryColor3us Wm3glSecondaryColor3us;
#define glSecondaryColor3us Wm3glSecondaryColor3us

typedef void (APIENTRY* pfn_glSecondaryColor3usv) (const GLushort*);
WM3_EXTERN pfn_glSecondaryColor3usv Wm3glSecondaryColor3usv;
#define glSecondaryColor3usv Wm3glSecondaryColor3usv

typedef void (APIENTRY* pfn_glSecondaryColorPointer) (GLint, GLenum, GLsizei, const GLvoid*);
WM3_EXTERN pfn_glSecondaryColorPointer Wm3glSecondaryColorPointer;
#define glSecondaryColorPointer Wm3glSecondaryColorPointer

typedef void (APIENTRY* pfn_glWindowPos2d) (GLdouble, GLdouble);
WM3_EXTERN pfn_glWindowPos2d Wm3glWindowPos2d;
#define glWindowPos2d Wm3glWindowPos2d

typedef void (APIENTRY* pfn_glWindowPos2dv) (const GLdouble*);
WM3_EXTERN pfn_glWindowPos2dv Wm3glWindowPos2dv;
#define glWindowPos2dv Wm3glWindowPos2dv

typedef void (APIENTRY* pfn_glWindowPos2f) (GLfloat, GLfloat);
WM3_EXTERN pfn_glWindowPos2f Wm3glWindowPos2f;
#define glWindowPos2f Wm3glWindowPos2f

typedef void (APIENTRY* pfn_glWindowPos2fv) (const GLfloat*);
WM3_EXTERN pfn_glWindowPos2fv Wm3glWindowPos2fv;
#define glWindowPos2fv Wm3glWindowPos2fv

typedef void (APIENTRY* pfn_glWindowPos2i) (GLint, GLint);
WM3_EXTERN pfn_glWindowPos2i Wm3glWindowPos2i;
#define glWindowPos2i Wm3glWindowPos2i

typedef void (APIENTRY* pfn_glWindowPos2iv) (const GLint*);
WM3_EXTERN pfn_glWindowPos2iv Wm3glWindowPos2iv;
#define glWindowPos2iv Wm3glWindowPos2iv

typedef void (APIENTRY* pfn_glWindowPos2s) (GLshort, GLshort);
WM3_EXTERN pfn_glWindowPos2s Wm3glWindowPos2s;
#define glWindowPos2s Wm3glWindowPos2s

typedef void (APIENTRY* pfn_glWindowPos2sv) (const GLshort*);
WM3_EXTERN pfn_glWindowPos2sv Wm3glWindowPos2sv;
#define glWindowPos2sv Wm3glWindowPos2sv

typedef void (APIENTRY* pfn_glWindowPos3d) (GLdouble, GLdouble, GLdouble);
WM3_EXTERN pfn_glWindowPos3d Wm3glWindowPos3d;
#define glWindowPos3d Wm3glWindowPos3d

typedef void (APIENTRY* pfn_glWindowPos3dv) (const GLdouble*);
WM3_EXTERN pfn_glWindowPos3dv Wm3glWindowPos3dv;
#define glWindowPos3dv Wm3glWindowPos3dv

typedef void (APIENTRY* pfn_glWindowPos3f) (GLfloat, GLfloat, GLfloat);
WM3_EXTERN pfn_glWindowPos3f Wm3glWindowPos3f;
#define glWindowPos3f Wm3glWindowPos3f

typedef void (APIENTRY* pfn_glWindowPos3fv) (const GLfloat*);
WM3_EXTERN pfn_glWindowPos3fv Wm3glWindowPos3fv;
#define glWindowPos3fv Wm3glWindowPos3fv

typedef void (APIENTRY* pfn_glWindowPos3i) (GLint, GLint, GLint);
WM3_EXTERN pfn_glWindowPos3i Wm3glWindowPos3i;
#define glWindowPos3i Wm3glWindowPos3i

typedef void (APIENTRY* pfn_glWindowPos3iv) (const GLint*);
WM3_EXTERN pfn_glWindowPos3iv Wm3glWindowPos3iv;
#define glWindowPos3iv Wm3glWindowPos3iv

typedef void (APIENTRY* pfn_glWindowPos3s) (GLshort, GLshort, GLshort);
WM3_EXTERN pfn_glWindowPos3s Wm3glWindowPos3s;
#define glWindowPos3s Wm3glWindowPos3s

typedef void (APIENTRY* pfn_glWindowPos3sv) (const GLshort*);
WM3_EXTERN pfn_glWindowPos3sv Wm3glWindowPos3sv;
#define glWindowPos3sv Wm3glWindowPos3sv
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_VERSION_1_5;
WM3_EXTERN int Wm3NumFunctions_GL_VERSION_1_5;
#ifndef GL_VERSION_1_5
#define GL_VERSION_1_5
#define WM3_DEFINED_GL_VERSION_1_5
#define GL_BUFFER_SIZE                          0x8764
#define GL_BUFFER_USAGE                         0x8765
#define GL_QUERY_COUNTER_BITS                   0x8864
#define GL_CURRENT_QUERY                        0x8865
#define GL_QUERY_RESULT                         0x8866
#define GL_QUERY_RESULT_AVAILABLE               0x8867
#define GL_ARRAY_BUFFER                         0x8892
#define GL_ELEMENT_ARRAY_BUFFER                 0x8893
#define GL_ARRAY_BUFFER_BINDING                 0x8894
#define GL_ELEMENT_ARRAY_BUFFER_BINDING         0x8895
#define GL_VERTEX_ARRAY_BUFFER_BINDING          0x8896
#define GL_NORMAL_ARRAY_BUFFER_BINDING          0x8897
#define GL_COLOR_ARRAY_BUFFER_BINDING           0x8898
#define GL_INDEX_ARRAY_BUFFER_BINDING           0x8899
#define GL_TEXTURE_COORD_ARRAY_BUFFER_BINDING   0x889A
#define GL_EDGE_FLAG_ARRAY_BUFFER_BINDING       0x889B
#define GL_SECONDARY_COLOR_ARRAY_BUFFER_BINDING 0x889C
#define GL_FOG_COORDINATE_ARRAY_BUFFER_BINDING  0x889D
#define GL_WEIGHT_ARRAY_BUFFER_BINDING          0x889E
#define GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING   0x889F
#define GL_READ_ONLY                            0x88B8
#define GL_WRITE_ONLY                           0x88B9
#define GL_READ_WRITE                           0x88BA
#define GL_BUFFER_ACCESS                        0x88BB
#define GL_BUFFER_MAPPED                        0x88BC
#define GL_BUFFER_MAP_POINTER                   0x88BD
#define GL_STREAM_DRAW                          0x88E0
#define GL_STREAM_READ                          0x88E1
#define GL_STREAM_COPY                          0x88E2
#define GL_STATIC_DRAW                          0x88E4
#define GL_STATIC_READ                          0x88E5
#define GL_STATIC_COPY                          0x88E6
#define GL_DYNAMIC_DRAW                         0x88E8
#define GL_DYNAMIC_READ                         0x88E9
#define GL_DYNAMIC_COPY                         0x88EA
#define GL_SAMPLES_PASSED                       0x8914
#define GL_FOG_COORD_SRC                        GL_FOG_COORDINATE_SOURCE
#define GL_FOG_COORD                            GL_FOG_COORDINATE
#define GL_CURRENT_FOG_COORD                    GL_CURRENT_FOG_COORDINATE
#define GL_FOG_COORD_ARRAY_TYPE                 GL_FOG_COORDINATE_ARRAY_TYPE
#define GL_FOG_COORD_ARRAY_STRIDE               GL_FOG_COORDINATE_ARRAY_STRIDE
#define GL_FOG_COORD_ARRAY_POINTER              GL_FOG_COORDINATE_ARRAY_POINTER
#define GL_FOG_COORD_ARRAY                      GL_FOG_COORDINATE_ARRAY
#define GL_FOG_COORD_ARRAY_BUFFER_BINDING       GL_FOG_COORDINATE_ARRAY_BUFFER_BINDING
#define GL_SRC0_RGB                             GL_SOURCE0_RGB
#define GL_SRC1_RGB                             GL_SOURCE1_RGB
#define GL_SRC2_RGB                             GL_SOURCE2_RGB
#define GL_SRC0_ALPHA                           GL_SOURCE0_ALPHA
#define GL_SRC1_ALPHA                           GL_SOURCE1_ALPHA
#define GL_SRC2_ALPHA                           GL_SOURCE2_ALPHA
typedef ptrdiff_t GLintptr;
typedef ptrdiff_t GLsizeiptr;

typedef void (APIENTRY* pfn_glGenQueries) (GLsizei, GLuint*);
WM3_EXTERN pfn_glGenQueries Wm3glGenQueries;
#define glGenQueries Wm3glGenQueries

typedef void (APIENTRY* pfn_glDeleteQueries) (GLsizei, const GLuint*);
WM3_EXTERN pfn_glDeleteQueries Wm3glDeleteQueries;
#define glDeleteQueries Wm3glDeleteQueries

typedef GLboolean (APIENTRY* pfn_glIsQuery) (GLuint);
WM3_EXTERN pfn_glIsQuery Wm3glIsQuery;
#define glIsQuery Wm3glIsQuery

typedef void (APIENTRY* pfn_glBeginQuery) (GLenum, GLuint);
WM3_EXTERN pfn_glBeginQuery Wm3glBeginQuery;
#define glBeginQuery Wm3glBeginQuery

typedef void (APIENTRY* pfn_glEndQuery) (GLenum);
WM3_EXTERN pfn_glEndQuery Wm3glEndQuery;
#define glEndQuery Wm3glEndQuery

typedef void (APIENTRY* pfn_glGetQueryiv) (GLenum, GLenum, GLint*);
WM3_EXTERN pfn_glGetQueryiv Wm3glGetQueryiv;
#define glGetQueryiv Wm3glGetQueryiv

typedef void (APIENTRY* pfn_glGetQueryObjectiv) (GLuint, GLenum, GLint*);
WM3_EXTERN pfn_glGetQueryObjectiv Wm3glGetQueryObjectiv;
#define glGetQueryObjectiv Wm3glGetQueryObjectiv

typedef void (APIENTRY* pfn_glGetQueryObjectuiv) (GLuint, GLenum, GLuint*);
WM3_EXTERN pfn_glGetQueryObjectuiv Wm3glGetQueryObjectuiv;
#define glGetQueryObjectuiv Wm3glGetQueryObjectuiv

typedef void (APIENTRY* pfn_glBindBuffer) (GLenum, GLuint);
WM3_EXTERN pfn_glBindBuffer Wm3glBindBuffer;
#define glBindBuffer Wm3glBindBuffer

typedef void (APIENTRY* pfn_glDeleteBuffers) (GLsizei, const GLuint*);
WM3_EXTERN pfn_glDeleteBuffers Wm3glDeleteBuffers;
#define glDeleteBuffers Wm3glDeleteBuffers

typedef void (APIENTRY* pfn_glGenBuffers) (GLsizei, GLuint*);
WM3_EXTERN pfn_glGenBuffers Wm3glGenBuffers;
#define glGenBuffers Wm3glGenBuffers

typedef GLboolean (APIENTRY* pfn_glIsBuffer) (GLuint);
WM3_EXTERN pfn_glIsBuffer Wm3glIsBuffer;
#define glIsBuffer Wm3glIsBuffer

typedef void (APIENTRY* pfn_glBufferData) (GLenum, GLsizeiptr, const GLvoid*, GLenum);
WM3_EXTERN pfn_glBufferData Wm3glBufferData;
#define glBufferData Wm3glBufferData

typedef void (APIENTRY* pfn_glBufferSubData) (GLenum, GLintptr, GLsizeiptr, const GLvoid*);
WM3_EXTERN pfn_glBufferSubData Wm3glBufferSubData;
#define glBufferSubData Wm3glBufferSubData

typedef void (APIENTRY* pfn_glGetBufferSubData) (GLenum, GLintptr, GLsizeiptr, GLvoid*);
WM3_EXTERN pfn_glGetBufferSubData Wm3glGetBufferSubData;
#define glGetBufferSubData Wm3glGetBufferSubData

typedef GLvoid* (APIENTRY* pfn_glMapBuffer) (GLenum, GLenum);
WM3_EXTERN pfn_glMapBuffer Wm3glMapBuffer;
#define glMapBuffer Wm3glMapBuffer

typedef GLboolean (APIENTRY* pfn_glUnmapBuffer) (GLenum);
WM3_EXTERN pfn_glUnmapBuffer Wm3glUnmapBuffer;
#define glUnmapBuffer Wm3glUnmapBuffer

typedef void (APIENTRY* pfn_glGetBufferParameteriv) (GLenum, GLenum, GLint*);
WM3_EXTERN pfn_glGetBufferParameteriv Wm3glGetBufferParameteriv;
#define glGetBufferParameteriv Wm3glGetBufferParameteriv

typedef void (APIENTRY* pfn_glGetBufferPointerv) (GLenum, GLenum, GLvoid**);
WM3_EXTERN pfn_glGetBufferPointerv Wm3glGetBufferPointerv;
#define glGetBufferPointerv Wm3glGetBufferPointerv
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_VERSION_2_0;
WM3_EXTERN int Wm3NumFunctions_GL_VERSION_2_0;
#ifndef GL_VERSION_2_0
#define GL_VERSION_2_0
#define WM3_DEFINED_GL_VERSION_2_0
#define GL_BLEND_EQUATION_RGB               GL_BLEND_EQUATION
#define GL_VERTEX_ATTRIB_ARRAY_ENABLED      0x8622
#define GL_VERTEX_ATTRIB_ARRAY_SIZE         0x8623
#define GL_VERTEX_ATTRIB_ARRAY_STRIDE       0x8624
#define GL_VERTEX_ATTRIB_ARRAY_TYPE         0x8625
#define GL_CURRENT_VERTEX_ATTRIB            0x8626
#define GL_VERTEX_PROGRAM_POINT_SIZE        0x8642
#define GL_VERTEX_PROGRAM_TWO_SIDE          0x8643
#define GL_VERTEX_ATTRIB_ARRAY_POINTER      0x8645
#define GL_STENCIL_BACK_FUNC                0x8800
#define GL_STENCIL_BACK_FAIL                0x8801
#define GL_STENCIL_BACK_PASS_DEPTH_FAIL     0x8802
#define GL_STENCIL_BACK_PASS_DEPTH_PASS     0x8803
#define GL_MAX_DRAW_BUFFERS                 0x8824
#define GL_DRAW_BUFFER0                     0x8825
#define GL_DRAW_BUFFER1                     0x8826
#define GL_DRAW_BUFFER2                     0x8827
#define GL_DRAW_BUFFER3                     0x8828
#define GL_DRAW_BUFFER4                     0x8829
#define GL_DRAW_BUFFER5                     0x882A
#define GL_DRAW_BUFFER6                     0x882B
#define GL_DRAW_BUFFER7                     0x882C
#define GL_DRAW_BUFFER8                     0x882D
#define GL_DRAW_BUFFER9                     0x882E
#define GL_DRAW_BUFFER10                    0x882F
#define GL_DRAW_BUFFER11                    0x8830
#define GL_DRAW_BUFFER12                    0x8831
#define GL_DRAW_BUFFER13                    0x8832
#define GL_DRAW_BUFFER14                    0x8833
#define GL_DRAW_BUFFER15                    0x8834
#define GL_BLEND_EQUATION_ALPHA             0x883D
#define GL_POINT_SPRITE                     0x8861
#define GL_COORD_REPLACE                    0x8862
#define GL_MAX_VERTEX_ATTRIBS               0x8869
#define GL_VERTEX_ATTRIB_ARRAY_NORMALIZED   0x886A
#define GL_MAX_TEXTURE_COORDS               0x8871
#define GL_MAX_TEXTURE_IMAGE_UNITS          0x8872
#define GL_FRAGMENT_SHADER                  0x8B30
#define GL_VERTEX_SHADER                    0x8B31
#define GL_MAX_FRAGMENT_UNIFORM_COMPONENTS  0x8B49
#define GL_MAX_VERTEX_UNIFORM_COMPONENTS    0x8B4A
#define GL_MAX_VARYING_FLOATS               0x8B4B
#define GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS   0x8B4C
#define GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS 0x8B4D
#define GL_SHADER_TYPE                      0x8B4F
#define GL_FLOAT_VEC2                       0x8B50
#define GL_FLOAT_VEC3                       0x8B51
#define GL_FLOAT_VEC4                       0x8B52
#define GL_INT_VEC2                         0x8B53
#define GL_INT_VEC3                         0x8B54
#define GL_INT_VEC4                         0x8B55
#define GL_BOOL                             0x8B56
#define GL_BOOL_VEC2                        0x8B57
#define GL_BOOL_VEC3                        0x8B58
#define GL_BOOL_VEC4                        0x8B59
#define GL_FLOAT_MAT2                       0x8B5A
#define GL_FLOAT_MAT3                       0x8B5B
#define GL_FLOAT_MAT4                       0x8B5C
#define GL_SAMPLER_1D                       0x8B5D
#define GL_SAMPLER_2D                       0x8B5E
#define GL_SAMPLER_3D                       0x8B5F
#define GL_SAMPLER_CUBE                     0x8B60
#define GL_SAMPLER_1D_SHADOW                0x8B61
#define GL_SAMPLER_2D_SHADOW                0x8B62
#define GL_DELETE_STATUS                    0x8B80
#define GL_COMPILE_STATUS                   0x8B81
#define GL_LINK_STATUS                      0x8B82
#define GL_VALIDATE_STATUS                  0x8B83
#define GL_INFO_LOG_LENGTH                  0x8B84
#define GL_ATTACHED_SHADERS                 0x8B85
#define GL_ACTIVE_UNIFORMS                  0x8B86
#define GL_ACTIVE_UNIFORM_MAX_LENGTH        0x8B87
#define GL_SHADER_SOURCE_LENGTH             0x8B88
#define GL_ACTIVE_ATTRIBUTES                0x8B89
#define GL_ACTIVE_ATTRIBUTE_MAX_LENGTH      0x8B8A
#define GL_FRAGMENT_SHADER_DERIVATIVE_HINT  0x8B8B
#define GL_SHADING_LANGUAGE_VERSION         0x8B8C
#define GL_CURRENT_PROGRAM                  0x8B8D
#define GL_POINT_SPRITE_COORD_ORIGIN        0x8CA0
#define GL_LOWER_LEFT                       0x8CA1
#define GL_UPPER_LEFT                       0x8CA2
#define GL_STENCIL_BACK_REF                 0x8CA3
#define GL_STENCIL_BACK_VALUE_MASK          0x8CA4
#define GL_STENCIL_BACK_WRITEMASK           0x8CA5
typedef char GLchar;

typedef void (APIENTRY* pfn_glBlendEquationSeparate) (GLenum, GLenum);
WM3_EXTERN pfn_glBlendEquationSeparate Wm3glBlendEquationSeparate;
#define glBlendEquationSeparate Wm3glBlendEquationSeparate

typedef void (APIENTRY* pfn_glDrawBuffers) (GLsizei, const GLenum*);
WM3_EXTERN pfn_glDrawBuffers Wm3glDrawBuffers;
#define glDrawBuffers Wm3glDrawBuffers

typedef void (APIENTRY* pfn_glStencilOpSeparate) (GLenum, GLenum, GLenum, GLenum);
WM3_EXTERN pfn_glStencilOpSeparate Wm3glStencilOpSeparate;
#define glStencilOpSeparate Wm3glStencilOpSeparate

typedef void (APIENTRY* pfn_glStencilFuncSeparate) (GLenum, GLenum, GLint, GLuint);
WM3_EXTERN pfn_glStencilFuncSeparate Wm3glStencilFuncSeparate;
#define glStencilFuncSeparate Wm3glStencilFuncSeparate

typedef void (APIENTRY* pfn_glStencilMaskSeparate) (GLenum, GLuint);
WM3_EXTERN pfn_glStencilMaskSeparate Wm3glStencilMaskSeparate;
#define glStencilMaskSeparate Wm3glStencilMaskSeparate

typedef void (APIENTRY* pfn_glAttachShader) (GLuint, GLuint);
WM3_EXTERN pfn_glAttachShader Wm3glAttachShader;
#define glAttachShader Wm3glAttachShader

typedef void (APIENTRY* pfn_glBindAttribLocation) (GLuint, GLuint, const GLchar*);
WM3_EXTERN pfn_glBindAttribLocation Wm3glBindAttribLocation;
#define glBindAttribLocation Wm3glBindAttribLocation

typedef void (APIENTRY* pfn_glCompileShader) (GLuint);
WM3_EXTERN pfn_glCompileShader Wm3glCompileShader;
#define glCompileShader Wm3glCompileShader

typedef GLuint (APIENTRY* pfn_glCreateProgram) (void);
WM3_EXTERN pfn_glCreateProgram Wm3glCreateProgram;
#define glCreateProgram Wm3glCreateProgram

typedef GLuint (APIENTRY* pfn_glCreateShader) (GLenum);
WM3_EXTERN pfn_glCreateShader Wm3glCreateShader;
#define glCreateShader Wm3glCreateShader

typedef void (APIENTRY* pfn_glDeleteProgram) (GLuint);
WM3_EXTERN pfn_glDeleteProgram Wm3glDeleteProgram;
#define glDeleteProgram Wm3glDeleteProgram

typedef void (APIENTRY* pfn_glDeleteShader) (GLuint);
WM3_EXTERN pfn_glDeleteShader Wm3glDeleteShader;
#define glDeleteShader Wm3glDeleteShader

typedef void (APIENTRY* pfn_glDetachShader) (GLuint, GLuint);
WM3_EXTERN pfn_glDetachShader Wm3glDetachShader;
#define glDetachShader Wm3glDetachShader

typedef void (APIENTRY* pfn_glDisableVertexAttribArray) (GLuint);
WM3_EXTERN pfn_glDisableVertexAttribArray Wm3glDisableVertexAttribArray;
#define glDisableVertexAttribArray Wm3glDisableVertexAttribArray

typedef void (APIENTRY* pfn_glEnableVertexAttribArray) (GLuint);
WM3_EXTERN pfn_glEnableVertexAttribArray Wm3glEnableVertexAttribArray;
#define glEnableVertexAttribArray Wm3glEnableVertexAttribArray

typedef void (APIENTRY* pfn_glGetActiveAttrib) (GLuint, GLuint, GLsizei, GLsizei*, GLint*, GLenum*, GLchar*);
WM3_EXTERN pfn_glGetActiveAttrib Wm3glGetActiveAttrib;
#define glGetActiveAttrib Wm3glGetActiveAttrib

typedef void (APIENTRY* pfn_glGetActiveUniform) (GLuint, GLuint, GLsizei, GLsizei*, GLint*, GLenum*, GLchar*);
WM3_EXTERN pfn_glGetActiveUniform Wm3glGetActiveUniform;
#define glGetActiveUniform Wm3glGetActiveUniform

typedef void (APIENTRY* pfn_glGetAttachedShaders) (GLuint, GLsizei, GLsizei*, GLuint*);
WM3_EXTERN pfn_glGetAttachedShaders Wm3glGetAttachedShaders;
#define glGetAttachedShaders Wm3glGetAttachedShaders

typedef GLint (APIENTRY* pfn_glGetAttribLocation) (GLuint, const GLchar*);
WM3_EXTERN pfn_glGetAttribLocation Wm3glGetAttribLocation;
#define glGetAttribLocation Wm3glGetAttribLocation

typedef void (APIENTRY* pfn_glGetProgramiv) (GLuint, GLenum, GLint*);
WM3_EXTERN pfn_glGetProgramiv Wm3glGetProgramiv;
#define glGetProgramiv Wm3glGetProgramiv

typedef void (APIENTRY* pfn_glGetProgramInfoLog) (GLuint, GLsizei, GLsizei*, GLchar*);
WM3_EXTERN pfn_glGetProgramInfoLog Wm3glGetProgramInfoLog;
#define glGetProgramInfoLog Wm3glGetProgramInfoLog

typedef void (APIENTRY* pfn_glGetShaderiv) (GLuint, GLenum, GLint*);
WM3_EXTERN pfn_glGetShaderiv Wm3glGetShaderiv;
#define glGetShaderiv Wm3glGetShaderiv

typedef void (APIENTRY* pfn_glGetShaderInfoLog) (GLuint, GLsizei, GLsizei*, GLchar*);
WM3_EXTERN pfn_glGetShaderInfoLog Wm3glGetShaderInfoLog;
#define glGetShaderInfoLog Wm3glGetShaderInfoLog

typedef void (APIENTRY* pfn_glGetShaderSource) (GLuint, GLsizei, GLsizei*, GLchar*);
WM3_EXTERN pfn_glGetShaderSource Wm3glGetShaderSource;
#define glGetShaderSource Wm3glGetShaderSource

typedef GLint (APIENTRY* pfn_glGetUniformLocation) (GLuint, const GLchar*);
WM3_EXTERN pfn_glGetUniformLocation Wm3glGetUniformLocation;
#define glGetUniformLocation Wm3glGetUniformLocation

typedef void (APIENTRY* pfn_glGetUniformfv) (GLuint, GLint, GLfloat*);
WM3_EXTERN pfn_glGetUniformfv Wm3glGetUniformfv;
#define glGetUniformfv Wm3glGetUniformfv

typedef void (APIENTRY* pfn_glGetUniformiv) (GLuint, GLint, GLint*);
WM3_EXTERN pfn_glGetUniformiv Wm3glGetUniformiv;
#define glGetUniformiv Wm3glGetUniformiv

typedef void (APIENTRY* pfn_glGetVertexAttribdv) (GLuint, GLenum, GLdouble*);
WM3_EXTERN pfn_glGetVertexAttribdv Wm3glGetVertexAttribdv;
#define glGetVertexAttribdv Wm3glGetVertexAttribdv

typedef void (APIENTRY* pfn_glGetVertexAttribfv) (GLuint, GLenum, GLfloat*);
WM3_EXTERN pfn_glGetVertexAttribfv Wm3glGetVertexAttribfv;
#define glGetVertexAttribfv Wm3glGetVertexAttribfv

typedef void (APIENTRY* pfn_glGetVertexAttribiv) (GLuint, GLenum, GLint*);
WM3_EXTERN pfn_glGetVertexAttribiv Wm3glGetVertexAttribiv;
#define glGetVertexAttribiv Wm3glGetVertexAttribiv

typedef void (APIENTRY* pfn_glGetVertexAttribPointerv) (GLuint, GLenum, GLvoid**);
WM3_EXTERN pfn_glGetVertexAttribPointerv Wm3glGetVertexAttribPointerv;
#define glGetVertexAttribPointerv Wm3glGetVertexAttribPointerv

typedef GLboolean (APIENTRY* pfn_glIsProgram) (GLuint);
WM3_EXTERN pfn_glIsProgram Wm3glIsProgram;
#define glIsProgram Wm3glIsProgram

typedef GLboolean (APIENTRY* pfn_glIsShader) (GLuint);
WM3_EXTERN pfn_glIsShader Wm3glIsShader;
#define glIsShader Wm3glIsShader

typedef void (APIENTRY* pfn_glLinkProgram) (GLuint);
WM3_EXTERN pfn_glLinkProgram Wm3glLinkProgram;
#define glLinkProgram Wm3glLinkProgram

typedef void (APIENTRY* pfn_glShaderSource) (GLuint, GLsizei, const GLchar**, const GLint*);
WM3_EXTERN pfn_glShaderSource Wm3glShaderSource;
#define glShaderSource Wm3glShaderSource

typedef void (APIENTRY* pfn_glUseProgram) (GLuint);
WM3_EXTERN pfn_glUseProgram Wm3glUseProgram;
#define glUseProgram Wm3glUseProgram

typedef void (APIENTRY* pfn_glUniform1f) (GLint, GLfloat);
WM3_EXTERN pfn_glUniform1f Wm3glUniform1f;
#define glUniform1f Wm3glUniform1f

typedef void (APIENTRY* pfn_glUniform2f) (GLint, GLfloat, GLfloat);
WM3_EXTERN pfn_glUniform2f Wm3glUniform2f;
#define glUniform2f Wm3glUniform2f

typedef void (APIENTRY* pfn_glUniform3f) (GLint, GLfloat, GLfloat, GLfloat);
WM3_EXTERN pfn_glUniform3f Wm3glUniform3f;
#define glUniform3f Wm3glUniform3f

typedef void (APIENTRY* pfn_glUniform4f) (GLint, GLfloat, GLfloat, GLfloat, GLfloat);
WM3_EXTERN pfn_glUniform4f Wm3glUniform4f;
#define glUniform4f Wm3glUniform4f

typedef void (APIENTRY* pfn_glUniform1i) (GLint, GLint);
WM3_EXTERN pfn_glUniform1i Wm3glUniform1i;
#define glUniform1i Wm3glUniform1i

typedef void (APIENTRY* pfn_glUniform2i) (GLint, GLint, GLint);
WM3_EXTERN pfn_glUniform2i Wm3glUniform2i;
#define glUniform2i Wm3glUniform2i

typedef void (APIENTRY* pfn_glUniform3i) (GLint, GLint, GLint, GLint);
WM3_EXTERN pfn_glUniform3i Wm3glUniform3i;
#define glUniform3i Wm3glUniform3i

typedef void (APIENTRY* pfn_glUniform4i) (GLint, GLint, GLint, GLint, GLint);
WM3_EXTERN pfn_glUniform4i Wm3glUniform4i;
#define glUniform4i Wm3glUniform4i

typedef void (APIENTRY* pfn_glUniform1fv) (GLint, GLsizei, const GLfloat*);
WM3_EXTERN pfn_glUniform1fv Wm3glUniform1fv;
#define glUniform1fv Wm3glUniform1fv

typedef void (APIENTRY* pfn_glUniform2fv) (GLint, GLsizei, const GLfloat*);
WM3_EXTERN pfn_glUniform2fv Wm3glUniform2fv;
#define glUniform2fv Wm3glUniform2fv

typedef void (APIENTRY* pfn_glUniform3fv) (GLint, GLsizei, const GLfloat*);
WM3_EXTERN pfn_glUniform3fv Wm3glUniform3fv;
#define glUniform3fv Wm3glUniform3fv

typedef void (APIENTRY* pfn_glUniform4fv) (GLint, GLsizei, const GLfloat*);
WM3_EXTERN pfn_glUniform4fv Wm3glUniform4fv;
#define glUniform4fv Wm3glUniform4fv

typedef void (APIENTRY* pfn_glUniform1iv) (GLint, GLsizei, const GLint*);
WM3_EXTERN pfn_glUniform1iv Wm3glUniform1iv;
#define glUniform1iv Wm3glUniform1iv

typedef void (APIENTRY* pfn_glUniform2iv) (GLint, GLsizei, const GLint*);
WM3_EXTERN pfn_glUniform2iv Wm3glUniform2iv;
#define glUniform2iv Wm3glUniform2iv

typedef void (APIENTRY* pfn_glUniform3iv) (GLint, GLsizei, const GLint*);
WM3_EXTERN pfn_glUniform3iv Wm3glUniform3iv;
#define glUniform3iv Wm3glUniform3iv

typedef void (APIENTRY* pfn_glUniform4iv) (GLint, GLsizei, const GLint*);
WM3_EXTERN pfn_glUniform4iv Wm3glUniform4iv;
#define glUniform4iv Wm3glUniform4iv

typedef void (APIENTRY* pfn_glUniformMatrix2fv) (GLint, GLsizei, GLboolean, const GLfloat*);
WM3_EXTERN pfn_glUniformMatrix2fv Wm3glUniformMatrix2fv;
#define glUniformMatrix2fv Wm3glUniformMatrix2fv

typedef void (APIENTRY* pfn_glUniformMatrix3fv) (GLint, GLsizei, GLboolean, const GLfloat*);
WM3_EXTERN pfn_glUniformMatrix3fv Wm3glUniformMatrix3fv;
#define glUniformMatrix3fv Wm3glUniformMatrix3fv

typedef void (APIENTRY* pfn_glUniformMatrix4fv) (GLint, GLsizei, GLboolean, const GLfloat*);
WM3_EXTERN pfn_glUniformMatrix4fv Wm3glUniformMatrix4fv;
#define glUniformMatrix4fv Wm3glUniformMatrix4fv

typedef void (APIENTRY* pfn_glValidateProgram) (GLuint);
WM3_EXTERN pfn_glValidateProgram Wm3glValidateProgram;
#define glValidateProgram Wm3glValidateProgram

typedef void (APIENTRY* pfn_glVertexAttrib1d) (GLuint, GLdouble);
WM3_EXTERN pfn_glVertexAttrib1d Wm3glVertexAttrib1d;
#define glVertexAttrib1d Wm3glVertexAttrib1d

typedef void (APIENTRY* pfn_glVertexAttrib1dv) (GLuint, const GLdouble*);
WM3_EXTERN pfn_glVertexAttrib1dv Wm3glVertexAttrib1dv;
#define glVertexAttrib1dv Wm3glVertexAttrib1dv

typedef void (APIENTRY* pfn_glVertexAttrib1f) (GLuint, GLfloat);
WM3_EXTERN pfn_glVertexAttrib1f Wm3glVertexAttrib1f;
#define glVertexAttrib1f Wm3glVertexAttrib1f

typedef void (APIENTRY* pfn_glVertexAttrib1fv) (GLuint, const GLfloat*);
WM3_EXTERN pfn_glVertexAttrib1fv Wm3glVertexAttrib1fv;
#define glVertexAttrib1fv Wm3glVertexAttrib1fv

typedef void (APIENTRY* pfn_glVertexAttrib1s) (GLuint, GLshort);
WM3_EXTERN pfn_glVertexAttrib1s Wm3glVertexAttrib1s;
#define glVertexAttrib1s Wm3glVertexAttrib1s

typedef void (APIENTRY* pfn_glVertexAttrib1sv) (GLuint, const GLshort*);
WM3_EXTERN pfn_glVertexAttrib1sv Wm3glVertexAttrib1sv;
#define glVertexAttrib1sv Wm3glVertexAttrib1sv

typedef void (APIENTRY* pfn_glVertexAttrib2d) (GLuint, GLdouble, GLdouble);
WM3_EXTERN pfn_glVertexAttrib2d Wm3glVertexAttrib2d;
#define glVertexAttrib2d Wm3glVertexAttrib2d

typedef void (APIENTRY* pfn_glVertexAttrib2dv) (GLuint, const GLdouble*);
WM3_EXTERN pfn_glVertexAttrib2dv Wm3glVertexAttrib2dv;
#define glVertexAttrib2dv Wm3glVertexAttrib2dv

typedef void (APIENTRY* pfn_glVertexAttrib2f) (GLuint, GLfloat, GLfloat);
WM3_EXTERN pfn_glVertexAttrib2f Wm3glVertexAttrib2f;
#define glVertexAttrib2f Wm3glVertexAttrib2f

typedef void (APIENTRY* pfn_glVertexAttrib2fv) (GLuint, const GLfloat*);
WM3_EXTERN pfn_glVertexAttrib2fv Wm3glVertexAttrib2fv;
#define glVertexAttrib2fv Wm3glVertexAttrib2fv

typedef void (APIENTRY* pfn_glVertexAttrib2s) (GLuint, GLshort, GLshort);
WM3_EXTERN pfn_glVertexAttrib2s Wm3glVertexAttrib2s;
#define glVertexAttrib2s Wm3glVertexAttrib2s

typedef void (APIENTRY* pfn_glVertexAttrib2sv) (GLuint, const GLshort*);
WM3_EXTERN pfn_glVertexAttrib2sv Wm3glVertexAttrib2sv;
#define glVertexAttrib2sv Wm3glVertexAttrib2sv

typedef void (APIENTRY* pfn_glVertexAttrib3d) (GLuint, GLdouble, GLdouble, GLdouble);
WM3_EXTERN pfn_glVertexAttrib3d Wm3glVertexAttrib3d;
#define glVertexAttrib3d Wm3glVertexAttrib3d

typedef void (APIENTRY* pfn_glVertexAttrib3dv) (GLuint, const GLdouble*);
WM3_EXTERN pfn_glVertexAttrib3dv Wm3glVertexAttrib3dv;
#define glVertexAttrib3dv Wm3glVertexAttrib3dv

typedef void (APIENTRY* pfn_glVertexAttrib3f) (GLuint, GLfloat, GLfloat, GLfloat);
WM3_EXTERN pfn_glVertexAttrib3f Wm3glVertexAttrib3f;
#define glVertexAttrib3f Wm3glVertexAttrib3f

typedef void (APIENTRY* pfn_glVertexAttrib3fv) (GLuint, const GLfloat*);
WM3_EXTERN pfn_glVertexAttrib3fv Wm3glVertexAttrib3fv;
#define glVertexAttrib3fv Wm3glVertexAttrib3fv

typedef void (APIENTRY* pfn_glVertexAttrib3s) (GLuint, GLshort, GLshort, GLshort);
WM3_EXTERN pfn_glVertexAttrib3s Wm3glVertexAttrib3s;
#define glVertexAttrib3s Wm3glVertexAttrib3s

typedef void (APIENTRY* pfn_glVertexAttrib3sv) (GLuint, const GLshort*);
WM3_EXTERN pfn_glVertexAttrib3sv Wm3glVertexAttrib3sv;
#define glVertexAttrib3sv Wm3glVertexAttrib3sv

typedef void (APIENTRY* pfn_glVertexAttrib4Nbv) (GLuint, const GLbyte*);
WM3_EXTERN pfn_glVertexAttrib4Nbv Wm3glVertexAttrib4Nbv;
#define glVertexAttrib4Nbv Wm3glVertexAttrib4Nbv

typedef void (APIENTRY* pfn_glVertexAttrib4Niv) (GLuint, const GLint*);
WM3_EXTERN pfn_glVertexAttrib4Niv Wm3glVertexAttrib4Niv;
#define glVertexAttrib4Niv Wm3glVertexAttrib4Niv

typedef void (APIENTRY* pfn_glVertexAttrib4Nsv) (GLuint, const GLshort*);
WM3_EXTERN pfn_glVertexAttrib4Nsv Wm3glVertexAttrib4Nsv;
#define glVertexAttrib4Nsv Wm3glVertexAttrib4Nsv

typedef void (APIENTRY* pfn_glVertexAttrib4Nub) (GLuint, GLubyte, GLubyte, GLubyte, GLubyte);
WM3_EXTERN pfn_glVertexAttrib4Nub Wm3glVertexAttrib4Nub;
#define glVertexAttrib4Nub Wm3glVertexAttrib4Nub

typedef void (APIENTRY* pfn_glVertexAttrib4Nubv) (GLuint, const GLubyte*);
WM3_EXTERN pfn_glVertexAttrib4Nubv Wm3glVertexAttrib4Nubv;
#define glVertexAttrib4Nubv Wm3glVertexAttrib4Nubv

typedef void (APIENTRY* pfn_glVertexAttrib4Nuiv) (GLuint, const GLuint*);
WM3_EXTERN pfn_glVertexAttrib4Nuiv Wm3glVertexAttrib4Nuiv;
#define glVertexAttrib4Nuiv Wm3glVertexAttrib4Nuiv

typedef void (APIENTRY* pfn_glVertexAttrib4Nusv) (GLuint, const GLushort*);
WM3_EXTERN pfn_glVertexAttrib4Nusv Wm3glVertexAttrib4Nusv;
#define glVertexAttrib4Nusv Wm3glVertexAttrib4Nusv

typedef void (APIENTRY* pfn_glVertexAttrib4bv) (GLuint, const GLbyte*);
WM3_EXTERN pfn_glVertexAttrib4bv Wm3glVertexAttrib4bv;
#define glVertexAttrib4bv Wm3glVertexAttrib4bv

typedef void (APIENTRY* pfn_glVertexAttrib4d) (GLuint, GLdouble, GLdouble, GLdouble, GLdouble);
WM3_EXTERN pfn_glVertexAttrib4d Wm3glVertexAttrib4d;
#define glVertexAttrib4d Wm3glVertexAttrib4d

typedef void (APIENTRY* pfn_glVertexAttrib4dv) (GLuint, const GLdouble*);
WM3_EXTERN pfn_glVertexAttrib4dv Wm3glVertexAttrib4dv;
#define glVertexAttrib4dv Wm3glVertexAttrib4dv

typedef void (APIENTRY* pfn_glVertexAttrib4f) (GLuint, GLfloat, GLfloat, GLfloat, GLfloat);
WM3_EXTERN pfn_glVertexAttrib4f Wm3glVertexAttrib4f;
#define glVertexAttrib4f Wm3glVertexAttrib4f

typedef void (APIENTRY* pfn_glVertexAttrib4fv) (GLuint, const GLfloat*);
WM3_EXTERN pfn_glVertexAttrib4fv Wm3glVertexAttrib4fv;
#define glVertexAttrib4fv Wm3glVertexAttrib4fv

typedef void (APIENTRY* pfn_glVertexAttrib4iv) (GLuint, const GLint*);
WM3_EXTERN pfn_glVertexAttrib4iv Wm3glVertexAttrib4iv;
#define glVertexAttrib4iv Wm3glVertexAttrib4iv

typedef void (APIENTRY* pfn_glVertexAttrib4s) (GLuint, GLshort, GLshort, GLshort, GLshort);
WM3_EXTERN pfn_glVertexAttrib4s Wm3glVertexAttrib4s;
#define glVertexAttrib4s Wm3glVertexAttrib4s

typedef void (APIENTRY* pfn_glVertexAttrib4sv) (GLuint, const GLshort*);
WM3_EXTERN pfn_glVertexAttrib4sv Wm3glVertexAttrib4sv;
#define glVertexAttrib4sv Wm3glVertexAttrib4sv

typedef void (APIENTRY* pfn_glVertexAttrib4ubv) (GLuint, const GLubyte*);
WM3_EXTERN pfn_glVertexAttrib4ubv Wm3glVertexAttrib4ubv;
#define glVertexAttrib4ubv Wm3glVertexAttrib4ubv

typedef void (APIENTRY* pfn_glVertexAttrib4uiv) (GLuint, const GLuint*);
WM3_EXTERN pfn_glVertexAttrib4uiv Wm3glVertexAttrib4uiv;
#define glVertexAttrib4uiv Wm3glVertexAttrib4uiv

typedef void (APIENTRY* pfn_glVertexAttrib4usv) (GLuint, const GLushort*);
WM3_EXTERN pfn_glVertexAttrib4usv Wm3glVertexAttrib4usv;
#define glVertexAttrib4usv Wm3glVertexAttrib4usv

typedef void (APIENTRY* pfn_glVertexAttribPointer) (GLuint, GLint, GLenum, GLboolean, GLsizei, const GLvoid*);
WM3_EXTERN pfn_glVertexAttribPointer Wm3glVertexAttribPointer;
#define glVertexAttribPointer Wm3glVertexAttribPointer
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_ARB_imaging;
WM3_EXTERN int Wm3NumFunctions_GL_ARB_imaging;
#ifndef GL_ARB_imaging
#define GL_ARB_imaging
#define WM3_DEFINED_GL_ARB_imaging
#define GL_CONSTANT_COLOR                       0x8001
#define GL_ONE_MINUS_CONSTANT_COLOR             0x8002
#define GL_CONSTANT_ALPHA                       0x8003
#define GL_ONE_MINUS_CONSTANT_ALPHA             0x8004
#define GL_BLEND_COLOR                          0x8005
#define GL_FUNC_ADD                             0x8006
#define GL_MIN                                  0x8007
#define GL_MAX                                  0x8008
#define GL_BLEND_EQUATION                       0x8009
#define GL_FUNC_SUBTRACT                        0x800A
#define GL_FUNC_REVERSE_SUBTRACT                0x800B
#define GL_CONVOLUTION_1D                       0x8010
#define GL_CONVOLUTION_2D                       0x8011
#define GL_SEPARABLE_2D                         0x8012
#define GL_CONVOLUTION_BORDER_MODE              0x8013
#define GL_CONVOLUTION_FILTER_SCALE             0x8014
#define GL_CONVOLUTION_FILTER_BIAS              0x8015
#define GL_REDUCE                               0x8016
#define GL_CONVOLUTION_FORMAT                   0x8017
#define GL_CONVOLUTION_WIDTH                    0x8018
#define GL_CONVOLUTION_HEIGHT                   0x8019
#define GL_MAX_CONVOLUTION_WIDTH                0x801A
#define GL_MAX_CONVOLUTION_HEIGHT               0x801B
#define GL_POST_CONVOLUTION_RED_SCALE           0x801C
#define GL_POST_CONVOLUTION_GREEN_SCALE         0x801D
#define GL_POST_CONVOLUTION_BLUE_SCALE          0x801E
#define GL_POST_CONVOLUTION_ALPHA_SCALE         0x801F
#define GL_POST_CONVOLUTION_RED_BIAS            0x8020
#define GL_POST_CONVOLUTION_GREEN_BIAS          0x8021
#define GL_POST_CONVOLUTION_BLUE_BIAS           0x8022
#define GL_POST_CONVOLUTION_ALPHA_BIAS          0x8023
#define GL_HISTOGRAM                            0x8024
#define GL_PROXY_HISTOGRAM                      0x8025
#define GL_HISTOGRAM_WIDTH                      0x8026
#define GL_HISTOGRAM_FORMAT                     0x8027
#define GL_HISTOGRAM_RED_SIZE                   0x8028
#define GL_HISTOGRAM_GREEN_SIZE                 0x8029
#define GL_HISTOGRAM_BLUE_SIZE                  0x802A
#define GL_HISTOGRAM_ALPHA_SIZE                 0x802B
#define GL_HISTOGRAM_LUMINANCE_SIZE             0x802C
#define GL_HISTOGRAM_SINK                       0x802D
#define GL_MINMAX                               0x802E
#define GL_MINMAX_FORMAT                        0x802F
#define GL_MINMAX_SINK                          0x8030
#define GL_TABLE_TOO_LARGE                      0x8031
#define GL_COLOR_MATRIX                         0x80B1
#define GL_COLOR_MATRIX_STACK_DEPTH             0x80B2
#define GL_MAX_COLOR_MATRIX_STACK_DEPTH         0x80B3
#define GL_POST_COLOR_MATRIX_RED_SCALE          0x80B4
#define GL_POST_COLOR_MATRIX_GREEN_SCALE        0x80B5
#define GL_POST_COLOR_MATRIX_BLUE_SCALE         0x80B6
#define GL_POST_COLOR_MATRIX_ALPHA_SCALE        0x80B7
#define GL_POST_COLOR_MATRIX_RED_BIAS           0x80B8
#define GL_POST_COLOR_MATRIX_GREEN_BIAS         0x80B9
#define GL_POST_COLOR_MATRIX_BLUE_BIAS          0x80BA
#define GL_POST_COLOR_MATRIX_ALPHA_BIAS         0x80BB
#define GL_COLOR_TABLE                          0x80D0
#define GL_POST_CONVOLUTION_COLOR_TABLE         0x80D1
#define GL_POST_COLOR_MATRIX_COLOR_TABLE        0x80D2
#define GL_PROXY_COLOR_TABLE                    0x80D3
#define GL_PROXY_POST_CONVOLUTION_COLOR_TABLE   0x80D4
#define GL_PROXY_POST_COLOR_MATRIX_COLOR_TABLE  0x80D5
#define GL_COLOR_TABLE_SCALE                    0x80D6
#define GL_COLOR_TABLE_BIAS                     0x80D7
#define GL_COLOR_TABLE_FORMAT                   0x80D8
#define GL_COLOR_TABLE_WIDTH                    0x80D9
#define GL_COLOR_TABLE_RED_SIZE                 0x80DA
#define GL_COLOR_TABLE_GREEN_SIZE               0x80DB
#define GL_COLOR_TABLE_BLUE_SIZE                0x80DC
#define GL_COLOR_TABLE_ALPHA_SIZE               0x80DD
#define GL_COLOR_TABLE_LUMINANCE_SIZE           0x80DE
#define GL_COLOR_TABLE_INTENSITY_SIZE           0x80DF
#define GL_CONSTANT_BORDER                      0x8151
#define GL_REPLICATE_BORDER                     0x8153
#define GL_CONVOLUTION_BORDER_COLOR             0x8154
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_ARB_multitexture;
WM3_EXTERN int Wm3NumFunctions_GL_ARB_multitexture;
#ifndef GL_ARB_multitexture
#define GL_ARB_multitexture
#define WM3_DEFINED_GL_ARB_multitexture
#define GL_TEXTURE0_ARB                   0x84C0
#define GL_TEXTURE1_ARB                   0x84C1
#define GL_TEXTURE2_ARB                   0x84C2
#define GL_TEXTURE3_ARB                   0x84C3
#define GL_TEXTURE4_ARB                   0x84C4
#define GL_TEXTURE5_ARB                   0x84C5
#define GL_TEXTURE6_ARB                   0x84C6
#define GL_TEXTURE7_ARB                   0x84C7
#define GL_TEXTURE8_ARB                   0x84C8
#define GL_TEXTURE9_ARB                   0x84C9
#define GL_TEXTURE10_ARB                  0x84CA
#define GL_TEXTURE11_ARB                  0x84CB
#define GL_TEXTURE12_ARB                  0x84CC
#define GL_TEXTURE13_ARB                  0x84CD
#define GL_TEXTURE14_ARB                  0x84CE
#define GL_TEXTURE15_ARB                  0x84CF
#define GL_TEXTURE16_ARB                  0x84D0
#define GL_TEXTURE17_ARB                  0x84D1
#define GL_TEXTURE18_ARB                  0x84D2
#define GL_TEXTURE19_ARB                  0x84D3
#define GL_TEXTURE20_ARB                  0x84D4
#define GL_TEXTURE21_ARB                  0x84D5
#define GL_TEXTURE22_ARB                  0x84D6
#define GL_TEXTURE23_ARB                  0x84D7
#define GL_TEXTURE24_ARB                  0x84D8
#define GL_TEXTURE25_ARB                  0x84D9
#define GL_TEXTURE26_ARB                  0x84DA
#define GL_TEXTURE27_ARB                  0x84DB
#define GL_TEXTURE28_ARB                  0x84DC
#define GL_TEXTURE29_ARB                  0x84DD
#define GL_TEXTURE30_ARB                  0x84DE
#define GL_TEXTURE31_ARB                  0x84DF
#define GL_ACTIVE_TEXTURE_ARB             0x84E0
#define GL_CLIENT_ACTIVE_TEXTURE_ARB      0x84E1
#define GL_MAX_TEXTURE_UNITS_ARB          0x84E2

typedef void (APIENTRY* pfn_glActiveTextureARB) (GLenum);
WM3_EXTERN pfn_glActiveTextureARB Wm3glActiveTextureARB;
#define glActiveTextureARB Wm3glActiveTextureARB

typedef void (APIENTRY* pfn_glClientActiveTextureARB) (GLenum);
WM3_EXTERN pfn_glClientActiveTextureARB Wm3glClientActiveTextureARB;
#define glClientActiveTextureARB Wm3glClientActiveTextureARB

typedef void (APIENTRY* pfn_glMultiTexCoord1dARB) (GLenum, GLdouble);
WM3_EXTERN pfn_glMultiTexCoord1dARB Wm3glMultiTexCoord1dARB;
#define glMultiTexCoord1dARB Wm3glMultiTexCoord1dARB

typedef void (APIENTRY* pfn_glMultiTexCoord1dvARB) (GLenum, const GLdouble*);
WM3_EXTERN pfn_glMultiTexCoord1dvARB Wm3glMultiTexCoord1dvARB;
#define glMultiTexCoord1dvARB Wm3glMultiTexCoord1dvARB

typedef void (APIENTRY* pfn_glMultiTexCoord1fARB) (GLenum, GLfloat);
WM3_EXTERN pfn_glMultiTexCoord1fARB Wm3glMultiTexCoord1fARB;
#define glMultiTexCoord1fARB Wm3glMultiTexCoord1fARB

typedef void (APIENTRY* pfn_glMultiTexCoord1fvARB) (GLenum, const GLfloat*);
WM3_EXTERN pfn_glMultiTexCoord1fvARB Wm3glMultiTexCoord1fvARB;
#define glMultiTexCoord1fvARB Wm3glMultiTexCoord1fvARB

typedef void (APIENTRY* pfn_glMultiTexCoord1iARB) (GLenum, GLint);
WM3_EXTERN pfn_glMultiTexCoord1iARB Wm3glMultiTexCoord1iARB;
#define glMultiTexCoord1iARB Wm3glMultiTexCoord1iARB

typedef void (APIENTRY* pfn_glMultiTexCoord1ivARB) (GLenum, const GLint*);
WM3_EXTERN pfn_glMultiTexCoord1ivARB Wm3glMultiTexCoord1ivARB;
#define glMultiTexCoord1ivARB Wm3glMultiTexCoord1ivARB

typedef void (APIENTRY* pfn_glMultiTexCoord1sARB) (GLenum, GLshort);
WM3_EXTERN pfn_glMultiTexCoord1sARB Wm3glMultiTexCoord1sARB;
#define glMultiTexCoord1sARB Wm3glMultiTexCoord1sARB

typedef void (APIENTRY* pfn_glMultiTexCoord1svARB) (GLenum, const GLshort*);
WM3_EXTERN pfn_glMultiTexCoord1svARB Wm3glMultiTexCoord1svARB;
#define glMultiTexCoord1svARB Wm3glMultiTexCoord1svARB

typedef void (APIENTRY* pfn_glMultiTexCoord2dARB) (GLenum, GLdouble, GLdouble);
WM3_EXTERN pfn_glMultiTexCoord2dARB Wm3glMultiTexCoord2dARB;
#define glMultiTexCoord2dARB Wm3glMultiTexCoord2dARB

typedef void (APIENTRY* pfn_glMultiTexCoord2dvARB) (GLenum, const GLdouble*);
WM3_EXTERN pfn_glMultiTexCoord2dvARB Wm3glMultiTexCoord2dvARB;
#define glMultiTexCoord2dvARB Wm3glMultiTexCoord2dvARB

typedef void (APIENTRY* pfn_glMultiTexCoord2fARB) (GLenum, GLfloat, GLfloat);
WM3_EXTERN pfn_glMultiTexCoord2fARB Wm3glMultiTexCoord2fARB;
#define glMultiTexCoord2fARB Wm3glMultiTexCoord2fARB

typedef void (APIENTRY* pfn_glMultiTexCoord2fvARB) (GLenum, const GLfloat*);
WM3_EXTERN pfn_glMultiTexCoord2fvARB Wm3glMultiTexCoord2fvARB;
#define glMultiTexCoord2fvARB Wm3glMultiTexCoord2fvARB

typedef void (APIENTRY* pfn_glMultiTexCoord2iARB) (GLenum, GLint, GLint);
WM3_EXTERN pfn_glMultiTexCoord2iARB Wm3glMultiTexCoord2iARB;
#define glMultiTexCoord2iARB Wm3glMultiTexCoord2iARB

typedef void (APIENTRY* pfn_glMultiTexCoord2ivARB) (GLenum, const GLint*);
WM3_EXTERN pfn_glMultiTexCoord2ivARB Wm3glMultiTexCoord2ivARB;
#define glMultiTexCoord2ivARB Wm3glMultiTexCoord2ivARB

typedef void (APIENTRY* pfn_glMultiTexCoord2sARB) (GLenum, GLshort, GLshort);
WM3_EXTERN pfn_glMultiTexCoord2sARB Wm3glMultiTexCoord2sARB;
#define glMultiTexCoord2sARB Wm3glMultiTexCoord2sARB

typedef void (APIENTRY* pfn_glMultiTexCoord2svARB) (GLenum, const GLshort*);
WM3_EXTERN pfn_glMultiTexCoord2svARB Wm3glMultiTexCoord2svARB;
#define glMultiTexCoord2svARB Wm3glMultiTexCoord2svARB

typedef void (APIENTRY* pfn_glMultiTexCoord3dARB) (GLenum, GLdouble, GLdouble, GLdouble);
WM3_EXTERN pfn_glMultiTexCoord3dARB Wm3glMultiTexCoord3dARB;
#define glMultiTexCoord3dARB Wm3glMultiTexCoord3dARB

typedef void (APIENTRY* pfn_glMultiTexCoord3dvARB) (GLenum, const GLdouble*);
WM3_EXTERN pfn_glMultiTexCoord3dvARB Wm3glMultiTexCoord3dvARB;
#define glMultiTexCoord3dvARB Wm3glMultiTexCoord3dvARB

typedef void (APIENTRY* pfn_glMultiTexCoord3fARB) (GLenum, GLfloat, GLfloat, GLfloat);
WM3_EXTERN pfn_glMultiTexCoord3fARB Wm3glMultiTexCoord3fARB;
#define glMultiTexCoord3fARB Wm3glMultiTexCoord3fARB

typedef void (APIENTRY* pfn_glMultiTexCoord3fvARB) (GLenum, const GLfloat*);
WM3_EXTERN pfn_glMultiTexCoord3fvARB Wm3glMultiTexCoord3fvARB;
#define glMultiTexCoord3fvARB Wm3glMultiTexCoord3fvARB

typedef void (APIENTRY* pfn_glMultiTexCoord3iARB) (GLenum, GLint, GLint, GLint);
WM3_EXTERN pfn_glMultiTexCoord3iARB Wm3glMultiTexCoord3iARB;
#define glMultiTexCoord3iARB Wm3glMultiTexCoord3iARB

typedef void (APIENTRY* pfn_glMultiTexCoord3ivARB) (GLenum, const GLint*);
WM3_EXTERN pfn_glMultiTexCoord3ivARB Wm3glMultiTexCoord3ivARB;
#define glMultiTexCoord3ivARB Wm3glMultiTexCoord3ivARB

typedef void (APIENTRY* pfn_glMultiTexCoord3sARB) (GLenum, GLshort, GLshort, GLshort);
WM3_EXTERN pfn_glMultiTexCoord3sARB Wm3glMultiTexCoord3sARB;
#define glMultiTexCoord3sARB Wm3glMultiTexCoord3sARB

typedef void (APIENTRY* pfn_glMultiTexCoord3svARB) (GLenum, const GLshort*);
WM3_EXTERN pfn_glMultiTexCoord3svARB Wm3glMultiTexCoord3svARB;
#define glMultiTexCoord3svARB Wm3glMultiTexCoord3svARB

typedef void (APIENTRY* pfn_glMultiTexCoord4dARB) (GLenum, GLdouble, GLdouble, GLdouble, GLdouble);
WM3_EXTERN pfn_glMultiTexCoord4dARB Wm3glMultiTexCoord4dARB;
#define glMultiTexCoord4dARB Wm3glMultiTexCoord4dARB

typedef void (APIENTRY* pfn_glMultiTexCoord4dvARB) (GLenum, const GLdouble*);
WM3_EXTERN pfn_glMultiTexCoord4dvARB Wm3glMultiTexCoord4dvARB;
#define glMultiTexCoord4dvARB Wm3glMultiTexCoord4dvARB

typedef void (APIENTRY* pfn_glMultiTexCoord4fARB) (GLenum, GLfloat, GLfloat, GLfloat, GLfloat);
WM3_EXTERN pfn_glMultiTexCoord4fARB Wm3glMultiTexCoord4fARB;
#define glMultiTexCoord4fARB Wm3glMultiTexCoord4fARB

typedef void (APIENTRY* pfn_glMultiTexCoord4fvARB) (GLenum, const GLfloat*);
WM3_EXTERN pfn_glMultiTexCoord4fvARB Wm3glMultiTexCoord4fvARB;
#define glMultiTexCoord4fvARB Wm3glMultiTexCoord4fvARB

typedef void (APIENTRY* pfn_glMultiTexCoord4iARB) (GLenum, GLint, GLint, GLint, GLint);
WM3_EXTERN pfn_glMultiTexCoord4iARB Wm3glMultiTexCoord4iARB;
#define glMultiTexCoord4iARB Wm3glMultiTexCoord4iARB

typedef void (APIENTRY* pfn_glMultiTexCoord4ivARB) (GLenum, const GLint*);
WM3_EXTERN pfn_glMultiTexCoord4ivARB Wm3glMultiTexCoord4ivARB;
#define glMultiTexCoord4ivARB Wm3glMultiTexCoord4ivARB

typedef void (APIENTRY* pfn_glMultiTexCoord4sARB) (GLenum, GLshort, GLshort, GLshort, GLshort);
WM3_EXTERN pfn_glMultiTexCoord4sARB Wm3glMultiTexCoord4sARB;
#define glMultiTexCoord4sARB Wm3glMultiTexCoord4sARB

typedef void (APIENTRY* pfn_glMultiTexCoord4svARB) (GLenum, const GLshort*);
WM3_EXTERN pfn_glMultiTexCoord4svARB Wm3glMultiTexCoord4svARB;
#define glMultiTexCoord4svARB Wm3glMultiTexCoord4svARB
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_ARB_transpose_matrix;
WM3_EXTERN int Wm3NumFunctions_GL_ARB_transpose_matrix;
#ifndef GL_ARB_transpose_matrix
#define GL_ARB_transpose_matrix
#define WM3_DEFINED_GL_ARB_transpose_matrix
#define GL_TRANSPOSE_MODELVIEW_MATRIX_ARB   0x84E3
#define GL_TRANSPOSE_PROJECTION_MATRIX_ARB  0x84E4
#define GL_TRANSPOSE_TEXTURE_MATRIX_ARB     0x84E5
#define GL_TRANSPOSE_COLOR_MATRIX_ARB       0x84E6

typedef void (APIENTRY* pfn_glLoadTransposeMatrixfARB) (const GLfloat*);
WM3_EXTERN pfn_glLoadTransposeMatrixfARB Wm3glLoadTransposeMatrixfARB;
#define glLoadTransposeMatrixfARB Wm3glLoadTransposeMatrixfARB

typedef void (APIENTRY* pfn_glLoadTransposeMatrixdARB) (const GLdouble*);
WM3_EXTERN pfn_glLoadTransposeMatrixdARB Wm3glLoadTransposeMatrixdARB;
#define glLoadTransposeMatrixdARB Wm3glLoadTransposeMatrixdARB

typedef void (APIENTRY* pfn_glMultTransposeMatrixfARB) (const GLfloat*);
WM3_EXTERN pfn_glMultTransposeMatrixfARB Wm3glMultTransposeMatrixfARB;
#define glMultTransposeMatrixfARB Wm3glMultTransposeMatrixfARB

typedef void (APIENTRY* pfn_glMultTransposeMatrixdARB) (const GLdouble*);
WM3_EXTERN pfn_glMultTransposeMatrixdARB Wm3glMultTransposeMatrixdARB;
#define glMultTransposeMatrixdARB Wm3glMultTransposeMatrixdARB
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_ARB_multisample;
WM3_EXTERN int Wm3NumFunctions_GL_ARB_multisample;
#ifndef GL_ARB_multisample
#define GL_ARB_multisample
#define WM3_DEFINED_GL_ARB_multisample
#define GL_MULTISAMPLE_ARB                0x809D
#define GL_SAMPLE_ALPHA_TO_COVERAGE_ARB   0x809E
#define GL_SAMPLE_ALPHA_TO_ONE_ARB        0x809F
#define GL_SAMPLE_COVERAGE_ARB            0x80A0
#define GL_SAMPLE_BUFFERS_ARB             0x80A8
#define GL_SAMPLES_ARB                    0x80A9
#define GL_SAMPLE_COVERAGE_VALUE_ARB      0x80AA
#define GL_SAMPLE_COVERAGE_INVERT_ARB     0x80AB
#define GL_MULTISAMPLE_BIT_ARB            0x20000000

typedef void (APIENTRY* pfn_glSampleCoverageARB) (GLclampf, GLboolean);
WM3_EXTERN pfn_glSampleCoverageARB Wm3glSampleCoverageARB;
#define glSampleCoverageARB Wm3glSampleCoverageARB
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_ARB_texture_env_add;
WM3_EXTERN int Wm3NumFunctions_GL_ARB_texture_env_add;
#ifndef GL_ARB_texture_env_add
#define GL_ARB_texture_env_add
#define WM3_DEFINED_GL_ARB_texture_env_add
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_ARB_texture_cube_map;
WM3_EXTERN int Wm3NumFunctions_GL_ARB_texture_cube_map;
#ifndef GL_ARB_texture_cube_map
#define GL_ARB_texture_cube_map
#define WM3_DEFINED_GL_ARB_texture_cube_map
#define GL_NORMAL_MAP_ARB                   0x8511
#define GL_REFLECTION_MAP_ARB               0x8512
#define GL_TEXTURE_CUBE_MAP_ARB             0x8513
#define GL_TEXTURE_BINDING_CUBE_MAP_ARB     0x8514
#define GL_TEXTURE_CUBE_MAP_POSITIVE_X_ARB  0x8515
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_X_ARB  0x8516
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Y_ARB  0x8517
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Y_ARB  0x8518
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Z_ARB  0x8519
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Z_ARB  0x851A
#define GL_PROXY_TEXTURE_CUBE_MAP_ARB       0x851B
#define GL_MAX_CUBE_MAP_TEXTURE_SIZE_ARB    0x851C
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_ARB_texture_compression;
WM3_EXTERN int Wm3NumFunctions_GL_ARB_texture_compression;
#ifndef GL_ARB_texture_compression
#define GL_ARB_texture_compression
#define WM3_DEFINED_GL_ARB_texture_compression
#define GL_COMPRESSED_ALPHA_ARB                 0x84E9
#define GL_COMPRESSED_LUMINANCE_ARB             0x84EA
#define GL_COMPRESSED_LUMINANCE_ALPHA_ARB       0x84EB
#define GL_COMPRESSED_INTENSITY_ARB             0x84EC
#define GL_COMPRESSED_RGB_ARB                   0x84ED
#define GL_COMPRESSED_RGBA_ARB                  0x84EE
#define GL_TEXTURE_COMPRESSION_HINT_ARB         0x84EF
#define GL_TEXTURE_COMPRESSED_IMAGE_SIZE_ARB    0x86A0
#define GL_TEXTURE_COMPRESSED_ARB               0x86A1
#define GL_NUM_COMPRESSED_TEXTURE_FORMATS_ARB   0x86A2
#define GL_COMPRESSED_TEXTURE_FORMATS_ARB       0x86A3

typedef void (APIENTRY* pfn_glCompressedTexImage3DARB) (GLenum, GLint, GLenum, GLsizei, GLsizei, GLsizei, GLint, GLsizei, const GLvoid*);
WM3_EXTERN pfn_glCompressedTexImage3DARB Wm3glCompressedTexImage3DARB;
#define glCompressedTexImage3DARB Wm3glCompressedTexImage3DARB

typedef void (APIENTRY* pfn_glCompressedTexImage2DARB) (GLenum, GLint, GLenum, GLsizei, GLsizei, GLint, GLsizei, const GLvoid*);
WM3_EXTERN pfn_glCompressedTexImage2DARB Wm3glCompressedTexImage2DARB;
#define glCompressedTexImage2DARB Wm3glCompressedTexImage2DARB

typedef void (APIENTRY* pfn_glCompressedTexImage1DARB) (GLenum, GLint, GLenum, GLsizei, GLint, GLsizei, const GLvoid*);
WM3_EXTERN pfn_glCompressedTexImage1DARB Wm3glCompressedTexImage1DARB;
#define glCompressedTexImage1DARB Wm3glCompressedTexImage1DARB

typedef void (APIENTRY* pfn_glCompressedTexSubImage3DARB) (GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLsizei, const GLvoid*);
WM3_EXTERN pfn_glCompressedTexSubImage3DARB Wm3glCompressedTexSubImage3DARB;
#define glCompressedTexSubImage3DARB Wm3glCompressedTexSubImage3DARB

typedef void (APIENTRY* pfn_glCompressedTexSubImage2DARB) (GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLsizei, const GLvoid*);
WM3_EXTERN pfn_glCompressedTexSubImage2DARB Wm3glCompressedTexSubImage2DARB;
#define glCompressedTexSubImage2DARB Wm3glCompressedTexSubImage2DARB

typedef void (APIENTRY* pfn_glCompressedTexSubImage1DARB) (GLenum, GLint, GLint, GLsizei, GLenum, GLsizei, const GLvoid*);
WM3_EXTERN pfn_glCompressedTexSubImage1DARB Wm3glCompressedTexSubImage1DARB;
#define glCompressedTexSubImage1DARB Wm3glCompressedTexSubImage1DARB

typedef void (APIENTRY* pfn_glGetCompressedTexImageARB) (GLenum, GLint, GLvoid*);
WM3_EXTERN pfn_glGetCompressedTexImageARB Wm3glGetCompressedTexImageARB;
#define glGetCompressedTexImageARB Wm3glGetCompressedTexImageARB
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_ARB_texture_border_clamp;
WM3_EXTERN int Wm3NumFunctions_GL_ARB_texture_border_clamp;
#ifndef GL_ARB_texture_border_clamp
#define GL_ARB_texture_border_clamp
#define WM3_DEFINED_GL_ARB_texture_border_clamp
#define GL_CLAMP_TO_BORDER_ARB            0x812D
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_ARB_point_parameters;
WM3_EXTERN int Wm3NumFunctions_GL_ARB_point_parameters;
#ifndef GL_ARB_point_parameters
#define GL_ARB_point_parameters
#define WM3_DEFINED_GL_ARB_point_parameters
#define GL_POINT_SIZE_MIN_ARB             0x8126
#define GL_POINT_SIZE_MAX_ARB             0x8127
#define GL_POINT_FADE_THRESHOLD_SIZE_ARB  0x8128
#define GL_POINT_DISTANCE_ATTENUATION_ARB 0x8129

typedef void (APIENTRY* pfn_glPointParameterfARB) (GLenum, GLfloat);
WM3_EXTERN pfn_glPointParameterfARB Wm3glPointParameterfARB;
#define glPointParameterfARB Wm3glPointParameterfARB

typedef void (APIENTRY* pfn_glPointParameterfvARB) (GLenum, const GLfloat*);
WM3_EXTERN pfn_glPointParameterfvARB Wm3glPointParameterfvARB;
#define glPointParameterfvARB Wm3glPointParameterfvARB
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_ARB_vertex_blend;
WM3_EXTERN int Wm3NumFunctions_GL_ARB_vertex_blend;
#ifndef GL_ARB_vertex_blend
#define GL_ARB_vertex_blend
#define WM3_DEFINED_GL_ARB_vertex_blend
#define GL_MAX_VERTEX_UNITS_ARB           0x86A4
#define GL_ACTIVE_VERTEX_UNITS_ARB        0x86A5
#define GL_WEIGHT_SUM_UNITY_ARB           0x86A6
#define GL_VERTEX_BLEND_ARB               0x86A7
#define GL_CURRENT_WEIGHT_ARB             0x86A8
#define GL_WEIGHT_ARRAY_TYPE_ARB          0x86A9
#define GL_WEIGHT_ARRAY_STRIDE_ARB        0x86AA
#define GL_WEIGHT_ARRAY_SIZE_ARB          0x86AB
#define GL_WEIGHT_ARRAY_POINTER_ARB       0x86AC
#define GL_WEIGHT_ARRAY_ARB               0x86AD
#define GL_MODELVIEW0_ARB                 0x1700
#define GL_MODELVIEW1_ARB                 0x850A
#define GL_MODELVIEW2_ARB                 0x8722
#define GL_MODELVIEW3_ARB                 0x8723
#define GL_MODELVIEW4_ARB                 0x8724
#define GL_MODELVIEW5_ARB                 0x8725
#define GL_MODELVIEW6_ARB                 0x8726
#define GL_MODELVIEW7_ARB                 0x8727
#define GL_MODELVIEW8_ARB                 0x8728
#define GL_MODELVIEW9_ARB                 0x8729
#define GL_MODELVIEW10_ARB                0x872A
#define GL_MODELVIEW11_ARB                0x872B
#define GL_MODELVIEW12_ARB                0x872C
#define GL_MODELVIEW13_ARB                0x872D
#define GL_MODELVIEW14_ARB                0x872E
#define GL_MODELVIEW15_ARB                0x872F
#define GL_MODELVIEW16_ARB                0x8730
#define GL_MODELVIEW17_ARB                0x8731
#define GL_MODELVIEW18_ARB                0x8732
#define GL_MODELVIEW19_ARB                0x8733
#define GL_MODELVIEW20_ARB                0x8734
#define GL_MODELVIEW21_ARB                0x8735
#define GL_MODELVIEW22_ARB                0x8736
#define GL_MODELVIEW23_ARB                0x8737
#define GL_MODELVIEW24_ARB                0x8738
#define GL_MODELVIEW25_ARB                0x8739
#define GL_MODELVIEW26_ARB                0x873A
#define GL_MODELVIEW27_ARB                0x873B
#define GL_MODELVIEW28_ARB                0x873C
#define GL_MODELVIEW29_ARB                0x873D
#define GL_MODELVIEW30_ARB                0x873E
#define GL_MODELVIEW31_ARB                0x873F

typedef void (APIENTRY* pfn_glWeightbvARB) (GLint, const GLbyte*);
WM3_EXTERN pfn_glWeightbvARB Wm3glWeightbvARB;
#define glWeightbvARB Wm3glWeightbvARB

typedef void (APIENTRY* pfn_glWeightsvARB) (GLint, const GLshort*);
WM3_EXTERN pfn_glWeightsvARB Wm3glWeightsvARB;
#define glWeightsvARB Wm3glWeightsvARB

typedef void (APIENTRY* pfn_glWeightivARB) (GLint, const GLint*);
WM3_EXTERN pfn_glWeightivARB Wm3glWeightivARB;
#define glWeightivARB Wm3glWeightivARB

typedef void (APIENTRY* pfn_glWeightfvARB) (GLint, const GLfloat*);
WM3_EXTERN pfn_glWeightfvARB Wm3glWeightfvARB;
#define glWeightfvARB Wm3glWeightfvARB

typedef void (APIENTRY* pfn_glWeightdvARB) (GLint, const GLdouble*);
WM3_EXTERN pfn_glWeightdvARB Wm3glWeightdvARB;
#define glWeightdvARB Wm3glWeightdvARB

typedef void (APIENTRY* pfn_glWeightubvARB) (GLint, const GLubyte*);
WM3_EXTERN pfn_glWeightubvARB Wm3glWeightubvARB;
#define glWeightubvARB Wm3glWeightubvARB

typedef void (APIENTRY* pfn_glWeightusvARB) (GLint, const GLushort*);
WM3_EXTERN pfn_glWeightusvARB Wm3glWeightusvARB;
#define glWeightusvARB Wm3glWeightusvARB

typedef void (APIENTRY* pfn_glWeightuivARB) (GLint, const GLuint*);
WM3_EXTERN pfn_glWeightuivARB Wm3glWeightuivARB;
#define glWeightuivARB Wm3glWeightuivARB

typedef void (APIENTRY* pfn_glWeightPointerARB) (GLint, GLenum, GLsizei, const GLvoid*);
WM3_EXTERN pfn_glWeightPointerARB Wm3glWeightPointerARB;
#define glWeightPointerARB Wm3glWeightPointerARB

typedef void (APIENTRY* pfn_glVertexBlendARB) (GLint);
WM3_EXTERN pfn_glVertexBlendARB Wm3glVertexBlendARB;
#define glVertexBlendARB Wm3glVertexBlendARB
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_ARB_matrix_palette;
WM3_EXTERN int Wm3NumFunctions_GL_ARB_matrix_palette;
#ifndef GL_ARB_matrix_palette
#define GL_ARB_matrix_palette
#define WM3_DEFINED_GL_ARB_matrix_palette
#define GL_MATRIX_PALETTE_ARB                   0x8840
#define GL_MAX_MATRIX_PALETTE_STACK_DEPTH_ARB   0x8841
#define GL_MAX_PALETTE_MATRICES_ARB             0x8842
#define GL_CURRENT_PALETTE_MATRIX_ARB           0x8843
#define GL_MATRIX_INDEX_ARRAY_ARB               0x8844
#define GL_CURRENT_MATRIX_INDEX_ARB             0x8845
#define GL_MATRIX_INDEX_ARRAY_SIZE_ARB          0x8846
#define GL_MATRIX_INDEX_ARRAY_TYPE_ARB          0x8847
#define GL_MATRIX_INDEX_ARRAY_STRIDE_ARB        0x8848
#define GL_MATRIX_INDEX_ARRAY_POINTER_ARB       0x8849

typedef void (APIENTRY* pfn_glCurrentPaletteMatrixARB) (GLint);
WM3_EXTERN pfn_glCurrentPaletteMatrixARB Wm3glCurrentPaletteMatrixARB;
#define glCurrentPaletteMatrixARB Wm3glCurrentPaletteMatrixARB

typedef void (APIENTRY* pfn_glMatrixIndexubvARB) (GLint, const GLubyte*);
WM3_EXTERN pfn_glMatrixIndexubvARB Wm3glMatrixIndexubvARB;
#define glMatrixIndexubvARB Wm3glMatrixIndexubvARB

typedef void (APIENTRY* pfn_glMatrixIndexusvARB) (GLint, const GLushort*);
WM3_EXTERN pfn_glMatrixIndexusvARB Wm3glMatrixIndexusvARB;
#define glMatrixIndexusvARB Wm3glMatrixIndexusvARB

typedef void (APIENTRY* pfn_glMatrixIndexuivARB) (GLint, const GLuint*);
WM3_EXTERN pfn_glMatrixIndexuivARB Wm3glMatrixIndexuivARB;
#define glMatrixIndexuivARB Wm3glMatrixIndexuivARB

typedef void (APIENTRY* pfn_glMatrixIndexPointerARB) (GLint, GLenum, GLsizei, const GLvoid*);
WM3_EXTERN pfn_glMatrixIndexPointerARB Wm3glMatrixIndexPointerARB;
#define glMatrixIndexPointerARB Wm3glMatrixIndexPointerARB
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_ARB_texture_env_combine;
WM3_EXTERN int Wm3NumFunctions_GL_ARB_texture_env_combine;
#ifndef GL_ARB_texture_env_combine
#define GL_ARB_texture_env_combine
#define WM3_DEFINED_GL_ARB_texture_env_combine
#define GL_COMBINE_ARB                    0x8570
#define GL_COMBINE_RGB_ARB                0x8571
#define GL_COMBINE_ALPHA_ARB              0x8572
#define GL_SOURCE0_RGB_ARB                0x8580
#define GL_SOURCE1_RGB_ARB                0x8581
#define GL_SOURCE2_RGB_ARB                0x8582
#define GL_SOURCE0_ALPHA_ARB              0x8588
#define GL_SOURCE1_ALPHA_ARB              0x8589
#define GL_SOURCE2_ALPHA_ARB              0x858A
#define GL_OPERAND0_RGB_ARB               0x8590
#define GL_OPERAND1_RGB_ARB               0x8591
#define GL_OPERAND2_RGB_ARB               0x8592
#define GL_OPERAND0_ALPHA_ARB             0x8598
#define GL_OPERAND1_ALPHA_ARB             0x8599
#define GL_OPERAND2_ALPHA_ARB             0x859A
#define GL_RGB_SCALE_ARB                  0x8573
#define GL_ADD_SIGNED_ARB                 0x8574
#define GL_INTERPOLATE_ARB                0x8575
#define GL_SUBTRACT_ARB                   0x84E7
#define GL_CONSTANT_ARB                   0x8576
#define GL_PRIMARY_COLOR_ARB              0x8577
#define GL_PREVIOUS_ARB                   0x8578
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_ARB_texture_env_crossbar;
WM3_EXTERN int Wm3NumFunctions_GL_ARB_texture_env_crossbar;
#ifndef GL_ARB_texture_env_crossbar
#define GL_ARB_texture_env_crossbar
#define WM3_DEFINED_GL_ARB_texture_env_crossbar
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_ARB_texture_env_dot3;
WM3_EXTERN int Wm3NumFunctions_GL_ARB_texture_env_dot3;
#ifndef GL_ARB_texture_env_dot3
#define GL_ARB_texture_env_dot3
#define WM3_DEFINED_GL_ARB_texture_env_dot3
#define GL_DOT3_RGB_ARB                   0x86AE
#define GL_DOT3_RGBA_ARB                  0x86AF
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_ARB_texture_mirrored_repeat;
WM3_EXTERN int Wm3NumFunctions_GL_ARB_texture_mirrored_repeat;
#ifndef GL_ARB_texture_mirrored_repeat
#define GL_ARB_texture_mirrored_repeat
#define WM3_DEFINED_GL_ARB_texture_mirrored_repeat
#define GL_MIRRORED_REPEAT_ARB            0x8370
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_ARB_depth_texture;
WM3_EXTERN int Wm3NumFunctions_GL_ARB_depth_texture;
#ifndef GL_ARB_depth_texture
#define GL_ARB_depth_texture
#define WM3_DEFINED_GL_ARB_depth_texture
#define GL_DEPTH_COMPONENT16_ARB          0x81A5
#define GL_DEPTH_COMPONENT24_ARB          0x81A6
#define GL_DEPTH_COMPONENT32_ARB          0x81A7
#define GL_TEXTURE_DEPTH_SIZE_ARB         0x884A
#define GL_DEPTH_TEXTURE_MODE_ARB         0x884B
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_ARB_shadow;
WM3_EXTERN int Wm3NumFunctions_GL_ARB_shadow;
#ifndef GL_ARB_shadow
#define GL_ARB_shadow
#define WM3_DEFINED_GL_ARB_shadow
#define GL_TEXTURE_COMPARE_MODE_ARB       0x884C
#define GL_TEXTURE_COMPARE_FUNC_ARB       0x884D
#define GL_COMPARE_R_TO_TEXTURE_ARB       0x884E
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_ARB_shadow_ambient;
WM3_EXTERN int Wm3NumFunctions_GL_ARB_shadow_ambient;
#ifndef GL_ARB_shadow_ambient
#define GL_ARB_shadow_ambient
#define WM3_DEFINED_GL_ARB_shadow_ambient
#define GL_TEXTURE_COMPARE_FAIL_VALUE_ARB 0x80BF
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_ARB_window_pos;
WM3_EXTERN int Wm3NumFunctions_GL_ARB_window_pos;
#ifndef GL_ARB_window_pos
#define GL_ARB_window_pos
#define WM3_DEFINED_GL_ARB_window_pos

typedef void (APIENTRY* pfn_glWindowPos2dARB) (GLdouble, GLdouble);
WM3_EXTERN pfn_glWindowPos2dARB Wm3glWindowPos2dARB;
#define glWindowPos2dARB Wm3glWindowPos2dARB

typedef void (APIENTRY* pfn_glWindowPos2dvARB) (const GLdouble*);
WM3_EXTERN pfn_glWindowPos2dvARB Wm3glWindowPos2dvARB;
#define glWindowPos2dvARB Wm3glWindowPos2dvARB

typedef void (APIENTRY* pfn_glWindowPos2fARB) (GLfloat, GLfloat);
WM3_EXTERN pfn_glWindowPos2fARB Wm3glWindowPos2fARB;
#define glWindowPos2fARB Wm3glWindowPos2fARB

typedef void (APIENTRY* pfn_glWindowPos2fvARB) (const GLfloat*);
WM3_EXTERN pfn_glWindowPos2fvARB Wm3glWindowPos2fvARB;
#define glWindowPos2fvARB Wm3glWindowPos2fvARB

typedef void (APIENTRY* pfn_glWindowPos2iARB) (GLint, GLint);
WM3_EXTERN pfn_glWindowPos2iARB Wm3glWindowPos2iARB;
#define glWindowPos2iARB Wm3glWindowPos2iARB

typedef void (APIENTRY* pfn_glWindowPos2ivARB) (const GLint*);
WM3_EXTERN pfn_glWindowPos2ivARB Wm3glWindowPos2ivARB;
#define glWindowPos2ivARB Wm3glWindowPos2ivARB

typedef void (APIENTRY* pfn_glWindowPos2sARB) (GLshort, GLshort);
WM3_EXTERN pfn_glWindowPos2sARB Wm3glWindowPos2sARB;
#define glWindowPos2sARB Wm3glWindowPos2sARB

typedef void (APIENTRY* pfn_glWindowPos2svARB) (const GLshort*);
WM3_EXTERN pfn_glWindowPos2svARB Wm3glWindowPos2svARB;
#define glWindowPos2svARB Wm3glWindowPos2svARB

typedef void (APIENTRY* pfn_glWindowPos3dARB) (GLdouble, GLdouble, GLdouble);
WM3_EXTERN pfn_glWindowPos3dARB Wm3glWindowPos3dARB;
#define glWindowPos3dARB Wm3glWindowPos3dARB

typedef void (APIENTRY* pfn_glWindowPos3dvARB) (const GLdouble*);
WM3_EXTERN pfn_glWindowPos3dvARB Wm3glWindowPos3dvARB;
#define glWindowPos3dvARB Wm3glWindowPos3dvARB

typedef void (APIENTRY* pfn_glWindowPos3fARB) (GLfloat, GLfloat, GLfloat);
WM3_EXTERN pfn_glWindowPos3fARB Wm3glWindowPos3fARB;
#define glWindowPos3fARB Wm3glWindowPos3fARB

typedef void (APIENTRY* pfn_glWindowPos3fvARB) (const GLfloat*);
WM3_EXTERN pfn_glWindowPos3fvARB Wm3glWindowPos3fvARB;
#define glWindowPos3fvARB Wm3glWindowPos3fvARB

typedef void (APIENTRY* pfn_glWindowPos3iARB) (GLint, GLint, GLint);
WM3_EXTERN pfn_glWindowPos3iARB Wm3glWindowPos3iARB;
#define glWindowPos3iARB Wm3glWindowPos3iARB

typedef void (APIENTRY* pfn_glWindowPos3ivARB) (const GLint*);
WM3_EXTERN pfn_glWindowPos3ivARB Wm3glWindowPos3ivARB;
#define glWindowPos3ivARB Wm3glWindowPos3ivARB

typedef void (APIENTRY* pfn_glWindowPos3sARB) (GLshort, GLshort, GLshort);
WM3_EXTERN pfn_glWindowPos3sARB Wm3glWindowPos3sARB;
#define glWindowPos3sARB Wm3glWindowPos3sARB

typedef void (APIENTRY* pfn_glWindowPos3svARB) (const GLshort*);
WM3_EXTERN pfn_glWindowPos3svARB Wm3glWindowPos3svARB;
#define glWindowPos3svARB Wm3glWindowPos3svARB
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_ARB_vertex_program;
WM3_EXTERN int Wm3NumFunctions_GL_ARB_vertex_program;
#ifndef GL_ARB_vertex_program
#define GL_ARB_vertex_program
#define WM3_DEFINED_GL_ARB_vertex_program
#define GL_COLOR_SUM_ARB                            0x8458
#define GL_VERTEX_PROGRAM_ARB                       0x8620
#define GL_VERTEX_ATTRIB_ARRAY_ENABLED_ARB          0x8622
#define GL_VERTEX_ATTRIB_ARRAY_SIZE_ARB             0x8623
#define GL_VERTEX_ATTRIB_ARRAY_STRIDE_ARB           0x8624
#define GL_VERTEX_ATTRIB_ARRAY_TYPE_ARB             0x8625
#define GL_CURRENT_VERTEX_ATTRIB_ARB                0x8626
#define GL_PROGRAM_LENGTH_ARB                       0x8627
#define GL_PROGRAM_STRING_ARB                       0x8628
#define GL_MAX_PROGRAM_MATRIX_STACK_DEPTH_ARB       0x862E
#define GL_MAX_PROGRAM_MATRICES_ARB                 0x862F
#define GL_CURRENT_MATRIX_STACK_DEPTH_ARB           0x8640
#define GL_CURRENT_MATRIX_ARB                       0x8641
#define GL_VERTEX_PROGRAM_POINT_SIZE_ARB            0x8642
#define GL_VERTEX_PROGRAM_TWO_SIDE_ARB              0x8643
#define GL_VERTEX_ATTRIB_ARRAY_POINTER_ARB          0x8645
#define GL_PROGRAM_ERROR_POSITION_ARB               0x864B
#define GL_PROGRAM_BINDING_ARB                      0x8677
#define GL_MAX_VERTEX_ATTRIBS_ARB                   0x8869
#define GL_VERTEX_ATTRIB_ARRAY_NORMALIZED_ARB       0x886A
#define GL_PROGRAM_ERROR_STRING_ARB                 0x8874
#define GL_PROGRAM_FORMAT_ASCII_ARB                 0x8875
#define GL_PROGRAM_FORMAT_ARB                       0x8876
#define GL_PROGRAM_INSTRUCTIONS_ARB                 0x88A0
#define GL_MAX_PROGRAM_INSTRUCTIONS_ARB             0x88A1
#define GL_PROGRAM_NATIVE_INSTRUCTIONS_ARB          0x88A2
#define GL_MAX_PROGRAM_NATIVE_INSTRUCTIONS_ARB      0x88A3
#define GL_PROGRAM_TEMPORARIES_ARB                  0x88A4
#define GL_MAX_PROGRAM_TEMPORARIES_ARB              0x88A5
#define GL_PROGRAM_NATIVE_TEMPORARIES_ARB           0x88A6
#define GL_MAX_PROGRAM_NATIVE_TEMPORARIES_ARB       0x88A7
#define GL_PROGRAM_PARAMETERS_ARB                   0x88A8
#define GL_MAX_PROGRAM_PARAMETERS_ARB               0x88A9
#define GL_PROGRAM_NATIVE_PARAMETERS_ARB            0x88AA
#define GL_MAX_PROGRAM_NATIVE_PARAMETERS_ARB        0x88AB
#define GL_PROGRAM_ATTRIBS_ARB                      0x88AC
#define GL_MAX_PROGRAM_ATTRIBS_ARB                  0x88AD
#define GL_PROGRAM_NATIVE_ATTRIBS_ARB               0x88AE
#define GL_MAX_PROGRAM_NATIVE_ATTRIBS_ARB           0x88AF
#define GL_PROGRAM_ADDRESS_REGISTERS_ARB            0x88B0
#define GL_MAX_PROGRAM_ADDRESS_REGISTERS_ARB        0x88B1
#define GL_PROGRAM_NATIVE_ADDRESS_REGISTERS_ARB     0x88B2
#define GL_MAX_PROGRAM_NATIVE_ADDRESS_REGISTERS_ARB 0x88B3
#define GL_MAX_PROGRAM_LOCAL_PARAMETERS_ARB         0x88B4
#define GL_MAX_PROGRAM_ENV_PARAMETERS_ARB           0x88B5
#define GL_PROGRAM_UNDER_NATIVE_LIMITS_ARB          0x88B6
#define GL_TRANSPOSE_CURRENT_MATRIX_ARB             0x88B7
#define GL_MATRIX0_ARB                              0x88C0
#define GL_MATRIX1_ARB                              0x88C1
#define GL_MATRIX2_ARB                              0x88C2
#define GL_MATRIX3_ARB                              0x88C3
#define GL_MATRIX4_ARB                              0x88C4
#define GL_MATRIX5_ARB                              0x88C5
#define GL_MATRIX6_ARB                              0x88C6
#define GL_MATRIX7_ARB                              0x88C7
#define GL_MATRIX8_ARB                              0x88C8
#define GL_MATRIX9_ARB                              0x88C9
#define GL_MATRIX10_ARB                             0x88CA
#define GL_MATRIX11_ARB                             0x88CB
#define GL_MATRIX12_ARB                             0x88CC
#define GL_MATRIX13_ARB                             0x88CD
#define GL_MATRIX14_ARB                             0x88CE
#define GL_MATRIX15_ARB                             0x88CF
#define GL_MATRIX16_ARB                             0x88D0
#define GL_MATRIX17_ARB                             0x88D1
#define GL_MATRIX18_ARB                             0x88D2
#define GL_MATRIX19_ARB                             0x88D3
#define GL_MATRIX20_ARB                             0x88D4
#define GL_MATRIX21_ARB                             0x88D5
#define GL_MATRIX22_ARB                             0x88D6
#define GL_MATRIX23_ARB                             0x88D7
#define GL_MATRIX24_ARB                             0x88D8
#define GL_MATRIX25_ARB                             0x88D9
#define GL_MATRIX26_ARB                             0x88DA
#define GL_MATRIX27_ARB                             0x88DB
#define GL_MATRIX28_ARB                             0x88DC
#define GL_MATRIX29_ARB                             0x88DD
#define GL_MATRIX30_ARB                             0x88DE
#define GL_MATRIX31_ARB                             0x88DF

typedef void (APIENTRY* pfn_glVertexAttrib1dARB) (GLuint, GLdouble);
WM3_EXTERN pfn_glVertexAttrib1dARB Wm3glVertexAttrib1dARB;
#define glVertexAttrib1dARB Wm3glVertexAttrib1dARB

typedef void (APIENTRY* pfn_glVertexAttrib1dvARB) (GLuint, const GLdouble*);
WM3_EXTERN pfn_glVertexAttrib1dvARB Wm3glVertexAttrib1dvARB;
#define glVertexAttrib1dvARB Wm3glVertexAttrib1dvARB

typedef void (APIENTRY* pfn_glVertexAttrib1fARB) (GLuint, GLfloat);
WM3_EXTERN pfn_glVertexAttrib1fARB Wm3glVertexAttrib1fARB;
#define glVertexAttrib1fARB Wm3glVertexAttrib1fARB

typedef void (APIENTRY* pfn_glVertexAttrib1fvARB) (GLuint, const GLfloat*);
WM3_EXTERN pfn_glVertexAttrib1fvARB Wm3glVertexAttrib1fvARB;
#define glVertexAttrib1fvARB Wm3glVertexAttrib1fvARB

typedef void (APIENTRY* pfn_glVertexAttrib1sARB) (GLuint, GLshort);
WM3_EXTERN pfn_glVertexAttrib1sARB Wm3glVertexAttrib1sARB;
#define glVertexAttrib1sARB Wm3glVertexAttrib1sARB

typedef void (APIENTRY* pfn_glVertexAttrib1svARB) (GLuint, const GLshort*);
WM3_EXTERN pfn_glVertexAttrib1svARB Wm3glVertexAttrib1svARB;
#define glVertexAttrib1svARB Wm3glVertexAttrib1svARB

typedef void (APIENTRY* pfn_glVertexAttrib2dARB) (GLuint, GLdouble, GLdouble);
WM3_EXTERN pfn_glVertexAttrib2dARB Wm3glVertexAttrib2dARB;
#define glVertexAttrib2dARB Wm3glVertexAttrib2dARB

typedef void (APIENTRY* pfn_glVertexAttrib2dvARB) (GLuint, const GLdouble*);
WM3_EXTERN pfn_glVertexAttrib2dvARB Wm3glVertexAttrib2dvARB;
#define glVertexAttrib2dvARB Wm3glVertexAttrib2dvARB

typedef void (APIENTRY* pfn_glVertexAttrib2fARB) (GLuint, GLfloat, GLfloat);
WM3_EXTERN pfn_glVertexAttrib2fARB Wm3glVertexAttrib2fARB;
#define glVertexAttrib2fARB Wm3glVertexAttrib2fARB

typedef void (APIENTRY* pfn_glVertexAttrib2fvARB) (GLuint, const GLfloat*);
WM3_EXTERN pfn_glVertexAttrib2fvARB Wm3glVertexAttrib2fvARB;
#define glVertexAttrib2fvARB Wm3glVertexAttrib2fvARB

typedef void (APIENTRY* pfn_glVertexAttrib2sARB) (GLuint, GLshort, GLshort);
WM3_EXTERN pfn_glVertexAttrib2sARB Wm3glVertexAttrib2sARB;
#define glVertexAttrib2sARB Wm3glVertexAttrib2sARB

typedef void (APIENTRY* pfn_glVertexAttrib2svARB) (GLuint, const GLshort*);
WM3_EXTERN pfn_glVertexAttrib2svARB Wm3glVertexAttrib2svARB;
#define glVertexAttrib2svARB Wm3glVertexAttrib2svARB

typedef void (APIENTRY* pfn_glVertexAttrib3dARB) (GLuint, GLdouble, GLdouble, GLdouble);
WM3_EXTERN pfn_glVertexAttrib3dARB Wm3glVertexAttrib3dARB;
#define glVertexAttrib3dARB Wm3glVertexAttrib3dARB

typedef void (APIENTRY* pfn_glVertexAttrib3dvARB) (GLuint, const GLdouble*);
WM3_EXTERN pfn_glVertexAttrib3dvARB Wm3glVertexAttrib3dvARB;
#define glVertexAttrib3dvARB Wm3glVertexAttrib3dvARB

typedef void (APIENTRY* pfn_glVertexAttrib3fARB) (GLuint, GLfloat, GLfloat, GLfloat);
WM3_EXTERN pfn_glVertexAttrib3fARB Wm3glVertexAttrib3fARB;
#define glVertexAttrib3fARB Wm3glVertexAttrib3fARB

typedef void (APIENTRY* pfn_glVertexAttrib3fvARB) (GLuint, const GLfloat*);
WM3_EXTERN pfn_glVertexAttrib3fvARB Wm3glVertexAttrib3fvARB;
#define glVertexAttrib3fvARB Wm3glVertexAttrib3fvARB

typedef void (APIENTRY* pfn_glVertexAttrib3sARB) (GLuint, GLshort, GLshort, GLshort);
WM3_EXTERN pfn_glVertexAttrib3sARB Wm3glVertexAttrib3sARB;
#define glVertexAttrib3sARB Wm3glVertexAttrib3sARB

typedef void (APIENTRY* pfn_glVertexAttrib3svARB) (GLuint, const GLshort*);
WM3_EXTERN pfn_glVertexAttrib3svARB Wm3glVertexAttrib3svARB;
#define glVertexAttrib3svARB Wm3glVertexAttrib3svARB

typedef void (APIENTRY* pfn_glVertexAttrib4NbvARB) (GLuint, const GLbyte*);
WM3_EXTERN pfn_glVertexAttrib4NbvARB Wm3glVertexAttrib4NbvARB;
#define glVertexAttrib4NbvARB Wm3glVertexAttrib4NbvARB

typedef void (APIENTRY* pfn_glVertexAttrib4NivARB) (GLuint, const GLint*);
WM3_EXTERN pfn_glVertexAttrib4NivARB Wm3glVertexAttrib4NivARB;
#define glVertexAttrib4NivARB Wm3glVertexAttrib4NivARB

typedef void (APIENTRY* pfn_glVertexAttrib4NsvARB) (GLuint, const GLshort*);
WM3_EXTERN pfn_glVertexAttrib4NsvARB Wm3glVertexAttrib4NsvARB;
#define glVertexAttrib4NsvARB Wm3glVertexAttrib4NsvARB

typedef void (APIENTRY* pfn_glVertexAttrib4NubARB) (GLuint, GLubyte, GLubyte, GLubyte, GLubyte);
WM3_EXTERN pfn_glVertexAttrib4NubARB Wm3glVertexAttrib4NubARB;
#define glVertexAttrib4NubARB Wm3glVertexAttrib4NubARB

typedef void (APIENTRY* pfn_glVertexAttrib4NubvARB) (GLuint, const GLubyte*);
WM3_EXTERN pfn_glVertexAttrib4NubvARB Wm3glVertexAttrib4NubvARB;
#define glVertexAttrib4NubvARB Wm3glVertexAttrib4NubvARB

typedef void (APIENTRY* pfn_glVertexAttrib4NuivARB) (GLuint, const GLuint*);
WM3_EXTERN pfn_glVertexAttrib4NuivARB Wm3glVertexAttrib4NuivARB;
#define glVertexAttrib4NuivARB Wm3glVertexAttrib4NuivARB

typedef void (APIENTRY* pfn_glVertexAttrib4NusvARB) (GLuint, const GLushort*);
WM3_EXTERN pfn_glVertexAttrib4NusvARB Wm3glVertexAttrib4NusvARB;
#define glVertexAttrib4NusvARB Wm3glVertexAttrib4NusvARB

typedef void (APIENTRY* pfn_glVertexAttrib4bvARB) (GLuint, const GLbyte*);
WM3_EXTERN pfn_glVertexAttrib4bvARB Wm3glVertexAttrib4bvARB;
#define glVertexAttrib4bvARB Wm3glVertexAttrib4bvARB

typedef void (APIENTRY* pfn_glVertexAttrib4dARB) (GLuint, GLdouble, GLdouble, GLdouble, GLdouble);
WM3_EXTERN pfn_glVertexAttrib4dARB Wm3glVertexAttrib4dARB;
#define glVertexAttrib4dARB Wm3glVertexAttrib4dARB

typedef void (APIENTRY* pfn_glVertexAttrib4dvARB) (GLuint, const GLdouble*);
WM3_EXTERN pfn_glVertexAttrib4dvARB Wm3glVertexAttrib4dvARB;
#define glVertexAttrib4dvARB Wm3glVertexAttrib4dvARB

typedef void (APIENTRY* pfn_glVertexAttrib4fARB) (GLuint, GLfloat, GLfloat, GLfloat, GLfloat);
WM3_EXTERN pfn_glVertexAttrib4fARB Wm3glVertexAttrib4fARB;
#define glVertexAttrib4fARB Wm3glVertexAttrib4fARB

typedef void (APIENTRY* pfn_glVertexAttrib4fvARB) (GLuint, const GLfloat*);
WM3_EXTERN pfn_glVertexAttrib4fvARB Wm3glVertexAttrib4fvARB;
#define glVertexAttrib4fvARB Wm3glVertexAttrib4fvARB

typedef void (APIENTRY* pfn_glVertexAttrib4ivARB) (GLuint, const GLint*);
WM3_EXTERN pfn_glVertexAttrib4ivARB Wm3glVertexAttrib4ivARB;
#define glVertexAttrib4ivARB Wm3glVertexAttrib4ivARB

typedef void (APIENTRY* pfn_glVertexAttrib4sARB) (GLuint, GLshort, GLshort, GLshort, GLshort);
WM3_EXTERN pfn_glVertexAttrib4sARB Wm3glVertexAttrib4sARB;
#define glVertexAttrib4sARB Wm3glVertexAttrib4sARB

typedef void (APIENTRY* pfn_glVertexAttrib4svARB) (GLuint, const GLshort*);
WM3_EXTERN pfn_glVertexAttrib4svARB Wm3glVertexAttrib4svARB;
#define glVertexAttrib4svARB Wm3glVertexAttrib4svARB

typedef void (APIENTRY* pfn_glVertexAttrib4ubvARB) (GLuint, const GLubyte*);
WM3_EXTERN pfn_glVertexAttrib4ubvARB Wm3glVertexAttrib4ubvARB;
#define glVertexAttrib4ubvARB Wm3glVertexAttrib4ubvARB

typedef void (APIENTRY* pfn_glVertexAttrib4uivARB) (GLuint, const GLuint*);
WM3_EXTERN pfn_glVertexAttrib4uivARB Wm3glVertexAttrib4uivARB;
#define glVertexAttrib4uivARB Wm3glVertexAttrib4uivARB

typedef void (APIENTRY* pfn_glVertexAttrib4usvARB) (GLuint, const GLushort*);
WM3_EXTERN pfn_glVertexAttrib4usvARB Wm3glVertexAttrib4usvARB;
#define glVertexAttrib4usvARB Wm3glVertexAttrib4usvARB

typedef void (APIENTRY* pfn_glVertexAttribPointerARB) (GLuint, GLint, GLenum, GLboolean, GLsizei, const GLvoid*);
WM3_EXTERN pfn_glVertexAttribPointerARB Wm3glVertexAttribPointerARB;
#define glVertexAttribPointerARB Wm3glVertexAttribPointerARB

typedef void (APIENTRY* pfn_glEnableVertexAttribArrayARB) (GLuint);
WM3_EXTERN pfn_glEnableVertexAttribArrayARB Wm3glEnableVertexAttribArrayARB;
#define glEnableVertexAttribArrayARB Wm3glEnableVertexAttribArrayARB

typedef void (APIENTRY* pfn_glDisableVertexAttribArrayARB) (GLuint);
WM3_EXTERN pfn_glDisableVertexAttribArrayARB Wm3glDisableVertexAttribArrayARB;
#define glDisableVertexAttribArrayARB Wm3glDisableVertexAttribArrayARB

typedef void (APIENTRY* pfn_glProgramStringARB) (GLenum, GLenum, GLsizei, const GLvoid*);
WM3_EXTERN pfn_glProgramStringARB Wm3glProgramStringARB;
#define glProgramStringARB Wm3glProgramStringARB

typedef void (APIENTRY* pfn_glBindProgramARB) (GLenum, GLuint);
WM3_EXTERN pfn_glBindProgramARB Wm3glBindProgramARB;
#define glBindProgramARB Wm3glBindProgramARB

typedef void (APIENTRY* pfn_glDeleteProgramsARB) (GLsizei, const GLuint*);
WM3_EXTERN pfn_glDeleteProgramsARB Wm3glDeleteProgramsARB;
#define glDeleteProgramsARB Wm3glDeleteProgramsARB

typedef void (APIENTRY* pfn_glGenProgramsARB) (GLsizei, GLuint*);
WM3_EXTERN pfn_glGenProgramsARB Wm3glGenProgramsARB;
#define glGenProgramsARB Wm3glGenProgramsARB

typedef void (APIENTRY* pfn_glProgramEnvParameter4dARB) (GLenum, GLuint, GLdouble, GLdouble, GLdouble, GLdouble);
WM3_EXTERN pfn_glProgramEnvParameter4dARB Wm3glProgramEnvParameter4dARB;
#define glProgramEnvParameter4dARB Wm3glProgramEnvParameter4dARB

typedef void (APIENTRY* pfn_glProgramEnvParameter4dvARB) (GLenum, GLuint, const GLdouble*);
WM3_EXTERN pfn_glProgramEnvParameter4dvARB Wm3glProgramEnvParameter4dvARB;
#define glProgramEnvParameter4dvARB Wm3glProgramEnvParameter4dvARB

typedef void (APIENTRY* pfn_glProgramEnvParameter4fARB) (GLenum, GLuint, GLfloat, GLfloat, GLfloat, GLfloat);
WM3_EXTERN pfn_glProgramEnvParameter4fARB Wm3glProgramEnvParameter4fARB;
#define glProgramEnvParameter4fARB Wm3glProgramEnvParameter4fARB

typedef void (APIENTRY* pfn_glProgramEnvParameter4fvARB) (GLenum, GLuint, const GLfloat*);
WM3_EXTERN pfn_glProgramEnvParameter4fvARB Wm3glProgramEnvParameter4fvARB;
#define glProgramEnvParameter4fvARB Wm3glProgramEnvParameter4fvARB

typedef void (APIENTRY* pfn_glProgramLocalParameter4dARB) (GLenum, GLuint, GLdouble, GLdouble, GLdouble, GLdouble);
WM3_EXTERN pfn_glProgramLocalParameter4dARB Wm3glProgramLocalParameter4dARB;
#define glProgramLocalParameter4dARB Wm3glProgramLocalParameter4dARB

typedef void (APIENTRY* pfn_glProgramLocalParameter4dvARB) (GLenum, GLuint, const GLdouble*);
WM3_EXTERN pfn_glProgramLocalParameter4dvARB Wm3glProgramLocalParameter4dvARB;
#define glProgramLocalParameter4dvARB Wm3glProgramLocalParameter4dvARB

typedef void (APIENTRY* pfn_glProgramLocalParameter4fARB) (GLenum, GLuint, GLfloat, GLfloat, GLfloat, GLfloat);
WM3_EXTERN pfn_glProgramLocalParameter4fARB Wm3glProgramLocalParameter4fARB;
#define glProgramLocalParameter4fARB Wm3glProgramLocalParameter4fARB

typedef void (APIENTRY* pfn_glProgramLocalParameter4fvARB) (GLenum, GLuint, const GLfloat*);
WM3_EXTERN pfn_glProgramLocalParameter4fvARB Wm3glProgramLocalParameter4fvARB;
#define glProgramLocalParameter4fvARB Wm3glProgramLocalParameter4fvARB

typedef void (APIENTRY* pfn_glGetProgramEnvParameterdvARB) (GLenum, GLuint, GLdouble*);
WM3_EXTERN pfn_glGetProgramEnvParameterdvARB Wm3glGetProgramEnvParameterdvARB;
#define glGetProgramEnvParameterdvARB Wm3glGetProgramEnvParameterdvARB

typedef void (APIENTRY* pfn_glGetProgramEnvParameterfvARB) (GLenum, GLuint, GLfloat*);
WM3_EXTERN pfn_glGetProgramEnvParameterfvARB Wm3glGetProgramEnvParameterfvARB;
#define glGetProgramEnvParameterfvARB Wm3glGetProgramEnvParameterfvARB

typedef void (APIENTRY* pfn_glGetProgramLocalParameterdvARB) (GLenum, GLuint, GLdouble*);
WM3_EXTERN pfn_glGetProgramLocalParameterdvARB Wm3glGetProgramLocalParameterdvARB;
#define glGetProgramLocalParameterdvARB Wm3glGetProgramLocalParameterdvARB

typedef void (APIENTRY* pfn_glGetProgramLocalParameterfvARB) (GLenum, GLuint, GLfloat*);
WM3_EXTERN pfn_glGetProgramLocalParameterfvARB Wm3glGetProgramLocalParameterfvARB;
#define glGetProgramLocalParameterfvARB Wm3glGetProgramLocalParameterfvARB

typedef void (APIENTRY* pfn_glGetProgramivARB) (GLenum, GLenum, GLint*);
WM3_EXTERN pfn_glGetProgramivARB Wm3glGetProgramivARB;
#define glGetProgramivARB Wm3glGetProgramivARB

typedef void (APIENTRY* pfn_glGetProgramStringARB) (GLenum, GLenum, GLvoid*);
WM3_EXTERN pfn_glGetProgramStringARB Wm3glGetProgramStringARB;
#define glGetProgramStringARB Wm3glGetProgramStringARB

typedef void (APIENTRY* pfn_glGetVertexAttribdvARB) (GLuint, GLenum, GLdouble*);
WM3_EXTERN pfn_glGetVertexAttribdvARB Wm3glGetVertexAttribdvARB;
#define glGetVertexAttribdvARB Wm3glGetVertexAttribdvARB

typedef void (APIENTRY* pfn_glGetVertexAttribfvARB) (GLuint, GLenum, GLfloat*);
WM3_EXTERN pfn_glGetVertexAttribfvARB Wm3glGetVertexAttribfvARB;
#define glGetVertexAttribfvARB Wm3glGetVertexAttribfvARB

typedef void (APIENTRY* pfn_glGetVertexAttribivARB) (GLuint, GLenum, GLint*);
WM3_EXTERN pfn_glGetVertexAttribivARB Wm3glGetVertexAttribivARB;
#define glGetVertexAttribivARB Wm3glGetVertexAttribivARB

typedef void (APIENTRY* pfn_glGetVertexAttribPointervARB) (GLuint, GLenum, GLvoid**);
WM3_EXTERN pfn_glGetVertexAttribPointervARB Wm3glGetVertexAttribPointervARB;
#define glGetVertexAttribPointervARB Wm3glGetVertexAttribPointervARB

typedef GLboolean (APIENTRY* pfn_glIsProgramARB) (GLuint);
WM3_EXTERN pfn_glIsProgramARB Wm3glIsProgramARB;
#define glIsProgramARB Wm3glIsProgramARB
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_ARB_fragment_program;
WM3_EXTERN int Wm3NumFunctions_GL_ARB_fragment_program;
#ifndef GL_ARB_fragment_program
#define GL_ARB_fragment_program
#define WM3_DEFINED_GL_ARB_fragment_program
#define GL_FRAGMENT_PROGRAM_ARB                     0x8804
#define GL_PROGRAM_ALU_INSTRUCTIONS_ARB             0x8805
#define GL_PROGRAM_TEX_INSTRUCTIONS_ARB             0x8806
#define GL_PROGRAM_TEX_INDIRECTIONS_ARB             0x8807
#define GL_PROGRAM_NATIVE_ALU_INSTRUCTIONS_ARB      0x8808
#define GL_PROGRAM_NATIVE_TEX_INSTRUCTIONS_ARB      0x8809
#define GL_PROGRAM_NATIVE_TEX_INDIRECTIONS_ARB      0x880A
#define GL_MAX_PROGRAM_ALU_INSTRUCTIONS_ARB         0x880B
#define GL_MAX_PROGRAM_TEX_INSTRUCTIONS_ARB         0x880C
#define GL_MAX_PROGRAM_TEX_INDIRECTIONS_ARB         0x880D
#define GL_MAX_PROGRAM_NATIVE_ALU_INSTRUCTIONS_ARB  0x880E
#define GL_MAX_PROGRAM_NATIVE_TEX_INSTRUCTIONS_ARB  0x880F
#define GL_MAX_PROGRAM_NATIVE_TEX_INDIRECTIONS_ARB  0x8810
#define GL_MAX_TEXTURE_COORDS_ARB                   0x8871
#define GL_MAX_TEXTURE_IMAGE_UNITS_ARB              0x8872
/* All ARB_fragment_program entry points are shared with ARB_vertex_program. */
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_ARB_vertex_buffer_object;
WM3_EXTERN int Wm3NumFunctions_GL_ARB_vertex_buffer_object;
#ifndef GL_ARB_vertex_buffer_object
#define GL_ARB_vertex_buffer_object
#define WM3_DEFINED_GL_ARB_vertex_buffer_object
#define GL_BUFFER_SIZE_ARB                          0x8764
#define GL_BUFFER_USAGE_ARB                         0x8765
#define GL_ARRAY_BUFFER_ARB                         0x8892
#define GL_ELEMENT_ARRAY_BUFFER_ARB                 0x8893
#define GL_ARRAY_BUFFER_BINDING_ARB                 0x8894
#define GL_ELEMENT_ARRAY_BUFFER_BINDING_ARB         0x8895
#define GL_VERTEX_ARRAY_BUFFER_BINDING_ARB          0x8896
#define GL_NORMAL_ARRAY_BUFFER_BINDING_ARB          0x8897
#define GL_COLOR_ARRAY_BUFFER_BINDING_ARB           0x8898
#define GL_INDEX_ARRAY_BUFFER_BINDING_ARB           0x8899
#define GL_TEXTURE_COORD_ARRAY_BUFFER_BINDING_ARB   0x889A
#define GL_EDGE_FLAG_ARRAY_BUFFER_BINDING_ARB       0x889B
#define GL_SECONDARY_COLOR_ARRAY_BUFFER_BINDING_ARB 0x889C
#define GL_FOG_COORDINATE_ARRAY_BUFFER_BINDING_ARB  0x889D
#define GL_WEIGHT_ARRAY_BUFFER_BINDING_ARB          0x889E
#define GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING_ARB   0x889F
#define GL_READ_ONLY_ARB                            0x88B8
#define GL_WRITE_ONLY_ARB                           0x88B9
#define GL_READ_WRITE_ARB                           0x88BA
#define GL_BUFFER_ACCESS_ARB                        0x88BB
#define GL_BUFFER_MAPPED_ARB                        0x88BC
#define GL_BUFFER_MAP_POINTER_ARB                   0x88BD
#define GL_STREAM_DRAW_ARB                          0x88E0
#define GL_STREAM_READ_ARB                          0x88E1
#define GL_STREAM_COPY_ARB                          0x88E2
#define GL_STATIC_DRAW_ARB                          0x88E4
#define GL_STATIC_READ_ARB                          0x88E5
#define GL_STATIC_COPY_ARB                          0x88E6
#define GL_DYNAMIC_DRAW_ARB                         0x88E8
#define GL_DYNAMIC_READ_ARB                         0x88E9
#define GL_DYNAMIC_COPY_ARB                         0x88EA
typedef ptrdiff_t GLintptrARB;
typedef ptrdiff_t GLsizeiptrARB;

typedef void (APIENTRY* pfn_glBindBufferARB) (GLenum, GLuint);
WM3_EXTERN pfn_glBindBufferARB Wm3glBindBufferARB;
#define glBindBufferARB Wm3glBindBufferARB

typedef void (APIENTRY* pfn_glDeleteBuffersARB) (GLsizei, const GLuint*);
WM3_EXTERN pfn_glDeleteBuffersARB Wm3glDeleteBuffersARB;
#define glDeleteBuffersARB Wm3glDeleteBuffersARB

typedef void (APIENTRY* pfn_glGenBuffersARB) (GLsizei, GLuint*);
WM3_EXTERN pfn_glGenBuffersARB Wm3glGenBuffersARB;
#define glGenBuffersARB Wm3glGenBuffersARB

typedef GLboolean (APIENTRY* pfn_glIsBufferARB) (GLuint);
WM3_EXTERN pfn_glIsBufferARB Wm3glIsBufferARB;
#define glIsBufferARB Wm3glIsBufferARB

typedef void (APIENTRY* pfn_glBufferDataARB) (GLenum, GLsizeiptrARB, const GLvoid*, GLenum);
WM3_EXTERN pfn_glBufferDataARB Wm3glBufferDataARB;
#define glBufferDataARB Wm3glBufferDataARB

typedef void (APIENTRY* pfn_glBufferSubDataARB) (GLenum, GLintptrARB, GLsizeiptrARB, const GLvoid*);
WM3_EXTERN pfn_glBufferSubDataARB Wm3glBufferSubDataARB;
#define glBufferSubDataARB Wm3glBufferSubDataARB

typedef void (APIENTRY* pfn_glGetBufferSubDataARB) (GLenum, GLintptrARB, GLsizeiptrARB, GLvoid*);
WM3_EXTERN pfn_glGetBufferSubDataARB Wm3glGetBufferSubDataARB;
#define glGetBufferSubDataARB Wm3glGetBufferSubDataARB

typedef GLvoid* (APIENTRY* pfn_glMapBufferARB) (GLenum, GLenum);
WM3_EXTERN pfn_glMapBufferARB Wm3glMapBufferARB;
#define glMapBufferARB Wm3glMapBufferARB

typedef GLboolean (APIENTRY* pfn_glUnmapBufferARB) (GLenum);
WM3_EXTERN pfn_glUnmapBufferARB Wm3glUnmapBufferARB;
#define glUnmapBufferARB Wm3glUnmapBufferARB

typedef void (APIENTRY* pfn_glGetBufferParameterivARB) (GLenum, GLenum, GLint*);
WM3_EXTERN pfn_glGetBufferParameterivARB Wm3glGetBufferParameterivARB;
#define glGetBufferParameterivARB Wm3glGetBufferParameterivARB

typedef void (APIENTRY* pfn_glGetBufferPointervARB) (GLenum, GLenum, GLvoid**);
WM3_EXTERN pfn_glGetBufferPointervARB Wm3glGetBufferPointervARB;
#define glGetBufferPointervARB Wm3glGetBufferPointervARB
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_ARB_occlusion_query;
WM3_EXTERN int Wm3NumFunctions_GL_ARB_occlusion_query;
#ifndef GL_ARB_occlusion_query
#define GL_ARB_occlusion_query
#define WM3_DEFINED_GL_ARB_occlusion_query
#define GL_QUERY_COUNTER_BITS_ARB         0x8864
#define GL_CURRENT_QUERY_ARB              0x8865
#define GL_QUERY_RESULT_ARB               0x8866
#define GL_QUERY_RESULT_AVAILABLE_ARB     0x8867
#define GL_SAMPLES_PASSED_ARB             0x8914

typedef void (APIENTRY* pfn_glGenQueriesARB) (GLsizei, GLuint*);
WM3_EXTERN pfn_glGenQueriesARB Wm3glGenQueriesARB;
#define glGenQueriesARB Wm3glGenQueriesARB

typedef void (APIENTRY* pfn_glDeleteQueriesARB) (GLsizei, const GLuint*);
WM3_EXTERN pfn_glDeleteQueriesARB Wm3glDeleteQueriesARB;
#define glDeleteQueriesARB Wm3glDeleteQueriesARB

typedef GLboolean (APIENTRY* pfn_glIsQueryARB) (GLuint);
WM3_EXTERN pfn_glIsQueryARB Wm3glIsQueryARB;
#define glIsQueryARB Wm3glIsQueryARB

typedef void (APIENTRY* pfn_glBeginQueryARB) (GLenum, GLuint);
WM3_EXTERN pfn_glBeginQueryARB Wm3glBeginQueryARB;
#define glBeginQueryARB Wm3glBeginQueryARB

typedef void (APIENTRY* pfn_glEndQueryARB) (GLenum);
WM3_EXTERN pfn_glEndQueryARB Wm3glEndQueryARB;
#define glEndQueryARB Wm3glEndQueryARB

typedef void (APIENTRY* pfn_glGetQueryivARB) (GLenum, GLenum, GLint*);
WM3_EXTERN pfn_glGetQueryivARB Wm3glGetQueryivARB;
#define glGetQueryivARB Wm3glGetQueryivARB

typedef void (APIENTRY* pfn_glGetQueryObjectivARB) (GLuint, GLenum, GLint*);
WM3_EXTERN pfn_glGetQueryObjectivARB Wm3glGetQueryObjectivARB;
#define glGetQueryObjectivARB Wm3glGetQueryObjectivARB

typedef void (APIENTRY* pfn_glGetQueryObjectuivARB) (GLuint, GLenum, GLuint*);
WM3_EXTERN pfn_glGetQueryObjectuivARB Wm3glGetQueryObjectuivARB;
#define glGetQueryObjectuivARB Wm3glGetQueryObjectuivARB
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_ARB_shader_objects;
WM3_EXTERN int Wm3NumFunctions_GL_ARB_shader_objects;
#ifndef GL_ARB_shader_objects
#define GL_ARB_shader_objects
#define WM3_DEFINED_GL_ARB_shader_objects
#define GL_PROGRAM_OBJECT_ARB                   0x8B40
#define GL_SHADER_OBJECT_ARB                    0x8B48
#define GL_OBJECT_TYPE_ARB                      0x8B4E
#define GL_OBJECT_SUBTYPE_ARB                   0x8B4F
#define GL_FLOAT_VEC2_ARB                       0x8B50
#define GL_FLOAT_VEC3_ARB                       0x8B51
#define GL_FLOAT_VEC4_ARB                       0x8B52
#define GL_INT_VEC2_ARB                         0x8B53
#define GL_INT_VEC3_ARB                         0x8B54
#define GL_INT_VEC4_ARB                         0x8B55
#define GL_BOOL_ARB                             0x8B56
#define GL_BOOL_VEC2_ARB                        0x8B57
#define GL_BOOL_VEC3_ARB                        0x8B58
#define GL_BOOL_VEC4_ARB                        0x8B59
#define GL_FLOAT_MAT2_ARB                       0x8B5A
#define GL_FLOAT_MAT3_ARB                       0x8B5B
#define GL_FLOAT_MAT4_ARB                       0x8B5C
#define GL_SAMPLER_1D_ARB                       0x8B5D
#define GL_SAMPLER_2D_ARB                       0x8B5E
#define GL_SAMPLER_3D_ARB                       0x8B5F
#define GL_SAMPLER_CUBE_ARB                     0x8B60
#define GL_SAMPLER_1D_SHADOW_ARB                0x8B61
#define GL_SAMPLER_2D_SHADOW_ARB                0x8B62
#define GL_SAMPLER_2D_RECT_ARB                  0x8B63
#define GL_SAMPLER_2D_RECT_SHADOW_ARB           0x8B64
#define GL_OBJECT_DELETE_STATUS_ARB             0x8B80
#define GL_OBJECT_COMPILE_STATUS_ARB            0x8B81
#define GL_OBJECT_LINK_STATUS_ARB               0x8B82
#define GL_OBJECT_VALIDATE_STATUS_ARB           0x8B83
#define GL_OBJECT_INFO_LOG_LENGTH_ARB           0x8B84
#define GL_OBJECT_ATTACHED_OBJECTS_ARB          0x8B85
#define GL_OBJECT_ACTIVE_UNIFORMS_ARB           0x8B86
#define GL_OBJECT_ACTIVE_UNIFORM_MAX_LENGTH_ARB 0x8B87
#define GL_OBJECT_SHADER_SOURCE_LENGTH_ARB      0x8B88
typedef char GLcharARB;
typedef unsigned int GLhandleARB;

typedef void (APIENTRY* pfn_glDeleteObjectARB) (GLhandleARB);
WM3_EXTERN pfn_glDeleteObjectARB Wm3glDeleteObjectARB;
#define glDeleteObjectARB Wm3glDeleteObjectARB

typedef GLhandleARB (APIENTRY* pfn_glGetHandleARB) (GLenum);
WM3_EXTERN pfn_glGetHandleARB Wm3glGetHandleARB;
#define glGetHandleARB Wm3glGetHandleARB

typedef void (APIENTRY* pfn_glDetachObjectARB) (GLhandleARB, GLhandleARB);
WM3_EXTERN pfn_glDetachObjectARB Wm3glDetachObjectARB;
#define glDetachObjectARB Wm3glDetachObjectARB

typedef GLhandleARB (APIENTRY* pfn_glCreateShaderObjectARB) (GLenum);
WM3_EXTERN pfn_glCreateShaderObjectARB Wm3glCreateShaderObjectARB;
#define glCreateShaderObjectARB Wm3glCreateShaderObjectARB

typedef void (APIENTRY* pfn_glShaderSourceARB) (GLhandleARB, GLsizei, const GLcharARB**, const GLint*);
WM3_EXTERN pfn_glShaderSourceARB Wm3glShaderSourceARB;
#define glShaderSourceARB Wm3glShaderSourceARB

typedef void (APIENTRY* pfn_glCompileShaderARB) (GLhandleARB);
WM3_EXTERN pfn_glCompileShaderARB Wm3glCompileShaderARB;
#define glCompileShaderARB Wm3glCompileShaderARB

typedef GLhandleARB (APIENTRY* pfn_glCreateProgramObjectARB) (void);
WM3_EXTERN pfn_glCreateProgramObjectARB Wm3glCreateProgramObjectARB;
#define glCreateProgramObjectARB Wm3glCreateProgramObjectARB

typedef void (APIENTRY* pfn_glAttachObjectARB) (GLhandleARB, GLhandleARB);
WM3_EXTERN pfn_glAttachObjectARB Wm3glAttachObjectARB;
#define glAttachObjectARB Wm3glAttachObjectARB

typedef void (APIENTRY* pfn_glLinkProgramARB) (GLhandleARB);
WM3_EXTERN pfn_glLinkProgramARB Wm3glLinkProgramARB;
#define glLinkProgramARB Wm3glLinkProgramARB

typedef void (APIENTRY* pfn_glUseProgramObjectARB) (GLhandleARB);
WM3_EXTERN pfn_glUseProgramObjectARB Wm3glUseProgramObjectARB;
#define glUseProgramObjectARB Wm3glUseProgramObjectARB

typedef void (APIENTRY* pfn_glValidateProgramARB) (GLhandleARB);
WM3_EXTERN pfn_glValidateProgramARB Wm3glValidateProgramARB;
#define glValidateProgramARB Wm3glValidateProgramARB

typedef void (APIENTRY* pfn_glUniform1fARB) (GLint, GLfloat);
WM3_EXTERN pfn_glUniform1fARB Wm3glUniform1fARB;
#define glUniform1fARB Wm3glUniform1fARB

typedef void (APIENTRY* pfn_glUniform2fARB) (GLint, GLfloat, GLfloat);
WM3_EXTERN pfn_glUniform2fARB Wm3glUniform2fARB;
#define glUniform2fARB Wm3glUniform2fARB

typedef void (APIENTRY* pfn_glUniform3fARB) (GLint, GLfloat, GLfloat, GLfloat);
WM3_EXTERN pfn_glUniform3fARB Wm3glUniform3fARB;
#define glUniform3fARB Wm3glUniform3fARB

typedef void (APIENTRY* pfn_glUniform4fARB) (GLint, GLfloat, GLfloat, GLfloat, GLfloat);
WM3_EXTERN pfn_glUniform4fARB Wm3glUniform4fARB;
#define glUniform4fARB Wm3glUniform4fARB

typedef void (APIENTRY* pfn_glUniform1iARB) (GLint, GLint);
WM3_EXTERN pfn_glUniform1iARB Wm3glUniform1iARB;
#define glUniform1iARB Wm3glUniform1iARB

typedef void (APIENTRY* pfn_glUniform2iARB) (GLint, GLint, GLint);
WM3_EXTERN pfn_glUniform2iARB Wm3glUniform2iARB;
#define glUniform2iARB Wm3glUniform2iARB

typedef void (APIENTRY* pfn_glUniform3iARB) (GLint, GLint, GLint, GLint);
WM3_EXTERN pfn_glUniform3iARB Wm3glUniform3iARB;
#define glUniform3iARB Wm3glUniform3iARB

typedef void (APIENTRY* pfn_glUniform4iARB) (GLint, GLint, GLint, GLint, GLint);
WM3_EXTERN pfn_glUniform4iARB Wm3glUniform4iARB;
#define glUniform4iARB Wm3glUniform4iARB

typedef void (APIENTRY* pfn_glUniform1fvARB) (GLint, GLsizei, const GLfloat*);
WM3_EXTERN pfn_glUniform1fvARB Wm3glUniform1fvARB;
#define glUniform1fvARB Wm3glUniform1fvARB

typedef void (APIENTRY* pfn_glUniform2fvARB) (GLint, GLsizei, const GLfloat*);
WM3_EXTERN pfn_glUniform2fvARB Wm3glUniform2fvARB;
#define glUniform2fvARB Wm3glUniform2fvARB

typedef void (APIENTRY* pfn_glUniform3fvARB) (GLint, GLsizei, const GLfloat*);
WM3_EXTERN pfn_glUniform3fvARB Wm3glUniform3fvARB;
#define glUniform3fvARB Wm3glUniform3fvARB

typedef void (APIENTRY* pfn_glUniform4fvARB) (GLint, GLsizei, const GLfloat*);
WM3_EXTERN pfn_glUniform4fvARB Wm3glUniform4fvARB;
#define glUniform4fvARB Wm3glUniform4fvARB

typedef void (APIENTRY* pfn_glUniform1ivARB) (GLint, GLsizei, const GLint*);
WM3_EXTERN pfn_glUniform1ivARB Wm3glUniform1ivARB;
#define glUniform1ivARB Wm3glUniform1ivARB

typedef void (APIENTRY* pfn_glUniform2ivARB) (GLint, GLsizei, const GLint*);
WM3_EXTERN pfn_glUniform2ivARB Wm3glUniform2ivARB;
#define glUniform2ivARB Wm3glUniform2ivARB

typedef void (APIENTRY* pfn_glUniform3ivARB) (GLint, GLsizei, const GLint*);
WM3_EXTERN pfn_glUniform3ivARB Wm3glUniform3ivARB;
#define glUniform3ivARB Wm3glUniform3ivARB

typedef void (APIENTRY* pfn_glUniform4ivARB) (GLint, GLsizei, const GLint*);
WM3_EXTERN pfn_glUniform4ivARB Wm3glUniform4ivARB;
#define glUniform4ivARB Wm3glUniform4ivARB

typedef void (APIENTRY* pfn_glUniformMatrix2fvARB) (GLint, GLsizei, GLboolean, const GLfloat*);
WM3_EXTERN pfn_glUniformMatrix2fvARB Wm3glUniformMatrix2fvARB;
#define glUniformMatrix2fvARB Wm3glUniformMatrix2fvARB

typedef void (APIENTRY* pfn_glUniformMatrix3fvARB) (GLint, GLsizei, GLboolean, const GLfloat*);
WM3_EXTERN pfn_glUniformMatrix3fvARB Wm3glUniformMatrix3fvARB;
#define glUniformMatrix3fvARB Wm3glUniformMatrix3fvARB

typedef void (APIENTRY* pfn_glUniformMatrix4fvARB) (GLint, GLsizei, GLboolean, const GLfloat*);
WM3_EXTERN pfn_glUniformMatrix4fvARB Wm3glUniformMatrix4fvARB;
#define glUniformMatrix4fvARB Wm3glUniformMatrix4fvARB

typedef void (APIENTRY* pfn_glGetObjectParameterfvARB) (GLhandleARB, GLenum, GLfloat*);
WM3_EXTERN pfn_glGetObjectParameterfvARB Wm3glGetObjectParameterfvARB;
#define glGetObjectParameterfvARB Wm3glGetObjectParameterfvARB

typedef void (APIENTRY* pfn_glGetObjectParameterivARB) (GLhandleARB, GLenum, GLint*);
WM3_EXTERN pfn_glGetObjectParameterivARB Wm3glGetObjectParameterivARB;
#define glGetObjectParameterivARB Wm3glGetObjectParameterivARB

typedef void (APIENTRY* pfn_glGetInfoLogARB) (GLhandleARB, GLsizei, GLsizei*, GLcharARB*);
WM3_EXTERN pfn_glGetInfoLogARB Wm3glGetInfoLogARB;
#define glGetInfoLogARB Wm3glGetInfoLogARB

typedef void (APIENTRY* pfn_glGetAttachedObjectsARB) (GLhandleARB, GLsizei, GLsizei*, GLhandleARB*);
WM3_EXTERN pfn_glGetAttachedObjectsARB Wm3glGetAttachedObjectsARB;
#define glGetAttachedObjectsARB Wm3glGetAttachedObjectsARB

typedef GLint (APIENTRY* pfn_glGetUniformLocationARB) (GLhandleARB, const GLcharARB*);
WM3_EXTERN pfn_glGetUniformLocationARB Wm3glGetUniformLocationARB;
#define glGetUniformLocationARB Wm3glGetUniformLocationARB

typedef void (APIENTRY* pfn_glGetActiveUniformARB) (GLhandleARB, GLuint, GLsizei, GLsizei*, GLint*, GLenum*, GLcharARB*);
WM3_EXTERN pfn_glGetActiveUniformARB Wm3glGetActiveUniformARB;
#define glGetActiveUniformARB Wm3glGetActiveUniformARB

typedef void (APIENTRY* pfn_glGetUniformfvARB) (GLhandleARB, GLint, GLfloat*);
WM3_EXTERN pfn_glGetUniformfvARB Wm3glGetUniformfvARB;
#define glGetUniformfvARB Wm3glGetUniformfvARB

typedef void (APIENTRY* pfn_glGetUniformivARB) (GLhandleARB, GLint, GLint*);
WM3_EXTERN pfn_glGetUniformivARB Wm3glGetUniformivARB;
#define glGetUniformivARB Wm3glGetUniformivARB

typedef void (APIENTRY* pfn_glGetShaderSourceARB) (GLhandleARB, GLsizei, GLsizei*, GLcharARB*);
WM3_EXTERN pfn_glGetShaderSourceARB Wm3glGetShaderSourceARB;
#define glGetShaderSourceARB Wm3glGetShaderSourceARB
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_ARB_vertex_shader;
WM3_EXTERN int Wm3NumFunctions_GL_ARB_vertex_shader;
#ifndef GL_ARB_vertex_shader
#define GL_ARB_vertex_shader
#define WM3_DEFINED_GL_ARB_vertex_shader
#define GL_VERTEX_SHADER_ARB                        0x8B31
#define GL_MAX_VERTEX_UNIFORM_COMPONENTS_ARB        0x8B4A
#define GL_MAX_VARYING_FLOATS_ARB                   0x8B4B
#define GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS_ARB       0x8B4C
#define GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS_ARB     0x8B4D
#define GL_OBJECT_ACTIVE_ATTRIBUTES_ARB             0x8B89
#define GL_OBJECT_ACTIVE_ATTRIBUTE_MAX_LENGTH_ARB   0x8B8A

typedef void (APIENTRY* pfn_glBindAttribLocationARB) (GLhandleARB, GLuint, const GLcharARB*);
WM3_EXTERN pfn_glBindAttribLocationARB Wm3glBindAttribLocationARB;
#define glBindAttribLocationARB Wm3glBindAttribLocationARB

typedef void (APIENTRY* pfn_glGetActiveAttribARB) (GLhandleARB, GLuint, GLsizei, GLsizei*, GLint*, GLenum*, GLcharARB*);
WM3_EXTERN pfn_glGetActiveAttribARB Wm3glGetActiveAttribARB;
#define glGetActiveAttribARB Wm3glGetActiveAttribARB

typedef GLint (APIENTRY* pfn_glGetAttribLocationARB) (GLhandleARB, const GLcharARB*);
WM3_EXTERN pfn_glGetAttribLocationARB Wm3glGetAttribLocationARB;
#define glGetAttribLocationARB Wm3glGetAttribLocationARB
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_ARB_fragment_shader;
WM3_EXTERN int Wm3NumFunctions_GL_ARB_fragment_shader;
#ifndef GL_ARB_fragment_shader
#define GL_ARB_fragment_shader
#define WM3_DEFINED_GL_ARB_fragment_shader
#define GL_FRAGMENT_SHADER_ARB                  0x8B30
#define GL_MAX_FRAGMENT_UNIFORM_COMPONENTS_ARB  0x8B49
#define GL_FRAGMENT_SHADER_DERIVATIVE_HINT_ARB  0x8B8B
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_ARB_shading_language_100;
WM3_EXTERN int Wm3NumFunctions_GL_ARB_shading_language_100;
#ifndef GL_ARB_shading_language_100
#define GL_ARB_shading_language_100
#define WM3_DEFINED_GL_ARB_shading_language_100
#define GL_SHADING_LANGUAGE_VERSION_ARB   0x8B8C
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_ARB_texture_non_power_of_two;
WM3_EXTERN int Wm3NumFunctions_GL_ARB_texture_non_power_of_two;
#ifndef GL_ARB_texture_non_power_of_two
#define GL_ARB_texture_non_power_of_two
#define WM3_DEFINED_GL_ARB_texture_non_power_of_two
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_ARB_point_sprite;
WM3_EXTERN int Wm3NumFunctions_GL_ARB_point_sprite;
#ifndef GL_ARB_point_sprite
#define GL_ARB_point_sprite
#define WM3_DEFINED_GL_ARB_point_sprite
#define GL_POINT_SPRITE_ARB               0x8861
#define GL_COORD_REPLACE_ARB              0x8862
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_ARB_fragment_program_shadow;
WM3_EXTERN int Wm3NumFunctions_GL_ARB_fragment_program_shadow;
#ifndef GL_ARB_fragment_program_shadow
#define GL_ARB_fragment_program_shadow
#define WM3_DEFINED_GL_ARB_fragment_program_shadow
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_ARB_draw_buffers;
WM3_EXTERN int Wm3NumFunctions_GL_ARB_draw_buffers;
#ifndef GL_ARB_draw_buffers
#define GL_ARB_draw_buffers
#define WM3_DEFINED_GL_ARB_draw_buffers
#define GL_MAX_DRAW_BUFFERS_ARB           0x8824
#define GL_DRAW_BUFFER0_ARB               0x8825
#define GL_DRAW_BUFFER1_ARB               0x8826
#define GL_DRAW_BUFFER2_ARB               0x8827
#define GL_DRAW_BUFFER3_ARB               0x8828
#define GL_DRAW_BUFFER4_ARB               0x8829
#define GL_DRAW_BUFFER5_ARB               0x882A
#define GL_DRAW_BUFFER6_ARB               0x882B
#define GL_DRAW_BUFFER7_ARB               0x882C
#define GL_DRAW_BUFFER8_ARB               0x882D
#define GL_DRAW_BUFFER9_ARB               0x882E
#define GL_DRAW_BUFFER10_ARB              0x882F
#define GL_DRAW_BUFFER11_ARB              0x8830
#define GL_DRAW_BUFFER12_ARB              0x8831
#define GL_DRAW_BUFFER13_ARB              0x8832
#define GL_DRAW_BUFFER14_ARB              0x8833
#define GL_DRAW_BUFFER15_ARB              0x8834

typedef void (APIENTRY* pfn_glDrawBuffersARB) (GLsizei, const GLenum*);
WM3_EXTERN pfn_glDrawBuffersARB Wm3glDrawBuffersARB;
#define glDrawBuffersARB Wm3glDrawBuffersARB
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_ARB_texture_rectangle;
WM3_EXTERN int Wm3NumFunctions_GL_ARB_texture_rectangle;
#ifndef GL_ARB_texture_rectangle
#define GL_ARB_texture_rectangle
#define WM3_DEFINED_GL_ARB_texture_rectangle
#define GL_TEXTURE_RECTANGLE_ARB          0x84F5
#define GL_TEXTURE_BINDING_RECTANGLE_ARB  0x84F6
#define GL_PROXY_TEXTURE_RECTANGLE_ARB    0x84F7
#define GL_MAX_RECTANGLE_TEXTURE_SIZE_ARB 0x84F8
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_ARB_color_buffer_float;
WM3_EXTERN int Wm3NumFunctions_GL_ARB_color_buffer_float;
#ifndef GL_ARB_color_buffer_float
#define GL_ARB_color_buffer_float
#define WM3_DEFINED_GL_ARB_color_buffer_float
#define GL_RGBA_FLOAT_MODE_ARB            0x8820
#define GL_CLAMP_VERTEX_COLOR_ARB         0x891A
#define GL_CLAMP_FRAGMENT_COLOR_ARB       0x891B
#define GL_CLAMP_READ_COLOR_ARB           0x891C
#define GL_FIXED_ONLY_ARB                 0x891D

typedef void (APIENTRY* pfn_glClampColorARB) (GLenum, GLenum);
WM3_EXTERN pfn_glClampColorARB Wm3glClampColorARB;
#define glClampColorARB Wm3glClampColorARB
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_ARB_half_float_pixel;
WM3_EXTERN int Wm3NumFunctions_GL_ARB_half_float_pixel;
#ifndef GL_ARB_half_float_pixel
#define GL_ARB_half_float_pixel
#define WM3_DEFINED_GL_ARB_half_float_pixel
#define GL_HALF_FLOAT_ARB                 0x140B
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_ARB_texture_float;
WM3_EXTERN int Wm3NumFunctions_GL_ARB_texture_float;
#ifndef GL_ARB_texture_float
#define GL_ARB_texture_float
#define WM3_DEFINED_GL_ARB_texture_float
#define GL_TEXTURE_RED_TYPE_ARB           0x8C10
#define GL_TEXTURE_GREEN_TYPE_ARB         0x8C11
#define GL_TEXTURE_BLUE_TYPE_ARB          0x8C12
#define GL_TEXTURE_ALPHA_TYPE_ARB         0x8C13
#define GL_TEXTURE_LUMINANCE_TYPE_ARB     0x8C14
#define GL_TEXTURE_INTENSITY_TYPE_ARB     0x8C15
#define GL_TEXTURE_DEPTH_TYPE_ARB         0x8C16
#define GL_UNSIGNED_NORMALIZED_ARB        0x8C17
#define GL_RGBA32F_ARB                    0x8814
#define GL_RGB32F_ARB                     0x8815
#define GL_ALPHA32F_ARB                   0x8816
#define GL_INTENSITY32F_ARB               0x8817
#define GL_LUMINANCE32F_ARB               0x8818
#define GL_LUMINANCE_ALPHA32F_ARB         0x8819
#define GL_RGBA16F_ARB                    0x881A
#define GL_RGB16F_ARB                     0x881B
#define GL_ALPHA16F_ARB                   0x881C
#define GL_INTENSITY16F_ARB               0x881D
#define GL_LUMINANCE16F_ARB               0x881E
#define GL_LUMINANCE_ALPHA16F_ARB         0x881F
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_ARB_pixel_buffer_object;
WM3_EXTERN int Wm3NumFunctions_GL_ARB_pixel_buffer_object;
#ifndef GL_ARB_pixel_buffer_object
#define GL_ARB_pixel_buffer_object
#define WM3_DEFINED_GL_ARB_pixel_buffer_object
#define GL_PIXEL_PACK_BUFFER_ARB            0x88EB
#define GL_PIXEL_UNPACK_BUFFER_ARB          0x88EC
#define GL_PIXEL_PACK_BUFFER_BINDING_ARB    0x88ED
#define GL_PIXEL_UNPACK_BUFFER_BINDING_ARB  0x88EF
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_EXT_abgr;
WM3_EXTERN int Wm3NumFunctions_GL_EXT_abgr;
#ifndef GL_EXT_abgr
#define GL_EXT_abgr
#define WM3_DEFINED_GL_EXT_abgr
#define GL_ABGR_EXT                       0x8000
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_EXT_blend_color;
WM3_EXTERN int Wm3NumFunctions_GL_EXT_blend_color;
#ifndef GL_EXT_blend_color
#define GL_EXT_blend_color
#define WM3_DEFINED_GL_EXT_blend_color
#define GL_CONSTANT_COLOR_EXT             0x8001
#define GL_ONE_MINUS_CONSTANT_COLOR_EXT   0x8002
#define GL_CONSTANT_ALPHA_EXT             0x8003
#define GL_ONE_MINUS_CONSTANT_ALPHA_EXT   0x8004
#define GL_BLEND_COLOR_EXT                0x8005

typedef void (APIENTRY* pfn_glBlendColorEXT) (GLclampf, GLclampf, GLclampf, GLclampf);
WM3_EXTERN pfn_glBlendColorEXT Wm3glBlendColorEXT;
#define glBlendColorEXT Wm3glBlendColorEXT
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_EXT_polygon_offset;
WM3_EXTERN int Wm3NumFunctions_GL_EXT_polygon_offset;
#ifndef GL_EXT_polygon_offset
#define GL_EXT_polygon_offset
#define WM3_DEFINED_GL_EXT_polygon_offset
#define GL_POLYGON_OFFSET_EXT             0x8037
#define GL_POLYGON_OFFSET_FACTOR_EXT      0x8038
#define GL_POLYGON_OFFSET_BIAS_EXT        0x8039

typedef void (APIENTRY* pfn_glPolygonOffsetEXT) (GLfloat, GLfloat);
WM3_EXTERN pfn_glPolygonOffsetEXT Wm3glPolygonOffsetEXT;
#define glPolygonOffsetEXT Wm3glPolygonOffsetEXT
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_EXT_texture;
WM3_EXTERN int Wm3NumFunctions_GL_EXT_texture;
#ifndef GL_EXT_texture
#define GL_EXT_texture
#define WM3_DEFINED_GL_EXT_texture
#define GL_ALPHA4_EXT                     0x803B
#define GL_ALPHA8_EXT                     0x803C
#define GL_ALPHA12_EXT                    0x803D
#define GL_ALPHA16_EXT                    0x803E
#define GL_LUMINANCE4_EXT                 0x803F
#define GL_LUMINANCE8_EXT                 0x8040
#define GL_LUMINANCE12_EXT                0x8041
#define GL_LUMINANCE16_EXT                0x8042
#define GL_LUMINANCE4_ALPHA4_EXT          0x8043
#define GL_LUMINANCE6_ALPHA2_EXT          0x8044
#define GL_LUMINANCE8_ALPHA8_EXT          0x8045
#define GL_LUMINANCE12_ALPHA4_EXT         0x8046
#define GL_LUMINANCE12_ALPHA12_EXT        0x8047
#define GL_LUMINANCE16_ALPHA16_EXT        0x8048
#define GL_INTENSITY_EXT                  0x8049
#define GL_INTENSITY4_EXT                 0x804A
#define GL_INTENSITY8_EXT                 0x804B
#define GL_INTENSITY12_EXT                0x804C
#define GL_INTENSITY16_EXT                0x804D
#define GL_RGB2_EXT                       0x804E
#define GL_RGB4_EXT                       0x804F
#define GL_RGB5_EXT                       0x8050
#define GL_RGB8_EXT                       0x8051
#define GL_RGB10_EXT                      0x8052
#define GL_RGB12_EXT                      0x8053
#define GL_RGB16_EXT                      0x8054
#define GL_RGBA2_EXT                      0x8055
#define GL_RGBA4_EXT                      0x8056
#define GL_RGB5_A1_EXT                    0x8057
#define GL_RGBA8_EXT                      0x8058
#define GL_RGB10_A2_EXT                   0x8059
#define GL_RGBA12_EXT                     0x805A
#define GL_RGBA16_EXT                     0x805B
#define GL_TEXTURE_RED_SIZE_EXT           0x805C
#define GL_TEXTURE_GREEN_SIZE_EXT         0x805D
#define GL_TEXTURE_BLUE_SIZE_EXT          0x805E
#define GL_TEXTURE_ALPHA_SIZE_EXT         0x805F
#define GL_TEXTURE_LUMINANCE_SIZE_EXT     0x8060
#define GL_TEXTURE_INTENSITY_SIZE_EXT     0x8061
#define GL_REPLACE_EXT                    0x8062
#define GL_PROXY_TEXTURE_1D_EXT           0x8063
#define GL_PROXY_TEXTURE_2D_EXT           0x8064
#define GL_TEXTURE_TOO_LARGE_EXT          0x8065
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_EXT_texture3D;
WM3_EXTERN int Wm3NumFunctions_GL_EXT_texture3D;
#ifndef GL_EXT_texture3D
#define GL_EXT_texture3D
#define WM3_DEFINED_GL_EXT_texture3D
#define GL_PACK_SKIP_IMAGES_EXT           0x806B
#define GL_PACK_IMAGE_HEIGHT_EXT          0x806C
#define GL_UNPACK_SKIP_IMAGES_EXT         0x806D
#define GL_UNPACK_IMAGE_HEIGHT_EXT        0x806E
#define GL_TEXTURE_3D_EXT                 0x806F
#define GL_PROXY_TEXTURE_3D_EXT           0x8070
#define GL_TEXTURE_DEPTH_EXT              0x8071
#define GL_TEXTURE_WRAP_R_EXT             0x8072
#define GL_MAX_3D_TEXTURE_SIZE_EXT        0x8073

typedef void (APIENTRY* pfn_glTexImage3DEXT) (GLenum, GLint, GLenum, GLsizei, GLsizei, GLsizei, GLint, GLenum, GLenum, const GLvoid*);
WM3_EXTERN pfn_glTexImage3DEXT Wm3glTexImage3DEXT;
#define glTexImage3DEXT Wm3glTexImage3DEXT

typedef void (APIENTRY* pfn_glTexSubImage3DEXT) (GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLenum, const GLvoid*);
WM3_EXTERN pfn_glTexSubImage3DEXT Wm3glTexSubImage3DEXT;
#define glTexSubImage3DEXT Wm3glTexSubImage3DEXT
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_SGIS_texture_filter4;
WM3_EXTERN int Wm3NumFunctions_GL_SGIS_texture_filter4;
#ifndef GL_SGIS_texture_filter4
#define GL_SGIS_texture_filter4
#define WM3_DEFINED_GL_SGIS_texture_filter4
#define GL_FILTER4_SGIS                   0x8146
#define GL_TEXTURE_FILTER4_SIZE_SGIS      0x8147

typedef void (APIENTRY* pfn_glGetTexFilterFuncSGIS) (GLenum, GLenum, GLfloat*);
WM3_EXTERN pfn_glGetTexFilterFuncSGIS Wm3glGetTexFilterFuncSGIS;
#define glGetTexFilterFuncSGIS Wm3glGetTexFilterFuncSGIS

typedef void (APIENTRY* pfn_glTexFilterFuncSGIS) (GLenum, GLenum, GLsizei, const GLfloat*);
WM3_EXTERN pfn_glTexFilterFuncSGIS Wm3glTexFilterFuncSGIS;
#define glTexFilterFuncSGIS Wm3glTexFilterFuncSGIS
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_EXT_subtexture;
WM3_EXTERN int Wm3NumFunctions_GL_EXT_subtexture;
#ifndef GL_EXT_subtexture
#define GL_EXT_subtexture
#define WM3_DEFINED_GL_EXT_subtexture

typedef void (APIENTRY* pfn_glTexSubImage1DEXT) (GLenum, GLint, GLint, GLsizei, GLenum, GLenum, const GLvoid*);
WM3_EXTERN pfn_glTexSubImage1DEXT Wm3glTexSubImage1DEXT;
#define glTexSubImage1DEXT Wm3glTexSubImage1DEXT

typedef void (APIENTRY* pfn_glTexSubImage2DEXT) (GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, const GLvoid*);
WM3_EXTERN pfn_glTexSubImage2DEXT Wm3glTexSubImage2DEXT;
#define glTexSubImage2DEXT Wm3glTexSubImage2DEXT
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_EXT_copy_texture;
WM3_EXTERN int Wm3NumFunctions_GL_EXT_copy_texture;
#ifndef GL_EXT_copy_texture
#define GL_EXT_copy_texture
#define WM3_DEFINED_GL_EXT_copy_texture

typedef void (APIENTRY* pfn_glCopyTexImage1DEXT) (GLenum, GLint, GLenum, GLint, GLint, GLsizei, GLint);
WM3_EXTERN pfn_glCopyTexImage1DEXT Wm3glCopyTexImage1DEXT;
#define glCopyTexImage1DEXT Wm3glCopyTexImage1DEXT

typedef void (APIENTRY* pfn_glCopyTexImage2DEXT) (GLenum, GLint, GLenum, GLint, GLint, GLsizei, GLsizei, GLint);
WM3_EXTERN pfn_glCopyTexImage2DEXT Wm3glCopyTexImage2DEXT;
#define glCopyTexImage2DEXT Wm3glCopyTexImage2DEXT

typedef void (APIENTRY* pfn_glCopyTexSubImage1DEXT) (GLenum, GLint, GLint, GLint, GLint, GLsizei);
WM3_EXTERN pfn_glCopyTexSubImage1DEXT Wm3glCopyTexSubImage1DEXT;
#define glCopyTexSubImage1DEXT Wm3glCopyTexSubImage1DEXT

typedef void (APIENTRY* pfn_glCopyTexSubImage2DEXT) (GLenum, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei);
WM3_EXTERN pfn_glCopyTexSubImage2DEXT Wm3glCopyTexSubImage2DEXT;
#define glCopyTexSubImage2DEXT Wm3glCopyTexSubImage2DEXT

typedef void (APIENTRY* pfn_glCopyTexSubImage3DEXT) (GLenum, GLint, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei);
WM3_EXTERN pfn_glCopyTexSubImage3DEXT Wm3glCopyTexSubImage3DEXT;
#define glCopyTexSubImage3DEXT Wm3glCopyTexSubImage3DEXT
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_EXT_histogram;
WM3_EXTERN int Wm3NumFunctions_GL_EXT_histogram;
#ifndef GL_EXT_histogram
#define GL_EXT_histogram
#define WM3_DEFINED_GL_EXT_histogram
#define GL_HISTOGRAM_EXT                  0x8024
#define GL_PROXY_HISTOGRAM_EXT            0x8025
#define GL_HISTOGRAM_WIDTH_EXT            0x8026
#define GL_HISTOGRAM_FORMAT_EXT           0x8027
#define GL_HISTOGRAM_RED_SIZE_EXT         0x8028
#define GL_HISTOGRAM_GREEN_SIZE_EXT       0x8029
#define GL_HISTOGRAM_BLUE_SIZE_EXT        0x802A
#define GL_HISTOGRAM_ALPHA_SIZE_EXT       0x802B
#define GL_HISTOGRAM_LUMINANCE_SIZE_EXT   0x802C
#define GL_HISTOGRAM_SINK_EXT             0x802D
#define GL_MINMAX_EXT                     0x802E
#define GL_MINMAX_FORMAT_EXT              0x802F
#define GL_MINMAX_SINK_EXT                0x8030
#define GL_TABLE_TOO_LARGE_EXT            0x8031

typedef void (APIENTRY* pfn_glGetHistogramEXT) (GLenum, GLboolean, GLenum, GLenum, GLvoid*);
WM3_EXTERN pfn_glGetHistogramEXT Wm3glGetHistogramEXT;
#define glGetHistogramEXT Wm3glGetHistogramEXT

typedef void (APIENTRY* pfn_glGetHistogramParameterfvEXT) (GLenum, GLenum, GLfloat*);
WM3_EXTERN pfn_glGetHistogramParameterfvEXT Wm3glGetHistogramParameterfvEXT;
#define glGetHistogramParameterfvEXT Wm3glGetHistogramParameterfvEXT

typedef void (APIENTRY* pfn_glGetHistogramParameterivEXT) (GLenum, GLenum, GLint*);
WM3_EXTERN pfn_glGetHistogramParameterivEXT Wm3glGetHistogramParameterivEXT;
#define glGetHistogramParameterivEXT Wm3glGetHistogramParameterivEXT

typedef void (APIENTRY* pfn_glGetMinmaxEXT) (GLenum, GLboolean, GLenum, GLenum, GLvoid*);
WM3_EXTERN pfn_glGetMinmaxEXT Wm3glGetMinmaxEXT;
#define glGetMinmaxEXT Wm3glGetMinmaxEXT

typedef void (APIENTRY* pfn_glGetMinmaxParameterfvEXT) (GLenum, GLenum, GLfloat*);
WM3_EXTERN pfn_glGetMinmaxParameterfvEXT Wm3glGetMinmaxParameterfvEXT;
#define glGetMinmaxParameterfvEXT Wm3glGetMinmaxParameterfvEXT

typedef void (APIENTRY* pfn_glGetMinmaxParameterivEXT) (GLenum, GLenum, GLint*);
WM3_EXTERN pfn_glGetMinmaxParameterivEXT Wm3glGetMinmaxParameterivEXT;
#define glGetMinmaxParameterivEXT Wm3glGetMinmaxParameterivEXT

typedef void (APIENTRY* pfn_glHistogramEXT) (GLenum, GLsizei, GLenum, GLboolean);
WM3_EXTERN pfn_glHistogramEXT Wm3glHistogramEXT;
#define glHistogramEXT Wm3glHistogramEXT

typedef void (APIENTRY* pfn_glMinmaxEXT) (GLenum, GLenum, GLboolean);
WM3_EXTERN pfn_glMinmaxEXT Wm3glMinmaxEXT;
#define glMinmaxEXT Wm3glMinmaxEXT

typedef void (APIENTRY* pfn_glResetHistogramEXT) (GLenum);
WM3_EXTERN pfn_glResetHistogramEXT Wm3glResetHistogramEXT;
#define glResetHistogramEXT Wm3glResetHistogramEXT

typedef void (APIENTRY* pfn_glResetMinmaxEXT) (GLenum);
WM3_EXTERN pfn_glResetMinmaxEXT Wm3glResetMinmaxEXT;
#define glResetMinmaxEXT Wm3glResetMinmaxEXT
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_EXT_convolution;
WM3_EXTERN int Wm3NumFunctions_GL_EXT_convolution;
#ifndef GL_EXT_convolution
#define GL_EXT_convolution
#define WM3_DEFINED_GL_EXT_convolution
#define GL_CONVOLUTION_1D_EXT               0x8010
#define GL_CONVOLUTION_2D_EXT               0x8011
#define GL_SEPARABLE_2D_EXT                 0x8012
#define GL_CONVOLUTION_BORDER_MODE_EXT      0x8013
#define GL_CONVOLUTION_FILTER_SCALE_EXT     0x8014
#define GL_CONVOLUTION_FILTER_BIAS_EXT      0x8015
#define GL_REDUCE_EXT                       0x8016
#define GL_CONVOLUTION_FORMAT_EXT           0x8017
#define GL_CONVOLUTION_WIDTH_EXT            0x8018
#define GL_CONVOLUTION_HEIGHT_EXT           0x8019
#define GL_MAX_CONVOLUTION_WIDTH_EXT        0x801A
#define GL_MAX_CONVOLUTION_HEIGHT_EXT       0x801B
#define GL_POST_CONVOLUTION_RED_SCALE_EXT   0x801C
#define GL_POST_CONVOLUTION_GREEN_SCALE_EXT 0x801D
#define GL_POST_CONVOLUTION_BLUE_SCALE_EXT  0x801E
#define GL_POST_CONVOLUTION_ALPHA_SCALE_EXT 0x801F
#define GL_POST_CONVOLUTION_RED_BIAS_EXT    0x8020
#define GL_POST_CONVOLUTION_GREEN_BIAS_EXT  0x8021
#define GL_POST_CONVOLUTION_BLUE_BIAS_EXT   0x8022
#define GL_POST_CONVOLUTION_ALPHA_BIAS_EXT  0x8023

typedef void (APIENTRY* pfn_glConvolutionFilter1DEXT) (GLenum, GLenum, GLsizei, GLenum, GLenum, const GLvoid*);
WM3_EXTERN pfn_glConvolutionFilter1DEXT Wm3glConvolutionFilter1DEXT;
#define glConvolutionFilter1DEXT Wm3glConvolutionFilter1DEXT

typedef void (APIENTRY* pfn_glConvolutionFilter2DEXT) (GLenum, GLenum, GLsizei, GLsizei, GLenum, GLenum, const GLvoid*);
WM3_EXTERN pfn_glConvolutionFilter2DEXT Wm3glConvolutionFilter2DEXT;
#define glConvolutionFilter2DEXT Wm3glConvolutionFilter2DEXT

typedef void (APIENTRY* pfn_glConvolutionParameterfEXT) (GLenum, GLenum, GLfloat);
WM3_EXTERN pfn_glConvolutionParameterfEXT Wm3glConvolutionParameterfEXT;
#define glConvolutionParameterfEXT Wm3glConvolutionParameterfEXT

typedef void (APIENTRY* pfn_glConvolutionParameterfvEXT) (GLenum, GLenum, const GLfloat*);
WM3_EXTERN pfn_glConvolutionParameterfvEXT Wm3glConvolutionParameterfvEXT;
#define glConvolutionParameterfvEXT Wm3glConvolutionParameterfvEXT

typedef void (APIENTRY* pfn_glConvolutionParameteriEXT) (GLenum, GLenum, GLint);
WM3_EXTERN pfn_glConvolutionParameteriEXT Wm3glConvolutionParameteriEXT;
#define glConvolutionParameteriEXT Wm3glConvolutionParameteriEXT

typedef void (APIENTRY* pfn_glConvolutionParameterivEXT) (GLenum, GLenum, const GLint*);
WM3_EXTERN pfn_glConvolutionParameterivEXT Wm3glConvolutionParameterivEXT;
#define glConvolutionParameterivEXT Wm3glConvolutionParameterivEXT

typedef void (APIENTRY* pfn_glCopyConvolutionFilter1DEXT) (GLenum, GLenum, GLint, GLint, GLsizei);
WM3_EXTERN pfn_glCopyConvolutionFilter1DEXT Wm3glCopyConvolutionFilter1DEXT;
#define glCopyConvolutionFilter1DEXT Wm3glCopyConvolutionFilter1DEXT

typedef void (APIENTRY* pfn_glCopyConvolutionFilter2DEXT) (GLenum, GLenum, GLint, GLint, GLsizei, GLsizei);
WM3_EXTERN pfn_glCopyConvolutionFilter2DEXT Wm3glCopyConvolutionFilter2DEXT;
#define glCopyConvolutionFilter2DEXT Wm3glCopyConvolutionFilter2DEXT

typedef void (APIENTRY* pfn_glGetConvolutionFilterEXT) (GLenum, GLenum, GLenum, GLvoid*);
WM3_EXTERN pfn_glGetConvolutionFilterEXT Wm3glGetConvolutionFilterEXT;
#define glGetConvolutionFilterEXT Wm3glGetConvolutionFilterEXT

typedef void (APIENTRY* pfn_glGetConvolutionParameterfvEXT) (GLenum, GLenum, GLfloat*);
WM3_EXTERN pfn_glGetConvolutionParameterfvEXT Wm3glGetConvolutionParameterfvEXT;
#define glGetConvolutionParameterfvEXT Wm3glGetConvolutionParameterfvEXT

typedef void (APIENTRY* pfn_glGetConvolutionParameterivEXT) (GLenum, GLenum, GLint*);
WM3_EXTERN pfn_glGetConvolutionParameterivEXT Wm3glGetConvolutionParameterivEXT;
#define glGetConvolutionParameterivEXT Wm3glGetConvolutionParameterivEXT

typedef void (APIENTRY* pfn_glGetSeparableFilterEXT) (GLenum, GLenum, GLenum, GLvoid*, GLvoid*, GLvoid*);
WM3_EXTERN pfn_glGetSeparableFilterEXT Wm3glGetSeparableFilterEXT;
#define glGetSeparableFilterEXT Wm3glGetSeparableFilterEXT

typedef void (APIENTRY* pfn_glSeparableFilter2DEXT) (GLenum, GLenum, GLsizei, GLsizei, GLenum, GLenum, const GLvoid*, const GLvoid*);
WM3_EXTERN pfn_glSeparableFilter2DEXT Wm3glSeparableFilter2DEXT;
#define glSeparableFilter2DEXT Wm3glSeparableFilter2DEXT
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_EXT_color_matrix;
WM3_EXTERN int Wm3NumFunctions_GL_EXT_color_matrix;
#ifndef GL_EXT_color_matrix
#define GL_EXT_color_matrix
#define WM3_DEFINED_GL_EXT_color_matrix
#define GL_COLOR_MATRIX_SGI                     0x80B1
#define GL_COLOR_MATRIX_STACK_DEPTH_SGI         0x80B2
#define GL_MAX_COLOR_MATRIX_STACK_DEPTH_SGI     0x80B3
#define GL_POST_COLOR_MATRIX_RED_SCALE_SGI      0x80B4
#define GL_POST_COLOR_MATRIX_GREEN_SCALE_SGI    0x80B5
#define GL_POST_COLOR_MATRIX_BLUE_SCALE_SGI     0x80B6
#define GL_POST_COLOR_MATRIX_ALPHA_SCALE_SGI    0x80B7
#define GL_POST_COLOR_MATRIX_RED_BIAS_SGI       0x80B8
#define GL_POST_COLOR_MATRIX_GREEN_BIAS_SGI     0x80B9
#define GL_POST_COLOR_MATRIX_BLUE_BIAS_SGI      0x80BA
#define GL_POST_COLOR_MATRIX_ALPHA_BIAS_SGI     0x80BB
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_SGI_color_table;
WM3_EXTERN int Wm3NumFunctions_GL_SGI_color_table;
#ifndef GL_SGI_color_table
#define GL_SGI_color_table
#define WM3_DEFINED_GL_SGI_color_table
#define GL_COLOR_TABLE_SGI                          0x80D0
#define GL_POST_CONVOLUTION_COLOR_TABLE_SGI         0x80D1
#define GL_POST_COLOR_MATRIX_COLOR_TABLE_SGI        0x80D2
#define GL_PROXY_COLOR_TABLE_SGI                    0x80D3
#define GL_PROXY_POST_CONVOLUTION_COLOR_TABLE_SGI   0x80D4
#define GL_PROXY_POST_COLOR_MATRIX_COLOR_TABLE_SGI  0x80D5
#define GL_COLOR_TABLE_SCALE_SGI                    0x80D6
#define GL_COLOR_TABLE_BIAS_SGI                     0x80D7
#define GL_COLOR_TABLE_FORMAT_SGI                   0x80D8
#define GL_COLOR_TABLE_WIDTH_SGI                    0x80D9
#define GL_COLOR_TABLE_RED_SIZE_SGI                 0x80DA
#define GL_COLOR_TABLE_GREEN_SIZE_SGI               0x80DB
#define GL_COLOR_TABLE_BLUE_SIZE_SGI                0x80DC
#define GL_COLOR_TABLE_ALPHA_SIZE_SGI               0x80DD
#define GL_COLOR_TABLE_LUMINANCE_SIZE_SGI           0x80DE
#define GL_COLOR_TABLE_INTENSITY_SIZE_SGI           0x80DF

typedef void (APIENTRY* pfn_glColorTableSGI) (GLenum, GLenum, GLsizei, GLenum, GLenum, const GLvoid*);
WM3_EXTERN pfn_glColorTableSGI Wm3glColorTableSGI;
#define glColorTableSGI Wm3glColorTableSGI

typedef void (APIENTRY* pfn_glColorTableParameterfvSGI) (GLenum, GLenum, const GLfloat*);
WM3_EXTERN pfn_glColorTableParameterfvSGI Wm3glColorTableParameterfvSGI;
#define glColorTableParameterfvSGI Wm3glColorTableParameterfvSGI

typedef void (APIENTRY* pfn_glColorTableParameterivSGI) (GLenum, GLenum, const GLint*);
WM3_EXTERN pfn_glColorTableParameterivSGI Wm3glColorTableParameterivSGI;
#define glColorTableParameterivSGI Wm3glColorTableParameterivSGI

typedef void (APIENTRY* pfn_glCopyColorTableSGI) (GLenum, GLenum, GLint, GLint, GLsizei);
WM3_EXTERN pfn_glCopyColorTableSGI Wm3glCopyColorTableSGI;
#define glCopyColorTableSGI Wm3glCopyColorTableSGI

typedef void (APIENTRY* pfn_glGetColorTableSGI) (GLenum, GLenum, GLenum, GLvoid*);
WM3_EXTERN pfn_glGetColorTableSGI Wm3glGetColorTableSGI;
#define glGetColorTableSGI Wm3glGetColorTableSGI

typedef void (APIENTRY* pfn_glGetColorTableParameterfvSGI) (GLenum, GLenum, GLfloat*);
WM3_EXTERN pfn_glGetColorTableParameterfvSGI Wm3glGetColorTableParameterfvSGI;
#define glGetColorTableParameterfvSGI Wm3glGetColorTableParameterfvSGI

typedef void (APIENTRY* pfn_glGetColorTableParameterivSGI) (GLenum, GLenum, GLint*);
WM3_EXTERN pfn_glGetColorTableParameterivSGI Wm3glGetColorTableParameterivSGI;
#define glGetColorTableParameterivSGI Wm3glGetColorTableParameterivSGI
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_SGIX_pixel_texture;
WM3_EXTERN int Wm3NumFunctions_GL_SGIX_pixel_texture;
#ifndef GL_SGIX_pixel_texture
#define GL_SGIX_pixel_texture
#define WM3_DEFINED_GL_SGIX_pixel_texture
#define GL_PIXEL_TEX_GEN_SGIX             0x8139
#define GL_PIXEL_TEX_GEN_MODE_SGIX        0x832B

typedef void (APIENTRY* pfn_glPixelTexGenSGIX) (GLenum);
WM3_EXTERN pfn_glPixelTexGenSGIX Wm3glPixelTexGenSGIX;
#define glPixelTexGenSGIX Wm3glPixelTexGenSGIX
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_SGIS_pixel_texture;
WM3_EXTERN int Wm3NumFunctions_GL_SGIS_pixel_texture;
#ifndef GL_SGIS_pixel_texture
#define GL_SGIS_pixel_texture
#define WM3_DEFINED_GL_SGIS_pixel_texture
#define GL_PIXEL_TEXTURE_SGIS               0x8353
#define GL_PIXEL_FRAGMENT_RGB_SOURCE_SGIS   0x8354
#define GL_PIXEL_FRAGMENT_ALPHA_SOURCE_SGIS 0x8355
#define GL_PIXEL_GROUP_COLOR_SGIS           0x8356

typedef void (APIENTRY* pfn_glPixelTexGenParameteriSGIS) (GLenum, GLint);
WM3_EXTERN pfn_glPixelTexGenParameteriSGIS Wm3glPixelTexGenParameteriSGIS;
#define glPixelTexGenParameteriSGIS Wm3glPixelTexGenParameteriSGIS

typedef void (APIENTRY* pfn_glPixelTexGenParameterivSGIS) (GLenum, const GLint*);
WM3_EXTERN pfn_glPixelTexGenParameterivSGIS Wm3glPixelTexGenParameterivSGIS;
#define glPixelTexGenParameterivSGIS Wm3glPixelTexGenParameterivSGIS

typedef void (APIENTRY* pfn_glPixelTexGenParameterfSGIS) (GLenum, GLfloat);
WM3_EXTERN pfn_glPixelTexGenParameterfSGIS Wm3glPixelTexGenParameterfSGIS;
#define glPixelTexGenParameterfSGIS Wm3glPixelTexGenParameterfSGIS

typedef void (APIENTRY* pfn_glPixelTexGenParameterfvSGIS) (GLenum, const GLfloat*);
WM3_EXTERN pfn_glPixelTexGenParameterfvSGIS Wm3glPixelTexGenParameterfvSGIS;
#define glPixelTexGenParameterfvSGIS Wm3glPixelTexGenParameterfvSGIS

typedef void (APIENTRY* pfn_glGetPixelTexGenParameterivSGIS) (GLenum, GLint*);
WM3_EXTERN pfn_glGetPixelTexGenParameterivSGIS Wm3glGetPixelTexGenParameterivSGIS;
#define glGetPixelTexGenParameterivSGIS Wm3glGetPixelTexGenParameterivSGIS

typedef void (APIENTRY* pfn_glGetPixelTexGenParameterfvSGIS) (GLenum, GLfloat*);
WM3_EXTERN pfn_glGetPixelTexGenParameterfvSGIS Wm3glGetPixelTexGenParameterfvSGIS;
#define glGetPixelTexGenParameterfvSGIS Wm3glGetPixelTexGenParameterfvSGIS
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_SGIS_texture4D;
WM3_EXTERN int Wm3NumFunctions_GL_SGIS_texture4D;
#ifndef GL_SGIS_texture4D
#define GL_SGIS_texture4D
#define WM3_DEFINED_GL_SGIS_texture4D
#define GL_PACK_SKIP_VOLUMES_SGIS         0x8130
#define GL_PACK_IMAGE_DEPTH_SGIS          0x8131
#define GL_UNPACK_SKIP_VOLUMES_SGIS       0x8132
#define GL_UNPACK_IMAGE_DEPTH_SGIS        0x8133
#define GL_TEXTURE_4D_SGIS                0x8134
#define GL_PROXY_TEXTURE_4D_SGIS          0x8135
#define GL_TEXTURE_4DSIZE_SGIS            0x8136
#define GL_TEXTURE_WRAP_Q_SGIS            0x8137
#define GL_MAX_4D_TEXTURE_SIZE_SGIS       0x8138
#define GL_TEXTURE_4D_BINDING_SGIS        0x814F

typedef void (APIENTRY* pfn_glTexImage4DSGIS) (GLenum, GLint, GLenum, GLsizei, GLsizei, GLsizei, GLsizei, GLint, GLenum, GLenum, const GLvoid*);
WM3_EXTERN pfn_glTexImage4DSGIS Wm3glTexImage4DSGIS;
#define glTexImage4DSGIS Wm3glTexImage4DSGIS

typedef void (APIENTRY* pfn_glTexSubImage4DSGIS) (GLenum, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLsizei, GLenum, GLenum, const GLvoid*);
WM3_EXTERN pfn_glTexSubImage4DSGIS Wm3glTexSubImage4DSGIS;
#define glTexSubImage4DSGIS Wm3glTexSubImage4DSGIS
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_SGI_texture_color_table;
WM3_EXTERN int Wm3NumFunctions_GL_SGI_texture_color_table;
#ifndef GL_SGI_texture_color_table
#define GL_SGI_texture_color_table
#define WM3_DEFINED_GL_SGI_texture_color_table
#define GL_TEXTURE_COLOR_TABLE_SGI        0x80BC
#define GL_PROXY_TEXTURE_COLOR_TABLE_SGI  0x80BD
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_EXT_cmyka;
WM3_EXTERN int Wm3NumFunctions_GL_EXT_cmyka;
#ifndef GL_EXT_cmyka
#define GL_EXT_cmyka
#define WM3_DEFINED_GL_EXT_cmyka
#define GL_CMYK_EXT                       0x800C
#define GL_CMYKA_EXT                      0x800D
#define GL_PACK_CMYK_HINT_EXT             0x800E
#define GL_UNPACK_CMYK_HINT_EXT           0x800F
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_EXT_texture_object;
WM3_EXTERN int Wm3NumFunctions_GL_EXT_texture_object;
#ifndef GL_EXT_texture_object
#define GL_EXT_texture_object
#define WM3_DEFINED_GL_EXT_texture_object
#define GL_TEXTURE_PRIORITY_EXT           0x8066
#define GL_TEXTURE_RESIDENT_EXT           0x8067
#define GL_TEXTURE_1D_BINDING_EXT         0x8068
#define GL_TEXTURE_2D_BINDING_EXT         0x8069
#define GL_TEXTURE_3D_BINDING_EXT         0x806A

typedef GLboolean (APIENTRY* pfn_glAreTexturesResidentEXT) (GLsizei, const GLuint*, GLboolean*);
WM3_EXTERN pfn_glAreTexturesResidentEXT Wm3glAreTexturesResidentEXT;
#define glAreTexturesResidentEXT Wm3glAreTexturesResidentEXT

typedef void (APIENTRY* pfn_glBindTextureEXT) (GLenum, GLuint);
WM3_EXTERN pfn_glBindTextureEXT Wm3glBindTextureEXT;
#define glBindTextureEXT Wm3glBindTextureEXT

typedef void (APIENTRY* pfn_glDeleteTexturesEXT) (GLsizei, const GLuint*);
WM3_EXTERN pfn_glDeleteTexturesEXT Wm3glDeleteTexturesEXT;
#define glDeleteTexturesEXT Wm3glDeleteTexturesEXT

typedef void (APIENTRY* pfn_glGenTexturesEXT) (GLsizei, GLuint*);
WM3_EXTERN pfn_glGenTexturesEXT Wm3glGenTexturesEXT;
#define glGenTexturesEXT Wm3glGenTexturesEXT

typedef GLboolean (APIENTRY* pfn_glIsTextureEXT) (GLuint);
WM3_EXTERN pfn_glIsTextureEXT Wm3glIsTextureEXT;
#define glIsTextureEXT Wm3glIsTextureEXT

typedef void (APIENTRY* pfn_glPrioritizeTexturesEXT) (GLsizei, const GLuint*, const GLclampf*);
WM3_EXTERN pfn_glPrioritizeTexturesEXT Wm3glPrioritizeTexturesEXT;
#define glPrioritizeTexturesEXT Wm3glPrioritizeTexturesEXT
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_SGIS_detail_texture;
WM3_EXTERN int Wm3NumFunctions_GL_SGIS_detail_texture;
#ifndef GL_SGIS_detail_texture
#define GL_SGIS_detail_texture
#define WM3_DEFINED_GL_SGIS_detail_texture
#define GL_DETAIL_TEXTURE_2D_SGIS           0x8095
#define GL_DETAIL_TEXTURE_2D_BINDING_SGIS   0x8096
#define GL_LINEAR_DETAIL_SGIS               0x8097
#define GL_LINEAR_DETAIL_ALPHA_SGIS         0x8098
#define GL_LINEAR_DETAIL_COLOR_SGIS         0x8099
#define GL_DETAIL_TEXTURE_LEVEL_SGIS        0x809A
#define GL_DETAIL_TEXTURE_MODE_SGIS         0x809B
#define GL_DETAIL_TEXTURE_FUNC_POINTS_SGIS  0x809C

typedef void (APIENTRY* pfn_glDetailTexFuncSGIS) (GLenum, GLsizei, const GLfloat*);
WM3_EXTERN pfn_glDetailTexFuncSGIS Wm3glDetailTexFuncSGIS;
#define glDetailTexFuncSGIS Wm3glDetailTexFuncSGIS

typedef void (APIENTRY* pfn_glGetDetailTexFuncSGIS) (GLenum, GLfloat*);
WM3_EXTERN pfn_glGetDetailTexFuncSGIS Wm3glGetDetailTexFuncSGIS;
#define glGetDetailTexFuncSGIS Wm3glGetDetailTexFuncSGIS
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_SGIS_sharpen_texture;
WM3_EXTERN int Wm3NumFunctions_GL_SGIS_sharpen_texture;
#ifndef GL_SGIS_sharpen_texture
#define GL_SGIS_sharpen_texture
#define WM3_DEFINED_GL_SGIS_sharpen_texture
#define GL_LINEAR_SHARPEN_SGIS              0x80AD
#define GL_LINEAR_SHARPEN_ALPHA_SGIS        0x80AE
#define GL_LINEAR_SHARPEN_COLOR_SGIS        0x80AF
#define GL_SHARPEN_TEXTURE_FUNC_POINTS_SGIS 0x80B0

typedef void (APIENTRY* pfn_glSharpenTexFuncSGIS) (GLenum, GLsizei, const GLfloat*);
WM3_EXTERN pfn_glSharpenTexFuncSGIS Wm3glSharpenTexFuncSGIS;
#define glSharpenTexFuncSGIS Wm3glSharpenTexFuncSGIS

typedef void (APIENTRY* pfn_glGetSharpenTexFuncSGIS) (GLenum, GLfloat*);
WM3_EXTERN pfn_glGetSharpenTexFuncSGIS Wm3glGetSharpenTexFuncSGIS;
#define glGetSharpenTexFuncSGIS Wm3glGetSharpenTexFuncSGIS
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_EXT_packed_pixels;
WM3_EXTERN int Wm3NumFunctions_GL_EXT_packed_pixels;
#ifndef GL_EXT_packed_pixels
#define GL_EXT_packed_pixels
#define WM3_DEFINED_GL_EXT_packed_pixels
#define GL_UNSIGNED_BYTE_3_3_2_EXT        0x8032
#define GL_UNSIGNED_SHORT_4_4_4_4_EXT     0x8033
#define GL_UNSIGNED_SHORT_5_5_5_1_EXT     0x8034
#define GL_UNSIGNED_INT_8_8_8_8_EXT       0x8035
#define GL_UNSIGNED_INT_10_10_10_2_EXT    0x8036
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_SGIS_texture_lod;
WM3_EXTERN int Wm3NumFunctions_GL_SGIS_texture_lod;
#ifndef GL_SGIS_texture_lod
#define GL_SGIS_texture_lod
#define WM3_DEFINED_GL_SGIS_texture_lod
#define GL_TEXTURE_MIN_LOD_SGIS           0x813A
#define GL_TEXTURE_MAX_LOD_SGIS           0x813B
#define GL_TEXTURE_BASE_LEVEL_SGIS        0x813C
#define GL_TEXTURE_MAX_LEVEL_SGIS         0x813D
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_SGIS_multisample;
WM3_EXTERN int Wm3NumFunctions_GL_SGIS_multisample;
#ifndef GL_SGIS_multisample
#define GL_SGIS_multisample
#define WM3_DEFINED_GL_SGIS_multisample
#define GL_MULTISAMPLE_SGIS               0x809D
#define GL_SAMPLE_ALPHA_TO_MASK_SGIS      0x809E
#define GL_SAMPLE_ALPHA_TO_ONE_SGIS       0x809F
#define GL_SAMPLE_MASK_SGIS               0x80A0
#define GL_1PASS_SGIS                     0x80A1
#define GL_2PASS_0_SGIS                   0x80A2
#define GL_2PASS_1_SGIS                   0x80A3
#define GL_4PASS_0_SGIS                   0x80A4
#define GL_4PASS_1_SGIS                   0x80A5
#define GL_4PASS_2_SGIS                   0x80A6
#define GL_4PASS_3_SGIS                   0x80A7
#define GL_SAMPLE_BUFFERS_SGIS            0x80A8
#define GL_SAMPLES_SGIS                   0x80A9
#define GL_SAMPLE_MASK_VALUE_SGIS         0x80AA
#define GL_SAMPLE_MASK_INVERT_SGIS        0x80AB
#define GL_SAMPLE_PATTERN_SGIS            0x80AC

typedef void (APIENTRY* pfn_glSampleMaskSGIS) (GLclampf, GLboolean);
WM3_EXTERN pfn_glSampleMaskSGIS Wm3glSampleMaskSGIS;
#define glSampleMaskSGIS Wm3glSampleMaskSGIS

typedef void (APIENTRY* pfn_glSamplePatternSGIS) (GLenum);
WM3_EXTERN pfn_glSamplePatternSGIS Wm3glSamplePatternSGIS;
#define glSamplePatternSGIS Wm3glSamplePatternSGIS
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_EXT_rescale_normal;
WM3_EXTERN int Wm3NumFunctions_GL_EXT_rescale_normal;
#ifndef GL_EXT_rescale_normal
#define GL_EXT_rescale_normal
#define WM3_DEFINED_GL_EXT_rescale_normal
#define GL_RESCALE_NORMAL_EXT             0x803A
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_EXT_vertex_array;
WM3_EXTERN int Wm3NumFunctions_GL_EXT_vertex_array;
#ifndef GL_EXT_vertex_array
#define GL_EXT_vertex_array
#define WM3_DEFINED_GL_EXT_vertex_array
#define GL_VERTEX_ARRAY_EXT                 0x8074
#define GL_NORMAL_ARRAY_EXT                 0x8075
#define GL_COLOR_ARRAY_EXT                  0x8076
#define GL_INDEX_ARRAY_EXT                  0x8077
#define GL_TEXTURE_COORD_ARRAY_EXT          0x8078
#define GL_EDGE_FLAG_ARRAY_EXT              0x8079
#define GL_VERTEX_ARRAY_SIZE_EXT            0x807A
#define GL_VERTEX_ARRAY_TYPE_EXT            0x807B
#define GL_VERTEX_ARRAY_STRIDE_EXT          0x807C
#define GL_VERTEX_ARRAY_COUNT_EXT           0x807D
#define GL_NORMAL_ARRAY_TYPE_EXT            0x807E
#define GL_NORMAL_ARRAY_STRIDE_EXT          0x807F
#define GL_NORMAL_ARRAY_COUNT_EXT           0x8080
#define GL_COLOR_ARRAY_SIZE_EXT             0x8081
#define GL_COLOR_ARRAY_TYPE_EXT             0x8082
#define GL_COLOR_ARRAY_STRIDE_EXT           0x8083
#define GL_COLOR_ARRAY_COUNT_EXT            0x8084
#define GL_INDEX_ARRAY_TYPE_EXT             0x8085
#define GL_INDEX_ARRAY_STRIDE_EXT           0x8086
#define GL_INDEX_ARRAY_COUNT_EXT            0x8087
#define GL_TEXTURE_COORD_ARRAY_SIZE_EXT     0x8088
#define GL_TEXTURE_COORD_ARRAY_TYPE_EXT     0x8089
#define GL_TEXTURE_COORD_ARRAY_STRIDE_EXT   0x808A
#define GL_TEXTURE_COORD_ARRAY_COUNT_EXT    0x808B
#define GL_EDGE_FLAG_ARRAY_STRIDE_EXT       0x808C
#define GL_EDGE_FLAG_ARRAY_COUNT_EXT        0x808D
#define GL_VERTEX_ARRAY_POINTER_EXT         0x808E
#define GL_NORMAL_ARRAY_POINTER_EXT         0x808F
#define GL_COLOR_ARRAY_POINTER_EXT          0x8090
#define GL_INDEX_ARRAY_POINTER_EXT          0x8091
#define GL_TEXTURE_COORD_ARRAY_POINTER_EXT  0x8092
#define GL_EDGE_FLAG_ARRAY_POINTER_EXT      0x8093

typedef void (APIENTRY* pfn_glArrayElementEXT) (GLint);
WM3_EXTERN pfn_glArrayElementEXT Wm3glArrayElementEXT;
#define glArrayElementEXT Wm3glArrayElementEXT

typedef void (APIENTRY* pfn_glColorPointerEXT) (GLint, GLenum, GLsizei, GLsizei, const GLvoid*);
WM3_EXTERN pfn_glColorPointerEXT Wm3glColorPointerEXT;
#define glColorPointerEXT Wm3glColorPointerEXT

typedef void (APIENTRY* pfn_glDrawArraysEXT) (GLenum, GLint, GLsizei);
WM3_EXTERN pfn_glDrawArraysEXT Wm3glDrawArraysEXT;
#define glDrawArraysEXT Wm3glDrawArraysEXT

typedef void (APIENTRY* pfn_glEdgeFlagPointerEXT) (GLsizei, GLsizei, const GLboolean*);
WM3_EXTERN pfn_glEdgeFlagPointerEXT Wm3glEdgeFlagPointerEXT;
#define glEdgeFlagPointerEXT Wm3glEdgeFlagPointerEXT

typedef void (APIENTRY* pfn_glGetPointervEXT) (GLenum, GLvoid**);
WM3_EXTERN pfn_glGetPointervEXT Wm3glGetPointervEXT;
#define glGetPointervEXT Wm3glGetPointervEXT

typedef void (APIENTRY* pfn_glIndexPointerEXT) (GLenum, GLsizei, GLsizei, const GLvoid*);
WM3_EXTERN pfn_glIndexPointerEXT Wm3glIndexPointerEXT;
#define glIndexPointerEXT Wm3glIndexPointerEXT

typedef void (APIENTRY* pfn_glNormalPointerEXT) (GLenum, GLsizei, GLsizei, const GLvoid*);
WM3_EXTERN pfn_glNormalPointerEXT Wm3glNormalPointerEXT;
#define glNormalPointerEXT Wm3glNormalPointerEXT

typedef void (APIENTRY* pfn_glTexCoordPointerEXT) (GLint, GLenum, GLsizei, GLsizei, const GLvoid*);
WM3_EXTERN pfn_glTexCoordPointerEXT Wm3glTexCoordPointerEXT;
#define glTexCoordPointerEXT Wm3glTexCoordPointerEXT

typedef void (APIENTRY* pfn_glVertexPointerEXT) (GLint, GLenum, GLsizei, GLsizei, const GLvoid*);
WM3_EXTERN pfn_glVertexPointerEXT Wm3glVertexPointerEXT;
#define glVertexPointerEXT Wm3glVertexPointerEXT
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_EXT_misc_attribute;
WM3_EXTERN int Wm3NumFunctions_GL_EXT_misc_attribute;
#ifndef GL_EXT_misc_attribute
#define GL_EXT_misc_attribute
#define WM3_DEFINED_GL_EXT_misc_attribute
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_SGIS_generate_mipmap;
WM3_EXTERN int Wm3NumFunctions_GL_SGIS_generate_mipmap;
#ifndef GL_SGIS_generate_mipmap
#define GL_SGIS_generate_mipmap
#define WM3_DEFINED_GL_SGIS_generate_mipmap
#define GL_GENERATE_MIPMAP_SGIS           0x8191
#define GL_GENERATE_MIPMAP_HINT_SGIS      0x8192
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_SGIX_clipmap;
WM3_EXTERN int Wm3NumFunctions_GL_SGIX_clipmap;
#ifndef GL_SGIX_clipmap
#define GL_SGIX_clipmap
#define WM3_DEFINED_GL_SGIX_clipmap
#define GL_LINEAR_CLIPMAP_LINEAR_SGIX     0x8170
#define GL_TEXTURE_CLIPMAP_CENTER_SGIX    0x8171
#define GL_TEXTURE_CLIPMAP_FRAME_SGIX     0x8172
#define GL_TEXTURE_CLIPMAP_OFFSET_SGIX    0x8173
#define GL_TEXTURE_CLIPMAP_VIRTUAL_DEPTH_SGIX 0x8174
#define GL_TEXTURE_CLIPMAP_LOD_OFFSET_SGIX 0x8175
#define GL_TEXTURE_CLIPMAP_DEPTH_SGIX     0x8176
#define GL_MAX_CLIPMAP_DEPTH_SGIX         0x8177
#define GL_MAX_CLIPMAP_VIRTUAL_DEPTH_SGIX 0x8178
#define GL_NEAREST_CLIPMAP_NEAREST_SGIX   0x844D
#define GL_NEAREST_CLIPMAP_LINEAR_SGIX    0x844E
#define GL_LINEAR_CLIPMAP_NEAREST_SGIX    0x844F
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_SGIX_shadow;
WM3_EXTERN int Wm3NumFunctions_GL_SGIX_shadow;
#ifndef GL_SGIX_shadow
#define GL_SGIX_shadow
#define WM3_DEFINED_GL_SGIX_shadow
#define GL_TEXTURE_COMPARE_SGIX           0x819A
#define GL_TEXTURE_COMPARE_OPERATOR_SGIX  0x819B
#define GL_TEXTURE_LEQUAL_R_SGIX          0x819C
#define GL_TEXTURE_GEQUAL_R_SGIX          0x819D
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_SGIS_texture_edge_clamp;
WM3_EXTERN int Wm3NumFunctions_GL_SGIS_texture_edge_clamp;
#ifndef GL_SGIS_texture_edge_clamp
#define GL_SGIS_texture_edge_clamp
#define WM3_DEFINED_GL_SGIS_texture_edge_clamp
#define GL_CLAMP_TO_EDGE_SGIS             0x812F
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_SGIS_texture_border_clamp;
WM3_EXTERN int Wm3NumFunctions_GL_SGIS_texture_border_clamp;
#ifndef GL_SGIS_texture_border_clamp
#define GL_SGIS_texture_border_clamp
#define WM3_DEFINED_GL_SGIS_texture_border_clamp
#define GL_CLAMP_TO_BORDER_SGIS           0x812D
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_EXT_blend_minmax;
WM3_EXTERN int Wm3NumFunctions_GL_EXT_blend_minmax;
#ifndef GL_EXT_blend_minmax
#define GL_EXT_blend_minmax
#define WM3_DEFINED_GL_EXT_blend_minmax
#define GL_FUNC_ADD_EXT                   0x8006
#define GL_MIN_EXT                        0x8007
#define GL_MAX_EXT                        0x8008
#define GL_BLEND_EQUATION_EXT             0x8009

typedef void (APIENTRY* pfn_glBlendEquationEXT) (GLenum);
WM3_EXTERN pfn_glBlendEquationEXT Wm3glBlendEquationEXT;
#define glBlendEquationEXT Wm3glBlendEquationEXT
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_EXT_blend_subtract;
WM3_EXTERN int Wm3NumFunctions_GL_EXT_blend_subtract;
#ifndef GL_EXT_blend_subtract
#define GL_EXT_blend_subtract
#define WM3_DEFINED_GL_EXT_blend_subtract
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_EXT_blend_logic_op;
WM3_EXTERN int Wm3NumFunctions_GL_EXT_blend_logic_op;
#ifndef GL_EXT_blend_logic_op
#define GL_EXT_blend_logic_op
#define WM3_DEFINED_GL_EXT_blend_logic_op
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_SGIX_interlace;
WM3_EXTERN int Wm3NumFunctions_GL_SGIX_interlace;
#ifndef GL_SGIX_interlace
#define GL_SGIX_interlace
#define WM3_DEFINED_GL_SGIX_interlace
#define GL_INTERLACE_SGIX                 0x8094
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_SGIX_pixel_tiles;
WM3_EXTERN int Wm3NumFunctions_GL_SGIX_pixel_tiles;
#ifndef GL_SGIX_pixel_tiles
#define GL_SGIX_pixel_tiles
#define WM3_DEFINED_GL_SGIX_pixel_tiles
#define GL_PIXEL_TILE_BEST_ALIGNMENT_SGIX   0x813E
#define GL_PIXEL_TILE_CACHE_INCREMENT_SGIX  0x813F
#define GL_PIXEL_TILE_WIDTH_SGIX            0x8140
#define GL_PIXEL_TILE_HEIGHT_SGIX           0x8141
#define GL_PIXEL_TILE_GRID_WIDTH_SGIX       0x8142
#define GL_PIXEL_TILE_GRID_HEIGHT_SGIX      0x8143
#define GL_PIXEL_TILE_GRID_DEPTH_SGIX       0x8144
#define GL_PIXEL_TILE_CACHE_SIZE_SGIX       0x8145
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_SGIX_texture_select;
WM3_EXTERN int Wm3NumFunctions_GL_SGIX_texture_select;
#ifndef GL_SGIX_texture_select
#define GL_SGIX_texture_select
#define WM3_DEFINED_GL_SGIX_texture_select
#define GL_DUAL_ALPHA4_SGIS               0x8110
#define GL_DUAL_ALPHA8_SGIS               0x8111
#define GL_DUAL_ALPHA12_SGIS              0x8112
#define GL_DUAL_ALPHA16_SGIS              0x8113
#define GL_DUAL_LUMINANCE4_SGIS           0x8114
#define GL_DUAL_LUMINANCE8_SGIS           0x8115
#define GL_DUAL_LUMINANCE12_SGIS          0x8116
#define GL_DUAL_LUMINANCE16_SGIS          0x8117
#define GL_DUAL_INTENSITY4_SGIS           0x8118
#define GL_DUAL_INTENSITY8_SGIS           0x8119
#define GL_DUAL_INTENSITY12_SGIS          0x811A
#define GL_DUAL_INTENSITY16_SGIS          0x811B
#define GL_DUAL_LUMINANCE_ALPHA4_SGIS     0x811C
#define GL_DUAL_LUMINANCE_ALPHA8_SGIS     0x811D
#define GL_QUAD_ALPHA4_SGIS               0x811E
#define GL_QUAD_ALPHA8_SGIS               0x811F
#define GL_QUAD_LUMINANCE4_SGIS           0x8120
#define GL_QUAD_LUMINANCE8_SGIS           0x8121
#define GL_QUAD_INTENSITY4_SGIS           0x8122
#define GL_QUAD_INTENSITY8_SGIS           0x8123
#define GL_DUAL_TEXTURE_SELECT_SGIS       0x8124
#define GL_QUAD_TEXTURE_SELECT_SGIS       0x8125
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_SGIX_sprite;
WM3_EXTERN int Wm3NumFunctions_GL_SGIX_sprite;
#ifndef GL_SGIX_sprite
#define GL_SGIX_sprite
#define WM3_DEFINED_GL_SGIX_sprite
#define GL_SPRITE_SGIX                    0x8148
#define GL_SPRITE_MODE_SGIX               0x8149
#define GL_SPRITE_AXIS_SGIX               0x814A
#define GL_SPRITE_TRANSLATION_SGIX        0x814B
#define GL_SPRITE_AXIAL_SGIX              0x814C
#define GL_SPRITE_OBJECT_ALIGNED_SGIX     0x814D
#define GL_SPRITE_EYE_ALIGNED_SGIX        0x814E

typedef void (APIENTRY* pfn_glSpriteParameterfSGIX) (GLenum, GLfloat);
WM3_EXTERN pfn_glSpriteParameterfSGIX Wm3glSpriteParameterfSGIX;
#define glSpriteParameterfSGIX Wm3glSpriteParameterfSGIX

typedef void (APIENTRY* pfn_glSpriteParameterfvSGIX) (GLenum, const GLfloat*);
WM3_EXTERN pfn_glSpriteParameterfvSGIX Wm3glSpriteParameterfvSGIX;
#define glSpriteParameterfvSGIX Wm3glSpriteParameterfvSGIX

typedef void (APIENTRY* pfn_glSpriteParameteriSGIX) (GLenum, GLint);
WM3_EXTERN pfn_glSpriteParameteriSGIX Wm3glSpriteParameteriSGIX;
#define glSpriteParameteriSGIX Wm3glSpriteParameteriSGIX

typedef void (APIENTRY* pfn_glSpriteParameterivSGIX) (GLenum, const GLint*);
WM3_EXTERN pfn_glSpriteParameterivSGIX Wm3glSpriteParameterivSGIX;
#define glSpriteParameterivSGIX Wm3glSpriteParameterivSGIX
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_SGIX_texture_multi_buffer;
WM3_EXTERN int Wm3NumFunctions_GL_SGIX_texture_multi_buffer;
#ifndef GL_SGIX_texture_multi_buffer
#define GL_SGIX_texture_multi_buffer
#define WM3_DEFINED_GL_SGIX_texture_multi_buffer
#define GL_TEXTURE_MULTI_BUFFER_HINT_SGIX 0x812E
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_EXT_point_parameters;
WM3_EXTERN int Wm3NumFunctions_GL_EXT_point_parameters;
#ifndef GL_EXT_point_parameters
#define GL_EXT_point_parameters
#define WM3_DEFINED_GL_EXT_point_parameters
#define GL_POINT_SIZE_MIN_EXT             0x8126
#define GL_POINT_SIZE_MAX_EXT             0x8127
#define GL_POINT_FADE_THRESHOLD_SIZE_EXT  0x8128
#define GL_DISTANCE_ATTENUATION_EXT       0x8129

typedef void (APIENTRY* pfn_glPointParameterfEXT) (GLenum, GLfloat);
WM3_EXTERN pfn_glPointParameterfEXT Wm3glPointParameterfEXT;
#define glPointParameterfEXT Wm3glPointParameterfEXT

typedef void (APIENTRY* pfn_glPointParameterfvEXT) (GLenum, const GLfloat*);
WM3_EXTERN pfn_glPointParameterfvEXT Wm3glPointParameterfvEXT;
#define glPointParameterfvEXT Wm3glPointParameterfvEXT
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_SGIS_point_parameters;
WM3_EXTERN int Wm3NumFunctions_GL_SGIS_point_parameters;
#ifndef GL_SGIS_point_parameters
#define GL_SGIS_point_parameters
#define WM3_DEFINED_GL_SGIS_point_parameters
#define GL_POINT_SIZE_MIN_SGIS            0x8126
#define GL_POINT_SIZE_MAX_SGIS            0x8127
#define GL_POINT_FADE_THRESHOLD_SIZE_SGIS 0x8128
#define GL_DISTANCE_ATTENUATION_SGIS      0x8129

typedef void (APIENTRY* pfn_glPointParameterfSGIS) (GLenum, GLfloat);
WM3_EXTERN pfn_glPointParameterfSGIS Wm3glPointParameterfSGIS;
#define glPointParameterfSGIS Wm3glPointParameterfSGIS

typedef void (APIENTRY* pfn_glPointParameterfvSGIS) (GLenum, const GLfloat*);
WM3_EXTERN pfn_glPointParameterfvSGIS Wm3glPointParameterfvSGIS;
#define glPointParameterfvSGIS Wm3glPointParameterfvSGIS
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_SGIX_instruments;
WM3_EXTERN int Wm3NumFunctions_GL_SGIX_instruments;
#ifndef GL_SGIX_instruments
#define GL_SGIX_instruments
#define WM3_DEFINED_GL_SGIX_instruments
#define GL_INSTRUMENT_BUFFER_POINTER_SGIX 0x8180
#define GL_INSTRUMENT_MEASUREMENTS_SGIX   0x8181

typedef GLint (APIENTRY* pfn_glGetInstrumentsSGIX) (void);
WM3_EXTERN pfn_glGetInstrumentsSGIX Wm3glGetInstrumentsSGIX;
#define glGetInstrumentsSGIX Wm3glGetInstrumentsSGIX

typedef void (APIENTRY* pfn_glInstrumentsBufferSGIX) (GLsizei, GLint*);
WM3_EXTERN pfn_glInstrumentsBufferSGIX Wm3glInstrumentsBufferSGIX;
#define glInstrumentsBufferSGIX Wm3glInstrumentsBufferSGIX

typedef GLint (APIENTRY* pfn_glPollInstrumentsSGIX) (GLint*);
WM3_EXTERN pfn_glPollInstrumentsSGIX Wm3glPollInstrumentsSGIX;
#define glPollInstrumentsSGIX Wm3glPollInstrumentsSGIX

typedef void (APIENTRY* pfn_glReadInstrumentsSGIX) (GLint);
WM3_EXTERN pfn_glReadInstrumentsSGIX Wm3glReadInstrumentsSGIX;
#define glReadInstrumentsSGIX Wm3glReadInstrumentsSGIX

typedef void (APIENTRY* pfn_glStartInstrumentsSGIX) (void);
WM3_EXTERN pfn_glStartInstrumentsSGIX Wm3glStartInstrumentsSGIX;
#define glStartInstrumentsSGIX Wm3glStartInstrumentsSGIX

typedef void (APIENTRY* pfn_glStopInstrumentsSGIX) (GLint);
WM3_EXTERN pfn_glStopInstrumentsSGIX Wm3glStopInstrumentsSGIX;
#define glStopInstrumentsSGIX Wm3glStopInstrumentsSGIX
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_SGIX_texture_scale_bias;
WM3_EXTERN int Wm3NumFunctions_GL_SGIX_texture_scale_bias;
#ifndef GL_SGIX_texture_scale_bias
#define GL_SGIX_texture_scale_bias
#define WM3_DEFINED_GL_SGIX_texture_scale_bias
#define GL_POST_TEXTURE_FILTER_BIAS_SGIX  0x8179
#define GL_POST_TEXTURE_FILTER_SCALE_SGIX 0x817A
#define GL_POST_TEXTURE_FILTER_BIAS_RANGE_SGIX 0x817B
#define GL_POST_TEXTURE_FILTER_SCALE_RANGE_SGIX 0x817C
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_SGIX_framezoom;
WM3_EXTERN int Wm3NumFunctions_GL_SGIX_framezoom;
#ifndef GL_SGIX_framezoom
#define GL_SGIX_framezoom
#define WM3_DEFINED_GL_SGIX_framezoom
#define GL_FRAMEZOOM_SGIX                 0x818B
#define GL_FRAMEZOOM_FACTOR_SGIX          0x818C
#define GL_MAX_FRAMEZOOM_FACTOR_SGIX      0x818D

typedef void (APIENTRY* pfn_glFrameZoomSGIX) (GLint);
WM3_EXTERN pfn_glFrameZoomSGIX Wm3glFrameZoomSGIX;
#define glFrameZoomSGIX Wm3glFrameZoomSGIX
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_SGIX_tag_sample_buffer;
WM3_EXTERN int Wm3NumFunctions_GL_SGIX_tag_sample_buffer;
#ifndef GL_SGIX_tag_sample_buffer
#define GL_SGIX_tag_sample_buffer
#define WM3_DEFINED_GL_SGIX_tag_sample_buffer

typedef void (APIENTRY* pfn_glTagSampleBufferSGIX) (void);
WM3_EXTERN pfn_glTagSampleBufferSGIX Wm3glTagSampleBufferSGIX;
#define glTagSampleBufferSGIX Wm3glTagSampleBufferSGIX
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_FfdMaskSGIX;
WM3_EXTERN int Wm3NumFunctions_GL_FfdMaskSGIX;
#ifndef GL_FfdMaskSGIX
#define GL_FfdMaskSGIX
#define WM3_DEFINED_GL_FfdMaskSGIX
#define GL_TEXTURE_DEFORMATION_BIT_SGIX   0x00000001
#define GL_GEOMETRY_DEFORMATION_BIT_SGIX  0x00000002
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_SGIX_polynomial_ffd;
WM3_EXTERN int Wm3NumFunctions_GL_SGIX_polynomial_ffd;
#ifndef GL_SGIX_polynomial_ffd
#define GL_SGIX_polynomial_ffd
#define WM3_DEFINED_GL_SGIX_polynomial_ffd
#define GL_GEOMETRY_DEFORMATION_SGIX      0x8194
#define GL_TEXTURE_DEFORMATION_SGIX       0x8195
#define GL_DEFORMATIONS_MASK_SGIX         0x8196
#define GL_MAX_DEFORMATION_ORDER_SGIX     0x8197

typedef void (APIENTRY* pfn_glDeformationMap3dSGIX) (GLenum, GLdouble, GLdouble, GLint, GLint, GLdouble, GLdouble, GLint, GLint, GLdouble, GLdouble, GLint, GLint, const GLdouble*);
WM3_EXTERN pfn_glDeformationMap3dSGIX Wm3glDeformationMap3dSGIX;
#define glDeformationMap3dSGIX Wm3glDeformationMap3dSGIX

typedef void (APIENTRY* pfn_glDeformationMap3fSGIX) (GLenum, GLfloat, GLfloat, GLint, GLint, GLfloat, GLfloat, GLint, GLint, GLfloat, GLfloat, GLint, GLint, const GLfloat*);
WM3_EXTERN pfn_glDeformationMap3fSGIX Wm3glDeformationMap3fSGIX;
#define glDeformationMap3fSGIX Wm3glDeformationMap3fSGIX

typedef void (APIENTRY* pfn_glDeformSGIX) (GLbitfield);
WM3_EXTERN pfn_glDeformSGIX Wm3glDeformSGIX;
#define glDeformSGIX Wm3glDeformSGIX

typedef void (APIENTRY* pfn_glLoadIdentityDeformationMapSGIX) (GLbitfield);
WM3_EXTERN pfn_glLoadIdentityDeformationMapSGIX Wm3glLoadIdentityDeformationMapSGIX;
#define glLoadIdentityDeformationMapSGIX Wm3glLoadIdentityDeformationMapSGIX
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_SGIX_reference_plane;
WM3_EXTERN int Wm3NumFunctions_GL_SGIX_reference_plane;
#ifndef GL_SGIX_reference_plane
#define GL_SGIX_reference_plane
#define WM3_DEFINED_GL_SGIX_reference_plane
#define GL_REFERENCE_PLANE_SGIX           0x817D
#define GL_REFERENCE_PLANE_EQUATION_SGIX  0x817E

typedef void (APIENTRY* pfn_glReferencePlaneSGIX) (const GLdouble*);
WM3_EXTERN pfn_glReferencePlaneSGIX Wm3glReferencePlaneSGIX;
#define glReferencePlaneSGIX Wm3glReferencePlaneSGIX
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_SGIX_flush_raster;
WM3_EXTERN int Wm3NumFunctions_GL_SGIX_flush_raster;
#ifndef GL_SGIX_flush_raster
#define GL_SGIX_flush_raster
#define WM3_DEFINED_GL_SGIX_flush_raster

typedef void (APIENTRY* pfn_glFlushRasterSGIX) (void);
WM3_EXTERN pfn_glFlushRasterSGIX Wm3glFlushRasterSGIX;
#define glFlushRasterSGIX Wm3glFlushRasterSGIX
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_SGIX_depth_texture;
WM3_EXTERN int Wm3NumFunctions_GL_SGIX_depth_texture;
#ifndef GL_SGIX_depth_texture
#define GL_SGIX_depth_texture
#define WM3_DEFINED_GL_SGIX_depth_texture
#define GL_DEPTH_COMPONENT16_SGIX         0x81A5
#define GL_DEPTH_COMPONENT24_SGIX         0x81A6
#define GL_DEPTH_COMPONENT32_SGIX         0x81A7
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_SGIS_fog_function;
WM3_EXTERN int Wm3NumFunctions_GL_SGIS_fog_function;
#ifndef GL_SGIS_fog_function
#define GL_SGIS_fog_function
#define WM3_DEFINED_GL_SGIS_fog_function
#define GL_FOG_FUNC_SGIS                  0x812A
#define GL_FOG_FUNC_POINTS_SGIS           0x812B
#define GL_MAX_FOG_FUNC_POINTS_SGIS       0x812C

typedef void (APIENTRY* pfn_glFogFuncSGIS) (GLsizei, const GLfloat*);
WM3_EXTERN pfn_glFogFuncSGIS Wm3glFogFuncSGIS;
#define glFogFuncSGIS Wm3glFogFuncSGIS

typedef void (APIENTRY* pfn_glGetFogFuncSGIS) (GLfloat*);
WM3_EXTERN pfn_glGetFogFuncSGIS Wm3glGetFogFuncSGIS;
#define glGetFogFuncSGIS Wm3glGetFogFuncSGIS
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_SGIX_fog_offset;
WM3_EXTERN int Wm3NumFunctions_GL_SGIX_fog_offset;
#ifndef GL_SGIX_fog_offset
#define GL_SGIX_fog_offset
#define WM3_DEFINED_GL_SGIX_fog_offset
#define GL_FOG_OFFSET_SGIX                0x8198
#define GL_FOG_OFFSET_VALUE_SGIX          0x8199
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_HP_image_transform;
WM3_EXTERN int Wm3NumFunctions_GL_HP_image_transform;
#ifndef GL_HP_image_transform
#define GL_HP_image_transform
#define WM3_DEFINED_GL_HP_image_transform
#define GL_IMAGE_SCALE_X_HP               0x8155
#define GL_IMAGE_SCALE_Y_HP               0x8156
#define GL_IMAGE_TRANSLATE_X_HP           0x8157
#define GL_IMAGE_TRANSLATE_Y_HP           0x8158
#define GL_IMAGE_ROTATE_ANGLE_HP          0x8159
#define GL_IMAGE_ROTATE_ORIGIN_X_HP       0x815A
#define GL_IMAGE_ROTATE_ORIGIN_Y_HP       0x815B
#define GL_IMAGE_MAG_FILTER_HP            0x815C
#define GL_IMAGE_MIN_FILTER_HP            0x815D
#define GL_IMAGE_CUBIC_WEIGHT_HP          0x815E
#define GL_CUBIC_HP                       0x815F
#define GL_AVERAGE_HP                     0x8160
#define GL_IMAGE_TRANSFORM_2D_HP          0x8161
#define GL_POST_IMAGE_TRANSFORM_COLOR_TABLE_HP 0x8162
#define GL_PROXY_POST_IMAGE_TRANSFORM_COLOR_TABLE_HP 0x8163

typedef void (APIENTRY* pfn_glImageTransformParameteriHP) (GLenum, GLenum, GLint);
WM3_EXTERN pfn_glImageTransformParameteriHP Wm3glImageTransformParameteriHP;
#define glImageTransformParameteriHP Wm3glImageTransformParameteriHP

typedef void (APIENTRY* pfn_glImageTransformParameterfHP) (GLenum, GLenum, GLfloat);
WM3_EXTERN pfn_glImageTransformParameterfHP Wm3glImageTransformParameterfHP;
#define glImageTransformParameterfHP Wm3glImageTransformParameterfHP

typedef void (APIENTRY* pfn_glImageTransformParameterivHP) (GLenum, GLenum, const GLint*);
WM3_EXTERN pfn_glImageTransformParameterivHP Wm3glImageTransformParameterivHP;
#define glImageTransformParameterivHP Wm3glImageTransformParameterivHP

typedef void (APIENTRY* pfn_glImageTransformParameterfvHP) (GLenum, GLenum, const GLfloat*);
WM3_EXTERN pfn_glImageTransformParameterfvHP Wm3glImageTransformParameterfvHP;
#define glImageTransformParameterfvHP Wm3glImageTransformParameterfvHP

typedef void (APIENTRY* pfn_glGetImageTransformParameterivHP) (GLenum, GLenum, GLint*);
WM3_EXTERN pfn_glGetImageTransformParameterivHP Wm3glGetImageTransformParameterivHP;
#define glGetImageTransformParameterivHP Wm3glGetImageTransformParameterivHP

typedef void (APIENTRY* pfn_glGetImageTransformParameterfvHP) (GLenum, GLenum, GLfloat*);
WM3_EXTERN pfn_glGetImageTransformParameterfvHP Wm3glGetImageTransformParameterfvHP;
#define glGetImageTransformParameterfvHP Wm3glGetImageTransformParameterfvHP
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_HP_convolution_border_modes;
WM3_EXTERN int Wm3NumFunctions_GL_HP_convolution_border_modes;
#ifndef GL_HP_convolution_border_modes
#define GL_HP_convolution_border_modes
#define WM3_DEFINED_GL_HP_convolution_border_modes
#define GL_IGNORE_BORDER_HP               0x8150
#define GL_CONSTANT_BORDER_HP             0x8151
#define GL_REPLICATE_BORDER_HP            0x8153
#define GL_CONVOLUTION_BORDER_COLOR_HP    0x8154
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_INGR_palette_buffer;
WM3_EXTERN int Wm3NumFunctions_GL_INGR_palette_buffer;
#ifndef GL_INGR_palette_buffer
#define GL_INGR_palette_buffer
#define WM3_DEFINED_GL_INGR_palette_buffer
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_SGIX_texture_add_env;
WM3_EXTERN int Wm3NumFunctions_GL_SGIX_texture_add_env;
#ifndef GL_SGIX_texture_add_env
#define GL_SGIX_texture_add_env
#define WM3_DEFINED_GL_SGIX_texture_add_env
#define GL_TEXTURE_ENV_BIAS_SGIX          0x80BE
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_EXT_color_subtable;
WM3_EXTERN int Wm3NumFunctions_GL_EXT_color_subtable;
#ifndef GL_EXT_color_subtable
#define GL_EXT_color_subtable
#define WM3_DEFINED_GL_EXT_color_subtable

typedef void (APIENTRY* pfn_glColorSubTableEXT) (GLenum, GLsizei, GLsizei, GLenum, GLenum, const GLvoid*);
WM3_EXTERN pfn_glColorSubTableEXT Wm3glColorSubTableEXT;
#define glColorSubTableEXT Wm3glColorSubTableEXT

typedef void (APIENTRY* pfn_glCopyColorSubTableEXT) (GLenum, GLsizei, GLint, GLint, GLsizei);
WM3_EXTERN pfn_glCopyColorSubTableEXT Wm3glCopyColorSubTableEXT;
#define glCopyColorSubTableEXT Wm3glCopyColorSubTableEXT
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_PGI_vertex_hints;
WM3_EXTERN int Wm3NumFunctions_GL_PGI_vertex_hints;
#ifndef GL_PGI_vertex_hints
#define GL_PGI_vertex_hints
#define WM3_DEFINED_GL_PGI_vertex_hints
#define GL_VERTEX_DATA_HINT_PGI             0x1A22A
#define GL_VERTEX_CONSISTENT_HINT_PGI       0x1A22B
#define GL_MATERIAL_SIDE_HINT_PGI           0x1A22C
#define GL_MAX_VERTEX_HINT_PGI              0x1A22D
#define GL_COLOR3_BIT_PGI                   0x00010000
#define GL_COLOR4_BIT_PGI                   0x00020000
#define GL_EDGEFLAG_BIT_PGI                 0x00040000
#define GL_INDEX_BIT_PGI                    0x00080000
#define GL_MAT_AMBIENT_BIT_PGI              0x00100000
#define GL_MAT_AMBIENT_AND_DIFFUSE_BIT_PGI  0x00200000
#define GL_MAT_DIFFUSE_BIT_PGI              0x00400000
#define GL_MAT_EMISSION_BIT_PGI             0x00800000
#define GL_MAT_COLOR_INDEXES_BIT_PGI        0x01000000
#define GL_MAT_SHININESS_BIT_PGI            0x02000000
#define GL_MAT_SPECULAR_BIT_PGI             0x04000000
#define GL_NORMAL_BIT_PGI                   0x08000000
#define GL_TEXCOORD1_BIT_PGI                0x10000000
#define GL_TEXCOORD2_BIT_PGI                0x20000000
#define GL_TEXCOORD3_BIT_PGI                0x40000000
#define GL_TEXCOORD4_BIT_PGI                0x80000000
#define GL_VERTEX23_BIT_PGI                 0x00000004
#define GL_VERTEX4_BIT_PGI                  0x00000008
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_PGI_misc_hints;
WM3_EXTERN int Wm3NumFunctions_GL_PGI_misc_hints;
#ifndef GL_PGI_misc_hints
#define GL_PGI_misc_hints
#define WM3_DEFINED_GL_PGI_misc_hints
#define GL_PREFER_DOUBLEBUFFER_HINT_PGI   0x1A1F8
#define GL_CONSERVE_MEMORY_HINT_PGI       0x1A1FD
#define GL_RECLAIM_MEMORY_HINT_PGI        0x1A1FE
#define GL_NATIVE_GRAPHICS_HANDLE_PGI     0x1A202
#define GL_NATIVE_GRAPHICS_BEGIN_HINT_PGI 0x1A203
#define GL_NATIVE_GRAPHICS_END_HINT_PGI   0x1A204
#define GL_ALWAYS_FAST_HINT_PGI           0x1A20C
#define GL_ALWAYS_SOFT_HINT_PGI           0x1A20D
#define GL_ALLOW_DRAW_OBJ_HINT_PGI        0x1A20E
#define GL_ALLOW_DRAW_WIN_HINT_PGI        0x1A20F
#define GL_ALLOW_DRAW_FRG_HINT_PGI        0x1A210
#define GL_ALLOW_DRAW_MEM_HINT_PGI        0x1A211
#define GL_STRICT_DEPTHFUNC_HINT_PGI      0x1A216
#define GL_STRICT_LIGHTING_HINT_PGI       0x1A217
#define GL_STRICT_SCISSOR_HINT_PGI        0x1A218
#define GL_FULL_STIPPLE_HINT_PGI          0x1A219
#define GL_CLIP_NEAR_HINT_PGI             0x1A220
#define GL_CLIP_FAR_HINT_PGI              0x1A221
#define GL_WIDE_LINE_HINT_PGI             0x1A222
#define GL_BACK_NORMALS_HINT_PGI          0x1A223

typedef void (APIENTRY* pfn_glHintPGI) (GLenum, GLint);
WM3_EXTERN pfn_glHintPGI Wm3glHintPGI;
#define glHintPGI Wm3glHintPGI
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_EXT_paletted_texture;
WM3_EXTERN int Wm3NumFunctions_GL_EXT_paletted_texture;
#ifndef GL_EXT_paletted_texture
#define GL_EXT_paletted_texture
#define WM3_DEFINED_GL_EXT_paletted_texture
#define GL_COLOR_INDEX1_EXT               0x80E2
#define GL_COLOR_INDEX2_EXT               0x80E3
#define GL_COLOR_INDEX4_EXT               0x80E4
#define GL_COLOR_INDEX8_EXT               0x80E5
#define GL_COLOR_INDEX12_EXT              0x80E6
#define GL_COLOR_INDEX16_EXT              0x80E7
#define GL_TEXTURE_INDEX_SIZE_EXT         0x80ED

typedef void (APIENTRY* pfn_glColorTableEXT) (GLenum, GLenum, GLsizei, GLenum, GLenum, const GLvoid*);
WM3_EXTERN pfn_glColorTableEXT Wm3glColorTableEXT;
#define glColorTableEXT Wm3glColorTableEXT

typedef void (APIENTRY* pfn_glGetColorTableEXT) (GLenum, GLenum, GLenum, GLvoid*);
WM3_EXTERN pfn_glGetColorTableEXT Wm3glGetColorTableEXT;
#define glGetColorTableEXT Wm3glGetColorTableEXT

typedef void (APIENTRY* pfn_glGetColorTableParameterivEXT) (GLenum, GLenum, GLint*);
WM3_EXTERN pfn_glGetColorTableParameterivEXT Wm3glGetColorTableParameterivEXT;
#define glGetColorTableParameterivEXT Wm3glGetColorTableParameterivEXT

typedef void (APIENTRY* pfn_glGetColorTableParameterfvEXT) (GLenum, GLenum, GLfloat*);
WM3_EXTERN pfn_glGetColorTableParameterfvEXT Wm3glGetColorTableParameterfvEXT;
#define glGetColorTableParameterfvEXT Wm3glGetColorTableParameterfvEXT
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_EXT_clip_volume_hint;
WM3_EXTERN int Wm3NumFunctions_GL_EXT_clip_volume_hint;
#ifndef GL_EXT_clip_volume_hint
#define GL_EXT_clip_volume_hint
#define WM3_DEFINED_GL_EXT_clip_volume_hint
#define GL_CLIP_VOLUME_CLIPPING_HINT_EXT  0x80F0
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_SGIX_list_priority;
WM3_EXTERN int Wm3NumFunctions_GL_SGIX_list_priority;
#ifndef GL_SGIX_list_priority
#define GL_SGIX_list_priority
#define WM3_DEFINED_GL_SGIX_list_priority
#define GL_LIST_PRIORITY_SGIX             0x8182

typedef void (APIENTRY* pfn_glGetListParameterfvSGIX) (GLuint, GLenum, GLfloat*);
WM3_EXTERN pfn_glGetListParameterfvSGIX Wm3glGetListParameterfvSGIX;
#define glGetListParameterfvSGIX Wm3glGetListParameterfvSGIX

typedef void (APIENTRY* pfn_glGetListParameterivSGIX) (GLuint, GLenum, GLint*);
WM3_EXTERN pfn_glGetListParameterivSGIX Wm3glGetListParameterivSGIX;
#define glGetListParameterivSGIX Wm3glGetListParameterivSGIX

typedef void (APIENTRY* pfn_glListParameterfSGIX) (GLuint, GLenum, GLfloat);
WM3_EXTERN pfn_glListParameterfSGIX Wm3glListParameterfSGIX;
#define glListParameterfSGIX Wm3glListParameterfSGIX

typedef void (APIENTRY* pfn_glListParameterfvSGIX) (GLuint, GLenum, const GLfloat*);
WM3_EXTERN pfn_glListParameterfvSGIX Wm3glListParameterfvSGIX;
#define glListParameterfvSGIX Wm3glListParameterfvSGIX

typedef void (APIENTRY* pfn_glListParameteriSGIX) (GLuint, GLenum, GLint);
WM3_EXTERN pfn_glListParameteriSGIX Wm3glListParameteriSGIX;
#define glListParameteriSGIX Wm3glListParameteriSGIX

typedef void (APIENTRY* pfn_glListParameterivSGIX) (GLuint, GLenum, const GLint*);
WM3_EXTERN pfn_glListParameterivSGIX Wm3glListParameterivSGIX;
#define glListParameterivSGIX Wm3glListParameterivSGIX
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_SGIX_ir_instrument1;
WM3_EXTERN int Wm3NumFunctions_GL_SGIX_ir_instrument1;
#ifndef GL_SGIX_ir_instrument1
#define GL_SGIX_ir_instrument1
#define WM3_DEFINED_GL_SGIX_ir_instrument1
#define GL_IR_INSTRUMENT1_SGIX            0x817F
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_SGIX_calligraphic_fragment;
WM3_EXTERN int Wm3NumFunctions_GL_SGIX_calligraphic_fragment;
#ifndef GL_SGIX_calligraphic_fragment
#define GL_SGIX_calligraphic_fragment
#define WM3_DEFINED_GL_SGIX_calligraphic_fragment
#define GL_CALLIGRAPHIC_FRAGMENT_SGIX     0x8183
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_SGIX_texture_lod_bias;
WM3_EXTERN int Wm3NumFunctions_GL_SGIX_texture_lod_bias;
#ifndef GL_SGIX_texture_lod_bias
#define GL_SGIX_texture_lod_bias
#define WM3_DEFINED_GL_SGIX_texture_lod_bias
#define GL_TEXTURE_LOD_BIAS_S_SGIX        0x818E
#define GL_TEXTURE_LOD_BIAS_T_SGIX        0x818F
#define GL_TEXTURE_LOD_BIAS_R_SGIX        0x8190
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_SGIX_shadow_ambient;
WM3_EXTERN int Wm3NumFunctions_GL_SGIX_shadow_ambient;
#ifndef GL_SGIX_shadow_ambient
#define GL_SGIX_shadow_ambient
#define WM3_DEFINED_GL_SGIX_shadow_ambient
#define GL_SHADOW_AMBIENT_SGIX            0x80BF
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_EXT_index_texture;
WM3_EXTERN int Wm3NumFunctions_GL_EXT_index_texture;
#ifndef GL_EXT_index_texture
#define GL_EXT_index_texture
#define WM3_DEFINED_GL_EXT_index_texture
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_EXT_index_material;
WM3_EXTERN int Wm3NumFunctions_GL_EXT_index_material;
#ifndef GL_EXT_index_material
#define GL_EXT_index_material
#define WM3_DEFINED_GL_EXT_index_material
#define GL_INDEX_MATERIAL_EXT             0x81B8
#define GL_INDEX_MATERIAL_PARAMETER_EXT   0x81B9
#define GL_INDEX_MATERIAL_FACE_EXT        0x81BA

typedef void (APIENTRY* pfn_glIndexMaterialEXT) (GLenum, GLenum);
WM3_EXTERN pfn_glIndexMaterialEXT Wm3glIndexMaterialEXT;
#define glIndexMaterialEXT Wm3glIndexMaterialEXT
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_EXT_index_func;
WM3_EXTERN int Wm3NumFunctions_GL_EXT_index_func;
#ifndef GL_EXT_index_func
#define GL_EXT_index_func
#define WM3_DEFINED_GL_EXT_index_func
#define GL_INDEX_TEST_EXT                 0x81B5
#define GL_INDEX_TEST_FUNC_EXT            0x81B6
#define GL_INDEX_TEST_REF_EXT             0x81B7

typedef void (APIENTRY* pfn_glIndexFuncEXT) (GLenum, GLclampf);
WM3_EXTERN pfn_glIndexFuncEXT Wm3glIndexFuncEXT;
#define glIndexFuncEXT Wm3glIndexFuncEXT
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_EXT_index_array_formats;
WM3_EXTERN int Wm3NumFunctions_GL_EXT_index_array_formats;
#ifndef GL_EXT_index_array_formats
#define GL_EXT_index_array_formats
#define WM3_DEFINED_GL_EXT_index_array_formats
#define GL_IUI_V2F_EXT                    0x81AD
#define GL_IUI_V3F_EXT                    0x81AE
#define GL_IUI_N3F_V2F_EXT                0x81AF
#define GL_IUI_N3F_V3F_EXT                0x81B0
#define GL_T2F_IUI_V2F_EXT                0x81B1
#define GL_T2F_IUI_V3F_EXT                0x81B2
#define GL_T2F_IUI_N3F_V2F_EXT            0x81B3
#define GL_T2F_IUI_N3F_V3F_EXT            0x81B4
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_EXT_compiled_vertex_array;
WM3_EXTERN int Wm3NumFunctions_GL_EXT_compiled_vertex_array;
#ifndef GL_EXT_compiled_vertex_array
#define GL_EXT_compiled_vertex_array
#define WM3_DEFINED_GL_EXT_compiled_vertex_array
#define GL_ARRAY_ELEMENT_LOCK_FIRST_EXT   0x81A8
#define GL_ARRAY_ELEMENT_LOCK_COUNT_EXT   0x81A9

typedef void (APIENTRY* pfn_glLockArraysEXT) (GLint, GLsizei);
WM3_EXTERN pfn_glLockArraysEXT Wm3glLockArraysEXT;
#define glLockArraysEXT Wm3glLockArraysEXT

typedef void (APIENTRY* pfn_glUnlockArraysEXT) (void);
WM3_EXTERN pfn_glUnlockArraysEXT Wm3glUnlockArraysEXT;
#define glUnlockArraysEXT Wm3glUnlockArraysEXT
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_EXT_cull_vertex;
WM3_EXTERN int Wm3NumFunctions_GL_EXT_cull_vertex;
#ifndef GL_EXT_cull_vertex
#define GL_EXT_cull_vertex
#define WM3_DEFINED_GL_EXT_cull_vertex
#define GL_CULL_VERTEX_EXT                  0x81AA
#define GL_CULL_VERTEX_EYE_POSITION_EXT     0x81AB
#define GL_CULL_VERTEX_OBJECT_POSITION_EXT  0x81AC

typedef void (APIENTRY* pfn_glCullParameterdvEXT) (GLenum, GLdouble*);
WM3_EXTERN pfn_glCullParameterdvEXT Wm3glCullParameterdvEXT;
#define glCullParameterdvEXT Wm3glCullParameterdvEXT

typedef void (APIENTRY* pfn_glCullParameterfvEXT) (GLenum, GLfloat*);
WM3_EXTERN pfn_glCullParameterfvEXT Wm3glCullParameterfvEXT;
#define glCullParameterfvEXT Wm3glCullParameterfvEXT
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_SGIX_ycrcb;
WM3_EXTERN int Wm3NumFunctions_GL_SGIX_ycrcb;
#ifndef GL_SGIX_ycrcb
#define GL_SGIX_ycrcb
#define WM3_DEFINED_GL_SGIX_ycrcb
#define GL_YCRCB_422_SGIX                 0x81BB
#define GL_YCRCB_444_SGIX                 0x81BC
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_SGIX_fragment_lighting;
WM3_EXTERN int Wm3NumFunctions_GL_SGIX_fragment_lighting;
#ifndef GL_SGIX_fragment_lighting
#define GL_SGIX_fragment_lighting
#define WM3_DEFINED_GL_SGIX_fragment_lighting
#define GL_FRAGMENT_LIGHTING_SGIX                           0x8400
#define GL_FRAGMENT_COLOR_MATERIAL_SGIX                     0x8401
#define GL_FRAGMENT_COLOR_MATERIAL_FACE_SGIX                0x8402
#define GL_FRAGMENT_COLOR_MATERIAL_PARAMETER_SGIX           0x8403
#define GL_MAX_FRAGMENT_LIGHTS_SGIX                         0x8404
#define GL_MAX_ACTIVE_LIGHTS_SGIX                           0x8405
#define GL_CURRENT_RASTER_NORMAL_SGIX                       0x8406
#define GL_LIGHT_ENV_MODE_SGIX                              0x8407
#define GL_FRAGMENT_LIGHT_MODEL_LOCAL_VIEWER_SGIX           0x8408
#define GL_FRAGMENT_LIGHT_MODEL_TWO_SIDE_SGIX               0x8409
#define GL_FRAGMENT_LIGHT_MODEL_AMBIENT_SGIX                0x840A
#define GL_FRAGMENT_LIGHT_MODEL_NORMAL_INTERPOLATION_SGIX   0x840B
#define GL_FRAGMENT_LIGHT0_SGIX                             0x840C
#define GL_FRAGMENT_LIGHT1_SGIX                             0x840D
#define GL_FRAGMENT_LIGHT2_SGIX                             0x840E
#define GL_FRAGMENT_LIGHT3_SGIX                             0x840F
#define GL_FRAGMENT_LIGHT4_SGIX                             0x8410
#define GL_FRAGMENT_LIGHT5_SGIX                             0x8411
#define GL_FRAGMENT_LIGHT6_SGIX                             0x8412
#define GL_FRAGMENT_LIGHT7_SGIX                             0x8413

typedef void (APIENTRY* pfn_glFragmentColorMaterialSGIX) (GLenum, GLenum);
WM3_EXTERN pfn_glFragmentColorMaterialSGIX Wm3glFragmentColorMaterialSGIX;
#define glFragmentColorMaterialSGIX Wm3glFragmentColorMaterialSGIX

typedef void (APIENTRY* pfn_glFragmentLightfSGIX) (GLenum, GLenum, GLfloat);
WM3_EXTERN pfn_glFragmentLightfSGIX Wm3glFragmentLightfSGIX;
#define glFragmentLightfSGIX Wm3glFragmentLightfSGIX

typedef void (APIENTRY* pfn_glFragmentLightfvSGIX) (GLenum, GLenum, const GLfloat*);
WM3_EXTERN pfn_glFragmentLightfvSGIX Wm3glFragmentLightfvSGIX;
#define glFragmentLightfvSGIX Wm3glFragmentLightfvSGIX

typedef void (APIENTRY* pfn_glFragmentLightiSGIX) (GLenum, GLenum, GLint);
WM3_EXTERN pfn_glFragmentLightiSGIX Wm3glFragmentLightiSGIX;
#define glFragmentLightiSGIX Wm3glFragmentLightiSGIX

typedef void (APIENTRY* pfn_glFragmentLightivSGIX) (GLenum, GLenum, const GLint*);
WM3_EXTERN pfn_glFragmentLightivSGIX Wm3glFragmentLightivSGIX;
#define glFragmentLightivSGIX Wm3glFragmentLightivSGIX

typedef void (APIENTRY* pfn_glFragmentLightModelfSGIX) (GLenum, GLfloat);
WM3_EXTERN pfn_glFragmentLightModelfSGIX Wm3glFragmentLightModelfSGIX;
#define glFragmentLightModelfSGIX Wm3glFragmentLightModelfSGIX

typedef void (APIENTRY* pfn_glFragmentLightModelfvSGIX) (GLenum, const GLfloat*);
WM3_EXTERN pfn_glFragmentLightModelfvSGIX Wm3glFragmentLightModelfvSGIX;
#define glFragmentLightModelfvSGIX Wm3glFragmentLightModelfvSGIX

typedef void (APIENTRY* pfn_glFragmentLightModeliSGIX) (GLenum, GLint);
WM3_EXTERN pfn_glFragmentLightModeliSGIX Wm3glFragmentLightModeliSGIX;
#define glFragmentLightModeliSGIX Wm3glFragmentLightModeliSGIX

typedef void (APIENTRY* pfn_glFragmentLightModelivSGIX) (GLenum, const GLint*);
WM3_EXTERN pfn_glFragmentLightModelivSGIX Wm3glFragmentLightModelivSGIX;
#define glFragmentLightModelivSGIX Wm3glFragmentLightModelivSGIX

typedef void (APIENTRY* pfn_glFragmentMaterialfSGIX) (GLenum, GLenum, GLfloat);
WM3_EXTERN pfn_glFragmentMaterialfSGIX Wm3glFragmentMaterialfSGIX;
#define glFragmentMaterialfSGIX Wm3glFragmentMaterialfSGIX

typedef void (APIENTRY* pfn_glFragmentMaterialfvSGIX) (GLenum, GLenum, const GLfloat*);
WM3_EXTERN pfn_glFragmentMaterialfvSGIX Wm3glFragmentMaterialfvSGIX;
#define glFragmentMaterialfvSGIX Wm3glFragmentMaterialfvSGIX

typedef void (APIENTRY* pfn_glFragmentMaterialiSGIX) (GLenum, GLenum, GLint);
WM3_EXTERN pfn_glFragmentMaterialiSGIX Wm3glFragmentMaterialiSGIX;
#define glFragmentMaterialiSGIX Wm3glFragmentMaterialiSGIX

typedef void (APIENTRY* pfn_glFragmentMaterialivSGIX) (GLenum, GLenum, const GLint*);
WM3_EXTERN pfn_glFragmentMaterialivSGIX Wm3glFragmentMaterialivSGIX;
#define glFragmentMaterialivSGIX Wm3glFragmentMaterialivSGIX

typedef void (APIENTRY* pfn_glGetFragmentLightfvSGIX) (GLenum, GLenum, GLfloat*);
WM3_EXTERN pfn_glGetFragmentLightfvSGIX Wm3glGetFragmentLightfvSGIX;
#define glGetFragmentLightfvSGIX Wm3glGetFragmentLightfvSGIX

typedef void (APIENTRY* pfn_glGetFragmentLightivSGIX) (GLenum, GLenum, GLint*);
WM3_EXTERN pfn_glGetFragmentLightivSGIX Wm3glGetFragmentLightivSGIX;
#define glGetFragmentLightivSGIX Wm3glGetFragmentLightivSGIX

typedef void (APIENTRY* pfn_glGetFragmentMaterialfvSGIX) (GLenum, GLenum, GLfloat*);
WM3_EXTERN pfn_glGetFragmentMaterialfvSGIX Wm3glGetFragmentMaterialfvSGIX;
#define glGetFragmentMaterialfvSGIX Wm3glGetFragmentMaterialfvSGIX

typedef void (APIENTRY* pfn_glGetFragmentMaterialivSGIX) (GLenum, GLenum, GLint*);
WM3_EXTERN pfn_glGetFragmentMaterialivSGIX Wm3glGetFragmentMaterialivSGIX;
#define glGetFragmentMaterialivSGIX Wm3glGetFragmentMaterialivSGIX

typedef void (APIENTRY* pfn_glLightEnviSGIX) (GLenum, GLint);
WM3_EXTERN pfn_glLightEnviSGIX Wm3glLightEnviSGIX;
#define glLightEnviSGIX Wm3glLightEnviSGIX
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_IBM_rasterpos_clip;
WM3_EXTERN int Wm3NumFunctions_GL_IBM_rasterpos_clip;
#ifndef GL_IBM_rasterpos_clip
#define GL_IBM_rasterpos_clip
#define WM3_DEFINED_GL_IBM_rasterpos_clip
#define GL_RASTER_POSITION_UNCLIPPED_IBM  0x19262
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_HP_texture_lighting;
WM3_EXTERN int Wm3NumFunctions_GL_HP_texture_lighting;
#ifndef GL_HP_texture_lighting
#define GL_HP_texture_lighting
#define WM3_DEFINED_GL_HP_texture_lighting
#define GL_TEXTURE_LIGHTING_MODE_HP       0x8167
#define GL_TEXTURE_POST_SPECULAR_HP       0x8168
#define GL_TEXTURE_PRE_SPECULAR_HP        0x8169
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_EXT_draw_range_elements;
WM3_EXTERN int Wm3NumFunctions_GL_EXT_draw_range_elements;
#ifndef GL_EXT_draw_range_elements
#define GL_EXT_draw_range_elements
#define WM3_DEFINED_GL_EXT_draw_range_elements
#define GL_MAX_ELEMENTS_VERTICES_EXT      0x80E8
#define GL_MAX_ELEMENTS_INDICES_EXT       0x80E9

typedef void (APIENTRY* pfn_glDrawRangeElementsEXT) (GLenum, GLuint, GLuint, GLsizei, GLenum, const GLvoid*);
WM3_EXTERN pfn_glDrawRangeElementsEXT Wm3glDrawRangeElementsEXT;
#define glDrawRangeElementsEXT Wm3glDrawRangeElementsEXT
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_WIN_phong_shading;
WM3_EXTERN int Wm3NumFunctions_GL_WIN_phong_shading;
#ifndef GL_WIN_phong_shading
#define GL_WIN_phong_shading
#define WM3_DEFINED_GL_WIN_phong_shading
#define GL_PHONG_WIN                      0x80EA
#define GL_PHONG_HINT_WIN                 0x80EB
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_WIN_specular_fog;
WM3_EXTERN int Wm3NumFunctions_GL_WIN_specular_fog;
#ifndef GL_WIN_specular_fog
#define GL_WIN_specular_fog
#define WM3_DEFINED_GL_WIN_specular_fog
#define GL_FOG_SPECULAR_TEXTURE_WIN       0x80EC
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_EXT_light_texture;
WM3_EXTERN int Wm3NumFunctions_GL_EXT_light_texture;
#ifndef GL_EXT_light_texture
#define GL_EXT_light_texture
#define WM3_DEFINED_GL_EXT_light_texture
#define GL_FRAGMENT_MATERIAL_EXT          0x8349
#define GL_FRAGMENT_NORMAL_EXT            0x834A
#define GL_FRAGMENT_COLOR_EXT             0x834C
#define GL_ATTENUATION_EXT                0x834D
#define GL_SHADOW_ATTENUATION_EXT         0x834E
#define GL_TEXTURE_APPLICATION_MODE_EXT   0x834F
#define GL_TEXTURE_LIGHT_EXT              0x8350
#define GL_TEXTURE_MATERIAL_FACE_EXT      0x8351
#define GL_TEXTURE_MATERIAL_PARAMETER_EXT 0x8352
/* reuse GL_FRAGMENT_DEPTH_EXT */

typedef void (APIENTRY* pfn_glApplyTextureEXT) (GLenum);
WM3_EXTERN pfn_glApplyTextureEXT Wm3glApplyTextureEXT;
#define glApplyTextureEXT Wm3glApplyTextureEXT

typedef void (APIENTRY* pfn_glTextureLightEXT) (GLenum);
WM3_EXTERN pfn_glTextureLightEXT Wm3glTextureLightEXT;
#define glTextureLightEXT Wm3glTextureLightEXT

typedef void (APIENTRY* pfn_glTextureMaterialEXT) (GLenum, GLenum);
WM3_EXTERN pfn_glTextureMaterialEXT Wm3glTextureMaterialEXT;
#define glTextureMaterialEXT Wm3glTextureMaterialEXT
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_SGIX_blend_alpha_minmax;
WM3_EXTERN int Wm3NumFunctions_GL_SGIX_blend_alpha_minmax;
#ifndef GL_SGIX_blend_alpha_minmax
#define GL_SGIX_blend_alpha_minmax
#define WM3_DEFINED_GL_SGIX_blend_alpha_minmax
#define GL_ALPHA_MIN_SGIX                 0x8320
#define GL_ALPHA_MAX_SGIX                 0x8321
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_SGIX_impact_pixel_texture;
WM3_EXTERN int Wm3NumFunctions_GL_SGIX_impact_pixel_texture;
#ifndef GL_SGIX_impact_pixel_texture
#define GL_SGIX_impact_pixel_texture
#define WM3_DEFINED_GL_SGIX_impact_pixel_texture
#define GL_PIXEL_TEX_GEN_Q_CEILING_SGIX         0x8184
#define GL_PIXEL_TEX_GEN_Q_ROUND_SGIX           0x8185
#define GL_PIXEL_TEX_GEN_Q_FLOOR_SGIX           0x8186
#define GL_PIXEL_TEX_GEN_ALPHA_REPLACE_SGIX     0x8187
#define GL_PIXEL_TEX_GEN_ALPHA_NO_REPLACE_SGIX  0x8188
#define GL_PIXEL_TEX_GEN_ALPHA_LS_SGIX          0x8189
#define GL_PIXEL_TEX_GEN_ALPHA_MS_SGIX          0x818A
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_EXT_bgra;
WM3_EXTERN int Wm3NumFunctions_GL_EXT_bgra;
#ifndef GL_EXT_bgra
#define GL_EXT_bgra
#define WM3_DEFINED_GL_EXT_bgra
#define GL_BGR_EXT                        0x80E0
#define GL_BGRA_EXT                       0x80E1
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_SGIX_async;
WM3_EXTERN int Wm3NumFunctions_GL_SGIX_async;
#ifndef GL_SGIX_async
#define GL_SGIX_async
#define WM3_DEFINED_GL_SGIX_async
#define GL_ASYNC_MARKER_SGIX              0x8329

typedef void (APIENTRY* pfn_glAsyncMarkerSGIX) (GLuint);
WM3_EXTERN pfn_glAsyncMarkerSGIX Wm3glAsyncMarkerSGIX;
#define glAsyncMarkerSGIX Wm3glAsyncMarkerSGIX

typedef GLint (APIENTRY* pfn_glFinishAsyncSGIX) (GLuint*);
WM3_EXTERN pfn_glFinishAsyncSGIX Wm3glFinishAsyncSGIX;
#define glFinishAsyncSGIX Wm3glFinishAsyncSGIX

typedef GLint (APIENTRY* pfn_glPollAsyncSGIX) (GLuint*);
WM3_EXTERN pfn_glPollAsyncSGIX Wm3glPollAsyncSGIX;
#define glPollAsyncSGIX Wm3glPollAsyncSGIX

typedef GLuint (APIENTRY* pfn_glGenAsyncMarkersSGIX) (GLsizei);
WM3_EXTERN pfn_glGenAsyncMarkersSGIX Wm3glGenAsyncMarkersSGIX;
#define glGenAsyncMarkersSGIX Wm3glGenAsyncMarkersSGIX

typedef void (APIENTRY* pfn_glDeleteAsyncMarkersSGIX) (GLuint, GLsizei);
WM3_EXTERN pfn_glDeleteAsyncMarkersSGIX Wm3glDeleteAsyncMarkersSGIX;
#define glDeleteAsyncMarkersSGIX Wm3glDeleteAsyncMarkersSGIX

typedef GLboolean (APIENTRY* pfn_glIsAsyncMarkerSGIX) (GLuint);
WM3_EXTERN pfn_glIsAsyncMarkerSGIX Wm3glIsAsyncMarkerSGIX;
#define glIsAsyncMarkerSGIX Wm3glIsAsyncMarkerSGIX
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_SGIX_async_pixel;
WM3_EXTERN int Wm3NumFunctions_GL_SGIX_async_pixel;
#ifndef GL_SGIX_async_pixel
#define GL_SGIX_async_pixel
#define WM3_DEFINED_GL_SGIX_async_pixel
#define GL_ASYNC_TEX_IMAGE_SGIX           0x835C
#define GL_ASYNC_DRAW_PIXELS_SGIX         0x835D
#define GL_ASYNC_READ_PIXELS_SGIX         0x835E
#define GL_MAX_ASYNC_TEX_IMAGE_SGIX       0x835F
#define GL_MAX_ASYNC_DRAW_PIXELS_SGIX     0x8360
#define GL_MAX_ASYNC_READ_PIXELS_SGIX     0x8361
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_SGIX_async_histogram;
WM3_EXTERN int Wm3NumFunctions_GL_SGIX_async_histogram;
#ifndef GL_SGIX_async_histogram
#define GL_SGIX_async_histogram
#define WM3_DEFINED_GL_SGIX_async_histogram
#define GL_ASYNC_HISTOGRAM_SGIX           0x832C
#define GL_MAX_ASYNC_HISTOGRAM_SGIX       0x832D
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_INTEL_texture_scissor;
WM3_EXTERN int Wm3NumFunctions_GL_INTEL_texture_scissor;
#ifndef GL_INTEL_texture_scissor
#define GL_INTEL_texture_scissor
#define WM3_DEFINED_GL_INTEL_texture_scissor
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_INTEL_parallel_arrays;
WM3_EXTERN int Wm3NumFunctions_GL_INTEL_parallel_arrays;
#ifndef GL_INTEL_parallel_arrays
#define GL_INTEL_parallel_arrays
#define WM3_DEFINED_GL_INTEL_parallel_arrays
#define GL_PARALLEL_ARRAYS_INTEL                        0x83F4
#define GL_VERTEX_ARRAY_PARALLEL_POINTERS_INTEL         0x83F5
#define GL_NORMAL_ARRAY_PARALLEL_POINTERS_INTEL         0x83F6
#define GL_COLOR_ARRAY_PARALLEL_POINTERS_INTEL          0x83F7
#define GL_TEXTURE_COORD_ARRAY_PARALLEL_POINTERS_INTEL  0x83F8

typedef void (APIENTRY* pfn_glVertexPointervINTEL) (GLint, GLenum, const GLvoid**);
WM3_EXTERN pfn_glVertexPointervINTEL Wm3glVertexPointervINTEL;
#define glVertexPointervINTEL Wm3glVertexPointervINTEL

typedef void (APIENTRY* pfn_glNormalPointervINTEL) (GLenum, const GLvoid**);
WM3_EXTERN pfn_glNormalPointervINTEL Wm3glNormalPointervINTEL;
#define glNormalPointervINTEL Wm3glNormalPointervINTEL

typedef void (APIENTRY* pfn_glColorPointervINTEL) (GLint, GLenum, const GLvoid**);
WM3_EXTERN pfn_glColorPointervINTEL Wm3glColorPointervINTEL;
#define glColorPointervINTEL Wm3glColorPointervINTEL

typedef void (APIENTRY* pfn_glTexCoordPointervINTEL) (GLint, GLenum, const GLvoid**);
WM3_EXTERN pfn_glTexCoordPointervINTEL Wm3glTexCoordPointervINTEL;
#define glTexCoordPointervINTEL Wm3glTexCoordPointervINTEL
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_HP_occlusion_test;
WM3_EXTERN int Wm3NumFunctions_GL_HP_occlusion_test;
#ifndef GL_HP_occlusion_test
#define GL_HP_occlusion_test
#define WM3_DEFINED_GL_HP_occlusion_test
#define GL_OCCLUSION_TEST_HP              0x8165
#define GL_OCCLUSION_TEST_RESULT_HP       0x8166
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_EXT_pixel_transform;
WM3_EXTERN int Wm3NumFunctions_GL_EXT_pixel_transform;
#ifndef GL_EXT_pixel_transform
#define GL_EXT_pixel_transform
#define WM3_DEFINED_GL_EXT_pixel_transform
#define GL_PIXEL_TRANSFORM_2D_EXT         0x8330
#define GL_PIXEL_MAG_FILTER_EXT           0x8331
#define GL_PIXEL_MIN_FILTER_EXT           0x8332
#define GL_PIXEL_CUBIC_WEIGHT_EXT         0x8333
#define GL_CUBIC_EXT                      0x8334
#define GL_AVERAGE_EXT                    0x8335
#define GL_PIXEL_TRANSFORM_2D_STACK_DEPTH_EXT 0x8336
#define GL_MAX_PIXEL_TRANSFORM_2D_STACK_DEPTH_EXT 0x8337
#define GL_PIXEL_TRANSFORM_2D_MATRIX_EXT  0x8338

typedef void (APIENTRY* pfn_glPixelTransformParameteriEXT) (GLenum, GLenum, GLint);
WM3_EXTERN pfn_glPixelTransformParameteriEXT Wm3glPixelTransformParameteriEXT;
#define glPixelTransformParameteriEXT Wm3glPixelTransformParameteriEXT

typedef void (APIENTRY* pfn_glPixelTransformParameterfEXT) (GLenum, GLenum, GLfloat);
WM3_EXTERN pfn_glPixelTransformParameterfEXT Wm3glPixelTransformParameterfEXT;
#define glPixelTransformParameterfEXT Wm3glPixelTransformParameterfEXT

typedef void (APIENTRY* pfn_glPixelTransformParameterivEXT) (GLenum, GLenum, const GLint*);
WM3_EXTERN pfn_glPixelTransformParameterivEXT Wm3glPixelTransformParameterivEXT;
#define glPixelTransformParameterivEXT Wm3glPixelTransformParameterivEXT

typedef void (APIENTRY* pfn_glPixelTransformParameterfvEXT) (GLenum, GLenum, const GLfloat*);
WM3_EXTERN pfn_glPixelTransformParameterfvEXT Wm3glPixelTransformParameterfvEXT;
#define glPixelTransformParameterfvEXT Wm3glPixelTransformParameterfvEXT
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_EXT_pixel_transform_color_table;
WM3_EXTERN int Wm3NumFunctions_GL_EXT_pixel_transform_color_table;
#ifndef GL_EXT_pixel_transform_color_table
#define GL_EXT_pixel_transform_color_table
#define WM3_DEFINED_GL_EXT_pixel_transform_color_table
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_EXT_shared_texture_palette;
WM3_EXTERN int Wm3NumFunctions_GL_EXT_shared_texture_palette;
#ifndef GL_EXT_shared_texture_palette
#define GL_EXT_shared_texture_palette
#define WM3_DEFINED_GL_EXT_shared_texture_palette
#define GL_SHARED_TEXTURE_PALETTE_EXT     0x81FB
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_EXT_separate_specular_color;
WM3_EXTERN int Wm3NumFunctions_GL_EXT_separate_specular_color;
#ifndef GL_EXT_separate_specular_color
#define GL_EXT_separate_specular_color
#define WM3_DEFINED_GL_EXT_separate_specular_color
#define GL_LIGHT_MODEL_COLOR_CONTROL_EXT  0x81F8
#define GL_SINGLE_COLOR_EXT               0x81F9
#define GL_SEPARATE_SPECULAR_COLOR_EXT    0x81FA
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_EXT_secondary_color;
WM3_EXTERN int Wm3NumFunctions_GL_EXT_secondary_color;
#ifndef GL_EXT_secondary_color
#define GL_EXT_secondary_color
#define WM3_DEFINED_GL_EXT_secondary_color
#define GL_COLOR_SUM_EXT                        0x8458
#define GL_CURRENT_SECONDARY_COLOR_EXT          0x8459
#define GL_SECONDARY_COLOR_ARRAY_SIZE_EXT       0x845A
#define GL_SECONDARY_COLOR_ARRAY_TYPE_EXT       0x845B
#define GL_SECONDARY_COLOR_ARRAY_STRIDE_EXT     0x845C
#define GL_SECONDARY_COLOR_ARRAY_POINTER_EXT    0x845D
#define GL_SECONDARY_COLOR_ARRAY_EXT            0x845E

typedef void (APIENTRY* pfn_glSecondaryColor3bEXT) (GLbyte, GLbyte, GLbyte);
WM3_EXTERN pfn_glSecondaryColor3bEXT Wm3glSecondaryColor3bEXT;
#define glSecondaryColor3bEXT Wm3glSecondaryColor3bEXT

typedef void (APIENTRY* pfn_glSecondaryColor3bvEXT) (const GLbyte*);
WM3_EXTERN pfn_glSecondaryColor3bvEXT Wm3glSecondaryColor3bvEXT;
#define glSecondaryColor3bvEXT Wm3glSecondaryColor3bvEXT

typedef void (APIENTRY* pfn_glSecondaryColor3dEXT) (GLdouble, GLdouble, GLdouble);
WM3_EXTERN pfn_glSecondaryColor3dEXT Wm3glSecondaryColor3dEXT;
#define glSecondaryColor3dEXT Wm3glSecondaryColor3dEXT

typedef void (APIENTRY* pfn_glSecondaryColor3dvEXT) (const GLdouble*);
WM3_EXTERN pfn_glSecondaryColor3dvEXT Wm3glSecondaryColor3dvEXT;
#define glSecondaryColor3dvEXT Wm3glSecondaryColor3dvEXT

typedef void (APIENTRY* pfn_glSecondaryColor3fEXT) (GLfloat, GLfloat, GLfloat);
WM3_EXTERN pfn_glSecondaryColor3fEXT Wm3glSecondaryColor3fEXT;
#define glSecondaryColor3fEXT Wm3glSecondaryColor3fEXT

typedef void (APIENTRY* pfn_glSecondaryColor3fvEXT) (const GLfloat*);
WM3_EXTERN pfn_glSecondaryColor3fvEXT Wm3glSecondaryColor3fvEXT;
#define glSecondaryColor3fvEXT Wm3glSecondaryColor3fvEXT

typedef void (APIENTRY* pfn_glSecondaryColor3iEXT) (GLint, GLint, GLint);
WM3_EXTERN pfn_glSecondaryColor3iEXT Wm3glSecondaryColor3iEXT;
#define glSecondaryColor3iEXT Wm3glSecondaryColor3iEXT

typedef void (APIENTRY* pfn_glSecondaryColor3ivEXT) (const GLint*);
WM3_EXTERN pfn_glSecondaryColor3ivEXT Wm3glSecondaryColor3ivEXT;
#define glSecondaryColor3ivEXT Wm3glSecondaryColor3ivEXT

typedef void (APIENTRY* pfn_glSecondaryColor3sEXT) (GLshort, GLshort, GLshort);
WM3_EXTERN pfn_glSecondaryColor3sEXT Wm3glSecondaryColor3sEXT;
#define glSecondaryColor3sEXT Wm3glSecondaryColor3sEXT

typedef void (APIENTRY* pfn_glSecondaryColor3svEXT) (const GLshort*);
WM3_EXTERN pfn_glSecondaryColor3svEXT Wm3glSecondaryColor3svEXT;
#define glSecondaryColor3svEXT Wm3glSecondaryColor3svEXT

typedef void (APIENTRY* pfn_glSecondaryColor3ubEXT) (GLubyte, GLubyte, GLubyte);
WM3_EXTERN pfn_glSecondaryColor3ubEXT Wm3glSecondaryColor3ubEXT;
#define glSecondaryColor3ubEXT Wm3glSecondaryColor3ubEXT

typedef void (APIENTRY* pfn_glSecondaryColor3ubvEXT) (const GLubyte*);
WM3_EXTERN pfn_glSecondaryColor3ubvEXT Wm3glSecondaryColor3ubvEXT;
#define glSecondaryColor3ubvEXT Wm3glSecondaryColor3ubvEXT

typedef void (APIENTRY* pfn_glSecondaryColor3uiEXT) (GLuint, GLuint, GLuint);
WM3_EXTERN pfn_glSecondaryColor3uiEXT Wm3glSecondaryColor3uiEXT;
#define glSecondaryColor3uiEXT Wm3glSecondaryColor3uiEXT

typedef void (APIENTRY* pfn_glSecondaryColor3uivEXT) (const GLuint*);
WM3_EXTERN pfn_glSecondaryColor3uivEXT Wm3glSecondaryColor3uivEXT;
#define glSecondaryColor3uivEXT Wm3glSecondaryColor3uivEXT

typedef void (APIENTRY* pfn_glSecondaryColor3usEXT) (GLushort, GLushort, GLushort);
WM3_EXTERN pfn_glSecondaryColor3usEXT Wm3glSecondaryColor3usEXT;
#define glSecondaryColor3usEXT Wm3glSecondaryColor3usEXT

typedef void (APIENTRY* pfn_glSecondaryColor3usvEXT) (const GLushort*);
WM3_EXTERN pfn_glSecondaryColor3usvEXT Wm3glSecondaryColor3usvEXT;
#define glSecondaryColor3usvEXT Wm3glSecondaryColor3usvEXT

typedef void (APIENTRY* pfn_glSecondaryColorPointerEXT) (GLint, GLenum, GLsizei, const GLvoid*);
WM3_EXTERN pfn_glSecondaryColorPointerEXT Wm3glSecondaryColorPointerEXT;
#define glSecondaryColorPointerEXT Wm3glSecondaryColorPointerEXT
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_EXT_texture_perturb_normal;
WM3_EXTERN int Wm3NumFunctions_GL_EXT_texture_perturb_normal;
#ifndef GL_EXT_texture_perturb_normal
#define GL_EXT_texture_perturb_normal
#define WM3_DEFINED_GL_EXT_texture_perturb_normal
#define GL_PERTURB_EXT                    0x85AE
#define GL_TEXTURE_NORMAL_EXT             0x85AF

typedef void (APIENTRY* pfn_glTextureNormalEXT) (GLenum);
WM3_EXTERN pfn_glTextureNormalEXT Wm3glTextureNormalEXT;
#define glTextureNormalEXT Wm3glTextureNormalEXT
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_EXT_multi_draw_arrays;
WM3_EXTERN int Wm3NumFunctions_GL_EXT_multi_draw_arrays;
#ifndef GL_EXT_multi_draw_arrays
#define GL_EXT_multi_draw_arrays
#define WM3_DEFINED_GL_EXT_multi_draw_arrays

typedef void (APIENTRY* pfn_glMultiDrawArraysEXT) (GLenum, GLint*, GLsizei*, GLsizei);
WM3_EXTERN pfn_glMultiDrawArraysEXT Wm3glMultiDrawArraysEXT;
#define glMultiDrawArraysEXT Wm3glMultiDrawArraysEXT

typedef void (APIENTRY* pfn_glMultiDrawElementsEXT) (GLenum, const GLsizei*, GLenum, const GLvoid**, GLsizei);
WM3_EXTERN pfn_glMultiDrawElementsEXT Wm3glMultiDrawElementsEXT;
#define glMultiDrawElementsEXT Wm3glMultiDrawElementsEXT
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_EXT_fog_coord;
WM3_EXTERN int Wm3NumFunctions_GL_EXT_fog_coord;
#ifndef GL_EXT_fog_coord
#define GL_EXT_fog_coord
#define WM3_DEFINED_GL_EXT_fog_coord
#define GL_FOG_COORDINATE_SOURCE_EXT        0x8450
#define GL_FOG_COORDINATE_EXT               0x8451
#define GL_FRAGMENT_DEPTH_EXT               0x8452
#define GL_CURRENT_FOG_COORDINATE_EXT       0x8453
#define GL_FOG_COORDINATE_ARRAY_TYPE_EXT    0x8454
#define GL_FOG_COORDINATE_ARRAY_STRIDE_EXT  0x8455
#define GL_FOG_COORDINATE_ARRAY_POINTER_EXT 0x8456
#define GL_FOG_COORDINATE_ARRAY_EXT         0x8457

typedef void (APIENTRY* pfn_glFogCoordfEXT) (GLfloat);
WM3_EXTERN pfn_glFogCoordfEXT Wm3glFogCoordfEXT;
#define glFogCoordfEXT Wm3glFogCoordfEXT

typedef void (APIENTRY* pfn_glFogCoordfvEXT) (const GLfloat*);
WM3_EXTERN pfn_glFogCoordfvEXT Wm3glFogCoordfvEXT;
#define glFogCoordfvEXT Wm3glFogCoordfvEXT

typedef void (APIENTRY* pfn_glFogCoorddEXT) (GLdouble);
WM3_EXTERN pfn_glFogCoorddEXT Wm3glFogCoorddEXT;
#define glFogCoorddEXT Wm3glFogCoorddEXT

typedef void (APIENTRY* pfn_glFogCoorddvEXT) (const GLdouble*);
WM3_EXTERN pfn_glFogCoorddvEXT Wm3glFogCoorddvEXT;
#define glFogCoorddvEXT Wm3glFogCoorddvEXT

typedef void (APIENTRY* pfn_glFogCoordPointerEXT) (GLenum, GLsizei, const GLvoid*);
WM3_EXTERN pfn_glFogCoordPointerEXT Wm3glFogCoordPointerEXT;
#define glFogCoordPointerEXT Wm3glFogCoordPointerEXT
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_REND_screen_coordinates;
WM3_EXTERN int Wm3NumFunctions_GL_REND_screen_coordinates;
#ifndef GL_REND_screen_coordinates
#define GL_REND_screen_coordinates
#define WM3_DEFINED_GL_REND_screen_coordinates
#define GL_SCREEN_COORDINATES_REND        0x8490
#define GL_INVERTED_SCREEN_W_REND         0x8491
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_EXT_coordinate_frame;
WM3_EXTERN int Wm3NumFunctions_GL_EXT_coordinate_frame;
#ifndef GL_EXT_coordinate_frame
#define GL_EXT_coordinate_frame
#define WM3_DEFINED_GL_EXT_coordinate_frame
#define GL_TANGENT_ARRAY_EXT              0x8439
#define GL_BINORMAL_ARRAY_EXT             0x843A
#define GL_CURRENT_TANGENT_EXT            0x843B
#define GL_CURRENT_BINORMAL_EXT           0x843C
#define GL_TANGENT_ARRAY_TYPE_EXT         0x843E
#define GL_TANGENT_ARRAY_STRIDE_EXT       0x843F
#define GL_BINORMAL_ARRAY_TYPE_EXT        0x8440
#define GL_BINORMAL_ARRAY_STRIDE_EXT      0x8441
#define GL_TANGENT_ARRAY_POINTER_EXT      0x8442
#define GL_BINORMAL_ARRAY_POINTER_EXT     0x8443
#define GL_MAP1_TANGENT_EXT               0x8444
#define GL_MAP2_TANGENT_EXT               0x8445
#define GL_MAP1_BINORMAL_EXT              0x8446
#define GL_MAP2_BINORMAL_EXT              0x8447

typedef void (APIENTRY* pfn_glTangent3bEXT) (GLbyte, GLbyte, GLbyte);
WM3_EXTERN pfn_glTangent3bEXT Wm3glTangent3bEXT;
#define glTangent3bEXT Wm3glTangent3bEXT

typedef void (APIENTRY* pfn_glTangent3bvEXT) (const GLbyte*);
WM3_EXTERN pfn_glTangent3bvEXT Wm3glTangent3bvEXT;
#define glTangent3bvEXT Wm3glTangent3bvEXT

typedef void (APIENTRY* pfn_glTangent3dEXT) (GLdouble, GLdouble, GLdouble);
WM3_EXTERN pfn_glTangent3dEXT Wm3glTangent3dEXT;
#define glTangent3dEXT Wm3glTangent3dEXT

typedef void (APIENTRY* pfn_glTangent3dvEXT) (const GLdouble*);
WM3_EXTERN pfn_glTangent3dvEXT Wm3glTangent3dvEXT;
#define glTangent3dvEXT Wm3glTangent3dvEXT

typedef void (APIENTRY* pfn_glTangent3fEXT) (GLfloat, GLfloat, GLfloat);
WM3_EXTERN pfn_glTangent3fEXT Wm3glTangent3fEXT;
#define glTangent3fEXT Wm3glTangent3fEXT

typedef void (APIENTRY* pfn_glTangent3fvEXT) (const GLfloat*);
WM3_EXTERN pfn_glTangent3fvEXT Wm3glTangent3fvEXT;
#define glTangent3fvEXT Wm3glTangent3fvEXT

typedef void (APIENTRY* pfn_glTangent3iEXT) (GLint, GLint, GLint);
WM3_EXTERN pfn_glTangent3iEXT Wm3glTangent3iEXT;
#define glTangent3iEXT Wm3glTangent3iEXT

typedef void (APIENTRY* pfn_glTangent3ivEXT) (const GLint*);
WM3_EXTERN pfn_glTangent3ivEXT Wm3glTangent3ivEXT;
#define glTangent3ivEXT Wm3glTangent3ivEXT

typedef void (APIENTRY* pfn_glTangent3sEXT) (GLshort, GLshort, GLshort);
WM3_EXTERN pfn_glTangent3sEXT Wm3glTangent3sEXT;
#define glTangent3sEXT Wm3glTangent3sEXT

typedef void (APIENTRY* pfn_glTangent3svEXT) (const GLshort*);
WM3_EXTERN pfn_glTangent3svEXT Wm3glTangent3svEXT;
#define glTangent3svEXT Wm3glTangent3svEXT

typedef void (APIENTRY* pfn_glBinormal3bEXT) (GLbyte, GLbyte, GLbyte);
WM3_EXTERN pfn_glBinormal3bEXT Wm3glBinormal3bEXT;
#define glBinormal3bEXT Wm3glBinormal3bEXT

typedef void (APIENTRY* pfn_glBinormal3bvEXT) (const GLbyte*);
WM3_EXTERN pfn_glBinormal3bvEXT Wm3glBinormal3bvEXT;
#define glBinormal3bvEXT Wm3glBinormal3bvEXT

typedef void (APIENTRY* pfn_glBinormal3dEXT) (GLdouble, GLdouble, GLdouble);
WM3_EXTERN pfn_glBinormal3dEXT Wm3glBinormal3dEXT;
#define glBinormal3dEXT Wm3glBinormal3dEXT

typedef void (APIENTRY* pfn_glBinormal3dvEXT) (const GLdouble*);
WM3_EXTERN pfn_glBinormal3dvEXT Wm3glBinormal3dvEXT;
#define glBinormal3dvEXT Wm3glBinormal3dvEXT

typedef void (APIENTRY* pfn_glBinormal3fEXT) (GLfloat, GLfloat, GLfloat);
WM3_EXTERN pfn_glBinormal3fEXT Wm3glBinormal3fEXT;
#define glBinormal3fEXT Wm3glBinormal3fEXT

typedef void (APIENTRY* pfn_glBinormal3fvEXT) (const GLfloat*);
WM3_EXTERN pfn_glBinormal3fvEXT Wm3glBinormal3fvEXT;
#define glBinormal3fvEXT Wm3glBinormal3fvEXT

typedef void (APIENTRY* pfn_glBinormal3iEXT) (GLint, GLint, GLint);
WM3_EXTERN pfn_glBinormal3iEXT Wm3glBinormal3iEXT;
#define glBinormal3iEXT Wm3glBinormal3iEXT

typedef void (APIENTRY* pfn_glBinormal3ivEXT) (const GLint*);
WM3_EXTERN pfn_glBinormal3ivEXT Wm3glBinormal3ivEXT;
#define glBinormal3ivEXT Wm3glBinormal3ivEXT

typedef void (APIENTRY* pfn_glBinormal3sEXT) (GLshort, GLshort, GLshort);
WM3_EXTERN pfn_glBinormal3sEXT Wm3glBinormal3sEXT;
#define glBinormal3sEXT Wm3glBinormal3sEXT

typedef void (APIENTRY* pfn_glBinormal3svEXT) (const GLshort*);
WM3_EXTERN pfn_glBinormal3svEXT Wm3glBinormal3svEXT;
#define glBinormal3svEXT Wm3glBinormal3svEXT

typedef void (APIENTRY* pfn_glTangentPointerEXT) (GLenum, GLsizei, const GLvoid*);
WM3_EXTERN pfn_glTangentPointerEXT Wm3glTangentPointerEXT;
#define glTangentPointerEXT Wm3glTangentPointerEXT

typedef void (APIENTRY* pfn_glBinormalPointerEXT) (GLenum, GLsizei, const GLvoid*);
WM3_EXTERN pfn_glBinormalPointerEXT Wm3glBinormalPointerEXT;
#define glBinormalPointerEXT Wm3glBinormalPointerEXT
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_EXT_texture_env_combine;
WM3_EXTERN int Wm3NumFunctions_GL_EXT_texture_env_combine;
#ifndef GL_EXT_texture_env_combine
#define GL_EXT_texture_env_combine
#define WM3_DEFINED_GL_EXT_texture_env_combine
#define GL_COMBINE_EXT                    0x8570
#define GL_COMBINE_RGB_EXT                0x8571
#define GL_COMBINE_ALPHA_EXT              0x8572
#define GL_RGB_SCALE_EXT                  0x8573
#define GL_ADD_SIGNED_EXT                 0x8574
#define GL_INTERPOLATE_EXT                0x8575
#define GL_CONSTANT_EXT                   0x8576
#define GL_PRIMARY_COLOR_EXT              0x8577
#define GL_PREVIOUS_EXT                   0x8578
#define GL_SOURCE0_RGB_EXT                0x8580
#define GL_SOURCE1_RGB_EXT                0x8581
#define GL_SOURCE2_RGB_EXT                0x8582
#define GL_SOURCE0_ALPHA_EXT              0x8588
#define GL_SOURCE1_ALPHA_EXT              0x8589
#define GL_SOURCE2_ALPHA_EXT              0x858A
#define GL_OPERAND0_RGB_EXT               0x8590
#define GL_OPERAND1_RGB_EXT               0x8591
#define GL_OPERAND2_RGB_EXT               0x8592
#define GL_OPERAND0_ALPHA_EXT             0x8598
#define GL_OPERAND1_ALPHA_EXT             0x8599
#define GL_OPERAND2_ALPHA_EXT             0x859A
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_APPLE_specular_vector;
WM3_EXTERN int Wm3NumFunctions_GL_APPLE_specular_vector;
#ifndef GL_APPLE_specular_vector
#define GL_APPLE_specular_vector
#define WM3_DEFINED_GL_APPLE_specular_vector
#define GL_LIGHT_MODEL_SPECULAR_VECTOR_APPLE 0x85B0
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_APPLE_transform_hint;
WM3_EXTERN int Wm3NumFunctions_GL_APPLE_transform_hint;
#ifndef GL_APPLE_transform_hint
#define GL_APPLE_transform_hint
#define WM3_DEFINED_GL_APPLE_transform_hint
#define GL_TRANSFORM_HINT_APPLE           0x85B1
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_SGIX_fog_scale;
WM3_EXTERN int Wm3NumFunctions_GL_SGIX_fog_scale;
#ifndef GL_SGIX_fog_scale
#define GL_SGIX_fog_scale
#define WM3_DEFINED_GL_SGIX_fog_scale
#define GL_FOG_SCALE_SGIX                 0x81FC
#define GL_FOG_SCALE_VALUE_SGIX           0x81FD
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_SUNX_constant_data;
WM3_EXTERN int Wm3NumFunctions_GL_SUNX_constant_data;
#ifndef GL_SUNX_constant_data
#define GL_SUNX_constant_data
#define WM3_DEFINED_GL_SUNX_constant_data
#define GL_UNPACK_CONSTANT_DATA_SUNX      0x81D5
#define GL_TEXTURE_CONSTANT_DATA_SUNX     0x81D6

typedef void (APIENTRY* pfn_glFinishTextureSUNX) (void);
WM3_EXTERN pfn_glFinishTextureSUNX Wm3glFinishTextureSUNX;
#define glFinishTextureSUNX Wm3glFinishTextureSUNX
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_SUN_global_alpha;
WM3_EXTERN int Wm3NumFunctions_GL_SUN_global_alpha;
#ifndef GL_SUN_global_alpha
#define GL_SUN_global_alpha
#define WM3_DEFINED_GL_SUN_global_alpha
#define GL_GLOBAL_ALPHA_SUN               0x81D9
#define GL_GLOBAL_ALPHA_FACTOR_SUN        0x81DA

typedef void (APIENTRY* pfn_glGlobalAlphaFactorbSUN) (GLbyte);
WM3_EXTERN pfn_glGlobalAlphaFactorbSUN Wm3glGlobalAlphaFactorbSUN;
#define glGlobalAlphaFactorbSUN Wm3glGlobalAlphaFactorbSUN

typedef void (APIENTRY* pfn_glGlobalAlphaFactorsSUN) (GLshort);
WM3_EXTERN pfn_glGlobalAlphaFactorsSUN Wm3glGlobalAlphaFactorsSUN;
#define glGlobalAlphaFactorsSUN Wm3glGlobalAlphaFactorsSUN

typedef void (APIENTRY* pfn_glGlobalAlphaFactoriSUN) (GLint);
WM3_EXTERN pfn_glGlobalAlphaFactoriSUN Wm3glGlobalAlphaFactoriSUN;
#define glGlobalAlphaFactoriSUN Wm3glGlobalAlphaFactoriSUN

typedef void (APIENTRY* pfn_glGlobalAlphaFactorfSUN) (GLfloat);
WM3_EXTERN pfn_glGlobalAlphaFactorfSUN Wm3glGlobalAlphaFactorfSUN;
#define glGlobalAlphaFactorfSUN Wm3glGlobalAlphaFactorfSUN

typedef void (APIENTRY* pfn_glGlobalAlphaFactordSUN) (GLdouble);
WM3_EXTERN pfn_glGlobalAlphaFactordSUN Wm3glGlobalAlphaFactordSUN;
#define glGlobalAlphaFactordSUN Wm3glGlobalAlphaFactordSUN

typedef void (APIENTRY* pfn_glGlobalAlphaFactorubSUN) (GLubyte);
WM3_EXTERN pfn_glGlobalAlphaFactorubSUN Wm3glGlobalAlphaFactorubSUN;
#define glGlobalAlphaFactorubSUN Wm3glGlobalAlphaFactorubSUN

typedef void (APIENTRY* pfn_glGlobalAlphaFactorusSUN) (GLushort);
WM3_EXTERN pfn_glGlobalAlphaFactorusSUN Wm3glGlobalAlphaFactorusSUN;
#define glGlobalAlphaFactorusSUN Wm3glGlobalAlphaFactorusSUN

typedef void (APIENTRY* pfn_glGlobalAlphaFactoruiSUN) (GLuint);
WM3_EXTERN pfn_glGlobalAlphaFactoruiSUN Wm3glGlobalAlphaFactoruiSUN;
#define glGlobalAlphaFactoruiSUN Wm3glGlobalAlphaFactoruiSUN
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_SUN_triangle_list;
WM3_EXTERN int Wm3NumFunctions_GL_SUN_triangle_list;
#ifndef GL_SUN_triangle_list
#define GL_SUN_triangle_list
#define WM3_DEFINED_GL_SUN_triangle_list
#define GL_RESTART_SUN                          0x0001
#define GL_REPLACE_MIDDLE_SUN                   0x0002
#define GL_REPLACE_OLDEST_SUN                   0x0003
#define GL_TRIANGLE_LIST_SUN                    0x81D7
#define GL_REPLACEMENT_CODE_SUN                 0x81D8
#define GL_REPLACEMENT_CODE_ARRAY_SUN           0x85C0
#define GL_REPLACEMENT_CODE_ARRAY_TYPE_SUN      0x85C1
#define GL_REPLACEMENT_CODE_ARRAY_STRIDE_SUN    0x85C2
#define GL_REPLACEMENT_CODE_ARRAY_POINTER_SUN   0x85C3
#define GL_R1UI_V3F_SUN                         0x85C4
#define GL_R1UI_C4UB_V3F_SUN                    0x85C5
#define GL_R1UI_C3F_V3F_SUN                     0x85C6
#define GL_R1UI_N3F_V3F_SUN                     0x85C7
#define GL_R1UI_C4F_N3F_V3F_SUN                 0x85C8
#define GL_R1UI_T2F_V3F_SUN                     0x85C9
#define GL_R1UI_T2F_N3F_V3F_SUN                 0x85CA
#define GL_R1UI_T2F_C4F_N3F_V3F_SUN             0x85CB

typedef void (APIENTRY* pfn_glReplacementCodeuiSUN) (GLuint);
WM3_EXTERN pfn_glReplacementCodeuiSUN Wm3glReplacementCodeuiSUN;
#define glReplacementCodeuiSUN Wm3glReplacementCodeuiSUN

typedef void (APIENTRY* pfn_glReplacementCodeusSUN) (GLushort);
WM3_EXTERN pfn_glReplacementCodeusSUN Wm3glReplacementCodeusSUN;
#define glReplacementCodeusSUN Wm3glReplacementCodeusSUN

typedef void (APIENTRY* pfn_glReplacementCodeubSUN) (GLubyte);
WM3_EXTERN pfn_glReplacementCodeubSUN Wm3glReplacementCodeubSUN;
#define glReplacementCodeubSUN Wm3glReplacementCodeubSUN

typedef void (APIENTRY* pfn_glReplacementCodeuivSUN) (const GLuint*);
WM3_EXTERN pfn_glReplacementCodeuivSUN Wm3glReplacementCodeuivSUN;
#define glReplacementCodeuivSUN Wm3glReplacementCodeuivSUN

typedef void (APIENTRY* pfn_glReplacementCodeusvSUN) (const GLushort*);
WM3_EXTERN pfn_glReplacementCodeusvSUN Wm3glReplacementCodeusvSUN;
#define glReplacementCodeusvSUN Wm3glReplacementCodeusvSUN

typedef void (APIENTRY* pfn_glReplacementCodeubvSUN) (const GLubyte*);
WM3_EXTERN pfn_glReplacementCodeubvSUN Wm3glReplacementCodeubvSUN;
#define glReplacementCodeubvSUN Wm3glReplacementCodeubvSUN

typedef void (APIENTRY* pfn_glReplacementCodePointerSUN) (GLenum, GLsizei, const GLvoid**);
WM3_EXTERN pfn_glReplacementCodePointerSUN Wm3glReplacementCodePointerSUN;
#define glReplacementCodePointerSUN Wm3glReplacementCodePointerSUN
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_SUN_vertex;
WM3_EXTERN int Wm3NumFunctions_GL_SUN_vertex;
#ifndef GL_SUN_vertex
#define GL_SUN_vertex
#define WM3_DEFINED_GL_SUN_vertex

typedef void (APIENTRY* pfn_glColor4ubVertex2fSUN) (GLubyte, GLubyte, GLubyte, GLubyte, GLfloat, GLfloat);
WM3_EXTERN pfn_glColor4ubVertex2fSUN Wm3glColor4ubVertex2fSUN;
#define glColor4ubVertex2fSUN Wm3glColor4ubVertex2fSUN

typedef void (APIENTRY* pfn_glColor4ubVertex2fvSUN) (const GLubyte*, const GLfloat*);
WM3_EXTERN pfn_glColor4ubVertex2fvSUN Wm3glColor4ubVertex2fvSUN;
#define glColor4ubVertex2fvSUN Wm3glColor4ubVertex2fvSUN

typedef void (APIENTRY* pfn_glColor4ubVertex3fSUN) (GLubyte, GLubyte, GLubyte, GLubyte, GLfloat, GLfloat, GLfloat);
WM3_EXTERN pfn_glColor4ubVertex3fSUN Wm3glColor4ubVertex3fSUN;
#define glColor4ubVertex3fSUN Wm3glColor4ubVertex3fSUN

typedef void (APIENTRY* pfn_glColor4ubVertex3fvSUN) (const GLubyte*, const GLfloat*);
WM3_EXTERN pfn_glColor4ubVertex3fvSUN Wm3glColor4ubVertex3fvSUN;
#define glColor4ubVertex3fvSUN Wm3glColor4ubVertex3fvSUN

typedef void (APIENTRY* pfn_glColor3fVertex3fSUN) (GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat);
WM3_EXTERN pfn_glColor3fVertex3fSUN Wm3glColor3fVertex3fSUN;
#define glColor3fVertex3fSUN Wm3glColor3fVertex3fSUN

typedef void (APIENTRY* pfn_glColor3fVertex3fvSUN) (const GLfloat*, const GLfloat*);
WM3_EXTERN pfn_glColor3fVertex3fvSUN Wm3glColor3fVertex3fvSUN;
#define glColor3fVertex3fvSUN Wm3glColor3fVertex3fvSUN

typedef void (APIENTRY* pfn_glNormal3fVertex3fSUN) (GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat);
WM3_EXTERN pfn_glNormal3fVertex3fSUN Wm3glNormal3fVertex3fSUN;
#define glNormal3fVertex3fSUN Wm3glNormal3fVertex3fSUN

typedef void (APIENTRY* pfn_glNormal3fVertex3fvSUN) (const GLfloat*, const GLfloat*);
WM3_EXTERN pfn_glNormal3fVertex3fvSUN Wm3glNormal3fVertex3fvSUN;
#define glNormal3fVertex3fvSUN Wm3glNormal3fVertex3fvSUN

typedef void (APIENTRY* pfn_glColor4fNormal3fVertex3fSUN) (GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat);
WM3_EXTERN pfn_glColor4fNormal3fVertex3fSUN Wm3glColor4fNormal3fVertex3fSUN;
#define glColor4fNormal3fVertex3fSUN Wm3glColor4fNormal3fVertex3fSUN

typedef void (APIENTRY* pfn_glColor4fNormal3fVertex3fvSUN) (const GLfloat*, const GLfloat*, const GLfloat*);
WM3_EXTERN pfn_glColor4fNormal3fVertex3fvSUN Wm3glColor4fNormal3fVertex3fvSUN;
#define glColor4fNormal3fVertex3fvSUN Wm3glColor4fNormal3fVertex3fvSUN

typedef void (APIENTRY* pfn_glTexCoord2fVertex3fSUN) (GLfloat, GLfloat, GLfloat, GLfloat, GLfloat);
WM3_EXTERN pfn_glTexCoord2fVertex3fSUN Wm3glTexCoord2fVertex3fSUN;
#define glTexCoord2fVertex3fSUN Wm3glTexCoord2fVertex3fSUN

typedef void (APIENTRY* pfn_glTexCoord2fVertex3fvSUN) (const GLfloat*, const GLfloat*);
WM3_EXTERN pfn_glTexCoord2fVertex3fvSUN Wm3glTexCoord2fVertex3fvSUN;
#define glTexCoord2fVertex3fvSUN Wm3glTexCoord2fVertex3fvSUN

typedef void (APIENTRY* pfn_glTexCoord4fVertex4fSUN) (GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat);
WM3_EXTERN pfn_glTexCoord4fVertex4fSUN Wm3glTexCoord4fVertex4fSUN;
#define glTexCoord4fVertex4fSUN Wm3glTexCoord4fVertex4fSUN

typedef void (APIENTRY* pfn_glTexCoord4fVertex4fvSUN) (const GLfloat*, const GLfloat*);
WM3_EXTERN pfn_glTexCoord4fVertex4fvSUN Wm3glTexCoord4fVertex4fvSUN;
#define glTexCoord4fVertex4fvSUN Wm3glTexCoord4fVertex4fvSUN

typedef void (APIENTRY* pfn_glTexCoord2fColor4ubVertex3fSUN) (GLfloat, GLfloat, GLubyte, GLubyte, GLubyte, GLubyte, GLfloat, GLfloat, GLfloat);
WM3_EXTERN pfn_glTexCoord2fColor4ubVertex3fSUN Wm3glTexCoord2fColor4ubVertex3fSUN;
#define glTexCoord2fColor4ubVertex3fSUN Wm3glTexCoord2fColor4ubVertex3fSUN

typedef void (APIENTRY* pfn_glTexCoord2fColor4ubVertex3fvSUN) (const GLfloat*, const GLubyte*, const GLfloat*);
WM3_EXTERN pfn_glTexCoord2fColor4ubVertex3fvSUN Wm3glTexCoord2fColor4ubVertex3fvSUN;
#define glTexCoord2fColor4ubVertex3fvSUN Wm3glTexCoord2fColor4ubVertex3fvSUN

typedef void (APIENTRY* pfn_glTexCoord2fColor3fVertex3fSUN) (GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat);
WM3_EXTERN pfn_glTexCoord2fColor3fVertex3fSUN Wm3glTexCoord2fColor3fVertex3fSUN;
#define glTexCoord2fColor3fVertex3fSUN Wm3glTexCoord2fColor3fVertex3fSUN

typedef void (APIENTRY* pfn_glTexCoord2fColor3fVertex3fvSUN) (const GLfloat*, const GLfloat*, const GLfloat*);
WM3_EXTERN pfn_glTexCoord2fColor3fVertex3fvSUN Wm3glTexCoord2fColor3fVertex3fvSUN;
#define glTexCoord2fColor3fVertex3fvSUN Wm3glTexCoord2fColor3fVertex3fvSUN

typedef void (APIENTRY* pfn_glTexCoord2fNormal3fVertex3fSUN) (GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat);
WM3_EXTERN pfn_glTexCoord2fNormal3fVertex3fSUN Wm3glTexCoord2fNormal3fVertex3fSUN;
#define glTexCoord2fNormal3fVertex3fSUN Wm3glTexCoord2fNormal3fVertex3fSUN

typedef void (APIENTRY* pfn_glTexCoord2fNormal3fVertex3fvSUN) (const GLfloat*, const GLfloat*, const GLfloat*);
WM3_EXTERN pfn_glTexCoord2fNormal3fVertex3fvSUN Wm3glTexCoord2fNormal3fVertex3fvSUN;
#define glTexCoord2fNormal3fVertex3fvSUN Wm3glTexCoord2fNormal3fVertex3fvSUN

typedef void (APIENTRY* pfn_glTexCoord2fColor4fNormal3fVertex3fSUN) (GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat);
WM3_EXTERN pfn_glTexCoord2fColor4fNormal3fVertex3fSUN Wm3glTexCoord2fColor4fNormal3fVertex3fSUN;
#define glTexCoord2fColor4fNormal3fVertex3fSUN Wm3glTexCoord2fColor4fNormal3fVertex3fSUN

typedef void (APIENTRY* pfn_glTexCoord2fColor4fNormal3fVertex3fvSUN) (const GLfloat*, const GLfloat*, const GLfloat*, const GLfloat*);
WM3_EXTERN pfn_glTexCoord2fColor4fNormal3fVertex3fvSUN Wm3glTexCoord2fColor4fNormal3fVertex3fvSUN;
#define glTexCoord2fColor4fNormal3fVertex3fvSUN Wm3glTexCoord2fColor4fNormal3fVertex3fvSUN

typedef void (APIENTRY* pfn_glTexCoord4fColor4fNormal3fVertex4fSUN) (GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat);
WM3_EXTERN pfn_glTexCoord4fColor4fNormal3fVertex4fSUN Wm3glTexCoord4fColor4fNormal3fVertex4fSUN;
#define glTexCoord4fColor4fNormal3fVertex4fSUN Wm3glTexCoord4fColor4fNormal3fVertex4fSUN

typedef void (APIENTRY* pfn_glTexCoord4fColor4fNormal3fVertex4fvSUN) (const GLfloat*, const GLfloat*, const GLfloat*, const GLfloat*);
WM3_EXTERN pfn_glTexCoord4fColor4fNormal3fVertex4fvSUN Wm3glTexCoord4fColor4fNormal3fVertex4fvSUN;
#define glTexCoord4fColor4fNormal3fVertex4fvSUN Wm3glTexCoord4fColor4fNormal3fVertex4fvSUN

typedef void (APIENTRY* pfn_glReplacementCodeuiVertex3fSUN) (GLuint, GLfloat, GLfloat, GLfloat);
WM3_EXTERN pfn_glReplacementCodeuiVertex3fSUN Wm3glReplacementCodeuiVertex3fSUN;
#define glReplacementCodeuiVertex3fSUN Wm3glReplacementCodeuiVertex3fSUN

typedef void (APIENTRY* pfn_glReplacementCodeuiVertex3fvSUN) (const GLuint*, const GLfloat*);
WM3_EXTERN pfn_glReplacementCodeuiVertex3fvSUN Wm3glReplacementCodeuiVertex3fvSUN;
#define glReplacementCodeuiVertex3fvSUN Wm3glReplacementCodeuiVertex3fvSUN

typedef void (APIENTRY* pfn_glReplacementCodeuiColor4ubVertex3fSUN) (GLuint, GLubyte, GLubyte, GLubyte, GLubyte, GLfloat, GLfloat, GLfloat);
WM3_EXTERN pfn_glReplacementCodeuiColor4ubVertex3fSUN Wm3glReplacementCodeuiColor4ubVertex3fSUN;
#define glReplacementCodeuiColor4ubVertex3fSUN Wm3glReplacementCodeuiColor4ubVertex3fSUN

typedef void (APIENTRY* pfn_glReplacementCodeuiColor4ubVertex3fvSUN) (const GLuint*, const GLubyte*, const GLfloat*);
WM3_EXTERN pfn_glReplacementCodeuiColor4ubVertex3fvSUN Wm3glReplacementCodeuiColor4ubVertex3fvSUN;
#define glReplacementCodeuiColor4ubVertex3fvSUN Wm3glReplacementCodeuiColor4ubVertex3fvSUN

typedef void (APIENTRY* pfn_glReplacementCodeuiColor3fVertex3fSUN) (GLuint, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat);
WM3_EXTERN pfn_glReplacementCodeuiColor3fVertex3fSUN Wm3glReplacementCodeuiColor3fVertex3fSUN;
#define glReplacementCodeuiColor3fVertex3fSUN Wm3glReplacementCodeuiColor3fVertex3fSUN

typedef void (APIENTRY* pfn_glReplacementCodeuiColor3fVertex3fvSUN) (const GLuint*, const GLfloat*, const GLfloat*);
WM3_EXTERN pfn_glReplacementCodeuiColor3fVertex3fvSUN Wm3glReplacementCodeuiColor3fVertex3fvSUN;
#define glReplacementCodeuiColor3fVertex3fvSUN Wm3glReplacementCodeuiColor3fVertex3fvSUN

typedef void (APIENTRY* pfn_glReplacementCodeuiNormal3fVertex3fSUN) (GLuint, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat);
WM3_EXTERN pfn_glReplacementCodeuiNormal3fVertex3fSUN Wm3glReplacementCodeuiNormal3fVertex3fSUN;
#define glReplacementCodeuiNormal3fVertex3fSUN Wm3glReplacementCodeuiNormal3fVertex3fSUN

typedef void (APIENTRY* pfn_glReplacementCodeuiNormal3fVertex3fvSUN) (const GLuint*, const GLfloat*, const GLfloat*);
WM3_EXTERN pfn_glReplacementCodeuiNormal3fVertex3fvSUN Wm3glReplacementCodeuiNormal3fVertex3fvSUN;
#define glReplacementCodeuiNormal3fVertex3fvSUN Wm3glReplacementCodeuiNormal3fVertex3fvSUN

typedef void (APIENTRY* pfn_glReplacementCodeuiColor4fNormal3fVertex3fSUN) (GLuint, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat);
WM3_EXTERN pfn_glReplacementCodeuiColor4fNormal3fVertex3fSUN Wm3glReplacementCodeuiColor4fNormal3fVertex3fSUN;
#define glReplacementCodeuiColor4fNormal3fVertex3fSUN Wm3glReplacementCodeuiColor4fNormal3fVertex3fSUN

typedef void (APIENTRY* pfn_glReplacementCodeuiColor4fNormal3fVertex3fvSUN) (const GLuint*, const GLfloat*, const GLfloat*, const GLfloat*);
WM3_EXTERN pfn_glReplacementCodeuiColor4fNormal3fVertex3fvSUN Wm3glReplacementCodeuiColor4fNormal3fVertex3fvSUN;
#define glReplacementCodeuiColor4fNormal3fVertex3fvSUN Wm3glReplacementCodeuiColor4fNormal3fVertex3fvSUN

typedef void (APIENTRY* pfn_glReplacementCodeuiTexCoord2fVertex3fSUN) (GLuint, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat);
WM3_EXTERN pfn_glReplacementCodeuiTexCoord2fVertex3fSUN Wm3glReplacementCodeuiTexCoord2fVertex3fSUN;
#define glReplacementCodeuiTexCoord2fVertex3fSUN Wm3glReplacementCodeuiTexCoord2fVertex3fSUN

typedef void (APIENTRY* pfn_glReplacementCodeuiTexCoord2fVertex3fvSUN) (const GLuint*, const GLfloat*, const GLfloat*);
WM3_EXTERN pfn_glReplacementCodeuiTexCoord2fVertex3fvSUN Wm3glReplacementCodeuiTexCoord2fVertex3fvSUN;
#define glReplacementCodeuiTexCoord2fVertex3fvSUN Wm3glReplacementCodeuiTexCoord2fVertex3fvSUN

typedef void (APIENTRY* pfn_glReplacementCodeuiTexCoord2fNormal3fVertex3fSUN) (GLuint, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat);
WM3_EXTERN pfn_glReplacementCodeuiTexCoord2fNormal3fVertex3fSUN Wm3glReplacementCodeuiTexCoord2fNormal3fVertex3fSUN;
#define glReplacementCodeuiTexCoord2fNormal3fVertex3fSUN Wm3glReplacementCodeuiTexCoord2fNormal3fVertex3fSUN

typedef void (APIENTRY* pfn_glReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN) (const GLuint*, const GLfloat*, const GLfloat*, const GLfloat*);
WM3_EXTERN pfn_glReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN Wm3glReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN;
#define glReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN Wm3glReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN

typedef void (APIENTRY* pfn_glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN) (GLuint, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat);
WM3_EXTERN pfn_glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN Wm3glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN;
#define glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN Wm3glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN

typedef void (APIENTRY* pfn_glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN) (const GLuint*, const GLfloat*, const GLfloat*, const GLfloat*, const GLfloat*);
WM3_EXTERN pfn_glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN Wm3glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN;
#define glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN Wm3glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_EXT_blend_func_separate;
WM3_EXTERN int Wm3NumFunctions_GL_EXT_blend_func_separate;
#ifndef GL_EXT_blend_func_separate
#define GL_EXT_blend_func_separate
#define WM3_DEFINED_GL_EXT_blend_func_separate
#define GL_BLEND_DST_RGB_EXT              0x80C8
#define GL_BLEND_SRC_RGB_EXT              0x80C9
#define GL_BLEND_DST_ALPHA_EXT            0x80CA
#define GL_BLEND_SRC_ALPHA_EXT            0x80CB

typedef void (APIENTRY* pfn_glBlendFuncSeparateEXT) (GLenum, GLenum, GLenum, GLenum);
WM3_EXTERN pfn_glBlendFuncSeparateEXT Wm3glBlendFuncSeparateEXT;
#define glBlendFuncSeparateEXT Wm3glBlendFuncSeparateEXT
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_INGR_blend_func_separate;
WM3_EXTERN int Wm3NumFunctions_GL_INGR_blend_func_separate;
#ifndef GL_INGR_blend_func_separate
#define GL_INGR_blend_func_separate
#define WM3_DEFINED_GL_INGR_blend_func_separate

typedef void (APIENTRY* pfn_glBlendFuncSeparateINGR) (GLenum, GLenum, GLenum, GLenum);
WM3_EXTERN pfn_glBlendFuncSeparateINGR Wm3glBlendFuncSeparateINGR;
#define glBlendFuncSeparateINGR Wm3glBlendFuncSeparateINGR
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_INGR_color_clamp;
WM3_EXTERN int Wm3NumFunctions_GL_INGR_color_clamp;
#ifndef GL_INGR_color_clamp
#define GL_INGR_color_clamp
#define WM3_DEFINED_GL_INGR_color_clamp
#define GL_RED_MIN_CLAMP_INGR             0x8560
#define GL_GREEN_MIN_CLAMP_INGR           0x8561
#define GL_BLUE_MIN_CLAMP_INGR            0x8562
#define GL_ALPHA_MIN_CLAMP_INGR           0x8563
#define GL_RED_MAX_CLAMP_INGR             0x8564
#define GL_GREEN_MAX_CLAMP_INGR           0x8565
#define GL_BLUE_MAX_CLAMP_INGR            0x8566
#define GL_ALPHA_MAX_CLAMP_INGR           0x8567
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_INGR_interlace_read;
WM3_EXTERN int Wm3NumFunctions_GL_INGR_interlace_read;
#ifndef GL_INGR_interlace_read
#define GL_INGR_interlace_read
#define WM3_DEFINED_GL_INGR_interlace_read
#define GL_INTERLACE_READ_INGR            0x8568
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_EXT_stencil_wrap;
WM3_EXTERN int Wm3NumFunctions_GL_EXT_stencil_wrap;
#ifndef GL_EXT_stencil_wrap
#define GL_EXT_stencil_wrap
#define WM3_DEFINED_GL_EXT_stencil_wrap
#define GL_INCR_WRAP_EXT                  0x8507
#define GL_DECR_WRAP_EXT                  0x8508
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_EXT_422_pixels;
WM3_EXTERN int Wm3NumFunctions_GL_EXT_422_pixels;
#ifndef GL_EXT_422_pixels
#define GL_EXT_422_pixels
#define WM3_DEFINED_GL_EXT_422_pixels
#define GL_422_EXT                        0x80CC
#define GL_422_REV_EXT                    0x80CD
#define GL_422_AVERAGE_EXT                0x80CE
#define GL_422_REV_AVERAGE_EXT            0x80CF
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_NV_texgen_reflection;
WM3_EXTERN int Wm3NumFunctions_GL_NV_texgen_reflection;
#ifndef GL_NV_texgen_reflection
#define GL_NV_texgen_reflection
#define WM3_DEFINED_GL_NV_texgen_reflection
#define GL_NORMAL_MAP_NV                  0x8511
#define GL_REFLECTION_MAP_NV              0x8512
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_EXT_texture_cube_map;
WM3_EXTERN int Wm3NumFunctions_GL_EXT_texture_cube_map;
#ifndef GL_EXT_texture_cube_map
#define GL_EXT_texture_cube_map
#define WM3_DEFINED_GL_EXT_texture_cube_map
#define GL_NORMAL_MAP_EXT                 0x8511
#define GL_REFLECTION_MAP_EXT             0x8512
#define GL_TEXTURE_CUBE_MAP_EXT           0x8513
#define GL_TEXTURE_BINDING_CUBE_MAP_EXT   0x8514
#define GL_TEXTURE_CUBE_MAP_POSITIVE_X_EXT 0x8515
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_X_EXT 0x8516
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Y_EXT 0x8517
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Y_EXT 0x8518
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Z_EXT 0x8519
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Z_EXT 0x851A
#define GL_PROXY_TEXTURE_CUBE_MAP_EXT     0x851B
#define GL_MAX_CUBE_MAP_TEXTURE_SIZE_EXT  0x851C
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_SUN_convolution_border_modes;
WM3_EXTERN int Wm3NumFunctions_GL_SUN_convolution_border_modes;
#ifndef GL_SUN_convolution_border_modes
#define GL_SUN_convolution_border_modes
#define WM3_DEFINED_GL_SUN_convolution_border_modes
#define GL_WRAP_BORDER_SUN                0x81D4
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_EXT_texture_env_add;
WM3_EXTERN int Wm3NumFunctions_GL_EXT_texture_env_add;
#ifndef GL_EXT_texture_env_add
#define GL_EXT_texture_env_add
#define WM3_DEFINED_GL_EXT_texture_env_add
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_EXT_texture_lod_bias;
WM3_EXTERN int Wm3NumFunctions_GL_EXT_texture_lod_bias;
#ifndef GL_EXT_texture_lod_bias
#define GL_EXT_texture_lod_bias
#define WM3_DEFINED_GL_EXT_texture_lod_bias
#define GL_MAX_TEXTURE_LOD_BIAS_EXT       0x84FD
#define GL_TEXTURE_FILTER_CONTROL_EXT     0x8500
#define GL_TEXTURE_LOD_BIAS_EXT           0x8501
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_EXT_texture_filter_anisotropic;
WM3_EXTERN int Wm3NumFunctions_GL_EXT_texture_filter_anisotropic;
#ifndef GL_EXT_texture_filter_anisotropic
#define GL_EXT_texture_filter_anisotropic
#define WM3_DEFINED_GL_EXT_texture_filter_anisotropic
#define GL_TEXTURE_MAX_ANISOTROPY_EXT     0x84FE
#define GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT 0x84FF
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_EXT_vertex_weighting;
WM3_EXTERN int Wm3NumFunctions_GL_EXT_vertex_weighting;
#ifndef GL_EXT_vertex_weighting
#define GL_EXT_vertex_weighting
#define WM3_DEFINED_GL_EXT_vertex_weighting
#define GL_MODELVIEW0_STACK_DEPTH_EXT       GL_MODELVIEW_STACK_DEPTH
#define GL_MODELVIEW1_STACK_DEPTH_EXT       0x8502
#define GL_MODELVIEW0_MATRIX_EXT            GL_MODELVIEW_MATRIX
#define GL_MODELVIEW1_MATRIX_EXT            0x8506
#define GL_VERTEX_WEIGHTING_EXT             0x8509
#define GL_MODELVIEW0_EXT                   GL_MODELVIEW
#define GL_MODELVIEW1_EXT                   0x850A
#define GL_CURRENT_VERTEX_WEIGHT_EXT        0x850B
#define GL_VERTEX_WEIGHT_ARRAY_EXT          0x850C
#define GL_VERTEX_WEIGHT_ARRAY_SIZE_EXT     0x850D
#define GL_VERTEX_WEIGHT_ARRAY_TYPE_EXT     0x850E
#define GL_VERTEX_WEIGHT_ARRAY_STRIDE_EXT   0x850F
#define GL_VERTEX_WEIGHT_ARRAY_POINTER_EXT  0x8510

typedef void (APIENTRY* pfn_glVertexWeightfEXT) (GLfloat);
WM3_EXTERN pfn_glVertexWeightfEXT Wm3glVertexWeightfEXT;
#define glVertexWeightfEXT Wm3glVertexWeightfEXT

typedef void (APIENTRY* pfn_glVertexWeightfvEXT) (const GLfloat*);
WM3_EXTERN pfn_glVertexWeightfvEXT Wm3glVertexWeightfvEXT;
#define glVertexWeightfvEXT Wm3glVertexWeightfvEXT

typedef void (APIENTRY* pfn_glVertexWeightPointerEXT) (GLsizei, GLenum, GLsizei, const GLvoid*);
WM3_EXTERN pfn_glVertexWeightPointerEXT Wm3glVertexWeightPointerEXT;
#define glVertexWeightPointerEXT Wm3glVertexWeightPointerEXT
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_NV_light_max_exponent;
WM3_EXTERN int Wm3NumFunctions_GL_NV_light_max_exponent;
#ifndef GL_NV_light_max_exponent
#define GL_NV_light_max_exponent
#define WM3_DEFINED_GL_NV_light_max_exponent
#define GL_MAX_SHININESS_NV               0x8504
#define GL_MAX_SPOT_EXPONENT_NV           0x8505
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_NV_vertex_array_range;
WM3_EXTERN int Wm3NumFunctions_GL_NV_vertex_array_range;
#ifndef GL_NV_vertex_array_range
#define GL_NV_vertex_array_range
#define WM3_DEFINED_GL_NV_vertex_array_range
#define GL_VERTEX_ARRAY_RANGE_NV          0x851D
#define GL_VERTEX_ARRAY_RANGE_LENGTH_NV   0x851E
#define GL_VERTEX_ARRAY_RANGE_VALID_NV    0x851F
#define GL_MAX_VERTEX_ARRAY_RANGE_ELEMENT_NV 0x8520
#define GL_VERTEX_ARRAY_RANGE_POINTER_NV  0x8521

typedef void (APIENTRY* pfn_glFlushVertexArrayRangeNV) (void);
WM3_EXTERN pfn_glFlushVertexArrayRangeNV Wm3glFlushVertexArrayRangeNV;
#define glFlushVertexArrayRangeNV Wm3glFlushVertexArrayRangeNV

typedef void (APIENTRY* pfn_glVertexArrayRangeNV) (GLsizei, const GLvoid*);
WM3_EXTERN pfn_glVertexArrayRangeNV Wm3glVertexArrayRangeNV;
#define glVertexArrayRangeNV Wm3glVertexArrayRangeNV
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_NV_register_combiners;
WM3_EXTERN int Wm3NumFunctions_GL_NV_register_combiners;
#ifndef GL_NV_register_combiners
#define GL_NV_register_combiners
#define WM3_DEFINED_GL_NV_register_combiners
#define GL_REGISTER_COMBINERS_NV          0x8522
#define GL_VARIABLE_A_NV                  0x8523
#define GL_VARIABLE_B_NV                  0x8524
#define GL_VARIABLE_C_NV                  0x8525
#define GL_VARIABLE_D_NV                  0x8526
#define GL_VARIABLE_E_NV                  0x8527
#define GL_VARIABLE_F_NV                  0x8528
#define GL_VARIABLE_G_NV                  0x8529
#define GL_CONSTANT_COLOR0_NV             0x852A
#define GL_CONSTANT_COLOR1_NV             0x852B
#define GL_PRIMARY_COLOR_NV               0x852C
#define GL_SECONDARY_COLOR_NV             0x852D
#define GL_SPARE0_NV                      0x852E
#define GL_SPARE1_NV                      0x852F
#define GL_DISCARD_NV                     0x8530
#define GL_E_TIMES_F_NV                   0x8531
#define GL_SPARE0_PLUS_SECONDARY_COLOR_NV 0x8532
#define GL_UNSIGNED_IDENTITY_NV           0x8536
#define GL_UNSIGNED_INVERT_NV             0x8537
#define GL_EXPAND_NORMAL_NV               0x8538
#define GL_EXPAND_NEGATE_NV               0x8539
#define GL_HALF_BIAS_NORMAL_NV            0x853A
#define GL_HALF_BIAS_NEGATE_NV            0x853B
#define GL_SIGNED_IDENTITY_NV             0x853C
#define GL_SIGNED_NEGATE_NV               0x853D
#define GL_SCALE_BY_TWO_NV                0x853E
#define GL_SCALE_BY_FOUR_NV               0x853F
#define GL_SCALE_BY_ONE_HALF_NV           0x8540
#define GL_BIAS_BY_NEGATIVE_ONE_HALF_NV   0x8541
#define GL_COMBINER_INPUT_NV              0x8542
#define GL_COMBINER_MAPPING_NV            0x8543
#define GL_COMBINER_COMPONENT_USAGE_NV    0x8544
#define GL_COMBINER_AB_DOT_PRODUCT_NV     0x8545
#define GL_COMBINER_CD_DOT_PRODUCT_NV     0x8546
#define GL_COMBINER_MUX_SUM_NV            0x8547
#define GL_COMBINER_SCALE_NV              0x8548
#define GL_COMBINER_BIAS_NV               0x8549
#define GL_COMBINER_AB_OUTPUT_NV          0x854A
#define GL_COMBINER_CD_OUTPUT_NV          0x854B
#define GL_COMBINER_SUM_OUTPUT_NV         0x854C
#define GL_MAX_GENERAL_COMBINERS_NV       0x854D
#define GL_NUM_GENERAL_COMBINERS_NV       0x854E
#define GL_COLOR_SUM_CLAMP_NV             0x854F
#define GL_COMBINER0_NV                   0x8550
#define GL_COMBINER1_NV                   0x8551
#define GL_COMBINER2_NV                   0x8552
#define GL_COMBINER3_NV                   0x8553
#define GL_COMBINER4_NV                   0x8554
#define GL_COMBINER5_NV                   0x8555
#define GL_COMBINER6_NV                   0x8556
#define GL_COMBINER7_NV                   0x8557
/* reuse GL_TEXTURE0_ARB */
/* reuse GL_TEXTURE1_ARB */
/* reuse GL_ZERO */
/* reuse GL_NONE */
/* reuse GL_FOG */

typedef void (APIENTRY* pfn_glCombinerParameterfvNV) (GLenum, const GLfloat*);
WM3_EXTERN pfn_glCombinerParameterfvNV Wm3glCombinerParameterfvNV;
#define glCombinerParameterfvNV Wm3glCombinerParameterfvNV

typedef void (APIENTRY* pfn_glCombinerParameterfNV) (GLenum, GLfloat);
WM3_EXTERN pfn_glCombinerParameterfNV Wm3glCombinerParameterfNV;
#define glCombinerParameterfNV Wm3glCombinerParameterfNV

typedef void (APIENTRY* pfn_glCombinerParameterivNV) (GLenum, const GLint*);
WM3_EXTERN pfn_glCombinerParameterivNV Wm3glCombinerParameterivNV;
#define glCombinerParameterivNV Wm3glCombinerParameterivNV

typedef void (APIENTRY* pfn_glCombinerParameteriNV) (GLenum, GLint);
WM3_EXTERN pfn_glCombinerParameteriNV Wm3glCombinerParameteriNV;
#define glCombinerParameteriNV Wm3glCombinerParameteriNV

typedef void (APIENTRY* pfn_glCombinerInputNV) (GLenum, GLenum, GLenum, GLenum, GLenum, GLenum);
WM3_EXTERN pfn_glCombinerInputNV Wm3glCombinerInputNV;
#define glCombinerInputNV Wm3glCombinerInputNV

typedef void (APIENTRY* pfn_glCombinerOutputNV) (GLenum, GLenum, GLenum, GLenum, GLenum, GLenum, GLenum, GLboolean, GLboolean, GLboolean);
WM3_EXTERN pfn_glCombinerOutputNV Wm3glCombinerOutputNV;
#define glCombinerOutputNV Wm3glCombinerOutputNV

typedef void (APIENTRY* pfn_glFinalCombinerInputNV) (GLenum, GLenum, GLenum, GLenum);
WM3_EXTERN pfn_glFinalCombinerInputNV Wm3glFinalCombinerInputNV;
#define glFinalCombinerInputNV Wm3glFinalCombinerInputNV

typedef void (APIENTRY* pfn_glGetCombinerInputParameterfvNV) (GLenum, GLenum, GLenum, GLenum, GLfloat*);
WM3_EXTERN pfn_glGetCombinerInputParameterfvNV Wm3glGetCombinerInputParameterfvNV;
#define glGetCombinerInputParameterfvNV Wm3glGetCombinerInputParameterfvNV

typedef void (APIENTRY* pfn_glGetCombinerInputParameterivNV) (GLenum, GLenum, GLenum, GLenum, GLint*);
WM3_EXTERN pfn_glGetCombinerInputParameterivNV Wm3glGetCombinerInputParameterivNV;
#define glGetCombinerInputParameterivNV Wm3glGetCombinerInputParameterivNV

typedef void (APIENTRY* pfn_glGetCombinerOutputParameterfvNV) (GLenum, GLenum, GLenum, GLfloat*);
WM3_EXTERN pfn_glGetCombinerOutputParameterfvNV Wm3glGetCombinerOutputParameterfvNV;
#define glGetCombinerOutputParameterfvNV Wm3glGetCombinerOutputParameterfvNV

typedef void (APIENTRY* pfn_glGetCombinerOutputParameterivNV) (GLenum, GLenum, GLenum, GLint*);
WM3_EXTERN pfn_glGetCombinerOutputParameterivNV Wm3glGetCombinerOutputParameterivNV;
#define glGetCombinerOutputParameterivNV Wm3glGetCombinerOutputParameterivNV

typedef void (APIENTRY* pfn_glGetFinalCombinerInputParameterfvNV) (GLenum, GLenum, GLfloat*);
WM3_EXTERN pfn_glGetFinalCombinerInputParameterfvNV Wm3glGetFinalCombinerInputParameterfvNV;
#define glGetFinalCombinerInputParameterfvNV Wm3glGetFinalCombinerInputParameterfvNV

typedef void (APIENTRY* pfn_glGetFinalCombinerInputParameterivNV) (GLenum, GLenum, GLint*);
WM3_EXTERN pfn_glGetFinalCombinerInputParameterivNV Wm3glGetFinalCombinerInputParameterivNV;
#define glGetFinalCombinerInputParameterivNV Wm3glGetFinalCombinerInputParameterivNV
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_NV_fog_distance;
WM3_EXTERN int Wm3NumFunctions_GL_NV_fog_distance;
#ifndef GL_NV_fog_distance
#define GL_NV_fog_distance
#define WM3_DEFINED_GL_NV_fog_distance
#define GL_FOG_DISTANCE_MODE_NV           0x855A
#define GL_EYE_RADIAL_NV                  0x855B
#define GL_EYE_PLANE_ABSOLUTE_NV          0x855C
/* reuse GL_EYE_PLANE */
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_NV_texgen_emboss;
WM3_EXTERN int Wm3NumFunctions_GL_NV_texgen_emboss;
#ifndef GL_NV_texgen_emboss
#define GL_NV_texgen_emboss
#define WM3_DEFINED_GL_NV_texgen_emboss
#define GL_EMBOSS_LIGHT_NV                0x855D
#define GL_EMBOSS_CONSTANT_NV             0x855E
#define GL_EMBOSS_MAP_NV                  0x855F
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_NV_blend_square;
WM3_EXTERN int Wm3NumFunctions_GL_NV_blend_square;
#ifndef GL_NV_blend_square
#define GL_NV_blend_square
#define WM3_DEFINED_GL_NV_blend_square
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_NV_texture_env_combine4;
WM3_EXTERN int Wm3NumFunctions_GL_NV_texture_env_combine4;
#ifndef GL_NV_texture_env_combine4
#define GL_NV_texture_env_combine4
#define WM3_DEFINED_GL_NV_texture_env_combine4
#define GL_COMBINE4_NV                    0x8503
#define GL_SOURCE3_RGB_NV                 0x8583
#define GL_SOURCE3_ALPHA_NV               0x858B
#define GL_OPERAND3_RGB_NV                0x8593
#define GL_OPERAND3_ALPHA_NV              0x859B
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_MESA_resize_buffers;
WM3_EXTERN int Wm3NumFunctions_GL_MESA_resize_buffers;
#ifndef GL_MESA_resize_buffers
#define GL_MESA_resize_buffers
#define WM3_DEFINED_GL_MESA_resize_buffers

typedef void (APIENTRY* pfn_glResizeBuffersMESA) (void);
WM3_EXTERN pfn_glResizeBuffersMESA Wm3glResizeBuffersMESA;
#define glResizeBuffersMESA Wm3glResizeBuffersMESA
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_MESA_window_pos;
WM3_EXTERN int Wm3NumFunctions_GL_MESA_window_pos;
#ifndef GL_MESA_window_pos
#define GL_MESA_window_pos
#define WM3_DEFINED_GL_MESA_window_pos

typedef void (APIENTRY* pfn_glWindowPos2dMESA) (GLdouble, GLdouble);
WM3_EXTERN pfn_glWindowPos2dMESA Wm3glWindowPos2dMESA;
#define glWindowPos2dMESA Wm3glWindowPos2dMESA

typedef void (APIENTRY* pfn_glWindowPos2dvMESA) (const GLdouble*);
WM3_EXTERN pfn_glWindowPos2dvMESA Wm3glWindowPos2dvMESA;
#define glWindowPos2dvMESA Wm3glWindowPos2dvMESA

typedef void (APIENTRY* pfn_glWindowPos2fMESA) (GLfloat, GLfloat);
WM3_EXTERN pfn_glWindowPos2fMESA Wm3glWindowPos2fMESA;
#define glWindowPos2fMESA Wm3glWindowPos2fMESA

typedef void (APIENTRY* pfn_glWindowPos2fvMESA) (const GLfloat*);
WM3_EXTERN pfn_glWindowPos2fvMESA Wm3glWindowPos2fvMESA;
#define glWindowPos2fvMESA Wm3glWindowPos2fvMESA

typedef void (APIENTRY* pfn_glWindowPos2iMESA) (GLint, GLint);
WM3_EXTERN pfn_glWindowPos2iMESA Wm3glWindowPos2iMESA;
#define glWindowPos2iMESA Wm3glWindowPos2iMESA

typedef void (APIENTRY* pfn_glWindowPos2ivMESA) (const GLint*);
WM3_EXTERN pfn_glWindowPos2ivMESA Wm3glWindowPos2ivMESA;
#define glWindowPos2ivMESA Wm3glWindowPos2ivMESA

typedef void (APIENTRY* pfn_glWindowPos2sMESA) (GLshort, GLshort);
WM3_EXTERN pfn_glWindowPos2sMESA Wm3glWindowPos2sMESA;
#define glWindowPos2sMESA Wm3glWindowPos2sMESA

typedef void (APIENTRY* pfn_glWindowPos2svMESA) (const GLshort*);
WM3_EXTERN pfn_glWindowPos2svMESA Wm3glWindowPos2svMESA;
#define glWindowPos2svMESA Wm3glWindowPos2svMESA

typedef void (APIENTRY* pfn_glWindowPos3dMESA) (GLdouble, GLdouble, GLdouble);
WM3_EXTERN pfn_glWindowPos3dMESA Wm3glWindowPos3dMESA;
#define glWindowPos3dMESA Wm3glWindowPos3dMESA

typedef void (APIENTRY* pfn_glWindowPos3dvMESA) (const GLdouble*);
WM3_EXTERN pfn_glWindowPos3dvMESA Wm3glWindowPos3dvMESA;
#define glWindowPos3dvMESA Wm3glWindowPos3dvMESA

typedef void (APIENTRY* pfn_glWindowPos3fMESA) (GLfloat, GLfloat, GLfloat);
WM3_EXTERN pfn_glWindowPos3fMESA Wm3glWindowPos3fMESA;
#define glWindowPos3fMESA Wm3glWindowPos3fMESA

typedef void (APIENTRY* pfn_glWindowPos3fvMESA) (const GLfloat*);
WM3_EXTERN pfn_glWindowPos3fvMESA Wm3glWindowPos3fvMESA;
#define glWindowPos3fvMESA Wm3glWindowPos3fvMESA

typedef void (APIENTRY* pfn_glWindowPos3iMESA) (GLint, GLint, GLint);
WM3_EXTERN pfn_glWindowPos3iMESA Wm3glWindowPos3iMESA;
#define glWindowPos3iMESA Wm3glWindowPos3iMESA

typedef void (APIENTRY* pfn_glWindowPos3ivMESA) (const GLint*);
WM3_EXTERN pfn_glWindowPos3ivMESA Wm3glWindowPos3ivMESA;
#define glWindowPos3ivMESA Wm3glWindowPos3ivMESA

typedef void (APIENTRY* pfn_glWindowPos3sMESA) (GLshort, GLshort, GLshort);
WM3_EXTERN pfn_glWindowPos3sMESA Wm3glWindowPos3sMESA;
#define glWindowPos3sMESA Wm3glWindowPos3sMESA

typedef void (APIENTRY* pfn_glWindowPos3svMESA) (const GLshort*);
WM3_EXTERN pfn_glWindowPos3svMESA Wm3glWindowPos3svMESA;
#define glWindowPos3svMESA Wm3glWindowPos3svMESA

typedef void (APIENTRY* pfn_glWindowPos4dMESA) (GLdouble, GLdouble, GLdouble, GLdouble);
WM3_EXTERN pfn_glWindowPos4dMESA Wm3glWindowPos4dMESA;
#define glWindowPos4dMESA Wm3glWindowPos4dMESA

typedef void (APIENTRY* pfn_glWindowPos4dvMESA) (const GLdouble*);
WM3_EXTERN pfn_glWindowPos4dvMESA Wm3glWindowPos4dvMESA;
#define glWindowPos4dvMESA Wm3glWindowPos4dvMESA

typedef void (APIENTRY* pfn_glWindowPos4fMESA) (GLfloat, GLfloat, GLfloat, GLfloat);
WM3_EXTERN pfn_glWindowPos4fMESA Wm3glWindowPos4fMESA;
#define glWindowPos4fMESA Wm3glWindowPos4fMESA

typedef void (APIENTRY* pfn_glWindowPos4fvMESA) (const GLfloat*);
WM3_EXTERN pfn_glWindowPos4fvMESA Wm3glWindowPos4fvMESA;
#define glWindowPos4fvMESA Wm3glWindowPos4fvMESA

typedef void (APIENTRY* pfn_glWindowPos4iMESA) (GLint, GLint, GLint, GLint);
WM3_EXTERN pfn_glWindowPos4iMESA Wm3glWindowPos4iMESA;
#define glWindowPos4iMESA Wm3glWindowPos4iMESA

typedef void (APIENTRY* pfn_glWindowPos4ivMESA) (const GLint*);
WM3_EXTERN pfn_glWindowPos4ivMESA Wm3glWindowPos4ivMESA;
#define glWindowPos4ivMESA Wm3glWindowPos4ivMESA

typedef void (APIENTRY* pfn_glWindowPos4sMESA) (GLshort, GLshort, GLshort, GLshort);
WM3_EXTERN pfn_glWindowPos4sMESA Wm3glWindowPos4sMESA;
#define glWindowPos4sMESA Wm3glWindowPos4sMESA

typedef void (APIENTRY* pfn_glWindowPos4svMESA) (const GLshort*);
WM3_EXTERN pfn_glWindowPos4svMESA Wm3glWindowPos4svMESA;
#define glWindowPos4svMESA Wm3glWindowPos4svMESA
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_EXT_texture_compression_s3tc;
WM3_EXTERN int Wm3NumFunctions_GL_EXT_texture_compression_s3tc;
#ifndef GL_EXT_texture_compression_s3tc
#define GL_EXT_texture_compression_s3tc
#define WM3_DEFINED_GL_EXT_texture_compression_s3tc
#define GL_COMPRESSED_RGB_S3TC_DXT1_EXT   0x83F0
#define GL_COMPRESSED_RGBA_S3TC_DXT1_EXT  0x83F1
#define GL_COMPRESSED_RGBA_S3TC_DXT3_EXT  0x83F2
#define GL_COMPRESSED_RGBA_S3TC_DXT5_EXT  0x83F3
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_IBM_cull_vertex;
WM3_EXTERN int Wm3NumFunctions_GL_IBM_cull_vertex;
#ifndef GL_IBM_cull_vertex
#define GL_IBM_cull_vertex
#define WM3_DEFINED_GL_IBM_cull_vertex
#define GL_CULL_VERTEX_IBM                103050
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_IBM_multimode_draw_arrays;
WM3_EXTERN int Wm3NumFunctions_GL_IBM_multimode_draw_arrays;
#ifndef GL_IBM_multimode_draw_arrays
#define GL_IBM_multimode_draw_arrays
#define WM3_DEFINED_GL_IBM_multimode_draw_arrays

typedef void (APIENTRY* pfn_glMultiModeDrawArraysIBM) (const GLenum*, const GLint*, const GLsizei*, GLsizei, GLint);
WM3_EXTERN pfn_glMultiModeDrawArraysIBM Wm3glMultiModeDrawArraysIBM;
#define glMultiModeDrawArraysIBM Wm3glMultiModeDrawArraysIBM

typedef void (APIENTRY* pfn_glMultiModeDrawElementsIBM) (const GLenum*, const GLsizei*, GLenum, const GLvoid* const*, GLsizei, GLint);
WM3_EXTERN pfn_glMultiModeDrawElementsIBM Wm3glMultiModeDrawElementsIBM;
#define glMultiModeDrawElementsIBM Wm3glMultiModeDrawElementsIBM
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_IBM_vertex_array_lists;
WM3_EXTERN int Wm3NumFunctions_GL_IBM_vertex_array_lists;
#ifndef GL_IBM_vertex_array_lists
#define GL_IBM_vertex_array_lists
#define WM3_DEFINED_GL_IBM_vertex_array_lists
#define GL_VERTEX_ARRAY_LIST_IBM                    103070
#define GL_NORMAL_ARRAY_LIST_IBM                    103071
#define GL_COLOR_ARRAY_LIST_IBM                     103072
#define GL_INDEX_ARRAY_LIST_IBM                     103073
#define GL_TEXTURE_COORD_ARRAY_LIST_IBM             103074
#define GL_EDGE_FLAG_ARRAY_LIST_IBM                 103075
#define GL_FOG_COORDINATE_ARRAY_LIST_IBM            103076
#define GL_SECONDARY_COLOR_ARRAY_LIST_IBM           103077
#define GL_VERTEX_ARRAY_LIST_STRIDE_IBM             103080
#define GL_NORMAL_ARRAY_LIST_STRIDE_IBM             103081
#define GL_COLOR_ARRAY_LIST_STRIDE_IBM              103082
#define GL_INDEX_ARRAY_LIST_STRIDE_IBM              103083
#define GL_TEXTURE_COORD_ARRAY_LIST_STRIDE_IBM      103084
#define GL_EDGE_FLAG_ARRAY_LIST_STRIDE_IBM          103085
#define GL_FOG_COORDINATE_ARRAY_LIST_STRIDE_IBM     103086
#define GL_SECONDARY_COLOR_ARRAY_LIST_STRIDE_IBM    103087

typedef void (APIENTRY* pfn_glColorPointerListIBM) (GLint, GLenum, GLint, const GLvoid**, GLint);
WM3_EXTERN pfn_glColorPointerListIBM Wm3glColorPointerListIBM;
#define glColorPointerListIBM Wm3glColorPointerListIBM

typedef void (APIENTRY* pfn_glSecondaryColorPointerListIBM) (GLint, GLenum, GLint, const GLvoid**, GLint);
WM3_EXTERN pfn_glSecondaryColorPointerListIBM Wm3glSecondaryColorPointerListIBM;
#define glSecondaryColorPointerListIBM Wm3glSecondaryColorPointerListIBM

typedef void (APIENTRY* pfn_glEdgeFlagPointerListIBM) (GLint, const GLboolean**, GLint);
WM3_EXTERN pfn_glEdgeFlagPointerListIBM Wm3glEdgeFlagPointerListIBM;
#define glEdgeFlagPointerListIBM Wm3glEdgeFlagPointerListIBM

typedef void (APIENTRY* pfn_glFogCoordPointerListIBM) (GLenum, GLint, const GLvoid**, GLint);
WM3_EXTERN pfn_glFogCoordPointerListIBM Wm3glFogCoordPointerListIBM;
#define glFogCoordPointerListIBM Wm3glFogCoordPointerListIBM

typedef void (APIENTRY* pfn_glIndexPointerListIBM) (GLenum, GLint, const GLvoid**, GLint);
WM3_EXTERN pfn_glIndexPointerListIBM Wm3glIndexPointerListIBM;
#define glIndexPointerListIBM Wm3glIndexPointerListIBM

typedef void (APIENTRY* pfn_glNormalPointerListIBM) (GLenum, GLint, const GLvoid**, GLint);
WM3_EXTERN pfn_glNormalPointerListIBM Wm3glNormalPointerListIBM;
#define glNormalPointerListIBM Wm3glNormalPointerListIBM

typedef void (APIENTRY* pfn_glTexCoordPointerListIBM) (GLint, GLenum, GLint, const GLvoid**, GLint);
WM3_EXTERN pfn_glTexCoordPointerListIBM Wm3glTexCoordPointerListIBM;
#define glTexCoordPointerListIBM Wm3glTexCoordPointerListIBM

typedef void (APIENTRY* pfn_glVertexPointerListIBM) (GLint, GLenum, GLint, const GLvoid**, GLint);
WM3_EXTERN pfn_glVertexPointerListIBM Wm3glVertexPointerListIBM;
#define glVertexPointerListIBM Wm3glVertexPointerListIBM
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_SGIX_subsample;
WM3_EXTERN int Wm3NumFunctions_GL_SGIX_subsample;
#ifndef GL_SGIX_subsample
#define GL_SGIX_subsample
#define WM3_DEFINED_GL_SGIX_subsample
#define GL_PACK_SUBSAMPLE_RATE_SGIX       0x85A0
#define GL_UNPACK_SUBSAMPLE_RATE_SGIX     0x85A1
#define GL_PIXEL_SUBSAMPLE_4444_SGIX      0x85A2
#define GL_PIXEL_SUBSAMPLE_2424_SGIX      0x85A3
#define GL_PIXEL_SUBSAMPLE_4242_SGIX      0x85A4
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_SGIX_ycrcb_subsample;
WM3_EXTERN int Wm3NumFunctions_GL_SGIX_ycrcb_subsample;
#ifndef GL_SGIX_ycrcb_subsample
#define GL_SGIX_ycrcb_subsample
#define WM3_DEFINED_GL_SGIX_ycrcb_subsample
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_SGIX_ycrcba;
WM3_EXTERN int Wm3NumFunctions_GL_SGIX_ycrcba;
#ifndef GL_SGIX_ycrcba
#define GL_SGIX_ycrcba
#define WM3_DEFINED_GL_SGIX_ycrcba
#define GL_YCRCB_SGIX                     0x8318
#define GL_YCRCBA_SGIX                    0x8319
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_SGIX_depth_pass_instrument;
WM3_EXTERN int Wm3NumFunctions_GL_SGIX_depth_pass_instrument;
#ifndef GL_SGIX_depth_pass_instrument
#define GL_SGIX_depth_pass_instrument
#define WM3_DEFINED_GL_SGIX_depth_pass_instrument
#define GL_DEPTH_PASS_INSTRUMENT_SGIX     0x8310
#define GL_DEPTH_PASS_INSTRUMENT_COUNTERS_SGIX 0x8311
#define GL_DEPTH_PASS_INSTRUMENT_MAX_SGIX 0x8312
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_3DFX_texture_compression_FXT1;
WM3_EXTERN int Wm3NumFunctions_GL_3DFX_texture_compression_FXT1;
#ifndef GL_3DFX_texture_compression_FXT1
#define GL_3DFX_texture_compression_FXT1
#define WM3_DEFINED_GL_3DFX_texture_compression_FXT1
#define GL_COMPRESSED_RGB_FXT1_3DFX       0x86B0
#define GL_COMPRESSED_RGBA_FXT1_3DFX      0x86B1
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_3DFX_multisample;
WM3_EXTERN int Wm3NumFunctions_GL_3DFX_multisample;
#ifndef GL_3DFX_multisample
#define GL_3DFX_multisample
#define WM3_DEFINED_GL_3DFX_multisample
#define GL_MULTISAMPLE_3DFX               0x86B2
#define GL_SAMPLE_BUFFERS_3DFX            0x86B3
#define GL_SAMPLES_3DFX                   0x86B4
#define GL_MULTISAMPLE_BIT_3DFX           0x20000000
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_3DFX_tbuffer;
WM3_EXTERN int Wm3NumFunctions_GL_3DFX_tbuffer;
#ifndef GL_3DFX_tbuffer
#define GL_3DFX_tbuffer
#define WM3_DEFINED_GL_3DFX_tbuffer

typedef void (APIENTRY* pfn_glTbufferMask3DFX) (GLuint);
WM3_EXTERN pfn_glTbufferMask3DFX Wm3glTbufferMask3DFX;
#define glTbufferMask3DFX Wm3glTbufferMask3DFX
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_EXT_multisample;
WM3_EXTERN int Wm3NumFunctions_GL_EXT_multisample;
#ifndef GL_EXT_multisample
#define GL_EXT_multisample
#define WM3_DEFINED_GL_EXT_multisample
#define GL_MULTISAMPLE_EXT                0x809D
#define GL_SAMPLE_ALPHA_TO_MASK_EXT       0x809E
#define GL_SAMPLE_ALPHA_TO_ONE_EXT        0x809F
#define GL_SAMPLE_MASK_EXT                0x80A0
#define GL_1PASS_EXT                      0x80A1
#define GL_2PASS_0_EXT                    0x80A2
#define GL_2PASS_1_EXT                    0x80A3
#define GL_4PASS_0_EXT                    0x80A4
#define GL_4PASS_1_EXT                    0x80A5
#define GL_4PASS_2_EXT                    0x80A6
#define GL_4PASS_3_EXT                    0x80A7
#define GL_SAMPLE_BUFFERS_EXT             0x80A8
#define GL_SAMPLES_EXT                    0x80A9
#define GL_SAMPLE_MASK_VALUE_EXT          0x80AA
#define GL_SAMPLE_MASK_INVERT_EXT         0x80AB
#define GL_SAMPLE_PATTERN_EXT             0x80AC
#define GL_MULTISAMPLE_BIT_EXT            0x20000000

typedef void (APIENTRY* pfn_glSampleMaskEXT) (GLclampf, GLboolean);
WM3_EXTERN pfn_glSampleMaskEXT Wm3glSampleMaskEXT;
#define glSampleMaskEXT Wm3glSampleMaskEXT

typedef void (APIENTRY* pfn_glSamplePatternEXT) (GLenum);
WM3_EXTERN pfn_glSamplePatternEXT Wm3glSamplePatternEXT;
#define glSamplePatternEXT Wm3glSamplePatternEXT
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_SGIX_vertex_preclip;
WM3_EXTERN int Wm3NumFunctions_GL_SGIX_vertex_preclip;
#ifndef GL_SGIX_vertex_preclip
#define GL_SGIX_vertex_preclip
#define WM3_DEFINED_GL_SGIX_vertex_preclip
#define GL_VERTEX_PRECLIP_SGIX            0x83EE
#define GL_VERTEX_PRECLIP_HINT_SGIX       0x83EF
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_SGIX_convolution_accuracy;
WM3_EXTERN int Wm3NumFunctions_GL_SGIX_convolution_accuracy;
#ifndef GL_SGIX_convolution_accuracy
#define GL_SGIX_convolution_accuracy
#define WM3_DEFINED_GL_SGIX_convolution_accuracy
#define GL_CONVOLUTION_HINT_SGIX          0x8316
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_SGIX_resample;
WM3_EXTERN int Wm3NumFunctions_GL_SGIX_resample;
#ifndef GL_SGIX_resample
#define GL_SGIX_resample
#define WM3_DEFINED_GL_SGIX_resample
#define GL_PACK_RESAMPLE_SGIX             0x842C
#define GL_UNPACK_RESAMPLE_SGIX           0x842D
#define GL_RESAMPLE_REPLICATE_SGIX        0x842E
#define GL_RESAMPLE_ZERO_FILL_SGIX        0x842F
#define GL_RESAMPLE_DECIMATE_SGIX         0x8430
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_SGIS_point_line_texgen;
WM3_EXTERN int Wm3NumFunctions_GL_SGIS_point_line_texgen;
#ifndef GL_SGIS_point_line_texgen
#define GL_SGIS_point_line_texgen
#define WM3_DEFINED_GL_SGIS_point_line_texgen
#define GL_EYE_DISTANCE_TO_POINT_SGIS     0x81F0
#define GL_OBJECT_DISTANCE_TO_POINT_SGIS  0x81F1
#define GL_EYE_DISTANCE_TO_LINE_SGIS      0x81F2
#define GL_OBJECT_DISTANCE_TO_LINE_SGIS   0x81F3
#define GL_EYE_POINT_SGIS                 0x81F4
#define GL_OBJECT_POINT_SGIS              0x81F5
#define GL_EYE_LINE_SGIS                  0x81F6
#define GL_OBJECT_LINE_SGIS               0x81F7
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_SGIS_texture_color_mask;
WM3_EXTERN int Wm3NumFunctions_GL_SGIS_texture_color_mask;
#ifndef GL_SGIS_texture_color_mask
#define GL_SGIS_texture_color_mask
#define WM3_DEFINED_GL_SGIS_texture_color_mask
#define GL_TEXTURE_COLOR_WRITEMASK_SGIS   0x81EF

typedef void (APIENTRY* pfn_glTextureColorMaskSGIS) (GLboolean, GLboolean, GLboolean, GLboolean);
WM3_EXTERN pfn_glTextureColorMaskSGIS Wm3glTextureColorMaskSGIS;
#define glTextureColorMaskSGIS Wm3glTextureColorMaskSGIS
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_SGIX_igloo_interface;
WM3_EXTERN int Wm3NumFunctions_GL_SGIX_igloo_interface;
#ifndef GL_SGIX_igloo_interface
#define GL_SGIX_igloo_interface
#define WM3_DEFINED_GL_SGIX_igloo_interface

typedef void (APIENTRY* pfn_glIglooInterfaceSGIX) (GLenum, const GLvoid*);
WM3_EXTERN pfn_glIglooInterfaceSGIX Wm3glIglooInterfaceSGIX;
#define glIglooInterfaceSGIX Wm3glIglooInterfaceSGIX
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_EXT_texture_env_dot3;
WM3_EXTERN int Wm3NumFunctions_GL_EXT_texture_env_dot3;
#ifndef GL_EXT_texture_env_dot3
#define GL_EXT_texture_env_dot3
#define WM3_DEFINED_GL_EXT_texture_env_dot3
#define GL_DOT3_RGB_EXT                   0x8740
#define GL_DOT3_RGBA_EXT                  0x8741
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_ATI_texture_mirror_once;
WM3_EXTERN int Wm3NumFunctions_GL_ATI_texture_mirror_once;
#ifndef GL_ATI_texture_mirror_once
#define GL_ATI_texture_mirror_once
#define WM3_DEFINED_GL_ATI_texture_mirror_once
#define GL_MIRROR_CLAMP_ATI               0x8742
#define GL_MIRROR_CLAMP_TO_EDGE_ATI       0x8743
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_NV_fence;
WM3_EXTERN int Wm3NumFunctions_GL_NV_fence;
#ifndef GL_NV_fence
#define GL_NV_fence
#define WM3_DEFINED_GL_NV_fence
#define GL_ALL_COMPLETED_NV               0x84F2
#define GL_FENCE_STATUS_NV                0x84F3
#define GL_FENCE_CONDITION_NV             0x84F4

typedef void (APIENTRY* pfn_glDeleteFencesNV) (GLsizei, const GLuint*);
WM3_EXTERN pfn_glDeleteFencesNV Wm3glDeleteFencesNV;
#define glDeleteFencesNV Wm3glDeleteFencesNV

typedef void (APIENTRY* pfn_glGenFencesNV) (GLsizei, GLuint*);
WM3_EXTERN pfn_glGenFencesNV Wm3glGenFencesNV;
#define glGenFencesNV Wm3glGenFencesNV

typedef GLboolean (APIENTRY* pfn_glIsFenceNV) (GLuint);
WM3_EXTERN pfn_glIsFenceNV Wm3glIsFenceNV;
#define glIsFenceNV Wm3glIsFenceNV

typedef GLboolean (APIENTRY* pfn_glTestFenceNV) (GLuint);
WM3_EXTERN pfn_glTestFenceNV Wm3glTestFenceNV;
#define glTestFenceNV Wm3glTestFenceNV

typedef void (APIENTRY* pfn_glGetFenceivNV) (GLuint, GLenum, GLint*);
WM3_EXTERN pfn_glGetFenceivNV Wm3glGetFenceivNV;
#define glGetFenceivNV Wm3glGetFenceivNV

typedef void (APIENTRY* pfn_glFinishFenceNV) (GLuint);
WM3_EXTERN pfn_glFinishFenceNV Wm3glFinishFenceNV;
#define glFinishFenceNV Wm3glFinishFenceNV

typedef void (APIENTRY* pfn_glSetFenceNV) (GLuint, GLenum);
WM3_EXTERN pfn_glSetFenceNV Wm3glSetFenceNV;
#define glSetFenceNV Wm3glSetFenceNV
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_IBM_texture_mirrored_repeat;
WM3_EXTERN int Wm3NumFunctions_GL_IBM_texture_mirrored_repeat;
#ifndef GL_IBM_texture_mirrored_repeat
#define GL_IBM_texture_mirrored_repeat
#define WM3_DEFINED_GL_IBM_texture_mirrored_repeat
#define GL_MIRRORED_REPEAT_IBM            0x8370
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_NV_evaluators;
WM3_EXTERN int Wm3NumFunctions_GL_NV_evaluators;
#ifndef GL_NV_evaluators
#define GL_NV_evaluators
#define WM3_DEFINED_GL_NV_evaluators
#define GL_EVAL_2D_NV                       0x86C0
#define GL_EVAL_TRIANGULAR_2D_NV            0x86C1
#define GL_MAP_TESSELLATION_NV              0x86C2
#define GL_MAP_ATTRIB_U_ORDER_NV            0x86C3
#define GL_MAP_ATTRIB_V_ORDER_NV            0x86C4
#define GL_EVAL_FRACTIONAL_TESSELLATION_NV  0x86C5
#define GL_EVAL_VERTEX_ATTRIB0_NV           0x86C6
#define GL_EVAL_VERTEX_ATTRIB1_NV           0x86C7
#define GL_EVAL_VERTEX_ATTRIB2_NV           0x86C8
#define GL_EVAL_VERTEX_ATTRIB3_NV           0x86C9
#define GL_EVAL_VERTEX_ATTRIB4_NV           0x86CA
#define GL_EVAL_VERTEX_ATTRIB5_NV           0x86CB
#define GL_EVAL_VERTEX_ATTRIB6_NV           0x86CC
#define GL_EVAL_VERTEX_ATTRIB7_NV           0x86CD
#define GL_EVAL_VERTEX_ATTRIB8_NV           0x86CE
#define GL_EVAL_VERTEX_ATTRIB9_NV           0x86CF
#define GL_EVAL_VERTEX_ATTRIB10_NV          0x86D0
#define GL_EVAL_VERTEX_ATTRIB11_NV          0x86D1
#define GL_EVAL_VERTEX_ATTRIB12_NV          0x86D2
#define GL_EVAL_VERTEX_ATTRIB13_NV          0x86D3
#define GL_EVAL_VERTEX_ATTRIB14_NV          0x86D4
#define GL_EVAL_VERTEX_ATTRIB15_NV          0x86D5
#define GL_MAX_MAP_TESSELLATION_NV          0x86D6
#define GL_MAX_RATIONAL_EVAL_ORDER_NV       0x86D7

typedef void (APIENTRY* pfn_glMapControlPointsNV) (GLenum, GLuint, GLenum, GLsizei, GLsizei, GLint, GLint, GLboolean, const GLvoid*);
WM3_EXTERN pfn_glMapControlPointsNV Wm3glMapControlPointsNV;
#define glMapControlPointsNV Wm3glMapControlPointsNV

typedef void (APIENTRY* pfn_glMapParameterivNV) (GLenum, GLenum, const GLint*);
WM3_EXTERN pfn_glMapParameterivNV Wm3glMapParameterivNV;
#define glMapParameterivNV Wm3glMapParameterivNV

typedef void (APIENTRY* pfn_glMapParameterfvNV) (GLenum, GLenum, const GLfloat*);
WM3_EXTERN pfn_glMapParameterfvNV Wm3glMapParameterfvNV;
#define glMapParameterfvNV Wm3glMapParameterfvNV

typedef void (APIENTRY* pfn_glGetMapControlPointsNV) (GLenum, GLuint, GLenum, GLsizei, GLsizei, GLboolean, GLvoid*);
WM3_EXTERN pfn_glGetMapControlPointsNV Wm3glGetMapControlPointsNV;
#define glGetMapControlPointsNV Wm3glGetMapControlPointsNV

typedef void (APIENTRY* pfn_glGetMapParameterivNV) (GLenum, GLenum, GLint*);
WM3_EXTERN pfn_glGetMapParameterivNV Wm3glGetMapParameterivNV;
#define glGetMapParameterivNV Wm3glGetMapParameterivNV

typedef void (APIENTRY* pfn_glGetMapParameterfvNV) (GLenum, GLenum, GLfloat*);
WM3_EXTERN pfn_glGetMapParameterfvNV Wm3glGetMapParameterfvNV;
#define glGetMapParameterfvNV Wm3glGetMapParameterfvNV

typedef void (APIENTRY* pfn_glGetMapAttribParameterivNV) (GLenum, GLuint, GLenum, GLint*);
WM3_EXTERN pfn_glGetMapAttribParameterivNV Wm3glGetMapAttribParameterivNV;
#define glGetMapAttribParameterivNV Wm3glGetMapAttribParameterivNV

typedef void (APIENTRY* pfn_glGetMapAttribParameterfvNV) (GLenum, GLuint, GLenum, GLfloat*);
WM3_EXTERN pfn_glGetMapAttribParameterfvNV Wm3glGetMapAttribParameterfvNV;
#define glGetMapAttribParameterfvNV Wm3glGetMapAttribParameterfvNV

typedef void (APIENTRY* pfn_glEvalMapsNV) (GLenum, GLenum);
WM3_EXTERN pfn_glEvalMapsNV Wm3glEvalMapsNV;
#define glEvalMapsNV Wm3glEvalMapsNV
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_NV_packed_depth_stencil;
WM3_EXTERN int Wm3NumFunctions_GL_NV_packed_depth_stencil;
#ifndef GL_NV_packed_depth_stencil
#define GL_NV_packed_depth_stencil
#define WM3_DEFINED_GL_NV_packed_depth_stencil
#define GL_DEPTH_STENCIL_NV               0x84F9
#define GL_UNSIGNED_INT_24_8_NV           0x84FA
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_NV_register_combiners2;
WM3_EXTERN int Wm3NumFunctions_GL_NV_register_combiners2;
#ifndef GL_NV_register_combiners2
#define GL_NV_register_combiners2
#define WM3_DEFINED_GL_NV_register_combiners2
#define GL_PER_STAGE_CONSTANTS_NV         0x8535

typedef void (APIENTRY* pfn_glCombinerStageParameterfvNV) (GLenum, GLenum, const GLfloat*);
WM3_EXTERN pfn_glCombinerStageParameterfvNV Wm3glCombinerStageParameterfvNV;
#define glCombinerStageParameterfvNV Wm3glCombinerStageParameterfvNV

typedef void (APIENTRY* pfn_glGetCombinerStageParameterfvNV) (GLenum, GLenum, GLfloat*);
WM3_EXTERN pfn_glGetCombinerStageParameterfvNV Wm3glGetCombinerStageParameterfvNV;
#define glGetCombinerStageParameterfvNV Wm3glGetCombinerStageParameterfvNV
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_NV_texture_compression_vtc;
WM3_EXTERN int Wm3NumFunctions_GL_NV_texture_compression_vtc;
#ifndef GL_NV_texture_compression_vtc
#define GL_NV_texture_compression_vtc
#define WM3_DEFINED_GL_NV_texture_compression_vtc
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_NV_texture_rectangle;
WM3_EXTERN int Wm3NumFunctions_GL_NV_texture_rectangle;
#ifndef GL_NV_texture_rectangle
#define GL_NV_texture_rectangle
#define WM3_DEFINED_GL_NV_texture_rectangle
#define GL_TEXTURE_RECTANGLE_NV           0x84F5
#define GL_TEXTURE_BINDING_RECTANGLE_NV   0x84F6
#define GL_PROXY_TEXTURE_RECTANGLE_NV     0x84F7
#define GL_MAX_RECTANGLE_TEXTURE_SIZE_NV  0x84F8
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_NV_texture_shader;
WM3_EXTERN int Wm3NumFunctions_GL_NV_texture_shader;
#ifndef GL_NV_texture_shader
#define GL_NV_texture_shader
#define WM3_DEFINED_GL_NV_texture_shader
#define GL_OFFSET_TEXTURE_RECTANGLE_NV                  0x864C
#define GL_OFFSET_TEXTURE_RECTANGLE_SCALE_NV            0x864D
#define GL_DOT_PRODUCT_TEXTURE_RECTANGLE_NV             0x864E
#define GL_RGBA_UNSIGNED_DOT_PRODUCT_MAPPING_NV         0x86D9
#define GL_UNSIGNED_INT_S8_S8_8_8_NV                    0x86DA
#define GL_UNSIGNED_INT_8_8_S8_S8_REV_NV                0x86DB
#define GL_DSDT_MAG_INTENSITY_NV                        0x86DC
#define GL_SHADER_CONSISTENT_NV                         0x86DD
#define GL_TEXTURE_SHADER_NV                            0x86DE
#define GL_SHADER_OPERATION_NV                          0x86DF
#define GL_CULL_MODES_NV                                0x86E0
#define GL_OFFSET_TEXTURE_MATRIX_NV                     0x86E1
#define GL_OFFSET_TEXTURE_SCALE_NV                      0x86E2
#define GL_OFFSET_TEXTURE_BIAS_NV                       0x86E3
#define GL_OFFSET_TEXTURE_2D_MATRIX_NV                  GL_OFFSET_TEXTURE_MATRIX_NV
#define GL_OFFSET_TEXTURE_2D_SCALE_NV                   GL_OFFSET_TEXTURE_SCALE_NV
#define GL_OFFSET_TEXTURE_2D_BIAS_NV                    GL_OFFSET_TEXTURE_BIAS_NV
#define GL_PREVIOUS_TEXTURE_INPUT_NV                    0x86E4
#define GL_CONST_EYE_NV                                 0x86E5
#define GL_PASS_THROUGH_NV                              0x86E6
#define GL_CULL_FRAGMENT_NV                             0x86E7
#define GL_OFFSET_TEXTURE_2D_NV                         0x86E8
#define GL_DEPENDENT_AR_TEXTURE_2D_NV                   0x86E9
#define GL_DEPENDENT_GB_TEXTURE_2D_NV                   0x86EA
#define GL_DOT_PRODUCT_NV                               0x86EC
#define GL_DOT_PRODUCT_DEPTH_REPLACE_NV                 0x86ED
#define GL_DOT_PRODUCT_TEXTURE_2D_NV                    0x86EE
#define GL_DOT_PRODUCT_TEXTURE_CUBE_MAP_NV              0x86F0
#define GL_DOT_PRODUCT_DIFFUSE_CUBE_MAP_NV              0x86F1
#define GL_DOT_PRODUCT_REFLECT_CUBE_MAP_NV              0x86F2
#define GL_DOT_PRODUCT_CONST_EYE_REFLECT_CUBE_MAP_NV    0x86F3
#define GL_HILO_NV                                      0x86F4
#define GL_DSDT_NV                                      0x86F5
#define GL_DSDT_MAG_NV                                  0x86F6
#define GL_DSDT_MAG_VIB_NV                              0x86F7
#define GL_HILO16_NV                                    0x86F8
#define GL_SIGNED_HILO_NV                               0x86F9
#define GL_SIGNED_HILO16_NV                             0x86FA
#define GL_SIGNED_RGBA_NV                               0x86FB
#define GL_SIGNED_RGBA8_NV                              0x86FC
#define GL_SIGNED_RGB_NV                                0x86FE
#define GL_SIGNED_RGB8_NV                               0x86FF
#define GL_SIGNED_LUMINANCE_NV                          0x8701
#define GL_SIGNED_LUMINANCE8_NV                         0x8702
#define GL_SIGNED_LUMINANCE_ALPHA_NV                    0x8703
#define GL_SIGNED_LUMINANCE8_ALPHA8_NV                  0x8704
#define GL_SIGNED_ALPHA_NV                              0x8705
#define GL_SIGNED_ALPHA8_NV                             0x8706
#define GL_SIGNED_INTENSITY_NV                          0x8707
#define GL_SIGNED_INTENSITY8_NV                         0x8708
#define GL_DSDT8_NV                                     0x8709
#define GL_DSDT8_MAG8_NV                                0x870A
#define GL_DSDT8_MAG8_INTENSITY8_NV                     0x870B
#define GL_SIGNED_RGB_UNSIGNED_ALPHA_NV                 0x870C
#define GL_SIGNED_RGB8_UNSIGNED_ALPHA8_NV               0x870D
#define GL_HI_SCALE_NV                                  0x870E
#define GL_LO_SCALE_NV                                  0x870F
#define GL_DS_SCALE_NV                                  0x8710
#define GL_DT_SCALE_NV                                  0x8711
#define GL_MAGNITUDE_SCALE_NV                           0x8712
#define GL_VIBRANCE_SCALE_NV                            0x8713
#define GL_HI_BIAS_NV                                   0x8714
#define GL_LO_BIAS_NV                                   0x8715
#define GL_DS_BIAS_NV                                   0x8716
#define GL_DT_BIAS_NV                                   0x8717
#define GL_MAGNITUDE_BIAS_NV                            0x8718
#define GL_VIBRANCE_BIAS_NV                             0x8719
#define GL_TEXTURE_BORDER_VALUES_NV                     0x871A
#define GL_TEXTURE_HI_SIZE_NV                           0x871B
#define GL_TEXTURE_LO_SIZE_NV                           0x871C
#define GL_TEXTURE_DS_SIZE_NV                           0x871D
#define GL_TEXTURE_DT_SIZE_NV                           0x871E
#define GL_TEXTURE_MAG_SIZE_NV                          0x871F
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_NV_texture_shader2;
WM3_EXTERN int Wm3NumFunctions_GL_NV_texture_shader2;
#ifndef GL_NV_texture_shader2
#define GL_NV_texture_shader2
#define WM3_DEFINED_GL_NV_texture_shader2
#define GL_DOT_PRODUCT_TEXTURE_3D_NV      0x86EF
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_NV_vertex_array_range2;
WM3_EXTERN int Wm3NumFunctions_GL_NV_vertex_array_range2;
#ifndef GL_NV_vertex_array_range2
#define GL_NV_vertex_array_range2
#define WM3_DEFINED_GL_NV_vertex_array_range2
#define GL_VERTEX_ARRAY_RANGE_WITHOUT_FLUSH_NV 0x8533
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_NV_vertex_program;
WM3_EXTERN int Wm3NumFunctions_GL_NV_vertex_program;
#ifndef GL_NV_vertex_program
#define GL_NV_vertex_program
#define WM3_DEFINED_GL_NV_vertex_program
#define GL_VERTEX_PROGRAM_NV                0x8620
#define GL_VERTEX_STATE_PROGRAM_NV          0x8621
#define GL_ATTRIB_ARRAY_SIZE_NV             0x8623
#define GL_ATTRIB_ARRAY_STRIDE_NV           0x8624
#define GL_ATTRIB_ARRAY_TYPE_NV             0x8625
#define GL_CURRENT_ATTRIB_NV                0x8626
#define GL_PROGRAM_LENGTH_NV                0x8627
#define GL_PROGRAM_STRING_NV                0x8628
#define GL_MODELVIEW_PROJECTION_NV          0x8629
#define GL_IDENTITY_NV                      0x862A
#define GL_INVERSE_NV                       0x862B
#define GL_TRANSPOSE_NV                     0x862C
#define GL_INVERSE_TRANSPOSE_NV             0x862D
#define GL_MAX_TRACK_MATRIX_STACK_DEPTH_NV  0x862E
#define GL_MAX_TRACK_MATRICES_NV            0x862F
#define GL_MATRIX0_NV                       0x8630
#define GL_MATRIX1_NV                       0x8631
#define GL_MATRIX2_NV                       0x8632
#define GL_MATRIX3_NV                       0x8633
#define GL_MATRIX4_NV                       0x8634
#define GL_MATRIX5_NV                       0x8635
#define GL_MATRIX6_NV                       0x8636
#define GL_MATRIX7_NV                       0x8637
#define GL_CURRENT_MATRIX_STACK_DEPTH_NV    0x8640
#define GL_CURRENT_MATRIX_NV                0x8641
#define GL_VERTEX_PROGRAM_POINT_SIZE_NV     0x8642
#define GL_VERTEX_PROGRAM_TWO_SIDE_NV       0x8643
#define GL_PROGRAM_PARAMETER_NV             0x8644
#define GL_ATTRIB_ARRAY_POINTER_NV          0x8645
#define GL_PROGRAM_TARGET_NV                0x8646
#define GL_PROGRAM_RESIDENT_NV              0x8647
#define GL_TRACK_MATRIX_NV                  0x8648
#define GL_TRACK_MATRIX_TRANSFORM_NV        0x8649
#define GL_VERTEX_PROGRAM_BINDING_NV        0x864A
#define GL_PROGRAM_ERROR_POSITION_NV        0x864B
#define GL_VERTEX_ATTRIB_ARRAY0_NV          0x8650
#define GL_VERTEX_ATTRIB_ARRAY1_NV          0x8651
#define GL_VERTEX_ATTRIB_ARRAY2_NV          0x8652
#define GL_VERTEX_ATTRIB_ARRAY3_NV          0x8653
#define GL_VERTEX_ATTRIB_ARRAY4_NV          0x8654
#define GL_VERTEX_ATTRIB_ARRAY5_NV          0x8655
#define GL_VERTEX_ATTRIB_ARRAY6_NV          0x8656
#define GL_VERTEX_ATTRIB_ARRAY7_NV          0x8657
#define GL_VERTEX_ATTRIB_ARRAY8_NV          0x8658
#define GL_VERTEX_ATTRIB_ARRAY9_NV          0x8659
#define GL_VERTEX_ATTRIB_ARRAY10_NV         0x865A
#define GL_VERTEX_ATTRIB_ARRAY11_NV         0x865B
#define GL_VERTEX_ATTRIB_ARRAY12_NV         0x865C
#define GL_VERTEX_ATTRIB_ARRAY13_NV         0x865D
#define GL_VERTEX_ATTRIB_ARRAY14_NV         0x865E
#define GL_VERTEX_ATTRIB_ARRAY15_NV         0x865F
#define GL_MAP1_VERTEX_ATTRIB0_4_NV         0x8660
#define GL_MAP1_VERTEX_ATTRIB1_4_NV         0x8661
#define GL_MAP1_VERTEX_ATTRIB2_4_NV         0x8662
#define GL_MAP1_VERTEX_ATTRIB3_4_NV         0x8663
#define GL_MAP1_VERTEX_ATTRIB4_4_NV         0x8664
#define GL_MAP1_VERTEX_ATTRIB5_4_NV         0x8665
#define GL_MAP1_VERTEX_ATTRIB6_4_NV         0x8666
#define GL_MAP1_VERTEX_ATTRIB7_4_NV         0x8667
#define GL_MAP1_VERTEX_ATTRIB8_4_NV         0x8668
#define GL_MAP1_VERTEX_ATTRIB9_4_NV         0x8669
#define GL_MAP1_VERTEX_ATTRIB10_4_NV        0x866A
#define GL_MAP1_VERTEX_ATTRIB11_4_NV        0x866B
#define GL_MAP1_VERTEX_ATTRIB12_4_NV        0x866C
#define GL_MAP1_VERTEX_ATTRIB13_4_NV        0x866D
#define GL_MAP1_VERTEX_ATTRIB14_4_NV        0x866E
#define GL_MAP1_VERTEX_ATTRIB15_4_NV        0x866F
#define GL_MAP2_VERTEX_ATTRIB0_4_NV         0x8670
#define GL_MAP2_VERTEX_ATTRIB1_4_NV         0x8671
#define GL_MAP2_VERTEX_ATTRIB2_4_NV         0x8672
#define GL_MAP2_VERTEX_ATTRIB3_4_NV         0x8673
#define GL_MAP2_VERTEX_ATTRIB4_4_NV         0x8674
#define GL_MAP2_VERTEX_ATTRIB5_4_NV         0x8675
#define GL_MAP2_VERTEX_ATTRIB6_4_NV         0x8676
#define GL_MAP2_VERTEX_ATTRIB7_4_NV         0x8677
#define GL_MAP2_VERTEX_ATTRIB8_4_NV         0x8678
#define GL_MAP2_VERTEX_ATTRIB9_4_NV         0x8679
#define GL_MAP2_VERTEX_ATTRIB10_4_NV        0x867A
#define GL_MAP2_VERTEX_ATTRIB11_4_NV        0x867B
#define GL_MAP2_VERTEX_ATTRIB12_4_NV        0x867C
#define GL_MAP2_VERTEX_ATTRIB13_4_NV        0x867D
#define GL_MAP2_VERTEX_ATTRIB14_4_NV        0x867E
#define GL_MAP2_VERTEX_ATTRIB15_4_NV        0x867F

typedef GLboolean (APIENTRY* pfn_glAreProgramsResidentNV) (GLsizei, const GLuint*, GLboolean*);
WM3_EXTERN pfn_glAreProgramsResidentNV Wm3glAreProgramsResidentNV;
#define glAreProgramsResidentNV Wm3glAreProgramsResidentNV

typedef void (APIENTRY* pfn_glBindProgramNV) (GLenum, GLuint);
WM3_EXTERN pfn_glBindProgramNV Wm3glBindProgramNV;
#define glBindProgramNV Wm3glBindProgramNV

typedef void (APIENTRY* pfn_glDeleteProgramsNV) (GLsizei, const GLuint*);
WM3_EXTERN pfn_glDeleteProgramsNV Wm3glDeleteProgramsNV;
#define glDeleteProgramsNV Wm3glDeleteProgramsNV

typedef void (APIENTRY* pfn_glExecuteProgramNV) (GLenum, GLuint, const GLfloat*);
WM3_EXTERN pfn_glExecuteProgramNV Wm3glExecuteProgramNV;
#define glExecuteProgramNV Wm3glExecuteProgramNV

typedef void (APIENTRY* pfn_glGenProgramsNV) (GLsizei, GLuint*);
WM3_EXTERN pfn_glGenProgramsNV Wm3glGenProgramsNV;
#define glGenProgramsNV Wm3glGenProgramsNV

typedef void (APIENTRY* pfn_glGetProgramParameterdvNV) (GLenum, GLuint, GLenum, GLdouble*);
WM3_EXTERN pfn_glGetProgramParameterdvNV Wm3glGetProgramParameterdvNV;
#define glGetProgramParameterdvNV Wm3glGetProgramParameterdvNV

typedef void (APIENTRY* pfn_glGetProgramParameterfvNV) (GLenum, GLuint, GLenum, GLfloat*);
WM3_EXTERN pfn_glGetProgramParameterfvNV Wm3glGetProgramParameterfvNV;
#define glGetProgramParameterfvNV Wm3glGetProgramParameterfvNV

typedef void (APIENTRY* pfn_glGetProgramivNV) (GLuint, GLenum, GLint*);
WM3_EXTERN pfn_glGetProgramivNV Wm3glGetProgramivNV;
#define glGetProgramivNV Wm3glGetProgramivNV

typedef void (APIENTRY* pfn_glGetProgramStringNV) (GLuint, GLenum, GLubyte*);
WM3_EXTERN pfn_glGetProgramStringNV Wm3glGetProgramStringNV;
#define glGetProgramStringNV Wm3glGetProgramStringNV

typedef void (APIENTRY* pfn_glGetTrackMatrixivNV) (GLenum, GLuint, GLenum, GLint*);
WM3_EXTERN pfn_glGetTrackMatrixivNV Wm3glGetTrackMatrixivNV;
#define glGetTrackMatrixivNV Wm3glGetTrackMatrixivNV

typedef void (APIENTRY* pfn_glGetVertexAttribdvNV) (GLuint, GLenum, GLdouble*);
WM3_EXTERN pfn_glGetVertexAttribdvNV Wm3glGetVertexAttribdvNV;
#define glGetVertexAttribdvNV Wm3glGetVertexAttribdvNV

typedef void (APIENTRY* pfn_glGetVertexAttribfvNV) (GLuint, GLenum, GLfloat*);
WM3_EXTERN pfn_glGetVertexAttribfvNV Wm3glGetVertexAttribfvNV;
#define glGetVertexAttribfvNV Wm3glGetVertexAttribfvNV

typedef void (APIENTRY* pfn_glGetVertexAttribivNV) (GLuint, GLenum, GLint*);
WM3_EXTERN pfn_glGetVertexAttribivNV Wm3glGetVertexAttribivNV;
#define glGetVertexAttribivNV Wm3glGetVertexAttribivNV

typedef void (APIENTRY* pfn_glGetVertexAttribPointervNV) (GLuint, GLenum, GLvoid**);
WM3_EXTERN pfn_glGetVertexAttribPointervNV Wm3glGetVertexAttribPointervNV;
#define glGetVertexAttribPointervNV Wm3glGetVertexAttribPointervNV

typedef GLboolean (APIENTRY* pfn_glIsProgramNV) (GLuint);
WM3_EXTERN pfn_glIsProgramNV Wm3glIsProgramNV;
#define glIsProgramNV Wm3glIsProgramNV

typedef void (APIENTRY* pfn_glLoadProgramNV) (GLenum, GLuint, GLsizei, const GLubyte*);
WM3_EXTERN pfn_glLoadProgramNV Wm3glLoadProgramNV;
#define glLoadProgramNV Wm3glLoadProgramNV

typedef void (APIENTRY* pfn_glProgramParameter4dNV) (GLenum, GLuint, GLdouble, GLdouble, GLdouble, GLdouble);
WM3_EXTERN pfn_glProgramParameter4dNV Wm3glProgramParameter4dNV;
#define glProgramParameter4dNV Wm3glProgramParameter4dNV

typedef void (APIENTRY* pfn_glProgramParameter4dvNV) (GLenum, GLuint, const GLdouble*);
WM3_EXTERN pfn_glProgramParameter4dvNV Wm3glProgramParameter4dvNV;
#define glProgramParameter4dvNV Wm3glProgramParameter4dvNV

typedef void (APIENTRY* pfn_glProgramParameter4fNV) (GLenum, GLuint, GLfloat, GLfloat, GLfloat, GLfloat);
WM3_EXTERN pfn_glProgramParameter4fNV Wm3glProgramParameter4fNV;
#define glProgramParameter4fNV Wm3glProgramParameter4fNV

typedef void (APIENTRY* pfn_glProgramParameter4fvNV) (GLenum, GLuint, const GLfloat*);
WM3_EXTERN pfn_glProgramParameter4fvNV Wm3glProgramParameter4fvNV;
#define glProgramParameter4fvNV Wm3glProgramParameter4fvNV

typedef void (APIENTRY* pfn_glProgramParameters4dvNV) (GLenum, GLuint, GLuint, const GLdouble*);
WM3_EXTERN pfn_glProgramParameters4dvNV Wm3glProgramParameters4dvNV;
#define glProgramParameters4dvNV Wm3glProgramParameters4dvNV

typedef void (APIENTRY* pfn_glProgramParameters4fvNV) (GLenum, GLuint, GLuint, const GLfloat*);
WM3_EXTERN pfn_glProgramParameters4fvNV Wm3glProgramParameters4fvNV;
#define glProgramParameters4fvNV Wm3glProgramParameters4fvNV

typedef void (APIENTRY* pfn_glRequestResidentProgramsNV) (GLsizei, const GLuint*);
WM3_EXTERN pfn_glRequestResidentProgramsNV Wm3glRequestResidentProgramsNV;
#define glRequestResidentProgramsNV Wm3glRequestResidentProgramsNV

typedef void (APIENTRY* pfn_glTrackMatrixNV) (GLenum, GLuint, GLenum, GLenum);
WM3_EXTERN pfn_glTrackMatrixNV Wm3glTrackMatrixNV;
#define glTrackMatrixNV Wm3glTrackMatrixNV

typedef void (APIENTRY* pfn_glVertexAttribPointerNV) (GLuint, GLint, GLenum, GLsizei, const GLvoid*);
WM3_EXTERN pfn_glVertexAttribPointerNV Wm3glVertexAttribPointerNV;
#define glVertexAttribPointerNV Wm3glVertexAttribPointerNV

typedef void (APIENTRY* pfn_glVertexAttrib1dNV) (GLuint, GLdouble);
WM3_EXTERN pfn_glVertexAttrib1dNV Wm3glVertexAttrib1dNV;
#define glVertexAttrib1dNV Wm3glVertexAttrib1dNV

typedef void (APIENTRY* pfn_glVertexAttrib1dvNV) (GLuint, const GLdouble*);
WM3_EXTERN pfn_glVertexAttrib1dvNV Wm3glVertexAttrib1dvNV;
#define glVertexAttrib1dvNV Wm3glVertexAttrib1dvNV

typedef void (APIENTRY* pfn_glVertexAttrib1fNV) (GLuint, GLfloat);
WM3_EXTERN pfn_glVertexAttrib1fNV Wm3glVertexAttrib1fNV;
#define glVertexAttrib1fNV Wm3glVertexAttrib1fNV

typedef void (APIENTRY* pfn_glVertexAttrib1fvNV) (GLuint, const GLfloat*);
WM3_EXTERN pfn_glVertexAttrib1fvNV Wm3glVertexAttrib1fvNV;
#define glVertexAttrib1fvNV Wm3glVertexAttrib1fvNV

typedef void (APIENTRY* pfn_glVertexAttrib1sNV) (GLuint, GLshort);
WM3_EXTERN pfn_glVertexAttrib1sNV Wm3glVertexAttrib1sNV;
#define glVertexAttrib1sNV Wm3glVertexAttrib1sNV

typedef void (APIENTRY* pfn_glVertexAttrib1svNV) (GLuint, const GLshort*);
WM3_EXTERN pfn_glVertexAttrib1svNV Wm3glVertexAttrib1svNV;
#define glVertexAttrib1svNV Wm3glVertexAttrib1svNV

typedef void (APIENTRY* pfn_glVertexAttrib2dNV) (GLuint, GLdouble, GLdouble);
WM3_EXTERN pfn_glVertexAttrib2dNV Wm3glVertexAttrib2dNV;
#define glVertexAttrib2dNV Wm3glVertexAttrib2dNV

typedef void (APIENTRY* pfn_glVertexAttrib2dvNV) (GLuint, const GLdouble*);
WM3_EXTERN pfn_glVertexAttrib2dvNV Wm3glVertexAttrib2dvNV;
#define glVertexAttrib2dvNV Wm3glVertexAttrib2dvNV

typedef void (APIENTRY* pfn_glVertexAttrib2fNV) (GLuint, GLfloat, GLfloat);
WM3_EXTERN pfn_glVertexAttrib2fNV Wm3glVertexAttrib2fNV;
#define glVertexAttrib2fNV Wm3glVertexAttrib2fNV

typedef void (APIENTRY* pfn_glVertexAttrib2fvNV) (GLuint, const GLfloat*);
WM3_EXTERN pfn_glVertexAttrib2fvNV Wm3glVertexAttrib2fvNV;
#define glVertexAttrib2fvNV Wm3glVertexAttrib2fvNV

typedef void (APIENTRY* pfn_glVertexAttrib2sNV) (GLuint, GLshort, GLshort);
WM3_EXTERN pfn_glVertexAttrib2sNV Wm3glVertexAttrib2sNV;
#define glVertexAttrib2sNV Wm3glVertexAttrib2sNV

typedef void (APIENTRY* pfn_glVertexAttrib2svNV) (GLuint, const GLshort*);
WM3_EXTERN pfn_glVertexAttrib2svNV Wm3glVertexAttrib2svNV;
#define glVertexAttrib2svNV Wm3glVertexAttrib2svNV

typedef void (APIENTRY* pfn_glVertexAttrib3dNV) (GLuint, GLdouble, GLdouble, GLdouble);
WM3_EXTERN pfn_glVertexAttrib3dNV Wm3glVertexAttrib3dNV;
#define glVertexAttrib3dNV Wm3glVertexAttrib3dNV

typedef void (APIENTRY* pfn_glVertexAttrib3dvNV) (GLuint, const GLdouble*);
WM3_EXTERN pfn_glVertexAttrib3dvNV Wm3glVertexAttrib3dvNV;
#define glVertexAttrib3dvNV Wm3glVertexAttrib3dvNV

typedef void (APIENTRY* pfn_glVertexAttrib3fNV) (GLuint, GLfloat, GLfloat, GLfloat);
WM3_EXTERN pfn_glVertexAttrib3fNV Wm3glVertexAttrib3fNV;
#define glVertexAttrib3fNV Wm3glVertexAttrib3fNV

typedef void (APIENTRY* pfn_glVertexAttrib3fvNV) (GLuint, const GLfloat*);
WM3_EXTERN pfn_glVertexAttrib3fvNV Wm3glVertexAttrib3fvNV;
#define glVertexAttrib3fvNV Wm3glVertexAttrib3fvNV

typedef void (APIENTRY* pfn_glVertexAttrib3sNV) (GLuint, GLshort, GLshort, GLshort);
WM3_EXTERN pfn_glVertexAttrib3sNV Wm3glVertexAttrib3sNV;
#define glVertexAttrib3sNV Wm3glVertexAttrib3sNV

typedef void (APIENTRY* pfn_glVertexAttrib3svNV) (GLuint, const GLshort*);
WM3_EXTERN pfn_glVertexAttrib3svNV Wm3glVertexAttrib3svNV;
#define glVertexAttrib3svNV Wm3glVertexAttrib3svNV

typedef void (APIENTRY* pfn_glVertexAttrib4dNV) (GLuint, GLdouble, GLdouble, GLdouble, GLdouble);
WM3_EXTERN pfn_glVertexAttrib4dNV Wm3glVertexAttrib4dNV;
#define glVertexAttrib4dNV Wm3glVertexAttrib4dNV

typedef void (APIENTRY* pfn_glVertexAttrib4dvNV) (GLuint, const GLdouble*);
WM3_EXTERN pfn_glVertexAttrib4dvNV Wm3glVertexAttrib4dvNV;
#define glVertexAttrib4dvNV Wm3glVertexAttrib4dvNV

typedef void (APIENTRY* pfn_glVertexAttrib4fNV) (GLuint, GLfloat, GLfloat, GLfloat, GLfloat);
WM3_EXTERN pfn_glVertexAttrib4fNV Wm3glVertexAttrib4fNV;
#define glVertexAttrib4fNV Wm3glVertexAttrib4fNV

typedef void (APIENTRY* pfn_glVertexAttrib4fvNV) (GLuint, const GLfloat*);
WM3_EXTERN pfn_glVertexAttrib4fvNV Wm3glVertexAttrib4fvNV;
#define glVertexAttrib4fvNV Wm3glVertexAttrib4fvNV

typedef void (APIENTRY* pfn_glVertexAttrib4sNV) (GLuint, GLshort, GLshort, GLshort, GLshort);
WM3_EXTERN pfn_glVertexAttrib4sNV Wm3glVertexAttrib4sNV;
#define glVertexAttrib4sNV Wm3glVertexAttrib4sNV

typedef void (APIENTRY* pfn_glVertexAttrib4svNV) (GLuint, const GLshort*);
WM3_EXTERN pfn_glVertexAttrib4svNV Wm3glVertexAttrib4svNV;
#define glVertexAttrib4svNV Wm3glVertexAttrib4svNV

typedef void (APIENTRY* pfn_glVertexAttrib4ubNV) (GLuint, GLubyte, GLubyte, GLubyte, GLubyte);
WM3_EXTERN pfn_glVertexAttrib4ubNV Wm3glVertexAttrib4ubNV;
#define glVertexAttrib4ubNV Wm3glVertexAttrib4ubNV

typedef void (APIENTRY* pfn_glVertexAttrib4ubvNV) (GLuint, const GLubyte*);
WM3_EXTERN pfn_glVertexAttrib4ubvNV Wm3glVertexAttrib4ubvNV;
#define glVertexAttrib4ubvNV Wm3glVertexAttrib4ubvNV

typedef void (APIENTRY* pfn_glVertexAttribs1dvNV) (GLuint, GLsizei, const GLdouble*);
WM3_EXTERN pfn_glVertexAttribs1dvNV Wm3glVertexAttribs1dvNV;
#define glVertexAttribs1dvNV Wm3glVertexAttribs1dvNV

typedef void (APIENTRY* pfn_glVertexAttribs1fvNV) (GLuint, GLsizei, const GLfloat*);
WM3_EXTERN pfn_glVertexAttribs1fvNV Wm3glVertexAttribs1fvNV;
#define glVertexAttribs1fvNV Wm3glVertexAttribs1fvNV

typedef void (APIENTRY* pfn_glVertexAttribs1svNV) (GLuint, GLsizei, const GLshort*);
WM3_EXTERN pfn_glVertexAttribs1svNV Wm3glVertexAttribs1svNV;
#define glVertexAttribs1svNV Wm3glVertexAttribs1svNV

typedef void (APIENTRY* pfn_glVertexAttribs2dvNV) (GLuint, GLsizei, const GLdouble*);
WM3_EXTERN pfn_glVertexAttribs2dvNV Wm3glVertexAttribs2dvNV;
#define glVertexAttribs2dvNV Wm3glVertexAttribs2dvNV

typedef void (APIENTRY* pfn_glVertexAttribs2fvNV) (GLuint, GLsizei, const GLfloat*);
WM3_EXTERN pfn_glVertexAttribs2fvNV Wm3glVertexAttribs2fvNV;
#define glVertexAttribs2fvNV Wm3glVertexAttribs2fvNV

typedef void (APIENTRY* pfn_glVertexAttribs2svNV) (GLuint, GLsizei, const GLshort*);
WM3_EXTERN pfn_glVertexAttribs2svNV Wm3glVertexAttribs2svNV;
#define glVertexAttribs2svNV Wm3glVertexAttribs2svNV

typedef void (APIENTRY* pfn_glVertexAttribs3dvNV) (GLuint, GLsizei, const GLdouble*);
WM3_EXTERN pfn_glVertexAttribs3dvNV Wm3glVertexAttribs3dvNV;
#define glVertexAttribs3dvNV Wm3glVertexAttribs3dvNV

typedef void (APIENTRY* pfn_glVertexAttribs3fvNV) (GLuint, GLsizei, const GLfloat*);
WM3_EXTERN pfn_glVertexAttribs3fvNV Wm3glVertexAttribs3fvNV;
#define glVertexAttribs3fvNV Wm3glVertexAttribs3fvNV

typedef void (APIENTRY* pfn_glVertexAttribs3svNV) (GLuint, GLsizei, const GLshort*);
WM3_EXTERN pfn_glVertexAttribs3svNV Wm3glVertexAttribs3svNV;
#define glVertexAttribs3svNV Wm3glVertexAttribs3svNV

typedef void (APIENTRY* pfn_glVertexAttribs4dvNV) (GLuint, GLsizei, const GLdouble*);
WM3_EXTERN pfn_glVertexAttribs4dvNV Wm3glVertexAttribs4dvNV;
#define glVertexAttribs4dvNV Wm3glVertexAttribs4dvNV

typedef void (APIENTRY* pfn_glVertexAttribs4fvNV) (GLuint, GLsizei, const GLfloat*);
WM3_EXTERN pfn_glVertexAttribs4fvNV Wm3glVertexAttribs4fvNV;
#define glVertexAttribs4fvNV Wm3glVertexAttribs4fvNV

typedef void (APIENTRY* pfn_glVertexAttribs4svNV) (GLuint, GLsizei, const GLshort*);
WM3_EXTERN pfn_glVertexAttribs4svNV Wm3glVertexAttribs4svNV;
#define glVertexAttribs4svNV Wm3glVertexAttribs4svNV

typedef void (APIENTRY* pfn_glVertexAttribs4ubvNV) (GLuint, GLsizei, const GLubyte*);
WM3_EXTERN pfn_glVertexAttribs4ubvNV Wm3glVertexAttribs4ubvNV;
#define glVertexAttribs4ubvNV Wm3glVertexAttribs4ubvNV
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_SGIX_texture_coordinate_clamp;
WM3_EXTERN int Wm3NumFunctions_GL_SGIX_texture_coordinate_clamp;
#ifndef GL_SGIX_texture_coordinate_clamp
#define GL_SGIX_texture_coordinate_clamp
#define WM3_DEFINED_GL_SGIX_texture_coordinate_clamp
#define GL_TEXTURE_MAX_CLAMP_S_SGIX       0x8369
#define GL_TEXTURE_MAX_CLAMP_T_SGIX       0x836A
#define GL_TEXTURE_MAX_CLAMP_R_SGIX       0x836B
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_SGIX_scalebias_hint;
WM3_EXTERN int Wm3NumFunctions_GL_SGIX_scalebias_hint;
#ifndef GL_SGIX_scalebias_hint
#define GL_SGIX_scalebias_hint
#define WM3_DEFINED_GL_SGIX_scalebias_hint
#define GL_SCALEBIAS_HINT_SGIX            0x8322
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_OML_interlace;
WM3_EXTERN int Wm3NumFunctions_GL_OML_interlace;
#ifndef GL_OML_interlace
#define GL_OML_interlace
#define WM3_DEFINED_GL_OML_interlace
#define GL_INTERLACE_OML                  0x8980
#define GL_INTERLACE_READ_OML             0x8981
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_OML_subsample;
WM3_EXTERN int Wm3NumFunctions_GL_OML_subsample;
#ifndef GL_OML_subsample
#define GL_OML_subsample
#define WM3_DEFINED_GL_OML_subsample
#define GL_FORMAT_SUBSAMPLE_24_24_OML     0x8982
#define GL_FORMAT_SUBSAMPLE_244_244_OML   0x8983
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_OML_resample;
WM3_EXTERN int Wm3NumFunctions_GL_OML_resample;
#ifndef GL_OML_resample
#define GL_OML_resample
#define WM3_DEFINED_GL_OML_resample
#define GL_PACK_RESAMPLE_OML              0x8984
#define GL_UNPACK_RESAMPLE_OML            0x8985
#define GL_RESAMPLE_REPLICATE_OML         0x8986
#define GL_RESAMPLE_ZERO_FILL_OML         0x8987
#define GL_RESAMPLE_AVERAGE_OML           0x8988
#define GL_RESAMPLE_DECIMATE_OML          0x8989
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_NV_copy_depth_to_color;
WM3_EXTERN int Wm3NumFunctions_GL_NV_copy_depth_to_color;
#ifndef GL_NV_copy_depth_to_color
#define GL_NV_copy_depth_to_color
#define WM3_DEFINED_GL_NV_copy_depth_to_color
#define GL_DEPTH_STENCIL_TO_RGBA_NV       0x886E
#define GL_DEPTH_STENCIL_TO_BGRA_NV       0x886F
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_ATI_envmap_bumpmap;
WM3_EXTERN int Wm3NumFunctions_GL_ATI_envmap_bumpmap;
#ifndef GL_ATI_envmap_bumpmap
#define GL_ATI_envmap_bumpmap
#define WM3_DEFINED_GL_ATI_envmap_bumpmap
#define GL_BUMP_ROT_MATRIX_ATI            0x8775
#define GL_BUMP_ROT_MATRIX_SIZE_ATI       0x8776
#define GL_BUMP_NUM_TEX_UNITS_ATI         0x8777
#define GL_BUMP_TEX_UNITS_ATI             0x8778
#define GL_DUDV_ATI                       0x8779
#define GL_DU8DV8_ATI                     0x877A
#define GL_BUMP_ENVMAP_ATI                0x877B
#define GL_BUMP_TARGET_ATI                0x877C

typedef void (APIENTRY* pfn_glTexBumpParameterivATI) (GLenum, const GLint*);
WM3_EXTERN pfn_glTexBumpParameterivATI Wm3glTexBumpParameterivATI;
#define glTexBumpParameterivATI Wm3glTexBumpParameterivATI

typedef void (APIENTRY* pfn_glTexBumpParameterfvATI) (GLenum, const GLfloat*);
WM3_EXTERN pfn_glTexBumpParameterfvATI Wm3glTexBumpParameterfvATI;
#define glTexBumpParameterfvATI Wm3glTexBumpParameterfvATI

typedef void (APIENTRY* pfn_glGetTexBumpParameterivATI) (GLenum, GLint*);
WM3_EXTERN pfn_glGetTexBumpParameterivATI Wm3glGetTexBumpParameterivATI;
#define glGetTexBumpParameterivATI Wm3glGetTexBumpParameterivATI

typedef void (APIENTRY* pfn_glGetTexBumpParameterfvATI) (GLenum, GLfloat*);
WM3_EXTERN pfn_glGetTexBumpParameterfvATI Wm3glGetTexBumpParameterfvATI;
#define glGetTexBumpParameterfvATI Wm3glGetTexBumpParameterfvATI
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_ATI_fragment_shader;
WM3_EXTERN int Wm3NumFunctions_GL_ATI_fragment_shader;
#ifndef GL_ATI_fragment_shader
#define GL_ATI_fragment_shader
#define WM3_DEFINED_GL_ATI_fragment_shader
#define GL_FRAGMENT_SHADER_ATI                      0x8920
#define GL_REG_0_ATI                                0x8921
#define GL_REG_1_ATI                                0x8922
#define GL_REG_2_ATI                                0x8923
#define GL_REG_3_ATI                                0x8924
#define GL_REG_4_ATI                                0x8925
#define GL_REG_5_ATI                                0x8926
#define GL_REG_6_ATI                                0x8927
#define GL_REG_7_ATI                                0x8928
#define GL_REG_8_ATI                                0x8929
#define GL_REG_9_ATI                                0x892A
#define GL_REG_10_ATI                               0x892B
#define GL_REG_11_ATI                               0x892C
#define GL_REG_12_ATI                               0x892D
#define GL_REG_13_ATI                               0x892E
#define GL_REG_14_ATI                               0x892F
#define GL_REG_15_ATI                               0x8930
#define GL_REG_16_ATI                               0x8931
#define GL_REG_17_ATI                               0x8932
#define GL_REG_18_ATI                               0x8933
#define GL_REG_19_ATI                               0x8934
#define GL_REG_20_ATI                               0x8935
#define GL_REG_21_ATI                               0x8936
#define GL_REG_22_ATI                               0x8937
#define GL_REG_23_ATI                               0x8938
#define GL_REG_24_ATI                               0x8939
#define GL_REG_25_ATI                               0x893A
#define GL_REG_26_ATI                               0x893B
#define GL_REG_27_ATI                               0x893C
#define GL_REG_28_ATI                               0x893D
#define GL_REG_29_ATI                               0x893E
#define GL_REG_30_ATI                               0x893F
#define GL_REG_31_ATI                               0x8940
#define GL_CON_0_ATI                                0x8941
#define GL_CON_1_ATI                                0x8942
#define GL_CON_2_ATI                                0x8943
#define GL_CON_3_ATI                                0x8944
#define GL_CON_4_ATI                                0x8945
#define GL_CON_5_ATI                                0x8946
#define GL_CON_6_ATI                                0x8947
#define GL_CON_7_ATI                                0x8948
#define GL_CON_8_ATI                                0x8949
#define GL_CON_9_ATI                                0x894A
#define GL_CON_10_ATI                               0x894B
#define GL_CON_11_ATI                               0x894C
#define GL_CON_12_ATI                               0x894D
#define GL_CON_13_ATI                               0x894E
#define GL_CON_14_ATI                               0x894F
#define GL_CON_15_ATI                               0x8950
#define GL_CON_16_ATI                               0x8951
#define GL_CON_17_ATI                               0x8952
#define GL_CON_18_ATI                               0x8953
#define GL_CON_19_ATI                               0x8954
#define GL_CON_20_ATI                               0x8955
#define GL_CON_21_ATI                               0x8956
#define GL_CON_22_ATI                               0x8957
#define GL_CON_23_ATI                               0x8958
#define GL_CON_24_ATI                               0x8959
#define GL_CON_25_ATI                               0x895A
#define GL_CON_26_ATI                               0x895B
#define GL_CON_27_ATI                               0x895C
#define GL_CON_28_ATI                               0x895D
#define GL_CON_29_ATI                               0x895E
#define GL_CON_30_ATI                               0x895F
#define GL_CON_31_ATI                               0x8960
#define GL_MOV_ATI                                  0x8961
#define GL_ADD_ATI                                  0x8963
#define GL_MUL_ATI                                  0x8964
#define GL_SUB_ATI                                  0x8965
#define GL_DOT3_ATI                                 0x8966
#define GL_DOT4_ATI                                 0x8967
#define GL_MAD_ATI                                  0x8968
#define GL_LERP_ATI                                 0x8969
#define GL_CND_ATI                                  0x896A
#define GL_CND0_ATI                                 0x896B
#define GL_DOT2_ADD_ATI                             0x896C
#define GL_SECONDARY_INTERPOLATOR_ATI               0x896D
#define GL_NUM_FRAGMENT_REGISTERS_ATI               0x896E
#define GL_NUM_FRAGMENT_CONSTANTS_ATI               0x896F
#define GL_NUM_PASSES_ATI                           0x8970
#define GL_NUM_INSTRUCTIONS_PER_PASS_ATI            0x8971
#define GL_NUM_INSTRUCTIONS_TOTAL_ATI               0x8972
#define GL_NUM_INPUT_INTERPOLATOR_COMPONENTS_ATI    0x8973
#define GL_NUM_LOOPBACK_COMPONENTS_ATI              0x8974
#define GL_COLOR_ALPHA_PAIRING_ATI                  0x8975
#define GL_SWIZZLE_STR_ATI                          0x8976
#define GL_SWIZZLE_STQ_ATI                          0x8977
#define GL_SWIZZLE_STR_DR_ATI                       0x8978
#define GL_SWIZZLE_STQ_DQ_ATI                       0x8979
#define GL_SWIZZLE_STRQ_ATI                         0x897A
#define GL_SWIZZLE_STRQ_DQ_ATI                      0x897B
#define GL_RED_BIT_ATI                              0x00000001
#define GL_GREEN_BIT_ATI                            0x00000002
#define GL_BLUE_BIT_ATI                             0x00000004
#define GL_2X_BIT_ATI                               0x00000001
#define GL_4X_BIT_ATI                               0x00000002
#define GL_8X_BIT_ATI                               0x00000004
#define GL_HALF_BIT_ATI                             0x00000008
#define GL_QUARTER_BIT_ATI                          0x00000010
#define GL_EIGHTH_BIT_ATI                           0x00000020
#define GL_SATURATE_BIT_ATI                         0x00000040
#define GL_COMP_BIT_ATI                             0x00000002
#define GL_NEGATE_BIT_ATI                           0x00000004
#define GL_BIAS_BIT_ATI                             0x00000008

typedef GLuint (APIENTRY* pfn_glGenFragmentShadersATI) (GLuint);
WM3_EXTERN pfn_glGenFragmentShadersATI Wm3glGenFragmentShadersATI;
#define glGenFragmentShadersATI Wm3glGenFragmentShadersATI

typedef void (APIENTRY* pfn_glBindFragmentShaderATI) (GLuint);
WM3_EXTERN pfn_glBindFragmentShaderATI Wm3glBindFragmentShaderATI;
#define glBindFragmentShaderATI Wm3glBindFragmentShaderATI

typedef void (APIENTRY* pfn_glDeleteFragmentShaderATI) (GLuint);
WM3_EXTERN pfn_glDeleteFragmentShaderATI Wm3glDeleteFragmentShaderATI;
#define glDeleteFragmentShaderATI Wm3glDeleteFragmentShaderATI

typedef void (APIENTRY* pfn_glBeginFragmentShaderATI) (void);
WM3_EXTERN pfn_glBeginFragmentShaderATI Wm3glBeginFragmentShaderATI;
#define glBeginFragmentShaderATI Wm3glBeginFragmentShaderATI

typedef void (APIENTRY* pfn_glEndFragmentShaderATI) (void);
WM3_EXTERN pfn_glEndFragmentShaderATI Wm3glEndFragmentShaderATI;
#define glEndFragmentShaderATI Wm3glEndFragmentShaderATI

typedef void (APIENTRY* pfn_glPassTexCoordATI) (GLuint, GLuint, GLenum);
WM3_EXTERN pfn_glPassTexCoordATI Wm3glPassTexCoordATI;
#define glPassTexCoordATI Wm3glPassTexCoordATI

typedef void (APIENTRY* pfn_glSampleMapATI) (GLuint, GLuint, GLenum);
WM3_EXTERN pfn_glSampleMapATI Wm3glSampleMapATI;
#define glSampleMapATI Wm3glSampleMapATI

typedef void (APIENTRY* pfn_glColorFragmentOp1ATI) (GLenum, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint);
WM3_EXTERN pfn_glColorFragmentOp1ATI Wm3glColorFragmentOp1ATI;
#define glColorFragmentOp1ATI Wm3glColorFragmentOp1ATI

typedef void (APIENTRY* pfn_glColorFragmentOp2ATI) (GLenum, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint);
WM3_EXTERN pfn_glColorFragmentOp2ATI Wm3glColorFragmentOp2ATI;
#define glColorFragmentOp2ATI Wm3glColorFragmentOp2ATI

typedef void (APIENTRY* pfn_glColorFragmentOp3ATI) (GLenum, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint);
WM3_EXTERN pfn_glColorFragmentOp3ATI Wm3glColorFragmentOp3ATI;
#define glColorFragmentOp3ATI Wm3glColorFragmentOp3ATI

typedef void (APIENTRY* pfn_glAlphaFragmentOp1ATI) (GLenum, GLuint, GLuint, GLuint, GLuint, GLuint);
WM3_EXTERN pfn_glAlphaFragmentOp1ATI Wm3glAlphaFragmentOp1ATI;
#define glAlphaFragmentOp1ATI Wm3glAlphaFragmentOp1ATI

typedef void (APIENTRY* pfn_glAlphaFragmentOp2ATI) (GLenum, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint);
WM3_EXTERN pfn_glAlphaFragmentOp2ATI Wm3glAlphaFragmentOp2ATI;
#define glAlphaFragmentOp2ATI Wm3glAlphaFragmentOp2ATI

typedef void (APIENTRY* pfn_glAlphaFragmentOp3ATI) (GLenum, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint);
WM3_EXTERN pfn_glAlphaFragmentOp3ATI Wm3glAlphaFragmentOp3ATI;
#define glAlphaFragmentOp3ATI Wm3glAlphaFragmentOp3ATI

typedef void (APIENTRY* pfn_glSetFragmentShaderConstantATI) (GLuint, const GLfloat*);
WM3_EXTERN pfn_glSetFragmentShaderConstantATI Wm3glSetFragmentShaderConstantATI;
#define glSetFragmentShaderConstantATI Wm3glSetFragmentShaderConstantATI
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_ATI_pn_triangles;
WM3_EXTERN int Wm3NumFunctions_GL_ATI_pn_triangles;
#ifndef GL_ATI_pn_triangles
#define GL_ATI_pn_triangles
#define WM3_DEFINED_GL_ATI_pn_triangles
#define GL_PN_TRIANGLES_ATI                         0x87F0
#define GL_MAX_PN_TRIANGLES_TESSELATION_LEVEL_ATI   0x87F1
#define GL_PN_TRIANGLES_POINT_MODE_ATI              0x87F2
#define GL_PN_TRIANGLES_NORMAL_MODE_ATI             0x87F3
#define GL_PN_TRIANGLES_TESSELATION_LEVEL_ATI       0x87F4
#define GL_PN_TRIANGLES_POINT_MODE_LINEAR_ATI       0x87F5
#define GL_PN_TRIANGLES_POINT_MODE_CUBIC_ATI        0x87F6
#define GL_PN_TRIANGLES_NORMAL_MODE_LINEAR_ATI      0x87F7
#define GL_PN_TRIANGLES_NORMAL_MODE_QUADRATIC_ATI   0x87F8

typedef void (APIENTRY* pfn_glPNTrianglesiATI) (GLenum, GLint);
WM3_EXTERN pfn_glPNTrianglesiATI Wm3glPNTrianglesiATI;
#define glPNTrianglesiATI Wm3glPNTrianglesiATI

typedef void (APIENTRY* pfn_glPNTrianglesfATI) (GLenum, GLfloat);
WM3_EXTERN pfn_glPNTrianglesfATI Wm3glPNTrianglesfATI;
#define glPNTrianglesfATI Wm3glPNTrianglesfATI
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_ATI_vertex_array_object;
WM3_EXTERN int Wm3NumFunctions_GL_ATI_vertex_array_object;
#ifndef GL_ATI_vertex_array_object
#define GL_ATI_vertex_array_object
#define WM3_DEFINED_GL_ATI_vertex_array_object
#define GL_STATIC_ATI                     0x8760
#define GL_DYNAMIC_ATI                    0x8761
#define GL_PRESERVE_ATI                   0x8762
#define GL_DISCARD_ATI                    0x8763
#define GL_OBJECT_BUFFER_SIZE_ATI         0x8764
#define GL_OBJECT_BUFFER_USAGE_ATI        0x8765
#define GL_ARRAY_OBJECT_BUFFER_ATI        0x8766
#define GL_ARRAY_OBJECT_OFFSET_ATI        0x8767

typedef GLuint (APIENTRY* pfn_glNewObjectBufferATI) (GLsizei, const GLvoid*, GLenum);
WM3_EXTERN pfn_glNewObjectBufferATI Wm3glNewObjectBufferATI;
#define glNewObjectBufferATI Wm3glNewObjectBufferATI

typedef GLboolean (APIENTRY* pfn_glIsObjectBufferATI) (GLuint);
WM3_EXTERN pfn_glIsObjectBufferATI Wm3glIsObjectBufferATI;
#define glIsObjectBufferATI Wm3glIsObjectBufferATI

typedef void (APIENTRY* pfn_glUpdateObjectBufferATI) (GLuint, GLuint, GLsizei, const GLvoid*, GLenum);
WM3_EXTERN pfn_glUpdateObjectBufferATI Wm3glUpdateObjectBufferATI;
#define glUpdateObjectBufferATI Wm3glUpdateObjectBufferATI

typedef void (APIENTRY* pfn_glGetObjectBufferfvATI) (GLuint, GLenum, GLfloat*);
WM3_EXTERN pfn_glGetObjectBufferfvATI Wm3glGetObjectBufferfvATI;
#define glGetObjectBufferfvATI Wm3glGetObjectBufferfvATI

typedef void (APIENTRY* pfn_glGetObjectBufferivATI) (GLuint, GLenum, GLint*);
WM3_EXTERN pfn_glGetObjectBufferivATI Wm3glGetObjectBufferivATI;
#define glGetObjectBufferivATI Wm3glGetObjectBufferivATI

typedef void (APIENTRY* pfn_glFreeObjectBufferATI) (GLuint);
WM3_EXTERN pfn_glFreeObjectBufferATI Wm3glFreeObjectBufferATI;
#define glFreeObjectBufferATI Wm3glFreeObjectBufferATI

typedef void (APIENTRY* pfn_glArrayObjectATI) (GLenum, GLint, GLenum, GLsizei, GLuint, GLuint);
WM3_EXTERN pfn_glArrayObjectATI Wm3glArrayObjectATI;
#define glArrayObjectATI Wm3glArrayObjectATI

typedef void (APIENTRY* pfn_glGetArrayObjectfvATI) (GLenum, GLenum, GLfloat*);
WM3_EXTERN pfn_glGetArrayObjectfvATI Wm3glGetArrayObjectfvATI;
#define glGetArrayObjectfvATI Wm3glGetArrayObjectfvATI

typedef void (APIENTRY* pfn_glGetArrayObjectivATI) (GLenum, GLenum, GLint*);
WM3_EXTERN pfn_glGetArrayObjectivATI Wm3glGetArrayObjectivATI;
#define glGetArrayObjectivATI Wm3glGetArrayObjectivATI

typedef void (APIENTRY* pfn_glVariantArrayObjectATI) (GLuint, GLenum, GLsizei, GLuint, GLuint);
WM3_EXTERN pfn_glVariantArrayObjectATI Wm3glVariantArrayObjectATI;
#define glVariantArrayObjectATI Wm3glVariantArrayObjectATI

typedef void (APIENTRY* pfn_glGetVariantArrayObjectfvATI) (GLuint, GLenum, GLfloat*);
WM3_EXTERN pfn_glGetVariantArrayObjectfvATI Wm3glGetVariantArrayObjectfvATI;
#define glGetVariantArrayObjectfvATI Wm3glGetVariantArrayObjectfvATI

typedef void (APIENTRY* pfn_glGetVariantArrayObjectivATI) (GLuint, GLenum, GLint*);
WM3_EXTERN pfn_glGetVariantArrayObjectivATI Wm3glGetVariantArrayObjectivATI;
#define glGetVariantArrayObjectivATI Wm3glGetVariantArrayObjectivATI
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_EXT_vertex_shader;
WM3_EXTERN int Wm3NumFunctions_GL_EXT_vertex_shader;
#ifndef GL_EXT_vertex_shader
#define GL_EXT_vertex_shader
#define WM3_DEFINED_GL_EXT_vertex_shader
#define GL_VERTEX_SHADER_EXT                                0x8780
#define GL_VERTEX_SHADER_BINDING_EXT                        0x8781
#define GL_OP_INDEX_EXT                                     0x8782
#define GL_OP_NEGATE_EXT                                    0x8783
#define GL_OP_DOT3_EXT                                      0x8784
#define GL_OP_DOT4_EXT                                      0x8785
#define GL_OP_MUL_EXT                                       0x8786
#define GL_OP_ADD_EXT                                       0x8787
#define GL_OP_MADD_EXT                                      0x8788
#define GL_OP_FRAC_EXT                                      0x8789
#define GL_OP_MAX_EXT                                       0x878A
#define GL_OP_MIN_EXT                                       0x878B
#define GL_OP_SET_GE_EXT                                    0x878C
#define GL_OP_SET_LT_EXT                                    0x878D
#define GL_OP_CLAMP_EXT                                     0x878E
#define GL_OP_FLOOR_EXT                                     0x878F
#define GL_OP_ROUND_EXT                                     0x8790
#define GL_OP_EXP_BASE_2_EXT                                0x8791
#define GL_OP_LOG_BASE_2_EXT                                0x8792
#define GL_OP_POWER_EXT                                     0x8793
#define GL_OP_RECIP_EXT                                     0x8794
#define GL_OP_RECIP_SQRT_EXT                                0x8795
#define GL_OP_SUB_EXT                                       0x8796
#define GL_OP_CROSS_PRODUCT_EXT                             0x8797
#define GL_OP_MULTIPLY_MATRIX_EXT                           0x8798
#define GL_OP_MOV_EXT                                       0x8799
#define GL_OUTPUT_VERTEX_EXT                                0x879A
#define GL_OUTPUT_COLOR0_EXT                                0x879B
#define GL_OUTPUT_COLOR1_EXT                                0x879C
#define GL_OUTPUT_TEXTURE_COORD0_EXT                        0x879D
#define GL_OUTPUT_TEXTURE_COORD1_EXT                        0x879E
#define GL_OUTPUT_TEXTURE_COORD2_EXT                        0x879F
#define GL_OUTPUT_TEXTURE_COORD3_EXT                        0x87A0
#define GL_OUTPUT_TEXTURE_COORD4_EXT                        0x87A1
#define GL_OUTPUT_TEXTURE_COORD5_EXT                        0x87A2
#define GL_OUTPUT_TEXTURE_COORD6_EXT                        0x87A3
#define GL_OUTPUT_TEXTURE_COORD7_EXT                        0x87A4
#define GL_OUTPUT_TEXTURE_COORD8_EXT                        0x87A5
#define GL_OUTPUT_TEXTURE_COORD9_EXT                        0x87A6
#define GL_OUTPUT_TEXTURE_COORD10_EXT                       0x87A7
#define GL_OUTPUT_TEXTURE_COORD11_EXT                       0x87A8
#define GL_OUTPUT_TEXTURE_COORD12_EXT                       0x87A9
#define GL_OUTPUT_TEXTURE_COORD13_EXT                       0x87AA
#define GL_OUTPUT_TEXTURE_COORD14_EXT                       0x87AB
#define GL_OUTPUT_TEXTURE_COORD15_EXT                       0x87AC
#define GL_OUTPUT_TEXTURE_COORD16_EXT                       0x87AD
#define GL_OUTPUT_TEXTURE_COORD17_EXT                       0x87AE
#define GL_OUTPUT_TEXTURE_COORD18_EXT                       0x87AF
#define GL_OUTPUT_TEXTURE_COORD19_EXT                       0x87B0
#define GL_OUTPUT_TEXTURE_COORD20_EXT                       0x87B1
#define GL_OUTPUT_TEXTURE_COORD21_EXT                       0x87B2
#define GL_OUTPUT_TEXTURE_COORD22_EXT                       0x87B3
#define GL_OUTPUT_TEXTURE_COORD23_EXT                       0x87B4
#define GL_OUTPUT_TEXTURE_COORD24_EXT                       0x87B5
#define GL_OUTPUT_TEXTURE_COORD25_EXT                       0x87B6
#define GL_OUTPUT_TEXTURE_COORD26_EXT                       0x87B7
#define GL_OUTPUT_TEXTURE_COORD27_EXT                       0x87B8
#define GL_OUTPUT_TEXTURE_COORD28_EXT                       0x87B9
#define GL_OUTPUT_TEXTURE_COORD29_EXT                       0x87BA
#define GL_OUTPUT_TEXTURE_COORD30_EXT                       0x87BB
#define GL_OUTPUT_TEXTURE_COORD31_EXT                       0x87BC
#define GL_OUTPUT_FOG_EXT                                   0x87BD
#define GL_SCALAR_EXT                                       0x87BE
#define GL_VECTOR_EXT                                       0x87BF
#define GL_MATRIX_EXT                                       0x87C0
#define GL_VARIANT_EXT                                      0x87C1
#define GL_INVARIANT_EXT                                    0x87C2
#define GL_LOCAL_CONSTANT_EXT                               0x87C3
#define GL_LOCAL_EXT                                        0x87C4
#define GL_MAX_VERTEX_SHADER_INSTRUCTIONS_EXT               0x87C5
#define GL_MAX_VERTEX_SHADER_VARIANTS_EXT                   0x87C6
#define GL_MAX_VERTEX_SHADER_INVARIANTS_EXT                 0x87C7
#define GL_MAX_VERTEX_SHADER_LOCAL_CONSTANTS_EXT            0x87C8
#define GL_MAX_VERTEX_SHADER_LOCALS_EXT                     0x87C9
#define GL_MAX_OPTIMIZED_VERTEX_SHADER_INSTRUCTIONS_EXT     0x87CA
#define GL_MAX_OPTIMIZED_VERTEX_SHADER_VARIANTS_EXT         0x87CB
#define GL_MAX_OPTIMIZED_VERTEX_SHADER_LOCAL_CONSTANTS_EXT  0x87CC
#define GL_MAX_OPTIMIZED_VERTEX_SHADER_INVARIANTS_EXT       0x87CD
#define GL_MAX_OPTIMIZED_VERTEX_SHADER_LOCALS_EXT           0x87CE
#define GL_VERTEX_SHADER_INSTRUCTIONS_EXT                   0x87CF
#define GL_VERTEX_SHADER_VARIANTS_EXT                       0x87D0
#define GL_VERTEX_SHADER_INVARIANTS_EXT                     0x87D1
#define GL_VERTEX_SHADER_LOCAL_CONSTANTS_EXT                0x87D2
#define GL_VERTEX_SHADER_LOCALS_EXT                         0x87D3
#define GL_VERTEX_SHADER_OPTIMIZED_EXT                      0x87D4
#define GL_X_EXT                                            0x87D5
#define GL_Y_EXT                                            0x87D6
#define GL_Z_EXT                                            0x87D7
#define GL_W_EXT                                            0x87D8
#define GL_NEGATIVE_X_EXT                                   0x87D9
#define GL_NEGATIVE_Y_EXT                                   0x87DA
#define GL_NEGATIVE_Z_EXT                                   0x87DB
#define GL_NEGATIVE_W_EXT                                   0x87DC
#define GL_ZERO_EXT                                         0x87DD
#define GL_ONE_EXT                                          0x87DE
#define GL_NEGATIVE_ONE_EXT                                 0x87DF
#define GL_NORMALIZED_RANGE_EXT                             0x87E0
#define GL_FULL_RANGE_EXT                                   0x87E1
#define GL_CURRENT_VERTEX_EXT                               0x87E2
#define GL_MVP_MATRIX_EXT                                   0x87E3
#define GL_VARIANT_VALUE_EXT                                0x87E4
#define GL_VARIANT_DATATYPE_EXT                             0x87E5
#define GL_VARIANT_ARRAY_STRIDE_EXT                         0x87E6
#define GL_VARIANT_ARRAY_TYPE_EXT                           0x87E7
#define GL_VARIANT_ARRAY_EXT                                0x87E8
#define GL_VARIANT_ARRAY_POINTER_EXT                        0x87E9
#define GL_INVARIANT_VALUE_EXT                              0x87EA
#define GL_INVARIANT_DATATYPE_EXT                           0x87EB
#define GL_LOCAL_CONSTANT_VALUE_EXT                         0x87EC
#define GL_LOCAL_CONSTANT_DATATYPE_EXT                      0x87ED

typedef void (APIENTRY* pfn_glBeginVertexShaderEXT) (void);
WM3_EXTERN pfn_glBeginVertexShaderEXT Wm3glBeginVertexShaderEXT;
#define glBeginVertexShaderEXT Wm3glBeginVertexShaderEXT

typedef void (APIENTRY* pfn_glEndVertexShaderEXT) (void);
WM3_EXTERN pfn_glEndVertexShaderEXT Wm3glEndVertexShaderEXT;
#define glEndVertexShaderEXT Wm3glEndVertexShaderEXT

typedef void (APIENTRY* pfn_glBindVertexShaderEXT) (GLuint);
WM3_EXTERN pfn_glBindVertexShaderEXT Wm3glBindVertexShaderEXT;
#define glBindVertexShaderEXT Wm3glBindVertexShaderEXT

typedef GLuint (APIENTRY* pfn_glGenVertexShadersEXT) (GLuint);
WM3_EXTERN pfn_glGenVertexShadersEXT Wm3glGenVertexShadersEXT;
#define glGenVertexShadersEXT Wm3glGenVertexShadersEXT

typedef void (APIENTRY* pfn_glDeleteVertexShaderEXT) (GLuint);
WM3_EXTERN pfn_glDeleteVertexShaderEXT Wm3glDeleteVertexShaderEXT;
#define glDeleteVertexShaderEXT Wm3glDeleteVertexShaderEXT

typedef void (APIENTRY* pfn_glShaderOp1EXT) (GLenum, GLuint, GLuint);
WM3_EXTERN pfn_glShaderOp1EXT Wm3glShaderOp1EXT;
#define glShaderOp1EXT Wm3glShaderOp1EXT

typedef void (APIENTRY* pfn_glShaderOp2EXT) (GLenum, GLuint, GLuint, GLuint);
WM3_EXTERN pfn_glShaderOp2EXT Wm3glShaderOp2EXT;
#define glShaderOp2EXT Wm3glShaderOp2EXT

typedef void (APIENTRY* pfn_glShaderOp3EXT) (GLenum, GLuint, GLuint, GLuint, GLuint);
WM3_EXTERN pfn_glShaderOp3EXT Wm3glShaderOp3EXT;
#define glShaderOp3EXT Wm3glShaderOp3EXT

typedef void (APIENTRY* pfn_glSwizzleEXT) (GLuint, GLuint, GLenum, GLenum, GLenum, GLenum);
WM3_EXTERN pfn_glSwizzleEXT Wm3glSwizzleEXT;
#define glSwizzleEXT Wm3glSwizzleEXT

typedef void (APIENTRY* pfn_glWriteMaskEXT) (GLuint, GLuint, GLenum, GLenum, GLenum, GLenum);
WM3_EXTERN pfn_glWriteMaskEXT Wm3glWriteMaskEXT;
#define glWriteMaskEXT Wm3glWriteMaskEXT

typedef void (APIENTRY* pfn_glInsertComponentEXT) (GLuint, GLuint, GLuint);
WM3_EXTERN pfn_glInsertComponentEXT Wm3glInsertComponentEXT;
#define glInsertComponentEXT Wm3glInsertComponentEXT

typedef void (APIENTRY* pfn_glExtractComponentEXT) (GLuint, GLuint, GLuint);
WM3_EXTERN pfn_glExtractComponentEXT Wm3glExtractComponentEXT;
#define glExtractComponentEXT Wm3glExtractComponentEXT

typedef GLuint (APIENTRY* pfn_glGenSymbolsEXT) (GLenum, GLenum, GLenum, GLuint);
WM3_EXTERN pfn_glGenSymbolsEXT Wm3glGenSymbolsEXT;
#define glGenSymbolsEXT Wm3glGenSymbolsEXT

typedef void (APIENTRY* pfn_glSetInvariantEXT) (GLuint, GLenum, const GLvoid*);
WM3_EXTERN pfn_glSetInvariantEXT Wm3glSetInvariantEXT;
#define glSetInvariantEXT Wm3glSetInvariantEXT

typedef void (APIENTRY* pfn_glSetLocalConstantEXT) (GLuint, GLenum, const GLvoid*);
WM3_EXTERN pfn_glSetLocalConstantEXT Wm3glSetLocalConstantEXT;
#define glSetLocalConstantEXT Wm3glSetLocalConstantEXT

typedef void (APIENTRY* pfn_glVariantbvEXT) (GLuint, const GLbyte*);
WM3_EXTERN pfn_glVariantbvEXT Wm3glVariantbvEXT;
#define glVariantbvEXT Wm3glVariantbvEXT

typedef void (APIENTRY* pfn_glVariantsvEXT) (GLuint, const GLshort*);
WM3_EXTERN pfn_glVariantsvEXT Wm3glVariantsvEXT;
#define glVariantsvEXT Wm3glVariantsvEXT

typedef void (APIENTRY* pfn_glVariantivEXT) (GLuint, const GLint*);
WM3_EXTERN pfn_glVariantivEXT Wm3glVariantivEXT;
#define glVariantivEXT Wm3glVariantivEXT

typedef void (APIENTRY* pfn_glVariantfvEXT) (GLuint, const GLfloat*);
WM3_EXTERN pfn_glVariantfvEXT Wm3glVariantfvEXT;
#define glVariantfvEXT Wm3glVariantfvEXT

typedef void (APIENTRY* pfn_glVariantdvEXT) (GLuint, const GLdouble*);
WM3_EXTERN pfn_glVariantdvEXT Wm3glVariantdvEXT;
#define glVariantdvEXT Wm3glVariantdvEXT

typedef void (APIENTRY* pfn_glVariantubvEXT) (GLuint, const GLubyte*);
WM3_EXTERN pfn_glVariantubvEXT Wm3glVariantubvEXT;
#define glVariantubvEXT Wm3glVariantubvEXT

typedef void (APIENTRY* pfn_glVariantusvEXT) (GLuint, const GLushort*);
WM3_EXTERN pfn_glVariantusvEXT Wm3glVariantusvEXT;
#define glVariantusvEXT Wm3glVariantusvEXT

typedef void (APIENTRY* pfn_glVariantuivEXT) (GLuint, const GLuint*);
WM3_EXTERN pfn_glVariantuivEXT Wm3glVariantuivEXT;
#define glVariantuivEXT Wm3glVariantuivEXT

typedef void (APIENTRY* pfn_glVariantPointerEXT) (GLuint, GLenum, GLuint, const GLvoid*);
WM3_EXTERN pfn_glVariantPointerEXT Wm3glVariantPointerEXT;
#define glVariantPointerEXT Wm3glVariantPointerEXT

typedef void (APIENTRY* pfn_glEnableVariantClientStateEXT) (GLuint);
WM3_EXTERN pfn_glEnableVariantClientStateEXT Wm3glEnableVariantClientStateEXT;
#define glEnableVariantClientStateEXT Wm3glEnableVariantClientStateEXT

typedef void (APIENTRY* pfn_glDisableVariantClientStateEXT) (GLuint);
WM3_EXTERN pfn_glDisableVariantClientStateEXT Wm3glDisableVariantClientStateEXT;
#define glDisableVariantClientStateEXT Wm3glDisableVariantClientStateEXT

typedef GLuint (APIENTRY* pfn_glBindLightParameterEXT) (GLenum, GLenum);
WM3_EXTERN pfn_glBindLightParameterEXT Wm3glBindLightParameterEXT;
#define glBindLightParameterEXT Wm3glBindLightParameterEXT

typedef GLuint (APIENTRY* pfn_glBindMaterialParameterEXT) (GLenum, GLenum);
WM3_EXTERN pfn_glBindMaterialParameterEXT Wm3glBindMaterialParameterEXT;
#define glBindMaterialParameterEXT Wm3glBindMaterialParameterEXT

typedef GLuint (APIENTRY* pfn_glBindTexGenParameterEXT) (GLenum, GLenum, GLenum);
WM3_EXTERN pfn_glBindTexGenParameterEXT Wm3glBindTexGenParameterEXT;
#define glBindTexGenParameterEXT Wm3glBindTexGenParameterEXT

typedef GLuint (APIENTRY* pfn_glBindTextureUnitParameterEXT) (GLenum, GLenum);
WM3_EXTERN pfn_glBindTextureUnitParameterEXT Wm3glBindTextureUnitParameterEXT;
#define glBindTextureUnitParameterEXT Wm3glBindTextureUnitParameterEXT

typedef GLuint (APIENTRY* pfn_glBindParameterEXT) (GLenum);
WM3_EXTERN pfn_glBindParameterEXT Wm3glBindParameterEXT;
#define glBindParameterEXT Wm3glBindParameterEXT

typedef GLboolean (APIENTRY* pfn_glIsVariantEnabledEXT) (GLuint, GLenum);
WM3_EXTERN pfn_glIsVariantEnabledEXT Wm3glIsVariantEnabledEXT;
#define glIsVariantEnabledEXT Wm3glIsVariantEnabledEXT

typedef void (APIENTRY* pfn_glGetVariantBooleanvEXT) (GLuint, GLenum, GLboolean*);
WM3_EXTERN pfn_glGetVariantBooleanvEXT Wm3glGetVariantBooleanvEXT;
#define glGetVariantBooleanvEXT Wm3glGetVariantBooleanvEXT

typedef void (APIENTRY* pfn_glGetVariantIntegervEXT) (GLuint, GLenum, GLint*);
WM3_EXTERN pfn_glGetVariantIntegervEXT Wm3glGetVariantIntegervEXT;
#define glGetVariantIntegervEXT Wm3glGetVariantIntegervEXT

typedef void (APIENTRY* pfn_glGetVariantFloatvEXT) (GLuint, GLenum, GLfloat*);
WM3_EXTERN pfn_glGetVariantFloatvEXT Wm3glGetVariantFloatvEXT;
#define glGetVariantFloatvEXT Wm3glGetVariantFloatvEXT

typedef void (APIENTRY* pfn_glGetVariantPointervEXT) (GLuint, GLenum, GLvoid**);
WM3_EXTERN pfn_glGetVariantPointervEXT Wm3glGetVariantPointervEXT;
#define glGetVariantPointervEXT Wm3glGetVariantPointervEXT

typedef void (APIENTRY* pfn_glGetInvariantBooleanvEXT) (GLuint, GLenum, GLboolean*);
WM3_EXTERN pfn_glGetInvariantBooleanvEXT Wm3glGetInvariantBooleanvEXT;
#define glGetInvariantBooleanvEXT Wm3glGetInvariantBooleanvEXT

typedef void (APIENTRY* pfn_glGetInvariantIntegervEXT) (GLuint, GLenum, GLint*);
WM3_EXTERN pfn_glGetInvariantIntegervEXT Wm3glGetInvariantIntegervEXT;
#define glGetInvariantIntegervEXT Wm3glGetInvariantIntegervEXT

typedef void (APIENTRY* pfn_glGetInvariantFloatvEXT) (GLuint, GLenum, GLfloat*);
WM3_EXTERN pfn_glGetInvariantFloatvEXT Wm3glGetInvariantFloatvEXT;
#define glGetInvariantFloatvEXT Wm3glGetInvariantFloatvEXT

typedef void (APIENTRY* pfn_glGetLocalConstantBooleanvEXT) (GLuint, GLenum, GLboolean*);
WM3_EXTERN pfn_glGetLocalConstantBooleanvEXT Wm3glGetLocalConstantBooleanvEXT;
#define glGetLocalConstantBooleanvEXT Wm3glGetLocalConstantBooleanvEXT

typedef void (APIENTRY* pfn_glGetLocalConstantIntegervEXT) (GLuint, GLenum, GLint*);
WM3_EXTERN pfn_glGetLocalConstantIntegervEXT Wm3glGetLocalConstantIntegervEXT;
#define glGetLocalConstantIntegervEXT Wm3glGetLocalConstantIntegervEXT

typedef void (APIENTRY* pfn_glGetLocalConstantFloatvEXT) (GLuint, GLenum, GLfloat*);
WM3_EXTERN pfn_glGetLocalConstantFloatvEXT Wm3glGetLocalConstantFloatvEXT;
#define glGetLocalConstantFloatvEXT Wm3glGetLocalConstantFloatvEXT
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_ATI_vertex_streams;
WM3_EXTERN int Wm3NumFunctions_GL_ATI_vertex_streams;
#ifndef GL_ATI_vertex_streams
#define GL_ATI_vertex_streams
#define WM3_DEFINED_GL_ATI_vertex_streams
#define GL_MAX_VERTEX_STREAMS_ATI         0x876B
#define GL_VERTEX_STREAM0_ATI             0x876C
#define GL_VERTEX_STREAM1_ATI             0x876D
#define GL_VERTEX_STREAM2_ATI             0x876E
#define GL_VERTEX_STREAM3_ATI             0x876F
#define GL_VERTEX_STREAM4_ATI             0x8770
#define GL_VERTEX_STREAM5_ATI             0x8771
#define GL_VERTEX_STREAM6_ATI             0x8772
#define GL_VERTEX_STREAM7_ATI             0x8773
#define GL_VERTEX_SOURCE_ATI              0x8774

typedef void (APIENTRY* pfn_glVertexStream1sATI) (GLenum, GLshort);
WM3_EXTERN pfn_glVertexStream1sATI Wm3glVertexStream1sATI;
#define glVertexStream1sATI Wm3glVertexStream1sATI

typedef void (APIENTRY* pfn_glVertexStream1svATI) (GLenum, const GLshort*);
WM3_EXTERN pfn_glVertexStream1svATI Wm3glVertexStream1svATI;
#define glVertexStream1svATI Wm3glVertexStream1svATI

typedef void (APIENTRY* pfn_glVertexStream1iATI) (GLenum, GLint);
WM3_EXTERN pfn_glVertexStream1iATI Wm3glVertexStream1iATI;
#define glVertexStream1iATI Wm3glVertexStream1iATI

typedef void (APIENTRY* pfn_glVertexStream1ivATI) (GLenum, const GLint*);
WM3_EXTERN pfn_glVertexStream1ivATI Wm3glVertexStream1ivATI;
#define glVertexStream1ivATI Wm3glVertexStream1ivATI

typedef void (APIENTRY* pfn_glVertexStream1fATI) (GLenum, GLfloat);
WM3_EXTERN pfn_glVertexStream1fATI Wm3glVertexStream1fATI;
#define glVertexStream1fATI Wm3glVertexStream1fATI

typedef void (APIENTRY* pfn_glVertexStream1fvATI) (GLenum, const GLfloat*);
WM3_EXTERN pfn_glVertexStream1fvATI Wm3glVertexStream1fvATI;
#define glVertexStream1fvATI Wm3glVertexStream1fvATI

typedef void (APIENTRY* pfn_glVertexStream1dATI) (GLenum, GLdouble);
WM3_EXTERN pfn_glVertexStream1dATI Wm3glVertexStream1dATI;
#define glVertexStream1dATI Wm3glVertexStream1dATI

typedef void (APIENTRY* pfn_glVertexStream1dvATI) (GLenum, const GLdouble*);
WM3_EXTERN pfn_glVertexStream1dvATI Wm3glVertexStream1dvATI;
#define glVertexStream1dvATI Wm3glVertexStream1dvATI

typedef void (APIENTRY* pfn_glVertexStream2sATI) (GLenum, GLshort, GLshort);
WM3_EXTERN pfn_glVertexStream2sATI Wm3glVertexStream2sATI;
#define glVertexStream2sATI Wm3glVertexStream2sATI

typedef void (APIENTRY* pfn_glVertexStream2svATI) (GLenum, const GLshort*);
WM3_EXTERN pfn_glVertexStream2svATI Wm3glVertexStream2svATI;
#define glVertexStream2svATI Wm3glVertexStream2svATI

typedef void (APIENTRY* pfn_glVertexStream2iATI) (GLenum, GLint, GLint);
WM3_EXTERN pfn_glVertexStream2iATI Wm3glVertexStream2iATI;
#define glVertexStream2iATI Wm3glVertexStream2iATI

typedef void (APIENTRY* pfn_glVertexStream2ivATI) (GLenum, const GLint*);
WM3_EXTERN pfn_glVertexStream2ivATI Wm3glVertexStream2ivATI;
#define glVertexStream2ivATI Wm3glVertexStream2ivATI

typedef void (APIENTRY* pfn_glVertexStream2fATI) (GLenum, GLfloat, GLfloat);
WM3_EXTERN pfn_glVertexStream2fATI Wm3glVertexStream2fATI;
#define glVertexStream2fATI Wm3glVertexStream2fATI

typedef void (APIENTRY* pfn_glVertexStream2fvATI) (GLenum, const GLfloat*);
WM3_EXTERN pfn_glVertexStream2fvATI Wm3glVertexStream2fvATI;
#define glVertexStream2fvATI Wm3glVertexStream2fvATI

typedef void (APIENTRY* pfn_glVertexStream2dATI) (GLenum, GLdouble, GLdouble);
WM3_EXTERN pfn_glVertexStream2dATI Wm3glVertexStream2dATI;
#define glVertexStream2dATI Wm3glVertexStream2dATI

typedef void (APIENTRY* pfn_glVertexStream2dvATI) (GLenum, const GLdouble*);
WM3_EXTERN pfn_glVertexStream2dvATI Wm3glVertexStream2dvATI;
#define glVertexStream2dvATI Wm3glVertexStream2dvATI

typedef void (APIENTRY* pfn_glVertexStream3sATI) (GLenum, GLshort, GLshort, GLshort);
WM3_EXTERN pfn_glVertexStream3sATI Wm3glVertexStream3sATI;
#define glVertexStream3sATI Wm3glVertexStream3sATI

typedef void (APIENTRY* pfn_glVertexStream3svATI) (GLenum, const GLshort*);
WM3_EXTERN pfn_glVertexStream3svATI Wm3glVertexStream3svATI;
#define glVertexStream3svATI Wm3glVertexStream3svATI

typedef void (APIENTRY* pfn_glVertexStream3iATI) (GLenum, GLint, GLint, GLint);
WM3_EXTERN pfn_glVertexStream3iATI Wm3glVertexStream3iATI;
#define glVertexStream3iATI Wm3glVertexStream3iATI

typedef void (APIENTRY* pfn_glVertexStream3ivATI) (GLenum, const GLint*);
WM3_EXTERN pfn_glVertexStream3ivATI Wm3glVertexStream3ivATI;
#define glVertexStream3ivATI Wm3glVertexStream3ivATI

typedef void (APIENTRY* pfn_glVertexStream3fATI) (GLenum, GLfloat, GLfloat, GLfloat);
WM3_EXTERN pfn_glVertexStream3fATI Wm3glVertexStream3fATI;
#define glVertexStream3fATI Wm3glVertexStream3fATI

typedef void (APIENTRY* pfn_glVertexStream3fvATI) (GLenum, const GLfloat*);
WM3_EXTERN pfn_glVertexStream3fvATI Wm3glVertexStream3fvATI;
#define glVertexStream3fvATI Wm3glVertexStream3fvATI

typedef void (APIENTRY* pfn_glVertexStream3dATI) (GLenum, GLdouble, GLdouble, GLdouble);
WM3_EXTERN pfn_glVertexStream3dATI Wm3glVertexStream3dATI;
#define glVertexStream3dATI Wm3glVertexStream3dATI

typedef void (APIENTRY* pfn_glVertexStream3dvATI) (GLenum, const GLdouble*);
WM3_EXTERN pfn_glVertexStream3dvATI Wm3glVertexStream3dvATI;
#define glVertexStream3dvATI Wm3glVertexStream3dvATI

typedef void (APIENTRY* pfn_glVertexStream4sATI) (GLenum, GLshort, GLshort, GLshort, GLshort);
WM3_EXTERN pfn_glVertexStream4sATI Wm3glVertexStream4sATI;
#define glVertexStream4sATI Wm3glVertexStream4sATI

typedef void (APIENTRY* pfn_glVertexStream4svATI) (GLenum, const GLshort*);
WM3_EXTERN pfn_glVertexStream4svATI Wm3glVertexStream4svATI;
#define glVertexStream4svATI Wm3glVertexStream4svATI

typedef void (APIENTRY* pfn_glVertexStream4iATI) (GLenum, GLint, GLint, GLint, GLint);
WM3_EXTERN pfn_glVertexStream4iATI Wm3glVertexStream4iATI;
#define glVertexStream4iATI Wm3glVertexStream4iATI

typedef void (APIENTRY* pfn_glVertexStream4ivATI) (GLenum, const GLint*);
WM3_EXTERN pfn_glVertexStream4ivATI Wm3glVertexStream4ivATI;
#define glVertexStream4ivATI Wm3glVertexStream4ivATI

typedef void (APIENTRY* pfn_glVertexStream4fATI) (GLenum, GLfloat, GLfloat, GLfloat, GLfloat);
WM3_EXTERN pfn_glVertexStream4fATI Wm3glVertexStream4fATI;
#define glVertexStream4fATI Wm3glVertexStream4fATI

typedef void (APIENTRY* pfn_glVertexStream4fvATI) (GLenum, const GLfloat*);
WM3_EXTERN pfn_glVertexStream4fvATI Wm3glVertexStream4fvATI;
#define glVertexStream4fvATI Wm3glVertexStream4fvATI

typedef void (APIENTRY* pfn_glVertexStream4dATI) (GLenum, GLdouble, GLdouble, GLdouble, GLdouble);
WM3_EXTERN pfn_glVertexStream4dATI Wm3glVertexStream4dATI;
#define glVertexStream4dATI Wm3glVertexStream4dATI

typedef void (APIENTRY* pfn_glVertexStream4dvATI) (GLenum, const GLdouble*);
WM3_EXTERN pfn_glVertexStream4dvATI Wm3glVertexStream4dvATI;
#define glVertexStream4dvATI Wm3glVertexStream4dvATI

typedef void (APIENTRY* pfn_glNormalStream3bATI) (GLenum, GLbyte, GLbyte, GLbyte);
WM3_EXTERN pfn_glNormalStream3bATI Wm3glNormalStream3bATI;
#define glNormalStream3bATI Wm3glNormalStream3bATI

typedef void (APIENTRY* pfn_glNormalStream3bvATI) (GLenum, const GLbyte*);
WM3_EXTERN pfn_glNormalStream3bvATI Wm3glNormalStream3bvATI;
#define glNormalStream3bvATI Wm3glNormalStream3bvATI

typedef void (APIENTRY* pfn_glNormalStream3sATI) (GLenum, GLshort, GLshort, GLshort);
WM3_EXTERN pfn_glNormalStream3sATI Wm3glNormalStream3sATI;
#define glNormalStream3sATI Wm3glNormalStream3sATI

typedef void (APIENTRY* pfn_glNormalStream3svATI) (GLenum, const GLshort*);
WM3_EXTERN pfn_glNormalStream3svATI Wm3glNormalStream3svATI;
#define glNormalStream3svATI Wm3glNormalStream3svATI

typedef void (APIENTRY* pfn_glNormalStream3iATI) (GLenum, GLint, GLint, GLint);
WM3_EXTERN pfn_glNormalStream3iATI Wm3glNormalStream3iATI;
#define glNormalStream3iATI Wm3glNormalStream3iATI

typedef void (APIENTRY* pfn_glNormalStream3ivATI) (GLenum, const GLint*);
WM3_EXTERN pfn_glNormalStream3ivATI Wm3glNormalStream3ivATI;
#define glNormalStream3ivATI Wm3glNormalStream3ivATI

typedef void (APIENTRY* pfn_glNormalStream3fATI) (GLenum, GLfloat, GLfloat, GLfloat);
WM3_EXTERN pfn_glNormalStream3fATI Wm3glNormalStream3fATI;
#define glNormalStream3fATI Wm3glNormalStream3fATI

typedef void (APIENTRY* pfn_glNormalStream3fvATI) (GLenum, const GLfloat*);
WM3_EXTERN pfn_glNormalStream3fvATI Wm3glNormalStream3fvATI;
#define glNormalStream3fvATI Wm3glNormalStream3fvATI

typedef void (APIENTRY* pfn_glNormalStream3dATI) (GLenum, GLdouble, GLdouble, GLdouble);
WM3_EXTERN pfn_glNormalStream3dATI Wm3glNormalStream3dATI;
#define glNormalStream3dATI Wm3glNormalStream3dATI

typedef void (APIENTRY* pfn_glNormalStream3dvATI) (GLenum, const GLdouble*);
WM3_EXTERN pfn_glNormalStream3dvATI Wm3glNormalStream3dvATI;
#define glNormalStream3dvATI Wm3glNormalStream3dvATI

typedef void (APIENTRY* pfn_glClientActiveVertexStreamATI) (GLenum);
WM3_EXTERN pfn_glClientActiveVertexStreamATI Wm3glClientActiveVertexStreamATI;
#define glClientActiveVertexStreamATI Wm3glClientActiveVertexStreamATI

typedef void (APIENTRY* pfn_glVertexBlendEnviATI) (GLenum, GLint);
WM3_EXTERN pfn_glVertexBlendEnviATI Wm3glVertexBlendEnviATI;
#define glVertexBlendEnviATI Wm3glVertexBlendEnviATI

typedef void (APIENTRY* pfn_glVertexBlendEnvfATI) (GLenum, GLfloat);
WM3_EXTERN pfn_glVertexBlendEnvfATI Wm3glVertexBlendEnvfATI;
#define glVertexBlendEnvfATI Wm3glVertexBlendEnvfATI
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_ATI_element_array;
WM3_EXTERN int Wm3NumFunctions_GL_ATI_element_array;
#ifndef GL_ATI_element_array
#define GL_ATI_element_array
#define WM3_DEFINED_GL_ATI_element_array
#define GL_ELEMENT_ARRAY_ATI              0x8768
#define GL_ELEMENT_ARRAY_TYPE_ATI         0x8769
#define GL_ELEMENT_ARRAY_POINTER_ATI      0x876A

typedef void (APIENTRY* pfn_glElementPointerATI) (GLenum, const GLvoid*);
WM3_EXTERN pfn_glElementPointerATI Wm3glElementPointerATI;
#define glElementPointerATI Wm3glElementPointerATI

typedef void (APIENTRY* pfn_glDrawElementArrayATI) (GLenum, GLsizei);
WM3_EXTERN pfn_glDrawElementArrayATI Wm3glDrawElementArrayATI;
#define glDrawElementArrayATI Wm3glDrawElementArrayATI

typedef void (APIENTRY* pfn_glDrawRangeElementArrayATI) (GLenum, GLuint, GLuint, GLsizei);
WM3_EXTERN pfn_glDrawRangeElementArrayATI Wm3glDrawRangeElementArrayATI;
#define glDrawRangeElementArrayATI Wm3glDrawRangeElementArrayATI
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_SUN_mesh_array;
WM3_EXTERN int Wm3NumFunctions_GL_SUN_mesh_array;
#ifndef GL_SUN_mesh_array
#define GL_SUN_mesh_array
#define WM3_DEFINED_GL_SUN_mesh_array
#define GL_QUAD_MESH_SUN                  0x8614
#define GL_TRIANGLE_MESH_SUN              0x8615

typedef void (APIENTRY* pfn_glDrawMeshArraysSUN) (GLenum, GLint, GLsizei, GLsizei);
WM3_EXTERN pfn_glDrawMeshArraysSUN Wm3glDrawMeshArraysSUN;
#define glDrawMeshArraysSUN Wm3glDrawMeshArraysSUN
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_SUN_slice_accum;
WM3_EXTERN int Wm3NumFunctions_GL_SUN_slice_accum;
#ifndef GL_SUN_slice_accum
#define GL_SUN_slice_accum
#define WM3_DEFINED_GL_SUN_slice_accum
#define GL_SLICE_ACCUM_SUN                0x85CC
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_NV_multisample_filter_hint;
WM3_EXTERN int Wm3NumFunctions_GL_NV_multisample_filter_hint;
#ifndef GL_NV_multisample_filter_hint
#define GL_NV_multisample_filter_hint
#define WM3_DEFINED_GL_NV_multisample_filter_hint
#define GL_MULTISAMPLE_FILTER_HINT_NV     0x8534
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_NV_depth_clamp;
WM3_EXTERN int Wm3NumFunctions_GL_NV_depth_clamp;
#ifndef GL_NV_depth_clamp
#define GL_NV_depth_clamp
#define WM3_DEFINED_GL_NV_depth_clamp
#define GL_DEPTH_CLAMP_NV                 0x864F
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_NV_occlusion_query;
WM3_EXTERN int Wm3NumFunctions_GL_NV_occlusion_query;
#ifndef GL_NV_occlusion_query
#define GL_NV_occlusion_query
#define WM3_DEFINED_GL_NV_occlusion_query
#define GL_PIXEL_COUNTER_BITS_NV          0x8864
#define GL_CURRENT_OCCLUSION_QUERY_ID_NV  0x8865
#define GL_PIXEL_COUNT_NV                 0x8866
#define GL_PIXEL_COUNT_AVAILABLE_NV       0x8867

typedef void (APIENTRY* pfn_glGenOcclusionQueriesNV) (GLsizei, GLuint*);
WM3_EXTERN pfn_glGenOcclusionQueriesNV Wm3glGenOcclusionQueriesNV;
#define glGenOcclusionQueriesNV Wm3glGenOcclusionQueriesNV

typedef void (APIENTRY* pfn_glDeleteOcclusionQueriesNV) (GLsizei, const GLuint*);
WM3_EXTERN pfn_glDeleteOcclusionQueriesNV Wm3glDeleteOcclusionQueriesNV;
#define glDeleteOcclusionQueriesNV Wm3glDeleteOcclusionQueriesNV

typedef GLboolean (APIENTRY* pfn_glIsOcclusionQueryNV) (GLuint);
WM3_EXTERN pfn_glIsOcclusionQueryNV Wm3glIsOcclusionQueryNV;
#define glIsOcclusionQueryNV Wm3glIsOcclusionQueryNV

typedef void (APIENTRY* pfn_glBeginOcclusionQueryNV) (GLuint);
WM3_EXTERN pfn_glBeginOcclusionQueryNV Wm3glBeginOcclusionQueryNV;
#define glBeginOcclusionQueryNV Wm3glBeginOcclusionQueryNV

typedef void (APIENTRY* pfn_glEndOcclusionQueryNV) (void);
WM3_EXTERN pfn_glEndOcclusionQueryNV Wm3glEndOcclusionQueryNV;
#define glEndOcclusionQueryNV Wm3glEndOcclusionQueryNV

typedef void (APIENTRY* pfn_glGetOcclusionQueryivNV) (GLuint, GLenum, GLint*);
WM3_EXTERN pfn_glGetOcclusionQueryivNV Wm3glGetOcclusionQueryivNV;
#define glGetOcclusionQueryivNV Wm3glGetOcclusionQueryivNV

typedef void (APIENTRY* pfn_glGetOcclusionQueryuivNV) (GLuint, GLenum, GLuint*);
WM3_EXTERN pfn_glGetOcclusionQueryuivNV Wm3glGetOcclusionQueryuivNV;
#define glGetOcclusionQueryuivNV Wm3glGetOcclusionQueryuivNV
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_NV_point_sprite;
WM3_EXTERN int Wm3NumFunctions_GL_NV_point_sprite;
#ifndef GL_NV_point_sprite
#define GL_NV_point_sprite
#define WM3_DEFINED_GL_NV_point_sprite
#define GL_POINT_SPRITE_NV                0x8861
#define GL_COORD_REPLACE_NV               0x8862
#define GL_POINT_SPRITE_R_MODE_NV         0x8863

typedef void (APIENTRY* pfn_glPointParameteriNV) (GLenum, GLint);
WM3_EXTERN pfn_glPointParameteriNV Wm3glPointParameteriNV;
#define glPointParameteriNV Wm3glPointParameteriNV

typedef void (APIENTRY* pfn_glPointParameterivNV) (GLenum, const GLint*);
WM3_EXTERN pfn_glPointParameterivNV Wm3glPointParameterivNV;
#define glPointParameterivNV Wm3glPointParameterivNV
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_NV_texture_shader3;
WM3_EXTERN int Wm3NumFunctions_GL_NV_texture_shader3;
#ifndef GL_NV_texture_shader3
#define GL_NV_texture_shader3
#define WM3_DEFINED_GL_NV_texture_shader3
#define GL_OFFSET_PROJECTIVE_TEXTURE_2D_NV              0x8850
#define GL_OFFSET_PROJECTIVE_TEXTURE_2D_SCALE_NV        0x8851
#define GL_OFFSET_PROJECTIVE_TEXTURE_RECTANGLE_NV       0x8852
#define GL_OFFSET_PROJECTIVE_TEXTURE_RECTANGLE_SCALE_NV 0x8853
#define GL_OFFSET_HILO_TEXTURE_2D_NV                    0x8854
#define GL_OFFSET_HILO_TEXTURE_RECTANGLE_NV             0x8855
#define GL_OFFSET_HILO_PROJECTIVE_TEXTURE_2D_NV         0x8856
#define GL_OFFSET_HILO_PROJECTIVE_TEXTURE_RECTANGLE_NV  0x8857
#define GL_DEPENDENT_HILO_TEXTURE_2D_NV                 0x8858
#define GL_DEPENDENT_RGB_TEXTURE_3D_NV                  0x8859
#define GL_DEPENDENT_RGB_TEXTURE_CUBE_MAP_NV            0x885A
#define GL_DOT_PRODUCT_PASS_THROUGH_NV                  0x885B
#define GL_DOT_PRODUCT_TEXTURE_1D_NV                    0x885C
#define GL_DOT_PRODUCT_AFFINE_DEPTH_REPLACE_NV          0x885D
#define GL_HILO8_NV                                     0x885E
#define GL_SIGNED_HILO8_NV                              0x885F
#define GL_FORCE_BLUE_TO_ONE_NV                         0x8860
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_NV_vertex_program1_1;
WM3_EXTERN int Wm3NumFunctions_GL_NV_vertex_program1_1;
#ifndef GL_NV_vertex_program1_1
#define GL_NV_vertex_program1_1
#define WM3_DEFINED_GL_NV_vertex_program1_1
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_EXT_shadow_funcs;
WM3_EXTERN int Wm3NumFunctions_GL_EXT_shadow_funcs;
#ifndef GL_EXT_shadow_funcs
#define GL_EXT_shadow_funcs
#define WM3_DEFINED_GL_EXT_shadow_funcs
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_EXT_stencil_two_side;
WM3_EXTERN int Wm3NumFunctions_GL_EXT_stencil_two_side;
#ifndef GL_EXT_stencil_two_side
#define GL_EXT_stencil_two_side
#define WM3_DEFINED_GL_EXT_stencil_two_side
#define GL_STENCIL_TEST_TWO_SIDE_EXT      0x8910
#define GL_ACTIVE_STENCIL_FACE_EXT        0x8911

typedef void (APIENTRY* pfn_glActiveStencilFaceEXT) (GLenum);
WM3_EXTERN pfn_glActiveStencilFaceEXT Wm3glActiveStencilFaceEXT;
#define glActiveStencilFaceEXT Wm3glActiveStencilFaceEXT
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_ATI_text_fragment_shader;
WM3_EXTERN int Wm3NumFunctions_GL_ATI_text_fragment_shader;
#ifndef GL_ATI_text_fragment_shader
#define GL_ATI_text_fragment_shader
#define WM3_DEFINED_GL_ATI_text_fragment_shader
#define GL_TEXT_FRAGMENT_SHADER_ATI       0x8200
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_APPLE_client_storage;
WM3_EXTERN int Wm3NumFunctions_GL_APPLE_client_storage;
#ifndef GL_APPLE_client_storage
#define GL_APPLE_client_storage
#define WM3_DEFINED_GL_APPLE_client_storage
#define GL_UNPACK_CLIENT_STORAGE_APPLE    0x85B2
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_APPLE_element_array;
WM3_EXTERN int Wm3NumFunctions_GL_APPLE_element_array;
#ifndef GL_APPLE_element_array
#define GL_APPLE_element_array
#define WM3_DEFINED_GL_APPLE_element_array
#define GL_ELEMENT_ARRAY_APPLE            0x8768
#define GL_ELEMENT_ARRAY_TYPE_APPLE       0x8769
#define GL_ELEMENT_ARRAY_POINTER_APPLE    0x876A

typedef void (APIENTRY* pfn_glElementPointerAPPLE) (GLenum, const GLvoid*);
WM3_EXTERN pfn_glElementPointerAPPLE Wm3glElementPointerAPPLE;
#define glElementPointerAPPLE Wm3glElementPointerAPPLE

typedef void (APIENTRY* pfn_glDrawElementArrayAPPLE) (GLenum, GLint, GLsizei);
WM3_EXTERN pfn_glDrawElementArrayAPPLE Wm3glDrawElementArrayAPPLE;
#define glDrawElementArrayAPPLE Wm3glDrawElementArrayAPPLE

typedef void (APIENTRY* pfn_glDrawRangeElementArrayAPPLE) (GLenum, GLuint, GLuint, GLint, GLsizei);
WM3_EXTERN pfn_glDrawRangeElementArrayAPPLE Wm3glDrawRangeElementArrayAPPLE;
#define glDrawRangeElementArrayAPPLE Wm3glDrawRangeElementArrayAPPLE

typedef void (APIENTRY* pfn_glMultiDrawElementArrayAPPLE) (GLenum, const GLint*, const GLsizei*, GLsizei);
WM3_EXTERN pfn_glMultiDrawElementArrayAPPLE Wm3glMultiDrawElementArrayAPPLE;
#define glMultiDrawElementArrayAPPLE Wm3glMultiDrawElementArrayAPPLE

typedef void (APIENTRY* pfn_glMultiDrawRangeElementArrayAPPLE) (GLenum, GLuint, GLuint, const GLint*, const GLsizei*, GLsizei);
WM3_EXTERN pfn_glMultiDrawRangeElementArrayAPPLE Wm3glMultiDrawRangeElementArrayAPPLE;
#define glMultiDrawRangeElementArrayAPPLE Wm3glMultiDrawRangeElementArrayAPPLE
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_APPLE_fence;
WM3_EXTERN int Wm3NumFunctions_GL_APPLE_fence;
#ifndef GL_APPLE_fence
#define GL_APPLE_fence
#define WM3_DEFINED_GL_APPLE_fence
#define GL_DRAW_PIXELS_APPLE              0x8A0A
#define GL_FENCE_APPLE                    0x8A0B

typedef void (APIENTRY* pfn_glGenFencesAPPLE) (GLsizei, GLuint*);
WM3_EXTERN pfn_glGenFencesAPPLE Wm3glGenFencesAPPLE;
#define glGenFencesAPPLE Wm3glGenFencesAPPLE

typedef void (APIENTRY* pfn_glDeleteFencesAPPLE) (GLsizei, const GLuint*);
WM3_EXTERN pfn_glDeleteFencesAPPLE Wm3glDeleteFencesAPPLE;
#define glDeleteFencesAPPLE Wm3glDeleteFencesAPPLE

typedef void (APIENTRY* pfn_glSetFenceAPPLE) (GLuint);
WM3_EXTERN pfn_glSetFenceAPPLE Wm3glSetFenceAPPLE;
#define glSetFenceAPPLE Wm3glSetFenceAPPLE

typedef GLboolean (APIENTRY* pfn_glIsFenceAPPLE) (GLuint);
WM3_EXTERN pfn_glIsFenceAPPLE Wm3glIsFenceAPPLE;
#define glIsFenceAPPLE Wm3glIsFenceAPPLE

typedef GLboolean (APIENTRY* pfn_glTestFenceAPPLE) (GLuint);
WM3_EXTERN pfn_glTestFenceAPPLE Wm3glTestFenceAPPLE;
#define glTestFenceAPPLE Wm3glTestFenceAPPLE

typedef void (APIENTRY* pfn_glFinishFenceAPPLE) (GLuint);
WM3_EXTERN pfn_glFinishFenceAPPLE Wm3glFinishFenceAPPLE;
#define glFinishFenceAPPLE Wm3glFinishFenceAPPLE

typedef GLboolean (APIENTRY* pfn_glTestObjectAPPLE) (GLenum, GLuint);
WM3_EXTERN pfn_glTestObjectAPPLE Wm3glTestObjectAPPLE;
#define glTestObjectAPPLE Wm3glTestObjectAPPLE

typedef void (APIENTRY* pfn_glFinishObjectAPPLE) (GLenum, GLint);
WM3_EXTERN pfn_glFinishObjectAPPLE Wm3glFinishObjectAPPLE;
#define glFinishObjectAPPLE Wm3glFinishObjectAPPLE
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_APPLE_vertex_array_object;
WM3_EXTERN int Wm3NumFunctions_GL_APPLE_vertex_array_object;
#ifndef GL_APPLE_vertex_array_object
#define GL_APPLE_vertex_array_object
#define WM3_DEFINED_GL_APPLE_vertex_array_object
#define GL_VERTEX_ARRAY_BINDING_APPLE     0x85B5

typedef void (APIENTRY* pfn_glBindVertexArrayAPPLE) (GLuint);
WM3_EXTERN pfn_glBindVertexArrayAPPLE Wm3glBindVertexArrayAPPLE;
#define glBindVertexArrayAPPLE Wm3glBindVertexArrayAPPLE

typedef void (APIENTRY* pfn_glDeleteVertexArraysAPPLE) (GLsizei, const GLuint*);
WM3_EXTERN pfn_glDeleteVertexArraysAPPLE Wm3glDeleteVertexArraysAPPLE;
#define glDeleteVertexArraysAPPLE Wm3glDeleteVertexArraysAPPLE

typedef void (APIENTRY* pfn_glGenVertexArraysAPPLE) (GLsizei, const GLuint*);
WM3_EXTERN pfn_glGenVertexArraysAPPLE Wm3glGenVertexArraysAPPLE;
#define glGenVertexArraysAPPLE Wm3glGenVertexArraysAPPLE

typedef GLboolean (APIENTRY* pfn_glIsVertexArrayAPPLE) (GLuint);
WM3_EXTERN pfn_glIsVertexArrayAPPLE Wm3glIsVertexArrayAPPLE;
#define glIsVertexArrayAPPLE Wm3glIsVertexArrayAPPLE
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_APPLE_vertex_array_range;
WM3_EXTERN int Wm3NumFunctions_GL_APPLE_vertex_array_range;
#ifndef GL_APPLE_vertex_array_range
#define GL_APPLE_vertex_array_range
#define WM3_DEFINED_GL_APPLE_vertex_array_range
#define GL_VERTEX_ARRAY_RANGE_APPLE         0x851D
#define GL_VERTEX_ARRAY_RANGE_LENGTH_APPLE  0x851E
#define GL_VERTEX_ARRAY_STORAGE_HINT_APPLE  0x851F
#define GL_VERTEX_ARRAY_RANGE_POINTER_APPLE 0x8521
#define GL_STORAGE_CACHED_APPLE             0x85BE
#define GL_STORAGE_SHARED_APPLE             0x85BF

typedef void (APIENTRY* pfn_glVertexArrayRangeAPPLE) (GLsizei, GLvoid*);
WM3_EXTERN pfn_glVertexArrayRangeAPPLE Wm3glVertexArrayRangeAPPLE;
#define glVertexArrayRangeAPPLE Wm3glVertexArrayRangeAPPLE

typedef void (APIENTRY* pfn_glFlushVertexArrayRangeAPPLE) (GLsizei, GLvoid*);
WM3_EXTERN pfn_glFlushVertexArrayRangeAPPLE Wm3glFlushVertexArrayRangeAPPLE;
#define glFlushVertexArrayRangeAPPLE Wm3glFlushVertexArrayRangeAPPLE

typedef void (APIENTRY* pfn_glVertexArrayParameteriAPPLE) (GLenum, GLint);
WM3_EXTERN pfn_glVertexArrayParameteriAPPLE Wm3glVertexArrayParameteriAPPLE;
#define glVertexArrayParameteriAPPLE Wm3glVertexArrayParameteriAPPLE
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_APPLE_ycbcr_422;
WM3_EXTERN int Wm3NumFunctions_GL_APPLE_ycbcr_422;
#ifndef GL_APPLE_ycbcr_422
#define GL_APPLE_ycbcr_422
#define WM3_DEFINED_GL_APPLE_ycbcr_422
#define GL_YCBCR_422_APPLE                0x85B9
#define GL_UNSIGNED_SHORT_8_8_APPLE       0x85BA
#define GL_UNSIGNED_SHORT_8_8_REV_APPLE   0x85BB
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_S3_s3tc;
WM3_EXTERN int Wm3NumFunctions_GL_S3_s3tc;
#ifndef GL_S3_s3tc
#define GL_S3_s3tc
#define WM3_DEFINED_GL_S3_s3tc
#define GL_RGB_S3TC                       0x83A0
#define GL_RGB4_S3TC                      0x83A1
#define GL_RGBA_S3TC                      0x83A2
#define GL_RGBA4_S3TC                     0x83A3
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_ATI_draw_buffers;
WM3_EXTERN int Wm3NumFunctions_GL_ATI_draw_buffers;
#ifndef GL_ATI_draw_buffers
#define GL_ATI_draw_buffers
#define WM3_DEFINED_GL_ATI_draw_buffers
#define GL_MAX_DRAW_BUFFERS_ATI           0x8824
#define GL_DRAW_BUFFER0_ATI               0x8825
#define GL_DRAW_BUFFER1_ATI               0x8826
#define GL_DRAW_BUFFER2_ATI               0x8827
#define GL_DRAW_BUFFER3_ATI               0x8828
#define GL_DRAW_BUFFER4_ATI               0x8829
#define GL_DRAW_BUFFER5_ATI               0x882A
#define GL_DRAW_BUFFER6_ATI               0x882B
#define GL_DRAW_BUFFER7_ATI               0x882C
#define GL_DRAW_BUFFER8_ATI               0x882D
#define GL_DRAW_BUFFER9_ATI               0x882E
#define GL_DRAW_BUFFER10_ATI              0x882F
#define GL_DRAW_BUFFER11_ATI              0x8830
#define GL_DRAW_BUFFER12_ATI              0x8831
#define GL_DRAW_BUFFER13_ATI              0x8832
#define GL_DRAW_BUFFER14_ATI              0x8833
#define GL_DRAW_BUFFER15_ATI              0x8834

typedef void (APIENTRY* pfn_glDrawBuffersATI) (GLsizei, const GLenum*);
WM3_EXTERN pfn_glDrawBuffersATI Wm3glDrawBuffersATI;
#define glDrawBuffersATI Wm3glDrawBuffersATI
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_ATI_pixel_format_float;
WM3_EXTERN int Wm3NumFunctions_GL_ATI_pixel_format_float;
#ifndef GL_ATI_pixel_format_float
#define GL_ATI_pixel_format_float
#define WM3_DEFINED_GL_ATI_pixel_format_float
#define GL_TYPE_RGBA_FLOAT_ATI            0x8820
#define GL_COLOR_CLEAR_UNCLAMPED_VALUE_ATI 0x8835
/* This is really a WGL extension, but defines some associated GL enums.
 * ATI does not export "GL_ATI_pixel_format_float" in the GL_EXTENSIONS string.
 */
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_ATI_texture_env_combine3;
WM3_EXTERN int Wm3NumFunctions_GL_ATI_texture_env_combine3;
#ifndef GL_ATI_texture_env_combine3
#define GL_ATI_texture_env_combine3
#define WM3_DEFINED_GL_ATI_texture_env_combine3
#define GL_MODULATE_ADD_ATI               0x8744
#define GL_MODULATE_SIGNED_ADD_ATI        0x8745
#define GL_MODULATE_SUBTRACT_ATI          0x8746
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_ATI_texture_float;
WM3_EXTERN int Wm3NumFunctions_GL_ATI_texture_float;
#ifndef GL_ATI_texture_float
#define GL_ATI_texture_float
#define WM3_DEFINED_GL_ATI_texture_float
#define GL_RGBA_FLOAT32_ATI               0x8814
#define GL_RGB_FLOAT32_ATI                0x8815
#define GL_ALPHA_FLOAT32_ATI              0x8816
#define GL_INTENSITY_FLOAT32_ATI          0x8817
#define GL_LUMINANCE_FLOAT32_ATI          0x8818
#define GL_LUMINANCE_ALPHA_FLOAT32_ATI    0x8819
#define GL_RGBA_FLOAT16_ATI               0x881A
#define GL_RGB_FLOAT16_ATI                0x881B
#define GL_ALPHA_FLOAT16_ATI              0x881C
#define GL_INTENSITY_FLOAT16_ATI          0x881D
#define GL_LUMINANCE_FLOAT16_ATI          0x881E
#define GL_LUMINANCE_ALPHA_FLOAT16_ATI    0x881F
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_NV_float_buffer;
WM3_EXTERN int Wm3NumFunctions_GL_NV_float_buffer;
#ifndef GL_NV_float_buffer
#define GL_NV_float_buffer
#define WM3_DEFINED_GL_NV_float_buffer
#define GL_FLOAT_R_NV                     0x8880
#define GL_FLOAT_RG_NV                    0x8881
#define GL_FLOAT_RGB_NV                   0x8882
#define GL_FLOAT_RGBA_NV                  0x8883
#define GL_FLOAT_R16_NV                   0x8884
#define GL_FLOAT_R32_NV                   0x8885
#define GL_FLOAT_RG16_NV                  0x8886
#define GL_FLOAT_RG32_NV                  0x8887
#define GL_FLOAT_RGB16_NV                 0x8888
#define GL_FLOAT_RGB32_NV                 0x8889
#define GL_FLOAT_RGBA16_NV                0x888A
#define GL_FLOAT_RGBA32_NV                0x888B
#define GL_TEXTURE_FLOAT_COMPONENTS_NV    0x888C
#define GL_FLOAT_CLEAR_COLOR_VALUE_NV     0x888D
#define GL_FLOAT_RGBA_MODE_NV             0x888E
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_NV_fragment_program;
WM3_EXTERN int Wm3NumFunctions_GL_NV_fragment_program;
#ifndef GL_NV_fragment_program
#define GL_NV_fragment_program
#define WM3_DEFINED_GL_NV_fragment_program
#define GL_MAX_FRAGMENT_PROGRAM_LOCAL_PARAMETERS_NV 0x8868
#define GL_FRAGMENT_PROGRAM_NV                      0x8870
#define GL_MAX_TEXTURE_COORDS_NV                    0x8871
#define GL_MAX_TEXTURE_IMAGE_UNITS_NV               0x8872
#define GL_FRAGMENT_PROGRAM_BINDING_NV              0x8873
#define GL_PROGRAM_ERROR_STRING_NV                  0x8874

typedef void (APIENTRY* pfn_glProgramNamedParameter4fNV) (GLuint, GLsizei, const GLubyte*, GLfloat, GLfloat, GLfloat, GLfloat);
WM3_EXTERN pfn_glProgramNamedParameter4fNV Wm3glProgramNamedParameter4fNV;
#define glProgramNamedParameter4fNV Wm3glProgramNamedParameter4fNV

typedef void (APIENTRY* pfn_glProgramNamedParameter4dNV) (GLuint, GLsizei, const GLubyte*, GLdouble, GLdouble, GLdouble, GLdouble);
WM3_EXTERN pfn_glProgramNamedParameter4dNV Wm3glProgramNamedParameter4dNV;
#define glProgramNamedParameter4dNV Wm3glProgramNamedParameter4dNV

typedef void (APIENTRY* pfn_glProgramNamedParameter4fvNV) (GLuint, GLsizei, const GLubyte*, const GLfloat*);
WM3_EXTERN pfn_glProgramNamedParameter4fvNV Wm3glProgramNamedParameter4fvNV;
#define glProgramNamedParameter4fvNV Wm3glProgramNamedParameter4fvNV

typedef void (APIENTRY* pfn_glProgramNamedParameter4dvNV) (GLuint, GLsizei, const GLubyte*, const GLdouble*);
WM3_EXTERN pfn_glProgramNamedParameter4dvNV Wm3glProgramNamedParameter4dvNV;
#define glProgramNamedParameter4dvNV Wm3glProgramNamedParameter4dvNV

typedef void (APIENTRY* pfn_glGetProgramNamedParameterfvNV) (GLuint, GLsizei, const GLubyte*, GLfloat*);
WM3_EXTERN pfn_glGetProgramNamedParameterfvNV Wm3glGetProgramNamedParameterfvNV;
#define glGetProgramNamedParameterfvNV Wm3glGetProgramNamedParameterfvNV

typedef void (APIENTRY* pfn_glGetProgramNamedParameterdvNV) (GLuint, GLsizei, const GLubyte*, GLdouble*);
WM3_EXTERN pfn_glGetProgramNamedParameterdvNV Wm3glGetProgramNamedParameterdvNV;
#define glGetProgramNamedParameterdvNV Wm3glGetProgramNamedParameterdvNV
/* Some NV_fragment_program entry points are shared with ARB_vertex_program. */
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_NV_half_float;
WM3_EXTERN int Wm3NumFunctions_GL_NV_half_float;
#ifndef GL_NV_half_float
#define GL_NV_half_float
#define WM3_DEFINED_GL_NV_half_float
#define GL_HALF_FLOAT_NV                  0x140B
typedef unsigned short GLhalfNV;

typedef void (APIENTRY* pfn_glVertex2hNV) (GLhalfNV, GLhalfNV);
WM3_EXTERN pfn_glVertex2hNV Wm3glVertex2hNV;
#define glVertex2hNV Wm3glVertex2hNV

typedef void (APIENTRY* pfn_glVertex2hvNV) (const GLhalfNV*);
WM3_EXTERN pfn_glVertex2hvNV Wm3glVertex2hvNV;
#define glVertex2hvNV Wm3glVertex2hvNV

typedef void (APIENTRY* pfn_glVertex3hNV) (GLhalfNV, GLhalfNV, GLhalfNV);
WM3_EXTERN pfn_glVertex3hNV Wm3glVertex3hNV;
#define glVertex3hNV Wm3glVertex3hNV

typedef void (APIENTRY* pfn_glVertex3hvNV) (const GLhalfNV*);
WM3_EXTERN pfn_glVertex3hvNV Wm3glVertex3hvNV;
#define glVertex3hvNV Wm3glVertex3hvNV

typedef void (APIENTRY* pfn_glVertex4hNV) (GLhalfNV, GLhalfNV, GLhalfNV, GLhalfNV);
WM3_EXTERN pfn_glVertex4hNV Wm3glVertex4hNV;
#define glVertex4hNV Wm3glVertex4hNV

typedef void (APIENTRY* pfn_glVertex4hvNV) (const GLhalfNV*);
WM3_EXTERN pfn_glVertex4hvNV Wm3glVertex4hvNV;
#define glVertex4hvNV Wm3glVertex4hvNV

typedef void (APIENTRY* pfn_glNormal3hNV) (GLhalfNV, GLhalfNV, GLhalfNV);
WM3_EXTERN pfn_glNormal3hNV Wm3glNormal3hNV;
#define glNormal3hNV Wm3glNormal3hNV

typedef void (APIENTRY* pfn_glNormal3hvNV) (const GLhalfNV*);
WM3_EXTERN pfn_glNormal3hvNV Wm3glNormal3hvNV;
#define glNormal3hvNV Wm3glNormal3hvNV

typedef void (APIENTRY* pfn_glColor3hNV) (GLhalfNV, GLhalfNV, GLhalfNV);
WM3_EXTERN pfn_glColor3hNV Wm3glColor3hNV;
#define glColor3hNV Wm3glColor3hNV

typedef void (APIENTRY* pfn_glColor3hvNV) (const GLhalfNV*);
WM3_EXTERN pfn_glColor3hvNV Wm3glColor3hvNV;
#define glColor3hvNV Wm3glColor3hvNV

typedef void (APIENTRY* pfn_glColor4hNV) (GLhalfNV, GLhalfNV, GLhalfNV, GLhalfNV);
WM3_EXTERN pfn_glColor4hNV Wm3glColor4hNV;
#define glColor4hNV Wm3glColor4hNV

typedef void (APIENTRY* pfn_glColor4hvNV) (const GLhalfNV*);
WM3_EXTERN pfn_glColor4hvNV Wm3glColor4hvNV;
#define glColor4hvNV Wm3glColor4hvNV

typedef void (APIENTRY* pfn_glTexCoord1hNV) (GLhalfNV);
WM3_EXTERN pfn_glTexCoord1hNV Wm3glTexCoord1hNV;
#define glTexCoord1hNV Wm3glTexCoord1hNV

typedef void (APIENTRY* pfn_glTexCoord1hvNV) (const GLhalfNV*);
WM3_EXTERN pfn_glTexCoord1hvNV Wm3glTexCoord1hvNV;
#define glTexCoord1hvNV Wm3glTexCoord1hvNV

typedef void (APIENTRY* pfn_glTexCoord2hNV) (GLhalfNV, GLhalfNV);
WM3_EXTERN pfn_glTexCoord2hNV Wm3glTexCoord2hNV;
#define glTexCoord2hNV Wm3glTexCoord2hNV

typedef void (APIENTRY* pfn_glTexCoord2hvNV) (const GLhalfNV*);
WM3_EXTERN pfn_glTexCoord2hvNV Wm3glTexCoord2hvNV;
#define glTexCoord2hvNV Wm3glTexCoord2hvNV

typedef void (APIENTRY* pfn_glTexCoord3hNV) (GLhalfNV, GLhalfNV, GLhalfNV);
WM3_EXTERN pfn_glTexCoord3hNV Wm3glTexCoord3hNV;
#define glTexCoord3hNV Wm3glTexCoord3hNV

typedef void (APIENTRY* pfn_glTexCoord3hvNV) (const GLhalfNV*);
WM3_EXTERN pfn_glTexCoord3hvNV Wm3glTexCoord3hvNV;
#define glTexCoord3hvNV Wm3glTexCoord3hvNV

typedef void (APIENTRY* pfn_glTexCoord4hNV) (GLhalfNV, GLhalfNV, GLhalfNV, GLhalfNV);
WM3_EXTERN pfn_glTexCoord4hNV Wm3glTexCoord4hNV;
#define glTexCoord4hNV Wm3glTexCoord4hNV

typedef void (APIENTRY* pfn_glTexCoord4hvNV) (const GLhalfNV*);
WM3_EXTERN pfn_glTexCoord4hvNV Wm3glTexCoord4hvNV;
#define glTexCoord4hvNV Wm3glTexCoord4hvNV

typedef void (APIENTRY* pfn_glMultiTexCoord1hNV) (GLenum, GLhalfNV);
WM3_EXTERN pfn_glMultiTexCoord1hNV Wm3glMultiTexCoord1hNV;
#define glMultiTexCoord1hNV Wm3glMultiTexCoord1hNV

typedef void (APIENTRY* pfn_glMultiTexCoord1hvNV) (GLenum, const GLhalfNV*);
WM3_EXTERN pfn_glMultiTexCoord1hvNV Wm3glMultiTexCoord1hvNV;
#define glMultiTexCoord1hvNV Wm3glMultiTexCoord1hvNV

typedef void (APIENTRY* pfn_glMultiTexCoord2hNV) (GLenum, GLhalfNV, GLhalfNV);
WM3_EXTERN pfn_glMultiTexCoord2hNV Wm3glMultiTexCoord2hNV;
#define glMultiTexCoord2hNV Wm3glMultiTexCoord2hNV

typedef void (APIENTRY* pfn_glMultiTexCoord2hvNV) (GLenum, const GLhalfNV*);
WM3_EXTERN pfn_glMultiTexCoord2hvNV Wm3glMultiTexCoord2hvNV;
#define glMultiTexCoord2hvNV Wm3glMultiTexCoord2hvNV

typedef void (APIENTRY* pfn_glMultiTexCoord3hNV) (GLenum, GLhalfNV, GLhalfNV, GLhalfNV);
WM3_EXTERN pfn_glMultiTexCoord3hNV Wm3glMultiTexCoord3hNV;
#define glMultiTexCoord3hNV Wm3glMultiTexCoord3hNV

typedef void (APIENTRY* pfn_glMultiTexCoord3hvNV) (GLenum, const GLhalfNV*);
WM3_EXTERN pfn_glMultiTexCoord3hvNV Wm3glMultiTexCoord3hvNV;
#define glMultiTexCoord3hvNV Wm3glMultiTexCoord3hvNV

typedef void (APIENTRY* pfn_glMultiTexCoord4hNV) (GLenum, GLhalfNV, GLhalfNV, GLhalfNV, GLhalfNV);
WM3_EXTERN pfn_glMultiTexCoord4hNV Wm3glMultiTexCoord4hNV;
#define glMultiTexCoord4hNV Wm3glMultiTexCoord4hNV

typedef void (APIENTRY* pfn_glMultiTexCoord4hvNV) (GLenum, const GLhalfNV*);
WM3_EXTERN pfn_glMultiTexCoord4hvNV Wm3glMultiTexCoord4hvNV;
#define glMultiTexCoord4hvNV Wm3glMultiTexCoord4hvNV

typedef void (APIENTRY* pfn_glFogCoordhNV) (GLhalfNV);
WM3_EXTERN pfn_glFogCoordhNV Wm3glFogCoordhNV;
#define glFogCoordhNV Wm3glFogCoordhNV

typedef void (APIENTRY* pfn_glFogCoordhvNV) (const GLhalfNV*);
WM3_EXTERN pfn_glFogCoordhvNV Wm3glFogCoordhvNV;
#define glFogCoordhvNV Wm3glFogCoordhvNV

typedef void (APIENTRY* pfn_glSecondaryColor3hNV) (GLhalfNV, GLhalfNV, GLhalfNV);
WM3_EXTERN pfn_glSecondaryColor3hNV Wm3glSecondaryColor3hNV;
#define glSecondaryColor3hNV Wm3glSecondaryColor3hNV

typedef void (APIENTRY* pfn_glSecondaryColor3hvNV) (const GLhalfNV*);
WM3_EXTERN pfn_glSecondaryColor3hvNV Wm3glSecondaryColor3hvNV;
#define glSecondaryColor3hvNV Wm3glSecondaryColor3hvNV

typedef void (APIENTRY* pfn_glVertexWeighthNV) (GLhalfNV);
WM3_EXTERN pfn_glVertexWeighthNV Wm3glVertexWeighthNV;
#define glVertexWeighthNV Wm3glVertexWeighthNV

typedef void (APIENTRY* pfn_glVertexWeighthvNV) (const GLhalfNV*);
WM3_EXTERN pfn_glVertexWeighthvNV Wm3glVertexWeighthvNV;
#define glVertexWeighthvNV Wm3glVertexWeighthvNV

typedef void (APIENTRY* pfn_glVertexAttrib1hNV) (GLuint, GLhalfNV);
WM3_EXTERN pfn_glVertexAttrib1hNV Wm3glVertexAttrib1hNV;
#define glVertexAttrib1hNV Wm3glVertexAttrib1hNV

typedef void (APIENTRY* pfn_glVertexAttrib1hvNV) (GLuint, const GLhalfNV*);
WM3_EXTERN pfn_glVertexAttrib1hvNV Wm3glVertexAttrib1hvNV;
#define glVertexAttrib1hvNV Wm3glVertexAttrib1hvNV

typedef void (APIENTRY* pfn_glVertexAttrib2hNV) (GLuint, GLhalfNV, GLhalfNV);
WM3_EXTERN pfn_glVertexAttrib2hNV Wm3glVertexAttrib2hNV;
#define glVertexAttrib2hNV Wm3glVertexAttrib2hNV

typedef void (APIENTRY* pfn_glVertexAttrib2hvNV) (GLuint, const GLhalfNV*);
WM3_EXTERN pfn_glVertexAttrib2hvNV Wm3glVertexAttrib2hvNV;
#define glVertexAttrib2hvNV Wm3glVertexAttrib2hvNV

typedef void (APIENTRY* pfn_glVertexAttrib3hNV) (GLuint, GLhalfNV, GLhalfNV, GLhalfNV);
WM3_EXTERN pfn_glVertexAttrib3hNV Wm3glVertexAttrib3hNV;
#define glVertexAttrib3hNV Wm3glVertexAttrib3hNV

typedef void (APIENTRY* pfn_glVertexAttrib3hvNV) (GLuint, const GLhalfNV*);
WM3_EXTERN pfn_glVertexAttrib3hvNV Wm3glVertexAttrib3hvNV;
#define glVertexAttrib3hvNV Wm3glVertexAttrib3hvNV

typedef void (APIENTRY* pfn_glVertexAttrib4hNV) (GLuint, GLhalfNV, GLhalfNV, GLhalfNV, GLhalfNV);
WM3_EXTERN pfn_glVertexAttrib4hNV Wm3glVertexAttrib4hNV;
#define glVertexAttrib4hNV Wm3glVertexAttrib4hNV

typedef void (APIENTRY* pfn_glVertexAttrib4hvNV) (GLuint, const GLhalfNV*);
WM3_EXTERN pfn_glVertexAttrib4hvNV Wm3glVertexAttrib4hvNV;
#define glVertexAttrib4hvNV Wm3glVertexAttrib4hvNV

typedef void (APIENTRY* pfn_glVertexAttribs1hvNV) (GLuint, GLsizei, const GLhalfNV*);
WM3_EXTERN pfn_glVertexAttribs1hvNV Wm3glVertexAttribs1hvNV;
#define glVertexAttribs1hvNV Wm3glVertexAttribs1hvNV

typedef void (APIENTRY* pfn_glVertexAttribs2hvNV) (GLuint, GLsizei, const GLhalfNV*);
WM3_EXTERN pfn_glVertexAttribs2hvNV Wm3glVertexAttribs2hvNV;
#define glVertexAttribs2hvNV Wm3glVertexAttribs2hvNV

typedef void (APIENTRY* pfn_glVertexAttribs3hvNV) (GLuint, GLsizei, const GLhalfNV*);
WM3_EXTERN pfn_glVertexAttribs3hvNV Wm3glVertexAttribs3hvNV;
#define glVertexAttribs3hvNV Wm3glVertexAttribs3hvNV

typedef void (APIENTRY* pfn_glVertexAttribs4hvNV) (GLuint, GLsizei, const GLhalfNV*);
WM3_EXTERN pfn_glVertexAttribs4hvNV Wm3glVertexAttribs4hvNV;
#define glVertexAttribs4hvNV Wm3glVertexAttribs4hvNV
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_NV_pixel_data_range;
WM3_EXTERN int Wm3NumFunctions_GL_NV_pixel_data_range;
#ifndef GL_NV_pixel_data_range
#define GL_NV_pixel_data_range
#define WM3_DEFINED_GL_NV_pixel_data_range
#define GL_WRITE_PIXEL_DATA_RANGE_NV            0x8878
#define GL_READ_PIXEL_DATA_RANGE_NV             0x8879
#define GL_WRITE_PIXEL_DATA_RANGE_LENGTH_NV     0x887A
#define GL_READ_PIXEL_DATA_RANGE_LENGTH_NV      0x887B
#define GL_WRITE_PIXEL_DATA_RANGE_POINTER_NV    0x887C
#define GL_READ_PIXEL_DATA_RANGE_POINTER_NV     0x887D

typedef void (APIENTRY* pfn_glPixelDataRangeNV) (GLenum, GLsizei, GLvoid*);
WM3_EXTERN pfn_glPixelDataRangeNV Wm3glPixelDataRangeNV;
#define glPixelDataRangeNV Wm3glPixelDataRangeNV

typedef void (APIENTRY* pfn_glFlushPixelDataRangeNV) (GLenum);
WM3_EXTERN pfn_glFlushPixelDataRangeNV Wm3glFlushPixelDataRangeNV;
#define glFlushPixelDataRangeNV Wm3glFlushPixelDataRangeNV
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_NV_primitive_restart;
WM3_EXTERN int Wm3NumFunctions_GL_NV_primitive_restart;
#ifndef GL_NV_primitive_restart
#define GL_NV_primitive_restart
#define WM3_DEFINED_GL_NV_primitive_restart
#define GL_PRIMITIVE_RESTART_NV           0x8558
#define GL_PRIMITIVE_RESTART_INDEX_NV     0x8559

typedef void (APIENTRY* pfn_glPrimitiveRestartNV) (void);
WM3_EXTERN pfn_glPrimitiveRestartNV Wm3glPrimitiveRestartNV;
#define glPrimitiveRestartNV Wm3glPrimitiveRestartNV

typedef void (APIENTRY* pfn_glPrimitiveRestartIndexNV) (GLuint);
WM3_EXTERN pfn_glPrimitiveRestartIndexNV Wm3glPrimitiveRestartIndexNV;
#define glPrimitiveRestartIndexNV Wm3glPrimitiveRestartIndexNV
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_NV_texture_expand_normal;
WM3_EXTERN int Wm3NumFunctions_GL_NV_texture_expand_normal;
#ifndef GL_NV_texture_expand_normal
#define GL_NV_texture_expand_normal
#define WM3_DEFINED_GL_NV_texture_expand_normal
#define GL_TEXTURE_UNSIGNED_REMAP_MODE_NV 0x888F
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_NV_vertex_program2;
WM3_EXTERN int Wm3NumFunctions_GL_NV_vertex_program2;
#ifndef GL_NV_vertex_program2
#define GL_NV_vertex_program2
#define WM3_DEFINED_GL_NV_vertex_program2
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_ATI_map_object_buffer;
WM3_EXTERN int Wm3NumFunctions_GL_ATI_map_object_buffer;
#ifndef GL_ATI_map_object_buffer
#define GL_ATI_map_object_buffer
#define WM3_DEFINED_GL_ATI_map_object_buffer

typedef GLvoid* (APIENTRY* pfn_glMapObjectBufferATI) (GLuint);
WM3_EXTERN pfn_glMapObjectBufferATI Wm3glMapObjectBufferATI;
#define glMapObjectBufferATI Wm3glMapObjectBufferATI

typedef void (APIENTRY* pfn_glUnmapObjectBufferATI) (GLuint);
WM3_EXTERN pfn_glUnmapObjectBufferATI Wm3glUnmapObjectBufferATI;
#define glUnmapObjectBufferATI Wm3glUnmapObjectBufferATI
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_ATI_separate_stencil;
WM3_EXTERN int Wm3NumFunctions_GL_ATI_separate_stencil;
#ifndef GL_ATI_separate_stencil
#define GL_ATI_separate_stencil
#define WM3_DEFINED_GL_ATI_separate_stencil
#define GL_STENCIL_BACK_FUNC_ATI            0x8800
#define GL_STENCIL_BACK_FAIL_ATI            0x8801
#define GL_STENCIL_BACK_PASS_DEPTH_FAIL_ATI 0x8802
#define GL_STENCIL_BACK_PASS_DEPTH_PASS_ATI 0x8803

typedef void (APIENTRY* pfn_glStencilOpSeparateATI) (GLenum, GLenum, GLenum, GLenum);
WM3_EXTERN pfn_glStencilOpSeparateATI Wm3glStencilOpSeparateATI;
#define glStencilOpSeparateATI Wm3glStencilOpSeparateATI

typedef void (APIENTRY* pfn_glStencilFuncSeparateATI) (GLenum, GLenum, GLint, GLuint);
WM3_EXTERN pfn_glStencilFuncSeparateATI Wm3glStencilFuncSeparateATI;
#define glStencilFuncSeparateATI Wm3glStencilFuncSeparateATI
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_ATI_vertex_attrib_array_object;
WM3_EXTERN int Wm3NumFunctions_GL_ATI_vertex_attrib_array_object;
#ifndef GL_ATI_vertex_attrib_array_object
#define GL_ATI_vertex_attrib_array_object
#define WM3_DEFINED_GL_ATI_vertex_attrib_array_object

typedef void (APIENTRY* pfn_glVertexAttribArrayObjectATI) (GLuint, GLint, GLenum, GLboolean, GLsizei, GLuint, GLuint);
WM3_EXTERN pfn_glVertexAttribArrayObjectATI Wm3glVertexAttribArrayObjectATI;
#define glVertexAttribArrayObjectATI Wm3glVertexAttribArrayObjectATI

typedef void (APIENTRY* pfn_glGetVertexAttribArrayObjectfvATI) (GLuint, GLenum, GLfloat*);
WM3_EXTERN pfn_glGetVertexAttribArrayObjectfvATI Wm3glGetVertexAttribArrayObjectfvATI;
#define glGetVertexAttribArrayObjectfvATI Wm3glGetVertexAttribArrayObjectfvATI

typedef void (APIENTRY* pfn_glGetVertexAttribArrayObjectivATI) (GLuint, GLenum, GLint*);
WM3_EXTERN pfn_glGetVertexAttribArrayObjectivATI Wm3glGetVertexAttribArrayObjectivATI;
#define glGetVertexAttribArrayObjectivATI Wm3glGetVertexAttribArrayObjectivATI
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_OES_read_format;
WM3_EXTERN int Wm3NumFunctions_GL_OES_read_format;
#ifndef GL_OES_read_format
#define GL_OES_read_format
#define WM3_DEFINED_GL_OES_read_format
#define GL_IMPLEMENTATION_COLOR_READ_TYPE_OES 0x8B9A
#define GL_IMPLEMENTATION_COLOR_READ_FORMAT_OES 0x8B9B
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_EXT_depth_bounds_test;
WM3_EXTERN int Wm3NumFunctions_GL_EXT_depth_bounds_test;
#ifndef GL_EXT_depth_bounds_test
#define GL_EXT_depth_bounds_test
#define WM3_DEFINED_GL_EXT_depth_bounds_test
#define GL_DEPTH_BOUNDS_TEST_EXT          0x8890
#define GL_DEPTH_BOUNDS_EXT               0x8891

typedef void (APIENTRY* pfn_glDepthBoundsEXT) (GLclampd, GLclampd);
WM3_EXTERN pfn_glDepthBoundsEXT Wm3glDepthBoundsEXT;
#define glDepthBoundsEXT Wm3glDepthBoundsEXT
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_EXT_texture_mirror_clamp;
WM3_EXTERN int Wm3NumFunctions_GL_EXT_texture_mirror_clamp;
#ifndef GL_EXT_texture_mirror_clamp
#define GL_EXT_texture_mirror_clamp
#define WM3_DEFINED_GL_EXT_texture_mirror_clamp
#define GL_MIRROR_CLAMP_EXT               0x8742
#define GL_MIRROR_CLAMP_TO_EDGE_EXT       0x8743
#define GL_MIRROR_CLAMP_TO_BORDER_EXT     0x8912
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_EXT_blend_equation_separate;
WM3_EXTERN int Wm3NumFunctions_GL_EXT_blend_equation_separate;
#ifndef GL_EXT_blend_equation_separate
#define GL_EXT_blend_equation_separate
#define WM3_DEFINED_GL_EXT_blend_equation_separate
#define GL_BLEND_EQUATION_RGB_EXT         GL_BLEND_EQUATION
#define GL_BLEND_EQUATION_ALPHA_EXT       0x883D

typedef void (APIENTRY* pfn_glBlendEquationSeparateEXT) (GLenum, GLenum);
WM3_EXTERN pfn_glBlendEquationSeparateEXT Wm3glBlendEquationSeparateEXT;
#define glBlendEquationSeparateEXT Wm3glBlendEquationSeparateEXT
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_MESA_pack_invert;
WM3_EXTERN int Wm3NumFunctions_GL_MESA_pack_invert;
#ifndef GL_MESA_pack_invert
#define GL_MESA_pack_invert
#define WM3_DEFINED_GL_MESA_pack_invert
#define GL_PACK_INVERT_MESA               0x8758
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_MESA_ycbcr_texture;
WM3_EXTERN int Wm3NumFunctions_GL_MESA_ycbcr_texture;
#ifndef GL_MESA_ycbcr_texture
#define GL_MESA_ycbcr_texture
#define WM3_DEFINED_GL_MESA_ycbcr_texture
#define GL_UNSIGNED_SHORT_8_8_MESA        0x85BA
#define GL_UNSIGNED_SHORT_8_8_REV_MESA    0x85BB
#define GL_YCBCR_MESA                     0x8757
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_EXT_pixel_buffer_object;
WM3_EXTERN int Wm3NumFunctions_GL_EXT_pixel_buffer_object;
#ifndef GL_EXT_pixel_buffer_object
#define GL_EXT_pixel_buffer_object
#define WM3_DEFINED_GL_EXT_pixel_buffer_object
#define GL_PIXEL_PACK_BUFFER_EXT          0x88EB
#define GL_PIXEL_UNPACK_BUFFER_EXT        0x88EC
#define GL_PIXEL_PACK_BUFFER_BINDING_EXT  0x88ED
#define GL_PIXEL_UNPACK_BUFFER_BINDING_EXT 0x88EF
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_NV_fragment_program_option;
WM3_EXTERN int Wm3NumFunctions_GL_NV_fragment_program_option;
#ifndef GL_NV_fragment_program_option
#define GL_NV_fragment_program_option
#define WM3_DEFINED_GL_NV_fragment_program_option
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_NV_fragment_program2;
WM3_EXTERN int Wm3NumFunctions_GL_NV_fragment_program2;
#ifndef GL_NV_fragment_program2
#define GL_NV_fragment_program2
#define WM3_DEFINED_GL_NV_fragment_program2
#define GL_MAX_PROGRAM_EXEC_INSTRUCTIONS_NV 0x88F4
#define GL_MAX_PROGRAM_CALL_DEPTH_NV        0x88F5
#define GL_MAX_PROGRAM_IF_DEPTH_NV          0x88F6
#define GL_MAX_PROGRAM_LOOP_DEPTH_NV        0x88F7
#define GL_MAX_PROGRAM_LOOP_COUNT_NV        0x88F8
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_NV_vertex_program2_option;
WM3_EXTERN int Wm3NumFunctions_GL_NV_vertex_program2_option;
#ifndef GL_NV_vertex_program2_option
#define GL_NV_vertex_program2_option
#define WM3_DEFINED_GL_NV_vertex_program2_option
/* reuse GL_MAX_PROGRAM_EXEC_INSTRUCTIONS_NV */
/* reuse GL_MAX_PROGRAM_CALL_DEPTH_NV */
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_NV_vertex_program3;
WM3_EXTERN int Wm3NumFunctions_GL_NV_vertex_program3;
#ifndef GL_NV_vertex_program3
#define GL_NV_vertex_program3
#define WM3_DEFINED_GL_NV_vertex_program3
/* reuse GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS_ARB */
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_EXT_framebuffer_object;
WM3_EXTERN int Wm3NumFunctions_GL_EXT_framebuffer_object;
#ifndef GL_EXT_framebuffer_object
#define GL_EXT_framebuffer_object
#define WM3_DEFINED_GL_EXT_framebuffer_object
#define GL_INVALID_FRAMEBUFFER_OPERATION_EXT 0x0506
#define GL_MAX_RENDERBUFFER_SIZE_EXT                        0x84E8
#define GL_FRAMEBUFFER_BINDING_EXT                          0x8CA6
#define GL_RENDERBUFFER_BINDING_EXT                         0x8CA7
#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE_EXT           0x8CD0
#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME_EXT           0x8CD1
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL_EXT         0x8CD2
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE_EXT 0x8CD3
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_3D_ZOFFSET_EXT    0x8CD4
#define GL_FRAMEBUFFER_COMPLETE_EXT                         0x8CD5
#define GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENTS_EXT           0x8CD6
#define GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT_EXT    0x8CD7
#define GL_FRAMEBUFFER_INCOMPLETE_DUPLICATE_ATTACHMENT_EXT  0x8CD8
#define GL_FRAMEBUFFER_INCOMPLETE_DIMENSIONS_EXT            0x8CD9
#define GL_FRAMEBUFFER_INCOMPLETE_FORMATS_EXT               0x8CDA
#define GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER_EXT           0x8CDB
#define GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER_EXT           0x8CDC
#define GL_FRAMEBUFFER_UNSUPPORTED_EXT                      0x8CDD
#define GL_FRAMEBUFFER_STATUS_ERROR_EXT                     0x8CDE
#define GL_MAX_COLOR_ATTACHMENTS_EXT                        0x8CDF
#define GL_COLOR_ATTACHMENT0_EXT                            0x8CE0
#define GL_COLOR_ATTACHMENT1_EXT                            0x8CE1
#define GL_COLOR_ATTACHMENT2_EXT                            0x8CE2
#define GL_COLOR_ATTACHMENT3_EXT                            0x8CE3
#define GL_COLOR_ATTACHMENT4_EXT                            0x8CE4
#define GL_COLOR_ATTACHMENT5_EXT                            0x8CE5
#define GL_COLOR_ATTACHMENT6_EXT                            0x8CE6
#define GL_COLOR_ATTACHMENT7_EXT                            0x8CE7
#define GL_COLOR_ATTACHMENT8_EXT                            0x8CE8
#define GL_COLOR_ATTACHMENT9_EXT                            0x8CE9
#define GL_COLOR_ATTACHMENT10_EXT                           0x8CEA
#define GL_COLOR_ATTACHMENT11_EXT                           0x8CEB
#define GL_COLOR_ATTACHMENT12_EXT                           0x8CEC
#define GL_COLOR_ATTACHMENT13_EXT                           0x8CED
#define GL_COLOR_ATTACHMENT14_EXT                           0x8CEE
#define GL_COLOR_ATTACHMENT15_EXT                           0x8CEF
#define GL_DEPTH_ATTACHMENT_EXT                             0x8D00
#define GL_STENCIL_ATTACHMENT_EXT                           0x8D20
#define GL_FRAMEBUFFER_EXT                                  0x8D40
#define GL_RENDERBUFFER_EXT                                 0x8D41
#define GL_RENDERBUFFER_WIDTH_EXT                           0x8D42
#define GL_RENDERBUFFER_HEIGHT_EXT                          0x8D43
#define GL_RENDERBUFFER_INTERNAL_FORMAT_EXT                 0x8D44
#define GL_STENCIL_INDEX_EXT                                0x8D45
#define GL_STENCIL_INDEX1_EXT                               0x8D46
#define GL_STENCIL_INDEX4_EXT                               0x8D47
#define GL_STENCIL_INDEX8_EXT                               0x8D48
#define GL_STENCIL_INDEX16_EXT                              0x8D49

typedef GLboolean (APIENTRY* pfn_glIsRenderbufferEXT) (GLuint);
WM3_EXTERN pfn_glIsRenderbufferEXT Wm3glIsRenderbufferEXT;
#define glIsRenderbufferEXT Wm3glIsRenderbufferEXT

typedef void (APIENTRY* pfn_glBindRenderbufferEXT) (GLenum, GLuint);
WM3_EXTERN pfn_glBindRenderbufferEXT Wm3glBindRenderbufferEXT;
#define glBindRenderbufferEXT Wm3glBindRenderbufferEXT

typedef void (APIENTRY* pfn_glDeleteRenderbuffersEXT) (GLsizei, const GLuint*);
WM3_EXTERN pfn_glDeleteRenderbuffersEXT Wm3glDeleteRenderbuffersEXT;
#define glDeleteRenderbuffersEXT Wm3glDeleteRenderbuffersEXT

typedef void (APIENTRY* pfn_glGenRenderbuffersEXT) (GLsizei, GLuint*);
WM3_EXTERN pfn_glGenRenderbuffersEXT Wm3glGenRenderbuffersEXT;
#define glGenRenderbuffersEXT Wm3glGenRenderbuffersEXT

typedef void (APIENTRY* pfn_glRenderbufferStorageEXT) (GLenum, GLenum, GLsizei, GLsizei);
WM3_EXTERN pfn_glRenderbufferStorageEXT Wm3glRenderbufferStorageEXT;
#define glRenderbufferStorageEXT Wm3glRenderbufferStorageEXT

typedef void (APIENTRY* pfn_glGetRenderbufferParameterivEXT) (GLenum, GLenum, GLint*);
WM3_EXTERN pfn_glGetRenderbufferParameterivEXT Wm3glGetRenderbufferParameterivEXT;
#define glGetRenderbufferParameterivEXT Wm3glGetRenderbufferParameterivEXT

typedef GLboolean (APIENTRY* pfn_glIsFramebufferEXT) (GLuint);
WM3_EXTERN pfn_glIsFramebufferEXT Wm3glIsFramebufferEXT;
#define glIsFramebufferEXT Wm3glIsFramebufferEXT

typedef void (APIENTRY* pfn_glBindFramebufferEXT) (GLenum, GLuint);
WM3_EXTERN pfn_glBindFramebufferEXT Wm3glBindFramebufferEXT;
#define glBindFramebufferEXT Wm3glBindFramebufferEXT

typedef void (APIENTRY* pfn_glDeleteFramebuffersEXT) (GLsizei, const GLuint*);
WM3_EXTERN pfn_glDeleteFramebuffersEXT Wm3glDeleteFramebuffersEXT;
#define glDeleteFramebuffersEXT Wm3glDeleteFramebuffersEXT

typedef void (APIENTRY* pfn_glGenFramebuffersEXT) (GLsizei, GLuint*);
WM3_EXTERN pfn_glGenFramebuffersEXT Wm3glGenFramebuffersEXT;
#define glGenFramebuffersEXT Wm3glGenFramebuffersEXT

typedef GLenum (APIENTRY* pfn_glCheckFramebufferStatusEXT) (GLenum);
WM3_EXTERN pfn_glCheckFramebufferStatusEXT Wm3glCheckFramebufferStatusEXT;
#define glCheckFramebufferStatusEXT Wm3glCheckFramebufferStatusEXT

typedef void (APIENTRY* pfn_glFramebufferTexture1DEXT) (GLenum, GLenum, GLenum, GLuint, GLint);
WM3_EXTERN pfn_glFramebufferTexture1DEXT Wm3glFramebufferTexture1DEXT;
#define glFramebufferTexture1DEXT Wm3glFramebufferTexture1DEXT

typedef void (APIENTRY* pfn_glFramebufferTexture2DEXT) (GLenum, GLenum, GLenum, GLuint, GLint);
WM3_EXTERN pfn_glFramebufferTexture2DEXT Wm3glFramebufferTexture2DEXT;
#define glFramebufferTexture2DEXT Wm3glFramebufferTexture2DEXT

typedef void (APIENTRY* pfn_glFramebufferTexture3DEXT) (GLenum, GLenum, GLenum, GLuint, GLint, GLint);
WM3_EXTERN pfn_glFramebufferTexture3DEXT Wm3glFramebufferTexture3DEXT;
#define glFramebufferTexture3DEXT Wm3glFramebufferTexture3DEXT

typedef void (APIENTRY* pfn_glFramebufferRenderbufferEXT) (GLenum, GLenum, GLenum, GLuint);
WM3_EXTERN pfn_glFramebufferRenderbufferEXT Wm3glFramebufferRenderbufferEXT;
#define glFramebufferRenderbufferEXT Wm3glFramebufferRenderbufferEXT

typedef void (APIENTRY* pfn_glGetFramebufferAttachmentParameterivEXT) (GLenum, GLenum, GLenum, GLint*);
WM3_EXTERN pfn_glGetFramebufferAttachmentParameterivEXT Wm3glGetFramebufferAttachmentParameterivEXT;
#define glGetFramebufferAttachmentParameterivEXT Wm3glGetFramebufferAttachmentParameterivEXT

typedef void (APIENTRY* pfn_glGenerateMipmapEXT) (GLenum);
WM3_EXTERN pfn_glGenerateMipmapEXT Wm3glGenerateMipmapEXT;
#define glGenerateMipmapEXT Wm3glGenerateMipmapEXT
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GL_GREMEDY_string_marker;
WM3_EXTERN int Wm3NumFunctions_GL_GREMEDY_string_marker;
#ifndef GL_GREMEDY_string_marker
#define GL_GREMEDY_string_marker
#define WM3_DEFINED_GL_GREMEDY_string_marker

typedef void (APIENTRY* pfn_glStringMarkerGREMEDY) (GLsizei, const GLvoid*);
WM3_EXTERN pfn_glStringMarkerGREMEDY Wm3glStringMarkerGREMEDY;
#define glStringMarkerGREMEDY Wm3glStringMarkerGREMEDY
#endif

/*--------------------------------------------------------------------------*/
#ifdef __APPLE__
#include <OpenGL/glu.h>
#else
#include <GL/glu.h>
#endif
/*--------------------------------------------------------------------------*/
void* GetFunctionPointer (const char*);
void InitializeOpenGL ();
/*--------------------------------------------------------------------------*/

#ifdef __cplusplus
}
#endif

#ifdef WM3_DEFINED_APIENTRY
#undef WM3_DEFINED_APIENTRY
#undef APIENTRY
#endif

#ifdef WM3_DEFINED_CALLBACK
#undef WM3_DEFINED_CALLBACK
#undef CALLBACK
#endif

#ifdef WM3_DEFINED_WINGDIAPI
#undef WM3_DEFINED_WINGDIAPI
#undef WINGDIAPI
#endif

#endif 
