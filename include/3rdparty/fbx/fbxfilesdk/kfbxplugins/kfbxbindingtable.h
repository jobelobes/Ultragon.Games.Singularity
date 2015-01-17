/*!  \file kfbxbindingtable.h
 */

#ifndef FBXFILESDK_KFBXPLUGINS_KFBXBINDINGTABLE_H 
#define FBXFILESDK_KFBXPLUGINS_KFBXBINDINGTABLE_H

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
// FBX SDK includes
#include <fbxfilesdk/kfbxplugins/kfbxbindingtablebase.h>

// FBX namespace
#include <fbxfilesdk/fbxfilesdk_nsbegin.h>

/** \brief A binding table represents a collection of bindings
  * from source types such as KFbxObjects, or KFbxLayerElements
  * to destinations which can be of similar types. See KFbxBindingTableEntry.
  * \nosubgrouping
  */
class KFBX_DLL KFbxBindingTable : public KFbxBindingTableBase
{
	KFBXOBJECT_DECLARE(KFbxBindingTable,KFbxBindingTableBase);

public:
	KFbxBindingTable& operator=(KFbxBindingTable const& pTable);

    /** This property stores the name of target.
      *
      * Default value is ""
      */
	KFbxTypedProperty<fbxString>			TargetName;

    /** This property stores the type of target.
      *
      * Default value is ""
      */
	KFbxTypedProperty<fbxString>			TargetType;

    /** Relative URL of file containing the shader implementation description. 
      * eg.: ./shader.mi
      * Default value is ""
      */
	KFbxTypedProperty<fbxString>			DescRelativeURL;

    /** Absolute URL of file containing the shader implementation description
      * eg.: file:///usr/tmp/shader.mi
      * Default value is ""
      */
	KFbxTypedProperty<fbxString>			DescAbsoluteURL;

    /** Identify the shader to use in previous description's URL
      * eg.: MyOwnShader
      * Default value is ""
      */
	KFbxTypedProperty<fbxString>			DescTAG;		

    /** Relative URL of file containing the shader implementation code
      * eg.: ./bin/shader.dll
      * Default value is ""
      */
	KFbxTypedProperty<fbxString>			CodeRelativeURL;

    /** Absolute URL of file containing the shader implementation code
      * eg.: file:///usr/tmp/bin/shader.dll
      * Default value is ""
      */
	KFbxTypedProperty<fbxString>			CodeAbsoluteURL;

    /** Identifyies the shader function entry to use in previous code's URL
      * eg.: MyOwnShaderFunc
      * Default value is ""
      */
	KFbxTypedProperty<fbxString>			CodeTAG;

	//////////////////////////////////////////////////////////////////////////
	// Static values
	//////////////////////////////////////////////////////////////////////////

	// property names
	static const char* sTargetName;
	static const char* sTargetType;
	static const char* sDescRelativeURL;
	static const char* sDescAbsoluteURL;
	static const char* sDescTAG;
	static const char* sCodeRelativeURL;
	static const char* sCodeAbsoluteURL;
	static const char* sCodeTAG;

	// property default values
	static const char* sDefaultTargetName;
	static const char* sDefaultTargetType;
	static const char* sDefaultDescRelativeURL;
	static const char* sDefaultDescAbsoluteURL;
	static const char* sDefaultDescTAG;
	static const char* sDefaultCodeRelativeURL;
	static const char* sDefaultCodeAbsoluteURL;
	static const char* sDefaultCodeTAG;

///////////////////////////////////////////////////////////////////////////////
//
//  WARNING!
//
//	Anything beyond these lines may not be documented accurately and is 
// 	subject to change without notice.
//
///////////////////////////////////////////////////////////////////////////////

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
	KFbxObject* Clone(KFbxObject* pContainer, KFbxObject::ECloneType pCloneType) const;
	KFbxBindingTable(KFbxSdkManager& pManager, char const* pName);

	virtual bool ConstructProperties(bool pForceSet);

#endif // #ifndef DOXYGEN_SHOULD_SKIP_THIS

};

#include <fbxfilesdk/fbxfilesdk_nsend.h>

#endif // FBXFILESDK_KFBXPLUGINS_KFBXBINDINGTABLE_H

