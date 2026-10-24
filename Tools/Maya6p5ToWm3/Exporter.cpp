// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#include <maya/MDagPath.h>
#include <maya/MFileIO.h>
#include <maya/MItDag.h>
#include <maya/MGlobal.h>
#include <maya/MItDependencyNodes.h>
#include <maya/MAnimControl.h>
#include <maya/MTime.h>

#include "Exporter.h"
#include "Wm3BumpMapEffect.h"
#include "Wm3KeyframeController.h"
using namespace Wm3;
using namespace std;

//----------------------------------------------------------------------------
Exporter::Exporter ()
    :
    m_kJointHash(10),
    m_kMap(10),
    m_kMeshDataMap(1)
{
    // default flags
    Flags[FLAG_OBJFILE] = true;
    Flags[FLAG_TEXTFILE] = false;
    Flags[FLAG_QUIET] = false;
    Flags[FLAG_COLLAPSE] = false;
    Flags[FLAG_CAMERAS] = true;
    Flags[FLAG_INVISIBLE] = false;
    Flags[FLAG_LIGHTS] = true;
    Flags[FLAG_TEXTURES] = true;
    Flags[FLAG_BUMP] = true;
    Flags[FLAG_KEYS] = true;
    Flags[FLAG_SKIN] = true;
    Flags[FLAG_BIND] = true;
    Flags[FLAG_CALC_NORM] = true;
}
//----------------------------------------------------------------------------
void Exporter::DoExport (const char* acFilename)
{
    m_bSuccess = true;

    // clean up invalid flag options
    if ( !Flags[FLAG_TEXTURES] || !Flags[FLAG_LIGHTS] )
        Flags[FLAG_BUMP] = false;

    // reset data structures
    m_kWMCamera.RemoveAll();
    m_kWMBumpMap.RemoveAll();
    m_kWMLight.RemoveAll();
    m_kMap.RemoveAll();
    m_kJointHash.RemoveAll();
    m_spkWMScene = 0;
    m_bObjectInvisible = false;

    // Make text file first since it is less likely to fail.
    if ( Flags[FLAG_TEXTFILE] )
        ExportTextFile(acFilename);

    if ( Flags[FLAG_OBJFILE] )
        ExportObjectFile(acFilename);
}
//----------------------------------------------------------------------------
void Exporter::ExportObjectFile (const char* acFilename)
{
    MItDag* pkMayaScene = new MItDag(MItDag::kDepthFirst,MFn::kInvalid,
        &m_kStatus);
    assert( m_kStatus );

    // DAG path height under which nodes are invisible (0 if all visible)
    int iInvisibleHeight = 0;

    // main pass: depth first walkthrough of scene graph
    for (/**/; !pkMayaScene->isDone(); pkMayaScene->next())
    {
        MDagPath kDagPath;
        m_kStatus = pkMayaScene->getPath(kDagPath);
        assert( m_kStatus );
        MFnDagNode kDagNode(kDagPath,&m_kStatus);
        assert( m_kStatus );
        MFn::Type eType = kDagNode.object().apiType();
        DisplayInfo(MString("--- Converting ") + 
            MString(TYPE_STRING[eType]) + " " + 
            kDagNode.name().asChar() + " ---");

        // Make the path stack the correct height so that the correct parent
        // node is on top of the stack.
        int iCurrentHeight = (int)kDagPath.length();
        while ( iCurrentHeight < m_kParentStack.GetQuantity() )
            m_kParentStack.Remove(m_kParentStack.GetQuantity()-1);
        
        if ( Flags[FLAG_INVISIBLE] )
        {
            // If convert invisible flag, then convert all objects.
            m_bObjectInvisible = false;
            (this->*CONVERT[eType])(kDagNode);
        }
        else if ( !iInvisibleHeight || iCurrentHeight <= iInvisibleHeight )
        {
            // If this object is not part of an invisible subtree...

            // reset height flag and invisible flag
            iInvisibleHeight = 0;
            m_bObjectInvisible = false;

            // convert object
            (this->*CONVERT[eType])(kDagNode);

            // Was this object invisible? If so set the height boundary.
            if ( m_bObjectInvisible )
                iInvisibleHeight = iCurrentHeight;
        }
        else
        {
            // If in an invisible subtree...
            assert( m_bObjectInvisible );
            (this->*CONVERT[eType])(kDagNode);
        }  
    }

    // must update world transforms before the skin controller pass
    m_spkWMScene->UpdateGS();

    // Second pass for skin, which needs the joints from the DAG and also
    // whose controllers are not in the DAG itself.
    if ( Flags[FLAG_SKIN] )
    {
        MItDependencyNodes* pkSkinScene = new MItDependencyNodes(
            MFn::kSkinClusterFilter,&m_kStatus);
        assert( m_kStatus );
        for (/**/; !pkSkinScene->isDone(); pkSkinScene->next())
        {        
            // Sanity check
            assert(pkSkinScene->item().apiType() == MFn::kSkinClusterFilter);
            CSkinClusterFilter(pkSkinScene->item());
        }

        delete pkSkinScene;
    }

    // Deferred bumpmaps, because lights need to be known at bumpmap creation
    // time.
    int i;
    if ( m_kWMBumpMap.GetQuantity() > 0 )
    {
        Light* pkFirstLight = 0;
        for (i = 0; i < m_kWMLight.GetQuantity(); i++)
        {
            // find the first non-ambient light
            if ( m_kWMLight[i]->Type != Light::LT_AMBIENT )
            {
                pkFirstLight = m_kWMLight[i];
                break;
            }
        }

        if ( !pkFirstLight )
        {
            DisplayError(
                "No nonambient lights in the scene. Ignoring bump maps.");
        }
        else if ( Flags[FLAG_BUMP] )
        {
            // process all bump map effects
            for (int j = 0; j < m_kWMBumpMap.GetQuantity(); j++)
            {
                // The default light to use is the first one in the scene.
                Light* pkBumpLight = pkFirstLight;
                InstanceData* pkFound = m_kMap.Find(m_kWMBumpMap[j].MeshKey);
                if ( !pkFound || pkFound->Spats.GetQuantity() <= 0 )
                {
                    DisplayInfo("--- Converting BumpMapEffect ---");
                    DisplayError("Could not find mesh for bump map effect.");
                    continue;
                }
                MString kObjName(pkFound->GetFirst()->GetName());

                DisplayInfo("--- Converting BumpMapEffect for " +
                    kObjName + "---");

                // Find a light for this bump map.
                for (i = 0; i < m_kWMLight.GetQuantity() ;i++)
                {
                    // If a light has the name of the object as a suffix,
                    // then that light will be used.
                    MString kLightName(m_kWMLight[i]->GetName());
                    MString kSuffix = kLightName.substring(
                        kLightName.length()-kObjName.length(),
                        kLightName.length());

                    if ( kObjName == kSuffix )
                    {
                        pkBumpLight = m_kWMLight[i];
                        break;
                    }
                }

                if ( pkBumpLight->GetName() )
                {
                    DisplayInfo("Using light " + 
                        MString(pkBumpLight->GetName()));
                }

                BumpMapEffect* pkEffect = new BumpMapEffect(
                    m_kWMBumpMap[j].Primary,m_kWMBumpMap[j].PrimaryUVs,
                    m_kWMBumpMap[j].NormalMap,m_kWMBumpMap[j].NormalUVs,
                    pkBumpLight);

                // set bumpmap for object and its instances
                pkFound->Spats[0]->SetEffect(pkEffect);
                for (i = 1; i < pkFound->Spats.GetQuantity(); i++)
                    pkFound->Spats[i]->SetEffect(pkEffect->Clone());
            }
        }
    }

    // add the lights to the scene
    for (i = 0; i < m_kWMLight.GetQuantity(); i++)
        m_spkWMScene->SetLight(m_kWMLight[i]);
    
    m_spkWMScene->UpdateGS();

    Stream kOut;
    kOut.Insert(m_spkWMScene);
    kOut.Save(acFilename);

    delete pkMayaScene;
}
//----------------------------------------------------------------------------
void Exporter::ExportTextFile (const char* acFilename)
{
    MItDag* pkMayaScene = new MItDag(MItDag::kDepthFirst,MFn::kInvalid,
        &m_kStatus);
    assert( m_kStatus );

    MString kStr(acFilename);
    kStr += "-data.txt";
    std::ofstream kOStr(kStr.asChar());

    for (/**/; !pkMayaScene->isDone(); pkMayaScene->next())
    {
        MDagPath kDagPath;
        m_kStatus = pkMayaScene->getPath(kDagPath);
        assert( m_kStatus );

        m_kStatus.clear();
        MFnDagNode kDagNode(kDagPath,&m_kStatus);
        assert( m_kStatus );

        unsigned int uiLength = kDagPath.length(&m_kStatus);
        assert( m_kStatus );
        for (unsigned int i = 0; i < 4*uiLength; i++)
            kOStr << ' ';

        MFn::Type eType = kDagNode.object().apiType();
        kOStr << TYPE_STRING[eType] << " (" <<
            kDagNode.name().asChar() << ")" << endl;
    }
    delete pkMayaScene;
    kOStr.close();
}
//----------------------------------------------------------------------------
Exporter::~Exporter ()
{
    m_spkWMScene = 0;
    m_kWMBumpMap.RemoveAll();
    m_kWMCamera.RemoveAll();
    m_kWMLight.RemoveAll();
}
//----------------------------------------------------------------------------
int Exporter::GetKey (const MObject& rkObject) const
{
    int iKey = *(int*)&rkObject;
    return iKey;
}
//----------------------------------------------------------------------------
void Exporter::AttachChainToParent (const MFnDagNode& rkDagNode, 
    Spatial* pkFirst, Spatial* pkLast, bool bAttachToWorld)
{
    // Attach a chain to its parent, insert the node into the object map,
    // and put the end of the chain onto the parent stack.

    // rkDagNode is the Maya node that pkChild was created from.
    // pkFirst is the head of the chain that will be attached to the chain's
    //   parent.
    // pkLast is the tail of the chain.  Other objects that attach to
    //   rkDagNode will be attached to pkLast.
    // bAttachToWorld is the boolean flag for if this
    //   object should be attached to the world or to its correct parent.

    // scene must be created and the world node may not be a chain
    assert( m_spkWMScene );
    assert( m_spkWMScene != pkFirst );
    assert( m_spkWMScene != pkLast );

    if ( bAttachToWorld )
    {
        // attaching to the world instead of parent
        m_spkWMScene->AttachChild(pkFirst);
    }
    else
    {
        // attaching to a parent
        assert( m_kParentStack.GetQuantity() > 0 );
        Spatial* pkParent = m_kParentStack[m_kParentStack.GetQuantity()-1];
        assert( pkParent->IsDerived(Node::TYPE) );
        Node* pkParentN = StaticCast<Node>(pkParent);
        pkParentN->AttachChild(pkFirst);
    }

    int iKey = GetKey(rkDagNode.object());
    InstanceData* pkFound = m_kMap.Find(iKey);
    if ( pkFound )
        DisplayError("Chain has already been created.  Ignoring chain.");
    else
        m_kMap.Insert(iKey,InstanceData(pkLast));

    m_kParentStack.Append(pkLast);
}
//----------------------------------------------------------------------------
void Exporter::AttachToParent (const MFnDagNode& rkDagNode, Spatial* pkChild,
    bool bAttachToWorld)
{
    // Attach an object to its parent, insert the node into the object map,
    // and put the object onto the parent stack.

    // rkDagNode is the Maya object that pkChild was created from.
    //
    // This should be called for the world node, though m_spkWMScene should
    // already be set to the world node before the call.  It will insert the
    // world node into the map and parent stack, but will not attach it
    // anywhere.  This slightly special behavior is to avoid having two
    // functions (Attach and InsertIntoMap) which need to be called in a
    // particular order every time.

    if ( !m_spkWMScene )
    {
        DisplayError("No scene to attach to!");
    }
    else if ( m_spkWMScene == pkChild )
    {
        // special case for the world, do nothing
    }
    else if ( bAttachToWorld )
    {
        // attaching to the world instead of parent
        m_spkWMScene->AttachChild(pkChild);
    }
    else
    {
        // attaching to a parent
        assert( m_kParentStack.GetQuantity() > 0 );
        Spatial* pkParent = m_kParentStack[m_kParentStack.GetQuantity()-1];
        assert( pkParent->IsDerived(Node::TYPE) );
        Node* pkParentN = StaticCast<Node>(pkParent);
        pkParentN->AttachChild(pkChild);
    }

    int iKey = GetKey(rkDagNode.object());
    InstanceData* pkFound = m_kMap.Find(iKey);
    if ( pkFound )
    {
        pkFound->Spats.Append(pkChild);
    }
    else
    {
        m_kMap.Insert(iKey,InstanceData(pkChild));
    }

    m_kParentStack.Append(pkChild);
}
//----------------------------------------------------------------------------



