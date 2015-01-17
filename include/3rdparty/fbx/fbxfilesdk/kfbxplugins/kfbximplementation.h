/*!  \file kfbximplementation.h
 */

#ifndef FBXFILESDK_KFBXPLUGINS_KFBXIMPLEMENTATION_H 
#define FBXFILESDK_KFBXPLUGINS_KFBXIMPLEMENTATION_H

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
#include <fbxfilesdk/kfbxplugins/kfbxsdkmanager.h>
#include <fbxfilesdk/kfbxplugins/kfbxobject.h>

#include <fbxfilesdk/components/kbaselib/klib/kdynamicarray.h>
#include <fbxfilesdk/components/kbaselib/klib/kpair.h>

#include <fbxfilesdk/fbxfilesdk_nsbegin.h>

class KFbxBindingOperator;
class KFbxBindingTable;

/** \brief This object represents the shading node implementation.
  * It defines basic information about the shader and the binding table in shader.
  * \nosubgrouping
  */
class KFBX_DLL KFbxImplementation : public KFbxObject
{
	KFBXOBJECT_DECLARE(KFbxImplementation, KFbxObject);

public:
	// Predefined shader languages
	static const char* sHLSL;
	static const char* sGLSL;
	static const char* sCGFX;
	static const char* sMentalRaySL;

	// Predefined rendering apis
	static const char* sDirectX;
	static const char* sOpenGL;
	static const char* sMentalRay;
    static const char* sPreview;

    /**
      * \name Shader description
      */
    //@{

	//! Shader Language
	KFbxTypedProperty<fbxString>			Language;

	//! Shader Language version
	KFbxTypedProperty<fbxString>			LanguageVersion;

	//! Render API
	KFbxTypedProperty<fbxString>			RenderAPI;

	//! Render API version
	KFbxTypedProperty<fbxString>			RenderAPIVersion;
    //@}


    /**
      * \name Binding description
      */
    //@{

	//! Root
	KFbxTypedProperty<fbxString>			RootBindingName;

	//! Constants
	KFbxProperty GetConstants() const;

	/** Add a new binding table to the table list.
	  * \param pTargetName The target name for the binding table
	  * \param pTargetType The target type for the binding table
	  * \return the new binding table
	  */ 
	KFbxBindingTable* AddNewTable( char const* pTargetName, char const* pTargetType );

    /** Retrieves a handle on the root binding table.
    * \return A const pointer to the root table or NULL if it does not exist.
    */ 
    KFbxBindingTable const* GetRootTable() const;
    KFbxBindingTable* GetRootTable();
    
    /** Gets the number of binding tables.
	  * \return the number of binding tables
	  */ 
	int GetTableCount() const;

	/** Retrieves a handle on the (pIndex)th binding table.
	  * \param pIndex The index of the table to retrieve. Valid values are [ 0, GetTableCount() )
	  * \return A const pointer to the pIndex-th table or NULL if pIndex is out of range
	  */ 
	KFbxBindingTable const* GetTable( int pIndex ) const;
    /** Retrieves a handle on the (pIndex)th binding table.
	  * \param pIndex The index of the table to retrieve. Valid values are [ 0, GetTableCount() )
	  * \return A const pointer to the pIndex-th table or NULL if pIndex is out of range
	  */ 
	KFbxBindingTable* GetTable( int pIndex );

	/** Returns the binding table that has the given name.
	  * \param pName The name of the table to look for
	  * \return A const pointer to the binding table with the given name, or NULL if there is no such binding table
	  */ 
	KFbxBindingTable const* GetTableByTargetName( char const* pName ) const;
	/** Returns the binding table that has the given name.
	  * \param pName The name of the table to look for
	  * \return A const pointer to the binding table with the given name, or NULL if there is no such binding table
	  */ 
	KFbxBindingTable* GetTableByTargetName( char const* pName );

	/** Returns the binding table for a given target.
	  * \param pTargetName The name of the target to look for
	  * \return A const pointer to the binding table with the given target, or SIZE_MAX if there is no such binding table
	  */ 
	KFbxBindingTable const* GetTableByTargetType( char const* pTargetName ) const;
	/** Returns the binding table for a given target.
	  * \param pTargetName The name of the target to look for
	  * \return A const pointer to the binding table with the given target, or SIZE_MAX if there is no such binding table
	  */ 
	KFbxBindingTable* GetTableByTargetType( char const* pTargetName );

	
	/** Add a new binding table to the table list.
	  * \param pTargetName The target name for the binding table
	  * \param pFunctionName The target type for the binding table
	  * \return the new operator
	  */ 
	KFbxBindingOperator* AddNewBindingOperator( char const* pTargetName, char const* pFunctionName );

	/** Gets the number of binding table operators.
	  * \return the number of binding table operators.
	  */ 
	int GetBindingOperatorCount() const;

	/** Returns the binding table that has the given name.
	  * \param pTargetName The name of the table to look for
	  * \return A const pointer to the binding table with the given name, or NULL if there is no such binding table
	  */ 
	KFbxBindingOperator const* GetOperatorByTargetName( char const* pTargetName ) const;
    //@}


    /**
      * \name Static values
      */
    //@{

	// property names
	static const char* sLanguage;
	static const char* sLanguageVersion;
	static const char* sRenderAPI;					
	static const char* sRenderAPIVersion;
	static const char* sRootBindingName;
	static const char* sConstants;

	// property default values
	static const char* sDefaultType;
	static const char* sDefaultLanguage;
	static const char* sDefaultLanguageVersion;
	static const char* sDefaultRenderAPI;
	static const char* sDefaultRenderAPIVersion;
	static const char* sDefaultRootBindingName;
    //@}

///////////////////////////////////////////////////////////////////////////////
//
//  WARNING!
//
//	Anything beyond these lines may not be documented accurately and is 
// 	subject to change without notice.
//
///////////////////////////////////////////////////////////////////////////////
#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:

	virtual KFbxObject* Clone(KFbxObject* pContainer, KFbxObject::ECloneType pCloneType) const;

protected:

	// Constructor / Destructor
	KFbxImplementation(KFbxSdkManager& pManager, char const* pName);

	virtual bool ConstructProperties(bool pForceSet);

	virtual KFbxImplementation& operator= (KFbxImplementation const& pImplementation);

#endif // #ifndef DOXYGEN_SHOULD_SKIP_THIS
};


#include <fbxfilesdk/fbxfilesdk_nsend.h>

#endif // FBXFILESDK_KFBXPLUGINS_KFBXIMPLEMENTATION_H

