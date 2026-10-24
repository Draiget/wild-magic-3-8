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

#include "Wm3WglExtensions.h"

/*--------------------------------------------------------------------------*/
void* GetFunctionPointer (const char* acFunction)
{
    return (void*)wglGetProcAddress(acFunction);
}
/*--------------------------------------------------------------------------*/


/*--------------------------------------------------------------------------*/
int Wm3Exists_WGL_ARB_buffer_region;
int Wm3NumFunctions_WGL_ARB_buffer_region;
#ifdef WM3_DEFINED_WGL_ARB_buffer_region
pfn_wglCreateBufferRegionARB Wm3wglCreateBufferRegionARB = 0;
pfn_wglDeleteBufferRegionARB Wm3wglDeleteBufferRegionARB = 0;
pfn_wglSaveBufferRegionARB Wm3wglSaveBufferRegionARB = 0;
pfn_wglRestoreBufferRegionARB Wm3wglRestoreBufferRegionARB = 0;

static void Init_WGL_ARB_buffer_region ()
{
    Wm3NumFunctions_WGL_ARB_buffer_region = 0;

    Wm3wglCreateBufferRegionARB = (pfn_wglCreateBufferRegionARB)GetFunctionPointer("wglCreateBufferRegionARB");
    if ( Wm3wglCreateBufferRegionARB )
        ++Wm3NumFunctions_WGL_ARB_buffer_region;

    Wm3wglDeleteBufferRegionARB = (pfn_wglDeleteBufferRegionARB)GetFunctionPointer("wglDeleteBufferRegionARB");
    if ( Wm3wglDeleteBufferRegionARB )
        ++Wm3NumFunctions_WGL_ARB_buffer_region;

    Wm3wglSaveBufferRegionARB = (pfn_wglSaveBufferRegionARB)GetFunctionPointer("wglSaveBufferRegionARB");
    if ( Wm3wglSaveBufferRegionARB )
        ++Wm3NumFunctions_WGL_ARB_buffer_region;

    Wm3wglRestoreBufferRegionARB = (pfn_wglRestoreBufferRegionARB)GetFunctionPointer("wglRestoreBufferRegionARB");
    if ( Wm3wglRestoreBufferRegionARB )
        ++Wm3NumFunctions_WGL_ARB_buffer_region;

    if ( Wm3NumFunctions_WGL_ARB_buffer_region == 4 )
        Wm3Exists_WGL_ARB_buffer_region = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_WGL_ARB_buffer_region = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_WGL_ARB_buffer_region ()
{
    Wm3NumFunctions_WGL_ARB_buffer_region = 0;
    Wm3Exists_WGL_ARB_buffer_region = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_WGL_ARB_multisample;
int Wm3NumFunctions_WGL_ARB_multisample;
#ifdef WM3_DEFINED_WGL_ARB_multisample

static void Init_WGL_ARB_multisample ()
{
    Wm3NumFunctions_WGL_ARB_multisample = 0;

    if ( Wm3NumFunctions_WGL_ARB_multisample == 0 )
        Wm3Exists_WGL_ARB_multisample = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_WGL_ARB_multisample = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_WGL_ARB_multisample ()
{
    Wm3NumFunctions_WGL_ARB_multisample = 0;
    Wm3Exists_WGL_ARB_multisample = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_WGL_ARB_extensions_string;
int Wm3NumFunctions_WGL_ARB_extensions_string;
#ifdef WM3_DEFINED_WGL_ARB_extensions_string
pfn_wglGetExtensionsStringARB Wm3wglGetExtensionsStringARB = 0;

static void Init_WGL_ARB_extensions_string ()
{
    Wm3NumFunctions_WGL_ARB_extensions_string = 0;

    Wm3wglGetExtensionsStringARB = (pfn_wglGetExtensionsStringARB)GetFunctionPointer("wglGetExtensionsStringARB");
    if ( Wm3wglGetExtensionsStringARB )
        ++Wm3NumFunctions_WGL_ARB_extensions_string;

    if ( Wm3NumFunctions_WGL_ARB_extensions_string == 1 )
        Wm3Exists_WGL_ARB_extensions_string = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_WGL_ARB_extensions_string = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_WGL_ARB_extensions_string ()
{
    Wm3NumFunctions_WGL_ARB_extensions_string = 0;
    Wm3Exists_WGL_ARB_extensions_string = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_WGL_ARB_pixel_format;
int Wm3NumFunctions_WGL_ARB_pixel_format;
#ifdef WM3_DEFINED_WGL_ARB_pixel_format
pfn_wglGetPixelFormatAttribivARB Wm3wglGetPixelFormatAttribivARB = 0;
pfn_wglGetPixelFormatAttribfvARB Wm3wglGetPixelFormatAttribfvARB = 0;
pfn_wglChoosePixelFormatARB Wm3wglChoosePixelFormatARB = 0;

static void Init_WGL_ARB_pixel_format ()
{
    Wm3NumFunctions_WGL_ARB_pixel_format = 0;

    Wm3wglGetPixelFormatAttribivARB = (pfn_wglGetPixelFormatAttribivARB)GetFunctionPointer("wglGetPixelFormatAttribivARB");
    if ( Wm3wglGetPixelFormatAttribivARB )
        ++Wm3NumFunctions_WGL_ARB_pixel_format;

    Wm3wglGetPixelFormatAttribfvARB = (pfn_wglGetPixelFormatAttribfvARB)GetFunctionPointer("wglGetPixelFormatAttribfvARB");
    if ( Wm3wglGetPixelFormatAttribfvARB )
        ++Wm3NumFunctions_WGL_ARB_pixel_format;

    Wm3wglChoosePixelFormatARB = (pfn_wglChoosePixelFormatARB)GetFunctionPointer("wglChoosePixelFormatARB");
    if ( Wm3wglChoosePixelFormatARB )
        ++Wm3NumFunctions_WGL_ARB_pixel_format;

    if ( Wm3NumFunctions_WGL_ARB_pixel_format == 3 )
        Wm3Exists_WGL_ARB_pixel_format = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_WGL_ARB_pixel_format = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_WGL_ARB_pixel_format ()
{
    Wm3NumFunctions_WGL_ARB_pixel_format = 0;
    Wm3Exists_WGL_ARB_pixel_format = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_WGL_ARB_make_current_read;
int Wm3NumFunctions_WGL_ARB_make_current_read;
#ifdef WM3_DEFINED_WGL_ARB_make_current_read
pfn_wglMakeContextCurrentARB Wm3wglMakeContextCurrentARB = 0;
pfn_wglGetCurrentReadDCARB Wm3wglGetCurrentReadDCARB = 0;

static void Init_WGL_ARB_make_current_read ()
{
    Wm3NumFunctions_WGL_ARB_make_current_read = 0;

    Wm3wglMakeContextCurrentARB = (pfn_wglMakeContextCurrentARB)GetFunctionPointer("wglMakeContextCurrentARB");
    if ( Wm3wglMakeContextCurrentARB )
        ++Wm3NumFunctions_WGL_ARB_make_current_read;

    Wm3wglGetCurrentReadDCARB = (pfn_wglGetCurrentReadDCARB)GetFunctionPointer("wglGetCurrentReadDCARB");
    if ( Wm3wglGetCurrentReadDCARB )
        ++Wm3NumFunctions_WGL_ARB_make_current_read;

    if ( Wm3NumFunctions_WGL_ARB_make_current_read == 2 )
        Wm3Exists_WGL_ARB_make_current_read = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_WGL_ARB_make_current_read = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_WGL_ARB_make_current_read ()
{
    Wm3NumFunctions_WGL_ARB_make_current_read = 0;
    Wm3Exists_WGL_ARB_make_current_read = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_WGL_ARB_pbuffer;
int Wm3NumFunctions_WGL_ARB_pbuffer;
#ifdef WM3_DEFINED_WGL_ARB_pbuffer
pfn_wglCreatePbufferARB Wm3wglCreatePbufferARB = 0;
pfn_wglGetPbufferDCARB Wm3wglGetPbufferDCARB = 0;
pfn_wglReleasePbufferDCARB Wm3wglReleasePbufferDCARB = 0;
pfn_wglDestroyPbufferARB Wm3wglDestroyPbufferARB = 0;
pfn_wglQueryPbufferARB Wm3wglQueryPbufferARB = 0;

static void Init_WGL_ARB_pbuffer ()
{
    Wm3NumFunctions_WGL_ARB_pbuffer = 0;

    Wm3wglCreatePbufferARB = (pfn_wglCreatePbufferARB)GetFunctionPointer("wglCreatePbufferARB");
    if ( Wm3wglCreatePbufferARB )
        ++Wm3NumFunctions_WGL_ARB_pbuffer;

    Wm3wglGetPbufferDCARB = (pfn_wglGetPbufferDCARB)GetFunctionPointer("wglGetPbufferDCARB");
    if ( Wm3wglGetPbufferDCARB )
        ++Wm3NumFunctions_WGL_ARB_pbuffer;

    Wm3wglReleasePbufferDCARB = (pfn_wglReleasePbufferDCARB)GetFunctionPointer("wglReleasePbufferDCARB");
    if ( Wm3wglReleasePbufferDCARB )
        ++Wm3NumFunctions_WGL_ARB_pbuffer;

    Wm3wglDestroyPbufferARB = (pfn_wglDestroyPbufferARB)GetFunctionPointer("wglDestroyPbufferARB");
    if ( Wm3wglDestroyPbufferARB )
        ++Wm3NumFunctions_WGL_ARB_pbuffer;

    Wm3wglQueryPbufferARB = (pfn_wglQueryPbufferARB)GetFunctionPointer("wglQueryPbufferARB");
    if ( Wm3wglQueryPbufferARB )
        ++Wm3NumFunctions_WGL_ARB_pbuffer;

    if ( Wm3NumFunctions_WGL_ARB_pbuffer == 5 )
        Wm3Exists_WGL_ARB_pbuffer = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_WGL_ARB_pbuffer = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_WGL_ARB_pbuffer ()
{
    Wm3NumFunctions_WGL_ARB_pbuffer = 0;
    Wm3Exists_WGL_ARB_pbuffer = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_WGL_ARB_render_texture;
int Wm3NumFunctions_WGL_ARB_render_texture;
#ifdef WM3_DEFINED_WGL_ARB_render_texture
pfn_wglBindTexImageARB Wm3wglBindTexImageARB = 0;
pfn_wglReleaseTexImageARB Wm3wglReleaseTexImageARB = 0;
pfn_wglSetPbufferAttribARB Wm3wglSetPbufferAttribARB = 0;

static void Init_WGL_ARB_render_texture ()
{
    Wm3NumFunctions_WGL_ARB_render_texture = 0;

    Wm3wglBindTexImageARB = (pfn_wglBindTexImageARB)GetFunctionPointer("wglBindTexImageARB");
    if ( Wm3wglBindTexImageARB )
        ++Wm3NumFunctions_WGL_ARB_render_texture;

    Wm3wglReleaseTexImageARB = (pfn_wglReleaseTexImageARB)GetFunctionPointer("wglReleaseTexImageARB");
    if ( Wm3wglReleaseTexImageARB )
        ++Wm3NumFunctions_WGL_ARB_render_texture;

    Wm3wglSetPbufferAttribARB = (pfn_wglSetPbufferAttribARB)GetFunctionPointer("wglSetPbufferAttribARB");
    if ( Wm3wglSetPbufferAttribARB )
        ++Wm3NumFunctions_WGL_ARB_render_texture;

    if ( Wm3NumFunctions_WGL_ARB_render_texture == 3 )
        Wm3Exists_WGL_ARB_render_texture = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_WGL_ARB_render_texture = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_WGL_ARB_render_texture ()
{
    Wm3NumFunctions_WGL_ARB_render_texture = 0;
    Wm3Exists_WGL_ARB_render_texture = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_WGL_ARB_pixel_format_float;
int Wm3NumFunctions_WGL_ARB_pixel_format_float;
#ifdef WM3_DEFINED_WGL_ARB_pixel_format_float

static void Init_WGL_ARB_pixel_format_float ()
{
    Wm3NumFunctions_WGL_ARB_pixel_format_float = 0;

    if ( Wm3NumFunctions_WGL_ARB_pixel_format_float == 0 )
        Wm3Exists_WGL_ARB_pixel_format_float = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_WGL_ARB_pixel_format_float = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_WGL_ARB_pixel_format_float ()
{
    Wm3NumFunctions_WGL_ARB_pixel_format_float = 0;
    Wm3Exists_WGL_ARB_pixel_format_float = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_WGL_EXT_make_current_read;
int Wm3NumFunctions_WGL_EXT_make_current_read;
#ifdef WM3_DEFINED_WGL_EXT_make_current_read
pfn_wglMakeContextCurrentEXT Wm3wglMakeContextCurrentEXT = 0;
pfn_wglGetCurrentReadDCEXT Wm3wglGetCurrentReadDCEXT = 0;

static void Init_WGL_EXT_make_current_read ()
{
    Wm3NumFunctions_WGL_EXT_make_current_read = 0;

    Wm3wglMakeContextCurrentEXT = (pfn_wglMakeContextCurrentEXT)GetFunctionPointer("wglMakeContextCurrentEXT");
    if ( Wm3wglMakeContextCurrentEXT )
        ++Wm3NumFunctions_WGL_EXT_make_current_read;

    Wm3wglGetCurrentReadDCEXT = (pfn_wglGetCurrentReadDCEXT)GetFunctionPointer("wglGetCurrentReadDCEXT");
    if ( Wm3wglGetCurrentReadDCEXT )
        ++Wm3NumFunctions_WGL_EXT_make_current_read;

    if ( Wm3NumFunctions_WGL_EXT_make_current_read == 2 )
        Wm3Exists_WGL_EXT_make_current_read = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_WGL_EXT_make_current_read = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_WGL_EXT_make_current_read ()
{
    Wm3NumFunctions_WGL_EXT_make_current_read = 0;
    Wm3Exists_WGL_EXT_make_current_read = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_WGL_EXT_pixel_format;
int Wm3NumFunctions_WGL_EXT_pixel_format;
#ifdef WM3_DEFINED_WGL_EXT_pixel_format
pfn_wglGetPixelFormatAttribivEXT Wm3wglGetPixelFormatAttribivEXT = 0;
pfn_wglGetPixelFormatAttribfvEXT Wm3wglGetPixelFormatAttribfvEXT = 0;
pfn_wglChoosePixelFormatEXT Wm3wglChoosePixelFormatEXT = 0;

static void Init_WGL_EXT_pixel_format ()
{
    Wm3NumFunctions_WGL_EXT_pixel_format = 0;

    Wm3wglGetPixelFormatAttribivEXT = (pfn_wglGetPixelFormatAttribivEXT)GetFunctionPointer("wglGetPixelFormatAttribivEXT");
    if ( Wm3wglGetPixelFormatAttribivEXT )
        ++Wm3NumFunctions_WGL_EXT_pixel_format;

    Wm3wglGetPixelFormatAttribfvEXT = (pfn_wglGetPixelFormatAttribfvEXT)GetFunctionPointer("wglGetPixelFormatAttribfvEXT");
    if ( Wm3wglGetPixelFormatAttribfvEXT )
        ++Wm3NumFunctions_WGL_EXT_pixel_format;

    Wm3wglChoosePixelFormatEXT = (pfn_wglChoosePixelFormatEXT)GetFunctionPointer("wglChoosePixelFormatEXT");
    if ( Wm3wglChoosePixelFormatEXT )
        ++Wm3NumFunctions_WGL_EXT_pixel_format;

    if ( Wm3NumFunctions_WGL_EXT_pixel_format == 3 )
        Wm3Exists_WGL_EXT_pixel_format = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_WGL_EXT_pixel_format = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_WGL_EXT_pixel_format ()
{
    Wm3NumFunctions_WGL_EXT_pixel_format = 0;
    Wm3Exists_WGL_EXT_pixel_format = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_WGL_EXT_pbuffer;
int Wm3NumFunctions_WGL_EXT_pbuffer;
#ifdef WM3_DEFINED_WGL_EXT_pbuffer
pfn_wglCreatePbufferEXT Wm3wglCreatePbufferEXT = 0;
pfn_wglGetPbufferDCEXT Wm3wglGetPbufferDCEXT = 0;
pfn_wglReleasePbufferDCEXT Wm3wglReleasePbufferDCEXT = 0;
pfn_wglDestroyPbufferEXT Wm3wglDestroyPbufferEXT = 0;
pfn_wglQueryPbufferEXT Wm3wglQueryPbufferEXT = 0;

static void Init_WGL_EXT_pbuffer ()
{
    Wm3NumFunctions_WGL_EXT_pbuffer = 0;

    Wm3wglCreatePbufferEXT = (pfn_wglCreatePbufferEXT)GetFunctionPointer("wglCreatePbufferEXT");
    if ( Wm3wglCreatePbufferEXT )
        ++Wm3NumFunctions_WGL_EXT_pbuffer;

    Wm3wglGetPbufferDCEXT = (pfn_wglGetPbufferDCEXT)GetFunctionPointer("wglGetPbufferDCEXT");
    if ( Wm3wglGetPbufferDCEXT )
        ++Wm3NumFunctions_WGL_EXT_pbuffer;

    Wm3wglReleasePbufferDCEXT = (pfn_wglReleasePbufferDCEXT)GetFunctionPointer("wglReleasePbufferDCEXT");
    if ( Wm3wglReleasePbufferDCEXT )
        ++Wm3NumFunctions_WGL_EXT_pbuffer;

    Wm3wglDestroyPbufferEXT = (pfn_wglDestroyPbufferEXT)GetFunctionPointer("wglDestroyPbufferEXT");
    if ( Wm3wglDestroyPbufferEXT )
        ++Wm3NumFunctions_WGL_EXT_pbuffer;

    Wm3wglQueryPbufferEXT = (pfn_wglQueryPbufferEXT)GetFunctionPointer("wglQueryPbufferEXT");
    if ( Wm3wglQueryPbufferEXT )
        ++Wm3NumFunctions_WGL_EXT_pbuffer;

    if ( Wm3NumFunctions_WGL_EXT_pbuffer == 5 )
        Wm3Exists_WGL_EXT_pbuffer = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_WGL_EXT_pbuffer = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_WGL_EXT_pbuffer ()
{
    Wm3NumFunctions_WGL_EXT_pbuffer = 0;
    Wm3Exists_WGL_EXT_pbuffer = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_WGL_EXT_depth_float;
int Wm3NumFunctions_WGL_EXT_depth_float;
#ifdef WM3_DEFINED_WGL_EXT_depth_float

static void Init_WGL_EXT_depth_float ()
{
    Wm3NumFunctions_WGL_EXT_depth_float = 0;

    if ( Wm3NumFunctions_WGL_EXT_depth_float == 0 )
        Wm3Exists_WGL_EXT_depth_float = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_WGL_EXT_depth_float = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_WGL_EXT_depth_float ()
{
    Wm3NumFunctions_WGL_EXT_depth_float = 0;
    Wm3Exists_WGL_EXT_depth_float = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_WGL_3DFX_multisample;
int Wm3NumFunctions_WGL_3DFX_multisample;
#ifdef WM3_DEFINED_WGL_3DFX_multisample

static void Init_WGL_3DFX_multisample ()
{
    Wm3NumFunctions_WGL_3DFX_multisample = 0;

    if ( Wm3NumFunctions_WGL_3DFX_multisample == 0 )
        Wm3Exists_WGL_3DFX_multisample = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_WGL_3DFX_multisample = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_WGL_3DFX_multisample ()
{
    Wm3NumFunctions_WGL_3DFX_multisample = 0;
    Wm3Exists_WGL_3DFX_multisample = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_WGL_EXT_multisample;
int Wm3NumFunctions_WGL_EXT_multisample;
#ifdef WM3_DEFINED_WGL_EXT_multisample

static void Init_WGL_EXT_multisample ()
{
    Wm3NumFunctions_WGL_EXT_multisample = 0;

    if ( Wm3NumFunctions_WGL_EXT_multisample == 0 )
        Wm3Exists_WGL_EXT_multisample = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_WGL_EXT_multisample = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_WGL_EXT_multisample ()
{
    Wm3NumFunctions_WGL_EXT_multisample = 0;
    Wm3Exists_WGL_EXT_multisample = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_WGL_I3D_digital_video_control;
int Wm3NumFunctions_WGL_I3D_digital_video_control;
#ifdef WM3_DEFINED_WGL_I3D_digital_video_control
pfn_wglGetDigitalVideoParametersI3D Wm3wglGetDigitalVideoParametersI3D = 0;
pfn_wglSetDigitalVideoParametersI3D Wm3wglSetDigitalVideoParametersI3D = 0;

static void Init_WGL_I3D_digital_video_control ()
{
    Wm3NumFunctions_WGL_I3D_digital_video_control = 0;

    Wm3wglGetDigitalVideoParametersI3D = (pfn_wglGetDigitalVideoParametersI3D)GetFunctionPointer("wglGetDigitalVideoParametersI3D");
    if ( Wm3wglGetDigitalVideoParametersI3D )
        ++Wm3NumFunctions_WGL_I3D_digital_video_control;

    Wm3wglSetDigitalVideoParametersI3D = (pfn_wglSetDigitalVideoParametersI3D)GetFunctionPointer("wglSetDigitalVideoParametersI3D");
    if ( Wm3wglSetDigitalVideoParametersI3D )
        ++Wm3NumFunctions_WGL_I3D_digital_video_control;

    if ( Wm3NumFunctions_WGL_I3D_digital_video_control == 2 )
        Wm3Exists_WGL_I3D_digital_video_control = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_WGL_I3D_digital_video_control = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_WGL_I3D_digital_video_control ()
{
    Wm3NumFunctions_WGL_I3D_digital_video_control = 0;
    Wm3Exists_WGL_I3D_digital_video_control = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_WGL_I3D_gamma;
int Wm3NumFunctions_WGL_I3D_gamma;
#ifdef WM3_DEFINED_WGL_I3D_gamma
pfn_wglGetGammaTableParametersI3D Wm3wglGetGammaTableParametersI3D = 0;
pfn_wglSetGammaTableParametersI3D Wm3wglSetGammaTableParametersI3D = 0;
pfn_wglGetGammaTableI3D Wm3wglGetGammaTableI3D = 0;
pfn_wglSetGammaTableI3D Wm3wglSetGammaTableI3D = 0;

static void Init_WGL_I3D_gamma ()
{
    Wm3NumFunctions_WGL_I3D_gamma = 0;

    Wm3wglGetGammaTableParametersI3D = (pfn_wglGetGammaTableParametersI3D)GetFunctionPointer("wglGetGammaTableParametersI3D");
    if ( Wm3wglGetGammaTableParametersI3D )
        ++Wm3NumFunctions_WGL_I3D_gamma;

    Wm3wglSetGammaTableParametersI3D = (pfn_wglSetGammaTableParametersI3D)GetFunctionPointer("wglSetGammaTableParametersI3D");
    if ( Wm3wglSetGammaTableParametersI3D )
        ++Wm3NumFunctions_WGL_I3D_gamma;

    Wm3wglGetGammaTableI3D = (pfn_wglGetGammaTableI3D)GetFunctionPointer("wglGetGammaTableI3D");
    if ( Wm3wglGetGammaTableI3D )
        ++Wm3NumFunctions_WGL_I3D_gamma;

    Wm3wglSetGammaTableI3D = (pfn_wglSetGammaTableI3D)GetFunctionPointer("wglSetGammaTableI3D");
    if ( Wm3wglSetGammaTableI3D )
        ++Wm3NumFunctions_WGL_I3D_gamma;

    if ( Wm3NumFunctions_WGL_I3D_gamma == 4 )
        Wm3Exists_WGL_I3D_gamma = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_WGL_I3D_gamma = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_WGL_I3D_gamma ()
{
    Wm3NumFunctions_WGL_I3D_gamma = 0;
    Wm3Exists_WGL_I3D_gamma = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_WGL_I3D_genlock;
int Wm3NumFunctions_WGL_I3D_genlock;
#ifdef WM3_DEFINED_WGL_I3D_genlock
pfn_wglEnableGenlockI3D Wm3wglEnableGenlockI3D = 0;
pfn_wglDisableGenlockI3D Wm3wglDisableGenlockI3D = 0;
pfn_wglIsEnabledGenlockI3D Wm3wglIsEnabledGenlockI3D = 0;
pfn_wglGenlockSourceI3D Wm3wglGenlockSourceI3D = 0;
pfn_wglGetGenlockSourceI3D Wm3wglGetGenlockSourceI3D = 0;
pfn_wglGenlockSourceEdgeI3D Wm3wglGenlockSourceEdgeI3D = 0;
pfn_wglGetGenlockSourceEdgeI3D Wm3wglGetGenlockSourceEdgeI3D = 0;
pfn_wglGenlockSampleRateI3D Wm3wglGenlockSampleRateI3D = 0;
pfn_wglGetGenlockSampleRateI3D Wm3wglGetGenlockSampleRateI3D = 0;
pfn_wglGenlockSourceDelayI3D Wm3wglGenlockSourceDelayI3D = 0;
pfn_wglGetGenlockSourceDelayI3D Wm3wglGetGenlockSourceDelayI3D = 0;
pfn_wglQueryGenlockMaxSourceDelayI3D Wm3wglQueryGenlockMaxSourceDelayI3D = 0;

static void Init_WGL_I3D_genlock ()
{
    Wm3NumFunctions_WGL_I3D_genlock = 0;

    Wm3wglEnableGenlockI3D = (pfn_wglEnableGenlockI3D)GetFunctionPointer("wglEnableGenlockI3D");
    if ( Wm3wglEnableGenlockI3D )
        ++Wm3NumFunctions_WGL_I3D_genlock;

    Wm3wglDisableGenlockI3D = (pfn_wglDisableGenlockI3D)GetFunctionPointer("wglDisableGenlockI3D");
    if ( Wm3wglDisableGenlockI3D )
        ++Wm3NumFunctions_WGL_I3D_genlock;

    Wm3wglIsEnabledGenlockI3D = (pfn_wglIsEnabledGenlockI3D)GetFunctionPointer("wglIsEnabledGenlockI3D");
    if ( Wm3wglIsEnabledGenlockI3D )
        ++Wm3NumFunctions_WGL_I3D_genlock;

    Wm3wglGenlockSourceI3D = (pfn_wglGenlockSourceI3D)GetFunctionPointer("wglGenlockSourceI3D");
    if ( Wm3wglGenlockSourceI3D )
        ++Wm3NumFunctions_WGL_I3D_genlock;

    Wm3wglGetGenlockSourceI3D = (pfn_wglGetGenlockSourceI3D)GetFunctionPointer("wglGetGenlockSourceI3D");
    if ( Wm3wglGetGenlockSourceI3D )
        ++Wm3NumFunctions_WGL_I3D_genlock;

    Wm3wglGenlockSourceEdgeI3D = (pfn_wglGenlockSourceEdgeI3D)GetFunctionPointer("wglGenlockSourceEdgeI3D");
    if ( Wm3wglGenlockSourceEdgeI3D )
        ++Wm3NumFunctions_WGL_I3D_genlock;

    Wm3wglGetGenlockSourceEdgeI3D = (pfn_wglGetGenlockSourceEdgeI3D)GetFunctionPointer("wglGetGenlockSourceEdgeI3D");
    if ( Wm3wglGetGenlockSourceEdgeI3D )
        ++Wm3NumFunctions_WGL_I3D_genlock;

    Wm3wglGenlockSampleRateI3D = (pfn_wglGenlockSampleRateI3D)GetFunctionPointer("wglGenlockSampleRateI3D");
    if ( Wm3wglGenlockSampleRateI3D )
        ++Wm3NumFunctions_WGL_I3D_genlock;

    Wm3wglGetGenlockSampleRateI3D = (pfn_wglGetGenlockSampleRateI3D)GetFunctionPointer("wglGetGenlockSampleRateI3D");
    if ( Wm3wglGetGenlockSampleRateI3D )
        ++Wm3NumFunctions_WGL_I3D_genlock;

    Wm3wglGenlockSourceDelayI3D = (pfn_wglGenlockSourceDelayI3D)GetFunctionPointer("wglGenlockSourceDelayI3D");
    if ( Wm3wglGenlockSourceDelayI3D )
        ++Wm3NumFunctions_WGL_I3D_genlock;

    Wm3wglGetGenlockSourceDelayI3D = (pfn_wglGetGenlockSourceDelayI3D)GetFunctionPointer("wglGetGenlockSourceDelayI3D");
    if ( Wm3wglGetGenlockSourceDelayI3D )
        ++Wm3NumFunctions_WGL_I3D_genlock;

    Wm3wglQueryGenlockMaxSourceDelayI3D = (pfn_wglQueryGenlockMaxSourceDelayI3D)GetFunctionPointer("wglQueryGenlockMaxSourceDelayI3D");
    if ( Wm3wglQueryGenlockMaxSourceDelayI3D )
        ++Wm3NumFunctions_WGL_I3D_genlock;

    if ( Wm3NumFunctions_WGL_I3D_genlock == 12 )
        Wm3Exists_WGL_I3D_genlock = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_WGL_I3D_genlock = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_WGL_I3D_genlock ()
{
    Wm3NumFunctions_WGL_I3D_genlock = 0;
    Wm3Exists_WGL_I3D_genlock = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_WGL_I3D_image_buffer;
int Wm3NumFunctions_WGL_I3D_image_buffer;
#ifdef WM3_DEFINED_WGL_I3D_image_buffer
pfn_wglCreateImageBufferI3D Wm3wglCreateImageBufferI3D = 0;
pfn_wglDestroyImageBufferI3D Wm3wglDestroyImageBufferI3D = 0;
pfn_wglAssociateImageBufferEventsI3D Wm3wglAssociateImageBufferEventsI3D = 0;
pfn_wglReleaseImageBufferEventsI3D Wm3wglReleaseImageBufferEventsI3D = 0;

static void Init_WGL_I3D_image_buffer ()
{
    Wm3NumFunctions_WGL_I3D_image_buffer = 0;

    Wm3wglCreateImageBufferI3D = (pfn_wglCreateImageBufferI3D)GetFunctionPointer("wglCreateImageBufferI3D");
    if ( Wm3wglCreateImageBufferI3D )
        ++Wm3NumFunctions_WGL_I3D_image_buffer;

    Wm3wglDestroyImageBufferI3D = (pfn_wglDestroyImageBufferI3D)GetFunctionPointer("wglDestroyImageBufferI3D");
    if ( Wm3wglDestroyImageBufferI3D )
        ++Wm3NumFunctions_WGL_I3D_image_buffer;

    Wm3wglAssociateImageBufferEventsI3D = (pfn_wglAssociateImageBufferEventsI3D)GetFunctionPointer("wglAssociateImageBufferEventsI3D");
    if ( Wm3wglAssociateImageBufferEventsI3D )
        ++Wm3NumFunctions_WGL_I3D_image_buffer;

    Wm3wglReleaseImageBufferEventsI3D = (pfn_wglReleaseImageBufferEventsI3D)GetFunctionPointer("wglReleaseImageBufferEventsI3D");
    if ( Wm3wglReleaseImageBufferEventsI3D )
        ++Wm3NumFunctions_WGL_I3D_image_buffer;

    if ( Wm3NumFunctions_WGL_I3D_image_buffer == 4 )
        Wm3Exists_WGL_I3D_image_buffer = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_WGL_I3D_image_buffer = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_WGL_I3D_image_buffer ()
{
    Wm3NumFunctions_WGL_I3D_image_buffer = 0;
    Wm3Exists_WGL_I3D_image_buffer = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_WGL_I3D_swap_frame_lock;
int Wm3NumFunctions_WGL_I3D_swap_frame_lock;
#ifdef WM3_DEFINED_WGL_I3D_swap_frame_lock
pfn_wglEnableFrameLockI3D Wm3wglEnableFrameLockI3D = 0;
pfn_wglDisableFrameLockI3D Wm3wglDisableFrameLockI3D = 0;
pfn_wglIsEnabledFrameLockI3D Wm3wglIsEnabledFrameLockI3D = 0;
pfn_wglQueryFrameLockMasterI3D Wm3wglQueryFrameLockMasterI3D = 0;

static void Init_WGL_I3D_swap_frame_lock ()
{
    Wm3NumFunctions_WGL_I3D_swap_frame_lock = 0;

    Wm3wglEnableFrameLockI3D = (pfn_wglEnableFrameLockI3D)GetFunctionPointer("wglEnableFrameLockI3D");
    if ( Wm3wglEnableFrameLockI3D )
        ++Wm3NumFunctions_WGL_I3D_swap_frame_lock;

    Wm3wglDisableFrameLockI3D = (pfn_wglDisableFrameLockI3D)GetFunctionPointer("wglDisableFrameLockI3D");
    if ( Wm3wglDisableFrameLockI3D )
        ++Wm3NumFunctions_WGL_I3D_swap_frame_lock;

    Wm3wglIsEnabledFrameLockI3D = (pfn_wglIsEnabledFrameLockI3D)GetFunctionPointer("wglIsEnabledFrameLockI3D");
    if ( Wm3wglIsEnabledFrameLockI3D )
        ++Wm3NumFunctions_WGL_I3D_swap_frame_lock;

    Wm3wglQueryFrameLockMasterI3D = (pfn_wglQueryFrameLockMasterI3D)GetFunctionPointer("wglQueryFrameLockMasterI3D");
    if ( Wm3wglQueryFrameLockMasterI3D )
        ++Wm3NumFunctions_WGL_I3D_swap_frame_lock;

    if ( Wm3NumFunctions_WGL_I3D_swap_frame_lock == 4 )
        Wm3Exists_WGL_I3D_swap_frame_lock = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_WGL_I3D_swap_frame_lock = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_WGL_I3D_swap_frame_lock ()
{
    Wm3NumFunctions_WGL_I3D_swap_frame_lock = 0;
    Wm3Exists_WGL_I3D_swap_frame_lock = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_WGL_I3D_swap_frame_usage;
int Wm3NumFunctions_WGL_I3D_swap_frame_usage;
#ifdef WM3_DEFINED_WGL_I3D_swap_frame_usage
pfn_wglGetFrameUsageI3D Wm3wglGetFrameUsageI3D = 0;
pfn_wglBeginFrameTrackingI3D Wm3wglBeginFrameTrackingI3D = 0;
pfn_wglEndFrameTrackingI3D Wm3wglEndFrameTrackingI3D = 0;
pfn_wglQueryFrameTrackingI3D Wm3wglQueryFrameTrackingI3D = 0;

static void Init_WGL_I3D_swap_frame_usage ()
{
    Wm3NumFunctions_WGL_I3D_swap_frame_usage = 0;

    Wm3wglGetFrameUsageI3D = (pfn_wglGetFrameUsageI3D)GetFunctionPointer("wglGetFrameUsageI3D");
    if ( Wm3wglGetFrameUsageI3D )
        ++Wm3NumFunctions_WGL_I3D_swap_frame_usage;

    Wm3wglBeginFrameTrackingI3D = (pfn_wglBeginFrameTrackingI3D)GetFunctionPointer("wglBeginFrameTrackingI3D");
    if ( Wm3wglBeginFrameTrackingI3D )
        ++Wm3NumFunctions_WGL_I3D_swap_frame_usage;

    Wm3wglEndFrameTrackingI3D = (pfn_wglEndFrameTrackingI3D)GetFunctionPointer("wglEndFrameTrackingI3D");
    if ( Wm3wglEndFrameTrackingI3D )
        ++Wm3NumFunctions_WGL_I3D_swap_frame_usage;

    Wm3wglQueryFrameTrackingI3D = (pfn_wglQueryFrameTrackingI3D)GetFunctionPointer("wglQueryFrameTrackingI3D");
    if ( Wm3wglQueryFrameTrackingI3D )
        ++Wm3NumFunctions_WGL_I3D_swap_frame_usage;

    if ( Wm3NumFunctions_WGL_I3D_swap_frame_usage == 4 )
        Wm3Exists_WGL_I3D_swap_frame_usage = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_WGL_I3D_swap_frame_usage = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_WGL_I3D_swap_frame_usage ()
{
    Wm3NumFunctions_WGL_I3D_swap_frame_usage = 0;
    Wm3Exists_WGL_I3D_swap_frame_usage = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_WGL_NV_render_depth_texture;
int Wm3NumFunctions_WGL_NV_render_depth_texture;
#ifdef WM3_DEFINED_WGL_NV_render_depth_texture

static void Init_WGL_NV_render_depth_texture ()
{
    Wm3NumFunctions_WGL_NV_render_depth_texture = 0;

    if ( Wm3NumFunctions_WGL_NV_render_depth_texture == 0 )
        Wm3Exists_WGL_NV_render_depth_texture = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_WGL_NV_render_depth_texture = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_WGL_NV_render_depth_texture ()
{
    Wm3NumFunctions_WGL_NV_render_depth_texture = 0;
    Wm3Exists_WGL_NV_render_depth_texture = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_WGL_NV_render_texture_rectangle;
int Wm3NumFunctions_WGL_NV_render_texture_rectangle;
#ifdef WM3_DEFINED_WGL_NV_render_texture_rectangle

static void Init_WGL_NV_render_texture_rectangle ()
{
    Wm3NumFunctions_WGL_NV_render_texture_rectangle = 0;

    if ( Wm3NumFunctions_WGL_NV_render_texture_rectangle == 0 )
        Wm3Exists_WGL_NV_render_texture_rectangle = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_WGL_NV_render_texture_rectangle = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_WGL_NV_render_texture_rectangle ()
{
    Wm3NumFunctions_WGL_NV_render_texture_rectangle = 0;
    Wm3Exists_WGL_NV_render_texture_rectangle = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_WGL_ATI_pixel_format_float;
int Wm3NumFunctions_WGL_ATI_pixel_format_float;
#ifdef WM3_DEFINED_WGL_ATI_pixel_format_float

static void Init_WGL_ATI_pixel_format_float ()
{
    Wm3NumFunctions_WGL_ATI_pixel_format_float = 0;

    if ( Wm3NumFunctions_WGL_ATI_pixel_format_float == 0 )
        Wm3Exists_WGL_ATI_pixel_format_float = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_WGL_ATI_pixel_format_float = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_WGL_ATI_pixel_format_float ()
{
    Wm3NumFunctions_WGL_ATI_pixel_format_float = 0;
    Wm3Exists_WGL_ATI_pixel_format_float = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_WGL_NV_float_buffer;
int Wm3NumFunctions_WGL_NV_float_buffer;
#ifdef WM3_DEFINED_WGL_NV_float_buffer

static void Init_WGL_NV_float_buffer ()
{
    Wm3NumFunctions_WGL_NV_float_buffer = 0;

    if ( Wm3NumFunctions_WGL_NV_float_buffer == 0 )
        Wm3Exists_WGL_NV_float_buffer = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_WGL_NV_float_buffer = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_WGL_NV_float_buffer ()
{
    Wm3NumFunctions_WGL_NV_float_buffer = 0;
    Wm3Exists_WGL_NV_float_buffer = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_WGL_EXT_display_color_table;
int Wm3NumFunctions_WGL_EXT_display_color_table;
#ifdef WM3_DEFINED_WGL_EXT_display_color_table
pfn_wglCreateDisplayColorTableEXT Wm3wglCreateDisplayColorTableEXT = 0;
pfn_wglLoadDisplayColorTableEXT Wm3wglLoadDisplayColorTableEXT = 0;
pfn_wglBindDisplayColorTableEXT Wm3wglBindDisplayColorTableEXT = 0;
pfn_wglDestroyDisplayColorTableEXT Wm3wglDestroyDisplayColorTableEXT = 0;

static void Init_WGL_EXT_display_color_table ()
{
    Wm3NumFunctions_WGL_EXT_display_color_table = 0;

    Wm3wglCreateDisplayColorTableEXT = (pfn_wglCreateDisplayColorTableEXT)GetFunctionPointer("wglCreateDisplayColorTableEXT");
    if ( Wm3wglCreateDisplayColorTableEXT )
        ++Wm3NumFunctions_WGL_EXT_display_color_table;

    Wm3wglLoadDisplayColorTableEXT = (pfn_wglLoadDisplayColorTableEXT)GetFunctionPointer("wglLoadDisplayColorTableEXT");
    if ( Wm3wglLoadDisplayColorTableEXT )
        ++Wm3NumFunctions_WGL_EXT_display_color_table;

    Wm3wglBindDisplayColorTableEXT = (pfn_wglBindDisplayColorTableEXT)GetFunctionPointer("wglBindDisplayColorTableEXT");
    if ( Wm3wglBindDisplayColorTableEXT )
        ++Wm3NumFunctions_WGL_EXT_display_color_table;

    Wm3wglDestroyDisplayColorTableEXT = (pfn_wglDestroyDisplayColorTableEXT)GetFunctionPointer("wglDestroyDisplayColorTableEXT");
    if ( Wm3wglDestroyDisplayColorTableEXT )
        ++Wm3NumFunctions_WGL_EXT_display_color_table;

    if ( Wm3NumFunctions_WGL_EXT_display_color_table == 4 )
        Wm3Exists_WGL_EXT_display_color_table = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_WGL_EXT_display_color_table = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_WGL_EXT_display_color_table ()
{
    Wm3NumFunctions_WGL_EXT_display_color_table = 0;
    Wm3Exists_WGL_EXT_display_color_table = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_WGL_EXT_extensions_string;
int Wm3NumFunctions_WGL_EXT_extensions_string;
#ifdef WM3_DEFINED_WGL_EXT_extensions_string
pfn_wglGetExtensionsStringEXT Wm3wglGetExtensionsStringEXT = 0;

static void Init_WGL_EXT_extensions_string ()
{
    Wm3NumFunctions_WGL_EXT_extensions_string = 0;

    Wm3wglGetExtensionsStringEXT = (pfn_wglGetExtensionsStringEXT)GetFunctionPointer("wglGetExtensionsStringEXT");
    if ( Wm3wglGetExtensionsStringEXT )
        ++Wm3NumFunctions_WGL_EXT_extensions_string;

    if ( Wm3NumFunctions_WGL_EXT_extensions_string == 1 )
        Wm3Exists_WGL_EXT_extensions_string = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_WGL_EXT_extensions_string = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_WGL_EXT_extensions_string ()
{
    Wm3NumFunctions_WGL_EXT_extensions_string = 0;
    Wm3Exists_WGL_EXT_extensions_string = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_WGL_EXT_swap_control;
int Wm3NumFunctions_WGL_EXT_swap_control;
#ifdef WM3_DEFINED_WGL_EXT_swap_control
pfn_wglSwapIntervalEXT Wm3wglSwapIntervalEXT = 0;
pfn_wglGetSwapIntervalEXT Wm3wglGetSwapIntervalEXT = 0;

static void Init_WGL_EXT_swap_control ()
{
    Wm3NumFunctions_WGL_EXT_swap_control = 0;

    Wm3wglSwapIntervalEXT = (pfn_wglSwapIntervalEXT)GetFunctionPointer("wglSwapIntervalEXT");
    if ( Wm3wglSwapIntervalEXT )
        ++Wm3NumFunctions_WGL_EXT_swap_control;

    Wm3wglGetSwapIntervalEXT = (pfn_wglGetSwapIntervalEXT)GetFunctionPointer("wglGetSwapIntervalEXT");
    if ( Wm3wglGetSwapIntervalEXT )
        ++Wm3NumFunctions_WGL_EXT_swap_control;

    if ( Wm3NumFunctions_WGL_EXT_swap_control == 2 )
        Wm3Exists_WGL_EXT_swap_control = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_WGL_EXT_swap_control = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_WGL_EXT_swap_control ()
{
    Wm3NumFunctions_WGL_EXT_swap_control = 0;
    Wm3Exists_WGL_EXT_swap_control = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_WGL_NV_vertex_array_range;
int Wm3NumFunctions_WGL_NV_vertex_array_range;
#ifdef WM3_DEFINED_WGL_NV_vertex_array_range
pfn_wglAllocateMemoryNV Wm3wglAllocateMemoryNV = 0;
pfn_wglFreeMemoryNV Wm3wglFreeMemoryNV = 0;

static void Init_WGL_NV_vertex_array_range ()
{
    Wm3NumFunctions_WGL_NV_vertex_array_range = 0;

    Wm3wglAllocateMemoryNV = (pfn_wglAllocateMemoryNV)GetFunctionPointer("wglAllocateMemoryNV");
    if ( Wm3wglAllocateMemoryNV )
        ++Wm3NumFunctions_WGL_NV_vertex_array_range;

    Wm3wglFreeMemoryNV = (pfn_wglFreeMemoryNV)GetFunctionPointer("wglFreeMemoryNV");
    if ( Wm3wglFreeMemoryNV )
        ++Wm3NumFunctions_WGL_NV_vertex_array_range;

    if ( Wm3NumFunctions_WGL_NV_vertex_array_range == 2 )
        Wm3Exists_WGL_NV_vertex_array_range = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_WGL_NV_vertex_array_range = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_WGL_NV_vertex_array_range ()
{
    Wm3NumFunctions_WGL_NV_vertex_array_range = 0;
    Wm3Exists_WGL_NV_vertex_array_range = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_WGL_OML_sync_control;
int Wm3NumFunctions_WGL_OML_sync_control;
#ifdef WM3_DEFINED_WGL_OML_sync_control
pfn_wglGetSyncValuesOML Wm3wglGetSyncValuesOML = 0;
pfn_wglGetMscRateOML Wm3wglGetMscRateOML = 0;
pfn_wglSwapBuffersMscOML Wm3wglSwapBuffersMscOML = 0;
pfn_wglSwapLayerBuffersMscOML Wm3wglSwapLayerBuffersMscOML = 0;
pfn_wglWaitForMscOML Wm3wglWaitForMscOML = 0;
pfn_wglWaitForSbcOML Wm3wglWaitForSbcOML = 0;

static void Init_WGL_OML_sync_control ()
{
    Wm3NumFunctions_WGL_OML_sync_control = 0;

    Wm3wglGetSyncValuesOML = (pfn_wglGetSyncValuesOML)GetFunctionPointer("wglGetSyncValuesOML");
    if ( Wm3wglGetSyncValuesOML )
        ++Wm3NumFunctions_WGL_OML_sync_control;

    Wm3wglGetMscRateOML = (pfn_wglGetMscRateOML)GetFunctionPointer("wglGetMscRateOML");
    if ( Wm3wglGetMscRateOML )
        ++Wm3NumFunctions_WGL_OML_sync_control;

    Wm3wglSwapBuffersMscOML = (pfn_wglSwapBuffersMscOML)GetFunctionPointer("wglSwapBuffersMscOML");
    if ( Wm3wglSwapBuffersMscOML )
        ++Wm3NumFunctions_WGL_OML_sync_control;

    Wm3wglSwapLayerBuffersMscOML = (pfn_wglSwapLayerBuffersMscOML)GetFunctionPointer("wglSwapLayerBuffersMscOML");
    if ( Wm3wglSwapLayerBuffersMscOML )
        ++Wm3NumFunctions_WGL_OML_sync_control;

    Wm3wglWaitForMscOML = (pfn_wglWaitForMscOML)GetFunctionPointer("wglWaitForMscOML");
    if ( Wm3wglWaitForMscOML )
        ++Wm3NumFunctions_WGL_OML_sync_control;

    Wm3wglWaitForSbcOML = (pfn_wglWaitForSbcOML)GetFunctionPointer("wglWaitForSbcOML");
    if ( Wm3wglWaitForSbcOML )
        ++Wm3NumFunctions_WGL_OML_sync_control;

    if ( Wm3NumFunctions_WGL_OML_sync_control == 6 )
        Wm3Exists_WGL_OML_sync_control = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_WGL_OML_sync_control = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_WGL_OML_sync_control ()
{
    Wm3NumFunctions_WGL_OML_sync_control = 0;
    Wm3Exists_WGL_OML_sync_control = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
void InitializeWgl ()
{
    Init_WGL_ARB_buffer_region();
    Init_WGL_ARB_multisample();
    Init_WGL_ARB_extensions_string();
    Init_WGL_ARB_pixel_format();
    Init_WGL_ARB_make_current_read();
    Init_WGL_ARB_pbuffer();
    Init_WGL_ARB_render_texture();
    Init_WGL_ARB_pixel_format_float();
    Init_WGL_EXT_make_current_read();
    Init_WGL_EXT_pixel_format();
    Init_WGL_EXT_pbuffer();
    Init_WGL_EXT_depth_float();
    Init_WGL_3DFX_multisample();
    Init_WGL_EXT_multisample();
    Init_WGL_I3D_digital_video_control();
    Init_WGL_I3D_gamma();
    Init_WGL_I3D_genlock();
    Init_WGL_I3D_image_buffer();
    Init_WGL_I3D_swap_frame_lock();
    Init_WGL_I3D_swap_frame_usage();
    Init_WGL_NV_render_depth_texture();
    Init_WGL_NV_render_texture_rectangle();
    Init_WGL_ATI_pixel_format_float();
    Init_WGL_NV_float_buffer();
    Init_WGL_EXT_display_color_table();
    Init_WGL_EXT_extensions_string();
    Init_WGL_EXT_swap_control();
    Init_WGL_NV_vertex_array_range();
    Init_WGL_OML_sync_control();
}
/*--------------------------------------------------------------------------*/
