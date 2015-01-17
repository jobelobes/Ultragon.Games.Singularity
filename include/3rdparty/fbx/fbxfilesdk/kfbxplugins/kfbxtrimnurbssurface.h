/*!  \file kfbxtrimnurbssurface.h
 */

#ifndef FBXFILESDK_KFBXPLUGINS_KFBXTRIMNURBSSURFACE_H
#define FBXFILESDK_KFBXPLUGINS_KFBXTRIMNURBSSURFACE_H

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
#include <fbxfilesdk/kfbxplugins/kfbxnurbssurface.h>
#include <fbxfilesdk/kfbxplugins/kfbxnurbscurve.h>
#include <fbxfilesdk/kfbxplugins/kfbxgenericnode.h>


#include <fbxfilesdk/fbxfilesdk_nsbegin.h>

/** KFbxBoundary Describes a trimming boundary for a trimmed nurbs object.
  * Note that outer boundaries run counter-clockwise in UV space and inner
  * boundaries run clockwise. An outer boundary represents the outer edges
  * of the trimmed surface whereas the inner boundaries define "holes" in
  * the surface.
  */
class KFBX_DLL KFbxBoundary : public KFbxGeometry
{
    KFBXOBJECT_DECLARE(KFbxBoundary,KFbxGeometry);

public:

    // Properties
    static const char* sOuterFlag;

    /** Add an edge to this boundary
      * \param pCurve The curve to append to the end of this boundary
      */
    void AddCurve( KFbxNurbsCurve* pCurve );

    /** \return The number of edges in this boundary
      */
    int GetCurveCount() const;

    /** Access the edge at index pIndex
      * \param pIndex The index of the edge to return.  No bounds checking is done
      * \return The edge at index pIndex if
      *  pIndex is in the range [0, GetEdgeCount() ),
      *  otherwise the return value is undefined
      */
    KFbxNurbsCurve* GetCurve( int pIndex );

    /** Access the edge at index pIndex
      * \param pIndex The index of the edge to return.  No bounds checking is done
      * \return The edge at index pIndex if
      *  pIndex is in the range [0, GetEdgeCount() ),
      *  otherwise the return value is undefined
      */
    KFbxNurbsCurve const* GetCurve( int pIndex ) const;


    //!Return the type of node attribute.
    virtual EAttributeType GetAttributeType() const { return KFbxNodeAttribute::eBOUNDARY; }

    /** Detect if the point is in the boundary's control hull
    * \param pPoint The point to detect.
    * \return The state if the point is in the boundary' control hull.
    */
    bool IsPointInControlHull( KFbxVector4& pPoint );

    /** Compute point in boundary
    * \return The point.
    */
    KFbxVector4 ComputePointInBoundary();



#ifndef DOXYGEN_SHOULD_SKIP_THIS
///////////////////////////////////////////////////////////////////////////////
//
//  WARNING!
//
//  Anything beyond these lines may not be documented accurately and is
//  subject to change without notice.
//
///////////////////////////////////////////////////////////////////////////////

protected:

    KFbxBoundary(KFbxSdkManager& pManager, char const* pName);

    virtual void Construct(const KFbxBoundary* pFrom);

    //! assignment operator
    KFbxBoundary& operator=(KFbxBoundary const& pBoundary);

    virtual KString GetTypeName() const;
    virtual KStringList GetTypeFlags() const;

    void Reset();


    bool LineSegmentIntersect( KFbxVector4 & pStart1, KFbxVector4 & pEnd1,
                               KFbxVector4 & pStart2, KFbxVector4 & pEnd2 ) const;


public:
    // Clone
    virtual KFbxObject* Clone(KFbxObject* pContainer, KFbxObject::ECloneType pCloneType = eDEEP_CLONE) const;

    void ClearCurves();

    void CopyCurves( KFbxBoundary const& pOther );

    bool IsValid(bool mustClosed = true);

    bool IsCounterClockwise();

#endif // DOXYGEN_SHOULD_SKIP_THIS
};


/** KFbxTrimNurbsSurface Describes a nurbs surface with regions
    trimmed or cut away with trimming boundaries.
  */
class KFBX_DLL KFbxTrimNurbsSurface : public KFbxGeometry
{
    KFBXOBJECT_DECLARE(KFbxTrimNurbsSurface,KFbxGeometry);
public:
    //! Return the type of node attribute
    virtual EAttributeType GetAttributeType() const { return KFbxNodeAttribute::eTRIM_NURBS_SURFACE; }


    /** Returns the number of regions on this trimmed nurbs surface.
      * Note there is at always at least one trim region.
      * \return The number of regions
      */
    int GetTrimRegionCount() const;

    /** Call this before adding boundaries for a new trim region.
      * The number of regions is incremented on this call.
      */
    void BeginTrimRegion();

    /** Call this after the last boundary for a given region is added.
      * If no boundaries are added in between calls to BeginTrimRegion
      * and EndTrimRegion, the last region is removed.
      */
    void EndTrimRegion();

    /** Appends a trimming boundary to the set of trimming boundaries.
      * The first boundary specified for a given trim region should be
      * the outer boundary. All other boundaries are inner boundaries.
      * This must be called after a call to BeginTrimRegion(). Boundaries
      * cannot be shared among regions. Duplicate the boundary if necessary.
      * See KFbxBoundary
      * \param pBoundary The boundary to add.
      * \return true if the boundary was added,
      *         false otherwise
      */
    bool              AddBoundary( KFbxBoundary* pBoundary );

    /** Gets the boundary at a given index for a given region
      * \param pIndex The index of the boundary to retrieve.  No bounds checking is done.
      * \param pRegionIndex The index of the region which is bound by the boundary.
      * \return The trimming boundary at index pIndex,
      * if pIndex is in the range [0, GetBoundaryCount() )
      * otherwise the result is undefined.
      */
    KFbxBoundary*     GetBoundary( int pIndex, int pRegionIndex = 0 );

    /** Gets the boundary at a given index for a given region
      * \param pIndex The index of the boundary to retrieve.  No bounds checking is done.
      * \param pRegionIndex The index of the region which is bound by the boundary.
      * \return The trimming boundary at index pIndex,
      * if pIndex is in the range [0, GetBoundaryCount() )
      * otherwise the result is undefined.
      */
    KFbxBoundary const*     GetBoundary( int pIndex, int pRegionIndex = 0 ) const;

    /** Gets the number of boundaries on this surface
	  * \param pRegionIndex The index of the region 
      * \return The number of trim boundaries
      */
    int               GetBoundaryCount(int pRegionIndex = 0) const;

    /** Set the nurbs surface that will be trimmed by the trimming boundaries.
      * \param pNurbs Nurbs
      */
    void       SetNurbsSurface( KFbxNurbsSurface const* pNurbs );

    /** Gets the untrimmed surface that is trimmed by the trim boundaries.
      * \return Pointer to the (untrimmed) nurbs surface.
      */
    KFbxNurbsSurface* GetNurbsSurface();

    /** Gets the untrimmed surface that is trimmed by the trim boundaries.
      * \return Pointer to the (untrimmed) nurbs surface.
      */
    KFbxNurbsSurface const* GetNurbsSurface() const;

    /** The normals of the surface can be reversed to reverse the surface
      * \param pFlip If true, the surface is reversed, else the surface is not reversed.
      */
    inline void SetFlipNormals( bool pFlip ) { mFlipNormals = pFlip; }

    /** Check if the normals are flipped
      * \return True if normals are flipped, false otherwise
      */
    inline bool GetFlipNormals() const { return  mFlipNormals; }



    /**
      * \name Shape Management
      */
    //@{

    /** Shapes on trim nurbs are stored on the untrimmed surface.
      * Thus, this is equivalent to calling GetNurbsSurface()->AddShape()
      * See KFbxGeometry::AddShape() for method description.
      * \param pShape         Pointer to the shape object.
      * \param pShapeName     Name given to the shape.
	  * \return -1
      */
    virtual int AddShape(KFbxShape* pShape, char const* pShapeName);

    /** Shapes on trim nurbs are stored on the untrimmed surface.
      * Thus, this is equivalent to calling GetNurbsSurface()->ClearShape()
      * See KFbxGeometry::ClearShape() for method description.
      */
    virtual void ClearShape();

    /** Shapes on trim nurbs are stored on the untrimmed surface.
      * Thus, this is equivalent to calling GetNurbsSurface()->GetShapeCount()
      * See KFbxGeometry::GetShapeCount() for method description.
      */
    virtual int GetShapeCount() const;

    /** Shapes on trim nurbs are stored on the untrimmed surface.
      * Thus, this is equivalent to calling GetNurbsSurface()->GetShape()
      * See KFbxGeometry::GetShape() for method description.
      * \param pIndex     Index of shape.
      */
    virtual KFbxShape* GetShape(int pIndex);

    /** Shapes on trim nurbs are stored on the untrimmed surface.
      * Thus, this is equivalent to calling GetNurbsSurface()->GetShape()
      * See KFbxGeometry::GetShape() for method description.
      * \param pIndex     Index of shape.
      */
    virtual KFbxShape const* GetShape(int pIndex) const;


    /** Shapes on trim nurbs are stored on the untrimmed surface.
      * Thus, this is equivalent to calling GetNurbsSurface()->GetShapeName()
      * See KFbxGeometry::GetShapeName() for method description.
      * \param pIndex     Index of shape.
      */
    virtual char const* GetShapeName(int pIndex) const;


    /** Shapes on trim nurbs are stored on the untrimmed surface.
      * Thus, this is equivalent to calling GetNurbsSurface()->GetShapeChannel()
      * See KFbxGeometry::GetShapeChannel() for method description.
      * \param pIndex          Shape index.
      * \param pCreateAsNeeded If true, the fcurve is created if not already present.
      * \param pTakeName       Take from which we want the FCurve (if NULL, use the current take).
      */
    virtual KFCurve* GetShapeChannel(int pIndex, bool pCreateAsNeeded = false, char const* pTakeName = NULL);
    //@}

     //!Return the nurb surface's control points count.
    virtual int GetControlPointsCount() const;

    /** Set a control point of the nurb surface.
    * \param pCtrlPoint The control point's location. 
    * \param pNormal The control point's normal.
    * \param pIndex The index of control point to be set.
    */
    virtual void SetControlPointAt(KFbxVector4 &pCtrlPoint, KFbxVector4 &pNormal , int pIndex);

     //!Return the nurb surface's control points.
    virtual KFbxVector4* GetControlPoints() const;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
///////////////////////////////////////////////////////////////////////////////
//
//  WARNING!
//
//  Anything beyond these lines may not be documented accurately and is
//  subject to change without notice.
//
///////////////////////////////////////////////////////////////////////////////

public:
    // Clone
    virtual KFbxObject* Clone(KFbxObject* pContainer, KFbxObject::ECloneType pCloneType = eDEEP_CLONE) const;

    /**
      * \param mustClosed     boundary curve must be closed
      */
    bool IsValid(bool mustClosed = true);

protected:

    KFbxTrimNurbsSurface(KFbxSdkManager& pManager, char const* pName);

    //! assignment operator
    KFbxTrimNurbsSurface& operator=(KFbxTrimNurbsSurface const& pTrimmedNurbs);

public:
    virtual KString GetTypeName() const;
    virtual KStringList GetTypeFlags() const;

    void ClearBoundaries();

    void CopyBoundaries( KFbxTrimNurbsSurface const& pOther );

    bool IsValid(int pRegion, bool mustClosed = true);

    void RebuildRegions();

private:
    bool mFlipNormals;

    KArrayTemplate<int> mRegionIndices;

    bool mNewRegion;

#endif // DOXYGEN_SHOULD_SKIP_THIS
};

typedef KFbxTrimNurbsSurface*   HKFbxTrimNurbsSurface;
typedef KFbxBoundary*           HKFbxBoundary;

#include <fbxfilesdk/fbxfilesdk_nsend.h>

#endif // FBXFILESDK_KFBXPLUGINS_KFBXTRIMNURBSSURFACE_H

