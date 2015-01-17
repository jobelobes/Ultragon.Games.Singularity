/*!  \file kfbxcollection.h
 */

#ifndef FBXFILESDK_FBXCORE_FBXCOLLECTION_KFBXCOLLECTION_H
#define FBXFILESDK_FBXCORE_FBXCOLLECTION_KFBXCOLLECTION_H

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
// FBX includes

#include <fbxfilesdk/kfbxplugins/kfbxobject.h>
#include <fbxfilesdk/kfbxplugins/kfbxsdkmanager.h>

#include <fbxfilesdk/kfbxevents/kfbxevents.h>

#include <fbxfilesdk/components/kbaselib/klib/kerror.h>

#include <fbxfilesdk/fbxfilesdk_nsbegin.h>

    class KFbxCriteria;

    /** This class contains objects.
      * \nosubgrouping
      * This class also provides access to global settings and take information.
      *
      */
    class KFBX_DLL KFbxCollection : public KFbxObject
    {
        KFBXOBJECT_DECLARE(KFbxCollection, KFbxObject);

        /**
        * \name Collection member management
        */
        //@{
        public:
            //! Delete all contained objects.
            virtual void    Clear();
            /** Add a member.
			  * \param pMember Object to be added.
			  */
            virtual bool    AddMember(KFbxObject *pMember)      { return ConnectSrcObject(pMember); }
            /** Remove a member.
			  * \param pMember Object to be removed.
			  */
            virtual bool    RemoveMember(KFbxObject *pMember)   { return DisconnectSrcObject(pMember); }
            /** Find a member.
			  * \param pfbxType Member type.
			  * \param pName Member name.
			  */
            template <class T> inline T *       FindMember(T const *pfbxType, const char *pName) { return FindSrcObject(pfbxType, pName); }
            /** Return the number of objects in the collection.
			  * \return The number of objects in the collection.
			  */
            inline int                          GetMemberCount () const { return GetSrcObjectCount(); }
            /** Return the number of objects of class T in the collection.
			  * \param pFBX_TYPE Member type.
			  * \return The number of objects of class T in the collection.
			  */
            template < class T > inline int     GetMemberCount (T const *pFBX_TYPE) const { return GetSrcObjectCount(T::ClassId); }
            /** Return the number of objects satisfying given criteria in the collection.
			  * \param pCriteria The given criteria
			  * \return The number of objects satisfying given criteria in the collection.
			  */
            int                                 GetMemberCount( KFbxCriteria pCriteria ) const;

            /** Return the index'th member of the collection.
			  * \param pIndex The member index.
			  * \return The index'th member of the collection.
			  */
            inline KFbxObject*                  GetMember (int pIndex=0) const                  { return GetSrcObject(pIndex); }
            /** Return the index'th member of class T in the collection.
			  * \param pFBX_TYPE Member type information.
			  * \param pIndex The member index.
			  * \return The index'th member of the collection.
			  */
            template < class T > inline T*      GetMember (T const *pFBX_TYPE, int pIndex=0) const  { return (T *)GetSrcObject(T::ClassId,pIndex); }
            
			/** Return the index'th member of the collection which satisfies given criteria.
			  * \param pCriteria The given criteria.
			  * \param pIndex The member index.
			  * \return The index'th member of the collection.
			  */
            KFbxObject*                         GetMember (KFbxCriteria pCriteria, int pIndex=0) const;
            /** Is an object part of the collection.
			  * \param pMember Whether pMember is part of the collection.
			  * \return \c True if is, \c false otherwise.
              */
            virtual bool    IsMember(KFbxObject *pMember) const;
        //@}

        /**
        * \name Selection management
        */
        //@{
        public:
            /** Select/Deselect all contained objects.
			  * \param pSelection If \c true, all object are selected, otherwise all objects are unselected.
			  */
            virtual void    SetSelectedAll(bool pSelection);
            /** Select/Deselect objects.
			  * \param pObject 
			  * \param pSelection If \c true, pObject are selected, otherwise pObject are unselected.
			  */
            virtual void    SetSelected(KFbxObject* pObject,bool pSelection);
            /** Get Selected/Deselected.
			  * \param pObject Get whether pObject is selected or unselected.
			  */
            virtual bool    GetSelected(KFbxObject* pObject);
        //@}

    ///////////////////////////////////////////////////////////////////////////////
    //  WARNING!
    //  Anything beyond these lines may not be documented accurately and is
    //  subject to change without notice.
    ///////////////////////////////////////////////////////////////////////////////
    #ifndef DOXYGEN_SHOULD_SKIP_THIS

        // Constructor / Destructor
        protected:
            virtual KFbxObject* Clone(KFbxObject* pContainer, KFbxObject::ECloneType pCloneType) const;
            KFbxCollection(KFbxSdkManager& pManager, char const* pName);

    #endif // #ifndef DOXYGEN_SHOULD_SKIP_THIS

    };

#include <fbxfilesdk/fbxfilesdk_nsend.h>

#endif // FBXFILESDK_FBXCORE_FBXCOLLECTION_KFBXCOLLECTION_H

