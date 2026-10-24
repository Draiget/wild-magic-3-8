// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#include "Wm3Foundation.h"
#include "CommandLine.h"
#include "LightWaveReader.h"
#include <iostream>
using namespace Wm3;
using namespace std;

//----------------------------------------------------------------------------
// To convert from LightWave's obj format to Wild Magic's wmof:
//   LwoToWm3 [-smooth] [-verbose] model.lwo model.wmof
//
// Any texture images needed by the obj file must be located in the same
// directory as the obj file, and must be .bmp or .tga files.
//----------------------------------------------------------------------------
int main (int iQuantity, char** aacArgument)
{
    if ( iQuantity <= 1 )
        return -1;

    CommandLine kCommand(iQuantity,aacArgument);

    // get command-line parameters
    bool bVerbose = ( kCommand.Boolean("verbose") ? true : false );
    bool bSmooth = ( kCommand.Boolean("smooth") ? true : false) ;

    char* acInputFile = 0;
    kCommand.Filename(acInputFile);
    if ( !acInputFile )
    {
        cout << "Cannot open input file" << endl;
        return -2;
    }

    char* acOutputFile = 0;
    kCommand.Filename(acOutputFile);
    if ( !acOutputFile )
    {
        cout << "Cannot open output file" << endl;
        delete[] acInputFile;
        return -3;
    }

    LightWaveReader kReader(acInputFile,bVerbose,bSmooth);
    if ( kReader.GetError() == LightWaveReader::LWR_NO_ERROR )
    {
        NodePtr spkScene = kReader.GetScene();
        assert( spkScene );
        if ( spkScene )
        {
            Stream kOStream;
            kOStream.Insert(spkScene);
            kOStream.Save(acOutputFile);
        }
        else
        {
            cout << "Reader claims success, but scene is null." << endl;
        }
    }
    else
    {
        cout << "Error: " << kReader.ErrorString[kReader.GetError()] << endl;
    }

    delete[] acInputFile;
    delete[] acOutputFile;
    return 0;
}
//----------------------------------------------------------------------------

