/*!  \file fbxsdk.h
 */

#ifndef FBXSDK_H
#define FBXSDK_H

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

/**
  * \mainpage FBX SDK Reference
  * <p>
  * \section welcome Welcome to the FBX SDK Reference
  * The FBX SDK Reference contains reference information on every header file, 
  * namespace, class, method, enum, typedef, variable, and other C++ elements 
  * that comprise the FBX software development kit (SDK).
  * <p>
  * The FBX SDK Reference is organized into the following sections:
  * <ul><li>Class List: an alphabetical list of FBX SDK classes
  *     <li>Class Hierarchy: a textual representation of the FBX SDK class structure
  *     <li>Graphical Class Hierarchy: a graphical representation of the FBX SDK class structure
  *     <li>File List: an alphabetical list of all documented header files</ul>
  * <p>
  * \section otherdocumentation Other Documentation
  * Apart from this reference guide, an FBX SDK Programming Guide and many FBX 
  * SDK examples are also provided.
  * <p>
  * \section aboutFBXSDK About the FBX SDK
  * The FBX SDK is a C++ software development kit (SDK) that lets you import 
  * and export 3D scenes using the Autodesk FBX file format. The FBX SDK 
  * reads FBX files created with FiLMBOX version 2.5 and later and writes FBX 
  * files compatible with MotionBuilder version 6.0 and up. 
  */

// Compatibility with the old #defines, which are being deprecated...
#ifdef K_FBXSDK
#   undef KFBX_SDK
#   define KFBX_SDK
#endif

#ifdef K_PLUGIN
#   undef KFBX_PLUGIN
#   define KFBX_PLUGIN
#endif

#ifdef K_NODLL
#   undef KFBX_NODLL
#   define KFBX_NODLL
#endif

#ifndef K_FBXSDK_INTERNALPLUGINS
    #ifndef KFBX_PLUGIN
        #define KFBX_PLUGIN
    #endif

    #ifndef KFBX_SDK
        #define KFBX_SDK
    #endif

	#ifdef MB_FBXSDK
		#undef KFBX_DLLIMPORT
		#undef KFBX_DLLEXPORT
        
		// import and export definitions
		#if (defined(_MSC_VER) || (defined(__GNUC__) && defined(_WIN32))) && !defined(MB_FBXSDK)
			#define KFBX_DLLIMPORT __declspec()
			#define KFBX_DLLEXPORT __declspec()
		#else 
			#define KFBX_DLLIMPORT
			#define KFBX_DLLEXPORT
		#endif
        
		#define _K_KAYDARADEF_H
		#include <fbxfilesdk/components/kbaselib/karch/arch.h>
        
		#define KFBX_DLL
	#else
		#ifndef K_FBXSDK_INTERFACE
			#define K_FBXSDK_INTERFACE
		#endif
	#endif /* MB_FBXSDK */
#endif

#ifndef KFBX_DLL 
    #define KFBX_DLL KFBX_DLLIMPORT
#endif

#include <fbxfilesdk/fbxfilesdk_def.h>
#include <fbxfilesdk/components/kbaselib/kaydara.h>

// io
#include <fbxfilesdk/kfbxio/kfbxexporter.h>
#include <fbxfilesdk/kfbxio/kfbxexternaldocreflistener.h>
#include <fbxfilesdk/kfbxio/kfbxfiletokenfbx.h>
#include <fbxfilesdk/kfbxio/kfbxgobo.h>
#include <fbxfilesdk/kfbxio/kfbximporter.h>
#include <fbxfilesdk/kfbxio/kfbxio.h>
#include <fbxfilesdk/kfbxio/kfbxiosettings.h>
#include <fbxfilesdk/kfbxio/kfbxstatisticsfbx.h>
#include <fbxfilesdk/kfbxio/kfbxstreamoptions.h>
#include <fbxfilesdk/kfbxio/kfbxstreamoptions3ds.h>
#include <fbxfilesdk/kfbxio/kfbxstreamoptionscollada.h>
#include <fbxfilesdk/kfbxio/kfbxstreamoptionsdxf.h>
#include <fbxfilesdk/kfbxio/kfbxstreamoptionsfbx.h>
#include <fbxfilesdk/kfbxio/kfbxstreamoptionsobj.h>
#include <fbxfilesdk/kfbxio/kfbxstreamoptionsmotion.h>

// math
#include <fbxfilesdk/kfbxmath/kfbxmatrix.h>
#include <fbxfilesdk/kfbxmath/kfbxquaternion.h>
#include <fbxfilesdk/kfbxmath/kfbxvector2.h>
#include <fbxfilesdk/kfbxmath/kfbxvector4.h>
#include <fbxfilesdk/kfbxmath/kfbxxmatrix.h>

// plugins
#include <fbxfilesdk/kfbxplugins/kfbxbindingtable.h>
#include <fbxfilesdk/kfbxplugins/kfbxbindingtableentry.h>
#include <fbxfilesdk/kfbxplugins/kfbxbindingoperator.h>
#include <fbxfilesdk/kfbxplugins/kfbxcache.h>
#include <fbxfilesdk/kfbxplugins/kfbxcamera.h>
#include <fbxfilesdk/kfbxplugins/kfbxcamerastereo.h>
#include <fbxfilesdk/kfbxplugins/kfbxcameraswitcher.h>
#include <fbxfilesdk/kfbxplugins/kfbxclonemanager.h>
#include <fbxfilesdk/kfbxplugins/kfbxcluster.h>
#include <fbxfilesdk/kfbxplugins/kfbxcolor.h>
#include <fbxfilesdk/kfbxplugins/kfbxconstraint.h>
#include <fbxfilesdk/kfbxplugins/kfbxconstraintaim.h>
#include <fbxfilesdk/kfbxplugins/kfbxconstraintcustom.h>
#include <fbxfilesdk/kfbxplugins/kfbxconstraintparent.h>
#include <fbxfilesdk/kfbxplugins/kfbxconstraintposition.h>
#include <fbxfilesdk/kfbxplugins/kfbxconstraintrotation.h>
#include <fbxfilesdk/kfbxplugins/kfbxconstraintscale.h>
#include <fbxfilesdk/kfbxplugins/kfbxconstraintsinglechainik.h>
#include <fbxfilesdk/kfbxplugins/kfbxcontainer.h>
#include <fbxfilesdk/kfbxplugins/kfbxcontainertemplate.h>
#include <fbxfilesdk/kfbxplugins/kfbxdeformer.h>
#include <fbxfilesdk/kfbxplugins/kfbxexposurecontrol.h>
#include <fbxfilesdk/kfbxplugins/kfbxgenericnode.h>
#include <fbxfilesdk/kfbxplugins/kfbxgeometry.h>
#include <fbxfilesdk/kfbxplugins/kfbxgeometrybase.h>
#include <fbxfilesdk/kfbxplugins/kfbxgeometryconverter.h>
#include <fbxfilesdk/kfbxplugins/kfbxgeometryweightedmap.h>
#include <fbxfilesdk/kfbxplugins/kfbxglobalcamerasettings.h>
#include <fbxfilesdk/kfbxplugins/kfbxgloballightsettings.h>
#include <fbxfilesdk/kfbxplugins/kfbxglobaltimesettings.h>
#include <fbxfilesdk/kfbxplugins/kfbximplementation.h>
#include <fbxfilesdk/kfbxplugins/kfbximplementationfilter.h>
#include <fbxfilesdk/kfbxplugins/kfbximplementationutils.h>
#include <fbxfilesdk/kfbxplugins/kfbxconstantentryview.h>
#include <fbxfilesdk/kfbxplugins/kfbxoperatorentryview.h>
#include <fbxfilesdk/kfbxplugins/kfbxentryview.h>
#include <fbxfilesdk/kfbxplugins/kfbxpropertyentryview.h>
#include <fbxfilesdk/kfbxplugins/kfbxiopluginregistry.h>
#include <fbxfilesdk/kfbxplugins/kfbxkfcurvefilters.h>
#include <fbxfilesdk/kfbxplugins/kfbxlayeredtexture.h>
#include <fbxfilesdk/kfbxplugins/kfbxlibrary.h>
#include <fbxfilesdk/kfbxplugins/kfbxlight.h>
#include <fbxfilesdk/kfbxplugins/kfbxlimitsutilities.h>
#include <fbxfilesdk/kfbxplugins/kfbxlodgroup.h>
#include <fbxfilesdk/kfbxplugins/kfbxmanipulators.h>
#include <fbxfilesdk/kfbxplugins/kfbxmarker.h>
#include <fbxfilesdk/kfbxplugins/kfbxmaterialconverter.h>
#include <fbxfilesdk/kfbxplugins/kfbxmemoryallocator.h>
#include <fbxfilesdk/kfbxplugins/kfbxmesh.h>
#include <fbxfilesdk/kfbxplugins/kfbxsubdiv.h>
#include <fbxfilesdk/kfbxplugins/kfbxnode.h>
#include <fbxfilesdk/kfbxplugins/kfbxnodeattribute.h>
#include <fbxfilesdk/kfbxplugins/kfbxnodeiterator.h>
#include <fbxfilesdk/kfbxplugins/kfbxnull.h>
#include <fbxfilesdk/kfbxplugins/kfbxnurb.h>
#include <fbxfilesdk/kfbxplugins/kfbxnurbscurve.h>
#include <fbxfilesdk/kfbxplugins/kfbxnurbssurface.h>
#include <fbxfilesdk/kfbxplugins/kfbxobjectmetadata.h>
#include <fbxfilesdk/kfbxplugins/kfbxopticalreference.h>
#include <fbxfilesdk/kfbxplugins/kfbxpatch.h>
#include <fbxfilesdk/kfbxplugins/kfbxperipheral.h>
#include <fbxfilesdk/kfbxplugins/kfbxpose.h>
#include <fbxfilesdk/kfbxplugins/kfbxproceduralgeometry.h>
#include <fbxfilesdk/kfbxplugins/kfbxproperty.h>
#include <fbxfilesdk/kfbxplugins/kfbxrenamingstrategyfbx5.h>
#include <fbxfilesdk/kfbxplugins/kfbxrenamingstrategyfbx6.h>
#include <fbxfilesdk/kfbxplugins/kfbxrootnodeutility.h>
#include <fbxfilesdk/kfbxplugins/kfbxscene.h>
#include <fbxfilesdk/kfbxplugins/kfbxsdkmanager.h>
#include <fbxfilesdk/kfbxplugins/kfbxshadingnode.h>
#include <fbxfilesdk/kfbxplugins/kfbxshape.h>
#include <fbxfilesdk/kfbxplugins/kfbxskeleton.h>
#include <fbxfilesdk/kfbxplugins/kfbxskin.h>
#include <fbxfilesdk/kfbxplugins/kfbxstatistics.h>
#include <fbxfilesdk/kfbxplugins/kfbxsubdeformer.h>
#include <fbxfilesdk/kfbxplugins/kfbxsurfacelambert.h>
#include <fbxfilesdk/kfbxplugins/kfbxsurfacematerial.h>
#include <fbxfilesdk/kfbxplugins/kfbxsurfacephong.h>
#include <fbxfilesdk/kfbxplugins/kfbxtakeinfo.h>
#include <fbxfilesdk/kfbxplugins/kfbxtakenode.h>
#include <fbxfilesdk/kfbxplugins/kfbxtexture.h>
#include <fbxfilesdk/kfbxplugins/kfbxthumbnail.h>
#include <fbxfilesdk/kfbxplugins/kfbxtrimnurbssurface.h>
#include <fbxfilesdk/kfbxplugins/kfbxusernotification.h>
#include <fbxfilesdk/kfbxplugins/kfbxuserproperty.h>
#include <fbxfilesdk/kfbxplugins/kfbxutilities.h>
#include <fbxfilesdk/kfbxplugins/kfbxvertexcachedeformer.h>
#include <fbxfilesdk/kfbxplugins/kfbxvideo.h>
#include <fbxfilesdk/kfbxplugins/kfbxweightedmapping.h>

// core
#include <fbxfilesdk/fbxcore/kfbxquery.h>
#include <fbxfilesdk/fbxcore/fbxcollection/kfbxdocumentinfo.h>
#include <fbxfilesdk/fbxcore/fbxcollection/kfbxpropertymap.h>
#include <fbxfilesdk/kfbxplugins/kfbxselectionset.h>
#include <fbxfilesdk/kfbxplugins/kfbxselectionnode.h>
#include <fbxfilesdk/kfbxplugins/kfbxdisplaylayer.h>
#include <fbxfilesdk/fbxcore/fbxxref/fbxxref.h>

// character
#include <fbxfilesdk/kfbxcharacter/kfbxcharacter.h>
#include <fbxfilesdk/kfbxcharacter/kfbxcharacterpose.h>
#include <fbxfilesdk/kfbxcharacter/kfbxcontrolset.h>

// components
#include <fbxfilesdk/components/kbaselib/kfbx/kfbx.h>

#include <fbxfilesdk/components/kbaselib/klib/karrayul.h>
#include <fbxfilesdk/components/kbaselib/klib/kdynamicarray.h>
#include <fbxfilesdk/components/kbaselib/klib/kerror.h>
#include <fbxfilesdk/components/kbaselib/klib/kmap.h>
#include <fbxfilesdk/components/kbaselib/klib/kmemory.h>
#include <fbxfilesdk/components/kbaselib/klib/kscopedptr.h>
#include <fbxfilesdk/components/kbaselib/klib/kset.h>
#include <fbxfilesdk/components/kbaselib/klib/kstring.h>
#include <fbxfilesdk/components/kbaselib/klib/ksystemtime.h>
#include <fbxfilesdk/components/kbaselib/klib/ktime.h>

#include <fbxfilesdk/components/kfcurve/kfcurve.h>
#include <fbxfilesdk/components/kfcurve/kfcurveglobal.h>
#include <fbxfilesdk/components/kfcurve/kfcurvenode.h>
#include <fbxfilesdk/components/kfcurve/kfcurveutils.h>
// Events
#include <fbxfilesdk/kfbxevents/includes.h>

// Mp
#include <fbxfilesdk/kfbxmp/kfbxmutex.h>

// Modules
#include <fbxfilesdk/kfbxmodules/includes.h>

// Processors
#include <fbxfilesdk/fbxprocessors/fbxprocessors.h>

#ifndef MB_FBXSDK
	using namespace FBXFILESDK_NAMESPACE;
#else
	#ifndef K_FBXSDK_INTERNALPLUGINS
    	#undef KFBX_DLLIMPORT
	    #undef KFBX_DLLEXPORT
    	#undef _K_KAYDARADEF_H
	    #undef K_FORWARD
	    #undef K_FORWARD_HI
	    #undef KFBX_DLL
	    #undef KBASELIB_DLL
	    #undef KFCURVE_DLL
	    #undef K_PLUGIN
	    #undef K_FBXSDK
	    #undef K_FBXSDK_INTERFACE
	    #undef K_DLLIMPORT
	    #undef K_DLLEXPORT
	    #undef IObject
	    #undef __func__
        
	    #undef KARCH_CPU_IA32
        
	    #undef UTF8_to_ANSI
	    #undef UTF8_to_WIDECHAR
	    #undef WIDECHAR_to_UTF8
	    #undef WIDECHAR_to_ANSI
	    #undef _WIN32_WINNT
        
	    #undef K_KERNEL_VERSION
	    #undef K_ASSERT
	    #undef K_ASSERT_LEVEL
	    #undef K_ASSERT_MSG_NOW
	    #undef K_ASSERT_MSG
	    #undef K_ASSERT_MSG_LEVEL
	    #undef K_ASSERT_MSG_NOT_IMPLEMENTED
	    #undef K_STATIC_ASSERT

	    #undef Pure
	    #undef IObjectID
	    #undef IObjectDerived
	    #undef K_INTERFACE
	    #undef KPLUG_FORWARD
	    #undef KPLUG_DECLARE_OBJECT
	    #undef KPLUG_DECLARE_GROUP_OBJECT
	    #undef KPLUG_IMPLEMENT_BASE
	    #undef KPLUG_IMPLEMENT_OBJECT
	    #undef KPLUG_DEFINE_CREATE
	    #undef KPLUG_DEFINE_CREATE_1
	    #undef KPLUG_DEFINE_CREATE_2

	    #undef KO_FORWARD
	    #undef K_SUBDATATYPE_DECLARE_WITH_TYPE
	    #undef K_SUBDATATYPE_DECLARE_WITH_SUBNAMES

	    #undef KARRAYUL_BLOCKSIZE

	    #undef PROPERTY_STAT
	    #undef PROPERTY_INIT
	    #undef PROPERTY_ENUM
	    #undef PROPERTY_STRINGLIST
	    #undef PROPERTY_STRINGLIST_INIT
	    #undef PROPERTY_EVENT_INIT
	    #undef PROPERTY_LIST_BASE
	    #undef PROPERTY_OBJECT_LIST
	    #undef PROPERTY_OBJECT_LIST2
	    #undef PROPERTY_OBJECT_LIST_BASE
	    #undef PROPERTY_OBJECT_LIST_INIT2
	    #undef PROPERTY_OBJECT_LIST_INIT_EXT_
	    #undef PROPERTY_OBJECT_LIST_INIT_NAME_EXT_
	    #undef PROPERTY_OBJECT_LIST_INIT
	    #undef IF_W_RDWD

	    #undef KFCURVE_INLINE
	    #undef FBX_CURRENT_VERSION_NUMBER
	    #undef KITEM_PER_BLOCK

	    #ifndef _INC_CRTDBG
		    #undef _malloc_dbg
		    #undef _realloc_dbg
		    #undef _free_dbg
	    #endif
        
	    #undef stricmp
	    #undef strnicmp
	    #undef itoa
	    #undef getcwd
	    #undef getpid
	    #undef tempnam
	    #undef fileno
	    #undef fdopen
	#endif
	#include <fbxfilesdk/components/kbaselib/kaydaradef.h>
#endif

/*
    These files, while not directly included here, are still required to use the
    FBX SDK, and they are referenced here so that our packaging system pulls them
    in into the final distribution directory.

    #include <fbxfilesdk/fbxfilesdk_nsuse.h>
*/

#endif // FBXSDK_H

