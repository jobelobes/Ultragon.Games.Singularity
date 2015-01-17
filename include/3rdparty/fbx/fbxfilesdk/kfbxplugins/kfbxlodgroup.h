/*!  \file kfbxlodgroup.h
 */

#ifndef FBXFILESDK_KFBXPLUGINS_KFBXLODGROUP_H
#define FBXFILESDK_KFBXPLUGINS_KFBXLODGROUP_H

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

#include <fbxfilesdk/kfbxplugins/kfbxnodeattribute.h>

#include <fbxfilesdk/fbxfilesdk_nsbegin.h>

class KFbxSdkManager;

/** \brief This node attribute contains the properties of a null node.
  * \nosubgrouping
  */
class KFBX_DLL KFbxLodGroup : public KFbxNodeAttribute
{
    KFBXOBJECT_DECLARE(KFbxLodGroup,KFbxNodeAttribute);

public:
    //! Return the type of node attribute which is EAttributeType::eLODGROUP.
    virtual EAttributeType GetAttributeType() const;

    /** \enum EDisplayLevel types.
      * - \e eUseLOD
      * - \e eShow
	  * - \e eHide
      */
	typedef enum {
		eUseLOD,
		eShow,
		eHide
	} EDisplayLevel;

    //////////////////////////////////////////////////////////////////////////
    //
    // Properties
    //
    //////////////////////////////////////////////////////////////////////////

    /** This property handles the use of the Min/Max distances.
      *
      * To access this property do: MinMaxDistance.Get().
      * To set this property do: MinMaxDistance.Set(bool).
      *
      * Default value is false.
      */
    KFbxTypedProperty<fbxBool1>       MinMaxDistance;

    /** This property handles the Min distance value.
      *
      * To access this property do: MinDistance.Get().
      * To set this property do: MinDistance.Set(double).
      *
      * Default value is -100
      */
    KFbxTypedProperty<fbxDouble1>     MinDistance;

    /** This property handles the Max distance value.
      *
      * To access this property do: MaxDistance.Get().
      * To set this property do: MaxDistance.Set(double).
      *
      * Default value is 100
      */
    KFbxTypedProperty<fbxDouble1>     MaxDistance;

    /** This property handles the WorldSpace flag.
      *
      * To access this property do: WorldSpace.Get().
      * To set this property do: WorldSpace.Set(bool).
      *
      * Default value is false
      */
	KFbxTypedProperty<fbxBool1>       WorldSpace;


    //////////////////////////////////////////////////////////////////////////
    //
    // Methods
    //
    //////////////////////////////////////////////////////////////////////////

	/** Get the size of the threshold list.
	  * \return The current size of the threshold list.
	  */
	int GetNumThresholds() const;

	/** Add a new threshold value to the current list. 
	  * \param pThreshValue Threshold distance from the previous entry in the threshold list
	  * \remark This list can only expand so the only way to shrink it, is
	  * to completely destroy this object.
	  * \remark This method does not check the received values and blindly add them
	  * to the list. Therefore duplicated values can exist in different positions in
	  * the list.
	  * \return true if successful and false if any error occurred.
	  */
	bool AddThreshold(fbxDistance pThreshValue);

	/** Set the threshold value for the specified object.
	  * \param pEl The index of the object we want to set the threshold.
	  * \param pThreshValue Threshold distance from the previous entry in the threshold list
	  * \return true if successful and false if the specified index is invalid.
	  */
	bool SetThreshold(int pEl, fbxDistance pThreshValue);

	/** Get the threshold value for the specified object.
      * \param pEl The index of the object we want to get the threshold.
	  * \param pThreshValue the current threshold value.
	  * \return true if successfull and false if the specified index is invalid.
	  * \remark in case of a failure, the pThreshValue is left unchanged.
	  */
	bool GetThreshold(int pEl, fbxDistance& pThreshValue);


	/** Get the size of the displayLevel list.
	  * \return The current size of the displayLevel list.
	  */
	int GetNumDisplayLevels() const;

	/** Add a new displayLevel value to the current list. 
	  * \param pValue Display level value
	  * \remark This list can only expand so the only way to shrink it, is
	  * to completely destroy this object.
	  * \remark This method does not check the received values and blindly add them
	  * to the list. Therefore duplicated values can exist in different positions in
	  * the list.
	  * \return true if successful and false if any error occurred.
	  */
	bool AddDisplayLevel(KFbxLodGroup::EDisplayLevel pValue);

	/** Set the display level value for the specified object.
	  * \param pEl The index of the object we want to set the display level.
	  * \param pValue New display level value
	  * \return true if successful and false if the specified index is invalid.
	  */
	bool SetDisplayLevel(int pEl, KFbxLodGroup::EDisplayLevel pValue);

	/** Get the display level value for the specified object.
      * \param pEl The index of the object we want to get the display level value.
	  * \param pValue the current display level value.
	  * \return true if successfull and false if the specified index is invalid.
	  * \remark in case of a failure, the pValue is left unchanged.
	  */
	bool GetDisplayLevel(int pEl, KFbxLodGroup::EDisplayLevel& pValue);
	
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
    // Clone
    virtual KFbxObject* Clone(KFbxObject* pContainer, KFbxObject::ECloneType pCloneType = eDEEP_CLONE) const;

protected:

    KFbxLodGroup(KFbxSdkManager& pManager, char const* pName);

    virtual bool ConstructProperties(bool pForceSet);

    //! Assignment operator.
    KFbxLodGroup& operator=(KFbxLodGroup const& pLodGroup);

private:
	int mNbThresholds;
	KFbxProperty mThresholds;	
	bool Threshold(int pEl, fbxDistance pThreshValue, bool pCreateNew);

	int mNbDisplayLevels;
	KFbxProperty mDisplayLevels;
	bool DisplayLevel(int pEl, KFbxLodGroup::EDisplayLevel pValue, bool pCreateNew);

public:
    virtual KString     GetTypeName() const;
    virtual KStringList GetTypeFlags() const;
#endif // #ifndef DOXYGEN_SHOULD_SKIP_THIS
};

typedef KFbxLodGroup* HKFbxLodGroup;
inline EFbxType FbxTypeOf( KFbxLodGroup::EDisplayLevel const &pItem )           { return eENUM; }

#include <fbxfilesdk/fbxfilesdk_nsend.h>

#endif // FBXFILESDK_KFBXPLUGINS_KFBXLODGROUP_H

