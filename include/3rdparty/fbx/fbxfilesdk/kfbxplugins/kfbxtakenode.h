/*!  \file kfbxtakenode.h
 */

#ifndef FBXFILESDK_KFBXPLUGINS_KFBXTAKENODE_H
#define FBXFILESDK_KFBXPLUGINS_KFBXTAKENODE_H

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

#include <fbxfilesdk/components/kbaselib/klib/kerror.h>

#include <fbxfilesdk/components/kbaselib/kbaselib_forward.h>

#include <fbxfilesdk/components/kfcurve/kfcurve_forward.h>

#include <fbxfilesdk/fbxfilesdk_nsbegin.h>

class KFbxGeometry;
class KFbxVector4;
class KFbxProperty;
class KFbxObject;

#define KFBXTAKENODE_DEFAULT_NAME           "Default"
#define KFBXTAKENODE_ROOT_CURVE_NODE_NAME   "Defaults"


/** \brief A take node contains channels of animation.
  * An object derived from class KFbxTakeNodeContainer contains multiple take
  * nodes to hold animation data.
  *
  * In the case of class KFbxNode, a take node contains all animation curves
  * necessary to define the animation for a node and its attribute. By having
  * multiple take nodes, a node might be animated differently. A scene
  * description held in a node hierarchy can be animated differently using
  * different animation take nodes.
  *
  * This object can be used to access the different animation curves
  * that define a take node. Some channels are only accessible once the
  * proper node attribute has been associated with an object of type KFbxNode.
  * \nosubgrouping
  */
class KFBX_DLL KFbxTakeNode
{

public:
    /**
      * \name Take Node creation/destruction.
      */
    //@{

    /** Constructor.
      * \param pName The name of the take this node is part of.
      */
    KFbxTakeNode(char* pName = KFBXTAKENODE_DEFAULT_NAME);

    /** Copy constructor.
      * \param pTakeNode A node from which data is cloned.
      */
    KFbxTakeNode(KFbxTakeNode& pTakeNode);

    //! Destructor.
    ~KFbxTakeNode();

    //@}

    /**
      * \name Take Node name management.
      */
    //@{

    /** Set take node name.
      * \param pName The name of the take this node is part of.
      */
    void SetName(char* pName);

    /** Get take node name.
      * \return Return the name of the take this node is part of.
      */
    char* GetName();

    //@}

    /** Get pointer to root KFCurveNode object.
      * \remarks All the channels of a take node are accessible by browsing
      * the KFCurveNode tree under this object.
      */
    KFCurveNode* GetKFCurveNode();
    /**
      * \name Error Management
      */
    //@{

    /** Retrieve error object.
     *  \return Reference to the take node's error object.
     */
    KError& GetError();

    /** \enum EError Error identifiers.
      */
    typedef enum
    {
        eNO_CURVE_FOUND, /**< The requested FCurve was not found. */
        eERROR_COUNT     /**< Mark the end of the EError enum.    */
    } EError;

    /** Get last error code.
     *  \return Last error code.
     */
    EError GetLastErrorID() const;

    /** Get last error string.
     *  \return Textual description of the last error.
     */
    const char* GetLastErrorString() const;

    //@}

    /**
      * \name Utility functions used by some plugins etc.
      *
      */
    //@{

    /** Find out start and end time of the animation.
      * This function retrieves the including time span for all
      * the FCurve's time span of this take node.
      * \param pStart Reference to receive start time.
      * \param pStop Reference to receive end time.
      * \return \c true on success, \c false otherwise.
      */
    bool GetAnimationInterval(KTime& pStart, KTime& pStop);

    /** Rotates the translation animation at a given angle
     *  \param pRotation vector containing the rotation.
     *  \returns \c True if everything went ok.
     */
    bool AddRotationToTranslation(KFbxVector4 pRotation);


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

    bool IsChannelAnimated(char* pGroup, char* pSubGroup, char* pName);
    bool IsChannelAnimated(char* pGroup, char* pSubGroup, KDataType* pDataType);

private:

    void DeleteRecursive(KFCurveNode* pNode);
    KFCurve* GetKFCurve(char* pGroup, char* pSubGroup, char* pName);
    KFCurve const* GetKFCurve(char* pGroup, char* pSubGroup, char* pName) const;
    KFCurve* GetKFCurve(char* pGroup, char* pSubGroup, KDataType* pDataType);
    KFCurve const* GetKFCurve(char* pGroup, char* pSubGroup, KDataType* pDataType) const;

    KString mName;
    KFCurveNode* mNode;

    KError mError;

    friend class KFbxTakeNodeContainer;

#endif // #ifndef DOXYGEN_SHOULD_SKIP_THIS

};

typedef KFbxTakeNode* HKFbxTakeNode;

#include <fbxfilesdk/fbxfilesdk_nsend.h>

#endif // FBXFILESDK_KFBXPLUGINS_KFBXTAKENODE_H

