// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

//----------------------------------------------------------------------------
inline void RefractionVShader::SetIndexOfRefraction (float fIndexOfRefraction)
{
    m_kConstant[3]->Data()[0] = fIndexOfRefraction;
}
//----------------------------------------------------------------------------
inline float RefractionVShader::GetIndexOfRefraction () const
{
    return float(m_kConstant[3]->Data()[0]);
}
//----------------------------------------------------------------------------
inline void RefractionVShader::SetFresnelConstants (
    const Vector4f& rkFresnelConstants)
{
    m_kConstant[4]->Data()[0] = rkFresnelConstants[0];
    m_kConstant[4]->Data()[1] = rkFresnelConstants[1];
    m_kConstant[4]->Data()[2] = rkFresnelConstants[2];
    m_kConstant[4]->Data()[3] = rkFresnelConstants[3];
}
//----------------------------------------------------------------------------
inline Vector4f RefractionVShader::GetFresnelConstants () const
{
    return Vector4f(m_kConstant[4]->Data()[0],
        m_kConstant[4]->Data()[1],
        m_kConstant[4]->Data()[2],
        m_kConstant[4]->Data()[3]);
}
//----------------------------------------------------------------------------

