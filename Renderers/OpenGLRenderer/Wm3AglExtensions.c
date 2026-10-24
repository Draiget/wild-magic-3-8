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

#ifdef __APPLE__
#include <mach-o/dyld.h>
#include <stdlib.h>
#include <string.h>

/*--------------------------------------------------------------------------*/
void* GetFunctionPointer (const char* acFunction)
{
    NSSymbol kSymbol;
    char* acSymbolName;

    /* Prepend a '_' for the Unix C symbol mangling convention. */
    acSymbolName = malloc(strlen((const char*)acFunction) + 2);
    strcpy(acSymbolName+1,(const char*)acFunction);
    acSymbolName[0] = '_';

    kSymbol = 0;
    if (NSIsSymbolNameDefined(acSymbolName))
        kSymbol = NSLookupAndBindSymbol(acSymbolName);

    free(acSymbolName);
    return kSymbol ? NSAddressOfSymbol(kSymbol) : 0;
}
/*--------------------------------------------------------------------------*/

#endif
