/*
Geometric Tools, Inc.
http://www.geometrictools.com
Copyright (c) 1998-2005.  All Rights Reserved

The Wild Magic Library (WM3) source code is supplied under the terms of
the license agreement
    http://www.geometrictools.com/License/WildMagic3License.pdf
and may not be copied or disclosed except in accordance with the terms
of that agreement.

This file evolved by modifications from a version of glxext.h that was
downloaded from the site listed in the license below.  The version of the
file is: GLX_GLXEXT_VERSION 10
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

#ifndef WM3GLXEXTENSIONS_H
#define WM3GLXEXTENSIONS_H

#include "Wm3OpenGLExtensions.h"

#ifdef __glxext_h_
#error glxext.h included before Wm3GlxExtensions.h
#endif

#define __glxext_h_

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xmd.h>

#ifndef APIENTRY
#define APIENTRY
#endif
#ifndef APIENTRYP
#define APIENTRYP APIENTRY *
#endif
#ifndef GLAPI
#define GLAPI extern
#endif

#ifdef __cplusplus
extern "C" {
#endif


/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GLX_VERSION_1_0;
WM3_EXTERN int Wm3NumFunctions_GLX_VERSION_1_0;
#ifndef GLX_VERSION_1_0
#define GLX_VERSION_1_0
#define WM3_DEFINED_GLX_VERSION_1_0
#define GLX_USE_GL            1
#define GLX_BUFFER_SIZE       2
#define GLX_LEVEL             3
#define GLX_RGBA              4
#define GLX_DOUBLEBUFFER      5
#define GLX_STEREO            6
#define GLX_AUX_BUFFERS       7
#define GLX_RED_SIZE          8
#define GLX_GREEN_SIZE        9
#define GLX_BLUE_SIZE        10
#define GLX_ALPHA_SIZE       11
#define GLX_DEPTH_SIZE       12
#define GLX_STENCIL_SIZE     13
#define GLX_ACCUM_RED_SIZE   14
#define GLX_ACCUM_GREEN_SIZE 15
#define GLX_ACCUM_BLUE_SIZE  16
#define GLX_ACCUM_ALPHA_SIZE 17
#define GLX_BAD_SCREEN        1
#define GLX_BAD_ATTRIBUTE     2
#define GLX_NO_EXTENSION      3
#define GLX_BAD_VISUAL        4
#define GLX_BAD_CONTEXT       5
#define GLX_BAD_VALUE         6
#define GLX_BAD_ENUM          7
typedef XID GLXDrawable;
typedef XID GLXPixmap;
typedef struct __GLXcontextRec* GLXContext;
WM3_EXTERN Bool glXQueryExtension (Display*, int*, int*);
WM3_EXTERN Bool glXQueryVersion (Display*, int*, int*);
WM3_EXTERN int glXGetConfig (Display*, XVisualInfo*, int, int*);
WM3_EXTERN XVisualInfo* glXChooseVisual (Display*, int, int*);
WM3_EXTERN GLXPixmap glXCreateGLXPixmap (Display*, XVisualInfo*, Pixmap);
WM3_EXTERN void glXDestroyGLXPixmap (Display*, GLXPixmap);
WM3_EXTERN GLXContext glXCreateContext (Display*, XVisualInfo*, GLXContext, Bool);
WM3_EXTERN void glXDestroyContext (Display*, GLXContext);
WM3_EXTERN Bool glXIsDirect (Display*, GLXContext);
WM3_EXTERN void glXCopyContext (Display*, GLXContext, GLXContext, GLuint);
WM3_EXTERN Bool glXMakeCurrent (Display*, GLXDrawable, GLXContext);
WM3_EXTERN GLXContext glXGetCurrentContext (void);
WM3_EXTERN GLXDrawable glXGetCurrentDrawable (void);
WM3_EXTERN void glXWaitGL (void);
WM3_EXTERN void glXWaitX (void);
WM3_EXTERN void glXSwapBuffers (Display*, GLXDrawable);
WM3_EXTERN void glXUseXFont (Font, int, int, int);
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GLX_VERSION_1_1;
WM3_EXTERN int Wm3NumFunctions_GLX_VERSION_1_1;
#ifndef GLX_VERSION_1_1
#define GLX_VERSION_1_1
#define WM3_DEFINED_GLX_VERSION_1_1
#define GLX_VENDOR     1
#define GLX_VERSION    2
#define GLX_EXTENSIONS 3
WM3_EXTERN const char* glXQueryExtensionsString (Display*, int);
WM3_EXTERN const char* glXGetClientString (Display*, int);
WM3_EXTERN const char* glXQueryServerString (Display*, int, int);
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GLX_VERSION_1_2;
WM3_EXTERN int Wm3NumFunctions_GLX_VERSION_1_2;
#ifndef GLX_VERSION_1_2
#define GLX_VERSION_1_2
#define WM3_DEFINED_GLX_VERSION_1_2

typedef Display* (* pfn_glXGetCurrentDisplay) (void);
WM3_EXTERN pfn_glXGetCurrentDisplay Wm3glXGetCurrentDisplay;
#define glXGetCurrentDisplay Wm3glXGetCurrentDisplay
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GLX_VERSION_1_3;
WM3_EXTERN int Wm3NumFunctions_GLX_VERSION_1_3;
#ifndef GLX_VERSION_1_3
#define GLX_VERSION_1_3
#define WM3_DEFINED_GLX_VERSION_1_3
#define GLX_WINDOW_BIT                     0x00000001
#define GLX_PIXMAP_BIT                     0x00000002
#define GLX_PBUFFER_BIT                    0x00000004
#define GLX_RGBA_BIT                       0x00000001
#define GLX_COLOR_INDEX_BIT                0x00000002
#define GLX_PBUFFER_CLOBBER_MASK           0x08000000
#define GLX_FRONT_LEFT_BUFFER_BIT          0x00000001
#define GLX_FRONT_RIGHT_BUFFER_BIT         0x00000002
#define GLX_BACK_LEFT_BUFFER_BIT           0x00000004
#define GLX_BACK_RIGHT_BUFFER_BIT          0x00000008
#define GLX_AUX_BUFFERS_BIT                0x00000010
#define GLX_DEPTH_BUFFER_BIT               0x00000020
#define GLX_STENCIL_BUFFER_BIT             0x00000040
#define GLX_ACCUM_BUFFER_BIT               0x00000080
#define GLX_CONFIG_CAVEAT                  0x20
#define GLX_X_VISUAL_TYPE                  0x22
#define GLX_TRANSPARENT_TYPE               0x23
#define GLX_TRANSPARENT_INDEX_VALUE        0x24
#define GLX_TRANSPARENT_RED_VALUE          0x25
#define GLX_TRANSPARENT_GREEN_VALUE        0x26
#define GLX_TRANSPARENT_BLUE_VALUE         0x27
#define GLX_TRANSPARENT_ALPHA_VALUE        0x28
#define GLX_DONT_CARE                      0xFFFFFFFF
#define GLX_NONE                           0x8000
#define GLX_SLOW_CONFIG                    0x8001
#define GLX_TRUE_COLOR                     0x8002
#define GLX_DIRECT_COLOR                   0x8003
#define GLX_PSEUDO_COLOR                   0x8004
#define GLX_STATIC_COLOR                   0x8005
#define GLX_GRAY_SCALE                     0x8006
#define GLX_STATIC_GRAY                    0x8007
#define GLX_TRANSPARENT_RGB                0x8008
#define GLX_TRANSPARENT_INDEX              0x8009
#define GLX_VISUAL_ID                      0x800B
#define GLX_SCREEN                         0x800C
#define GLX_NON_CONFORMANT_CONFIG          0x800D
#define GLX_DRAWABLE_TYPE                  0x8010
#define GLX_RENDER_TYPE                    0x8011
#define GLX_X_RENDERABLE                   0x8012
#define GLX_FBCONFIG_ID                    0x8013
#define GLX_RGBA_TYPE                      0x8014
#define GLX_COLOR_INDEX_TYPE               0x8015
#define GLX_MAX_PBUFFER_WIDTH              0x8016
#define GLX_MAX_PBUFFER_HEIGHT             0x8017
#define GLX_MAX_PBUFFER_PIXELS             0x8018
#define GLX_PRESERVED_CONTENTS             0x801B
#define GLX_LARGEST_PBUFFER                0x801C
#define GLX_WIDTH                          0x801D
#define GLX_HEIGHT                         0x801E
#define GLX_EVENT_MASK                     0x801F
#define GLX_DAMAGED                        0x8020
#define GLX_SAVED                          0x8021
#define GLX_WINDOW                         0x8022
#define GLX_PBUFFER                        0x8023
#define GLX_PBUFFER_HEIGHT                 0x8040
#define GLX_PBUFFER_WIDTH                  0x8041
typedef struct __GLXFBConfigRec* GLXFBConfig;
typedef XID GLXWindow;
typedef XID GLXPbuffer;

typedef GLXFBConfig* (* pfn_glXGetFBConfigs) (Display*, int, int*);
WM3_EXTERN pfn_glXGetFBConfigs Wm3glXGetFBConfigs;
#define glXGetFBConfigs Wm3glXGetFBConfigs

typedef GLXFBConfig* (* pfn_glXChooseFBConfig) (Display*, int, const int*, int*);
WM3_EXTERN pfn_glXChooseFBConfig Wm3glXChooseFBConfig;
#define glXChooseFBConfig Wm3glXChooseFBConfig

typedef int (* pfn_glXGetFBConfigAttrib) (Display*, GLXFBConfig, int, int*);
WM3_EXTERN pfn_glXGetFBConfigAttrib Wm3glXGetFBConfigAttrib;
#define glXGetFBConfigAttrib Wm3glXGetFBConfigAttrib

typedef XVisualInfo* (* pfn_glXGetVisualFromFBConfig) (Display*, GLXFBConfig);
WM3_EXTERN pfn_glXGetVisualFromFBConfig Wm3glXGetVisualFromFBConfig;
#define glXGetVisualFromFBConfig Wm3glXGetVisualFromFBConfig

typedef GLXWindow (* pfn_glXCreateWindow) (Display*, GLXFBConfig, Window, const int*);
WM3_EXTERN pfn_glXCreateWindow Wm3glXCreateWindow;
#define glXCreateWindow Wm3glXCreateWindow

typedef void (* pfn_glXDestroyWindow) (Display*, GLXWindow);
WM3_EXTERN pfn_glXDestroyWindow Wm3glXDestroyWindow;
#define glXDestroyWindow Wm3glXDestroyWindow

typedef GLXPixmap (* pfn_glXCreatePixmap) (Display*, GLXFBConfig, Pixmap, const int*);
WM3_EXTERN pfn_glXCreatePixmap Wm3glXCreatePixmap;
#define glXCreatePixmap Wm3glXCreatePixmap

typedef void (* pfn_glXDestroyPixmap) (Display*, GLXPixmap);
WM3_EXTERN pfn_glXDestroyPixmap Wm3glXDestroyPixmap;
#define glXDestroyPixmap Wm3glXDestroyPixmap

typedef GLXPbuffer (* pfn_glXCreatePbuffer) (Display*, GLXFBConfig, const int*);
WM3_EXTERN pfn_glXCreatePbuffer Wm3glXCreatePbuffer;
#define glXCreatePbuffer Wm3glXCreatePbuffer

typedef void (* pfn_glXDestroyPbuffer) (Display*, GLXPbuffer);
WM3_EXTERN pfn_glXDestroyPbuffer Wm3glXDestroyPbuffer;
#define glXDestroyPbuffer Wm3glXDestroyPbuffer

typedef void (* pfn_glXQueryDrawable) (Display*, GLXDrawable, int, unsigned int*);
WM3_EXTERN pfn_glXQueryDrawable Wm3glXQueryDrawable;
#define glXQueryDrawable Wm3glXQueryDrawable

typedef GLXContext (* pfn_glXCreateNewContext) (Display*, GLXFBConfig, int, GLXContext, Bool);
WM3_EXTERN pfn_glXCreateNewContext Wm3glXCreateNewContext;
#define glXCreateNewContext Wm3glXCreateNewContext

typedef Bool (* pfn_glXMakeContextCurrent) (Display*, GLXDrawable, GLXDrawable, GLXContext);
WM3_EXTERN pfn_glXMakeContextCurrent Wm3glXMakeContextCurrent;
#define glXMakeContextCurrent Wm3glXMakeContextCurrent

typedef GLXDrawable (* pfn_glXGetCurrentReadDrawable) (void);
WM3_EXTERN pfn_glXGetCurrentReadDrawable Wm3glXGetCurrentReadDrawable;
#define glXGetCurrentReadDrawable Wm3glXGetCurrentReadDrawable

typedef int (* pfn_glXQueryContext) (Display*, GLXContext, int, int*);
WM3_EXTERN pfn_glXQueryContext Wm3glXQueryContext;
#define glXQueryContext Wm3glXQueryContext

typedef void (* pfn_glXSelectEvent) (Display*, GLXDrawable, unsigned long);
WM3_EXTERN pfn_glXSelectEvent Wm3glXSelectEvent;
#define glXSelectEvent Wm3glXSelectEvent

typedef void (* pfn_glXGetSelectedEvent) (Display*, GLXDrawable, unsigned long*);
WM3_EXTERN pfn_glXGetSelectedEvent Wm3glXGetSelectedEvent;
#define glXGetSelectedEvent Wm3glXGetSelectedEvent
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GLX_VERSION_1_4;
WM3_EXTERN int Wm3NumFunctions_GLX_VERSION_1_4;
#ifndef GLX_VERSION_1_4
#define GLX_VERSION_1_4
#define WM3_DEFINED_GLX_VERSION_1_4
#define GLX_SAMPLE_BUFFERS                 100000
#define GLX_SAMPLES                        100001
extern void (*glXGetProcAddress (const GLubyte*))(void);
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GLX_ARB_get_proc_address;
WM3_EXTERN int Wm3NumFunctions_GLX_ARB_get_proc_address;
#ifndef GLX_ARB_get_proc_address
#define GLX_ARB_get_proc_address
#define WM3_DEFINED_GLX_ARB_get_proc_address
extern void (*glXGetProcAddressARB (const GLubyte*))(void);
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GLX_ARB_multisample;
WM3_EXTERN int Wm3NumFunctions_GLX_ARB_multisample;
#ifndef GLX_ARB_multisample
#define GLX_ARB_multisample
#define WM3_DEFINED_GLX_ARB_multisample
#define GLX_SAMPLE_BUFFERS_ARB             100000
#define GLX_SAMPLES_ARB                    100001
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GLX_ARB_fbconfig_float;
WM3_EXTERN int Wm3NumFunctions_GLX_ARB_fbconfig_float;
#ifndef GLX_ARB_fbconfig_float
#define GLX_ARB_fbconfig_float
#define WM3_DEFINED_GLX_ARB_fbconfig_float
#define GLX_RGBA_FLOAT_TYPE_ARB            0x20B9
#define GLX_RGBA_FLOAT_BIT_ARB             0x00000004
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GLX_SGIS_multisample;
WM3_EXTERN int Wm3NumFunctions_GLX_SGIS_multisample;
#ifndef GLX_SGIS_multisample
#define GLX_SGIS_multisample
#define WM3_DEFINED_GLX_SGIS_multisample
#define GLX_SAMPLE_BUFFERS_SGIS            100000
#define GLX_SAMPLES_SGIS                   100001
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GLX_EXT_visual_info;
WM3_EXTERN int Wm3NumFunctions_GLX_EXT_visual_info;
#ifndef GLX_EXT_visual_info
#define GLX_EXT_visual_info
#define WM3_DEFINED_GLX_EXT_visual_info
#define GLX_X_VISUAL_TYPE_EXT              0x22
#define GLX_TRANSPARENT_TYPE_EXT           0x23
#define GLX_TRANSPARENT_INDEX_VALUE_EXT    0x24
#define GLX_TRANSPARENT_RED_VALUE_EXT      0x25
#define GLX_TRANSPARENT_GREEN_VALUE_EXT    0x26
#define GLX_TRANSPARENT_BLUE_VALUE_EXT     0x27
#define GLX_TRANSPARENT_ALPHA_VALUE_EXT    0x28
#define GLX_NONE_EXT                       0x8000
#define GLX_TRUE_COLOR_EXT                 0x8002
#define GLX_DIRECT_COLOR_EXT               0x8003
#define GLX_PSEUDO_COLOR_EXT               0x8004
#define GLX_STATIC_COLOR_EXT               0x8005
#define GLX_GRAY_SCALE_EXT                 0x8006
#define GLX_STATIC_GRAY_EXT                0x8007
#define GLX_TRANSPARENT_RGB_EXT            0x8008
#define GLX_TRANSPARENT_INDEX_EXT          0x8009
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GLX_SGI_swap_control;
WM3_EXTERN int Wm3NumFunctions_GLX_SGI_swap_control;
#ifndef GLX_SGI_swap_control
#define GLX_SGI_swap_control
#define WM3_DEFINED_GLX_SGI_swap_control

typedef int (* pfn_glXSwapIntervalSGI) (int);
WM3_EXTERN pfn_glXSwapIntervalSGI Wm3glXSwapIntervalSGI;
#define glXSwapIntervalSGI Wm3glXSwapIntervalSGI
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GLX_SGI_video_sync;
WM3_EXTERN int Wm3NumFunctions_GLX_SGI_video_sync;
#ifndef GLX_SGI_video_sync
#define GLX_SGI_video_sync
#define WM3_DEFINED_GLX_SGI_video_sync

typedef int (* pfn_glXGetVideoSyncSGI) (unsigned int*);
WM3_EXTERN pfn_glXGetVideoSyncSGI Wm3glXGetVideoSyncSGI;
#define glXGetVideoSyncSGI Wm3glXGetVideoSyncSGI

typedef int (* pfn_glXWaitVideoSyncSGI) (int, int, unsigned int*);
WM3_EXTERN pfn_glXWaitVideoSyncSGI Wm3glXWaitVideoSyncSGI;
#define glXWaitVideoSyncSGI Wm3glXWaitVideoSyncSGI
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GLX_SGI_make_current_read;
WM3_EXTERN int Wm3NumFunctions_GLX_SGI_make_current_read;
#ifndef GLX_SGI_make_current_read
#define GLX_SGI_make_current_read
#define WM3_DEFINED_GLX_SGI_make_current_read

typedef Bool (* pfn_glXGetCurrentReadDrawableSGI) (Display*, GLXDrawable, GLXDrawable, GLXContext);
WM3_EXTERN pfn_glXGetCurrentReadDrawableSGI Wm3glXGetCurrentReadDrawableSGI;
#define glXGetCurrentReadDrawableSGI Wm3glXGetCurrentReadDrawableSGI

typedef GLXDrawable (* pfn_glXMakeCurrentReadSGI) (void);
WM3_EXTERN pfn_glXMakeCurrentReadSGI Wm3glXMakeCurrentReadSGI;
#define glXMakeCurrentReadSGI Wm3glXMakeCurrentReadSGI
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GLX_EXT_visual_rating;
WM3_EXTERN int Wm3NumFunctions_GLX_EXT_visual_rating;
#ifndef GLX_EXT_visual_rating
#define GLX_EXT_visual_rating
#define WM3_DEFINED_GLX_EXT_visual_rating
#define GLX_VISUAL_CAVEAT_EXT              0x20
#define GLX_SLOW_VISUAL_EXT                0x8001
#define GLX_NON_CONFORMANT_VISUAL_EXT      0x800D
/* reuse GLX_NONE_EXT */
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GLX_EXT_import_context;
WM3_EXTERN int Wm3NumFunctions_GLX_EXT_import_context;
#ifndef GLX_EXT_import_context
#define GLX_EXT_import_context
#define WM3_DEFINED_GLX_EXT_import_context
#define GLX_SHARE_CONTEXT_EXT              0x800A
#define GLX_VISUAL_ID_EXT                  0x800B
#define GLX_SCREEN_EXT                     0x800C
typedef XID GLXContextID;

typedef Display* (* pfn_glXGetCurrentDisplayEXT) (void);
WM3_EXTERN pfn_glXGetCurrentDisplayEXT Wm3glXGetCurrentDisplayEXT;
#define glXGetCurrentDisplayEXT Wm3glXGetCurrentDisplayEXT

typedef int (* pfn_glXQueryContextInfoEXT) (Display*, GLXContext, int, int*);
WM3_EXTERN pfn_glXQueryContextInfoEXT Wm3glXQueryContextInfoEXT;
#define glXQueryContextInfoEXT Wm3glXQueryContextInfoEXT

typedef GLXContextID (* pfn_glXGetContextIDEXT) (const GLXContext);
WM3_EXTERN pfn_glXGetContextIDEXT Wm3glXGetContextIDEXT;
#define glXGetContextIDEXT Wm3glXGetContextIDEXT

typedef GLXContext (* pfn_glXImportContextEXT) (Display*, GLXContextID);
WM3_EXTERN pfn_glXImportContextEXT Wm3glXImportContextEXT;
#define glXImportContextEXT Wm3glXImportContextEXT

typedef void (* pfn_glXFreeContextEXT) (Display*, GLXContext);
WM3_EXTERN pfn_glXFreeContextEXT Wm3glXFreeContextEXT;
#define glXFreeContextEXT Wm3glXFreeContextEXT
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GLX_SGIX_fbconfig;
WM3_EXTERN int Wm3NumFunctions_GLX_SGIX_fbconfig;
#ifndef GLX_SGIX_fbconfig
#define GLX_SGIX_fbconfig
#define WM3_DEFINED_GLX_SGIX_fbconfig
#define GLX_WINDOW_BIT_SGIX                0x00000001
#define GLX_PIXMAP_BIT_SGIX                0x00000002
#define GLX_RGBA_BIT_SGIX                  0x00000001
#define GLX_COLOR_INDEX_BIT_SGIX           0x00000002
#define GLX_DRAWABLE_TYPE_SGIX             0x8010
#define GLX_RENDER_TYPE_SGIX               0x8011
#define GLX_X_RENDERABLE_SGIX              0x8012
#define GLX_FBCONFIG_ID_SGIX               0x8013
#define GLX_RGBA_TYPE_SGIX                 0x8014
#define GLX_COLOR_INDEX_TYPE_SGIX          0x8015
/* reuse GLX_SCREEN_EXT */
typedef XID GLXFBConfigIDSGIX;
typedef struct __GLXFBConfigRec* GLXFBConfigSGIX;

typedef int (* pfn_glXGetFBConfigAttribSGIX) (Display*, GLXFBConfigSGIX, int, int*);
WM3_EXTERN pfn_glXGetFBConfigAttribSGIX Wm3glXGetFBConfigAttribSGIX;
#define glXGetFBConfigAttribSGIX Wm3glXGetFBConfigAttribSGIX

typedef GLXFBConfigSGIX* (* pfn_glXChooseFBConfigSGIX) (Display*, int, int*, int*);
WM3_EXTERN pfn_glXChooseFBConfigSGIX Wm3glXChooseFBConfigSGIX;
#define glXChooseFBConfigSGIX Wm3glXChooseFBConfigSGIX

typedef GLXPixmap (* pfn_glXCreateGLXPixmapWithConfigSGIX) (Display*, GLXFBConfigSGIX, Pixmap);
WM3_EXTERN pfn_glXCreateGLXPixmapWithConfigSGIX Wm3glXCreateGLXPixmapWithConfigSGIX;
#define glXCreateGLXPixmapWithConfigSGIX Wm3glXCreateGLXPixmapWithConfigSGIX

typedef GLXContext (* pfn_glXCreateContextWithConfigSGIX) (Display*, GLXFBConfigSGIX, int, GLXContext, Bool);
WM3_EXTERN pfn_glXCreateContextWithConfigSGIX Wm3glXCreateContextWithConfigSGIX;
#define glXCreateContextWithConfigSGIX Wm3glXCreateContextWithConfigSGIX

typedef XVisualInfo* (* pfn_glXGetVisualFromFBConfigSGIX) (Display*, GLXFBConfigSGIX);
WM3_EXTERN pfn_glXGetVisualFromFBConfigSGIX Wm3glXGetVisualFromFBConfigSGIX;
#define glXGetVisualFromFBConfigSGIX Wm3glXGetVisualFromFBConfigSGIX

typedef GLXFBConfigSGIX (* pfn_glXGetFBConfigFromVisualSGIX) (Display*, XVisualInfo*);
WM3_EXTERN pfn_glXGetFBConfigFromVisualSGIX Wm3glXGetFBConfigFromVisualSGIX;
#define glXGetFBConfigFromVisualSGIX Wm3glXGetFBConfigFromVisualSGIX
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GLX_SGIX_pbuffer;
WM3_EXTERN int Wm3NumFunctions_GLX_SGIX_pbuffer;
#ifndef GLX_SGIX_pbuffer
#define GLX_SGIX_pbuffer
#define WM3_DEFINED_GLX_SGIX_pbuffer
#define GLX_PBUFFER_BIT_SGIX               0x00000004
#define GLX_BUFFER_CLOBBER_MASK_SGIX       0x08000000
#define GLX_FRONT_LEFT_BUFFER_BIT_SGIX     0x00000001
#define GLX_FRONT_RIGHT_BUFFER_BIT_SGIX    0x00000002
#define GLX_BACK_LEFT_BUFFER_BIT_SGIX      0x00000004
#define GLX_BACK_RIGHT_BUFFER_BIT_SGIX     0x00000008
#define GLX_AUX_BUFFERS_BIT_SGIX           0x00000010
#define GLX_DEPTH_BUFFER_BIT_SGIX          0x00000020
#define GLX_STENCIL_BUFFER_BIT_SGIX        0x00000040
#define GLX_ACCUM_BUFFER_BIT_SGIX          0x00000080
#define GLX_SAMPLE_BUFFERS_BIT_SGIX        0x00000100
#define GLX_MAX_PBUFFER_WIDTH_SGIX         0x8016
#define GLX_MAX_PBUFFER_HEIGHT_SGIX        0x8017
#define GLX_MAX_PBUFFER_PIXELS_SGIX        0x8018
#define GLX_OPTIMAL_PBUFFER_WIDTH_SGIX     0x8019
#define GLX_OPTIMAL_PBUFFER_HEIGHT_SGIX    0x801A
#define GLX_PRESERVED_CONTENTS_SGIX        0x801B
#define GLX_LARGEST_PBUFFER_SGIX           0x801C
#define GLX_WIDTH_SGIX                     0x801D
#define GLX_HEIGHT_SGIX                    0x801E
#define GLX_EVENT_MASK_SGIX                0x801F
#define GLX_DAMAGED_SGIX                   0x8020
#define GLX_SAVED_SGIX                     0x8021
#define GLX_WINDOW_SGIX                    0x8022
#define GLX_PBUFFER_SGIX                   0x8023
typedef XID GLXPbufferSGIX;
typedef struct
{
    int type;
    unsigned long serial;   /* # of last request processed by server */
    Bool send_event;        /* true if this came for SendEvent request */
    Display *display;       /* display the event was read from */
    GLXDrawable drawable;   /* i.d. of Drawable */
    int event_type;         /* GLX_DAMAGED_SGIX or GLX_SAVED_SGIX */
    int draw_type;          /* GLX_WINDOW_SGIX or GLX_PBUFFER_SGIX */
    unsigned int mask;      /* mask indicating which buffers are affected*/
    int x, y;
    int width, height;
    int count;              /* if nonzero, at least this many more */
}
GLXBufferClobberEventSGIX;

typedef GLXPbufferSGIX (* pfn_glXCreateGLXPbufferSGIX) (Display*, GLXFBConfigSGIX, unsigned int, unsigned int, int*);
WM3_EXTERN pfn_glXCreateGLXPbufferSGIX Wm3glXCreateGLXPbufferSGIX;
#define glXCreateGLXPbufferSGIX Wm3glXCreateGLXPbufferSGIX

typedef void (* pfn_glXDestroyGLXPbufferSGIX) (Display*, GLXPbufferSGIX);
WM3_EXTERN pfn_glXDestroyGLXPbufferSGIX Wm3glXDestroyGLXPbufferSGIX;
#define glXDestroyGLXPbufferSGIX Wm3glXDestroyGLXPbufferSGIX

typedef int (* pfn_glXQueryGLXPbufferSGIX) (Display*, GLXPbufferSGIX, int, unsigned int*);
WM3_EXTERN pfn_glXQueryGLXPbufferSGIX Wm3glXQueryGLXPbufferSGIX;
#define glXQueryGLXPbufferSGIX Wm3glXQueryGLXPbufferSGIX

typedef void (* pfn_glXSelectEventSGIX) (Display*, GLXDrawable, unsigned long);
WM3_EXTERN pfn_glXSelectEventSGIX Wm3glXSelectEventSGIX;
#define glXSelectEventSGIX Wm3glXSelectEventSGIX

typedef void (* pfn_glXGetSelectedEventSGIX) (Display*, GLXDrawable, unsigned long*);
WM3_EXTERN pfn_glXGetSelectedEventSGIX Wm3glXGetSelectedEventSGIX;
#define glXGetSelectedEventSGIX Wm3glXGetSelectedEventSGIX
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GLX_SGI_cushion;
WM3_EXTERN int Wm3NumFunctions_GLX_SGI_cushion;
#ifndef GLX_SGI_cushion
#define GLX_SGI_cushion
#define WM3_DEFINED_GLX_SGI_cushion

typedef void (* pfn_glXCushionSGI) (Display*, Window, float);
WM3_EXTERN pfn_glXCushionSGI Wm3glXCushionSGI;
#define glXCushionSGI Wm3glXCushionSGI
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GLX_SGIX_video_resize;
WM3_EXTERN int Wm3NumFunctions_GLX_SGIX_video_resize;
#ifndef GLX_SGIX_video_resize
#define GLX_SGIX_video_resize
#define WM3_DEFINED_GLX_SGIX_video_resize
#define GLX_SYNC_FRAME_SGIX                0x00000000
#define GLX_SYNC_SWAP_SGIX                 0x00000001

typedef int (* pfn_glXBindChannelToWindowSGIX) (Display*, int, int, Window);
WM3_EXTERN pfn_glXBindChannelToWindowSGIX Wm3glXBindChannelToWindowSGIX;
#define glXBindChannelToWindowSGIX Wm3glXBindChannelToWindowSGIX

typedef int (* pfn_glXChannelRectSGIX) (Display*, int, int, int, int, int, int);
WM3_EXTERN pfn_glXChannelRectSGIX Wm3glXChannelRectSGIX;
#define glXChannelRectSGIX Wm3glXChannelRectSGIX

typedef int (* pfn_glXQueryChannelRectSGIX) (Display*, int, int, int*, int*, int*, int*);
WM3_EXTERN pfn_glXQueryChannelRectSGIX Wm3glXQueryChannelRectSGIX;
#define glXQueryChannelRectSGIX Wm3glXQueryChannelRectSGIX

typedef int (* pfn_glXQueryChannelDeltasSGIX) (Display*, int, int, int*, int*, int*, int*);
WM3_EXTERN pfn_glXQueryChannelDeltasSGIX Wm3glXQueryChannelDeltasSGIX;
#define glXQueryChannelDeltasSGIX Wm3glXQueryChannelDeltasSGIX

typedef int (* pfn_glXChannelRectSyncSGIX) (Display*, int, int, GLenum);
WM3_EXTERN pfn_glXChannelRectSyncSGIX Wm3glXChannelRectSyncSGIX;
#define glXChannelRectSyncSGIX Wm3glXChannelRectSyncSGIX
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GLX_SGIX_dmbuffer;
WM3_EXTERN int Wm3NumFunctions_GLX_SGIX_dmbuffer;
#ifndef GLX_SGIX_dmbuffer
#define GLX_SGIX_dmbuffer
#define WM3_DEFINED_GLX_SGIX_dmbuffer
/*
The type DMparams and DMbuffer are not defined in glxext.h.  Once ported to
the SGI, I will expose this extension.

#define GLX_DIGITAL_MEDIA_PBUFFER_SGIX     0x8024
typedef Bool (*PFNGLXASSOCIATEDMPBUFFERSGIXPROC)(Display*, GLXPbufferSGIX, DMparams*, DMbuffer);
extern PFNGLXASSOCIATEDMPBUFFERSGIXPROC glXAssociatedMPbufferSGIX;
*/
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GLX_SGIX_swap_group;
WM3_EXTERN int Wm3NumFunctions_GLX_SGIX_swap_group;
#ifndef GLX_SGIX_swap_group
#define GLX_SGIX_swap_group
#define WM3_DEFINED_GLX_SGIX_swap_group

typedef void (* pfn_glXJoinSwapGroupSGIX) (Display*, GLXDrawable, GLXDrawable);
WM3_EXTERN pfn_glXJoinSwapGroupSGIX Wm3glXJoinSwapGroupSGIX;
#define glXJoinSwapGroupSGIX Wm3glXJoinSwapGroupSGIX
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GLX_SGIX_swap_barrier;
WM3_EXTERN int Wm3NumFunctions_GLX_SGIX_swap_barrier;
#ifndef GLX_SGIX_swap_barrier
#define GLX_SGIX_swap_barrier
#define WM3_DEFINED_GLX_SGIX_swap_barrier

typedef void (* pfn_glXBindSwapBarrierSGIX) (Display*, GLXDrawable, int);
WM3_EXTERN pfn_glXBindSwapBarrierSGIX Wm3glXBindSwapBarrierSGIX;
#define glXBindSwapBarrierSGIX Wm3glXBindSwapBarrierSGIX

typedef Bool (* pfn_glXQueryMaxSwapBarriersSGIX) (Display*, int, int*);
WM3_EXTERN pfn_glXQueryMaxSwapBarriersSGIX Wm3glXQueryMaxSwapBarriersSGIX;
#define glXQueryMaxSwapBarriersSGIX Wm3glXQueryMaxSwapBarriersSGIX
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GLX_SGIS_blended_overlay;
WM3_EXTERN int Wm3NumFunctions_GLX_SGIS_blended_overlay;
#ifndef GLX_SGIS_blended_overlay
#define GLX_SGIS_blended_overlay
#define WM3_DEFINED_GLX_SGIS_blended_overlay
#define GLX_BLENDED_RGBA_SGIS              0x8025
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GLX_SGIS_shared_multisample;
WM3_EXTERN int Wm3NumFunctions_GLX_SGIS_shared_multisample;
#ifndef GLX_SGIS_shared_multisample
#define GLX_SGIS_shared_multisample
#define WM3_DEFINED_GLX_SGIS_shared_multisample
#define GLX_MULTISAMPLE_SUB_RECT_WIDTH_SGIS 0x8026
#define GLX_MULTISAMPLE_SUB_RECT_HEIGHT_SGIS 0x8027
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GLX_SUN_get_transparent_index;
WM3_EXTERN int Wm3NumFunctions_GLX_SUN_get_transparent_index;
#ifndef GLX_SUN_get_transparent_index
#define GLX_SUN_get_transparent_index
#define WM3_DEFINED_GLX_SUN_get_transparent_index

typedef Status (* pfn_glXGetTransparentIndexSUN) (Display*, Window, Window, long*);
WM3_EXTERN pfn_glXGetTransparentIndexSUN Wm3glXGetTransparentIndexSUN;
#define glXGetTransparentIndexSUN Wm3glXGetTransparentIndexSUN
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GLX_3DFX_multisample;
WM3_EXTERN int Wm3NumFunctions_GLX_3DFX_multisample;
#ifndef GLX_3DFX_multisample
#define GLX_3DFX_multisample
#define WM3_DEFINED_GLX_3DFX_multisample
#define GLX_SAMPLE_BUFFERS_3DFX            0x8050
#define GLX_SAMPLES_3DFX                   0x8051
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GLX_MESA_copy_sub_buffer;
WM3_EXTERN int Wm3NumFunctions_GLX_MESA_copy_sub_buffer;
#ifndef GLX_MESA_copy_sub_buffer
#define GLX_MESA_copy_sub_buffer
#define WM3_DEFINED_GLX_MESA_copy_sub_buffer

typedef void (* pfn_glXCopySubBufferMESA) (Display*, GLXDrawable, int, int, int, int);
WM3_EXTERN pfn_glXCopySubBufferMESA Wm3glXCopySubBufferMESA;
#define glXCopySubBufferMESA Wm3glXCopySubBufferMESA
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GLX_MESA_pixmap_colormap;
WM3_EXTERN int Wm3NumFunctions_GLX_MESA_pixmap_colormap;
#ifndef GLX_MESA_pixmap_colormap
#define GLX_MESA_pixmap_colormap
#define WM3_DEFINED_GLX_MESA_pixmap_colormap

typedef GLXPixmap (* pfn_glXCreateGLXPixmapMESA) (Display*, XVisualInfo*, Pixmap, Colormap);
WM3_EXTERN pfn_glXCreateGLXPixmapMESA Wm3glXCreateGLXPixmapMESA;
#define glXCreateGLXPixmapMESA Wm3glXCreateGLXPixmapMESA
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GLX_MESA_release_buffers;
WM3_EXTERN int Wm3NumFunctions_GLX_MESA_release_buffers;
#ifndef GLX_MESA_release_buffers
#define GLX_MESA_release_buffers
#define WM3_DEFINED_GLX_MESA_release_buffers

typedef Bool (* pfn_glXReleaseBuffersMESA) (Display*, GLXDrawable);
WM3_EXTERN pfn_glXReleaseBuffersMESA Wm3glXReleaseBuffersMESA;
#define glXReleaseBuffersMESA Wm3glXReleaseBuffersMESA
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GLX_MESA_set_3dfx_mode;
WM3_EXTERN int Wm3NumFunctions_GLX_MESA_set_3dfx_mode;
#ifndef GLX_MESA_set_3dfx_mode
#define GLX_MESA_set_3dfx_mode
#define WM3_DEFINED_GLX_MESA_set_3dfx_mode
#define GLX_3DFX_WINDOW_MODE_MESA          0x1
#define GLX_3DFX_FULLSCREEN_MODE_MESA      0x2

typedef Bool (* pfn_glXSet3DfxModeMESA) (int);
WM3_EXTERN pfn_glXSet3DfxModeMESA Wm3glXSet3DfxModeMESA;
#define glXSet3DfxModeMESA Wm3glXSet3DfxModeMESA
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GLX_SGIX_visual_select_group;
WM3_EXTERN int Wm3NumFunctions_GLX_SGIX_visual_select_group;
#ifndef GLX_SGIX_visual_select_group
#define GLX_SGIX_visual_select_group
#define WM3_DEFINED_GLX_SGIX_visual_select_group
#define GLX_VISUAL_SELECT_GROUP_SGIX       0x8028
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GLX_OML_swap_method;
WM3_EXTERN int Wm3NumFunctions_GLX_OML_swap_method;
#ifndef GLX_OML_swap_method
#define GLX_OML_swap_method
#define WM3_DEFINED_GLX_OML_swap_method
#define GLX_SWAP_METHOD_OML                0x8060
#define GLX_SWAP_EXCHANGE_OML              0x8061
#define GLX_SWAP_COPY_OML                  0x8062
#define GLX_SWAP_UNDEFINED_OML             0x8063
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GLX_OML_sync_control;
WM3_EXTERN int Wm3NumFunctions_GLX_OML_sync_control;
#ifndef GLX_OML_sync_control
#define GLX_OML_sync_control
#define WM3_DEFINED_GLX_OML_sync_control
#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
#include <inttypes.h>
#elif defined( __VMS )
#include <inttypes.h>
#elif defined(__SCO__) || defined(__USLC__)
#include <stdint.h>
#elif defined(__UNIXOS2__) || defined(__SOL64__)
typedef long int int32_t;
typedef long long int int64_t;
#else
typedef long long int int64_t;
#endif

typedef Bool (* pfn_glXGetSyncValuesOML) (Display*, GLXDrawable, int64_t*, int64_t*, int64_t*);
WM3_EXTERN pfn_glXGetSyncValuesOML Wm3glXGetSyncValuesOML;
#define glXGetSyncValuesOML Wm3glXGetSyncValuesOML

typedef Bool (* pfn_glXGetMscRateOML) (Display*, GLXDrawable, int32_t*, int32_t*);
WM3_EXTERN pfn_glXGetMscRateOML Wm3glXGetMscRateOML;
#define glXGetMscRateOML Wm3glXGetMscRateOML

typedef int64_t (* pfn_glXSwapBuffersMscOML) (Display*, GLXDrawable, int64_t, int64_t, int64_t);
WM3_EXTERN pfn_glXSwapBuffersMscOML Wm3glXSwapBuffersMscOML;
#define glXSwapBuffersMscOML Wm3glXSwapBuffersMscOML

typedef Bool (* pfn_glXWaitForMscOML) (Display*, GLXDrawable, int64_t, int64_t, int64_t, int64_t*, int64_t*, int64_t*);
WM3_EXTERN pfn_glXWaitForMscOML Wm3glXWaitForMscOML;
#define glXWaitForMscOML Wm3glXWaitForMscOML

typedef Bool (* pfn_glXWaitForSbcOML) (Display*, GLXDrawable, int64_t, int64_t*, int64_t*, int64_t*);
WM3_EXTERN pfn_glXWaitForSbcOML Wm3glXWaitForSbcOML;
#define glXWaitForSbcOML Wm3glXWaitForSbcOML
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GLX_NV_float_buffer;
WM3_EXTERN int Wm3NumFunctions_GLX_NV_float_buffer;
#ifndef GLX_NV_float_buffer
#define GLX_NV_float_buffer
#define WM3_DEFINED_GLX_NV_float_buffer
#define GLX_FLOAT_COMPONENTS_NV            0x20B0
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GLX_SGIX_hyperpipe;
WM3_EXTERN int Wm3NumFunctions_GLX_SGIX_hyperpipe;
#ifndef GLX_SGIX_hyperpipe
#define GLX_SGIX_hyperpipe
#define WM3_DEFINED_GLX_SGIX_hyperpipe
#define GLX_HYPERPIPE_PIPE_NAME_LENGTH_SGIX 80
#define GLX_BAD_HYPERPIPE_CONFIG_SGIX      91
#define GLX_BAD_HYPERPIPE_SGIX             92
#define GLX_HYPERPIPE_DISPLAY_PIPE_SGIX    0x00000001
#define GLX_HYPERPIPE_RENDER_PIPE_SGIX     0x00000002
#define GLX_PIPE_RECT_SGIX                 0x00000001
#define GLX_PIPE_RECT_LIMITS_SGIX          0x00000002
#define GLX_HYPERPIPE_STEREO_SGIX          0x00000003
#define GLX_HYPERPIPE_PIXEL_AVERAGE_SGIX   0x00000004
#define GLX_HYPERPIPE_ID_SGIX              0x8030
typedef struct
{
    char pipeName[GLX_HYPERPIPE_PIPE_NAME_LENGTH_SGIX];
    int  networkId;
}
GLXHyperpipeNetworkSGIX;
typedef struct
{
    char pipeName[GLX_HYPERPIPE_PIPE_NAME_LENGTH_SGIX];
    int channel;
    unsigned int participationType;
    int timeSlice;
}
GLXHyperpipeConfigSGIX;
typedef struct
{
    char pipeName[GLX_HYPERPIPE_PIPE_NAME_LENGTH_SGIX];
    int srcXOrigin, srcYOrigin, srcWidth, srcHeight;
    int destXOrigin, destYOrigin, destWidth, destHeight;
}
GLXPipeRect;
typedef struct
{
    char pipeName[GLX_HYPERPIPE_PIPE_NAME_LENGTH_SGIX];
    int XOrigin, YOrigin, maxHeight, maxWidth;
}
GLXPipeRectLimits;

typedef GLXHyperpipeNetworkSGIX* (* pfn_glXQueryHyperpipeNetworkSGIX) (Display*, int*);
WM3_EXTERN pfn_glXQueryHyperpipeNetworkSGIX Wm3glXQueryHyperpipeNetworkSGIX;
#define glXQueryHyperpipeNetworkSGIX Wm3glXQueryHyperpipeNetworkSGIX

typedef int (* pfn_glXHyperpipeConfigSGIX) (Display*, int, int, GLXHyperpipeConfigSGIX*, int*);
WM3_EXTERN pfn_glXHyperpipeConfigSGIX Wm3glXHyperpipeConfigSGIX;
#define glXHyperpipeConfigSGIX Wm3glXHyperpipeConfigSGIX

typedef GLXHyperpipeConfigSGIX* (* pfn_glXQueryHyperpipeConfigSGIX) (Display*, int, int*);
WM3_EXTERN pfn_glXQueryHyperpipeConfigSGIX Wm3glXQueryHyperpipeConfigSGIX;
#define glXQueryHyperpipeConfigSGIX Wm3glXQueryHyperpipeConfigSGIX

typedef int (* pfn_glXDestroyHyperpipeConfigSGIX) (Display*, int);
WM3_EXTERN pfn_glXDestroyHyperpipeConfigSGIX Wm3glXDestroyHyperpipeConfigSGIX;
#define glXDestroyHyperpipeConfigSGIX Wm3glXDestroyHyperpipeConfigSGIX

typedef int (* pfn_glXBindHyperpipeSGIX) (Display*, int);
WM3_EXTERN pfn_glXBindHyperpipeSGIX Wm3glXBindHyperpipeSGIX;
#define glXBindHyperpipeSGIX Wm3glXBindHyperpipeSGIX

typedef int (* pfn_glXQueryHyperpipeBestAttribSGIX) (Display*, int, int, int, void*, void*);
WM3_EXTERN pfn_glXQueryHyperpipeBestAttribSGIX Wm3glXQueryHyperpipeBestAttribSGIX;
#define glXQueryHyperpipeBestAttribSGIX Wm3glXQueryHyperpipeBestAttribSGIX

typedef int (* pfn_glXHyperpipeAttribSGIX) (Display*, int, int, int, void*);
WM3_EXTERN pfn_glXHyperpipeAttribSGIX Wm3glXHyperpipeAttribSGIX;
#define glXHyperpipeAttribSGIX Wm3glXHyperpipeAttribSGIX

typedef int (* pfn_glXQueryHyperpipeAttribSGIX) (Display*, int, int, int, void*);
WM3_EXTERN pfn_glXQueryHyperpipeAttribSGIX Wm3glXQueryHyperpipeAttribSGIX;
#define glXQueryHyperpipeAttribSGIX Wm3glXQueryHyperpipeAttribSGIX
#endif

/*--------------------------------------------------------------------------*/
WM3_EXTERN int Wm3Exists_GLX_MESA_agp_offset;
WM3_EXTERN int Wm3NumFunctions_GLX_MESA_agp_offset;
#ifndef GLX_MESA_agp_offset
#define GLX_MESA_agp_offset
#define WM3_DEFINED_GLX_MESA_agp_offset

typedef unsigned int (* pfn_glXGetAGPOffsetMesa) (const void*);
WM3_EXTERN pfn_glXGetAGPOffsetMesa Wm3glXGetAGPOffsetMesa;
#define glXGetAGPOffsetMesa Wm3glXGetAGPOffsetMesa
#endif

/*--------------------------------------------------------------------------*/
void InitializeGlx ();
/*--------------------------------------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif
