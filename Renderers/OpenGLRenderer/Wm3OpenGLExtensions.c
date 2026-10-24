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

#include "Wm3OpenGLExtensions.h"


/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_VERSION_1_1;
int Wm3NumFunctions_GL_VERSION_1_1;
#ifdef WM3_DEFINED_GL_VERSION_1_1
static void Init_GL_VERSION_1_1 ()
{
    Wm3NumFunctions_GL_VERSION_1_1 = 336;
    Wm3Exists_GL_VERSION_1_1 = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_VERSION_1_1 ()
{
    Wm3NumFunctions_GL_VERSION_1_1 = 0;
    Wm3Exists_GL_VERSION_1_1 = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_VERSION_1_2;
int Wm3NumFunctions_GL_VERSION_1_2;
#ifdef WM3_DEFINED_GL_VERSION_1_2
pfn_glBlendColor Wm3glBlendColor = 0;
pfn_glBlendEquation Wm3glBlendEquation = 0;
pfn_glDrawRangeElements Wm3glDrawRangeElements = 0;
pfn_glColorTable Wm3glColorTable = 0;
pfn_glColorTableParameterfv Wm3glColorTableParameterfv = 0;
pfn_glColorTableParameteriv Wm3glColorTableParameteriv = 0;
pfn_glCopyColorTable Wm3glCopyColorTable = 0;
pfn_glGetColorTable Wm3glGetColorTable = 0;
pfn_glGetColorTableParameterfv Wm3glGetColorTableParameterfv = 0;
pfn_glGetColorTableParameteriv Wm3glGetColorTableParameteriv = 0;
pfn_glColorSubTable Wm3glColorSubTable = 0;
pfn_glCopyColorSubTable Wm3glCopyColorSubTable = 0;
pfn_glConvolutionFilter1D Wm3glConvolutionFilter1D = 0;
pfn_glConvolutionFilter2D Wm3glConvolutionFilter2D = 0;
pfn_glConvolutionParameterf Wm3glConvolutionParameterf = 0;
pfn_glConvolutionParameterfv Wm3glConvolutionParameterfv = 0;
pfn_glConvolutionParameteri Wm3glConvolutionParameteri = 0;
pfn_glConvolutionParameteriv Wm3glConvolutionParameteriv = 0;
pfn_glCopyConvolutionFilter1D Wm3glCopyConvolutionFilter1D = 0;
pfn_glCopyConvolutionFilter2D Wm3glCopyConvolutionFilter2D = 0;
pfn_glGetConvolutionFilter Wm3glGetConvolutionFilter = 0;
pfn_glGetConvolutionParameterfv Wm3glGetConvolutionParameterfv = 0;
pfn_glGetConvolutionParameteriv Wm3glGetConvolutionParameteriv = 0;
pfn_glGetSeparableFilter Wm3glGetSeparableFilter = 0;
pfn_glSeparableFilter2D Wm3glSeparableFilter2D = 0;
pfn_glGetHistogram Wm3glGetHistogram = 0;
pfn_glGetHistogramParameterfv Wm3glGetHistogramParameterfv = 0;
pfn_glGetHistogramParameteriv Wm3glGetHistogramParameteriv = 0;
pfn_glGetMinmax Wm3glGetMinmax = 0;
pfn_glGetMinmaxParameterfv Wm3glGetMinmaxParameterfv = 0;
pfn_glGetMinmaxParameteriv Wm3glGetMinmaxParameteriv = 0;
pfn_glHistogram Wm3glHistogram = 0;
pfn_glMinmax Wm3glMinmax = 0;
pfn_glResetHistogram Wm3glResetHistogram = 0;
pfn_glResetMinmax Wm3glResetMinmax = 0;
pfn_glTexImage3D Wm3glTexImage3D = 0;
pfn_glTexSubImage3D Wm3glTexSubImage3D = 0;
pfn_glCopyTexSubImage3D Wm3glCopyTexSubImage3D = 0;

static void Init_GL_VERSION_1_2 ()
{
    Wm3NumFunctions_GL_VERSION_1_2 = 0;

    Wm3glBlendColor = (pfn_glBlendColor)GetFunctionPointer("glBlendColor");
    if ( Wm3glBlendColor )
        ++Wm3NumFunctions_GL_VERSION_1_2;

    Wm3glBlendEquation = (pfn_glBlendEquation)GetFunctionPointer("glBlendEquation");
    if ( Wm3glBlendEquation )
        ++Wm3NumFunctions_GL_VERSION_1_2;

    Wm3glDrawRangeElements = (pfn_glDrawRangeElements)GetFunctionPointer("glDrawRangeElements");
    if ( Wm3glDrawRangeElements )
        ++Wm3NumFunctions_GL_VERSION_1_2;

    Wm3glColorTable = (pfn_glColorTable)GetFunctionPointer("glColorTable");
    if ( Wm3glColorTable )
        ++Wm3NumFunctions_GL_VERSION_1_2;

    Wm3glColorTableParameterfv = (pfn_glColorTableParameterfv)GetFunctionPointer("glColorTableParameterfv");
    if ( Wm3glColorTableParameterfv )
        ++Wm3NumFunctions_GL_VERSION_1_2;

    Wm3glColorTableParameteriv = (pfn_glColorTableParameteriv)GetFunctionPointer("glColorTableParameteriv");
    if ( Wm3glColorTableParameteriv )
        ++Wm3NumFunctions_GL_VERSION_1_2;

    Wm3glCopyColorTable = (pfn_glCopyColorTable)GetFunctionPointer("glCopyColorTable");
    if ( Wm3glCopyColorTable )
        ++Wm3NumFunctions_GL_VERSION_1_2;

    Wm3glGetColorTable = (pfn_glGetColorTable)GetFunctionPointer("glGetColorTable");
    if ( Wm3glGetColorTable )
        ++Wm3NumFunctions_GL_VERSION_1_2;

    Wm3glGetColorTableParameterfv = (pfn_glGetColorTableParameterfv)GetFunctionPointer("glGetColorTableParameterfv");
    if ( Wm3glGetColorTableParameterfv )
        ++Wm3NumFunctions_GL_VERSION_1_2;

    Wm3glGetColorTableParameteriv = (pfn_glGetColorTableParameteriv)GetFunctionPointer("glGetColorTableParameteriv");
    if ( Wm3glGetColorTableParameteriv )
        ++Wm3NumFunctions_GL_VERSION_1_2;

    Wm3glColorSubTable = (pfn_glColorSubTable)GetFunctionPointer("glColorSubTable");
    if ( Wm3glColorSubTable )
        ++Wm3NumFunctions_GL_VERSION_1_2;

    Wm3glCopyColorSubTable = (pfn_glCopyColorSubTable)GetFunctionPointer("glCopyColorSubTable");
    if ( Wm3glCopyColorSubTable )
        ++Wm3NumFunctions_GL_VERSION_1_2;

    Wm3glConvolutionFilter1D = (pfn_glConvolutionFilter1D)GetFunctionPointer("glConvolutionFilter1D");
    if ( Wm3glConvolutionFilter1D )
        ++Wm3NumFunctions_GL_VERSION_1_2;

    Wm3glConvolutionFilter2D = (pfn_glConvolutionFilter2D)GetFunctionPointer("glConvolutionFilter2D");
    if ( Wm3glConvolutionFilter2D )
        ++Wm3NumFunctions_GL_VERSION_1_2;

    Wm3glConvolutionParameterf = (pfn_glConvolutionParameterf)GetFunctionPointer("glConvolutionParameterf");
    if ( Wm3glConvolutionParameterf )
        ++Wm3NumFunctions_GL_VERSION_1_2;

    Wm3glConvolutionParameterfv = (pfn_glConvolutionParameterfv)GetFunctionPointer("glConvolutionParameterfv");
    if ( Wm3glConvolutionParameterfv )
        ++Wm3NumFunctions_GL_VERSION_1_2;

    Wm3glConvolutionParameteri = (pfn_glConvolutionParameteri)GetFunctionPointer("glConvolutionParameteri");
    if ( Wm3glConvolutionParameteri )
        ++Wm3NumFunctions_GL_VERSION_1_2;

    Wm3glConvolutionParameteriv = (pfn_glConvolutionParameteriv)GetFunctionPointer("glConvolutionParameteriv");
    if ( Wm3glConvolutionParameteriv )
        ++Wm3NumFunctions_GL_VERSION_1_2;

    Wm3glCopyConvolutionFilter1D = (pfn_glCopyConvolutionFilter1D)GetFunctionPointer("glCopyConvolutionFilter1D");
    if ( Wm3glCopyConvolutionFilter1D )
        ++Wm3NumFunctions_GL_VERSION_1_2;

    Wm3glCopyConvolutionFilter2D = (pfn_glCopyConvolutionFilter2D)GetFunctionPointer("glCopyConvolutionFilter2D");
    if ( Wm3glCopyConvolutionFilter2D )
        ++Wm3NumFunctions_GL_VERSION_1_2;

    Wm3glGetConvolutionFilter = (pfn_glGetConvolutionFilter)GetFunctionPointer("glGetConvolutionFilter");
    if ( Wm3glGetConvolutionFilter )
        ++Wm3NumFunctions_GL_VERSION_1_2;

    Wm3glGetConvolutionParameterfv = (pfn_glGetConvolutionParameterfv)GetFunctionPointer("glGetConvolutionParameterfv");
    if ( Wm3glGetConvolutionParameterfv )
        ++Wm3NumFunctions_GL_VERSION_1_2;

    Wm3glGetConvolutionParameteriv = (pfn_glGetConvolutionParameteriv)GetFunctionPointer("glGetConvolutionParameteriv");
    if ( Wm3glGetConvolutionParameteriv )
        ++Wm3NumFunctions_GL_VERSION_1_2;

    Wm3glGetSeparableFilter = (pfn_glGetSeparableFilter)GetFunctionPointer("glGetSeparableFilter");
    if ( Wm3glGetSeparableFilter )
        ++Wm3NumFunctions_GL_VERSION_1_2;

    Wm3glSeparableFilter2D = (pfn_glSeparableFilter2D)GetFunctionPointer("glSeparableFilter2D");
    if ( Wm3glSeparableFilter2D )
        ++Wm3NumFunctions_GL_VERSION_1_2;

    Wm3glGetHistogram = (pfn_glGetHistogram)GetFunctionPointer("glGetHistogram");
    if ( Wm3glGetHistogram )
        ++Wm3NumFunctions_GL_VERSION_1_2;

    Wm3glGetHistogramParameterfv = (pfn_glGetHistogramParameterfv)GetFunctionPointer("glGetHistogramParameterfv");
    if ( Wm3glGetHistogramParameterfv )
        ++Wm3NumFunctions_GL_VERSION_1_2;

    Wm3glGetHistogramParameteriv = (pfn_glGetHistogramParameteriv)GetFunctionPointer("glGetHistogramParameteriv");
    if ( Wm3glGetHistogramParameteriv )
        ++Wm3NumFunctions_GL_VERSION_1_2;

    Wm3glGetMinmax = (pfn_glGetMinmax)GetFunctionPointer("glGetMinmax");
    if ( Wm3glGetMinmax )
        ++Wm3NumFunctions_GL_VERSION_1_2;

    Wm3glGetMinmaxParameterfv = (pfn_glGetMinmaxParameterfv)GetFunctionPointer("glGetMinmaxParameterfv");
    if ( Wm3glGetMinmaxParameterfv )
        ++Wm3NumFunctions_GL_VERSION_1_2;

    Wm3glGetMinmaxParameteriv = (pfn_glGetMinmaxParameteriv)GetFunctionPointer("glGetMinmaxParameteriv");
    if ( Wm3glGetMinmaxParameteriv )
        ++Wm3NumFunctions_GL_VERSION_1_2;

    Wm3glHistogram = (pfn_glHistogram)GetFunctionPointer("glHistogram");
    if ( Wm3glHistogram )
        ++Wm3NumFunctions_GL_VERSION_1_2;

    Wm3glMinmax = (pfn_glMinmax)GetFunctionPointer("glMinmax");
    if ( Wm3glMinmax )
        ++Wm3NumFunctions_GL_VERSION_1_2;

    Wm3glResetHistogram = (pfn_glResetHistogram)GetFunctionPointer("glResetHistogram");
    if ( Wm3glResetHistogram )
        ++Wm3NumFunctions_GL_VERSION_1_2;

    Wm3glResetMinmax = (pfn_glResetMinmax)GetFunctionPointer("glResetMinmax");
    if ( Wm3glResetMinmax )
        ++Wm3NumFunctions_GL_VERSION_1_2;

    Wm3glTexImage3D = (pfn_glTexImage3D)GetFunctionPointer("glTexImage3D");
    if ( Wm3glTexImage3D )
        ++Wm3NumFunctions_GL_VERSION_1_2;

    Wm3glTexSubImage3D = (pfn_glTexSubImage3D)GetFunctionPointer("glTexSubImage3D");
    if ( Wm3glTexSubImage3D )
        ++Wm3NumFunctions_GL_VERSION_1_2;

    Wm3glCopyTexSubImage3D = (pfn_glCopyTexSubImage3D)GetFunctionPointer("glCopyTexSubImage3D");
    if ( Wm3glCopyTexSubImage3D )
        ++Wm3NumFunctions_GL_VERSION_1_2;

    if ( Wm3NumFunctions_GL_VERSION_1_2 == 38 )
        Wm3Exists_GL_VERSION_1_2 = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_VERSION_1_2 = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_VERSION_1_2 ()
{
    Wm3NumFunctions_GL_VERSION_1_2 = 0;
    Wm3Exists_GL_VERSION_1_2 = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_VERSION_1_3;
int Wm3NumFunctions_GL_VERSION_1_3;
#ifdef WM3_DEFINED_GL_VERSION_1_3
pfn_glActiveTexture Wm3glActiveTexture = 0;
pfn_glClientActiveTexture Wm3glClientActiveTexture = 0;
pfn_glMultiTexCoord1d Wm3glMultiTexCoord1d = 0;
pfn_glMultiTexCoord1dv Wm3glMultiTexCoord1dv = 0;
pfn_glMultiTexCoord1f Wm3glMultiTexCoord1f = 0;
pfn_glMultiTexCoord1fv Wm3glMultiTexCoord1fv = 0;
pfn_glMultiTexCoord1i Wm3glMultiTexCoord1i = 0;
pfn_glMultiTexCoord1iv Wm3glMultiTexCoord1iv = 0;
pfn_glMultiTexCoord1s Wm3glMultiTexCoord1s = 0;
pfn_glMultiTexCoord1sv Wm3glMultiTexCoord1sv = 0;
pfn_glMultiTexCoord2d Wm3glMultiTexCoord2d = 0;
pfn_glMultiTexCoord2dv Wm3glMultiTexCoord2dv = 0;
pfn_glMultiTexCoord2f Wm3glMultiTexCoord2f = 0;
pfn_glMultiTexCoord2fv Wm3glMultiTexCoord2fv = 0;
pfn_glMultiTexCoord2i Wm3glMultiTexCoord2i = 0;
pfn_glMultiTexCoord2iv Wm3glMultiTexCoord2iv = 0;
pfn_glMultiTexCoord2s Wm3glMultiTexCoord2s = 0;
pfn_glMultiTexCoord2sv Wm3glMultiTexCoord2sv = 0;
pfn_glMultiTexCoord3d Wm3glMultiTexCoord3d = 0;
pfn_glMultiTexCoord3dv Wm3glMultiTexCoord3dv = 0;
pfn_glMultiTexCoord3f Wm3glMultiTexCoord3f = 0;
pfn_glMultiTexCoord3fv Wm3glMultiTexCoord3fv = 0;
pfn_glMultiTexCoord3i Wm3glMultiTexCoord3i = 0;
pfn_glMultiTexCoord3iv Wm3glMultiTexCoord3iv = 0;
pfn_glMultiTexCoord3s Wm3glMultiTexCoord3s = 0;
pfn_glMultiTexCoord3sv Wm3glMultiTexCoord3sv = 0;
pfn_glMultiTexCoord4d Wm3glMultiTexCoord4d = 0;
pfn_glMultiTexCoord4dv Wm3glMultiTexCoord4dv = 0;
pfn_glMultiTexCoord4f Wm3glMultiTexCoord4f = 0;
pfn_glMultiTexCoord4fv Wm3glMultiTexCoord4fv = 0;
pfn_glMultiTexCoord4i Wm3glMultiTexCoord4i = 0;
pfn_glMultiTexCoord4iv Wm3glMultiTexCoord4iv = 0;
pfn_glMultiTexCoord4s Wm3glMultiTexCoord4s = 0;
pfn_glMultiTexCoord4sv Wm3glMultiTexCoord4sv = 0;
pfn_glLoadTransposeMatrixf Wm3glLoadTransposeMatrixf = 0;
pfn_glLoadTransposeMatrixd Wm3glLoadTransposeMatrixd = 0;
pfn_glMultTransposeMatrixf Wm3glMultTransposeMatrixf = 0;
pfn_glMultTransposeMatrixd Wm3glMultTransposeMatrixd = 0;
pfn_glSampleCoverage Wm3glSampleCoverage = 0;
pfn_glCompressedTexImage3D Wm3glCompressedTexImage3D = 0;
pfn_glCompressedTexImage2D Wm3glCompressedTexImage2D = 0;
pfn_glCompressedTexImage1D Wm3glCompressedTexImage1D = 0;
pfn_glCompressedTexSubImage3D Wm3glCompressedTexSubImage3D = 0;
pfn_glCompressedTexSubImage2D Wm3glCompressedTexSubImage2D = 0;
pfn_glCompressedTexSubImage1D Wm3glCompressedTexSubImage1D = 0;
pfn_glGetCompressedTexImage Wm3glGetCompressedTexImage = 0;

static void Init_GL_VERSION_1_3 ()
{
    Wm3NumFunctions_GL_VERSION_1_3 = 0;

    Wm3glActiveTexture = (pfn_glActiveTexture)GetFunctionPointer("glActiveTexture");
    if ( Wm3glActiveTexture )
        ++Wm3NumFunctions_GL_VERSION_1_3;

    Wm3glClientActiveTexture = (pfn_glClientActiveTexture)GetFunctionPointer("glClientActiveTexture");
    if ( Wm3glClientActiveTexture )
        ++Wm3NumFunctions_GL_VERSION_1_3;

    Wm3glMultiTexCoord1d = (pfn_glMultiTexCoord1d)GetFunctionPointer("glMultiTexCoord1d");
    if ( Wm3glMultiTexCoord1d )
        ++Wm3NumFunctions_GL_VERSION_1_3;

    Wm3glMultiTexCoord1dv = (pfn_glMultiTexCoord1dv)GetFunctionPointer("glMultiTexCoord1dv");
    if ( Wm3glMultiTexCoord1dv )
        ++Wm3NumFunctions_GL_VERSION_1_3;

    Wm3glMultiTexCoord1f = (pfn_glMultiTexCoord1f)GetFunctionPointer("glMultiTexCoord1f");
    if ( Wm3glMultiTexCoord1f )
        ++Wm3NumFunctions_GL_VERSION_1_3;

    Wm3glMultiTexCoord1fv = (pfn_glMultiTexCoord1fv)GetFunctionPointer("glMultiTexCoord1fv");
    if ( Wm3glMultiTexCoord1fv )
        ++Wm3NumFunctions_GL_VERSION_1_3;

    Wm3glMultiTexCoord1i = (pfn_glMultiTexCoord1i)GetFunctionPointer("glMultiTexCoord1i");
    if ( Wm3glMultiTexCoord1i )
        ++Wm3NumFunctions_GL_VERSION_1_3;

    Wm3glMultiTexCoord1iv = (pfn_glMultiTexCoord1iv)GetFunctionPointer("glMultiTexCoord1iv");
    if ( Wm3glMultiTexCoord1iv )
        ++Wm3NumFunctions_GL_VERSION_1_3;

    Wm3glMultiTexCoord1s = (pfn_glMultiTexCoord1s)GetFunctionPointer("glMultiTexCoord1s");
    if ( Wm3glMultiTexCoord1s )
        ++Wm3NumFunctions_GL_VERSION_1_3;

    Wm3glMultiTexCoord1sv = (pfn_glMultiTexCoord1sv)GetFunctionPointer("glMultiTexCoord1sv");
    if ( Wm3glMultiTexCoord1sv )
        ++Wm3NumFunctions_GL_VERSION_1_3;

    Wm3glMultiTexCoord2d = (pfn_glMultiTexCoord2d)GetFunctionPointer("glMultiTexCoord2d");
    if ( Wm3glMultiTexCoord2d )
        ++Wm3NumFunctions_GL_VERSION_1_3;

    Wm3glMultiTexCoord2dv = (pfn_glMultiTexCoord2dv)GetFunctionPointer("glMultiTexCoord2dv");
    if ( Wm3glMultiTexCoord2dv )
        ++Wm3NumFunctions_GL_VERSION_1_3;

    Wm3glMultiTexCoord2f = (pfn_glMultiTexCoord2f)GetFunctionPointer("glMultiTexCoord2f");
    if ( Wm3glMultiTexCoord2f )
        ++Wm3NumFunctions_GL_VERSION_1_3;

    Wm3glMultiTexCoord2fv = (pfn_glMultiTexCoord2fv)GetFunctionPointer("glMultiTexCoord2fv");
    if ( Wm3glMultiTexCoord2fv )
        ++Wm3NumFunctions_GL_VERSION_1_3;

    Wm3glMultiTexCoord2i = (pfn_glMultiTexCoord2i)GetFunctionPointer("glMultiTexCoord2i");
    if ( Wm3glMultiTexCoord2i )
        ++Wm3NumFunctions_GL_VERSION_1_3;

    Wm3glMultiTexCoord2iv = (pfn_glMultiTexCoord2iv)GetFunctionPointer("glMultiTexCoord2iv");
    if ( Wm3glMultiTexCoord2iv )
        ++Wm3NumFunctions_GL_VERSION_1_3;

    Wm3glMultiTexCoord2s = (pfn_glMultiTexCoord2s)GetFunctionPointer("glMultiTexCoord2s");
    if ( Wm3glMultiTexCoord2s )
        ++Wm3NumFunctions_GL_VERSION_1_3;

    Wm3glMultiTexCoord2sv = (pfn_glMultiTexCoord2sv)GetFunctionPointer("glMultiTexCoord2sv");
    if ( Wm3glMultiTexCoord2sv )
        ++Wm3NumFunctions_GL_VERSION_1_3;

    Wm3glMultiTexCoord3d = (pfn_glMultiTexCoord3d)GetFunctionPointer("glMultiTexCoord3d");
    if ( Wm3glMultiTexCoord3d )
        ++Wm3NumFunctions_GL_VERSION_1_3;

    Wm3glMultiTexCoord3dv = (pfn_glMultiTexCoord3dv)GetFunctionPointer("glMultiTexCoord3dv");
    if ( Wm3glMultiTexCoord3dv )
        ++Wm3NumFunctions_GL_VERSION_1_3;

    Wm3glMultiTexCoord3f = (pfn_glMultiTexCoord3f)GetFunctionPointer("glMultiTexCoord3f");
    if ( Wm3glMultiTexCoord3f )
        ++Wm3NumFunctions_GL_VERSION_1_3;

    Wm3glMultiTexCoord3fv = (pfn_glMultiTexCoord3fv)GetFunctionPointer("glMultiTexCoord3fv");
    if ( Wm3glMultiTexCoord3fv )
        ++Wm3NumFunctions_GL_VERSION_1_3;

    Wm3glMultiTexCoord3i = (pfn_glMultiTexCoord3i)GetFunctionPointer("glMultiTexCoord3i");
    if ( Wm3glMultiTexCoord3i )
        ++Wm3NumFunctions_GL_VERSION_1_3;

    Wm3glMultiTexCoord3iv = (pfn_glMultiTexCoord3iv)GetFunctionPointer("glMultiTexCoord3iv");
    if ( Wm3glMultiTexCoord3iv )
        ++Wm3NumFunctions_GL_VERSION_1_3;

    Wm3glMultiTexCoord3s = (pfn_glMultiTexCoord3s)GetFunctionPointer("glMultiTexCoord3s");
    if ( Wm3glMultiTexCoord3s )
        ++Wm3NumFunctions_GL_VERSION_1_3;

    Wm3glMultiTexCoord3sv = (pfn_glMultiTexCoord3sv)GetFunctionPointer("glMultiTexCoord3sv");
    if ( Wm3glMultiTexCoord3sv )
        ++Wm3NumFunctions_GL_VERSION_1_3;

    Wm3glMultiTexCoord4d = (pfn_glMultiTexCoord4d)GetFunctionPointer("glMultiTexCoord4d");
    if ( Wm3glMultiTexCoord4d )
        ++Wm3NumFunctions_GL_VERSION_1_3;

    Wm3glMultiTexCoord4dv = (pfn_glMultiTexCoord4dv)GetFunctionPointer("glMultiTexCoord4dv");
    if ( Wm3glMultiTexCoord4dv )
        ++Wm3NumFunctions_GL_VERSION_1_3;

    Wm3glMultiTexCoord4f = (pfn_glMultiTexCoord4f)GetFunctionPointer("glMultiTexCoord4f");
    if ( Wm3glMultiTexCoord4f )
        ++Wm3NumFunctions_GL_VERSION_1_3;

    Wm3glMultiTexCoord4fv = (pfn_glMultiTexCoord4fv)GetFunctionPointer("glMultiTexCoord4fv");
    if ( Wm3glMultiTexCoord4fv )
        ++Wm3NumFunctions_GL_VERSION_1_3;

    Wm3glMultiTexCoord4i = (pfn_glMultiTexCoord4i)GetFunctionPointer("glMultiTexCoord4i");
    if ( Wm3glMultiTexCoord4i )
        ++Wm3NumFunctions_GL_VERSION_1_3;

    Wm3glMultiTexCoord4iv = (pfn_glMultiTexCoord4iv)GetFunctionPointer("glMultiTexCoord4iv");
    if ( Wm3glMultiTexCoord4iv )
        ++Wm3NumFunctions_GL_VERSION_1_3;

    Wm3glMultiTexCoord4s = (pfn_glMultiTexCoord4s)GetFunctionPointer("glMultiTexCoord4s");
    if ( Wm3glMultiTexCoord4s )
        ++Wm3NumFunctions_GL_VERSION_1_3;

    Wm3glMultiTexCoord4sv = (pfn_glMultiTexCoord4sv)GetFunctionPointer("glMultiTexCoord4sv");
    if ( Wm3glMultiTexCoord4sv )
        ++Wm3NumFunctions_GL_VERSION_1_3;

    Wm3glLoadTransposeMatrixf = (pfn_glLoadTransposeMatrixf)GetFunctionPointer("glLoadTransposeMatrixf");
    if ( Wm3glLoadTransposeMatrixf )
        ++Wm3NumFunctions_GL_VERSION_1_3;

    Wm3glLoadTransposeMatrixd = (pfn_glLoadTransposeMatrixd)GetFunctionPointer("glLoadTransposeMatrixd");
    if ( Wm3glLoadTransposeMatrixd )
        ++Wm3NumFunctions_GL_VERSION_1_3;

    Wm3glMultTransposeMatrixf = (pfn_glMultTransposeMatrixf)GetFunctionPointer("glMultTransposeMatrixf");
    if ( Wm3glMultTransposeMatrixf )
        ++Wm3NumFunctions_GL_VERSION_1_3;

    Wm3glMultTransposeMatrixd = (pfn_glMultTransposeMatrixd)GetFunctionPointer("glMultTransposeMatrixd");
    if ( Wm3glMultTransposeMatrixd )
        ++Wm3NumFunctions_GL_VERSION_1_3;

    Wm3glSampleCoverage = (pfn_glSampleCoverage)GetFunctionPointer("glSampleCoverage");
    if ( Wm3glSampleCoverage )
        ++Wm3NumFunctions_GL_VERSION_1_3;

    Wm3glCompressedTexImage3D = (pfn_glCompressedTexImage3D)GetFunctionPointer("glCompressedTexImage3D");
    if ( Wm3glCompressedTexImage3D )
        ++Wm3NumFunctions_GL_VERSION_1_3;

    Wm3glCompressedTexImage2D = (pfn_glCompressedTexImage2D)GetFunctionPointer("glCompressedTexImage2D");
    if ( Wm3glCompressedTexImage2D )
        ++Wm3NumFunctions_GL_VERSION_1_3;

    Wm3glCompressedTexImage1D = (pfn_glCompressedTexImage1D)GetFunctionPointer("glCompressedTexImage1D");
    if ( Wm3glCompressedTexImage1D )
        ++Wm3NumFunctions_GL_VERSION_1_3;

    Wm3glCompressedTexSubImage3D = (pfn_glCompressedTexSubImage3D)GetFunctionPointer("glCompressedTexSubImage3D");
    if ( Wm3glCompressedTexSubImage3D )
        ++Wm3NumFunctions_GL_VERSION_1_3;

    Wm3glCompressedTexSubImage2D = (pfn_glCompressedTexSubImage2D)GetFunctionPointer("glCompressedTexSubImage2D");
    if ( Wm3glCompressedTexSubImage2D )
        ++Wm3NumFunctions_GL_VERSION_1_3;

    Wm3glCompressedTexSubImage1D = (pfn_glCompressedTexSubImage1D)GetFunctionPointer("glCompressedTexSubImage1D");
    if ( Wm3glCompressedTexSubImage1D )
        ++Wm3NumFunctions_GL_VERSION_1_3;

    Wm3glGetCompressedTexImage = (pfn_glGetCompressedTexImage)GetFunctionPointer("glGetCompressedTexImage");
    if ( Wm3glGetCompressedTexImage )
        ++Wm3NumFunctions_GL_VERSION_1_3;

    if ( Wm3NumFunctions_GL_VERSION_1_3 == 46 )
        Wm3Exists_GL_VERSION_1_3 = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_VERSION_1_3 = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_VERSION_1_3 ()
{
    Wm3NumFunctions_GL_VERSION_1_3 = 0;
    Wm3Exists_GL_VERSION_1_3 = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_VERSION_1_4;
int Wm3NumFunctions_GL_VERSION_1_4;
#ifdef WM3_DEFINED_GL_VERSION_1_4
pfn_glBlendFuncSeparate Wm3glBlendFuncSeparate = 0;
pfn_glFogCoordf Wm3glFogCoordf = 0;
pfn_glFogCoordfv Wm3glFogCoordfv = 0;
pfn_glFogCoordd Wm3glFogCoordd = 0;
pfn_glFogCoorddv Wm3glFogCoorddv = 0;
pfn_glFogCoordPointer Wm3glFogCoordPointer = 0;
pfn_glMultiDrawArrays Wm3glMultiDrawArrays = 0;
pfn_glMultiDrawElements Wm3glMultiDrawElements = 0;
pfn_glPointParameterf Wm3glPointParameterf = 0;
pfn_glPointParameterfv Wm3glPointParameterfv = 0;
pfn_glPointParameteri Wm3glPointParameteri = 0;
pfn_glPointParameteriv Wm3glPointParameteriv = 0;
pfn_glSecondaryColor3b Wm3glSecondaryColor3b = 0;
pfn_glSecondaryColor3bv Wm3glSecondaryColor3bv = 0;
pfn_glSecondaryColor3d Wm3glSecondaryColor3d = 0;
pfn_glSecondaryColor3dv Wm3glSecondaryColor3dv = 0;
pfn_glSecondaryColor3f Wm3glSecondaryColor3f = 0;
pfn_glSecondaryColor3fv Wm3glSecondaryColor3fv = 0;
pfn_glSecondaryColor3i Wm3glSecondaryColor3i = 0;
pfn_glSecondaryColor3iv Wm3glSecondaryColor3iv = 0;
pfn_glSecondaryColor3s Wm3glSecondaryColor3s = 0;
pfn_glSecondaryColor3sv Wm3glSecondaryColor3sv = 0;
pfn_glSecondaryColor3ub Wm3glSecondaryColor3ub = 0;
pfn_glSecondaryColor3ubv Wm3glSecondaryColor3ubv = 0;
pfn_glSecondaryColor3ui Wm3glSecondaryColor3ui = 0;
pfn_glSecondaryColor3uiv Wm3glSecondaryColor3uiv = 0;
pfn_glSecondaryColor3us Wm3glSecondaryColor3us = 0;
pfn_glSecondaryColor3usv Wm3glSecondaryColor3usv = 0;
pfn_glSecondaryColorPointer Wm3glSecondaryColorPointer = 0;
pfn_glWindowPos2d Wm3glWindowPos2d = 0;
pfn_glWindowPos2dv Wm3glWindowPos2dv = 0;
pfn_glWindowPos2f Wm3glWindowPos2f = 0;
pfn_glWindowPos2fv Wm3glWindowPos2fv = 0;
pfn_glWindowPos2i Wm3glWindowPos2i = 0;
pfn_glWindowPos2iv Wm3glWindowPos2iv = 0;
pfn_glWindowPos2s Wm3glWindowPos2s = 0;
pfn_glWindowPos2sv Wm3glWindowPos2sv = 0;
pfn_glWindowPos3d Wm3glWindowPos3d = 0;
pfn_glWindowPos3dv Wm3glWindowPos3dv = 0;
pfn_glWindowPos3f Wm3glWindowPos3f = 0;
pfn_glWindowPos3fv Wm3glWindowPos3fv = 0;
pfn_glWindowPos3i Wm3glWindowPos3i = 0;
pfn_glWindowPos3iv Wm3glWindowPos3iv = 0;
pfn_glWindowPos3s Wm3glWindowPos3s = 0;
pfn_glWindowPos3sv Wm3glWindowPos3sv = 0;

static void Init_GL_VERSION_1_4 ()
{
    Wm3NumFunctions_GL_VERSION_1_4 = 0;

    Wm3glBlendFuncSeparate = (pfn_glBlendFuncSeparate)GetFunctionPointer("glBlendFuncSeparate");
    if ( Wm3glBlendFuncSeparate )
        ++Wm3NumFunctions_GL_VERSION_1_4;

    Wm3glFogCoordf = (pfn_glFogCoordf)GetFunctionPointer("glFogCoordf");
    if ( Wm3glFogCoordf )
        ++Wm3NumFunctions_GL_VERSION_1_4;

    Wm3glFogCoordfv = (pfn_glFogCoordfv)GetFunctionPointer("glFogCoordfv");
    if ( Wm3glFogCoordfv )
        ++Wm3NumFunctions_GL_VERSION_1_4;

    Wm3glFogCoordd = (pfn_glFogCoordd)GetFunctionPointer("glFogCoordd");
    if ( Wm3glFogCoordd )
        ++Wm3NumFunctions_GL_VERSION_1_4;

    Wm3glFogCoorddv = (pfn_glFogCoorddv)GetFunctionPointer("glFogCoorddv");
    if ( Wm3glFogCoorddv )
        ++Wm3NumFunctions_GL_VERSION_1_4;

    Wm3glFogCoordPointer = (pfn_glFogCoordPointer)GetFunctionPointer("glFogCoordPointer");
    if ( Wm3glFogCoordPointer )
        ++Wm3NumFunctions_GL_VERSION_1_4;

    Wm3glMultiDrawArrays = (pfn_glMultiDrawArrays)GetFunctionPointer("glMultiDrawArrays");
    if ( Wm3glMultiDrawArrays )
        ++Wm3NumFunctions_GL_VERSION_1_4;

    Wm3glMultiDrawElements = (pfn_glMultiDrawElements)GetFunctionPointer("glMultiDrawElements");
    if ( Wm3glMultiDrawElements )
        ++Wm3NumFunctions_GL_VERSION_1_4;

    Wm3glPointParameterf = (pfn_glPointParameterf)GetFunctionPointer("glPointParameterf");
    if ( Wm3glPointParameterf )
        ++Wm3NumFunctions_GL_VERSION_1_4;

    Wm3glPointParameterfv = (pfn_glPointParameterfv)GetFunctionPointer("glPointParameterfv");
    if ( Wm3glPointParameterfv )
        ++Wm3NumFunctions_GL_VERSION_1_4;

    Wm3glPointParameteri = (pfn_glPointParameteri)GetFunctionPointer("glPointParameteri");
    if ( Wm3glPointParameteri )
        ++Wm3NumFunctions_GL_VERSION_1_4;

    Wm3glPointParameteriv = (pfn_glPointParameteriv)GetFunctionPointer("glPointParameteriv");
    if ( Wm3glPointParameteriv )
        ++Wm3NumFunctions_GL_VERSION_1_4;

    Wm3glSecondaryColor3b = (pfn_glSecondaryColor3b)GetFunctionPointer("glSecondaryColor3b");
    if ( Wm3glSecondaryColor3b )
        ++Wm3NumFunctions_GL_VERSION_1_4;

    Wm3glSecondaryColor3bv = (pfn_glSecondaryColor3bv)GetFunctionPointer("glSecondaryColor3bv");
    if ( Wm3glSecondaryColor3bv )
        ++Wm3NumFunctions_GL_VERSION_1_4;

    Wm3glSecondaryColor3d = (pfn_glSecondaryColor3d)GetFunctionPointer("glSecondaryColor3d");
    if ( Wm3glSecondaryColor3d )
        ++Wm3NumFunctions_GL_VERSION_1_4;

    Wm3glSecondaryColor3dv = (pfn_glSecondaryColor3dv)GetFunctionPointer("glSecondaryColor3dv");
    if ( Wm3glSecondaryColor3dv )
        ++Wm3NumFunctions_GL_VERSION_1_4;

    Wm3glSecondaryColor3f = (pfn_glSecondaryColor3f)GetFunctionPointer("glSecondaryColor3f");
    if ( Wm3glSecondaryColor3f )
        ++Wm3NumFunctions_GL_VERSION_1_4;

    Wm3glSecondaryColor3fv = (pfn_glSecondaryColor3fv)GetFunctionPointer("glSecondaryColor3fv");
    if ( Wm3glSecondaryColor3fv )
        ++Wm3NumFunctions_GL_VERSION_1_4;

    Wm3glSecondaryColor3i = (pfn_glSecondaryColor3i)GetFunctionPointer("glSecondaryColor3i");
    if ( Wm3glSecondaryColor3i )
        ++Wm3NumFunctions_GL_VERSION_1_4;

    Wm3glSecondaryColor3iv = (pfn_glSecondaryColor3iv)GetFunctionPointer("glSecondaryColor3iv");
    if ( Wm3glSecondaryColor3iv )
        ++Wm3NumFunctions_GL_VERSION_1_4;

    Wm3glSecondaryColor3s = (pfn_glSecondaryColor3s)GetFunctionPointer("glSecondaryColor3s");
    if ( Wm3glSecondaryColor3s )
        ++Wm3NumFunctions_GL_VERSION_1_4;

    Wm3glSecondaryColor3sv = (pfn_glSecondaryColor3sv)GetFunctionPointer("glSecondaryColor3sv");
    if ( Wm3glSecondaryColor3sv )
        ++Wm3NumFunctions_GL_VERSION_1_4;

    Wm3glSecondaryColor3ub = (pfn_glSecondaryColor3ub)GetFunctionPointer("glSecondaryColor3ub");
    if ( Wm3glSecondaryColor3ub )
        ++Wm3NumFunctions_GL_VERSION_1_4;

    Wm3glSecondaryColor3ubv = (pfn_glSecondaryColor3ubv)GetFunctionPointer("glSecondaryColor3ubv");
    if ( Wm3glSecondaryColor3ubv )
        ++Wm3NumFunctions_GL_VERSION_1_4;

    Wm3glSecondaryColor3ui = (pfn_glSecondaryColor3ui)GetFunctionPointer("glSecondaryColor3ui");
    if ( Wm3glSecondaryColor3ui )
        ++Wm3NumFunctions_GL_VERSION_1_4;

    Wm3glSecondaryColor3uiv = (pfn_glSecondaryColor3uiv)GetFunctionPointer("glSecondaryColor3uiv");
    if ( Wm3glSecondaryColor3uiv )
        ++Wm3NumFunctions_GL_VERSION_1_4;

    Wm3glSecondaryColor3us = (pfn_glSecondaryColor3us)GetFunctionPointer("glSecondaryColor3us");
    if ( Wm3glSecondaryColor3us )
        ++Wm3NumFunctions_GL_VERSION_1_4;

    Wm3glSecondaryColor3usv = (pfn_glSecondaryColor3usv)GetFunctionPointer("glSecondaryColor3usv");
    if ( Wm3glSecondaryColor3usv )
        ++Wm3NumFunctions_GL_VERSION_1_4;

    Wm3glSecondaryColorPointer = (pfn_glSecondaryColorPointer)GetFunctionPointer("glSecondaryColorPointer");
    if ( Wm3glSecondaryColorPointer )
        ++Wm3NumFunctions_GL_VERSION_1_4;

    Wm3glWindowPos2d = (pfn_glWindowPos2d)GetFunctionPointer("glWindowPos2d");
    if ( Wm3glWindowPos2d )
        ++Wm3NumFunctions_GL_VERSION_1_4;

    Wm3glWindowPos2dv = (pfn_glWindowPos2dv)GetFunctionPointer("glWindowPos2dv");
    if ( Wm3glWindowPos2dv )
        ++Wm3NumFunctions_GL_VERSION_1_4;

    Wm3glWindowPos2f = (pfn_glWindowPos2f)GetFunctionPointer("glWindowPos2f");
    if ( Wm3glWindowPos2f )
        ++Wm3NumFunctions_GL_VERSION_1_4;

    Wm3glWindowPos2fv = (pfn_glWindowPos2fv)GetFunctionPointer("glWindowPos2fv");
    if ( Wm3glWindowPos2fv )
        ++Wm3NumFunctions_GL_VERSION_1_4;

    Wm3glWindowPos2i = (pfn_glWindowPos2i)GetFunctionPointer("glWindowPos2i");
    if ( Wm3glWindowPos2i )
        ++Wm3NumFunctions_GL_VERSION_1_4;

    Wm3glWindowPos2iv = (pfn_glWindowPos2iv)GetFunctionPointer("glWindowPos2iv");
    if ( Wm3glWindowPos2iv )
        ++Wm3NumFunctions_GL_VERSION_1_4;

    Wm3glWindowPos2s = (pfn_glWindowPos2s)GetFunctionPointer("glWindowPos2s");
    if ( Wm3glWindowPos2s )
        ++Wm3NumFunctions_GL_VERSION_1_4;

    Wm3glWindowPos2sv = (pfn_glWindowPos2sv)GetFunctionPointer("glWindowPos2sv");
    if ( Wm3glWindowPos2sv )
        ++Wm3NumFunctions_GL_VERSION_1_4;

    Wm3glWindowPos3d = (pfn_glWindowPos3d)GetFunctionPointer("glWindowPos3d");
    if ( Wm3glWindowPos3d )
        ++Wm3NumFunctions_GL_VERSION_1_4;

    Wm3glWindowPos3dv = (pfn_glWindowPos3dv)GetFunctionPointer("glWindowPos3dv");
    if ( Wm3glWindowPos3dv )
        ++Wm3NumFunctions_GL_VERSION_1_4;

    Wm3glWindowPos3f = (pfn_glWindowPos3f)GetFunctionPointer("glWindowPos3f");
    if ( Wm3glWindowPos3f )
        ++Wm3NumFunctions_GL_VERSION_1_4;

    Wm3glWindowPos3fv = (pfn_glWindowPos3fv)GetFunctionPointer("glWindowPos3fv");
    if ( Wm3glWindowPos3fv )
        ++Wm3NumFunctions_GL_VERSION_1_4;

    Wm3glWindowPos3i = (pfn_glWindowPos3i)GetFunctionPointer("glWindowPos3i");
    if ( Wm3glWindowPos3i )
        ++Wm3NumFunctions_GL_VERSION_1_4;

    Wm3glWindowPos3iv = (pfn_glWindowPos3iv)GetFunctionPointer("glWindowPos3iv");
    if ( Wm3glWindowPos3iv )
        ++Wm3NumFunctions_GL_VERSION_1_4;

    Wm3glWindowPos3s = (pfn_glWindowPos3s)GetFunctionPointer("glWindowPos3s");
    if ( Wm3glWindowPos3s )
        ++Wm3NumFunctions_GL_VERSION_1_4;

    Wm3glWindowPos3sv = (pfn_glWindowPos3sv)GetFunctionPointer("glWindowPos3sv");
    if ( Wm3glWindowPos3sv )
        ++Wm3NumFunctions_GL_VERSION_1_4;

    if ( Wm3NumFunctions_GL_VERSION_1_4 == 45 )
        Wm3Exists_GL_VERSION_1_4 = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_VERSION_1_4 = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_VERSION_1_4 ()
{
    Wm3NumFunctions_GL_VERSION_1_4 = 0;
    Wm3Exists_GL_VERSION_1_4 = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_VERSION_1_5;
int Wm3NumFunctions_GL_VERSION_1_5;
#ifdef WM3_DEFINED_GL_VERSION_1_5
pfn_glGenQueries Wm3glGenQueries = 0;
pfn_glDeleteQueries Wm3glDeleteQueries = 0;
pfn_glIsQuery Wm3glIsQuery = 0;
pfn_glBeginQuery Wm3glBeginQuery = 0;
pfn_glEndQuery Wm3glEndQuery = 0;
pfn_glGetQueryiv Wm3glGetQueryiv = 0;
pfn_glGetQueryObjectiv Wm3glGetQueryObjectiv = 0;
pfn_glGetQueryObjectuiv Wm3glGetQueryObjectuiv = 0;
pfn_glBindBuffer Wm3glBindBuffer = 0;
pfn_glDeleteBuffers Wm3glDeleteBuffers = 0;
pfn_glGenBuffers Wm3glGenBuffers = 0;
pfn_glIsBuffer Wm3glIsBuffer = 0;
pfn_glBufferData Wm3glBufferData = 0;
pfn_glBufferSubData Wm3glBufferSubData = 0;
pfn_glGetBufferSubData Wm3glGetBufferSubData = 0;
pfn_glMapBuffer Wm3glMapBuffer = 0;
pfn_glUnmapBuffer Wm3glUnmapBuffer = 0;
pfn_glGetBufferParameteriv Wm3glGetBufferParameteriv = 0;
pfn_glGetBufferPointerv Wm3glGetBufferPointerv = 0;

static void Init_GL_VERSION_1_5 ()
{
    Wm3NumFunctions_GL_VERSION_1_5 = 0;

    Wm3glGenQueries = (pfn_glGenQueries)GetFunctionPointer("glGenQueries");
    if ( Wm3glGenQueries )
        ++Wm3NumFunctions_GL_VERSION_1_5;

    Wm3glDeleteQueries = (pfn_glDeleteQueries)GetFunctionPointer("glDeleteQueries");
    if ( Wm3glDeleteQueries )
        ++Wm3NumFunctions_GL_VERSION_1_5;

    Wm3glIsQuery = (pfn_glIsQuery)GetFunctionPointer("glIsQuery");
    if ( Wm3glIsQuery )
        ++Wm3NumFunctions_GL_VERSION_1_5;

    Wm3glBeginQuery = (pfn_glBeginQuery)GetFunctionPointer("glBeginQuery");
    if ( Wm3glBeginQuery )
        ++Wm3NumFunctions_GL_VERSION_1_5;

    Wm3glEndQuery = (pfn_glEndQuery)GetFunctionPointer("glEndQuery");
    if ( Wm3glEndQuery )
        ++Wm3NumFunctions_GL_VERSION_1_5;

    Wm3glGetQueryiv = (pfn_glGetQueryiv)GetFunctionPointer("glGetQueryiv");
    if ( Wm3glGetQueryiv )
        ++Wm3NumFunctions_GL_VERSION_1_5;

    Wm3glGetQueryObjectiv = (pfn_glGetQueryObjectiv)GetFunctionPointer("glGetQueryObjectiv");
    if ( Wm3glGetQueryObjectiv )
        ++Wm3NumFunctions_GL_VERSION_1_5;

    Wm3glGetQueryObjectuiv = (pfn_glGetQueryObjectuiv)GetFunctionPointer("glGetQueryObjectuiv");
    if ( Wm3glGetQueryObjectuiv )
        ++Wm3NumFunctions_GL_VERSION_1_5;

    Wm3glBindBuffer = (pfn_glBindBuffer)GetFunctionPointer("glBindBuffer");
    if ( Wm3glBindBuffer )
        ++Wm3NumFunctions_GL_VERSION_1_5;

    Wm3glDeleteBuffers = (pfn_glDeleteBuffers)GetFunctionPointer("glDeleteBuffers");
    if ( Wm3glDeleteBuffers )
        ++Wm3NumFunctions_GL_VERSION_1_5;

    Wm3glGenBuffers = (pfn_glGenBuffers)GetFunctionPointer("glGenBuffers");
    if ( Wm3glGenBuffers )
        ++Wm3NumFunctions_GL_VERSION_1_5;

    Wm3glIsBuffer = (pfn_glIsBuffer)GetFunctionPointer("glIsBuffer");
    if ( Wm3glIsBuffer )
        ++Wm3NumFunctions_GL_VERSION_1_5;

    Wm3glBufferData = (pfn_glBufferData)GetFunctionPointer("glBufferData");
    if ( Wm3glBufferData )
        ++Wm3NumFunctions_GL_VERSION_1_5;

    Wm3glBufferSubData = (pfn_glBufferSubData)GetFunctionPointer("glBufferSubData");
    if ( Wm3glBufferSubData )
        ++Wm3NumFunctions_GL_VERSION_1_5;

    Wm3glGetBufferSubData = (pfn_glGetBufferSubData)GetFunctionPointer("glGetBufferSubData");
    if ( Wm3glGetBufferSubData )
        ++Wm3NumFunctions_GL_VERSION_1_5;

    Wm3glMapBuffer = (pfn_glMapBuffer)GetFunctionPointer("glMapBuffer");
    if ( Wm3glMapBuffer )
        ++Wm3NumFunctions_GL_VERSION_1_5;

    Wm3glUnmapBuffer = (pfn_glUnmapBuffer)GetFunctionPointer("glUnmapBuffer");
    if ( Wm3glUnmapBuffer )
        ++Wm3NumFunctions_GL_VERSION_1_5;

    Wm3glGetBufferParameteriv = (pfn_glGetBufferParameteriv)GetFunctionPointer("glGetBufferParameteriv");
    if ( Wm3glGetBufferParameteriv )
        ++Wm3NumFunctions_GL_VERSION_1_5;

    Wm3glGetBufferPointerv = (pfn_glGetBufferPointerv)GetFunctionPointer("glGetBufferPointerv");
    if ( Wm3glGetBufferPointerv )
        ++Wm3NumFunctions_GL_VERSION_1_5;

    if ( Wm3NumFunctions_GL_VERSION_1_5 == 19 )
        Wm3Exists_GL_VERSION_1_5 = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_VERSION_1_5 = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_VERSION_1_5 ()
{
    Wm3NumFunctions_GL_VERSION_1_5 = 0;
    Wm3Exists_GL_VERSION_1_5 = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_VERSION_2_0;
int Wm3NumFunctions_GL_VERSION_2_0;
#ifdef WM3_DEFINED_GL_VERSION_2_0
pfn_glBlendEquationSeparate Wm3glBlendEquationSeparate = 0;
pfn_glDrawBuffers Wm3glDrawBuffers = 0;
pfn_glStencilOpSeparate Wm3glStencilOpSeparate = 0;
pfn_glStencilFuncSeparate Wm3glStencilFuncSeparate = 0;
pfn_glStencilMaskSeparate Wm3glStencilMaskSeparate = 0;
pfn_glAttachShader Wm3glAttachShader = 0;
pfn_glBindAttribLocation Wm3glBindAttribLocation = 0;
pfn_glCompileShader Wm3glCompileShader = 0;
pfn_glCreateProgram Wm3glCreateProgram = 0;
pfn_glCreateShader Wm3glCreateShader = 0;
pfn_glDeleteProgram Wm3glDeleteProgram = 0;
pfn_glDeleteShader Wm3glDeleteShader = 0;
pfn_glDetachShader Wm3glDetachShader = 0;
pfn_glDisableVertexAttribArray Wm3glDisableVertexAttribArray = 0;
pfn_glEnableVertexAttribArray Wm3glEnableVertexAttribArray = 0;
pfn_glGetActiveAttrib Wm3glGetActiveAttrib = 0;
pfn_glGetActiveUniform Wm3glGetActiveUniform = 0;
pfn_glGetAttachedShaders Wm3glGetAttachedShaders = 0;
pfn_glGetAttribLocation Wm3glGetAttribLocation = 0;
pfn_glGetProgramiv Wm3glGetProgramiv = 0;
pfn_glGetProgramInfoLog Wm3glGetProgramInfoLog = 0;
pfn_glGetShaderiv Wm3glGetShaderiv = 0;
pfn_glGetShaderInfoLog Wm3glGetShaderInfoLog = 0;
pfn_glGetShaderSource Wm3glGetShaderSource = 0;
pfn_glGetUniformLocation Wm3glGetUniformLocation = 0;
pfn_glGetUniformfv Wm3glGetUniformfv = 0;
pfn_glGetUniformiv Wm3glGetUniformiv = 0;
pfn_glGetVertexAttribdv Wm3glGetVertexAttribdv = 0;
pfn_glGetVertexAttribfv Wm3glGetVertexAttribfv = 0;
pfn_glGetVertexAttribiv Wm3glGetVertexAttribiv = 0;
pfn_glGetVertexAttribPointerv Wm3glGetVertexAttribPointerv = 0;
pfn_glIsProgram Wm3glIsProgram = 0;
pfn_glIsShader Wm3glIsShader = 0;
pfn_glLinkProgram Wm3glLinkProgram = 0;
pfn_glShaderSource Wm3glShaderSource = 0;
pfn_glUseProgram Wm3glUseProgram = 0;
pfn_glUniform1f Wm3glUniform1f = 0;
pfn_glUniform2f Wm3glUniform2f = 0;
pfn_glUniform3f Wm3glUniform3f = 0;
pfn_glUniform4f Wm3glUniform4f = 0;
pfn_glUniform1i Wm3glUniform1i = 0;
pfn_glUniform2i Wm3glUniform2i = 0;
pfn_glUniform3i Wm3glUniform3i = 0;
pfn_glUniform4i Wm3glUniform4i = 0;
pfn_glUniform1fv Wm3glUniform1fv = 0;
pfn_glUniform2fv Wm3glUniform2fv = 0;
pfn_glUniform3fv Wm3glUniform3fv = 0;
pfn_glUniform4fv Wm3glUniform4fv = 0;
pfn_glUniform1iv Wm3glUniform1iv = 0;
pfn_glUniform2iv Wm3glUniform2iv = 0;
pfn_glUniform3iv Wm3glUniform3iv = 0;
pfn_glUniform4iv Wm3glUniform4iv = 0;
pfn_glUniformMatrix2fv Wm3glUniformMatrix2fv = 0;
pfn_glUniformMatrix3fv Wm3glUniformMatrix3fv = 0;
pfn_glUniformMatrix4fv Wm3glUniformMatrix4fv = 0;
pfn_glValidateProgram Wm3glValidateProgram = 0;
pfn_glVertexAttrib1d Wm3glVertexAttrib1d = 0;
pfn_glVertexAttrib1dv Wm3glVertexAttrib1dv = 0;
pfn_glVertexAttrib1f Wm3glVertexAttrib1f = 0;
pfn_glVertexAttrib1fv Wm3glVertexAttrib1fv = 0;
pfn_glVertexAttrib1s Wm3glVertexAttrib1s = 0;
pfn_glVertexAttrib1sv Wm3glVertexAttrib1sv = 0;
pfn_glVertexAttrib2d Wm3glVertexAttrib2d = 0;
pfn_glVertexAttrib2dv Wm3glVertexAttrib2dv = 0;
pfn_glVertexAttrib2f Wm3glVertexAttrib2f = 0;
pfn_glVertexAttrib2fv Wm3glVertexAttrib2fv = 0;
pfn_glVertexAttrib2s Wm3glVertexAttrib2s = 0;
pfn_glVertexAttrib2sv Wm3glVertexAttrib2sv = 0;
pfn_glVertexAttrib3d Wm3glVertexAttrib3d = 0;
pfn_glVertexAttrib3dv Wm3glVertexAttrib3dv = 0;
pfn_glVertexAttrib3f Wm3glVertexAttrib3f = 0;
pfn_glVertexAttrib3fv Wm3glVertexAttrib3fv = 0;
pfn_glVertexAttrib3s Wm3glVertexAttrib3s = 0;
pfn_glVertexAttrib3sv Wm3glVertexAttrib3sv = 0;
pfn_glVertexAttrib4Nbv Wm3glVertexAttrib4Nbv = 0;
pfn_glVertexAttrib4Niv Wm3glVertexAttrib4Niv = 0;
pfn_glVertexAttrib4Nsv Wm3glVertexAttrib4Nsv = 0;
pfn_glVertexAttrib4Nub Wm3glVertexAttrib4Nub = 0;
pfn_glVertexAttrib4Nubv Wm3glVertexAttrib4Nubv = 0;
pfn_glVertexAttrib4Nuiv Wm3glVertexAttrib4Nuiv = 0;
pfn_glVertexAttrib4Nusv Wm3glVertexAttrib4Nusv = 0;
pfn_glVertexAttrib4bv Wm3glVertexAttrib4bv = 0;
pfn_glVertexAttrib4d Wm3glVertexAttrib4d = 0;
pfn_glVertexAttrib4dv Wm3glVertexAttrib4dv = 0;
pfn_glVertexAttrib4f Wm3glVertexAttrib4f = 0;
pfn_glVertexAttrib4fv Wm3glVertexAttrib4fv = 0;
pfn_glVertexAttrib4iv Wm3glVertexAttrib4iv = 0;
pfn_glVertexAttrib4s Wm3glVertexAttrib4s = 0;
pfn_glVertexAttrib4sv Wm3glVertexAttrib4sv = 0;
pfn_glVertexAttrib4ubv Wm3glVertexAttrib4ubv = 0;
pfn_glVertexAttrib4uiv Wm3glVertexAttrib4uiv = 0;
pfn_glVertexAttrib4usv Wm3glVertexAttrib4usv = 0;
pfn_glVertexAttribPointer Wm3glVertexAttribPointer = 0;

static void Init_GL_VERSION_2_0 ()
{
    Wm3NumFunctions_GL_VERSION_2_0 = 0;

    Wm3glBlendEquationSeparate = (pfn_glBlendEquationSeparate)GetFunctionPointer("glBlendEquationSeparate");
    if ( Wm3glBlendEquationSeparate )
        ++Wm3NumFunctions_GL_VERSION_2_0;

    Wm3glDrawBuffers = (pfn_glDrawBuffers)GetFunctionPointer("glDrawBuffers");
    if ( Wm3glDrawBuffers )
        ++Wm3NumFunctions_GL_VERSION_2_0;

    Wm3glStencilOpSeparate = (pfn_glStencilOpSeparate)GetFunctionPointer("glStencilOpSeparate");
    if ( Wm3glStencilOpSeparate )
        ++Wm3NumFunctions_GL_VERSION_2_0;

    Wm3glStencilFuncSeparate = (pfn_glStencilFuncSeparate)GetFunctionPointer("glStencilFuncSeparate");
    if ( Wm3glStencilFuncSeparate )
        ++Wm3NumFunctions_GL_VERSION_2_0;

    Wm3glStencilMaskSeparate = (pfn_glStencilMaskSeparate)GetFunctionPointer("glStencilMaskSeparate");
    if ( Wm3glStencilMaskSeparate )
        ++Wm3NumFunctions_GL_VERSION_2_0;

    Wm3glAttachShader = (pfn_glAttachShader)GetFunctionPointer("glAttachShader");
    if ( Wm3glAttachShader )
        ++Wm3NumFunctions_GL_VERSION_2_0;

    Wm3glBindAttribLocation = (pfn_glBindAttribLocation)GetFunctionPointer("glBindAttribLocation");
    if ( Wm3glBindAttribLocation )
        ++Wm3NumFunctions_GL_VERSION_2_0;

    Wm3glCompileShader = (pfn_glCompileShader)GetFunctionPointer("glCompileShader");
    if ( Wm3glCompileShader )
        ++Wm3NumFunctions_GL_VERSION_2_0;

    Wm3glCreateProgram = (pfn_glCreateProgram)GetFunctionPointer("glCreateProgram");
    if ( Wm3glCreateProgram )
        ++Wm3NumFunctions_GL_VERSION_2_0;

    Wm3glCreateShader = (pfn_glCreateShader)GetFunctionPointer("glCreateShader");
    if ( Wm3glCreateShader )
        ++Wm3NumFunctions_GL_VERSION_2_0;

    Wm3glDeleteProgram = (pfn_glDeleteProgram)GetFunctionPointer("glDeleteProgram");
    if ( Wm3glDeleteProgram )
        ++Wm3NumFunctions_GL_VERSION_2_0;

    Wm3glDeleteShader = (pfn_glDeleteShader)GetFunctionPointer("glDeleteShader");
    if ( Wm3glDeleteShader )
        ++Wm3NumFunctions_GL_VERSION_2_0;

    Wm3glDetachShader = (pfn_glDetachShader)GetFunctionPointer("glDetachShader");
    if ( Wm3glDetachShader )
        ++Wm3NumFunctions_GL_VERSION_2_0;

    Wm3glDisableVertexAttribArray = (pfn_glDisableVertexAttribArray)GetFunctionPointer("glDisableVertexAttribArray");
    if ( Wm3glDisableVertexAttribArray )
        ++Wm3NumFunctions_GL_VERSION_2_0;

    Wm3glEnableVertexAttribArray = (pfn_glEnableVertexAttribArray)GetFunctionPointer("glEnableVertexAttribArray");
    if ( Wm3glEnableVertexAttribArray )
        ++Wm3NumFunctions_GL_VERSION_2_0;

    Wm3glGetActiveAttrib = (pfn_glGetActiveAttrib)GetFunctionPointer("glGetActiveAttrib");
    if ( Wm3glGetActiveAttrib )
        ++Wm3NumFunctions_GL_VERSION_2_0;

    Wm3glGetActiveUniform = (pfn_glGetActiveUniform)GetFunctionPointer("glGetActiveUniform");
    if ( Wm3glGetActiveUniform )
        ++Wm3NumFunctions_GL_VERSION_2_0;

    Wm3glGetAttachedShaders = (pfn_glGetAttachedShaders)GetFunctionPointer("glGetAttachedShaders");
    if ( Wm3glGetAttachedShaders )
        ++Wm3NumFunctions_GL_VERSION_2_0;

    Wm3glGetAttribLocation = (pfn_glGetAttribLocation)GetFunctionPointer("glGetAttribLocation");
    if ( Wm3glGetAttribLocation )
        ++Wm3NumFunctions_GL_VERSION_2_0;

    Wm3glGetProgramiv = (pfn_glGetProgramiv)GetFunctionPointer("glGetProgramiv");
    if ( Wm3glGetProgramiv )
        ++Wm3NumFunctions_GL_VERSION_2_0;

    Wm3glGetProgramInfoLog = (pfn_glGetProgramInfoLog)GetFunctionPointer("glGetProgramInfoLog");
    if ( Wm3glGetProgramInfoLog )
        ++Wm3NumFunctions_GL_VERSION_2_0;

    Wm3glGetShaderiv = (pfn_glGetShaderiv)GetFunctionPointer("glGetShaderiv");
    if ( Wm3glGetShaderiv )
        ++Wm3NumFunctions_GL_VERSION_2_0;

    Wm3glGetShaderInfoLog = (pfn_glGetShaderInfoLog)GetFunctionPointer("glGetShaderInfoLog");
    if ( Wm3glGetShaderInfoLog )
        ++Wm3NumFunctions_GL_VERSION_2_0;

    Wm3glGetShaderSource = (pfn_glGetShaderSource)GetFunctionPointer("glGetShaderSource");
    if ( Wm3glGetShaderSource )
        ++Wm3NumFunctions_GL_VERSION_2_0;

    Wm3glGetUniformLocation = (pfn_glGetUniformLocation)GetFunctionPointer("glGetUniformLocation");
    if ( Wm3glGetUniformLocation )
        ++Wm3NumFunctions_GL_VERSION_2_0;

    Wm3glGetUniformfv = (pfn_glGetUniformfv)GetFunctionPointer("glGetUniformfv");
    if ( Wm3glGetUniformfv )
        ++Wm3NumFunctions_GL_VERSION_2_0;

    Wm3glGetUniformiv = (pfn_glGetUniformiv)GetFunctionPointer("glGetUniformiv");
    if ( Wm3glGetUniformiv )
        ++Wm3NumFunctions_GL_VERSION_2_0;

    Wm3glGetVertexAttribdv = (pfn_glGetVertexAttribdv)GetFunctionPointer("glGetVertexAttribdv");
    if ( Wm3glGetVertexAttribdv )
        ++Wm3NumFunctions_GL_VERSION_2_0;

    Wm3glGetVertexAttribfv = (pfn_glGetVertexAttribfv)GetFunctionPointer("glGetVertexAttribfv");
    if ( Wm3glGetVertexAttribfv )
        ++Wm3NumFunctions_GL_VERSION_2_0;

    Wm3glGetVertexAttribiv = (pfn_glGetVertexAttribiv)GetFunctionPointer("glGetVertexAttribiv");
    if ( Wm3glGetVertexAttribiv )
        ++Wm3NumFunctions_GL_VERSION_2_0;

    Wm3glGetVertexAttribPointerv = (pfn_glGetVertexAttribPointerv)GetFunctionPointer("glGetVertexAttribPointerv");
    if ( Wm3glGetVertexAttribPointerv )
        ++Wm3NumFunctions_GL_VERSION_2_0;

    Wm3glIsProgram = (pfn_glIsProgram)GetFunctionPointer("glIsProgram");
    if ( Wm3glIsProgram )
        ++Wm3NumFunctions_GL_VERSION_2_0;

    Wm3glIsShader = (pfn_glIsShader)GetFunctionPointer("glIsShader");
    if ( Wm3glIsShader )
        ++Wm3NumFunctions_GL_VERSION_2_0;

    Wm3glLinkProgram = (pfn_glLinkProgram)GetFunctionPointer("glLinkProgram");
    if ( Wm3glLinkProgram )
        ++Wm3NumFunctions_GL_VERSION_2_0;

    Wm3glShaderSource = (pfn_glShaderSource)GetFunctionPointer("glShaderSource");
    if ( Wm3glShaderSource )
        ++Wm3NumFunctions_GL_VERSION_2_0;

    Wm3glUseProgram = (pfn_glUseProgram)GetFunctionPointer("glUseProgram");
    if ( Wm3glUseProgram )
        ++Wm3NumFunctions_GL_VERSION_2_0;

    Wm3glUniform1f = (pfn_glUniform1f)GetFunctionPointer("glUniform1f");
    if ( Wm3glUniform1f )
        ++Wm3NumFunctions_GL_VERSION_2_0;

    Wm3glUniform2f = (pfn_glUniform2f)GetFunctionPointer("glUniform2f");
    if ( Wm3glUniform2f )
        ++Wm3NumFunctions_GL_VERSION_2_0;

    Wm3glUniform3f = (pfn_glUniform3f)GetFunctionPointer("glUniform3f");
    if ( Wm3glUniform3f )
        ++Wm3NumFunctions_GL_VERSION_2_0;

    Wm3glUniform4f = (pfn_glUniform4f)GetFunctionPointer("glUniform4f");
    if ( Wm3glUniform4f )
        ++Wm3NumFunctions_GL_VERSION_2_0;

    Wm3glUniform1i = (pfn_glUniform1i)GetFunctionPointer("glUniform1i");
    if ( Wm3glUniform1i )
        ++Wm3NumFunctions_GL_VERSION_2_0;

    Wm3glUniform2i = (pfn_glUniform2i)GetFunctionPointer("glUniform2i");
    if ( Wm3glUniform2i )
        ++Wm3NumFunctions_GL_VERSION_2_0;

    Wm3glUniform3i = (pfn_glUniform3i)GetFunctionPointer("glUniform3i");
    if ( Wm3glUniform3i )
        ++Wm3NumFunctions_GL_VERSION_2_0;

    Wm3glUniform4i = (pfn_glUniform4i)GetFunctionPointer("glUniform4i");
    if ( Wm3glUniform4i )
        ++Wm3NumFunctions_GL_VERSION_2_0;

    Wm3glUniform1fv = (pfn_glUniform1fv)GetFunctionPointer("glUniform1fv");
    if ( Wm3glUniform1fv )
        ++Wm3NumFunctions_GL_VERSION_2_0;

    Wm3glUniform2fv = (pfn_glUniform2fv)GetFunctionPointer("glUniform2fv");
    if ( Wm3glUniform2fv )
        ++Wm3NumFunctions_GL_VERSION_2_0;

    Wm3glUniform3fv = (pfn_glUniform3fv)GetFunctionPointer("glUniform3fv");
    if ( Wm3glUniform3fv )
        ++Wm3NumFunctions_GL_VERSION_2_0;

    Wm3glUniform4fv = (pfn_glUniform4fv)GetFunctionPointer("glUniform4fv");
    if ( Wm3glUniform4fv )
        ++Wm3NumFunctions_GL_VERSION_2_0;

    Wm3glUniform1iv = (pfn_glUniform1iv)GetFunctionPointer("glUniform1iv");
    if ( Wm3glUniform1iv )
        ++Wm3NumFunctions_GL_VERSION_2_0;

    Wm3glUniform2iv = (pfn_glUniform2iv)GetFunctionPointer("glUniform2iv");
    if ( Wm3glUniform2iv )
        ++Wm3NumFunctions_GL_VERSION_2_0;

    Wm3glUniform3iv = (pfn_glUniform3iv)GetFunctionPointer("glUniform3iv");
    if ( Wm3glUniform3iv )
        ++Wm3NumFunctions_GL_VERSION_2_0;

    Wm3glUniform4iv = (pfn_glUniform4iv)GetFunctionPointer("glUniform4iv");
    if ( Wm3glUniform4iv )
        ++Wm3NumFunctions_GL_VERSION_2_0;

    Wm3glUniformMatrix2fv = (pfn_glUniformMatrix2fv)GetFunctionPointer("glUniformMatrix2fv");
    if ( Wm3glUniformMatrix2fv )
        ++Wm3NumFunctions_GL_VERSION_2_0;

    Wm3glUniformMatrix3fv = (pfn_glUniformMatrix3fv)GetFunctionPointer("glUniformMatrix3fv");
    if ( Wm3glUniformMatrix3fv )
        ++Wm3NumFunctions_GL_VERSION_2_0;

    Wm3glUniformMatrix4fv = (pfn_glUniformMatrix4fv)GetFunctionPointer("glUniformMatrix4fv");
    if ( Wm3glUniformMatrix4fv )
        ++Wm3NumFunctions_GL_VERSION_2_0;

    Wm3glValidateProgram = (pfn_glValidateProgram)GetFunctionPointer("glValidateProgram");
    if ( Wm3glValidateProgram )
        ++Wm3NumFunctions_GL_VERSION_2_0;

    Wm3glVertexAttrib1d = (pfn_glVertexAttrib1d)GetFunctionPointer("glVertexAttrib1d");
    if ( Wm3glVertexAttrib1d )
        ++Wm3NumFunctions_GL_VERSION_2_0;

    Wm3glVertexAttrib1dv = (pfn_glVertexAttrib1dv)GetFunctionPointer("glVertexAttrib1dv");
    if ( Wm3glVertexAttrib1dv )
        ++Wm3NumFunctions_GL_VERSION_2_0;

    Wm3glVertexAttrib1f = (pfn_glVertexAttrib1f)GetFunctionPointer("glVertexAttrib1f");
    if ( Wm3glVertexAttrib1f )
        ++Wm3NumFunctions_GL_VERSION_2_0;

    Wm3glVertexAttrib1fv = (pfn_glVertexAttrib1fv)GetFunctionPointer("glVertexAttrib1fv");
    if ( Wm3glVertexAttrib1fv )
        ++Wm3NumFunctions_GL_VERSION_2_0;

    Wm3glVertexAttrib1s = (pfn_glVertexAttrib1s)GetFunctionPointer("glVertexAttrib1s");
    if ( Wm3glVertexAttrib1s )
        ++Wm3NumFunctions_GL_VERSION_2_0;

    Wm3glVertexAttrib1sv = (pfn_glVertexAttrib1sv)GetFunctionPointer("glVertexAttrib1sv");
    if ( Wm3glVertexAttrib1sv )
        ++Wm3NumFunctions_GL_VERSION_2_0;

    Wm3glVertexAttrib2d = (pfn_glVertexAttrib2d)GetFunctionPointer("glVertexAttrib2d");
    if ( Wm3glVertexAttrib2d )
        ++Wm3NumFunctions_GL_VERSION_2_0;

    Wm3glVertexAttrib2dv = (pfn_glVertexAttrib2dv)GetFunctionPointer("glVertexAttrib2dv");
    if ( Wm3glVertexAttrib2dv )
        ++Wm3NumFunctions_GL_VERSION_2_0;

    Wm3glVertexAttrib2f = (pfn_glVertexAttrib2f)GetFunctionPointer("glVertexAttrib2f");
    if ( Wm3glVertexAttrib2f )
        ++Wm3NumFunctions_GL_VERSION_2_0;

    Wm3glVertexAttrib2fv = (pfn_glVertexAttrib2fv)GetFunctionPointer("glVertexAttrib2fv");
    if ( Wm3glVertexAttrib2fv )
        ++Wm3NumFunctions_GL_VERSION_2_0;

    Wm3glVertexAttrib2s = (pfn_glVertexAttrib2s)GetFunctionPointer("glVertexAttrib2s");
    if ( Wm3glVertexAttrib2s )
        ++Wm3NumFunctions_GL_VERSION_2_0;

    Wm3glVertexAttrib2sv = (pfn_glVertexAttrib2sv)GetFunctionPointer("glVertexAttrib2sv");
    if ( Wm3glVertexAttrib2sv )
        ++Wm3NumFunctions_GL_VERSION_2_0;

    Wm3glVertexAttrib3d = (pfn_glVertexAttrib3d)GetFunctionPointer("glVertexAttrib3d");
    if ( Wm3glVertexAttrib3d )
        ++Wm3NumFunctions_GL_VERSION_2_0;

    Wm3glVertexAttrib3dv = (pfn_glVertexAttrib3dv)GetFunctionPointer("glVertexAttrib3dv");
    if ( Wm3glVertexAttrib3dv )
        ++Wm3NumFunctions_GL_VERSION_2_0;

    Wm3glVertexAttrib3f = (pfn_glVertexAttrib3f)GetFunctionPointer("glVertexAttrib3f");
    if ( Wm3glVertexAttrib3f )
        ++Wm3NumFunctions_GL_VERSION_2_0;

    Wm3glVertexAttrib3fv = (pfn_glVertexAttrib3fv)GetFunctionPointer("glVertexAttrib3fv");
    if ( Wm3glVertexAttrib3fv )
        ++Wm3NumFunctions_GL_VERSION_2_0;

    Wm3glVertexAttrib3s = (pfn_glVertexAttrib3s)GetFunctionPointer("glVertexAttrib3s");
    if ( Wm3glVertexAttrib3s )
        ++Wm3NumFunctions_GL_VERSION_2_0;

    Wm3glVertexAttrib3sv = (pfn_glVertexAttrib3sv)GetFunctionPointer("glVertexAttrib3sv");
    if ( Wm3glVertexAttrib3sv )
        ++Wm3NumFunctions_GL_VERSION_2_0;

    Wm3glVertexAttrib4Nbv = (pfn_glVertexAttrib4Nbv)GetFunctionPointer("glVertexAttrib4Nbv");
    if ( Wm3glVertexAttrib4Nbv )
        ++Wm3NumFunctions_GL_VERSION_2_0;

    Wm3glVertexAttrib4Niv = (pfn_glVertexAttrib4Niv)GetFunctionPointer("glVertexAttrib4Niv");
    if ( Wm3glVertexAttrib4Niv )
        ++Wm3NumFunctions_GL_VERSION_2_0;

    Wm3glVertexAttrib4Nsv = (pfn_glVertexAttrib4Nsv)GetFunctionPointer("glVertexAttrib4Nsv");
    if ( Wm3glVertexAttrib4Nsv )
        ++Wm3NumFunctions_GL_VERSION_2_0;

    Wm3glVertexAttrib4Nub = (pfn_glVertexAttrib4Nub)GetFunctionPointer("glVertexAttrib4Nub");
    if ( Wm3glVertexAttrib4Nub )
        ++Wm3NumFunctions_GL_VERSION_2_0;

    Wm3glVertexAttrib4Nubv = (pfn_glVertexAttrib4Nubv)GetFunctionPointer("glVertexAttrib4Nubv");
    if ( Wm3glVertexAttrib4Nubv )
        ++Wm3NumFunctions_GL_VERSION_2_0;

    Wm3glVertexAttrib4Nuiv = (pfn_glVertexAttrib4Nuiv)GetFunctionPointer("glVertexAttrib4Nuiv");
    if ( Wm3glVertexAttrib4Nuiv )
        ++Wm3NumFunctions_GL_VERSION_2_0;

    Wm3glVertexAttrib4Nusv = (pfn_glVertexAttrib4Nusv)GetFunctionPointer("glVertexAttrib4Nusv");
    if ( Wm3glVertexAttrib4Nusv )
        ++Wm3NumFunctions_GL_VERSION_2_0;

    Wm3glVertexAttrib4bv = (pfn_glVertexAttrib4bv)GetFunctionPointer("glVertexAttrib4bv");
    if ( Wm3glVertexAttrib4bv )
        ++Wm3NumFunctions_GL_VERSION_2_0;

    Wm3glVertexAttrib4d = (pfn_glVertexAttrib4d)GetFunctionPointer("glVertexAttrib4d");
    if ( Wm3glVertexAttrib4d )
        ++Wm3NumFunctions_GL_VERSION_2_0;

    Wm3glVertexAttrib4dv = (pfn_glVertexAttrib4dv)GetFunctionPointer("glVertexAttrib4dv");
    if ( Wm3glVertexAttrib4dv )
        ++Wm3NumFunctions_GL_VERSION_2_0;

    Wm3glVertexAttrib4f = (pfn_glVertexAttrib4f)GetFunctionPointer("glVertexAttrib4f");
    if ( Wm3glVertexAttrib4f )
        ++Wm3NumFunctions_GL_VERSION_2_0;

    Wm3glVertexAttrib4fv = (pfn_glVertexAttrib4fv)GetFunctionPointer("glVertexAttrib4fv");
    if ( Wm3glVertexAttrib4fv )
        ++Wm3NumFunctions_GL_VERSION_2_0;

    Wm3glVertexAttrib4iv = (pfn_glVertexAttrib4iv)GetFunctionPointer("glVertexAttrib4iv");
    if ( Wm3glVertexAttrib4iv )
        ++Wm3NumFunctions_GL_VERSION_2_0;

    Wm3glVertexAttrib4s = (pfn_glVertexAttrib4s)GetFunctionPointer("glVertexAttrib4s");
    if ( Wm3glVertexAttrib4s )
        ++Wm3NumFunctions_GL_VERSION_2_0;

    Wm3glVertexAttrib4sv = (pfn_glVertexAttrib4sv)GetFunctionPointer("glVertexAttrib4sv");
    if ( Wm3glVertexAttrib4sv )
        ++Wm3NumFunctions_GL_VERSION_2_0;

    Wm3glVertexAttrib4ubv = (pfn_glVertexAttrib4ubv)GetFunctionPointer("glVertexAttrib4ubv");
    if ( Wm3glVertexAttrib4ubv )
        ++Wm3NumFunctions_GL_VERSION_2_0;

    Wm3glVertexAttrib4uiv = (pfn_glVertexAttrib4uiv)GetFunctionPointer("glVertexAttrib4uiv");
    if ( Wm3glVertexAttrib4uiv )
        ++Wm3NumFunctions_GL_VERSION_2_0;

    Wm3glVertexAttrib4usv = (pfn_glVertexAttrib4usv)GetFunctionPointer("glVertexAttrib4usv");
    if ( Wm3glVertexAttrib4usv )
        ++Wm3NumFunctions_GL_VERSION_2_0;

    Wm3glVertexAttribPointer = (pfn_glVertexAttribPointer)GetFunctionPointer("glVertexAttribPointer");
    if ( Wm3glVertexAttribPointer )
        ++Wm3NumFunctions_GL_VERSION_2_0;

    if ( Wm3NumFunctions_GL_VERSION_2_0 == 93 )
        Wm3Exists_GL_VERSION_2_0 = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_VERSION_2_0 = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_VERSION_2_0 ()
{
    Wm3NumFunctions_GL_VERSION_2_0 = 0;
    Wm3Exists_GL_VERSION_2_0 = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_ARB_imaging;
int Wm3NumFunctions_GL_ARB_imaging;
#ifdef WM3_DEFINED_GL_ARB_imaging
static void Init_GL_ARB_imaging ()
{
    Wm3NumFunctions_GL_ARB_imaging = 0;
    Wm3Exists_GL_ARB_imaging = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_ARB_imaging ()
{
    Wm3NumFunctions_GL_ARB_imaging = 0;
    Wm3Exists_GL_ARB_imaging = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_ARB_multitexture;
int Wm3NumFunctions_GL_ARB_multitexture;
#ifdef WM3_DEFINED_GL_ARB_multitexture
pfn_glActiveTextureARB Wm3glActiveTextureARB = 0;
pfn_glClientActiveTextureARB Wm3glClientActiveTextureARB = 0;
pfn_glMultiTexCoord1dARB Wm3glMultiTexCoord1dARB = 0;
pfn_glMultiTexCoord1dvARB Wm3glMultiTexCoord1dvARB = 0;
pfn_glMultiTexCoord1fARB Wm3glMultiTexCoord1fARB = 0;
pfn_glMultiTexCoord1fvARB Wm3glMultiTexCoord1fvARB = 0;
pfn_glMultiTexCoord1iARB Wm3glMultiTexCoord1iARB = 0;
pfn_glMultiTexCoord1ivARB Wm3glMultiTexCoord1ivARB = 0;
pfn_glMultiTexCoord1sARB Wm3glMultiTexCoord1sARB = 0;
pfn_glMultiTexCoord1svARB Wm3glMultiTexCoord1svARB = 0;
pfn_glMultiTexCoord2dARB Wm3glMultiTexCoord2dARB = 0;
pfn_glMultiTexCoord2dvARB Wm3glMultiTexCoord2dvARB = 0;
pfn_glMultiTexCoord2fARB Wm3glMultiTexCoord2fARB = 0;
pfn_glMultiTexCoord2fvARB Wm3glMultiTexCoord2fvARB = 0;
pfn_glMultiTexCoord2iARB Wm3glMultiTexCoord2iARB = 0;
pfn_glMultiTexCoord2ivARB Wm3glMultiTexCoord2ivARB = 0;
pfn_glMultiTexCoord2sARB Wm3glMultiTexCoord2sARB = 0;
pfn_glMultiTexCoord2svARB Wm3glMultiTexCoord2svARB = 0;
pfn_glMultiTexCoord3dARB Wm3glMultiTexCoord3dARB = 0;
pfn_glMultiTexCoord3dvARB Wm3glMultiTexCoord3dvARB = 0;
pfn_glMultiTexCoord3fARB Wm3glMultiTexCoord3fARB = 0;
pfn_glMultiTexCoord3fvARB Wm3glMultiTexCoord3fvARB = 0;
pfn_glMultiTexCoord3iARB Wm3glMultiTexCoord3iARB = 0;
pfn_glMultiTexCoord3ivARB Wm3glMultiTexCoord3ivARB = 0;
pfn_glMultiTexCoord3sARB Wm3glMultiTexCoord3sARB = 0;
pfn_glMultiTexCoord3svARB Wm3glMultiTexCoord3svARB = 0;
pfn_glMultiTexCoord4dARB Wm3glMultiTexCoord4dARB = 0;
pfn_glMultiTexCoord4dvARB Wm3glMultiTexCoord4dvARB = 0;
pfn_glMultiTexCoord4fARB Wm3glMultiTexCoord4fARB = 0;
pfn_glMultiTexCoord4fvARB Wm3glMultiTexCoord4fvARB = 0;
pfn_glMultiTexCoord4iARB Wm3glMultiTexCoord4iARB = 0;
pfn_glMultiTexCoord4ivARB Wm3glMultiTexCoord4ivARB = 0;
pfn_glMultiTexCoord4sARB Wm3glMultiTexCoord4sARB = 0;
pfn_glMultiTexCoord4svARB Wm3glMultiTexCoord4svARB = 0;

static void Init_GL_ARB_multitexture ()
{
    Wm3NumFunctions_GL_ARB_multitexture = 0;

    Wm3glActiveTextureARB = (pfn_glActiveTextureARB)GetFunctionPointer("glActiveTextureARB");
    if ( Wm3glActiveTextureARB )
        ++Wm3NumFunctions_GL_ARB_multitexture;

    Wm3glClientActiveTextureARB = (pfn_glClientActiveTextureARB)GetFunctionPointer("glClientActiveTextureARB");
    if ( Wm3glClientActiveTextureARB )
        ++Wm3NumFunctions_GL_ARB_multitexture;

    Wm3glMultiTexCoord1dARB = (pfn_glMultiTexCoord1dARB)GetFunctionPointer("glMultiTexCoord1dARB");
    if ( Wm3glMultiTexCoord1dARB )
        ++Wm3NumFunctions_GL_ARB_multitexture;

    Wm3glMultiTexCoord1dvARB = (pfn_glMultiTexCoord1dvARB)GetFunctionPointer("glMultiTexCoord1dvARB");
    if ( Wm3glMultiTexCoord1dvARB )
        ++Wm3NumFunctions_GL_ARB_multitexture;

    Wm3glMultiTexCoord1fARB = (pfn_glMultiTexCoord1fARB)GetFunctionPointer("glMultiTexCoord1fARB");
    if ( Wm3glMultiTexCoord1fARB )
        ++Wm3NumFunctions_GL_ARB_multitexture;

    Wm3glMultiTexCoord1fvARB = (pfn_glMultiTexCoord1fvARB)GetFunctionPointer("glMultiTexCoord1fvARB");
    if ( Wm3glMultiTexCoord1fvARB )
        ++Wm3NumFunctions_GL_ARB_multitexture;

    Wm3glMultiTexCoord1iARB = (pfn_glMultiTexCoord1iARB)GetFunctionPointer("glMultiTexCoord1iARB");
    if ( Wm3glMultiTexCoord1iARB )
        ++Wm3NumFunctions_GL_ARB_multitexture;

    Wm3glMultiTexCoord1ivARB = (pfn_glMultiTexCoord1ivARB)GetFunctionPointer("glMultiTexCoord1ivARB");
    if ( Wm3glMultiTexCoord1ivARB )
        ++Wm3NumFunctions_GL_ARB_multitexture;

    Wm3glMultiTexCoord1sARB = (pfn_glMultiTexCoord1sARB)GetFunctionPointer("glMultiTexCoord1sARB");
    if ( Wm3glMultiTexCoord1sARB )
        ++Wm3NumFunctions_GL_ARB_multitexture;

    Wm3glMultiTexCoord1svARB = (pfn_glMultiTexCoord1svARB)GetFunctionPointer("glMultiTexCoord1svARB");
    if ( Wm3glMultiTexCoord1svARB )
        ++Wm3NumFunctions_GL_ARB_multitexture;

    Wm3glMultiTexCoord2dARB = (pfn_glMultiTexCoord2dARB)GetFunctionPointer("glMultiTexCoord2dARB");
    if ( Wm3glMultiTexCoord2dARB )
        ++Wm3NumFunctions_GL_ARB_multitexture;

    Wm3glMultiTexCoord2dvARB = (pfn_glMultiTexCoord2dvARB)GetFunctionPointer("glMultiTexCoord2dvARB");
    if ( Wm3glMultiTexCoord2dvARB )
        ++Wm3NumFunctions_GL_ARB_multitexture;

    Wm3glMultiTexCoord2fARB = (pfn_glMultiTexCoord2fARB)GetFunctionPointer("glMultiTexCoord2fARB");
    if ( Wm3glMultiTexCoord2fARB )
        ++Wm3NumFunctions_GL_ARB_multitexture;

    Wm3glMultiTexCoord2fvARB = (pfn_glMultiTexCoord2fvARB)GetFunctionPointer("glMultiTexCoord2fvARB");
    if ( Wm3glMultiTexCoord2fvARB )
        ++Wm3NumFunctions_GL_ARB_multitexture;

    Wm3glMultiTexCoord2iARB = (pfn_glMultiTexCoord2iARB)GetFunctionPointer("glMultiTexCoord2iARB");
    if ( Wm3glMultiTexCoord2iARB )
        ++Wm3NumFunctions_GL_ARB_multitexture;

    Wm3glMultiTexCoord2ivARB = (pfn_glMultiTexCoord2ivARB)GetFunctionPointer("glMultiTexCoord2ivARB");
    if ( Wm3glMultiTexCoord2ivARB )
        ++Wm3NumFunctions_GL_ARB_multitexture;

    Wm3glMultiTexCoord2sARB = (pfn_glMultiTexCoord2sARB)GetFunctionPointer("glMultiTexCoord2sARB");
    if ( Wm3glMultiTexCoord2sARB )
        ++Wm3NumFunctions_GL_ARB_multitexture;

    Wm3glMultiTexCoord2svARB = (pfn_glMultiTexCoord2svARB)GetFunctionPointer("glMultiTexCoord2svARB");
    if ( Wm3glMultiTexCoord2svARB )
        ++Wm3NumFunctions_GL_ARB_multitexture;

    Wm3glMultiTexCoord3dARB = (pfn_glMultiTexCoord3dARB)GetFunctionPointer("glMultiTexCoord3dARB");
    if ( Wm3glMultiTexCoord3dARB )
        ++Wm3NumFunctions_GL_ARB_multitexture;

    Wm3glMultiTexCoord3dvARB = (pfn_glMultiTexCoord3dvARB)GetFunctionPointer("glMultiTexCoord3dvARB");
    if ( Wm3glMultiTexCoord3dvARB )
        ++Wm3NumFunctions_GL_ARB_multitexture;

    Wm3glMultiTexCoord3fARB = (pfn_glMultiTexCoord3fARB)GetFunctionPointer("glMultiTexCoord3fARB");
    if ( Wm3glMultiTexCoord3fARB )
        ++Wm3NumFunctions_GL_ARB_multitexture;

    Wm3glMultiTexCoord3fvARB = (pfn_glMultiTexCoord3fvARB)GetFunctionPointer("glMultiTexCoord3fvARB");
    if ( Wm3glMultiTexCoord3fvARB )
        ++Wm3NumFunctions_GL_ARB_multitexture;

    Wm3glMultiTexCoord3iARB = (pfn_glMultiTexCoord3iARB)GetFunctionPointer("glMultiTexCoord3iARB");
    if ( Wm3glMultiTexCoord3iARB )
        ++Wm3NumFunctions_GL_ARB_multitexture;

    Wm3glMultiTexCoord3ivARB = (pfn_glMultiTexCoord3ivARB)GetFunctionPointer("glMultiTexCoord3ivARB");
    if ( Wm3glMultiTexCoord3ivARB )
        ++Wm3NumFunctions_GL_ARB_multitexture;

    Wm3glMultiTexCoord3sARB = (pfn_glMultiTexCoord3sARB)GetFunctionPointer("glMultiTexCoord3sARB");
    if ( Wm3glMultiTexCoord3sARB )
        ++Wm3NumFunctions_GL_ARB_multitexture;

    Wm3glMultiTexCoord3svARB = (pfn_glMultiTexCoord3svARB)GetFunctionPointer("glMultiTexCoord3svARB");
    if ( Wm3glMultiTexCoord3svARB )
        ++Wm3NumFunctions_GL_ARB_multitexture;

    Wm3glMultiTexCoord4dARB = (pfn_glMultiTexCoord4dARB)GetFunctionPointer("glMultiTexCoord4dARB");
    if ( Wm3glMultiTexCoord4dARB )
        ++Wm3NumFunctions_GL_ARB_multitexture;

    Wm3glMultiTexCoord4dvARB = (pfn_glMultiTexCoord4dvARB)GetFunctionPointer("glMultiTexCoord4dvARB");
    if ( Wm3glMultiTexCoord4dvARB )
        ++Wm3NumFunctions_GL_ARB_multitexture;

    Wm3glMultiTexCoord4fARB = (pfn_glMultiTexCoord4fARB)GetFunctionPointer("glMultiTexCoord4fARB");
    if ( Wm3glMultiTexCoord4fARB )
        ++Wm3NumFunctions_GL_ARB_multitexture;

    Wm3glMultiTexCoord4fvARB = (pfn_glMultiTexCoord4fvARB)GetFunctionPointer("glMultiTexCoord4fvARB");
    if ( Wm3glMultiTexCoord4fvARB )
        ++Wm3NumFunctions_GL_ARB_multitexture;

    Wm3glMultiTexCoord4iARB = (pfn_glMultiTexCoord4iARB)GetFunctionPointer("glMultiTexCoord4iARB");
    if ( Wm3glMultiTexCoord4iARB )
        ++Wm3NumFunctions_GL_ARB_multitexture;

    Wm3glMultiTexCoord4ivARB = (pfn_glMultiTexCoord4ivARB)GetFunctionPointer("glMultiTexCoord4ivARB");
    if ( Wm3glMultiTexCoord4ivARB )
        ++Wm3NumFunctions_GL_ARB_multitexture;

    Wm3glMultiTexCoord4sARB = (pfn_glMultiTexCoord4sARB)GetFunctionPointer("glMultiTexCoord4sARB");
    if ( Wm3glMultiTexCoord4sARB )
        ++Wm3NumFunctions_GL_ARB_multitexture;

    Wm3glMultiTexCoord4svARB = (pfn_glMultiTexCoord4svARB)GetFunctionPointer("glMultiTexCoord4svARB");
    if ( Wm3glMultiTexCoord4svARB )
        ++Wm3NumFunctions_GL_ARB_multitexture;

    if ( Wm3NumFunctions_GL_ARB_multitexture == 34 )
        Wm3Exists_GL_ARB_multitexture = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_ARB_multitexture = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_ARB_multitexture ()
{
    Wm3NumFunctions_GL_ARB_multitexture = 0;
    Wm3Exists_GL_ARB_multitexture = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_ARB_transpose_matrix;
int Wm3NumFunctions_GL_ARB_transpose_matrix;
#ifdef WM3_DEFINED_GL_ARB_transpose_matrix
pfn_glLoadTransposeMatrixfARB Wm3glLoadTransposeMatrixfARB = 0;
pfn_glLoadTransposeMatrixdARB Wm3glLoadTransposeMatrixdARB = 0;
pfn_glMultTransposeMatrixfARB Wm3glMultTransposeMatrixfARB = 0;
pfn_glMultTransposeMatrixdARB Wm3glMultTransposeMatrixdARB = 0;

static void Init_GL_ARB_transpose_matrix ()
{
    Wm3NumFunctions_GL_ARB_transpose_matrix = 0;

    Wm3glLoadTransposeMatrixfARB = (pfn_glLoadTransposeMatrixfARB)GetFunctionPointer("glLoadTransposeMatrixfARB");
    if ( Wm3glLoadTransposeMatrixfARB )
        ++Wm3NumFunctions_GL_ARB_transpose_matrix;

    Wm3glLoadTransposeMatrixdARB = (pfn_glLoadTransposeMatrixdARB)GetFunctionPointer("glLoadTransposeMatrixdARB");
    if ( Wm3glLoadTransposeMatrixdARB )
        ++Wm3NumFunctions_GL_ARB_transpose_matrix;

    Wm3glMultTransposeMatrixfARB = (pfn_glMultTransposeMatrixfARB)GetFunctionPointer("glMultTransposeMatrixfARB");
    if ( Wm3glMultTransposeMatrixfARB )
        ++Wm3NumFunctions_GL_ARB_transpose_matrix;

    Wm3glMultTransposeMatrixdARB = (pfn_glMultTransposeMatrixdARB)GetFunctionPointer("glMultTransposeMatrixdARB");
    if ( Wm3glMultTransposeMatrixdARB )
        ++Wm3NumFunctions_GL_ARB_transpose_matrix;

    if ( Wm3NumFunctions_GL_ARB_transpose_matrix == 4 )
        Wm3Exists_GL_ARB_transpose_matrix = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_ARB_transpose_matrix = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_ARB_transpose_matrix ()
{
    Wm3NumFunctions_GL_ARB_transpose_matrix = 0;
    Wm3Exists_GL_ARB_transpose_matrix = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_ARB_multisample;
int Wm3NumFunctions_GL_ARB_multisample;
#ifdef WM3_DEFINED_GL_ARB_multisample
pfn_glSampleCoverageARB Wm3glSampleCoverageARB = 0;

static void Init_GL_ARB_multisample ()
{
    Wm3NumFunctions_GL_ARB_multisample = 0;

    Wm3glSampleCoverageARB = (pfn_glSampleCoverageARB)GetFunctionPointer("glSampleCoverageARB");
    if ( Wm3glSampleCoverageARB )
        ++Wm3NumFunctions_GL_ARB_multisample;

    if ( Wm3NumFunctions_GL_ARB_multisample == 1 )
        Wm3Exists_GL_ARB_multisample = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_ARB_multisample = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_ARB_multisample ()
{
    Wm3NumFunctions_GL_ARB_multisample = 0;
    Wm3Exists_GL_ARB_multisample = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_ARB_texture_env_add;
int Wm3NumFunctions_GL_ARB_texture_env_add;
#ifdef WM3_DEFINED_GL_ARB_texture_env_add
static void Init_GL_ARB_texture_env_add ()
{
    Wm3NumFunctions_GL_ARB_texture_env_add = 0;
    Wm3Exists_GL_ARB_texture_env_add = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_ARB_texture_env_add ()
{
    Wm3NumFunctions_GL_ARB_texture_env_add = 0;
    Wm3Exists_GL_ARB_texture_env_add = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_ARB_texture_cube_map;
int Wm3NumFunctions_GL_ARB_texture_cube_map;
#ifdef WM3_DEFINED_GL_ARB_texture_cube_map
static void Init_GL_ARB_texture_cube_map ()
{
    Wm3NumFunctions_GL_ARB_texture_cube_map = 0;
    Wm3Exists_GL_ARB_texture_cube_map = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_ARB_texture_cube_map ()
{
    Wm3NumFunctions_GL_ARB_texture_cube_map = 0;
    Wm3Exists_GL_ARB_texture_cube_map = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_ARB_texture_compression;
int Wm3NumFunctions_GL_ARB_texture_compression;
#ifdef WM3_DEFINED_GL_ARB_texture_compression
pfn_glCompressedTexImage3DARB Wm3glCompressedTexImage3DARB = 0;
pfn_glCompressedTexImage2DARB Wm3glCompressedTexImage2DARB = 0;
pfn_glCompressedTexImage1DARB Wm3glCompressedTexImage1DARB = 0;
pfn_glCompressedTexSubImage3DARB Wm3glCompressedTexSubImage3DARB = 0;
pfn_glCompressedTexSubImage2DARB Wm3glCompressedTexSubImage2DARB = 0;
pfn_glCompressedTexSubImage1DARB Wm3glCompressedTexSubImage1DARB = 0;
pfn_glGetCompressedTexImageARB Wm3glGetCompressedTexImageARB = 0;

static void Init_GL_ARB_texture_compression ()
{
    Wm3NumFunctions_GL_ARB_texture_compression = 0;

    Wm3glCompressedTexImage3DARB = (pfn_glCompressedTexImage3DARB)GetFunctionPointer("glCompressedTexImage3DARB");
    if ( Wm3glCompressedTexImage3DARB )
        ++Wm3NumFunctions_GL_ARB_texture_compression;

    Wm3glCompressedTexImage2DARB = (pfn_glCompressedTexImage2DARB)GetFunctionPointer("glCompressedTexImage2DARB");
    if ( Wm3glCompressedTexImage2DARB )
        ++Wm3NumFunctions_GL_ARB_texture_compression;

    Wm3glCompressedTexImage1DARB = (pfn_glCompressedTexImage1DARB)GetFunctionPointer("glCompressedTexImage1DARB");
    if ( Wm3glCompressedTexImage1DARB )
        ++Wm3NumFunctions_GL_ARB_texture_compression;

    Wm3glCompressedTexSubImage3DARB = (pfn_glCompressedTexSubImage3DARB)GetFunctionPointer("glCompressedTexSubImage3DARB");
    if ( Wm3glCompressedTexSubImage3DARB )
        ++Wm3NumFunctions_GL_ARB_texture_compression;

    Wm3glCompressedTexSubImage2DARB = (pfn_glCompressedTexSubImage2DARB)GetFunctionPointer("glCompressedTexSubImage2DARB");
    if ( Wm3glCompressedTexSubImage2DARB )
        ++Wm3NumFunctions_GL_ARB_texture_compression;

    Wm3glCompressedTexSubImage1DARB = (pfn_glCompressedTexSubImage1DARB)GetFunctionPointer("glCompressedTexSubImage1DARB");
    if ( Wm3glCompressedTexSubImage1DARB )
        ++Wm3NumFunctions_GL_ARB_texture_compression;

    Wm3glGetCompressedTexImageARB = (pfn_glGetCompressedTexImageARB)GetFunctionPointer("glGetCompressedTexImageARB");
    if ( Wm3glGetCompressedTexImageARB )
        ++Wm3NumFunctions_GL_ARB_texture_compression;

    if ( Wm3NumFunctions_GL_ARB_texture_compression == 7 )
        Wm3Exists_GL_ARB_texture_compression = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_ARB_texture_compression = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_ARB_texture_compression ()
{
    Wm3NumFunctions_GL_ARB_texture_compression = 0;
    Wm3Exists_GL_ARB_texture_compression = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_ARB_texture_border_clamp;
int Wm3NumFunctions_GL_ARB_texture_border_clamp;
#ifdef WM3_DEFINED_GL_ARB_texture_border_clamp
static void Init_GL_ARB_texture_border_clamp ()
{
    Wm3NumFunctions_GL_ARB_texture_border_clamp = 0;
    Wm3Exists_GL_ARB_texture_border_clamp = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_ARB_texture_border_clamp ()
{
    Wm3NumFunctions_GL_ARB_texture_border_clamp = 0;
    Wm3Exists_GL_ARB_texture_border_clamp = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_ARB_point_parameters;
int Wm3NumFunctions_GL_ARB_point_parameters;
#ifdef WM3_DEFINED_GL_ARB_point_parameters
pfn_glPointParameterfARB Wm3glPointParameterfARB = 0;
pfn_glPointParameterfvARB Wm3glPointParameterfvARB = 0;

static void Init_GL_ARB_point_parameters ()
{
    Wm3NumFunctions_GL_ARB_point_parameters = 0;

    Wm3glPointParameterfARB = (pfn_glPointParameterfARB)GetFunctionPointer("glPointParameterfARB");
    if ( Wm3glPointParameterfARB )
        ++Wm3NumFunctions_GL_ARB_point_parameters;

    Wm3glPointParameterfvARB = (pfn_glPointParameterfvARB)GetFunctionPointer("glPointParameterfvARB");
    if ( Wm3glPointParameterfvARB )
        ++Wm3NumFunctions_GL_ARB_point_parameters;

    if ( Wm3NumFunctions_GL_ARB_point_parameters == 2 )
        Wm3Exists_GL_ARB_point_parameters = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_ARB_point_parameters = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_ARB_point_parameters ()
{
    Wm3NumFunctions_GL_ARB_point_parameters = 0;
    Wm3Exists_GL_ARB_point_parameters = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_ARB_vertex_blend;
int Wm3NumFunctions_GL_ARB_vertex_blend;
#ifdef WM3_DEFINED_GL_ARB_vertex_blend
pfn_glWeightbvARB Wm3glWeightbvARB = 0;
pfn_glWeightsvARB Wm3glWeightsvARB = 0;
pfn_glWeightivARB Wm3glWeightivARB = 0;
pfn_glWeightfvARB Wm3glWeightfvARB = 0;
pfn_glWeightdvARB Wm3glWeightdvARB = 0;
pfn_glWeightubvARB Wm3glWeightubvARB = 0;
pfn_glWeightusvARB Wm3glWeightusvARB = 0;
pfn_glWeightuivARB Wm3glWeightuivARB = 0;
pfn_glWeightPointerARB Wm3glWeightPointerARB = 0;
pfn_glVertexBlendARB Wm3glVertexBlendARB = 0;

static void Init_GL_ARB_vertex_blend ()
{
    Wm3NumFunctions_GL_ARB_vertex_blend = 0;

    Wm3glWeightbvARB = (pfn_glWeightbvARB)GetFunctionPointer("glWeightbvARB");
    if ( Wm3glWeightbvARB )
        ++Wm3NumFunctions_GL_ARB_vertex_blend;

    Wm3glWeightsvARB = (pfn_glWeightsvARB)GetFunctionPointer("glWeightsvARB");
    if ( Wm3glWeightsvARB )
        ++Wm3NumFunctions_GL_ARB_vertex_blend;

    Wm3glWeightivARB = (pfn_glWeightivARB)GetFunctionPointer("glWeightivARB");
    if ( Wm3glWeightivARB )
        ++Wm3NumFunctions_GL_ARB_vertex_blend;

    Wm3glWeightfvARB = (pfn_glWeightfvARB)GetFunctionPointer("glWeightfvARB");
    if ( Wm3glWeightfvARB )
        ++Wm3NumFunctions_GL_ARB_vertex_blend;

    Wm3glWeightdvARB = (pfn_glWeightdvARB)GetFunctionPointer("glWeightdvARB");
    if ( Wm3glWeightdvARB )
        ++Wm3NumFunctions_GL_ARB_vertex_blend;

    Wm3glWeightubvARB = (pfn_glWeightubvARB)GetFunctionPointer("glWeightubvARB");
    if ( Wm3glWeightubvARB )
        ++Wm3NumFunctions_GL_ARB_vertex_blend;

    Wm3glWeightusvARB = (pfn_glWeightusvARB)GetFunctionPointer("glWeightusvARB");
    if ( Wm3glWeightusvARB )
        ++Wm3NumFunctions_GL_ARB_vertex_blend;

    Wm3glWeightuivARB = (pfn_glWeightuivARB)GetFunctionPointer("glWeightuivARB");
    if ( Wm3glWeightuivARB )
        ++Wm3NumFunctions_GL_ARB_vertex_blend;

    Wm3glWeightPointerARB = (pfn_glWeightPointerARB)GetFunctionPointer("glWeightPointerARB");
    if ( Wm3glWeightPointerARB )
        ++Wm3NumFunctions_GL_ARB_vertex_blend;

    Wm3glVertexBlendARB = (pfn_glVertexBlendARB)GetFunctionPointer("glVertexBlendARB");
    if ( Wm3glVertexBlendARB )
        ++Wm3NumFunctions_GL_ARB_vertex_blend;

    if ( Wm3NumFunctions_GL_ARB_vertex_blend == 10 )
        Wm3Exists_GL_ARB_vertex_blend = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_ARB_vertex_blend = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_ARB_vertex_blend ()
{
    Wm3NumFunctions_GL_ARB_vertex_blend = 0;
    Wm3Exists_GL_ARB_vertex_blend = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_ARB_matrix_palette;
int Wm3NumFunctions_GL_ARB_matrix_palette;
#ifdef WM3_DEFINED_GL_ARB_matrix_palette
pfn_glCurrentPaletteMatrixARB Wm3glCurrentPaletteMatrixARB = 0;
pfn_glMatrixIndexubvARB Wm3glMatrixIndexubvARB = 0;
pfn_glMatrixIndexusvARB Wm3glMatrixIndexusvARB = 0;
pfn_glMatrixIndexuivARB Wm3glMatrixIndexuivARB = 0;
pfn_glMatrixIndexPointerARB Wm3glMatrixIndexPointerARB = 0;

static void Init_GL_ARB_matrix_palette ()
{
    Wm3NumFunctions_GL_ARB_matrix_palette = 0;

    Wm3glCurrentPaletteMatrixARB = (pfn_glCurrentPaletteMatrixARB)GetFunctionPointer("glCurrentPaletteMatrixARB");
    if ( Wm3glCurrentPaletteMatrixARB )
        ++Wm3NumFunctions_GL_ARB_matrix_palette;

    Wm3glMatrixIndexubvARB = (pfn_glMatrixIndexubvARB)GetFunctionPointer("glMatrixIndexubvARB");
    if ( Wm3glMatrixIndexubvARB )
        ++Wm3NumFunctions_GL_ARB_matrix_palette;

    Wm3glMatrixIndexusvARB = (pfn_glMatrixIndexusvARB)GetFunctionPointer("glMatrixIndexusvARB");
    if ( Wm3glMatrixIndexusvARB )
        ++Wm3NumFunctions_GL_ARB_matrix_palette;

    Wm3glMatrixIndexuivARB = (pfn_glMatrixIndexuivARB)GetFunctionPointer("glMatrixIndexuivARB");
    if ( Wm3glMatrixIndexuivARB )
        ++Wm3NumFunctions_GL_ARB_matrix_palette;

    Wm3glMatrixIndexPointerARB = (pfn_glMatrixIndexPointerARB)GetFunctionPointer("glMatrixIndexPointerARB");
    if ( Wm3glMatrixIndexPointerARB )
        ++Wm3NumFunctions_GL_ARB_matrix_palette;

    if ( Wm3NumFunctions_GL_ARB_matrix_palette == 5 )
        Wm3Exists_GL_ARB_matrix_palette = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_ARB_matrix_palette = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_ARB_matrix_palette ()
{
    Wm3NumFunctions_GL_ARB_matrix_palette = 0;
    Wm3Exists_GL_ARB_matrix_palette = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_ARB_texture_env_combine;
int Wm3NumFunctions_GL_ARB_texture_env_combine;
#ifdef WM3_DEFINED_GL_ARB_texture_env_combine
static void Init_GL_ARB_texture_env_combine ()
{
    Wm3NumFunctions_GL_ARB_texture_env_combine = 0;
    Wm3Exists_GL_ARB_texture_env_combine = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_ARB_texture_env_combine ()
{
    Wm3NumFunctions_GL_ARB_texture_env_combine = 0;
    Wm3Exists_GL_ARB_texture_env_combine = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_ARB_texture_env_crossbar;
int Wm3NumFunctions_GL_ARB_texture_env_crossbar;
#ifdef WM3_DEFINED_GL_ARB_texture_env_crossbar
static void Init_GL_ARB_texture_env_crossbar ()
{
    Wm3NumFunctions_GL_ARB_texture_env_crossbar = 0;
    Wm3Exists_GL_ARB_texture_env_crossbar = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_ARB_texture_env_crossbar ()
{
    Wm3NumFunctions_GL_ARB_texture_env_crossbar = 0;
    Wm3Exists_GL_ARB_texture_env_crossbar = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_ARB_texture_env_dot3;
int Wm3NumFunctions_GL_ARB_texture_env_dot3;
#ifdef WM3_DEFINED_GL_ARB_texture_env_dot3
static void Init_GL_ARB_texture_env_dot3 ()
{
    Wm3NumFunctions_GL_ARB_texture_env_dot3 = 0;
    Wm3Exists_GL_ARB_texture_env_dot3 = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_ARB_texture_env_dot3 ()
{
    Wm3NumFunctions_GL_ARB_texture_env_dot3 = 0;
    Wm3Exists_GL_ARB_texture_env_dot3 = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_ARB_texture_mirrored_repeat;
int Wm3NumFunctions_GL_ARB_texture_mirrored_repeat;
#ifdef WM3_DEFINED_GL_ARB_texture_mirrored_repeat
static void Init_GL_ARB_texture_mirrored_repeat ()
{
    Wm3NumFunctions_GL_ARB_texture_mirrored_repeat = 0;
    Wm3Exists_GL_ARB_texture_mirrored_repeat = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_ARB_texture_mirrored_repeat ()
{
    Wm3NumFunctions_GL_ARB_texture_mirrored_repeat = 0;
    Wm3Exists_GL_ARB_texture_mirrored_repeat = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_ARB_depth_texture;
int Wm3NumFunctions_GL_ARB_depth_texture;
#ifdef WM3_DEFINED_GL_ARB_depth_texture
static void Init_GL_ARB_depth_texture ()
{
    Wm3NumFunctions_GL_ARB_depth_texture = 0;
    Wm3Exists_GL_ARB_depth_texture = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_ARB_depth_texture ()
{
    Wm3NumFunctions_GL_ARB_depth_texture = 0;
    Wm3Exists_GL_ARB_depth_texture = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_ARB_shadow;
int Wm3NumFunctions_GL_ARB_shadow;
#ifdef WM3_DEFINED_GL_ARB_shadow
static void Init_GL_ARB_shadow ()
{
    Wm3NumFunctions_GL_ARB_shadow = 0;
    Wm3Exists_GL_ARB_shadow = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_ARB_shadow ()
{
    Wm3NumFunctions_GL_ARB_shadow = 0;
    Wm3Exists_GL_ARB_shadow = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_ARB_shadow_ambient;
int Wm3NumFunctions_GL_ARB_shadow_ambient;
#ifdef WM3_DEFINED_GL_ARB_shadow_ambient
static void Init_GL_ARB_shadow_ambient ()
{
    Wm3NumFunctions_GL_ARB_shadow_ambient = 0;
    Wm3Exists_GL_ARB_shadow_ambient = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_ARB_shadow_ambient ()
{
    Wm3NumFunctions_GL_ARB_shadow_ambient = 0;
    Wm3Exists_GL_ARB_shadow_ambient = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_ARB_window_pos;
int Wm3NumFunctions_GL_ARB_window_pos;
#ifdef WM3_DEFINED_GL_ARB_window_pos
pfn_glWindowPos2dARB Wm3glWindowPos2dARB = 0;
pfn_glWindowPos2dvARB Wm3glWindowPos2dvARB = 0;
pfn_glWindowPos2fARB Wm3glWindowPos2fARB = 0;
pfn_glWindowPos2fvARB Wm3glWindowPos2fvARB = 0;
pfn_glWindowPos2iARB Wm3glWindowPos2iARB = 0;
pfn_glWindowPos2ivARB Wm3glWindowPos2ivARB = 0;
pfn_glWindowPos2sARB Wm3glWindowPos2sARB = 0;
pfn_glWindowPos2svARB Wm3glWindowPos2svARB = 0;
pfn_glWindowPos3dARB Wm3glWindowPos3dARB = 0;
pfn_glWindowPos3dvARB Wm3glWindowPos3dvARB = 0;
pfn_glWindowPos3fARB Wm3glWindowPos3fARB = 0;
pfn_glWindowPos3fvARB Wm3glWindowPos3fvARB = 0;
pfn_glWindowPos3iARB Wm3glWindowPos3iARB = 0;
pfn_glWindowPos3ivARB Wm3glWindowPos3ivARB = 0;
pfn_glWindowPos3sARB Wm3glWindowPos3sARB = 0;
pfn_glWindowPos3svARB Wm3glWindowPos3svARB = 0;

static void Init_GL_ARB_window_pos ()
{
    Wm3NumFunctions_GL_ARB_window_pos = 0;

    Wm3glWindowPos2dARB = (pfn_glWindowPos2dARB)GetFunctionPointer("glWindowPos2dARB");
    if ( Wm3glWindowPos2dARB )
        ++Wm3NumFunctions_GL_ARB_window_pos;

    Wm3glWindowPos2dvARB = (pfn_glWindowPos2dvARB)GetFunctionPointer("glWindowPos2dvARB");
    if ( Wm3glWindowPos2dvARB )
        ++Wm3NumFunctions_GL_ARB_window_pos;

    Wm3glWindowPos2fARB = (pfn_glWindowPos2fARB)GetFunctionPointer("glWindowPos2fARB");
    if ( Wm3glWindowPos2fARB )
        ++Wm3NumFunctions_GL_ARB_window_pos;

    Wm3glWindowPos2fvARB = (pfn_glWindowPos2fvARB)GetFunctionPointer("glWindowPos2fvARB");
    if ( Wm3glWindowPos2fvARB )
        ++Wm3NumFunctions_GL_ARB_window_pos;

    Wm3glWindowPos2iARB = (pfn_glWindowPos2iARB)GetFunctionPointer("glWindowPos2iARB");
    if ( Wm3glWindowPos2iARB )
        ++Wm3NumFunctions_GL_ARB_window_pos;

    Wm3glWindowPos2ivARB = (pfn_glWindowPos2ivARB)GetFunctionPointer("glWindowPos2ivARB");
    if ( Wm3glWindowPos2ivARB )
        ++Wm3NumFunctions_GL_ARB_window_pos;

    Wm3glWindowPos2sARB = (pfn_glWindowPos2sARB)GetFunctionPointer("glWindowPos2sARB");
    if ( Wm3glWindowPos2sARB )
        ++Wm3NumFunctions_GL_ARB_window_pos;

    Wm3glWindowPos2svARB = (pfn_glWindowPos2svARB)GetFunctionPointer("glWindowPos2svARB");
    if ( Wm3glWindowPos2svARB )
        ++Wm3NumFunctions_GL_ARB_window_pos;

    Wm3glWindowPos3dARB = (pfn_glWindowPos3dARB)GetFunctionPointer("glWindowPos3dARB");
    if ( Wm3glWindowPos3dARB )
        ++Wm3NumFunctions_GL_ARB_window_pos;

    Wm3glWindowPos3dvARB = (pfn_glWindowPos3dvARB)GetFunctionPointer("glWindowPos3dvARB");
    if ( Wm3glWindowPos3dvARB )
        ++Wm3NumFunctions_GL_ARB_window_pos;

    Wm3glWindowPos3fARB = (pfn_glWindowPos3fARB)GetFunctionPointer("glWindowPos3fARB");
    if ( Wm3glWindowPos3fARB )
        ++Wm3NumFunctions_GL_ARB_window_pos;

    Wm3glWindowPos3fvARB = (pfn_glWindowPos3fvARB)GetFunctionPointer("glWindowPos3fvARB");
    if ( Wm3glWindowPos3fvARB )
        ++Wm3NumFunctions_GL_ARB_window_pos;

    Wm3glWindowPos3iARB = (pfn_glWindowPos3iARB)GetFunctionPointer("glWindowPos3iARB");
    if ( Wm3glWindowPos3iARB )
        ++Wm3NumFunctions_GL_ARB_window_pos;

    Wm3glWindowPos3ivARB = (pfn_glWindowPos3ivARB)GetFunctionPointer("glWindowPos3ivARB");
    if ( Wm3glWindowPos3ivARB )
        ++Wm3NumFunctions_GL_ARB_window_pos;

    Wm3glWindowPos3sARB = (pfn_glWindowPos3sARB)GetFunctionPointer("glWindowPos3sARB");
    if ( Wm3glWindowPos3sARB )
        ++Wm3NumFunctions_GL_ARB_window_pos;

    Wm3glWindowPos3svARB = (pfn_glWindowPos3svARB)GetFunctionPointer("glWindowPos3svARB");
    if ( Wm3glWindowPos3svARB )
        ++Wm3NumFunctions_GL_ARB_window_pos;

    if ( Wm3NumFunctions_GL_ARB_window_pos == 16 )
        Wm3Exists_GL_ARB_window_pos = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_ARB_window_pos = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_ARB_window_pos ()
{
    Wm3NumFunctions_GL_ARB_window_pos = 0;
    Wm3Exists_GL_ARB_window_pos = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_ARB_vertex_program;
int Wm3NumFunctions_GL_ARB_vertex_program;
#ifdef WM3_DEFINED_GL_ARB_vertex_program
pfn_glVertexAttrib1dARB Wm3glVertexAttrib1dARB = 0;
pfn_glVertexAttrib1dvARB Wm3glVertexAttrib1dvARB = 0;
pfn_glVertexAttrib1fARB Wm3glVertexAttrib1fARB = 0;
pfn_glVertexAttrib1fvARB Wm3glVertexAttrib1fvARB = 0;
pfn_glVertexAttrib1sARB Wm3glVertexAttrib1sARB = 0;
pfn_glVertexAttrib1svARB Wm3glVertexAttrib1svARB = 0;
pfn_glVertexAttrib2dARB Wm3glVertexAttrib2dARB = 0;
pfn_glVertexAttrib2dvARB Wm3glVertexAttrib2dvARB = 0;
pfn_glVertexAttrib2fARB Wm3glVertexAttrib2fARB = 0;
pfn_glVertexAttrib2fvARB Wm3glVertexAttrib2fvARB = 0;
pfn_glVertexAttrib2sARB Wm3glVertexAttrib2sARB = 0;
pfn_glVertexAttrib2svARB Wm3glVertexAttrib2svARB = 0;
pfn_glVertexAttrib3dARB Wm3glVertexAttrib3dARB = 0;
pfn_glVertexAttrib3dvARB Wm3glVertexAttrib3dvARB = 0;
pfn_glVertexAttrib3fARB Wm3glVertexAttrib3fARB = 0;
pfn_glVertexAttrib3fvARB Wm3glVertexAttrib3fvARB = 0;
pfn_glVertexAttrib3sARB Wm3glVertexAttrib3sARB = 0;
pfn_glVertexAttrib3svARB Wm3glVertexAttrib3svARB = 0;
pfn_glVertexAttrib4NbvARB Wm3glVertexAttrib4NbvARB = 0;
pfn_glVertexAttrib4NivARB Wm3glVertexAttrib4NivARB = 0;
pfn_glVertexAttrib4NsvARB Wm3glVertexAttrib4NsvARB = 0;
pfn_glVertexAttrib4NubARB Wm3glVertexAttrib4NubARB = 0;
pfn_glVertexAttrib4NubvARB Wm3glVertexAttrib4NubvARB = 0;
pfn_glVertexAttrib4NuivARB Wm3glVertexAttrib4NuivARB = 0;
pfn_glVertexAttrib4NusvARB Wm3glVertexAttrib4NusvARB = 0;
pfn_glVertexAttrib4bvARB Wm3glVertexAttrib4bvARB = 0;
pfn_glVertexAttrib4dARB Wm3glVertexAttrib4dARB = 0;
pfn_glVertexAttrib4dvARB Wm3glVertexAttrib4dvARB = 0;
pfn_glVertexAttrib4fARB Wm3glVertexAttrib4fARB = 0;
pfn_glVertexAttrib4fvARB Wm3glVertexAttrib4fvARB = 0;
pfn_glVertexAttrib4ivARB Wm3glVertexAttrib4ivARB = 0;
pfn_glVertexAttrib4sARB Wm3glVertexAttrib4sARB = 0;
pfn_glVertexAttrib4svARB Wm3glVertexAttrib4svARB = 0;
pfn_glVertexAttrib4ubvARB Wm3glVertexAttrib4ubvARB = 0;
pfn_glVertexAttrib4uivARB Wm3glVertexAttrib4uivARB = 0;
pfn_glVertexAttrib4usvARB Wm3glVertexAttrib4usvARB = 0;
pfn_glVertexAttribPointerARB Wm3glVertexAttribPointerARB = 0;
pfn_glEnableVertexAttribArrayARB Wm3glEnableVertexAttribArrayARB = 0;
pfn_glDisableVertexAttribArrayARB Wm3glDisableVertexAttribArrayARB = 0;
pfn_glProgramStringARB Wm3glProgramStringARB = 0;
pfn_glBindProgramARB Wm3glBindProgramARB = 0;
pfn_glDeleteProgramsARB Wm3glDeleteProgramsARB = 0;
pfn_glGenProgramsARB Wm3glGenProgramsARB = 0;
pfn_glProgramEnvParameter4dARB Wm3glProgramEnvParameter4dARB = 0;
pfn_glProgramEnvParameter4dvARB Wm3glProgramEnvParameter4dvARB = 0;
pfn_glProgramEnvParameter4fARB Wm3glProgramEnvParameter4fARB = 0;
pfn_glProgramEnvParameter4fvARB Wm3glProgramEnvParameter4fvARB = 0;
pfn_glProgramLocalParameter4dARB Wm3glProgramLocalParameter4dARB = 0;
pfn_glProgramLocalParameter4dvARB Wm3glProgramLocalParameter4dvARB = 0;
pfn_glProgramLocalParameter4fARB Wm3glProgramLocalParameter4fARB = 0;
pfn_glProgramLocalParameter4fvARB Wm3glProgramLocalParameter4fvARB = 0;
pfn_glGetProgramEnvParameterdvARB Wm3glGetProgramEnvParameterdvARB = 0;
pfn_glGetProgramEnvParameterfvARB Wm3glGetProgramEnvParameterfvARB = 0;
pfn_glGetProgramLocalParameterdvARB Wm3glGetProgramLocalParameterdvARB = 0;
pfn_glGetProgramLocalParameterfvARB Wm3glGetProgramLocalParameterfvARB = 0;
pfn_glGetProgramivARB Wm3glGetProgramivARB = 0;
pfn_glGetProgramStringARB Wm3glGetProgramStringARB = 0;
pfn_glGetVertexAttribdvARB Wm3glGetVertexAttribdvARB = 0;
pfn_glGetVertexAttribfvARB Wm3glGetVertexAttribfvARB = 0;
pfn_glGetVertexAttribivARB Wm3glGetVertexAttribivARB = 0;
pfn_glGetVertexAttribPointervARB Wm3glGetVertexAttribPointervARB = 0;
pfn_glIsProgramARB Wm3glIsProgramARB = 0;

static void Init_GL_ARB_vertex_program ()
{
    Wm3NumFunctions_GL_ARB_vertex_program = 0;

    Wm3glVertexAttrib1dARB = (pfn_glVertexAttrib1dARB)GetFunctionPointer("glVertexAttrib1dARB");
    if ( Wm3glVertexAttrib1dARB )
        ++Wm3NumFunctions_GL_ARB_vertex_program;

    Wm3glVertexAttrib1dvARB = (pfn_glVertexAttrib1dvARB)GetFunctionPointer("glVertexAttrib1dvARB");
    if ( Wm3glVertexAttrib1dvARB )
        ++Wm3NumFunctions_GL_ARB_vertex_program;

    Wm3glVertexAttrib1fARB = (pfn_glVertexAttrib1fARB)GetFunctionPointer("glVertexAttrib1fARB");
    if ( Wm3glVertexAttrib1fARB )
        ++Wm3NumFunctions_GL_ARB_vertex_program;

    Wm3glVertexAttrib1fvARB = (pfn_glVertexAttrib1fvARB)GetFunctionPointer("glVertexAttrib1fvARB");
    if ( Wm3glVertexAttrib1fvARB )
        ++Wm3NumFunctions_GL_ARB_vertex_program;

    Wm3glVertexAttrib1sARB = (pfn_glVertexAttrib1sARB)GetFunctionPointer("glVertexAttrib1sARB");
    if ( Wm3glVertexAttrib1sARB )
        ++Wm3NumFunctions_GL_ARB_vertex_program;

    Wm3glVertexAttrib1svARB = (pfn_glVertexAttrib1svARB)GetFunctionPointer("glVertexAttrib1svARB");
    if ( Wm3glVertexAttrib1svARB )
        ++Wm3NumFunctions_GL_ARB_vertex_program;

    Wm3glVertexAttrib2dARB = (pfn_glVertexAttrib2dARB)GetFunctionPointer("glVertexAttrib2dARB");
    if ( Wm3glVertexAttrib2dARB )
        ++Wm3NumFunctions_GL_ARB_vertex_program;

    Wm3glVertexAttrib2dvARB = (pfn_glVertexAttrib2dvARB)GetFunctionPointer("glVertexAttrib2dvARB");
    if ( Wm3glVertexAttrib2dvARB )
        ++Wm3NumFunctions_GL_ARB_vertex_program;

    Wm3glVertexAttrib2fARB = (pfn_glVertexAttrib2fARB)GetFunctionPointer("glVertexAttrib2fARB");
    if ( Wm3glVertexAttrib2fARB )
        ++Wm3NumFunctions_GL_ARB_vertex_program;

    Wm3glVertexAttrib2fvARB = (pfn_glVertexAttrib2fvARB)GetFunctionPointer("glVertexAttrib2fvARB");
    if ( Wm3glVertexAttrib2fvARB )
        ++Wm3NumFunctions_GL_ARB_vertex_program;

    Wm3glVertexAttrib2sARB = (pfn_glVertexAttrib2sARB)GetFunctionPointer("glVertexAttrib2sARB");
    if ( Wm3glVertexAttrib2sARB )
        ++Wm3NumFunctions_GL_ARB_vertex_program;

    Wm3glVertexAttrib2svARB = (pfn_glVertexAttrib2svARB)GetFunctionPointer("glVertexAttrib2svARB");
    if ( Wm3glVertexAttrib2svARB )
        ++Wm3NumFunctions_GL_ARB_vertex_program;

    Wm3glVertexAttrib3dARB = (pfn_glVertexAttrib3dARB)GetFunctionPointer("glVertexAttrib3dARB");
    if ( Wm3glVertexAttrib3dARB )
        ++Wm3NumFunctions_GL_ARB_vertex_program;

    Wm3glVertexAttrib3dvARB = (pfn_glVertexAttrib3dvARB)GetFunctionPointer("glVertexAttrib3dvARB");
    if ( Wm3glVertexAttrib3dvARB )
        ++Wm3NumFunctions_GL_ARB_vertex_program;

    Wm3glVertexAttrib3fARB = (pfn_glVertexAttrib3fARB)GetFunctionPointer("glVertexAttrib3fARB");
    if ( Wm3glVertexAttrib3fARB )
        ++Wm3NumFunctions_GL_ARB_vertex_program;

    Wm3glVertexAttrib3fvARB = (pfn_glVertexAttrib3fvARB)GetFunctionPointer("glVertexAttrib3fvARB");
    if ( Wm3glVertexAttrib3fvARB )
        ++Wm3NumFunctions_GL_ARB_vertex_program;

    Wm3glVertexAttrib3sARB = (pfn_glVertexAttrib3sARB)GetFunctionPointer("glVertexAttrib3sARB");
    if ( Wm3glVertexAttrib3sARB )
        ++Wm3NumFunctions_GL_ARB_vertex_program;

    Wm3glVertexAttrib3svARB = (pfn_glVertexAttrib3svARB)GetFunctionPointer("glVertexAttrib3svARB");
    if ( Wm3glVertexAttrib3svARB )
        ++Wm3NumFunctions_GL_ARB_vertex_program;

    Wm3glVertexAttrib4NbvARB = (pfn_glVertexAttrib4NbvARB)GetFunctionPointer("glVertexAttrib4NbvARB");
    if ( Wm3glVertexAttrib4NbvARB )
        ++Wm3NumFunctions_GL_ARB_vertex_program;

    Wm3glVertexAttrib4NivARB = (pfn_glVertexAttrib4NivARB)GetFunctionPointer("glVertexAttrib4NivARB");
    if ( Wm3glVertexAttrib4NivARB )
        ++Wm3NumFunctions_GL_ARB_vertex_program;

    Wm3glVertexAttrib4NsvARB = (pfn_glVertexAttrib4NsvARB)GetFunctionPointer("glVertexAttrib4NsvARB");
    if ( Wm3glVertexAttrib4NsvARB )
        ++Wm3NumFunctions_GL_ARB_vertex_program;

    Wm3glVertexAttrib4NubARB = (pfn_glVertexAttrib4NubARB)GetFunctionPointer("glVertexAttrib4NubARB");
    if ( Wm3glVertexAttrib4NubARB )
        ++Wm3NumFunctions_GL_ARB_vertex_program;

    Wm3glVertexAttrib4NubvARB = (pfn_glVertexAttrib4NubvARB)GetFunctionPointer("glVertexAttrib4NubvARB");
    if ( Wm3glVertexAttrib4NubvARB )
        ++Wm3NumFunctions_GL_ARB_vertex_program;

    Wm3glVertexAttrib4NuivARB = (pfn_glVertexAttrib4NuivARB)GetFunctionPointer("glVertexAttrib4NuivARB");
    if ( Wm3glVertexAttrib4NuivARB )
        ++Wm3NumFunctions_GL_ARB_vertex_program;

    Wm3glVertexAttrib4NusvARB = (pfn_glVertexAttrib4NusvARB)GetFunctionPointer("glVertexAttrib4NusvARB");
    if ( Wm3glVertexAttrib4NusvARB )
        ++Wm3NumFunctions_GL_ARB_vertex_program;

    Wm3glVertexAttrib4bvARB = (pfn_glVertexAttrib4bvARB)GetFunctionPointer("glVertexAttrib4bvARB");
    if ( Wm3glVertexAttrib4bvARB )
        ++Wm3NumFunctions_GL_ARB_vertex_program;

    Wm3glVertexAttrib4dARB = (pfn_glVertexAttrib4dARB)GetFunctionPointer("glVertexAttrib4dARB");
    if ( Wm3glVertexAttrib4dARB )
        ++Wm3NumFunctions_GL_ARB_vertex_program;

    Wm3glVertexAttrib4dvARB = (pfn_glVertexAttrib4dvARB)GetFunctionPointer("glVertexAttrib4dvARB");
    if ( Wm3glVertexAttrib4dvARB )
        ++Wm3NumFunctions_GL_ARB_vertex_program;

    Wm3glVertexAttrib4fARB = (pfn_glVertexAttrib4fARB)GetFunctionPointer("glVertexAttrib4fARB");
    if ( Wm3glVertexAttrib4fARB )
        ++Wm3NumFunctions_GL_ARB_vertex_program;

    Wm3glVertexAttrib4fvARB = (pfn_glVertexAttrib4fvARB)GetFunctionPointer("glVertexAttrib4fvARB");
    if ( Wm3glVertexAttrib4fvARB )
        ++Wm3NumFunctions_GL_ARB_vertex_program;

    Wm3glVertexAttrib4ivARB = (pfn_glVertexAttrib4ivARB)GetFunctionPointer("glVertexAttrib4ivARB");
    if ( Wm3glVertexAttrib4ivARB )
        ++Wm3NumFunctions_GL_ARB_vertex_program;

    Wm3glVertexAttrib4sARB = (pfn_glVertexAttrib4sARB)GetFunctionPointer("glVertexAttrib4sARB");
    if ( Wm3glVertexAttrib4sARB )
        ++Wm3NumFunctions_GL_ARB_vertex_program;

    Wm3glVertexAttrib4svARB = (pfn_glVertexAttrib4svARB)GetFunctionPointer("glVertexAttrib4svARB");
    if ( Wm3glVertexAttrib4svARB )
        ++Wm3NumFunctions_GL_ARB_vertex_program;

    Wm3glVertexAttrib4ubvARB = (pfn_glVertexAttrib4ubvARB)GetFunctionPointer("glVertexAttrib4ubvARB");
    if ( Wm3glVertexAttrib4ubvARB )
        ++Wm3NumFunctions_GL_ARB_vertex_program;

    Wm3glVertexAttrib4uivARB = (pfn_glVertexAttrib4uivARB)GetFunctionPointer("glVertexAttrib4uivARB");
    if ( Wm3glVertexAttrib4uivARB )
        ++Wm3NumFunctions_GL_ARB_vertex_program;

    Wm3glVertexAttrib4usvARB = (pfn_glVertexAttrib4usvARB)GetFunctionPointer("glVertexAttrib4usvARB");
    if ( Wm3glVertexAttrib4usvARB )
        ++Wm3NumFunctions_GL_ARB_vertex_program;

    Wm3glVertexAttribPointerARB = (pfn_glVertexAttribPointerARB)GetFunctionPointer("glVertexAttribPointerARB");
    if ( Wm3glVertexAttribPointerARB )
        ++Wm3NumFunctions_GL_ARB_vertex_program;

    Wm3glEnableVertexAttribArrayARB = (pfn_glEnableVertexAttribArrayARB)GetFunctionPointer("glEnableVertexAttribArrayARB");
    if ( Wm3glEnableVertexAttribArrayARB )
        ++Wm3NumFunctions_GL_ARB_vertex_program;

    Wm3glDisableVertexAttribArrayARB = (pfn_glDisableVertexAttribArrayARB)GetFunctionPointer("glDisableVertexAttribArrayARB");
    if ( Wm3glDisableVertexAttribArrayARB )
        ++Wm3NumFunctions_GL_ARB_vertex_program;

    Wm3glProgramStringARB = (pfn_glProgramStringARB)GetFunctionPointer("glProgramStringARB");
    if ( Wm3glProgramStringARB )
        ++Wm3NumFunctions_GL_ARB_vertex_program;

    Wm3glBindProgramARB = (pfn_glBindProgramARB)GetFunctionPointer("glBindProgramARB");
    if ( Wm3glBindProgramARB )
        ++Wm3NumFunctions_GL_ARB_vertex_program;

    Wm3glDeleteProgramsARB = (pfn_glDeleteProgramsARB)GetFunctionPointer("glDeleteProgramsARB");
    if ( Wm3glDeleteProgramsARB )
        ++Wm3NumFunctions_GL_ARB_vertex_program;

    Wm3glGenProgramsARB = (pfn_glGenProgramsARB)GetFunctionPointer("glGenProgramsARB");
    if ( Wm3glGenProgramsARB )
        ++Wm3NumFunctions_GL_ARB_vertex_program;

    Wm3glProgramEnvParameter4dARB = (pfn_glProgramEnvParameter4dARB)GetFunctionPointer("glProgramEnvParameter4dARB");
    if ( Wm3glProgramEnvParameter4dARB )
        ++Wm3NumFunctions_GL_ARB_vertex_program;

    Wm3glProgramEnvParameter4dvARB = (pfn_glProgramEnvParameter4dvARB)GetFunctionPointer("glProgramEnvParameter4dvARB");
    if ( Wm3glProgramEnvParameter4dvARB )
        ++Wm3NumFunctions_GL_ARB_vertex_program;

    Wm3glProgramEnvParameter4fARB = (pfn_glProgramEnvParameter4fARB)GetFunctionPointer("glProgramEnvParameter4fARB");
    if ( Wm3glProgramEnvParameter4fARB )
        ++Wm3NumFunctions_GL_ARB_vertex_program;

    Wm3glProgramEnvParameter4fvARB = (pfn_glProgramEnvParameter4fvARB)GetFunctionPointer("glProgramEnvParameter4fvARB");
    if ( Wm3glProgramEnvParameter4fvARB )
        ++Wm3NumFunctions_GL_ARB_vertex_program;

    Wm3glProgramLocalParameter4dARB = (pfn_glProgramLocalParameter4dARB)GetFunctionPointer("glProgramLocalParameter4dARB");
    if ( Wm3glProgramLocalParameter4dARB )
        ++Wm3NumFunctions_GL_ARB_vertex_program;

    Wm3glProgramLocalParameter4dvARB = (pfn_glProgramLocalParameter4dvARB)GetFunctionPointer("glProgramLocalParameter4dvARB");
    if ( Wm3glProgramLocalParameter4dvARB )
        ++Wm3NumFunctions_GL_ARB_vertex_program;

    Wm3glProgramLocalParameter4fARB = (pfn_glProgramLocalParameter4fARB)GetFunctionPointer("glProgramLocalParameter4fARB");
    if ( Wm3glProgramLocalParameter4fARB )
        ++Wm3NumFunctions_GL_ARB_vertex_program;

    Wm3glProgramLocalParameter4fvARB = (pfn_glProgramLocalParameter4fvARB)GetFunctionPointer("glProgramLocalParameter4fvARB");
    if ( Wm3glProgramLocalParameter4fvARB )
        ++Wm3NumFunctions_GL_ARB_vertex_program;

    Wm3glGetProgramEnvParameterdvARB = (pfn_glGetProgramEnvParameterdvARB)GetFunctionPointer("glGetProgramEnvParameterdvARB");
    if ( Wm3glGetProgramEnvParameterdvARB )
        ++Wm3NumFunctions_GL_ARB_vertex_program;

    Wm3glGetProgramEnvParameterfvARB = (pfn_glGetProgramEnvParameterfvARB)GetFunctionPointer("glGetProgramEnvParameterfvARB");
    if ( Wm3glGetProgramEnvParameterfvARB )
        ++Wm3NumFunctions_GL_ARB_vertex_program;

    Wm3glGetProgramLocalParameterdvARB = (pfn_glGetProgramLocalParameterdvARB)GetFunctionPointer("glGetProgramLocalParameterdvARB");
    if ( Wm3glGetProgramLocalParameterdvARB )
        ++Wm3NumFunctions_GL_ARB_vertex_program;

    Wm3glGetProgramLocalParameterfvARB = (pfn_glGetProgramLocalParameterfvARB)GetFunctionPointer("glGetProgramLocalParameterfvARB");
    if ( Wm3glGetProgramLocalParameterfvARB )
        ++Wm3NumFunctions_GL_ARB_vertex_program;

    Wm3glGetProgramivARB = (pfn_glGetProgramivARB)GetFunctionPointer("glGetProgramivARB");
    if ( Wm3glGetProgramivARB )
        ++Wm3NumFunctions_GL_ARB_vertex_program;

    Wm3glGetProgramStringARB = (pfn_glGetProgramStringARB)GetFunctionPointer("glGetProgramStringARB");
    if ( Wm3glGetProgramStringARB )
        ++Wm3NumFunctions_GL_ARB_vertex_program;

    Wm3glGetVertexAttribdvARB = (pfn_glGetVertexAttribdvARB)GetFunctionPointer("glGetVertexAttribdvARB");
    if ( Wm3glGetVertexAttribdvARB )
        ++Wm3NumFunctions_GL_ARB_vertex_program;

    Wm3glGetVertexAttribfvARB = (pfn_glGetVertexAttribfvARB)GetFunctionPointer("glGetVertexAttribfvARB");
    if ( Wm3glGetVertexAttribfvARB )
        ++Wm3NumFunctions_GL_ARB_vertex_program;

    Wm3glGetVertexAttribivARB = (pfn_glGetVertexAttribivARB)GetFunctionPointer("glGetVertexAttribivARB");
    if ( Wm3glGetVertexAttribivARB )
        ++Wm3NumFunctions_GL_ARB_vertex_program;

    Wm3glGetVertexAttribPointervARB = (pfn_glGetVertexAttribPointervARB)GetFunctionPointer("glGetVertexAttribPointervARB");
    if ( Wm3glGetVertexAttribPointervARB )
        ++Wm3NumFunctions_GL_ARB_vertex_program;

    Wm3glIsProgramARB = (pfn_glIsProgramARB)GetFunctionPointer("glIsProgramARB");
    if ( Wm3glIsProgramARB )
        ++Wm3NumFunctions_GL_ARB_vertex_program;

    if ( Wm3NumFunctions_GL_ARB_vertex_program == 62 )
        Wm3Exists_GL_ARB_vertex_program = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_ARB_vertex_program = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_ARB_vertex_program ()
{
    Wm3NumFunctions_GL_ARB_vertex_program = 0;
    Wm3Exists_GL_ARB_vertex_program = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_ARB_fragment_program;
int Wm3NumFunctions_GL_ARB_fragment_program;
#ifdef WM3_DEFINED_GL_ARB_fragment_program
static void Init_GL_ARB_fragment_program ()
{
    Wm3NumFunctions_GL_ARB_fragment_program = 0;
    Wm3Exists_GL_ARB_fragment_program = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_ARB_fragment_program ()
{
    Wm3NumFunctions_GL_ARB_fragment_program = 0;
    Wm3Exists_GL_ARB_fragment_program = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_ARB_vertex_buffer_object;
int Wm3NumFunctions_GL_ARB_vertex_buffer_object;
#ifdef WM3_DEFINED_GL_ARB_vertex_buffer_object
pfn_glBindBufferARB Wm3glBindBufferARB = 0;
pfn_glDeleteBuffersARB Wm3glDeleteBuffersARB = 0;
pfn_glGenBuffersARB Wm3glGenBuffersARB = 0;
pfn_glIsBufferARB Wm3glIsBufferARB = 0;
pfn_glBufferDataARB Wm3glBufferDataARB = 0;
pfn_glBufferSubDataARB Wm3glBufferSubDataARB = 0;
pfn_glGetBufferSubDataARB Wm3glGetBufferSubDataARB = 0;
pfn_glMapBufferARB Wm3glMapBufferARB = 0;
pfn_glUnmapBufferARB Wm3glUnmapBufferARB = 0;
pfn_glGetBufferParameterivARB Wm3glGetBufferParameterivARB = 0;
pfn_glGetBufferPointervARB Wm3glGetBufferPointervARB = 0;

static void Init_GL_ARB_vertex_buffer_object ()
{
    Wm3NumFunctions_GL_ARB_vertex_buffer_object = 0;

    Wm3glBindBufferARB = (pfn_glBindBufferARB)GetFunctionPointer("glBindBufferARB");
    if ( Wm3glBindBufferARB )
        ++Wm3NumFunctions_GL_ARB_vertex_buffer_object;

    Wm3glDeleteBuffersARB = (pfn_glDeleteBuffersARB)GetFunctionPointer("glDeleteBuffersARB");
    if ( Wm3glDeleteBuffersARB )
        ++Wm3NumFunctions_GL_ARB_vertex_buffer_object;

    Wm3glGenBuffersARB = (pfn_glGenBuffersARB)GetFunctionPointer("glGenBuffersARB");
    if ( Wm3glGenBuffersARB )
        ++Wm3NumFunctions_GL_ARB_vertex_buffer_object;

    Wm3glIsBufferARB = (pfn_glIsBufferARB)GetFunctionPointer("glIsBufferARB");
    if ( Wm3glIsBufferARB )
        ++Wm3NumFunctions_GL_ARB_vertex_buffer_object;

    Wm3glBufferDataARB = (pfn_glBufferDataARB)GetFunctionPointer("glBufferDataARB");
    if ( Wm3glBufferDataARB )
        ++Wm3NumFunctions_GL_ARB_vertex_buffer_object;

    Wm3glBufferSubDataARB = (pfn_glBufferSubDataARB)GetFunctionPointer("glBufferSubDataARB");
    if ( Wm3glBufferSubDataARB )
        ++Wm3NumFunctions_GL_ARB_vertex_buffer_object;

    Wm3glGetBufferSubDataARB = (pfn_glGetBufferSubDataARB)GetFunctionPointer("glGetBufferSubDataARB");
    if ( Wm3glGetBufferSubDataARB )
        ++Wm3NumFunctions_GL_ARB_vertex_buffer_object;

    Wm3glMapBufferARB = (pfn_glMapBufferARB)GetFunctionPointer("glMapBufferARB");
    if ( Wm3glMapBufferARB )
        ++Wm3NumFunctions_GL_ARB_vertex_buffer_object;

    Wm3glUnmapBufferARB = (pfn_glUnmapBufferARB)GetFunctionPointer("glUnmapBufferARB");
    if ( Wm3glUnmapBufferARB )
        ++Wm3NumFunctions_GL_ARB_vertex_buffer_object;

    Wm3glGetBufferParameterivARB = (pfn_glGetBufferParameterivARB)GetFunctionPointer("glGetBufferParameterivARB");
    if ( Wm3glGetBufferParameterivARB )
        ++Wm3NumFunctions_GL_ARB_vertex_buffer_object;

    Wm3glGetBufferPointervARB = (pfn_glGetBufferPointervARB)GetFunctionPointer("glGetBufferPointervARB");
    if ( Wm3glGetBufferPointervARB )
        ++Wm3NumFunctions_GL_ARB_vertex_buffer_object;

    if ( Wm3NumFunctions_GL_ARB_vertex_buffer_object == 11 )
        Wm3Exists_GL_ARB_vertex_buffer_object = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_ARB_vertex_buffer_object = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_ARB_vertex_buffer_object ()
{
    Wm3NumFunctions_GL_ARB_vertex_buffer_object = 0;
    Wm3Exists_GL_ARB_vertex_buffer_object = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_ARB_occlusion_query;
int Wm3NumFunctions_GL_ARB_occlusion_query;
#ifdef WM3_DEFINED_GL_ARB_occlusion_query
pfn_glGenQueriesARB Wm3glGenQueriesARB = 0;
pfn_glDeleteQueriesARB Wm3glDeleteQueriesARB = 0;
pfn_glIsQueryARB Wm3glIsQueryARB = 0;
pfn_glBeginQueryARB Wm3glBeginQueryARB = 0;
pfn_glEndQueryARB Wm3glEndQueryARB = 0;
pfn_glGetQueryivARB Wm3glGetQueryivARB = 0;
pfn_glGetQueryObjectivARB Wm3glGetQueryObjectivARB = 0;
pfn_glGetQueryObjectuivARB Wm3glGetQueryObjectuivARB = 0;

static void Init_GL_ARB_occlusion_query ()
{
    Wm3NumFunctions_GL_ARB_occlusion_query = 0;

    Wm3glGenQueriesARB = (pfn_glGenQueriesARB)GetFunctionPointer("glGenQueriesARB");
    if ( Wm3glGenQueriesARB )
        ++Wm3NumFunctions_GL_ARB_occlusion_query;

    Wm3glDeleteQueriesARB = (pfn_glDeleteQueriesARB)GetFunctionPointer("glDeleteQueriesARB");
    if ( Wm3glDeleteQueriesARB )
        ++Wm3NumFunctions_GL_ARB_occlusion_query;

    Wm3glIsQueryARB = (pfn_glIsQueryARB)GetFunctionPointer("glIsQueryARB");
    if ( Wm3glIsQueryARB )
        ++Wm3NumFunctions_GL_ARB_occlusion_query;

    Wm3glBeginQueryARB = (pfn_glBeginQueryARB)GetFunctionPointer("glBeginQueryARB");
    if ( Wm3glBeginQueryARB )
        ++Wm3NumFunctions_GL_ARB_occlusion_query;

    Wm3glEndQueryARB = (pfn_glEndQueryARB)GetFunctionPointer("glEndQueryARB");
    if ( Wm3glEndQueryARB )
        ++Wm3NumFunctions_GL_ARB_occlusion_query;

    Wm3glGetQueryivARB = (pfn_glGetQueryivARB)GetFunctionPointer("glGetQueryivARB");
    if ( Wm3glGetQueryivARB )
        ++Wm3NumFunctions_GL_ARB_occlusion_query;

    Wm3glGetQueryObjectivARB = (pfn_glGetQueryObjectivARB)GetFunctionPointer("glGetQueryObjectivARB");
    if ( Wm3glGetQueryObjectivARB )
        ++Wm3NumFunctions_GL_ARB_occlusion_query;

    Wm3glGetQueryObjectuivARB = (pfn_glGetQueryObjectuivARB)GetFunctionPointer("glGetQueryObjectuivARB");
    if ( Wm3glGetQueryObjectuivARB )
        ++Wm3NumFunctions_GL_ARB_occlusion_query;

    if ( Wm3NumFunctions_GL_ARB_occlusion_query == 8 )
        Wm3Exists_GL_ARB_occlusion_query = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_ARB_occlusion_query = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_ARB_occlusion_query ()
{
    Wm3NumFunctions_GL_ARB_occlusion_query = 0;
    Wm3Exists_GL_ARB_occlusion_query = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_ARB_shader_objects;
int Wm3NumFunctions_GL_ARB_shader_objects;
#ifdef WM3_DEFINED_GL_ARB_shader_objects
pfn_glDeleteObjectARB Wm3glDeleteObjectARB = 0;
pfn_glGetHandleARB Wm3glGetHandleARB = 0;
pfn_glDetachObjectARB Wm3glDetachObjectARB = 0;
pfn_glCreateShaderObjectARB Wm3glCreateShaderObjectARB = 0;
pfn_glShaderSourceARB Wm3glShaderSourceARB = 0;
pfn_glCompileShaderARB Wm3glCompileShaderARB = 0;
pfn_glCreateProgramObjectARB Wm3glCreateProgramObjectARB = 0;
pfn_glAttachObjectARB Wm3glAttachObjectARB = 0;
pfn_glLinkProgramARB Wm3glLinkProgramARB = 0;
pfn_glUseProgramObjectARB Wm3glUseProgramObjectARB = 0;
pfn_glValidateProgramARB Wm3glValidateProgramARB = 0;
pfn_glUniform1fARB Wm3glUniform1fARB = 0;
pfn_glUniform2fARB Wm3glUniform2fARB = 0;
pfn_glUniform3fARB Wm3glUniform3fARB = 0;
pfn_glUniform4fARB Wm3glUniform4fARB = 0;
pfn_glUniform1iARB Wm3glUniform1iARB = 0;
pfn_glUniform2iARB Wm3glUniform2iARB = 0;
pfn_glUniform3iARB Wm3glUniform3iARB = 0;
pfn_glUniform4iARB Wm3glUniform4iARB = 0;
pfn_glUniform1fvARB Wm3glUniform1fvARB = 0;
pfn_glUniform2fvARB Wm3glUniform2fvARB = 0;
pfn_glUniform3fvARB Wm3glUniform3fvARB = 0;
pfn_glUniform4fvARB Wm3glUniform4fvARB = 0;
pfn_glUniform1ivARB Wm3glUniform1ivARB = 0;
pfn_glUniform2ivARB Wm3glUniform2ivARB = 0;
pfn_glUniform3ivARB Wm3glUniform3ivARB = 0;
pfn_glUniform4ivARB Wm3glUniform4ivARB = 0;
pfn_glUniformMatrix2fvARB Wm3glUniformMatrix2fvARB = 0;
pfn_glUniformMatrix3fvARB Wm3glUniformMatrix3fvARB = 0;
pfn_glUniformMatrix4fvARB Wm3glUniformMatrix4fvARB = 0;
pfn_glGetObjectParameterfvARB Wm3glGetObjectParameterfvARB = 0;
pfn_glGetObjectParameterivARB Wm3glGetObjectParameterivARB = 0;
pfn_glGetInfoLogARB Wm3glGetInfoLogARB = 0;
pfn_glGetAttachedObjectsARB Wm3glGetAttachedObjectsARB = 0;
pfn_glGetUniformLocationARB Wm3glGetUniformLocationARB = 0;
pfn_glGetActiveUniformARB Wm3glGetActiveUniformARB = 0;
pfn_glGetUniformfvARB Wm3glGetUniformfvARB = 0;
pfn_glGetUniformivARB Wm3glGetUniformivARB = 0;
pfn_glGetShaderSourceARB Wm3glGetShaderSourceARB = 0;

static void Init_GL_ARB_shader_objects ()
{
    Wm3NumFunctions_GL_ARB_shader_objects = 0;

    Wm3glDeleteObjectARB = (pfn_glDeleteObjectARB)GetFunctionPointer("glDeleteObjectARB");
    if ( Wm3glDeleteObjectARB )
        ++Wm3NumFunctions_GL_ARB_shader_objects;

    Wm3glGetHandleARB = (pfn_glGetHandleARB)GetFunctionPointer("glGetHandleARB");
    if ( Wm3glGetHandleARB )
        ++Wm3NumFunctions_GL_ARB_shader_objects;

    Wm3glDetachObjectARB = (pfn_glDetachObjectARB)GetFunctionPointer("glDetachObjectARB");
    if ( Wm3glDetachObjectARB )
        ++Wm3NumFunctions_GL_ARB_shader_objects;

    Wm3glCreateShaderObjectARB = (pfn_glCreateShaderObjectARB)GetFunctionPointer("glCreateShaderObjectARB");
    if ( Wm3glCreateShaderObjectARB )
        ++Wm3NumFunctions_GL_ARB_shader_objects;

    Wm3glShaderSourceARB = (pfn_glShaderSourceARB)GetFunctionPointer("glShaderSourceARB");
    if ( Wm3glShaderSourceARB )
        ++Wm3NumFunctions_GL_ARB_shader_objects;

    Wm3glCompileShaderARB = (pfn_glCompileShaderARB)GetFunctionPointer("glCompileShaderARB");
    if ( Wm3glCompileShaderARB )
        ++Wm3NumFunctions_GL_ARB_shader_objects;

    Wm3glCreateProgramObjectARB = (pfn_glCreateProgramObjectARB)GetFunctionPointer("glCreateProgramObjectARB");
    if ( Wm3glCreateProgramObjectARB )
        ++Wm3NumFunctions_GL_ARB_shader_objects;

    Wm3glAttachObjectARB = (pfn_glAttachObjectARB)GetFunctionPointer("glAttachObjectARB");
    if ( Wm3glAttachObjectARB )
        ++Wm3NumFunctions_GL_ARB_shader_objects;

    Wm3glLinkProgramARB = (pfn_glLinkProgramARB)GetFunctionPointer("glLinkProgramARB");
    if ( Wm3glLinkProgramARB )
        ++Wm3NumFunctions_GL_ARB_shader_objects;

    Wm3glUseProgramObjectARB = (pfn_glUseProgramObjectARB)GetFunctionPointer("glUseProgramObjectARB");
    if ( Wm3glUseProgramObjectARB )
        ++Wm3NumFunctions_GL_ARB_shader_objects;

    Wm3glValidateProgramARB = (pfn_glValidateProgramARB)GetFunctionPointer("glValidateProgramARB");
    if ( Wm3glValidateProgramARB )
        ++Wm3NumFunctions_GL_ARB_shader_objects;

    Wm3glUniform1fARB = (pfn_glUniform1fARB)GetFunctionPointer("glUniform1fARB");
    if ( Wm3glUniform1fARB )
        ++Wm3NumFunctions_GL_ARB_shader_objects;

    Wm3glUniform2fARB = (pfn_glUniform2fARB)GetFunctionPointer("glUniform2fARB");
    if ( Wm3glUniform2fARB )
        ++Wm3NumFunctions_GL_ARB_shader_objects;

    Wm3glUniform3fARB = (pfn_glUniform3fARB)GetFunctionPointer("glUniform3fARB");
    if ( Wm3glUniform3fARB )
        ++Wm3NumFunctions_GL_ARB_shader_objects;

    Wm3glUniform4fARB = (pfn_glUniform4fARB)GetFunctionPointer("glUniform4fARB");
    if ( Wm3glUniform4fARB )
        ++Wm3NumFunctions_GL_ARB_shader_objects;

    Wm3glUniform1iARB = (pfn_glUniform1iARB)GetFunctionPointer("glUniform1iARB");
    if ( Wm3glUniform1iARB )
        ++Wm3NumFunctions_GL_ARB_shader_objects;

    Wm3glUniform2iARB = (pfn_glUniform2iARB)GetFunctionPointer("glUniform2iARB");
    if ( Wm3glUniform2iARB )
        ++Wm3NumFunctions_GL_ARB_shader_objects;

    Wm3glUniform3iARB = (pfn_glUniform3iARB)GetFunctionPointer("glUniform3iARB");
    if ( Wm3glUniform3iARB )
        ++Wm3NumFunctions_GL_ARB_shader_objects;

    Wm3glUniform4iARB = (pfn_glUniform4iARB)GetFunctionPointer("glUniform4iARB");
    if ( Wm3glUniform4iARB )
        ++Wm3NumFunctions_GL_ARB_shader_objects;

    Wm3glUniform1fvARB = (pfn_glUniform1fvARB)GetFunctionPointer("glUniform1fvARB");
    if ( Wm3glUniform1fvARB )
        ++Wm3NumFunctions_GL_ARB_shader_objects;

    Wm3glUniform2fvARB = (pfn_glUniform2fvARB)GetFunctionPointer("glUniform2fvARB");
    if ( Wm3glUniform2fvARB )
        ++Wm3NumFunctions_GL_ARB_shader_objects;

    Wm3glUniform3fvARB = (pfn_glUniform3fvARB)GetFunctionPointer("glUniform3fvARB");
    if ( Wm3glUniform3fvARB )
        ++Wm3NumFunctions_GL_ARB_shader_objects;

    Wm3glUniform4fvARB = (pfn_glUniform4fvARB)GetFunctionPointer("glUniform4fvARB");
    if ( Wm3glUniform4fvARB )
        ++Wm3NumFunctions_GL_ARB_shader_objects;

    Wm3glUniform1ivARB = (pfn_glUniform1ivARB)GetFunctionPointer("glUniform1ivARB");
    if ( Wm3glUniform1ivARB )
        ++Wm3NumFunctions_GL_ARB_shader_objects;

    Wm3glUniform2ivARB = (pfn_glUniform2ivARB)GetFunctionPointer("glUniform2ivARB");
    if ( Wm3glUniform2ivARB )
        ++Wm3NumFunctions_GL_ARB_shader_objects;

    Wm3glUniform3ivARB = (pfn_glUniform3ivARB)GetFunctionPointer("glUniform3ivARB");
    if ( Wm3glUniform3ivARB )
        ++Wm3NumFunctions_GL_ARB_shader_objects;

    Wm3glUniform4ivARB = (pfn_glUniform4ivARB)GetFunctionPointer("glUniform4ivARB");
    if ( Wm3glUniform4ivARB )
        ++Wm3NumFunctions_GL_ARB_shader_objects;

    Wm3glUniformMatrix2fvARB = (pfn_glUniformMatrix2fvARB)GetFunctionPointer("glUniformMatrix2fvARB");
    if ( Wm3glUniformMatrix2fvARB )
        ++Wm3NumFunctions_GL_ARB_shader_objects;

    Wm3glUniformMatrix3fvARB = (pfn_glUniformMatrix3fvARB)GetFunctionPointer("glUniformMatrix3fvARB");
    if ( Wm3glUniformMatrix3fvARB )
        ++Wm3NumFunctions_GL_ARB_shader_objects;

    Wm3glUniformMatrix4fvARB = (pfn_glUniformMatrix4fvARB)GetFunctionPointer("glUniformMatrix4fvARB");
    if ( Wm3glUniformMatrix4fvARB )
        ++Wm3NumFunctions_GL_ARB_shader_objects;

    Wm3glGetObjectParameterfvARB = (pfn_glGetObjectParameterfvARB)GetFunctionPointer("glGetObjectParameterfvARB");
    if ( Wm3glGetObjectParameterfvARB )
        ++Wm3NumFunctions_GL_ARB_shader_objects;

    Wm3glGetObjectParameterivARB = (pfn_glGetObjectParameterivARB)GetFunctionPointer("glGetObjectParameterivARB");
    if ( Wm3glGetObjectParameterivARB )
        ++Wm3NumFunctions_GL_ARB_shader_objects;

    Wm3glGetInfoLogARB = (pfn_glGetInfoLogARB)GetFunctionPointer("glGetInfoLogARB");
    if ( Wm3glGetInfoLogARB )
        ++Wm3NumFunctions_GL_ARB_shader_objects;

    Wm3glGetAttachedObjectsARB = (pfn_glGetAttachedObjectsARB)GetFunctionPointer("glGetAttachedObjectsARB");
    if ( Wm3glGetAttachedObjectsARB )
        ++Wm3NumFunctions_GL_ARB_shader_objects;

    Wm3glGetUniformLocationARB = (pfn_glGetUniformLocationARB)GetFunctionPointer("glGetUniformLocationARB");
    if ( Wm3glGetUniformLocationARB )
        ++Wm3NumFunctions_GL_ARB_shader_objects;

    Wm3glGetActiveUniformARB = (pfn_glGetActiveUniformARB)GetFunctionPointer("glGetActiveUniformARB");
    if ( Wm3glGetActiveUniformARB )
        ++Wm3NumFunctions_GL_ARB_shader_objects;

    Wm3glGetUniformfvARB = (pfn_glGetUniformfvARB)GetFunctionPointer("glGetUniformfvARB");
    if ( Wm3glGetUniformfvARB )
        ++Wm3NumFunctions_GL_ARB_shader_objects;

    Wm3glGetUniformivARB = (pfn_glGetUniformivARB)GetFunctionPointer("glGetUniformivARB");
    if ( Wm3glGetUniformivARB )
        ++Wm3NumFunctions_GL_ARB_shader_objects;

    Wm3glGetShaderSourceARB = (pfn_glGetShaderSourceARB)GetFunctionPointer("glGetShaderSourceARB");
    if ( Wm3glGetShaderSourceARB )
        ++Wm3NumFunctions_GL_ARB_shader_objects;

    if ( Wm3NumFunctions_GL_ARB_shader_objects == 39 )
        Wm3Exists_GL_ARB_shader_objects = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_ARB_shader_objects = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_ARB_shader_objects ()
{
    Wm3NumFunctions_GL_ARB_shader_objects = 0;
    Wm3Exists_GL_ARB_shader_objects = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_ARB_vertex_shader;
int Wm3NumFunctions_GL_ARB_vertex_shader;
#ifdef WM3_DEFINED_GL_ARB_vertex_shader
pfn_glBindAttribLocationARB Wm3glBindAttribLocationARB = 0;
pfn_glGetActiveAttribARB Wm3glGetActiveAttribARB = 0;
pfn_glGetAttribLocationARB Wm3glGetAttribLocationARB = 0;

static void Init_GL_ARB_vertex_shader ()
{
    Wm3NumFunctions_GL_ARB_vertex_shader = 0;

    Wm3glBindAttribLocationARB = (pfn_glBindAttribLocationARB)GetFunctionPointer("glBindAttribLocationARB");
    if ( Wm3glBindAttribLocationARB )
        ++Wm3NumFunctions_GL_ARB_vertex_shader;

    Wm3glGetActiveAttribARB = (pfn_glGetActiveAttribARB)GetFunctionPointer("glGetActiveAttribARB");
    if ( Wm3glGetActiveAttribARB )
        ++Wm3NumFunctions_GL_ARB_vertex_shader;

    Wm3glGetAttribLocationARB = (pfn_glGetAttribLocationARB)GetFunctionPointer("glGetAttribLocationARB");
    if ( Wm3glGetAttribLocationARB )
        ++Wm3NumFunctions_GL_ARB_vertex_shader;

    if ( Wm3NumFunctions_GL_ARB_vertex_shader == 3 )
        Wm3Exists_GL_ARB_vertex_shader = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_ARB_vertex_shader = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_ARB_vertex_shader ()
{
    Wm3NumFunctions_GL_ARB_vertex_shader = 0;
    Wm3Exists_GL_ARB_vertex_shader = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_ARB_fragment_shader;
int Wm3NumFunctions_GL_ARB_fragment_shader;
#ifdef WM3_DEFINED_GL_ARB_fragment_shader
static void Init_GL_ARB_fragment_shader ()
{
    Wm3NumFunctions_GL_ARB_fragment_shader = 0;
    Wm3Exists_GL_ARB_fragment_shader = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_ARB_fragment_shader ()
{
    Wm3NumFunctions_GL_ARB_fragment_shader = 0;
    Wm3Exists_GL_ARB_fragment_shader = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_ARB_shading_language_100;
int Wm3NumFunctions_GL_ARB_shading_language_100;
#ifdef WM3_DEFINED_GL_ARB_shading_language_100
static void Init_GL_ARB_shading_language_100 ()
{
    Wm3NumFunctions_GL_ARB_shading_language_100 = 0;
    Wm3Exists_GL_ARB_shading_language_100 = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_ARB_shading_language_100 ()
{
    Wm3NumFunctions_GL_ARB_shading_language_100 = 0;
    Wm3Exists_GL_ARB_shading_language_100 = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_ARB_texture_non_power_of_two;
int Wm3NumFunctions_GL_ARB_texture_non_power_of_two;
#ifdef WM3_DEFINED_GL_ARB_texture_non_power_of_two
static void Init_GL_ARB_texture_non_power_of_two ()
{
    Wm3NumFunctions_GL_ARB_texture_non_power_of_two = 0;
    Wm3Exists_GL_ARB_texture_non_power_of_two = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_ARB_texture_non_power_of_two ()
{
    Wm3NumFunctions_GL_ARB_texture_non_power_of_two = 0;
    Wm3Exists_GL_ARB_texture_non_power_of_two = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_ARB_point_sprite;
int Wm3NumFunctions_GL_ARB_point_sprite;
#ifdef WM3_DEFINED_GL_ARB_point_sprite
static void Init_GL_ARB_point_sprite ()
{
    Wm3NumFunctions_GL_ARB_point_sprite = 0;
    Wm3Exists_GL_ARB_point_sprite = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_ARB_point_sprite ()
{
    Wm3NumFunctions_GL_ARB_point_sprite = 0;
    Wm3Exists_GL_ARB_point_sprite = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_ARB_fragment_program_shadow;
int Wm3NumFunctions_GL_ARB_fragment_program_shadow;
#ifdef WM3_DEFINED_GL_ARB_fragment_program_shadow
static void Init_GL_ARB_fragment_program_shadow ()
{
    Wm3NumFunctions_GL_ARB_fragment_program_shadow = 0;
    Wm3Exists_GL_ARB_fragment_program_shadow = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_ARB_fragment_program_shadow ()
{
    Wm3NumFunctions_GL_ARB_fragment_program_shadow = 0;
    Wm3Exists_GL_ARB_fragment_program_shadow = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_ARB_draw_buffers;
int Wm3NumFunctions_GL_ARB_draw_buffers;
#ifdef WM3_DEFINED_GL_ARB_draw_buffers
pfn_glDrawBuffersARB Wm3glDrawBuffersARB = 0;

static void Init_GL_ARB_draw_buffers ()
{
    Wm3NumFunctions_GL_ARB_draw_buffers = 0;

    Wm3glDrawBuffersARB = (pfn_glDrawBuffersARB)GetFunctionPointer("glDrawBuffersARB");
    if ( Wm3glDrawBuffersARB )
        ++Wm3NumFunctions_GL_ARB_draw_buffers;

    if ( Wm3NumFunctions_GL_ARB_draw_buffers == 1 )
        Wm3Exists_GL_ARB_draw_buffers = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_ARB_draw_buffers = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_ARB_draw_buffers ()
{
    Wm3NumFunctions_GL_ARB_draw_buffers = 0;
    Wm3Exists_GL_ARB_draw_buffers = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_ARB_texture_rectangle;
int Wm3NumFunctions_GL_ARB_texture_rectangle;
#ifdef WM3_DEFINED_GL_ARB_texture_rectangle
static void Init_GL_ARB_texture_rectangle ()
{
    Wm3NumFunctions_GL_ARB_texture_rectangle = 0;
    Wm3Exists_GL_ARB_texture_rectangle = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_ARB_texture_rectangle ()
{
    Wm3NumFunctions_GL_ARB_texture_rectangle = 0;
    Wm3Exists_GL_ARB_texture_rectangle = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_ARB_color_buffer_float;
int Wm3NumFunctions_GL_ARB_color_buffer_float;
#ifdef WM3_DEFINED_GL_ARB_color_buffer_float
pfn_glClampColorARB Wm3glClampColorARB = 0;

static void Init_GL_ARB_color_buffer_float ()
{
    Wm3NumFunctions_GL_ARB_color_buffer_float = 0;

    Wm3glClampColorARB = (pfn_glClampColorARB)GetFunctionPointer("glClampColorARB");
    if ( Wm3glClampColorARB )
        ++Wm3NumFunctions_GL_ARB_color_buffer_float;

    if ( Wm3NumFunctions_GL_ARB_color_buffer_float == 1 )
        Wm3Exists_GL_ARB_color_buffer_float = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_ARB_color_buffer_float = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_ARB_color_buffer_float ()
{
    Wm3NumFunctions_GL_ARB_color_buffer_float = 0;
    Wm3Exists_GL_ARB_color_buffer_float = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_ARB_half_float_pixel;
int Wm3NumFunctions_GL_ARB_half_float_pixel;
#ifdef WM3_DEFINED_GL_ARB_half_float_pixel
static void Init_GL_ARB_half_float_pixel ()
{
    Wm3NumFunctions_GL_ARB_half_float_pixel = 0;
    Wm3Exists_GL_ARB_half_float_pixel = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_ARB_half_float_pixel ()
{
    Wm3NumFunctions_GL_ARB_half_float_pixel = 0;
    Wm3Exists_GL_ARB_half_float_pixel = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_ARB_texture_float;
int Wm3NumFunctions_GL_ARB_texture_float;
#ifdef WM3_DEFINED_GL_ARB_texture_float
static void Init_GL_ARB_texture_float ()
{
    Wm3NumFunctions_GL_ARB_texture_float = 0;
    Wm3Exists_GL_ARB_texture_float = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_ARB_texture_float ()
{
    Wm3NumFunctions_GL_ARB_texture_float = 0;
    Wm3Exists_GL_ARB_texture_float = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_ARB_pixel_buffer_object;
int Wm3NumFunctions_GL_ARB_pixel_buffer_object;
#ifdef WM3_DEFINED_GL_ARB_pixel_buffer_object
static void Init_GL_ARB_pixel_buffer_object ()
{
    Wm3NumFunctions_GL_ARB_pixel_buffer_object = 0;
    Wm3Exists_GL_ARB_pixel_buffer_object = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_ARB_pixel_buffer_object ()
{
    Wm3NumFunctions_GL_ARB_pixel_buffer_object = 0;
    Wm3Exists_GL_ARB_pixel_buffer_object = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_EXT_abgr;
int Wm3NumFunctions_GL_EXT_abgr;
#ifdef WM3_DEFINED_GL_EXT_abgr
static void Init_GL_EXT_abgr ()
{
    Wm3NumFunctions_GL_EXT_abgr = 0;
    Wm3Exists_GL_EXT_abgr = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_EXT_abgr ()
{
    Wm3NumFunctions_GL_EXT_abgr = 0;
    Wm3Exists_GL_EXT_abgr = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_EXT_blend_color;
int Wm3NumFunctions_GL_EXT_blend_color;
#ifdef WM3_DEFINED_GL_EXT_blend_color
pfn_glBlendColorEXT Wm3glBlendColorEXT = 0;

static void Init_GL_EXT_blend_color ()
{
    Wm3NumFunctions_GL_EXT_blend_color = 0;

    Wm3glBlendColorEXT = (pfn_glBlendColorEXT)GetFunctionPointer("glBlendColorEXT");
    if ( Wm3glBlendColorEXT )
        ++Wm3NumFunctions_GL_EXT_blend_color;

    if ( Wm3NumFunctions_GL_EXT_blend_color == 1 )
        Wm3Exists_GL_EXT_blend_color = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_EXT_blend_color = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_EXT_blend_color ()
{
    Wm3NumFunctions_GL_EXT_blend_color = 0;
    Wm3Exists_GL_EXT_blend_color = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_EXT_polygon_offset;
int Wm3NumFunctions_GL_EXT_polygon_offset;
#ifdef WM3_DEFINED_GL_EXT_polygon_offset
pfn_glPolygonOffsetEXT Wm3glPolygonOffsetEXT = 0;

static void Init_GL_EXT_polygon_offset ()
{
    Wm3NumFunctions_GL_EXT_polygon_offset = 0;

    Wm3glPolygonOffsetEXT = (pfn_glPolygonOffsetEXT)GetFunctionPointer("glPolygonOffsetEXT");
    if ( Wm3glPolygonOffsetEXT )
        ++Wm3NumFunctions_GL_EXT_polygon_offset;

    if ( Wm3NumFunctions_GL_EXT_polygon_offset == 1 )
        Wm3Exists_GL_EXT_polygon_offset = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_EXT_polygon_offset = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_EXT_polygon_offset ()
{
    Wm3NumFunctions_GL_EXT_polygon_offset = 0;
    Wm3Exists_GL_EXT_polygon_offset = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_EXT_texture;
int Wm3NumFunctions_GL_EXT_texture;
#ifdef WM3_DEFINED_GL_EXT_texture
static void Init_GL_EXT_texture ()
{
    Wm3NumFunctions_GL_EXT_texture = 0;
    Wm3Exists_GL_EXT_texture = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_EXT_texture ()
{
    Wm3NumFunctions_GL_EXT_texture = 0;
    Wm3Exists_GL_EXT_texture = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_EXT_texture3D;
int Wm3NumFunctions_GL_EXT_texture3D;
#ifdef WM3_DEFINED_GL_EXT_texture3D
pfn_glTexImage3DEXT Wm3glTexImage3DEXT = 0;
pfn_glTexSubImage3DEXT Wm3glTexSubImage3DEXT = 0;

static void Init_GL_EXT_texture3D ()
{
    Wm3NumFunctions_GL_EXT_texture3D = 0;

    Wm3glTexImage3DEXT = (pfn_glTexImage3DEXT)GetFunctionPointer("glTexImage3DEXT");
    if ( Wm3glTexImage3DEXT )
        ++Wm3NumFunctions_GL_EXT_texture3D;

    Wm3glTexSubImage3DEXT = (pfn_glTexSubImage3DEXT)GetFunctionPointer("glTexSubImage3DEXT");
    if ( Wm3glTexSubImage3DEXT )
        ++Wm3NumFunctions_GL_EXT_texture3D;

    if ( Wm3NumFunctions_GL_EXT_texture3D == 2 )
        Wm3Exists_GL_EXT_texture3D = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_EXT_texture3D = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_EXT_texture3D ()
{
    Wm3NumFunctions_GL_EXT_texture3D = 0;
    Wm3Exists_GL_EXT_texture3D = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_SGIS_texture_filter4;
int Wm3NumFunctions_GL_SGIS_texture_filter4;
#ifdef WM3_DEFINED_GL_SGIS_texture_filter4
pfn_glGetTexFilterFuncSGIS Wm3glGetTexFilterFuncSGIS = 0;
pfn_glTexFilterFuncSGIS Wm3glTexFilterFuncSGIS = 0;

static void Init_GL_SGIS_texture_filter4 ()
{
    Wm3NumFunctions_GL_SGIS_texture_filter4 = 0;

    Wm3glGetTexFilterFuncSGIS = (pfn_glGetTexFilterFuncSGIS)GetFunctionPointer("glGetTexFilterFuncSGIS");
    if ( Wm3glGetTexFilterFuncSGIS )
        ++Wm3NumFunctions_GL_SGIS_texture_filter4;

    Wm3glTexFilterFuncSGIS = (pfn_glTexFilterFuncSGIS)GetFunctionPointer("glTexFilterFuncSGIS");
    if ( Wm3glTexFilterFuncSGIS )
        ++Wm3NumFunctions_GL_SGIS_texture_filter4;

    if ( Wm3NumFunctions_GL_SGIS_texture_filter4 == 2 )
        Wm3Exists_GL_SGIS_texture_filter4 = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_SGIS_texture_filter4 = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_SGIS_texture_filter4 ()
{
    Wm3NumFunctions_GL_SGIS_texture_filter4 = 0;
    Wm3Exists_GL_SGIS_texture_filter4 = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_EXT_subtexture;
int Wm3NumFunctions_GL_EXT_subtexture;
#ifdef WM3_DEFINED_GL_EXT_subtexture
pfn_glTexSubImage1DEXT Wm3glTexSubImage1DEXT = 0;
pfn_glTexSubImage2DEXT Wm3glTexSubImage2DEXT = 0;

static void Init_GL_EXT_subtexture ()
{
    Wm3NumFunctions_GL_EXT_subtexture = 0;

    Wm3glTexSubImage1DEXT = (pfn_glTexSubImage1DEXT)GetFunctionPointer("glTexSubImage1DEXT");
    if ( Wm3glTexSubImage1DEXT )
        ++Wm3NumFunctions_GL_EXT_subtexture;

    Wm3glTexSubImage2DEXT = (pfn_glTexSubImage2DEXT)GetFunctionPointer("glTexSubImage2DEXT");
    if ( Wm3glTexSubImage2DEXT )
        ++Wm3NumFunctions_GL_EXT_subtexture;

    if ( Wm3NumFunctions_GL_EXT_subtexture == 2 )
        Wm3Exists_GL_EXT_subtexture = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_EXT_subtexture = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_EXT_subtexture ()
{
    Wm3NumFunctions_GL_EXT_subtexture = 0;
    Wm3Exists_GL_EXT_subtexture = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_EXT_copy_texture;
int Wm3NumFunctions_GL_EXT_copy_texture;
#ifdef WM3_DEFINED_GL_EXT_copy_texture
pfn_glCopyTexImage1DEXT Wm3glCopyTexImage1DEXT = 0;
pfn_glCopyTexImage2DEXT Wm3glCopyTexImage2DEXT = 0;
pfn_glCopyTexSubImage1DEXT Wm3glCopyTexSubImage1DEXT = 0;
pfn_glCopyTexSubImage2DEXT Wm3glCopyTexSubImage2DEXT = 0;
pfn_glCopyTexSubImage3DEXT Wm3glCopyTexSubImage3DEXT = 0;

static void Init_GL_EXT_copy_texture ()
{
    Wm3NumFunctions_GL_EXT_copy_texture = 0;

    Wm3glCopyTexImage1DEXT = (pfn_glCopyTexImage1DEXT)GetFunctionPointer("glCopyTexImage1DEXT");
    if ( Wm3glCopyTexImage1DEXT )
        ++Wm3NumFunctions_GL_EXT_copy_texture;

    Wm3glCopyTexImage2DEXT = (pfn_glCopyTexImage2DEXT)GetFunctionPointer("glCopyTexImage2DEXT");
    if ( Wm3glCopyTexImage2DEXT )
        ++Wm3NumFunctions_GL_EXT_copy_texture;

    Wm3glCopyTexSubImage1DEXT = (pfn_glCopyTexSubImage1DEXT)GetFunctionPointer("glCopyTexSubImage1DEXT");
    if ( Wm3glCopyTexSubImage1DEXT )
        ++Wm3NumFunctions_GL_EXT_copy_texture;

    Wm3glCopyTexSubImage2DEXT = (pfn_glCopyTexSubImage2DEXT)GetFunctionPointer("glCopyTexSubImage2DEXT");
    if ( Wm3glCopyTexSubImage2DEXT )
        ++Wm3NumFunctions_GL_EXT_copy_texture;

    Wm3glCopyTexSubImage3DEXT = (pfn_glCopyTexSubImage3DEXT)GetFunctionPointer("glCopyTexSubImage3DEXT");
    if ( Wm3glCopyTexSubImage3DEXT )
        ++Wm3NumFunctions_GL_EXT_copy_texture;

    if ( Wm3NumFunctions_GL_EXT_copy_texture == 5 )
        Wm3Exists_GL_EXT_copy_texture = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_EXT_copy_texture = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_EXT_copy_texture ()
{
    Wm3NumFunctions_GL_EXT_copy_texture = 0;
    Wm3Exists_GL_EXT_copy_texture = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_EXT_histogram;
int Wm3NumFunctions_GL_EXT_histogram;
#ifdef WM3_DEFINED_GL_EXT_histogram
pfn_glGetHistogramEXT Wm3glGetHistogramEXT = 0;
pfn_glGetHistogramParameterfvEXT Wm3glGetHistogramParameterfvEXT = 0;
pfn_glGetHistogramParameterivEXT Wm3glGetHistogramParameterivEXT = 0;
pfn_glGetMinmaxEXT Wm3glGetMinmaxEXT = 0;
pfn_glGetMinmaxParameterfvEXT Wm3glGetMinmaxParameterfvEXT = 0;
pfn_glGetMinmaxParameterivEXT Wm3glGetMinmaxParameterivEXT = 0;
pfn_glHistogramEXT Wm3glHistogramEXT = 0;
pfn_glMinmaxEXT Wm3glMinmaxEXT = 0;
pfn_glResetHistogramEXT Wm3glResetHistogramEXT = 0;
pfn_glResetMinmaxEXT Wm3glResetMinmaxEXT = 0;

static void Init_GL_EXT_histogram ()
{
    Wm3NumFunctions_GL_EXT_histogram = 0;

    Wm3glGetHistogramEXT = (pfn_glGetHistogramEXT)GetFunctionPointer("glGetHistogramEXT");
    if ( Wm3glGetHistogramEXT )
        ++Wm3NumFunctions_GL_EXT_histogram;

    Wm3glGetHistogramParameterfvEXT = (pfn_glGetHistogramParameterfvEXT)GetFunctionPointer("glGetHistogramParameterfvEXT");
    if ( Wm3glGetHistogramParameterfvEXT )
        ++Wm3NumFunctions_GL_EXT_histogram;

    Wm3glGetHistogramParameterivEXT = (pfn_glGetHistogramParameterivEXT)GetFunctionPointer("glGetHistogramParameterivEXT");
    if ( Wm3glGetHistogramParameterivEXT )
        ++Wm3NumFunctions_GL_EXT_histogram;

    Wm3glGetMinmaxEXT = (pfn_glGetMinmaxEXT)GetFunctionPointer("glGetMinmaxEXT");
    if ( Wm3glGetMinmaxEXT )
        ++Wm3NumFunctions_GL_EXT_histogram;

    Wm3glGetMinmaxParameterfvEXT = (pfn_glGetMinmaxParameterfvEXT)GetFunctionPointer("glGetMinmaxParameterfvEXT");
    if ( Wm3glGetMinmaxParameterfvEXT )
        ++Wm3NumFunctions_GL_EXT_histogram;

    Wm3glGetMinmaxParameterivEXT = (pfn_glGetMinmaxParameterivEXT)GetFunctionPointer("glGetMinmaxParameterivEXT");
    if ( Wm3glGetMinmaxParameterivEXT )
        ++Wm3NumFunctions_GL_EXT_histogram;

    Wm3glHistogramEXT = (pfn_glHistogramEXT)GetFunctionPointer("glHistogramEXT");
    if ( Wm3glHistogramEXT )
        ++Wm3NumFunctions_GL_EXT_histogram;

    Wm3glMinmaxEXT = (pfn_glMinmaxEXT)GetFunctionPointer("glMinmaxEXT");
    if ( Wm3glMinmaxEXT )
        ++Wm3NumFunctions_GL_EXT_histogram;

    Wm3glResetHistogramEXT = (pfn_glResetHistogramEXT)GetFunctionPointer("glResetHistogramEXT");
    if ( Wm3glResetHistogramEXT )
        ++Wm3NumFunctions_GL_EXT_histogram;

    Wm3glResetMinmaxEXT = (pfn_glResetMinmaxEXT)GetFunctionPointer("glResetMinmaxEXT");
    if ( Wm3glResetMinmaxEXT )
        ++Wm3NumFunctions_GL_EXT_histogram;

    if ( Wm3NumFunctions_GL_EXT_histogram == 10 )
        Wm3Exists_GL_EXT_histogram = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_EXT_histogram = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_EXT_histogram ()
{
    Wm3NumFunctions_GL_EXT_histogram = 0;
    Wm3Exists_GL_EXT_histogram = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_EXT_convolution;
int Wm3NumFunctions_GL_EXT_convolution;
#ifdef WM3_DEFINED_GL_EXT_convolution
pfn_glConvolutionFilter1DEXT Wm3glConvolutionFilter1DEXT = 0;
pfn_glConvolutionFilter2DEXT Wm3glConvolutionFilter2DEXT = 0;
pfn_glConvolutionParameterfEXT Wm3glConvolutionParameterfEXT = 0;
pfn_glConvolutionParameterfvEXT Wm3glConvolutionParameterfvEXT = 0;
pfn_glConvolutionParameteriEXT Wm3glConvolutionParameteriEXT = 0;
pfn_glConvolutionParameterivEXT Wm3glConvolutionParameterivEXT = 0;
pfn_glCopyConvolutionFilter1DEXT Wm3glCopyConvolutionFilter1DEXT = 0;
pfn_glCopyConvolutionFilter2DEXT Wm3glCopyConvolutionFilter2DEXT = 0;
pfn_glGetConvolutionFilterEXT Wm3glGetConvolutionFilterEXT = 0;
pfn_glGetConvolutionParameterfvEXT Wm3glGetConvolutionParameterfvEXT = 0;
pfn_glGetConvolutionParameterivEXT Wm3glGetConvolutionParameterivEXT = 0;
pfn_glGetSeparableFilterEXT Wm3glGetSeparableFilterEXT = 0;
pfn_glSeparableFilter2DEXT Wm3glSeparableFilter2DEXT = 0;

static void Init_GL_EXT_convolution ()
{
    Wm3NumFunctions_GL_EXT_convolution = 0;

    Wm3glConvolutionFilter1DEXT = (pfn_glConvolutionFilter1DEXT)GetFunctionPointer("glConvolutionFilter1DEXT");
    if ( Wm3glConvolutionFilter1DEXT )
        ++Wm3NumFunctions_GL_EXT_convolution;

    Wm3glConvolutionFilter2DEXT = (pfn_glConvolutionFilter2DEXT)GetFunctionPointer("glConvolutionFilter2DEXT");
    if ( Wm3glConvolutionFilter2DEXT )
        ++Wm3NumFunctions_GL_EXT_convolution;

    Wm3glConvolutionParameterfEXT = (pfn_glConvolutionParameterfEXT)GetFunctionPointer("glConvolutionParameterfEXT");
    if ( Wm3glConvolutionParameterfEXT )
        ++Wm3NumFunctions_GL_EXT_convolution;

    Wm3glConvolutionParameterfvEXT = (pfn_glConvolutionParameterfvEXT)GetFunctionPointer("glConvolutionParameterfvEXT");
    if ( Wm3glConvolutionParameterfvEXT )
        ++Wm3NumFunctions_GL_EXT_convolution;

    Wm3glConvolutionParameteriEXT = (pfn_glConvolutionParameteriEXT)GetFunctionPointer("glConvolutionParameteriEXT");
    if ( Wm3glConvolutionParameteriEXT )
        ++Wm3NumFunctions_GL_EXT_convolution;

    Wm3glConvolutionParameterivEXT = (pfn_glConvolutionParameterivEXT)GetFunctionPointer("glConvolutionParameterivEXT");
    if ( Wm3glConvolutionParameterivEXT )
        ++Wm3NumFunctions_GL_EXT_convolution;

    Wm3glCopyConvolutionFilter1DEXT = (pfn_glCopyConvolutionFilter1DEXT)GetFunctionPointer("glCopyConvolutionFilter1DEXT");
    if ( Wm3glCopyConvolutionFilter1DEXT )
        ++Wm3NumFunctions_GL_EXT_convolution;

    Wm3glCopyConvolutionFilter2DEXT = (pfn_glCopyConvolutionFilter2DEXT)GetFunctionPointer("glCopyConvolutionFilter2DEXT");
    if ( Wm3glCopyConvolutionFilter2DEXT )
        ++Wm3NumFunctions_GL_EXT_convolution;

    Wm3glGetConvolutionFilterEXT = (pfn_glGetConvolutionFilterEXT)GetFunctionPointer("glGetConvolutionFilterEXT");
    if ( Wm3glGetConvolutionFilterEXT )
        ++Wm3NumFunctions_GL_EXT_convolution;

    Wm3glGetConvolutionParameterfvEXT = (pfn_glGetConvolutionParameterfvEXT)GetFunctionPointer("glGetConvolutionParameterfvEXT");
    if ( Wm3glGetConvolutionParameterfvEXT )
        ++Wm3NumFunctions_GL_EXT_convolution;

    Wm3glGetConvolutionParameterivEXT = (pfn_glGetConvolutionParameterivEXT)GetFunctionPointer("glGetConvolutionParameterivEXT");
    if ( Wm3glGetConvolutionParameterivEXT )
        ++Wm3NumFunctions_GL_EXT_convolution;

    Wm3glGetSeparableFilterEXT = (pfn_glGetSeparableFilterEXT)GetFunctionPointer("glGetSeparableFilterEXT");
    if ( Wm3glGetSeparableFilterEXT )
        ++Wm3NumFunctions_GL_EXT_convolution;

    Wm3glSeparableFilter2DEXT = (pfn_glSeparableFilter2DEXT)GetFunctionPointer("glSeparableFilter2DEXT");
    if ( Wm3glSeparableFilter2DEXT )
        ++Wm3NumFunctions_GL_EXT_convolution;

    if ( Wm3NumFunctions_GL_EXT_convolution == 13 )
        Wm3Exists_GL_EXT_convolution = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_EXT_convolution = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_EXT_convolution ()
{
    Wm3NumFunctions_GL_EXT_convolution = 0;
    Wm3Exists_GL_EXT_convolution = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_EXT_color_matrix;
int Wm3NumFunctions_GL_EXT_color_matrix;
#ifdef WM3_DEFINED_GL_EXT_color_matrix
static void Init_GL_EXT_color_matrix ()
{
    Wm3NumFunctions_GL_EXT_color_matrix = 0;
    Wm3Exists_GL_EXT_color_matrix = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_EXT_color_matrix ()
{
    Wm3NumFunctions_GL_EXT_color_matrix = 0;
    Wm3Exists_GL_EXT_color_matrix = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_SGI_color_table;
int Wm3NumFunctions_GL_SGI_color_table;
#ifdef WM3_DEFINED_GL_SGI_color_table
pfn_glColorTableSGI Wm3glColorTableSGI = 0;
pfn_glColorTableParameterfvSGI Wm3glColorTableParameterfvSGI = 0;
pfn_glColorTableParameterivSGI Wm3glColorTableParameterivSGI = 0;
pfn_glCopyColorTableSGI Wm3glCopyColorTableSGI = 0;
pfn_glGetColorTableSGI Wm3glGetColorTableSGI = 0;
pfn_glGetColorTableParameterfvSGI Wm3glGetColorTableParameterfvSGI = 0;
pfn_glGetColorTableParameterivSGI Wm3glGetColorTableParameterivSGI = 0;

static void Init_GL_SGI_color_table ()
{
    Wm3NumFunctions_GL_SGI_color_table = 0;

    Wm3glColorTableSGI = (pfn_glColorTableSGI)GetFunctionPointer("glColorTableSGI");
    if ( Wm3glColorTableSGI )
        ++Wm3NumFunctions_GL_SGI_color_table;

    Wm3glColorTableParameterfvSGI = (pfn_glColorTableParameterfvSGI)GetFunctionPointer("glColorTableParameterfvSGI");
    if ( Wm3glColorTableParameterfvSGI )
        ++Wm3NumFunctions_GL_SGI_color_table;

    Wm3glColorTableParameterivSGI = (pfn_glColorTableParameterivSGI)GetFunctionPointer("glColorTableParameterivSGI");
    if ( Wm3glColorTableParameterivSGI )
        ++Wm3NumFunctions_GL_SGI_color_table;

    Wm3glCopyColorTableSGI = (pfn_glCopyColorTableSGI)GetFunctionPointer("glCopyColorTableSGI");
    if ( Wm3glCopyColorTableSGI )
        ++Wm3NumFunctions_GL_SGI_color_table;

    Wm3glGetColorTableSGI = (pfn_glGetColorTableSGI)GetFunctionPointer("glGetColorTableSGI");
    if ( Wm3glGetColorTableSGI )
        ++Wm3NumFunctions_GL_SGI_color_table;

    Wm3glGetColorTableParameterfvSGI = (pfn_glGetColorTableParameterfvSGI)GetFunctionPointer("glGetColorTableParameterfvSGI");
    if ( Wm3glGetColorTableParameterfvSGI )
        ++Wm3NumFunctions_GL_SGI_color_table;

    Wm3glGetColorTableParameterivSGI = (pfn_glGetColorTableParameterivSGI)GetFunctionPointer("glGetColorTableParameterivSGI");
    if ( Wm3glGetColorTableParameterivSGI )
        ++Wm3NumFunctions_GL_SGI_color_table;

    if ( Wm3NumFunctions_GL_SGI_color_table == 7 )
        Wm3Exists_GL_SGI_color_table = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_SGI_color_table = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_SGI_color_table ()
{
    Wm3NumFunctions_GL_SGI_color_table = 0;
    Wm3Exists_GL_SGI_color_table = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_SGIX_pixel_texture;
int Wm3NumFunctions_GL_SGIX_pixel_texture;
#ifdef WM3_DEFINED_GL_SGIX_pixel_texture
pfn_glPixelTexGenSGIX Wm3glPixelTexGenSGIX = 0;

static void Init_GL_SGIX_pixel_texture ()
{
    Wm3NumFunctions_GL_SGIX_pixel_texture = 0;

    Wm3glPixelTexGenSGIX = (pfn_glPixelTexGenSGIX)GetFunctionPointer("glPixelTexGenSGIX");
    if ( Wm3glPixelTexGenSGIX )
        ++Wm3NumFunctions_GL_SGIX_pixel_texture;

    if ( Wm3NumFunctions_GL_SGIX_pixel_texture == 1 )
        Wm3Exists_GL_SGIX_pixel_texture = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_SGIX_pixel_texture = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_SGIX_pixel_texture ()
{
    Wm3NumFunctions_GL_SGIX_pixel_texture = 0;
    Wm3Exists_GL_SGIX_pixel_texture = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_SGIS_pixel_texture;
int Wm3NumFunctions_GL_SGIS_pixel_texture;
#ifdef WM3_DEFINED_GL_SGIS_pixel_texture
pfn_glPixelTexGenParameteriSGIS Wm3glPixelTexGenParameteriSGIS = 0;
pfn_glPixelTexGenParameterivSGIS Wm3glPixelTexGenParameterivSGIS = 0;
pfn_glPixelTexGenParameterfSGIS Wm3glPixelTexGenParameterfSGIS = 0;
pfn_glPixelTexGenParameterfvSGIS Wm3glPixelTexGenParameterfvSGIS = 0;
pfn_glGetPixelTexGenParameterivSGIS Wm3glGetPixelTexGenParameterivSGIS = 0;
pfn_glGetPixelTexGenParameterfvSGIS Wm3glGetPixelTexGenParameterfvSGIS = 0;

static void Init_GL_SGIS_pixel_texture ()
{
    Wm3NumFunctions_GL_SGIS_pixel_texture = 0;

    Wm3glPixelTexGenParameteriSGIS = (pfn_glPixelTexGenParameteriSGIS)GetFunctionPointer("glPixelTexGenParameteriSGIS");
    if ( Wm3glPixelTexGenParameteriSGIS )
        ++Wm3NumFunctions_GL_SGIS_pixel_texture;

    Wm3glPixelTexGenParameterivSGIS = (pfn_glPixelTexGenParameterivSGIS)GetFunctionPointer("glPixelTexGenParameterivSGIS");
    if ( Wm3glPixelTexGenParameterivSGIS )
        ++Wm3NumFunctions_GL_SGIS_pixel_texture;

    Wm3glPixelTexGenParameterfSGIS = (pfn_glPixelTexGenParameterfSGIS)GetFunctionPointer("glPixelTexGenParameterfSGIS");
    if ( Wm3glPixelTexGenParameterfSGIS )
        ++Wm3NumFunctions_GL_SGIS_pixel_texture;

    Wm3glPixelTexGenParameterfvSGIS = (pfn_glPixelTexGenParameterfvSGIS)GetFunctionPointer("glPixelTexGenParameterfvSGIS");
    if ( Wm3glPixelTexGenParameterfvSGIS )
        ++Wm3NumFunctions_GL_SGIS_pixel_texture;

    Wm3glGetPixelTexGenParameterivSGIS = (pfn_glGetPixelTexGenParameterivSGIS)GetFunctionPointer("glGetPixelTexGenParameterivSGIS");
    if ( Wm3glGetPixelTexGenParameterivSGIS )
        ++Wm3NumFunctions_GL_SGIS_pixel_texture;

    Wm3glGetPixelTexGenParameterfvSGIS = (pfn_glGetPixelTexGenParameterfvSGIS)GetFunctionPointer("glGetPixelTexGenParameterfvSGIS");
    if ( Wm3glGetPixelTexGenParameterfvSGIS )
        ++Wm3NumFunctions_GL_SGIS_pixel_texture;

    if ( Wm3NumFunctions_GL_SGIS_pixel_texture == 6 )
        Wm3Exists_GL_SGIS_pixel_texture = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_SGIS_pixel_texture = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_SGIS_pixel_texture ()
{
    Wm3NumFunctions_GL_SGIS_pixel_texture = 0;
    Wm3Exists_GL_SGIS_pixel_texture = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_SGIS_texture4D;
int Wm3NumFunctions_GL_SGIS_texture4D;
#ifdef WM3_DEFINED_GL_SGIS_texture4D
pfn_glTexImage4DSGIS Wm3glTexImage4DSGIS = 0;
pfn_glTexSubImage4DSGIS Wm3glTexSubImage4DSGIS = 0;

static void Init_GL_SGIS_texture4D ()
{
    Wm3NumFunctions_GL_SGIS_texture4D = 0;

    Wm3glTexImage4DSGIS = (pfn_glTexImage4DSGIS)GetFunctionPointer("glTexImage4DSGIS");
    if ( Wm3glTexImage4DSGIS )
        ++Wm3NumFunctions_GL_SGIS_texture4D;

    Wm3glTexSubImage4DSGIS = (pfn_glTexSubImage4DSGIS)GetFunctionPointer("glTexSubImage4DSGIS");
    if ( Wm3glTexSubImage4DSGIS )
        ++Wm3NumFunctions_GL_SGIS_texture4D;

    if ( Wm3NumFunctions_GL_SGIS_texture4D == 2 )
        Wm3Exists_GL_SGIS_texture4D = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_SGIS_texture4D = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_SGIS_texture4D ()
{
    Wm3NumFunctions_GL_SGIS_texture4D = 0;
    Wm3Exists_GL_SGIS_texture4D = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_SGI_texture_color_table;
int Wm3NumFunctions_GL_SGI_texture_color_table;
#ifdef WM3_DEFINED_GL_SGI_texture_color_table
static void Init_GL_SGI_texture_color_table ()
{
    Wm3NumFunctions_GL_SGI_texture_color_table = 0;
    Wm3Exists_GL_SGI_texture_color_table = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_SGI_texture_color_table ()
{
    Wm3NumFunctions_GL_SGI_texture_color_table = 0;
    Wm3Exists_GL_SGI_texture_color_table = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_EXT_cmyka;
int Wm3NumFunctions_GL_EXT_cmyka;
#ifdef WM3_DEFINED_GL_EXT_cmyka
static void Init_GL_EXT_cmyka ()
{
    Wm3NumFunctions_GL_EXT_cmyka = 0;
    Wm3Exists_GL_EXT_cmyka = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_EXT_cmyka ()
{
    Wm3NumFunctions_GL_EXT_cmyka = 0;
    Wm3Exists_GL_EXT_cmyka = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_EXT_texture_object;
int Wm3NumFunctions_GL_EXT_texture_object;
#ifdef WM3_DEFINED_GL_EXT_texture_object
pfn_glAreTexturesResidentEXT Wm3glAreTexturesResidentEXT = 0;
pfn_glBindTextureEXT Wm3glBindTextureEXT = 0;
pfn_glDeleteTexturesEXT Wm3glDeleteTexturesEXT = 0;
pfn_glGenTexturesEXT Wm3glGenTexturesEXT = 0;
pfn_glIsTextureEXT Wm3glIsTextureEXT = 0;
pfn_glPrioritizeTexturesEXT Wm3glPrioritizeTexturesEXT = 0;

static void Init_GL_EXT_texture_object ()
{
    Wm3NumFunctions_GL_EXT_texture_object = 0;

    Wm3glAreTexturesResidentEXT = (pfn_glAreTexturesResidentEXT)GetFunctionPointer("glAreTexturesResidentEXT");
    if ( Wm3glAreTexturesResidentEXT )
        ++Wm3NumFunctions_GL_EXT_texture_object;

    Wm3glBindTextureEXT = (pfn_glBindTextureEXT)GetFunctionPointer("glBindTextureEXT");
    if ( Wm3glBindTextureEXT )
        ++Wm3NumFunctions_GL_EXT_texture_object;

    Wm3glDeleteTexturesEXT = (pfn_glDeleteTexturesEXT)GetFunctionPointer("glDeleteTexturesEXT");
    if ( Wm3glDeleteTexturesEXT )
        ++Wm3NumFunctions_GL_EXT_texture_object;

    Wm3glGenTexturesEXT = (pfn_glGenTexturesEXT)GetFunctionPointer("glGenTexturesEXT");
    if ( Wm3glGenTexturesEXT )
        ++Wm3NumFunctions_GL_EXT_texture_object;

    Wm3glIsTextureEXT = (pfn_glIsTextureEXT)GetFunctionPointer("glIsTextureEXT");
    if ( Wm3glIsTextureEXT )
        ++Wm3NumFunctions_GL_EXT_texture_object;

    Wm3glPrioritizeTexturesEXT = (pfn_glPrioritizeTexturesEXT)GetFunctionPointer("glPrioritizeTexturesEXT");
    if ( Wm3glPrioritizeTexturesEXT )
        ++Wm3NumFunctions_GL_EXT_texture_object;

    if ( Wm3NumFunctions_GL_EXT_texture_object == 6 )
        Wm3Exists_GL_EXT_texture_object = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_EXT_texture_object = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_EXT_texture_object ()
{
    Wm3NumFunctions_GL_EXT_texture_object = 0;
    Wm3Exists_GL_EXT_texture_object = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_SGIS_detail_texture;
int Wm3NumFunctions_GL_SGIS_detail_texture;
#ifdef WM3_DEFINED_GL_SGIS_detail_texture
pfn_glDetailTexFuncSGIS Wm3glDetailTexFuncSGIS = 0;
pfn_glGetDetailTexFuncSGIS Wm3glGetDetailTexFuncSGIS = 0;

static void Init_GL_SGIS_detail_texture ()
{
    Wm3NumFunctions_GL_SGIS_detail_texture = 0;

    Wm3glDetailTexFuncSGIS = (pfn_glDetailTexFuncSGIS)GetFunctionPointer("glDetailTexFuncSGIS");
    if ( Wm3glDetailTexFuncSGIS )
        ++Wm3NumFunctions_GL_SGIS_detail_texture;

    Wm3glGetDetailTexFuncSGIS = (pfn_glGetDetailTexFuncSGIS)GetFunctionPointer("glGetDetailTexFuncSGIS");
    if ( Wm3glGetDetailTexFuncSGIS )
        ++Wm3NumFunctions_GL_SGIS_detail_texture;

    if ( Wm3NumFunctions_GL_SGIS_detail_texture == 2 )
        Wm3Exists_GL_SGIS_detail_texture = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_SGIS_detail_texture = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_SGIS_detail_texture ()
{
    Wm3NumFunctions_GL_SGIS_detail_texture = 0;
    Wm3Exists_GL_SGIS_detail_texture = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_SGIS_sharpen_texture;
int Wm3NumFunctions_GL_SGIS_sharpen_texture;
#ifdef WM3_DEFINED_GL_SGIS_sharpen_texture
pfn_glSharpenTexFuncSGIS Wm3glSharpenTexFuncSGIS = 0;
pfn_glGetSharpenTexFuncSGIS Wm3glGetSharpenTexFuncSGIS = 0;

static void Init_GL_SGIS_sharpen_texture ()
{
    Wm3NumFunctions_GL_SGIS_sharpen_texture = 0;

    Wm3glSharpenTexFuncSGIS = (pfn_glSharpenTexFuncSGIS)GetFunctionPointer("glSharpenTexFuncSGIS");
    if ( Wm3glSharpenTexFuncSGIS )
        ++Wm3NumFunctions_GL_SGIS_sharpen_texture;

    Wm3glGetSharpenTexFuncSGIS = (pfn_glGetSharpenTexFuncSGIS)GetFunctionPointer("glGetSharpenTexFuncSGIS");
    if ( Wm3glGetSharpenTexFuncSGIS )
        ++Wm3NumFunctions_GL_SGIS_sharpen_texture;

    if ( Wm3NumFunctions_GL_SGIS_sharpen_texture == 2 )
        Wm3Exists_GL_SGIS_sharpen_texture = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_SGIS_sharpen_texture = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_SGIS_sharpen_texture ()
{
    Wm3NumFunctions_GL_SGIS_sharpen_texture = 0;
    Wm3Exists_GL_SGIS_sharpen_texture = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_EXT_packed_pixels;
int Wm3NumFunctions_GL_EXT_packed_pixels;
#ifdef WM3_DEFINED_GL_EXT_packed_pixels
static void Init_GL_EXT_packed_pixels ()
{
    Wm3NumFunctions_GL_EXT_packed_pixels = 0;
    Wm3Exists_GL_EXT_packed_pixels = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_EXT_packed_pixels ()
{
    Wm3NumFunctions_GL_EXT_packed_pixels = 0;
    Wm3Exists_GL_EXT_packed_pixels = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_SGIS_texture_lod;
int Wm3NumFunctions_GL_SGIS_texture_lod;
#ifdef WM3_DEFINED_GL_SGIS_texture_lod
static void Init_GL_SGIS_texture_lod ()
{
    Wm3NumFunctions_GL_SGIS_texture_lod = 0;
    Wm3Exists_GL_SGIS_texture_lod = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_SGIS_texture_lod ()
{
    Wm3NumFunctions_GL_SGIS_texture_lod = 0;
    Wm3Exists_GL_SGIS_texture_lod = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_SGIS_multisample;
int Wm3NumFunctions_GL_SGIS_multisample;
#ifdef WM3_DEFINED_GL_SGIS_multisample
pfn_glSampleMaskSGIS Wm3glSampleMaskSGIS = 0;
pfn_glSamplePatternSGIS Wm3glSamplePatternSGIS = 0;

static void Init_GL_SGIS_multisample ()
{
    Wm3NumFunctions_GL_SGIS_multisample = 0;

    Wm3glSampleMaskSGIS = (pfn_glSampleMaskSGIS)GetFunctionPointer("glSampleMaskSGIS");
    if ( Wm3glSampleMaskSGIS )
        ++Wm3NumFunctions_GL_SGIS_multisample;

    Wm3glSamplePatternSGIS = (pfn_glSamplePatternSGIS)GetFunctionPointer("glSamplePatternSGIS");
    if ( Wm3glSamplePatternSGIS )
        ++Wm3NumFunctions_GL_SGIS_multisample;

    if ( Wm3NumFunctions_GL_SGIS_multisample == 2 )
        Wm3Exists_GL_SGIS_multisample = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_SGIS_multisample = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_SGIS_multisample ()
{
    Wm3NumFunctions_GL_SGIS_multisample = 0;
    Wm3Exists_GL_SGIS_multisample = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_EXT_rescale_normal;
int Wm3NumFunctions_GL_EXT_rescale_normal;
#ifdef WM3_DEFINED_GL_EXT_rescale_normal
static void Init_GL_EXT_rescale_normal ()
{
    Wm3NumFunctions_GL_EXT_rescale_normal = 0;
    Wm3Exists_GL_EXT_rescale_normal = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_EXT_rescale_normal ()
{
    Wm3NumFunctions_GL_EXT_rescale_normal = 0;
    Wm3Exists_GL_EXT_rescale_normal = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_EXT_vertex_array;
int Wm3NumFunctions_GL_EXT_vertex_array;
#ifdef WM3_DEFINED_GL_EXT_vertex_array
pfn_glArrayElementEXT Wm3glArrayElementEXT = 0;
pfn_glColorPointerEXT Wm3glColorPointerEXT = 0;
pfn_glDrawArraysEXT Wm3glDrawArraysEXT = 0;
pfn_glEdgeFlagPointerEXT Wm3glEdgeFlagPointerEXT = 0;
pfn_glGetPointervEXT Wm3glGetPointervEXT = 0;
pfn_glIndexPointerEXT Wm3glIndexPointerEXT = 0;
pfn_glNormalPointerEXT Wm3glNormalPointerEXT = 0;
pfn_glTexCoordPointerEXT Wm3glTexCoordPointerEXT = 0;
pfn_glVertexPointerEXT Wm3glVertexPointerEXT = 0;

static void Init_GL_EXT_vertex_array ()
{
    Wm3NumFunctions_GL_EXT_vertex_array = 0;

    Wm3glArrayElementEXT = (pfn_glArrayElementEXT)GetFunctionPointer("glArrayElementEXT");
    if ( Wm3glArrayElementEXT )
        ++Wm3NumFunctions_GL_EXT_vertex_array;

    Wm3glColorPointerEXT = (pfn_glColorPointerEXT)GetFunctionPointer("glColorPointerEXT");
    if ( Wm3glColorPointerEXT )
        ++Wm3NumFunctions_GL_EXT_vertex_array;

    Wm3glDrawArraysEXT = (pfn_glDrawArraysEXT)GetFunctionPointer("glDrawArraysEXT");
    if ( Wm3glDrawArraysEXT )
        ++Wm3NumFunctions_GL_EXT_vertex_array;

    Wm3glEdgeFlagPointerEXT = (pfn_glEdgeFlagPointerEXT)GetFunctionPointer("glEdgeFlagPointerEXT");
    if ( Wm3glEdgeFlagPointerEXT )
        ++Wm3NumFunctions_GL_EXT_vertex_array;

    Wm3glGetPointervEXT = (pfn_glGetPointervEXT)GetFunctionPointer("glGetPointervEXT");
    if ( Wm3glGetPointervEXT )
        ++Wm3NumFunctions_GL_EXT_vertex_array;

    Wm3glIndexPointerEXT = (pfn_glIndexPointerEXT)GetFunctionPointer("glIndexPointerEXT");
    if ( Wm3glIndexPointerEXT )
        ++Wm3NumFunctions_GL_EXT_vertex_array;

    Wm3glNormalPointerEXT = (pfn_glNormalPointerEXT)GetFunctionPointer("glNormalPointerEXT");
    if ( Wm3glNormalPointerEXT )
        ++Wm3NumFunctions_GL_EXT_vertex_array;

    Wm3glTexCoordPointerEXT = (pfn_glTexCoordPointerEXT)GetFunctionPointer("glTexCoordPointerEXT");
    if ( Wm3glTexCoordPointerEXT )
        ++Wm3NumFunctions_GL_EXT_vertex_array;

    Wm3glVertexPointerEXT = (pfn_glVertexPointerEXT)GetFunctionPointer("glVertexPointerEXT");
    if ( Wm3glVertexPointerEXT )
        ++Wm3NumFunctions_GL_EXT_vertex_array;

    if ( Wm3NumFunctions_GL_EXT_vertex_array == 9 )
        Wm3Exists_GL_EXT_vertex_array = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_EXT_vertex_array = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_EXT_vertex_array ()
{
    Wm3NumFunctions_GL_EXT_vertex_array = 0;
    Wm3Exists_GL_EXT_vertex_array = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_EXT_misc_attribute;
int Wm3NumFunctions_GL_EXT_misc_attribute;
#ifdef WM3_DEFINED_GL_EXT_misc_attribute
static void Init_GL_EXT_misc_attribute ()
{
    Wm3NumFunctions_GL_EXT_misc_attribute = 0;
    Wm3Exists_GL_EXT_misc_attribute = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_EXT_misc_attribute ()
{
    Wm3NumFunctions_GL_EXT_misc_attribute = 0;
    Wm3Exists_GL_EXT_misc_attribute = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_SGIS_generate_mipmap;
int Wm3NumFunctions_GL_SGIS_generate_mipmap;
#ifdef WM3_DEFINED_GL_SGIS_generate_mipmap
static void Init_GL_SGIS_generate_mipmap ()
{
    Wm3NumFunctions_GL_SGIS_generate_mipmap = 0;
    Wm3Exists_GL_SGIS_generate_mipmap = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_SGIS_generate_mipmap ()
{
    Wm3NumFunctions_GL_SGIS_generate_mipmap = 0;
    Wm3Exists_GL_SGIS_generate_mipmap = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_SGIX_clipmap;
int Wm3NumFunctions_GL_SGIX_clipmap;
#ifdef WM3_DEFINED_GL_SGIX_clipmap
static void Init_GL_SGIX_clipmap ()
{
    Wm3NumFunctions_GL_SGIX_clipmap = 0;
    Wm3Exists_GL_SGIX_clipmap = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_SGIX_clipmap ()
{
    Wm3NumFunctions_GL_SGIX_clipmap = 0;
    Wm3Exists_GL_SGIX_clipmap = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_SGIX_shadow;
int Wm3NumFunctions_GL_SGIX_shadow;
#ifdef WM3_DEFINED_GL_SGIX_shadow
static void Init_GL_SGIX_shadow ()
{
    Wm3NumFunctions_GL_SGIX_shadow = 0;
    Wm3Exists_GL_SGIX_shadow = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_SGIX_shadow ()
{
    Wm3NumFunctions_GL_SGIX_shadow = 0;
    Wm3Exists_GL_SGIX_shadow = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_SGIS_texture_edge_clamp;
int Wm3NumFunctions_GL_SGIS_texture_edge_clamp;
#ifdef WM3_DEFINED_GL_SGIS_texture_edge_clamp
static void Init_GL_SGIS_texture_edge_clamp ()
{
    Wm3NumFunctions_GL_SGIS_texture_edge_clamp = 0;
    Wm3Exists_GL_SGIS_texture_edge_clamp = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_SGIS_texture_edge_clamp ()
{
    Wm3NumFunctions_GL_SGIS_texture_edge_clamp = 0;
    Wm3Exists_GL_SGIS_texture_edge_clamp = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_SGIS_texture_border_clamp;
int Wm3NumFunctions_GL_SGIS_texture_border_clamp;
#ifdef WM3_DEFINED_GL_SGIS_texture_border_clamp
static void Init_GL_SGIS_texture_border_clamp ()
{
    Wm3NumFunctions_GL_SGIS_texture_border_clamp = 0;
    Wm3Exists_GL_SGIS_texture_border_clamp = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_SGIS_texture_border_clamp ()
{
    Wm3NumFunctions_GL_SGIS_texture_border_clamp = 0;
    Wm3Exists_GL_SGIS_texture_border_clamp = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_EXT_blend_minmax;
int Wm3NumFunctions_GL_EXT_blend_minmax;
#ifdef WM3_DEFINED_GL_EXT_blend_minmax
pfn_glBlendEquationEXT Wm3glBlendEquationEXT = 0;

static void Init_GL_EXT_blend_minmax ()
{
    Wm3NumFunctions_GL_EXT_blend_minmax = 0;

    Wm3glBlendEquationEXT = (pfn_glBlendEquationEXT)GetFunctionPointer("glBlendEquationEXT");
    if ( Wm3glBlendEquationEXT )
        ++Wm3NumFunctions_GL_EXT_blend_minmax;

    if ( Wm3NumFunctions_GL_EXT_blend_minmax == 1 )
        Wm3Exists_GL_EXT_blend_minmax = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_EXT_blend_minmax = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_EXT_blend_minmax ()
{
    Wm3NumFunctions_GL_EXT_blend_minmax = 0;
    Wm3Exists_GL_EXT_blend_minmax = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_EXT_blend_subtract;
int Wm3NumFunctions_GL_EXT_blend_subtract;
#ifdef WM3_DEFINED_GL_EXT_blend_subtract
static void Init_GL_EXT_blend_subtract ()
{
    Wm3NumFunctions_GL_EXT_blend_subtract = 0;
    Wm3Exists_GL_EXT_blend_subtract = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_EXT_blend_subtract ()
{
    Wm3NumFunctions_GL_EXT_blend_subtract = 0;
    Wm3Exists_GL_EXT_blend_subtract = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_EXT_blend_logic_op;
int Wm3NumFunctions_GL_EXT_blend_logic_op;
#ifdef WM3_DEFINED_GL_EXT_blend_logic_op
static void Init_GL_EXT_blend_logic_op ()
{
    Wm3NumFunctions_GL_EXT_blend_logic_op = 0;
    Wm3Exists_GL_EXT_blend_logic_op = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_EXT_blend_logic_op ()
{
    Wm3NumFunctions_GL_EXT_blend_logic_op = 0;
    Wm3Exists_GL_EXT_blend_logic_op = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_SGIX_interlace;
int Wm3NumFunctions_GL_SGIX_interlace;
#ifdef WM3_DEFINED_GL_SGIX_interlace
static void Init_GL_SGIX_interlace ()
{
    Wm3NumFunctions_GL_SGIX_interlace = 0;
    Wm3Exists_GL_SGIX_interlace = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_SGIX_interlace ()
{
    Wm3NumFunctions_GL_SGIX_interlace = 0;
    Wm3Exists_GL_SGIX_interlace = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_SGIX_pixel_tiles;
int Wm3NumFunctions_GL_SGIX_pixel_tiles;
#ifdef WM3_DEFINED_GL_SGIX_pixel_tiles
static void Init_GL_SGIX_pixel_tiles ()
{
    Wm3NumFunctions_GL_SGIX_pixel_tiles = 0;
    Wm3Exists_GL_SGIX_pixel_tiles = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_SGIX_pixel_tiles ()
{
    Wm3NumFunctions_GL_SGIX_pixel_tiles = 0;
    Wm3Exists_GL_SGIX_pixel_tiles = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_SGIX_texture_select;
int Wm3NumFunctions_GL_SGIX_texture_select;
#ifdef WM3_DEFINED_GL_SGIX_texture_select
static void Init_GL_SGIX_texture_select ()
{
    Wm3NumFunctions_GL_SGIX_texture_select = 0;
    Wm3Exists_GL_SGIX_texture_select = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_SGIX_texture_select ()
{
    Wm3NumFunctions_GL_SGIX_texture_select = 0;
    Wm3Exists_GL_SGIX_texture_select = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_SGIX_sprite;
int Wm3NumFunctions_GL_SGIX_sprite;
#ifdef WM3_DEFINED_GL_SGIX_sprite
pfn_glSpriteParameterfSGIX Wm3glSpriteParameterfSGIX = 0;
pfn_glSpriteParameterfvSGIX Wm3glSpriteParameterfvSGIX = 0;
pfn_glSpriteParameteriSGIX Wm3glSpriteParameteriSGIX = 0;
pfn_glSpriteParameterivSGIX Wm3glSpriteParameterivSGIX = 0;

static void Init_GL_SGIX_sprite ()
{
    Wm3NumFunctions_GL_SGIX_sprite = 0;

    Wm3glSpriteParameterfSGIX = (pfn_glSpriteParameterfSGIX)GetFunctionPointer("glSpriteParameterfSGIX");
    if ( Wm3glSpriteParameterfSGIX )
        ++Wm3NumFunctions_GL_SGIX_sprite;

    Wm3glSpriteParameterfvSGIX = (pfn_glSpriteParameterfvSGIX)GetFunctionPointer("glSpriteParameterfvSGIX");
    if ( Wm3glSpriteParameterfvSGIX )
        ++Wm3NumFunctions_GL_SGIX_sprite;

    Wm3glSpriteParameteriSGIX = (pfn_glSpriteParameteriSGIX)GetFunctionPointer("glSpriteParameteriSGIX");
    if ( Wm3glSpriteParameteriSGIX )
        ++Wm3NumFunctions_GL_SGIX_sprite;

    Wm3glSpriteParameterivSGIX = (pfn_glSpriteParameterivSGIX)GetFunctionPointer("glSpriteParameterivSGIX");
    if ( Wm3glSpriteParameterivSGIX )
        ++Wm3NumFunctions_GL_SGIX_sprite;

    if ( Wm3NumFunctions_GL_SGIX_sprite == 4 )
        Wm3Exists_GL_SGIX_sprite = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_SGIX_sprite = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_SGIX_sprite ()
{
    Wm3NumFunctions_GL_SGIX_sprite = 0;
    Wm3Exists_GL_SGIX_sprite = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_SGIX_texture_multi_buffer;
int Wm3NumFunctions_GL_SGIX_texture_multi_buffer;
#ifdef WM3_DEFINED_GL_SGIX_texture_multi_buffer
static void Init_GL_SGIX_texture_multi_buffer ()
{
    Wm3NumFunctions_GL_SGIX_texture_multi_buffer = 0;
    Wm3Exists_GL_SGIX_texture_multi_buffer = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_SGIX_texture_multi_buffer ()
{
    Wm3NumFunctions_GL_SGIX_texture_multi_buffer = 0;
    Wm3Exists_GL_SGIX_texture_multi_buffer = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_EXT_point_parameters;
int Wm3NumFunctions_GL_EXT_point_parameters;
#ifdef WM3_DEFINED_GL_EXT_point_parameters
pfn_glPointParameterfEXT Wm3glPointParameterfEXT = 0;
pfn_glPointParameterfvEXT Wm3glPointParameterfvEXT = 0;

static void Init_GL_EXT_point_parameters ()
{
    Wm3NumFunctions_GL_EXT_point_parameters = 0;

    Wm3glPointParameterfEXT = (pfn_glPointParameterfEXT)GetFunctionPointer("glPointParameterfEXT");
    if ( Wm3glPointParameterfEXT )
        ++Wm3NumFunctions_GL_EXT_point_parameters;

    Wm3glPointParameterfvEXT = (pfn_glPointParameterfvEXT)GetFunctionPointer("glPointParameterfvEXT");
    if ( Wm3glPointParameterfvEXT )
        ++Wm3NumFunctions_GL_EXT_point_parameters;

    if ( Wm3NumFunctions_GL_EXT_point_parameters == 2 )
        Wm3Exists_GL_EXT_point_parameters = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_EXT_point_parameters = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_EXT_point_parameters ()
{
    Wm3NumFunctions_GL_EXT_point_parameters = 0;
    Wm3Exists_GL_EXT_point_parameters = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_SGIS_point_parameters;
int Wm3NumFunctions_GL_SGIS_point_parameters;
#ifdef WM3_DEFINED_GL_SGIS_point_parameters
pfn_glPointParameterfSGIS Wm3glPointParameterfSGIS = 0;
pfn_glPointParameterfvSGIS Wm3glPointParameterfvSGIS = 0;

static void Init_GL_SGIS_point_parameters ()
{
    Wm3NumFunctions_GL_SGIS_point_parameters = 0;

    Wm3glPointParameterfSGIS = (pfn_glPointParameterfSGIS)GetFunctionPointer("glPointParameterfSGIS");
    if ( Wm3glPointParameterfSGIS )
        ++Wm3NumFunctions_GL_SGIS_point_parameters;

    Wm3glPointParameterfvSGIS = (pfn_glPointParameterfvSGIS)GetFunctionPointer("glPointParameterfvSGIS");
    if ( Wm3glPointParameterfvSGIS )
        ++Wm3NumFunctions_GL_SGIS_point_parameters;

    if ( Wm3NumFunctions_GL_SGIS_point_parameters == 2 )
        Wm3Exists_GL_SGIS_point_parameters = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_SGIS_point_parameters = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_SGIS_point_parameters ()
{
    Wm3NumFunctions_GL_SGIS_point_parameters = 0;
    Wm3Exists_GL_SGIS_point_parameters = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_SGIX_instruments;
int Wm3NumFunctions_GL_SGIX_instruments;
#ifdef WM3_DEFINED_GL_SGIX_instruments
pfn_glGetInstrumentsSGIX Wm3glGetInstrumentsSGIX = 0;
pfn_glInstrumentsBufferSGIX Wm3glInstrumentsBufferSGIX = 0;
pfn_glPollInstrumentsSGIX Wm3glPollInstrumentsSGIX = 0;
pfn_glReadInstrumentsSGIX Wm3glReadInstrumentsSGIX = 0;
pfn_glStartInstrumentsSGIX Wm3glStartInstrumentsSGIX = 0;
pfn_glStopInstrumentsSGIX Wm3glStopInstrumentsSGIX = 0;

static void Init_GL_SGIX_instruments ()
{
    Wm3NumFunctions_GL_SGIX_instruments = 0;

    Wm3glGetInstrumentsSGIX = (pfn_glGetInstrumentsSGIX)GetFunctionPointer("glGetInstrumentsSGIX");
    if ( Wm3glGetInstrumentsSGIX )
        ++Wm3NumFunctions_GL_SGIX_instruments;

    Wm3glInstrumentsBufferSGIX = (pfn_glInstrumentsBufferSGIX)GetFunctionPointer("glInstrumentsBufferSGIX");
    if ( Wm3glInstrumentsBufferSGIX )
        ++Wm3NumFunctions_GL_SGIX_instruments;

    Wm3glPollInstrumentsSGIX = (pfn_glPollInstrumentsSGIX)GetFunctionPointer("glPollInstrumentsSGIX");
    if ( Wm3glPollInstrumentsSGIX )
        ++Wm3NumFunctions_GL_SGIX_instruments;

    Wm3glReadInstrumentsSGIX = (pfn_glReadInstrumentsSGIX)GetFunctionPointer("glReadInstrumentsSGIX");
    if ( Wm3glReadInstrumentsSGIX )
        ++Wm3NumFunctions_GL_SGIX_instruments;

    Wm3glStartInstrumentsSGIX = (pfn_glStartInstrumentsSGIX)GetFunctionPointer("glStartInstrumentsSGIX");
    if ( Wm3glStartInstrumentsSGIX )
        ++Wm3NumFunctions_GL_SGIX_instruments;

    Wm3glStopInstrumentsSGIX = (pfn_glStopInstrumentsSGIX)GetFunctionPointer("glStopInstrumentsSGIX");
    if ( Wm3glStopInstrumentsSGIX )
        ++Wm3NumFunctions_GL_SGIX_instruments;

    if ( Wm3NumFunctions_GL_SGIX_instruments == 6 )
        Wm3Exists_GL_SGIX_instruments = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_SGIX_instruments = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_SGIX_instruments ()
{
    Wm3NumFunctions_GL_SGIX_instruments = 0;
    Wm3Exists_GL_SGIX_instruments = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_SGIX_texture_scale_bias;
int Wm3NumFunctions_GL_SGIX_texture_scale_bias;
#ifdef WM3_DEFINED_GL_SGIX_texture_scale_bias
static void Init_GL_SGIX_texture_scale_bias ()
{
    Wm3NumFunctions_GL_SGIX_texture_scale_bias = 0;
    Wm3Exists_GL_SGIX_texture_scale_bias = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_SGIX_texture_scale_bias ()
{
    Wm3NumFunctions_GL_SGIX_texture_scale_bias = 0;
    Wm3Exists_GL_SGIX_texture_scale_bias = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_SGIX_framezoom;
int Wm3NumFunctions_GL_SGIX_framezoom;
#ifdef WM3_DEFINED_GL_SGIX_framezoom
pfn_glFrameZoomSGIX Wm3glFrameZoomSGIX = 0;

static void Init_GL_SGIX_framezoom ()
{
    Wm3NumFunctions_GL_SGIX_framezoom = 0;

    Wm3glFrameZoomSGIX = (pfn_glFrameZoomSGIX)GetFunctionPointer("glFrameZoomSGIX");
    if ( Wm3glFrameZoomSGIX )
        ++Wm3NumFunctions_GL_SGIX_framezoom;

    if ( Wm3NumFunctions_GL_SGIX_framezoom == 1 )
        Wm3Exists_GL_SGIX_framezoom = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_SGIX_framezoom = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_SGIX_framezoom ()
{
    Wm3NumFunctions_GL_SGIX_framezoom = 0;
    Wm3Exists_GL_SGIX_framezoom = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_SGIX_tag_sample_buffer;
int Wm3NumFunctions_GL_SGIX_tag_sample_buffer;
#ifdef WM3_DEFINED_GL_SGIX_tag_sample_buffer
pfn_glTagSampleBufferSGIX Wm3glTagSampleBufferSGIX = 0;

static void Init_GL_SGIX_tag_sample_buffer ()
{
    Wm3NumFunctions_GL_SGIX_tag_sample_buffer = 0;

    Wm3glTagSampleBufferSGIX = (pfn_glTagSampleBufferSGIX)GetFunctionPointer("glTagSampleBufferSGIX");
    if ( Wm3glTagSampleBufferSGIX )
        ++Wm3NumFunctions_GL_SGIX_tag_sample_buffer;

    if ( Wm3NumFunctions_GL_SGIX_tag_sample_buffer == 1 )
        Wm3Exists_GL_SGIX_tag_sample_buffer = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_SGIX_tag_sample_buffer = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_SGIX_tag_sample_buffer ()
{
    Wm3NumFunctions_GL_SGIX_tag_sample_buffer = 0;
    Wm3Exists_GL_SGIX_tag_sample_buffer = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_FfdMaskSGIX;
int Wm3NumFunctions_GL_FfdMaskSGIX;
#ifdef WM3_DEFINED_GL_FfdMaskSGIX
static void Init_GL_FfdMaskSGIX ()
{
    Wm3NumFunctions_GL_FfdMaskSGIX = 0;
    Wm3Exists_GL_FfdMaskSGIX = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_FfdMaskSGIX ()
{
    Wm3NumFunctions_GL_FfdMaskSGIX = 0;
    Wm3Exists_GL_FfdMaskSGIX = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_SGIX_polynomial_ffd;
int Wm3NumFunctions_GL_SGIX_polynomial_ffd;
#ifdef WM3_DEFINED_GL_SGIX_polynomial_ffd
pfn_glDeformationMap3dSGIX Wm3glDeformationMap3dSGIX = 0;
pfn_glDeformationMap3fSGIX Wm3glDeformationMap3fSGIX = 0;
pfn_glDeformSGIX Wm3glDeformSGIX = 0;
pfn_glLoadIdentityDeformationMapSGIX Wm3glLoadIdentityDeformationMapSGIX = 0;

static void Init_GL_SGIX_polynomial_ffd ()
{
    Wm3NumFunctions_GL_SGIX_polynomial_ffd = 0;

    Wm3glDeformationMap3dSGIX = (pfn_glDeformationMap3dSGIX)GetFunctionPointer("glDeformationMap3dSGIX");
    if ( Wm3glDeformationMap3dSGIX )
        ++Wm3NumFunctions_GL_SGIX_polynomial_ffd;

    Wm3glDeformationMap3fSGIX = (pfn_glDeformationMap3fSGIX)GetFunctionPointer("glDeformationMap3fSGIX");
    if ( Wm3glDeformationMap3fSGIX )
        ++Wm3NumFunctions_GL_SGIX_polynomial_ffd;

    Wm3glDeformSGIX = (pfn_glDeformSGIX)GetFunctionPointer("glDeformSGIX");
    if ( Wm3glDeformSGIX )
        ++Wm3NumFunctions_GL_SGIX_polynomial_ffd;

    Wm3glLoadIdentityDeformationMapSGIX = (pfn_glLoadIdentityDeformationMapSGIX)GetFunctionPointer("glLoadIdentityDeformationMapSGIX");
    if ( Wm3glLoadIdentityDeformationMapSGIX )
        ++Wm3NumFunctions_GL_SGIX_polynomial_ffd;

    if ( Wm3NumFunctions_GL_SGIX_polynomial_ffd == 4 )
        Wm3Exists_GL_SGIX_polynomial_ffd = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_SGIX_polynomial_ffd = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_SGIX_polynomial_ffd ()
{
    Wm3NumFunctions_GL_SGIX_polynomial_ffd = 0;
    Wm3Exists_GL_SGIX_polynomial_ffd = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_SGIX_reference_plane;
int Wm3NumFunctions_GL_SGIX_reference_plane;
#ifdef WM3_DEFINED_GL_SGIX_reference_plane
pfn_glReferencePlaneSGIX Wm3glReferencePlaneSGIX = 0;

static void Init_GL_SGIX_reference_plane ()
{
    Wm3NumFunctions_GL_SGIX_reference_plane = 0;

    Wm3glReferencePlaneSGIX = (pfn_glReferencePlaneSGIX)GetFunctionPointer("glReferencePlaneSGIX");
    if ( Wm3glReferencePlaneSGIX )
        ++Wm3NumFunctions_GL_SGIX_reference_plane;

    if ( Wm3NumFunctions_GL_SGIX_reference_plane == 1 )
        Wm3Exists_GL_SGIX_reference_plane = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_SGIX_reference_plane = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_SGIX_reference_plane ()
{
    Wm3NumFunctions_GL_SGIX_reference_plane = 0;
    Wm3Exists_GL_SGIX_reference_plane = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_SGIX_flush_raster;
int Wm3NumFunctions_GL_SGIX_flush_raster;
#ifdef WM3_DEFINED_GL_SGIX_flush_raster
pfn_glFlushRasterSGIX Wm3glFlushRasterSGIX = 0;

static void Init_GL_SGIX_flush_raster ()
{
    Wm3NumFunctions_GL_SGIX_flush_raster = 0;

    Wm3glFlushRasterSGIX = (pfn_glFlushRasterSGIX)GetFunctionPointer("glFlushRasterSGIX");
    if ( Wm3glFlushRasterSGIX )
        ++Wm3NumFunctions_GL_SGIX_flush_raster;

    if ( Wm3NumFunctions_GL_SGIX_flush_raster == 1 )
        Wm3Exists_GL_SGIX_flush_raster = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_SGIX_flush_raster = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_SGIX_flush_raster ()
{
    Wm3NumFunctions_GL_SGIX_flush_raster = 0;
    Wm3Exists_GL_SGIX_flush_raster = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_SGIX_depth_texture;
int Wm3NumFunctions_GL_SGIX_depth_texture;
#ifdef WM3_DEFINED_GL_SGIX_depth_texture
static void Init_GL_SGIX_depth_texture ()
{
    Wm3NumFunctions_GL_SGIX_depth_texture = 0;
    Wm3Exists_GL_SGIX_depth_texture = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_SGIX_depth_texture ()
{
    Wm3NumFunctions_GL_SGIX_depth_texture = 0;
    Wm3Exists_GL_SGIX_depth_texture = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_SGIS_fog_function;
int Wm3NumFunctions_GL_SGIS_fog_function;
#ifdef WM3_DEFINED_GL_SGIS_fog_function
pfn_glFogFuncSGIS Wm3glFogFuncSGIS = 0;
pfn_glGetFogFuncSGIS Wm3glGetFogFuncSGIS = 0;

static void Init_GL_SGIS_fog_function ()
{
    Wm3NumFunctions_GL_SGIS_fog_function = 0;

    Wm3glFogFuncSGIS = (pfn_glFogFuncSGIS)GetFunctionPointer("glFogFuncSGIS");
    if ( Wm3glFogFuncSGIS )
        ++Wm3NumFunctions_GL_SGIS_fog_function;

    Wm3glGetFogFuncSGIS = (pfn_glGetFogFuncSGIS)GetFunctionPointer("glGetFogFuncSGIS");
    if ( Wm3glGetFogFuncSGIS )
        ++Wm3NumFunctions_GL_SGIS_fog_function;

    if ( Wm3NumFunctions_GL_SGIS_fog_function == 2 )
        Wm3Exists_GL_SGIS_fog_function = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_SGIS_fog_function = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_SGIS_fog_function ()
{
    Wm3NumFunctions_GL_SGIS_fog_function = 0;
    Wm3Exists_GL_SGIS_fog_function = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_SGIX_fog_offset;
int Wm3NumFunctions_GL_SGIX_fog_offset;
#ifdef WM3_DEFINED_GL_SGIX_fog_offset
static void Init_GL_SGIX_fog_offset ()
{
    Wm3NumFunctions_GL_SGIX_fog_offset = 0;
    Wm3Exists_GL_SGIX_fog_offset = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_SGIX_fog_offset ()
{
    Wm3NumFunctions_GL_SGIX_fog_offset = 0;
    Wm3Exists_GL_SGIX_fog_offset = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_HP_image_transform;
int Wm3NumFunctions_GL_HP_image_transform;
#ifdef WM3_DEFINED_GL_HP_image_transform
pfn_glImageTransformParameteriHP Wm3glImageTransformParameteriHP = 0;
pfn_glImageTransformParameterfHP Wm3glImageTransformParameterfHP = 0;
pfn_glImageTransformParameterivHP Wm3glImageTransformParameterivHP = 0;
pfn_glImageTransformParameterfvHP Wm3glImageTransformParameterfvHP = 0;
pfn_glGetImageTransformParameterivHP Wm3glGetImageTransformParameterivHP = 0;
pfn_glGetImageTransformParameterfvHP Wm3glGetImageTransformParameterfvHP = 0;

static void Init_GL_HP_image_transform ()
{
    Wm3NumFunctions_GL_HP_image_transform = 0;

    Wm3glImageTransformParameteriHP = (pfn_glImageTransformParameteriHP)GetFunctionPointer("glImageTransformParameteriHP");
    if ( Wm3glImageTransformParameteriHP )
        ++Wm3NumFunctions_GL_HP_image_transform;

    Wm3glImageTransformParameterfHP = (pfn_glImageTransformParameterfHP)GetFunctionPointer("glImageTransformParameterfHP");
    if ( Wm3glImageTransformParameterfHP )
        ++Wm3NumFunctions_GL_HP_image_transform;

    Wm3glImageTransformParameterivHP = (pfn_glImageTransformParameterivHP)GetFunctionPointer("glImageTransformParameterivHP");
    if ( Wm3glImageTransformParameterivHP )
        ++Wm3NumFunctions_GL_HP_image_transform;

    Wm3glImageTransformParameterfvHP = (pfn_glImageTransformParameterfvHP)GetFunctionPointer("glImageTransformParameterfvHP");
    if ( Wm3glImageTransformParameterfvHP )
        ++Wm3NumFunctions_GL_HP_image_transform;

    Wm3glGetImageTransformParameterivHP = (pfn_glGetImageTransformParameterivHP)GetFunctionPointer("glGetImageTransformParameterivHP");
    if ( Wm3glGetImageTransformParameterivHP )
        ++Wm3NumFunctions_GL_HP_image_transform;

    Wm3glGetImageTransformParameterfvHP = (pfn_glGetImageTransformParameterfvHP)GetFunctionPointer("glGetImageTransformParameterfvHP");
    if ( Wm3glGetImageTransformParameterfvHP )
        ++Wm3NumFunctions_GL_HP_image_transform;

    if ( Wm3NumFunctions_GL_HP_image_transform == 6 )
        Wm3Exists_GL_HP_image_transform = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_HP_image_transform = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_HP_image_transform ()
{
    Wm3NumFunctions_GL_HP_image_transform = 0;
    Wm3Exists_GL_HP_image_transform = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_HP_convolution_border_modes;
int Wm3NumFunctions_GL_HP_convolution_border_modes;
#ifdef WM3_DEFINED_GL_HP_convolution_border_modes
static void Init_GL_HP_convolution_border_modes ()
{
    Wm3NumFunctions_GL_HP_convolution_border_modes = 0;
    Wm3Exists_GL_HP_convolution_border_modes = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_HP_convolution_border_modes ()
{
    Wm3NumFunctions_GL_HP_convolution_border_modes = 0;
    Wm3Exists_GL_HP_convolution_border_modes = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_INGR_palette_buffer;
int Wm3NumFunctions_GL_INGR_palette_buffer;
#ifdef WM3_DEFINED_GL_INGR_palette_buffer
static void Init_GL_INGR_palette_buffer ()
{
    Wm3NumFunctions_GL_INGR_palette_buffer = 0;
    Wm3Exists_GL_INGR_palette_buffer = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_INGR_palette_buffer ()
{
    Wm3NumFunctions_GL_INGR_palette_buffer = 0;
    Wm3Exists_GL_INGR_palette_buffer = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_SGIX_texture_add_env;
int Wm3NumFunctions_GL_SGIX_texture_add_env;
#ifdef WM3_DEFINED_GL_SGIX_texture_add_env
static void Init_GL_SGIX_texture_add_env ()
{
    Wm3NumFunctions_GL_SGIX_texture_add_env = 0;
    Wm3Exists_GL_SGIX_texture_add_env = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_SGIX_texture_add_env ()
{
    Wm3NumFunctions_GL_SGIX_texture_add_env = 0;
    Wm3Exists_GL_SGIX_texture_add_env = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_EXT_color_subtable;
int Wm3NumFunctions_GL_EXT_color_subtable;
#ifdef WM3_DEFINED_GL_EXT_color_subtable
pfn_glColorSubTableEXT Wm3glColorSubTableEXT = 0;
pfn_glCopyColorSubTableEXT Wm3glCopyColorSubTableEXT = 0;

static void Init_GL_EXT_color_subtable ()
{
    Wm3NumFunctions_GL_EXT_color_subtable = 0;

    Wm3glColorSubTableEXT = (pfn_glColorSubTableEXT)GetFunctionPointer("glColorSubTableEXT");
    if ( Wm3glColorSubTableEXT )
        ++Wm3NumFunctions_GL_EXT_color_subtable;

    Wm3glCopyColorSubTableEXT = (pfn_glCopyColorSubTableEXT)GetFunctionPointer("glCopyColorSubTableEXT");
    if ( Wm3glCopyColorSubTableEXT )
        ++Wm3NumFunctions_GL_EXT_color_subtable;

    if ( Wm3NumFunctions_GL_EXT_color_subtable == 2 )
        Wm3Exists_GL_EXT_color_subtable = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_EXT_color_subtable = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_EXT_color_subtable ()
{
    Wm3NumFunctions_GL_EXT_color_subtable = 0;
    Wm3Exists_GL_EXT_color_subtable = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_PGI_vertex_hints;
int Wm3NumFunctions_GL_PGI_vertex_hints;
#ifdef WM3_DEFINED_GL_PGI_vertex_hints
static void Init_GL_PGI_vertex_hints ()
{
    Wm3NumFunctions_GL_PGI_vertex_hints = 0;
    Wm3Exists_GL_PGI_vertex_hints = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_PGI_vertex_hints ()
{
    Wm3NumFunctions_GL_PGI_vertex_hints = 0;
    Wm3Exists_GL_PGI_vertex_hints = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_PGI_misc_hints;
int Wm3NumFunctions_GL_PGI_misc_hints;
#ifdef WM3_DEFINED_GL_PGI_misc_hints
pfn_glHintPGI Wm3glHintPGI = 0;

static void Init_GL_PGI_misc_hints ()
{
    Wm3NumFunctions_GL_PGI_misc_hints = 0;

    Wm3glHintPGI = (pfn_glHintPGI)GetFunctionPointer("glHintPGI");
    if ( Wm3glHintPGI )
        ++Wm3NumFunctions_GL_PGI_misc_hints;

    if ( Wm3NumFunctions_GL_PGI_misc_hints == 1 )
        Wm3Exists_GL_PGI_misc_hints = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_PGI_misc_hints = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_PGI_misc_hints ()
{
    Wm3NumFunctions_GL_PGI_misc_hints = 0;
    Wm3Exists_GL_PGI_misc_hints = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_EXT_paletted_texture;
int Wm3NumFunctions_GL_EXT_paletted_texture;
#ifdef WM3_DEFINED_GL_EXT_paletted_texture
pfn_glColorTableEXT Wm3glColorTableEXT = 0;
pfn_glGetColorTableEXT Wm3glGetColorTableEXT = 0;
pfn_glGetColorTableParameterivEXT Wm3glGetColorTableParameterivEXT = 0;
pfn_glGetColorTableParameterfvEXT Wm3glGetColorTableParameterfvEXT = 0;

static void Init_GL_EXT_paletted_texture ()
{
    Wm3NumFunctions_GL_EXT_paletted_texture = 0;

    Wm3glColorTableEXT = (pfn_glColorTableEXT)GetFunctionPointer("glColorTableEXT");
    if ( Wm3glColorTableEXT )
        ++Wm3NumFunctions_GL_EXT_paletted_texture;

    Wm3glGetColorTableEXT = (pfn_glGetColorTableEXT)GetFunctionPointer("glGetColorTableEXT");
    if ( Wm3glGetColorTableEXT )
        ++Wm3NumFunctions_GL_EXT_paletted_texture;

    Wm3glGetColorTableParameterivEXT = (pfn_glGetColorTableParameterivEXT)GetFunctionPointer("glGetColorTableParameterivEXT");
    if ( Wm3glGetColorTableParameterivEXT )
        ++Wm3NumFunctions_GL_EXT_paletted_texture;

    Wm3glGetColorTableParameterfvEXT = (pfn_glGetColorTableParameterfvEXT)GetFunctionPointer("glGetColorTableParameterfvEXT");
    if ( Wm3glGetColorTableParameterfvEXT )
        ++Wm3NumFunctions_GL_EXT_paletted_texture;

    if ( Wm3NumFunctions_GL_EXT_paletted_texture == 4 )
        Wm3Exists_GL_EXT_paletted_texture = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_EXT_paletted_texture = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_EXT_paletted_texture ()
{
    Wm3NumFunctions_GL_EXT_paletted_texture = 0;
    Wm3Exists_GL_EXT_paletted_texture = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_EXT_clip_volume_hint;
int Wm3NumFunctions_GL_EXT_clip_volume_hint;
#ifdef WM3_DEFINED_GL_EXT_clip_volume_hint
static void Init_GL_EXT_clip_volume_hint ()
{
    Wm3NumFunctions_GL_EXT_clip_volume_hint = 0;
    Wm3Exists_GL_EXT_clip_volume_hint = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_EXT_clip_volume_hint ()
{
    Wm3NumFunctions_GL_EXT_clip_volume_hint = 0;
    Wm3Exists_GL_EXT_clip_volume_hint = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_SGIX_list_priority;
int Wm3NumFunctions_GL_SGIX_list_priority;
#ifdef WM3_DEFINED_GL_SGIX_list_priority
pfn_glGetListParameterfvSGIX Wm3glGetListParameterfvSGIX = 0;
pfn_glGetListParameterivSGIX Wm3glGetListParameterivSGIX = 0;
pfn_glListParameterfSGIX Wm3glListParameterfSGIX = 0;
pfn_glListParameterfvSGIX Wm3glListParameterfvSGIX = 0;
pfn_glListParameteriSGIX Wm3glListParameteriSGIX = 0;
pfn_glListParameterivSGIX Wm3glListParameterivSGIX = 0;

static void Init_GL_SGIX_list_priority ()
{
    Wm3NumFunctions_GL_SGIX_list_priority = 0;

    Wm3glGetListParameterfvSGIX = (pfn_glGetListParameterfvSGIX)GetFunctionPointer("glGetListParameterfvSGIX");
    if ( Wm3glGetListParameterfvSGIX )
        ++Wm3NumFunctions_GL_SGIX_list_priority;

    Wm3glGetListParameterivSGIX = (pfn_glGetListParameterivSGIX)GetFunctionPointer("glGetListParameterivSGIX");
    if ( Wm3glGetListParameterivSGIX )
        ++Wm3NumFunctions_GL_SGIX_list_priority;

    Wm3glListParameterfSGIX = (pfn_glListParameterfSGIX)GetFunctionPointer("glListParameterfSGIX");
    if ( Wm3glListParameterfSGIX )
        ++Wm3NumFunctions_GL_SGIX_list_priority;

    Wm3glListParameterfvSGIX = (pfn_glListParameterfvSGIX)GetFunctionPointer("glListParameterfvSGIX");
    if ( Wm3glListParameterfvSGIX )
        ++Wm3NumFunctions_GL_SGIX_list_priority;

    Wm3glListParameteriSGIX = (pfn_glListParameteriSGIX)GetFunctionPointer("glListParameteriSGIX");
    if ( Wm3glListParameteriSGIX )
        ++Wm3NumFunctions_GL_SGIX_list_priority;

    Wm3glListParameterivSGIX = (pfn_glListParameterivSGIX)GetFunctionPointer("glListParameterivSGIX");
    if ( Wm3glListParameterivSGIX )
        ++Wm3NumFunctions_GL_SGIX_list_priority;

    if ( Wm3NumFunctions_GL_SGIX_list_priority == 6 )
        Wm3Exists_GL_SGIX_list_priority = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_SGIX_list_priority = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_SGIX_list_priority ()
{
    Wm3NumFunctions_GL_SGIX_list_priority = 0;
    Wm3Exists_GL_SGIX_list_priority = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_SGIX_ir_instrument1;
int Wm3NumFunctions_GL_SGIX_ir_instrument1;
#ifdef WM3_DEFINED_GL_SGIX_ir_instrument1
static void Init_GL_SGIX_ir_instrument1 ()
{
    Wm3NumFunctions_GL_SGIX_ir_instrument1 = 0;
    Wm3Exists_GL_SGIX_ir_instrument1 = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_SGIX_ir_instrument1 ()
{
    Wm3NumFunctions_GL_SGIX_ir_instrument1 = 0;
    Wm3Exists_GL_SGIX_ir_instrument1 = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_SGIX_calligraphic_fragment;
int Wm3NumFunctions_GL_SGIX_calligraphic_fragment;
#ifdef WM3_DEFINED_GL_SGIX_calligraphic_fragment
static void Init_GL_SGIX_calligraphic_fragment ()
{
    Wm3NumFunctions_GL_SGIX_calligraphic_fragment = 0;
    Wm3Exists_GL_SGIX_calligraphic_fragment = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_SGIX_calligraphic_fragment ()
{
    Wm3NumFunctions_GL_SGIX_calligraphic_fragment = 0;
    Wm3Exists_GL_SGIX_calligraphic_fragment = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_SGIX_texture_lod_bias;
int Wm3NumFunctions_GL_SGIX_texture_lod_bias;
#ifdef WM3_DEFINED_GL_SGIX_texture_lod_bias
static void Init_GL_SGIX_texture_lod_bias ()
{
    Wm3NumFunctions_GL_SGIX_texture_lod_bias = 0;
    Wm3Exists_GL_SGIX_texture_lod_bias = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_SGIX_texture_lod_bias ()
{
    Wm3NumFunctions_GL_SGIX_texture_lod_bias = 0;
    Wm3Exists_GL_SGIX_texture_lod_bias = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_SGIX_shadow_ambient;
int Wm3NumFunctions_GL_SGIX_shadow_ambient;
#ifdef WM3_DEFINED_GL_SGIX_shadow_ambient
static void Init_GL_SGIX_shadow_ambient ()
{
    Wm3NumFunctions_GL_SGIX_shadow_ambient = 0;
    Wm3Exists_GL_SGIX_shadow_ambient = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_SGIX_shadow_ambient ()
{
    Wm3NumFunctions_GL_SGIX_shadow_ambient = 0;
    Wm3Exists_GL_SGIX_shadow_ambient = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_EXT_index_texture;
int Wm3NumFunctions_GL_EXT_index_texture;
#ifdef WM3_DEFINED_GL_EXT_index_texture
static void Init_GL_EXT_index_texture ()
{
    Wm3NumFunctions_GL_EXT_index_texture = 0;
    Wm3Exists_GL_EXT_index_texture = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_EXT_index_texture ()
{
    Wm3NumFunctions_GL_EXT_index_texture = 0;
    Wm3Exists_GL_EXT_index_texture = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_EXT_index_material;
int Wm3NumFunctions_GL_EXT_index_material;
#ifdef WM3_DEFINED_GL_EXT_index_material
pfn_glIndexMaterialEXT Wm3glIndexMaterialEXT = 0;

static void Init_GL_EXT_index_material ()
{
    Wm3NumFunctions_GL_EXT_index_material = 0;

    Wm3glIndexMaterialEXT = (pfn_glIndexMaterialEXT)GetFunctionPointer("glIndexMaterialEXT");
    if ( Wm3glIndexMaterialEXT )
        ++Wm3NumFunctions_GL_EXT_index_material;

    if ( Wm3NumFunctions_GL_EXT_index_material == 1 )
        Wm3Exists_GL_EXT_index_material = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_EXT_index_material = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_EXT_index_material ()
{
    Wm3NumFunctions_GL_EXT_index_material = 0;
    Wm3Exists_GL_EXT_index_material = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_EXT_index_func;
int Wm3NumFunctions_GL_EXT_index_func;
#ifdef WM3_DEFINED_GL_EXT_index_func
pfn_glIndexFuncEXT Wm3glIndexFuncEXT = 0;

static void Init_GL_EXT_index_func ()
{
    Wm3NumFunctions_GL_EXT_index_func = 0;

    Wm3glIndexFuncEXT = (pfn_glIndexFuncEXT)GetFunctionPointer("glIndexFuncEXT");
    if ( Wm3glIndexFuncEXT )
        ++Wm3NumFunctions_GL_EXT_index_func;

    if ( Wm3NumFunctions_GL_EXT_index_func == 1 )
        Wm3Exists_GL_EXT_index_func = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_EXT_index_func = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_EXT_index_func ()
{
    Wm3NumFunctions_GL_EXT_index_func = 0;
    Wm3Exists_GL_EXT_index_func = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_EXT_index_array_formats;
int Wm3NumFunctions_GL_EXT_index_array_formats;
#ifdef WM3_DEFINED_GL_EXT_index_array_formats
static void Init_GL_EXT_index_array_formats ()
{
    Wm3NumFunctions_GL_EXT_index_array_formats = 0;
    Wm3Exists_GL_EXT_index_array_formats = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_EXT_index_array_formats ()
{
    Wm3NumFunctions_GL_EXT_index_array_formats = 0;
    Wm3Exists_GL_EXT_index_array_formats = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_EXT_compiled_vertex_array;
int Wm3NumFunctions_GL_EXT_compiled_vertex_array;
#ifdef WM3_DEFINED_GL_EXT_compiled_vertex_array
pfn_glLockArraysEXT Wm3glLockArraysEXT = 0;
pfn_glUnlockArraysEXT Wm3glUnlockArraysEXT = 0;

static void Init_GL_EXT_compiled_vertex_array ()
{
    Wm3NumFunctions_GL_EXT_compiled_vertex_array = 0;

    Wm3glLockArraysEXT = (pfn_glLockArraysEXT)GetFunctionPointer("glLockArraysEXT");
    if ( Wm3glLockArraysEXT )
        ++Wm3NumFunctions_GL_EXT_compiled_vertex_array;

    Wm3glUnlockArraysEXT = (pfn_glUnlockArraysEXT)GetFunctionPointer("glUnlockArraysEXT");
    if ( Wm3glUnlockArraysEXT )
        ++Wm3NumFunctions_GL_EXT_compiled_vertex_array;

    if ( Wm3NumFunctions_GL_EXT_compiled_vertex_array == 2 )
        Wm3Exists_GL_EXT_compiled_vertex_array = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_EXT_compiled_vertex_array = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_EXT_compiled_vertex_array ()
{
    Wm3NumFunctions_GL_EXT_compiled_vertex_array = 0;
    Wm3Exists_GL_EXT_compiled_vertex_array = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_EXT_cull_vertex;
int Wm3NumFunctions_GL_EXT_cull_vertex;
#ifdef WM3_DEFINED_GL_EXT_cull_vertex
pfn_glCullParameterdvEXT Wm3glCullParameterdvEXT = 0;
pfn_glCullParameterfvEXT Wm3glCullParameterfvEXT = 0;

static void Init_GL_EXT_cull_vertex ()
{
    Wm3NumFunctions_GL_EXT_cull_vertex = 0;

    Wm3glCullParameterdvEXT = (pfn_glCullParameterdvEXT)GetFunctionPointer("glCullParameterdvEXT");
    if ( Wm3glCullParameterdvEXT )
        ++Wm3NumFunctions_GL_EXT_cull_vertex;

    Wm3glCullParameterfvEXT = (pfn_glCullParameterfvEXT)GetFunctionPointer("glCullParameterfvEXT");
    if ( Wm3glCullParameterfvEXT )
        ++Wm3NumFunctions_GL_EXT_cull_vertex;

    if ( Wm3NumFunctions_GL_EXT_cull_vertex == 2 )
        Wm3Exists_GL_EXT_cull_vertex = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_EXT_cull_vertex = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_EXT_cull_vertex ()
{
    Wm3NumFunctions_GL_EXT_cull_vertex = 0;
    Wm3Exists_GL_EXT_cull_vertex = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_SGIX_ycrcb;
int Wm3NumFunctions_GL_SGIX_ycrcb;
#ifdef WM3_DEFINED_GL_SGIX_ycrcb
static void Init_GL_SGIX_ycrcb ()
{
    Wm3NumFunctions_GL_SGIX_ycrcb = 0;
    Wm3Exists_GL_SGIX_ycrcb = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_SGIX_ycrcb ()
{
    Wm3NumFunctions_GL_SGIX_ycrcb = 0;
    Wm3Exists_GL_SGIX_ycrcb = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_SGIX_fragment_lighting;
int Wm3NumFunctions_GL_SGIX_fragment_lighting;
#ifdef WM3_DEFINED_GL_SGIX_fragment_lighting
pfn_glFragmentColorMaterialSGIX Wm3glFragmentColorMaterialSGIX = 0;
pfn_glFragmentLightfSGIX Wm3glFragmentLightfSGIX = 0;
pfn_glFragmentLightfvSGIX Wm3glFragmentLightfvSGIX = 0;
pfn_glFragmentLightiSGIX Wm3glFragmentLightiSGIX = 0;
pfn_glFragmentLightivSGIX Wm3glFragmentLightivSGIX = 0;
pfn_glFragmentLightModelfSGIX Wm3glFragmentLightModelfSGIX = 0;
pfn_glFragmentLightModelfvSGIX Wm3glFragmentLightModelfvSGIX = 0;
pfn_glFragmentLightModeliSGIX Wm3glFragmentLightModeliSGIX = 0;
pfn_glFragmentLightModelivSGIX Wm3glFragmentLightModelivSGIX = 0;
pfn_glFragmentMaterialfSGIX Wm3glFragmentMaterialfSGIX = 0;
pfn_glFragmentMaterialfvSGIX Wm3glFragmentMaterialfvSGIX = 0;
pfn_glFragmentMaterialiSGIX Wm3glFragmentMaterialiSGIX = 0;
pfn_glFragmentMaterialivSGIX Wm3glFragmentMaterialivSGIX = 0;
pfn_glGetFragmentLightfvSGIX Wm3glGetFragmentLightfvSGIX = 0;
pfn_glGetFragmentLightivSGIX Wm3glGetFragmentLightivSGIX = 0;
pfn_glGetFragmentMaterialfvSGIX Wm3glGetFragmentMaterialfvSGIX = 0;
pfn_glGetFragmentMaterialivSGIX Wm3glGetFragmentMaterialivSGIX = 0;
pfn_glLightEnviSGIX Wm3glLightEnviSGIX = 0;

static void Init_GL_SGIX_fragment_lighting ()
{
    Wm3NumFunctions_GL_SGIX_fragment_lighting = 0;

    Wm3glFragmentColorMaterialSGIX = (pfn_glFragmentColorMaterialSGIX)GetFunctionPointer("glFragmentColorMaterialSGIX");
    if ( Wm3glFragmentColorMaterialSGIX )
        ++Wm3NumFunctions_GL_SGIX_fragment_lighting;

    Wm3glFragmentLightfSGIX = (pfn_glFragmentLightfSGIX)GetFunctionPointer("glFragmentLightfSGIX");
    if ( Wm3glFragmentLightfSGIX )
        ++Wm3NumFunctions_GL_SGIX_fragment_lighting;

    Wm3glFragmentLightfvSGIX = (pfn_glFragmentLightfvSGIX)GetFunctionPointer("glFragmentLightfvSGIX");
    if ( Wm3glFragmentLightfvSGIX )
        ++Wm3NumFunctions_GL_SGIX_fragment_lighting;

    Wm3glFragmentLightiSGIX = (pfn_glFragmentLightiSGIX)GetFunctionPointer("glFragmentLightiSGIX");
    if ( Wm3glFragmentLightiSGIX )
        ++Wm3NumFunctions_GL_SGIX_fragment_lighting;

    Wm3glFragmentLightivSGIX = (pfn_glFragmentLightivSGIX)GetFunctionPointer("glFragmentLightivSGIX");
    if ( Wm3glFragmentLightivSGIX )
        ++Wm3NumFunctions_GL_SGIX_fragment_lighting;

    Wm3glFragmentLightModelfSGIX = (pfn_glFragmentLightModelfSGIX)GetFunctionPointer("glFragmentLightModelfSGIX");
    if ( Wm3glFragmentLightModelfSGIX )
        ++Wm3NumFunctions_GL_SGIX_fragment_lighting;

    Wm3glFragmentLightModelfvSGIX = (pfn_glFragmentLightModelfvSGIX)GetFunctionPointer("glFragmentLightModelfvSGIX");
    if ( Wm3glFragmentLightModelfvSGIX )
        ++Wm3NumFunctions_GL_SGIX_fragment_lighting;

    Wm3glFragmentLightModeliSGIX = (pfn_glFragmentLightModeliSGIX)GetFunctionPointer("glFragmentLightModeliSGIX");
    if ( Wm3glFragmentLightModeliSGIX )
        ++Wm3NumFunctions_GL_SGIX_fragment_lighting;

    Wm3glFragmentLightModelivSGIX = (pfn_glFragmentLightModelivSGIX)GetFunctionPointer("glFragmentLightModelivSGIX");
    if ( Wm3glFragmentLightModelivSGIX )
        ++Wm3NumFunctions_GL_SGIX_fragment_lighting;

    Wm3glFragmentMaterialfSGIX = (pfn_glFragmentMaterialfSGIX)GetFunctionPointer("glFragmentMaterialfSGIX");
    if ( Wm3glFragmentMaterialfSGIX )
        ++Wm3NumFunctions_GL_SGIX_fragment_lighting;

    Wm3glFragmentMaterialfvSGIX = (pfn_glFragmentMaterialfvSGIX)GetFunctionPointer("glFragmentMaterialfvSGIX");
    if ( Wm3glFragmentMaterialfvSGIX )
        ++Wm3NumFunctions_GL_SGIX_fragment_lighting;

    Wm3glFragmentMaterialiSGIX = (pfn_glFragmentMaterialiSGIX)GetFunctionPointer("glFragmentMaterialiSGIX");
    if ( Wm3glFragmentMaterialiSGIX )
        ++Wm3NumFunctions_GL_SGIX_fragment_lighting;

    Wm3glFragmentMaterialivSGIX = (pfn_glFragmentMaterialivSGIX)GetFunctionPointer("glFragmentMaterialivSGIX");
    if ( Wm3glFragmentMaterialivSGIX )
        ++Wm3NumFunctions_GL_SGIX_fragment_lighting;

    Wm3glGetFragmentLightfvSGIX = (pfn_glGetFragmentLightfvSGIX)GetFunctionPointer("glGetFragmentLightfvSGIX");
    if ( Wm3glGetFragmentLightfvSGIX )
        ++Wm3NumFunctions_GL_SGIX_fragment_lighting;

    Wm3glGetFragmentLightivSGIX = (pfn_glGetFragmentLightivSGIX)GetFunctionPointer("glGetFragmentLightivSGIX");
    if ( Wm3glGetFragmentLightivSGIX )
        ++Wm3NumFunctions_GL_SGIX_fragment_lighting;

    Wm3glGetFragmentMaterialfvSGIX = (pfn_glGetFragmentMaterialfvSGIX)GetFunctionPointer("glGetFragmentMaterialfvSGIX");
    if ( Wm3glGetFragmentMaterialfvSGIX )
        ++Wm3NumFunctions_GL_SGIX_fragment_lighting;

    Wm3glGetFragmentMaterialivSGIX = (pfn_glGetFragmentMaterialivSGIX)GetFunctionPointer("glGetFragmentMaterialivSGIX");
    if ( Wm3glGetFragmentMaterialivSGIX )
        ++Wm3NumFunctions_GL_SGIX_fragment_lighting;

    Wm3glLightEnviSGIX = (pfn_glLightEnviSGIX)GetFunctionPointer("glLightEnviSGIX");
    if ( Wm3glLightEnviSGIX )
        ++Wm3NumFunctions_GL_SGIX_fragment_lighting;

    if ( Wm3NumFunctions_GL_SGIX_fragment_lighting == 18 )
        Wm3Exists_GL_SGIX_fragment_lighting = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_SGIX_fragment_lighting = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_SGIX_fragment_lighting ()
{
    Wm3NumFunctions_GL_SGIX_fragment_lighting = 0;
    Wm3Exists_GL_SGIX_fragment_lighting = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_IBM_rasterpos_clip;
int Wm3NumFunctions_GL_IBM_rasterpos_clip;
#ifdef WM3_DEFINED_GL_IBM_rasterpos_clip
static void Init_GL_IBM_rasterpos_clip ()
{
    Wm3NumFunctions_GL_IBM_rasterpos_clip = 0;
    Wm3Exists_GL_IBM_rasterpos_clip = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_IBM_rasterpos_clip ()
{
    Wm3NumFunctions_GL_IBM_rasterpos_clip = 0;
    Wm3Exists_GL_IBM_rasterpos_clip = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_HP_texture_lighting;
int Wm3NumFunctions_GL_HP_texture_lighting;
#ifdef WM3_DEFINED_GL_HP_texture_lighting
static void Init_GL_HP_texture_lighting ()
{
    Wm3NumFunctions_GL_HP_texture_lighting = 0;
    Wm3Exists_GL_HP_texture_lighting = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_HP_texture_lighting ()
{
    Wm3NumFunctions_GL_HP_texture_lighting = 0;
    Wm3Exists_GL_HP_texture_lighting = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_EXT_draw_range_elements;
int Wm3NumFunctions_GL_EXT_draw_range_elements;
#ifdef WM3_DEFINED_GL_EXT_draw_range_elements
pfn_glDrawRangeElementsEXT Wm3glDrawRangeElementsEXT = 0;

static void Init_GL_EXT_draw_range_elements ()
{
    Wm3NumFunctions_GL_EXT_draw_range_elements = 0;

    Wm3glDrawRangeElementsEXT = (pfn_glDrawRangeElementsEXT)GetFunctionPointer("glDrawRangeElementsEXT");
    if ( Wm3glDrawRangeElementsEXT )
        ++Wm3NumFunctions_GL_EXT_draw_range_elements;

    if ( Wm3NumFunctions_GL_EXT_draw_range_elements == 1 )
        Wm3Exists_GL_EXT_draw_range_elements = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_EXT_draw_range_elements = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_EXT_draw_range_elements ()
{
    Wm3NumFunctions_GL_EXT_draw_range_elements = 0;
    Wm3Exists_GL_EXT_draw_range_elements = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_WIN_phong_shading;
int Wm3NumFunctions_GL_WIN_phong_shading;
#ifdef WM3_DEFINED_GL_WIN_phong_shading
static void Init_GL_WIN_phong_shading ()
{
    Wm3NumFunctions_GL_WIN_phong_shading = 0;
    Wm3Exists_GL_WIN_phong_shading = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_WIN_phong_shading ()
{
    Wm3NumFunctions_GL_WIN_phong_shading = 0;
    Wm3Exists_GL_WIN_phong_shading = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_WIN_specular_fog;
int Wm3NumFunctions_GL_WIN_specular_fog;
#ifdef WM3_DEFINED_GL_WIN_specular_fog
static void Init_GL_WIN_specular_fog ()
{
    Wm3NumFunctions_GL_WIN_specular_fog = 0;
    Wm3Exists_GL_WIN_specular_fog = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_WIN_specular_fog ()
{
    Wm3NumFunctions_GL_WIN_specular_fog = 0;
    Wm3Exists_GL_WIN_specular_fog = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_EXT_light_texture;
int Wm3NumFunctions_GL_EXT_light_texture;
#ifdef WM3_DEFINED_GL_EXT_light_texture
pfn_glApplyTextureEXT Wm3glApplyTextureEXT = 0;
pfn_glTextureLightEXT Wm3glTextureLightEXT = 0;
pfn_glTextureMaterialEXT Wm3glTextureMaterialEXT = 0;

static void Init_GL_EXT_light_texture ()
{
    Wm3NumFunctions_GL_EXT_light_texture = 0;

    Wm3glApplyTextureEXT = (pfn_glApplyTextureEXT)GetFunctionPointer("glApplyTextureEXT");
    if ( Wm3glApplyTextureEXT )
        ++Wm3NumFunctions_GL_EXT_light_texture;

    Wm3glTextureLightEXT = (pfn_glTextureLightEXT)GetFunctionPointer("glTextureLightEXT");
    if ( Wm3glTextureLightEXT )
        ++Wm3NumFunctions_GL_EXT_light_texture;

    Wm3glTextureMaterialEXT = (pfn_glTextureMaterialEXT)GetFunctionPointer("glTextureMaterialEXT");
    if ( Wm3glTextureMaterialEXT )
        ++Wm3NumFunctions_GL_EXT_light_texture;

    if ( Wm3NumFunctions_GL_EXT_light_texture == 3 )
        Wm3Exists_GL_EXT_light_texture = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_EXT_light_texture = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_EXT_light_texture ()
{
    Wm3NumFunctions_GL_EXT_light_texture = 0;
    Wm3Exists_GL_EXT_light_texture = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_SGIX_blend_alpha_minmax;
int Wm3NumFunctions_GL_SGIX_blend_alpha_minmax;
#ifdef WM3_DEFINED_GL_SGIX_blend_alpha_minmax
static void Init_GL_SGIX_blend_alpha_minmax ()
{
    Wm3NumFunctions_GL_SGIX_blend_alpha_minmax = 0;
    Wm3Exists_GL_SGIX_blend_alpha_minmax = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_SGIX_blend_alpha_minmax ()
{
    Wm3NumFunctions_GL_SGIX_blend_alpha_minmax = 0;
    Wm3Exists_GL_SGIX_blend_alpha_minmax = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_SGIX_impact_pixel_texture;
int Wm3NumFunctions_GL_SGIX_impact_pixel_texture;
#ifdef WM3_DEFINED_GL_SGIX_impact_pixel_texture
static void Init_GL_SGIX_impact_pixel_texture ()
{
    Wm3NumFunctions_GL_SGIX_impact_pixel_texture = 0;
    Wm3Exists_GL_SGIX_impact_pixel_texture = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_SGIX_impact_pixel_texture ()
{
    Wm3NumFunctions_GL_SGIX_impact_pixel_texture = 0;
    Wm3Exists_GL_SGIX_impact_pixel_texture = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_EXT_bgra;
int Wm3NumFunctions_GL_EXT_bgra;
#ifdef WM3_DEFINED_GL_EXT_bgra
static void Init_GL_EXT_bgra ()
{
    Wm3NumFunctions_GL_EXT_bgra = 0;
    Wm3Exists_GL_EXT_bgra = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_EXT_bgra ()
{
    Wm3NumFunctions_GL_EXT_bgra = 0;
    Wm3Exists_GL_EXT_bgra = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_SGIX_async;
int Wm3NumFunctions_GL_SGIX_async;
#ifdef WM3_DEFINED_GL_SGIX_async
pfn_glAsyncMarkerSGIX Wm3glAsyncMarkerSGIX = 0;
pfn_glFinishAsyncSGIX Wm3glFinishAsyncSGIX = 0;
pfn_glPollAsyncSGIX Wm3glPollAsyncSGIX = 0;
pfn_glGenAsyncMarkersSGIX Wm3glGenAsyncMarkersSGIX = 0;
pfn_glDeleteAsyncMarkersSGIX Wm3glDeleteAsyncMarkersSGIX = 0;
pfn_glIsAsyncMarkerSGIX Wm3glIsAsyncMarkerSGIX = 0;

static void Init_GL_SGIX_async ()
{
    Wm3NumFunctions_GL_SGIX_async = 0;

    Wm3glAsyncMarkerSGIX = (pfn_glAsyncMarkerSGIX)GetFunctionPointer("glAsyncMarkerSGIX");
    if ( Wm3glAsyncMarkerSGIX )
        ++Wm3NumFunctions_GL_SGIX_async;

    Wm3glFinishAsyncSGIX = (pfn_glFinishAsyncSGIX)GetFunctionPointer("glFinishAsyncSGIX");
    if ( Wm3glFinishAsyncSGIX )
        ++Wm3NumFunctions_GL_SGIX_async;

    Wm3glPollAsyncSGIX = (pfn_glPollAsyncSGIX)GetFunctionPointer("glPollAsyncSGIX");
    if ( Wm3glPollAsyncSGIX )
        ++Wm3NumFunctions_GL_SGIX_async;

    Wm3glGenAsyncMarkersSGIX = (pfn_glGenAsyncMarkersSGIX)GetFunctionPointer("glGenAsyncMarkersSGIX");
    if ( Wm3glGenAsyncMarkersSGIX )
        ++Wm3NumFunctions_GL_SGIX_async;

    Wm3glDeleteAsyncMarkersSGIX = (pfn_glDeleteAsyncMarkersSGIX)GetFunctionPointer("glDeleteAsyncMarkersSGIX");
    if ( Wm3glDeleteAsyncMarkersSGIX )
        ++Wm3NumFunctions_GL_SGIX_async;

    Wm3glIsAsyncMarkerSGIX = (pfn_glIsAsyncMarkerSGIX)GetFunctionPointer("glIsAsyncMarkerSGIX");
    if ( Wm3glIsAsyncMarkerSGIX )
        ++Wm3NumFunctions_GL_SGIX_async;

    if ( Wm3NumFunctions_GL_SGIX_async == 6 )
        Wm3Exists_GL_SGIX_async = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_SGIX_async = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_SGIX_async ()
{
    Wm3NumFunctions_GL_SGIX_async = 0;
    Wm3Exists_GL_SGIX_async = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_SGIX_async_pixel;
int Wm3NumFunctions_GL_SGIX_async_pixel;
#ifdef WM3_DEFINED_GL_SGIX_async_pixel
static void Init_GL_SGIX_async_pixel ()
{
    Wm3NumFunctions_GL_SGIX_async_pixel = 0;
    Wm3Exists_GL_SGIX_async_pixel = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_SGIX_async_pixel ()
{
    Wm3NumFunctions_GL_SGIX_async_pixel = 0;
    Wm3Exists_GL_SGIX_async_pixel = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_SGIX_async_histogram;
int Wm3NumFunctions_GL_SGIX_async_histogram;
#ifdef WM3_DEFINED_GL_SGIX_async_histogram
static void Init_GL_SGIX_async_histogram ()
{
    Wm3NumFunctions_GL_SGIX_async_histogram = 0;
    Wm3Exists_GL_SGIX_async_histogram = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_SGIX_async_histogram ()
{
    Wm3NumFunctions_GL_SGIX_async_histogram = 0;
    Wm3Exists_GL_SGIX_async_histogram = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_INTEL_texture_scissor;
int Wm3NumFunctions_GL_INTEL_texture_scissor;
#ifdef WM3_DEFINED_GL_INTEL_texture_scissor
static void Init_GL_INTEL_texture_scissor ()
{
    Wm3NumFunctions_GL_INTEL_texture_scissor = 0;
    Wm3Exists_GL_INTEL_texture_scissor = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_INTEL_texture_scissor ()
{
    Wm3NumFunctions_GL_INTEL_texture_scissor = 0;
    Wm3Exists_GL_INTEL_texture_scissor = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_INTEL_parallel_arrays;
int Wm3NumFunctions_GL_INTEL_parallel_arrays;
#ifdef WM3_DEFINED_GL_INTEL_parallel_arrays
pfn_glVertexPointervINTEL Wm3glVertexPointervINTEL = 0;
pfn_glNormalPointervINTEL Wm3glNormalPointervINTEL = 0;
pfn_glColorPointervINTEL Wm3glColorPointervINTEL = 0;
pfn_glTexCoordPointervINTEL Wm3glTexCoordPointervINTEL = 0;

static void Init_GL_INTEL_parallel_arrays ()
{
    Wm3NumFunctions_GL_INTEL_parallel_arrays = 0;

    Wm3glVertexPointervINTEL = (pfn_glVertexPointervINTEL)GetFunctionPointer("glVertexPointervINTEL");
    if ( Wm3glVertexPointervINTEL )
        ++Wm3NumFunctions_GL_INTEL_parallel_arrays;

    Wm3glNormalPointervINTEL = (pfn_glNormalPointervINTEL)GetFunctionPointer("glNormalPointervINTEL");
    if ( Wm3glNormalPointervINTEL )
        ++Wm3NumFunctions_GL_INTEL_parallel_arrays;

    Wm3glColorPointervINTEL = (pfn_glColorPointervINTEL)GetFunctionPointer("glColorPointervINTEL");
    if ( Wm3glColorPointervINTEL )
        ++Wm3NumFunctions_GL_INTEL_parallel_arrays;

    Wm3glTexCoordPointervINTEL = (pfn_glTexCoordPointervINTEL)GetFunctionPointer("glTexCoordPointervINTEL");
    if ( Wm3glTexCoordPointervINTEL )
        ++Wm3NumFunctions_GL_INTEL_parallel_arrays;

    if ( Wm3NumFunctions_GL_INTEL_parallel_arrays == 4 )
        Wm3Exists_GL_INTEL_parallel_arrays = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_INTEL_parallel_arrays = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_INTEL_parallel_arrays ()
{
    Wm3NumFunctions_GL_INTEL_parallel_arrays = 0;
    Wm3Exists_GL_INTEL_parallel_arrays = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_HP_occlusion_test;
int Wm3NumFunctions_GL_HP_occlusion_test;
#ifdef WM3_DEFINED_GL_HP_occlusion_test
static void Init_GL_HP_occlusion_test ()
{
    Wm3NumFunctions_GL_HP_occlusion_test = 0;
    Wm3Exists_GL_HP_occlusion_test = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_HP_occlusion_test ()
{
    Wm3NumFunctions_GL_HP_occlusion_test = 0;
    Wm3Exists_GL_HP_occlusion_test = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_EXT_pixel_transform;
int Wm3NumFunctions_GL_EXT_pixel_transform;
#ifdef WM3_DEFINED_GL_EXT_pixel_transform
pfn_glPixelTransformParameteriEXT Wm3glPixelTransformParameteriEXT = 0;
pfn_glPixelTransformParameterfEXT Wm3glPixelTransformParameterfEXT = 0;
pfn_glPixelTransformParameterivEXT Wm3glPixelTransformParameterivEXT = 0;
pfn_glPixelTransformParameterfvEXT Wm3glPixelTransformParameterfvEXT = 0;

static void Init_GL_EXT_pixel_transform ()
{
    Wm3NumFunctions_GL_EXT_pixel_transform = 0;

    Wm3glPixelTransformParameteriEXT = (pfn_glPixelTransformParameteriEXT)GetFunctionPointer("glPixelTransformParameteriEXT");
    if ( Wm3glPixelTransformParameteriEXT )
        ++Wm3NumFunctions_GL_EXT_pixel_transform;

    Wm3glPixelTransformParameterfEXT = (pfn_glPixelTransformParameterfEXT)GetFunctionPointer("glPixelTransformParameterfEXT");
    if ( Wm3glPixelTransformParameterfEXT )
        ++Wm3NumFunctions_GL_EXT_pixel_transform;

    Wm3glPixelTransformParameterivEXT = (pfn_glPixelTransformParameterivEXT)GetFunctionPointer("glPixelTransformParameterivEXT");
    if ( Wm3glPixelTransformParameterivEXT )
        ++Wm3NumFunctions_GL_EXT_pixel_transform;

    Wm3glPixelTransformParameterfvEXT = (pfn_glPixelTransformParameterfvEXT)GetFunctionPointer("glPixelTransformParameterfvEXT");
    if ( Wm3glPixelTransformParameterfvEXT )
        ++Wm3NumFunctions_GL_EXT_pixel_transform;

    if ( Wm3NumFunctions_GL_EXT_pixel_transform == 4 )
        Wm3Exists_GL_EXT_pixel_transform = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_EXT_pixel_transform = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_EXT_pixel_transform ()
{
    Wm3NumFunctions_GL_EXT_pixel_transform = 0;
    Wm3Exists_GL_EXT_pixel_transform = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_EXT_pixel_transform_color_table;
int Wm3NumFunctions_GL_EXT_pixel_transform_color_table;
#ifdef WM3_DEFINED_GL_EXT_pixel_transform_color_table
static void Init_GL_EXT_pixel_transform_color_table ()
{
    Wm3NumFunctions_GL_EXT_pixel_transform_color_table = 0;
    Wm3Exists_GL_EXT_pixel_transform_color_table = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_EXT_pixel_transform_color_table ()
{
    Wm3NumFunctions_GL_EXT_pixel_transform_color_table = 0;
    Wm3Exists_GL_EXT_pixel_transform_color_table = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_EXT_shared_texture_palette;
int Wm3NumFunctions_GL_EXT_shared_texture_palette;
#ifdef WM3_DEFINED_GL_EXT_shared_texture_palette
static void Init_GL_EXT_shared_texture_palette ()
{
    Wm3NumFunctions_GL_EXT_shared_texture_palette = 0;
    Wm3Exists_GL_EXT_shared_texture_palette = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_EXT_shared_texture_palette ()
{
    Wm3NumFunctions_GL_EXT_shared_texture_palette = 0;
    Wm3Exists_GL_EXT_shared_texture_palette = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_EXT_separate_specular_color;
int Wm3NumFunctions_GL_EXT_separate_specular_color;
#ifdef WM3_DEFINED_GL_EXT_separate_specular_color
static void Init_GL_EXT_separate_specular_color ()
{
    Wm3NumFunctions_GL_EXT_separate_specular_color = 0;
    Wm3Exists_GL_EXT_separate_specular_color = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_EXT_separate_specular_color ()
{
    Wm3NumFunctions_GL_EXT_separate_specular_color = 0;
    Wm3Exists_GL_EXT_separate_specular_color = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_EXT_secondary_color;
int Wm3NumFunctions_GL_EXT_secondary_color;
#ifdef WM3_DEFINED_GL_EXT_secondary_color
pfn_glSecondaryColor3bEXT Wm3glSecondaryColor3bEXT = 0;
pfn_glSecondaryColor3bvEXT Wm3glSecondaryColor3bvEXT = 0;
pfn_glSecondaryColor3dEXT Wm3glSecondaryColor3dEXT = 0;
pfn_glSecondaryColor3dvEXT Wm3glSecondaryColor3dvEXT = 0;
pfn_glSecondaryColor3fEXT Wm3glSecondaryColor3fEXT = 0;
pfn_glSecondaryColor3fvEXT Wm3glSecondaryColor3fvEXT = 0;
pfn_glSecondaryColor3iEXT Wm3glSecondaryColor3iEXT = 0;
pfn_glSecondaryColor3ivEXT Wm3glSecondaryColor3ivEXT = 0;
pfn_glSecondaryColor3sEXT Wm3glSecondaryColor3sEXT = 0;
pfn_glSecondaryColor3svEXT Wm3glSecondaryColor3svEXT = 0;
pfn_glSecondaryColor3ubEXT Wm3glSecondaryColor3ubEXT = 0;
pfn_glSecondaryColor3ubvEXT Wm3glSecondaryColor3ubvEXT = 0;
pfn_glSecondaryColor3uiEXT Wm3glSecondaryColor3uiEXT = 0;
pfn_glSecondaryColor3uivEXT Wm3glSecondaryColor3uivEXT = 0;
pfn_glSecondaryColor3usEXT Wm3glSecondaryColor3usEXT = 0;
pfn_glSecondaryColor3usvEXT Wm3glSecondaryColor3usvEXT = 0;
pfn_glSecondaryColorPointerEXT Wm3glSecondaryColorPointerEXT = 0;

static void Init_GL_EXT_secondary_color ()
{
    Wm3NumFunctions_GL_EXT_secondary_color = 0;

    Wm3glSecondaryColor3bEXT = (pfn_glSecondaryColor3bEXT)GetFunctionPointer("glSecondaryColor3bEXT");
    if ( Wm3glSecondaryColor3bEXT )
        ++Wm3NumFunctions_GL_EXT_secondary_color;

    Wm3glSecondaryColor3bvEXT = (pfn_glSecondaryColor3bvEXT)GetFunctionPointer("glSecondaryColor3bvEXT");
    if ( Wm3glSecondaryColor3bvEXT )
        ++Wm3NumFunctions_GL_EXT_secondary_color;

    Wm3glSecondaryColor3dEXT = (pfn_glSecondaryColor3dEXT)GetFunctionPointer("glSecondaryColor3dEXT");
    if ( Wm3glSecondaryColor3dEXT )
        ++Wm3NumFunctions_GL_EXT_secondary_color;

    Wm3glSecondaryColor3dvEXT = (pfn_glSecondaryColor3dvEXT)GetFunctionPointer("glSecondaryColor3dvEXT");
    if ( Wm3glSecondaryColor3dvEXT )
        ++Wm3NumFunctions_GL_EXT_secondary_color;

    Wm3glSecondaryColor3fEXT = (pfn_glSecondaryColor3fEXT)GetFunctionPointer("glSecondaryColor3fEXT");
    if ( Wm3glSecondaryColor3fEXT )
        ++Wm3NumFunctions_GL_EXT_secondary_color;

    Wm3glSecondaryColor3fvEXT = (pfn_glSecondaryColor3fvEXT)GetFunctionPointer("glSecondaryColor3fvEXT");
    if ( Wm3glSecondaryColor3fvEXT )
        ++Wm3NumFunctions_GL_EXT_secondary_color;

    Wm3glSecondaryColor3iEXT = (pfn_glSecondaryColor3iEXT)GetFunctionPointer("glSecondaryColor3iEXT");
    if ( Wm3glSecondaryColor3iEXT )
        ++Wm3NumFunctions_GL_EXT_secondary_color;

    Wm3glSecondaryColor3ivEXT = (pfn_glSecondaryColor3ivEXT)GetFunctionPointer("glSecondaryColor3ivEXT");
    if ( Wm3glSecondaryColor3ivEXT )
        ++Wm3NumFunctions_GL_EXT_secondary_color;

    Wm3glSecondaryColor3sEXT = (pfn_glSecondaryColor3sEXT)GetFunctionPointer("glSecondaryColor3sEXT");
    if ( Wm3glSecondaryColor3sEXT )
        ++Wm3NumFunctions_GL_EXT_secondary_color;

    Wm3glSecondaryColor3svEXT = (pfn_glSecondaryColor3svEXT)GetFunctionPointer("glSecondaryColor3svEXT");
    if ( Wm3glSecondaryColor3svEXT )
        ++Wm3NumFunctions_GL_EXT_secondary_color;

    Wm3glSecondaryColor3ubEXT = (pfn_glSecondaryColor3ubEXT)GetFunctionPointer("glSecondaryColor3ubEXT");
    if ( Wm3glSecondaryColor3ubEXT )
        ++Wm3NumFunctions_GL_EXT_secondary_color;

    Wm3glSecondaryColor3ubvEXT = (pfn_glSecondaryColor3ubvEXT)GetFunctionPointer("glSecondaryColor3ubvEXT");
    if ( Wm3glSecondaryColor3ubvEXT )
        ++Wm3NumFunctions_GL_EXT_secondary_color;

    Wm3glSecondaryColor3uiEXT = (pfn_glSecondaryColor3uiEXT)GetFunctionPointer("glSecondaryColor3uiEXT");
    if ( Wm3glSecondaryColor3uiEXT )
        ++Wm3NumFunctions_GL_EXT_secondary_color;

    Wm3glSecondaryColor3uivEXT = (pfn_glSecondaryColor3uivEXT)GetFunctionPointer("glSecondaryColor3uivEXT");
    if ( Wm3glSecondaryColor3uivEXT )
        ++Wm3NumFunctions_GL_EXT_secondary_color;

    Wm3glSecondaryColor3usEXT = (pfn_glSecondaryColor3usEXT)GetFunctionPointer("glSecondaryColor3usEXT");
    if ( Wm3glSecondaryColor3usEXT )
        ++Wm3NumFunctions_GL_EXT_secondary_color;

    Wm3glSecondaryColor3usvEXT = (pfn_glSecondaryColor3usvEXT)GetFunctionPointer("glSecondaryColor3usvEXT");
    if ( Wm3glSecondaryColor3usvEXT )
        ++Wm3NumFunctions_GL_EXT_secondary_color;

    Wm3glSecondaryColorPointerEXT = (pfn_glSecondaryColorPointerEXT)GetFunctionPointer("glSecondaryColorPointerEXT");
    if ( Wm3glSecondaryColorPointerEXT )
        ++Wm3NumFunctions_GL_EXT_secondary_color;

    if ( Wm3NumFunctions_GL_EXT_secondary_color == 17 )
        Wm3Exists_GL_EXT_secondary_color = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_EXT_secondary_color = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_EXT_secondary_color ()
{
    Wm3NumFunctions_GL_EXT_secondary_color = 0;
    Wm3Exists_GL_EXT_secondary_color = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_EXT_texture_perturb_normal;
int Wm3NumFunctions_GL_EXT_texture_perturb_normal;
#ifdef WM3_DEFINED_GL_EXT_texture_perturb_normal
pfn_glTextureNormalEXT Wm3glTextureNormalEXT = 0;

static void Init_GL_EXT_texture_perturb_normal ()
{
    Wm3NumFunctions_GL_EXT_texture_perturb_normal = 0;

    Wm3glTextureNormalEXT = (pfn_glTextureNormalEXT)GetFunctionPointer("glTextureNormalEXT");
    if ( Wm3glTextureNormalEXT )
        ++Wm3NumFunctions_GL_EXT_texture_perturb_normal;

    if ( Wm3NumFunctions_GL_EXT_texture_perturb_normal == 1 )
        Wm3Exists_GL_EXT_texture_perturb_normal = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_EXT_texture_perturb_normal = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_EXT_texture_perturb_normal ()
{
    Wm3NumFunctions_GL_EXT_texture_perturb_normal = 0;
    Wm3Exists_GL_EXT_texture_perturb_normal = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_EXT_multi_draw_arrays;
int Wm3NumFunctions_GL_EXT_multi_draw_arrays;
#ifdef WM3_DEFINED_GL_EXT_multi_draw_arrays
pfn_glMultiDrawArraysEXT Wm3glMultiDrawArraysEXT = 0;
pfn_glMultiDrawElementsEXT Wm3glMultiDrawElementsEXT = 0;

static void Init_GL_EXT_multi_draw_arrays ()
{
    Wm3NumFunctions_GL_EXT_multi_draw_arrays = 0;

    Wm3glMultiDrawArraysEXT = (pfn_glMultiDrawArraysEXT)GetFunctionPointer("glMultiDrawArraysEXT");
    if ( Wm3glMultiDrawArraysEXT )
        ++Wm3NumFunctions_GL_EXT_multi_draw_arrays;

    Wm3glMultiDrawElementsEXT = (pfn_glMultiDrawElementsEXT)GetFunctionPointer("glMultiDrawElementsEXT");
    if ( Wm3glMultiDrawElementsEXT )
        ++Wm3NumFunctions_GL_EXT_multi_draw_arrays;

    if ( Wm3NumFunctions_GL_EXT_multi_draw_arrays == 2 )
        Wm3Exists_GL_EXT_multi_draw_arrays = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_EXT_multi_draw_arrays = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_EXT_multi_draw_arrays ()
{
    Wm3NumFunctions_GL_EXT_multi_draw_arrays = 0;
    Wm3Exists_GL_EXT_multi_draw_arrays = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_EXT_fog_coord;
int Wm3NumFunctions_GL_EXT_fog_coord;
#ifdef WM3_DEFINED_GL_EXT_fog_coord
pfn_glFogCoordfEXT Wm3glFogCoordfEXT = 0;
pfn_glFogCoordfvEXT Wm3glFogCoordfvEXT = 0;
pfn_glFogCoorddEXT Wm3glFogCoorddEXT = 0;
pfn_glFogCoorddvEXT Wm3glFogCoorddvEXT = 0;
pfn_glFogCoordPointerEXT Wm3glFogCoordPointerEXT = 0;

static void Init_GL_EXT_fog_coord ()
{
    Wm3NumFunctions_GL_EXT_fog_coord = 0;

    Wm3glFogCoordfEXT = (pfn_glFogCoordfEXT)GetFunctionPointer("glFogCoordfEXT");
    if ( Wm3glFogCoordfEXT )
        ++Wm3NumFunctions_GL_EXT_fog_coord;

    Wm3glFogCoordfvEXT = (pfn_glFogCoordfvEXT)GetFunctionPointer("glFogCoordfvEXT");
    if ( Wm3glFogCoordfvEXT )
        ++Wm3NumFunctions_GL_EXT_fog_coord;

    Wm3glFogCoorddEXT = (pfn_glFogCoorddEXT)GetFunctionPointer("glFogCoorddEXT");
    if ( Wm3glFogCoorddEXT )
        ++Wm3NumFunctions_GL_EXT_fog_coord;

    Wm3glFogCoorddvEXT = (pfn_glFogCoorddvEXT)GetFunctionPointer("glFogCoorddvEXT");
    if ( Wm3glFogCoorddvEXT )
        ++Wm3NumFunctions_GL_EXT_fog_coord;

    Wm3glFogCoordPointerEXT = (pfn_glFogCoordPointerEXT)GetFunctionPointer("glFogCoordPointerEXT");
    if ( Wm3glFogCoordPointerEXT )
        ++Wm3NumFunctions_GL_EXT_fog_coord;

    if ( Wm3NumFunctions_GL_EXT_fog_coord == 5 )
        Wm3Exists_GL_EXT_fog_coord = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_EXT_fog_coord = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_EXT_fog_coord ()
{
    Wm3NumFunctions_GL_EXT_fog_coord = 0;
    Wm3Exists_GL_EXT_fog_coord = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_REND_screen_coordinates;
int Wm3NumFunctions_GL_REND_screen_coordinates;
#ifdef WM3_DEFINED_GL_REND_screen_coordinates
static void Init_GL_REND_screen_coordinates ()
{
    Wm3NumFunctions_GL_REND_screen_coordinates = 0;
    Wm3Exists_GL_REND_screen_coordinates = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_REND_screen_coordinates ()
{
    Wm3NumFunctions_GL_REND_screen_coordinates = 0;
    Wm3Exists_GL_REND_screen_coordinates = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_EXT_coordinate_frame;
int Wm3NumFunctions_GL_EXT_coordinate_frame;
#ifdef WM3_DEFINED_GL_EXT_coordinate_frame
pfn_glTangent3bEXT Wm3glTangent3bEXT = 0;
pfn_glTangent3bvEXT Wm3glTangent3bvEXT = 0;
pfn_glTangent3dEXT Wm3glTangent3dEXT = 0;
pfn_glTangent3dvEXT Wm3glTangent3dvEXT = 0;
pfn_glTangent3fEXT Wm3glTangent3fEXT = 0;
pfn_glTangent3fvEXT Wm3glTangent3fvEXT = 0;
pfn_glTangent3iEXT Wm3glTangent3iEXT = 0;
pfn_glTangent3ivEXT Wm3glTangent3ivEXT = 0;
pfn_glTangent3sEXT Wm3glTangent3sEXT = 0;
pfn_glTangent3svEXT Wm3glTangent3svEXT = 0;
pfn_glBinormal3bEXT Wm3glBinormal3bEXT = 0;
pfn_glBinormal3bvEXT Wm3glBinormal3bvEXT = 0;
pfn_glBinormal3dEXT Wm3glBinormal3dEXT = 0;
pfn_glBinormal3dvEXT Wm3glBinormal3dvEXT = 0;
pfn_glBinormal3fEXT Wm3glBinormal3fEXT = 0;
pfn_glBinormal3fvEXT Wm3glBinormal3fvEXT = 0;
pfn_glBinormal3iEXT Wm3glBinormal3iEXT = 0;
pfn_glBinormal3ivEXT Wm3glBinormal3ivEXT = 0;
pfn_glBinormal3sEXT Wm3glBinormal3sEXT = 0;
pfn_glBinormal3svEXT Wm3glBinormal3svEXT = 0;
pfn_glTangentPointerEXT Wm3glTangentPointerEXT = 0;
pfn_glBinormalPointerEXT Wm3glBinormalPointerEXT = 0;

static void Init_GL_EXT_coordinate_frame ()
{
    Wm3NumFunctions_GL_EXT_coordinate_frame = 0;

    Wm3glTangent3bEXT = (pfn_glTangent3bEXT)GetFunctionPointer("glTangent3bEXT");
    if ( Wm3glTangent3bEXT )
        ++Wm3NumFunctions_GL_EXT_coordinate_frame;

    Wm3glTangent3bvEXT = (pfn_glTangent3bvEXT)GetFunctionPointer("glTangent3bvEXT");
    if ( Wm3glTangent3bvEXT )
        ++Wm3NumFunctions_GL_EXT_coordinate_frame;

    Wm3glTangent3dEXT = (pfn_glTangent3dEXT)GetFunctionPointer("glTangent3dEXT");
    if ( Wm3glTangent3dEXT )
        ++Wm3NumFunctions_GL_EXT_coordinate_frame;

    Wm3glTangent3dvEXT = (pfn_glTangent3dvEXT)GetFunctionPointer("glTangent3dvEXT");
    if ( Wm3glTangent3dvEXT )
        ++Wm3NumFunctions_GL_EXT_coordinate_frame;

    Wm3glTangent3fEXT = (pfn_glTangent3fEXT)GetFunctionPointer("glTangent3fEXT");
    if ( Wm3glTangent3fEXT )
        ++Wm3NumFunctions_GL_EXT_coordinate_frame;

    Wm3glTangent3fvEXT = (pfn_glTangent3fvEXT)GetFunctionPointer("glTangent3fvEXT");
    if ( Wm3glTangent3fvEXT )
        ++Wm3NumFunctions_GL_EXT_coordinate_frame;

    Wm3glTangent3iEXT = (pfn_glTangent3iEXT)GetFunctionPointer("glTangent3iEXT");
    if ( Wm3glTangent3iEXT )
        ++Wm3NumFunctions_GL_EXT_coordinate_frame;

    Wm3glTangent3ivEXT = (pfn_glTangent3ivEXT)GetFunctionPointer("glTangent3ivEXT");
    if ( Wm3glTangent3ivEXT )
        ++Wm3NumFunctions_GL_EXT_coordinate_frame;

    Wm3glTangent3sEXT = (pfn_glTangent3sEXT)GetFunctionPointer("glTangent3sEXT");
    if ( Wm3glTangent3sEXT )
        ++Wm3NumFunctions_GL_EXT_coordinate_frame;

    Wm3glTangent3svEXT = (pfn_glTangent3svEXT)GetFunctionPointer("glTangent3svEXT");
    if ( Wm3glTangent3svEXT )
        ++Wm3NumFunctions_GL_EXT_coordinate_frame;

    Wm3glBinormal3bEXT = (pfn_glBinormal3bEXT)GetFunctionPointer("glBinormal3bEXT");
    if ( Wm3glBinormal3bEXT )
        ++Wm3NumFunctions_GL_EXT_coordinate_frame;

    Wm3glBinormal3bvEXT = (pfn_glBinormal3bvEXT)GetFunctionPointer("glBinormal3bvEXT");
    if ( Wm3glBinormal3bvEXT )
        ++Wm3NumFunctions_GL_EXT_coordinate_frame;

    Wm3glBinormal3dEXT = (pfn_glBinormal3dEXT)GetFunctionPointer("glBinormal3dEXT");
    if ( Wm3glBinormal3dEXT )
        ++Wm3NumFunctions_GL_EXT_coordinate_frame;

    Wm3glBinormal3dvEXT = (pfn_glBinormal3dvEXT)GetFunctionPointer("glBinormal3dvEXT");
    if ( Wm3glBinormal3dvEXT )
        ++Wm3NumFunctions_GL_EXT_coordinate_frame;

    Wm3glBinormal3fEXT = (pfn_glBinormal3fEXT)GetFunctionPointer("glBinormal3fEXT");
    if ( Wm3glBinormal3fEXT )
        ++Wm3NumFunctions_GL_EXT_coordinate_frame;

    Wm3glBinormal3fvEXT = (pfn_glBinormal3fvEXT)GetFunctionPointer("glBinormal3fvEXT");
    if ( Wm3glBinormal3fvEXT )
        ++Wm3NumFunctions_GL_EXT_coordinate_frame;

    Wm3glBinormal3iEXT = (pfn_glBinormal3iEXT)GetFunctionPointer("glBinormal3iEXT");
    if ( Wm3glBinormal3iEXT )
        ++Wm3NumFunctions_GL_EXT_coordinate_frame;

    Wm3glBinormal3ivEXT = (pfn_glBinormal3ivEXT)GetFunctionPointer("glBinormal3ivEXT");
    if ( Wm3glBinormal3ivEXT )
        ++Wm3NumFunctions_GL_EXT_coordinate_frame;

    Wm3glBinormal3sEXT = (pfn_glBinormal3sEXT)GetFunctionPointer("glBinormal3sEXT");
    if ( Wm3glBinormal3sEXT )
        ++Wm3NumFunctions_GL_EXT_coordinate_frame;

    Wm3glBinormal3svEXT = (pfn_glBinormal3svEXT)GetFunctionPointer("glBinormal3svEXT");
    if ( Wm3glBinormal3svEXT )
        ++Wm3NumFunctions_GL_EXT_coordinate_frame;

    Wm3glTangentPointerEXT = (pfn_glTangentPointerEXT)GetFunctionPointer("glTangentPointerEXT");
    if ( Wm3glTangentPointerEXT )
        ++Wm3NumFunctions_GL_EXT_coordinate_frame;

    Wm3glBinormalPointerEXT = (pfn_glBinormalPointerEXT)GetFunctionPointer("glBinormalPointerEXT");
    if ( Wm3glBinormalPointerEXT )
        ++Wm3NumFunctions_GL_EXT_coordinate_frame;

    if ( Wm3NumFunctions_GL_EXT_coordinate_frame == 22 )
        Wm3Exists_GL_EXT_coordinate_frame = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_EXT_coordinate_frame = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_EXT_coordinate_frame ()
{
    Wm3NumFunctions_GL_EXT_coordinate_frame = 0;
    Wm3Exists_GL_EXT_coordinate_frame = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_EXT_texture_env_combine;
int Wm3NumFunctions_GL_EXT_texture_env_combine;
#ifdef WM3_DEFINED_GL_EXT_texture_env_combine
static void Init_GL_EXT_texture_env_combine ()
{
    Wm3NumFunctions_GL_EXT_texture_env_combine = 0;
    Wm3Exists_GL_EXT_texture_env_combine = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_EXT_texture_env_combine ()
{
    Wm3NumFunctions_GL_EXT_texture_env_combine = 0;
    Wm3Exists_GL_EXT_texture_env_combine = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_APPLE_specular_vector;
int Wm3NumFunctions_GL_APPLE_specular_vector;
#ifdef WM3_DEFINED_GL_APPLE_specular_vector
static void Init_GL_APPLE_specular_vector ()
{
    Wm3NumFunctions_GL_APPLE_specular_vector = 0;
    Wm3Exists_GL_APPLE_specular_vector = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_APPLE_specular_vector ()
{
    Wm3NumFunctions_GL_APPLE_specular_vector = 0;
    Wm3Exists_GL_APPLE_specular_vector = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_APPLE_transform_hint;
int Wm3NumFunctions_GL_APPLE_transform_hint;
#ifdef WM3_DEFINED_GL_APPLE_transform_hint
static void Init_GL_APPLE_transform_hint ()
{
    Wm3NumFunctions_GL_APPLE_transform_hint = 0;
    Wm3Exists_GL_APPLE_transform_hint = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_APPLE_transform_hint ()
{
    Wm3NumFunctions_GL_APPLE_transform_hint = 0;
    Wm3Exists_GL_APPLE_transform_hint = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_SGIX_fog_scale;
int Wm3NumFunctions_GL_SGIX_fog_scale;
#ifdef WM3_DEFINED_GL_SGIX_fog_scale
static void Init_GL_SGIX_fog_scale ()
{
    Wm3NumFunctions_GL_SGIX_fog_scale = 0;
    Wm3Exists_GL_SGIX_fog_scale = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_SGIX_fog_scale ()
{
    Wm3NumFunctions_GL_SGIX_fog_scale = 0;
    Wm3Exists_GL_SGIX_fog_scale = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_SUNX_constant_data;
int Wm3NumFunctions_GL_SUNX_constant_data;
#ifdef WM3_DEFINED_GL_SUNX_constant_data
pfn_glFinishTextureSUNX Wm3glFinishTextureSUNX = 0;

static void Init_GL_SUNX_constant_data ()
{
    Wm3NumFunctions_GL_SUNX_constant_data = 0;

    Wm3glFinishTextureSUNX = (pfn_glFinishTextureSUNX)GetFunctionPointer("glFinishTextureSUNX");
    if ( Wm3glFinishTextureSUNX )
        ++Wm3NumFunctions_GL_SUNX_constant_data;

    if ( Wm3NumFunctions_GL_SUNX_constant_data == 1 )
        Wm3Exists_GL_SUNX_constant_data = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_SUNX_constant_data = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_SUNX_constant_data ()
{
    Wm3NumFunctions_GL_SUNX_constant_data = 0;
    Wm3Exists_GL_SUNX_constant_data = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_SUN_global_alpha;
int Wm3NumFunctions_GL_SUN_global_alpha;
#ifdef WM3_DEFINED_GL_SUN_global_alpha
pfn_glGlobalAlphaFactorbSUN Wm3glGlobalAlphaFactorbSUN = 0;
pfn_glGlobalAlphaFactorsSUN Wm3glGlobalAlphaFactorsSUN = 0;
pfn_glGlobalAlphaFactoriSUN Wm3glGlobalAlphaFactoriSUN = 0;
pfn_glGlobalAlphaFactorfSUN Wm3glGlobalAlphaFactorfSUN = 0;
pfn_glGlobalAlphaFactordSUN Wm3glGlobalAlphaFactordSUN = 0;
pfn_glGlobalAlphaFactorubSUN Wm3glGlobalAlphaFactorubSUN = 0;
pfn_glGlobalAlphaFactorusSUN Wm3glGlobalAlphaFactorusSUN = 0;
pfn_glGlobalAlphaFactoruiSUN Wm3glGlobalAlphaFactoruiSUN = 0;

static void Init_GL_SUN_global_alpha ()
{
    Wm3NumFunctions_GL_SUN_global_alpha = 0;

    Wm3glGlobalAlphaFactorbSUN = (pfn_glGlobalAlphaFactorbSUN)GetFunctionPointer("glGlobalAlphaFactorbSUN");
    if ( Wm3glGlobalAlphaFactorbSUN )
        ++Wm3NumFunctions_GL_SUN_global_alpha;

    Wm3glGlobalAlphaFactorsSUN = (pfn_glGlobalAlphaFactorsSUN)GetFunctionPointer("glGlobalAlphaFactorsSUN");
    if ( Wm3glGlobalAlphaFactorsSUN )
        ++Wm3NumFunctions_GL_SUN_global_alpha;

    Wm3glGlobalAlphaFactoriSUN = (pfn_glGlobalAlphaFactoriSUN)GetFunctionPointer("glGlobalAlphaFactoriSUN");
    if ( Wm3glGlobalAlphaFactoriSUN )
        ++Wm3NumFunctions_GL_SUN_global_alpha;

    Wm3glGlobalAlphaFactorfSUN = (pfn_glGlobalAlphaFactorfSUN)GetFunctionPointer("glGlobalAlphaFactorfSUN");
    if ( Wm3glGlobalAlphaFactorfSUN )
        ++Wm3NumFunctions_GL_SUN_global_alpha;

    Wm3glGlobalAlphaFactordSUN = (pfn_glGlobalAlphaFactordSUN)GetFunctionPointer("glGlobalAlphaFactordSUN");
    if ( Wm3glGlobalAlphaFactordSUN )
        ++Wm3NumFunctions_GL_SUN_global_alpha;

    Wm3glGlobalAlphaFactorubSUN = (pfn_glGlobalAlphaFactorubSUN)GetFunctionPointer("glGlobalAlphaFactorubSUN");
    if ( Wm3glGlobalAlphaFactorubSUN )
        ++Wm3NumFunctions_GL_SUN_global_alpha;

    Wm3glGlobalAlphaFactorusSUN = (pfn_glGlobalAlphaFactorusSUN)GetFunctionPointer("glGlobalAlphaFactorusSUN");
    if ( Wm3glGlobalAlphaFactorusSUN )
        ++Wm3NumFunctions_GL_SUN_global_alpha;

    Wm3glGlobalAlphaFactoruiSUN = (pfn_glGlobalAlphaFactoruiSUN)GetFunctionPointer("glGlobalAlphaFactoruiSUN");
    if ( Wm3glGlobalAlphaFactoruiSUN )
        ++Wm3NumFunctions_GL_SUN_global_alpha;

    if ( Wm3NumFunctions_GL_SUN_global_alpha == 8 )
        Wm3Exists_GL_SUN_global_alpha = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_SUN_global_alpha = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_SUN_global_alpha ()
{
    Wm3NumFunctions_GL_SUN_global_alpha = 0;
    Wm3Exists_GL_SUN_global_alpha = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_SUN_triangle_list;
int Wm3NumFunctions_GL_SUN_triangle_list;
#ifdef WM3_DEFINED_GL_SUN_triangle_list
pfn_glReplacementCodeuiSUN Wm3glReplacementCodeuiSUN = 0;
pfn_glReplacementCodeusSUN Wm3glReplacementCodeusSUN = 0;
pfn_glReplacementCodeubSUN Wm3glReplacementCodeubSUN = 0;
pfn_glReplacementCodeuivSUN Wm3glReplacementCodeuivSUN = 0;
pfn_glReplacementCodeusvSUN Wm3glReplacementCodeusvSUN = 0;
pfn_glReplacementCodeubvSUN Wm3glReplacementCodeubvSUN = 0;
pfn_glReplacementCodePointerSUN Wm3glReplacementCodePointerSUN = 0;

static void Init_GL_SUN_triangle_list ()
{
    Wm3NumFunctions_GL_SUN_triangle_list = 0;

    Wm3glReplacementCodeuiSUN = (pfn_glReplacementCodeuiSUN)GetFunctionPointer("glReplacementCodeuiSUN");
    if ( Wm3glReplacementCodeuiSUN )
        ++Wm3NumFunctions_GL_SUN_triangle_list;

    Wm3glReplacementCodeusSUN = (pfn_glReplacementCodeusSUN)GetFunctionPointer("glReplacementCodeusSUN");
    if ( Wm3glReplacementCodeusSUN )
        ++Wm3NumFunctions_GL_SUN_triangle_list;

    Wm3glReplacementCodeubSUN = (pfn_glReplacementCodeubSUN)GetFunctionPointer("glReplacementCodeubSUN");
    if ( Wm3glReplacementCodeubSUN )
        ++Wm3NumFunctions_GL_SUN_triangle_list;

    Wm3glReplacementCodeuivSUN = (pfn_glReplacementCodeuivSUN)GetFunctionPointer("glReplacementCodeuivSUN");
    if ( Wm3glReplacementCodeuivSUN )
        ++Wm3NumFunctions_GL_SUN_triangle_list;

    Wm3glReplacementCodeusvSUN = (pfn_glReplacementCodeusvSUN)GetFunctionPointer("glReplacementCodeusvSUN");
    if ( Wm3glReplacementCodeusvSUN )
        ++Wm3NumFunctions_GL_SUN_triangle_list;

    Wm3glReplacementCodeubvSUN = (pfn_glReplacementCodeubvSUN)GetFunctionPointer("glReplacementCodeubvSUN");
    if ( Wm3glReplacementCodeubvSUN )
        ++Wm3NumFunctions_GL_SUN_triangle_list;

    Wm3glReplacementCodePointerSUN = (pfn_glReplacementCodePointerSUN)GetFunctionPointer("glReplacementCodePointerSUN");
    if ( Wm3glReplacementCodePointerSUN )
        ++Wm3NumFunctions_GL_SUN_triangle_list;

    if ( Wm3NumFunctions_GL_SUN_triangle_list == 7 )
        Wm3Exists_GL_SUN_triangle_list = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_SUN_triangle_list = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_SUN_triangle_list ()
{
    Wm3NumFunctions_GL_SUN_triangle_list = 0;
    Wm3Exists_GL_SUN_triangle_list = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_SUN_vertex;
int Wm3NumFunctions_GL_SUN_vertex;
#ifdef WM3_DEFINED_GL_SUN_vertex
pfn_glColor4ubVertex2fSUN Wm3glColor4ubVertex2fSUN = 0;
pfn_glColor4ubVertex2fvSUN Wm3glColor4ubVertex2fvSUN = 0;
pfn_glColor4ubVertex3fSUN Wm3glColor4ubVertex3fSUN = 0;
pfn_glColor4ubVertex3fvSUN Wm3glColor4ubVertex3fvSUN = 0;
pfn_glColor3fVertex3fSUN Wm3glColor3fVertex3fSUN = 0;
pfn_glColor3fVertex3fvSUN Wm3glColor3fVertex3fvSUN = 0;
pfn_glNormal3fVertex3fSUN Wm3glNormal3fVertex3fSUN = 0;
pfn_glNormal3fVertex3fvSUN Wm3glNormal3fVertex3fvSUN = 0;
pfn_glColor4fNormal3fVertex3fSUN Wm3glColor4fNormal3fVertex3fSUN = 0;
pfn_glColor4fNormal3fVertex3fvSUN Wm3glColor4fNormal3fVertex3fvSUN = 0;
pfn_glTexCoord2fVertex3fSUN Wm3glTexCoord2fVertex3fSUN = 0;
pfn_glTexCoord2fVertex3fvSUN Wm3glTexCoord2fVertex3fvSUN = 0;
pfn_glTexCoord4fVertex4fSUN Wm3glTexCoord4fVertex4fSUN = 0;
pfn_glTexCoord4fVertex4fvSUN Wm3glTexCoord4fVertex4fvSUN = 0;
pfn_glTexCoord2fColor4ubVertex3fSUN Wm3glTexCoord2fColor4ubVertex3fSUN = 0;
pfn_glTexCoord2fColor4ubVertex3fvSUN Wm3glTexCoord2fColor4ubVertex3fvSUN = 0;
pfn_glTexCoord2fColor3fVertex3fSUN Wm3glTexCoord2fColor3fVertex3fSUN = 0;
pfn_glTexCoord2fColor3fVertex3fvSUN Wm3glTexCoord2fColor3fVertex3fvSUN = 0;
pfn_glTexCoord2fNormal3fVertex3fSUN Wm3glTexCoord2fNormal3fVertex3fSUN = 0;
pfn_glTexCoord2fNormal3fVertex3fvSUN Wm3glTexCoord2fNormal3fVertex3fvSUN = 0;
pfn_glTexCoord2fColor4fNormal3fVertex3fSUN Wm3glTexCoord2fColor4fNormal3fVertex3fSUN = 0;
pfn_glTexCoord2fColor4fNormal3fVertex3fvSUN Wm3glTexCoord2fColor4fNormal3fVertex3fvSUN = 0;
pfn_glTexCoord4fColor4fNormal3fVertex4fSUN Wm3glTexCoord4fColor4fNormal3fVertex4fSUN = 0;
pfn_glTexCoord4fColor4fNormal3fVertex4fvSUN Wm3glTexCoord4fColor4fNormal3fVertex4fvSUN = 0;
pfn_glReplacementCodeuiVertex3fSUN Wm3glReplacementCodeuiVertex3fSUN = 0;
pfn_glReplacementCodeuiVertex3fvSUN Wm3glReplacementCodeuiVertex3fvSUN = 0;
pfn_glReplacementCodeuiColor4ubVertex3fSUN Wm3glReplacementCodeuiColor4ubVertex3fSUN = 0;
pfn_glReplacementCodeuiColor4ubVertex3fvSUN Wm3glReplacementCodeuiColor4ubVertex3fvSUN = 0;
pfn_glReplacementCodeuiColor3fVertex3fSUN Wm3glReplacementCodeuiColor3fVertex3fSUN = 0;
pfn_glReplacementCodeuiColor3fVertex3fvSUN Wm3glReplacementCodeuiColor3fVertex3fvSUN = 0;
pfn_glReplacementCodeuiNormal3fVertex3fSUN Wm3glReplacementCodeuiNormal3fVertex3fSUN = 0;
pfn_glReplacementCodeuiNormal3fVertex3fvSUN Wm3glReplacementCodeuiNormal3fVertex3fvSUN = 0;
pfn_glReplacementCodeuiColor4fNormal3fVertex3fSUN Wm3glReplacementCodeuiColor4fNormal3fVertex3fSUN = 0;
pfn_glReplacementCodeuiColor4fNormal3fVertex3fvSUN Wm3glReplacementCodeuiColor4fNormal3fVertex3fvSUN = 0;
pfn_glReplacementCodeuiTexCoord2fVertex3fSUN Wm3glReplacementCodeuiTexCoord2fVertex3fSUN = 0;
pfn_glReplacementCodeuiTexCoord2fVertex3fvSUN Wm3glReplacementCodeuiTexCoord2fVertex3fvSUN = 0;
pfn_glReplacementCodeuiTexCoord2fNormal3fVertex3fSUN Wm3glReplacementCodeuiTexCoord2fNormal3fVertex3fSUN = 0;
pfn_glReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN Wm3glReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN = 0;
pfn_glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN Wm3glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN = 0;
pfn_glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN Wm3glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN = 0;

static void Init_GL_SUN_vertex ()
{
    Wm3NumFunctions_GL_SUN_vertex = 0;

    Wm3glColor4ubVertex2fSUN = (pfn_glColor4ubVertex2fSUN)GetFunctionPointer("glColor4ubVertex2fSUN");
    if ( Wm3glColor4ubVertex2fSUN )
        ++Wm3NumFunctions_GL_SUN_vertex;

    Wm3glColor4ubVertex2fvSUN = (pfn_glColor4ubVertex2fvSUN)GetFunctionPointer("glColor4ubVertex2fvSUN");
    if ( Wm3glColor4ubVertex2fvSUN )
        ++Wm3NumFunctions_GL_SUN_vertex;

    Wm3glColor4ubVertex3fSUN = (pfn_glColor4ubVertex3fSUN)GetFunctionPointer("glColor4ubVertex3fSUN");
    if ( Wm3glColor4ubVertex3fSUN )
        ++Wm3NumFunctions_GL_SUN_vertex;

    Wm3glColor4ubVertex3fvSUN = (pfn_glColor4ubVertex3fvSUN)GetFunctionPointer("glColor4ubVertex3fvSUN");
    if ( Wm3glColor4ubVertex3fvSUN )
        ++Wm3NumFunctions_GL_SUN_vertex;

    Wm3glColor3fVertex3fSUN = (pfn_glColor3fVertex3fSUN)GetFunctionPointer("glColor3fVertex3fSUN");
    if ( Wm3glColor3fVertex3fSUN )
        ++Wm3NumFunctions_GL_SUN_vertex;

    Wm3glColor3fVertex3fvSUN = (pfn_glColor3fVertex3fvSUN)GetFunctionPointer("glColor3fVertex3fvSUN");
    if ( Wm3glColor3fVertex3fvSUN )
        ++Wm3NumFunctions_GL_SUN_vertex;

    Wm3glNormal3fVertex3fSUN = (pfn_glNormal3fVertex3fSUN)GetFunctionPointer("glNormal3fVertex3fSUN");
    if ( Wm3glNormal3fVertex3fSUN )
        ++Wm3NumFunctions_GL_SUN_vertex;

    Wm3glNormal3fVertex3fvSUN = (pfn_glNormal3fVertex3fvSUN)GetFunctionPointer("glNormal3fVertex3fvSUN");
    if ( Wm3glNormal3fVertex3fvSUN )
        ++Wm3NumFunctions_GL_SUN_vertex;

    Wm3glColor4fNormal3fVertex3fSUN = (pfn_glColor4fNormal3fVertex3fSUN)GetFunctionPointer("glColor4fNormal3fVertex3fSUN");
    if ( Wm3glColor4fNormal3fVertex3fSUN )
        ++Wm3NumFunctions_GL_SUN_vertex;

    Wm3glColor4fNormal3fVertex3fvSUN = (pfn_glColor4fNormal3fVertex3fvSUN)GetFunctionPointer("glColor4fNormal3fVertex3fvSUN");
    if ( Wm3glColor4fNormal3fVertex3fvSUN )
        ++Wm3NumFunctions_GL_SUN_vertex;

    Wm3glTexCoord2fVertex3fSUN = (pfn_glTexCoord2fVertex3fSUN)GetFunctionPointer("glTexCoord2fVertex3fSUN");
    if ( Wm3glTexCoord2fVertex3fSUN )
        ++Wm3NumFunctions_GL_SUN_vertex;

    Wm3glTexCoord2fVertex3fvSUN = (pfn_glTexCoord2fVertex3fvSUN)GetFunctionPointer("glTexCoord2fVertex3fvSUN");
    if ( Wm3glTexCoord2fVertex3fvSUN )
        ++Wm3NumFunctions_GL_SUN_vertex;

    Wm3glTexCoord4fVertex4fSUN = (pfn_glTexCoord4fVertex4fSUN)GetFunctionPointer("glTexCoord4fVertex4fSUN");
    if ( Wm3glTexCoord4fVertex4fSUN )
        ++Wm3NumFunctions_GL_SUN_vertex;

    Wm3glTexCoord4fVertex4fvSUN = (pfn_glTexCoord4fVertex4fvSUN)GetFunctionPointer("glTexCoord4fVertex4fvSUN");
    if ( Wm3glTexCoord4fVertex4fvSUN )
        ++Wm3NumFunctions_GL_SUN_vertex;

    Wm3glTexCoord2fColor4ubVertex3fSUN = (pfn_glTexCoord2fColor4ubVertex3fSUN)GetFunctionPointer("glTexCoord2fColor4ubVertex3fSUN");
    if ( Wm3glTexCoord2fColor4ubVertex3fSUN )
        ++Wm3NumFunctions_GL_SUN_vertex;

    Wm3glTexCoord2fColor4ubVertex3fvSUN = (pfn_glTexCoord2fColor4ubVertex3fvSUN)GetFunctionPointer("glTexCoord2fColor4ubVertex3fvSUN");
    if ( Wm3glTexCoord2fColor4ubVertex3fvSUN )
        ++Wm3NumFunctions_GL_SUN_vertex;

    Wm3glTexCoord2fColor3fVertex3fSUN = (pfn_glTexCoord2fColor3fVertex3fSUN)GetFunctionPointer("glTexCoord2fColor3fVertex3fSUN");
    if ( Wm3glTexCoord2fColor3fVertex3fSUN )
        ++Wm3NumFunctions_GL_SUN_vertex;

    Wm3glTexCoord2fColor3fVertex3fvSUN = (pfn_glTexCoord2fColor3fVertex3fvSUN)GetFunctionPointer("glTexCoord2fColor3fVertex3fvSUN");
    if ( Wm3glTexCoord2fColor3fVertex3fvSUN )
        ++Wm3NumFunctions_GL_SUN_vertex;

    Wm3glTexCoord2fNormal3fVertex3fSUN = (pfn_glTexCoord2fNormal3fVertex3fSUN)GetFunctionPointer("glTexCoord2fNormal3fVertex3fSUN");
    if ( Wm3glTexCoord2fNormal3fVertex3fSUN )
        ++Wm3NumFunctions_GL_SUN_vertex;

    Wm3glTexCoord2fNormal3fVertex3fvSUN = (pfn_glTexCoord2fNormal3fVertex3fvSUN)GetFunctionPointer("glTexCoord2fNormal3fVertex3fvSUN");
    if ( Wm3glTexCoord2fNormal3fVertex3fvSUN )
        ++Wm3NumFunctions_GL_SUN_vertex;

    Wm3glTexCoord2fColor4fNormal3fVertex3fSUN = (pfn_glTexCoord2fColor4fNormal3fVertex3fSUN)GetFunctionPointer("glTexCoord2fColor4fNormal3fVertex3fSUN");
    if ( Wm3glTexCoord2fColor4fNormal3fVertex3fSUN )
        ++Wm3NumFunctions_GL_SUN_vertex;

    Wm3glTexCoord2fColor4fNormal3fVertex3fvSUN = (pfn_glTexCoord2fColor4fNormal3fVertex3fvSUN)GetFunctionPointer("glTexCoord2fColor4fNormal3fVertex3fvSUN");
    if ( Wm3glTexCoord2fColor4fNormal3fVertex3fvSUN )
        ++Wm3NumFunctions_GL_SUN_vertex;

    Wm3glTexCoord4fColor4fNormal3fVertex4fSUN = (pfn_glTexCoord4fColor4fNormal3fVertex4fSUN)GetFunctionPointer("glTexCoord4fColor4fNormal3fVertex4fSUN");
    if ( Wm3glTexCoord4fColor4fNormal3fVertex4fSUN )
        ++Wm3NumFunctions_GL_SUN_vertex;

    Wm3glTexCoord4fColor4fNormal3fVertex4fvSUN = (pfn_glTexCoord4fColor4fNormal3fVertex4fvSUN)GetFunctionPointer("glTexCoord4fColor4fNormal3fVertex4fvSUN");
    if ( Wm3glTexCoord4fColor4fNormal3fVertex4fvSUN )
        ++Wm3NumFunctions_GL_SUN_vertex;

    Wm3glReplacementCodeuiVertex3fSUN = (pfn_glReplacementCodeuiVertex3fSUN)GetFunctionPointer("glReplacementCodeuiVertex3fSUN");
    if ( Wm3glReplacementCodeuiVertex3fSUN )
        ++Wm3NumFunctions_GL_SUN_vertex;

    Wm3glReplacementCodeuiVertex3fvSUN = (pfn_glReplacementCodeuiVertex3fvSUN)GetFunctionPointer("glReplacementCodeuiVertex3fvSUN");
    if ( Wm3glReplacementCodeuiVertex3fvSUN )
        ++Wm3NumFunctions_GL_SUN_vertex;

    Wm3glReplacementCodeuiColor4ubVertex3fSUN = (pfn_glReplacementCodeuiColor4ubVertex3fSUN)GetFunctionPointer("glReplacementCodeuiColor4ubVertex3fSUN");
    if ( Wm3glReplacementCodeuiColor4ubVertex3fSUN )
        ++Wm3NumFunctions_GL_SUN_vertex;

    Wm3glReplacementCodeuiColor4ubVertex3fvSUN = (pfn_glReplacementCodeuiColor4ubVertex3fvSUN)GetFunctionPointer("glReplacementCodeuiColor4ubVertex3fvSUN");
    if ( Wm3glReplacementCodeuiColor4ubVertex3fvSUN )
        ++Wm3NumFunctions_GL_SUN_vertex;

    Wm3glReplacementCodeuiColor3fVertex3fSUN = (pfn_glReplacementCodeuiColor3fVertex3fSUN)GetFunctionPointer("glReplacementCodeuiColor3fVertex3fSUN");
    if ( Wm3glReplacementCodeuiColor3fVertex3fSUN )
        ++Wm3NumFunctions_GL_SUN_vertex;

    Wm3glReplacementCodeuiColor3fVertex3fvSUN = (pfn_glReplacementCodeuiColor3fVertex3fvSUN)GetFunctionPointer("glReplacementCodeuiColor3fVertex3fvSUN");
    if ( Wm3glReplacementCodeuiColor3fVertex3fvSUN )
        ++Wm3NumFunctions_GL_SUN_vertex;

    Wm3glReplacementCodeuiNormal3fVertex3fSUN = (pfn_glReplacementCodeuiNormal3fVertex3fSUN)GetFunctionPointer("glReplacementCodeuiNormal3fVertex3fSUN");
    if ( Wm3glReplacementCodeuiNormal3fVertex3fSUN )
        ++Wm3NumFunctions_GL_SUN_vertex;

    Wm3glReplacementCodeuiNormal3fVertex3fvSUN = (pfn_glReplacementCodeuiNormal3fVertex3fvSUN)GetFunctionPointer("glReplacementCodeuiNormal3fVertex3fvSUN");
    if ( Wm3glReplacementCodeuiNormal3fVertex3fvSUN )
        ++Wm3NumFunctions_GL_SUN_vertex;

    Wm3glReplacementCodeuiColor4fNormal3fVertex3fSUN = (pfn_glReplacementCodeuiColor4fNormal3fVertex3fSUN)GetFunctionPointer("glReplacementCodeuiColor4fNormal3fVertex3fSUN");
    if ( Wm3glReplacementCodeuiColor4fNormal3fVertex3fSUN )
        ++Wm3NumFunctions_GL_SUN_vertex;

    Wm3glReplacementCodeuiColor4fNormal3fVertex3fvSUN = (pfn_glReplacementCodeuiColor4fNormal3fVertex3fvSUN)GetFunctionPointer("glReplacementCodeuiColor4fNormal3fVertex3fvSUN");
    if ( Wm3glReplacementCodeuiColor4fNormal3fVertex3fvSUN )
        ++Wm3NumFunctions_GL_SUN_vertex;

    Wm3glReplacementCodeuiTexCoord2fVertex3fSUN = (pfn_glReplacementCodeuiTexCoord2fVertex3fSUN)GetFunctionPointer("glReplacementCodeuiTexCoord2fVertex3fSUN");
    if ( Wm3glReplacementCodeuiTexCoord2fVertex3fSUN )
        ++Wm3NumFunctions_GL_SUN_vertex;

    Wm3glReplacementCodeuiTexCoord2fVertex3fvSUN = (pfn_glReplacementCodeuiTexCoord2fVertex3fvSUN)GetFunctionPointer("glReplacementCodeuiTexCoord2fVertex3fvSUN");
    if ( Wm3glReplacementCodeuiTexCoord2fVertex3fvSUN )
        ++Wm3NumFunctions_GL_SUN_vertex;

    Wm3glReplacementCodeuiTexCoord2fNormal3fVertex3fSUN = (pfn_glReplacementCodeuiTexCoord2fNormal3fVertex3fSUN)GetFunctionPointer("glReplacementCodeuiTexCoord2fNormal3fVertex3fSUN");
    if ( Wm3glReplacementCodeuiTexCoord2fNormal3fVertex3fSUN )
        ++Wm3NumFunctions_GL_SUN_vertex;

    Wm3glReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN = (pfn_glReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN)GetFunctionPointer("glReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN");
    if ( Wm3glReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN )
        ++Wm3NumFunctions_GL_SUN_vertex;

    Wm3glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN = (pfn_glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN)GetFunctionPointer("glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN");
    if ( Wm3glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN )
        ++Wm3NumFunctions_GL_SUN_vertex;

    Wm3glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN = (pfn_glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN)GetFunctionPointer("glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN");
    if ( Wm3glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN )
        ++Wm3NumFunctions_GL_SUN_vertex;

    if ( Wm3NumFunctions_GL_SUN_vertex == 40 )
        Wm3Exists_GL_SUN_vertex = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_SUN_vertex = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_SUN_vertex ()
{
    Wm3NumFunctions_GL_SUN_vertex = 0;
    Wm3Exists_GL_SUN_vertex = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_EXT_blend_func_separate;
int Wm3NumFunctions_GL_EXT_blend_func_separate;
#ifdef WM3_DEFINED_GL_EXT_blend_func_separate
pfn_glBlendFuncSeparateEXT Wm3glBlendFuncSeparateEXT = 0;

static void Init_GL_EXT_blend_func_separate ()
{
    Wm3NumFunctions_GL_EXT_blend_func_separate = 0;

    Wm3glBlendFuncSeparateEXT = (pfn_glBlendFuncSeparateEXT)GetFunctionPointer("glBlendFuncSeparateEXT");
    if ( Wm3glBlendFuncSeparateEXT )
        ++Wm3NumFunctions_GL_EXT_blend_func_separate;

    if ( Wm3NumFunctions_GL_EXT_blend_func_separate == 1 )
        Wm3Exists_GL_EXT_blend_func_separate = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_EXT_blend_func_separate = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_EXT_blend_func_separate ()
{
    Wm3NumFunctions_GL_EXT_blend_func_separate = 0;
    Wm3Exists_GL_EXT_blend_func_separate = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_INGR_blend_func_separate;
int Wm3NumFunctions_GL_INGR_blend_func_separate;
#ifdef WM3_DEFINED_GL_INGR_blend_func_separate
pfn_glBlendFuncSeparateINGR Wm3glBlendFuncSeparateINGR = 0;

static void Init_GL_INGR_blend_func_separate ()
{
    Wm3NumFunctions_GL_INGR_blend_func_separate = 0;

    Wm3glBlendFuncSeparateINGR = (pfn_glBlendFuncSeparateINGR)GetFunctionPointer("glBlendFuncSeparateINGR");
    if ( Wm3glBlendFuncSeparateINGR )
        ++Wm3NumFunctions_GL_INGR_blend_func_separate;

    if ( Wm3NumFunctions_GL_INGR_blend_func_separate == 1 )
        Wm3Exists_GL_INGR_blend_func_separate = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_INGR_blend_func_separate = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_INGR_blend_func_separate ()
{
    Wm3NumFunctions_GL_INGR_blend_func_separate = 0;
    Wm3Exists_GL_INGR_blend_func_separate = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_INGR_color_clamp;
int Wm3NumFunctions_GL_INGR_color_clamp;
#ifdef WM3_DEFINED_GL_INGR_color_clamp
static void Init_GL_INGR_color_clamp ()
{
    Wm3NumFunctions_GL_INGR_color_clamp = 0;
    Wm3Exists_GL_INGR_color_clamp = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_INGR_color_clamp ()
{
    Wm3NumFunctions_GL_INGR_color_clamp = 0;
    Wm3Exists_GL_INGR_color_clamp = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_INGR_interlace_read;
int Wm3NumFunctions_GL_INGR_interlace_read;
#ifdef WM3_DEFINED_GL_INGR_interlace_read
static void Init_GL_INGR_interlace_read ()
{
    Wm3NumFunctions_GL_INGR_interlace_read = 0;
    Wm3Exists_GL_INGR_interlace_read = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_INGR_interlace_read ()
{
    Wm3NumFunctions_GL_INGR_interlace_read = 0;
    Wm3Exists_GL_INGR_interlace_read = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_EXT_stencil_wrap;
int Wm3NumFunctions_GL_EXT_stencil_wrap;
#ifdef WM3_DEFINED_GL_EXT_stencil_wrap
static void Init_GL_EXT_stencil_wrap ()
{
    Wm3NumFunctions_GL_EXT_stencil_wrap = 0;
    Wm3Exists_GL_EXT_stencil_wrap = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_EXT_stencil_wrap ()
{
    Wm3NumFunctions_GL_EXT_stencil_wrap = 0;
    Wm3Exists_GL_EXT_stencil_wrap = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_EXT_422_pixels;
int Wm3NumFunctions_GL_EXT_422_pixels;
#ifdef WM3_DEFINED_GL_EXT_422_pixels
static void Init_GL_EXT_422_pixels ()
{
    Wm3NumFunctions_GL_EXT_422_pixels = 0;
    Wm3Exists_GL_EXT_422_pixels = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_EXT_422_pixels ()
{
    Wm3NumFunctions_GL_EXT_422_pixels = 0;
    Wm3Exists_GL_EXT_422_pixels = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_NV_texgen_reflection;
int Wm3NumFunctions_GL_NV_texgen_reflection;
#ifdef WM3_DEFINED_GL_NV_texgen_reflection
static void Init_GL_NV_texgen_reflection ()
{
    Wm3NumFunctions_GL_NV_texgen_reflection = 0;
    Wm3Exists_GL_NV_texgen_reflection = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_NV_texgen_reflection ()
{
    Wm3NumFunctions_GL_NV_texgen_reflection = 0;
    Wm3Exists_GL_NV_texgen_reflection = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_EXT_texture_cube_map;
int Wm3NumFunctions_GL_EXT_texture_cube_map;
#ifdef WM3_DEFINED_GL_EXT_texture_cube_map
static void Init_GL_EXT_texture_cube_map ()
{
    Wm3NumFunctions_GL_EXT_texture_cube_map = 0;
    Wm3Exists_GL_EXT_texture_cube_map = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_EXT_texture_cube_map ()
{
    Wm3NumFunctions_GL_EXT_texture_cube_map = 0;
    Wm3Exists_GL_EXT_texture_cube_map = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_SUN_convolution_border_modes;
int Wm3NumFunctions_GL_SUN_convolution_border_modes;
#ifdef WM3_DEFINED_GL_SUN_convolution_border_modes
static void Init_GL_SUN_convolution_border_modes ()
{
    Wm3NumFunctions_GL_SUN_convolution_border_modes = 0;
    Wm3Exists_GL_SUN_convolution_border_modes = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_SUN_convolution_border_modes ()
{
    Wm3NumFunctions_GL_SUN_convolution_border_modes = 0;
    Wm3Exists_GL_SUN_convolution_border_modes = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_EXT_texture_env_add;
int Wm3NumFunctions_GL_EXT_texture_env_add;
#ifdef WM3_DEFINED_GL_EXT_texture_env_add
static void Init_GL_EXT_texture_env_add ()
{
    Wm3NumFunctions_GL_EXT_texture_env_add = 0;
    Wm3Exists_GL_EXT_texture_env_add = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_EXT_texture_env_add ()
{
    Wm3NumFunctions_GL_EXT_texture_env_add = 0;
    Wm3Exists_GL_EXT_texture_env_add = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_EXT_texture_lod_bias;
int Wm3NumFunctions_GL_EXT_texture_lod_bias;
#ifdef WM3_DEFINED_GL_EXT_texture_lod_bias
static void Init_GL_EXT_texture_lod_bias ()
{
    Wm3NumFunctions_GL_EXT_texture_lod_bias = 0;
    Wm3Exists_GL_EXT_texture_lod_bias = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_EXT_texture_lod_bias ()
{
    Wm3NumFunctions_GL_EXT_texture_lod_bias = 0;
    Wm3Exists_GL_EXT_texture_lod_bias = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_EXT_texture_filter_anisotropic;
int Wm3NumFunctions_GL_EXT_texture_filter_anisotropic;
#ifdef WM3_DEFINED_GL_EXT_texture_filter_anisotropic
static void Init_GL_EXT_texture_filter_anisotropic ()
{
    Wm3NumFunctions_GL_EXT_texture_filter_anisotropic = 0;
    Wm3Exists_GL_EXT_texture_filter_anisotropic = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_EXT_texture_filter_anisotropic ()
{
    Wm3NumFunctions_GL_EXT_texture_filter_anisotropic = 0;
    Wm3Exists_GL_EXT_texture_filter_anisotropic = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_EXT_vertex_weighting;
int Wm3NumFunctions_GL_EXT_vertex_weighting;
#ifdef WM3_DEFINED_GL_EXT_vertex_weighting
pfn_glVertexWeightfEXT Wm3glVertexWeightfEXT = 0;
pfn_glVertexWeightfvEXT Wm3glVertexWeightfvEXT = 0;
pfn_glVertexWeightPointerEXT Wm3glVertexWeightPointerEXT = 0;

static void Init_GL_EXT_vertex_weighting ()
{
    Wm3NumFunctions_GL_EXT_vertex_weighting = 0;

    Wm3glVertexWeightfEXT = (pfn_glVertexWeightfEXT)GetFunctionPointer("glVertexWeightfEXT");
    if ( Wm3glVertexWeightfEXT )
        ++Wm3NumFunctions_GL_EXT_vertex_weighting;

    Wm3glVertexWeightfvEXT = (pfn_glVertexWeightfvEXT)GetFunctionPointer("glVertexWeightfvEXT");
    if ( Wm3glVertexWeightfvEXT )
        ++Wm3NumFunctions_GL_EXT_vertex_weighting;

    Wm3glVertexWeightPointerEXT = (pfn_glVertexWeightPointerEXT)GetFunctionPointer("glVertexWeightPointerEXT");
    if ( Wm3glVertexWeightPointerEXT )
        ++Wm3NumFunctions_GL_EXT_vertex_weighting;

    if ( Wm3NumFunctions_GL_EXT_vertex_weighting == 3 )
        Wm3Exists_GL_EXT_vertex_weighting = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_EXT_vertex_weighting = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_EXT_vertex_weighting ()
{
    Wm3NumFunctions_GL_EXT_vertex_weighting = 0;
    Wm3Exists_GL_EXT_vertex_weighting = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_NV_light_max_exponent;
int Wm3NumFunctions_GL_NV_light_max_exponent;
#ifdef WM3_DEFINED_GL_NV_light_max_exponent
static void Init_GL_NV_light_max_exponent ()
{
    Wm3NumFunctions_GL_NV_light_max_exponent = 0;
    Wm3Exists_GL_NV_light_max_exponent = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_NV_light_max_exponent ()
{
    Wm3NumFunctions_GL_NV_light_max_exponent = 0;
    Wm3Exists_GL_NV_light_max_exponent = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_NV_vertex_array_range;
int Wm3NumFunctions_GL_NV_vertex_array_range;
#ifdef WM3_DEFINED_GL_NV_vertex_array_range
pfn_glFlushVertexArrayRangeNV Wm3glFlushVertexArrayRangeNV = 0;
pfn_glVertexArrayRangeNV Wm3glVertexArrayRangeNV = 0;

static void Init_GL_NV_vertex_array_range ()
{
    Wm3NumFunctions_GL_NV_vertex_array_range = 0;

    Wm3glFlushVertexArrayRangeNV = (pfn_glFlushVertexArrayRangeNV)GetFunctionPointer("glFlushVertexArrayRangeNV");
    if ( Wm3glFlushVertexArrayRangeNV )
        ++Wm3NumFunctions_GL_NV_vertex_array_range;

    Wm3glVertexArrayRangeNV = (pfn_glVertexArrayRangeNV)GetFunctionPointer("glVertexArrayRangeNV");
    if ( Wm3glVertexArrayRangeNV )
        ++Wm3NumFunctions_GL_NV_vertex_array_range;

    if ( Wm3NumFunctions_GL_NV_vertex_array_range == 2 )
        Wm3Exists_GL_NV_vertex_array_range = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_NV_vertex_array_range = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_NV_vertex_array_range ()
{
    Wm3NumFunctions_GL_NV_vertex_array_range = 0;
    Wm3Exists_GL_NV_vertex_array_range = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_NV_register_combiners;
int Wm3NumFunctions_GL_NV_register_combiners;
#ifdef WM3_DEFINED_GL_NV_register_combiners
pfn_glCombinerParameterfvNV Wm3glCombinerParameterfvNV = 0;
pfn_glCombinerParameterfNV Wm3glCombinerParameterfNV = 0;
pfn_glCombinerParameterivNV Wm3glCombinerParameterivNV = 0;
pfn_glCombinerParameteriNV Wm3glCombinerParameteriNV = 0;
pfn_glCombinerInputNV Wm3glCombinerInputNV = 0;
pfn_glCombinerOutputNV Wm3glCombinerOutputNV = 0;
pfn_glFinalCombinerInputNV Wm3glFinalCombinerInputNV = 0;
pfn_glGetCombinerInputParameterfvNV Wm3glGetCombinerInputParameterfvNV = 0;
pfn_glGetCombinerInputParameterivNV Wm3glGetCombinerInputParameterivNV = 0;
pfn_glGetCombinerOutputParameterfvNV Wm3glGetCombinerOutputParameterfvNV = 0;
pfn_glGetCombinerOutputParameterivNV Wm3glGetCombinerOutputParameterivNV = 0;
pfn_glGetFinalCombinerInputParameterfvNV Wm3glGetFinalCombinerInputParameterfvNV = 0;
pfn_glGetFinalCombinerInputParameterivNV Wm3glGetFinalCombinerInputParameterivNV = 0;

static void Init_GL_NV_register_combiners ()
{
    Wm3NumFunctions_GL_NV_register_combiners = 0;

    Wm3glCombinerParameterfvNV = (pfn_glCombinerParameterfvNV)GetFunctionPointer("glCombinerParameterfvNV");
    if ( Wm3glCombinerParameterfvNV )
        ++Wm3NumFunctions_GL_NV_register_combiners;

    Wm3glCombinerParameterfNV = (pfn_glCombinerParameterfNV)GetFunctionPointer("glCombinerParameterfNV");
    if ( Wm3glCombinerParameterfNV )
        ++Wm3NumFunctions_GL_NV_register_combiners;

    Wm3glCombinerParameterivNV = (pfn_glCombinerParameterivNV)GetFunctionPointer("glCombinerParameterivNV");
    if ( Wm3glCombinerParameterivNV )
        ++Wm3NumFunctions_GL_NV_register_combiners;

    Wm3glCombinerParameteriNV = (pfn_glCombinerParameteriNV)GetFunctionPointer("glCombinerParameteriNV");
    if ( Wm3glCombinerParameteriNV )
        ++Wm3NumFunctions_GL_NV_register_combiners;

    Wm3glCombinerInputNV = (pfn_glCombinerInputNV)GetFunctionPointer("glCombinerInputNV");
    if ( Wm3glCombinerInputNV )
        ++Wm3NumFunctions_GL_NV_register_combiners;

    Wm3glCombinerOutputNV = (pfn_glCombinerOutputNV)GetFunctionPointer("glCombinerOutputNV");
    if ( Wm3glCombinerOutputNV )
        ++Wm3NumFunctions_GL_NV_register_combiners;

    Wm3glFinalCombinerInputNV = (pfn_glFinalCombinerInputNV)GetFunctionPointer("glFinalCombinerInputNV");
    if ( Wm3glFinalCombinerInputNV )
        ++Wm3NumFunctions_GL_NV_register_combiners;

    Wm3glGetCombinerInputParameterfvNV = (pfn_glGetCombinerInputParameterfvNV)GetFunctionPointer("glGetCombinerInputParameterfvNV");
    if ( Wm3glGetCombinerInputParameterfvNV )
        ++Wm3NumFunctions_GL_NV_register_combiners;

    Wm3glGetCombinerInputParameterivNV = (pfn_glGetCombinerInputParameterivNV)GetFunctionPointer("glGetCombinerInputParameterivNV");
    if ( Wm3glGetCombinerInputParameterivNV )
        ++Wm3NumFunctions_GL_NV_register_combiners;

    Wm3glGetCombinerOutputParameterfvNV = (pfn_glGetCombinerOutputParameterfvNV)GetFunctionPointer("glGetCombinerOutputParameterfvNV");
    if ( Wm3glGetCombinerOutputParameterfvNV )
        ++Wm3NumFunctions_GL_NV_register_combiners;

    Wm3glGetCombinerOutputParameterivNV = (pfn_glGetCombinerOutputParameterivNV)GetFunctionPointer("glGetCombinerOutputParameterivNV");
    if ( Wm3glGetCombinerOutputParameterivNV )
        ++Wm3NumFunctions_GL_NV_register_combiners;

    Wm3glGetFinalCombinerInputParameterfvNV = (pfn_glGetFinalCombinerInputParameterfvNV)GetFunctionPointer("glGetFinalCombinerInputParameterfvNV");
    if ( Wm3glGetFinalCombinerInputParameterfvNV )
        ++Wm3NumFunctions_GL_NV_register_combiners;

    Wm3glGetFinalCombinerInputParameterivNV = (pfn_glGetFinalCombinerInputParameterivNV)GetFunctionPointer("glGetFinalCombinerInputParameterivNV");
    if ( Wm3glGetFinalCombinerInputParameterivNV )
        ++Wm3NumFunctions_GL_NV_register_combiners;

    if ( Wm3NumFunctions_GL_NV_register_combiners == 13 )
        Wm3Exists_GL_NV_register_combiners = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_NV_register_combiners = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_NV_register_combiners ()
{
    Wm3NumFunctions_GL_NV_register_combiners = 0;
    Wm3Exists_GL_NV_register_combiners = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_NV_fog_distance;
int Wm3NumFunctions_GL_NV_fog_distance;
#ifdef WM3_DEFINED_GL_NV_fog_distance
static void Init_GL_NV_fog_distance ()
{
    Wm3NumFunctions_GL_NV_fog_distance = 0;
    Wm3Exists_GL_NV_fog_distance = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_NV_fog_distance ()
{
    Wm3NumFunctions_GL_NV_fog_distance = 0;
    Wm3Exists_GL_NV_fog_distance = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_NV_texgen_emboss;
int Wm3NumFunctions_GL_NV_texgen_emboss;
#ifdef WM3_DEFINED_GL_NV_texgen_emboss
static void Init_GL_NV_texgen_emboss ()
{
    Wm3NumFunctions_GL_NV_texgen_emboss = 0;
    Wm3Exists_GL_NV_texgen_emboss = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_NV_texgen_emboss ()
{
    Wm3NumFunctions_GL_NV_texgen_emboss = 0;
    Wm3Exists_GL_NV_texgen_emboss = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_NV_blend_square;
int Wm3NumFunctions_GL_NV_blend_square;
#ifdef WM3_DEFINED_GL_NV_blend_square
static void Init_GL_NV_blend_square ()
{
    Wm3NumFunctions_GL_NV_blend_square = 0;
    Wm3Exists_GL_NV_blend_square = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_NV_blend_square ()
{
    Wm3NumFunctions_GL_NV_blend_square = 0;
    Wm3Exists_GL_NV_blend_square = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_NV_texture_env_combine4;
int Wm3NumFunctions_GL_NV_texture_env_combine4;
#ifdef WM3_DEFINED_GL_NV_texture_env_combine4
static void Init_GL_NV_texture_env_combine4 ()
{
    Wm3NumFunctions_GL_NV_texture_env_combine4 = 0;
    Wm3Exists_GL_NV_texture_env_combine4 = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_NV_texture_env_combine4 ()
{
    Wm3NumFunctions_GL_NV_texture_env_combine4 = 0;
    Wm3Exists_GL_NV_texture_env_combine4 = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_MESA_resize_buffers;
int Wm3NumFunctions_GL_MESA_resize_buffers;
#ifdef WM3_DEFINED_GL_MESA_resize_buffers
pfn_glResizeBuffersMESA Wm3glResizeBuffersMESA = 0;

static void Init_GL_MESA_resize_buffers ()
{
    Wm3NumFunctions_GL_MESA_resize_buffers = 0;

    Wm3glResizeBuffersMESA = (pfn_glResizeBuffersMESA)GetFunctionPointer("glResizeBuffersMESA");
    if ( Wm3glResizeBuffersMESA )
        ++Wm3NumFunctions_GL_MESA_resize_buffers;

    if ( Wm3NumFunctions_GL_MESA_resize_buffers == 1 )
        Wm3Exists_GL_MESA_resize_buffers = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_MESA_resize_buffers = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_MESA_resize_buffers ()
{
    Wm3NumFunctions_GL_MESA_resize_buffers = 0;
    Wm3Exists_GL_MESA_resize_buffers = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_MESA_window_pos;
int Wm3NumFunctions_GL_MESA_window_pos;
#ifdef WM3_DEFINED_GL_MESA_window_pos
pfn_glWindowPos2dMESA Wm3glWindowPos2dMESA = 0;
pfn_glWindowPos2dvMESA Wm3glWindowPos2dvMESA = 0;
pfn_glWindowPos2fMESA Wm3glWindowPos2fMESA = 0;
pfn_glWindowPos2fvMESA Wm3glWindowPos2fvMESA = 0;
pfn_glWindowPos2iMESA Wm3glWindowPos2iMESA = 0;
pfn_glWindowPos2ivMESA Wm3glWindowPos2ivMESA = 0;
pfn_glWindowPos2sMESA Wm3glWindowPos2sMESA = 0;
pfn_glWindowPos2svMESA Wm3glWindowPos2svMESA = 0;
pfn_glWindowPos3dMESA Wm3glWindowPos3dMESA = 0;
pfn_glWindowPos3dvMESA Wm3glWindowPos3dvMESA = 0;
pfn_glWindowPos3fMESA Wm3glWindowPos3fMESA = 0;
pfn_glWindowPos3fvMESA Wm3glWindowPos3fvMESA = 0;
pfn_glWindowPos3iMESA Wm3glWindowPos3iMESA = 0;
pfn_glWindowPos3ivMESA Wm3glWindowPos3ivMESA = 0;
pfn_glWindowPos3sMESA Wm3glWindowPos3sMESA = 0;
pfn_glWindowPos3svMESA Wm3glWindowPos3svMESA = 0;
pfn_glWindowPos4dMESA Wm3glWindowPos4dMESA = 0;
pfn_glWindowPos4dvMESA Wm3glWindowPos4dvMESA = 0;
pfn_glWindowPos4fMESA Wm3glWindowPos4fMESA = 0;
pfn_glWindowPos4fvMESA Wm3glWindowPos4fvMESA = 0;
pfn_glWindowPos4iMESA Wm3glWindowPos4iMESA = 0;
pfn_glWindowPos4ivMESA Wm3glWindowPos4ivMESA = 0;
pfn_glWindowPos4sMESA Wm3glWindowPos4sMESA = 0;
pfn_glWindowPos4svMESA Wm3glWindowPos4svMESA = 0;

static void Init_GL_MESA_window_pos ()
{
    Wm3NumFunctions_GL_MESA_window_pos = 0;

    Wm3glWindowPos2dMESA = (pfn_glWindowPos2dMESA)GetFunctionPointer("glWindowPos2dMESA");
    if ( Wm3glWindowPos2dMESA )
        ++Wm3NumFunctions_GL_MESA_window_pos;

    Wm3glWindowPos2dvMESA = (pfn_glWindowPos2dvMESA)GetFunctionPointer("glWindowPos2dvMESA");
    if ( Wm3glWindowPos2dvMESA )
        ++Wm3NumFunctions_GL_MESA_window_pos;

    Wm3glWindowPos2fMESA = (pfn_glWindowPos2fMESA)GetFunctionPointer("glWindowPos2fMESA");
    if ( Wm3glWindowPos2fMESA )
        ++Wm3NumFunctions_GL_MESA_window_pos;

    Wm3glWindowPos2fvMESA = (pfn_glWindowPos2fvMESA)GetFunctionPointer("glWindowPos2fvMESA");
    if ( Wm3glWindowPos2fvMESA )
        ++Wm3NumFunctions_GL_MESA_window_pos;

    Wm3glWindowPos2iMESA = (pfn_glWindowPos2iMESA)GetFunctionPointer("glWindowPos2iMESA");
    if ( Wm3glWindowPos2iMESA )
        ++Wm3NumFunctions_GL_MESA_window_pos;

    Wm3glWindowPos2ivMESA = (pfn_glWindowPos2ivMESA)GetFunctionPointer("glWindowPos2ivMESA");
    if ( Wm3glWindowPos2ivMESA )
        ++Wm3NumFunctions_GL_MESA_window_pos;

    Wm3glWindowPos2sMESA = (pfn_glWindowPos2sMESA)GetFunctionPointer("glWindowPos2sMESA");
    if ( Wm3glWindowPos2sMESA )
        ++Wm3NumFunctions_GL_MESA_window_pos;

    Wm3glWindowPos2svMESA = (pfn_glWindowPos2svMESA)GetFunctionPointer("glWindowPos2svMESA");
    if ( Wm3glWindowPos2svMESA )
        ++Wm3NumFunctions_GL_MESA_window_pos;

    Wm3glWindowPos3dMESA = (pfn_glWindowPos3dMESA)GetFunctionPointer("glWindowPos3dMESA");
    if ( Wm3glWindowPos3dMESA )
        ++Wm3NumFunctions_GL_MESA_window_pos;

    Wm3glWindowPos3dvMESA = (pfn_glWindowPos3dvMESA)GetFunctionPointer("glWindowPos3dvMESA");
    if ( Wm3glWindowPos3dvMESA )
        ++Wm3NumFunctions_GL_MESA_window_pos;

    Wm3glWindowPos3fMESA = (pfn_glWindowPos3fMESA)GetFunctionPointer("glWindowPos3fMESA");
    if ( Wm3glWindowPos3fMESA )
        ++Wm3NumFunctions_GL_MESA_window_pos;

    Wm3glWindowPos3fvMESA = (pfn_glWindowPos3fvMESA)GetFunctionPointer("glWindowPos3fvMESA");
    if ( Wm3glWindowPos3fvMESA )
        ++Wm3NumFunctions_GL_MESA_window_pos;

    Wm3glWindowPos3iMESA = (pfn_glWindowPos3iMESA)GetFunctionPointer("glWindowPos3iMESA");
    if ( Wm3glWindowPos3iMESA )
        ++Wm3NumFunctions_GL_MESA_window_pos;

    Wm3glWindowPos3ivMESA = (pfn_glWindowPos3ivMESA)GetFunctionPointer("glWindowPos3ivMESA");
    if ( Wm3glWindowPos3ivMESA )
        ++Wm3NumFunctions_GL_MESA_window_pos;

    Wm3glWindowPos3sMESA = (pfn_glWindowPos3sMESA)GetFunctionPointer("glWindowPos3sMESA");
    if ( Wm3glWindowPos3sMESA )
        ++Wm3NumFunctions_GL_MESA_window_pos;

    Wm3glWindowPos3svMESA = (pfn_glWindowPos3svMESA)GetFunctionPointer("glWindowPos3svMESA");
    if ( Wm3glWindowPos3svMESA )
        ++Wm3NumFunctions_GL_MESA_window_pos;

    Wm3glWindowPos4dMESA = (pfn_glWindowPos4dMESA)GetFunctionPointer("glWindowPos4dMESA");
    if ( Wm3glWindowPos4dMESA )
        ++Wm3NumFunctions_GL_MESA_window_pos;

    Wm3glWindowPos4dvMESA = (pfn_glWindowPos4dvMESA)GetFunctionPointer("glWindowPos4dvMESA");
    if ( Wm3glWindowPos4dvMESA )
        ++Wm3NumFunctions_GL_MESA_window_pos;

    Wm3glWindowPos4fMESA = (pfn_glWindowPos4fMESA)GetFunctionPointer("glWindowPos4fMESA");
    if ( Wm3glWindowPos4fMESA )
        ++Wm3NumFunctions_GL_MESA_window_pos;

    Wm3glWindowPos4fvMESA = (pfn_glWindowPos4fvMESA)GetFunctionPointer("glWindowPos4fvMESA");
    if ( Wm3glWindowPos4fvMESA )
        ++Wm3NumFunctions_GL_MESA_window_pos;

    Wm3glWindowPos4iMESA = (pfn_glWindowPos4iMESA)GetFunctionPointer("glWindowPos4iMESA");
    if ( Wm3glWindowPos4iMESA )
        ++Wm3NumFunctions_GL_MESA_window_pos;

    Wm3glWindowPos4ivMESA = (pfn_glWindowPos4ivMESA)GetFunctionPointer("glWindowPos4ivMESA");
    if ( Wm3glWindowPos4ivMESA )
        ++Wm3NumFunctions_GL_MESA_window_pos;

    Wm3glWindowPos4sMESA = (pfn_glWindowPos4sMESA)GetFunctionPointer("glWindowPos4sMESA");
    if ( Wm3glWindowPos4sMESA )
        ++Wm3NumFunctions_GL_MESA_window_pos;

    Wm3glWindowPos4svMESA = (pfn_glWindowPos4svMESA)GetFunctionPointer("glWindowPos4svMESA");
    if ( Wm3glWindowPos4svMESA )
        ++Wm3NumFunctions_GL_MESA_window_pos;

    if ( Wm3NumFunctions_GL_MESA_window_pos == 24 )
        Wm3Exists_GL_MESA_window_pos = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_MESA_window_pos = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_MESA_window_pos ()
{
    Wm3NumFunctions_GL_MESA_window_pos = 0;
    Wm3Exists_GL_MESA_window_pos = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_EXT_texture_compression_s3tc;
int Wm3NumFunctions_GL_EXT_texture_compression_s3tc;
#ifdef WM3_DEFINED_GL_EXT_texture_compression_s3tc
static void Init_GL_EXT_texture_compression_s3tc ()
{
    Wm3NumFunctions_GL_EXT_texture_compression_s3tc = 0;
    Wm3Exists_GL_EXT_texture_compression_s3tc = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_EXT_texture_compression_s3tc ()
{
    Wm3NumFunctions_GL_EXT_texture_compression_s3tc = 0;
    Wm3Exists_GL_EXT_texture_compression_s3tc = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_IBM_cull_vertex;
int Wm3NumFunctions_GL_IBM_cull_vertex;
#ifdef WM3_DEFINED_GL_IBM_cull_vertex
static void Init_GL_IBM_cull_vertex ()
{
    Wm3NumFunctions_GL_IBM_cull_vertex = 0;
    Wm3Exists_GL_IBM_cull_vertex = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_IBM_cull_vertex ()
{
    Wm3NumFunctions_GL_IBM_cull_vertex = 0;
    Wm3Exists_GL_IBM_cull_vertex = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_IBM_multimode_draw_arrays;
int Wm3NumFunctions_GL_IBM_multimode_draw_arrays;
#ifdef WM3_DEFINED_GL_IBM_multimode_draw_arrays
pfn_glMultiModeDrawArraysIBM Wm3glMultiModeDrawArraysIBM = 0;
pfn_glMultiModeDrawElementsIBM Wm3glMultiModeDrawElementsIBM = 0;

static void Init_GL_IBM_multimode_draw_arrays ()
{
    Wm3NumFunctions_GL_IBM_multimode_draw_arrays = 0;

    Wm3glMultiModeDrawArraysIBM = (pfn_glMultiModeDrawArraysIBM)GetFunctionPointer("glMultiModeDrawArraysIBM");
    if ( Wm3glMultiModeDrawArraysIBM )
        ++Wm3NumFunctions_GL_IBM_multimode_draw_arrays;

    Wm3glMultiModeDrawElementsIBM = (pfn_glMultiModeDrawElementsIBM)GetFunctionPointer("glMultiModeDrawElementsIBM");
    if ( Wm3glMultiModeDrawElementsIBM )
        ++Wm3NumFunctions_GL_IBM_multimode_draw_arrays;

    if ( Wm3NumFunctions_GL_IBM_multimode_draw_arrays == 2 )
        Wm3Exists_GL_IBM_multimode_draw_arrays = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_IBM_multimode_draw_arrays = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_IBM_multimode_draw_arrays ()
{
    Wm3NumFunctions_GL_IBM_multimode_draw_arrays = 0;
    Wm3Exists_GL_IBM_multimode_draw_arrays = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_IBM_vertex_array_lists;
int Wm3NumFunctions_GL_IBM_vertex_array_lists;
#ifdef WM3_DEFINED_GL_IBM_vertex_array_lists
pfn_glColorPointerListIBM Wm3glColorPointerListIBM = 0;
pfn_glSecondaryColorPointerListIBM Wm3glSecondaryColorPointerListIBM = 0;
pfn_glEdgeFlagPointerListIBM Wm3glEdgeFlagPointerListIBM = 0;
pfn_glFogCoordPointerListIBM Wm3glFogCoordPointerListIBM = 0;
pfn_glIndexPointerListIBM Wm3glIndexPointerListIBM = 0;
pfn_glNormalPointerListIBM Wm3glNormalPointerListIBM = 0;
pfn_glTexCoordPointerListIBM Wm3glTexCoordPointerListIBM = 0;
pfn_glVertexPointerListIBM Wm3glVertexPointerListIBM = 0;

static void Init_GL_IBM_vertex_array_lists ()
{
    Wm3NumFunctions_GL_IBM_vertex_array_lists = 0;

    Wm3glColorPointerListIBM = (pfn_glColorPointerListIBM)GetFunctionPointer("glColorPointerListIBM");
    if ( Wm3glColorPointerListIBM )
        ++Wm3NumFunctions_GL_IBM_vertex_array_lists;

    Wm3glSecondaryColorPointerListIBM = (pfn_glSecondaryColorPointerListIBM)GetFunctionPointer("glSecondaryColorPointerListIBM");
    if ( Wm3glSecondaryColorPointerListIBM )
        ++Wm3NumFunctions_GL_IBM_vertex_array_lists;

    Wm3glEdgeFlagPointerListIBM = (pfn_glEdgeFlagPointerListIBM)GetFunctionPointer("glEdgeFlagPointerListIBM");
    if ( Wm3glEdgeFlagPointerListIBM )
        ++Wm3NumFunctions_GL_IBM_vertex_array_lists;

    Wm3glFogCoordPointerListIBM = (pfn_glFogCoordPointerListIBM)GetFunctionPointer("glFogCoordPointerListIBM");
    if ( Wm3glFogCoordPointerListIBM )
        ++Wm3NumFunctions_GL_IBM_vertex_array_lists;

    Wm3glIndexPointerListIBM = (pfn_glIndexPointerListIBM)GetFunctionPointer("glIndexPointerListIBM");
    if ( Wm3glIndexPointerListIBM )
        ++Wm3NumFunctions_GL_IBM_vertex_array_lists;

    Wm3glNormalPointerListIBM = (pfn_glNormalPointerListIBM)GetFunctionPointer("glNormalPointerListIBM");
    if ( Wm3glNormalPointerListIBM )
        ++Wm3NumFunctions_GL_IBM_vertex_array_lists;

    Wm3glTexCoordPointerListIBM = (pfn_glTexCoordPointerListIBM)GetFunctionPointer("glTexCoordPointerListIBM");
    if ( Wm3glTexCoordPointerListIBM )
        ++Wm3NumFunctions_GL_IBM_vertex_array_lists;

    Wm3glVertexPointerListIBM = (pfn_glVertexPointerListIBM)GetFunctionPointer("glVertexPointerListIBM");
    if ( Wm3glVertexPointerListIBM )
        ++Wm3NumFunctions_GL_IBM_vertex_array_lists;

    if ( Wm3NumFunctions_GL_IBM_vertex_array_lists == 8 )
        Wm3Exists_GL_IBM_vertex_array_lists = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_IBM_vertex_array_lists = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_IBM_vertex_array_lists ()
{
    Wm3NumFunctions_GL_IBM_vertex_array_lists = 0;
    Wm3Exists_GL_IBM_vertex_array_lists = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_SGIX_subsample;
int Wm3NumFunctions_GL_SGIX_subsample;
#ifdef WM3_DEFINED_GL_SGIX_subsample
static void Init_GL_SGIX_subsample ()
{
    Wm3NumFunctions_GL_SGIX_subsample = 0;
    Wm3Exists_GL_SGIX_subsample = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_SGIX_subsample ()
{
    Wm3NumFunctions_GL_SGIX_subsample = 0;
    Wm3Exists_GL_SGIX_subsample = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_SGIX_ycrcb_subsample;
int Wm3NumFunctions_GL_SGIX_ycrcb_subsample;
#ifdef WM3_DEFINED_GL_SGIX_ycrcb_subsample
static void Init_GL_SGIX_ycrcb_subsample ()
{
    Wm3NumFunctions_GL_SGIX_ycrcb_subsample = 0;
    Wm3Exists_GL_SGIX_ycrcb_subsample = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_SGIX_ycrcb_subsample ()
{
    Wm3NumFunctions_GL_SGIX_ycrcb_subsample = 0;
    Wm3Exists_GL_SGIX_ycrcb_subsample = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_SGIX_ycrcba;
int Wm3NumFunctions_GL_SGIX_ycrcba;
#ifdef WM3_DEFINED_GL_SGIX_ycrcba
static void Init_GL_SGIX_ycrcba ()
{
    Wm3NumFunctions_GL_SGIX_ycrcba = 0;
    Wm3Exists_GL_SGIX_ycrcba = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_SGIX_ycrcba ()
{
    Wm3NumFunctions_GL_SGIX_ycrcba = 0;
    Wm3Exists_GL_SGIX_ycrcba = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_SGIX_depth_pass_instrument;
int Wm3NumFunctions_GL_SGIX_depth_pass_instrument;
#ifdef WM3_DEFINED_GL_SGIX_depth_pass_instrument
static void Init_GL_SGIX_depth_pass_instrument ()
{
    Wm3NumFunctions_GL_SGIX_depth_pass_instrument = 0;
    Wm3Exists_GL_SGIX_depth_pass_instrument = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_SGIX_depth_pass_instrument ()
{
    Wm3NumFunctions_GL_SGIX_depth_pass_instrument = 0;
    Wm3Exists_GL_SGIX_depth_pass_instrument = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_3DFX_texture_compression_FXT1;
int Wm3NumFunctions_GL_3DFX_texture_compression_FXT1;
#ifdef WM3_DEFINED_GL_3DFX_texture_compression_FXT1
static void Init_GL_3DFX_texture_compression_FXT1 ()
{
    Wm3NumFunctions_GL_3DFX_texture_compression_FXT1 = 0;
    Wm3Exists_GL_3DFX_texture_compression_FXT1 = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_3DFX_texture_compression_FXT1 ()
{
    Wm3NumFunctions_GL_3DFX_texture_compression_FXT1 = 0;
    Wm3Exists_GL_3DFX_texture_compression_FXT1 = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_3DFX_multisample;
int Wm3NumFunctions_GL_3DFX_multisample;
#ifdef WM3_DEFINED_GL_3DFX_multisample
static void Init_GL_3DFX_multisample ()
{
    Wm3NumFunctions_GL_3DFX_multisample = 0;
    Wm3Exists_GL_3DFX_multisample = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_3DFX_multisample ()
{
    Wm3NumFunctions_GL_3DFX_multisample = 0;
    Wm3Exists_GL_3DFX_multisample = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_3DFX_tbuffer;
int Wm3NumFunctions_GL_3DFX_tbuffer;
#ifdef WM3_DEFINED_GL_3DFX_tbuffer
pfn_glTbufferMask3DFX Wm3glTbufferMask3DFX = 0;

static void Init_GL_3DFX_tbuffer ()
{
    Wm3NumFunctions_GL_3DFX_tbuffer = 0;

    Wm3glTbufferMask3DFX = (pfn_glTbufferMask3DFX)GetFunctionPointer("glTbufferMask3DFX");
    if ( Wm3glTbufferMask3DFX )
        ++Wm3NumFunctions_GL_3DFX_tbuffer;

    if ( Wm3NumFunctions_GL_3DFX_tbuffer == 1 )
        Wm3Exists_GL_3DFX_tbuffer = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_3DFX_tbuffer = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_3DFX_tbuffer ()
{
    Wm3NumFunctions_GL_3DFX_tbuffer = 0;
    Wm3Exists_GL_3DFX_tbuffer = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_EXT_multisample;
int Wm3NumFunctions_GL_EXT_multisample;
#ifdef WM3_DEFINED_GL_EXT_multisample
pfn_glSampleMaskEXT Wm3glSampleMaskEXT = 0;
pfn_glSamplePatternEXT Wm3glSamplePatternEXT = 0;

static void Init_GL_EXT_multisample ()
{
    Wm3NumFunctions_GL_EXT_multisample = 0;

    Wm3glSampleMaskEXT = (pfn_glSampleMaskEXT)GetFunctionPointer("glSampleMaskEXT");
    if ( Wm3glSampleMaskEXT )
        ++Wm3NumFunctions_GL_EXT_multisample;

    Wm3glSamplePatternEXT = (pfn_glSamplePatternEXT)GetFunctionPointer("glSamplePatternEXT");
    if ( Wm3glSamplePatternEXT )
        ++Wm3NumFunctions_GL_EXT_multisample;

    if ( Wm3NumFunctions_GL_EXT_multisample == 2 )
        Wm3Exists_GL_EXT_multisample = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_EXT_multisample = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_EXT_multisample ()
{
    Wm3NumFunctions_GL_EXT_multisample = 0;
    Wm3Exists_GL_EXT_multisample = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_SGIX_vertex_preclip;
int Wm3NumFunctions_GL_SGIX_vertex_preclip;
#ifdef WM3_DEFINED_GL_SGIX_vertex_preclip
static void Init_GL_SGIX_vertex_preclip ()
{
    Wm3NumFunctions_GL_SGIX_vertex_preclip = 0;
    Wm3Exists_GL_SGIX_vertex_preclip = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_SGIX_vertex_preclip ()
{
    Wm3NumFunctions_GL_SGIX_vertex_preclip = 0;
    Wm3Exists_GL_SGIX_vertex_preclip = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_SGIX_convolution_accuracy;
int Wm3NumFunctions_GL_SGIX_convolution_accuracy;
#ifdef WM3_DEFINED_GL_SGIX_convolution_accuracy
static void Init_GL_SGIX_convolution_accuracy ()
{
    Wm3NumFunctions_GL_SGIX_convolution_accuracy = 0;
    Wm3Exists_GL_SGIX_convolution_accuracy = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_SGIX_convolution_accuracy ()
{
    Wm3NumFunctions_GL_SGIX_convolution_accuracy = 0;
    Wm3Exists_GL_SGIX_convolution_accuracy = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_SGIX_resample;
int Wm3NumFunctions_GL_SGIX_resample;
#ifdef WM3_DEFINED_GL_SGIX_resample
static void Init_GL_SGIX_resample ()
{
    Wm3NumFunctions_GL_SGIX_resample = 0;
    Wm3Exists_GL_SGIX_resample = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_SGIX_resample ()
{
    Wm3NumFunctions_GL_SGIX_resample = 0;
    Wm3Exists_GL_SGIX_resample = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_SGIS_point_line_texgen;
int Wm3NumFunctions_GL_SGIS_point_line_texgen;
#ifdef WM3_DEFINED_GL_SGIS_point_line_texgen
static void Init_GL_SGIS_point_line_texgen ()
{
    Wm3NumFunctions_GL_SGIS_point_line_texgen = 0;
    Wm3Exists_GL_SGIS_point_line_texgen = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_SGIS_point_line_texgen ()
{
    Wm3NumFunctions_GL_SGIS_point_line_texgen = 0;
    Wm3Exists_GL_SGIS_point_line_texgen = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_SGIS_texture_color_mask;
int Wm3NumFunctions_GL_SGIS_texture_color_mask;
#ifdef WM3_DEFINED_GL_SGIS_texture_color_mask
pfn_glTextureColorMaskSGIS Wm3glTextureColorMaskSGIS = 0;

static void Init_GL_SGIS_texture_color_mask ()
{
    Wm3NumFunctions_GL_SGIS_texture_color_mask = 0;

    Wm3glTextureColorMaskSGIS = (pfn_glTextureColorMaskSGIS)GetFunctionPointer("glTextureColorMaskSGIS");
    if ( Wm3glTextureColorMaskSGIS )
        ++Wm3NumFunctions_GL_SGIS_texture_color_mask;

    if ( Wm3NumFunctions_GL_SGIS_texture_color_mask == 1 )
        Wm3Exists_GL_SGIS_texture_color_mask = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_SGIS_texture_color_mask = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_SGIS_texture_color_mask ()
{
    Wm3NumFunctions_GL_SGIS_texture_color_mask = 0;
    Wm3Exists_GL_SGIS_texture_color_mask = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_SGIX_igloo_interface;
int Wm3NumFunctions_GL_SGIX_igloo_interface;
#ifdef WM3_DEFINED_GL_SGIX_igloo_interface
pfn_glIglooInterfaceSGIX Wm3glIglooInterfaceSGIX = 0;

static void Init_GL_SGIX_igloo_interface ()
{
    Wm3NumFunctions_GL_SGIX_igloo_interface = 0;

    Wm3glIglooInterfaceSGIX = (pfn_glIglooInterfaceSGIX)GetFunctionPointer("glIglooInterfaceSGIX");
    if ( Wm3glIglooInterfaceSGIX )
        ++Wm3NumFunctions_GL_SGIX_igloo_interface;

    if ( Wm3NumFunctions_GL_SGIX_igloo_interface == 1 )
        Wm3Exists_GL_SGIX_igloo_interface = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_SGIX_igloo_interface = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_SGIX_igloo_interface ()
{
    Wm3NumFunctions_GL_SGIX_igloo_interface = 0;
    Wm3Exists_GL_SGIX_igloo_interface = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_EXT_texture_env_dot3;
int Wm3NumFunctions_GL_EXT_texture_env_dot3;
#ifdef WM3_DEFINED_GL_EXT_texture_env_dot3
static void Init_GL_EXT_texture_env_dot3 ()
{
    Wm3NumFunctions_GL_EXT_texture_env_dot3 = 0;
    Wm3Exists_GL_EXT_texture_env_dot3 = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_EXT_texture_env_dot3 ()
{
    Wm3NumFunctions_GL_EXT_texture_env_dot3 = 0;
    Wm3Exists_GL_EXT_texture_env_dot3 = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_ATI_texture_mirror_once;
int Wm3NumFunctions_GL_ATI_texture_mirror_once;
#ifdef WM3_DEFINED_GL_ATI_texture_mirror_once
static void Init_GL_ATI_texture_mirror_once ()
{
    Wm3NumFunctions_GL_ATI_texture_mirror_once = 0;
    Wm3Exists_GL_ATI_texture_mirror_once = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_ATI_texture_mirror_once ()
{
    Wm3NumFunctions_GL_ATI_texture_mirror_once = 0;
    Wm3Exists_GL_ATI_texture_mirror_once = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_NV_fence;
int Wm3NumFunctions_GL_NV_fence;
#ifdef WM3_DEFINED_GL_NV_fence
pfn_glDeleteFencesNV Wm3glDeleteFencesNV = 0;
pfn_glGenFencesNV Wm3glGenFencesNV = 0;
pfn_glIsFenceNV Wm3glIsFenceNV = 0;
pfn_glTestFenceNV Wm3glTestFenceNV = 0;
pfn_glGetFenceivNV Wm3glGetFenceivNV = 0;
pfn_glFinishFenceNV Wm3glFinishFenceNV = 0;
pfn_glSetFenceNV Wm3glSetFenceNV = 0;

static void Init_GL_NV_fence ()
{
    Wm3NumFunctions_GL_NV_fence = 0;

    Wm3glDeleteFencesNV = (pfn_glDeleteFencesNV)GetFunctionPointer("glDeleteFencesNV");
    if ( Wm3glDeleteFencesNV )
        ++Wm3NumFunctions_GL_NV_fence;

    Wm3glGenFencesNV = (pfn_glGenFencesNV)GetFunctionPointer("glGenFencesNV");
    if ( Wm3glGenFencesNV )
        ++Wm3NumFunctions_GL_NV_fence;

    Wm3glIsFenceNV = (pfn_glIsFenceNV)GetFunctionPointer("glIsFenceNV");
    if ( Wm3glIsFenceNV )
        ++Wm3NumFunctions_GL_NV_fence;

    Wm3glTestFenceNV = (pfn_glTestFenceNV)GetFunctionPointer("glTestFenceNV");
    if ( Wm3glTestFenceNV )
        ++Wm3NumFunctions_GL_NV_fence;

    Wm3glGetFenceivNV = (pfn_glGetFenceivNV)GetFunctionPointer("glGetFenceivNV");
    if ( Wm3glGetFenceivNV )
        ++Wm3NumFunctions_GL_NV_fence;

    Wm3glFinishFenceNV = (pfn_glFinishFenceNV)GetFunctionPointer("glFinishFenceNV");
    if ( Wm3glFinishFenceNV )
        ++Wm3NumFunctions_GL_NV_fence;

    Wm3glSetFenceNV = (pfn_glSetFenceNV)GetFunctionPointer("glSetFenceNV");
    if ( Wm3glSetFenceNV )
        ++Wm3NumFunctions_GL_NV_fence;

    if ( Wm3NumFunctions_GL_NV_fence == 7 )
        Wm3Exists_GL_NV_fence = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_NV_fence = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_NV_fence ()
{
    Wm3NumFunctions_GL_NV_fence = 0;
    Wm3Exists_GL_NV_fence = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_IBM_texture_mirrored_repeat;
int Wm3NumFunctions_GL_IBM_texture_mirrored_repeat;
#ifdef WM3_DEFINED_GL_IBM_texture_mirrored_repeat
static void Init_GL_IBM_texture_mirrored_repeat ()
{
    Wm3NumFunctions_GL_IBM_texture_mirrored_repeat = 0;
    Wm3Exists_GL_IBM_texture_mirrored_repeat = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_IBM_texture_mirrored_repeat ()
{
    Wm3NumFunctions_GL_IBM_texture_mirrored_repeat = 0;
    Wm3Exists_GL_IBM_texture_mirrored_repeat = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_NV_evaluators;
int Wm3NumFunctions_GL_NV_evaluators;
#ifdef WM3_DEFINED_GL_NV_evaluators
pfn_glMapControlPointsNV Wm3glMapControlPointsNV = 0;
pfn_glMapParameterivNV Wm3glMapParameterivNV = 0;
pfn_glMapParameterfvNV Wm3glMapParameterfvNV = 0;
pfn_glGetMapControlPointsNV Wm3glGetMapControlPointsNV = 0;
pfn_glGetMapParameterivNV Wm3glGetMapParameterivNV = 0;
pfn_glGetMapParameterfvNV Wm3glGetMapParameterfvNV = 0;
pfn_glGetMapAttribParameterivNV Wm3glGetMapAttribParameterivNV = 0;
pfn_glGetMapAttribParameterfvNV Wm3glGetMapAttribParameterfvNV = 0;
pfn_glEvalMapsNV Wm3glEvalMapsNV = 0;

static void Init_GL_NV_evaluators ()
{
    Wm3NumFunctions_GL_NV_evaluators = 0;

    Wm3glMapControlPointsNV = (pfn_glMapControlPointsNV)GetFunctionPointer("glMapControlPointsNV");
    if ( Wm3glMapControlPointsNV )
        ++Wm3NumFunctions_GL_NV_evaluators;

    Wm3glMapParameterivNV = (pfn_glMapParameterivNV)GetFunctionPointer("glMapParameterivNV");
    if ( Wm3glMapParameterivNV )
        ++Wm3NumFunctions_GL_NV_evaluators;

    Wm3glMapParameterfvNV = (pfn_glMapParameterfvNV)GetFunctionPointer("glMapParameterfvNV");
    if ( Wm3glMapParameterfvNV )
        ++Wm3NumFunctions_GL_NV_evaluators;

    Wm3glGetMapControlPointsNV = (pfn_glGetMapControlPointsNV)GetFunctionPointer("glGetMapControlPointsNV");
    if ( Wm3glGetMapControlPointsNV )
        ++Wm3NumFunctions_GL_NV_evaluators;

    Wm3glGetMapParameterivNV = (pfn_glGetMapParameterivNV)GetFunctionPointer("glGetMapParameterivNV");
    if ( Wm3glGetMapParameterivNV )
        ++Wm3NumFunctions_GL_NV_evaluators;

    Wm3glGetMapParameterfvNV = (pfn_glGetMapParameterfvNV)GetFunctionPointer("glGetMapParameterfvNV");
    if ( Wm3glGetMapParameterfvNV )
        ++Wm3NumFunctions_GL_NV_evaluators;

    Wm3glGetMapAttribParameterivNV = (pfn_glGetMapAttribParameterivNV)GetFunctionPointer("glGetMapAttribParameterivNV");
    if ( Wm3glGetMapAttribParameterivNV )
        ++Wm3NumFunctions_GL_NV_evaluators;

    Wm3glGetMapAttribParameterfvNV = (pfn_glGetMapAttribParameterfvNV)GetFunctionPointer("glGetMapAttribParameterfvNV");
    if ( Wm3glGetMapAttribParameterfvNV )
        ++Wm3NumFunctions_GL_NV_evaluators;

    Wm3glEvalMapsNV = (pfn_glEvalMapsNV)GetFunctionPointer("glEvalMapsNV");
    if ( Wm3glEvalMapsNV )
        ++Wm3NumFunctions_GL_NV_evaluators;

    if ( Wm3NumFunctions_GL_NV_evaluators == 9 )
        Wm3Exists_GL_NV_evaluators = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_NV_evaluators = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_NV_evaluators ()
{
    Wm3NumFunctions_GL_NV_evaluators = 0;
    Wm3Exists_GL_NV_evaluators = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_NV_packed_depth_stencil;
int Wm3NumFunctions_GL_NV_packed_depth_stencil;
#ifdef WM3_DEFINED_GL_NV_packed_depth_stencil
static void Init_GL_NV_packed_depth_stencil ()
{
    Wm3NumFunctions_GL_NV_packed_depth_stencil = 0;
    Wm3Exists_GL_NV_packed_depth_stencil = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_NV_packed_depth_stencil ()
{
    Wm3NumFunctions_GL_NV_packed_depth_stencil = 0;
    Wm3Exists_GL_NV_packed_depth_stencil = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_NV_register_combiners2;
int Wm3NumFunctions_GL_NV_register_combiners2;
#ifdef WM3_DEFINED_GL_NV_register_combiners2
pfn_glCombinerStageParameterfvNV Wm3glCombinerStageParameterfvNV = 0;
pfn_glGetCombinerStageParameterfvNV Wm3glGetCombinerStageParameterfvNV = 0;

static void Init_GL_NV_register_combiners2 ()
{
    Wm3NumFunctions_GL_NV_register_combiners2 = 0;

    Wm3glCombinerStageParameterfvNV = (pfn_glCombinerStageParameterfvNV)GetFunctionPointer("glCombinerStageParameterfvNV");
    if ( Wm3glCombinerStageParameterfvNV )
        ++Wm3NumFunctions_GL_NV_register_combiners2;

    Wm3glGetCombinerStageParameterfvNV = (pfn_glGetCombinerStageParameterfvNV)GetFunctionPointer("glGetCombinerStageParameterfvNV");
    if ( Wm3glGetCombinerStageParameterfvNV )
        ++Wm3NumFunctions_GL_NV_register_combiners2;

    if ( Wm3NumFunctions_GL_NV_register_combiners2 == 2 )
        Wm3Exists_GL_NV_register_combiners2 = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_NV_register_combiners2 = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_NV_register_combiners2 ()
{
    Wm3NumFunctions_GL_NV_register_combiners2 = 0;
    Wm3Exists_GL_NV_register_combiners2 = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_NV_texture_compression_vtc;
int Wm3NumFunctions_GL_NV_texture_compression_vtc;
#ifdef WM3_DEFINED_GL_NV_texture_compression_vtc
static void Init_GL_NV_texture_compression_vtc ()
{
    Wm3NumFunctions_GL_NV_texture_compression_vtc = 0;
    Wm3Exists_GL_NV_texture_compression_vtc = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_NV_texture_compression_vtc ()
{
    Wm3NumFunctions_GL_NV_texture_compression_vtc = 0;
    Wm3Exists_GL_NV_texture_compression_vtc = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_NV_texture_rectangle;
int Wm3NumFunctions_GL_NV_texture_rectangle;
#ifdef WM3_DEFINED_GL_NV_texture_rectangle
static void Init_GL_NV_texture_rectangle ()
{
    Wm3NumFunctions_GL_NV_texture_rectangle = 0;
    Wm3Exists_GL_NV_texture_rectangle = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_NV_texture_rectangle ()
{
    Wm3NumFunctions_GL_NV_texture_rectangle = 0;
    Wm3Exists_GL_NV_texture_rectangle = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_NV_texture_shader;
int Wm3NumFunctions_GL_NV_texture_shader;
#ifdef WM3_DEFINED_GL_NV_texture_shader
static void Init_GL_NV_texture_shader ()
{
    Wm3NumFunctions_GL_NV_texture_shader = 0;
    Wm3Exists_GL_NV_texture_shader = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_NV_texture_shader ()
{
    Wm3NumFunctions_GL_NV_texture_shader = 0;
    Wm3Exists_GL_NV_texture_shader = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_NV_texture_shader2;
int Wm3NumFunctions_GL_NV_texture_shader2;
#ifdef WM3_DEFINED_GL_NV_texture_shader2
static void Init_GL_NV_texture_shader2 ()
{
    Wm3NumFunctions_GL_NV_texture_shader2 = 0;
    Wm3Exists_GL_NV_texture_shader2 = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_NV_texture_shader2 ()
{
    Wm3NumFunctions_GL_NV_texture_shader2 = 0;
    Wm3Exists_GL_NV_texture_shader2 = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_NV_vertex_array_range2;
int Wm3NumFunctions_GL_NV_vertex_array_range2;
#ifdef WM3_DEFINED_GL_NV_vertex_array_range2
static void Init_GL_NV_vertex_array_range2 ()
{
    Wm3NumFunctions_GL_NV_vertex_array_range2 = 0;
    Wm3Exists_GL_NV_vertex_array_range2 = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_NV_vertex_array_range2 ()
{
    Wm3NumFunctions_GL_NV_vertex_array_range2 = 0;
    Wm3Exists_GL_NV_vertex_array_range2 = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_NV_vertex_program;
int Wm3NumFunctions_GL_NV_vertex_program;
#ifdef WM3_DEFINED_GL_NV_vertex_program
pfn_glAreProgramsResidentNV Wm3glAreProgramsResidentNV = 0;
pfn_glBindProgramNV Wm3glBindProgramNV = 0;
pfn_glDeleteProgramsNV Wm3glDeleteProgramsNV = 0;
pfn_glExecuteProgramNV Wm3glExecuteProgramNV = 0;
pfn_glGenProgramsNV Wm3glGenProgramsNV = 0;
pfn_glGetProgramParameterdvNV Wm3glGetProgramParameterdvNV = 0;
pfn_glGetProgramParameterfvNV Wm3glGetProgramParameterfvNV = 0;
pfn_glGetProgramivNV Wm3glGetProgramivNV = 0;
pfn_glGetProgramStringNV Wm3glGetProgramStringNV = 0;
pfn_glGetTrackMatrixivNV Wm3glGetTrackMatrixivNV = 0;
pfn_glGetVertexAttribdvNV Wm3glGetVertexAttribdvNV = 0;
pfn_glGetVertexAttribfvNV Wm3glGetVertexAttribfvNV = 0;
pfn_glGetVertexAttribivNV Wm3glGetVertexAttribivNV = 0;
pfn_glGetVertexAttribPointervNV Wm3glGetVertexAttribPointervNV = 0;
pfn_glIsProgramNV Wm3glIsProgramNV = 0;
pfn_glLoadProgramNV Wm3glLoadProgramNV = 0;
pfn_glProgramParameter4dNV Wm3glProgramParameter4dNV = 0;
pfn_glProgramParameter4dvNV Wm3glProgramParameter4dvNV = 0;
pfn_glProgramParameter4fNV Wm3glProgramParameter4fNV = 0;
pfn_glProgramParameter4fvNV Wm3glProgramParameter4fvNV = 0;
pfn_glProgramParameters4dvNV Wm3glProgramParameters4dvNV = 0;
pfn_glProgramParameters4fvNV Wm3glProgramParameters4fvNV = 0;
pfn_glRequestResidentProgramsNV Wm3glRequestResidentProgramsNV = 0;
pfn_glTrackMatrixNV Wm3glTrackMatrixNV = 0;
pfn_glVertexAttribPointerNV Wm3glVertexAttribPointerNV = 0;
pfn_glVertexAttrib1dNV Wm3glVertexAttrib1dNV = 0;
pfn_glVertexAttrib1dvNV Wm3glVertexAttrib1dvNV = 0;
pfn_glVertexAttrib1fNV Wm3glVertexAttrib1fNV = 0;
pfn_glVertexAttrib1fvNV Wm3glVertexAttrib1fvNV = 0;
pfn_glVertexAttrib1sNV Wm3glVertexAttrib1sNV = 0;
pfn_glVertexAttrib1svNV Wm3glVertexAttrib1svNV = 0;
pfn_glVertexAttrib2dNV Wm3glVertexAttrib2dNV = 0;
pfn_glVertexAttrib2dvNV Wm3glVertexAttrib2dvNV = 0;
pfn_glVertexAttrib2fNV Wm3glVertexAttrib2fNV = 0;
pfn_glVertexAttrib2fvNV Wm3glVertexAttrib2fvNV = 0;
pfn_glVertexAttrib2sNV Wm3glVertexAttrib2sNV = 0;
pfn_glVertexAttrib2svNV Wm3glVertexAttrib2svNV = 0;
pfn_glVertexAttrib3dNV Wm3glVertexAttrib3dNV = 0;
pfn_glVertexAttrib3dvNV Wm3glVertexAttrib3dvNV = 0;
pfn_glVertexAttrib3fNV Wm3glVertexAttrib3fNV = 0;
pfn_glVertexAttrib3fvNV Wm3glVertexAttrib3fvNV = 0;
pfn_glVertexAttrib3sNV Wm3glVertexAttrib3sNV = 0;
pfn_glVertexAttrib3svNV Wm3glVertexAttrib3svNV = 0;
pfn_glVertexAttrib4dNV Wm3glVertexAttrib4dNV = 0;
pfn_glVertexAttrib4dvNV Wm3glVertexAttrib4dvNV = 0;
pfn_glVertexAttrib4fNV Wm3glVertexAttrib4fNV = 0;
pfn_glVertexAttrib4fvNV Wm3glVertexAttrib4fvNV = 0;
pfn_glVertexAttrib4sNV Wm3glVertexAttrib4sNV = 0;
pfn_glVertexAttrib4svNV Wm3glVertexAttrib4svNV = 0;
pfn_glVertexAttrib4ubNV Wm3glVertexAttrib4ubNV = 0;
pfn_glVertexAttrib4ubvNV Wm3glVertexAttrib4ubvNV = 0;
pfn_glVertexAttribs1dvNV Wm3glVertexAttribs1dvNV = 0;
pfn_glVertexAttribs1fvNV Wm3glVertexAttribs1fvNV = 0;
pfn_glVertexAttribs1svNV Wm3glVertexAttribs1svNV = 0;
pfn_glVertexAttribs2dvNV Wm3glVertexAttribs2dvNV = 0;
pfn_glVertexAttribs2fvNV Wm3glVertexAttribs2fvNV = 0;
pfn_glVertexAttribs2svNV Wm3glVertexAttribs2svNV = 0;
pfn_glVertexAttribs3dvNV Wm3glVertexAttribs3dvNV = 0;
pfn_glVertexAttribs3fvNV Wm3glVertexAttribs3fvNV = 0;
pfn_glVertexAttribs3svNV Wm3glVertexAttribs3svNV = 0;
pfn_glVertexAttribs4dvNV Wm3glVertexAttribs4dvNV = 0;
pfn_glVertexAttribs4fvNV Wm3glVertexAttribs4fvNV = 0;
pfn_glVertexAttribs4svNV Wm3glVertexAttribs4svNV = 0;
pfn_glVertexAttribs4ubvNV Wm3glVertexAttribs4ubvNV = 0;

static void Init_GL_NV_vertex_program ()
{
    Wm3NumFunctions_GL_NV_vertex_program = 0;

    Wm3glAreProgramsResidentNV = (pfn_glAreProgramsResidentNV)GetFunctionPointer("glAreProgramsResidentNV");
    if ( Wm3glAreProgramsResidentNV )
        ++Wm3NumFunctions_GL_NV_vertex_program;

    Wm3glBindProgramNV = (pfn_glBindProgramNV)GetFunctionPointer("glBindProgramNV");
    if ( Wm3glBindProgramNV )
        ++Wm3NumFunctions_GL_NV_vertex_program;

    Wm3glDeleteProgramsNV = (pfn_glDeleteProgramsNV)GetFunctionPointer("glDeleteProgramsNV");
    if ( Wm3glDeleteProgramsNV )
        ++Wm3NumFunctions_GL_NV_vertex_program;

    Wm3glExecuteProgramNV = (pfn_glExecuteProgramNV)GetFunctionPointer("glExecuteProgramNV");
    if ( Wm3glExecuteProgramNV )
        ++Wm3NumFunctions_GL_NV_vertex_program;

    Wm3glGenProgramsNV = (pfn_glGenProgramsNV)GetFunctionPointer("glGenProgramsNV");
    if ( Wm3glGenProgramsNV )
        ++Wm3NumFunctions_GL_NV_vertex_program;

    Wm3glGetProgramParameterdvNV = (pfn_glGetProgramParameterdvNV)GetFunctionPointer("glGetProgramParameterdvNV");
    if ( Wm3glGetProgramParameterdvNV )
        ++Wm3NumFunctions_GL_NV_vertex_program;

    Wm3glGetProgramParameterfvNV = (pfn_glGetProgramParameterfvNV)GetFunctionPointer("glGetProgramParameterfvNV");
    if ( Wm3glGetProgramParameterfvNV )
        ++Wm3NumFunctions_GL_NV_vertex_program;

    Wm3glGetProgramivNV = (pfn_glGetProgramivNV)GetFunctionPointer("glGetProgramivNV");
    if ( Wm3glGetProgramivNV )
        ++Wm3NumFunctions_GL_NV_vertex_program;

    Wm3glGetProgramStringNV = (pfn_glGetProgramStringNV)GetFunctionPointer("glGetProgramStringNV");
    if ( Wm3glGetProgramStringNV )
        ++Wm3NumFunctions_GL_NV_vertex_program;

    Wm3glGetTrackMatrixivNV = (pfn_glGetTrackMatrixivNV)GetFunctionPointer("glGetTrackMatrixivNV");
    if ( Wm3glGetTrackMatrixivNV )
        ++Wm3NumFunctions_GL_NV_vertex_program;

    Wm3glGetVertexAttribdvNV = (pfn_glGetVertexAttribdvNV)GetFunctionPointer("glGetVertexAttribdvNV");
    if ( Wm3glGetVertexAttribdvNV )
        ++Wm3NumFunctions_GL_NV_vertex_program;

    Wm3glGetVertexAttribfvNV = (pfn_glGetVertexAttribfvNV)GetFunctionPointer("glGetVertexAttribfvNV");
    if ( Wm3glGetVertexAttribfvNV )
        ++Wm3NumFunctions_GL_NV_vertex_program;

    Wm3glGetVertexAttribivNV = (pfn_glGetVertexAttribivNV)GetFunctionPointer("glGetVertexAttribivNV");
    if ( Wm3glGetVertexAttribivNV )
        ++Wm3NumFunctions_GL_NV_vertex_program;

    Wm3glGetVertexAttribPointervNV = (pfn_glGetVertexAttribPointervNV)GetFunctionPointer("glGetVertexAttribPointervNV");
    if ( Wm3glGetVertexAttribPointervNV )
        ++Wm3NumFunctions_GL_NV_vertex_program;

    Wm3glIsProgramNV = (pfn_glIsProgramNV)GetFunctionPointer("glIsProgramNV");
    if ( Wm3glIsProgramNV )
        ++Wm3NumFunctions_GL_NV_vertex_program;

    Wm3glLoadProgramNV = (pfn_glLoadProgramNV)GetFunctionPointer("glLoadProgramNV");
    if ( Wm3glLoadProgramNV )
        ++Wm3NumFunctions_GL_NV_vertex_program;

    Wm3glProgramParameter4dNV = (pfn_glProgramParameter4dNV)GetFunctionPointer("glProgramParameter4dNV");
    if ( Wm3glProgramParameter4dNV )
        ++Wm3NumFunctions_GL_NV_vertex_program;

    Wm3glProgramParameter4dvNV = (pfn_glProgramParameter4dvNV)GetFunctionPointer("glProgramParameter4dvNV");
    if ( Wm3glProgramParameter4dvNV )
        ++Wm3NumFunctions_GL_NV_vertex_program;

    Wm3glProgramParameter4fNV = (pfn_glProgramParameter4fNV)GetFunctionPointer("glProgramParameter4fNV");
    if ( Wm3glProgramParameter4fNV )
        ++Wm3NumFunctions_GL_NV_vertex_program;

    Wm3glProgramParameter4fvNV = (pfn_glProgramParameter4fvNV)GetFunctionPointer("glProgramParameter4fvNV");
    if ( Wm3glProgramParameter4fvNV )
        ++Wm3NumFunctions_GL_NV_vertex_program;

    Wm3glProgramParameters4dvNV = (pfn_glProgramParameters4dvNV)GetFunctionPointer("glProgramParameters4dvNV");
    if ( Wm3glProgramParameters4dvNV )
        ++Wm3NumFunctions_GL_NV_vertex_program;

    Wm3glProgramParameters4fvNV = (pfn_glProgramParameters4fvNV)GetFunctionPointer("glProgramParameters4fvNV");
    if ( Wm3glProgramParameters4fvNV )
        ++Wm3NumFunctions_GL_NV_vertex_program;

    Wm3glRequestResidentProgramsNV = (pfn_glRequestResidentProgramsNV)GetFunctionPointer("glRequestResidentProgramsNV");
    if ( Wm3glRequestResidentProgramsNV )
        ++Wm3NumFunctions_GL_NV_vertex_program;

    Wm3glTrackMatrixNV = (pfn_glTrackMatrixNV)GetFunctionPointer("glTrackMatrixNV");
    if ( Wm3glTrackMatrixNV )
        ++Wm3NumFunctions_GL_NV_vertex_program;

    Wm3glVertexAttribPointerNV = (pfn_glVertexAttribPointerNV)GetFunctionPointer("glVertexAttribPointerNV");
    if ( Wm3glVertexAttribPointerNV )
        ++Wm3NumFunctions_GL_NV_vertex_program;

    Wm3glVertexAttrib1dNV = (pfn_glVertexAttrib1dNV)GetFunctionPointer("glVertexAttrib1dNV");
    if ( Wm3glVertexAttrib1dNV )
        ++Wm3NumFunctions_GL_NV_vertex_program;

    Wm3glVertexAttrib1dvNV = (pfn_glVertexAttrib1dvNV)GetFunctionPointer("glVertexAttrib1dvNV");
    if ( Wm3glVertexAttrib1dvNV )
        ++Wm3NumFunctions_GL_NV_vertex_program;

    Wm3glVertexAttrib1fNV = (pfn_glVertexAttrib1fNV)GetFunctionPointer("glVertexAttrib1fNV");
    if ( Wm3glVertexAttrib1fNV )
        ++Wm3NumFunctions_GL_NV_vertex_program;

    Wm3glVertexAttrib1fvNV = (pfn_glVertexAttrib1fvNV)GetFunctionPointer("glVertexAttrib1fvNV");
    if ( Wm3glVertexAttrib1fvNV )
        ++Wm3NumFunctions_GL_NV_vertex_program;

    Wm3glVertexAttrib1sNV = (pfn_glVertexAttrib1sNV)GetFunctionPointer("glVertexAttrib1sNV");
    if ( Wm3glVertexAttrib1sNV )
        ++Wm3NumFunctions_GL_NV_vertex_program;

    Wm3glVertexAttrib1svNV = (pfn_glVertexAttrib1svNV)GetFunctionPointer("glVertexAttrib1svNV");
    if ( Wm3glVertexAttrib1svNV )
        ++Wm3NumFunctions_GL_NV_vertex_program;

    Wm3glVertexAttrib2dNV = (pfn_glVertexAttrib2dNV)GetFunctionPointer("glVertexAttrib2dNV");
    if ( Wm3glVertexAttrib2dNV )
        ++Wm3NumFunctions_GL_NV_vertex_program;

    Wm3glVertexAttrib2dvNV = (pfn_glVertexAttrib2dvNV)GetFunctionPointer("glVertexAttrib2dvNV");
    if ( Wm3glVertexAttrib2dvNV )
        ++Wm3NumFunctions_GL_NV_vertex_program;

    Wm3glVertexAttrib2fNV = (pfn_glVertexAttrib2fNV)GetFunctionPointer("glVertexAttrib2fNV");
    if ( Wm3glVertexAttrib2fNV )
        ++Wm3NumFunctions_GL_NV_vertex_program;

    Wm3glVertexAttrib2fvNV = (pfn_glVertexAttrib2fvNV)GetFunctionPointer("glVertexAttrib2fvNV");
    if ( Wm3glVertexAttrib2fvNV )
        ++Wm3NumFunctions_GL_NV_vertex_program;

    Wm3glVertexAttrib2sNV = (pfn_glVertexAttrib2sNV)GetFunctionPointer("glVertexAttrib2sNV");
    if ( Wm3glVertexAttrib2sNV )
        ++Wm3NumFunctions_GL_NV_vertex_program;

    Wm3glVertexAttrib2svNV = (pfn_glVertexAttrib2svNV)GetFunctionPointer("glVertexAttrib2svNV");
    if ( Wm3glVertexAttrib2svNV )
        ++Wm3NumFunctions_GL_NV_vertex_program;

    Wm3glVertexAttrib3dNV = (pfn_glVertexAttrib3dNV)GetFunctionPointer("glVertexAttrib3dNV");
    if ( Wm3glVertexAttrib3dNV )
        ++Wm3NumFunctions_GL_NV_vertex_program;

    Wm3glVertexAttrib3dvNV = (pfn_glVertexAttrib3dvNV)GetFunctionPointer("glVertexAttrib3dvNV");
    if ( Wm3glVertexAttrib3dvNV )
        ++Wm3NumFunctions_GL_NV_vertex_program;

    Wm3glVertexAttrib3fNV = (pfn_glVertexAttrib3fNV)GetFunctionPointer("glVertexAttrib3fNV");
    if ( Wm3glVertexAttrib3fNV )
        ++Wm3NumFunctions_GL_NV_vertex_program;

    Wm3glVertexAttrib3fvNV = (pfn_glVertexAttrib3fvNV)GetFunctionPointer("glVertexAttrib3fvNV");
    if ( Wm3glVertexAttrib3fvNV )
        ++Wm3NumFunctions_GL_NV_vertex_program;

    Wm3glVertexAttrib3sNV = (pfn_glVertexAttrib3sNV)GetFunctionPointer("glVertexAttrib3sNV");
    if ( Wm3glVertexAttrib3sNV )
        ++Wm3NumFunctions_GL_NV_vertex_program;

    Wm3glVertexAttrib3svNV = (pfn_glVertexAttrib3svNV)GetFunctionPointer("glVertexAttrib3svNV");
    if ( Wm3glVertexAttrib3svNV )
        ++Wm3NumFunctions_GL_NV_vertex_program;

    Wm3glVertexAttrib4dNV = (pfn_glVertexAttrib4dNV)GetFunctionPointer("glVertexAttrib4dNV");
    if ( Wm3glVertexAttrib4dNV )
        ++Wm3NumFunctions_GL_NV_vertex_program;

    Wm3glVertexAttrib4dvNV = (pfn_glVertexAttrib4dvNV)GetFunctionPointer("glVertexAttrib4dvNV");
    if ( Wm3glVertexAttrib4dvNV )
        ++Wm3NumFunctions_GL_NV_vertex_program;

    Wm3glVertexAttrib4fNV = (pfn_glVertexAttrib4fNV)GetFunctionPointer("glVertexAttrib4fNV");
    if ( Wm3glVertexAttrib4fNV )
        ++Wm3NumFunctions_GL_NV_vertex_program;

    Wm3glVertexAttrib4fvNV = (pfn_glVertexAttrib4fvNV)GetFunctionPointer("glVertexAttrib4fvNV");
    if ( Wm3glVertexAttrib4fvNV )
        ++Wm3NumFunctions_GL_NV_vertex_program;

    Wm3glVertexAttrib4sNV = (pfn_glVertexAttrib4sNV)GetFunctionPointer("glVertexAttrib4sNV");
    if ( Wm3glVertexAttrib4sNV )
        ++Wm3NumFunctions_GL_NV_vertex_program;

    Wm3glVertexAttrib4svNV = (pfn_glVertexAttrib4svNV)GetFunctionPointer("glVertexAttrib4svNV");
    if ( Wm3glVertexAttrib4svNV )
        ++Wm3NumFunctions_GL_NV_vertex_program;

    Wm3glVertexAttrib4ubNV = (pfn_glVertexAttrib4ubNV)GetFunctionPointer("glVertexAttrib4ubNV");
    if ( Wm3glVertexAttrib4ubNV )
        ++Wm3NumFunctions_GL_NV_vertex_program;

    Wm3glVertexAttrib4ubvNV = (pfn_glVertexAttrib4ubvNV)GetFunctionPointer("glVertexAttrib4ubvNV");
    if ( Wm3glVertexAttrib4ubvNV )
        ++Wm3NumFunctions_GL_NV_vertex_program;

    Wm3glVertexAttribs1dvNV = (pfn_glVertexAttribs1dvNV)GetFunctionPointer("glVertexAttribs1dvNV");
    if ( Wm3glVertexAttribs1dvNV )
        ++Wm3NumFunctions_GL_NV_vertex_program;

    Wm3glVertexAttribs1fvNV = (pfn_glVertexAttribs1fvNV)GetFunctionPointer("glVertexAttribs1fvNV");
    if ( Wm3glVertexAttribs1fvNV )
        ++Wm3NumFunctions_GL_NV_vertex_program;

    Wm3glVertexAttribs1svNV = (pfn_glVertexAttribs1svNV)GetFunctionPointer("glVertexAttribs1svNV");
    if ( Wm3glVertexAttribs1svNV )
        ++Wm3NumFunctions_GL_NV_vertex_program;

    Wm3glVertexAttribs2dvNV = (pfn_glVertexAttribs2dvNV)GetFunctionPointer("glVertexAttribs2dvNV");
    if ( Wm3glVertexAttribs2dvNV )
        ++Wm3NumFunctions_GL_NV_vertex_program;

    Wm3glVertexAttribs2fvNV = (pfn_glVertexAttribs2fvNV)GetFunctionPointer("glVertexAttribs2fvNV");
    if ( Wm3glVertexAttribs2fvNV )
        ++Wm3NumFunctions_GL_NV_vertex_program;

    Wm3glVertexAttribs2svNV = (pfn_glVertexAttribs2svNV)GetFunctionPointer("glVertexAttribs2svNV");
    if ( Wm3glVertexAttribs2svNV )
        ++Wm3NumFunctions_GL_NV_vertex_program;

    Wm3glVertexAttribs3dvNV = (pfn_glVertexAttribs3dvNV)GetFunctionPointer("glVertexAttribs3dvNV");
    if ( Wm3glVertexAttribs3dvNV )
        ++Wm3NumFunctions_GL_NV_vertex_program;

    Wm3glVertexAttribs3fvNV = (pfn_glVertexAttribs3fvNV)GetFunctionPointer("glVertexAttribs3fvNV");
    if ( Wm3glVertexAttribs3fvNV )
        ++Wm3NumFunctions_GL_NV_vertex_program;

    Wm3glVertexAttribs3svNV = (pfn_glVertexAttribs3svNV)GetFunctionPointer("glVertexAttribs3svNV");
    if ( Wm3glVertexAttribs3svNV )
        ++Wm3NumFunctions_GL_NV_vertex_program;

    Wm3glVertexAttribs4dvNV = (pfn_glVertexAttribs4dvNV)GetFunctionPointer("glVertexAttribs4dvNV");
    if ( Wm3glVertexAttribs4dvNV )
        ++Wm3NumFunctions_GL_NV_vertex_program;

    Wm3glVertexAttribs4fvNV = (pfn_glVertexAttribs4fvNV)GetFunctionPointer("glVertexAttribs4fvNV");
    if ( Wm3glVertexAttribs4fvNV )
        ++Wm3NumFunctions_GL_NV_vertex_program;

    Wm3glVertexAttribs4svNV = (pfn_glVertexAttribs4svNV)GetFunctionPointer("glVertexAttribs4svNV");
    if ( Wm3glVertexAttribs4svNV )
        ++Wm3NumFunctions_GL_NV_vertex_program;

    Wm3glVertexAttribs4ubvNV = (pfn_glVertexAttribs4ubvNV)GetFunctionPointer("glVertexAttribs4ubvNV");
    if ( Wm3glVertexAttribs4ubvNV )
        ++Wm3NumFunctions_GL_NV_vertex_program;

    if ( Wm3NumFunctions_GL_NV_vertex_program == 64 )
        Wm3Exists_GL_NV_vertex_program = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_NV_vertex_program = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_NV_vertex_program ()
{
    Wm3NumFunctions_GL_NV_vertex_program = 0;
    Wm3Exists_GL_NV_vertex_program = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_SGIX_texture_coordinate_clamp;
int Wm3NumFunctions_GL_SGIX_texture_coordinate_clamp;
#ifdef WM3_DEFINED_GL_SGIX_texture_coordinate_clamp
static void Init_GL_SGIX_texture_coordinate_clamp ()
{
    Wm3NumFunctions_GL_SGIX_texture_coordinate_clamp = 0;
    Wm3Exists_GL_SGIX_texture_coordinate_clamp = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_SGIX_texture_coordinate_clamp ()
{
    Wm3NumFunctions_GL_SGIX_texture_coordinate_clamp = 0;
    Wm3Exists_GL_SGIX_texture_coordinate_clamp = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_SGIX_scalebias_hint;
int Wm3NumFunctions_GL_SGIX_scalebias_hint;
#ifdef WM3_DEFINED_GL_SGIX_scalebias_hint
static void Init_GL_SGIX_scalebias_hint ()
{
    Wm3NumFunctions_GL_SGIX_scalebias_hint = 0;
    Wm3Exists_GL_SGIX_scalebias_hint = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_SGIX_scalebias_hint ()
{
    Wm3NumFunctions_GL_SGIX_scalebias_hint = 0;
    Wm3Exists_GL_SGIX_scalebias_hint = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_OML_interlace;
int Wm3NumFunctions_GL_OML_interlace;
#ifdef WM3_DEFINED_GL_OML_interlace
static void Init_GL_OML_interlace ()
{
    Wm3NumFunctions_GL_OML_interlace = 0;
    Wm3Exists_GL_OML_interlace = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_OML_interlace ()
{
    Wm3NumFunctions_GL_OML_interlace = 0;
    Wm3Exists_GL_OML_interlace = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_OML_subsample;
int Wm3NumFunctions_GL_OML_subsample;
#ifdef WM3_DEFINED_GL_OML_subsample
static void Init_GL_OML_subsample ()
{
    Wm3NumFunctions_GL_OML_subsample = 0;
    Wm3Exists_GL_OML_subsample = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_OML_subsample ()
{
    Wm3NumFunctions_GL_OML_subsample = 0;
    Wm3Exists_GL_OML_subsample = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_OML_resample;
int Wm3NumFunctions_GL_OML_resample;
#ifdef WM3_DEFINED_GL_OML_resample
static void Init_GL_OML_resample ()
{
    Wm3NumFunctions_GL_OML_resample = 0;
    Wm3Exists_GL_OML_resample = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_OML_resample ()
{
    Wm3NumFunctions_GL_OML_resample = 0;
    Wm3Exists_GL_OML_resample = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_NV_copy_depth_to_color;
int Wm3NumFunctions_GL_NV_copy_depth_to_color;
#ifdef WM3_DEFINED_GL_NV_copy_depth_to_color
static void Init_GL_NV_copy_depth_to_color ()
{
    Wm3NumFunctions_GL_NV_copy_depth_to_color = 0;
    Wm3Exists_GL_NV_copy_depth_to_color = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_NV_copy_depth_to_color ()
{
    Wm3NumFunctions_GL_NV_copy_depth_to_color = 0;
    Wm3Exists_GL_NV_copy_depth_to_color = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_ATI_envmap_bumpmap;
int Wm3NumFunctions_GL_ATI_envmap_bumpmap;
#ifdef WM3_DEFINED_GL_ATI_envmap_bumpmap
pfn_glTexBumpParameterivATI Wm3glTexBumpParameterivATI = 0;
pfn_glTexBumpParameterfvATI Wm3glTexBumpParameterfvATI = 0;
pfn_glGetTexBumpParameterivATI Wm3glGetTexBumpParameterivATI = 0;
pfn_glGetTexBumpParameterfvATI Wm3glGetTexBumpParameterfvATI = 0;

static void Init_GL_ATI_envmap_bumpmap ()
{
    Wm3NumFunctions_GL_ATI_envmap_bumpmap = 0;

    Wm3glTexBumpParameterivATI = (pfn_glTexBumpParameterivATI)GetFunctionPointer("glTexBumpParameterivATI");
    if ( Wm3glTexBumpParameterivATI )
        ++Wm3NumFunctions_GL_ATI_envmap_bumpmap;

    Wm3glTexBumpParameterfvATI = (pfn_glTexBumpParameterfvATI)GetFunctionPointer("glTexBumpParameterfvATI");
    if ( Wm3glTexBumpParameterfvATI )
        ++Wm3NumFunctions_GL_ATI_envmap_bumpmap;

    Wm3glGetTexBumpParameterivATI = (pfn_glGetTexBumpParameterivATI)GetFunctionPointer("glGetTexBumpParameterivATI");
    if ( Wm3glGetTexBumpParameterivATI )
        ++Wm3NumFunctions_GL_ATI_envmap_bumpmap;

    Wm3glGetTexBumpParameterfvATI = (pfn_glGetTexBumpParameterfvATI)GetFunctionPointer("glGetTexBumpParameterfvATI");
    if ( Wm3glGetTexBumpParameterfvATI )
        ++Wm3NumFunctions_GL_ATI_envmap_bumpmap;

    if ( Wm3NumFunctions_GL_ATI_envmap_bumpmap == 4 )
        Wm3Exists_GL_ATI_envmap_bumpmap = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_ATI_envmap_bumpmap = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_ATI_envmap_bumpmap ()
{
    Wm3NumFunctions_GL_ATI_envmap_bumpmap = 0;
    Wm3Exists_GL_ATI_envmap_bumpmap = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_ATI_fragment_shader;
int Wm3NumFunctions_GL_ATI_fragment_shader;
#ifdef WM3_DEFINED_GL_ATI_fragment_shader
pfn_glGenFragmentShadersATI Wm3glGenFragmentShadersATI = 0;
pfn_glBindFragmentShaderATI Wm3glBindFragmentShaderATI = 0;
pfn_glDeleteFragmentShaderATI Wm3glDeleteFragmentShaderATI = 0;
pfn_glBeginFragmentShaderATI Wm3glBeginFragmentShaderATI = 0;
pfn_glEndFragmentShaderATI Wm3glEndFragmentShaderATI = 0;
pfn_glPassTexCoordATI Wm3glPassTexCoordATI = 0;
pfn_glSampleMapATI Wm3glSampleMapATI = 0;
pfn_glColorFragmentOp1ATI Wm3glColorFragmentOp1ATI = 0;
pfn_glColorFragmentOp2ATI Wm3glColorFragmentOp2ATI = 0;
pfn_glColorFragmentOp3ATI Wm3glColorFragmentOp3ATI = 0;
pfn_glAlphaFragmentOp1ATI Wm3glAlphaFragmentOp1ATI = 0;
pfn_glAlphaFragmentOp2ATI Wm3glAlphaFragmentOp2ATI = 0;
pfn_glAlphaFragmentOp3ATI Wm3glAlphaFragmentOp3ATI = 0;
pfn_glSetFragmentShaderConstantATI Wm3glSetFragmentShaderConstantATI = 0;

static void Init_GL_ATI_fragment_shader ()
{
    Wm3NumFunctions_GL_ATI_fragment_shader = 0;

    Wm3glGenFragmentShadersATI = (pfn_glGenFragmentShadersATI)GetFunctionPointer("glGenFragmentShadersATI");
    if ( Wm3glGenFragmentShadersATI )
        ++Wm3NumFunctions_GL_ATI_fragment_shader;

    Wm3glBindFragmentShaderATI = (pfn_glBindFragmentShaderATI)GetFunctionPointer("glBindFragmentShaderATI");
    if ( Wm3glBindFragmentShaderATI )
        ++Wm3NumFunctions_GL_ATI_fragment_shader;

    Wm3glDeleteFragmentShaderATI = (pfn_glDeleteFragmentShaderATI)GetFunctionPointer("glDeleteFragmentShaderATI");
    if ( Wm3glDeleteFragmentShaderATI )
        ++Wm3NumFunctions_GL_ATI_fragment_shader;

    Wm3glBeginFragmentShaderATI = (pfn_glBeginFragmentShaderATI)GetFunctionPointer("glBeginFragmentShaderATI");
    if ( Wm3glBeginFragmentShaderATI )
        ++Wm3NumFunctions_GL_ATI_fragment_shader;

    Wm3glEndFragmentShaderATI = (pfn_glEndFragmentShaderATI)GetFunctionPointer("glEndFragmentShaderATI");
    if ( Wm3glEndFragmentShaderATI )
        ++Wm3NumFunctions_GL_ATI_fragment_shader;

    Wm3glPassTexCoordATI = (pfn_glPassTexCoordATI)GetFunctionPointer("glPassTexCoordATI");
    if ( Wm3glPassTexCoordATI )
        ++Wm3NumFunctions_GL_ATI_fragment_shader;

    Wm3glSampleMapATI = (pfn_glSampleMapATI)GetFunctionPointer("glSampleMapATI");
    if ( Wm3glSampleMapATI )
        ++Wm3NumFunctions_GL_ATI_fragment_shader;

    Wm3glColorFragmentOp1ATI = (pfn_glColorFragmentOp1ATI)GetFunctionPointer("glColorFragmentOp1ATI");
    if ( Wm3glColorFragmentOp1ATI )
        ++Wm3NumFunctions_GL_ATI_fragment_shader;

    Wm3glColorFragmentOp2ATI = (pfn_glColorFragmentOp2ATI)GetFunctionPointer("glColorFragmentOp2ATI");
    if ( Wm3glColorFragmentOp2ATI )
        ++Wm3NumFunctions_GL_ATI_fragment_shader;

    Wm3glColorFragmentOp3ATI = (pfn_glColorFragmentOp3ATI)GetFunctionPointer("glColorFragmentOp3ATI");
    if ( Wm3glColorFragmentOp3ATI )
        ++Wm3NumFunctions_GL_ATI_fragment_shader;

    Wm3glAlphaFragmentOp1ATI = (pfn_glAlphaFragmentOp1ATI)GetFunctionPointer("glAlphaFragmentOp1ATI");
    if ( Wm3glAlphaFragmentOp1ATI )
        ++Wm3NumFunctions_GL_ATI_fragment_shader;

    Wm3glAlphaFragmentOp2ATI = (pfn_glAlphaFragmentOp2ATI)GetFunctionPointer("glAlphaFragmentOp2ATI");
    if ( Wm3glAlphaFragmentOp2ATI )
        ++Wm3NumFunctions_GL_ATI_fragment_shader;

    Wm3glAlphaFragmentOp3ATI = (pfn_glAlphaFragmentOp3ATI)GetFunctionPointer("glAlphaFragmentOp3ATI");
    if ( Wm3glAlphaFragmentOp3ATI )
        ++Wm3NumFunctions_GL_ATI_fragment_shader;

    Wm3glSetFragmentShaderConstantATI = (pfn_glSetFragmentShaderConstantATI)GetFunctionPointer("glSetFragmentShaderConstantATI");
    if ( Wm3glSetFragmentShaderConstantATI )
        ++Wm3NumFunctions_GL_ATI_fragment_shader;

    if ( Wm3NumFunctions_GL_ATI_fragment_shader == 14 )
        Wm3Exists_GL_ATI_fragment_shader = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_ATI_fragment_shader = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_ATI_fragment_shader ()
{
    Wm3NumFunctions_GL_ATI_fragment_shader = 0;
    Wm3Exists_GL_ATI_fragment_shader = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_ATI_pn_triangles;
int Wm3NumFunctions_GL_ATI_pn_triangles;
#ifdef WM3_DEFINED_GL_ATI_pn_triangles
pfn_glPNTrianglesiATI Wm3glPNTrianglesiATI = 0;
pfn_glPNTrianglesfATI Wm3glPNTrianglesfATI = 0;

static void Init_GL_ATI_pn_triangles ()
{
    Wm3NumFunctions_GL_ATI_pn_triangles = 0;

    Wm3glPNTrianglesiATI = (pfn_glPNTrianglesiATI)GetFunctionPointer("glPNTrianglesiATI");
    if ( Wm3glPNTrianglesiATI )
        ++Wm3NumFunctions_GL_ATI_pn_triangles;

    Wm3glPNTrianglesfATI = (pfn_glPNTrianglesfATI)GetFunctionPointer("glPNTrianglesfATI");
    if ( Wm3glPNTrianglesfATI )
        ++Wm3NumFunctions_GL_ATI_pn_triangles;

    if ( Wm3NumFunctions_GL_ATI_pn_triangles == 2 )
        Wm3Exists_GL_ATI_pn_triangles = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_ATI_pn_triangles = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_ATI_pn_triangles ()
{
    Wm3NumFunctions_GL_ATI_pn_triangles = 0;
    Wm3Exists_GL_ATI_pn_triangles = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_ATI_vertex_array_object;
int Wm3NumFunctions_GL_ATI_vertex_array_object;
#ifdef WM3_DEFINED_GL_ATI_vertex_array_object
pfn_glNewObjectBufferATI Wm3glNewObjectBufferATI = 0;
pfn_glIsObjectBufferATI Wm3glIsObjectBufferATI = 0;
pfn_glUpdateObjectBufferATI Wm3glUpdateObjectBufferATI = 0;
pfn_glGetObjectBufferfvATI Wm3glGetObjectBufferfvATI = 0;
pfn_glGetObjectBufferivATI Wm3glGetObjectBufferivATI = 0;
pfn_glFreeObjectBufferATI Wm3glFreeObjectBufferATI = 0;
pfn_glArrayObjectATI Wm3glArrayObjectATI = 0;
pfn_glGetArrayObjectfvATI Wm3glGetArrayObjectfvATI = 0;
pfn_glGetArrayObjectivATI Wm3glGetArrayObjectivATI = 0;
pfn_glVariantArrayObjectATI Wm3glVariantArrayObjectATI = 0;
pfn_glGetVariantArrayObjectfvATI Wm3glGetVariantArrayObjectfvATI = 0;
pfn_glGetVariantArrayObjectivATI Wm3glGetVariantArrayObjectivATI = 0;

static void Init_GL_ATI_vertex_array_object ()
{
    Wm3NumFunctions_GL_ATI_vertex_array_object = 0;

    Wm3glNewObjectBufferATI = (pfn_glNewObjectBufferATI)GetFunctionPointer("glNewObjectBufferATI");
    if ( Wm3glNewObjectBufferATI )
        ++Wm3NumFunctions_GL_ATI_vertex_array_object;

    Wm3glIsObjectBufferATI = (pfn_glIsObjectBufferATI)GetFunctionPointer("glIsObjectBufferATI");
    if ( Wm3glIsObjectBufferATI )
        ++Wm3NumFunctions_GL_ATI_vertex_array_object;

    Wm3glUpdateObjectBufferATI = (pfn_glUpdateObjectBufferATI)GetFunctionPointer("glUpdateObjectBufferATI");
    if ( Wm3glUpdateObjectBufferATI )
        ++Wm3NumFunctions_GL_ATI_vertex_array_object;

    Wm3glGetObjectBufferfvATI = (pfn_glGetObjectBufferfvATI)GetFunctionPointer("glGetObjectBufferfvATI");
    if ( Wm3glGetObjectBufferfvATI )
        ++Wm3NumFunctions_GL_ATI_vertex_array_object;

    Wm3glGetObjectBufferivATI = (pfn_glGetObjectBufferivATI)GetFunctionPointer("glGetObjectBufferivATI");
    if ( Wm3glGetObjectBufferivATI )
        ++Wm3NumFunctions_GL_ATI_vertex_array_object;

    Wm3glFreeObjectBufferATI = (pfn_glFreeObjectBufferATI)GetFunctionPointer("glFreeObjectBufferATI");
    if ( Wm3glFreeObjectBufferATI )
        ++Wm3NumFunctions_GL_ATI_vertex_array_object;

    Wm3glArrayObjectATI = (pfn_glArrayObjectATI)GetFunctionPointer("glArrayObjectATI");
    if ( Wm3glArrayObjectATI )
        ++Wm3NumFunctions_GL_ATI_vertex_array_object;

    Wm3glGetArrayObjectfvATI = (pfn_glGetArrayObjectfvATI)GetFunctionPointer("glGetArrayObjectfvATI");
    if ( Wm3glGetArrayObjectfvATI )
        ++Wm3NumFunctions_GL_ATI_vertex_array_object;

    Wm3glGetArrayObjectivATI = (pfn_glGetArrayObjectivATI)GetFunctionPointer("glGetArrayObjectivATI");
    if ( Wm3glGetArrayObjectivATI )
        ++Wm3NumFunctions_GL_ATI_vertex_array_object;

    Wm3glVariantArrayObjectATI = (pfn_glVariantArrayObjectATI)GetFunctionPointer("glVariantArrayObjectATI");
    if ( Wm3glVariantArrayObjectATI )
        ++Wm3NumFunctions_GL_ATI_vertex_array_object;

    Wm3glGetVariantArrayObjectfvATI = (pfn_glGetVariantArrayObjectfvATI)GetFunctionPointer("glGetVariantArrayObjectfvATI");
    if ( Wm3glGetVariantArrayObjectfvATI )
        ++Wm3NumFunctions_GL_ATI_vertex_array_object;

    Wm3glGetVariantArrayObjectivATI = (pfn_glGetVariantArrayObjectivATI)GetFunctionPointer("glGetVariantArrayObjectivATI");
    if ( Wm3glGetVariantArrayObjectivATI )
        ++Wm3NumFunctions_GL_ATI_vertex_array_object;

    if ( Wm3NumFunctions_GL_ATI_vertex_array_object == 12 )
        Wm3Exists_GL_ATI_vertex_array_object = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_ATI_vertex_array_object = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_ATI_vertex_array_object ()
{
    Wm3NumFunctions_GL_ATI_vertex_array_object = 0;
    Wm3Exists_GL_ATI_vertex_array_object = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_EXT_vertex_shader;
int Wm3NumFunctions_GL_EXT_vertex_shader;
#ifdef WM3_DEFINED_GL_EXT_vertex_shader
pfn_glBeginVertexShaderEXT Wm3glBeginVertexShaderEXT = 0;
pfn_glEndVertexShaderEXT Wm3glEndVertexShaderEXT = 0;
pfn_glBindVertexShaderEXT Wm3glBindVertexShaderEXT = 0;
pfn_glGenVertexShadersEXT Wm3glGenVertexShadersEXT = 0;
pfn_glDeleteVertexShaderEXT Wm3glDeleteVertexShaderEXT = 0;
pfn_glShaderOp1EXT Wm3glShaderOp1EXT = 0;
pfn_glShaderOp2EXT Wm3glShaderOp2EXT = 0;
pfn_glShaderOp3EXT Wm3glShaderOp3EXT = 0;
pfn_glSwizzleEXT Wm3glSwizzleEXT = 0;
pfn_glWriteMaskEXT Wm3glWriteMaskEXT = 0;
pfn_glInsertComponentEXT Wm3glInsertComponentEXT = 0;
pfn_glExtractComponentEXT Wm3glExtractComponentEXT = 0;
pfn_glGenSymbolsEXT Wm3glGenSymbolsEXT = 0;
pfn_glSetInvariantEXT Wm3glSetInvariantEXT = 0;
pfn_glSetLocalConstantEXT Wm3glSetLocalConstantEXT = 0;
pfn_glVariantbvEXT Wm3glVariantbvEXT = 0;
pfn_glVariantsvEXT Wm3glVariantsvEXT = 0;
pfn_glVariantivEXT Wm3glVariantivEXT = 0;
pfn_glVariantfvEXT Wm3glVariantfvEXT = 0;
pfn_glVariantdvEXT Wm3glVariantdvEXT = 0;
pfn_glVariantubvEXT Wm3glVariantubvEXT = 0;
pfn_glVariantusvEXT Wm3glVariantusvEXT = 0;
pfn_glVariantuivEXT Wm3glVariantuivEXT = 0;
pfn_glVariantPointerEXT Wm3glVariantPointerEXT = 0;
pfn_glEnableVariantClientStateEXT Wm3glEnableVariantClientStateEXT = 0;
pfn_glDisableVariantClientStateEXT Wm3glDisableVariantClientStateEXT = 0;
pfn_glBindLightParameterEXT Wm3glBindLightParameterEXT = 0;
pfn_glBindMaterialParameterEXT Wm3glBindMaterialParameterEXT = 0;
pfn_glBindTexGenParameterEXT Wm3glBindTexGenParameterEXT = 0;
pfn_glBindTextureUnitParameterEXT Wm3glBindTextureUnitParameterEXT = 0;
pfn_glBindParameterEXT Wm3glBindParameterEXT = 0;
pfn_glIsVariantEnabledEXT Wm3glIsVariantEnabledEXT = 0;
pfn_glGetVariantBooleanvEXT Wm3glGetVariantBooleanvEXT = 0;
pfn_glGetVariantIntegervEXT Wm3glGetVariantIntegervEXT = 0;
pfn_glGetVariantFloatvEXT Wm3glGetVariantFloatvEXT = 0;
pfn_glGetVariantPointervEXT Wm3glGetVariantPointervEXT = 0;
pfn_glGetInvariantBooleanvEXT Wm3glGetInvariantBooleanvEXT = 0;
pfn_glGetInvariantIntegervEXT Wm3glGetInvariantIntegervEXT = 0;
pfn_glGetInvariantFloatvEXT Wm3glGetInvariantFloatvEXT = 0;
pfn_glGetLocalConstantBooleanvEXT Wm3glGetLocalConstantBooleanvEXT = 0;
pfn_glGetLocalConstantIntegervEXT Wm3glGetLocalConstantIntegervEXT = 0;
pfn_glGetLocalConstantFloatvEXT Wm3glGetLocalConstantFloatvEXT = 0;

static void Init_GL_EXT_vertex_shader ()
{
    Wm3NumFunctions_GL_EXT_vertex_shader = 0;

    Wm3glBeginVertexShaderEXT = (pfn_glBeginVertexShaderEXT)GetFunctionPointer("glBeginVertexShaderEXT");
    if ( Wm3glBeginVertexShaderEXT )
        ++Wm3NumFunctions_GL_EXT_vertex_shader;

    Wm3glEndVertexShaderEXT = (pfn_glEndVertexShaderEXT)GetFunctionPointer("glEndVertexShaderEXT");
    if ( Wm3glEndVertexShaderEXT )
        ++Wm3NumFunctions_GL_EXT_vertex_shader;

    Wm3glBindVertexShaderEXT = (pfn_glBindVertexShaderEXT)GetFunctionPointer("glBindVertexShaderEXT");
    if ( Wm3glBindVertexShaderEXT )
        ++Wm3NumFunctions_GL_EXT_vertex_shader;

    Wm3glGenVertexShadersEXT = (pfn_glGenVertexShadersEXT)GetFunctionPointer("glGenVertexShadersEXT");
    if ( Wm3glGenVertexShadersEXT )
        ++Wm3NumFunctions_GL_EXT_vertex_shader;

    Wm3glDeleteVertexShaderEXT = (pfn_glDeleteVertexShaderEXT)GetFunctionPointer("glDeleteVertexShaderEXT");
    if ( Wm3glDeleteVertexShaderEXT )
        ++Wm3NumFunctions_GL_EXT_vertex_shader;

    Wm3glShaderOp1EXT = (pfn_glShaderOp1EXT)GetFunctionPointer("glShaderOp1EXT");
    if ( Wm3glShaderOp1EXT )
        ++Wm3NumFunctions_GL_EXT_vertex_shader;

    Wm3glShaderOp2EXT = (pfn_glShaderOp2EXT)GetFunctionPointer("glShaderOp2EXT");
    if ( Wm3glShaderOp2EXT )
        ++Wm3NumFunctions_GL_EXT_vertex_shader;

    Wm3glShaderOp3EXT = (pfn_glShaderOp3EXT)GetFunctionPointer("glShaderOp3EXT");
    if ( Wm3glShaderOp3EXT )
        ++Wm3NumFunctions_GL_EXT_vertex_shader;

    Wm3glSwizzleEXT = (pfn_glSwizzleEXT)GetFunctionPointer("glSwizzleEXT");
    if ( Wm3glSwizzleEXT )
        ++Wm3NumFunctions_GL_EXT_vertex_shader;

    Wm3glWriteMaskEXT = (pfn_glWriteMaskEXT)GetFunctionPointer("glWriteMaskEXT");
    if ( Wm3glWriteMaskEXT )
        ++Wm3NumFunctions_GL_EXT_vertex_shader;

    Wm3glInsertComponentEXT = (pfn_glInsertComponentEXT)GetFunctionPointer("glInsertComponentEXT");
    if ( Wm3glInsertComponentEXT )
        ++Wm3NumFunctions_GL_EXT_vertex_shader;

    Wm3glExtractComponentEXT = (pfn_glExtractComponentEXT)GetFunctionPointer("glExtractComponentEXT");
    if ( Wm3glExtractComponentEXT )
        ++Wm3NumFunctions_GL_EXT_vertex_shader;

    Wm3glGenSymbolsEXT = (pfn_glGenSymbolsEXT)GetFunctionPointer("glGenSymbolsEXT");
    if ( Wm3glGenSymbolsEXT )
        ++Wm3NumFunctions_GL_EXT_vertex_shader;

    Wm3glSetInvariantEXT = (pfn_glSetInvariantEXT)GetFunctionPointer("glSetInvariantEXT");
    if ( Wm3glSetInvariantEXT )
        ++Wm3NumFunctions_GL_EXT_vertex_shader;

    Wm3glSetLocalConstantEXT = (pfn_glSetLocalConstantEXT)GetFunctionPointer("glSetLocalConstantEXT");
    if ( Wm3glSetLocalConstantEXT )
        ++Wm3NumFunctions_GL_EXT_vertex_shader;

    Wm3glVariantbvEXT = (pfn_glVariantbvEXT)GetFunctionPointer("glVariantbvEXT");
    if ( Wm3glVariantbvEXT )
        ++Wm3NumFunctions_GL_EXT_vertex_shader;

    Wm3glVariantsvEXT = (pfn_glVariantsvEXT)GetFunctionPointer("glVariantsvEXT");
    if ( Wm3glVariantsvEXT )
        ++Wm3NumFunctions_GL_EXT_vertex_shader;

    Wm3glVariantivEXT = (pfn_glVariantivEXT)GetFunctionPointer("glVariantivEXT");
    if ( Wm3glVariantivEXT )
        ++Wm3NumFunctions_GL_EXT_vertex_shader;

    Wm3glVariantfvEXT = (pfn_glVariantfvEXT)GetFunctionPointer("glVariantfvEXT");
    if ( Wm3glVariantfvEXT )
        ++Wm3NumFunctions_GL_EXT_vertex_shader;

    Wm3glVariantdvEXT = (pfn_glVariantdvEXT)GetFunctionPointer("glVariantdvEXT");
    if ( Wm3glVariantdvEXT )
        ++Wm3NumFunctions_GL_EXT_vertex_shader;

    Wm3glVariantubvEXT = (pfn_glVariantubvEXT)GetFunctionPointer("glVariantubvEXT");
    if ( Wm3glVariantubvEXT )
        ++Wm3NumFunctions_GL_EXT_vertex_shader;

    Wm3glVariantusvEXT = (pfn_glVariantusvEXT)GetFunctionPointer("glVariantusvEXT");
    if ( Wm3glVariantusvEXT )
        ++Wm3NumFunctions_GL_EXT_vertex_shader;

    Wm3glVariantuivEXT = (pfn_glVariantuivEXT)GetFunctionPointer("glVariantuivEXT");
    if ( Wm3glVariantuivEXT )
        ++Wm3NumFunctions_GL_EXT_vertex_shader;

    Wm3glVariantPointerEXT = (pfn_glVariantPointerEXT)GetFunctionPointer("glVariantPointerEXT");
    if ( Wm3glVariantPointerEXT )
        ++Wm3NumFunctions_GL_EXT_vertex_shader;

    Wm3glEnableVariantClientStateEXT = (pfn_glEnableVariantClientStateEXT)GetFunctionPointer("glEnableVariantClientStateEXT");
    if ( Wm3glEnableVariantClientStateEXT )
        ++Wm3NumFunctions_GL_EXT_vertex_shader;

    Wm3glDisableVariantClientStateEXT = (pfn_glDisableVariantClientStateEXT)GetFunctionPointer("glDisableVariantClientStateEXT");
    if ( Wm3glDisableVariantClientStateEXT )
        ++Wm3NumFunctions_GL_EXT_vertex_shader;

    Wm3glBindLightParameterEXT = (pfn_glBindLightParameterEXT)GetFunctionPointer("glBindLightParameterEXT");
    if ( Wm3glBindLightParameterEXT )
        ++Wm3NumFunctions_GL_EXT_vertex_shader;

    Wm3glBindMaterialParameterEXT = (pfn_glBindMaterialParameterEXT)GetFunctionPointer("glBindMaterialParameterEXT");
    if ( Wm3glBindMaterialParameterEXT )
        ++Wm3NumFunctions_GL_EXT_vertex_shader;

    Wm3glBindTexGenParameterEXT = (pfn_glBindTexGenParameterEXT)GetFunctionPointer("glBindTexGenParameterEXT");
    if ( Wm3glBindTexGenParameterEXT )
        ++Wm3NumFunctions_GL_EXT_vertex_shader;

    Wm3glBindTextureUnitParameterEXT = (pfn_glBindTextureUnitParameterEXT)GetFunctionPointer("glBindTextureUnitParameterEXT");
    if ( Wm3glBindTextureUnitParameterEXT )
        ++Wm3NumFunctions_GL_EXT_vertex_shader;

    Wm3glBindParameterEXT = (pfn_glBindParameterEXT)GetFunctionPointer("glBindParameterEXT");
    if ( Wm3glBindParameterEXT )
        ++Wm3NumFunctions_GL_EXT_vertex_shader;

    Wm3glIsVariantEnabledEXT = (pfn_glIsVariantEnabledEXT)GetFunctionPointer("glIsVariantEnabledEXT");
    if ( Wm3glIsVariantEnabledEXT )
        ++Wm3NumFunctions_GL_EXT_vertex_shader;

    Wm3glGetVariantBooleanvEXT = (pfn_glGetVariantBooleanvEXT)GetFunctionPointer("glGetVariantBooleanvEXT");
    if ( Wm3glGetVariantBooleanvEXT )
        ++Wm3NumFunctions_GL_EXT_vertex_shader;

    Wm3glGetVariantIntegervEXT = (pfn_glGetVariantIntegervEXT)GetFunctionPointer("glGetVariantIntegervEXT");
    if ( Wm3glGetVariantIntegervEXT )
        ++Wm3NumFunctions_GL_EXT_vertex_shader;

    Wm3glGetVariantFloatvEXT = (pfn_glGetVariantFloatvEXT)GetFunctionPointer("glGetVariantFloatvEXT");
    if ( Wm3glGetVariantFloatvEXT )
        ++Wm3NumFunctions_GL_EXT_vertex_shader;

    Wm3glGetVariantPointervEXT = (pfn_glGetVariantPointervEXT)GetFunctionPointer("glGetVariantPointervEXT");
    if ( Wm3glGetVariantPointervEXT )
        ++Wm3NumFunctions_GL_EXT_vertex_shader;

    Wm3glGetInvariantBooleanvEXT = (pfn_glGetInvariantBooleanvEXT)GetFunctionPointer("glGetInvariantBooleanvEXT");
    if ( Wm3glGetInvariantBooleanvEXT )
        ++Wm3NumFunctions_GL_EXT_vertex_shader;

    Wm3glGetInvariantIntegervEXT = (pfn_glGetInvariantIntegervEXT)GetFunctionPointer("glGetInvariantIntegervEXT");
    if ( Wm3glGetInvariantIntegervEXT )
        ++Wm3NumFunctions_GL_EXT_vertex_shader;

    Wm3glGetInvariantFloatvEXT = (pfn_glGetInvariantFloatvEXT)GetFunctionPointer("glGetInvariantFloatvEXT");
    if ( Wm3glGetInvariantFloatvEXT )
        ++Wm3NumFunctions_GL_EXT_vertex_shader;

    Wm3glGetLocalConstantBooleanvEXT = (pfn_glGetLocalConstantBooleanvEXT)GetFunctionPointer("glGetLocalConstantBooleanvEXT");
    if ( Wm3glGetLocalConstantBooleanvEXT )
        ++Wm3NumFunctions_GL_EXT_vertex_shader;

    Wm3glGetLocalConstantIntegervEXT = (pfn_glGetLocalConstantIntegervEXT)GetFunctionPointer("glGetLocalConstantIntegervEXT");
    if ( Wm3glGetLocalConstantIntegervEXT )
        ++Wm3NumFunctions_GL_EXT_vertex_shader;

    Wm3glGetLocalConstantFloatvEXT = (pfn_glGetLocalConstantFloatvEXT)GetFunctionPointer("glGetLocalConstantFloatvEXT");
    if ( Wm3glGetLocalConstantFloatvEXT )
        ++Wm3NumFunctions_GL_EXT_vertex_shader;

    if ( Wm3NumFunctions_GL_EXT_vertex_shader == 42 )
        Wm3Exists_GL_EXT_vertex_shader = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_EXT_vertex_shader = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_EXT_vertex_shader ()
{
    Wm3NumFunctions_GL_EXT_vertex_shader = 0;
    Wm3Exists_GL_EXT_vertex_shader = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_ATI_vertex_streams;
int Wm3NumFunctions_GL_ATI_vertex_streams;
#ifdef WM3_DEFINED_GL_ATI_vertex_streams
pfn_glVertexStream1sATI Wm3glVertexStream1sATI = 0;
pfn_glVertexStream1svATI Wm3glVertexStream1svATI = 0;
pfn_glVertexStream1iATI Wm3glVertexStream1iATI = 0;
pfn_glVertexStream1ivATI Wm3glVertexStream1ivATI = 0;
pfn_glVertexStream1fATI Wm3glVertexStream1fATI = 0;
pfn_glVertexStream1fvATI Wm3glVertexStream1fvATI = 0;
pfn_glVertexStream1dATI Wm3glVertexStream1dATI = 0;
pfn_glVertexStream1dvATI Wm3glVertexStream1dvATI = 0;
pfn_glVertexStream2sATI Wm3glVertexStream2sATI = 0;
pfn_glVertexStream2svATI Wm3glVertexStream2svATI = 0;
pfn_glVertexStream2iATI Wm3glVertexStream2iATI = 0;
pfn_glVertexStream2ivATI Wm3glVertexStream2ivATI = 0;
pfn_glVertexStream2fATI Wm3glVertexStream2fATI = 0;
pfn_glVertexStream2fvATI Wm3glVertexStream2fvATI = 0;
pfn_glVertexStream2dATI Wm3glVertexStream2dATI = 0;
pfn_glVertexStream2dvATI Wm3glVertexStream2dvATI = 0;
pfn_glVertexStream3sATI Wm3glVertexStream3sATI = 0;
pfn_glVertexStream3svATI Wm3glVertexStream3svATI = 0;
pfn_glVertexStream3iATI Wm3glVertexStream3iATI = 0;
pfn_glVertexStream3ivATI Wm3glVertexStream3ivATI = 0;
pfn_glVertexStream3fATI Wm3glVertexStream3fATI = 0;
pfn_glVertexStream3fvATI Wm3glVertexStream3fvATI = 0;
pfn_glVertexStream3dATI Wm3glVertexStream3dATI = 0;
pfn_glVertexStream3dvATI Wm3glVertexStream3dvATI = 0;
pfn_glVertexStream4sATI Wm3glVertexStream4sATI = 0;
pfn_glVertexStream4svATI Wm3glVertexStream4svATI = 0;
pfn_glVertexStream4iATI Wm3glVertexStream4iATI = 0;
pfn_glVertexStream4ivATI Wm3glVertexStream4ivATI = 0;
pfn_glVertexStream4fATI Wm3glVertexStream4fATI = 0;
pfn_glVertexStream4fvATI Wm3glVertexStream4fvATI = 0;
pfn_glVertexStream4dATI Wm3glVertexStream4dATI = 0;
pfn_glVertexStream4dvATI Wm3glVertexStream4dvATI = 0;
pfn_glNormalStream3bATI Wm3glNormalStream3bATI = 0;
pfn_glNormalStream3bvATI Wm3glNormalStream3bvATI = 0;
pfn_glNormalStream3sATI Wm3glNormalStream3sATI = 0;
pfn_glNormalStream3svATI Wm3glNormalStream3svATI = 0;
pfn_glNormalStream3iATI Wm3glNormalStream3iATI = 0;
pfn_glNormalStream3ivATI Wm3glNormalStream3ivATI = 0;
pfn_glNormalStream3fATI Wm3glNormalStream3fATI = 0;
pfn_glNormalStream3fvATI Wm3glNormalStream3fvATI = 0;
pfn_glNormalStream3dATI Wm3glNormalStream3dATI = 0;
pfn_glNormalStream3dvATI Wm3glNormalStream3dvATI = 0;
pfn_glClientActiveVertexStreamATI Wm3glClientActiveVertexStreamATI = 0;
pfn_glVertexBlendEnviATI Wm3glVertexBlendEnviATI = 0;
pfn_glVertexBlendEnvfATI Wm3glVertexBlendEnvfATI = 0;

static void Init_GL_ATI_vertex_streams ()
{
    Wm3NumFunctions_GL_ATI_vertex_streams = 0;

    Wm3glVertexStream1sATI = (pfn_glVertexStream1sATI)GetFunctionPointer("glVertexStream1sATI");
    if ( Wm3glVertexStream1sATI )
        ++Wm3NumFunctions_GL_ATI_vertex_streams;

    Wm3glVertexStream1svATI = (pfn_glVertexStream1svATI)GetFunctionPointer("glVertexStream1svATI");
    if ( Wm3glVertexStream1svATI )
        ++Wm3NumFunctions_GL_ATI_vertex_streams;

    Wm3glVertexStream1iATI = (pfn_glVertexStream1iATI)GetFunctionPointer("glVertexStream1iATI");
    if ( Wm3glVertexStream1iATI )
        ++Wm3NumFunctions_GL_ATI_vertex_streams;

    Wm3glVertexStream1ivATI = (pfn_glVertexStream1ivATI)GetFunctionPointer("glVertexStream1ivATI");
    if ( Wm3glVertexStream1ivATI )
        ++Wm3NumFunctions_GL_ATI_vertex_streams;

    Wm3glVertexStream1fATI = (pfn_glVertexStream1fATI)GetFunctionPointer("glVertexStream1fATI");
    if ( Wm3glVertexStream1fATI )
        ++Wm3NumFunctions_GL_ATI_vertex_streams;

    Wm3glVertexStream1fvATI = (pfn_glVertexStream1fvATI)GetFunctionPointer("glVertexStream1fvATI");
    if ( Wm3glVertexStream1fvATI )
        ++Wm3NumFunctions_GL_ATI_vertex_streams;

    Wm3glVertexStream1dATI = (pfn_glVertexStream1dATI)GetFunctionPointer("glVertexStream1dATI");
    if ( Wm3glVertexStream1dATI )
        ++Wm3NumFunctions_GL_ATI_vertex_streams;

    Wm3glVertexStream1dvATI = (pfn_glVertexStream1dvATI)GetFunctionPointer("glVertexStream1dvATI");
    if ( Wm3glVertexStream1dvATI )
        ++Wm3NumFunctions_GL_ATI_vertex_streams;

    Wm3glVertexStream2sATI = (pfn_glVertexStream2sATI)GetFunctionPointer("glVertexStream2sATI");
    if ( Wm3glVertexStream2sATI )
        ++Wm3NumFunctions_GL_ATI_vertex_streams;

    Wm3glVertexStream2svATI = (pfn_glVertexStream2svATI)GetFunctionPointer("glVertexStream2svATI");
    if ( Wm3glVertexStream2svATI )
        ++Wm3NumFunctions_GL_ATI_vertex_streams;

    Wm3glVertexStream2iATI = (pfn_glVertexStream2iATI)GetFunctionPointer("glVertexStream2iATI");
    if ( Wm3glVertexStream2iATI )
        ++Wm3NumFunctions_GL_ATI_vertex_streams;

    Wm3glVertexStream2ivATI = (pfn_glVertexStream2ivATI)GetFunctionPointer("glVertexStream2ivATI");
    if ( Wm3glVertexStream2ivATI )
        ++Wm3NumFunctions_GL_ATI_vertex_streams;

    Wm3glVertexStream2fATI = (pfn_glVertexStream2fATI)GetFunctionPointer("glVertexStream2fATI");
    if ( Wm3glVertexStream2fATI )
        ++Wm3NumFunctions_GL_ATI_vertex_streams;

    Wm3glVertexStream2fvATI = (pfn_glVertexStream2fvATI)GetFunctionPointer("glVertexStream2fvATI");
    if ( Wm3glVertexStream2fvATI )
        ++Wm3NumFunctions_GL_ATI_vertex_streams;

    Wm3glVertexStream2dATI = (pfn_glVertexStream2dATI)GetFunctionPointer("glVertexStream2dATI");
    if ( Wm3glVertexStream2dATI )
        ++Wm3NumFunctions_GL_ATI_vertex_streams;

    Wm3glVertexStream2dvATI = (pfn_glVertexStream2dvATI)GetFunctionPointer("glVertexStream2dvATI");
    if ( Wm3glVertexStream2dvATI )
        ++Wm3NumFunctions_GL_ATI_vertex_streams;

    Wm3glVertexStream3sATI = (pfn_glVertexStream3sATI)GetFunctionPointer("glVertexStream3sATI");
    if ( Wm3glVertexStream3sATI )
        ++Wm3NumFunctions_GL_ATI_vertex_streams;

    Wm3glVertexStream3svATI = (pfn_glVertexStream3svATI)GetFunctionPointer("glVertexStream3svATI");
    if ( Wm3glVertexStream3svATI )
        ++Wm3NumFunctions_GL_ATI_vertex_streams;

    Wm3glVertexStream3iATI = (pfn_glVertexStream3iATI)GetFunctionPointer("glVertexStream3iATI");
    if ( Wm3glVertexStream3iATI )
        ++Wm3NumFunctions_GL_ATI_vertex_streams;

    Wm3glVertexStream3ivATI = (pfn_glVertexStream3ivATI)GetFunctionPointer("glVertexStream3ivATI");
    if ( Wm3glVertexStream3ivATI )
        ++Wm3NumFunctions_GL_ATI_vertex_streams;

    Wm3glVertexStream3fATI = (pfn_glVertexStream3fATI)GetFunctionPointer("glVertexStream3fATI");
    if ( Wm3glVertexStream3fATI )
        ++Wm3NumFunctions_GL_ATI_vertex_streams;

    Wm3glVertexStream3fvATI = (pfn_glVertexStream3fvATI)GetFunctionPointer("glVertexStream3fvATI");
    if ( Wm3glVertexStream3fvATI )
        ++Wm3NumFunctions_GL_ATI_vertex_streams;

    Wm3glVertexStream3dATI = (pfn_glVertexStream3dATI)GetFunctionPointer("glVertexStream3dATI");
    if ( Wm3glVertexStream3dATI )
        ++Wm3NumFunctions_GL_ATI_vertex_streams;

    Wm3glVertexStream3dvATI = (pfn_glVertexStream3dvATI)GetFunctionPointer("glVertexStream3dvATI");
    if ( Wm3glVertexStream3dvATI )
        ++Wm3NumFunctions_GL_ATI_vertex_streams;

    Wm3glVertexStream4sATI = (pfn_glVertexStream4sATI)GetFunctionPointer("glVertexStream4sATI");
    if ( Wm3glVertexStream4sATI )
        ++Wm3NumFunctions_GL_ATI_vertex_streams;

    Wm3glVertexStream4svATI = (pfn_glVertexStream4svATI)GetFunctionPointer("glVertexStream4svATI");
    if ( Wm3glVertexStream4svATI )
        ++Wm3NumFunctions_GL_ATI_vertex_streams;

    Wm3glVertexStream4iATI = (pfn_glVertexStream4iATI)GetFunctionPointer("glVertexStream4iATI");
    if ( Wm3glVertexStream4iATI )
        ++Wm3NumFunctions_GL_ATI_vertex_streams;

    Wm3glVertexStream4ivATI = (pfn_glVertexStream4ivATI)GetFunctionPointer("glVertexStream4ivATI");
    if ( Wm3glVertexStream4ivATI )
        ++Wm3NumFunctions_GL_ATI_vertex_streams;

    Wm3glVertexStream4fATI = (pfn_glVertexStream4fATI)GetFunctionPointer("glVertexStream4fATI");
    if ( Wm3glVertexStream4fATI )
        ++Wm3NumFunctions_GL_ATI_vertex_streams;

    Wm3glVertexStream4fvATI = (pfn_glVertexStream4fvATI)GetFunctionPointer("glVertexStream4fvATI");
    if ( Wm3glVertexStream4fvATI )
        ++Wm3NumFunctions_GL_ATI_vertex_streams;

    Wm3glVertexStream4dATI = (pfn_glVertexStream4dATI)GetFunctionPointer("glVertexStream4dATI");
    if ( Wm3glVertexStream4dATI )
        ++Wm3NumFunctions_GL_ATI_vertex_streams;

    Wm3glVertexStream4dvATI = (pfn_glVertexStream4dvATI)GetFunctionPointer("glVertexStream4dvATI");
    if ( Wm3glVertexStream4dvATI )
        ++Wm3NumFunctions_GL_ATI_vertex_streams;

    Wm3glNormalStream3bATI = (pfn_glNormalStream3bATI)GetFunctionPointer("glNormalStream3bATI");
    if ( Wm3glNormalStream3bATI )
        ++Wm3NumFunctions_GL_ATI_vertex_streams;

    Wm3glNormalStream3bvATI = (pfn_glNormalStream3bvATI)GetFunctionPointer("glNormalStream3bvATI");
    if ( Wm3glNormalStream3bvATI )
        ++Wm3NumFunctions_GL_ATI_vertex_streams;

    Wm3glNormalStream3sATI = (pfn_glNormalStream3sATI)GetFunctionPointer("glNormalStream3sATI");
    if ( Wm3glNormalStream3sATI )
        ++Wm3NumFunctions_GL_ATI_vertex_streams;

    Wm3glNormalStream3svATI = (pfn_glNormalStream3svATI)GetFunctionPointer("glNormalStream3svATI");
    if ( Wm3glNormalStream3svATI )
        ++Wm3NumFunctions_GL_ATI_vertex_streams;

    Wm3glNormalStream3iATI = (pfn_glNormalStream3iATI)GetFunctionPointer("glNormalStream3iATI");
    if ( Wm3glNormalStream3iATI )
        ++Wm3NumFunctions_GL_ATI_vertex_streams;

    Wm3glNormalStream3ivATI = (pfn_glNormalStream3ivATI)GetFunctionPointer("glNormalStream3ivATI");
    if ( Wm3glNormalStream3ivATI )
        ++Wm3NumFunctions_GL_ATI_vertex_streams;

    Wm3glNormalStream3fATI = (pfn_glNormalStream3fATI)GetFunctionPointer("glNormalStream3fATI");
    if ( Wm3glNormalStream3fATI )
        ++Wm3NumFunctions_GL_ATI_vertex_streams;

    Wm3glNormalStream3fvATI = (pfn_glNormalStream3fvATI)GetFunctionPointer("glNormalStream3fvATI");
    if ( Wm3glNormalStream3fvATI )
        ++Wm3NumFunctions_GL_ATI_vertex_streams;

    Wm3glNormalStream3dATI = (pfn_glNormalStream3dATI)GetFunctionPointer("glNormalStream3dATI");
    if ( Wm3glNormalStream3dATI )
        ++Wm3NumFunctions_GL_ATI_vertex_streams;

    Wm3glNormalStream3dvATI = (pfn_glNormalStream3dvATI)GetFunctionPointer("glNormalStream3dvATI");
    if ( Wm3glNormalStream3dvATI )
        ++Wm3NumFunctions_GL_ATI_vertex_streams;

    Wm3glClientActiveVertexStreamATI = (pfn_glClientActiveVertexStreamATI)GetFunctionPointer("glClientActiveVertexStreamATI");
    if ( Wm3glClientActiveVertexStreamATI )
        ++Wm3NumFunctions_GL_ATI_vertex_streams;

    Wm3glVertexBlendEnviATI = (pfn_glVertexBlendEnviATI)GetFunctionPointer("glVertexBlendEnviATI");
    if ( Wm3glVertexBlendEnviATI )
        ++Wm3NumFunctions_GL_ATI_vertex_streams;

    Wm3glVertexBlendEnvfATI = (pfn_glVertexBlendEnvfATI)GetFunctionPointer("glVertexBlendEnvfATI");
    if ( Wm3glVertexBlendEnvfATI )
        ++Wm3NumFunctions_GL_ATI_vertex_streams;

    if ( Wm3NumFunctions_GL_ATI_vertex_streams == 45 )
        Wm3Exists_GL_ATI_vertex_streams = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_ATI_vertex_streams = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_ATI_vertex_streams ()
{
    Wm3NumFunctions_GL_ATI_vertex_streams = 0;
    Wm3Exists_GL_ATI_vertex_streams = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_ATI_element_array;
int Wm3NumFunctions_GL_ATI_element_array;
#ifdef WM3_DEFINED_GL_ATI_element_array
pfn_glElementPointerATI Wm3glElementPointerATI = 0;
pfn_glDrawElementArrayATI Wm3glDrawElementArrayATI = 0;
pfn_glDrawRangeElementArrayATI Wm3glDrawRangeElementArrayATI = 0;

static void Init_GL_ATI_element_array ()
{
    Wm3NumFunctions_GL_ATI_element_array = 0;

    Wm3glElementPointerATI = (pfn_glElementPointerATI)GetFunctionPointer("glElementPointerATI");
    if ( Wm3glElementPointerATI )
        ++Wm3NumFunctions_GL_ATI_element_array;

    Wm3glDrawElementArrayATI = (pfn_glDrawElementArrayATI)GetFunctionPointer("glDrawElementArrayATI");
    if ( Wm3glDrawElementArrayATI )
        ++Wm3NumFunctions_GL_ATI_element_array;

    Wm3glDrawRangeElementArrayATI = (pfn_glDrawRangeElementArrayATI)GetFunctionPointer("glDrawRangeElementArrayATI");
    if ( Wm3glDrawRangeElementArrayATI )
        ++Wm3NumFunctions_GL_ATI_element_array;

    if ( Wm3NumFunctions_GL_ATI_element_array == 3 )
        Wm3Exists_GL_ATI_element_array = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_ATI_element_array = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_ATI_element_array ()
{
    Wm3NumFunctions_GL_ATI_element_array = 0;
    Wm3Exists_GL_ATI_element_array = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_SUN_mesh_array;
int Wm3NumFunctions_GL_SUN_mesh_array;
#ifdef WM3_DEFINED_GL_SUN_mesh_array
pfn_glDrawMeshArraysSUN Wm3glDrawMeshArraysSUN = 0;

static void Init_GL_SUN_mesh_array ()
{
    Wm3NumFunctions_GL_SUN_mesh_array = 0;

    Wm3glDrawMeshArraysSUN = (pfn_glDrawMeshArraysSUN)GetFunctionPointer("glDrawMeshArraysSUN");
    if ( Wm3glDrawMeshArraysSUN )
        ++Wm3NumFunctions_GL_SUN_mesh_array;

    if ( Wm3NumFunctions_GL_SUN_mesh_array == 1 )
        Wm3Exists_GL_SUN_mesh_array = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_SUN_mesh_array = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_SUN_mesh_array ()
{
    Wm3NumFunctions_GL_SUN_mesh_array = 0;
    Wm3Exists_GL_SUN_mesh_array = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_SUN_slice_accum;
int Wm3NumFunctions_GL_SUN_slice_accum;
#ifdef WM3_DEFINED_GL_SUN_slice_accum
static void Init_GL_SUN_slice_accum ()
{
    Wm3NumFunctions_GL_SUN_slice_accum = 0;
    Wm3Exists_GL_SUN_slice_accum = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_SUN_slice_accum ()
{
    Wm3NumFunctions_GL_SUN_slice_accum = 0;
    Wm3Exists_GL_SUN_slice_accum = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_NV_multisample_filter_hint;
int Wm3NumFunctions_GL_NV_multisample_filter_hint;
#ifdef WM3_DEFINED_GL_NV_multisample_filter_hint
static void Init_GL_NV_multisample_filter_hint ()
{
    Wm3NumFunctions_GL_NV_multisample_filter_hint = 0;
    Wm3Exists_GL_NV_multisample_filter_hint = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_NV_multisample_filter_hint ()
{
    Wm3NumFunctions_GL_NV_multisample_filter_hint = 0;
    Wm3Exists_GL_NV_multisample_filter_hint = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_NV_depth_clamp;
int Wm3NumFunctions_GL_NV_depth_clamp;
#ifdef WM3_DEFINED_GL_NV_depth_clamp
static void Init_GL_NV_depth_clamp ()
{
    Wm3NumFunctions_GL_NV_depth_clamp = 0;
    Wm3Exists_GL_NV_depth_clamp = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_NV_depth_clamp ()
{
    Wm3NumFunctions_GL_NV_depth_clamp = 0;
    Wm3Exists_GL_NV_depth_clamp = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_NV_occlusion_query;
int Wm3NumFunctions_GL_NV_occlusion_query;
#ifdef WM3_DEFINED_GL_NV_occlusion_query
pfn_glGenOcclusionQueriesNV Wm3glGenOcclusionQueriesNV = 0;
pfn_glDeleteOcclusionQueriesNV Wm3glDeleteOcclusionQueriesNV = 0;
pfn_glIsOcclusionQueryNV Wm3glIsOcclusionQueryNV = 0;
pfn_glBeginOcclusionQueryNV Wm3glBeginOcclusionQueryNV = 0;
pfn_glEndOcclusionQueryNV Wm3glEndOcclusionQueryNV = 0;
pfn_glGetOcclusionQueryivNV Wm3glGetOcclusionQueryivNV = 0;
pfn_glGetOcclusionQueryuivNV Wm3glGetOcclusionQueryuivNV = 0;

static void Init_GL_NV_occlusion_query ()
{
    Wm3NumFunctions_GL_NV_occlusion_query = 0;

    Wm3glGenOcclusionQueriesNV = (pfn_glGenOcclusionQueriesNV)GetFunctionPointer("glGenOcclusionQueriesNV");
    if ( Wm3glGenOcclusionQueriesNV )
        ++Wm3NumFunctions_GL_NV_occlusion_query;

    Wm3glDeleteOcclusionQueriesNV = (pfn_glDeleteOcclusionQueriesNV)GetFunctionPointer("glDeleteOcclusionQueriesNV");
    if ( Wm3glDeleteOcclusionQueriesNV )
        ++Wm3NumFunctions_GL_NV_occlusion_query;

    Wm3glIsOcclusionQueryNV = (pfn_glIsOcclusionQueryNV)GetFunctionPointer("glIsOcclusionQueryNV");
    if ( Wm3glIsOcclusionQueryNV )
        ++Wm3NumFunctions_GL_NV_occlusion_query;

    Wm3glBeginOcclusionQueryNV = (pfn_glBeginOcclusionQueryNV)GetFunctionPointer("glBeginOcclusionQueryNV");
    if ( Wm3glBeginOcclusionQueryNV )
        ++Wm3NumFunctions_GL_NV_occlusion_query;

    Wm3glEndOcclusionQueryNV = (pfn_glEndOcclusionQueryNV)GetFunctionPointer("glEndOcclusionQueryNV");
    if ( Wm3glEndOcclusionQueryNV )
        ++Wm3NumFunctions_GL_NV_occlusion_query;

    Wm3glGetOcclusionQueryivNV = (pfn_glGetOcclusionQueryivNV)GetFunctionPointer("glGetOcclusionQueryivNV");
    if ( Wm3glGetOcclusionQueryivNV )
        ++Wm3NumFunctions_GL_NV_occlusion_query;

    Wm3glGetOcclusionQueryuivNV = (pfn_glGetOcclusionQueryuivNV)GetFunctionPointer("glGetOcclusionQueryuivNV");
    if ( Wm3glGetOcclusionQueryuivNV )
        ++Wm3NumFunctions_GL_NV_occlusion_query;

    if ( Wm3NumFunctions_GL_NV_occlusion_query == 7 )
        Wm3Exists_GL_NV_occlusion_query = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_NV_occlusion_query = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_NV_occlusion_query ()
{
    Wm3NumFunctions_GL_NV_occlusion_query = 0;
    Wm3Exists_GL_NV_occlusion_query = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_NV_point_sprite;
int Wm3NumFunctions_GL_NV_point_sprite;
#ifdef WM3_DEFINED_GL_NV_point_sprite
pfn_glPointParameteriNV Wm3glPointParameteriNV = 0;
pfn_glPointParameterivNV Wm3glPointParameterivNV = 0;

static void Init_GL_NV_point_sprite ()
{
    Wm3NumFunctions_GL_NV_point_sprite = 0;

    Wm3glPointParameteriNV = (pfn_glPointParameteriNV)GetFunctionPointer("glPointParameteriNV");
    if ( Wm3glPointParameteriNV )
        ++Wm3NumFunctions_GL_NV_point_sprite;

    Wm3glPointParameterivNV = (pfn_glPointParameterivNV)GetFunctionPointer("glPointParameterivNV");
    if ( Wm3glPointParameterivNV )
        ++Wm3NumFunctions_GL_NV_point_sprite;

    if ( Wm3NumFunctions_GL_NV_point_sprite == 2 )
        Wm3Exists_GL_NV_point_sprite = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_NV_point_sprite = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_NV_point_sprite ()
{
    Wm3NumFunctions_GL_NV_point_sprite = 0;
    Wm3Exists_GL_NV_point_sprite = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_NV_texture_shader3;
int Wm3NumFunctions_GL_NV_texture_shader3;
#ifdef WM3_DEFINED_GL_NV_texture_shader3
static void Init_GL_NV_texture_shader3 ()
{
    Wm3NumFunctions_GL_NV_texture_shader3 = 0;
    Wm3Exists_GL_NV_texture_shader3 = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_NV_texture_shader3 ()
{
    Wm3NumFunctions_GL_NV_texture_shader3 = 0;
    Wm3Exists_GL_NV_texture_shader3 = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_NV_vertex_program1_1;
int Wm3NumFunctions_GL_NV_vertex_program1_1;
#ifdef WM3_DEFINED_GL_NV_vertex_program1_1
static void Init_GL_NV_vertex_program1_1 ()
{
    Wm3NumFunctions_GL_NV_vertex_program1_1 = 0;
    Wm3Exists_GL_NV_vertex_program1_1 = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_NV_vertex_program1_1 ()
{
    Wm3NumFunctions_GL_NV_vertex_program1_1 = 0;
    Wm3Exists_GL_NV_vertex_program1_1 = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_EXT_shadow_funcs;
int Wm3NumFunctions_GL_EXT_shadow_funcs;
#ifdef WM3_DEFINED_GL_EXT_shadow_funcs
static void Init_GL_EXT_shadow_funcs ()
{
    Wm3NumFunctions_GL_EXT_shadow_funcs = 0;
    Wm3Exists_GL_EXT_shadow_funcs = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_EXT_shadow_funcs ()
{
    Wm3NumFunctions_GL_EXT_shadow_funcs = 0;
    Wm3Exists_GL_EXT_shadow_funcs = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_EXT_stencil_two_side;
int Wm3NumFunctions_GL_EXT_stencil_two_side;
#ifdef WM3_DEFINED_GL_EXT_stencil_two_side
pfn_glActiveStencilFaceEXT Wm3glActiveStencilFaceEXT = 0;

static void Init_GL_EXT_stencil_two_side ()
{
    Wm3NumFunctions_GL_EXT_stencil_two_side = 0;

    Wm3glActiveStencilFaceEXT = (pfn_glActiveStencilFaceEXT)GetFunctionPointer("glActiveStencilFaceEXT");
    if ( Wm3glActiveStencilFaceEXT )
        ++Wm3NumFunctions_GL_EXT_stencil_two_side;

    if ( Wm3NumFunctions_GL_EXT_stencil_two_side == 1 )
        Wm3Exists_GL_EXT_stencil_two_side = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_EXT_stencil_two_side = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_EXT_stencil_two_side ()
{
    Wm3NumFunctions_GL_EXT_stencil_two_side = 0;
    Wm3Exists_GL_EXT_stencil_two_side = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_ATI_text_fragment_shader;
int Wm3NumFunctions_GL_ATI_text_fragment_shader;
#ifdef WM3_DEFINED_GL_ATI_text_fragment_shader
static void Init_GL_ATI_text_fragment_shader ()
{
    Wm3NumFunctions_GL_ATI_text_fragment_shader = 0;
    Wm3Exists_GL_ATI_text_fragment_shader = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_ATI_text_fragment_shader ()
{
    Wm3NumFunctions_GL_ATI_text_fragment_shader = 0;
    Wm3Exists_GL_ATI_text_fragment_shader = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_APPLE_client_storage;
int Wm3NumFunctions_GL_APPLE_client_storage;
#ifdef WM3_DEFINED_GL_APPLE_client_storage
static void Init_GL_APPLE_client_storage ()
{
    Wm3NumFunctions_GL_APPLE_client_storage = 0;
    Wm3Exists_GL_APPLE_client_storage = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_APPLE_client_storage ()
{
    Wm3NumFunctions_GL_APPLE_client_storage = 0;
    Wm3Exists_GL_APPLE_client_storage = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_APPLE_element_array;
int Wm3NumFunctions_GL_APPLE_element_array;
#ifdef WM3_DEFINED_GL_APPLE_element_array
pfn_glElementPointerAPPLE Wm3glElementPointerAPPLE = 0;
pfn_glDrawElementArrayAPPLE Wm3glDrawElementArrayAPPLE = 0;
pfn_glDrawRangeElementArrayAPPLE Wm3glDrawRangeElementArrayAPPLE = 0;
pfn_glMultiDrawElementArrayAPPLE Wm3glMultiDrawElementArrayAPPLE = 0;
pfn_glMultiDrawRangeElementArrayAPPLE Wm3glMultiDrawRangeElementArrayAPPLE = 0;

static void Init_GL_APPLE_element_array ()
{
    Wm3NumFunctions_GL_APPLE_element_array = 0;

    Wm3glElementPointerAPPLE = (pfn_glElementPointerAPPLE)GetFunctionPointer("glElementPointerAPPLE");
    if ( Wm3glElementPointerAPPLE )
        ++Wm3NumFunctions_GL_APPLE_element_array;

    Wm3glDrawElementArrayAPPLE = (pfn_glDrawElementArrayAPPLE)GetFunctionPointer("glDrawElementArrayAPPLE");
    if ( Wm3glDrawElementArrayAPPLE )
        ++Wm3NumFunctions_GL_APPLE_element_array;

    Wm3glDrawRangeElementArrayAPPLE = (pfn_glDrawRangeElementArrayAPPLE)GetFunctionPointer("glDrawRangeElementArrayAPPLE");
    if ( Wm3glDrawRangeElementArrayAPPLE )
        ++Wm3NumFunctions_GL_APPLE_element_array;

    Wm3glMultiDrawElementArrayAPPLE = (pfn_glMultiDrawElementArrayAPPLE)GetFunctionPointer("glMultiDrawElementArrayAPPLE");
    if ( Wm3glMultiDrawElementArrayAPPLE )
        ++Wm3NumFunctions_GL_APPLE_element_array;

    Wm3glMultiDrawRangeElementArrayAPPLE = (pfn_glMultiDrawRangeElementArrayAPPLE)GetFunctionPointer("glMultiDrawRangeElementArrayAPPLE");
    if ( Wm3glMultiDrawRangeElementArrayAPPLE )
        ++Wm3NumFunctions_GL_APPLE_element_array;

    if ( Wm3NumFunctions_GL_APPLE_element_array == 5 )
        Wm3Exists_GL_APPLE_element_array = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_APPLE_element_array = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_APPLE_element_array ()
{
    Wm3NumFunctions_GL_APPLE_element_array = 0;
    Wm3Exists_GL_APPLE_element_array = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_APPLE_fence;
int Wm3NumFunctions_GL_APPLE_fence;
#ifdef WM3_DEFINED_GL_APPLE_fence
pfn_glGenFencesAPPLE Wm3glGenFencesAPPLE = 0;
pfn_glDeleteFencesAPPLE Wm3glDeleteFencesAPPLE = 0;
pfn_glSetFenceAPPLE Wm3glSetFenceAPPLE = 0;
pfn_glIsFenceAPPLE Wm3glIsFenceAPPLE = 0;
pfn_glTestFenceAPPLE Wm3glTestFenceAPPLE = 0;
pfn_glFinishFenceAPPLE Wm3glFinishFenceAPPLE = 0;
pfn_glTestObjectAPPLE Wm3glTestObjectAPPLE = 0;
pfn_glFinishObjectAPPLE Wm3glFinishObjectAPPLE = 0;

static void Init_GL_APPLE_fence ()
{
    Wm3NumFunctions_GL_APPLE_fence = 0;

    Wm3glGenFencesAPPLE = (pfn_glGenFencesAPPLE)GetFunctionPointer("glGenFencesAPPLE");
    if ( Wm3glGenFencesAPPLE )
        ++Wm3NumFunctions_GL_APPLE_fence;

    Wm3glDeleteFencesAPPLE = (pfn_glDeleteFencesAPPLE)GetFunctionPointer("glDeleteFencesAPPLE");
    if ( Wm3glDeleteFencesAPPLE )
        ++Wm3NumFunctions_GL_APPLE_fence;

    Wm3glSetFenceAPPLE = (pfn_glSetFenceAPPLE)GetFunctionPointer("glSetFenceAPPLE");
    if ( Wm3glSetFenceAPPLE )
        ++Wm3NumFunctions_GL_APPLE_fence;

    Wm3glIsFenceAPPLE = (pfn_glIsFenceAPPLE)GetFunctionPointer("glIsFenceAPPLE");
    if ( Wm3glIsFenceAPPLE )
        ++Wm3NumFunctions_GL_APPLE_fence;

    Wm3glTestFenceAPPLE = (pfn_glTestFenceAPPLE)GetFunctionPointer("glTestFenceAPPLE");
    if ( Wm3glTestFenceAPPLE )
        ++Wm3NumFunctions_GL_APPLE_fence;

    Wm3glFinishFenceAPPLE = (pfn_glFinishFenceAPPLE)GetFunctionPointer("glFinishFenceAPPLE");
    if ( Wm3glFinishFenceAPPLE )
        ++Wm3NumFunctions_GL_APPLE_fence;

    Wm3glTestObjectAPPLE = (pfn_glTestObjectAPPLE)GetFunctionPointer("glTestObjectAPPLE");
    if ( Wm3glTestObjectAPPLE )
        ++Wm3NumFunctions_GL_APPLE_fence;

    Wm3glFinishObjectAPPLE = (pfn_glFinishObjectAPPLE)GetFunctionPointer("glFinishObjectAPPLE");
    if ( Wm3glFinishObjectAPPLE )
        ++Wm3NumFunctions_GL_APPLE_fence;

    if ( Wm3NumFunctions_GL_APPLE_fence == 8 )
        Wm3Exists_GL_APPLE_fence = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_APPLE_fence = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_APPLE_fence ()
{
    Wm3NumFunctions_GL_APPLE_fence = 0;
    Wm3Exists_GL_APPLE_fence = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_APPLE_vertex_array_object;
int Wm3NumFunctions_GL_APPLE_vertex_array_object;
#ifdef WM3_DEFINED_GL_APPLE_vertex_array_object
pfn_glBindVertexArrayAPPLE Wm3glBindVertexArrayAPPLE = 0;
pfn_glDeleteVertexArraysAPPLE Wm3glDeleteVertexArraysAPPLE = 0;
pfn_glGenVertexArraysAPPLE Wm3glGenVertexArraysAPPLE = 0;
pfn_glIsVertexArrayAPPLE Wm3glIsVertexArrayAPPLE = 0;

static void Init_GL_APPLE_vertex_array_object ()
{
    Wm3NumFunctions_GL_APPLE_vertex_array_object = 0;

    Wm3glBindVertexArrayAPPLE = (pfn_glBindVertexArrayAPPLE)GetFunctionPointer("glBindVertexArrayAPPLE");
    if ( Wm3glBindVertexArrayAPPLE )
        ++Wm3NumFunctions_GL_APPLE_vertex_array_object;

    Wm3glDeleteVertexArraysAPPLE = (pfn_glDeleteVertexArraysAPPLE)GetFunctionPointer("glDeleteVertexArraysAPPLE");
    if ( Wm3glDeleteVertexArraysAPPLE )
        ++Wm3NumFunctions_GL_APPLE_vertex_array_object;

    Wm3glGenVertexArraysAPPLE = (pfn_glGenVertexArraysAPPLE)GetFunctionPointer("glGenVertexArraysAPPLE");
    if ( Wm3glGenVertexArraysAPPLE )
        ++Wm3NumFunctions_GL_APPLE_vertex_array_object;

    Wm3glIsVertexArrayAPPLE = (pfn_glIsVertexArrayAPPLE)GetFunctionPointer("glIsVertexArrayAPPLE");
    if ( Wm3glIsVertexArrayAPPLE )
        ++Wm3NumFunctions_GL_APPLE_vertex_array_object;

    if ( Wm3NumFunctions_GL_APPLE_vertex_array_object == 4 )
        Wm3Exists_GL_APPLE_vertex_array_object = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_APPLE_vertex_array_object = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_APPLE_vertex_array_object ()
{
    Wm3NumFunctions_GL_APPLE_vertex_array_object = 0;
    Wm3Exists_GL_APPLE_vertex_array_object = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_APPLE_vertex_array_range;
int Wm3NumFunctions_GL_APPLE_vertex_array_range;
#ifdef WM3_DEFINED_GL_APPLE_vertex_array_range
pfn_glVertexArrayRangeAPPLE Wm3glVertexArrayRangeAPPLE = 0;
pfn_glFlushVertexArrayRangeAPPLE Wm3glFlushVertexArrayRangeAPPLE = 0;
pfn_glVertexArrayParameteriAPPLE Wm3glVertexArrayParameteriAPPLE = 0;

static void Init_GL_APPLE_vertex_array_range ()
{
    Wm3NumFunctions_GL_APPLE_vertex_array_range = 0;

    Wm3glVertexArrayRangeAPPLE = (pfn_glVertexArrayRangeAPPLE)GetFunctionPointer("glVertexArrayRangeAPPLE");
    if ( Wm3glVertexArrayRangeAPPLE )
        ++Wm3NumFunctions_GL_APPLE_vertex_array_range;

    Wm3glFlushVertexArrayRangeAPPLE = (pfn_glFlushVertexArrayRangeAPPLE)GetFunctionPointer("glFlushVertexArrayRangeAPPLE");
    if ( Wm3glFlushVertexArrayRangeAPPLE )
        ++Wm3NumFunctions_GL_APPLE_vertex_array_range;

    Wm3glVertexArrayParameteriAPPLE = (pfn_glVertexArrayParameteriAPPLE)GetFunctionPointer("glVertexArrayParameteriAPPLE");
    if ( Wm3glVertexArrayParameteriAPPLE )
        ++Wm3NumFunctions_GL_APPLE_vertex_array_range;

    if ( Wm3NumFunctions_GL_APPLE_vertex_array_range == 3 )
        Wm3Exists_GL_APPLE_vertex_array_range = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_APPLE_vertex_array_range = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_APPLE_vertex_array_range ()
{
    Wm3NumFunctions_GL_APPLE_vertex_array_range = 0;
    Wm3Exists_GL_APPLE_vertex_array_range = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_APPLE_ycbcr_422;
int Wm3NumFunctions_GL_APPLE_ycbcr_422;
#ifdef WM3_DEFINED_GL_APPLE_ycbcr_422
static void Init_GL_APPLE_ycbcr_422 ()
{
    Wm3NumFunctions_GL_APPLE_ycbcr_422 = 0;
    Wm3Exists_GL_APPLE_ycbcr_422 = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_APPLE_ycbcr_422 ()
{
    Wm3NumFunctions_GL_APPLE_ycbcr_422 = 0;
    Wm3Exists_GL_APPLE_ycbcr_422 = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_S3_s3tc;
int Wm3NumFunctions_GL_S3_s3tc;
#ifdef WM3_DEFINED_GL_S3_s3tc
static void Init_GL_S3_s3tc ()
{
    Wm3NumFunctions_GL_S3_s3tc = 0;
    Wm3Exists_GL_S3_s3tc = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_S3_s3tc ()
{
    Wm3NumFunctions_GL_S3_s3tc = 0;
    Wm3Exists_GL_S3_s3tc = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_ATI_draw_buffers;
int Wm3NumFunctions_GL_ATI_draw_buffers;
#ifdef WM3_DEFINED_GL_ATI_draw_buffers
pfn_glDrawBuffersATI Wm3glDrawBuffersATI = 0;

static void Init_GL_ATI_draw_buffers ()
{
    Wm3NumFunctions_GL_ATI_draw_buffers = 0;

    Wm3glDrawBuffersATI = (pfn_glDrawBuffersATI)GetFunctionPointer("glDrawBuffersATI");
    if ( Wm3glDrawBuffersATI )
        ++Wm3NumFunctions_GL_ATI_draw_buffers;

    if ( Wm3NumFunctions_GL_ATI_draw_buffers == 1 )
        Wm3Exists_GL_ATI_draw_buffers = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_ATI_draw_buffers = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_ATI_draw_buffers ()
{
    Wm3NumFunctions_GL_ATI_draw_buffers = 0;
    Wm3Exists_GL_ATI_draw_buffers = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_ATI_pixel_format_float;
int Wm3NumFunctions_GL_ATI_pixel_format_float;
#ifdef WM3_DEFINED_GL_ATI_pixel_format_float
static void Init_GL_ATI_pixel_format_float ()
{
    Wm3NumFunctions_GL_ATI_pixel_format_float = 0;
    Wm3Exists_GL_ATI_pixel_format_float = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_ATI_pixel_format_float ()
{
    Wm3NumFunctions_GL_ATI_pixel_format_float = 0;
    Wm3Exists_GL_ATI_pixel_format_float = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_ATI_texture_env_combine3;
int Wm3NumFunctions_GL_ATI_texture_env_combine3;
#ifdef WM3_DEFINED_GL_ATI_texture_env_combine3
static void Init_GL_ATI_texture_env_combine3 ()
{
    Wm3NumFunctions_GL_ATI_texture_env_combine3 = 0;
    Wm3Exists_GL_ATI_texture_env_combine3 = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_ATI_texture_env_combine3 ()
{
    Wm3NumFunctions_GL_ATI_texture_env_combine3 = 0;
    Wm3Exists_GL_ATI_texture_env_combine3 = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_ATI_texture_float;
int Wm3NumFunctions_GL_ATI_texture_float;
#ifdef WM3_DEFINED_GL_ATI_texture_float
static void Init_GL_ATI_texture_float ()
{
    Wm3NumFunctions_GL_ATI_texture_float = 0;
    Wm3Exists_GL_ATI_texture_float = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_ATI_texture_float ()
{
    Wm3NumFunctions_GL_ATI_texture_float = 0;
    Wm3Exists_GL_ATI_texture_float = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_NV_float_buffer;
int Wm3NumFunctions_GL_NV_float_buffer;
#ifdef WM3_DEFINED_GL_NV_float_buffer
static void Init_GL_NV_float_buffer ()
{
    Wm3NumFunctions_GL_NV_float_buffer = 0;
    Wm3Exists_GL_NV_float_buffer = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_NV_float_buffer ()
{
    Wm3NumFunctions_GL_NV_float_buffer = 0;
    Wm3Exists_GL_NV_float_buffer = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_NV_fragment_program;
int Wm3NumFunctions_GL_NV_fragment_program;
#ifdef WM3_DEFINED_GL_NV_fragment_program
pfn_glProgramNamedParameter4fNV Wm3glProgramNamedParameter4fNV = 0;
pfn_glProgramNamedParameter4dNV Wm3glProgramNamedParameter4dNV = 0;
pfn_glProgramNamedParameter4fvNV Wm3glProgramNamedParameter4fvNV = 0;
pfn_glProgramNamedParameter4dvNV Wm3glProgramNamedParameter4dvNV = 0;
pfn_glGetProgramNamedParameterfvNV Wm3glGetProgramNamedParameterfvNV = 0;
pfn_glGetProgramNamedParameterdvNV Wm3glGetProgramNamedParameterdvNV = 0;

static void Init_GL_NV_fragment_program ()
{
    Wm3NumFunctions_GL_NV_fragment_program = 0;

    Wm3glProgramNamedParameter4fNV = (pfn_glProgramNamedParameter4fNV)GetFunctionPointer("glProgramNamedParameter4fNV");
    if ( Wm3glProgramNamedParameter4fNV )
        ++Wm3NumFunctions_GL_NV_fragment_program;

    Wm3glProgramNamedParameter4dNV = (pfn_glProgramNamedParameter4dNV)GetFunctionPointer("glProgramNamedParameter4dNV");
    if ( Wm3glProgramNamedParameter4dNV )
        ++Wm3NumFunctions_GL_NV_fragment_program;

    Wm3glProgramNamedParameter4fvNV = (pfn_glProgramNamedParameter4fvNV)GetFunctionPointer("glProgramNamedParameter4fvNV");
    if ( Wm3glProgramNamedParameter4fvNV )
        ++Wm3NumFunctions_GL_NV_fragment_program;

    Wm3glProgramNamedParameter4dvNV = (pfn_glProgramNamedParameter4dvNV)GetFunctionPointer("glProgramNamedParameter4dvNV");
    if ( Wm3glProgramNamedParameter4dvNV )
        ++Wm3NumFunctions_GL_NV_fragment_program;

    Wm3glGetProgramNamedParameterfvNV = (pfn_glGetProgramNamedParameterfvNV)GetFunctionPointer("glGetProgramNamedParameterfvNV");
    if ( Wm3glGetProgramNamedParameterfvNV )
        ++Wm3NumFunctions_GL_NV_fragment_program;

    Wm3glGetProgramNamedParameterdvNV = (pfn_glGetProgramNamedParameterdvNV)GetFunctionPointer("glGetProgramNamedParameterdvNV");
    if ( Wm3glGetProgramNamedParameterdvNV )
        ++Wm3NumFunctions_GL_NV_fragment_program;

    if ( Wm3NumFunctions_GL_NV_fragment_program == 6 )
        Wm3Exists_GL_NV_fragment_program = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_NV_fragment_program = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_NV_fragment_program ()
{
    Wm3NumFunctions_GL_NV_fragment_program = 0;
    Wm3Exists_GL_NV_fragment_program = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_NV_half_float;
int Wm3NumFunctions_GL_NV_half_float;
#ifdef WM3_DEFINED_GL_NV_half_float
pfn_glVertex2hNV Wm3glVertex2hNV = 0;
pfn_glVertex2hvNV Wm3glVertex2hvNV = 0;
pfn_glVertex3hNV Wm3glVertex3hNV = 0;
pfn_glVertex3hvNV Wm3glVertex3hvNV = 0;
pfn_glVertex4hNV Wm3glVertex4hNV = 0;
pfn_glVertex4hvNV Wm3glVertex4hvNV = 0;
pfn_glNormal3hNV Wm3glNormal3hNV = 0;
pfn_glNormal3hvNV Wm3glNormal3hvNV = 0;
pfn_glColor3hNV Wm3glColor3hNV = 0;
pfn_glColor3hvNV Wm3glColor3hvNV = 0;
pfn_glColor4hNV Wm3glColor4hNV = 0;
pfn_glColor4hvNV Wm3glColor4hvNV = 0;
pfn_glTexCoord1hNV Wm3glTexCoord1hNV = 0;
pfn_glTexCoord1hvNV Wm3glTexCoord1hvNV = 0;
pfn_glTexCoord2hNV Wm3glTexCoord2hNV = 0;
pfn_glTexCoord2hvNV Wm3glTexCoord2hvNV = 0;
pfn_glTexCoord3hNV Wm3glTexCoord3hNV = 0;
pfn_glTexCoord3hvNV Wm3glTexCoord3hvNV = 0;
pfn_glTexCoord4hNV Wm3glTexCoord4hNV = 0;
pfn_glTexCoord4hvNV Wm3glTexCoord4hvNV = 0;
pfn_glMultiTexCoord1hNV Wm3glMultiTexCoord1hNV = 0;
pfn_glMultiTexCoord1hvNV Wm3glMultiTexCoord1hvNV = 0;
pfn_glMultiTexCoord2hNV Wm3glMultiTexCoord2hNV = 0;
pfn_glMultiTexCoord2hvNV Wm3glMultiTexCoord2hvNV = 0;
pfn_glMultiTexCoord3hNV Wm3glMultiTexCoord3hNV = 0;
pfn_glMultiTexCoord3hvNV Wm3glMultiTexCoord3hvNV = 0;
pfn_glMultiTexCoord4hNV Wm3glMultiTexCoord4hNV = 0;
pfn_glMultiTexCoord4hvNV Wm3glMultiTexCoord4hvNV = 0;
pfn_glFogCoordhNV Wm3glFogCoordhNV = 0;
pfn_glFogCoordhvNV Wm3glFogCoordhvNV = 0;
pfn_glSecondaryColor3hNV Wm3glSecondaryColor3hNV = 0;
pfn_glSecondaryColor3hvNV Wm3glSecondaryColor3hvNV = 0;
pfn_glVertexWeighthNV Wm3glVertexWeighthNV = 0;
pfn_glVertexWeighthvNV Wm3glVertexWeighthvNV = 0;
pfn_glVertexAttrib1hNV Wm3glVertexAttrib1hNV = 0;
pfn_glVertexAttrib1hvNV Wm3glVertexAttrib1hvNV = 0;
pfn_glVertexAttrib2hNV Wm3glVertexAttrib2hNV = 0;
pfn_glVertexAttrib2hvNV Wm3glVertexAttrib2hvNV = 0;
pfn_glVertexAttrib3hNV Wm3glVertexAttrib3hNV = 0;
pfn_glVertexAttrib3hvNV Wm3glVertexAttrib3hvNV = 0;
pfn_glVertexAttrib4hNV Wm3glVertexAttrib4hNV = 0;
pfn_glVertexAttrib4hvNV Wm3glVertexAttrib4hvNV = 0;
pfn_glVertexAttribs1hvNV Wm3glVertexAttribs1hvNV = 0;
pfn_glVertexAttribs2hvNV Wm3glVertexAttribs2hvNV = 0;
pfn_glVertexAttribs3hvNV Wm3glVertexAttribs3hvNV = 0;
pfn_glVertexAttribs4hvNV Wm3glVertexAttribs4hvNV = 0;

static void Init_GL_NV_half_float ()
{
    Wm3NumFunctions_GL_NV_half_float = 0;

    Wm3glVertex2hNV = (pfn_glVertex2hNV)GetFunctionPointer("glVertex2hNV");
    if ( Wm3glVertex2hNV )
        ++Wm3NumFunctions_GL_NV_half_float;

    Wm3glVertex2hvNV = (pfn_glVertex2hvNV)GetFunctionPointer("glVertex2hvNV");
    if ( Wm3glVertex2hvNV )
        ++Wm3NumFunctions_GL_NV_half_float;

    Wm3glVertex3hNV = (pfn_glVertex3hNV)GetFunctionPointer("glVertex3hNV");
    if ( Wm3glVertex3hNV )
        ++Wm3NumFunctions_GL_NV_half_float;

    Wm3glVertex3hvNV = (pfn_glVertex3hvNV)GetFunctionPointer("glVertex3hvNV");
    if ( Wm3glVertex3hvNV )
        ++Wm3NumFunctions_GL_NV_half_float;

    Wm3glVertex4hNV = (pfn_glVertex4hNV)GetFunctionPointer("glVertex4hNV");
    if ( Wm3glVertex4hNV )
        ++Wm3NumFunctions_GL_NV_half_float;

    Wm3glVertex4hvNV = (pfn_glVertex4hvNV)GetFunctionPointer("glVertex4hvNV");
    if ( Wm3glVertex4hvNV )
        ++Wm3NumFunctions_GL_NV_half_float;

    Wm3glNormal3hNV = (pfn_glNormal3hNV)GetFunctionPointer("glNormal3hNV");
    if ( Wm3glNormal3hNV )
        ++Wm3NumFunctions_GL_NV_half_float;

    Wm3glNormal3hvNV = (pfn_glNormal3hvNV)GetFunctionPointer("glNormal3hvNV");
    if ( Wm3glNormal3hvNV )
        ++Wm3NumFunctions_GL_NV_half_float;

    Wm3glColor3hNV = (pfn_glColor3hNV)GetFunctionPointer("glColor3hNV");
    if ( Wm3glColor3hNV )
        ++Wm3NumFunctions_GL_NV_half_float;

    Wm3glColor3hvNV = (pfn_glColor3hvNV)GetFunctionPointer("glColor3hvNV");
    if ( Wm3glColor3hvNV )
        ++Wm3NumFunctions_GL_NV_half_float;

    Wm3glColor4hNV = (pfn_glColor4hNV)GetFunctionPointer("glColor4hNV");
    if ( Wm3glColor4hNV )
        ++Wm3NumFunctions_GL_NV_half_float;

    Wm3glColor4hvNV = (pfn_glColor4hvNV)GetFunctionPointer("glColor4hvNV");
    if ( Wm3glColor4hvNV )
        ++Wm3NumFunctions_GL_NV_half_float;

    Wm3glTexCoord1hNV = (pfn_glTexCoord1hNV)GetFunctionPointer("glTexCoord1hNV");
    if ( Wm3glTexCoord1hNV )
        ++Wm3NumFunctions_GL_NV_half_float;

    Wm3glTexCoord1hvNV = (pfn_glTexCoord1hvNV)GetFunctionPointer("glTexCoord1hvNV");
    if ( Wm3glTexCoord1hvNV )
        ++Wm3NumFunctions_GL_NV_half_float;

    Wm3glTexCoord2hNV = (pfn_glTexCoord2hNV)GetFunctionPointer("glTexCoord2hNV");
    if ( Wm3glTexCoord2hNV )
        ++Wm3NumFunctions_GL_NV_half_float;

    Wm3glTexCoord2hvNV = (pfn_glTexCoord2hvNV)GetFunctionPointer("glTexCoord2hvNV");
    if ( Wm3glTexCoord2hvNV )
        ++Wm3NumFunctions_GL_NV_half_float;

    Wm3glTexCoord3hNV = (pfn_glTexCoord3hNV)GetFunctionPointer("glTexCoord3hNV");
    if ( Wm3glTexCoord3hNV )
        ++Wm3NumFunctions_GL_NV_half_float;

    Wm3glTexCoord3hvNV = (pfn_glTexCoord3hvNV)GetFunctionPointer("glTexCoord3hvNV");
    if ( Wm3glTexCoord3hvNV )
        ++Wm3NumFunctions_GL_NV_half_float;

    Wm3glTexCoord4hNV = (pfn_glTexCoord4hNV)GetFunctionPointer("glTexCoord4hNV");
    if ( Wm3glTexCoord4hNV )
        ++Wm3NumFunctions_GL_NV_half_float;

    Wm3glTexCoord4hvNV = (pfn_glTexCoord4hvNV)GetFunctionPointer("glTexCoord4hvNV");
    if ( Wm3glTexCoord4hvNV )
        ++Wm3NumFunctions_GL_NV_half_float;

    Wm3glMultiTexCoord1hNV = (pfn_glMultiTexCoord1hNV)GetFunctionPointer("glMultiTexCoord1hNV");
    if ( Wm3glMultiTexCoord1hNV )
        ++Wm3NumFunctions_GL_NV_half_float;

    Wm3glMultiTexCoord1hvNV = (pfn_glMultiTexCoord1hvNV)GetFunctionPointer("glMultiTexCoord1hvNV");
    if ( Wm3glMultiTexCoord1hvNV )
        ++Wm3NumFunctions_GL_NV_half_float;

    Wm3glMultiTexCoord2hNV = (pfn_glMultiTexCoord2hNV)GetFunctionPointer("glMultiTexCoord2hNV");
    if ( Wm3glMultiTexCoord2hNV )
        ++Wm3NumFunctions_GL_NV_half_float;

    Wm3glMultiTexCoord2hvNV = (pfn_glMultiTexCoord2hvNV)GetFunctionPointer("glMultiTexCoord2hvNV");
    if ( Wm3glMultiTexCoord2hvNV )
        ++Wm3NumFunctions_GL_NV_half_float;

    Wm3glMultiTexCoord3hNV = (pfn_glMultiTexCoord3hNV)GetFunctionPointer("glMultiTexCoord3hNV");
    if ( Wm3glMultiTexCoord3hNV )
        ++Wm3NumFunctions_GL_NV_half_float;

    Wm3glMultiTexCoord3hvNV = (pfn_glMultiTexCoord3hvNV)GetFunctionPointer("glMultiTexCoord3hvNV");
    if ( Wm3glMultiTexCoord3hvNV )
        ++Wm3NumFunctions_GL_NV_half_float;

    Wm3glMultiTexCoord4hNV = (pfn_glMultiTexCoord4hNV)GetFunctionPointer("glMultiTexCoord4hNV");
    if ( Wm3glMultiTexCoord4hNV )
        ++Wm3NumFunctions_GL_NV_half_float;

    Wm3glMultiTexCoord4hvNV = (pfn_glMultiTexCoord4hvNV)GetFunctionPointer("glMultiTexCoord4hvNV");
    if ( Wm3glMultiTexCoord4hvNV )
        ++Wm3NumFunctions_GL_NV_half_float;

    Wm3glFogCoordhNV = (pfn_glFogCoordhNV)GetFunctionPointer("glFogCoordhNV");
    if ( Wm3glFogCoordhNV )
        ++Wm3NumFunctions_GL_NV_half_float;

    Wm3glFogCoordhvNV = (pfn_glFogCoordhvNV)GetFunctionPointer("glFogCoordhvNV");
    if ( Wm3glFogCoordhvNV )
        ++Wm3NumFunctions_GL_NV_half_float;

    Wm3glSecondaryColor3hNV = (pfn_glSecondaryColor3hNV)GetFunctionPointer("glSecondaryColor3hNV");
    if ( Wm3glSecondaryColor3hNV )
        ++Wm3NumFunctions_GL_NV_half_float;

    Wm3glSecondaryColor3hvNV = (pfn_glSecondaryColor3hvNV)GetFunctionPointer("glSecondaryColor3hvNV");
    if ( Wm3glSecondaryColor3hvNV )
        ++Wm3NumFunctions_GL_NV_half_float;

    Wm3glVertexWeighthNV = (pfn_glVertexWeighthNV)GetFunctionPointer("glVertexWeighthNV");
    if ( Wm3glVertexWeighthNV )
        ++Wm3NumFunctions_GL_NV_half_float;

    Wm3glVertexWeighthvNV = (pfn_glVertexWeighthvNV)GetFunctionPointer("glVertexWeighthvNV");
    if ( Wm3glVertexWeighthvNV )
        ++Wm3NumFunctions_GL_NV_half_float;

    Wm3glVertexAttrib1hNV = (pfn_glVertexAttrib1hNV)GetFunctionPointer("glVertexAttrib1hNV");
    if ( Wm3glVertexAttrib1hNV )
        ++Wm3NumFunctions_GL_NV_half_float;

    Wm3glVertexAttrib1hvNV = (pfn_glVertexAttrib1hvNV)GetFunctionPointer("glVertexAttrib1hvNV");
    if ( Wm3glVertexAttrib1hvNV )
        ++Wm3NumFunctions_GL_NV_half_float;

    Wm3glVertexAttrib2hNV = (pfn_glVertexAttrib2hNV)GetFunctionPointer("glVertexAttrib2hNV");
    if ( Wm3glVertexAttrib2hNV )
        ++Wm3NumFunctions_GL_NV_half_float;

    Wm3glVertexAttrib2hvNV = (pfn_glVertexAttrib2hvNV)GetFunctionPointer("glVertexAttrib2hvNV");
    if ( Wm3glVertexAttrib2hvNV )
        ++Wm3NumFunctions_GL_NV_half_float;

    Wm3glVertexAttrib3hNV = (pfn_glVertexAttrib3hNV)GetFunctionPointer("glVertexAttrib3hNV");
    if ( Wm3glVertexAttrib3hNV )
        ++Wm3NumFunctions_GL_NV_half_float;

    Wm3glVertexAttrib3hvNV = (pfn_glVertexAttrib3hvNV)GetFunctionPointer("glVertexAttrib3hvNV");
    if ( Wm3glVertexAttrib3hvNV )
        ++Wm3NumFunctions_GL_NV_half_float;

    Wm3glVertexAttrib4hNV = (pfn_glVertexAttrib4hNV)GetFunctionPointer("glVertexAttrib4hNV");
    if ( Wm3glVertexAttrib4hNV )
        ++Wm3NumFunctions_GL_NV_half_float;

    Wm3glVertexAttrib4hvNV = (pfn_glVertexAttrib4hvNV)GetFunctionPointer("glVertexAttrib4hvNV");
    if ( Wm3glVertexAttrib4hvNV )
        ++Wm3NumFunctions_GL_NV_half_float;

    Wm3glVertexAttribs1hvNV = (pfn_glVertexAttribs1hvNV)GetFunctionPointer("glVertexAttribs1hvNV");
    if ( Wm3glVertexAttribs1hvNV )
        ++Wm3NumFunctions_GL_NV_half_float;

    Wm3glVertexAttribs2hvNV = (pfn_glVertexAttribs2hvNV)GetFunctionPointer("glVertexAttribs2hvNV");
    if ( Wm3glVertexAttribs2hvNV )
        ++Wm3NumFunctions_GL_NV_half_float;

    Wm3glVertexAttribs3hvNV = (pfn_glVertexAttribs3hvNV)GetFunctionPointer("glVertexAttribs3hvNV");
    if ( Wm3glVertexAttribs3hvNV )
        ++Wm3NumFunctions_GL_NV_half_float;

    Wm3glVertexAttribs4hvNV = (pfn_glVertexAttribs4hvNV)GetFunctionPointer("glVertexAttribs4hvNV");
    if ( Wm3glVertexAttribs4hvNV )
        ++Wm3NumFunctions_GL_NV_half_float;

    if ( Wm3NumFunctions_GL_NV_half_float == 46 )
        Wm3Exists_GL_NV_half_float = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_NV_half_float = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_NV_half_float ()
{
    Wm3NumFunctions_GL_NV_half_float = 0;
    Wm3Exists_GL_NV_half_float = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_NV_pixel_data_range;
int Wm3NumFunctions_GL_NV_pixel_data_range;
#ifdef WM3_DEFINED_GL_NV_pixel_data_range
pfn_glPixelDataRangeNV Wm3glPixelDataRangeNV = 0;
pfn_glFlushPixelDataRangeNV Wm3glFlushPixelDataRangeNV = 0;

static void Init_GL_NV_pixel_data_range ()
{
    Wm3NumFunctions_GL_NV_pixel_data_range = 0;

    Wm3glPixelDataRangeNV = (pfn_glPixelDataRangeNV)GetFunctionPointer("glPixelDataRangeNV");
    if ( Wm3glPixelDataRangeNV )
        ++Wm3NumFunctions_GL_NV_pixel_data_range;

    Wm3glFlushPixelDataRangeNV = (pfn_glFlushPixelDataRangeNV)GetFunctionPointer("glFlushPixelDataRangeNV");
    if ( Wm3glFlushPixelDataRangeNV )
        ++Wm3NumFunctions_GL_NV_pixel_data_range;

    if ( Wm3NumFunctions_GL_NV_pixel_data_range == 2 )
        Wm3Exists_GL_NV_pixel_data_range = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_NV_pixel_data_range = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_NV_pixel_data_range ()
{
    Wm3NumFunctions_GL_NV_pixel_data_range = 0;
    Wm3Exists_GL_NV_pixel_data_range = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_NV_primitive_restart;
int Wm3NumFunctions_GL_NV_primitive_restart;
#ifdef WM3_DEFINED_GL_NV_primitive_restart
pfn_glPrimitiveRestartNV Wm3glPrimitiveRestartNV = 0;
pfn_glPrimitiveRestartIndexNV Wm3glPrimitiveRestartIndexNV = 0;

static void Init_GL_NV_primitive_restart ()
{
    Wm3NumFunctions_GL_NV_primitive_restart = 0;

    Wm3glPrimitiveRestartNV = (pfn_glPrimitiveRestartNV)GetFunctionPointer("glPrimitiveRestartNV");
    if ( Wm3glPrimitiveRestartNV )
        ++Wm3NumFunctions_GL_NV_primitive_restart;

    Wm3glPrimitiveRestartIndexNV = (pfn_glPrimitiveRestartIndexNV)GetFunctionPointer("glPrimitiveRestartIndexNV");
    if ( Wm3glPrimitiveRestartIndexNV )
        ++Wm3NumFunctions_GL_NV_primitive_restart;

    if ( Wm3NumFunctions_GL_NV_primitive_restart == 2 )
        Wm3Exists_GL_NV_primitive_restart = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_NV_primitive_restart = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_NV_primitive_restart ()
{
    Wm3NumFunctions_GL_NV_primitive_restart = 0;
    Wm3Exists_GL_NV_primitive_restart = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_NV_texture_expand_normal;
int Wm3NumFunctions_GL_NV_texture_expand_normal;
#ifdef WM3_DEFINED_GL_NV_texture_expand_normal
static void Init_GL_NV_texture_expand_normal ()
{
    Wm3NumFunctions_GL_NV_texture_expand_normal = 0;
    Wm3Exists_GL_NV_texture_expand_normal = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_NV_texture_expand_normal ()
{
    Wm3NumFunctions_GL_NV_texture_expand_normal = 0;
    Wm3Exists_GL_NV_texture_expand_normal = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_NV_vertex_program2;
int Wm3NumFunctions_GL_NV_vertex_program2;
#ifdef WM3_DEFINED_GL_NV_vertex_program2
static void Init_GL_NV_vertex_program2 ()
{
    Wm3NumFunctions_GL_NV_vertex_program2 = 0;
    Wm3Exists_GL_NV_vertex_program2 = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_NV_vertex_program2 ()
{
    Wm3NumFunctions_GL_NV_vertex_program2 = 0;
    Wm3Exists_GL_NV_vertex_program2 = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_ATI_map_object_buffer;
int Wm3NumFunctions_GL_ATI_map_object_buffer;
#ifdef WM3_DEFINED_GL_ATI_map_object_buffer
pfn_glMapObjectBufferATI Wm3glMapObjectBufferATI = 0;
pfn_glUnmapObjectBufferATI Wm3glUnmapObjectBufferATI = 0;

static void Init_GL_ATI_map_object_buffer ()
{
    Wm3NumFunctions_GL_ATI_map_object_buffer = 0;

    Wm3glMapObjectBufferATI = (pfn_glMapObjectBufferATI)GetFunctionPointer("glMapObjectBufferATI");
    if ( Wm3glMapObjectBufferATI )
        ++Wm3NumFunctions_GL_ATI_map_object_buffer;

    Wm3glUnmapObjectBufferATI = (pfn_glUnmapObjectBufferATI)GetFunctionPointer("glUnmapObjectBufferATI");
    if ( Wm3glUnmapObjectBufferATI )
        ++Wm3NumFunctions_GL_ATI_map_object_buffer;

    if ( Wm3NumFunctions_GL_ATI_map_object_buffer == 2 )
        Wm3Exists_GL_ATI_map_object_buffer = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_ATI_map_object_buffer = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_ATI_map_object_buffer ()
{
    Wm3NumFunctions_GL_ATI_map_object_buffer = 0;
    Wm3Exists_GL_ATI_map_object_buffer = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_ATI_separate_stencil;
int Wm3NumFunctions_GL_ATI_separate_stencil;
#ifdef WM3_DEFINED_GL_ATI_separate_stencil
pfn_glStencilOpSeparateATI Wm3glStencilOpSeparateATI = 0;
pfn_glStencilFuncSeparateATI Wm3glStencilFuncSeparateATI = 0;

static void Init_GL_ATI_separate_stencil ()
{
    Wm3NumFunctions_GL_ATI_separate_stencil = 0;

    Wm3glStencilOpSeparateATI = (pfn_glStencilOpSeparateATI)GetFunctionPointer("glStencilOpSeparateATI");
    if ( Wm3glStencilOpSeparateATI )
        ++Wm3NumFunctions_GL_ATI_separate_stencil;

    Wm3glStencilFuncSeparateATI = (pfn_glStencilFuncSeparateATI)GetFunctionPointer("glStencilFuncSeparateATI");
    if ( Wm3glStencilFuncSeparateATI )
        ++Wm3NumFunctions_GL_ATI_separate_stencil;

    if ( Wm3NumFunctions_GL_ATI_separate_stencil == 2 )
        Wm3Exists_GL_ATI_separate_stencil = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_ATI_separate_stencil = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_ATI_separate_stencil ()
{
    Wm3NumFunctions_GL_ATI_separate_stencil = 0;
    Wm3Exists_GL_ATI_separate_stencil = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_ATI_vertex_attrib_array_object;
int Wm3NumFunctions_GL_ATI_vertex_attrib_array_object;
#ifdef WM3_DEFINED_GL_ATI_vertex_attrib_array_object
pfn_glVertexAttribArrayObjectATI Wm3glVertexAttribArrayObjectATI = 0;
pfn_glGetVertexAttribArrayObjectfvATI Wm3glGetVertexAttribArrayObjectfvATI = 0;
pfn_glGetVertexAttribArrayObjectivATI Wm3glGetVertexAttribArrayObjectivATI = 0;

static void Init_GL_ATI_vertex_attrib_array_object ()
{
    Wm3NumFunctions_GL_ATI_vertex_attrib_array_object = 0;

    Wm3glVertexAttribArrayObjectATI = (pfn_glVertexAttribArrayObjectATI)GetFunctionPointer("glVertexAttribArrayObjectATI");
    if ( Wm3glVertexAttribArrayObjectATI )
        ++Wm3NumFunctions_GL_ATI_vertex_attrib_array_object;

    Wm3glGetVertexAttribArrayObjectfvATI = (pfn_glGetVertexAttribArrayObjectfvATI)GetFunctionPointer("glGetVertexAttribArrayObjectfvATI");
    if ( Wm3glGetVertexAttribArrayObjectfvATI )
        ++Wm3NumFunctions_GL_ATI_vertex_attrib_array_object;

    Wm3glGetVertexAttribArrayObjectivATI = (pfn_glGetVertexAttribArrayObjectivATI)GetFunctionPointer("glGetVertexAttribArrayObjectivATI");
    if ( Wm3glGetVertexAttribArrayObjectivATI )
        ++Wm3NumFunctions_GL_ATI_vertex_attrib_array_object;

    if ( Wm3NumFunctions_GL_ATI_vertex_attrib_array_object == 3 )
        Wm3Exists_GL_ATI_vertex_attrib_array_object = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_ATI_vertex_attrib_array_object = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_ATI_vertex_attrib_array_object ()
{
    Wm3NumFunctions_GL_ATI_vertex_attrib_array_object = 0;
    Wm3Exists_GL_ATI_vertex_attrib_array_object = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_OES_read_format;
int Wm3NumFunctions_GL_OES_read_format;
#ifdef WM3_DEFINED_GL_OES_read_format
static void Init_GL_OES_read_format ()
{
    Wm3NumFunctions_GL_OES_read_format = 0;
    Wm3Exists_GL_OES_read_format = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_OES_read_format ()
{
    Wm3NumFunctions_GL_OES_read_format = 0;
    Wm3Exists_GL_OES_read_format = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_EXT_depth_bounds_test;
int Wm3NumFunctions_GL_EXT_depth_bounds_test;
#ifdef WM3_DEFINED_GL_EXT_depth_bounds_test
pfn_glDepthBoundsEXT Wm3glDepthBoundsEXT = 0;

static void Init_GL_EXT_depth_bounds_test ()
{
    Wm3NumFunctions_GL_EXT_depth_bounds_test = 0;

    Wm3glDepthBoundsEXT = (pfn_glDepthBoundsEXT)GetFunctionPointer("glDepthBoundsEXT");
    if ( Wm3glDepthBoundsEXT )
        ++Wm3NumFunctions_GL_EXT_depth_bounds_test;

    if ( Wm3NumFunctions_GL_EXT_depth_bounds_test == 1 )
        Wm3Exists_GL_EXT_depth_bounds_test = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_EXT_depth_bounds_test = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_EXT_depth_bounds_test ()
{
    Wm3NumFunctions_GL_EXT_depth_bounds_test = 0;
    Wm3Exists_GL_EXT_depth_bounds_test = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_EXT_texture_mirror_clamp;
int Wm3NumFunctions_GL_EXT_texture_mirror_clamp;
#ifdef WM3_DEFINED_GL_EXT_texture_mirror_clamp
static void Init_GL_EXT_texture_mirror_clamp ()
{
    Wm3NumFunctions_GL_EXT_texture_mirror_clamp = 0;
    Wm3Exists_GL_EXT_texture_mirror_clamp = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_EXT_texture_mirror_clamp ()
{
    Wm3NumFunctions_GL_EXT_texture_mirror_clamp = 0;
    Wm3Exists_GL_EXT_texture_mirror_clamp = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_EXT_blend_equation_separate;
int Wm3NumFunctions_GL_EXT_blend_equation_separate;
#ifdef WM3_DEFINED_GL_EXT_blend_equation_separate
pfn_glBlendEquationSeparateEXT Wm3glBlendEquationSeparateEXT = 0;

static void Init_GL_EXT_blend_equation_separate ()
{
    Wm3NumFunctions_GL_EXT_blend_equation_separate = 0;

    Wm3glBlendEquationSeparateEXT = (pfn_glBlendEquationSeparateEXT)GetFunctionPointer("glBlendEquationSeparateEXT");
    if ( Wm3glBlendEquationSeparateEXT )
        ++Wm3NumFunctions_GL_EXT_blend_equation_separate;

    if ( Wm3NumFunctions_GL_EXT_blend_equation_separate == 1 )
        Wm3Exists_GL_EXT_blend_equation_separate = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_EXT_blend_equation_separate = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_EXT_blend_equation_separate ()
{
    Wm3NumFunctions_GL_EXT_blend_equation_separate = 0;
    Wm3Exists_GL_EXT_blend_equation_separate = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_MESA_pack_invert;
int Wm3NumFunctions_GL_MESA_pack_invert;
#ifdef WM3_DEFINED_GL_MESA_pack_invert
static void Init_GL_MESA_pack_invert ()
{
    Wm3NumFunctions_GL_MESA_pack_invert = 0;
    Wm3Exists_GL_MESA_pack_invert = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_MESA_pack_invert ()
{
    Wm3NumFunctions_GL_MESA_pack_invert = 0;
    Wm3Exists_GL_MESA_pack_invert = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_MESA_ycbcr_texture;
int Wm3NumFunctions_GL_MESA_ycbcr_texture;
#ifdef WM3_DEFINED_GL_MESA_ycbcr_texture
static void Init_GL_MESA_ycbcr_texture ()
{
    Wm3NumFunctions_GL_MESA_ycbcr_texture = 0;
    Wm3Exists_GL_MESA_ycbcr_texture = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_MESA_ycbcr_texture ()
{
    Wm3NumFunctions_GL_MESA_ycbcr_texture = 0;
    Wm3Exists_GL_MESA_ycbcr_texture = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_EXT_pixel_buffer_object;
int Wm3NumFunctions_GL_EXT_pixel_buffer_object;
#ifdef WM3_DEFINED_GL_EXT_pixel_buffer_object
static void Init_GL_EXT_pixel_buffer_object ()
{
    Wm3NumFunctions_GL_EXT_pixel_buffer_object = 0;
    Wm3Exists_GL_EXT_pixel_buffer_object = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_EXT_pixel_buffer_object ()
{
    Wm3NumFunctions_GL_EXT_pixel_buffer_object = 0;
    Wm3Exists_GL_EXT_pixel_buffer_object = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_NV_fragment_program_option;
int Wm3NumFunctions_GL_NV_fragment_program_option;
#ifdef WM3_DEFINED_GL_NV_fragment_program_option
static void Init_GL_NV_fragment_program_option ()
{
    Wm3NumFunctions_GL_NV_fragment_program_option = 0;
    Wm3Exists_GL_NV_fragment_program_option = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_NV_fragment_program_option ()
{
    Wm3NumFunctions_GL_NV_fragment_program_option = 0;
    Wm3Exists_GL_NV_fragment_program_option = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_NV_fragment_program2;
int Wm3NumFunctions_GL_NV_fragment_program2;
#ifdef WM3_DEFINED_GL_NV_fragment_program2
static void Init_GL_NV_fragment_program2 ()
{
    Wm3NumFunctions_GL_NV_fragment_program2 = 0;
    Wm3Exists_GL_NV_fragment_program2 = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_NV_fragment_program2 ()
{
    Wm3NumFunctions_GL_NV_fragment_program2 = 0;
    Wm3Exists_GL_NV_fragment_program2 = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_NV_vertex_program2_option;
int Wm3NumFunctions_GL_NV_vertex_program2_option;
#ifdef WM3_DEFINED_GL_NV_vertex_program2_option
static void Init_GL_NV_vertex_program2_option ()
{
    Wm3NumFunctions_GL_NV_vertex_program2_option = 0;
    Wm3Exists_GL_NV_vertex_program2_option = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_NV_vertex_program2_option ()
{
    Wm3NumFunctions_GL_NV_vertex_program2_option = 0;
    Wm3Exists_GL_NV_vertex_program2_option = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_NV_vertex_program3;
int Wm3NumFunctions_GL_NV_vertex_program3;
#ifdef WM3_DEFINED_GL_NV_vertex_program3
static void Init_GL_NV_vertex_program3 ()
{
    Wm3NumFunctions_GL_NV_vertex_program3 = 0;
    Wm3Exists_GL_NV_vertex_program3 = WM3_EXT_FULLY_EXISTS;
}
#else
static void Init_GL_NV_vertex_program3 ()
{
    Wm3NumFunctions_GL_NV_vertex_program3 = 0;
    Wm3Exists_GL_NV_vertex_program3 = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_EXT_framebuffer_object;
int Wm3NumFunctions_GL_EXT_framebuffer_object;
#ifdef WM3_DEFINED_GL_EXT_framebuffer_object
pfn_glIsRenderbufferEXT Wm3glIsRenderbufferEXT = 0;
pfn_glBindRenderbufferEXT Wm3glBindRenderbufferEXT = 0;
pfn_glDeleteRenderbuffersEXT Wm3glDeleteRenderbuffersEXT = 0;
pfn_glGenRenderbuffersEXT Wm3glGenRenderbuffersEXT = 0;
pfn_glRenderbufferStorageEXT Wm3glRenderbufferStorageEXT = 0;
pfn_glGetRenderbufferParameterivEXT Wm3glGetRenderbufferParameterivEXT = 0;
pfn_glIsFramebufferEXT Wm3glIsFramebufferEXT = 0;
pfn_glBindFramebufferEXT Wm3glBindFramebufferEXT = 0;
pfn_glDeleteFramebuffersEXT Wm3glDeleteFramebuffersEXT = 0;
pfn_glGenFramebuffersEXT Wm3glGenFramebuffersEXT = 0;
pfn_glCheckFramebufferStatusEXT Wm3glCheckFramebufferStatusEXT = 0;
pfn_glFramebufferTexture1DEXT Wm3glFramebufferTexture1DEXT = 0;
pfn_glFramebufferTexture2DEXT Wm3glFramebufferTexture2DEXT = 0;
pfn_glFramebufferTexture3DEXT Wm3glFramebufferTexture3DEXT = 0;
pfn_glFramebufferRenderbufferEXT Wm3glFramebufferRenderbufferEXT = 0;
pfn_glGetFramebufferAttachmentParameterivEXT Wm3glGetFramebufferAttachmentParameterivEXT = 0;
pfn_glGenerateMipmapEXT Wm3glGenerateMipmapEXT = 0;

static void Init_GL_EXT_framebuffer_object ()
{
    Wm3NumFunctions_GL_EXT_framebuffer_object = 0;

    Wm3glIsRenderbufferEXT = (pfn_glIsRenderbufferEXT)GetFunctionPointer("glIsRenderbufferEXT");
    if ( Wm3glIsRenderbufferEXT )
        ++Wm3NumFunctions_GL_EXT_framebuffer_object;

    Wm3glBindRenderbufferEXT = (pfn_glBindRenderbufferEXT)GetFunctionPointer("glBindRenderbufferEXT");
    if ( Wm3glBindRenderbufferEXT )
        ++Wm3NumFunctions_GL_EXT_framebuffer_object;

    Wm3glDeleteRenderbuffersEXT = (pfn_glDeleteRenderbuffersEXT)GetFunctionPointer("glDeleteRenderbuffersEXT");
    if ( Wm3glDeleteRenderbuffersEXT )
        ++Wm3NumFunctions_GL_EXT_framebuffer_object;

    Wm3glGenRenderbuffersEXT = (pfn_glGenRenderbuffersEXT)GetFunctionPointer("glGenRenderbuffersEXT");
    if ( Wm3glGenRenderbuffersEXT )
        ++Wm3NumFunctions_GL_EXT_framebuffer_object;

    Wm3glRenderbufferStorageEXT = (pfn_glRenderbufferStorageEXT)GetFunctionPointer("glRenderbufferStorageEXT");
    if ( Wm3glRenderbufferStorageEXT )
        ++Wm3NumFunctions_GL_EXT_framebuffer_object;

    Wm3glGetRenderbufferParameterivEXT = (pfn_glGetRenderbufferParameterivEXT)GetFunctionPointer("glGetRenderbufferParameterivEXT");
    if ( Wm3glGetRenderbufferParameterivEXT )
        ++Wm3NumFunctions_GL_EXT_framebuffer_object;

    Wm3glIsFramebufferEXT = (pfn_glIsFramebufferEXT)GetFunctionPointer("glIsFramebufferEXT");
    if ( Wm3glIsFramebufferEXT )
        ++Wm3NumFunctions_GL_EXT_framebuffer_object;

    Wm3glBindFramebufferEXT = (pfn_glBindFramebufferEXT)GetFunctionPointer("glBindFramebufferEXT");
    if ( Wm3glBindFramebufferEXT )
        ++Wm3NumFunctions_GL_EXT_framebuffer_object;

    Wm3glDeleteFramebuffersEXT = (pfn_glDeleteFramebuffersEXT)GetFunctionPointer("glDeleteFramebuffersEXT");
    if ( Wm3glDeleteFramebuffersEXT )
        ++Wm3NumFunctions_GL_EXT_framebuffer_object;

    Wm3glGenFramebuffersEXT = (pfn_glGenFramebuffersEXT)GetFunctionPointer("glGenFramebuffersEXT");
    if ( Wm3glGenFramebuffersEXT )
        ++Wm3NumFunctions_GL_EXT_framebuffer_object;

    Wm3glCheckFramebufferStatusEXT = (pfn_glCheckFramebufferStatusEXT)GetFunctionPointer("glCheckFramebufferStatusEXT");
    if ( Wm3glCheckFramebufferStatusEXT )
        ++Wm3NumFunctions_GL_EXT_framebuffer_object;

    Wm3glFramebufferTexture1DEXT = (pfn_glFramebufferTexture1DEXT)GetFunctionPointer("glFramebufferTexture1DEXT");
    if ( Wm3glFramebufferTexture1DEXT )
        ++Wm3NumFunctions_GL_EXT_framebuffer_object;

    Wm3glFramebufferTexture2DEXT = (pfn_glFramebufferTexture2DEXT)GetFunctionPointer("glFramebufferTexture2DEXT");
    if ( Wm3glFramebufferTexture2DEXT )
        ++Wm3NumFunctions_GL_EXT_framebuffer_object;

    Wm3glFramebufferTexture3DEXT = (pfn_glFramebufferTexture3DEXT)GetFunctionPointer("glFramebufferTexture3DEXT");
    if ( Wm3glFramebufferTexture3DEXT )
        ++Wm3NumFunctions_GL_EXT_framebuffer_object;

    Wm3glFramebufferRenderbufferEXT = (pfn_glFramebufferRenderbufferEXT)GetFunctionPointer("glFramebufferRenderbufferEXT");
    if ( Wm3glFramebufferRenderbufferEXT )
        ++Wm3NumFunctions_GL_EXT_framebuffer_object;

    Wm3glGetFramebufferAttachmentParameterivEXT = (pfn_glGetFramebufferAttachmentParameterivEXT)GetFunctionPointer("glGetFramebufferAttachmentParameterivEXT");
    if ( Wm3glGetFramebufferAttachmentParameterivEXT )
        ++Wm3NumFunctions_GL_EXT_framebuffer_object;

    Wm3glGenerateMipmapEXT = (pfn_glGenerateMipmapEXT)GetFunctionPointer("glGenerateMipmapEXT");
    if ( Wm3glGenerateMipmapEXT )
        ++Wm3NumFunctions_GL_EXT_framebuffer_object;

    if ( Wm3NumFunctions_GL_EXT_framebuffer_object == 17 )
        Wm3Exists_GL_EXT_framebuffer_object = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_EXT_framebuffer_object = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_EXT_framebuffer_object ()
{
    Wm3NumFunctions_GL_EXT_framebuffer_object = 0;
    Wm3Exists_GL_EXT_framebuffer_object = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
int Wm3Exists_GL_GREMEDY_string_marker;
int Wm3NumFunctions_GL_GREMEDY_string_marker;
#ifdef WM3_DEFINED_GL_GREMEDY_string_marker
pfn_glStringMarkerGREMEDY Wm3glStringMarkerGREMEDY = 0;

static void Init_GL_GREMEDY_string_marker ()
{
    Wm3NumFunctions_GL_GREMEDY_string_marker = 0;

    Wm3glStringMarkerGREMEDY = (pfn_glStringMarkerGREMEDY)GetFunctionPointer("glStringMarkerGREMEDY");
    if ( Wm3glStringMarkerGREMEDY )
        ++Wm3NumFunctions_GL_GREMEDY_string_marker;

    if ( Wm3NumFunctions_GL_GREMEDY_string_marker == 1 )
        Wm3Exists_GL_GREMEDY_string_marker = WM3_EXT_FULLY_EXISTS;
    else
        Wm3Exists_GL_GREMEDY_string_marker = WM3_EXT_PARTIALLY_EXISTS;
}
#else
static void Init_GL_GREMEDY_string_marker ()
{
    Wm3NumFunctions_GL_GREMEDY_string_marker = 0;
    Wm3Exists_GL_GREMEDY_string_marker = WM3_EXT_DOES_NOT_EXIST;
}
#endif

/*--------------------------------------------------------------------------*/
void InitializeOpenGL ()
{
    Init_GL_VERSION_1_1();
    Init_GL_VERSION_1_2();
    Init_GL_VERSION_1_3();
    Init_GL_VERSION_1_4();
    Init_GL_VERSION_1_5();
    Init_GL_VERSION_2_0();
    Init_GL_ARB_imaging();
    Init_GL_ARB_multitexture();
    Init_GL_ARB_transpose_matrix();
    Init_GL_ARB_multisample();
    Init_GL_ARB_texture_env_add();
    Init_GL_ARB_texture_cube_map();
    Init_GL_ARB_texture_compression();
    Init_GL_ARB_texture_border_clamp();
    Init_GL_ARB_point_parameters();
    Init_GL_ARB_vertex_blend();
    Init_GL_ARB_matrix_palette();
    Init_GL_ARB_texture_env_combine();
    Init_GL_ARB_texture_env_crossbar();
    Init_GL_ARB_texture_env_dot3();
    Init_GL_ARB_texture_mirrored_repeat();
    Init_GL_ARB_depth_texture();
    Init_GL_ARB_shadow();
    Init_GL_ARB_shadow_ambient();
    Init_GL_ARB_window_pos();
    Init_GL_ARB_vertex_program();
    Init_GL_ARB_fragment_program();
    Init_GL_ARB_vertex_buffer_object();
    Init_GL_ARB_occlusion_query();
    Init_GL_ARB_shader_objects();
    Init_GL_ARB_vertex_shader();
    Init_GL_ARB_fragment_shader();
    Init_GL_ARB_shading_language_100();
    Init_GL_ARB_texture_non_power_of_two();
    Init_GL_ARB_point_sprite();
    Init_GL_ARB_fragment_program_shadow();
    Init_GL_ARB_draw_buffers();
    Init_GL_ARB_texture_rectangle();
    Init_GL_ARB_color_buffer_float();
    Init_GL_ARB_half_float_pixel();
    Init_GL_ARB_texture_float();
    Init_GL_ARB_pixel_buffer_object();
    Init_GL_EXT_abgr();
    Init_GL_EXT_blend_color();
    Init_GL_EXT_polygon_offset();
    Init_GL_EXT_texture();
    Init_GL_EXT_texture3D();
    Init_GL_SGIS_texture_filter4();
    Init_GL_EXT_subtexture();
    Init_GL_EXT_copy_texture();
    Init_GL_EXT_histogram();
    Init_GL_EXT_convolution();
    Init_GL_EXT_color_matrix();
    Init_GL_SGI_color_table();
    Init_GL_SGIX_pixel_texture();
    Init_GL_SGIS_pixel_texture();
    Init_GL_SGIS_texture4D();
    Init_GL_SGI_texture_color_table();
    Init_GL_EXT_cmyka();
    Init_GL_EXT_texture_object();
    Init_GL_SGIS_detail_texture();
    Init_GL_SGIS_sharpen_texture();
    Init_GL_EXT_packed_pixels();
    Init_GL_SGIS_texture_lod();
    Init_GL_SGIS_multisample();
    Init_GL_EXT_rescale_normal();
    Init_GL_EXT_vertex_array();
    Init_GL_EXT_misc_attribute();
    Init_GL_SGIS_generate_mipmap();
    Init_GL_SGIX_clipmap();
    Init_GL_SGIX_shadow();
    Init_GL_SGIS_texture_edge_clamp();
    Init_GL_SGIS_texture_border_clamp();
    Init_GL_EXT_blend_minmax();
    Init_GL_EXT_blend_subtract();
    Init_GL_EXT_blend_logic_op();
    Init_GL_SGIX_interlace();
    Init_GL_SGIX_pixel_tiles();
    Init_GL_SGIX_texture_select();
    Init_GL_SGIX_sprite();
    Init_GL_SGIX_texture_multi_buffer();
    Init_GL_EXT_point_parameters();
    Init_GL_SGIS_point_parameters();
    Init_GL_SGIX_instruments();
    Init_GL_SGIX_texture_scale_bias();
    Init_GL_SGIX_framezoom();
    Init_GL_SGIX_tag_sample_buffer();
    Init_GL_FfdMaskSGIX();
    Init_GL_SGIX_polynomial_ffd();
    Init_GL_SGIX_reference_plane();
    Init_GL_SGIX_flush_raster();
    Init_GL_SGIX_depth_texture();
    Init_GL_SGIS_fog_function();
    Init_GL_SGIX_fog_offset();
    Init_GL_HP_image_transform();
    Init_GL_HP_convolution_border_modes();
    Init_GL_INGR_palette_buffer();
    Init_GL_SGIX_texture_add_env();
    Init_GL_EXT_color_subtable();
    Init_GL_PGI_vertex_hints();
    Init_GL_PGI_misc_hints();
    Init_GL_EXT_paletted_texture();
    Init_GL_EXT_clip_volume_hint();
    Init_GL_SGIX_list_priority();
    Init_GL_SGIX_ir_instrument1();
    Init_GL_SGIX_calligraphic_fragment();
    Init_GL_SGIX_texture_lod_bias();
    Init_GL_SGIX_shadow_ambient();
    Init_GL_EXT_index_texture();
    Init_GL_EXT_index_material();
    Init_GL_EXT_index_func();
    Init_GL_EXT_index_array_formats();
    Init_GL_EXT_compiled_vertex_array();
    Init_GL_EXT_cull_vertex();
    Init_GL_SGIX_ycrcb();
    Init_GL_SGIX_fragment_lighting();
    Init_GL_IBM_rasterpos_clip();
    Init_GL_HP_texture_lighting();
    Init_GL_EXT_draw_range_elements();
    Init_GL_WIN_phong_shading();
    Init_GL_WIN_specular_fog();
    Init_GL_EXT_light_texture();
    Init_GL_SGIX_blend_alpha_minmax();
    Init_GL_SGIX_impact_pixel_texture();
    Init_GL_EXT_bgra();
    Init_GL_SGIX_async();
    Init_GL_SGIX_async_pixel();
    Init_GL_SGIX_async_histogram();
    Init_GL_INTEL_texture_scissor();
    Init_GL_INTEL_parallel_arrays();
    Init_GL_HP_occlusion_test();
    Init_GL_EXT_pixel_transform();
    Init_GL_EXT_pixel_transform_color_table();
    Init_GL_EXT_shared_texture_palette();
    Init_GL_EXT_separate_specular_color();
    Init_GL_EXT_secondary_color();
    Init_GL_EXT_texture_perturb_normal();
    Init_GL_EXT_multi_draw_arrays();
    Init_GL_EXT_fog_coord();
    Init_GL_REND_screen_coordinates();
    Init_GL_EXT_coordinate_frame();
    Init_GL_EXT_texture_env_combine();
    Init_GL_APPLE_specular_vector();
    Init_GL_APPLE_transform_hint();
    Init_GL_SGIX_fog_scale();
    Init_GL_SUNX_constant_data();
    Init_GL_SUN_global_alpha();
    Init_GL_SUN_triangle_list();
    Init_GL_SUN_vertex();
    Init_GL_EXT_blend_func_separate();
    Init_GL_INGR_blend_func_separate();
    Init_GL_INGR_color_clamp();
    Init_GL_INGR_interlace_read();
    Init_GL_EXT_stencil_wrap();
    Init_GL_EXT_422_pixels();
    Init_GL_NV_texgen_reflection();
    Init_GL_EXT_texture_cube_map();
    Init_GL_SUN_convolution_border_modes();
    Init_GL_EXT_texture_env_add();
    Init_GL_EXT_texture_lod_bias();
    Init_GL_EXT_texture_filter_anisotropic();
    Init_GL_EXT_vertex_weighting();
    Init_GL_NV_light_max_exponent();
    Init_GL_NV_vertex_array_range();
    Init_GL_NV_register_combiners();
    Init_GL_NV_fog_distance();
    Init_GL_NV_texgen_emboss();
    Init_GL_NV_blend_square();
    Init_GL_NV_texture_env_combine4();
    Init_GL_MESA_resize_buffers();
    Init_GL_MESA_window_pos();
    Init_GL_EXT_texture_compression_s3tc();
    Init_GL_IBM_cull_vertex();
    Init_GL_IBM_multimode_draw_arrays();
    Init_GL_IBM_vertex_array_lists();
    Init_GL_SGIX_subsample();
    Init_GL_SGIX_ycrcb_subsample();
    Init_GL_SGIX_ycrcba();
    Init_GL_SGIX_depth_pass_instrument();
    Init_GL_3DFX_texture_compression_FXT1();
    Init_GL_3DFX_multisample();
    Init_GL_3DFX_tbuffer();
    Init_GL_EXT_multisample();
    Init_GL_SGIX_vertex_preclip();
    Init_GL_SGIX_convolution_accuracy();
    Init_GL_SGIX_resample();
    Init_GL_SGIS_point_line_texgen();
    Init_GL_SGIS_texture_color_mask();
    Init_GL_SGIX_igloo_interface();
    Init_GL_EXT_texture_env_dot3();
    Init_GL_ATI_texture_mirror_once();
    Init_GL_NV_fence();
    Init_GL_IBM_texture_mirrored_repeat();
    Init_GL_NV_evaluators();
    Init_GL_NV_packed_depth_stencil();
    Init_GL_NV_register_combiners2();
    Init_GL_NV_texture_compression_vtc();
    Init_GL_NV_texture_rectangle();
    Init_GL_NV_texture_shader();
    Init_GL_NV_texture_shader2();
    Init_GL_NV_vertex_array_range2();
    Init_GL_NV_vertex_program();
    Init_GL_SGIX_texture_coordinate_clamp();
    Init_GL_SGIX_scalebias_hint();
    Init_GL_OML_interlace();
    Init_GL_OML_subsample();
    Init_GL_OML_resample();
    Init_GL_NV_copy_depth_to_color();
    Init_GL_ATI_envmap_bumpmap();
    Init_GL_ATI_fragment_shader();
    Init_GL_ATI_pn_triangles();
    Init_GL_ATI_vertex_array_object();
    Init_GL_EXT_vertex_shader();
    Init_GL_ATI_vertex_streams();
    Init_GL_ATI_element_array();
    Init_GL_SUN_mesh_array();
    Init_GL_SUN_slice_accum();
    Init_GL_NV_multisample_filter_hint();
    Init_GL_NV_depth_clamp();
    Init_GL_NV_occlusion_query();
    Init_GL_NV_point_sprite();
    Init_GL_NV_texture_shader3();
    Init_GL_NV_vertex_program1_1();
    Init_GL_EXT_shadow_funcs();
    Init_GL_EXT_stencil_two_side();
    Init_GL_ATI_text_fragment_shader();
    Init_GL_APPLE_client_storage();
    Init_GL_APPLE_element_array();
    Init_GL_APPLE_fence();
    Init_GL_APPLE_vertex_array_object();
    Init_GL_APPLE_vertex_array_range();
    Init_GL_APPLE_ycbcr_422();
    Init_GL_S3_s3tc();
    Init_GL_ATI_draw_buffers();
    Init_GL_ATI_pixel_format_float();
    Init_GL_ATI_texture_env_combine3();
    Init_GL_ATI_texture_float();
    Init_GL_NV_float_buffer();
    Init_GL_NV_fragment_program();
    Init_GL_NV_half_float();
    Init_GL_NV_pixel_data_range();
    Init_GL_NV_primitive_restart();
    Init_GL_NV_texture_expand_normal();
    Init_GL_NV_vertex_program2();
    Init_GL_ATI_map_object_buffer();
    Init_GL_ATI_separate_stencil();
    Init_GL_ATI_vertex_attrib_array_object();
    Init_GL_OES_read_format();
    Init_GL_EXT_depth_bounds_test();
    Init_GL_EXT_texture_mirror_clamp();
    Init_GL_EXT_blend_equation_separate();
    Init_GL_MESA_pack_invert();
    Init_GL_MESA_ycbcr_texture();
    Init_GL_EXT_pixel_buffer_object();
    Init_GL_NV_fragment_program_option();
    Init_GL_NV_fragment_program2();
    Init_GL_NV_vertex_program2_option();
    Init_GL_NV_vertex_program3();
    Init_GL_EXT_framebuffer_object();
    Init_GL_GREMEDY_string_marker();
}
/*--------------------------------------------------------------------------*/
