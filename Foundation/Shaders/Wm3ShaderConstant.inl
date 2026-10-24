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
inline int ShaderConstant::GetSCType () const
{
    return m_iSCType;
}
//----------------------------------------------------------------------------
inline int ShaderConstant::GetSCOption () const
{
    return m_iSCOption;
}
//----------------------------------------------------------------------------
inline int ShaderConstant::GetRegister () const
{
    return m_iRegister;
}
//----------------------------------------------------------------------------
inline int ShaderConstant::GetRegisterQuantity () const
{
    return m_iRegisterQuantity;
}
//----------------------------------------------------------------------------
inline float* ShaderConstant::Data ()
{
    return m_afData;
}
//----------------------------------------------------------------------------
inline float ShaderConstant::Data (int i) const
{
    return m_afData[i];
}
//----------------------------------------------------------------------------

