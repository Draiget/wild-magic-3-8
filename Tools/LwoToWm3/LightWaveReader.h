// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef LIGHTWAVEREADER_H
#define LIGHTWAVEREADER_H

#include "Wm3Foundation.h"
#include <list>
#include <map>
#include <vector>
#include <string>

// A LightWave file reader.  The public interface is really minimal: construct
// the object, initialize the reader, and parse the LightWave file.

class LightWaveReader
{
public:
    LightWaveReader (const char* acFileName, bool bVerbose, bool bSmooth);

    ~LightWaveReader ();

    enum
    {
        LWR_NO_ERROR,
        LWR_BAD_LWO_FILE,
        LWR_BAD_LOG_FILE,
        LWR_MISSING_FORM_CHUNK,
        LWR_MISSING_LWO2_CHUNK,
        LWR_BAD_LAYR_CHUNK,
        LWR_BAD_PNTS_CHUNK,
        LWR_BAD_BBOX_CHUNK,
        LWR_UNSUPPORTED_POLYGON_TYPE,
        LWR_UNSUPPORTED_TEXTURE_TYPE,
        LWR_MISSING_CHANNEL,
        LWR_BAD_IMAP_CHUNK,
        LWR_QUANTITY
    };
    int GetError () const;
    static const char* ErrorString[LWR_QUANTITY];

    Wm3::NodePtr GetScene ();

private:
    // The entry point for loading and parsing the LWO file.
    bool DataAvailable() const;
    bool Parse ();
    void BuildObject ();
    void ObjectStatistics ();
    std::string ReadEvenString (int* piBytes);
    unsigned int ReadChunk (unsigned int uiFileSize);
    bool ParseChunk (unsigned int uiChunk, unsigned int& ruiChunkSize);
    bool ParseTAGS (unsigned int uiChunkSize);
    bool ParseLAYR (unsigned int uiChunkSize);
    bool ParsePNTS (unsigned int uiChunkSize);
    bool ParseBBOX (unsigned int uiChunkSize);
    bool ParseVMAP (unsigned int& ruiChunkSize);
    bool ParseVMAD (unsigned int& ruiChunkSize);
    bool ParsePOLS (unsigned int uiChunkSize);
    bool ParsePTAG (unsigned int uiChunkSize);
    bool ParseCLIP (unsigned int& ruiChunkSize);
    bool ParseSURF (unsigned int& ruiChunkSize);
    bool ParseSURFSubchunk (unsigned short& rusSubSize, int& riNumBLOKS,
        int iIndent);
    unsigned short ParseBLOKSubchunk (int iIndent, bool& rbSupported);
    unsigned short ParseBLOKHeader (int iIndent);
    unsigned short ParseBLOKHeaderComponent (int iIndent);
    unsigned short ParseIMAPSubchunk (unsigned short usSizeIMAP, int iIndent);
    unsigned short ParseTMAPSubchunk (int iIndent);
    bool AddTexture (const char* acTFileName);

    // data members
    FILE* m_pkLWOFile;
    std::ofstream* m_pkLogFile;
    char* m_acBuffer;
    int m_iLength;
    char* m_pcCurrent;
    int m_eError;
    bool m_bSmoothed;
    Wm3::NodePtr m_spkLWObject;

    static const char ms_acTab[];

    // Triangle: vertex indices and plane normal.
    class Triangle
    {
    public:
        Triangle ();
        Triangle (unsigned short usV0, unsigned short usV1,
            unsigned short usV2, Wm3::Vector3f& rkNormal);
        Triangle (const Triangle& rkTriangle);
        bool HasVertex (unsigned short usV);

        unsigned short V0, V1, V2;
        Wm3::Vector3f Normal;
    };

    // Vertex map: vertex and texture coords.
    class VMAP
    {
    public:
        VMAP ();
        VMAP (int iVertex, float fU, float fV);
        VMAP (const VMAP& rkVMAP);

        int Vertex;
        float U, V;
    };

    // Discontinous vertex map: vertex, polygon and texture coordinates.
    class VMAD
    {
    public:
        VMAD ();
        VMAD (int iVertex, int iPolygon, float fU, float fV);
        VMAD (const VMAD& rkVMAD);

        int Vertex, Polygon;
        float U, V;
    };
    
    // Vertex attribute: point, normal and texture coordinates.  Use for
    // geometry compression.
    class VertexAttribute
    {
    public:
        VertexAttribute ();
        VertexAttribute (const Wm3::Vector3f& rkVertex,
            const Wm3::Vector3f& rkNormal, const Wm3::Vector2f& rkTexture);
        VertexAttribute (const VertexAttribute& rkVertexAttribute);
        
        bool operator< (const VertexAttribute& rkVA) const;
        bool operator== (const VertexAttribute& rkVA) const;

        Wm3::Vector3f Vertex;
        Wm3::Vector3f Normal;
        Wm3::Vector2f Texture;
    };

    typedef std::list<unsigned short>               PolygonList;
    typedef std::vector<VMAP>                       VMAPArray;
    typedef std::vector<VMAD>                       VMADArray;
    typedef std::vector<Wm3::Vector2f>              Vector2Array;
    typedef std::vector<Wm3::Vector3f>              Vector3Array;
    typedef std::vector<PolygonList*>               PolygonListArray;
    typedef std::vector<Triangle>                   TriangleArray;
    typedef std::vector<Wm3::Texture*>              TextureArray;
    typedef std::vector<VertexAttribute>            VertexAttributeArray;
    typedef std::map<unsigned short,PolygonList*>   TagMap;
    typedef std::map<unsigned short,unsigned short> PolygonMap;
    typedef std::map<int,int>                       VertexMap;
    typedef std::map<std::string,Wm3::Vector2f*>    Vector2ArrayMap;
    typedef std::map<std::string,Wm3::Vector3f*>    Vector3ArrayMap;
    typedef std::map<std::string,int*>              IntArrayMap;
    typedef std::map<std::string,PolygonList*>      PolygonListMap;
    typedef std::map<std::string,PolygonMap*>       PolygonTagMap;
    typedef std::map<std::string,VertexMap*>        SurfaceVertexMap;
    typedef std::map<std::string,VMAPArray*>        VMAPArrayMap;
    typedef std::map<std::string,VMADArray*>        VMADArrayMap;
    typedef std::map<std::string,float>             SmoothingAngleMap;
    typedef std::map<std::string,Wm3::TriMesh*>     SurfaceMap;
    typedef std::map<unsigned short,Wm3::TriMesh*>  SurfaceTagMap;
    typedef std::map<VertexAttribute,int>           VertexAttributeMap;

    void BuildTriMesh ();
    void ApplyVertexMap (const std::string& rkName);
    void ApplyDiscontinuousVertexMap (const std::string& rkName);
    void ComputeNormals ();
    Wm3::Vector3f ComputePlaneNormal (const Wm3::Vector3f& rkV0,
        const Wm3::Vector3f& rkV1, const Wm3::Vector3f& rkV2) const;
    void ExpandGeometry ();
    void CreateVertexNormals ();
    void CompressGeometry ();

    void PrintIndent (int iIndent);
    void PrintChunkType (unsigned int uiNumber);
    void PrintChunkInfo (unsigned int uiChunkType, unsigned short usChunkSize,
        int iIndent);

    Wm3::TriMesh* m_pkCurrentMesh;
    std::string m_kCurrentSurface;
    Wm3::ColorRGBA m_kCurrentColor;
    Wm3::TexturePtr m_pkCurrentTexture;
    PolygonList* m_pkCurrentPolyList;

    Vector3Array m_akVertices;
    TriangleArray m_akPolygons;
    PolygonListArray m_akVertexToPolygon;
    SurfaceMap m_kSurfaces;
    SurfaceTagMap m_kTagSurfaces;
    TagMap m_kTagMap;
    PolygonMap m_kPolygonTags;
    PolygonListMap m_kPolygonLists;
    PolygonTagMap m_kPolygonMaps;
    SurfaceVertexMap m_kVertexMaps;
    SmoothingAngleMap m_kAngles;
    VMAPArrayMap m_kMaps;
    VMADArrayMap m_kDiscontMaps;
    TextureArray m_akTextures;
    Vector3ArrayMap m_kMapVertices;
    Vector3ArrayMap m_kMapNormals;
    Vector2ArrayMap m_kMapTextures;
    IntArrayMap m_kMapConnectivity;
};

#endif



