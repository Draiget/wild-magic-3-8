// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#include <maya/MGlobal.h>
#include <maya/MFnPlugin.h>

#include "Maya6p5ToWm3.h"
#include "Exporter.h"

// This file contains the calls to the Maya Plugin-related API.  No conversion
// is done here.

#define VERSION "1.02"
#define AUTHOR "Geometric Tools, Inc."

// Note: Due to a bug in Maya6.0 that makes it use the class name as the file
// type whenever you do an exportAll, the name of the file exporter should be
// exactly the same name as this class.  Our first choice for the name was
// "Wild Magic 3 Object File", but so be it.
#define NAME "Maya6p5ToWm3"

// The .mel script for the options pane.
#define EXPORT_OPTIONS_SCRIPT "Maya6p5ToWm3Options"

// Default options for that script.  See Maya6p5ToWm3Options.mel for
// descriptions of these options.
#define EXPORT_DEFAULT_OPTIONS "objFile=1;textFile=0;"\
    "quiet=0;expCameras=1;expInvisible=0;expLights=1;"\
    "expTextures=1;expBump=1;expKeys=1;expSkin=1;expBind=0;"

//----------------------------------------------------------------------------
MStatus initializePlugin (MObject kObj)
{
	MStatus kStatus;
	MFnPlugin kPlugin(kObj,AUTHOR,VERSION,"Any");

	kStatus = kPlugin.registerFileTranslator(NAME,"",Maya6p5ToWm3::creator,
        EXPORT_OPTIONS_SCRIPT,EXPORT_DEFAULT_OPTIONS);
	if (!kStatus)
    {
		kStatus.perror("registerCommand");
		return kStatus;
	}

	return kStatus;
}
//----------------------------------------------------------------------------
MStatus uninitializePlugin (MObject kObj)
{
	MStatus kStatus;
	MFnPlugin kPlugin(kObj,AUTHOR,VERSION,"Any");

	kStatus = kPlugin.deregisterFileTranslator(NAME);
	if (!kStatus)
    {
		kStatus.perror("deregisterFileTranslator");
    }

	return kStatus;
}
//----------------------------------------------------------------------------
Maya6p5ToWm3::Maya6p5ToWm3 ()
{
}
//----------------------------------------------------------------------------
Maya6p5ToWm3::~Maya6p5ToWm3 ()
{
}
//----------------------------------------------------------------------------
MStatus Maya6p5ToWm3::doIt (const MArgList&)
{
    return MS::kSuccess;
}
//----------------------------------------------------------------------------
void* Maya6p5ToWm3::creator ()
{
    return new Maya6p5ToWm3;
}
//----------------------------------------------------------------------------
bool Maya6p5ToWm3::haveReadMethod () const
{
	return false;
}
//----------------------------------------------------------------------------
bool Maya6p5ToWm3::haveWriteMethod () const
{
	return true;
}
//----------------------------------------------------------------------------
MString Maya6p5ToWm3::defaultExtension () const
{
	return MString("wmof");
}
//----------------------------------------------------------------------------
MString Maya6p5ToWm3::filter () const
{
    return MString("*.wmof");
}
//----------------------------------------------------------------------------
MPxFileTranslator::MFileKind Maya6p5ToWm3::identifyFile (
    const MFileObject& rkFileName, const char*, short) const
{
	const char* acName = rkFileName.name().asChar();
	size_t uiNameLength = strlen(acName);
    if (uiNameLength > 5)
    {
        const char* acExt = acName + uiNameLength - 5;
        if (acExt[0] == '.'
        &&  tolower(acExt[1]) == 'w'
        &&  tolower(acExt[2]) == 'm'
        &&  tolower(acExt[3]) == 'o'
        &&  tolower(acExt[4]) == 'f')
        {
    		return kIsMyFileType;
        }
    }

	return kNotMyFileType;
}
//----------------------------------------------------------------------------
MStatus Maya6p5ToWm3::writer (const MFileObject& rkFile,
    const MString& rkOptions, FileAccessMode)
{
    Exporter kExporter;

    // Read the options string, if it exists.  It comes in the format
    // option1=value1;option2=value2; ... etc
	if (rkOptions.length() > 0)
    {
		MStringArray kOptionList;
		MStringArray kThisOption;
		rkOptions.split(';',kOptionList);

		int iNumOptions = (int)kOptionList.length();
		for (int i = 0; i < iNumOptions; i++)
        {
			kThisOption.clear();
			kOptionList[i].split('=', kThisOption);
			if (kThisOption.length() < 2 || !kThisOption[1].isInt())
            {
				continue;
            }

            bool bValue = (kThisOption[1].asInt() ? true : false);

            if (kThisOption[0] == "objFile")
            {
                kExporter.Flags[Exporter::FLAG_OBJFILE] = bValue;
            }
            else if (kThisOption[0] == "textFile")
            {
                kExporter.Flags[Exporter::FLAG_TEXTFILE] = bValue;
            }
            else if (kThisOption[0] == "quiet")
            {
                kExporter.Flags[Exporter::FLAG_QUIET] = bValue;
            }
            else if (kThisOption[0] == "collapse")
            {
                kExporter.Flags[Exporter::FLAG_COLLAPSE] = bValue;
            }
            else if (kThisOption[0] == "expCameras")
            {
                kExporter.Flags[Exporter::FLAG_CAMERAS] = bValue;
            }
            else if (kThisOption[0] == "expInvisible")
            {
                kExporter.Flags[Exporter::FLAG_INVISIBLE] = bValue;
            }
            else if (kThisOption[0] == "expLights")
            {
                kExporter.Flags[Exporter::FLAG_LIGHTS] = bValue;
            }
            else if (kThisOption[0] == "expTextures")
            {
                kExporter.Flags[Exporter::FLAG_TEXTURES] = bValue;
            }
            else if (kThisOption[0] == "expBump")
            {
                kExporter.Flags[Exporter::FLAG_BUMP] = bValue;
            }
            else if (kThisOption[0] == "expKeys")
            {
                kExporter.Flags[Exporter::FLAG_KEYS] = bValue;
            }
            else if (kThisOption[0] == "expSkin")
            {
                kExporter.Flags[Exporter::FLAG_SKIN] = bValue;
            }
            else if (kThisOption[0] == "expBind")
            {
                kExporter.Flags[Exporter::FLAG_BIND] = bValue;
            }
            else if (kThisOption[0] == "expCalcNorm")
            {
                kExporter.Flags[Exporter::FLAG_CALC_NORM] = bValue;
            }
            else
            {
                MGlobal::displayError("Unknown flag: " + kOptionList[i]);
            }
		}
	}

    MGlobal::displayInfo("");

    kExporter.DoExport(rkFile.fullName().asChar());

    if (kExporter.Successful())
    {
        MGlobal::displayInfo("Conversion was successful.");
        return MStatus::kSuccess;
    }
    else
    {
        MGlobal::displayInfo("Conversion had errors; see script editor.");

        // If Maya gets back a failure status, it will not save the file.  It
        // is possible the user does not want to, or cannot fix, the errors,
        // and so we will just return success anyway.
        return MStatus::kSuccess;
    }
}
//----------------------------------------------------------------------------

