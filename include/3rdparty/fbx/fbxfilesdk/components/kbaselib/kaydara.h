#ifndef FBXFILESDK_COMPONENTS_KBASELIB_KAYDARA_H
#define FBXFILESDK_COMPONENTS_KBASELIB_KAYDARA_H

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

/*
	Version of the Kernel that historicaly is in sync with the version of MotionBuilder
*/

#define KFBX_KERNEL_VERSION	7000

/* Product definitions using the Kernel */

// Alias MotionBuilder Standard

#if defined(K_STD)
	#define K_NO_NLE
	#define	K_NO_ASSETMNG
	#define K_NO_DECK
	#define	K_NO_IMAGEOPERATOR
#endif

// FB_KERNEL

#if defined(FB_KERNEL)
	#define	K_NO_ACTOR
	#define	K_NO_ASSETMNG
	#define	K_NO_AUDIO
	#define	K_NO_CHARACTER
	#define	K_NO_DECK
	#define	K_NO_FOLDER
	#define	K_NO_IMAGEOPERATOR
	#define	K_NO_MANIPULATOR
	#define	K_NO_NOTE
	#define	K_NO_OPTICAL
	#define	K_NO_POSE
	#define	K_NO_RENDERER
	#define	K_NO_STORY
	#define	K_NO_UI
	#define	K_NO_UNDO
#if defined(K_QUICKTIME_PLUGIN)
#undef K_NO_ACTOR
#undef K_NO_CHARACTER
#endif
#endif

// Make sure the FBX SDK namespace is defined.
#include <fbxfilesdk/fbxfilesdk_nsbegin.h>
#include <fbxfilesdk/fbxfilesdk_nsend.h>

#ifdef KFBX_BUILD_SDK
// Automatically grab memory allocations when we're building the FBX SDK.
#   include <fbxfilesdk/fbxfilesdk_memory.h>        
#else
// Otherwise just make sure that malloc/free are defined.
#   ifdef KARCH_DEV_MSC
#       include <malloc.h>
#   else
#       include <stdlib.h>
#   endif
#endif	

#include <fbxfilesdk/components/kbaselib/karch/arch.h>
#include <fbxfilesdk/components/kbaselib/karch/types.h>

#ifndef NULL
	#if defined __GNUG__ && (__GNUC__ > 2 || (__GNUC__ == 2 && __GNUC_MINOR__ >= 8))
		#define NULL (__null)
	#else	
    	#ifdef __cplusplus
    		#define NULL    0
    	#else
    		#define NULL    ((void *)0)
    	#endif
    #endif
#endif

#if !defined( _MAX_PATH ) && defined( KARCH_ENV_UNIX )
	#define _MAX_PATH 1024
#endif

#define KFBX_MAX_TEXT_LENGTH 1020 // Max text length, to be used when declaring fixed width char ptrs directly

#define KFBX_FORWARD( ClassName ) class ClassName; typedef ClassName *H##ClassName;
#define KFBX_FORWARD_HI( ClassName ) class ClassName; typedef ClassName *H##ClassName; typedef H##ClassName HI##ClassName;

#define KFBX_SAFE_DELETE_PTR( p )			if( p ){ delete (p); (p) = NULL; }
#define KFBX_SAFE_DELETE_ARRAY_PTR( a )	    if( a ){ delete [] (a); (a) = NULL; }

#define KFBX_SAFE_DESTROY_OBJECT( p )		{ if( p ){ (p)->Destroy(); (p) = NULL; } }


#ifdef KARCH_ENV_WIN
	#define snprintf _snprintf // for stdio.h platform compatibility
	#ifndef WIN32_LEAN_AND_MEAN
		#define WIN32_LEAN_AND_MEAN  // Defined to speed up compilation
	#endif
#else
	#include <ctype.h>
	#include <stdio.h>
	#include <string.h>
#endif

#if defined(KARCH_ENV_MACOSX_CFM)
	#define strncmpi strnicmp
#elif !defined(KARCH_DEV_MSC)

	#ifndef strcmpi
		#define strcmpi strcasecmp
	#endif
	#ifndef stricmp
		#define stricmp strcasecmp
	#endif
	#ifndef strncmpi
		#define strncmpi strncasecmp
	#endif
	#ifndef strnicmp
		#define strnicmp strncasecmp
	#endif
#endif

#if defined(KARCH_ENV_LINUX)
	#include <malloc.h>
	#define _msize     	((size_t (*)(void*))malloc_usable_size)
#endif

#if defined(KARCH_ENV_IRIX)
	#include <malloc.h>
	#define _msize		((size_t (*)(void*))mallocblksize)
#endif

#if defined(KARCH_ENV_MACOSX)
	#include <stdlib.h>
	#include <malloc/malloc.h>
	#define _msize		((size_t (*)(void*))malloc_size)
#endif

// Compiler specific
#if defined(KARCH_DEV_MSC) && !defined(KARCH_DEV_INTEL)
	#pragma warning(disable: 4097)	// warning C4097: typedef-name 'ClassType' used as synonym for class-name 'KTextTag'
	#pragma warning(disable: 4100)	// warning C4100: '?' : unreferenced formal parameter
	#pragma warning(disable: 4201)	//nonstandard extension used : nameless struct/union (Level 4) portability  
	#pragma warning(disable: 4244)	//conversion from 'const double' to 'float', possible loss of data 
	#pragma warning(disable: 4514)	//unreferenced inline function has been removed (Level 4) optimizer  
	#pragma warning(disable: 4660)	//template-class specialization 'identifier' is already instantiated (Level 2) compiler
	#pragma warning(disable: 4710)	//function (X) not expanded  ??? may be good to know
	#pragma warning(disable: 4711)	//function (X) selected for automatic inline expansion
	#pragma warning(disable: 4725)	// instruction may be inaccurate on some Pentiums

	#pragma warning( disable : 4018 ) // signed/unsigned mismatch 
	#pragma warning( disable : 4244 ) //// 'conversion' conversion from 'type1' to 'type2', possible loss of data


	#pragma warning(error : 4002)	// too many actual parameters for macro 'identifier'
	#pragma warning(error : 4130)	// warning C4130: '==' : logical operation on address of string constant
	#pragma warning(error : 4238)	// warning C4238: nonstandard extension used : class rvalue used as lvalue
	#pragma warning(error : 4311)	// warning C4311: 'type cast' : pointer truncation from 'x *' to 'y'
	#pragma warning(error : 4551)	// warning C4551: function call missing argument list
	#pragma warning(error : 4553)	// warning C4553: '==' : operator has no effect; did you intend '='?

	// make sure that all declared variables are initialized
	#pragma warning(error : 4700)	// warning C4700: (level 1 and 4) local variable 'name' used without having been initialized
	#pragma warning(error : 4701)	// warning C4700: (level 4) local variable 'name' may be used without having been initialized

// temporary
	#pragma warning( disable : 4251 )// needs to have dll-interface to be used by clients of class

    #if (_MSC_VER <= 1200) // VC6
	    #pragma warning( disable : 4786 )// identifier was truncated to '255' characters in the debug information
    #endif
#endif

#if defined(KARCH_DEV_MIPSPRO) || defined(KARCH_DEV_MIPS)
	#pragma set woff 1355 // The extra semicolon (";") is ignored.
	#pragma set woff 1682 //The overloaded virtual function "" is only partially overridden in class
	#pragma set woff 1681 //virtual function mix
	#pragma set woff 1183 //signed/unsigned mismatch
	
#endif

#define K_LOCAL_CLASS

// Deprecated macro, to remind people to stop using certain functions

#if defined(KARCH_DEV_GNUC) || defined(KARCH_DEV_GNUC_MACOSX) || defined(KARCH_DEV_GNUC_EE) // GNU compiler
    #define K_DEPRECATED __attribute__((deprecated))

#elif defined(KARCH_DEV_INTEL) // Intel compiler
    #if (__INTEL_COMPILER >= 810) // Maybe we could use an earlier version, we should check this some day
        #define K_DEPRECATED __declspec(deprecated)
    #else
        #define K_DEPRECATED
    #endif

#elif defined(KARCH_DEV_MSC) // Microsoft compiler
    #if (_MSC_VER >= 1300) // 7.1
        #define K_DEPRECATED __declspec(deprecated)
    #else
        #define K_DEPRECATED
    #endif

#elif defined(KARCH_DEV_MIPSPRO) || defined(KARCH_DEV_MIPS) // SGI compiler
    #define K_DEPRECATED

#elif defined(KARCH_DEV_MACOSX) // Metrowerks compiler
    #define K_DEPRECATED

#else // Unknown compiler
    #define K_DEPRECATED

#endif


#endif // FBXFILESDK_COMPONENTS_KBASELIB_KAYDARA_H

