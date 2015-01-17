/*!  \file kfbxmesh.h
 */

#ifndef FBXFILESDK_KFBXPLUGINS_KFBXMESH_H
#define FBXFILESDK_KFBXPLUGINS_KFBXMESH_H

/**************************************************************************************

 Copyright (C) 2001 - 2009 Autodesk, Inc. and/or its licensors.
 All Rights Reserved.

 The coded instructions, statements, computer programs, and/or related material 
 (collectively the "Data") in these files contain unpublished information 
 proprietary to Autodesk, Inc. and/or its licensors, which is protected by 
 Canada and United States of America federal copyright law and by international 
 treaties. 
 
 The Data may not be disclosed or distributed to third parties, in whole or in
 part, without the prior written consent of Autodesk, Inc. ("Autodesk").

 THE DATA IS PROVIDED "AS IS" AND WITHOUT WARRANTY.
 ALL WARRANTIES ARE EXPRESSLY EXCLUDED AND DISCLAIMED. AUTODESK MAKES NO
 WARRANTY OF ANY KIND WITH RESPECT TO THE DATA, EXPRESS, IMPLIED OR ARISING
 BY CUSTOM OR TRADE USAGE, AND DISCLAIMS ANY IMPLIED WARRANTIES OF TITLE, 
 NON-INFRINGEMENT, MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE OR USE. 
 WITHOUT LIMITING THE FOREGOING, AUTODESK DOES NOT WARRANT THAT THE OPERATION
 OF THE DATA WILL BE UNINTERRUPTED OR ERROR FREE. 
 
 IN NO EVENT SHALL AUTODESK, ITS AFFILIATES, PARENT COMPANIES, LICENSORS
 OR SUPPLIERS ("AUTODESK GROUP") BE LIABLE FOR ANY LOSSES, DAMAGES OR EXPENSES
 OF ANY KIND (INCLUDING WITHOUT LIMITATION PUNITIVE OR MULTIPLE DAMAGES OR OTHER
 SPECIAL, DIRECT, INDIRECT, EXEMPLARY, INCIDENTAL, LOSS OF PROFITS, REVENUE
 OR DATA, COST OF COVER OR CONSEQUENTIAL LOSSES OR DAMAGES OF ANY KIND),
 HOWEVER CAUSED, AND REGARDLESS OF THE THEORY OF LIABILITY, WHETHER DERIVED
 FROM CONTRACT, TORT (INCLUDING, BUT NOT LIMITED TO, NEGLIGENCE), OR OTHERWISE,
 ARISING OUT OF OR RELATING TO THE DATA OR ITS USE OR ANY OTHER PERFORMANCE,
 WHETHER OR NOT AUTODESK HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH LOSS
 OR DAMAGE. 

**************************************************************************************/

#include <fbxfilesdk/components/kbaselib/kaydaradef_h.h>
#include <fbxfilesdk/components/kbaselib/kaydara.h>

#include <fbxfilesdk/kfbxplugins/kfbxgeometry.h>

#include <fbxfilesdk/kfbxmath/kfbxvector4.h>
#include <fbxfilesdk/kfbxmath/kfbxvector2.h>

#include <fbxfilesdk/components/kbaselib/klib/karrayul.h>

#include <fbxfilesdk/fbxfilesdk_nsbegin.h>

class KFbxMesh;
class KFbxSdkManager;

/** A mesh is a geometry made of polygons.
  * Functions to initialize, set and access vertices are provided in the
  * KFbxGeometry base class. A vertex is referred as a control point in the
  * KFbxGeometry base class. Though a control point is made of four elements,
  * meshes only use the first three to store the XYZ coordinates.
  * <p>
  * Since the mesh-related terminology of the FBX SDK differs a little from
  * the standard, here are some definitions:
  * <ul><li>A control point is a XYZ coordinate, it is synonym of vertex.
  *     <li>A polygon vertex is an index to a control point, it is synonym of vertex index.
  *     <li>A polygon is a group of polygon vertex.</ul>
  * \nosubgrouping
  */
class KFBX_DLL KFbxMesh : public KFbxGeometry
{
    KFBXOBJECT_DECLARE(KFbxMesh,KFbxGeometry);

public:
    /** Return the type of node attribute.
      * \return Return the type of this node attribute which is \e EAttributeType::eMESH.
      */
    virtual EAttributeType GetAttributeType() const;

    /**
      * \name Polygon Management
      */
    //@{

    /** Begin writing a polygon.
      * \param pMaterial Index of material to assign to this polygon if material mapping
      * type is \e eBY_POLYGON. Otherwise it must be \c -1.
      * \param pTexture Index of texture to assign to this polygon if texture mapping
      * type is \e eBY_POLYGON. Otherwise it must be \c -1.
      * \param pGroup Group index assigned to polygon.
      * \param pLegacy When set to \c true, automatically create a LayerElement of type Texture;
      * this was the old behavior.
      */
    void BeginPolygon(int pMaterial = -1, int pTexture = -1, int pGroup = -1, bool pLegacy=true);

    /** Begin writing a polygon.
      * \param pMaterial Index of material to assign to this polygon if material mapping
      * type is \e eBY_POLYGON. Otherwise it must be \c -1.
      * \param pTextures Array of index of texture to assign to this polygon if texture mapping
      * type is \e eBY_POLYGON. Otherwise it must be an array of \c -1.
      */
    void BeginPolygonExt(int pMaterial, int* pTextures);

    /** Add an index to a control point (i.e. a polygon vertex) to the current polygon.
      * \param pIndex Index to a control point (i.e. a polygon vertex).
      * \param pTextureUVIndex Index of texture UV coordinates to assign to this polygon
      * if texture UV mapping type is \e eBY_POLYGON_VERTEX. Otherwise it must be \c -1.
      */
    void AddPolygon(int pIndex, int pTextureUVIndex = -1);

    //! End writing a polygon.
    void EndPolygon();

    /** Get the polygon count of this mesh.
    * \return Return the number of polygons in the mesh.
    */
    inline int GetPolygonCount() const { return mPolygons.GetCount(); }

    /** Get the beginning index of a polygon.
      * \param pPolygonIndex Index of the polygon.
      * \return Return the beginning index of the polygon in the mesh.
      * If the polygon index is out of bounds, return -1.
      */
    inline int GetPolygonIndex(int pPolygonIndex) const
    {
        return pPolygonIndex < mPolygons.GetCount() ? mPolygons[pPolygonIndex].mIndex : -1;
    }

    /** Get the number of polygon vertices in a polygon.
      * \param pPolygonIndex Index of the polygon.
      * \return The number of polygon vertices in the indexed polygon.
      * If the polygon index is out of bounds, return -1.
      */
    inline int GetPolygonSize(int pPolygonIndex) const
    {
        return pPolygonIndex < mPolygons.GetCount() ? mPolygons[pPolygonIndex].mSize : -1;
    }

    /** Get the group index assigned to a polygon.
      * \param pPolygonIndex Index of the polygon.
      * \return Group index assigned to the polygon.
      * If the polygon index is out of bounds, return -1.
      */
    int GetPolygonGroup(int pPolygonIndex) const;

    /** Set the group index assigned to a polygon.
      * \param pPolygonIndex Index of the polygon.
      * \param pGroup Group index assigned to the polygon.
      * \return Group index assigned to the polygon.
      * If the polygon index is out of bounds, do nothing.
      */
    inline void SetPolygonGroup(int pPolygonIndex, int pGroup) const
    {
        if (pPolygonIndex<mPolygons.GetCount())
            mPolygons[pPolygonIndex].mGroup = pGroup;
    }

    /** Get a polygon vertex (i.e. an index to a control point).
      * \param pPolygonIndex Index of polygon.
      * The valid range for this parameter is 0 to \c KFbxMesh::GetPolygonCount().
      * \param pPositionInPolygon Position of polygon vertex in indexed polygon.
      * The valid range for this parameter is 0 to \c KFbxMesh::GetPolygonSize(pPolygonIndex).
      * \return Return the polygon vertex indexed or -1 if the requested vertex does not exists.
      */
    inline int GetPolygonVertex(int pPolygonIndex, int pPositionInPolygon) const
    {
        return pPolygonIndex < mPolygons.GetCount() && pPositionInPolygon < mPolygons[pPolygonIndex].mSize ?
            mPolygonVertices[mPolygons[pPolygonIndex].mIndex + pPositionInPolygon] : -1;
    }

    /** Get the normal associated with a polygon/vertex.
      * \param pPolyIndex Index of the polygon.
      * \param pVertexIndex Index of the vertex in the polygon space.
      * \param pNormal The returned normal.
      * \remarks \c pNormal remain unchanged if the requested vertex does
      * not exists.
      */
    void GetPolygonVertexNormal(int pPolyIndex, int pVertexIndex, KFbxVector4 &pNormal) const;

    /** Get the array of polygon vertices (i.e. index to control points).
      * This array is a concatenation of the list of polygon vertices
      * of all the polygons. Example: a mesh made of 2 triangles [1,2,3]
      * and [2,3,4] results in [1,2,3,2,3,4]. The first polygon starts at
      * position 0 and the second at position 3.
	  * \return The array of polygon vertices
      */
    int* GetPolygonVertices() const;

    /** Gets the number of polygon vertices in the mesh.
	  * \return The number of polygon vertices in the mesh.
      */
    int GetPolygonVertexCount() const;

    /** Gets the start index into the array returned by GetPolygonVertices()
      * for the given polygon.
      * \param pPolygonIndex The polygon to query
      * \return An index into the GetPolygonVertices() array
      */
    int GetPolygonVertexIndex( int pPolygonIndex ) const;

    /** Remove this polygon from the mesh. Update layers accordingly.
      * \param pPolygonIndex Index of the polygon.
      * \return Polygon index.
      * If the polygon index is out of bounds, return -1.
      */
    int RemovePolygon(int pPolygonIndex);

    //@}

    /**
      * \name Texture UV Utility Functions.
      * <p>
      * The functions you will find in this section are utility functions
      * to handle UV coordinates quickly. Internally they refer to \c KFbxLayer
      * and \c KFbxLayerElementUV methods to do the work.
      * These functions are only working on Layer 0. Use the \c KFbxLayer
      * methods directly to access other layers.
      */
    //@{

    /** Init texture UV coordinates.
      * \param pCount Number of texture UV elements.
	  * \param pTypeIdentifier
      * \remarks \c pCount must equal the number of control points of the Mesh if
      * the UV mapping mode is \e KFbxLayerElement::eBY_CONTROL_POINT.
      */
    void InitTextureUV(int pCount, KFbxLayerElement::ELayerElementType pTypeIdentifier=KFbxLayerElement::eDIFFUSE_TEXTURES);

    /** Add texture UV coordinates.
      * Appends a new element at the end of the array of texture UV coordinates.
      * \param pUV Texture UV coordinates, ranging between \c 0 and \c 1.
	  * \param pTypeIdentifier
      * \remarks The final number of texture UV elements must equal the number of control
      * points if the UV mapping mode is \e KFbxLayerElement::eBY_CONTROL_POINT.
      */
    void AddTextureUV(KFbxVector2 pUV, KFbxLayerElement::ELayerElementType pTypeIdentifier=KFbxLayerElement::eDIFFUSE_TEXTURES);

    /** Get the number of texture UV coordinates.
      * \param pTypeIdentifier Type of the layer.
      */
    int GetTextureUVCount(KFbxLayerElement::ELayerElementType pTypeIdentifier=KFbxLayerElement::eDIFFUSE_TEXTURES);

    /** Get the number of layer containing at least one channel UVMap.
      */
    int GetUVLayerCount();

    /** Get an array of UV of the different UV set for a layer.
      * \param pLayer Index of the layer.
      */
    KArrayTemplate<KFbxLayerElement::ELayerElementType> GetAllChannelUV(int pLayer);

    //@}

    /**
      * \name Material, Texture and UV Indices Utility Functions.
      * <p>
      * The functions you will find in this section are utility functions
      * to handle Material, Texture and UV indices. Internally they refer to \c KFbxLayer
      * and \c KFbxLayerElement methods to do the work.
      * These functions are only working on Layer 0. Use the \c KFbxLayer
      * methods directly to access other layers.
      */
    //@{

    /** Initialize material indices.
      * \param pMappingMode The mapping mode.
      * This function must be called after function KFbxGeometryBase::InitControlPoints().
      * The material indices refer to the position of a material in the KFbxLayerElementMaterial's direct array.
      * See KFbxLayerElementMaterial for more details. Supported mapping types are \e eBY_CONTROL_POINT,
      * \e eBY_POLYGON and \e eALL_SAME.
      *     - If mapping mode is \e eBY_CONTROL_POINT, there will be as many indices in the material index array
      *       as there are control points.
      *     - If mapping mode is \e eBY_POLYGON, there will be as many indices in the material index array
      *       as there are polygons in the mesh.
      *     - If mapping mode is \e eALL_SAME, there will be only one index in the material index array.
      * \remarks This function will set the Reference mode of the KFbxLayerElementMaterial on layer 0 to \e eINDEX_TO_DIRECT.
      */
    void InitMaterialIndices(KFbxLayerElement::EMappingMode pMappingMode);

    /** Initialize texture indices.
      * \param pMappingMode The mapping mode.
      * The texture indices refer to the position of a texture in the KFbxLayerElementTexture's direct array.
      * See KFbxLayerElementTexture for more details. Supported mapping modes are \e eBY_POLYGON
      * and \e eALL_SAME.
      *     - If mapping mode is \e eBY_POLYGON, there will be as many indices in the texture index array
      *       as there are polygons in the mesh.
      *     - If mapping mode is \e eALL_SAME, there will be only one index in the texture index array.
	  * \param pTextureType
      * \remarks This function will set the Reference mode of the KFbxLayerElementTexture on layer 0 to \e eINDEX_TO_DIRECT.
      */
    void InitTextureIndices(KFbxLayerElement::EMappingMode pMappingMode, KFbxLayerElement::ELayerElementType pTextureType);

    /** Initialize texture UV indices.
      * \param pMappingMode The mapping mode.
      * The texture UV indices refer to the index of an element in the KFbxLayerElementUV's direct array.
      * See KFbxLayerElementUV for more details. Supported mapping types are \e eBY_CONTROL_POINT , \e eBY_POLYGON_VERTEX
      * and \e eALL_SAME.
      *     - If mapping mode is \e eBY_CONTROL_POINT, there will be as many indices in the UV index array
      *       as there are control points. This will also set the Reference mode of the KFbxLayerElementUV on
      *       layer 0 to \e eDIRECT.
      *     - If mapping mode is \e eBY_POLYGON_VERTEX, there will be an index in the UV index array
      *       for each vertex, for each polygon it is part of. This will also set the Reference mode of the KFbxLayerElementUV on
      *       layer 0 to \e eINDEX_TO_DIRECT.
      *     - If mapping mode is \e eALL_SAME, there will be no index in the UV index array. This will also set the Reference
      *       mode of the KFbxLayerElementUV on layer 0 to \e eDIRECT.
	  * \param pTypeIdentifier
      */
    void InitTextureUVIndices(KFbxLayerElement::EMappingMode pMappingMode, KFbxLayerElement::ELayerElementType pTypeIdentifier=KFbxLayerElement::eDIFFUSE_TEXTURES);

    /** Get a texture UV index associated with a polygon vertex (i.e. an index to a control point).
      * \param pPolygonIndex Index of polygon.
      * The valid range for this parameter is 0 to KFbxMesh::GetPolygonCount().
      * \param pPositionInPolygon Position of polygon vertex in indexed polygon.
      * The valid range for this parameter is 0 to KFbxMesh::GetPolygonSize(pPolygonIndex).
	  * \param pTypeIdentifier
      * \return Return a texture UV index.
      * \remarks This function only works if the texture UV mapping mode is set to \e eBY_POLYGON_VERTEX,
      * otherwise it returns -1.
      */
    int GetTextureUVIndex(int pPolygonIndex, int pPositionInPolygon, KFbxLayerElement::ELayerElementType pTypeIdentifier=KFbxLayerElement::eDIFFUSE_TEXTURES);


    /** Set a texture UV index associated with a polygon vertex (i.e. an index to a control point).
      * \param pPolygonIndex Index of polygon.
      * The valid range for this parameter is 0 to KFbxMesh::GetPolygonCount().
      * \param pPositionInPolygon Position of polygon vertex in indexed polygon.
      * The valid range for this parameter is 0 to KFbxMesh::GetPolygonSize(pPolygonIndex).
      * \param pIndex The index of the texture UV we want to assign to the polygon vertex.
	  * \param pTypeIdentifier
      * \remarks This function only works if the texture UV mapping type is set to \e eBY_POLYGON_VERTEX.
      */
    void SetTextureUVIndex(int pPolygonIndex, int pPositionInPolygon, int pIndex, KFbxLayerElement::ELayerElementType pTypeIdentifier/*=KFbxLayerElement::eDIFFUSE_TEXTURES*/);

    //@}

    /**
      * \name Utility functions
      */
    //@{

    /** Reset the mesh to default values.
      * Frees and set to \c NULL all layers and clear the polygon and the control point array.
      */
    void Reset();

    /** Compute the vertex normals on the mesh.
      * The normals are per vertex and are the average of all the polygon normals
      * associated with each vertex.
      * \param pCW True if the normals are calculated clockwise, false otherwise (counter-clockwise).
      */
    void ComputeVertexNormals(bool pCW =  false);

    /** Compares the normals calculated by doing cross-products between the polygon vertex and by the ones
      * stored in the normal array.
      * \returns \c false if ALL of them are Clockwise. Returns \c true otherwise.
      */
    bool CheckIfVertexNormalsCCW();

    /** \enum ESplitObject Object of interest when splitting.
      */
    typedef enum
    {
        eBY_NORMAL  /**< Each split point will have a different normal for polygon/vertex.
                         This is for normal mapping emulation. */
    } ESplitObject;

    //! Internal structure used to keep the duplicate vertex information.
    class KDuplicateVertex
    {
    public:
		//!Constructor.
        KDuplicateVertex() :
          lVertexPolyIndex(0),
          lNewVertexIndex(0),
          lNormal(0,0,0)
          {
          };

        int lVertexPolyIndex ; //!< Index in mPolygonsVertex where the vertex is found.
        int lNewVertexIndex;   //!< The new index of the vertex.
        KFbxVector4 lNormal;    //!< The normal associated with this duplicate control point.
        KFbxVector2 lUV;        //!< The UV associated with this duplicate control point.

        int lEdgeIndex;         //!< The edge index.
    };

    //! Internal structure used to compute the normals on a mesh
    class KVertexNormalInfo
    {
    public:
		//!Constructor.
        KVertexNormalInfo():
          mTotalNormal(0,0,0),
          mNumNormal(0)
          {
          };

          KFbxVector4 mTotalNormal; //!< Sum of all the normals found.
          int mNumNormal;          //!< Number of normals added.
    };

    /** Verify if the mesh has polygons that are defined on the same point more than once.
      * \return true if the mesh has that kind of polygon, false otherwise.
      */
    bool CheckSamePointTwice();

    /** Remove bad polygons from a mesh.
      * Degenerate polygons use a vertex more than once. Remove them from the mesh and
      * from the layer element indices as needed.
      * \return Number of polygons removed from the mesh, -1 if an error occurred.
      */
    int RemoveBadPolygons();

    //@}

    /**
      * \name Point Splitting/Merging utility functions
      */
    //@{

    /** Split points.
    * \param pTypeIdentifier
	* \remarks This method replaces the BuildSplitList and SplitPointsForHardEdge.
    */
    void SplitPoints(KFbxLayerElement::ELayerElementType pTypeIdentifier=KFbxLayerElement::eDIFFUSE_TEXTURES);

    /** Insert the new indexes of the object that have to be merged.
      * \param pMergeList The list that will contain the indexes of the objects to merge.
      * \param pObject The object of interest of the merge.
      * \param pExport If set to \c true, include the duplicate indexes in the merge list.
      */
    bool BuildMergeList(KArrayTemplate<int> &pMergeList,ESplitObject pObject , bool pExport = false);

    /** Merge the points specified in the list.
      * \param pMergeList list containing the information on the points that will be merge
      */
    void MergePointsForPolygonVerteNormals(KArrayTemplate<int> &pMergeList);

    //@}


    /**
      * \name Edge management functions
      */
    //@{

    /** Automatically generate edge data for the mesh.
      * Clears all previously stored edge information
      */
    void BuildMeshEdgeArray();

    /** Query the number of edges defined on this mesh
      * \return The number of edges defined for this mesh
      */
    int GetMeshEdgeCount() const;

    /** Get the index for the edge between the given vertices.
      * Note that the result of this method is the same if pStartVertexIndex and pEndVertexIndex are
      * swapped.
      * \param pStartVertexIndex The starting point of the edge
      * \param pEndVertexIndex The ending point of the edge
      * \param pReversed flag will be set to true if the reverse edge is found, false otherwise
      * \return -1 if no edge exists for the given pair of vertices
      */
    int GetMeshEdgeIndex( int pStartVertexIndex, int pEndVertexIndex, bool& pReversed );

	/** Get the index for the specific edge of pPolygon.
	  * \param pPolygon The polygen.
	  * \param pPositionInPolygon The specific edge number in the polygon.
	  * \return -1 if the specific edge does not exist.
	  */
    int GetMeshEdgeIndexForPolygon( int pPolygon, int pPositionInPolygon );

    /** Get the vertices for the given edge. Note that the values returned are indices into the
      * control point array.
      * \param pEdgeIndex The edge to query
      * \param pStartVertexIndex The edge's starting point will be stored here
      * \param pEndVertexIndex The edge's starting point will be stored here
      */
    void GetMeshEdgeVertices( int pEdgeIndex, int& pStartVertexIndex, int& pEndVertexIndex );

    /**  Use this method before calling GetMeshEdgeVertices if making several calls to that method.
      *  Once done calling that method, call EndGetMeshEdgeVertices. This will optimize access time.
      *  Do not modify the mesh inbetween calls to BeginGetMeshEdgeVertices and EndGetMeshEdgeVertices.
      */
    void BeginGetMeshEdgeVertices();

	/**  Use this method after calling GetMeshEdgeVertices if making several calls to that method.
	  *  This will optimize access time.
	  *  Do not modify the mesh inbetween calls to BeginGetMeshEdgeVertices and EndGetMeshEdgeVertices.
	  */
    void EndGetMeshEdgeVertices();

    /** Presets the number edge data elements
      * \param pEdgeCount The number of edges to allocate
      */
    void SetMeshEdgeCount( int pEdgeCount );

    /** Sets element in edge array to specific value
      * \param pEdgeIndex The edge index
      * \param pValue The edge data
      */
    inline void SetMeshEdge( int pEdgeIndex, int pValue )
    {
        if( pEdgeIndex >= 0 && pEdgeIndex < mEdgeArray.GetCount() ) mEdgeArray[pEdgeIndex] = pValue;
    }

    /** Add an edge with the given start/end points. Note that the inserted edge
      * may start at the given end point, and end at the given start point.
      * \param pStartVertexIndex The starting point of the edge
      * \param pEndVertexIndex The ending point of the edge.
      * \param pCheckForDuplicates Set to true to check if the mesh already contains an edge with these two points.
      *  Can be set to false to speed up this method, when the incoming edges are known to be consistent.
      * \return Edge index of the new edge, or -1 on failure (edge/reverse edge already exists,
      *  no face using these 2 points consecutively )
      */
    int AddMeshEdgeIndex( int pStartVertexIndex, int pEndVertexIndex, bool pCheckForDuplicates );

    /** Set the index for the edge with the given start/end points. Note that the edge
      * may start at the given end point, and end at the given start point.
	  * \param pEdgeIndex The edge index of the edge.
      * \param pStartVertexIndex The starting point of the edge
      * \param pEndVertexIndex The ending point of the edge.
      * \param pCheckForDuplicates Set to true to check if the mesh already contains an edge with these two points.
      *  Can be set to false to speed up this method, when the incoming edges are known to be consistent.
      * \return Edge index of the edge, or -1 on failure (edge/reverse edge already exists,
      *  no face using these 2 points consecutively )
      */
    int SetMeshEdgeIndex( int pEdgeIndex, int pStartVertexIndex, int pEndVertexIndex, bool pCheckForDuplicates );

    /** Call this before calling AddMeshEdgeIndex or SetMeshEdgeIndex to increase performance.
      * Once finished adding/setting edges EndAddMeshEdgeIndex should be called.
      */
    void BeginAddMeshEdgeIndex();

    /** After calling AddMeshEdgeIndex or SetMeshEdgeIndex, EndAddMeshEdgeIndex should be called.
      */
    void EndAddMeshEdgeIndex();


    /** Adds an edge for the specified polygon, and edge number within the polygon
      * see SetMeshEdgeIndex for notes the the parameters.
      * \param pPolygonIndex The polygon
      * \param pPositionInPolygon The edge within the polygon
      * \return edge index or -1 if failed.
      */
    int AddMeshEdgeIndexForPolygon( int pPolygonIndex, int pPositionInPolygon );

    /** Sets the specified edge to the specified polygon's edge.
      * Note that the position in polygon ranges from 0 to GetPolygonSize(pPolygonindex) - 1
      * and represents the edge from GetPolygonVertex(pPolygonIndex, pPositionInPolygon) to
      * GetPolygonVertex( pPolygonIndex, pPositionInPolygon + 1 ) or from pPositionInPolygon to
      * 0 if pPositionInPolygon == GetPolygonSize(pPolygonindex) - 1
      * \param pEdgeIndex The edge
      * \param pPolygonIndex The polygon
      * \param pPositionInPolygon The specific edge number in the polygon
      * \return true on success, false on failure. ( edge for the poly and position already exists )
      */
    bool SetMeshEdgeIndex( int pEdgeIndex, int pPolygonIndex, int pPositionInPolygon );


	//!Internal structure used to keep the mapping information between edges and polygons.
    struct KFbxComponentMap
    {
        KArrayTemplate<int> mData; //!< The array to store data.
        KArrayTemplate<int> mOffsets; //!< The array to store the offsets of the data in mData.

        int GetDataCount(int pIndex) { return mOffsets[pIndex + 1] - mOffsets[pIndex]; }
        int GetData(int pIndex, int pSubIndex) { return mData[ mOffsets[pIndex] + pSubIndex ]; }
        int GetComponentCount() { return mOffsets.GetCount() - 1; }
    };

	/** Computer component maps.
	  * \param pEdgeToPolyMap
	  * \param pPolyToEdgeMap
	  */
    void ComputeComponentMaps( KFbxComponentMap& pEdgeToPolyMap, KFbxComponentMap& pPolyToEdgeMap );

    /** Determines if the mesh is composed entirely of triangles.
      * \return true if all polygons are triangles, false otherwise
      */
    bool IsTriangleMesh() const;

    //@}

///////////////////////////////////////////////////////////////////////////////
//
//  WARNING!
//
//  Anything beyond these lines may not be documented accurately and is
//  subject to change without notice.
//
///////////////////////////////////////////////////////////////////////////////

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:

    /** Reserve memory in the polygon array to hold the specified number of polygons
      * \param pCount The number of polygons this mesh will hold
      */
    inline void ReservePolygonCount( int pCount ) { mPolygons.Reserve( pCount ); }

    /** Reserve memory in the polygon vertex array to hold the specified number
      * of polygon vertices.
      * \param pCount The number of polygon vertices
      */
    inline void ReservePolygonVertexCount( int pCount ) { mPolygonVertices.Reserve( pCount ); }

    // Clone
    virtual KFbxObject* Clone(KFbxObject* pContainer, KFbxObject::ECloneType pCloneType) const;

    bool GetTextureUV(KFbxLayerElementArrayTemplate<KFbxVector2>** pLockableArray, KFbxLayerElement::ELayerElementType pTypeIdentifier=KFbxLayerElement::eDIFFUSE_TEXTURES) const;
    bool GetMaterialIndices(KFbxLayerElementArrayTemplate<int>** pLockableArray) const;
    bool GetTextureIndices(KFbxLayerElementArrayTemplate<int>** pLockableArray, KFbxLayerElement::ELayerElementType pTextureType) const;


    /**
    * \name Crease utility functions
    */
    //@{

    /** GetEdgeCreaseInfo Get crease weight by edge index
      * \param pEdgeIndex   Edge index
      * \return float       Crease weight (0.0 ~ 1.0)
      */
    double GetEdgeCreaseInfo(int pEdgeIndex);

    /** GetVertexCreaseInfo Get crease weight by vertex index(an index to a control point)
      * \param pVertexIndex Vertex index
      * \return float       Crease weight (0.0 ~ 1.0)
      */
    double GetVertexCreaseInfo(int pVertexIndex);

    /** SetEdgeCreaseInfo   Set crease weight by edge index
      * \param pEdgeIndex   Edge index
      * \param pWeight      Crease weight (0.0 ~ 1.0)
      * \return bool        return \ctrue if successfully set the crease weight
      */
    bool SetEdgeCreaseInfo(int pEdgeIndex, double pWeight);

    /** SetVertexCreaseInfo Set crease weight by vertex index
      * \param pVertexIndex Vertex index
      * \param pWeight      Crease weight (0.0 ~ 1.0)
      * \return bool        return \ctrue if successfully set the crease weight
      */
    bool SetVertexCreaseInfo(int pVertexIndex, double pWeight);

    //@}

    /**
    * \name Smooth mesh preview utility functions
    */ 
    //@{

    /** Display Smoothness, it represents smooth mesh preview mode 
    * \HULL the default value, NOT active "smooth mesh preview"
    * \ROUGH NOT active "smooth mesh preview"
    * \MEDIUM both display cage and smooth mesh
    * \FINE display smooth mesh
    */
    enum MeshSmoothness
    {
        HULL,
        ROUGH,
        MEDIUM,
        FINE,
    };


    /** Get display smoothness from mesh
      * \return mesh smoothness
      * \remarks it represents smooth mesh preview mode
      */
    KFbxMesh::MeshSmoothness GetMeshSmoothness() const;

    /** Set mesh display smoothness (mode)
      * \param pSmoothness new smoothness factor
      * \remarks it represents smooth mesh preview mode
      * KFbxMesh::HULL the default value, NOT active "smooth mesh preview"
      * KFbxMesh::ROUGH NOT active "smooth mesh preview"
      * KFbxMesh::MEDIUM both display cage and smooth mesh
      * KFbxMesh::FINE display smooth mesh
      */
    void SetMeshSmoothness(KFbxMesh::MeshSmoothness pSmoothness);

    /** Get preview subdivision levels from mesh
    * \return mesh preview subdivision levels 
    */
    int GetMeshPreviewDivisionLevels() const;

    /** Set mesh preview subdivision levels
    * \param pPreviewDivisionLevels 
    */
    void SetMeshPreviewDivisionLevels(int pPreviewDivisionLevels);

    /** Get render subdivision levels from mesh
    * \return mesh render subdivision levels 
    * \remarks sometimes, render division level is same as preview level
    */
    int GetMeshRenderDivisionLevels() const;

    /** Set mesh render subdivision levels
    * \param pRenderDivisionLevels 
    */
    void SetMeshRenderDivisionLevels(int pRenderDivisionLevels);

    /** Query whether to display subdivisions isolines on mesh
    * \return the flag of DisplySubdivisions
    */
    bool GetDisplaySubdivisions() const;

    /** Set the flag of DisplySubdivisions
    * \param pDisplySubdivisions
    */
    void SetDisplaySubdivisions(bool pDisplySubdivisions);

    //@}

protected:

    void InitTextureIndices(KFbxLayerElementTexture* pLayerElementTexture, KFbxLayerElement::EMappingMode pMappingMode);
    void RemoveTextureIndex(KFbxLayerElementTexture* pLayerElementTextures, int pPolygonIndex, int pOffset);
    void RemoveUVIndex(KFbxLayerElementUV* pLayerElementUV, int pPolygonIndex, int pOffset);

    bool IsBadPoly(int pPolygonIndex);

    KFbxMesh(KFbxSdkManager& pManager, char const* pName);

    virtual void Destruct(bool pRecursive, bool pDependents);

    //! Assignment operator.
    KFbxMesh& operator= (KFbxMesh const& pMesh);

    virtual KString     GetTypeName() const;
    virtual KStringList GetTypeFlags() const;

    struct KFbxPolygon
    {
        int mIndex;
        int mSize;
        int mGroup;
    };

    struct KFbxSplitEdgeData
    {
        int mOriginalEdge;
        bool mIsNew;
    };

    //smooth mesh preview
    MeshSmoothness mSmoothness;
    int mPreviewDivisionLevels;
    int mRenderDivisionLevels;

    bool mDisplaySubdivisions;

    KArrayTemplate<KFbxPolygon> mPolygons;
public:
    KArrayTemplate<int> mPolygonVertices;

protected:
    struct KFbxPolyIndex
    {
        int mPolygonIndex;
        int mSubPolygonIndex;
    };

    struct KFbxV2PVMap
    {
        KFbxPolyIndex* mV2PV;
        int* mV2PVOffset;
        int* mV2PVCount;
        bool mValid;
    };

    KFbxV2PVMap mV2PVMap;

    struct KFbxEdgeLookup
    {
        KArrayTemplate<int> mPVFlags;
        bool mValid;
    };

    KFbxEdgeLookup mPVEndFlags;

public:
    KArrayTemplate< int > mEdgeArray;

protected:
    // Finds the polygon index for the given edge
    int FindPolygonIndex( int pEdgeIndex );
    static int PolygonIndexCompare( const void *p1, const void *p2 );

    void PolySetTexture(KFbxLayer* pLayer, int pTextureIndex,
                        KFbxLayerElement::ELayerElementType pTextureType);

    friend class KFbxGeometryConverter;
    friend class KFbxWriter3DS;

#endif // #ifndef DOXYGEN_SHOULD_SKIP_THIS

};


typedef KFbxMesh* HKFbxMesh;

#include <fbxfilesdk/fbxfilesdk_nsend.h>

#endif // FBXFILESDK_KFBXPLUGINS_KFBXMESH_H

