/*!  \file kfbxselectionset.h
*/

#ifndef FBXFILESDK_KFBXPLUGINS_KFBXSELECTIONSET_H
#define FBXFILESDK_KFBXPLUGINS_KFBXSELECTIONSET_H

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

#include <fbxfilesdk/fbxcore/fbxcollection/kfbxcollection.h>
#include <fbxfilesdk/components/kbaselib/klib/kname.h>
#include <fbxfilesdk/kfbxplugins/kfbxsdkmanager.h>
#include <fbxfilesdk/kfbxplugins/kfbxnode.h>
#include <fbxfilesdk/kfbxplugins/kfbxselectionnode.h>

#include <fbxfilesdk/fbxfilesdk_nsbegin.h>

/** FBX SDK selection set class.
* \nosubgrouping
*  Any object can be added to a selection set directly. 
*  To add components (vertex, edge or face) of an object to a selection set, 
*  a selection node need to be constructed to organize the object and its components together,
*  then add the selection node to the selection set.
*/
class KFBX_DLL KFbxSelectionSet : public KFbxCollection
{
    KFBXOBJECT_DECLARE(KFbxSelectionSet, KFbxCollection);

public:
    /** This property stores this selection set's annotation.
    * Default value is "".
    */
    KFbxTypedProperty<fbxString>        SelectionSetAnnotation;

    /**
    * \name Utility functions
    */
    //@{

    /**  Get the faces selected for pObj. 
    *    \param pObj
    *    \param pPolygonIndexArray
    *    \remarks Put selected faces index in pPolygonIndexArray.
    */
    void GetFaceSelection( KFbxObject* pObj,KArrayTemplate<int>& pPolygonIndexArray ) ;

    /**  Get the edges selected for pObj. 
    *    \param pObj
    *    \param pEdgeIndexArray
    *    \remarks Put selected edges index in pEdgeIndexArray.
    */
    void GetEdgeSelection( KFbxObject* pObj,KArrayTemplate<int>& pEdgeIndexArray ) ; 

    /**  Get the vertices selected for pObj. 
    *    \param pObj
    *    \param pVertexIndexArray
    *    \remarks Put selected vertices index in pVertexIndexArray.
    */
    void GetVertexSelection( KFbxObject* pObj,KArrayTemplate<int>& pVertexIndexArray ) ; 

    /**  Get two types of member in selection set: SelectionNodes and Directly contained objects.
    *    \param pSelectionNodeList
    *    \param pDirectObjectList
    *    \remarks There might be two types members for a selection set. One is SelectionNode, the other is directly contained objects.
    *    They will be listed in pSelectionNodeList and pDirectObjectList separately.
    */
    void GetSelectionNodesAndDirectObjects(KArrayTemplate<KFbxSelectionNode*> &pSelectionNodeList, KArrayTemplate<KFbxObject*> &pDirectObjectList) ; 

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

protected:
    KFbxSelectionSet(KFbxSdkManager& pManager, char const* pName);
    KString	GetTypeName() const;    
    bool ConstructProperties(bool pForceSet); 

#endif // #ifndef DOXYGEN_SHOULD_SKIP_THIS
};

#include <fbxfilesdk/fbxfilesdk_nsend.h>

#endif /* FBXFILESDK_KFBXSELECTIONSET_H */
