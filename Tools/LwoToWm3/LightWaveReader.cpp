// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#include "LightWaveReader.h"
#include "ImageLoader.h"
#include "Wm3TextureEffect.h"
using namespace Wm3;
using namespace std;

#define LWREADER_UNITIZE_MODEL 0
#define LWREADER_USE_FUZZ 1

const char* LightWaveReader::ErrorString[LWR_QUANTITY] =
{
    "no error",
    "bad LWO file",
    "bad log file",
    "missing form chunk",
    "missing LWO2 chunk",
    "bad layer chunk",
    "bad points chunk",
    "bad bounding box chunk",
    "unsupported polygon type",
    "unsupported texture type",
    "missing channel",
    "bad imap chunk"
};

const char LightWaveReader::ms_acTab[] = "    ";

//----------------------------------------------------------------------------
LightWaveReader::LightWaveReader (const char* acFileName, bool bVerbose,
    bool bSmoothed)
{
    m_acBuffer = 0;
    m_iLength = 0;
    m_pcCurrent = 0;
    m_eError = LWR_NO_ERROR;
    m_bSmoothed = bSmoothed;

    m_spkLWObject = 0;
    m_pkCurrentMesh = 0;
    m_pkCurrentTexture = 0;
    m_pkCurrentPolyList = 0;

    m_pkLWOFile = System::Fopen(acFileName,"rb");
    if ( !m_pkLWOFile )
    {
        m_eError = LWR_BAD_LWO_FILE;
        return;
    }

    if ( !System::Load(acFileName,m_acBuffer,m_iLength) )
    {
        fclose(m_pkLWOFile);
        m_eError = LWR_BAD_LWO_FILE;
        return;
    }

    if ( bVerbose )
    {
        m_pkLogFile = new ofstream("LogFile.txt");
        if ( !m_pkLogFile )
        {
            fclose(m_pkLWOFile);
            m_eError = LWR_BAD_LOG_FILE;
            return;
        }
    }
    else
    {
        m_pkLogFile = 0;
    }

    Parse();

    fclose(m_pkLWOFile);

    if ( m_pkLogFile )
    {
        m_pkLogFile->close();
        delete m_pkLogFile;
    }

    delete[] m_acBuffer;
}
//----------------------------------------------------------------------------
LightWaveReader::~LightWaveReader ()
{
    const int iSize = (int)m_akVertexToPolygon.size();
    for (int i = 0; i < iSize; i++)
    {
        PolygonList* pkList = m_akVertexToPolygon[i];
        pkList->clear();
        delete pkList;
    }
    m_akVertexToPolygon.clear();

    TagMap::iterator kTMIter = m_kTagMap.begin();
    for (/**/; kTMIter != m_kTagMap.end(); kTMIter++)
    {
        PolygonList* pkList = kTMIter->second;
        pkList->clear();
        delete pkList;
    }
    m_kTagMap.clear();

    PolygonTagMap::iterator kPMIter = m_kPolygonMaps.begin();
    for (/**/; kPMIter != m_kPolygonMaps.end(); kPMIter++)
    {
        PolygonMap* pkMap = kPMIter->second;
        pkMap->clear();
        delete pkMap;
    }
    m_kPolygonMaps.clear();

    SurfaceVertexMap::iterator kSVMIter = m_kVertexMaps.begin();
    for (/**/; kSVMIter != m_kVertexMaps.end(); kSVMIter++)
    {
        VertexMap* pkMap = kSVMIter->second;
        pkMap->clear();
        delete pkMap;
    }
    m_kVertexMaps.clear();

    VMAPArrayMap::iterator kVPMIter = m_kMaps.begin();
    for (/**/; kVPMIter != m_kMaps.end(); kVPMIter++)
    {
        VMAPArray* pkArray = kVPMIter->second;
        pkArray->clear();
        delete pkArray;
    }
    m_kMaps.clear();

    VMADArrayMap::iterator kVDMIter = m_kDiscontMaps.begin();
    for (/**/; kVDMIter != m_kDiscontMaps.end(); kVDMIter++)
    {
        VMADArray* pkArray = kVDMIter->second;
        pkArray->clear();
        delete pkArray;
    }
    m_kDiscontMaps.clear();

    m_akVertices.clear();
    m_kSurfaces.clear();
    m_kTagSurfaces.clear();
    m_kPolygonTags.clear();
    m_kPolygonLists.clear();
    m_kAngles.clear();
    m_akPolygons.clear();
    m_kMapVertices.clear();
    m_kMapNormals.clear();
    m_kMapTextures.clear();
    m_kMapConnectivity.clear();
}
//----------------------------------------------------------------------------
int LightWaveReader::GetError () const
{
    return m_eError;
}
//----------------------------------------------------------------------------
NodePtr LightWaveReader::GetScene ()
{
    return m_spkLWObject;
}
//----------------------------------------------------------------------------
bool LightWaveReader::DataAvailable() const
{
    return m_pcCurrent < m_acBuffer + m_iLength;
}
//----------------------------------------------------------------------------
bool LightWaveReader::Parse ()
{
    // initialize the file position pointer
    m_pcCurrent = m_acBuffer;

    // parse LWO2 file headers: IFF marker, file size, LightWave signature
    unsigned int uiForm;
    System::Read4be(m_pcCurrent,1,&uiForm);
    m_pcCurrent += sizeof(unsigned int);
    if ( uiForm != 'FORM' )
    {
        m_eError = LWR_MISSING_FORM_CHUNK;
        if ( m_pkLogFile )
            *m_pkLogFile << "Missing FORM chunk." << endl;
        return false;
    }

    unsigned int uiFileSize;
    System::Read4be(m_pcCurrent,1,&uiFileSize);
    m_pcCurrent += sizeof(unsigned int);

    unsigned int uiLWO2;
    System::Read4be(m_pcCurrent,1,&uiLWO2);
    m_pcCurrent += sizeof(unsigned int);
    if ( uiLWO2 != 'LWO2' )
    {
        m_eError = LWR_MISSING_LWO2_CHUNK;
        if ( m_pkLogFile )
            *m_pkLogFile << "Missing LWO2 chunk type." << endl;
        return false;
    }

    // parse LWO2 file
    while ( ReadChunk(uiFileSize) )
    {
        if ( !DataAvailable() || m_eError != LWR_NO_ERROR )
            break;
    }

    // construct object
    BuildObject();
    if ( m_spkLWObject && m_pkLogFile )
        ObjectStatistics();

    return m_eError == LWR_NO_ERROR;
}
//----------------------------------------------------------------------------
void LightWaveReader::BuildObject ()
{
    // create a Node and add default states to it
    m_spkLWObject = new Node((int)m_kSurfaces.size());

    // add all surfaces as trimesh children
    SurfaceMap::iterator kSIter = m_kSurfaces.begin();
    for (/**/; kSIter != m_kSurfaces.end(); kSIter++)
    {
        TriMesh* pkMesh = kSIter->second;
        m_spkLWObject->AttachChild(pkMesh);
        pkMesh->UpdateGS();
    }

    // compute normals (if requested) before returning the object
    ComputeNormals();
}
//----------------------------------------------------------------------------
void LightWaveReader::ObjectStatistics ()
{
    // Display simplified stats summary for object.

    *m_pkLogFile
        << endl
        << "STATISTICS"
        << endl
        << endl;

    *m_pkLogFile
        << "Number of trimeshes: "
        << (int)m_kSurfaces.size()
        << endl;
    *m_pkLogFile
        << "Number of vertices : "
        << (int)m_akVertices.size()
        << endl;
    *m_pkLogFile
        << "Number of triangles: "
        << (int)m_akPolygons.size()
        << endl;
    *m_pkLogFile
        << "Number of textures : "
        << (int)m_akTextures.size()
        << endl;
    *m_pkLogFile
        << "Number of VMAPs    : "
        << (int)m_kMaps.size()
        << endl;
    *m_pkLogFile
        << "Number of VMADs    : "
        << (int)m_kDiscontMaps.size()
        << endl;

    if ( m_kSurfaces.size() )
    {
        *m_pkLogFile
            << "Trimeshes: "
            << endl;
        SurfaceMap::iterator kSIter = m_kSurfaces.begin();
        for (/**/; kSIter != m_kSurfaces.end(); kSIter++)
        {
            string kName = kSIter->first;
            TriMesh* pkMesh = kSIter->second;
            if ( !pkMesh )
            {
                *m_pkLogFile << ms_acTab << "mesh is null" << endl;
                continue;
            }
            *m_pkLogFile
                << ms_acTab
                << kName.c_str()
                << endl;

            if ( pkMesh->Indices )
            {
                *m_pkLogFile
                    << ms_acTab
                    << ms_acTab
                    << "Triangles: "
                    << pkMesh->GetTriangleQuantity()
                    << " (total vertices: "
                    << pkMesh->GetTriangleQuantity() * 3 << ")"
                    << endl;
            }
            else
            {
                *m_pkLogFile << ms_acTab << "mesh does not have indices"
                    << endl;
            }

            if ( pkMesh->Vertices )
            {
                *m_pkLogFile
                    << ms_acTab
                    << ms_acTab
                    << "Vertices: "
                    << pkMesh->Vertices->GetQuantity()
                    << endl;
            }
            else
            {
                *m_pkLogFile << ms_acTab << "mesh does not have vertices"
                    << endl;
            }

            *m_pkLogFile
                << ms_acTab
                << ms_acTab
                << "LW vertices: "
                << (int)m_kVertexMaps[kName]->size()
                << endl;
            *m_pkLogFile
                << ms_acTab
                << ms_acTab
                << "Textured: ";
            if ( pkMesh->GetEffect()
            &&   pkMesh->GetEffect()->Textures.GetQuantity() > 0)
            {
                *m_pkLogFile << "yes" << endl;
            }
            else
            {
                *m_pkLogFile << "no" << endl;
            }
        }
    }

    if ( m_kMaps.size() )
    {
        *m_pkLogFile << "UV maps: " << endl;
        VMAPArrayMap::iterator kVPMIter = m_kMaps.begin();
        for (/**/; kVPMIter != m_kMaps.end(); kVPMIter++)
        {
            string kName = kVPMIter->first;
            VMAPArray* pkVMAP = kVPMIter->second;
            *m_pkLogFile << ms_acTab << kName.c_str() << endl;
            *m_pkLogFile << ms_acTab << ms_acTab << "Elements: "
                << (int)pkVMAP->size() << endl;
        }
    }

    if ( m_kDiscontMaps.size() )
    {
        *m_pkLogFile << "Discontinuous UV maps: " << endl;
        VMADArrayMap::iterator kVDMIter = m_kDiscontMaps.begin();
        for (/**/;  kVDMIter != m_kDiscontMaps.end(); kVDMIter++)
        {
            string kName = kVDMIter->first;
            VMADArray* pkVMAD = kVDMIter->second;
            *m_pkLogFile << ms_acTab << kName.c_str() << endl;
            *m_pkLogFile << ms_acTab << ms_acTab << "Elements: "
                << (int)pkVMAD->size() << endl;
        }
    }
}
//----------------------------------------------------------------------------
string LightWaveReader::ReadEvenString (int* piBytes)
{
    string kStr;
    *piBytes = 0;
    bool bLoop = true;
    while ( bLoop )
    {
        char cCurrentChar = *m_pcCurrent++;
        ++(*piBytes);
        if ( cCurrentChar && DataAvailable() )
        {
            kStr += cCurrentChar;
        }
        else
        {
            if ( (*piBytes) & 1 )
            {
                ++m_pcCurrent;
                ++(*piBytes);
            }
            bLoop = false;
        }
    }
    return kStr;
}
//----------------------------------------------------------------------------
unsigned int LightWaveReader::ReadChunk (unsigned int uiFileSize)
{
    // Ensure enough data available to read chunk type and size.
    char* acEnd = m_acBuffer + uiFileSize - 8;
    if ( m_pcCurrent >= acEnd )
        return 0;

    unsigned int uiChunk;
    System::Read4be(m_pcCurrent,1,&uiChunk);
    m_pcCurrent += sizeof(unsigned int);

    unsigned int uiChunkSize;
    System::Read4be(m_pcCurrent,1,&uiChunkSize);
    m_pcCurrent += sizeof(unsigned int);

    if ( m_pkLogFile )
    {
        PrintChunkType(uiChunk);
        *m_pkLogFile << " size = " << uiChunkSize << endl;
    }
    if ( uiChunkSize & 1 )
        ++uiChunkSize;

    // Parse chunk or skip it if bad/unknown.  Return either number of bytes
    // in chunk or zero if end of file.
    if ( !ParseChunk(uiChunk,uiChunkSize) )
        m_pcCurrent += uiChunkSize;

    return DataAvailable() ? uiChunkSize : 0;
}
//----------------------------------------------------------------------------
bool LightWaveReader::ParseChunk (unsigned int uiChunk,
    unsigned int& ruiChunkSize)
{
    switch ( uiChunk )
    {
        case 'TAGS': return ParseTAGS(ruiChunkSize);
        case 'LAYR': return ParseLAYR(ruiChunkSize);
        case 'PNTS': return ParsePNTS(ruiChunkSize);
        case 'BBOX': return ParseBBOX(ruiChunkSize);
        case 'VMAP': return ParseVMAP(ruiChunkSize);
        case 'VMAD': return ParseVMAD(ruiChunkSize);
        case 'POLS': return ParsePOLS(ruiChunkSize);
        case 'PTAG': return ParsePTAG(ruiChunkSize);
        case 'CLIP': return ParseCLIP(ruiChunkSize);
        case 'SURF': return ParseSURF(ruiChunkSize);
    }
    return false;
}
//----------------------------------------------------------------------------
bool LightWaveReader::ParseTAGS (unsigned int uiChunkSize)
{
    // Tags are surface names.  Each surface will correspond to a triangle
    // mesh and associated auxiliary objects.

    int iLength = 0;
    int iCurrentTag = 0;
    while ( iLength < (int)uiChunkSize && DataAvailable() )
    {
        int iBytes;
        string kTag = ReadEvenString(&iBytes);
        iLength += iBytes;

        TriMesh* pkMesh = new TriMesh(0,0,false,false);
        PolygonList* pkPolygonList = new PolygonList;
        VertexMap* pkVertexMap = new VertexMap;

        m_kSurfaces[kTag] = pkMesh;
        m_kVertexMaps[kTag] = pkVertexMap;
        m_kPolygonLists[kTag] = pkPolygonList;
        m_kTagSurfaces[iCurrentTag] = pkMesh;
        m_kTagMap[iCurrentTag] = pkPolygonList;

        if ( m_pkLogFile )
            *m_pkLogFile << ms_acTab << kTag.c_str() << endl;
        iCurrentTag++;
    }
    return true;
}
//----------------------------------------------------------------------------
bool LightWaveReader::ParseLAYR (unsigned int uiChunkSize)
{
    // There might be multiple layers per file, each containing its own
    // object, but we only support the first object in the first layer.  We
    // parse the chunk anyway to report/prevent errors.

    const int iMinSize = (3*sizeof(unsigned short)) + sizeof(Vector3f);
    if ( (int)uiChunkSize < iMinSize )
    {
        if ( m_pkLogFile )
        {
            *m_pkLogFile << ms_acTab << "not enough bytes in LAYR chunk!"
                << endl;
        }
        m_eError = LWR_BAD_LAYR_CHUNK;
        return false;
    }

    unsigned short usLayerNumber;
    System::Read2be(m_pcCurrent,1,&usLayerNumber);
    m_pcCurrent += sizeof(unsigned short);

    unsigned short usLayerFlags;
    System::Read2be(m_pcCurrent,1,&usLayerFlags);
    m_pcCurrent += sizeof(unsigned short);

    Vector3f kLayerPivot;
    System::Read4be(m_pcCurrent,3,(float*)kLayerPivot);
    m_pcCurrent += sizeof(Vector3f);

    unsigned short usSubSize = sizeof(usLayerNumber) + sizeof(usLayerFlags) +
        sizeof(kLayerPivot);

    int iBytes = 0;
    string kLayerName;
    if ( (int)uiChunkSize > iMinSize )
        kLayerName = ReadEvenString(&iBytes);
    else
        kLayerName = "(unnamed)";

    unsigned short usLayerParent = 0;
    usSubSize += (unsigned short)iBytes;
    if ( usSubSize < (unsigned short)uiChunkSize )
    {
        System::Read2be(m_pcCurrent,1,&usLayerParent);
        m_pcCurrent += sizeof(unsigned short);
    }

    if ( m_pkLogFile )
    {
        *m_pkLogFile << ms_acTab << "number = " << usLayerNumber << endl;
        *m_pkLogFile << ms_acTab << "flags  = "
            << (usLayerFlags & 1 ? "hidden" : "normal") << endl;
        *m_pkLogFile << ms_acTab << "pivot  = ("
            << kLayerPivot[0] << ","
            << kLayerPivot[1] << ","
            << kLayerPivot[2] << ")"
            << endl;
        *m_pkLogFile << ms_acTab << "name   = " << kLayerName.c_str() << endl;
        *m_pkLogFile << ms_acTab << "parent = " << usLayerParent << endl;
    }
    return true;
}
//----------------------------------------------------------------------------
bool LightWaveReader::ParsePNTS (unsigned int uiChunkSize)
{
    // Raw geometric data (e.g. vertices) are represented by points.  Ensure
    // there is enough data in the chunk while reading it.

    unsigned int uiNumPoints = uiChunkSize / sizeof(Vector3f);
    if ( m_pkLogFile )
    {
        *m_pkLogFile << ms_acTab << "number of points = " << uiNumPoints
            << endl;
    }

    for (int iIndex = 0; iIndex < (int)uiNumPoints; iIndex++)
    {
        if ( !DataAvailable() )
        {
            m_eError = LWR_BAD_PNTS_CHUNK;
            return false;
        }

        Vector3f kPoint;
        System::Read4be(m_pcCurrent,3,(float*)kPoint);
        m_pcCurrent += sizeof(Vector3f);
        m_akVertices.push_back(kPoint);
        PolygonList* pkPolygonList = new PolygonList;
        m_akVertexToPolygon.push_back(pkPolygonList);

        if ( m_pkLogFile )
        {
            *m_pkLogFile << ms_acTab << "("
                << kPoint[0] << ","
                << kPoint[1] << ","
                << kPoint[2] << ")"
                << endl;
        }
    }
    return true;
}
//----------------------------------------------------------------------------
bool LightWaveReader::ParseBBOX (unsigned int uiChunkSize)
{
    // Object bounding box.  This will usually be present, and it is needed if
    // we wish to unitize the model before using it.

    if ( uiChunkSize < 2*sizeof(Vector3f) )
    {
        if ( m_pkLogFile )
        {
            *m_pkLogFile << ms_acTab << "not enough bytes in BBOX chunk!"
                << endl;
        }
        m_eError = LWR_BAD_BBOX_CHUNK;
        return false;
    }

    Vector3f kMinPoint;
    System::Read4be(m_pcCurrent,3,(float*)kMinPoint);
    m_pcCurrent += sizeof(Vector3f);

    Vector3f kMaxPoint;
    System::Read4be(m_pcCurrent,3,(float*)kMaxPoint);
    m_pcCurrent += sizeof(Vector3f);

    if ( m_pkLogFile )
    {
        *m_pkLogFile << ms_acTab << "min = ("
            << kMinPoint[0] << ","
            << kMinPoint[1] << ","
            << kMinPoint[2] << ")"
            << endl;
        *m_pkLogFile << ms_acTab << "max = ("
            << kMaxPoint[0] << ","
            << kMaxPoint[1] << ","
            << kMaxPoint[2] << ")"
            << endl;
    }

#if LWREADER_UNITIZE_MODEL
    // compute required dimensions
    float fW = Math::FAbs(kMinPoint.x) + Math::FAbs(kMaxPoint.x);
    float fH = Math::FAbs(kMinPoint.y) + Math::FAbs(kMaxPoint.y);
    float fD = Math::FAbs(kMinPoint.z) + Math::FAbs(kMaxPoint.z);

    // compute rescaling factor and scale all vertices
    float fScale = 2.0f/max(max(fW,fH),fD);    
    for (int iIndex = 0; iIndex < m_akVertices.size(); iIndex++)
        m_akVertices[iIndex] *= fScale;

#endif

    return true;
}
//----------------------------------------------------------------------------
bool LightWaveReader::ParseVMAP (unsigned int& ruiChunkSize)
{
    // Vertex map: vertex and texture coords.  Ensure the chunk is properly
    // structured.

    unsigned int uiChunkType;
    System::Read4be(m_pcCurrent,1,&uiChunkType);
    m_pcCurrent += sizeof(unsigned int);

    unsigned short usDim ;
    System::Read2be(m_pcCurrent,1,&usDim);
    m_pcCurrent += sizeof(unsigned short);

    unsigned int uiSubSize = sizeof(uiChunkType) + sizeof(usDim);

    if ( uiChunkType != 'TXUV' || usDim != 2 )
    {
        if ( m_pkLogFile )
        {
            *m_pkLogFile << ms_acTab
                << "only 2D TXUV subchunks are supported!" << endl;
        }
        m_pcCurrent -= uiSubSize;
        return false;
    }

    int iBytes;
    string kName = ReadEvenString(&iBytes);
    uiSubSize += iBytes;

    if ( m_pkLogFile )
    {
        *m_pkLogFile << ms_acTab;
        PrintChunkType(uiChunkType);
        *m_pkLogFile << endl;
        *m_pkLogFile << ms_acTab << ms_acTab << "dimension = " << usDim
            << endl;
        *m_pkLogFile << ms_acTab << ms_acTab << "name      = "
            << kName.c_str() << endl;
    }

    VMAPArray* pkMap = new VMAPArray;
    while ( uiSubSize < ruiChunkSize && DataAvailable() )
    {
        unsigned short usVertex;
        System::Read2be(m_pcCurrent,1,&usVertex);
        m_pcCurrent += sizeof(unsigned short);

        float fCoordU;
        System::Read4be(m_pcCurrent,1,&fCoordU);
        m_pcCurrent += sizeof(float);

        float fCoordV;
        System::Read4be(m_pcCurrent,1,&fCoordV);
        m_pcCurrent += sizeof(float);

        if ( m_pkLogFile )
        {
            *m_pkLogFile << ms_acTab << ms_acTab << "vertex = " << usVertex
                << " U = " << fCoordU << " V = " << fCoordV << endl;
        }

        pkMap->push_back(VMAP(usVertex,fCoordU,fCoordV));
        uiSubSize += sizeof(usVertex) + sizeof(fCoordU) + sizeof(fCoordV);
    }
    m_kMaps[kName] = pkMap;

    return true;
}
//----------------------------------------------------------------------------
bool LightWaveReader::ParseVMAD (unsigned int& ruiChunkSize)
{
    // Discontinous vertex map: vertex, polygon and texture coords.  Ensure
    // the chunk is properly structured.

    unsigned int uiChunkType;
    System::Read4be(m_pcCurrent,1,&uiChunkType);
    m_pcCurrent += sizeof(unsigned int);

    unsigned short usDim;
    System::Read2be(m_pcCurrent,1,&usDim);
    m_pcCurrent += sizeof(unsigned short);

    unsigned int uiSubSize = sizeof(uiChunkType) + sizeof(usDim);

    if ( uiChunkType != 'TXUV' || usDim != 2 )
    {
        if ( m_pkLogFile )
        {
            *m_pkLogFile << ms_acTab
                << "only 2D TXUV subchunks are supported!" << endl;
        }
        m_pcCurrent -= uiSubSize;
        return false;
    }

    int iBytes;
    string kName = ReadEvenString(&iBytes);
    uiSubSize += iBytes;

    if ( m_pkLogFile )
    {
        *m_pkLogFile << ms_acTab;
        PrintChunkType(uiChunkType);
        *m_pkLogFile << endl;
        *m_pkLogFile << ms_acTab << ms_acTab << "dimension = " << usDim
            << endl;
        *m_pkLogFile << ms_acTab << ms_acTab << "name      = "
            << kName.c_str() << endl;
    }

    VMADArray* pkMap = new VMADArray;
    while ( uiSubSize < ruiChunkSize && DataAvailable() )
    {
        unsigned short usVertex;
        System::Read2be(m_pcCurrent,1,&usVertex);
        m_pcCurrent += sizeof(unsigned short);

        unsigned short usPolygon;
        System::Read2be(m_pcCurrent,1,&usPolygon);
        m_pcCurrent += sizeof(unsigned short);

        float fCoordU;
        System::Read4be(m_pcCurrent,1,&fCoordU);
        m_pcCurrent += sizeof(float);

        float fCoordV;
        System::Read4be(m_pcCurrent,1,&fCoordV);
        m_pcCurrent += sizeof(float);

        if ( m_pkLogFile )
        {
            *m_pkLogFile << ms_acTab << ms_acTab << "vertex = " << usVertex
                << " polygon = " << usPolygon << " U = " << fCoordU
                << " V = " << fCoordV << endl;
        }

        pkMap->push_back(VMAD(usVertex,usPolygon,fCoordU,fCoordV));
        uiSubSize += sizeof(usVertex) + sizeof(usPolygon) + sizeof(fCoordU) +
            sizeof(fCoordV);
    }
    m_kDiscontMaps[kName] = pkMap;

    return true;
}
//----------------------------------------------------------------------------
bool LightWaveReader::ParsePOLS (unsigned int uiChunkSize)
{
    // Polygon (that is, triangles) description.  Insist on standard polygons
    // (no funky LightWave 3D entities).

    unsigned int uiChunkType;
    System::Read4be(m_pcCurrent,1,&uiChunkType);
    m_pcCurrent += sizeof(unsigned int);

    if ( uiChunkType != 'FACE' )
    {
        if ( m_pkLogFile )
        {
            *m_pkLogFile << ms_acTab << "unsupported polygon type: ";
            PrintChunkType(uiChunkType);
            *m_pkLogFile << endl;
        }
        m_pcCurrent -= sizeof(uiChunkType);
        return false;
    }

    if ( m_pkLogFile )
    {
        *m_pkLogFile << ms_acTab;
        PrintChunkType(uiChunkType);
        *m_pkLogFile << endl;
    }

    // We only support triangles with 2-byte indices.  This imposes a limit of
    // 64K triangles per object.
    int iPolygonIndex = 0;
    unsigned int uiTotalBytes = sizeof(uiChunkType);
    while ( uiTotalBytes < uiChunkSize && DataAvailable() )
    {
        unsigned short usVertexCount;
        System::Read2be(m_pcCurrent,1,&usVertexCount);
        m_pcCurrent += sizeof(unsigned short);

        uiTotalBytes += sizeof(usVertexCount);
        usVertexCount &= 0x03FF;

        if ( usVertexCount == 3 )
        {
            // For each vertex in the triangle, we compute its plane normal by
            // extracting its vertex data, contained in the previous chunk.
            unsigned short usFirst;
            System::Read2be(m_pcCurrent,1,&usFirst);
            m_pcCurrent += sizeof(unsigned short);

            unsigned short usSecond;
            System::Read2be(m_pcCurrent,1,&usSecond);
            m_pcCurrent += sizeof(unsigned short);

            unsigned short usThird;
            System::Read2be(m_pcCurrent,1,&usThird);
            m_pcCurrent += sizeof(unsigned short);

            uiTotalBytes += sizeof(usFirst) + sizeof(usSecond) +
                sizeof(usThird);

            Vector3f kNormal = ComputePlaneNormal(m_akVertices[usFirst],
                m_akVertices[usSecond],m_akVertices[usThird]);
            Triangle kTriangle(usFirst,usSecond,usThird,kNormal);
            m_akPolygons.push_back(kTriangle);
            if ( m_pkLogFile )
            {
                *m_pkLogFile << ms_acTab << ms_acTab << "triangle(" << usFirst
                    << ", " << usSecond << ", " << usThird << ")" << endl;
            }

            // We keep a list of polygons per vertex, which helps us process
            // model data while computing LightWave normals.
            PolygonList* pkPolygonList = m_akVertexToPolygon[usFirst];
            pkPolygonList->push_back(iPolygonIndex);
            pkPolygonList = m_akVertexToPolygon[usSecond];
            pkPolygonList->push_back(iPolygonIndex);
            pkPolygonList = m_akVertexToPolygon[usThird];
            pkPolygonList->push_back(iPolygonIndex);
        }
        else
        {
            if ( m_pkLogFile )
            {
                *m_pkLogFile << ms_acTab << ms_acTab << usVertexCount
                    << "-sided polygon: ";
                *m_pkLogFile << "only triangles are supported!" << endl;
            }
            m_eError = LWR_UNSUPPORTED_POLYGON_TYPE;
            return false;
        }

        iPolygonIndex++;
    }

    return true;
}
//----------------------------------------------------------------------------
bool LightWaveReader::ParsePTAG (unsigned int uiChunkSize)
{
    // Polygon tags associate polygons (that is, triangles) to surfaces.
    // Trimesh creation collects all triangles for a given tag.
    unsigned int uiChunkType;
    System::Read4be(m_pcCurrent,1,&uiChunkType);
    m_pcCurrent += sizeof(unsigned int);

    if ( m_pkLogFile ) 
    {
        *m_pkLogFile << ms_acTab;
        PrintChunkType(uiChunkType);
        *m_pkLogFile << endl;
    }

    if ( uiChunkType != 'SURF' )
    {
        if ( m_pkLogFile )
        {
            *m_pkLogFile << ms_acTab << "we only support SURF subchunks!"
                << endl;
        }
        m_pcCurrent -= sizeof(uiChunkType);
        return false;
    }

    unsigned int uiTotalBytes = sizeof(uiChunkType);
    while ( uiTotalBytes < uiChunkSize && DataAvailable() )
    {
        unsigned short usPolygonIndex;
        System::Read2be(m_pcCurrent,1,&usPolygonIndex);
        m_pcCurrent += sizeof(unsigned short);

        unsigned short usSurfaceTag;
        System::Read2be(m_pcCurrent,1,&usSurfaceTag);
        m_pcCurrent += sizeof(unsigned short);

        uiTotalBytes += sizeof(usPolygonIndex) + sizeof(usSurfaceTag);

        PolygonList* pkPolyList = m_kTagMap[usSurfaceTag];
        pkPolyList->push_back(usPolygonIndex);
        m_kPolygonTags[usPolygonIndex] = usSurfaceTag;
        if ( m_pkLogFile )
        {
            *m_pkLogFile << ms_acTab << ms_acTab << "polygon = "
                << usPolygonIndex << " tag = " << usSurfaceTag << endl;
        }
    }
    return true;
}
//----------------------------------------------------------------------------
bool LightWaveReader::ParseCLIP (unsigned int& ruiChunkSize)
{
    // Clips are textures.  Ensure the chunk is properly formed and represents
    // a still image.
    unsigned int uiIndex;
    System::Read4be(m_pcCurrent,1,&uiIndex);
    m_pcCurrent += sizeof(unsigned int);

    unsigned int uiTotalBytes = sizeof(uiIndex);

    unsigned int uiChunkType;
    System::Read4be(m_pcCurrent,1,&uiChunkType);
    m_pcCurrent += sizeof(unsigned int);

    if ( m_pkLogFile )
    {
        *m_pkLogFile << ms_acTab << "index = " << uiIndex << endl;
        *m_pkLogFile << ms_acTab;
        PrintChunkType(uiChunkType);
    }
    uiTotalBytes += sizeof(uiChunkType);

    // We only support still images: no animated textures yet.
    if ( uiChunkType != 'STIL' )
    {
        if ( m_pkLogFile )
        {
            *m_pkLogFile << endl << ms_acTab << "unsupported clip type: ";
            PrintChunkType(uiChunkType);
            *m_pkLogFile << endl;
        }
        m_pcCurrent -= uiTotalBytes;
        return false;
    }

    // read subchunk size
    unsigned short usSubSize;
    System::Read2be(m_pcCurrent,1,&usSubSize);
    m_pcCurrent += sizeof(unsigned short);

    uiTotalBytes += sizeof(usSubSize);

    // read image name
    int iBytes;
    string kFileName = ReadEvenString(&iBytes);
    if ( m_pkLogFile )
    {
        *m_pkLogFile << " size = " << usSubSize << endl;
        *m_pkLogFile << ms_acTab << ms_acTab << kFileName.c_str() << endl;
    }
    uiTotalBytes += iBytes;

    if ( uiTotalBytes < ruiChunkSize )
    {
        if ( m_pkLogFile )
            *m_pkLogFile << ms_acTab << "incomplete CLIP chunk!" << endl;
        m_pcCurrent -= uiTotalBytes;
        return false;
    }    

    // Load texture and add it to array so that other surfaces can use it
    // without having to duplicate its data.
    const char* acTFileName = strrchr(kFileName.c_str(),'/');
    if ( !acTFileName )
        return false;

    acTFileName++;
    bool bTextureLoaded = AddTexture(acTFileName);
    if ( !bTextureLoaded )
        m_eError = LWR_UNSUPPORTED_TEXTURE_TYPE;

    return bTextureLoaded;
}
//----------------------------------------------------------------------------
bool LightWaveReader::ParseSURF (unsigned int& ruiChunkSize)
{
    // Surface description.  We only support a subset of the possible chunks.
    int iBytes;
    string kName = ReadEvenString(&iBytes);
    unsigned int uiTotalBytes = (unsigned int)iBytes;
    string kSource = ReadEvenString(&iBytes);
    uiTotalBytes += (unsigned int)iBytes;

    if ( m_pkLogFile )
    {
        *m_pkLogFile << ms_acTab << "name   = " << kName.c_str() << endl;
        *m_pkLogFile << ms_acTab << "source = " << kSource.c_str() << endl;
    }

    // Set up current surface as default and build preliminary trimesh
    // representation.
    m_kCurrentSurface = kName;
    m_kCurrentColor = ColorRGBA::WHITE;
    m_pkCurrentMesh = m_kSurfaces[kName];
    m_pkCurrentPolyList = m_kPolygonLists[kName];
    m_pkCurrentMesh->SetName(m_kCurrentSurface.c_str());
    BuildTriMesh();

    // scan all known surface subchunks
    int iIndent = 2;
    int iNumBLOKs = 0;

    while ( uiTotalBytes < ruiChunkSize && DataAvailable() )
    {
        unsigned short usSubSize = 0;
        bool bSuccess = ParseSURFSubchunk(usSubSize,iNumBLOKs,iIndent);
        uiTotalBytes += (unsigned int)usSubSize;
        if ( !bSuccess )
        {
            m_pcCurrent -= uiTotalBytes;
            return false;
        }
    }

    return true;
}
//----------------------------------------------------------------------------
bool LightWaveReader::ParseSURFSubchunk (unsigned short& rusSubSize,
    int& riNumBLOKs, int iIndent)
{
    // Parse and possibly represent all relevant surface subchunks.  Note that
    // some of them are not feasible to represent with WildMagic as of version
    // 1.2.
    
    unsigned int uiSubchunk;
    System::Read4be(m_pcCurrent,1,&uiSubchunk);
    m_pcCurrent += sizeof(unsigned int);
    rusSubSize += sizeof(uiSubchunk);

    unsigned short usCurSize;
    System::Read2be(m_pcCurrent,1,&usCurSize);
    m_pcCurrent += sizeof(unsigned short);
    rusSubSize += sizeof(usCurSize);

    if ( m_pkLogFile )
        PrintChunkInfo(uiSubchunk,usCurSize,iIndent);

    bool bSupported = true;
    switch ( uiSubchunk )
    {
        case 'COLR':
        {
            // Basic surface color.  This will be reset for textured surfaces.
            // For plain surfaces, it corresponds to the ambient color.
            rusSubSize += usCurSize;

            float fRed;
            System::Read4be(m_pcCurrent,1,&fRed);
            m_pcCurrent += sizeof(float);

            float fGreen;
            System::Read4be(m_pcCurrent,1,&fGreen);
            m_pcCurrent += sizeof(float);

            float fBlue;
            System::Read4be(m_pcCurrent,1,&fBlue);
            m_pcCurrent += sizeof(float);

            unsigned short usEnvelope;
            System::Read2be(m_pcCurrent,1,&usEnvelope);
            m_pcCurrent += sizeof(unsigned short);

            m_kCurrentColor = ColorRGBA(fRed,fGreen,fBlue,1.0f);
            MaterialStatePtr pkMaterialState = new MaterialState;
            pkMaterialState->Ambient = m_kCurrentColor;
            m_pkCurrentMesh->SetGlobalState(pkMaterialState);

            if ( m_pkLogFile )
            {
                PrintIndent(iIndent+1);
                *m_pkLogFile << "(r:" << fRed << ", g:" << fGreen << ", b:"
                    << fBlue << ")";
                if ( usEnvelope )
                    *m_pkLogFile << ", envelope = " << usEnvelope;
                *m_pkLogFile << endl;
            }
        }
        break;

        case 'DIFF':
        {
            // Diffuse reflection component.
            rusSubSize += usCurSize;

            float fDiffuse;
            System::Read4be(m_pcCurrent,1,&fDiffuse);
            m_pcCurrent += sizeof(float);

            unsigned short usEnvelope;
            System::Read2be(m_pcCurrent,1,&usEnvelope);
            m_pcCurrent += sizeof(unsigned short);

            ColorRGBA kColor(m_kCurrentColor);
            kColor = fDiffuse*kColor;
            GlobalState* pkGlobalState =
                m_pkCurrentMesh->GetGlobalState(GlobalState::MATERIAL);
            MaterialState* pkMaterialState = 
                DynamicCast<MaterialState>(pkGlobalState);
            pkMaterialState->Diffuse = kColor;

            if ( m_pkLogFile )
            {
                PrintIndent(iIndent+1);
                *m_pkLogFile << "diffuse = " << 100.0f*fDiffuse << "%";
                if ( usEnvelope )
                    *m_pkLogFile << ", envelope = " << usEnvelope;
                *m_pkLogFile << endl;
            }
        }
        break;

        case 'LUMI':
        {
            // Surface luminance. Currently unsupported.
            rusSubSize += usCurSize;

            float fLuminance;
            System::Read4be(m_pcCurrent,1,&fLuminance);
            m_pcCurrent += sizeof(float);

            unsigned short usEnvelope;
            System::Read2be(m_pcCurrent,1,&usEnvelope);
            m_pcCurrent += sizeof(unsigned short);

            // TODO. How to add luminance using a RenderState?
            if ( m_pkLogFile )
            {
                PrintIndent(iIndent+1);
                *m_pkLogFile << "luminance = " << 100.0f*fLuminance << "%";
                if ( usEnvelope )
                    *m_pkLogFile << ", envelope = " << usEnvelope;
                *m_pkLogFile << endl;
            }
        }
        break;

        case 'SPEC':
        {
            // Specular reflection component.
            rusSubSize += usCurSize;

            float fSpecular;
            System::Read4be(m_pcCurrent,1,&fSpecular);
            m_pcCurrent += sizeof(float);

            unsigned short usEnvelope;
            System::Read2be(m_pcCurrent,1,&usEnvelope);
            m_pcCurrent += sizeof(unsigned short);

            ColorRGBA kColor(m_kCurrentColor);
            kColor = fSpecular*kColor;
            GlobalState* pkGlobalState =
                m_pkCurrentMesh->GetGlobalState(GlobalState::MATERIAL);
            MaterialState* pkMaterialState = 
                DynamicCast<MaterialState>(pkGlobalState);
            pkMaterialState->Specular = kColor;

            if ( m_pkLogFile )
            {
                PrintIndent(iIndent+1);
                *m_pkLogFile << "specular = " << 100.0f*fSpecular << "%";
                if ( usEnvelope )
                    *m_pkLogFile << ", envelope = " << usEnvelope;
                *m_pkLogFile << endl;
            }
        }
        break;

        case 'GLOS':
        {
            // Surface glossiness. Currently unsupported.
            rusSubSize += usCurSize;

            float fGlossiness;
            System::Read4be(m_pcCurrent,1,&fGlossiness);
            m_pcCurrent += sizeof(float);

            unsigned short usEnvelope;
            System::Read2be(m_pcCurrent,1,&usEnvelope);
            m_pcCurrent += sizeof(unsigned short);

            // TODO. How to add glossiness using a RenderState?
            
            if ( m_pkLogFile )
            {
                PrintIndent(iIndent+1);
                *m_pkLogFile << "glossiness = " << 100.0f*fGlossiness << "%";
                if ( usEnvelope )
                    *m_pkLogFile << ", envelope = " << usEnvelope;
                *m_pkLogFile << endl;
            }
        }
        break;

        case 'REFL':
        {
            // Reflection component. Currently unsupported.
            rusSubSize += usCurSize;

            float fReflection;
            System::Read4be(m_pcCurrent,1,&fReflection);
            m_pcCurrent += sizeof(float);

            unsigned short usEnvelope;
            System::Read2be(m_pcCurrent,1,&usEnvelope);
            m_pcCurrent += sizeof(unsigned short);

            // TODO. How to add reflection using a RenderState?

            if ( m_pkLogFile )
            {
                PrintIndent(iIndent+1);
                *m_pkLogFile << "reflection = " << 100.0f*fReflection << "%";
                if ( usEnvelope )
                    *m_pkLogFile << ", envelope = " << usEnvelope;
                *m_pkLogFile << endl;
            }
        }
        break;

        case 'CLRH':
        {
            // Specular highlight component.
            rusSubSize += usCurSize;

            float fHighlights;
            System::Read4be(m_pcCurrent,1,&fHighlights);
            m_pcCurrent += sizeof(float);

            unsigned short usEnvelope;
            System::Read2be(m_pcCurrent,1,&usEnvelope);
            m_pcCurrent += sizeof(unsigned short);

            GlobalState* pkGlobalState =
                m_pkCurrentMesh->GetGlobalState(GlobalState::MATERIAL);
            MaterialState* pkMaterialState = 
                DynamicCast<MaterialState>(pkGlobalState);
            pkMaterialState->Shininess = 128.0f*fHighlights;

            if ( m_pkLogFile )
            {
                PrintIndent(iIndent+1);
                *m_pkLogFile << "color highlights = " << 100.0f*fHighlights
                    << "%";
                if ( usEnvelope )
                    *m_pkLogFile << ", envelope = " << usEnvelope;
                *m_pkLogFile << endl;
            }
        }
        break;

        case 'TRAN':
        {
            // Surface transparency. Currently unsupported.
            rusSubSize += usCurSize;

            float fTransparency;
            System::Read4be(m_pcCurrent,1,&fTransparency);
            m_pcCurrent += sizeof(float);

            unsigned short usEnvelope;
            System::Read2be(m_pcCurrent,1,&usEnvelope);
            m_pcCurrent += sizeof(unsigned short);

            // TODO. How to add transparency using a RenderState?

            if ( m_pkLogFile )
            {
                PrintIndent(iIndent+1);
                *m_pkLogFile << "transparency = " << 100.0f*fTransparency
                    << "%";
                if ( usEnvelope )
                    *m_pkLogFile << ", envelope = " << usEnvelope;
                *m_pkLogFile << endl;
            }
        }
        break;

        case 'TRNL':
        {
            // Surface translucency. Currently unsupported.
            rusSubSize += usCurSize;

            float fTranslucency;
            System::Read4be(m_pcCurrent,1,&fTranslucency);
            m_pcCurrent += sizeof(float);

            unsigned short usEnvelope;
            System::Read2be(m_pcCurrent,1,&usEnvelope);
            m_pcCurrent += sizeof(unsigned short);

            // TODO. How to add translucency using a RenderState?

            if ( m_pkLogFile )
            {
                PrintIndent(iIndent+1);
                *m_pkLogFile << "translucency = " << 100.0f*fTranslucency
                    << "%";
                if ( usEnvelope )
                    *m_pkLogFile << ", envelope = " << usEnvelope;
                *m_pkLogFile << endl;
            }
        }
        break;

        case 'SMAN':
        {
            // Smoothing angle for this surface.  Used in normals computation.
            rusSubSize += usCurSize;

            float fSmoothingAngle;
            System::Read4be(m_pcCurrent,1,&fSmoothingAngle);
            m_pcCurrent += sizeof(float);

            m_kAngles[m_kCurrentSurface] = fSmoothingAngle;

            if ( m_pkLogFile )
            {
                PrintIndent(iIndent+1);
                *m_pkLogFile << "angle = "
                    << Mathf::RAD_TO_DEG*fSmoothingAngle << endl;
            }
        }
        break;

        case 'BLOK':
        {
            // Block description of current surface.
            if ( riNumBLOKs < 1 )
            {
                unsigned short usSizeBLOKSubchunk =
                    ParseBLOKSubchunk(iIndent+1,bSupported);
                if ( !bSupported )
                {
                    m_pcCurrent += usCurSize - rusSubSize;
                    rusSubSize += usCurSize;
                }
                else
                {
                    riNumBLOKs++;
                    rusSubSize += usSizeBLOKSubchunk;
                }
            }
            else
            {
                if ( m_pkLogFile )
                {
                    PrintIndent(iIndent+1);
                    *m_pkLogFile << "(skipped)" << endl;
                }
                rusSubSize += usCurSize;
                m_pcCurrent += usCurSize;
            }
        }
        break;

        default:
        {
            rusSubSize += usCurSize;
            m_pcCurrent += usCurSize;
        }
    }

    return true;
}
//----------------------------------------------------------------------------
unsigned short LightWaveReader::ParseBLOKSubchunk (int iIndent,
    bool& rbSupported)
{
    // Generic surface block description.  We only support one per surface,
    // thereby imposing single textured and single coloured surfaces.  Also,
    // we only support image maps.

    unsigned int uiChunkType;
    System::Read4be(m_pcCurrent,1,&uiChunkType);
    m_pcCurrent += sizeof(unsigned int);

    unsigned short usChunkSize = sizeof(uiChunkType);

    unsigned short usSubSize;
    System::Read2be(m_pcCurrent,1,&usSubSize);
    m_pcCurrent += sizeof(unsigned short);

    usChunkSize += sizeof(usSubSize);

    if ( m_pkLogFile )
        PrintChunkInfo(uiChunkType,usSubSize,iIndent);

    switch ( uiChunkType )
    {
        case 'IMAP':
        {
            usChunkSize += ParseIMAPSubchunk(usSubSize,iIndent+1);
        }
        break;

        case 'PROC':
        {
            if ( m_pkLogFile )
            {
                PrintIndent(iIndent);
                *m_pkLogFile << "unsupported!" << endl;
            }
            usChunkSize += usSubSize;
            rbSupported = false;
        }
        break;

        case 'GRAD':
        {
            if ( m_pkLogFile )
            {
                PrintIndent(iIndent);
                *m_pkLogFile << "unsupported!" << endl;
            }
            usChunkSize += usSubSize;
            rbSupported = false;
        }
        break;

        case 'SHDR':
        {
            if ( m_pkLogFile )
            {
                PrintIndent(iIndent);
                *m_pkLogFile << "unsupported!" << endl;
            }
            usChunkSize += usSubSize;
            rbSupported = false;
        }
        break;
    }

    return usChunkSize;
}
//----------------------------------------------------------------------------
unsigned short LightWaveReader::ParseBLOKHeader (int iIndent)
{
    // Surface block description header information is currently unused.
    // Read ordinal string.

    int iBytes;
    string kOrdinal = ReadEvenString(&iBytes);
    unsigned short usChunkSize = (unsigned short)iBytes;
    for (int iIndex = 0; iIndex < (int)kOrdinal.length(); iIndex++)
        kOrdinal[iIndex] = (kOrdinal[iIndex] - 0x80) + 0x30;

    if ( m_pkLogFile )
    {
        PrintIndent(iIndent);
        *m_pkLogFile << "ordinal = \"" << kOrdinal.c_str() << "\"" << endl;
    }

    // Read channel information.
    unsigned int uiChunkType;
    System::Read4be(m_pcCurrent,1,&uiChunkType);
    m_pcCurrent += sizeof(unsigned int);

    usChunkSize += sizeof(uiChunkType);
    if ( uiChunkType != 'CHAN' )
    {
        if ( m_pkLogFile )
        {
            PrintIndent(iIndent);
            *m_pkLogFile << "missing channel information!" << endl;
        }
        m_eError = LWR_MISSING_CHANNEL;
        return usChunkSize;
    }

    unsigned short usSubSize;
    System::Read2be(m_pcCurrent,1,&usSubSize);
    m_pcCurrent += sizeof(unsigned short);

    usChunkSize += sizeof(usSubSize);
    if ( m_pkLogFile )
    {
        PrintIndent(iIndent);
        PrintChunkType(uiChunkType);
        *m_pkLogFile << endl;
    }

    // Read channel destination.
    unsigned int uiChan;
    System::Read4be(m_pcCurrent,1,&uiChan);
    m_pcCurrent += sizeof(unsigned int);

    usChunkSize += sizeof(uiChan);
    if ( m_pkLogFile )
    {
        PrintIndent(iIndent+1);
        PrintChunkType(uiChan);
        *m_pkLogFile << endl;
    }

    // Read rest of header.  Up to three components can be found in the BLOK
    // header.
    usChunkSize += ParseBLOKHeaderComponent(iIndent);
    usChunkSize += ParseBLOKHeaderComponent(iIndent);
    usChunkSize += ParseBLOKHeaderComponent(iIndent);

    return usChunkSize;
}
//----------------------------------------------------------------------------
unsigned short LightWaveReader::ParseBLOKHeaderComponent (int iIndent)
{
    // Subcomponents of surface block description header.  We can find either
    // an OPAC, an ENAB or a NEGA subblock, or all of them, but currently we
    // don't support any.

    unsigned int uiHeader;
    System::Read4be(m_pcCurrent,1,&uiHeader);
    m_pcCurrent += sizeof(unsigned int);

    unsigned short usChunkSize = sizeof(uiHeader);

    unsigned short usHeaderSize;
    System::Read2be(m_pcCurrent,1,&usHeaderSize);
    m_pcCurrent += sizeof(unsigned short);

    usChunkSize += sizeof(usHeaderSize);

    if ( uiHeader == 'ENAB' || uiHeader == 'OPAC' || uiHeader == 'NEGA' )
    {
        if ( m_pkLogFile )
        {
            PrintIndent(iIndent);
            PrintChunkType(uiHeader);
            *m_pkLogFile << endl;
        }
    }

    switch ( uiHeader )
    {
        case 'ENAB':
        {
            unsigned short usEnabled;
            System::Read2be(m_pcCurrent,1,&usEnabled);
            m_pcCurrent += sizeof(unsigned short);

            usChunkSize += sizeof(usEnabled);
            if ( m_pkLogFile )
            {
                PrintIndent(iIndent+1);
                *m_pkLogFile << (usEnabled ? "enabled" : "disabled") << endl;
            }
        }
        break;

        case 'OPAC':
        {
            unsigned short usOpacityType;
            System::Read2be(m_pcCurrent,1,&usOpacityType);
            m_pcCurrent += sizeof(unsigned short);

            float fOpacity;
            System::Read4be(m_pcCurrent,1,&fOpacity);
            m_pcCurrent += sizeof(float);

            unsigned short usEnvelope;
            System::Read2be(m_pcCurrent,1,&usEnvelope);
            m_pcCurrent += sizeof(unsigned short);

            usChunkSize += sizeof(usOpacityType) + sizeof(fOpacity) +
                sizeof(usEnvelope);

            if ( m_pkLogFile )
            {
                PrintIndent(iIndent+1);
                switch ( usOpacityType )
                {
                    case 0:   *m_pkLogFile << "additive"; break;
                    case 1:   *m_pkLogFile << "subtractive"; break;
                    case 2:   *m_pkLogFile << "difference"; break;
                    case 3:   *m_pkLogFile << "multiply"; break;
                    case 4:   *m_pkLogFile << "divide"; break;
                    case 5:   *m_pkLogFile << "alpha"; break;
                    case 6:   *m_pkLogFile << "texture displacement"; break;
                    default:  *m_pkLogFile << "unknown opacity type";
                }
                *m_pkLogFile << " " << 100.0f*fOpacity << "%";
                if ( usEnvelope )
                    *m_pkLogFile << ", envelope = " << usEnvelope;
                *m_pkLogFile << endl;
            }
        }
        break;

        case 'NEGA':
        {
            unsigned short usNegated;
            System::Read2be(m_pcCurrent,1,&usNegated);
            m_pcCurrent += sizeof(unsigned short);

            usChunkSize += sizeof(usNegated);

            if ( m_pkLogFile )
            {
                PrintIndent(iIndent+1);
                *m_pkLogFile << (usNegated ? "negated" : "non-negated")
                    << endl;
            }
        }
        break;

        default:
        {
            // Back up, we've entered another subchunk.
            short usOffset = sizeof(uiHeader) + sizeof(usHeaderSize);
            usChunkSize -= usOffset;
            m_pcCurrent -= usOffset;
        }
    }

    return usChunkSize;
}
//----------------------------------------------------------------------------
unsigned short LightWaveReader::ParseIMAPSubchunk (unsigned short usSizeIMAP,
    int iIndent)
{
    // Image maps contain texture information and layout.  Get rid of tedious
    // header bookkeeping.

    unsigned short usChunkSize = ParseBLOKHeader(iIndent);    

    // Now the header is behind us, let's do some real parsing.
    usSizeIMAP -= usChunkSize;
    if ( usSizeIMAP != 0 )
    {
        if ( m_pkLogFile )
        {
            PrintIndent(iIndent);
            *m_pkLogFile << "malformed IMAP subchunk!" << endl;
        }
        m_eError = LWR_BAD_IMAP_CHUNK;
        return usChunkSize;
    }

    // Parse all known and relevant subchunks.
    // Only texture images are currently used.

    bool bLoop = true;    
    while ( bLoop && DataAvailable() )
    {
        unsigned int uiChunkType;
        System::Read4be(m_pcCurrent,1,&uiChunkType);
        m_pcCurrent += sizeof(unsigned int);

        unsigned int uiCurSize = sizeof(uiChunkType);

        unsigned short usSubSize;
        System::Read2be(m_pcCurrent,1,&usSubSize);
        m_pcCurrent += sizeof(unsigned short);

        uiCurSize += sizeof(usSubSize);

        usChunkSize += (unsigned short)uiCurSize;

        switch ( uiChunkType )
        {
            case 'TMAP':
            {
                if ( m_pkLogFile )
                    PrintChunkInfo(uiChunkType,usSubSize,iIndent);
                unsigned short usSizeTMAP = ParseTMAPSubchunk(iIndent+1);
                usChunkSize += usSizeTMAP;
            }
            break;

            case 'PROJ':
            {
                unsigned short usProjectionMode;
                System::Read2be(m_pcCurrent,1,&usProjectionMode);
                m_pcCurrent += sizeof(unsigned short);

                usChunkSize += sizeof(usProjectionMode);
                if ( m_pkLogFile )
                {
                    PrintChunkInfo(uiChunkType,usSubSize,iIndent);
                    PrintIndent(iIndent+1);
                    switch ( usProjectionMode )
                    {
                        case 0:   *m_pkLogFile << "planar"; break;
                        case 1:   *m_pkLogFile << "cylindrical"; break;
                        case 2:   *m_pkLogFile << "spherical"; break;
                        case 3:   *m_pkLogFile << "cubic"; break;
                        case 4:   *m_pkLogFile << "front projection"; break;
                        case 5:   *m_pkLogFile << "UV"; break;
                        default:  *m_pkLogFile << "unknown projection mode";
                    }
                    *m_pkLogFile << endl;
                }
            }
            break;

            case 'AXIS':
            {
                unsigned short usAxis;
                System::Read2be(m_pcCurrent,1,&usAxis);
                m_pcCurrent += sizeof(unsigned short);

                usChunkSize += sizeof(usAxis);
                if ( m_pkLogFile )
                {
                    PrintChunkInfo(uiChunkType,usSubSize,iIndent);
                    PrintIndent(iIndent+1);
                    switch ( usAxis )
                    {
                        case 0:   *m_pkLogFile << "X"; break;
                        case 1:   *m_pkLogFile << "Y"; break;
                        case 2:   *m_pkLogFile << "Z"; break;
                        default:  *m_pkLogFile << "unknown axis";
                    }
                    *m_pkLogFile << endl;
                }
            }
            break;

            case 'IMAG':
            {
                unsigned short usIndex;
                System::Read2be(m_pcCurrent,1,&usIndex);
                m_pcCurrent += sizeof(unsigned short);

                usChunkSize += sizeof(usIndex);

                if ( usIndex
                &&   usIndex <= (unsigned short)m_akTextures.size() )
                {
                    m_pkCurrentTexture = m_akTextures[usIndex-1];
                }
                else
                {
                    m_pkCurrentTexture = 0;
                }

                if ( m_pkLogFile )
                {
                    PrintChunkInfo(uiChunkType,usSubSize,iIndent);
                    PrintIndent(iIndent+1);
                    if ( usIndex )
                        *m_pkLogFile << "index = " << usIndex << endl;
                    else
                        *m_pkLogFile << "(no image)" << endl;
                }
            }
            break;

            case 'WRAP':
            {
                unsigned short usWidth;
                System::Read2be(m_pcCurrent,1,&usWidth);
                m_pcCurrent += sizeof(unsigned short);

                unsigned short usHeight;
                System::Read2be(m_pcCurrent,1,&usHeight);
                m_pcCurrent += sizeof(unsigned short);

                usChunkSize += sizeof(usWidth) + sizeof(usHeight);

                if ( m_pkLogFile )
                {
                    PrintChunkInfo(uiChunkType,usSubSize,iIndent);
                    PrintIndent(iIndent+1);
                    *m_pkLogFile << "width = ";
                    switch ( usWidth )
                    {
                        case 0:   *m_pkLogFile << "reset"; break;
                        case 1:   *m_pkLogFile << "repeat"; break;
                        case 2:   *m_pkLogFile << "mirror"; break;
                        case 3:   *m_pkLogFile << "edge"; break;
                        default:  *m_pkLogFile << "unknown wrap mode";
                    }
                    *m_pkLogFile << endl;

                    PrintIndent(iIndent+1);
                    *m_pkLogFile << "height = ";
                    switch ( usHeight )
                    {
                        case 0:   *m_pkLogFile << "reset"; break;
                        case 1:   *m_pkLogFile << "repeat"; break;
                        case 2:   *m_pkLogFile << "mirror"; break;
                        case 3:   *m_pkLogFile << "edge"; break;
                        default:  *m_pkLogFile << "unknown wrap mode";
                    }
                    *m_pkLogFile << endl;
                }
            }
            break;

            case 'WRPW':
            case 'WRPH':
            {
                float fCycles;
                System::Read4be(m_pcCurrent,1,&fCycles);
                m_pcCurrent += sizeof(float);

                unsigned short usEnvelope;
                System::Read2be(m_pcCurrent,1,&usEnvelope);
                m_pcCurrent += sizeof(unsigned short);

                usChunkSize += sizeof(fCycles) + sizeof(usEnvelope);
                if ( m_pkLogFile )
                {
                    PrintChunkInfo(uiChunkType,usSubSize,iIndent);
                    PrintIndent(iIndent+1);
                    *m_pkLogFile << "cycles = " << 100.0f*fCycles << "%";
                    if ( usEnvelope )
                        *m_pkLogFile << ", envelope = " << usEnvelope;
                    *m_pkLogFile << endl;
                }
            }
            break;

            case 'VMAP':
            {
                int iBytes;
                string kVertexMapName = ReadEvenString(&iBytes);
                usChunkSize += (unsigned short)iBytes;

                if ( kVertexMapName.length() && m_pkCurrentTexture )
                {
                    ApplyVertexMap(kVertexMapName);
                    ApplyDiscontinuousVertexMap(kVertexMapName);
                }

                if ( m_pkLogFile )
                {
                    PrintChunkInfo(uiChunkType,usSubSize,iIndent);
                    PrintIndent(iIndent+1);
                    *m_pkLogFile << "vertex map = "
                        << kVertexMapName.c_str() << endl;
                }
            }
            break;

            case 'AAST':
            {
                unsigned short usFlags;
                System::Read2be(m_pcCurrent,1,&usFlags);
                m_pcCurrent += sizeof(unsigned short);

                float fStrength;
                System::Read4be(m_pcCurrent,1,&fStrength);
                m_pcCurrent += sizeof(float);

                usChunkSize += sizeof(usFlags) + sizeof(fStrength);
                if ( m_pkLogFile )
                {
                    PrintChunkInfo(uiChunkType,usSubSize,iIndent);
                    PrintIndent(iIndent+1);
                    *m_pkLogFile << "antialiasing       = "
                        << ((usFlags & 1) ? "enabled" : "disabled") << endl;
                    PrintIndent(iIndent+1);
                    *m_pkLogFile << "antialias strength = "
                        << 100.0f*fStrength << "%" << endl;
                }
            }
            break;

            case 'PIXB':
            {
                unsigned short usFlags;
                System::Read2be(m_pcCurrent,1,&usFlags);
                m_pcCurrent += sizeof(unsigned short);

                usChunkSize += sizeof(usFlags);
                if ( m_pkLogFile )
                {
                    PrintChunkInfo(uiChunkType,usSubSize,iIndent);
                    PrintIndent(iIndent+1);
                    *m_pkLogFile << "blending = "
                        << ((usFlags & 1) ? "enabled" : "disabled") << endl;
                }
            }
            break;

            default:
            {
                // Back up, we've entered another subchunk.
                usChunkSize -= (unsigned short)uiCurSize;
                m_pcCurrent -= uiCurSize;
                bLoop = false;
            }
        }
    }

    return usChunkSize;
}
//----------------------------------------------------------------------------
unsigned short LightWaveReader::ParseTMAPSubchunk (int iIndent)
{
    // Texture map internal description.  Parse all known and relevant
    // subchunks.

    unsigned short usChunkSize = 0;    
    bool bLoop = true;    
    while ( bLoop && DataAvailable() )
    {
        unsigned int uiChunkType;
        System::Read4be(m_pcCurrent,1,&uiChunkType);
        m_pcCurrent += sizeof(unsigned int);

        unsigned int uiCurSize = sizeof(uiChunkType);

        unsigned short usSubSize;
        System::Read2be(m_pcCurrent,1,&usSubSize);
        m_pcCurrent += sizeof(unsigned short);

        uiCurSize += sizeof(usSubSize);

        usChunkSize += (unsigned short) uiCurSize;

        switch ( uiChunkType )
        {
            case 'CNTR':
            case 'SIZE':
            case 'ROTA':
            {
                Vector3f kPoint;
                System::Read4be(m_pcCurrent,3,(float*)kPoint);
                m_pcCurrent += sizeof(Vector3f);

                unsigned short usEnvelope;
                System::Read2be(m_pcCurrent,1,&usEnvelope);
                m_pcCurrent += sizeof(unsigned short);

                usChunkSize += sizeof(kPoint) + sizeof(usEnvelope);
                if ( m_pkLogFile )
                {
                    PrintChunkInfo(uiChunkType,usSubSize,iIndent);
                    PrintIndent(iIndent+1);
                    *m_pkLogFile << "vector = ("
                        << kPoint[0] << ","
                        << kPoint[1] << ","
                        << kPoint[2] << ")";
                    if ( usEnvelope )
                        *m_pkLogFile << ", envelope = " << usEnvelope;
                    *m_pkLogFile << endl;
                }
            }
            break;

            case 'OREF':
            {
                int iBytes;
                string kObject = ReadEvenString(&iBytes);
                usChunkSize += (unsigned short)iBytes;
                if ( m_pkLogFile )
                {
                    PrintChunkInfo(uiChunkType,usSubSize,iIndent);
                    PrintIndent(iIndent+1);
                    if ( kObject.length() )
                    {
                        *m_pkLogFile << "object reference = "
                            << kObject.c_str();
                    }
                    else
                    {
                        *m_pkLogFile << "(none)";
                    }
                    *m_pkLogFile << endl;
                }
            }
            break;

            case 'FALL':
            {
                unsigned short usFallType;
                System::Read2be(m_pcCurrent,1,&usFallType);
                m_pcCurrent += sizeof(unsigned short);

                Vector3f kPoint;
                System::Read4be(m_pcCurrent,3,(float*)kPoint);
                m_pcCurrent += sizeof(Vector3f);

                unsigned short usEnvelope;
                System::Read2be(m_pcCurrent,1,&usEnvelope);
                m_pcCurrent += sizeof(unsigned short);

                usChunkSize += sizeof(usFallType) + sizeof(kPoint) +
                    sizeof(usEnvelope);
                if ( m_pkLogFile )
                {
                    PrintChunkInfo(uiChunkType,usSubSize,iIndent);
                    PrintIndent(iIndent+1);
                    switch ( usFallType )
                    {
                        case 0:   *m_pkLogFile << "cubic"; break;
                        case 1:   *m_pkLogFile << "spherical"; break;
                        case 2:   *m_pkLogFile << "linear X"; break;
                        case 3:   *m_pkLogFile << "linear Y"; break;
                        case 4:   *m_pkLogFile << "linear Z"; break;
                        default:  *m_pkLogFile << "unknown fall-off type";
                    }
                    *m_pkLogFile << ", vector = ("
                        << kPoint[0] << ","
                        << kPoint[1] << ","
                        << kPoint[2] << ")";
                    if ( usEnvelope )
                        *m_pkLogFile << ", envelope = " << usEnvelope;
                    *m_pkLogFile << endl;
                }
            }
            break;

            case 'CSYS':
            {
                unsigned short usCoordType;
                System::Read2be(m_pcCurrent,1,&usCoordType);
                m_pcCurrent += sizeof(unsigned short);

                usChunkSize += sizeof(usCoordType);
                if ( m_pkLogFile )
                {
                    PrintChunkInfo(uiChunkType,usSubSize,iIndent);
                    PrintIndent(iIndent+1);
                    *m_pkLogFile << (usCoordType ? "world" : "object")
                        << " coordinates" << endl;
                }
            }
            break;

            default:
            {
                // Back up, we've entered another subchunk.
                usChunkSize -= (unsigned short)uiCurSize;
                m_pcCurrent -= uiCurSize;
                bLoop = false;
            }
        }
    }

    return usChunkSize;
}
//----------------------------------------------------------------------------
bool LightWaveReader::AddTexture (const char* acTFileName)
{
    // Add a texture to the object array, thereby making it available to all
    // surfaces.
    int iWidth, iHeight, iBitsPerPixel;
    unsigned char* aucData = 0;
    if ( !ImageLoader(acTFileName,iWidth,iHeight,iBitsPerPixel,aucData) )
    {
        delete[] aucData;
        return false;
    }

    int eType = (iBitsPerPixel == 24 ? Image::IT_RGB888 : Image::IT_RGBA8888);
    Image* pkImage = new Image(eType,iWidth,iHeight,aucData,acTFileName);
    Texture* pkTexture = new Texture;
    pkTexture->SetName(acTFileName);
    pkTexture->Apply = Texture::AM_MODULATE;
    pkTexture->Filter = Texture::FM_LINEAR;
    pkTexture->Mipmap = Texture::MM_LINEAR_NEAREST;
    pkTexture->SetImage(pkImage);

    m_akTextures.push_back(pkTexture);
    return true;
}
//----------------------------------------------------------------------------
void LightWaveReader::BuildTriMesh ()
{
    // Build vertex array as a vector, containing no duplicate points.
    VertexMap* pkVertexMap = m_kVertexMaps[m_kCurrentSurface];
    PolygonMap* pkPolygonMap = new PolygonMap;
    m_kPolygonMaps[m_kCurrentSurface] = pkPolygonMap;
    PolygonList::iterator kPolygon = m_pkCurrentPolyList->begin();
    Vector3Array akVertexArray;
    int iTriangleQuantity = (int)m_pkCurrentPolyList->size();
    int iTriangle, iVertex = 0;
    for (iTriangle = 0; iTriangle < iTriangleQuantity; iTriangle++)
    {
        unsigned short usPolygonID = *kPolygon++;
        (*pkPolygonMap)[usPolygonID] = iTriangle;

        Triangle& rkTriangle = m_akPolygons[usPolygonID];
        unsigned short usFirst = rkTriangle.V0;
        unsigned short usSecond = rkTriangle.V1;
        unsigned short usThird = rkTriangle.V2;

        if ( pkVertexMap->find(usFirst) == pkVertexMap->end() )
        {
            (*pkVertexMap)[usFirst] = iVertex++;
            akVertexArray.push_back(m_akVertices[usFirst]);
        }
        if (pkVertexMap->find(usSecond) == pkVertexMap->end())
        {
            (*pkVertexMap)[usSecond] = iVertex++;
            akVertexArray.push_back(m_akVertices[usSecond]);
        }
        if (pkVertexMap->find(usThird) == pkVertexMap->end())
        {
            (*pkVertexMap)[usThird] = iVertex++;
            akVertexArray.push_back(m_akVertices[usThird]);
        }
    }

    // Create raw vertex array to be used by the trimesh.
    int iVertexQuantity = (int)akVertexArray.size();
    Vector3f* akVertices = new Vector3f[iVertexQuantity];
    size_t uiSize = iVertexQuantity*sizeof(Vector3f);
    System::Memcpy(akVertices,uiSize,&akVertexArray.front(),uiSize);
    for (int i = 0; i < iVertexQuantity; i++)
    {
        akVertices[i] = akVertexArray[i];
    }

    // Build connectivity array.
    int* aiConnectivity = new int[3*iTriangleQuantity];
    kPolygon = m_pkCurrentPolyList->begin();
    iVertex = 0;
    for (iTriangle = 0; iTriangle < iTriangleQuantity; iTriangle++)
    {
        unsigned short usPolygonID = *kPolygon++;
        Triangle& rkTriangle = m_akPolygons[usPolygonID];
        aiConnectivity[iVertex++] = (*pkVertexMap)[rkTriangle.V0];
        aiConnectivity[iVertex++] = (*pkVertexMap)[rkTriangle.V1];
        aiConnectivity[iVertex++] = (*pkVertexMap)[rkTriangle.V2];
    }

    // Build the trimesh.
    Vector3fArray* pkVerts = new Vector3fArray(iVertexQuantity,akVertices);
    IntArray* pkIndices = new IntArray(iTriangleQuantity*3,aiConnectivity);
    m_pkCurrentMesh->Vertices = pkVerts;
    m_pkCurrentMesh->Indices = pkIndices;
    m_pkCurrentMesh->GenerateNormals();
    m_pkCurrentMesh->UpdateMS();
}
//----------------------------------------------------------------------------
void LightWaveReader::ApplyVertexMap (const string& rkName)
{
    if ( m_kMaps.find(rkName) == m_kMaps.end() )
        return;

    // Create texture coordinates array.
    VertexMap* pkVertexMap = m_kVertexMaps[m_kCurrentSurface];
    int iVertexQuantity = m_pkCurrentMesh->Vertices->GetQuantity();
    Vector2f* akTextures = new Vector2f[iVertexQuantity];
    memset(akTextures,0,sizeof(Vector2f)*iVertexQuantity);

    // Fill in texture coordinates array.
    VMAPArray* pakVMAP = m_kMaps[rkName];
    int iVMAPSize = (int)pakVMAP->size();    
    for (int iElement = 0; iElement < iVMAPSize; iElement++)
    {
        VMAP& rkVMAP = (*pakVMAP)[iElement];
        if ( pkVertexMap->find(rkVMAP.Vertex) == pkVertexMap->end() )
            continue;

        int iVertex = (*pkVertexMap)[rkVMAP.Vertex];
        akTextures[iVertex] = Vector2f(rkVMAP.U,rkVMAP.V);
    }

    // Assign texture coordinates and texture image.
    Vector2fArray* pkUVs = new Vector2fArray(iVertexQuantity,akTextures);
    TextureEffect* pkTextureEffect = new TextureEffect(m_pkCurrentTexture,pkUVs);
    pkTextureEffect->SetName(rkName.c_str());
    m_pkCurrentMesh->SetEffect(pkTextureEffect);

    // Reset default material.
    ColorRGBA kAmbient(0.2f,0.2f,0.2f,1.0f);
    ColorRGBA kDiffuse(0.8f,0.8f,0.8f,1.0f);
    ColorRGBA kSpecular(0.0f,0.0f,0.0f,1.0f);
    GlobalState* pkGlobalState =
        m_pkCurrentMesh->GetGlobalState(GlobalState::MATERIAL);
    MaterialState* pkMaterialState = 
        DynamicCast<MaterialState>(pkGlobalState);
    pkMaterialState->Ambient = kAmbient;
    pkMaterialState->Diffuse = kDiffuse;
    pkMaterialState->Specular = kSpecular;
    pkMaterialState->Shininess = 0.0f;
}
//----------------------------------------------------------------------------
void LightWaveReader::ApplyDiscontinuousVertexMap (const string& rkName)
{
    if ( m_kDiscontMaps.find(rkName) == m_kDiscontMaps.end() )
        return;

    // Prepare trimesh expansion: it will be triggered by per-vertex and
    // per-polygon texture coordinates assignment.  Copy original raw
    // LightWave geometric data.
    int iVertexQuantity = m_pkCurrentMesh->Vertices->GetQuantity();
    const Vector3f* akVertices = m_pkCurrentMesh->Vertices->GetData();
    const Vector3f* akNormals = m_pkCurrentMesh->Normals->GetData();
    const Vector2f* akTextures = m_pkCurrentMesh->GetEffect()->UVs[0]->GetData();
    Vector3Array kVertices(iVertexQuantity);
    Vector3Array kNormals(iVertexQuantity);
    Vector2Array kTextures(iVertexQuantity);
    int i;
    for (i = 0; i < iVertexQuantity; i++)
    {
        kVertices[i] = akVertices[i];
        kNormals[i] = akNormals[i];
        kTextures[i] = akTextures[i];
    }
    
    // For each entry in the map, locate the polygon and vertex that
    // correspond to the entry in the current trimesh. Then, add it to the
    // geometric data by expanding the array.
    PolygonMap* pkPolygonMap = m_kPolygonMaps[m_kCurrentSurface];
    VertexMap* pkVertexMap = m_kVertexMaps[m_kCurrentSurface];
    VMADArray* pakVMAD = m_kDiscontMaps[rkName];
    int iVMADSize = (int)pakVMAD->size();
    int* aiConnectivity = m_pkCurrentMesh->Indices->GetData();
    for (int iElement = 0; iElement < iVMADSize; iElement++)
    {
        VMAD& rkVMAD = (*pakVMAD)[iElement];
        if ( pkPolygonMap->find(rkVMAD.Polygon) == pkPolygonMap->end() )
            continue;
        if ( pkVertexMap->find(rkVMAD.Vertex) == pkVertexMap->end() )
            continue;

        int iPolygon = (*pkPolygonMap)[rkVMAD.Polygon];
        int iVertex = (*pkVertexMap)[rkVMAD.Vertex];

        int iPolygonIndex = 3*iPolygon;
        int iVertexIndex = (int)kVertices.size();

        kVertices.push_back(akVertices[iVertex]);
        kNormals.push_back(akNormals[iVertex]);
        kTextures.push_back(Vector2f(rkVMAD.U,rkVMAD.V));
        
        if ( aiConnectivity[iPolygonIndex] == iVertex )
            aiConnectivity[iPolygonIndex] = iVertexIndex;
        else if ( aiConnectivity[iPolygonIndex+1] == iVertex )
            aiConnectivity[iPolygonIndex+1] = iVertexIndex;
        else if ( aiConnectivity[iPolygonIndex+2] == iVertex )
            aiConnectivity[iPolygonIndex+2] = iVertexIndex;
    }
    
    // Recreate raw geometric data from expanded array.
    iVertexQuantity = (int)kVertices.size();
    Vector3f* akNewVertices = new Vector3f[iVertexQuantity];
    Vector3f* akNewNormals = new Vector3f[iVertexQuantity];
    Vector2f* akNewTextures = new Vector2f[iVertexQuantity];
    for (i = 0; i < iVertexQuantity; i++)
    {
        akNewVertices[i] = kVertices[i];
        akNewNormals[i] = kNormals[i];
        akNewTextures[i] = kTextures[i];
    }

    Vector3fArray* pkVerts = new Vector3fArray(iVertexQuantity,akNewVertices);
    Vector3fArray* pkNorms = new Vector3fArray(iVertexQuantity,akNewNormals);
    Vector2fArray* pkUVs = new Vector2fArray(iVertexQuantity,akNewTextures);

    m_pkCurrentMesh->Vertices = pkVerts;
    m_pkCurrentMesh->Normals = pkNorms;
    m_pkCurrentMesh->GetEffect()->UVs[0] = pkUVs;
}
//----------------------------------------------------------------------------
void LightWaveReader::ComputeNormals ()
{
    // Just use the default WildMagic normals if we're not interested in
    // actual LightWave smoothing.
    if ( !m_bSmoothed )
        return;

    // Compute the actual vertex normals by first expanding the geometry, then
    // calculating the smoothed normals, and finally compressing the geometry
    // to eliminate duplicate data. The compression step also rebuilds the
    // trimeshes.
    
    ExpandGeometry();
    CreateVertexNormals();
    CompressGeometry();
}
//----------------------------------------------------------------------------
Vector3f LightWaveReader::ComputePlaneNormal (const Vector3f& rkV0,
    const Vector3f& rkV1, const Vector3f& rkV2) const
{
    Vector3f kEdge1 = rkV1 - rkV0;
    Vector3f kEdge2 = rkV2 - rkV0;
    Vector3f kNormal = kEdge1.Cross(kEdge2);
    kNormal.Normalize();
    return kNormal;
}
//----------------------------------------------------------------------------
void LightWaveReader::ExpandGeometry ()
{
    // Expand raw geometric data by creating one vertex per polygon for the
    // whole model. Each vertex normal is reset to the plane normal.
    SurfaceMap::iterator kSIter = m_kSurfaces.begin();
    for (/**/; kSIter != m_kSurfaces.end(); kSIter++)
    {
        TriMesh* pkMesh = kSIter->second;
        int iTriangleQuantity = pkMesh->GetTriangleQuantity();
        int iVertexQuantity = 3*iTriangleQuantity;
        
        Vector3f* akVertex = new Vector3f[iVertexQuantity];
        Vector3f* akNormal = new Vector3f[iVertexQuantity];
        Vector2f* akTexture = 0;
        int* aiConnect = new int[iVertexQuantity];
        const Vector3f* akMVertex = pkMesh->Vertices->GetData();
        const Vector2f* akMTexture = (pkMesh->GetEffect() && 
            pkMesh->GetEffect()->UVs.GetQuantity() > 0 ? 
            pkMesh->GetEffect()->UVs[0]->GetData() : 0);
        if ( akMTexture )
            akTexture = new Vector2f[iVertexQuantity];
        const int* aiMConnect = pkMesh->Indices->GetData();

        int iPosition = 0;
        for (int iTriangle = 0; iTriangle < iTriangleQuantity; iTriangle++)
        {
            int iVertex = 3*iTriangle;
            int iV0 = aiMConnect[iVertex];
            int iV1 = aiMConnect[iVertex+1];
            int iV2 = aiMConnect[iVertex+2];
            Vector3f kNormal = ComputePlaneNormal(akMVertex[iV0],
                akMVertex[iV1],akMVertex[iV2]);
            
            akVertex[iPosition] = akMVertex[iV0];
            akNormal[iPosition] = kNormal;
            if ( akMTexture )
                akTexture[iPosition] = akMTexture[iV0];
            aiConnect[iVertex] = iPosition++;
            
            akVertex[iPosition] = akMVertex[iV1];
            akNormal[iPosition] = kNormal;
            if ( akMTexture )
                akTexture[iPosition] = akMTexture[iV1];
            aiConnect[iVertex+1] = iPosition++;

            akVertex[iPosition] = akMVertex[iV2];
            akNormal[iPosition] = kNormal;
            if ( akMTexture )
                akTexture[iPosition] = akMTexture[iV2];
            aiConnect[iVertex+2] = iPosition++;            
        }

        string kName = kSIter->first;

        Vector3fArray* pkVerts = new Vector3fArray(iVertexQuantity,akVertex);
        Vector3fArray* pkNorms = new Vector3fArray(iVertexQuantity,akNormal);
        IntArray* pkIndices = new IntArray(iVertexQuantity,aiConnect);

        pkMesh->Vertices = pkVerts;
        pkMesh->Normals = pkNorms;
        pkMesh->Indices = pkIndices;

        if (akTexture)
        {
            Vector2fArray* pkUVs = 
                new Vector2fArray(iVertexQuantity,akTexture);
            pkMesh->GetEffect()->UVs[0] = pkUVs;
        }

        m_kMapVertices[kName] = akVertex;
        m_kMapNormals[kName] = akNormal;
        m_kMapTextures[kName] = akTexture;
        m_kMapConnectivity[kName] = aiConnect;
    }
}
//----------------------------------------------------------------------------
void LightWaveReader::CreateVertexNormals ()
{
    // Compute vertex normals.
    unsigned short usVertexQuantity = (unsigned short)m_akVertices.size();
    unsigned short usPolygonQuantity = (unsigned short)m_akPolygons.size();
    for (unsigned short usV = 0; usV < usVertexQuantity; usV++)
    {
        Vector3f& rkVertex = m_akVertices[usV];
        PolygonList* pkPolygonList = m_akVertexToPolygon[usV];
        for (unsigned short usP = 0; usP < usPolygonQuantity; usP++)
        {
            // Do not process this polygon if it doesn't contain the current
            // vertex.
            Triangle& rkTriangle = m_akPolygons[usP];
            if ( !rkTriangle.HasVertex(usV) )
                continue;

            // Retrieve surface and smoothing angle.
            Vector3f& rkFirstFacetNormal = rkTriangle.Normal;
            unsigned short usSurfaceTag = m_kPolygonTags[usP];
            TriMesh* pkMesh = m_kTagSurfaces[usSurfaceTag];
            string kName(pkMesh->GetName());
            if ( m_kAngles.find(kName) == m_kAngles.end() )
                continue;

            // Extract current facet normal and process all polygons sharing
            // this vertex.
            float fSmoothing = m_kAngles[kName];
            bool bAveraged = false;
            Vector3f kAverage = Vector3f::ZERO;
            PolygonList::iterator kPolyIter = pkPolygonList->begin();
            for (/**/; kPolyIter != pkPolygonList->end(); kPolyIter++)
            {
                // Do not average against the same polygon.
                unsigned short usPolygonID = *kPolyIter;
                if ( usPolygonID == usP )
                    continue;

                Triangle& rkSecondTriangle = m_akPolygons[usPolygonID];
                Vector3f& rkSecondFacetNormal = rkSecondTriangle.Normal;
                float fAngle = Mathf::ACos(
                    rkFirstFacetNormal.Dot(rkSecondFacetNormal));
                if ( 0.0f <= fAngle && fAngle <= fSmoothing )
                {
                    bAveraged = true;
                    kAverage += rkSecondFacetNormal;
                }
            }
            
            // If we have averaged this normal, we have to assign it to the
            // current vertex of the current polygon in the current surface.
            if ( bAveraged )
            {
                kAverage.Normalize();                
                Vector3f* akVertices = m_kMapVertices[kName];
                Vector3f* akNormals = m_kMapNormals[kName];
                PolygonMap* pkPolygonMap = m_kPolygonMaps[kName];
                unsigned short usPolygonID = (*pkPolygonMap)[usP];
                unsigned short usPolygonIndex = 3*usPolygonID;
                if ( akVertices[usPolygonIndex] == rkVertex )
                    akNormals[usPolygonIndex] = kAverage;
                else if ( akVertices[usPolygonIndex+1] == rkVertex )
                    akNormals[usPolygonIndex+1] = kAverage;
                else if ( akVertices[usPolygonIndex+2] == rkVertex )
                    akNormals[usPolygonIndex+2] = kAverage;
            }
        }
    }
}
//----------------------------------------------------------------------------
void LightWaveReader::CompressGeometry ()
{
    // Iterate over the expanded geometric data and build an array
    // that contains only unique vertices.
    Vector2f kNoTexture(-1.0f,-1.0f);
    SurfaceMap::iterator kSIter = m_kSurfaces.begin();
    for (/**/; kSIter != m_kSurfaces.end(); kSIter++)
    {
        TriMesh* pkMesh = kSIter->second;
        int iTriangleQuantity = pkMesh->GetTriangleQuantity();
        int iVertexQuantity = 3*iTriangleQuantity;

        string kName = kSIter->first;
        Vector3f* akVertex = m_kMapVertices[kName];
        Vector3f* akNormal = m_kMapNormals[kName];
        Vector2f* akTexture = m_kMapTextures[kName];
        int* aiConnect = m_kMapConnectivity[kName];

        // A map is used to make sure there are no duplicates.
        VertexAttributeMap kUniqueMap;
        VertexAttributeArray kUniqueArray;
        int iPosition = 0;
        for (int iTriangle = 0; iTriangle < iTriangleQuantity; iTriangle++)
        {
            int iVertex = 3*iTriangle;
            int iV0 = aiConnect[iVertex];
            int iV1 = aiConnect[iVertex+1];
            int iV2 = aiConnect[iVertex+2];

            VertexAttribute kVA0(akVertex[iV0], akNormal[iV0],
                akTexture ? akTexture[iV0] : kNoTexture);
            VertexAttribute kVA1(akVertex[iV1], akNormal[iV1],
                akTexture ? akTexture[iV1] : kNoTexture);
            VertexAttribute kVA2(akVertex[iV2], akNormal[iV2],
                akTexture ? akTexture[iV2] : kNoTexture);

            VertexAttributeMap::iterator kPosVA0 = kUniqueMap.find(kVA0);
            if ( kPosVA0 == kUniqueMap.end() )
            {
                kUniqueArray.push_back(kVA0);
                kUniqueMap[kVA0] = iPosition;
                aiConnect[iVertex] = iPosition++;
            }
            else
            {
                aiConnect[iVertex] = kPosVA0->second;
            }

            VertexAttributeMap::iterator kPosVA1 = kUniqueMap.find(kVA1);
            if ( kPosVA1 == kUniqueMap.end() )
            {
                kUniqueArray.push_back(kVA1);
                kUniqueMap[kVA1] = iPosition;
                aiConnect[iVertex+1] = iPosition++;
            }
            else
            {
                aiConnect[iVertex+1] = kPosVA1->second;
            }

            VertexAttributeMap::iterator kPosVA2 = kUniqueMap.find(kVA2);
            if ( kPosVA2 == kUniqueMap.end() )
            {
                kUniqueArray.push_back(kVA2);
                kUniqueMap[kVA2] = iPosition;
                aiConnect[iVertex+2] = iPosition++;
            }
            else
            {
                aiConnect[iVertex+2] = kPosVA2->second;
            }
        }
        
        // Recreate raw geometric data from the unique set computed above.
        iVertexQuantity = (int)kUniqueArray.size();
        akVertex = new Vector3f[iVertexQuantity];
        akNormal = new Vector3f[iVertexQuantity];
        if ( akTexture )
            akTexture = new Vector2f[iVertexQuantity];

        // No need to delete previous values, because the previous values
        // are all mapped from smart pointers (from the TriMesh arrays).
        m_kMapVertices[kName] = akVertex;
        m_kMapNormals[kName] = akNormal;
        m_kMapTextures[kName] = akTexture;
        
        for (int iVertex = 0; iVertex < iVertexQuantity; iVertex++)
        {
            VertexAttribute& rkVA = kUniqueArray[iVertex];
            akVertex[iVertex] = rkVA.Vertex;
            akNormal[iVertex] = rkVA.Normal;
            if ( akTexture )
                akTexture[iVertex] = rkVA.Texture;
        }

        Vector3fArray* pkVerts = new Vector3fArray(iVertexQuantity,akVertex);
        Vector3fArray* pkNorms = new Vector3fArray(iVertexQuantity,akNormal);
        pkMesh->Vertices = pkVerts;
        pkMesh->Normals = pkNorms;

        if (akTexture)
        {
            Vector2fArray* pkUVs = new Vector2fArray(iVertexQuantity,
                akTexture);
            pkMesh->GetEffect()->UVs[0] = pkUVs;
        }
    }
}
//----------------------------------------------------------------------------
void LightWaveReader::PrintIndent (int iIndent)
{
    for (int iIndex = 0; iIndex < iIndent; iIndex++)
        *m_pkLogFile << ms_acTab;
}
//----------------------------------------------------------------------------
void LightWaveReader::PrintChunkType (unsigned int uiChunk)
{
#ifndef WM3_BIG_ENDIAN
    // chunk type should be big endian on any platform
    System::SwapBytes(sizeof(unsigned int),&uiChunk);
#endif

    unsigned char* pucBytes = (unsigned char*)&uiChunk;
    *m_pkLogFile << pucBytes[0] << pucBytes[1] << pucBytes[2] << pucBytes[3];
}
//----------------------------------------------------------------------------
void LightWaveReader::PrintChunkInfo (unsigned int uiChunkType,
    unsigned short usChunkSize, int iIndent)
{
    PrintIndent(iIndent);
    PrintChunkType(uiChunkType);
    (*m_pkLogFile) << " size = " << usChunkSize << endl;
}
//----------------------------------------------------------------------------
bool LightWaveReader::VertexAttribute::operator<
    (const LightWaveReader::VertexAttribute& rkVA) const
{
    if ( Vertex < rkVA.Vertex )
        return true;
    if ( Vertex > rkVA.Vertex )
        return false;
    if ( Normal < rkVA.Normal )
        return true;
    if ( Normal > rkVA.Normal )
        return false;
    if ( Texture < rkVA.Texture )
        return true;
    return false;
}
//----------------------------------------------------------------------------
bool LightWaveReader::VertexAttribute::operator==
    (const LightWaveReader::VertexAttribute& rkVA) const
{
    return (Vertex == rkVA.Vertex) &&
           (Normal == rkVA.Normal) &&
           (Texture == rkVA.Texture);
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// LightWaveReader::Triangle
//----------------------------------------------------------------------------
LightWaveReader::Triangle::Triangle ()
    :
    Normal(Vector3f::ZERO)
{
    V0 = 0;
    V1 = 0;
    V2 = 0;
}
//----------------------------------------------------------------------------
LightWaveReader::Triangle::Triangle (unsigned short usV0,
    unsigned short usV1, unsigned short usV2, Vector3f& rkNormal)
    :
    Normal(rkNormal)
{
    V0 = usV0;
    V1 = usV1;
    V2 = usV2;
}
//----------------------------------------------------------------------------
LightWaveReader::Triangle::Triangle (const Triangle& rkTriangle)
    :
    Normal(rkTriangle.Normal)
{
    V0 = rkTriangle.V0;
    V1 = rkTriangle.V1;
    V2 = rkTriangle.V2;
}
//----------------------------------------------------------------------------
bool LightWaveReader::Triangle::HasVertex (unsigned short usV)
{
    return (usV == V0) || (usV == V1) || (usV == V2);
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// LightWaveReader::VMAP
//----------------------------------------------------------------------------
LightWaveReader::VMAP::VMAP ()
{
    Vertex = 0;
    U = 0.0f;
    V = 0.0f;
}
//----------------------------------------------------------------------------
LightWaveReader::VMAP::VMAP (int iVertex, float fU, float fV)
{
    Vertex = iVertex;
    U = fU;
    V = fV;
}
//----------------------------------------------------------------------------
LightWaveReader::VMAP::VMAP (const LightWaveReader::VMAP& rkVMAP)
{
    Vertex = rkVMAP.Vertex;
    U = rkVMAP.U;
    V = rkVMAP.V;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// LightWaveReader::VMAD
//----------------------------------------------------------------------------
LightWaveReader::VMAD::VMAD ()
{
    Vertex = 0;
    Polygon = 0;
    U = 0.0f;
    V = 0.0f;
}
//----------------------------------------------------------------------------
LightWaveReader::VMAD::VMAD (int iVertex, int iPolygon, float fU, float fV)
{
    Vertex = iVertex;
    Polygon = iPolygon;
    U = fU;
    V = fV;
}
//----------------------------------------------------------------------------
LightWaveReader::VMAD::VMAD (const LightWaveReader::VMAD& rkVMAD)
{
    Vertex = rkVMAD.Vertex;
    Polygon = rkVMAD.Polygon;
    U = rkVMAD.U;
    V = rkVMAD.V;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// LightWaveReader::VertexAttribute
//----------------------------------------------------------------------------
LightWaveReader::VertexAttribute::VertexAttribute ()
    :
    Vertex(Vector3f::ZERO),
    Normal(Vector3f::ZERO),
    Texture(Vector2f(-1.0f,-1.0f))
{
}
//----------------------------------------------------------------------------
LightWaveReader::VertexAttribute::VertexAttribute (const Vector3f& rkVertex,
    const Vector3f& rkNormal, const Vector2f& rkTexture)
    :
    Vertex(rkVertex),
    Normal(rkNormal),
    Texture(rkTexture)
{
}
//----------------------------------------------------------------------------
LightWaveReader::VertexAttribute::VertexAttribute (
    const VertexAttribute& rkVertexAttribute)
    :
    Vertex(rkVertexAttribute.Vertex),
    Normal(rkVertexAttribute.Normal),
    Texture(rkVertexAttribute.Texture)
{
}
//----------------------------------------------------------------------------



