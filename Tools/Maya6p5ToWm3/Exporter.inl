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
inline bool Exporter::Successful () const
{
    return m_bSuccess;
}
//----------------------------------------------------------------------------
inline void Exporter::DisplayInfo (MString kStr)
{
    if ( !Flags[FLAG_QUIET] )
        MGlobal::displayInfo(kStr);
}
//----------------------------------------------------------------------------
inline void Exporter::DisplayWarning (MString kStr)
{
    if ( !Flags[FLAG_QUIET] )
        MGlobal::displayWarning(kStr);
}
//----------------------------------------------------------------------------
inline void Exporter::DisplayError (MString kStr)
{
    // always display errors, even if being Quiet
    MGlobal::displayError(kStr);
    m_bSuccess = false;
}
//----------------------------------------------------------------------------



