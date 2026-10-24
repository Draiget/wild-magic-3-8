// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef MAX7TOWM3_H
#define MAX7TOWM3_H

#include <windows.h>

class Max7ToWm3
{
public:
    Max7ToWm3 ();
    ~Max7ToWm3 ();

    void SetInstance (HINSTANCE hInstance);
    HINSTANCE GetInstance () const;
    void SetControlsInitialized ();
    bool GetControlsInitialized () const;
    const TCHAR* GetResourceString (unsigned int uiID) const;

    static Max7ToWm3 ThePlugin;

private:
    HINSTANCE m_hInstance;
    bool m_bControlsInitialized;

    enum { MAX_RESOURCE_STRING = 512 };
    TCHAR m_acResourceString[MAX_RESOURCE_STRING];
};

#endif




