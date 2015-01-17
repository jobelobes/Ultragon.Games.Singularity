/*!  \file kfbxgeometrybase.h
 */

#ifndef FBXFILESDK_KFBXPLUGINS_KFBXGEOMETRYBASE_H
#define FBXFILESDK_KFBXPLUGINS_KFBXGEOMETRYBASE_H

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

#include <fbxfilesdk/components/kbaselib/klib/karrayul.h>

#include <fbxfilesdk/kfbxmath/kfbxvector4.h>

#include <fbxfilesdk/kfbxplugins/kfbxlayercontainer.h>

#include <fbxfilesdk/fbxfilesdk_nsbegin.h>

class KFbxSdkManager;

/** \brief This class is the base class for managing control points.
  * Use the KFbxGeometryBase class to manage control points for mesh, nurbs, patches and normals (on Layer 0).
  * \nosubgrouping
  */
class KFBX_DLL KFbxGeometryBase : public KFbxLayerContainer
{
    KFBXOBJECT_DECLARE(KFbxGeometryBase,KFbxLayerContainer);
public:

    /**
      * \name Control Points and Normals Management.
      */
    //@{

    /** Allocate memory space for the array of control points.
      * \param pCount     The number of control points.
      * \remarks          Any previously allocated array of control points will be cleared.
      */
    virtual void InitControlPoints(int pCount);

    /** Allocate memory space for the array of normals.
      * \param pCount     The desired size for the normal array. If pCount is specified, the array will have the same size as pCount.
      *                   If pCount is not specified, the array will be the same length as the array of control points.
      * \remarks          This function must be called after function KFbxLayerContainer::InitControlPoints().
      * \remarks          The normals initialized with this function will have the ReferenceMode set to eDIRECT.
      */
    void InitNormals(int pCount = 0 );

    /** Allocate memory space for the array of normals cloning them from the pSrc.
      * \param pSrc       The source geometry from wich we will clone the normals information (on Layer 0).
      * \remarks          This function must be called with the argument otherwise it will do nothing.
      */
    void InitNormals(KFbxGeometryBase* pSrc);

    /** Allocate memory space for the array of tangents.
      * \param pCount     The desired size for the tangent array. If pCount is specified, the array will have the same size as pCount.
      *                   If pCount is not specified, the array will be the same length as the array of control points.
      * \remarks          This function must be called after function KFbxLayerContainer::InitControlPoints().
      * \remarks          The tangents initialized with this function will have the ReferenceMode set to eDIRECT.
      */
    void InitTangents(int pCount = 0 );

    /** Allocate memory space for the array of tangents cloning them from the pSrc.
      * \param pSrc       The source geometry from wich we will clone the tangents information (on Layer 0).
      * \remarks          This function must be called with the argument otherwise it will do nothing.
      */
    void InitTangents(KFbxGeometryBase* pSrc);

    /** Allocate memory space for the array of binormals.
      * \param pCount     The desired size for the binormal array. If pCount is specified, the array will have the same size as pCount.
      *                   If pCount is not specified, the array will be the same length as the array of control points.
      * \remarks          This function must be called after function KFbxLayerContainer::InitControlPoints().
      * \remarks          The binormals initialized with this function will have the ReferenceMode set to eDIRECT.
      */
    void InitBinormals(int pCount = 0 );

    /** Allocate memory space for the array of binormals cloning them from the pSrc.
      * \param pSrc       The source geometry from wich we will clone the binormals information (on Layer 0).
      * \remarks          This function must be called with the argument otherwise it will do nothing.
      */
    void InitBinormals(KFbxGeometryBase* pSrc);

    /** Sets the control point and the normal values for a given index.
      * \param pCtrlPoint     The value of the control point.
      * \param pNormal        The value of the normal.
      * \param pIndex         The index of the control point/normal to be modified.
      * \param pI2DSearch     When true AND the normals array reference mode is eINDEX_TO_DIRECT, search pNormal in the
      *                       existing array to avoid inserting it if it already exist. NOTE: this feature uses a linear
      *                       search algorithm, therefore it can be time consuming if the DIRECT array of normals contains
      *                       a huge number of elements.
      * \remarks              If the arrays are not big enough to store the values at the given index, their size will be increased.
      */
    virtual void SetControlPointAt(KFbxVector4 &pCtrlPoint , KFbxVector4 &pNormal , int pIndex, bool pI2DSearch = false);


    /** Sets the control point for a given index.
    * \param pCtrlPoint     The value of the control point.
    * \param pIndex         The index of the control point/normal to be modified.
    *
    * \remarks              If the arrays are not big enough to store the values at the given index, their size will be increased.
    */
    virtual void SetControlPointAt(KFbxVector4 &pCtrlPoint , int pIndex);

    /** Sets the the normal values for a given index.
    * \param pNormal        The value of the normal.
    * \param pIndex         The index of the control point/normal to be modified.
    * \param pI2DSearch     When true AND the normals array reference mode is eINDEX_TO_DIRECT, search pNormal in the
    *                       existing array to avoid inserting it if it already exist. NOTE: this feature uses a linear
    *                       search algorithm, therefore it can be time consuming if the DIRECT array of normals contains
    *                       a huge number of elements.
    * \remarks              If the arrays are not big enough to store the values at the given index, their size will be increased.
    */
    virtual void SetControlPointNormalAt(KFbxVector4 &pNormal, int pIndex, bool pI2DSearch=false);

    /** Get the number of control points.
      * \return     The number of control points allocated in the geometry.
      */
    virtual int GetControlPointsCount() const;


    /** Get a pointer to the array of control points.
      * \return      Pointer to the array of control points, or \c NULL if the array has not been allocated.
      * \remarks     Use the function KFbxGeometryBase::InitControlPoints() to allocate the array.
      */
    virtual KFbxVector4* GetControlPoints() const;

	virtual void SetControlPointCount(int pCount);

    //@}


    /**
      * \name Public and fast access Properties
      */
    //@{
        KFbxTypedProperty<fbxDouble3>               BBoxMin;
        KFbxTypedProperty<fbxDouble3>               BBoxMax;

        /** Compute the Bounding box of the ControlPoints.
          */
        void ComputeBBox();
    //@}

    /**
      * \name Off-loading Serialization section
      */
    //@{
        virtual bool ContentWriteTo(KFbxStream& pStream) const;
        virtual bool ContentReadFrom(const KFbxStream& pStream);
    //@}

        virtual int MemoryUsage() const;

///////////////////////////////////////////////////////////////////////////////
//
//  WARNING!
//
//  Anything beyond these lines may not be documented accurately and is
//  subject to change without notice.
//
///////////////////////////////////////////////////////////////////////////////

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    bool GetNormals(KFbxLayerElementArrayTemplate<KFbxVector4>** pLockableArray) const;
    bool GetNormalsIndices(KFbxLayerElementArrayTemplate<int>** pLockableArray) const;

    bool GetTangents(KFbxLayerElementArrayTemplate<KFbxVector4>** pLockableArray) const;
    bool GetTangentsIndices(KFbxLayerElementArrayTemplate<int>** pLockableArray) const;

    bool GetBinormals(KFbxLayerElementArrayTemplate<KFbxVector4>** pLockableArray) const;
    bool GetBinormalsIndices(KFbxLayerElementArrayTemplate<int>** pLockableArray) const;

protected:
    KFbxGeometryBase(KFbxSdkManager& pManager, char const* pName);

    KFbxGeometryBase& operator=(KFbxGeometryBase const& pGeometryBase);
    virtual bool ConstructProperties(bool pForceSet);
    virtual void ContentClear();

public:
    KArrayTemplate<KFbxVector4> mControlPoints;

protected:
    friend class KFbxGeometryConverter;
#endif // #ifndef DOXYGEN_SHOULD_SKIP_THIS

};

#include <fbxfilesdk/fbxfilesdk_nsend.h>

#endif // FBXFILESDK_KFBXPLUGINS_KFBXGEOMETRYBASE_H

