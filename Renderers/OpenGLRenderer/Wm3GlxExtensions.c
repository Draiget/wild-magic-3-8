/*
Geometric Tools, Inc.
http://www.geometrictools.com
Copyright (c) 1998-2005.  All Rights Reserved

The Wild Magic Library (WM3) source code is supplied under the terms of
the license agreement
    http://www.geometrictools.com/License/WildMagic3License.pdf
and may not be copied or disclosed except in accordance with the terms
of that agreement.
*/

#ifndef _WIN32

#include "Wm3GlxExtensions.h"

/*--------------------------------------------------------------------------*/
void* GetFunctionPointer (const char* acFunction)
{
    return (void*)(*glXGetProcAddressARB)(acFunction);
}
/*--------------------------------------------------------------------------*/


/*--------------------------------------------------------------------------*/
int Wm3Exists_GLX_VERSION_1_0;
int Wm3NumFunctions_GLX_VERSION_1_0;
#ifdef WM3_DEFINED_GLX_VERSION_1_0
static void Init_GLX_VERSION_1_0 ()
{
    Wm3NumFunctions_GLX_VERSION_1_0 = 17;
    Wm3Exists_GLX_VERSION_1_0 = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GLX_VERSION_1_0 ()
{
    Wm3NumFunctions_GLX_VERSION_1_0 = 0;
    Wm3Exists_GLX_VERSION_1_0 = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GLX_VERSION_1_1;
int Wm3NumFunctions_GLX_VERSION_1_1;
#ifdef WM3_DEFINED_GLX_VERSION_1_1
static void Init_GLX_VERSION_1_1 ()
{
    Wm3NumFunctions_GLX_VERSION_1_1 = 3;
    Wm3Exists_GLX_VERSION_1_1 = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GLX_VERSION_1_1 ()
{
    Wm3NumFunctions_GLX_VERSION_1_1 = 0;
    Wm3Exists_GLX_VERSION_1_1 = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GLX_VERSION_1_2;
int Wm3NumFunctions_GLX_VERSION_1_2;
#ifdef WM3_DEFINED_GLX_VERSION_1_2
pfn_glXGetCurrentDisplay Wm3glXGetCurrentDisplay = 0;

static void Init_GLX_VERSION_1_2 ()
{
    Wm3NumFunctions_GLX_VERSION_1_2 = 0;

    Wm3glXGetCurrentDisplay = (pfn_glXGetCurrentDisplay)GetFunctionPointer("glXGetCurrentDisplay");
    if ( Wm3glXGetCurrentDisplay )
        ++Wm3NumFunctions_GLX_VERSION_1_2;

    if ( Wm3NumFunctions_GLX_VERSION_1_2 == 1 )
        Wm3Exists_GLX_VERSION_1_2 = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GLX_VERSION_1_2 = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GLX_VERSION_1_2 ()
{
    Wm3NumFunctions_GLX_VERSION_1_2 = 0;
    Wm3Exists_GLX_VERSION_1_2 = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GLX_VERSION_1_3;
int Wm3NumFunctions_GLX_VERSION_1_3;
#ifdef WM3_DEFINED_GLX_VERSION_1_3
pfn_glXGetFBConfigs Wm3glXGetFBConfigs = 0;
pfn_glXChooseFBConfig Wm3glXChooseFBConfig = 0;
pfn_glXGetFBConfigAttrib Wm3glXGetFBConfigAttrib = 0;
pfn_glXGetVisualFromFBConfig Wm3glXGetVisualFromFBConfig = 0;
pfn_glXCreateWindow Wm3glXCreateWindow = 0;
pfn_glXDestroyWindow Wm3glXDestroyWindow = 0;
pfn_glXCreatePixmap Wm3glXCreatePixmap = 0;
pfn_glXDestroyPixmap Wm3glXDestroyPixmap = 0;
pfn_glXCreatePbuffer Wm3glXCreatePbuffer = 0;
pfn_glXDestroyPbuffer Wm3glXDestroyPbuffer = 0;
pfn_glXQueryDrawable Wm3glXQueryDrawable = 0;
pfn_glXCreateNewContext Wm3glXCreateNewContext = 0;
pfn_glXMakeContextCurrent Wm3glXMakeContextCurrent = 0;
pfn_glXGetCurrentReadDrawable Wm3glXGetCurrentReadDrawable = 0;
pfn_glXQueryContext Wm3glXQueryContext = 0;
pfn_glXSelectEvent Wm3glXSelectEvent = 0;
pfn_glXGetSelectedEvent Wm3glXGetSelectedEvent = 0;

static void Init_GLX_VERSION_1_3 ()
{
    Wm3NumFunctions_GLX_VERSION_1_3 = 0;

    Wm3glXGetFBConfigs = (pfn_glXGetFBConfigs)GetFunctionPointer("glXGetFBConfigs");
    if ( Wm3glXGetFBConfigs )
        ++Wm3NumFunctions_GLX_VERSION_1_3;

    Wm3glXChooseFBConfig = (pfn_glXChooseFBConfig)GetFunctionPointer("glXChooseFBConfig");
    if ( Wm3glXChooseFBConfig )
        ++Wm3NumFunctions_GLX_VERSION_1_3;

    Wm3glXGetFBConfigAttrib = (pfn_glXGetFBConfigAttrib)GetFunctionPointer("glXGetFBConfigAttrib");
    if ( Wm3glXGetFBConfigAttrib )
        ++Wm3NumFunctions_GLX_VERSION_1_3;

    Wm3glXGetVisualFromFBConfig = (pfn_glXGetVisualFromFBConfig)GetFunctionPointer("glXGetVisualFromFBConfig");
    if ( Wm3glXGetVisualFromFBConfig )
        ++Wm3NumFunctions_GLX_VERSION_1_3;

    Wm3glXCreateWindow = (pfn_glXCreateWindow)GetFunctionPointer("glXCreateWindow");
    if ( Wm3glXCreateWindow )
        ++Wm3NumFunctions_GLX_VERSION_1_3;

    Wm3glXDestroyWindow = (pfn_glXDestroyWindow)GetFunctionPointer("glXDestroyWindow");
    if ( Wm3glXDestroyWindow )
        ++Wm3NumFunctions_GLX_VERSION_1_3;

    Wm3glXCreatePixmap = (pfn_glXCreatePixmap)GetFunctionPointer("glXCreatePixmap");
    if ( Wm3glXCreatePixmap )
        ++Wm3NumFunctions_GLX_VERSION_1_3;

    Wm3glXDestroyPixmap = (pfn_glXDestroyPixmap)GetFunctionPointer("glXDestroyPixmap");
    if ( Wm3glXDestroyPixmap )
        ++Wm3NumFunctions_GLX_VERSION_1_3;

    Wm3glXCreatePbuffer = (pfn_glXCreatePbuffer)GetFunctionPointer("glXCreatePbuffer");
    if ( Wm3glXCreatePbuffer )
        ++Wm3NumFunctions_GLX_VERSION_1_3;

    Wm3glXDestroyPbuffer = (pfn_glXDestroyPbuffer)GetFunctionPointer("glXDestroyPbuffer");
    if ( Wm3glXDestroyPbuffer )
        ++Wm3NumFunctions_GLX_VERSION_1_3;

    Wm3glXQueryDrawable = (pfn_glXQueryDrawable)GetFunctionPointer("glXQueryDrawable");
    if ( Wm3glXQueryDrawable )
        ++Wm3NumFunctions_GLX_VERSION_1_3;

    Wm3glXCreateNewContext = (pfn_glXCreateNewContext)GetFunctionPointer("glXCreateNewContext");
    if ( Wm3glXCreateNewContext )
        ++Wm3NumFunctions_GLX_VERSION_1_3;

    Wm3glXMakeContextCurrent = (pfn_glXMakeContextCurrent)GetFunctionPointer("glXMakeContextCurrent");
    if ( Wm3glXMakeContextCurrent )
        ++Wm3NumFunctions_GLX_VERSION_1_3;

    Wm3glXGetCurrentReadDrawable = (pfn_glXGetCurrentReadDrawable)GetFunctionPointer("glXGetCurrentReadDrawable");
    if ( Wm3glXGetCurrentReadDrawable )
        ++Wm3NumFunctions_GLX_VERSION_1_3;

    Wm3glXQueryContext = (pfn_glXQueryContext)GetFunctionPointer("glXQueryContext");
    if ( Wm3glXQueryContext )
        ++Wm3NumFunctions_GLX_VERSION_1_3;

    Wm3glXSelectEvent = (pfn_glXSelectEvent)GetFunctionPointer("glXSelectEvent");
    if ( Wm3glXSelectEvent )
        ++Wm3NumFunctions_GLX_VERSION_1_3;

    Wm3glXGetSelectedEvent = (pfn_glXGetSelectedEvent)GetFunctionPointer("glXGetSelectedEvent");
    if ( Wm3glXGetSelectedEvent )
        ++Wm3NumFunctions_GLX_VERSION_1_3;

    if ( Wm3NumFunctions_GLX_VERSION_1_3 == 17 )
        Wm3Exists_GLX_VERSION_1_3 = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GLX_VERSION_1_3 = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GLX_VERSION_1_3 ()
{
    Wm3NumFunctions_GLX_VERSION_1_3 = 0;
    Wm3Exists_GLX_VERSION_1_3 = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GLX_VERSION_1_4;
int Wm3NumFunctions_GLX_VERSION_1_4;
#ifdef WM3_DEFINED_GLX_VERSION_1_4
static void Init_GLX_VERSION_1_4 ()
{
    Wm3NumFunctions_GLX_VERSION_1_4 = 0;
    Wm3Exists_GLX_VERSION_1_4 = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GLX_VERSION_1_4 ()
{
    Wm3NumFunctions_GLX_VERSION_1_4 = 0;
    Wm3Exists_GLX_VERSION_1_4 = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GLX_ARB_get_proc_address;
int Wm3NumFunctions_GLX_ARB_get_proc_address;
#ifdef WM3_DEFINED_GLX_ARB_get_proc_address
static void Init_GLX_ARB_get_proc_address ()
{
    Wm3NumFunctions_GLX_ARB_get_proc_address = 0;
    Wm3Exists_GLX_ARB_get_proc_address = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GLX_ARB_get_proc_address ()
{
    Wm3NumFunctions_GLX_ARB_get_proc_address = 0;
    Wm3Exists_GLX_ARB_get_proc_address = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GLX_ARB_multisample;
int Wm3NumFunctions_GLX_ARB_multisample;
#ifdef WM3_DEFINED_GLX_ARB_multisample
static void Init_GLX_ARB_multisample ()
{
    Wm3NumFunctions_GLX_ARB_multisample = 0;
    Wm3Exists_GLX_ARB_multisample = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GLX_ARB_multisample ()
{
    Wm3NumFunctions_GLX_ARB_multisample = 0;
    Wm3Exists_GLX_ARB_multisample = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GLX_ARB_fbconfig_float;
int Wm3NumFunctions_GLX_ARB_fbconfig_float;
#ifdef WM3_DEFINED_GLX_ARB_fbconfig_float
static void Init_GLX_ARB_fbconfig_float ()
{
    Wm3NumFunctions_GLX_ARB_fbconfig_float = 0;
    Wm3Exists_GLX_ARB_fbconfig_float = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GLX_ARB_fbconfig_float ()
{
    Wm3NumFunctions_GLX_ARB_fbconfig_float = 0;
    Wm3Exists_GLX_ARB_fbconfig_float = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GLX_SGIS_multisample;
int Wm3NumFunctions_GLX_SGIS_multisample;
#ifdef WM3_DEFINED_GLX_SGIS_multisample
static void Init_GLX_SGIS_multisample ()
{
    Wm3NumFunctions_GLX_SGIS_multisample = 0;
    Wm3Exists_GLX_SGIS_multisample = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GLX_SGIS_multisample ()
{
    Wm3NumFunctions_GLX_SGIS_multisample = 0;
    Wm3Exists_GLX_SGIS_multisample = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GLX_EXT_visual_info;
int Wm3NumFunctions_GLX_EXT_visual_info;
#ifdef WM3_DEFINED_GLX_EXT_visual_info
static void Init_GLX_EXT_visual_info ()
{
    Wm3NumFunctions_GLX_EXT_visual_info = 0;
    Wm3Exists_GLX_EXT_visual_info = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GLX_EXT_visual_info ()
{
    Wm3NumFunctions_GLX_EXT_visual_info = 0;
    Wm3Exists_GLX_EXT_visual_info = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GLX_SGI_swap_control;
int Wm3NumFunctions_GLX_SGI_swap_control;
#ifdef WM3_DEFINED_GLX_SGI_swap_control
pfn_glXSwapIntervalSGI Wm3glXSwapIntervalSGI = 0;

static void Init_GLX_SGI_swap_control ()
{
    Wm3NumFunctions_GLX_SGI_swap_control = 0;

    Wm3glXSwapIntervalSGI = (pfn_glXSwapIntervalSGI)GetFunctionPointer("glXSwapIntervalSGI");
    if ( Wm3glXSwapIntervalSGI )
        ++Wm3NumFunctions_GLX_SGI_swap_control;

    if ( Wm3NumFunctions_GLX_SGI_swap_control == 1 )
        Wm3Exists_GLX_SGI_swap_control = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GLX_SGI_swap_control = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GLX_SGI_swap_control ()
{
    Wm3NumFunctions_GLX_SGI_swap_control = 0;
    Wm3Exists_GLX_SGI_swap_control = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GLX_SGI_video_sync;
int Wm3NumFunctions_GLX_SGI_video_sync;
#ifdef WM3_DEFINED_GLX_SGI_video_sync
pfn_glXGetVideoSyncSGI Wm3glXGetVideoSyncSGI = 0;
pfn_glXWaitVideoSyncSGI Wm3glXWaitVideoSyncSGI = 0;

static void Init_GLX_SGI_video_sync ()
{
    Wm3NumFunctions_GLX_SGI_video_sync = 0;

    Wm3glXGetVideoSyncSGI = (pfn_glXGetVideoSyncSGI)GetFunctionPointer("glXGetVideoSyncSGI");
    if ( Wm3glXGetVideoSyncSGI )
        ++Wm3NumFunctions_GLX_SGI_video_sync;

    Wm3glXWaitVideoSyncSGI = (pfn_glXWaitVideoSyncSGI)GetFunctionPointer("glXWaitVideoSyncSGI");
    if ( Wm3glXWaitVideoSyncSGI )
        ++Wm3NumFunctions_GLX_SGI_video_sync;

    if ( Wm3NumFunctions_GLX_SGI_video_sync == 2 )
        Wm3Exists_GLX_SGI_video_sync = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GLX_SGI_video_sync = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GLX_SGI_video_sync ()
{
    Wm3NumFunctions_GLX_SGI_video_sync = 0;
    Wm3Exists_GLX_SGI_video_sync = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GLX_SGI_make_current_read;
int Wm3NumFunctions_GLX_SGI_make_current_read;
#ifdef WM3_DEFINED_GLX_SGI_make_current_read
pfn_glXGetCurrentReadDrawableSGI Wm3glXGetCurrentReadDrawableSGI = 0;
pfn_glXMakeCurrentReadSGI Wm3glXMakeCurrentReadSGI = 0;

static void Init_GLX_SGI_make_current_read ()
{
    Wm3NumFunctions_GLX_SGI_make_current_read = 0;

    Wm3glXGetCurrentReadDrawableSGI = (pfn_glXGetCurrentReadDrawableSGI)GetFunctionPointer("glXGetCurrentReadDrawableSGI");
    if ( Wm3glXGetCurrentReadDrawableSGI )
        ++Wm3NumFunctions_GLX_SGI_make_current_read;

    Wm3glXMakeCurrentReadSGI = (pfn_glXMakeCurrentReadSGI)GetFunctionPointer("glXMakeCurrentReadSGI");
    if ( Wm3glXMakeCurrentReadSGI )
        ++Wm3NumFunctions_GLX_SGI_make_current_read;

    if ( Wm3NumFunctions_GLX_SGI_make_current_read == 2 )
        Wm3Exists_GLX_SGI_make_current_read = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GLX_SGI_make_current_read = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GLX_SGI_make_current_read ()
{
    Wm3NumFunctions_GLX_SGI_make_current_read = 0;
    Wm3Exists_GLX_SGI_make_current_read = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GLX_EXT_visual_rating;
int Wm3NumFunctions_GLX_EXT_visual_rating;
#ifdef WM3_DEFINED_GLX_EXT_visual_rating
static void Init_GLX_EXT_visual_rating ()
{
    Wm3NumFunctions_GLX_EXT_visual_rating = 0;
    Wm3Exists_GLX_EXT_visual_rating = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GLX_EXT_visual_rating ()
{
    Wm3NumFunctions_GLX_EXT_visual_rating = 0;
    Wm3Exists_GLX_EXT_visual_rating = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GLX_EXT_import_context;
int Wm3NumFunctions_GLX_EXT_import_context;
#ifdef WM3_DEFINED_GLX_EXT_import_context
pfn_glXGetCurrentDisplayEXT Wm3glXGetCurrentDisplayEXT = 0;
pfn_glXQueryContextInfoEXT Wm3glXQueryContextInfoEXT = 0;
pfn_glXGetContextIDEXT Wm3glXGetContextIDEXT = 0;
pfn_glXImportContextEXT Wm3glXImportContextEXT = 0;
pfn_glXFreeContextEXT Wm3glXFreeContextEXT = 0;

static void Init_GLX_EXT_import_context ()
{
    Wm3NumFunctions_GLX_EXT_import_context = 0;

    Wm3glXGetCurrentDisplayEXT = (pfn_glXGetCurrentDisplayEXT)GetFunctionPointer("glXGetCurrentDisplayEXT");
    if ( Wm3glXGetCurrentDisplayEXT )
        ++Wm3NumFunctions_GLX_EXT_import_context;

    Wm3glXQueryContextInfoEXT = (pfn_glXQueryContextInfoEXT)GetFunctionPointer("glXQueryContextInfoEXT");
    if ( Wm3glXQueryContextInfoEXT )
        ++Wm3NumFunctions_GLX_EXT_import_context;

    Wm3glXGetContextIDEXT = (pfn_glXGetContextIDEXT)GetFunctionPointer("glXGetContextIDEXT");
    if ( Wm3glXGetContextIDEXT )
        ++Wm3NumFunctions_GLX_EXT_import_context;

    Wm3glXImportContextEXT = (pfn_glXImportContextEXT)GetFunctionPointer("glXImportContextEXT");
    if ( Wm3glXImportContextEXT )
        ++Wm3NumFunctions_GLX_EXT_import_context;

    Wm3glXFreeContextEXT = (pfn_glXFreeContextEXT)GetFunctionPointer("glXFreeContextEXT");
    if ( Wm3glXFreeContextEXT )
        ++Wm3NumFunctions_GLX_EXT_import_context;

    if ( Wm3NumFunctions_GLX_EXT_import_context == 5 )
        Wm3Exists_GLX_EXT_import_context = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GLX_EXT_import_context = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GLX_EXT_import_context ()
{
    Wm3NumFunctions_GLX_EXT_import_context = 0;
    Wm3Exists_GLX_EXT_import_context = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GLX_SGIX_fbconfig;
int Wm3NumFunctions_GLX_SGIX_fbconfig;
#ifdef WM3_DEFINED_GLX_SGIX_fbconfig
pfn_glXGetFBConfigAttribSGIX Wm3glXGetFBConfigAttribSGIX = 0;
pfn_glXChooseFBConfigSGIX Wm3glXChooseFBConfigSGIX = 0;
pfn_glXCreateGLXPixmapWithConfigSGIX Wm3glXCreateGLXPixmapWithConfigSGIX = 0;
pfn_glXCreateContextWithConfigSGIX Wm3glXCreateContextWithConfigSGIX = 0;
pfn_glXGetVisualFromFBConfigSGIX Wm3glXGetVisualFromFBConfigSGIX = 0;
pfn_glXGetFBConfigFromVisualSGIX Wm3glXGetFBConfigFromVisualSGIX = 0;

static void Init_GLX_SGIX_fbconfig ()
{
    Wm3NumFunctions_GLX_SGIX_fbconfig = 0;

    Wm3glXGetFBConfigAttribSGIX = (pfn_glXGetFBConfigAttribSGIX)GetFunctionPointer("glXGetFBConfigAttribSGIX");
    if ( Wm3glXGetFBConfigAttribSGIX )
        ++Wm3NumFunctions_GLX_SGIX_fbconfig;

    Wm3glXChooseFBConfigSGIX = (pfn_glXChooseFBConfigSGIX)GetFunctionPointer("glXChooseFBConfigSGIX");
    if ( Wm3glXChooseFBConfigSGIX )
        ++Wm3NumFunctions_GLX_SGIX_fbconfig;

    Wm3glXCreateGLXPixmapWithConfigSGIX = (pfn_glXCreateGLXPixmapWithConfigSGIX)GetFunctionPointer("glXCreateGLXPixmapWithConfigSGIX");
    if ( Wm3glXCreateGLXPixmapWithConfigSGIX )
        ++Wm3NumFunctions_GLX_SGIX_fbconfig;

    Wm3glXCreateContextWithConfigSGIX = (pfn_glXCreateContextWithConfigSGIX)GetFunctionPointer("glXCreateContextWithConfigSGIX");
    if ( Wm3glXCreateContextWithConfigSGIX )
        ++Wm3NumFunctions_GLX_SGIX_fbconfig;

    Wm3glXGetVisualFromFBConfigSGIX = (pfn_glXGetVisualFromFBConfigSGIX)GetFunctionPointer("glXGetVisualFromFBConfigSGIX");
    if ( Wm3glXGetVisualFromFBConfigSGIX )
        ++Wm3NumFunctions_GLX_SGIX_fbconfig;

    Wm3glXGetFBConfigFromVisualSGIX = (pfn_glXGetFBConfigFromVisualSGIX)GetFunctionPointer("glXGetFBConfigFromVisualSGIX");
    if ( Wm3glXGetFBConfigFromVisualSGIX )
        ++Wm3NumFunctions_GLX_SGIX_fbconfig;

    if ( Wm3NumFunctions_GLX_SGIX_fbconfig == 6 )
        Wm3Exists_GLX_SGIX_fbconfig = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GLX_SGIX_fbconfig = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GLX_SGIX_fbconfig ()
{
    Wm3NumFunctions_GLX_SGIX_fbconfig = 0;
    Wm3Exists_GLX_SGIX_fbconfig = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GLX_SGIX_pbuffer;
int Wm3NumFunctions_GLX_SGIX_pbuffer;
#ifdef WM3_DEFINED_GLX_SGIX_pbuffer
pfn_glXCreateGLXPbufferSGIX Wm3glXCreateGLXPbufferSGIX = 0;
pfn_glXDestroyGLXPbufferSGIX Wm3glXDestroyGLXPbufferSGIX = 0;
pfn_glXQueryGLXPbufferSGIX Wm3glXQueryGLXPbufferSGIX = 0;
pfn_glXSelectEventSGIX Wm3glXSelectEventSGIX = 0;
pfn_glXGetSelectedEventSGIX Wm3glXGetSelectedEventSGIX = 0;

static void Init_GLX_SGIX_pbuffer ()
{
    Wm3NumFunctions_GLX_SGIX_pbuffer = 0;

    Wm3glXCreateGLXPbufferSGIX = (pfn_glXCreateGLXPbufferSGIX)GetFunctionPointer("glXCreateGLXPbufferSGIX");
    if ( Wm3glXCreateGLXPbufferSGIX )
        ++Wm3NumFunctions_GLX_SGIX_pbuffer;

    Wm3glXDestroyGLXPbufferSGIX = (pfn_glXDestroyGLXPbufferSGIX)GetFunctionPointer("glXDestroyGLXPbufferSGIX");
    if ( Wm3glXDestroyGLXPbufferSGIX )
        ++Wm3NumFunctions_GLX_SGIX_pbuffer;

    Wm3glXQueryGLXPbufferSGIX = (pfn_glXQueryGLXPbufferSGIX)GetFunctionPointer("glXQueryGLXPbufferSGIX");
    if ( Wm3glXQueryGLXPbufferSGIX )
        ++Wm3NumFunctions_GLX_SGIX_pbuffer;

    Wm3glXSelectEventSGIX = (pfn_glXSelectEventSGIX)GetFunctionPointer("glXSelectEventSGIX");
    if ( Wm3glXSelectEventSGIX )
        ++Wm3NumFunctions_GLX_SGIX_pbuffer;

    Wm3glXGetSelectedEventSGIX = (pfn_glXGetSelectedEventSGIX)GetFunctionPointer("glXGetSelectedEventSGIX");
    if ( Wm3glXGetSelectedEventSGIX )
        ++Wm3NumFunctions_GLX_SGIX_pbuffer;

    if ( Wm3NumFunctions_GLX_SGIX_pbuffer == 5 )
        Wm3Exists_GLX_SGIX_pbuffer = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GLX_SGIX_pbuffer = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GLX_SGIX_pbuffer ()
{
    Wm3NumFunctions_GLX_SGIX_pbuffer = 0;
    Wm3Exists_GLX_SGIX_pbuffer = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GLX_SGI_cushion;
int Wm3NumFunctions_GLX_SGI_cushion;
#ifdef WM3_DEFINED_GLX_SGI_cushion
pfn_glXCushionSGI Wm3glXCushionSGI = 0;

static void Init_GLX_SGI_cushion ()
{
    Wm3NumFunctions_GLX_SGI_cushion = 0;

    Wm3glXCushionSGI = (pfn_glXCushionSGI)GetFunctionPointer("glXCushionSGI");
    if ( Wm3glXCushionSGI )
        ++Wm3NumFunctions_GLX_SGI_cushion;

    if ( Wm3NumFunctions_GLX_SGI_cushion == 1 )
        Wm3Exists_GLX_SGI_cushion = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GLX_SGI_cushion = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GLX_SGI_cushion ()
{
    Wm3NumFunctions_GLX_SGI_cushion = 0;
    Wm3Exists_GLX_SGI_cushion = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GLX_SGIX_video_resize;
int Wm3NumFunctions_GLX_SGIX_video_resize;
#ifdef WM3_DEFINED_GLX_SGIX_video_resize
pfn_glXBindChannelToWindowSGIX Wm3glXBindChannelToWindowSGIX = 0;
pfn_glXChannelRectSGIX Wm3glXChannelRectSGIX = 0;
pfn_glXQueryChannelRectSGIX Wm3glXQueryChannelRectSGIX = 0;
pfn_glXQueryChannelDeltasSGIX Wm3glXQueryChannelDeltasSGIX = 0;
pfn_glXChannelRectSyncSGIX Wm3glXChannelRectSyncSGIX = 0;

static void Init_GLX_SGIX_video_resize ()
{
    Wm3NumFunctions_GLX_SGIX_video_resize = 0;

    Wm3glXBindChannelToWindowSGIX = (pfn_glXBindChannelToWindowSGIX)GetFunctionPointer("glXBindChannelToWindowSGIX");
    if ( Wm3glXBindChannelToWindowSGIX )
        ++Wm3NumFunctions_GLX_SGIX_video_resize;

    Wm3glXChannelRectSGIX = (pfn_glXChannelRectSGIX)GetFunctionPointer("glXChannelRectSGIX");
    if ( Wm3glXChannelRectSGIX )
        ++Wm3NumFunctions_GLX_SGIX_video_resize;

    Wm3glXQueryChannelRectSGIX = (pfn_glXQueryChannelRectSGIX)GetFunctionPointer("glXQueryChannelRectSGIX");
    if ( Wm3glXQueryChannelRectSGIX )
        ++Wm3NumFunctions_GLX_SGIX_video_resize;

    Wm3glXQueryChannelDeltasSGIX = (pfn_glXQueryChannelDeltasSGIX)GetFunctionPointer("glXQueryChannelDeltasSGIX");
    if ( Wm3glXQueryChannelDeltasSGIX )
        ++Wm3NumFunctions_GLX_SGIX_video_resize;

    Wm3glXChannelRectSyncSGIX = (pfn_glXChannelRectSyncSGIX)GetFunctionPointer("glXChannelRectSyncSGIX");
    if ( Wm3glXChannelRectSyncSGIX )
        ++Wm3NumFunctions_GLX_SGIX_video_resize;

    if ( Wm3NumFunctions_GLX_SGIX_video_resize == 5 )
        Wm3Exists_GLX_SGIX_video_resize = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GLX_SGIX_video_resize = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GLX_SGIX_video_resize ()
{
    Wm3NumFunctions_GLX_SGIX_video_resize = 0;
    Wm3Exists_GLX_SGIX_video_resize = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GLX_SGIX_dmbuffer;
int Wm3NumFunctions_GLX_SGIX_dmbuffer;
#ifdef WM3_DEFINED_GLX_SGIX_dmbuffer
static void Init_GLX_SGIX_dmbuffer ()
{
    Wm3NumFunctions_GLX_SGIX_dmbuffer = 0;
    Wm3Exists_GLX_SGIX_dmbuffer = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GLX_SGIX_dmbuffer ()
{
    Wm3NumFunctions_GLX_SGIX_dmbuffer = 0;
    Wm3Exists_GLX_SGIX_dmbuffer = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GLX_SGIX_swap_group;
int Wm3NumFunctions_GLX_SGIX_swap_group;
#ifdef WM3_DEFINED_GLX_SGIX_swap_group
pfn_glXJoinSwapGroupSGIX Wm3glXJoinSwapGroupSGIX = 0;

static void Init_GLX_SGIX_swap_group ()
{
    Wm3NumFunctions_GLX_SGIX_swap_group = 0;

    Wm3glXJoinSwapGroupSGIX = (pfn_glXJoinSwapGroupSGIX)GetFunctionPointer("glXJoinSwapGroupSGIX");
    if ( Wm3glXJoinSwapGroupSGIX )
        ++Wm3NumFunctions_GLX_SGIX_swap_group;

    if ( Wm3NumFunctions_GLX_SGIX_swap_group == 1 )
        Wm3Exists_GLX_SGIX_swap_group = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GLX_SGIX_swap_group = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GLX_SGIX_swap_group ()
{
    Wm3NumFunctions_GLX_SGIX_swap_group = 0;
    Wm3Exists_GLX_SGIX_swap_group = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GLX_SGIX_swap_barrier;
int Wm3NumFunctions_GLX_SGIX_swap_barrier;
#ifdef WM3_DEFINED_GLX_SGIX_swap_barrier
pfn_glXBindSwapBarrierSGIX Wm3glXBindSwapBarrierSGIX = 0;
pfn_glXQueryMaxSwapBarriersSGIX Wm3glXQueryMaxSwapBarriersSGIX = 0;

static void Init_GLX_SGIX_swap_barrier ()
{
    Wm3NumFunctions_GLX_SGIX_swap_barrier = 0;

    Wm3glXBindSwapBarrierSGIX = (pfn_glXBindSwapBarrierSGIX)GetFunctionPointer("glXBindSwapBarrierSGIX");
    if ( Wm3glXBindSwapBarrierSGIX )
        ++Wm3NumFunctions_GLX_SGIX_swap_barrier;

    Wm3glXQueryMaxSwapBarriersSGIX = (pfn_glXQueryMaxSwapBarriersSGIX)GetFunctionPointer("glXQueryMaxSwapBarriersSGIX");
    if ( Wm3glXQueryMaxSwapBarriersSGIX )
        ++Wm3NumFunctions_GLX_SGIX_swap_barrier;

    if ( Wm3NumFunctions_GLX_SGIX_swap_barrier == 2 )
        Wm3Exists_GLX_SGIX_swap_barrier = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GLX_SGIX_swap_barrier = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GLX_SGIX_swap_barrier ()
{
    Wm3NumFunctions_GLX_SGIX_swap_barrier = 0;
    Wm3Exists_GLX_SGIX_swap_barrier = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GLX_SGIS_blended_overlay;
int Wm3NumFunctions_GLX_SGIS_blended_overlay;
#ifdef WM3_DEFINED_GLX_SGIS_blended_overlay
static void Init_GLX_SGIS_blended_overlay ()
{
    Wm3NumFunctions_GLX_SGIS_blended_overlay = 0;
    Wm3Exists_GLX_SGIS_blended_overlay = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GLX_SGIS_blended_overlay ()
{
    Wm3NumFunctions_GLX_SGIS_blended_overlay = 0;
    Wm3Exists_GLX_SGIS_blended_overlay = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GLX_SGIS_shared_multisample;
int Wm3NumFunctions_GLX_SGIS_shared_multisample;
#ifdef WM3_DEFINED_GLX_SGIS_shared_multisample
static void Init_GLX_SGIS_shared_multisample ()
{
    Wm3NumFunctions_GLX_SGIS_shared_multisample = 0;
    Wm3Exists_GLX_SGIS_shared_multisample = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GLX_SGIS_shared_multisample ()
{
    Wm3NumFunctions_GLX_SGIS_shared_multisample = 0;
    Wm3Exists_GLX_SGIS_shared_multisample = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GLX_SUN_get_transparent_index;
int Wm3NumFunctions_GLX_SUN_get_transparent_index;
#ifdef WM3_DEFINED_GLX_SUN_get_transparent_index
pfn_glXGetTransparentIndexSUN Wm3glXGetTransparentIndexSUN = 0;

static void Init_GLX_SUN_get_transparent_index ()
{
    Wm3NumFunctions_GLX_SUN_get_transparent_index = 0;

    Wm3glXGetTransparentIndexSUN = (pfn_glXGetTransparentIndexSUN)GetFunctionPointer("glXGetTransparentIndexSUN");
    if ( Wm3glXGetTransparentIndexSUN )
        ++Wm3NumFunctions_GLX_SUN_get_transparent_index;

    if ( Wm3NumFunctions_GLX_SUN_get_transparent_index == 1 )
        Wm3Exists_GLX_SUN_get_transparent_index = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GLX_SUN_get_transparent_index = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GLX_SUN_get_transparent_index ()
{
    Wm3NumFunctions_GLX_SUN_get_transparent_index = 0;
    Wm3Exists_GLX_SUN_get_transparent_index = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GLX_3DFX_multisample;
int Wm3NumFunctions_GLX_3DFX_multisample;
#ifdef WM3_DEFINED_GLX_3DFX_multisample
static void Init_GLX_3DFX_multisample ()
{
    Wm3NumFunctions_GLX_3DFX_multisample = 0;
    Wm3Exists_GLX_3DFX_multisample = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GLX_3DFX_multisample ()
{
    Wm3NumFunctions_GLX_3DFX_multisample = 0;
    Wm3Exists_GLX_3DFX_multisample = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GLX_MESA_copy_sub_buffer;
int Wm3NumFunctions_GLX_MESA_copy_sub_buffer;
#ifdef WM3_DEFINED_GLX_MESA_copy_sub_buffer
pfn_glXCopySubBufferMESA Wm3glXCopySubBufferMESA = 0;

static void Init_GLX_MESA_copy_sub_buffer ()
{
    Wm3NumFunctions_GLX_MESA_copy_sub_buffer = 0;

    Wm3glXCopySubBufferMESA = (pfn_glXCopySubBufferMESA)GetFunctionPointer("glXCopySubBufferMESA");
    if ( Wm3glXCopySubBufferMESA )
        ++Wm3NumFunctions_GLX_MESA_copy_sub_buffer;

    if ( Wm3NumFunctions_GLX_MESA_copy_sub_buffer == 1 )
        Wm3Exists_GLX_MESA_copy_sub_buffer = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GLX_MESA_copy_sub_buffer = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GLX_MESA_copy_sub_buffer ()
{
    Wm3NumFunctions_GLX_MESA_copy_sub_buffer = 0;
    Wm3Exists_GLX_MESA_copy_sub_buffer = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GLX_MESA_pixmap_colormap;
int Wm3NumFunctions_GLX_MESA_pixmap_colormap;
#ifdef WM3_DEFINED_GLX_MESA_pixmap_colormap
pfn_glXCreateGLXPixmapMESA Wm3glXCreateGLXPixmapMESA = 0;

static void Init_GLX_MESA_pixmap_colormap ()
{
    Wm3NumFunctions_GLX_MESA_pixmap_colormap = 0;

    Wm3glXCreateGLXPixmapMESA = (pfn_glXCreateGLXPixmapMESA)GetFunctionPointer("glXCreateGLXPixmapMESA");
    if ( Wm3glXCreateGLXPixmapMESA )
        ++Wm3NumFunctions_GLX_MESA_pixmap_colormap;

    if ( Wm3NumFunctions_GLX_MESA_pixmap_colormap == 1 )
        Wm3Exists_GLX_MESA_pixmap_colormap = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GLX_MESA_pixmap_colormap = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GLX_MESA_pixmap_colormap ()
{
    Wm3NumFunctions_GLX_MESA_pixmap_colormap = 0;
    Wm3Exists_GLX_MESA_pixmap_colormap = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GLX_MESA_release_buffers;
int Wm3NumFunctions_GLX_MESA_release_buffers;
#ifdef WM3_DEFINED_GLX_MESA_release_buffers
pfn_glXReleaseBuffersMESA Wm3glXReleaseBuffersMESA = 0;

static void Init_GLX_MESA_release_buffers ()
{
    Wm3NumFunctions_GLX_MESA_release_buffers = 0;

    Wm3glXReleaseBuffersMESA = (pfn_glXReleaseBuffersMESA)GetFunctionPointer("glXReleaseBuffersMESA");
    if ( Wm3glXReleaseBuffersMESA )
        ++Wm3NumFunctions_GLX_MESA_release_buffers;

    if ( Wm3NumFunctions_GLX_MESA_release_buffers == 1 )
        Wm3Exists_GLX_MESA_release_buffers = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GLX_MESA_release_buffers = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GLX_MESA_release_buffers ()
{
    Wm3NumFunctions_GLX_MESA_release_buffers = 0;
    Wm3Exists_GLX_MESA_release_buffers = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GLX_MESA_set_3dfx_mode;
int Wm3NumFunctions_GLX_MESA_set_3dfx_mode;
#ifdef WM3_DEFINED_GLX_MESA_set_3dfx_mode
pfn_glXSet3DfxModeMESA Wm3glXSet3DfxModeMESA = 0;

static void Init_GLX_MESA_set_3dfx_mode ()
{
    Wm3NumFunctions_GLX_MESA_set_3dfx_mode = 0;

    Wm3glXSet3DfxModeMESA = (pfn_glXSet3DfxModeMESA)GetFunctionPointer("glXSet3DfxModeMESA");
    if ( Wm3glXSet3DfxModeMESA )
        ++Wm3NumFunctions_GLX_MESA_set_3dfx_mode;

    if ( Wm3NumFunctions_GLX_MESA_set_3dfx_mode == 1 )
        Wm3Exists_GLX_MESA_set_3dfx_mode = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GLX_MESA_set_3dfx_mode = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GLX_MESA_set_3dfx_mode ()
{
    Wm3NumFunctions_GLX_MESA_set_3dfx_mode = 0;
    Wm3Exists_GLX_MESA_set_3dfx_mode = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GLX_SGIX_visual_select_group;
int Wm3NumFunctions_GLX_SGIX_visual_select_group;
#ifdef WM3_DEFINED_GLX_SGIX_visual_select_group
static void Init_GLX_SGIX_visual_select_group ()
{
    Wm3NumFunctions_GLX_SGIX_visual_select_group = 0;
    Wm3Exists_GLX_SGIX_visual_select_group = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GLX_SGIX_visual_select_group ()
{
    Wm3NumFunctions_GLX_SGIX_visual_select_group = 0;
    Wm3Exists_GLX_SGIX_visual_select_group = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GLX_OML_swap_method;
int Wm3NumFunctions_GLX_OML_swap_method;
#ifdef WM3_DEFINED_GLX_OML_swap_method
static void Init_GLX_OML_swap_method ()
{
    Wm3NumFunctions_GLX_OML_swap_method = 0;
    Wm3Exists_GLX_OML_swap_method = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GLX_OML_swap_method ()
{
    Wm3NumFunctions_GLX_OML_swap_method = 0;
    Wm3Exists_GLX_OML_swap_method = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GLX_OML_sync_control;
int Wm3NumFunctions_GLX_OML_sync_control;
#ifdef WM3_DEFINED_GLX_OML_sync_control
pfn_glXGetSyncValuesOML Wm3glXGetSyncValuesOML = 0;
pfn_glXGetMscRateOML Wm3glXGetMscRateOML = 0;
pfn_glXSwapBuffersMscOML Wm3glXSwapBuffersMscOML = 0;
pfn_glXWaitForMscOML Wm3glXWaitForMscOML = 0;
pfn_glXWaitForSbcOML Wm3glXWaitForSbcOML = 0;

static void Init_GLX_OML_sync_control ()
{
    Wm3NumFunctions_GLX_OML_sync_control = 0;

    Wm3glXGetSyncValuesOML = (pfn_glXGetSyncValuesOML)GetFunctionPointer("glXGetSyncValuesOML");
    if ( Wm3glXGetSyncValuesOML )
        ++Wm3NumFunctions_GLX_OML_sync_control;

    Wm3glXGetMscRateOML = (pfn_glXGetMscRateOML)GetFunctionPointer("glXGetMscRateOML");
    if ( Wm3glXGetMscRateOML )
        ++Wm3NumFunctions_GLX_OML_sync_control;

    Wm3glXSwapBuffersMscOML = (pfn_glXSwapBuffersMscOML)GetFunctionPointer("glXSwapBuffersMscOML");
    if ( Wm3glXSwapBuffersMscOML )
        ++Wm3NumFunctions_GLX_OML_sync_control;

    Wm3glXWaitForMscOML = (pfn_glXWaitForMscOML)GetFunctionPointer("glXWaitForMscOML");
    if ( Wm3glXWaitForMscOML )
        ++Wm3NumFunctions_GLX_OML_sync_control;

    Wm3glXWaitForSbcOML = (pfn_glXWaitForSbcOML)GetFunctionPointer("glXWaitForSbcOML");
    if ( Wm3glXWaitForSbcOML )
        ++Wm3NumFunctions_GLX_OML_sync_control;

    if ( Wm3NumFunctions_GLX_OML_sync_control == 5 )
        Wm3Exists_GLX_OML_sync_control = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GLX_OML_sync_control = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GLX_OML_sync_control ()
{
    Wm3NumFunctions_GLX_OML_sync_control = 0;
    Wm3Exists_GLX_OML_sync_control = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GLX_NV_float_buffer;
int Wm3NumFunctions_GLX_NV_float_buffer;
#ifdef WM3_DEFINED_GLX_NV_float_buffer
static void Init_GLX_NV_float_buffer ()
{
    Wm3NumFunctions_GLX_NV_float_buffer = 0;
    Wm3Exists_GLX_NV_float_buffer = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GLX_NV_float_buffer ()
{
    Wm3NumFunctions_GLX_NV_float_buffer = 0;
    Wm3Exists_GLX_NV_float_buffer = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GLX_SGIX_hyperpipe;
int Wm3NumFunctions_GLX_SGIX_hyperpipe;
#ifdef WM3_DEFINED_GLX_SGIX_hyperpipe
pfn_glXQueryHyperpipeNetworkSGIX Wm3glXQueryHyperpipeNetworkSGIX = 0;
pfn_glXHyperpipeConfigSGIX Wm3glXHyperpipeConfigSGIX = 0;
pfn_glXQueryHyperpipeConfigSGIX Wm3glXQueryHyperpipeConfigSGIX = 0;
pfn_glXDestroyHyperpipeConfigSGIX Wm3glXDestroyHyperpipeConfigSGIX = 0;
pfn_glXBindHyperpipeSGIX Wm3glXBindHyperpipeSGIX = 0;
pfn_glXQueryHyperpipeBestAttribSGIX Wm3glXQueryHyperpipeBestAttribSGIX = 0;
pfn_glXHyperpipeAttribSGIX Wm3glXHyperpipeAttribSGIX = 0;
pfn_glXQueryHyperpipeAttribSGIX Wm3glXQueryHyperpipeAttribSGIX = 0;

static void Init_GLX_SGIX_hyperpipe ()
{
    Wm3NumFunctions_GLX_SGIX_hyperpipe = 0;

    Wm3glXQueryHyperpipeNetworkSGIX = (pfn_glXQueryHyperpipeNetworkSGIX)GetFunctionPointer("glXQueryHyperpipeNetworkSGIX");
    if ( Wm3glXQueryHyperpipeNetworkSGIX )
        ++Wm3NumFunctions_GLX_SGIX_hyperpipe;

    Wm3glXHyperpipeConfigSGIX = (pfn_glXHyperpipeConfigSGIX)GetFunctionPointer("glXHyperpipeConfigSGIX");
    if ( Wm3glXHyperpipeConfigSGIX )
        ++Wm3NumFunctions_GLX_SGIX_hyperpipe;

    Wm3glXQueryHyperpipeConfigSGIX = (pfn_glXQueryHyperpipeConfigSGIX)GetFunctionPointer("glXQueryHyperpipeConfigSGIX");
    if ( Wm3glXQueryHyperpipeConfigSGIX )
        ++Wm3NumFunctions_GLX_SGIX_hyperpipe;

    Wm3glXDestroyHyperpipeConfigSGIX = (pfn_glXDestroyHyperpipeConfigSGIX)GetFunctionPointer("glXDestroyHyperpipeConfigSGIX");
    if ( Wm3glXDestroyHyperpipeConfigSGIX )
        ++Wm3NumFunctions_GLX_SGIX_hyperpipe;

    Wm3glXBindHyperpipeSGIX = (pfn_glXBindHyperpipeSGIX)GetFunctionPointer("glXBindHyperpipeSGIX");
    if ( Wm3glXBindHyperpipeSGIX )
        ++Wm3NumFunctions_GLX_SGIX_hyperpipe;

    Wm3glXQueryHyperpipeBestAttribSGIX = (pfn_glXQueryHyperpipeBestAttribSGIX)GetFunctionPointer("glXQueryHyperpipeBestAttribSGIX");
    if ( Wm3glXQueryHyperpipeBestAttribSGIX )
        ++Wm3NumFunctions_GLX_SGIX_hyperpipe;

    Wm3glXHyperpipeAttribSGIX = (pfn_glXHyperpipeAttribSGIX)GetFunctionPointer("glXHyperpipeAttribSGIX");
    if ( Wm3glXHyperpipeAttribSGIX )
        ++Wm3NumFunctions_GLX_SGIX_hyperpipe;

    Wm3glXQueryHyperpipeAttribSGIX = (pfn_glXQueryHyperpipeAttribSGIX)GetFunctionPointer("glXQueryHyperpipeAttribSGIX");
    if ( Wm3glXQueryHyperpipeAttribSGIX )
        ++Wm3NumFunctions_GLX_SGIX_hyperpipe;

    if ( Wm3NumFunctions_GLX_SGIX_hyperpipe == 8 )
        Wm3Exists_GLX_SGIX_hyperpipe = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GLX_SGIX_hyperpipe = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GLX_SGIX_hyperpipe ()
{
    Wm3NumFunctions_GLX_SGIX_hyperpipe = 0;
    Wm3Exists_GLX_SGIX_hyperpipe = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GLX_MESA_agp_offset;
int Wm3NumFunctions_GLX_MESA_agp_offset;
#ifdef WM3_DEFINED_GLX_MESA_agp_offset
pfn_glXGetAGPOffsetMesa Wm3glXGetAGPOffsetMesa = 0;

static void Init_GLX_MESA_agp_offset ()
{
    Wm3NumFunctions_GLX_MESA_agp_offset = 0;

    Wm3glXGetAGPOffsetMesa = (pfn_glXGetAGPOffsetMesa)GetFunctionPointer("glXGetAGPOffsetMesa");
    if ( Wm3glXGetAGPOffsetMesa )
        ++Wm3NumFunctions_GLX_MESA_agp_offset;

    if ( Wm3NumFunctions_GLX_MESA_agp_offset == 1 )
        Wm3Exists_GLX_MESA_agp_offset = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GLX_MESA_agp_offset = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GLX_MESA_agp_offset ()
{
    Wm3NumFunctions_GLX_MESA_agp_offset = 0;
    Wm3Exists_GLX_MESA_agp_offset = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
void InitializeGlx ()
{
    Init_GLX_VERSION_1_0();
    Init_GLX_VERSION_1_1();
    Init_GLX_VERSION_1_2();
    Init_GLX_VERSION_1_3();
    Init_GLX_VERSION_1_4();
    Init_GLX_ARB_get_proc_address();
    Init_GLX_ARB_multisample();
    Init_GLX_ARB_fbconfig_float();
    Init_GLX_SGIS_multisample();
    Init_GLX_EXT_visual_info();
    Init_GLX_SGI_swap_control();
    Init_GLX_SGI_video_sync();
    Init_GLX_SGI_make_current_read();
    Init_GLX_EXT_visual_rating();
    Init_GLX_EXT_import_context();
    Init_GLX_SGIX_fbconfig();
    Init_GLX_SGIX_pbuffer();
    Init_GLX_SGI_cushion();
    Init_GLX_SGIX_video_resize();
    Init_GLX_SGIX_dmbuffer();
    Init_GLX_SGIX_swap_group();
    Init_GLX_SGIX_swap_barrier();
    Init_GLX_SGIS_blended_overlay();
    Init_GLX_SGIS_shared_multisample();
    Init_GLX_SUN_get_transparent_index();
    Init_GLX_3DFX_multisample();
    Init_GLX_MESA_copy_sub_buffer();
    Init_GLX_MESA_pixmap_colormap();
    Init_GLX_MESA_release_buffers();
    Init_GLX_MESA_set_3dfx_mode();
    Init_GLX_SGIX_visual_select_group();
    Init_GLX_OML_swap_method();
    Init_GLX_OML_sync_control();
    Init_GLX_NV_float_buffer();
    Init_GLX_SGIX_hyperpipe();
    Init_GLX_MESA_agp_offset();
}
/*--------------------------------------------------------------------------*/
#endif
