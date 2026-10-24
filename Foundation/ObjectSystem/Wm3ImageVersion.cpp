// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#include "Wm3FoundationPCH.h"
#include "Wm3ImageVersion.h"
using namespace Wm3;

const int ImageVersion::MAJOR = 3;
const int ImageVersion::MINOR = 0;
const char ImageVersion::LABEL[] = "Wild Magic Image File 3.00";
const int ImageVersion::LENGTH = 27;
const ImageVersion ImageVersion::CURRENT(MAJOR,MINOR);

//----------------------------------------------------------------------------
ImageVersion::ImageVersion (int iMajor, int iMinor)
{
    m_iMajor = iMajor;
    m_iMinor = iMinor;
}
//----------------------------------------------------------------------------
ImageVersion::ImageVersion (const char* acString)
{
    m_iMajor = -1;
    m_iMinor = -1;

    if (acString
    &&  strlen(acString) >= LENGTH-1
    &&  acString[LENGTH-1] == 0
    &&  strncmp(acString,LABEL,LENGTH-5) == 0)  // 5 = strlen(" 3.xx")
    {
        // The version string is "x.yy".
        const char* acVersion = acString + LENGTH - 5;
        m_iMajor = (int)(acVersion[0]-'0');
        m_iMinor = 10*(int)(acVersion[2]-'0') + (int)(acVersion[3]-'0');
    }
}
//----------------------------------------------------------------------------
bool ImageVersion::IsValid () const
{
    return m_iMajor == 3 && 0 <= m_iMinor && m_iMinor < 100;
}
//----------------------------------------------------------------------------
int ImageVersion::GetMajor () const
{
    return m_iMajor;
}
//----------------------------------------------------------------------------
int ImageVersion::GetMinor () const
{
    return m_iMinor;
}
//----------------------------------------------------------------------------
int ImageVersion::GetCombined () const
{
    return 100*m_iMajor + m_iMinor;
}
//----------------------------------------------------------------------------
bool ImageVersion::operator== (const ImageVersion& rkVersion) const
{
    assert(IsValid() && rkVersion.IsValid());
    return GetCombined() == rkVersion.GetCombined();
}
//----------------------------------------------------------------------------
bool ImageVersion::operator!= (const ImageVersion& rkVersion) const
{
    assert(IsValid() && rkVersion.IsValid());
    return GetCombined() != rkVersion.GetCombined();
}
//----------------------------------------------------------------------------
bool ImageVersion::operator< (const ImageVersion& rkVersion) const
{
    assert(IsValid() && rkVersion.IsValid());
    return GetCombined() < rkVersion.GetCombined();
}
//----------------------------------------------------------------------------
bool ImageVersion::operator<= (const ImageVersion& rkVersion) const
{
    assert(IsValid() && rkVersion.IsValid());
    return GetCombined() <= rkVersion.GetCombined();
}
//----------------------------------------------------------------------------
bool ImageVersion::operator> (const ImageVersion& rkVersion) const
{
    assert(IsValid() && rkVersion.IsValid());
    return GetCombined() > rkVersion.GetCombined();
}
//----------------------------------------------------------------------------
bool ImageVersion::operator>= (const ImageVersion& rkVersion) const
{
    assert(IsValid() && rkVersion.IsValid());
    return GetCombined() >= rkVersion.GetCombined();
}
//----------------------------------------------------------------------------

