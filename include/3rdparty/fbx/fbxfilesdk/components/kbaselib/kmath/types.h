/*!  \file
 */

#ifndef FBXFILESDK_COMPONENTS_KBASELIB_KMATH_TYPES_H
#define FBXFILESDK_COMPONENTS_KBASELIB_KMATH_TYPES_H

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

#include <fbxfilesdk/components/kbaselib/karch/arch.h>

#include <float.h>

#define K_FLOAT_MIN				FLT_MIN					// minimum positive value
#define K_FLOAT_MAX				FLT_MAX					// maximum positive value
#define K_FLOAT_EPSILON			FLT_EPSILON
#define K_FLOAT_EXP_MIN			FLT_MIN_EXP
#define K_FLOAT_EXP_MAX			FLT_MAX_EXP

#define K_DOUBLE_MIN			DBL_MIN					// minimum positive value
#define K_DOUBLE_MAX			DBL_MAX					// maximum positive value
#define K_DOUBLE_EPSILON		DBL_EPSILON
#define K_DOUBLE_EXP_MIN		DBL_MIN_EXP
#define K_DOUBLE_EXP_MAX		DBL_MAX_EXP

typedef float					kReal;
#define K_REAL(x)				x##F
#define K_REAL_MIN				K_FLOAT_MIN
#define K_REAL_MAX				K_FLOAT_MAX
#define K_REAL_EPSILON			K_FLOAT_EPSILON
#define K_REAL_EXP_MIN			K_FLOAT_MIN_EXP
#define K_REAL_EXP_MAX			K_FLOAT_MAX_EXP
#define K_SIZEOF_REAL			K_SIZEOF_FLOAT

#define K_HUGE					HUGE_VAL

K_INLINE double _kDoubleInf()
{
	const kUInt64 val = K_ULONGLONG(0x7ff0000000000000);

	return *(const double *) &val;
}

#define K_INF					_kDoubleInf()

#endif // FBXFILESDK_COMPONENTS_KBASELIB_KMATH_TYPES_H

