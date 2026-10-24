// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM3STREAMVERSION_H
#define WM3STREAMVERSION_H

#include "Wm3FoundationLIB.h"
#include "Wm3System.h"

// Scene graphs are stored in files with extension wmof.  The header is of the
// form "Wild Magic Object File 3.xx" where the major version is 3 and the
// the minor version is xx in [00,99].  The length of the string is 27, but
// the null terminator is written to disk, so total number of file bytes used
// by the version is 28.  The current version is "3.00"

namespace Wm3
{

class WM3_ITEM StreamVersion
{
public:
    static const int MAJOR;     // 3
    static const int MINOR;     // 0
    static const char LABEL[];  // "Wild Magic Object File 3.00"
    static const int LENGTH;    // 28 = strlen(LABEL)+1
    static const StreamVersion CURRENT;

    StreamVersion (int iMajor = MAJOR, int iMinor = MINOR);
    StreamVersion (const char* acString);

    int GetMajor () const;
    int GetMinor () const;

    // The version is valid if major is 3 and minor in [0,99].
    bool IsValid () const;

    // For comparisons of versions.  This is useful in the Stream support in
    // an Object-derived class whenever a change to that class causes a file
    // format change.
    bool operator== (const StreamVersion& rkVersion) const;
    bool operator!= (const StreamVersion& rkVersion) const;
    bool operator<  (const StreamVersion& rkVersion) const;
    bool operator<= (const StreamVersion& rkVersion) const;
    bool operator>  (const StreamVersion& rkVersion) const;
    bool operator>= (const StreamVersion& rkVersion) const;

protected:
    int GetCombined () const;  // 100*major + minor

    int m_iMajor, m_iMinor;
};

}

#endif

