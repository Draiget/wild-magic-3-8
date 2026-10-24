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
inline void CharcoalPShader::SetSmudgeFactor (float fSmudgeFactor)
{
    m_kConstant[0]->Data()[0] = fSmudgeFactor;
}
//----------------------------------------------------------------------------
inline float CharcoalPShader::GetSmudgeFactor () const
{
    return m_kConstant[0]->Data()[0];
}
//----------------------------------------------------------------------------
inline void CharcoalPShader::SetPaperFactor (float fPaperFactor)
{
    m_kConstant[0]->Data()[1] = fPaperFactor;
}
//----------------------------------------------------------------------------
inline float CharcoalPShader::GetPaperFactor () const
{
    return m_kConstant[0]->Data()[1];
}
//----------------------------------------------------------------------------

