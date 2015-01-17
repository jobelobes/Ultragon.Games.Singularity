#ifndef FBXFILESDK_COMPONENTS_KBASELIB_KMATH_KMATH_H
#define FBXFILESDK_COMPONENTS_KBASELIB_KMATH_KMATH_H

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

#include <fbxfilesdk/components/kbaselib/kbaselib_h.h>

#include <string.h>	// memcmp
#include <fbxfilesdk/components/kbaselib/kmath/maths.h>

#define OGLFLOAT 1
typedef float			kOGLFloat;
typedef kOGLFloat		kOGLVector2[2];   
typedef kOGLFloat		kOGLVector3[3];   
typedef kOGLFloat		kOGLVector4[4];   

#define KM_TOLERANCE	(1.0e-6)
#define KM_EPSILON		(1.0e-10)

#ifdef __cplusplus
#define K_DEFAULT(arg, val) arg = val
#else
#define K_DEFAULT(arg, val) arg
#endif

#ifndef KM_ASSERT
//#define KM_ASSERT(cond, msg)	assert(cond)
#define KM_ASSERT(cond, msg)	// K_ASSERT_MSG(cond,msg)
#endif

// to remove potential side effects for in-place calls
#ifndef KM_CONST
#define KM_CONST const
#endif


#include <fbxfilesdk/fbxfilesdk_nsbegin.h>

    /*
    *	LEGEND
    *		- N stands for scalar
    *		- V stands for vector
    *		- Q stands for quaternion
    *		- M stands for matrix
    *		- LU stands for LU matrix
    *		- A stands for affine matrix (TRS)
    *		- T stands for translation matrix
    *		- R stands for rotation matrix
    *		- S stands for scaling matrix
    *		- P stands for projection matrix
    *		- D stands for direction vector
    */

    /*
    *	For KmVtoRord() and KmRtoVord()
    */
    enum {
	    KM_EULER_REPEAT_NO =	0,
	    KM_EULER_REPEAT_YES =	1
    };

    enum {
	    KM_EULER_PARITY_EVEN =	0,
	    KM_EULER_PARITY_ODD =	2
    };

    enum {
	    KM_EULER_AXIS_X =	0,
	    KM_EULER_AXIS_Y =	1,
	    KM_EULER_AXIS_Z =	2
    };

    #define KM_EULER_ORDER(Axis, Parity, Repeat)	(((Axis) << 2) | (Parity) | (Repeat))

    enum {
	    KM_EULER_XYZ = KM_EULER_ORDER(KM_EULER_AXIS_X, KM_EULER_PARITY_EVEN, KM_EULER_REPEAT_NO),
	    KM_EULER_XYX = KM_EULER_ORDER(KM_EULER_AXIS_X, KM_EULER_PARITY_EVEN, KM_EULER_REPEAT_YES),
	    KM_EULER_XZY = KM_EULER_ORDER(KM_EULER_AXIS_X, KM_EULER_PARITY_ODD, KM_EULER_REPEAT_NO),
	    KM_EULER_XZX = KM_EULER_ORDER(KM_EULER_AXIS_X, KM_EULER_PARITY_ODD, KM_EULER_REPEAT_YES),
	    KM_EULER_YZX = KM_EULER_ORDER(KM_EULER_AXIS_Y, KM_EULER_PARITY_EVEN, KM_EULER_REPEAT_NO),
	    KM_EULER_YZY = KM_EULER_ORDER(KM_EULER_AXIS_Y, KM_EULER_PARITY_EVEN, KM_EULER_REPEAT_YES),
	    KM_EULER_YXZ = KM_EULER_ORDER(KM_EULER_AXIS_Y, KM_EULER_PARITY_ODD, KM_EULER_REPEAT_NO),
	    KM_EULER_YXY = KM_EULER_ORDER(KM_EULER_AXIS_Y, KM_EULER_PARITY_ODD, KM_EULER_REPEAT_YES),
	    KM_EULER_ZXY = KM_EULER_ORDER(KM_EULER_AXIS_Z, KM_EULER_PARITY_EVEN, KM_EULER_REPEAT_NO),
	    KM_EULER_ZXZ = KM_EULER_ORDER(KM_EULER_AXIS_Z, KM_EULER_PARITY_EVEN, KM_EULER_REPEAT_YES),
	    KM_EULER_ZYX = KM_EULER_ORDER(KM_EULER_AXIS_Z, KM_EULER_PARITY_ODD, KM_EULER_REPEAT_NO),
	    KM_EULER_ZYZ = KM_EULER_ORDER(KM_EULER_AXIS_Z, KM_EULER_PARITY_ODD, KM_EULER_REPEAT_YES)
    };


    ////////////////////////////////////////////////////////////////////////////////
    //
    //	Constants
    //
    ////////////////////////////////////////////////////////////////////////////////

    extern KFBX_DLL const int KmEulerAxis[][3];
    extern KFBX_DLL const double KmIdentity[4][4];

    ////////////////////////////////////////////////////////////////////////////////
    //
    //	Vector Utilities
    //
    ////////////////////////////////////////////////////////////////////////////////

    /*
    *	KmVlength : Vector Length
    *
    *	INPUT
    *		pVi:	input vector Vi
    *
    *	RETURN VALUE
    *		|Vi|
    */
    K_INLINE double KmVlength(const double *const pVi)
    {
	    return kNorm(pVi[0], pVi[1], pVi[2]);
    }

    K_INLINE float Kmvlength(const kOGLFloat *const pVi)
    {
	    return kNorm(pVi[0], pVi[1], pVi[2]);
    }

    /*
    *	KmVlength2 : Vector Squared Length
    *
    *	INPUT
    *		pVi:	input vector Vi
    *
    *	RETURN VALUE
    *		|Vi|^2
    */
    K_INLINE double KmVlength2(const double *const pVi)
    {
	    double X, Y, Z;

	    X = pVi[0];
	    Y = pVi[1];
	    Z = pVi[2];

	    return X * X + Y * Y + Z * Z;
    }

    /*
    *	KmVdist2 : Vector Squared Distance
    *
    *	INPUT
    *		pViA:	input vector ViA
    *		pViB:	input vector ViB
    *
    *	RETURN VALUE
    *		| ViA - ViB |^2
    */
    K_INLINE double KmVdist2(const double *const pViA, const double *const pViB)
    {
	    double	X, Y, Z;

	    X = pViA[0] - pViB[0];
	    Y = pViA[1] - pViB[1];
	    Z = pViA[2] - pViB[2];

	    return X * X + Y * Y + Z * Z;
    }

    /*
    *	KmVdist : Vector Distance
    *
    *	INPUT
    *		pViA:	input vector ViA
    *		pViB:	input vector ViB
    *
    *	RETURN VALUE
    *		| ViA - ViB |
    */
    K_INLINE double KmVdist(const double *const pViA, const double *const pViB)
    {
	    return kSqrt(KmVdist2(pViA, pViB));
    }

    /*
    *	KmVdotV : Vector Inner Product
    *
    *	INPUT
    *		pViA:	input vector ViA
    *		pViB:	input vector ViB
    *
    *	RETURN VALUE
    *		ViA . ViB
    */
    K_INLINE double KmVdotV(const double *const pViA, const double *const pViB)
    {
	    return pViA[0] * pViB[0] + pViA[1] * pViB[1] + pViA[2] * pViB[2];
    }

    K_INLINE float KmVdotV(const float *const pViA, const float *const pViB)
    {
	    return pViA[0] * pViB[0] + pViA[1] * pViB[1] + pViA[2] * pViB[2];
    }
    /*
    *	KmVcmp : Vector Compare
    *
    *	INPUT
    *		pViA:	input vector ViA
    *		pViB:	input vector ViB
    *
    *	RETURN VALUE
    *		ViA != ViB
    */
    K_INLINE int KmVcmp(const double *const pViA, const double *const pViB, K_DEFAULT(const double pThreshold, KM_TOLERANCE))
    {
	    return 
		    (pThreshold == 0.0) ?
			    memcmp((const void *) pViA, (const void *) pViB, 3 * sizeof(double)) :
			    (kAbs(pViA[0] - pViB[0]) > pThreshold) ||
			    (kAbs(pViA[1] - pViB[1]) > pThreshold) ||
			    (kAbs(pViA[2] - pViB[2]) > pThreshold);
    }

    K_INLINE int Kmvcmp(const kOGLFloat *const pViA, const kOGLFloat *const pViB, K_DEFAULT(const kOGLFloat pThreshold, KM_TOLERANCE))
    {
	    return 
		    (pThreshold == 0.0) ?
			    memcmp((const void *) pViA, (const void *) pViB, 3 * sizeof(kOGLFloat)) :
			    (kAbs(pViA[0] - pViB[0]) > pThreshold) ||
			    (kAbs(pViA[1] - pViB[1]) > pThreshold) ||
			    (kAbs(pViA[2] - pViB[2]) > pThreshold);
    }


    /*
    *	KmRVcmp : Rotation Vector Compare
    *
    *	INPUT
    *		pViA:	input vector ViA
    *		pViB:	input vector ViB
    *
    *	RETURN VALUE
    *		ViA != ViB
    */
    K_INLINE int KmRVcmp(const double *const pViA, const double *const pViB, K_DEFAULT(const double pThreshold, KM_TOLERANCE))
    {
	    double ViA[3], ViB[3];

	    ViA[0] = kMod(pViA[0], 360.0);
	    ViA[1] = kMod(pViA[1], 360.0);
	    ViA[2] = kMod(pViA[2], 360.0);
	    ViB[0] = kMod(pViB[0], 360.0);
	    ViB[1] = kMod(pViB[1], 360.0);
	    ViB[2] = kMod(pViB[2], 360.0);

	    return (
		    ((kAbs(pViA[0] - pViB[0]) > pThreshold) ||
		    (kAbs(pViA[1] - pViB[1]) > pThreshold) ||
		    (kAbs(pViA[2] - pViB[2]) > pThreshold)) &&
		    ((kAbs(kAbs(ViA[0] - ViB[0]) - 180.0) > pThreshold) ||
		    (kAbs(kAbs(ViA[1] + ViB[1]) - 180.0) > pThreshold) ||
		    (kAbs(kAbs(ViA[2] - ViB[2]) - 180.0) > pThreshold)));
    }

    ////////////////////////////////////////////////////////////////////////////////
    //
    //	Vector Initialization
    //
    ////////////////////////////////////////////////////////////////////////////////

    /*
    *	KmV : Set Vector
    *
    *	INPUT
    *		pN0:	input value N0
    *		pN1:	input value N1
    *		pN2:	input value N2
    *
    *	OUTPUT
    *		pVo:	output vector Vo = | N0 N1 N2 |^T
    *
    *	RETURN VALUE
    *		pVo
    */
    K_INLINE double *KmV(double *const pVo, const double pN0, const double pN1, const double pN2)
    {
	    pVo[0] = pN0;
	    pVo[1] = pN1;
	    pVo[2] = pN2;

	    return pVo;
    }

    K_INLINE float *KmV(float *const pVo, const float pN0, const float pN1, const float pN2)
    {
	    pVo[0] = pN0;
	    pVo[1] = pN1;
	    pVo[2] = pN2;

	    return pVo;
    }

    /*
    *	KmVset : Set Vector
    *
    *	INPUT
    *		pVi:	input vector Vi
    *
    *	OUTPUT
    *		pVo:	output vector Vo = Vi
    *
    *	RETURN VALUE
    *		pVo
    *
    *	REMARKS
    *		- Works in-place
    */
    K_INLINE double *KmVset(double *const pVo, const double *const pVi)
    {
	    pVo[0] = pVi[0];
	    pVo[1] = pVi[1];
	    pVo[2] = pVi[2];

	    return pVo;
    }


    K_INLINE float *KmVset(float *const pVo, const float *const pVi)
    {
	    pVo[0] = pVi[0];
	    pVo[1] = pVi[1];
	    pVo[2] = pVi[2];

	    return pVo;
    }

    K_INLINE float *KmVset(float *const pVo, const double *const pVi)
    {
	    pVo[0] = (float)pVi[0];
	    pVo[1] = (float)pVi[1];
	    pVo[2] = (float)pVi[2];

	    return pVo;
    }

    K_INLINE double *KmVset(double *const pVo, const float *const pVi)
    {
	    pVo[0] = pVi[0];
	    pVo[1] = pVi[1];
	    pVo[2] = pVi[2];

	    return pVo;
    }



    ////////////////////////////////////////////////////////////////////////////////
    //
    //	Vector Operations
    //
    ////////////////////////////////////////////////////////////////////////////////

    /*
    *	KmVneg : Vector Negate
    *
    *	INPUT
    *		pVi:	input vector Vi
    *
    *	OUTPUT
    *		pVo:	output vector Vo = -Vi
    *
    *	RETURN VALUE
    *		pVo
    *
    *	REMARKS
    *		- Works in-place
    */
    K_INLINE double *KmVneg(double *const pVo, KM_CONST double *const pVi)
    {
	    pVo[0] = -pVi[0];
	    pVo[1] = -pVi[1];
	    pVo[2] = -pVi[2];

	    return pVo;
    }

    /*
    *	KmVadd : Vector Add
    *
    *	INPUT
    *		pViA:	input vector ViA
    *		pViB:	input vector ViB
    *
    *	OUTPUT
    *		pVo:	output vector Vo = ViA + ViB
    *
    *	RETURN VALUE
    *		pVo
    *
    *	REMARKS
    *		- Works in-place
    */
    K_INLINE double *KmVadd(double *const pVo, KM_CONST double *const pViA, KM_CONST double *const pViB)
    {
	    pVo[0] = pViA[0] + pViB[0];
	    pVo[1] = pViA[1] + pViB[1];
	    pVo[2] = pViA[2] + pViB[2];

	    return pVo;
    }

    K_INLINE float *KmVadd(float *const pVo, KM_CONST float *const pViA, KM_CONST float *const pViB)
    {
	    pVo[0] = pViA[0] + pViB[0];
	    pVo[1] = pViA[1] + pViB[1];
	    pVo[2] = pViA[2] + pViB[2];

	    return pVo;
    }

    /*
    *	KmVsub : Vector Subtract
    *
    *	INPUT
    *		pViA:	input vector ViA
    *		pViB:	input vector ViB
    *
    *	OUTPUT
    *		pVo:	output vector Vo = ViA - ViB
    *
    *	RETURN VALUE
    *		pVo
    *
    *	REMARKS
    *		- Works in-place
    */
    K_INLINE double *KmVsub(double *const pVo, KM_CONST double *const pViA, KM_CONST double *const pViB)
    {
	    pVo[0] = pViA[0] - pViB[0];
	    pVo[1] = pViA[1] - pViB[1];
	    pVo[2] = pViA[2] - pViB[2];

	    return pVo;
    }

    K_INLINE double *KmVsub(double *const pVo, KM_CONST float *const pViA, KM_CONST float *const pViB)
    {
	    pVo[0] = pViA[0] - pViB[0];
	    pVo[1] = pViA[1] - pViB[1];
	    pVo[2] = pViA[2] - pViB[2];

	    return pVo;
    }

    K_INLINE float *KmVsub(float *const pVo, KM_CONST float *const pViA, KM_CONST float *const pViB)
    {
	    pVo[0] = pViA[0] - pViB[0];
	    pVo[1] = pViA[1] - pViB[1];
	    pVo[2] = pViA[2] - pViB[2];

	    return pVo;
    }

    /*
    *	KmVrev : Vector Reverse
    *
    *	INPUT
    *		pVi:	input vector Vi
    *
    *	OUTPUT
    *		pVo:	output vector Vo = | Vi[2] Vi[1] Vi[0] |^T
    *
    *	RETURN VALUE
    *		pVo
    *
    *	REMARKS
    *		- Works in-place
    */
    K_INLINE double *KmVrev(double *const pVo, KM_CONST double *const pVi)
    {
	    if(pVo == pVi) {

		    double	T;

		    kSwap(pVo[0], pVo[2], T);

	    } else {

		    pVo[0] = pVi[2];
		    pVo[1] = pVi[1];
		    pVo[2] = pVi[0];
	    }

	    return pVo;
    }

    /*
    *	KmVV : Vector Cross Product
    *
    *	INPUT
    *		pViA:	input vector ViA
    *		pViB:	input vector ViB
    *
    *	OUTPUT
    *		pVo:	output vector Vo = ViA x ViB
    *
    *	RETURN VALUE
    *		pVo
    *
    *	REMARKS
    *		- Works in-place
    */
    K_INLINE double *KmVV(double *const pVo, KM_CONST double *const pViA, KM_CONST double *const pViB)
    {
	    double	T0, T1, T2;

	    T0 = pViA[1] * pViB[2] - pViA[2] * pViB[1];
	    T1 = pViA[2] * pViB[0] - pViA[0] * pViB[2];
	    T2 = pViA[0] * pViB[1] - pViA[1] * pViB[0];

	    pVo[0] = T0;
	    pVo[1] = T1;
	    pVo[2] = T2;

	    return pVo;
    }

    K_INLINE kOGLFloat *Kmvv( kOGLFloat *const pVo, KM_CONST kOGLFloat *const pViA, KM_CONST kOGLFloat *const pViB)
    {
	    kOGLFloat T0, T1, T2;

	    T0 = pViA[1] * pViB[2] - pViA[2] * pViB[1];
	    T1 = pViA[2] * pViB[0] - pViA[0] * pViB[2];
	    T2 = pViA[0] * pViB[1] - pViA[1] * pViB[0];

	    pVo[0] = T0;
	    pVo[1] = T1;
	    pVo[2] = T2;

	    return pVo;
    }


    /*
    *	KmVs : Vector Times Scalar
    *
    *	INPUT
    *		pVi:	input vector Vi
    *		pNi:	input scalar Ni
    *
    *	OUTPUT
    *		pVo:	output vector Vo = Vi * Ni
    *
    *	RETURN VALUE
    *		pVo
    *
    *	REMARKS
    *		- Works in-place
    */
    K_INLINE double *KmVN(double *const pVo, KM_CONST double *const pVi, const double pNi)
    {
	    pVo[0] = pVi[0] * pNi;
	    pVo[1] = pVi[1] * pNi;
	    pVo[2] = pVi[2] * pNi;

	    return pVo;
    }

    K_INLINE float *Kmvn(float *const pVo, KM_CONST float *const pVi, const float pNi)
    {
	    pVo[0] = pVi[0] * pNi;
	    pVo[1] = pVi[1] * pNi;
	    pVo[2] = pVi[2] * pNi;

	    return pVo;
    }

    /*
    *	KmVnorm : Vector Normalize
    *
    *	INPUT
    *		pVi:	input vector Vi
    *
    *	OUTPUT
    *		pVo:	output vector Vo = Vi / |Vi|
    *
    *	RETURN VALUE
    *		pVo
    *
    *	REMARKS
    *		- Works in-place
    */
    K_INLINE double *KmVnorm(double *const pVo, KM_CONST double *const pVi)
    {
	    double Len = KmVlength(pVi);
	    if (Len==0.0) {
		    pVo[0] = 0.0;
		    pVo[1] = 0.0;
		    pVo[2] = 0.0;
		    return pVo;
	    } else {
		    return KmVN(pVo, pVi, 1.0 / Len);
	    }
    }

    K_INLINE float *KmVnorm(float *const pVo, KM_CONST float *const pVi)
    {
	    float Len = Kmvlength(pVi);
	    if (Len==0.0) {
		    pVo[0] = 0.0;
		    pVo[1] = 0.0;
		    pVo[2] = 0.0;
		    return pVo;
	    } else {
		    return Kmvn(pVo, pVi, 1.0f / Len);
	    }
    }

    /*
    *	KmMV : Matrix by Vector Product
    *
    *	INPUT
    *		pMi:	input matrix Mi
    *		pVi:	input vector Vi
    *
    *	OUTPUT
    *		pVo:	output vector Vo = Mi * Vi
    *
    *	RETURN VALUE
    *		pVo
    *
    *	REMARKS
    *		- Works in-place
    */
    K_INLINE double *KmMV(
	    double *const pVo, 
	    const double (*const pMi)[4], 
	    KM_CONST double *const pVi)
    {
	    double	V0, V1, V2, W;

	    V0 = pVi[0];
	    V1 = pVi[1];
	    V2 = pVi[2];

	    W = 1.0 / (pMi[0][3] * V0 + pMi[1][3] * V1 + pMi[2][3] * V2 + pMi[3][3]);

	    pVo[0] = (pMi[0][0] * V0 + pMi[1][0] * V1 + pMi[2][0] * V2 + pMi[3][0]) * W;
	    pVo[1] = (pMi[0][1] * V0 + pMi[1][1] * V1 + pMi[2][1] * V2 + pMi[3][1]) * W;
	    pVo[2] = (pMi[0][2] * V0 + pMi[1][2] * V1 + pMi[2][2] * V2 + pMi[3][2]) * W;

	    return pVo;
    }

    /*
    *	KmMv : Matrix by Vector Product
    *
    *	INPUT
    *		pMi:	input matrix Mi
    *		pVi:	input vector Vi
    *
    *	OUTPUT
    *		pVo:	output vector Vo = Mi * Vi
    *
    *	RETURN VALUE
    *		pVo
    *
    *	REMARKS
    *		- Works in-place
    */
    K_INLINE kOGLFloat *KmMv(
	    kOGLFloat *const pVo, 
	    const double (*const pMi)[4], 
	    KM_CONST kOGLFloat *const pVi)
    {
	    kOGLFloat	V0, V1, V2, W;

	    V0 = pVi[0];
	    V1 = pVi[1];
	    V2 = pVi[2];

	    W = (kOGLFloat)(1.0 / (pMi[0][3] * V0 + pMi[1][3] * V1 + pMi[2][3] * V2 + pMi[3][3]));

	    pVo[0] = (kOGLFloat)((pMi[0][0] * V0 + pMi[1][0] * V1 + pMi[2][0] * V2 + pMi[3][0]) * W);
	    pVo[1] = (kOGLFloat)((pMi[0][1] * V0 + pMi[1][1] * V1 + pMi[2][1] * V2 + pMi[3][1]) * W);
	    pVo[2] = (kOGLFloat)((pMi[0][2] * V0 + pMi[1][2] * V1 + pMi[2][2] * V2 + pMi[3][2]) * W);

	    return pVo;
    }




    /*
    *	KmAV : Affine Matrix by Vector Product
    *
    *	INPUT
    *		pAi:	input matrix Ai
    *		pVi:	input vector Vi
    *
    *	OUTPUT
    *		pVo:	output vector Vo = Ai * Vi
    *
    *	RETURN VALUE
    *		pVo
    *
    *	REMARKS
    *		- Works in-place
    */
    K_INLINE double *KmAV(
	    double *const pVo, 
	    const double (*const pAi)[4], 
	    KM_CONST double *const pVi)
    {
	    double	V0, V1, V2;

	    V0 = pVi[0];
	    V1 = pVi[1];
	    V2 = pVi[2];

	    pVo[0] = pAi[0][0] * V0 + pAi[1][0] * V1 + pAi[2][0] * V2 + pAi[3][0];
	    pVo[1] = pAi[0][1] * V0 + pAi[1][1] * V1 + pAi[2][1] * V2 + pAi[3][1];
	    pVo[2] = pAi[0][2] * V0 + pAi[1][2] * V1 + pAi[2][2] * V2 + pAi[3][2];

	    return pVo;
    }

    /*
    *	KmAv : Affine Matrix by Vertex Product
    *
    *	INPUT
    *		pAi:	input matrix Ai
    *		pvi:	input vertex vi
    *
    *	OUTPUT
    *		pvo:	output vector vo = Ai * vi
    *
    *	RETURN VALUE
    *		pvo
    *
    *	REMARKS
    *		- Works in-place
    */
    K_INLINE kOGLFloat *KmAv(
	    kOGLFloat *const pVo, 
	    const double (*const pAi)[4], 
	    KM_CONST kOGLFloat *const pVi)
    {
	    const kOGLFloat V0 = pVi[0];
	    const kOGLFloat V1 = pVi[1];
	    const kOGLFloat V2 = pVi[2];

	    pVo[0] = kOGLFloat(pAi[0][0] * V0 + pAi[1][0] * V1 + pAi[2][0] * V2 + pAi[3][0]);
	    pVo[1] = kOGLFloat(pAi[0][1] * V0 + pAi[1][1] * V1 + pAi[2][1] * V2 + pAi[3][1]);
	    pVo[2] = kOGLFloat(pAi[0][2] * V0 + pAi[1][2] * V1 + pAi[2][2] * V2 + pAi[3][2]);

	    return pVo;
    }

    /*
    *	KmTV : Translation Matrix by Vector Product
    *
    *	INPUT
    *		pTi:	input matrix Ti
    *		pVi:	input vector Vi
    *
    *	OUTPUT
    *		pVo:	output vector Vo = Ti * Vi
    *
    *	RETURN VALUE
    *		pVo
    *
    *	REMARKS
    *		- Works in-place
    */
    K_INLINE double *KmTV(
	    double *const pVo, 
	    const double (*const pTi)[4], 
	    KM_CONST double *const pVi)
    {
	    pVo[0] = pTi[3][0] + pVi[0];
	    pVo[1] = pTi[3][1] + pVi[1];
	    pVo[2] = pTi[3][2] + pVi[2];

	    return pVo;
    }

    /*
    *	KmRV : Rotation Matrix by Vector Product
    *
    *	INPUT
    *		pRi:	input matrix Ri
    *		pVi:	input vector Vi
    *
    *	OUTPUT
    *		pVo:	output vector Vo = Ri * Vi
    *
    *	RETURN VALUE
    *		pVo
    *
    *	REMARKS
    *		- Works in-place
    */
    K_INLINE double *KmRV(
	    double *const pVo, 
	    const double (*const pRi)[4], 
	    KM_CONST double *const pVi)
    {
	    double	V0, V1, V2;

	    V0 = pVi[0];
	    V1 = pVi[1];
	    V2 = pVi[2];

	    pVo[0] = pRi[0][0] * V0 + pRi[1][0] * V1 + pRi[2][0] * V2;
	    pVo[1] = pRi[0][1] * V0 + pRi[1][1] * V1 + pRi[2][1] * V2;
	    pVo[2] = pRi[0][2] * V0 + pRi[1][2] * V1 + pRi[2][2] * V2;

	    return pVo;
    }

    /*
    *	KmRV : Rotation Matrix by Vertex Product
    *
    *	INPUT
    *		pRi:	input matrix Ri
    *		pVi:	input vector Vi
    *
    *	OUTPUT
    *		pVo:	output vector Vo = Ri * Vi
    *
    *	RETURN VALUE
    *		pVo
    *
    *	REMARKS
    *		- Works in-place
    */
    K_INLINE kOGLFloat *KmRV(
	    kOGLFloat *const pVo, 
	    const double (*const pRi)[4], 
	    KM_CONST kOGLFloat *const pVi)
    {
	    const kOGLFloat V0 = pVi[0];
	    const kOGLFloat V1 = pVi[1];
	    const kOGLFloat V2 = pVi[2];

	    pVo[0] = (kOGLFloat)(pRi[0][0] * V0 + pRi[1][0] * V1 + pRi[2][0] * V2);
	    pVo[1] = (kOGLFloat)(pRi[0][1] * V0 + pRi[1][1] * V1 + pRi[2][1] * V2);
	    pVo[2] = (kOGLFloat)(pRi[0][2] * V0 + pRi[1][2] * V1 + pRi[2][2] * V2);

	    return pVo;
    }



    /*
    *	KmSV : Scaling Matrix by Vector Product
    *
    *	INPUT
    *		pSi:	input matrix Si
    *		pVi:	input vector Vi
    *
    *	OUTPUT
    *		pVo:	output vector Vo = Si * Vi
    *
    *	RETURN VALUE
    *		pVo
    *
    *	REMARKS
    *		- Works in-place
    */
    K_INLINE double *KmSV(
	    double *const pVo, 
	    const double (*const pSi)[4], 
	    KM_CONST double *const pVi)
    {
	    pVo[0] = pSi[0][0] * pVi[0];
	    pVo[1] = pSi[1][1] * pVi[1];
	    pVo[2] = pSi[2][2] * pVi[2];

	    return pVo;
    }

    ////////////////////////////////////////////////////////////////////////////////
    //
    //	Quaternion Utilities
    //
    ////////////////////////////////////////////////////////////////////////////////

    /*
    *	KmQlength : Quaternion Length
    *
    *	INPUT
    *		pQi:	input quaternion Qi
    *
    *	RETURN VALUE
    *		|Qi|
    */
    K_INLINE double KmQlength(const double *const pQi)
    {
	    return kNorm(pQi[0], pQi[1], pQi[2], pQi[3]);
    }

    /*
    *	KmQlength2 : Quaternion Squared Length
    *
    *	INPUT
    *		pQi:	input quaternion Qi
    *
    *	RETURN VALUE
    *		|Qi|^2
    */
    K_INLINE double KmQlength2(const double *const pQi)
    {
	    double X, Y, Z, W;

	    X = pQi[0];
	    Y = pQi[1];
	    Z = pQi[2];
	    W = pQi[3];

	    return X * X + Y * Y + Z * Z + W * W;
    }

    /*
    *	KmQdotQ : Quaternion Dot Product
    *
    *	INPUT
    *		pQiA:	input quaternion QiA
    *		pQiB:	input quaternion QiB
    *
    *	RETURN VALUE
    *		pQiA . pQiB
    */
    K_INLINE double KmQdotQ(const double *const pQiA, const double *const pQiB)
    {
	    return pQiA[0] * pQiB[0] + pQiA[1] * pQiB[1] + pQiA[2] * pQiB[2] + pQiA[3] * pQiB[3];
    }

    /*
    *	KmQcmp : Quaternion Compare
    *
    *	INPUT
    *		pQiA:	input vector QiA
    *		pQiB:	input vector QiB
    *
    *	RETURN VALUE
    *		QiA != QiB
    */
    K_INLINE int KmQcmp(const double *const pQiA, const double *const pQiB, K_DEFAULT(const double pThreshold, KM_TOLERANCE))
    {
	    return 
		    (pThreshold == 0.0) ?
			    memcmp((const void *) pQiA, (const void *) pQiB, 4 * sizeof(double)) :
			    (kAbs(pQiA[0] - pQiB[0]) > pThreshold) ||
			    (kAbs(pQiA[1] - pQiB[1]) > pThreshold) ||
			    (kAbs(pQiA[2] - pQiB[2]) > pThreshold) ||
			    (kAbs(pQiA[3] - pQiB[3]) > pThreshold);
    }

    ////////////////////////////////////////////////////////////////////////////////
    //
    //	Quaternion Initialization
    //
    ////////////////////////////////////////////////////////////////////////////////

    /*
    *	KmQ : Set Quaternion
    *
    *	INPUT
    *		pX:	input value X
    *		pY:	input value Y
    *		pZ:	input value Z
    *		pW:	input value W
    *
    *	OUTPUT
    *		pQo:	output quaternion Qo = | X Y Z W |
    *
    *	RETURN VALUE
    *		pQo
    */
    K_INLINE double *KmQ(
	    double *const pQo, 
	    const double pX, const double pY, const double pZ, const double pW)
    {
	    pQo[0] = pX;
	    pQo[1] = pY;
	    pQo[2] = pZ;
	    pQo[3] = pW;

	    return pQo;
    }

    /*
    *	KmQset : Set Quaternion
    *
    *	INPUT
    *		pQi:	input quaternion Qi
    *
    *	OUTPUT
    *		pQo:	output quaternion Qo = Qi
    *
    *	RETURN VALUE
    *		pQo
    *
    *	REMARKS
    *		- Works in-place
    */
    K_INLINE double *KmQset(double *const pQo, const double *const pQi)
    {
	    pQo[0] = pQi[0];
	    pQo[1] = pQi[1];
	    pQo[2] = pQi[2];
	    pQo[3] = pQi[3];

	    return pQo;
    }

    ////////////////////////////////////////////////////////////////////////////////
    //
    //	Quaternion Operations
    //
    ////////////////////////////////////////////////////////////////////////////////

    /*
    *	KmQconj : Quaternion Conjugate
    *
    *	INPUT
    *		pQi:	input quaternion Qi
    *
    *	OUTPUT
    *		pQo:	output quaternion Qo = ~Qi
    *
    *	RETURN VALUE
    *		pQo
    *
    *	REMARKS
    *		- Works in-place
    */
    K_INLINE double *KmQconj(double *const pQo, KM_CONST double *const pQi)
    {
	    pQo[0] = -pQi[0];
	    pQo[1] = -pQi[1];
	    pQo[2] = -pQi[2];
	    pQo[3] = pQi[3];

	    return pQo;
    }

    /*
    *	KmQs : Quaternion Times Scalar
    *
    *	INPUT
    *		pQi:	input vector Qi
    *		pNi:	input scalar Ni
    *
    *	OUTPUT
    *		pQo:	output vector Qo = Qi * Ni
    *
    *	RETURN VALUE
    *		pQo
    *
    *	REMARKS
    *		- Works in-place
    */
    K_INLINE double *KmQN(double *const pQo, KM_CONST double *const pQi, const double pNi)
    {
	    pQo[0] = pQi[0] * pNi;
	    pQo[1] = pQi[1] * pNi;
	    pQo[2] = pQi[2] * pNi;
	    pQo[3] = pQi[3] * pNi;

	    return pQo;
    }

    /*
    *	KmQnorm : Quaternion Normalize
    *
    *	INPUT
    *		pQi:	input quaternion Qi
    *
    *	OUTPUT
    *		pQo:	output quaternion Qo = Qi / |Qi|
    *
    *	RETURN VALUE
    *		pQo
    *
    *	REMARKS
    *		- Works in-place
    */
    K_INLINE double *KmQnorm(double *const pQo, KM_CONST double *const pQi)
    {
	    return KmQN(pQo, pQi, 1.0 / KmQlength(pQi));
    }

    /*
    *	KmQadd : Quaternion Add
    *
    *	INPUT
    *		pQiA:	input quaternion QiA
    *		pQiB:	input quaternion QiB
    *
    *	OUTPUT
    *		pQo:	output quaternion Qo = QiA + QiB
    *
    *	RETURN VALUE
    *		pQo
    *
    *	REMARKS
    *		- Works in-place
    */
    K_INLINE double *KmQadd(double *const pQo, KM_CONST double *const pQiA, KM_CONST double *const pQiB)
    {
	    pQo[0] = pQiA[0] + pQiB[0];
	    pQo[1] = pQiA[1] + pQiB[1];
	    pQo[2] = pQiA[2] + pQiB[2];
	    pQo[3] = pQiA[3] + pQiB[3];

	    return pQo;
    }

    /*
    *	KmQQ : Quaternion Product
    *
    *	INPUT
    *		pQiA:	input quaternion QiL
    *		pQiB:	input quaternion QiR
    *
    *	OUTPUT
    *		pQo:	output quaternion Qo = QiL * QiR
    *
    *	RETURN VALUE
    *		pQo
    *
    *	REMARKS
    *		- Works in-place
    */
    K_INLINE double *KmQQ(double *const pQo, KM_CONST double *const pQiA, KM_CONST double *const pQiB)
    {
	    double	Q0, Q1, Q2, Q3;

	    if(pQo == pQiA) {

		    Q0 = pQiA[0];
		    Q1 = pQiA[1];
		    Q2 = pQiA[2];
		    Q3 = pQiA[3];

		    pQo[0] = Q3 * pQiB[0] + Q0 * pQiB[3] + Q1 * pQiB[2] - Q2 * pQiB[1];
		    pQo[1] = Q3 * pQiB[1] - Q0 * pQiB[2] + Q1 * pQiB[3] + Q2 * pQiB[0];
		    pQo[2] = Q3 * pQiB[2] + Q0 * pQiB[1] - Q1 * pQiB[0] + Q2 * pQiB[3];
		    pQo[3] = Q3 * pQiB[3] - Q0 * pQiB[0] - Q1 * pQiB[1] - Q2 * pQiB[2];

	    } else {

		    Q0 = pQiB[0];
		    Q1 = pQiB[1];
		    Q2 = pQiB[2];
		    Q3 = pQiB[3];

		    pQo[0] = Q0 * pQiA[3] + Q3 * pQiA[0] + Q2 * pQiA[1] - Q1 * pQiA[2];
		    pQo[1] = Q1 * pQiA[3] - Q2 * pQiA[0] + Q3 * pQiA[1] + Q0 * pQiA[2];
		    pQo[2] = Q2 * pQiA[3] + Q1 * pQiA[0] - Q0 * pQiA[1] + Q3 * pQiA[2];
		    pQo[3] = Q3 * pQiA[3] - Q0 * pQiA[0] - Q1 * pQiA[1] - Q2 * pQiA[2];
	    }

	    return pQo;
    }

    ////////////////////////////////////////////////////////////////////////////////
    //
    //	Matrix To Quaternion Decompositions
    //
    ////////////////////////////////////////////////////////////////////////////////
    					  
    /*
    *	KmRtoQ : Rotation Matrix To Quaternion
    *
    *	INPUT
    *		pRi:	input matrix Ri
    *
    *	OUTPUT
    *		pQo:	output quaternion Qo = Q(Ri)
    *
    *	RETURN VALUE
    *		pQo
    *
    *	REMARKS
    */
    K_INLINE double *KmRtoQ(double *const pQo, const double (*const pRi)[4])
    {
	    double T;

	    if((T = 0.25 * (pRi[0][0] + pRi[1][1] + pRi[2][2] + 1.0)) > KM_EPSILON) {

		    pQo[3] = T = kSqrt(T); T = 0.25 / T;
		    pQo[0] = T * (pRi[1][2] - pRi[2][1]);
		    pQo[1] = T * (pRi[2][0] - pRi[0][2]);
		    pQo[2] = T * (pRi[0][1] - pRi[1][0]);

	    } else {

		    pQo[3] = 0.0;
		    if((T = -0.5 * (pRi[1][1] + pRi[2][2])) > KM_EPSILON) {

			    pQo[0] = T = kSqrt(T); T = 0.5 / T;
			    pQo[1] = T * pRi[0][1];
			    pQo[2] = T * pRi[0][2];

		    } else {

			    pQo[0] = 0.0;
			    if((T = 0.5 * (1.0 - pRi[2][2])) > KM_EPSILON) {

				    pQo[1] = T = kSqrt(T); T  = 0.5 / T;
				    pQo[2] = T * pRi[1][2];

			    } else {

				    pQo[1] = 0.0;
				    pQo[2] = 1.0;
			    }
		    }
	    }

	    return pQo;
    }

    ////////////////////////////////////////////////////////////////////////////////
    //
    //	Matrix Utilities
    //
    ////////////////////////////////////////////////////////////////////////////////

    /*
    *	KmMdet : Matrix Determinant
    *
    *	INPUT
    *		pMi:	input matrix Mi
    *
    *	RETURN VALUE
    *		det(Mi)
    */
    K_INLINE double KmMdet(const double (*const pMi)[4])
    {
	    double	D01, D02, D03, D12, D13, D23;

	    D01 = pMi[0][2] * pMi[1][3] - pMi[0][3] * pMi[1][2];
	    D02 = pMi[0][2] * pMi[2][3] - pMi[0][3] * pMi[2][2];
	    D03 = pMi[0][2] * pMi[3][3] - pMi[0][3] * pMi[3][2];
	    D12 = pMi[1][2] * pMi[2][3] - pMi[1][3] * pMi[2][2];
	    D13 = pMi[1][2] * pMi[3][3] - pMi[1][3] * pMi[3][2];
	    D23 = pMi[2][2] * pMi[3][3] - pMi[2][3] * pMi[3][2];

	    return	
		    pMi[0][0] * (pMi[1][1] * D23 - pMi[2][1] * D13 + pMi[3][1] * D12) -
		    pMi[1][0] * (pMi[0][1] * D23 - pMi[2][1] * D03 + pMi[3][1] * D02) +
		    pMi[2][0] * (pMi[0][1] * D13 - pMi[1][1] * D03 + pMi[3][1] * D01) -
		    pMi[3][0] * (pMi[0][1] * D12 - pMi[1][1] * D02 + pMi[2][1] * D01);
    }
    													
    /*
    *	KmAdet : Affine Matrix Determinant
    *
    *	INPUT
    *		pAi:	input matrix Ai
    *
    *	RETURN VALUE
    *		det(Ai)
    */
    K_INLINE double KmAdet(const double (*const pAi)[4])
    {
	    return	
		    pAi[0][0] * (pAi[1][1] * pAi[2][2] - pAi[1][2] * pAi[2][1]) -
		    pAi[1][0] * (pAi[0][1] * pAi[2][2] - pAi[0][2] * pAi[2][1]) +
		    pAi[2][0] * (pAi[0][1] * pAi[1][2] - pAi[0][2] * pAi[1][1]);
    }
    													
    /*
    *	KmTdet : Translation Matrix Determinant
    *
    *	INPUT
    *		pTi:	input matrix Ti
    *
    *	RETURN VALUE
    *		det(Ti)
    */
    K_INLINE double KmTdet(const double (*const)[4])
    {
	    return 1.0;
    }

    /*
    *	KmRdet : Rotation Matrix Determinant
    *
    *	INPUT
    *		pRi:	input matrix Ri
    *
    *	RETURN VALUE
    *		det(Ri)
    */
    K_INLINE double KmRdet(const double (*const /*pRi*/)[4])
    {
	    return 1.0;
    }

    /*
    *	KmSdet : Scaling Matrix Determinant
    *
    *	INPUT
    *		pSi:	input matrix Si
    *
    *	RETURN VALUE
    *		det(Si)
    */
    K_INLINE double KmSdet(const double (*const pSi)[4])
    {
	    return pSi[0][0] * pSi[1][1] * pSi[2][2];
    }

    /*
    *	KmMtrace : Matrix Trace
    *
    *	INPUT
    *		pMi:	input matrix Mi
    *
    *	RETURN VALUE
    *		trace(Mi)
    */
    K_INLINE double KmMtrace(const double (*const pMi)[4])
    {
	    return pMi[0][0] + pMi[1][1] + pMi[2][2] + pMi[3][3];
    }

    /*
    *	KmAtrace : Affine Matrix Trace
    *
    *	INPUT
    *		pAi:	input matrix Ai
    *
    *	RETURN VALUE
    *		trace(Ai)
    */
    K_INLINE double KmAtrace(const double (*const pAi)[4])
    {
	    return pAi[0][0] + pAi[1][1] + pAi[2][2] + 1.0;
    }

    /*
    *	KmTtrace : Translation Matrix Trace
    *
    *	INPUT
    *		pTi:	input matrix Ti
    *
    *	RETURN VALUE
    *		trace(Ti)
    */
    K_INLINE double KmTtrace(const double (*const /*pTi*/)[4])
    {
	    return 4.0;
    }

    /*
    *	KmRtrace : Rotation Matrix Trace
    *
    *	INPUT
    *		pRi:	input matrix Ri
    *
    *	RETURN VALUE
    *		trace(Ri)
    */
    K_INLINE double KmRtrace(const double (*const pRi)[4])
    {
	    return KmAtrace(pRi);
    }

    /*
    *	KmStrace : Scaling Matrix Trace
    *
    *	INPUT
    *		pSi:	input matrix Si
    *
    *	RETURN VALUE
    *		trace(Si)
    */
    K_INLINE double KmStrace(const double (*const pSi)[4])
    {
	    return KmAtrace(pSi);
    }

    /*
    *	KmMcmp : Matrix Compare
    *
    *	INPUT
    *		pMiA:	input vector MiA
    *		pMiB:	input vector MiB
    *
    *	RETURN VALUE
    *		MiA != MiB
    */
    K_INLINE int KmMcmp(const double (*const pMiA)[4], const double (*const pMiB)[4], K_DEFAULT(const double pThreshold, KM_TOLERANCE))
    {
	    return 
		    (pThreshold == 0.0) ?
			    memcmp((const void *) pMiA, (const void *) pMiB, 16 * sizeof(double)) :
			    (kAbs(pMiA[0][0] - pMiB[0][0]) > pThreshold) ||
			    (kAbs(pMiA[0][1] - pMiB[0][1]) > pThreshold) ||
			    (kAbs(pMiA[0][2] - pMiB[0][2]) > pThreshold) ||
			    (kAbs(pMiA[0][3] - pMiB[0][3]) > pThreshold) ||
			    (kAbs(pMiA[1][0] - pMiB[1][0]) > pThreshold) ||
			    (kAbs(pMiA[1][1] - pMiB[1][1]) > pThreshold) ||
			    (kAbs(pMiA[1][2] - pMiB[1][2]) > pThreshold) ||
			    (kAbs(pMiA[1][3] - pMiB[1][3]) > pThreshold) ||
			    (kAbs(pMiA[2][0] - pMiB[2][0]) > pThreshold) ||
			    (kAbs(pMiA[2][1] - pMiB[2][1]) > pThreshold) ||
			    (kAbs(pMiA[2][2] - pMiB[2][2]) > pThreshold) ||
			    (kAbs(pMiA[2][3] - pMiB[2][3]) > pThreshold) ||
			    (kAbs(pMiA[3][0] - pMiB[3][0]) > pThreshold) ||
			    (kAbs(pMiA[3][1] - pMiB[3][1]) > pThreshold) ||
			    (kAbs(pMiA[3][2] - pMiB[3][2]) > pThreshold) ||
			    (kAbs(pMiA[3][3] - pMiB[3][3]) > pThreshold);
    }

    /*
    *	KmAcmp : Affine Matrix Compare
    *
    *	INPUT
    *		pAiA:	input vector AiA
    *		pAiB:	input vector AiB
    *
    *	RETURN VALUE
    *		AiA != AiB
    */
    K_INLINE int KmAcmp(const double (*const pAiA)[4], const double (*const pAiB)[4], K_DEFAULT(const double pThreshold, KM_TOLERANCE))
    {
	    return 
		    (pThreshold == 0.0) ?
			    memcmp((const void *) pAiA, (const void *) pAiB, 15 * sizeof(double)) :
			    (kAbs(pAiA[0][0] - pAiB[0][0]) > pThreshold) ||
			    (kAbs(pAiA[0][1] - pAiB[0][1]) > pThreshold) ||
			    (kAbs(pAiA[0][2] - pAiB[0][2]) > pThreshold) ||
			    (kAbs(pAiA[1][0] - pAiB[1][0]) > pThreshold) ||
			    (kAbs(pAiA[1][1] - pAiB[1][1]) > pThreshold) ||
			    (kAbs(pAiA[1][2] - pAiB[1][2]) > pThreshold) ||
			    (kAbs(pAiA[2][0] - pAiB[2][0]) > pThreshold) ||
			    (kAbs(pAiA[2][1] - pAiB[2][1]) > pThreshold) ||
			    (kAbs(pAiA[2][2] - pAiB[2][2]) > pThreshold) ||
			    (kAbs(pAiA[3][0] - pAiB[3][0]) > pThreshold) ||
			    (kAbs(pAiA[3][1] - pAiB[3][1]) > pThreshold) ||
			    (kAbs(pAiA[3][2] - pAiB[3][2]) > pThreshold);
    }

    /*
    *	KmTcmp : Affine Matrix Compare
    *
    *	INPUT
    *		pTiA:	input vector TiA
    *		pTiB:	input vector TiB
    *
    *	RETURN VALUE
    *		TiA == TiB
    */
    K_INLINE int KmTcmp(const double (*const pTiA)[4], const double (*const pTiB)[4], K_DEFAULT(const double pThreshold, KM_TOLERANCE))
    {
	    return 
		    (pThreshold == 0.0) ?
			    (pTiA[3][0] == pTiB[3][0]) && (pTiA[3][1] == pTiB[3][1]) && (pTiA[3][2] == pTiB[3][2]) :
			    (kAbs(pTiA[3][0] - pTiB[3][0]) < pThreshold) &&
			    (kAbs(pTiA[3][1] - pTiB[3][1]) < pThreshold) &&
			    (kAbs(pTiA[3][2] - pTiB[3][2]) < pThreshold);
    }

    /*
    *	KmRcmp : Rotation Matrix Compare
    *
    *	INPUT
    *		pRiA:	input vector RiA
    *		pRiB:	input vector RiB
    *
    *	RETURN VALUE
    *		RiA != RiB
    */
    K_INLINE int KmRcmp(const double (*const pRiA)[4], const double (*const pRiB)[4], K_DEFAULT(const double pThreshold, KM_TOLERANCE))
    {
	    return 
		    (pThreshold == 0.0) ?
			    memcmp((const void *) pRiA, (const void *) pRiB, 11 * sizeof(double)) :
			    (kAbs(pRiA[0][0] - pRiB[0][0]) > pThreshold) ||
			    (kAbs(pRiA[0][1] - pRiB[0][1]) > pThreshold) ||
			    (kAbs(pRiA[0][2] - pRiB[0][2]) > pThreshold) ||
			    (kAbs(pRiA[1][0] - pRiB[1][0]) > pThreshold) ||
			    (kAbs(pRiA[1][1] - pRiB[1][1]) > pThreshold) ||
			    (kAbs(pRiA[1][2] - pRiB[1][2]) > pThreshold) ||
			    (kAbs(pRiA[2][0] - pRiB[2][0]) > pThreshold) ||
			    (kAbs(pRiA[2][1] - pRiB[2][1]) > pThreshold) ||
			    (kAbs(pRiA[2][2] - pRiB[2][2]) > pThreshold);
    }

    /*
    *	KmScmp : Scaling Matrix Compare
    *
    *	INPUT
    *		pSiA:	input vector SiA
    *		pSiB:	input vector SiB
    *
    *	RETURN VALUE
    *		SiA == SiB
    */
    K_INLINE int KmScmp(const double (*const pSiA)[4], const double (*const pSiB)[4], K_DEFAULT(const double pThreshold, KM_TOLERANCE))
    {
	    return 
		    (pThreshold == 0.0) ?
			    (pSiA[0][0] == pSiB[0][0]) && (pSiA[1][1] == pSiB[1][1]) && (pSiA[2][2] == pSiB[2][2]) :
			    (kAbs(pSiA[0][0] - pSiB[0][0]) < pThreshold) &&
			    (kAbs(pSiA[1][1] - pSiB[1][1]) < pThreshold) &&
			    (kAbs(pSiA[2][2] - pSiB[2][2]) < pThreshold);
    }

    ////////////////////////////////////////////////////////////////////////////////
    //
    //	Matrix Initialization
    //
    ////////////////////////////////////////////////////////////////////////////////

    /*
    *	KmId : Matrix Identity
    *
    *	OUTPUT
    *		pMo:	output vector Mo = I
    *
    *	RETURN VALUE
    *		pMo
    *
    *	REMARKS
    *		- Should try out memset() under Win32 with intrinsic optimization
    */
    K_INLINE double (*KmId(double (*const pMo)[4]))[4]
    {
	    pMo[0][0] = pMo[1][1] = pMo[2][2] = pMo[3][3] = 1.0;
	    pMo[0][1] = pMo[0][2] = pMo[0][3] = 
	    pMo[1][0] = pMo[1][2] = pMo[1][3] =
	    pMo[2][0] = pMo[2][1] = pMo[2][3] =
	    pMo[3][0] = pMo[3][1] = pMo[3][2] = 0.0;

	    return pMo;
    }

    /*
    *	KmAinit : Affine Matrix Initialize
    *
    *	OUTPUT
    *		pAo:	output vector Ao
    *
    *	RETURN VALUE
    *		pAo
    *
    *	REMARKS
    *		- Should try out memset() under Win32 with intrinsic optimization
    */
    K_INLINE double (*KmAinit(double (*const pAo)[4]))[4]
    {
	    pAo[0][3] = pAo[1][3] = pAo[2][3] = 0.0;
	    pAo[3][3] = 1.0;

	    return pAo;
    }

    /*
    *	KmTinit : Translation Matrix Initialize
    *
    *	OUTPUT
    *		pTo:	output vector To
    *
    *	RETURN VALUE
    *		pTo
    *
    *	REMARKS
    *		- Should try out memset() under Win32 with intrinsic optimization
    */
    K_INLINE double (*KmTinit(double (*const pTo)[4]))[4]
    {
	    pTo[0][1] = pTo[0][2] = pTo[0][3] = 
	    pTo[1][0] = pTo[1][2] = pTo[1][3] =
	    pTo[2][0] = pTo[2][1] = pTo[2][3] = 0.0;
	    pTo[0][0] = pTo[1][1] = pTo[2][2] = pTo[3][3] = 1.0;

	    return pTo;
    }

    /*
    *	KmRinit : Rotation Matrix Initialize
    *
    *	OUTPUT
    *		pRo:	output vector Ro
    *
    *	RETURN VALUE
    *		pRo
    *
    *	REMARKS
    *		- Should try out memset() under Win32 with intrinsic optimization
    */
    K_INLINE double (*KmRinit(double (*const pRo)[4]))[4]
    {
	    pRo[0][3] = pRo[1][3] = pRo[2][3] = 
	    pRo[3][0] = pRo[3][1] = pRo[3][2] = 0.0;
	    pRo[3][3] = 1.0;

	    return pRo;
    }

    /*
    *	KmSinit : Scaling Matrix Initialize
    *
    *	OUTPUT
    *		pSo:	output vector So
    *
    *	RETURN VALUE
    *		pSo
    *
    *	REMARKS
    *		- Should try out memset() under Win32 with intrinsic optimization
    */
    K_INLINE double (*KmSinit(double (*const pSo)[4]))[4]
    {
	    pSo[0][1] = pSo[0][2] = pSo[0][3] = 
	    pSo[1][0] = pSo[1][2] = pSo[1][3] =
	    pSo[2][0] = pSo[2][1] = pSo[2][3] = 
	    pSo[3][0] = pSo[3][1] = pSo[3][2] = 0.0;
	    pSo[3][3] = 1.0;

	    return pSo;
    }

    /*
    *	KmMset : Set Matrix
    *
    *	INPUT
    *		pMi:	input matrix Mi
    *
    *	OUTPUT
    *		pMo:	output matrix Mo = Mi
    *
    *	RETURN VALUE
    *		pMo
    *
    *	REMARKS
    *		- Should try out memcpy() under Win32 with intrinsic optimization
    */
    K_INLINE double (*KmMset(double (*const pMo)[4], const double (*const pMi)[4]))[4]
    {
	    pMo[0][0] = pMi[0][0];
	    pMo[0][1] = pMi[0][1];
	    pMo[0][2] = pMi[0][2];
	    pMo[0][3] = pMi[0][3];

	    pMo[1][0] = pMi[1][0];
	    pMo[1][1] = pMi[1][1];
	    pMo[1][2] = pMi[1][2];
	    pMo[1][3] = pMi[1][3];

	    pMo[2][0] = pMi[2][0];
	    pMo[2][1] = pMi[2][1];
	    pMo[2][2] = pMi[2][2];
	    pMo[2][3] = pMi[2][3];

	    pMo[3][0] = pMi[3][0];
	    pMo[3][1] = pMi[3][1];
	    pMo[3][2] = pMi[3][2];
	    pMo[3][3] = pMi[3][3];

	    return pMo;
    }

    /*
    *	KmAset : Set Affine Matrix
    *
    *	INPUT
    *		pAi:	input matrix Ai
    *
    *	OUTPUT
    *		pAo:	output matrix Ao = Ai
    *
    *	RETURN VALUE
    *		pAo
    *
    *	REMARKS
    *		- Should try out memcpy() under Win32 with intrinsic optimization
    */
    K_INLINE double (*KmAset(double (*const pAo)[4], const double (*const pAi)[4]))[4]
    {
	    pAo[0][0] = pAi[0][0];
	    pAo[0][1] = pAi[0][1];
	    pAo[0][2] = pAi[0][2];

	    pAo[1][0] = pAi[1][0];
	    pAo[1][1] = pAi[1][1];
	    pAo[1][2] = pAi[1][2];

	    pAo[2][0] = pAi[2][0];
	    pAo[2][1] = pAi[2][1];
	    pAo[2][2] = pAi[2][2];

	    pAo[3][0] = pAi[3][0];
	    pAo[3][1] = pAi[3][1];
	    pAo[3][2] = pAi[3][2];

	    return pAo;
    }

    /*
    *	KmTset : Set Translation Matrix
    *
    *	INPUT
    *		pTi:	input matrix Ti
    *
    *	OUTPUT
    *		pTo:	output matrix To = Ti
    *
    *	RETURN VALUE
    *		pTo
    */
    K_INLINE double (*KmTset(double (*const pTo)[4], const double (*const pTi)[4]))[4]
    {
	    pTo[3][0] = pTi[3][0];
	    pTo[3][1] = pTi[3][1];
	    pTo[3][2] = pTi[3][2];

	    return pTo;
    }

    /*
    *	KmRset : Set Rotation Matrix
    *
    *	INPUT
    *		pRi:	input matrix Ri
    *
    *	OUTPUT
    *		pRo:	output matrix Ro = Ri
    *
    *	RETURN VALUE
    *		pRo
    */
    K_INLINE double (*KmRset(double (*const pRo)[4], const double (*const pRi)[4]))[4]
    {
	    pRo[0][0] = pRi[0][0];
	    pRo[0][1] = pRi[0][1];
	    pRo[0][2] = pRi[0][2];

	    pRo[1][0] = pRi[1][0];
	    pRo[1][1] = pRi[1][1];
	    pRo[1][2] = pRi[1][2];

	    pRo[2][0] = pRi[2][0];
	    pRo[2][1] = pRi[2][1];
	    pRo[2][2] = pRi[2][2];

	    return pRo;
    }

    /*
    *	KmSset : Set Scaling Matrix
    *
    *	INPUT
    *		pSi:	input matrix Si
    *
    *	OUTPUT
    *		pSo:	output matrix So = Si
    *
    *	RETURN VALUE
    *		pSo
    */
    K_INLINE double (*KmSset(double (*const pSo)[4], const double (*const pSi)[4]))[4]
    {
	    pSo[0][0] = pSi[0][0];
	    pSo[1][1] = pSi[1][1];
	    pSo[2][2] = pSi[2][2];

	    return pSo;
    }

    ////////////////////////////////////////////////////////////////////////////////
    //
    //	Matrix Operations
    //
    ////////////////////////////////////////////////////////////////////////////////

    /*
    *	KmMt : Matrix Transpose
    *
    *	INPUT
    *		pMi:	input matrix Mi
    *
    *	OUTPUT
    *		pMo:	output matrix Mo = Mi^t
    *
    *	RETURN VALUE
    *		pMo
    *
    *	REMARKS
    *		- Works in-place
    */
    K_INLINE double (*KmMt(
	    double (*const pMo)[4], 
	    KM_CONST double (*const pMi)[4]))[4]
    {
	    if(pMo == pMi) {

		    double T;

		    kSwap(pMo[0][1], pMo[1][0], T);
		    kSwap(pMo[0][2], pMo[2][0], T);
		    kSwap(pMo[0][3], pMo[3][0], T);
		    kSwap(pMo[1][2], pMo[2][1], T);
		    kSwap(pMo[1][3], pMo[3][1], T);
		    kSwap(pMo[2][3], pMo[3][2], T);

	    } else {

		    pMo[0][0] = pMi[0][0];
		    pMo[0][1] = pMi[1][0];
		    pMo[0][2] = pMi[2][0];
		    pMo[0][3] = pMi[3][0];

		    pMo[1][0] = pMi[0][1];
		    pMo[1][1] = pMi[1][1];
		    pMo[1][2] = pMi[2][1];
		    pMo[1][3] = pMi[3][1];

		    pMo[2][0] = pMi[0][2];
		    pMo[2][1] = pMi[1][2];
		    pMo[2][2] = pMi[2][2];
		    pMo[2][3] = pMi[3][2];

		    pMo[3][0] = pMi[0][3];
		    pMo[3][1] = pMi[1][3];
		    pMo[3][2] = pMi[2][3];
		    pMo[3][3] = pMi[3][3];
	    }

	    return pMo;
    }

    /*
    *	KmMadj : Matrix Adjoint
    *
    *	INPUT
    *		pMi:	input matrix Mi
    *
    *	OUTPUT
    *		pMo:	output matrix Mo = adj(Mi)
    *
    *	RETURN VALUE
    *		pMo
    *
    *	REMARKS
    *		- Doesn't work in-place
    */
    K_INLINE double (*KmMadj(
	    double (*const pMo)[4], 
	    const double (*const pMi)[4]))[4]
    {
	    double	D01, D02, D03, D12, D13, D23;

	    KM_ASSERT(pMo != (double (*)[4]) pMi, "KmMadj() doesn't work in-place");

	    D01 = pMi[0][2] * pMi[1][3] - pMi[0][3] * pMi[1][2];
	    D02 = pMi[0][2] * pMi[2][3] - pMi[0][3] * pMi[2][2];
	    D03 = pMi[0][2] * pMi[3][3] - pMi[0][3] * pMi[3][2];
	    D12 = pMi[1][2] * pMi[2][3] - pMi[1][3] * pMi[2][2];
	    D13 = pMi[1][2] * pMi[3][3] - pMi[1][3] * pMi[3][2];
	    D23 = pMi[2][2] * pMi[3][3] - pMi[2][3] * pMi[3][2];

	    pMo[0][0] = pMi[1][1] * D23 - pMi[2][1] * D13 + pMi[3][1] * D12;
	    pMo[0][1] = pMi[0][1] * D23 - pMi[2][1] * D03 + pMi[3][1] * D02;
	    pMo[0][2] = pMi[0][1] * D13 - pMi[1][1] * D03 + pMi[3][1] * D01;
	    pMo[0][3] = pMi[0][1] * D12 - pMi[1][1] * D02 + pMi[2][1] * D01;
	    pMo[1][0] = pMi[1][0] * D23 - pMi[2][0] * D13 + pMi[3][0] * D12;
	    pMo[1][1] = pMi[0][0] * D23 - pMi[2][0] * D03 + pMi[3][0] * D02;
	    pMo[1][2] = pMi[0][0] * D13 - pMi[1][0] * D03 + pMi[3][0] * D01;
	    pMo[1][3] = pMi[0][0] * D12 - pMi[1][0] * D02 + pMi[2][0] * D01;

	    D01 = pMi[0][0] * pMi[1][1] - pMi[0][1] * pMi[1][0];
	    D02 = pMi[0][0] * pMi[2][1] - pMi[0][1] * pMi[2][0];
	    D03 = pMi[0][0] * pMi[3][1] - pMi[0][1] * pMi[3][0];
	    D12 = pMi[1][0] * pMi[2][1] - pMi[1][1] * pMi[2][0];
	    D13 = pMi[1][0] * pMi[3][1] - pMi[1][1] * pMi[3][0];
	    D23 = pMi[2][0] * pMi[3][1] - pMi[2][1] * pMi[3][0];

	    pMo[2][0] = pMi[1][3] * D23 - pMi[2][3] * D13 + pMi[3][3] * D12;
	    pMo[2][1] = pMi[0][3] * D23 - pMi[2][3] * D03 + pMi[3][3] * D02;
	    pMo[2][2] = pMi[0][3] * D13 - pMi[1][3] * D03 + pMi[3][3] * D01;
	    pMo[2][3] = pMi[0][3] * D12 - pMi[1][3] * D02 + pMi[2][3] * D01;
	    pMo[3][0] = pMi[1][2] * D23 - pMi[2][2] * D13 + pMi[3][2] * D12;
	    pMo[3][1] = pMi[0][2] * D23 - pMi[2][2] * D03 + pMi[3][2] * D02;
	    pMo[3][2] = pMi[0][2] * D13 - pMi[1][2] * D03 + pMi[3][2] * D01;
	    pMo[3][3] = pMi[0][2] * D12 - pMi[1][2] * D02 + pMi[2][2] * D01;

	    return pMo;
    }

    /*
    *	KmLU : Matrix LU
    *
    *	RETURN VALUE
    *		0.0 if singular
    */
    #ifdef KARCH_DEV_MSC
    #pragma warning(disable: 4706)
    #endif
    K_INLINE double (*KmLU(double (*const pM)[4]))[4]
    {
	    double	T0, T1;
	    int	I0, I1;
	    int	Index[4];

	    if((T0 = kAbs(pM[0][0])) > (T1 = kAbs(pM[0][1]))) {
		    if(T0 > (T1 = kAbs(pM[0][2]))) {
			    I0 = (T0 > kAbs(pM[0][3])) ? 0 : 3;
		    } else {
			    I0 = (kAbs(pM[0][3]) > T1) ? 3 : 2;
		    }
	    } else {
		    if((T0 = kAbs(pM[0][2])) > T1) {
			    I0 = (T0 > kAbs(pM[0][3])) ? 2 : 3;
		    } else {
			    I0 = (kAbs(pM[0][3]) > T1) ? 3 : 1;
		    }
	    }

	    Index[0] = 0;
	    Index[1] = 1;
	    Index[2] = 2;
	    Index[3] = 3;

	    if(I0 != 0) {
		    kSwap(Index[0], Index[I0], I1);
	    }

	    if((T0 = pM[0][Index[0]]) != 0) {

		    T0 = 1.0 / T0;

		    pM[0][Index[1]] = pM[0][Index[1]] * T0;
		    pM[1][Index[1]] -= pM[0][Index[1]] * pM[1][Index[0]];
		    pM[2][Index[1]] -= pM[0][Index[1]] * pM[2][Index[0]];
		    pM[3][Index[1]] -= pM[0][Index[1]] * pM[3][Index[0]];

		    pM[0][Index[2]] = pM[0][Index[2]] * T0;
		    pM[1][Index[2]] -= pM[0][Index[2]] * pM[1][Index[0]];
		    pM[2][Index[2]] -= pM[0][Index[2]] * pM[2][Index[0]];
		    pM[3][Index[2]] -= pM[0][Index[2]] * pM[3][Index[0]];

		    pM[0][Index[3]] = pM[0][Index[3]] * T0;
		    pM[1][Index[3]] -= pM[0][Index[3]] * pM[1][Index[0]];
		    pM[2][Index[3]] -= pM[0][Index[3]] * pM[2][Index[0]];
		    pM[3][Index[3]] -= pM[0][Index[3]] * pM[3][Index[0]];

		    if((T0 = kAbs(pM[1][Index[1]])) > (T1 = kAbs(pM[1][Index[2]]))) {
			    I0 = (T0 > kAbs(pM[1][Index[3]])) ? 1 : 3;
		    } else {
			    I0 = (kAbs(pM[1][Index[3]]) > T1) ? 3 : 2;
		    }

		    if(I0 != 1) {
			    kSwap(Index[1], Index[I0], I1);
		    }

		    if((T0 = pM[1][Index[1]]) != 0) {

			    T0 = 1.0 / T0;

			    pM[1][Index[2]] = pM[1][Index[2]] * T0;
			    pM[2][Index[2]] -= pM[1][Index[2]] * pM[2][Index[1]];
			    pM[3][Index[2]] -= pM[1][Index[2]] * pM[3][Index[1]];

			    pM[1][Index[3]] = pM[1][Index[3]] * T0;
			    pM[2][Index[3]] -= pM[1][Index[3]] * pM[2][Index[1]];
			    pM[3][Index[3]] -= pM[1][Index[3]] * pM[3][Index[1]];

			    I0 = (kAbs(pM[2][Index[2]]) > kAbs(pM[2][Index[3]])) ? 2 : 3;

			    if(I0 != 2) {
				    kSwap(Index[2], Index[I0], I1);
			    }

			    if((T0 = pM[2][Index[2]]) != 0) {

				    pM[2][Index[3]] = pM[2][Index[3]] / T0;
				    pM[3][Index[3]] -= pM[2][Index[3]] * pM[3][Index[2]];

				    pM[4][0] = (double) Index[0];
				    pM[4][1] = (double) Index[1];
				    pM[4][2] = (double) Index[2];
				    pM[4][3] = (double) Index[3];

				    return pM[3][Index[3]] ? pM : NULL;
			    }
		    }
	    }

	    return NULL;
    }
    #ifdef KARCH_DEV_MSC
    #pragma warning(default: 4706)
    #endif

    /*
    *	KmMneg : Matrix Negate
    *
    *	INPUT
    *		pMi:	input matrix Mi
    *
    *	OUTPUT
    *		pMo:	output matrix Mo = -Mi
    *
    *	RETURN VALUE
    *		pMo
    *
    *	REMARKS
    *		- Works in-place
    */
    K_INLINE double (*KmMneg(
	    double (*const pMo)[4], 
	    KM_CONST double (*const pMi)[4]))[4]
    {
	    pMo[0][0] = -pMi[0][0];
	    pMo[0][1] = -pMi[0][1];
	    pMo[0][2] = -pMi[0][2];
	    pMo[0][3] = -pMi[0][3];

	    pMo[1][0] = -pMi[1][0];
	    pMo[1][1] = -pMi[1][1];
	    pMo[1][2] = -pMi[1][2];
	    pMo[1][3] = -pMi[1][3];

	    pMo[2][0] = -pMi[2][0];
	    pMo[2][1] = -pMi[2][1];
	    pMo[2][2] = -pMi[2][2];
	    pMo[2][3] = -pMi[2][3];

	    pMo[3][0] = -pMi[3][0];
	    pMo[3][1] = -pMi[3][1];
	    pMo[3][2] = -pMi[3][2];
	    pMo[3][3] = -pMi[3][3];

	    return pMo;
    }

    /*
    *	KmLUM : LU Matrix Times Matrix
    *
    *	INPUT
    *		pLUi:	input LU matrix LUi
    *		pMi:	input matrix Mi
    *
    *	OUTPUT
    *		pMo:	output matrix Mo = LU * Mi
    *
    *	RETURN VALUE
    *		pMo
    *
    *	REMARKS
    *		- Doesn't work in-place
    *		- pMi is destroyed
    */
    K_INLINE double (*KmLUM(double (*const pMo)[4], const double (*const pLUi)[4], double (*const pMi)[4]))[4]
    {
	    int	I0, I1, I2, I3;

	    KM_ASSERT((pMo != (double (*)[4]) pLUi) && (pMo != pMi), "KmLUM() doesn't work in-place");

	    I0 = (int) pLUi[4][0];
	    I1 = (int) pLUi[4][1];
	    I2 = (int) pLUi[4][2];
	    I3 = (int) pLUi[4][3];

	    pMi[0][I1] -= pLUi[0][I1] * pMi[0][I0];
	    pMi[0][I2] -= pLUi[0][I2] * pMi[0][I0];
	    pMi[0][I3] -= pLUi[0][I3] * pMi[0][I0];
	    pMi[0][I2] -= pLUi[1][I2] * pMi[0][I1];
	    pMi[0][I3] -= pLUi[1][I3] * pMi[0][I1];
	    pMi[0][I3] -= pLUi[2][I3] * pMi[0][I2];

	    pMo[0][3] = pMi[0][I3] / pLUi[3][I3];
	    pMo[0][2] = (pMi[0][I2] - pLUi[3][I2] * pMo[0][3]) / pLUi[2][I2];
	    pMo[0][1] = (pMi[0][I1] - pLUi[2][I1] * pMo[0][2] - pLUi[3][I1] * pMo[0][3]) / pLUi[1][I1];
	    pMo[0][0] = (pMi[0][I0] - pLUi[1][I0] * pMo[0][1] - pLUi[2][I0] * pMo[0][2] - pLUi[3][I0] * pMo[0][3]) / pLUi[0][I0];

	    pMi[1][I1] -= pLUi[0][I1] * pMi[1][I0];
	    pMi[1][I2] -= pLUi[0][I2] * pMi[1][I0];
	    pMi[1][I3] -= pLUi[0][I3] * pMi[1][I0];
	    pMi[1][I2] -= pLUi[1][I2] * pMi[1][I1];
	    pMi[1][I3] -= pLUi[1][I3] * pMi[1][I1];
	    pMi[1][I3] -= pLUi[2][I3] * pMi[1][I2];

	    pMo[1][3] = pMi[1][I3] / pLUi[3][I3];
	    pMo[1][2] = (pMi[1][I2] - pLUi[3][I2] * pMo[1][3]) / pLUi[2][I2];
	    pMo[1][1] = (pMi[1][I1] - pLUi[2][I1] * pMo[1][2] - pLUi[3][I1] * pMo[1][3]) / pLUi[1][I1];
	    pMo[1][0] = (pMi[1][I0] - pLUi[1][I0] * pMo[1][1] - pLUi[2][I0] * pMo[1][2] - pLUi[3][I0] * pMo[1][3]) / pLUi[0][I0];

	    pMi[2][I1] -= pLUi[0][I1] * pMi[2][I0];
	    pMi[2][I2] -= pLUi[0][I2] * pMi[2][I0];
	    pMi[2][I3] -= pLUi[0][I3] * pMi[2][I0];
	    pMi[2][I2] -= pLUi[1][I2] * pMi[2][I1];
	    pMi[2][I3] -= pLUi[1][I3] * pMi[2][I1];
	    pMi[2][I3] -= pLUi[2][I3] * pMi[2][I2];

	    pMo[2][3] = pMi[2][I3] / pLUi[3][I3];
	    pMo[2][2] = (pMi[2][I2] - pLUi[3][I2] * pMo[2][3]) / pLUi[2][I2];
	    pMo[2][1] = (pMi[2][I1] - pLUi[2][I1] * pMo[2][2] - pLUi[3][I1] * pMo[2][3]) / pLUi[1][I1];
	    pMo[2][0] = (pMi[2][I0] - pLUi[1][I0] * pMo[2][1] - pLUi[2][I0] * pMo[2][2] - pLUi[3][I0] * pMo[2][3]) / pLUi[0][I0];

	    pMi[3][I1] -= pLUi[0][I1] * pMi[3][I0];
	    pMi[3][I2] -= pLUi[0][I2] * pMi[3][I0];
	    pMi[3][I3] -= pLUi[0][I3] * pMi[3][I0];
	    pMi[3][I2] -= pLUi[1][I2] * pMi[3][I1];
	    pMi[3][I3] -= pLUi[1][I3] * pMi[3][I1];
	    pMi[3][I3] -= pLUi[2][I3] * pMi[3][I2];

	    pMo[3][3] = pMi[3][I3] / pLUi[3][I3];
	    pMo[3][2] = (pMi[3][I2] - pLUi[3][I2] * pMo[3][3]) / pLUi[2][I2];
	    pMo[3][1] = (pMi[3][I1] - pLUi[2][I1] * pMo[3][2] - pLUi[3][I1] * pMo[3][3]) / pLUi[1][I1];
	    pMo[3][0] = (pMi[3][I0] - pLUi[1][I0] * pMo[3][1] - pLUi[2][I0] * pMo[3][2] - pLUi[3][I0] * pMo[3][3]) / pLUi[0][I0];

	    return pMo;
    }

    /*
    *	KmMi : Matrix Inverse
    *
    *	INPUT
    *		pMi:	input matrix Mi
    *
    *	OUTPUT
    *		pMo:	output matrix Mo = Mi^-1
    *
    *	RETURN VALUE
    *		pMo
    *
    *	REMARKS
    *		- Works in-place
    */
    K_INLINE double (*KmMi(double (*const pMo)[4], KM_CONST double (*const pMi)[4]))[4]
    {
	    double	LU[5][4];
      
	    (void) KmMset(LU, (const double (*)[4]) pMi);
      
	    if(KmLU(LU)) {

		    double B[4][4];

		    (void) KmId(B);
		    (void) KmLUM(pMo, (const double (*)[4]) LU, B);

		    return pMo;
	    }

	    return NULL;
    }

    /*
    *	KmAi : Affine Matrix Inverse
    *
    *	INPUT
    *		pAi:	input matrix Ai
    *
    *	OUTPUT
    *		pAo:	output matrix Ao = Ai^-1
    *
    *	RETURN VALUE
    *		pAo
    *
    *	REMARKS
    *		- Works in-place
    *
    *	BUGS
    *		- Doesn't work in-place with 'assume no aliasing' MVC's optimization
    */
	#if defined(_MSC_VER) && (_MSC_VER < 1400)
		#pragma optimize("a", off)
    #endif

    K_INLINE double (*KmAi(
	    double (*const pAo)[4], 
	    KM_CONST double (*const pAi)[4]))[4]
    {
    #if 1
	    double A0, A1, A2;
        double S0, S1, S2;

	    A0 = pAi[0][0];
	    A1 = pAi[0][1];
	    A2 = pAi[0][2];
	    S0 = 1.0 / (A0 * A0 + A1 * A1 + A2 * A2);

	    A0 = pAi[1][0];
	    A1 = pAi[1][1];
	    A2 = pAi[1][2];
	    S1 = 1.0 / (A0 * A0 + A1 * A1 + A2 * A2);

	    A0 = pAi[2][0];
	    A1 = pAi[2][1];
	    A2 = pAi[2][2];
	    S2 = 1.0 / (A0 * A0 + A1 * A1 + A2 * A2);

	    A2 = pAi[1][0]; 

	    pAo[1][0] = S0 * pAi[0][1];
	    pAo[2][0] = S0 * pAi[0][2];
	    pAo[2][1] = S1 * pAi[1][2];

	    pAo[0][1] = S1 * A2;
	    pAo[0][2] = S2 * A0;
	    pAo[1][2] = S2 * A1;

        pAo[0][0] = S0 * pAi[0][0];
        pAo[1][1] = S1 * pAi[1][1];
        pAo[2][2] = S2 * pAi[2][2];

	    A0 = -pAi[3][0];
	    A1 = -pAi[3][1];
	    A2 = -pAi[3][2];

        pAo[3][2] = pAo[0][2] * A0 + pAo[1][2] * A1 + pAo[2][2] * A2;
        pAo[3][0] = pAo[0][0] * A0 + pAo[1][0] * A1 + pAo[2][0] * A2;
        pAo[3][1] = pAo[0][1] * A0 + pAo[1][1] * A1 + pAo[2][1] * A2;
    #else
	    // check this on MIPS
	    double A0, A1, A2, T0, T1, TX, TY, TZ, S;

	    T0 = pAi[1][0];
	    T1 = pAi[2][0];

	    TX = -pAi[3][0]; 
	    TY = -pAi[3][1];
	    TZ = -pAi[3][2];

	    A0 = pAi[0][0];
	    A1 = pAi[0][1];
	    A2 = pAi[0][2];
	    S = 1.0 / (A0 * A0 + A1 * A1 + A2 * A2);

	    A0 *= S;
	    A1 *= S;
	    A2 *= S;
        pAo[0][0] = A0;
	    pAo[1][0] = A1;
	    pAo[2][0] = A2;
        pAo[3][0] = A0 * TX + A1 * TY + A2 * TZ;

	    A0 = T0;
	    A1 = pAi[1][1];
	    A2 = pAi[1][2];
	    S = 1.0 / (A0 * A0 + A1 * A1 + A2 * A2);

	    T0 = pAi[2][1];

	    A0 *= S;
	    A1 *= S;
	    A2 *= S;
	    pAo[0][1] = A0;
        pAo[1][1] = A1;
	    pAo[2][1] = A2;
        pAo[3][1] = A0 * TX + A1 * TY + A2 * TZ;

	    A0 = T1;
	    A1 = T0;
	    A2 = pAi[2][2];
	    S = 1.0 / (A0 * A0 + A1 * A1 + A2 * A2);

	    A0 *= S;
	    A1 *= S;
	    A2 *= S;
	    pAo[0][2] = A0;
	    pAo[1][2] = A1;
        pAo[2][2] = A2;
        pAo[3][2] = A0 * TX + A1 * TY + A2 * TZ;
    #endif
	    return pAo;
    }
    #ifdef KARCH_DEV_MSC
    #pragma optimize("", on)
    #endif

    /*
    *	KmTi : Translation Matrix Inverse
    *
    *	INPUT
    *		pTi:	input matrix Ti
    *
    *	OUTPUT
    *		pTo:	output matrix To = Ti^-1
    *
    *	RETURN VALUE
    *		pTo
    *
    *	REMARKS
    *		- Works in-place
    */
    K_INLINE double (*KmTi(
	    double (*const pTo)[4], 
	    KM_CONST double (*const pTi)[4]))[4]
    {
	    pTo[3][0] = -pTi[3][0];
	    pTo[3][1] = -pTi[3][1];
	    pTo[3][2] = -pTi[3][2];

	    return pTo;
    }

    /*
    *	KmRi : Rotation Matrix Inverse
    *
    *	INPUT
    *		pRi:	input matrix Ri
    *
    *	OUTPUT
    *		pRo:	output matrix Ro = Ri^-1
    *
    *	RETURN VALUE
    *		pRo
    *
    *	REMARKS
    *		- Works in-place
    */
    K_INLINE double (*KmRi(
	    double (*const pRo)[4], 
	    KM_CONST double (*const pRi)[4]))[4]
    {
	    if(pRo == pRi) {

		    double	T;

		    kSwap(pRo[0][1], pRo[1][0], T);
		    kSwap(pRo[0][2], pRo[2][0], T);
		    kSwap(pRo[1][2], pRo[2][1], T);

	    } else {

		    pRo[0][0] = pRi[0][0];
		    pRo[0][1] = pRi[1][0];
		    pRo[0][2] = pRi[2][0];

		    pRo[1][0] = pRi[0][1];
		    pRo[1][1] = pRi[1][1];
		    pRo[1][2] = pRi[2][1];

		    pRo[2][0] = pRi[0][2];
		    pRo[2][1] = pRi[1][2];
		    pRo[2][2] = pRi[2][2];
	    }

	    return pRo;
    }

    /*
    *	KmSi : Scaling Matrix Inverse
    *
    *	INPUT
    *		pSi:	input matrix Si
    *
    *	OUTPUT
    *		pSo:	output matrix So = Si^-1
    *
    *	RETURN VALUE
    *		pSo
    *
    *	REMARKS
    *		- Works in-place
    */
    K_INLINE double (*KmSi(
	    double (*const pSo)[4], 
	    KM_CONST double (*const pSi)[4]))[4]
    {
	    pSo[0][0] = 1.0 / pSi[0][0];
	    pSo[1][1] = 1.0 / pSi[1][1];
	    pSo[2][2] = 1.0 / pSi[2][2];

	    return pSo;
    }

    /*
    *	KmMadd : Matrix Add
    *
    *	INPUT
    *		pMiA:	input matrix MiA
    *		pMiB:	input matrix MiB
    *
    *	OUTPUT
    *		pMo:	output matrix Mo = MiA + MiB
    *
    *	RETURN VALUE
    *		pMo
    *
    *	REMARKS
    *		- Works in-place
    */
    K_INLINE double (*KmMadd(
	    double (*const pMo)[4], 
	    KM_CONST double (*const pMiA)[4], KM_CONST double (*const pMiB)[4]))[4]
    {
	    pMo[0][0] = pMiA[0][0] + pMiB[0][0];
	    pMo[0][1] = pMiA[0][1] + pMiB[0][1];
	    pMo[0][2] = pMiA[0][2] + pMiB[0][2];
	    pMo[0][3] = pMiA[0][3] + pMiB[0][3];

	    pMo[1][0] = pMiA[1][0] + pMiB[1][0];
	    pMo[1][1] = pMiA[1][1] + pMiB[1][1];
	    pMo[1][2] = pMiA[1][2] + pMiB[1][2];
	    pMo[1][3] = pMiA[1][3] + pMiB[1][3];

	    pMo[2][0] = pMiA[2][0] + pMiB[2][0];
	    pMo[2][1] = pMiA[2][1] + pMiB[2][1];
	    pMo[2][2] = pMiA[2][2] + pMiB[2][2];
	    pMo[2][3] = pMiA[2][3] + pMiB[2][3];

	    pMo[3][0] = pMiA[3][0] + pMiB[3][0];
	    pMo[3][1] = pMiA[3][1] + pMiB[3][1];
	    pMo[3][2] = pMiA[3][2] + pMiB[3][2];
	    pMo[3][3] = pMiA[3][3] + pMiB[3][3];

	    return pMo;
    }

    /*
    *	KmMadd : Matrix Subtract
    *
    *	INPUT
    *		pMiA:	input matrix MiA
    *		pMiB:	input matrix MiB
    *
    *	OUTPUT
    *		pMo:	output matrix Mo = MiA - MiB
    *
    *	RETURN VALUE
    *		pMo
    *
    *	REMARKS
    *		- Works in-place
    */
    K_INLINE double (*KmMsub(
	    double (*const pMo)[4], 
	    KM_CONST double (*const pMiA)[4], KM_CONST double (*const pMiB)[4]))[4]
    {
	    pMo[0][0] = pMiA[0][0] - pMiB[0][0];
	    pMo[0][1] = pMiA[0][1] - pMiB[0][1];
	    pMo[0][2] = pMiA[0][2] - pMiB[0][2];
	    pMo[0][3] = pMiA[0][3] - pMiB[0][3];

	    pMo[1][0] = pMiA[1][0] - pMiB[1][0];
	    pMo[1][1] = pMiA[1][1] - pMiB[1][1];
	    pMo[1][2] = pMiA[1][2] - pMiB[1][2];
	    pMo[1][3] = pMiA[1][3] - pMiB[1][3];

	    pMo[2][0] = pMiA[2][0] - pMiB[2][0];
	    pMo[2][1] = pMiA[2][1] - pMiB[2][1];
	    pMo[2][2] = pMiA[2][2] - pMiB[2][2];
	    pMo[2][3] = pMiA[2][3] - pMiB[2][3];

	    pMo[3][0] = pMiA[3][0] - pMiB[3][0];
	    pMo[3][1] = pMiA[3][1] - pMiB[3][1];
	    pMo[3][2] = pMiA[3][2] - pMiB[3][2];
	    pMo[3][3] = pMiA[3][3] - pMiB[3][3];

	    return pMo;
    }

    /*
    *	KmMN : Matrix Scale
    *
    *	INPUT
    *		pMi:	input matrix Mi
    *		pNi:	input scalar Ni
    *
    *	OUTPUT
    *		pMo:	output matrix Mo = Mi * Ni
    *
    *	RETURN VALUE
    *		pMo
    *
    *	REMARKS
    *		- Works in-place
    */
    K_INLINE double (*KmMN(
	    double (*const pMo)[4], 
	    KM_CONST double (*const pMiA)[4], const double pNi))[4]
    {
	    pMo[0][0] = pMiA[0][0] * pNi;
	    pMo[0][1] = pMiA[0][1] * pNi;
	    pMo[0][2] = pMiA[0][2] * pNi;
	    pMo[0][3] = pMiA[0][3] * pNi;

	    pMo[1][0] = pMiA[1][0] * pNi;
	    pMo[1][1] = pMiA[1][1] * pNi;
	    pMo[1][2] = pMiA[1][2] * pNi;
	    pMo[1][3] = pMiA[1][3] * pNi;

	    pMo[2][0] = pMiA[2][0] * pNi;
	    pMo[2][1] = pMiA[2][1] * pNi;
	    pMo[2][2] = pMiA[2][2] * pNi;
	    pMo[2][3] = pMiA[2][3] * pNi;

	    pMo[3][0] = pMiA[3][0] * pNi;
	    pMo[3][1] = pMiA[3][1] * pNi;
	    pMo[3][2] = pMiA[3][2] * pNi;
	    pMo[3][3] = pMiA[3][3] * pNi;

	    return pMo;
    }

    /*
    *	KmMM : Matrix Product
    *
    *	INPUT
    *		pMiA:	input matrix MiA
    *		pMiB:	input matrix MiB
    *
    *	OUTPUT
    *		pMo:	output matrix Mo = MiA * MiB
    *
    *	RETURN VALUE
    *		pMo
    *
    *	REMARKS
    *		- Works in-place
    */
    K_INLINE double (*KmMM(
	    double (*const pMo)[4], 
	    KM_CONST double (*const pMiA)[4], KM_CONST double (*const pMiB)[4]))[4]
    {
	    double M0, M1, M2, M3;

	    if(pMo == pMiA) {

		    M0 = pMiA[0][0];
		    M1 = pMiA[1][0];
		    M2 = pMiA[2][0];
		    M3 = pMiA[3][0];

		    pMo[0][0] = pMiB[0][0] * M0 + pMiB[0][1] * M1 + pMiB[0][2] * M2 + pMiB[0][3] * M3;
		    pMo[1][0] = pMiB[1][0] * M0 + pMiB[1][1] * M1 + pMiB[1][2] * M2 + pMiB[1][3] * M3;
		    pMo[2][0] = pMiB[2][0] * M0 + pMiB[2][1] * M1 + pMiB[2][2] * M2 + pMiB[2][3] * M3;
		    pMo[3][0] = pMiB[3][0] * M0 + pMiB[3][1] * M1 + pMiB[3][2] * M2 + pMiB[3][3] * M3;

		    M0 = pMiA[0][1];
		    M1 = pMiA[1][1];
		    M2 = pMiA[2][1];
		    M3 = pMiA[3][1];

		    pMo[0][1] = pMiB[0][0] * M0 + pMiB[0][1] * M1 + pMiB[0][2] * M2 + pMiB[0][3] * M3;
		    pMo[1][1] = pMiB[1][0] * M0 + pMiB[1][1] * M1 + pMiB[1][2] * M2 + pMiB[1][3] * M3;
		    pMo[2][1] = pMiB[2][0] * M0 + pMiB[2][1] * M1 + pMiB[2][2] * M2 + pMiB[2][3] * M3;
		    pMo[3][1] = pMiB[3][0] * M0 + pMiB[3][1] * M1 + pMiB[3][2] * M2 + pMiB[3][3] * M3;

		    M0 = pMiA[0][2];
		    M1 = pMiA[1][2];
		    M2 = pMiA[2][2];
		    M3 = pMiA[3][2];

		    pMo[0][2] = pMiB[0][0] * M0 + pMiB[0][1] * M1 + pMiB[0][2] * M2 + pMiB[0][3] * M3;
		    pMo[1][2] = pMiB[1][0] * M0 + pMiB[1][1] * M1 + pMiB[1][2] * M2 + pMiB[1][3] * M3;
		    pMo[2][2] = pMiB[2][0] * M0 + pMiB[2][1] * M1 + pMiB[2][2] * M2 + pMiB[2][3] * M3;
		    pMo[3][2] = pMiB[3][0] * M0 + pMiB[3][1] * M1 + pMiB[3][2] * M2 + pMiB[3][3] * M3;

		    M0 = pMiA[0][3];
		    M1 = pMiA[1][3];
		    M2 = pMiA[2][3];
		    M3 = pMiA[3][3];

		    pMo[0][3] = pMiB[0][0] * M0 + pMiB[0][1] * M1 + pMiB[0][2] * M2 + pMiB[0][3] * M3;
		    pMo[1][3] = pMiB[1][0] * M0 + pMiB[1][1] * M1 + pMiB[1][2] * M2 + pMiB[1][3] * M3;
		    pMo[2][3] = pMiB[2][0] * M0 + pMiB[2][1] * M1 + pMiB[2][2] * M2 + pMiB[2][3] * M3;
		    pMo[3][3] = pMiB[3][0] * M0 + pMiB[3][1] * M1 + pMiB[3][2] * M2 + pMiB[3][3] * M3;

	    } else {

		    M0 = pMiB[0][0];
		    M1 = pMiB[0][1];
		    M2 = pMiB[0][2];
		    M3 = pMiB[0][3];

		    pMo[0][0] = pMiA[0][0] * M0 + pMiA[1][0] * M1 + pMiA[2][0] * M2 + pMiA[3][0] * M3;
		    pMo[0][1] = pMiA[0][1] * M0 + pMiA[1][1] * M1 + pMiA[2][1] * M2 + pMiA[3][1] * M3;
		    pMo[0][2] = pMiA[0][2] * M0 + pMiA[1][2] * M1 + pMiA[2][2] * M2 + pMiA[3][2] * M3;
		    pMo[0][3] = pMiA[0][3] * M0 + pMiA[1][3] * M1 + pMiA[2][3] * M2 + pMiA[3][3] * M3;
    								    					   
		    M0 = pMiB[1][0];
		    M1 = pMiB[1][1];
		    M2 = pMiB[1][2];
		    M3 = pMiB[1][3];

		    pMo[1][0] = pMiA[0][0] * M0 + pMiA[1][0] * M1 + pMiA[2][0] * M2 + pMiA[3][0] * M3;
		    pMo[1][1] = pMiA[0][1] * M0 + pMiA[1][1] * M1 + pMiA[2][1] * M2 + pMiA[3][1] * M3;
		    pMo[1][2] = pMiA[0][2] * M0 + pMiA[1][2] * M1 + pMiA[2][2] * M2 + pMiA[3][2] * M3;
		    pMo[1][3] = pMiA[0][3] * M0 + pMiA[1][3] * M1 + pMiA[2][3] * M2 + pMiA[3][3] * M3;
    							    					   
		    M0 = pMiB[2][0];
		    M1 = pMiB[2][1];
		    M2 = pMiB[2][2];
		    M3 = pMiB[2][3];

		    pMo[2][0] = pMiA[0][0] * M0 + pMiA[1][0] * M1 + pMiA[2][0] * M2 + pMiA[3][0] * M3;
		    pMo[2][1] = pMiA[0][1] * M0 + pMiA[1][1] * M1 + pMiA[2][1] * M2 + pMiA[3][1] * M3;
		    pMo[2][2] = pMiA[0][2] * M0 + pMiA[1][2] * M1 + pMiA[2][2] * M2 + pMiA[3][2] * M3;
		    pMo[2][3] = pMiA[0][3] * M0 + pMiA[1][3] * M1 + pMiA[2][3] * M2 + pMiA[3][3] * M3;
    																	 
		    M0 = pMiB[3][0];
		    M1 = pMiB[3][1];
		    M2 = pMiB[3][2];
		    M3 = pMiB[3][3];

		    pMo[3][0] = pMiA[0][0] * M0 + pMiA[1][0] * M1 + pMiA[2][0] * M2 + pMiA[3][0] * M3;
		    pMo[3][1] = pMiA[0][1] * M0 + pMiA[1][1] * M1 + pMiA[2][1] * M2 + pMiA[3][1] * M3;
		    pMo[3][2] = pMiA[0][2] * M0 + pMiA[1][2] * M1 + pMiA[2][2] * M2 + pMiA[3][2] * M3;
		    pMo[3][3] = pMiA[0][3] * M0 + pMiA[1][3] * M1 + pMiA[2][3] * M2 + pMiA[3][3] * M3;
	    }

	    return pMo;
    }

    /*
    *	KmAA : Affine Matrix Product
    *
    *	INPUT
    *		pAiA:	input matrix AiA
    *		pAiB:	input matrix AiB
    *
    *	OUTPUT
    *		pAo:	output matrix Ao = AiA * AiB
    *
    *	RETURN VALUE
    *		pAo
    *
    *	REMARKS
    *		- Works in-place
    */
    K_INLINE double (*KmAA(
	    double (*const pAo)[4], 
	    KM_CONST double (*const pAiA)[4], KM_CONST double (*const pAiB)[4]))[4]
    {
	    double A0, A1, A2;

	    if(pAo == pAiA) {

		    A0 = pAiA[0][0];
		    A1 = pAiA[1][0];
		    A2 = pAiA[2][0];

		    pAo[0][0] = pAiB[0][0] * A0 + pAiB[0][1] * A1 + pAiB[0][2] * A2;
		    pAo[1][0] = pAiB[1][0] * A0 + pAiB[1][1] * A1 + pAiB[1][2] * A2;
		    pAo[2][0] = pAiB[2][0] * A0 + pAiB[2][1] * A1 + pAiB[2][2] * A2;
		    pAo[3][0] = pAiB[3][0] * A0 + pAiB[3][1] * A1 + pAiB[3][2] * A2 + pAiA[3][0];

		    A0 = pAiA[0][1];
		    A1 = pAiA[1][1];
		    A2 = pAiA[2][1];

		    pAo[0][1] = pAiB[0][0] * A0 + pAiB[0][1] * A1 + pAiB[0][2] * A2;
		    pAo[1][1] = pAiB[1][0] * A0 + pAiB[1][1] * A1 + pAiB[1][2] * A2;
		    pAo[2][1] = pAiB[2][0] * A0 + pAiB[2][1] * A1 + pAiB[2][2] * A2;
		    pAo[3][1] = pAiB[3][0] * A0 + pAiB[3][1] * A1 + pAiB[3][2] * A2 + pAiA[3][1];

		    A0 = pAiA[0][2];
		    A1 = pAiA[1][2];
		    A2 = pAiA[2][2];

		    pAo[0][2] = pAiB[0][0] * A0 + pAiB[0][1] * A1 + pAiB[0][2] * A2;
		    pAo[1][2] = pAiB[1][0] * A0 + pAiB[1][1] * A1 + pAiB[1][2] * A2;
		    pAo[2][2] = pAiB[2][0] * A0 + pAiB[2][1] * A1 + pAiB[2][2] * A2;
		    pAo[3][2] = pAiB[3][0] * A0 + pAiB[3][1] * A1 + pAiB[3][2] * A2 + pAiA[3][2];

	    } else {

		    A0 = pAiB[0][0];
		    A1 = pAiB[0][1];
		    A2 = pAiB[0][2];

		    pAo[0][0] = pAiA[0][0] * A0 + pAiA[1][0] * A1 + pAiA[2][0] * A2;
		    pAo[0][1] = pAiA[0][1] * A0 + pAiA[1][1] * A1 + pAiA[2][1] * A2;
		    pAo[0][2] = pAiA[0][2] * A0 + pAiA[1][2] * A1 + pAiA[2][2] * A2;
    								    					   
		    A0 = pAiB[1][0];
		    A1 = pAiB[1][1];
		    A2 = pAiB[1][2];

		    pAo[1][0] = pAiA[0][0] * A0 + pAiA[1][0] * A1 + pAiA[2][0] * A2;
		    pAo[1][1] = pAiA[0][1] * A0 + pAiA[1][1] * A1 + pAiA[2][1] * A2;
		    pAo[1][2] = pAiA[0][2] * A0 + pAiA[1][2] * A1 + pAiA[2][2] * A2;
    							    					   
		    A0 = pAiB[2][0];
		    A1 = pAiB[2][1];
		    A2 = pAiB[2][2];

		    pAo[2][0] = pAiA[0][0] * A0 + pAiA[1][0] * A1 + pAiA[2][0] * A2;
		    pAo[2][1] = pAiA[0][1] * A0 + pAiA[1][1] * A1 + pAiA[2][1] * A2;
		    pAo[2][2] = pAiA[0][2] * A0 + pAiA[1][2] * A1 + pAiA[2][2] * A2;
    																	 
		    A0 = pAiB[3][0];
		    A1 = pAiB[3][1];
		    A2 = pAiB[3][2];

		    pAo[3][0] = pAiA[0][0] * A0 + pAiA[1][0] * A1 + pAiA[2][0] * A2 + pAiA[3][0];
		    pAo[3][1] = pAiA[0][1] * A0 + pAiA[1][1] * A1 + pAiA[2][1] * A2 + pAiA[3][1];
		    pAo[3][2] = pAiA[0][2] * A0 + pAiA[1][2] * A1 + pAiA[2][2] * A2 + pAiA[3][2];
	    }

	    return pAo;
    }

    /*
    *	KmTT : Translation Matrix Product
    *
    *	INPUT
    *		pTiA:	input matrix TiA
    *		pTiB:	input matrix TiB
    *
    *	OUTPUT
    *		pTo:	output matrix To = TiA * TiB
    *
    *	RETURN VALUE
    *		pTo
    *
    *	REMARKS
    *		- Works in-place
    */
    K_INLINE double (*KmTT(
	    double (*const pTo)[4], 
	    KM_CONST double (*const pTiA)[4], KM_CONST double (*const pTiB)[4]))[4]
    {
	    pTo[3][0] = pTiA[3][0] + pTiB[3][0];
	    pTo[3][1] = pTiA[3][1] + pTiB[3][1];
	    pTo[3][2] = pTiA[3][2] + pTiB[3][2];

	    return pTo;
    }

    /*
    *	KmRR : Rotation Matrix Product
    *
    *	INPUT
    *		pRiA:	input matrix RiA
    *		pRiB:	input matrix RiB
    *
    *	OUTPUT
    *		pRo:	output matrix Ro = RiA * RiB
    *
    *	RETURN VALUE
    *		pRo
    *
    *	REMARKS
    *		- Works in-place
    */
    K_INLINE double (*KmRR(
	    double (*const pRo)[4], 
	    KM_CONST double (*const pRiA)[4], KM_CONST double (*const pRiB)[4]))[4]
    {
	    double R0, R1, R2;

	    if(pRo == pRiA) {

		    R0 = pRiA[0][0];
		    R1 = pRiA[1][0];
		    R2 = pRiA[2][0];

		    pRo[0][0] = pRiB[0][0] * R0 + pRiB[0][1] * R1 + pRiB[0][2] * R2;
		    pRo[1][0] = pRiB[1][0] * R0 + pRiB[1][1] * R1 + pRiB[1][2] * R2;
		    pRo[2][0] = pRiB[2][0] * R0 + pRiB[2][1] * R1 + pRiB[2][2] * R2;

		    R0 = pRiA[0][1];
		    R1 = pRiA[1][1];
		    R2 = pRiA[2][1];

		    pRo[0][1] = pRiB[0][0] * R0 + pRiB[0][1] * R1 + pRiB[0][2] * R2;
		    pRo[1][1] = pRiB[1][0] * R0 + pRiB[1][1] * R1 + pRiB[1][2] * R2;
		    pRo[2][1] = pRiB[2][0] * R0 + pRiB[2][1] * R1 + pRiB[2][2] * R2;

		    R0 = pRiA[0][2];
		    R1 = pRiA[1][2];
		    R2 = pRiA[2][2];

		    pRo[0][2] = pRiB[0][0] * R0 + pRiB[0][1] * R1 + pRiB[0][2] * R2;
		    pRo[1][2] = pRiB[1][0] * R0 + pRiB[1][1] * R1 + pRiB[1][2] * R2;
		    pRo[2][2] = pRiB[2][0] * R0 + pRiB[2][1] * R1 + pRiB[2][2] * R2;

	    } else {

		    R0 = pRiB[0][0];
		    R1 = pRiB[0][1];
		    R2 = pRiB[0][2];

		    pRo[0][0] = pRiA[0][0] * R0 + pRiA[1][0] * R1 + pRiA[2][0] * R2;
		    pRo[0][1] = pRiA[0][1] * R0 + pRiA[1][1] * R1 + pRiA[2][1] * R2;
		    pRo[0][2] = pRiA[0][2] * R0 + pRiA[1][2] * R1 + pRiA[2][2] * R2;
    								    					   
		    R0 = pRiB[1][0];
		    R1 = pRiB[1][1];
		    R2 = pRiB[1][2];

		    pRo[1][0] = pRiA[0][0] * R0 + pRiA[1][0] * R1 + pRiA[2][0] * R2;
		    pRo[1][1] = pRiA[0][1] * R0 + pRiA[1][1] * R1 + pRiA[2][1] * R2;
		    pRo[1][2] = pRiA[0][2] * R0 + pRiA[1][2] * R1 + pRiA[2][2] * R2;
    							    					   
		    R0 = pRiB[2][0];
		    R1 = pRiB[2][1];
		    R2 = pRiB[2][2];

		    pRo[2][0] = pRiA[0][0] * R0 + pRiA[1][0] * R1 + pRiA[2][0] * R2;
		    pRo[2][1] = pRiA[0][1] * R0 + pRiA[1][1] * R1 + pRiA[2][1] * R2;
		    pRo[2][2] = pRiA[0][2] * R0 + pRiA[1][2] * R1 + pRiA[2][2] * R2;
	    }

	    return pRo;
    }

    /*
    *	KmSS : Scaling Matrix Product
    *
    *	INPUT
    *		pSiA:	input matrix SiA
    *		pSiB:	input matrix SiB
    *
    *	OUTPUT
    *		pSo:	output matrix So = SiA * SiB
    *
    *	RETURN VALUE
    *		pSo
    *
    *	REMARKS
    *		- Works in-place
    */
    K_INLINE double (*KmSS(
	    double (*const pSo)[4], 
	    KM_CONST double (*const pSiA)[4], 
	    KM_CONST double (*const pSiB)[4]))[4]
    {
	    pSo[0][0] = pSiA[0][0] * pSiB[0][0];
	    pSo[1][1] = pSiA[1][1] * pSiB[1][1];
	    pSo[2][2] = pSiA[2][2] * pSiB[2][2];

	    return pSo;
    }

    /*
    *	KmTR : T by R Matrix Product
    *
    *	INPUT
    *		pTi:	input matrix Ti
    *		pRi:	input matrix Ri
    *
    *	OUTPUT
    *		pAo:	output matrix Ao = Ti * Ri
    *
    *	RETURN VALUE
    *		pAo
    *
    *	REMARKS
    *		- Doesn't work in-place
    */
    K_INLINE double (*KmTR(
	    double (*const pAo)[4], 
	    const double (*const pTi)[4], const double (*const pRi)[4]))[4]
    {
	    KM_ASSERT((pAo != (double (*)[4]) pTi) && (pAo != (double (*)[4]) pRi), "KmTR() doesn't work in-place");

	    return KmTset(KmRset(pAo, pRi), pTi);
    }

    /*
    *	KmTRS : T by R by S Matrix Product
    *
    *	INPUT
    *		pTi:	input matrix Ti
    *		pRi:	input matrix Ri
    *		pSi:	input matrix Si
    *
    *	OUTPUT
    *		pAo:	output matrix Ao = Ti * Ri * Si
    *
    *	RETURN VALUE
    *		pAo
    *
    *	REMARKS
    *		- Doesn't work in-place
    */
    K_INLINE double (*KmTRS(
	    double (*const pAo)[4], 
	    const double (*const pTi)[4], 
	    const double (*const pRi)[4], 
	    const double (*const pSi)[4]))[4]
    {
	    double	T;

	    KM_ASSERT((pAo != (double (*)[4]) pTi) && (pAo != (double (*)[4]) pRi) && (pAo != (double (*)[4]) pSi), "KmTRS() doesn't work in-place");

	    (void) KmTset(pAo, pTi);

	    T = pSi[0][0];

	    pAo[0][0] = pRi[0][0] * T;
	    pAo[0][1] = pRi[0][1] * T;
	    pAo[0][2] = pRi[0][2] * T;

	    T = pSi[1][1];

	    pAo[1][0] = pRi[1][0] * T;
	    pAo[1][1] = pRi[1][1] * T;
	    pAo[1][2] = pRi[1][2] * T;

	    T = pSi[2][2];

	    pAo[2][0] = pRi[2][0] * T;
	    pAo[2][1] = pRi[2][1] * T;
	    pAo[2][2] = pRi[2][2] * T;

	    return pAo;
    }

    /*
    *	KmMiM : Matrix Inverse Product
    *
    *	INPUT
    *		pMiA:	input matrix MiA
    *		pMiB:	input matrix MiB
    *
    *	OUTPUT
    *		pMo:	output matrix Mo = MiA^-1 * MiB
    *
    *	RETURN VALUE
    *		pMo
    *
    *	REMARKS
    *		- Works in-place
    */
    K_INLINE double (*KmMiM(
	    double (*const pMo)[4], 
	    KM_CONST double (*const pMiA)[4], 
	    KM_CONST double (*const pMiB)[4]))[4]
    {
	    double	LU[5][4];
      
	    (void) KmMset(LU, (const double (*)[4]) pMiA);
      
	    if(KmLU(LU)) {

		    double B[4][4];

		    (void) KmMset(B, (const double (*)[4]) pMiB);
		    (void) KmLUM(pMo, (const double (*)[4]) LU, B);

		    return pMo;
	    }

	    return NULL;
    }

    /*
    *	KmAiA : Affine Matrix Inverse Product
    *
    *	INPUT
    *		pAiA:	input matrix AiA
    *		pAiB:	input matrix AiB
    *
    *	OUTPUT
    *		pAo:	output matrix Ao = AiA^-1 * AiB
    *
    *	RETURN VALUE
    *		pAo
    *
    *	REMARKS
    *		- Works in-place
    */
    K_INLINE double (*KmAiA(
	    double (*const pAo)[4], 
	    KM_CONST double (*const pAiA)[4], 
	    KM_CONST double (*const pAiB)[4]))[4]
    {
	    double T[4][4];
	    double A0, A1, A2;
        double S;

	    if(pAo == pAiB) {

		    (void) KmAi(T, pAiA);
		    (void) KmAA(pAo, T, pAiB);

	    } else if(pAo == pAiA) {

		    double T0, T1, T2, T3;

		    A0 = pAiA[0][0];
		    A1 = pAiA[0][1];
		    A2 = pAiA[0][2];
		    S = 1.0 / (A0 * A0 + A1 * A1 + A2 * A2);

		    A0 = S * pAiA[0][0];
		    A1 = S * pAiA[0][1];
		    A2 = S * pAiA[0][2];

		    T0 = pAiA[1][0];
		    T1 = pAiA[2][0];
		    T2 = pAiA[3][0];
		    T3 = pAiA[3][1];

		    pAo[0][0] = pAiB[0][0] * A0 + pAiB[0][1] * A1 + pAiB[0][2] * A2;
		    pAo[1][0] = pAiB[1][0] * A0 + pAiB[1][1] * A1 + pAiB[1][2] * A2;
		    pAo[2][0] = pAiB[2][0] * A0 + pAiB[2][1] * A1 + pAiB[2][2] * A2;
		    pAo[3][0] = pAiB[3][0] * A0 + pAiB[3][1] * A1 + pAiB[3][2] * A2 - (A0 * T2 + A1 * T3 + A2 * pAiA[3][2]);

		    A1 = pAiA[1][1];
		    A2 = pAiA[1][2];
		    S = 1.0 / (T0 * T0 + A1 * A1 + A2 * A2);

		    A0 = S * T0;
		    A1 *= S;
		    A2 *= S;

		    T0 = pAiA[2][1];

		    pAo[0][1] = pAiB[0][0] * A0 + pAiB[0][1] * A1 + pAiB[0][2] * A2;
		    pAo[1][1] = pAiB[1][0] * A0 + pAiB[1][1] * A1 + pAiB[1][2] * A2;
		    pAo[2][1] = pAiB[2][0] * A0 + pAiB[2][1] * A1 + pAiB[2][2] * A2;
		    pAo[3][1] = pAiB[3][0] * A0 + pAiB[3][1] * A1 + pAiB[3][2] * A2 - (A0 * T2 + A1 * T3 + A2 * pAiA[3][2]);

		    A2 = pAiA[2][2];
		    S = 1.0 / (T1 * T1 + T0 * T0 + A2 * A2);

		    A0 = S * T1;
		    A1 = S * T0;
		    A2 = S * A2;

		    pAo[0][2] = pAiB[0][0] * A0 + pAiB[0][1] * A1 + pAiB[0][2] * A2;
		    pAo[1][2] = pAiB[1][0] * A0 + pAiB[1][1] * A1 + pAiB[1][2] * A2;
		    pAo[2][2] = pAiB[2][0] * A0 + pAiB[2][1] * A1 + pAiB[2][2] * A2;
		    pAo[3][2] = pAiB[3][0] * A0 + pAiB[3][1] * A1 + pAiB[3][2] * A2 - (A0 * T2 + A1 * T3 + A2 * pAiA[3][2]);

	    } else {

		    double A0, A1, A2, T0, T1, T2, S;

		    T0 = pAiA[3][0];
		    T1 = pAiA[3][1];
		    T2 = pAiA[3][2];

		    A0 = pAiA[0][0];
		    A1 = pAiA[0][1];
		    A2 = pAiA[0][2];
		    S = 1.0 / (A0 * A0 + A1 * A1 + A2 * A2);

		    A0 *= S;
		    A1 *= S;
		    A2 *= S;

		    pAo[0][0] = pAiB[0][0] * A0 + pAiB[0][1] * A1 + pAiB[0][2] * A2;
		    pAo[1][0] = pAiB[1][0] * A0 + pAiB[1][1] * A1 + pAiB[1][2] * A2;
		    pAo[2][0] = pAiB[2][0] * A0 + pAiB[2][1] * A1 + pAiB[2][2] * A2;
		    pAo[3][0] = pAiB[3][0] * A0 + pAiB[3][1] * A1 + pAiB[3][2] * A2 - (A0 * T0 + A1 * T1 + A2 * T2);

		    A0 = pAiA[1][0];
		    A1 = pAiA[1][1];
		    A2 = pAiA[1][2];
		    S = 1.0 / (A0 * A0 + A1 * A1 + A2 * A2);

		    A0 *= S;
		    A1 *= S;
		    A2 *= S;

		    pAo[0][1] = pAiB[0][0] * A0 + pAiB[0][1] * A1 + pAiB[0][2] * A2;
		    pAo[1][1] = pAiB[1][0] * A0 + pAiB[1][1] * A1 + pAiB[1][2] * A2;
		    pAo[2][1] = pAiB[2][0] * A0 + pAiB[2][1] * A1 + pAiB[2][2] * A2;
		    pAo[3][1] = pAiB[3][0] * A0 + pAiB[3][1] * A1 + pAiB[3][2] * A2 - (A0 * T0 + A1 * T1 + A2 * T2);

		    A0 = pAiA[2][0];
		    A1 = pAiA[2][1];
		    A2 = pAiA[2][2];
		    S = 1.0 / (A0 * A0 + A1 * A1 + A2 * A2);

		    A0 *= S;
		    A1 *= S;
		    A2 *= S;

		    pAo[0][2] = pAiB[0][0] * A0 + pAiB[0][1] * A1 + pAiB[0][2] * A2;
		    pAo[1][2] = pAiB[1][0] * A0 + pAiB[1][1] * A1 + pAiB[1][2] * A2;
		    pAo[2][2] = pAiB[2][0] * A0 + pAiB[2][1] * A1 + pAiB[2][2] * A2;
		    pAo[3][2] = pAiB[3][0] * A0 + pAiB[3][1] * A1 + pAiB[3][2] * A2 - (A0 * T0 + A1 * T1 + A2 * T2);
	    }

	    return pAo;

    }

    /*
    *	KmTiT : Translation Matrix Inverse Product
    *
    *	INPUT
    *		pTiA:	input matrix TiA
    *		pTiB:	input matrix TiB
    *
    *	OUTPUT
    *		pTo:	output matrix To = TiA^-1 * TiB
    *
    *	RETURN VALUE
    *		pTo
    *
    *	REMARKS
    *		- Works in-place
    */
    K_INLINE double (*KmTiT(
	    double (*const pTo)[4], 
	    KM_CONST double (*const pTiA)[4], 
	    KM_CONST double (*const pTiB)[4]))[4]
    {
	    pTo[3][0] = pTiB[3][0] - pTiA[3][0];
	    pTo[3][1] = pTiB[3][1] - pTiA[3][1];
	    pTo[3][2] = pTiB[3][2] - pTiA[3][2];

	    return pTo;
    }

    /*
    *	KmRiR : Rotation Matrix Inverse Product
    *
    *	INPUT
    *		pRiA:	input matrix RiA
    *		pRiB:	input matrix RiB
    *
    *	OUTPUT
    *		pRo:	output matrix Ro = RiA^-1 * RiB
    *
    *	RETURN VALUE
    *		pRo
    *
    *	REMARKS
    *		- Works in-place
    */
    K_INLINE double (*KmRiR(
	    double (*const pRo)[4], 
	    KM_CONST double (*const pRiA)[4], 
	    KM_CONST double (*const pRiB)[4]))[4]
    {
	    double R0, R1, R2;

	    if(pRo == pRiA) {

		    double	T0, T1;

		    T0 = pRiA[0][2];
		    T1 = pRiA[1][2];

		    R0 = pRiA[2][0];
		    R1 = pRiA[2][1];
		    R2 = pRiA[2][2];

		    pRo[2][2] = R0 * pRiB[2][0] + R1 * pRiB[2][1] + R2 * pRiB[2][2];
		    pRo[1][2] = R0 * pRiB[1][0] + R1 * pRiB[1][1] + R2 * pRiB[1][2];
		    pRo[0][2] = R0 * pRiB[0][0] + R1 * pRiB[0][1] + R2 * pRiB[0][2];

		    R0 = pRiA[1][0];
		    R1 = pRiA[0][1];
		    R2 = pRiA[1][1];

		    pRo[2][1] = R0 * pRiB[2][0] + R2 * pRiB[2][1] + T1 * pRiB[2][2];
		    pRo[1][1] = R0 * pRiB[1][0] + R2 * pRiB[1][1] + T1 * pRiB[1][2];
		    pRo[0][1] = R0 * pRiB[0][0] + R2 * pRiB[0][1] + T1 * pRiB[0][2];

		    R0 = pRiA[0][0];

		    pRo[2][0] = R0 * pRiB[2][0] + R1 * pRiB[2][1] + T0 * pRiB[2][2];
		    pRo[1][0] = R0 * pRiB[1][0] + R1 * pRiB[1][1] + T0 * pRiB[1][2];
		    pRo[0][0] = R0 * pRiB[0][0] + R1 * pRiB[0][1] + T0 * pRiB[0][2];

	    } else {

		    R0 = pRiB[0][0];
		    R1 = pRiB[0][1];
		    R2 = pRiB[0][2];

		    pRo[0][0] = pRiA[0][0] * R0 + pRiA[0][1] * R1 + pRiA[0][2] * R2;
		    pRo[0][1] = pRiA[1][0] * R0 + pRiA[1][1] * R1 + pRiA[1][2] * R2;
		    pRo[0][2] = pRiA[2][0] * R0 + pRiA[2][1] * R1 + pRiA[2][2] * R2;
    								    					   
		    R0 = pRiB[1][0];
		    R1 = pRiB[1][1];
		    R2 = pRiB[1][2];

		    pRo[1][0] = pRiA[0][0] * R0 + pRiA[0][1] * R1 + pRiA[0][2] * R2;
		    pRo[1][1] = pRiA[1][0] * R0 + pRiA[1][1] * R1 + pRiA[1][2] * R2;
		    pRo[1][2] = pRiA[2][0] * R0 + pRiA[2][1] * R1 + pRiA[2][2] * R2;
    							    					   
		    R0 = pRiB[2][0];
		    R1 = pRiB[2][1];
		    R2 = pRiB[2][2];

		    pRo[2][0] = pRiA[0][0] * R0 + pRiA[0][1] * R1 + pRiA[0][2] * R2;
		    pRo[2][1] = pRiA[1][0] * R0 + pRiA[1][1] * R1 + pRiA[1][2] * R2;
		    pRo[2][2] = pRiA[2][0] * R0 + pRiA[2][1] * R1 + pRiA[2][2] * R2;
	    }
	    return pRo;
    }

    /*
    *	KmSiS : Scaling Matrix Inverse Product
    *
    *	INPUT
    *		pSiA:	input matrix SiA
    *		pSiB:	input matrix SiB
    *
    *	OUTPUT
    *		pSo:	output matrix So = SiA^-1 * SiB
    *
    *	RETURN VALUE
    *		pSo
    *
    *	REMARKS
    *		- Works in-place
    */
    K_INLINE double (*KmSiS(
	    double (*const pSo)[4], 
	    KM_CONST double (*const pSiA)[4],
	    KM_CONST double (*const pSiB)[4]))[4]
    {
	    pSo[0][0] = pSiB[0][0] / pSiA[0][0];
	    pSo[1][1] = pSiB[1][1] / pSiA[1][1];
	    pSo[2][2] = pSiB[2][2] / pSiA[2][2];

	    return pSo;
    }

    ////////////////////////////////////////////////////////////////////////////////
    //
    //	Matrix To Vector Decompositions
    //
    ////////////////////////////////////////////////////////////////////////////////

    /*
    *	KmTtoV : Translation Matrix To Vector
    *
    *	INPUT
    *		pTi:	input matrix Ti
    *
    *	OUTPUT
    *		pVo:	output vector Vo = T(Ti)
    *
    *	RETURN VALUE
    *		pTo
    */
    K_INLINE double *KmTtoV(double *const pVo, const double (*const pTi)[4])
    {
	    pVo[0] = pTi[3][0];
	    pVo[1] = pTi[3][1];
	    pVo[2] = pTi[3][2];

	    return pVo;
    }

    /*
    *	KmRtoVXYZ : Rotation Matrix to XYZ Euler Vector
    *
    *	INPUT
    *		pRi:	input matrix Ri
    *
    *	OUTPUT
    *		pVo:	output vector Vo = RXYZ(Ri)
    *
    *	RETURN VALUE
    *		pVo
    *
    *	REMARKS
    *		- Rotations are post-multiplied
    */
    K_INLINE double *KmRtoVXYZ(double *const pVo, const double (*const pRi)[4])
    {    
	    if(pRi[0][2] >= 1.0 - KM_TOLERANCE) {
		    pVo[0] = kAtand(-pRi[2][1], -pRi[2][0]);
		    pVo[1] = -90;
		    pVo[2] = 0;
	    } else if(pRi[0][2] <= KM_TOLERANCE - 1.0) {
		    pVo[0] = kAtand(pRi[1][0], pRi[1][1]);
		    pVo[1] = 90;
		    pVo[2] = 0;
	    } else {
		    pVo[0] = kAtand(pRi[1][2], pRi[2][2]);
		    pVo[1] = -kAsind(pRi[0][2]);
		    pVo[2] = kAtand(pRi[0][1], pRi[0][0]);
	    }
	    return pVo;
    }

    /*
    *	KmRtoVZYX : Rotation Matrix To ZYX Euler Vector
    *
    *	INPUT
    *		pRi:	input matrix Ri
    *
    *	OUTPUT
    *		pVo:	output vector Vo = RZYX(Ri)
    *
    *	RETURN VALUE
    *		pVo
    *
    *	REMARKS
    *		- Rotations are post-multiplied
    */
    K_INLINE double *KmRtoVZYX(double *const pVo, const double (*const pRi)[4])
    {
	    if(pRi[2][0] >= 1.0 - KM_TOLERANCE) {
		    pVo[2] = kAtand(pRi[1][2], -pRi[0][2]);
		    pVo[1] = 90.0;
		    pVo[0] = 0.0;
	    } else if(pRi[2][0] <= KM_TOLERANCE - 1.0) {
		    pVo[2] = kAtand(-pRi[0][1], pRi[1][1]);
		    pVo[1] = -90.0;
		    pVo[0] = 0.0;
	    } else {
		    pVo[2] = kAtand(-pRi[2][1], pRi[2][2]);
		    pVo[1] = kAsind(pRi[2][0]);
		    pVo[0] = kAtand(-pRi[1][0], pRi[0][0]);
	    }
	    return pVo;
    }

    /*
    *	KmRtoVord : Rotation Matrix To Ordered Euler Vector
    *
    *	INPUT
    *		pRi:	input matrix Ri
    *		pOrd:	order (Ord) of rotations
    *
    *	OUTPUT
    *		pVo:	output vector Vo = R(Ri, Ord)
    *
    *	RETURN VALUE
    *		pVo
    *
    *	REMARKS
    *		- Rotations are post-multiplied
    */
    K_INLINE double *KmRtoVord(double *const pVo, const double (*const pRi)[4], const int pOrd)
    {
        int	I, J, K;
	    double T;

	    I = KmEulerAxis[pOrd][0];
	    J = KmEulerAxis[pOrd][1];
	    K = KmEulerAxis[pOrd][2];

        if(pOrd & KM_EULER_REPEAT_YES) {

		    T = kHypot(pRi[J][I], pRi[K][I]);
		    if(T > 16.0 * KM_EPSILON) {
			    pVo[0] = kAtand(pRi[J][I], pRi[K][I]);
			    pVo[1] = kAtand(T, pRi[I][I]);
			    pVo[2] = kAtand(pRi[I][J], -pRi[I][K]);
		    } else {
			    pVo[0] = kAtand(-pRi[K][J], pRi[J][J]);
			    pVo[1] = kAtand(T, pRi[I][I]);
			    pVo[2] = 0.0;
		    }

        } else {

		    T = kHypot(pRi[I][I], pRi[I][J]);
		    if(T > 16.0 * KM_EPSILON) {
			    pVo[0] = kAtand(pRi[J][K], pRi[K][K]);
			    pVo[1] = kAtand(-pRi[I][K], T);
			    pVo[2] = kAtand(pRi[I][J], pRi[I][I]);
		    } else {
			    pVo[0] = kAtand(-pRi[K][J], pRi[J][J]);
			    pVo[1] = kAtand(-pRi[I][K], T);
			    pVo[2] = 0.0;
		    }
        }

        if(pOrd & KM_EULER_PARITY_ODD) {
		    (void) KmVneg(pVo, pVo);
	    }

        return pVo;
    }

    /*
    *	KmRtoV : Default Order Rotation Matrix To Euler Vector
    *
    *	INPUT
    *		pRi:	input matrix Ri
    *
    *	OUTPUT
    *		pVo:	output vector Vo = RXYZ(Ri)
    *
    *	RETURN VALUE
    *		pVo
    *
    *	REMARKS
    *		- Rotations are post-multiplied
    */
    K_INLINE double *KmRtoV(double *const pVo, const double (*const pRi)[4])
    {
	    return KmRtoVXYZ(pVo, pRi);
    }

    /*
    *	KmIsRightHand: Affine Matrix To Vector
    *
    *	INPUT
    *		pAi:	input matrix Ai
    *
    *	OUTPUT
    *		pBool:	if Matrix if right hand
    */
    K_INLINE bool KmIsRightHand(const double (*pAi)[4])
    {
    double VectorialProduct[4];

	    KmVV(VectorialProduct,pAi[0],pAi[1]);
	    return (KmVdotV(VectorialProduct,pAi[2])>=0); 
    }

    /*
    *	KmAtoV : Affine Matrix To Vector
    *
    *	INPUT
    *		pAi:	input matrix Ai
    *
    *	OUTPUT
    *		pTo:	output vector To = T(Ai)
    *		pRo:	output vector Ro = R(Ai)
    *		pSo:	output vector So = S(Ai)
    */
    K_INLINE void KmAtoV(double *pTo, double *pRo, double *pSo, const double (*pAi)[4])
    {
	    double A[4][4];
    	
	    KmAset(A, pAi);

	    if (KmIsRightHand(A)) {
		    pSo[0] = KmVlength(A[0]);
		    pSo[1] = KmVlength(A[1]);
		    pSo[2] = KmVlength(A[2]);
	    } else {
		    pSo[0] = -KmVlength(A[0]);
		    pSo[1] = -KmVlength(A[1]);
		    pSo[2] = -KmVlength(A[2]);
	    }

	    KM_ASSERT(pSo[0] * pSo[1] * pSo[2] != 0.0, "Zero scaling factor found in KmAtoV()");

	    KmVN(A[0], A[0], 1.0 / pSo[0]);
	    KmVN(A[1], A[1], 1.0 / pSo[1]);
	    KmVN(A[2], A[2], 1.0 / pSo[2]);

	    (void) KmRtoV(pRo, (const double (*)[4]) A);

	    pTo[0] = A[3][0];
	    pTo[1] = A[3][1];
	    pTo[2] = A[3][2];
    }

    /*
    *	KmAtoVord : Affine Matrix To Ordered Vector
    *
    *	INPUT
    *		pAi:	input matrix Ai
    *		pOrd:	rotation order
    *
    *	OUTPUT
    *		pTo:	output vector To = T(Ti)
    *		pRo:	output vector Ro = R(Ai)
    *		pSo:	output vector So = S(Ti)
    */
    K_INLINE void KmAtoVord(double *pTo, double *pRo, double *pSo, const double (*pAi)[4], const int pOrd)
    {
	    double A[4][4];
    	
	    KmAset(A, pAi);

	    if (KmIsRightHand(A)) {
		    pSo[0] = KmVlength(A[0]);
		    pSo[1] = KmVlength(A[1]);
		    pSo[2] = KmVlength(A[2]);
	    } else {
		    pSo[0] = -KmVlength(A[0]);
		    pSo[1] = -KmVlength(A[1]);
		    pSo[2] = -KmVlength(A[2]);
	    }

	    KM_ASSERT(pSo[0] * pSo[1] * pSo[2] != 0.0, "Zero scaling factor found in KmAtoV()");

	    KmVN(A[0], A[0], 1.0 / pSo[0]);
	    KmVN(A[1], A[1], 1.0 / pSo[1]);
	    KmVN(A[2], A[2], 1.0 / pSo[2]);

	    (void) KmRtoVord(pRo, (const double (*)[4]) A, pOrd);

	    pTo[0] = A[3][0];
	    pTo[1] = A[3][1];
	    pTo[2] = A[3][2];
    }

    /*
    *	KmAtoVT : Affine Matrix To Translation Vector
    *
    *	INPUT
    *		pAi:	input matrix Ai
    *
    *	OUTPUT
    *		pTo:	output vector To = T(Ai)
    */
    K_INLINE double *KmAtoVT(double *pTo, const double (*pAi)[4])
    {
	    pTo[0] = pAi[3][0];
	    pTo[1] = pAi[3][1];
	    pTo[2] = pAi[3][2];

	    return pTo;
    }

    /*
    *	KmAtoVR : Affine Matrix To Rotation Vector
    *
    *	INPUT
    *		pAi:	input matrix Ai
    *
    *	OUTPUT
    *		pRo:	output vector Ro = R(Ai)
    */
    K_INLINE double *KmAtoVR(double *pRo, const double (*pAi)[4])
    {
	    double A[4][4];
	    double	S0, S1, S2;
    	
	    (void) KmAset(A, pAi);

	    if (KmIsRightHand(A)) {
		    S0 = KmVlength(A[0]);
		    S1 = KmVlength(A[1]);
		    S2 = KmVlength(A[2]);
	    } else {
		    S0 = -KmVlength(A[0]);
		    S1 = -KmVlength(A[1]);
		    S2 = -KmVlength(A[2]);
	    }

	    KM_ASSERT(S0 * S1 * S2 != 0.0, "Zero scaling factor found in KmAtoVR()");

	    (void) KmVN(A[0], A[0], 1.0 / S0);
	    (void) KmVN(A[1], A[1], 1.0 / S1);
	    (void) KmVN(A[2], A[2], 1.0 / S2);

	    return KmRtoV(pRo, (const double (*)[4]) A);
    }

    /*
    *	KmAtoVRord : Affine Matrix To Ordered Rotation Vector
    *
    *	INPUT
    *		pAi:	input matrix Ai
    *		pOrd:	rotation order
    *
    *	OUTPUT
    *		pRo:	output vector Ro = R(Ai)
    */
    K_INLINE double *KmAtoVRord(double *pRo, const double (*pAi)[4], const int pOrd)
    {
	    double A[4][4];
	    double	S0, S1, S2;
    	
	    KmAset(A, pAi);

	    if (KmIsRightHand(A)) {
		    S0 = KmVlength(A[0]);
		    S1 = KmVlength(A[1]);
		    S2 = KmVlength(A[2]);
	    } else {
		    S0 = -KmVlength(A[0]);
		    S1 = -KmVlength(A[1]);
		    S2 = -KmVlength(A[2]);
	    }

	    KM_ASSERT(S0 * S1 * S2 != 0.0, "Zero scaling factor found in KmAtoVRord()");

	    KmVN(A[0], A[0], 1.0 / S0);
	    KmVN(A[1], A[1], 1.0 / S1);
	    KmVN(A[2], A[2], 1.0 / S2);

	    return KmRtoVord(pRo, (const double (*)[4]) A, pOrd);
    }

    /*
    *	KmAtoVS : Affine Matrix To Scaling Vector
    *
    *	INPUT
    *		pAi:	input matrix Ai
    *
    *	OUTPUT
    *		pSo:	output vector So = S(Ai)
    */
    K_INLINE double *KmAtoVS(double *pSo, const double (*pAi)[4])
    {
	    if (KmIsRightHand(pAi)) {
		    pSo[0] = KmVlength(pAi[0]);
		    pSo[1] = KmVlength(pAi[1]);
		    pSo[2] = KmVlength(pAi[2]);
	    } else {
		    pSo[0] = -KmVlength(pAi[0]);
		    pSo[1] = -KmVlength(pAi[1]);
		    pSo[2] = -KmVlength(pAi[2]);
	    }

	    KM_ASSERT(pSo[0] * pSo[1] * pSo[2] != 0.0, "Zero scaling factor found in KmAtoVS()");

	    return pSo;
    }

    ////////////////////////////////////////////////////////////////////////////////
    //
    //	Matrix Compositions
    //
    ////////////////////////////////////////////////////////////////////////////////

    /*
    *	KmXYZtoT : Scalar To Translation Matrix
    *
    *	INPUT
    *		pX:		input value X
    *		pY:		input value Y
    *		pZ:		input value Z
    *
    *	OUTPUT
    *		pTo:	output matrix To = T(X, Y, Z)
    *
    *	RETURN VALUE
    *		pTo
    */
    K_INLINE double (*KmXYZtoT(double (*const pTo)[4], const double pX, const double pY, const double pZ))[4]
    {
	    pTo[3][0] = pX;
	    pTo[3][1] = pY;
	    pTo[3][2] = pZ;

	    return pTo;
    }

    /*
    *	KmVtoT : Vector To Translation Matrix
    *
    *	INPUT
    *		pVi:	input vector Vi
    *
    *	OUTPUT
    *		pTo:	output matrix To = T(Vi)
    *
    *	RETURN VALUE
    *		pTo
    */
    K_INLINE double (*KmVtoT(double (*const pTo)[4], const double *const pVi))[4]
    {
	    return KmXYZtoT(pTo, pVi[0], pVi[1], pVi[2]);
    }

    /*
    *	KmDtoR : Direction Vector To Rotation Matrix
    *
    *	INPUT
    *		pDi:	input direction vector Vi
    *		pRoll:	optional roll angle
    *
    *	OUTPUT
    *		pRo:	output matrix Ro = R(Vi)
    *
    *	RETURN VALUE
    *		pRo
    */
    K_INLINE double (*KmDtoR(double (*const pRo)[4], const double *const pDi, K_DEFAULT(double pRoll, 0.0)))[4]
    {
	    double CY, CZ, SZ, T, X, Y, Z;

	    T = KmVlength(pDi);

	    KM_ASSERT(T != 0.0, "Null vector as direction");

	    T = 1.0 / T;

	    X = pDi[0] * T;
	    Y = pDi[1] * T;
	    Z = pDi[2] * T;

	    T = X * X + Y * Y;
	    if(T != 0.0) {
		    T = kRsqrt(T);
		    CZ = X * T;
		    SZ = Y * T;
	    } else {
		    CZ = 1.0;
		    SZ = 0.0;
	    }

	    CY = kSqrt(1.0 - Z * Z);

	    if(pRoll != 0.0) {

		    double CX, SX;

		    SX = kSinCosd(pRoll, &CX);

		    pRo[0][0] = X;
		    pRo[0][1] = Y;
		    pRo[0][2] = Z;
		    pRo[1][0] = -SZ * CX - CZ * Z * SX;
		    pRo[1][1] = CZ * CX - SZ * Z * SX;
		    pRo[1][2] = CY * SX;
		    pRo[2][0] = SZ * SX - CZ * Z;
		    pRo[2][1] = -CZ * SX - SZ * Z;
		    pRo[2][2] = CY * CX;

	    } else {

		    pRo[0][0] = X;
		    pRo[0][1] = Y;
		    pRo[0][2] = Z;
		    pRo[1][0] = -SZ;
		    pRo[1][1] = CZ;
		    pRo[1][2] = 0.0;
		    pRo[2][0] = -CZ * Z;
		    pRo[2][1] = -SZ * Z;
		    pRo[2][2] = CY;
	    }

	    return pRo;
    }

    /*
    *	KmRtoD : Rotation Matrix To Direction Vector
    *
    *	INPUT
    *		pRi:	input direction vector Ri
    *		pLength: length of output vector
    *
    *	OUTPUT
    *		pDo:	output vector Do = D(Ri)
    *
    *	RETURN VALUE
    *		pDo
    */
    K_INLINE double *KmRtoD(double *const pDo, const double (*const pRi)[4], K_DEFAULT(const double pLength, 1.0))
    {
	    pDo[0] = pRi[0][0] * pLength;
	    pDo[1] = pRi[0][1] * pLength;
	    pDo[2] = pRi[0][2] * pLength;

	    return pDo;
    }

    /*
    *	KmRunroll : Euler Angle Un-Roller
    *
    *	INPUT
    *		pVi:	input angle vector
    *		pRi:	reference angle vector
    *
    *	OUTPUT
    *		pVo:	output vector Vo
    *
    *	RETURN VALUE
    *		pVo
    *
    *	REMARKS
    *		- Find nearest angle representation to reference vector
    */
    K_INLINE double *KmRunroll(
	    double *const pVo, 
	    KM_CONST double *const pVi, 
	    const double *const pRi)
    {
	    double U0, U1, U2, V0, V1, V2;

	    U0 = V0 = pVi[0];
	    U1 = V1 = pVi[1];
	    U2 = V2 = pVi[2];

	    U0 += 360.0 * floor((pRi[0] - V0) / 360.0 + 0.5);
	    U1 += 360.0 * floor((pRi[1] - V1) / 360.0 + 0.5);
	    U2 += 360.0 * floor((pRi[2] - V2) / 360.0 + 0.5);

	    V0 += 360.0 * floor((pRi[0] - V0 - 180.0) / 360.0 + 0.5) + 180.0;
	    V1 = 360.0 * floor((pRi[1] + V1 - 180.0) / 360.0 + 0.5) + 180.0 - V1;
	    V2 += 360.0 * floor((pRi[2] - V0 - 180.0) / 360.0 + 0.5) + 180.0;

	    if(kAbs(pRi[0] - U0) + kAbs(pRi[1] - U1) + kAbs(pRi[2] - U2) < kAbs(pRi[0] - V0) + kAbs(pRi[1] - V1) + kAbs(pRi[2] - V2)) {
		    pVo[0] = U0;
		    pVo[1] = U1;
		    pVo[2] = U2;
	    } else {
		    pVo[0] = V0;
		    pVo[1] = V1;
		    pVo[2] = V2;
	    }
    	
	    return pVo;
    }

    /*
    *	KmXYZtoR : XYZ Euler Angles To Rotation Matrix
    *
    *	INPUT
    *		pX:		input angle X
    *		pY:		input angle Y
    *		pZ:		input angle Z
    *
    *	OUTPUT
    *		pRo:	output matrix Ro = RXYZ(X, Y, Z)
    *
    *	RETURN VALUE
    *		pRo
    *
    *	REMARKS
    *		- Rotations are post-multiplied
    */
    K_INLINE double (*KmXYZtoR(double (*const pRo)[4], double pX, double pY, double pZ))[4]
    {
	    double SX, CX, SY, CY, SZ, CZ;
	    double SYSX, SYCX;	

        SX = kSinCosd(pX, &CX);
        SY = kSinCosd(pY, &CY);
        SZ = kSinCosd(pZ, &CZ);

	    SYSX = SY * SX;
	    SYCX = SY * CX;

	    pRo[0][0] = CZ * CY;
	    pRo[0][1] = SZ * CY;
	    pRo[0][2] = -SY;

	    pRo[1][0] = -SZ * CX + CZ * SYSX;
	    pRo[1][1] = CZ * CX + SZ * SYSX;
	    pRo[1][2] = CY * SX;

	    pRo[2][0] = SZ * SX + CZ * SYCX;
	    pRo[2][1] = -CZ * SX + SZ * SYCX;
	    pRo[2][2] = CY * CX;

	    return pRo;
    }
     
    /*
    *	KmYZXtoR : YZX Euler Angles To Rotation Matrix
    *
    *	INPUT
    *		pY:		input angle pY
    *		pZ:		input angle pZ
    *		pX:		input angle pX
    *
    *	OUTPUT
    *		pRo:	output matrix Ro = RYZX(Y, Z, X)
    *
    *	RETURN VALUE
    *		pRo
    */
    K_INLINE double (*KmYZXtoR(double (*const pRo)[4], double pY, double pZ, double pX))[4]
    {
	    double SX, CX, SY, CY, SZ, CZ;

        SX = kSinCosd(pX, &CX);
        SY = kSinCosd(pY, &CY);
        SZ = kSinCosd(pZ, &CZ);

	    pRo[0][0] = CZ * CY;
	    pRo[0][1] = SZ * CY * CX + SY * SX;
	    pRo[0][2] = CY * SX * SZ - SY * CX;

	    pRo[1][0] = -SZ;
	    pRo[1][1] = CZ * CX;
	    pRo[1][2] = CZ * SX;

	    pRo[2][0] = CZ * SY;
	    pRo[2][1] = SZ * SY * CX - CY * SX;
	    pRo[2][2] = SZ * SY * SX + CY * CX;

	    return pRo;
    }

    /*
    *	KmZXYtoR : ZXY Euler Angles To Rotation Matrix
    *
    *	INPUT
    *		pZ:		input angle Z
    *		pX:		input angle X
    *		pY:		input angle Y
    *
    *	OUTPUT
    *		pRo:	output matrix Ro = RZXY(Z, X, Y)
    *
    *	RETURN VALUE
    *		pRo
    *
    *	REMARKS
    *		- Rotations are post-multiplied
    */
    K_INLINE double (*KmZXYtoR(double (*const pRo)[4], double pZ, double pX, double pY))[4]
    {
	    double SX, CX, SY, CY, SZ, CZ;

        SX = kSinCosd(pX, &CX);
        SY = kSinCosd(pY, &CY);
        SZ = kSinCosd(pZ, &CZ);

	    pRo[0][0] = CZ * CY + SZ * SY * SX;
	    pRo[0][1] = SZ * CX;
	    pRo[0][2] = -CZ * SY + CY * SX * SZ;

	    pRo[1][0] = -SZ * CY + CZ * SY * SX;
	    pRo[1][1] = CZ * CX;
	    pRo[1][2] = SZ * SY + CY * SX * CZ;

	    pRo[2][0] = SY * CX;
	    pRo[2][1] = -SX;
	    pRo[2][2] = CY * CX;

	    return pRo;
    }

    /*
    *	KmXZYtoR : XZY Euler Angles To Rotation Matrix
    *
    *	INPUT
    *		pX:		input angle X
    *		pZ:		input angle Z
    *		pY:		input angle Y
    *
    *	OUTPUT
    *		pRo:	output matrix Ro = RXZY(X, Z, Y)
    *
    *	RETURN VALUE
    *		pRo
    *
    *	REMARKS
    *		- Rotations are post-multiplied
    */
    K_INLINE double (*KmXZYtoR(double (*const pRo)[4], double pX, double pZ, double pY))[4]
    {
	    double SX, CX, SY, CY, SZ, CZ;

        SX = kSinCosd(pX, &CX);
        SY = kSinCosd(pY, &CY);
        SZ = kSinCosd(pZ, &CZ);

	    pRo[0][0] = CZ * CY;
	    pRo[0][1] = SZ;
	    pRo[0][2] = -CZ * SY;

	    pRo[1][0] = -SZ * CY * CX + SY * SX;
	    pRo[1][1] = CZ * CX;
	    pRo[1][2] = SZ * SY * CX + CY * SX;

	    pRo[2][0] = CY * SX * SZ + SY * CX;
	    pRo[2][1] = -CZ * SX;
	    pRo[2][2] = -SZ * SY * SX + CY * CX;

	    return pRo;
    }
     
    /*
    *	KmYXZtoR : YXZ Euler Angles To Rotation Matrix
    *
    *	INPUT
    *		pY:		input angle Y
    *		pX:		input angle X
    *		pZ:		input angle Z
    *
    *	OUTPUT
    *		pRo:	output matrix Ro = RYXZ(Y, X, Z)
    *
    *	RETURN VALUE
    *		pRo
    *
    *	REMARKS
    *		- Rotations are post-multiplied
    */
    K_INLINE double (*KmYXZtoR(double (*const pRo)[4], double pY, double pX, double pZ))[4]
    {
	    double SX, CX, SY, CY, SZ, CZ;

        SX = kSinCosd(pX, &CX);
        SY = kSinCosd(pY, &CY);
        SZ = kSinCosd(pZ, &CZ);

	    pRo[0][0] = CZ * CY - SZ * SY * SX;
	    pRo[0][1] = SZ * CY + CZ * SY * SX;
	    pRo[0][2] = -SY * CX;

	    pRo[1][0] = -SZ * CX;
	    pRo[1][1] = CZ * CX;
	    pRo[1][2] = SX;

	    pRo[2][0] = CZ * SY + CY * SX * SZ;
	    pRo[2][1] = SZ * SY - CY * SX * CZ;
	    pRo[2][2] = CY * CX;

	    return pRo;
    }

    /*
    *	KmZYXtoR : ZYX Euler Angle To Rotation Matrix
    *
    *	INPUT
    *		pZ:		input angle Z
    *		pY:		input angle Y
    *		pX:		input angle X
    *
    *	OUTPUT
    *		pRo:	output matrix Ro = RZYX(Z, Y, X)
    *
    *	RETURN VALUE
    *		pRo
    *
    *	REMARKS
    *		- Rotations are post-multiplied
    */
    K_INLINE double (*KmZYXtoR(double (*const pRo)[4], double pZ, double pY, double pX))[4]
    {
	    double SX, CX, SY, CY, SZ, CZ;

        SX = kSinCosd(pX, &CX);
        SY = kSinCosd(pY, &CY);
        SZ = kSinCosd(pZ, &CZ);

	    pRo[0][0] = CZ * CY;
	    pRo[0][1] = CZ * SY * SX + SZ * CX;
	    pRo[0][2] = -CZ * SY * CX + SZ * SX;

	    pRo[1][0] = -SZ * CY;
	    pRo[1][1] = -SZ * SY * SX + CZ * CX;
	    pRo[1][2] = SZ * SY * CX + CZ * SX;

	    pRo[2][0] = SY;
	    pRo[2][1] = -CY * SX;
	    pRo[2][2] = CY * CX;

	    return pRo;
    }

    /*
    *	KmIJKtoR : IJK Euler Angles To Rotation Matrix
    *
    *	INPUT
    *		pI:		input angle I
    *		pJ:		input angle J
    *		pK:		input angle K
    *		pOrd:	order of rotations Ord
    *
    *	OUTPUT
    *		pRo:	output matrix Ro = R(I, J, K, Ord)
    *
    *	RETURN VALUE
    *		pRo
    *
    *	REMARKS
    *		- Rotations are post-multiplied
    */
    K_INLINE double (*KmIJKtoR(double (*const pRo)[4], double pI, double pJ, double pK, const int pOrd))[4]
    {
        double	CI, CJ, CK, SI, SJ, SK, CC, CS, SC, SS;
        int I, J, K;

        if(pOrd & KM_EULER_PARITY_ODD) {
		    SI = kSinCosd(-pI, &CI);
		    SJ = kSinCosd(-pJ, &CJ);
		    SK = kSinCosd(-pK, &CK);
	    } else {
		    SI = kSinCosd(pI, &CI);
		    SJ = kSinCosd(pJ, &CJ);
		    SK = kSinCosd(pK, &CK);
	    }

	    CC = CI * CK;
	    CS = CI * SK;
	    SC = SI * CK;
	    SS = SI * SK;

	    I = KmEulerAxis[pOrd][0];
	    J = KmEulerAxis[pOrd][1];
	    K = KmEulerAxis[pOrd][2];

	    if(pOrd & KM_EULER_REPEAT_YES) {

		    pRo[I][I] = CJ;
		    pRo[J][I] = SJ * SI;
		    pRo[K][I] = SJ * CI;
		    pRo[I][J] = SJ * SK;
		    pRo[J][J] = -CJ * SS + CC;
		    pRo[K][J] = -CJ * CS - SC;
		    pRo[I][K] = -SJ * CK;
		    pRo[J][K] = CJ * SC + CS;
		    pRo[K][K] = CJ * CC - SS;

	    } else {

		    pRo[I][I] = CJ * CK;
		    pRo[J][I] = SJ * SC - CS;
		    pRo[K][I] = SJ * CC + SS;
		    pRo[I][J] = CJ * SK;
		    pRo[J][J] = SJ * SS + CC;
		    pRo[K][J] = SJ * CS - SC;
		    pRo[I][K] = -SJ;
		    pRo[J][K] = CJ * SI;
		    pRo[K][K] = CJ * CI;
	    }

	    return pRo;
    }

    /*
    *	KmVYZXtoR : YZX Euler Vector To Rotation Matrix
    *
    *	INPUT
    *		pVi:	input vector Vi
    *
    *	OUTPUT
    *		pRo:	output matrix Ro = RYZX(Vi)
    *
    *	RETURN VALUE
    *		pRo
    */
    K_INLINE double (*KmVYZXtoR(double (*const pRo)[4], const double *const pVi))[4]
    {
	    return KmYZXtoR(pRo, pVi[0], pVi[1], pVi[2]);
    }

    /*
    *	KmVXYZtoR : XYZ Euler Vector To Rotation Matrix
    *
    *	INPUT
    *		pVi:	input vector Vi
    *
    *	OUTPUT
    *		pRo:	output matrix Ro = RXYZ(Vi)
    *
    *	RETURN VALUE
    *		pRo
    *
    *	REMARKS
    *		- Rotations are post-multiplied
    */
    K_INLINE double (*KmVXYZtoR(double (*const pRo)[4], const double *const pVi))[4]
    {
	    return KmXYZtoR(pRo, pVi[0], pVi[1], pVi[2]);
    }

    /*
    *	KmVZXYtoR : ZXY Euler Vector To Rotation Matrix
    *
    *	INPUT
    *		pVi:	input vector Vi
    *
    *	OUTPUT
    *		pRo:	output matrix Ro = RZXY(Vi)
    *
    *	RETURN VALUE
    *		pRo
    *
    *	REMARKS
    *		- Rotations are post-multiplied
    */
    K_INLINE double (*KmVZXYtoR(double (*const pRo)[4], const double *const pVi))[4]
    {
	    return KmZXYtoR(pRo, pVi[0], pVi[1], pVi[2]);
    }

    /*
    *	KmVXZYtoR : XZY Euler Vector To Rotation Matrix
    *
    *	INPUT
    *		pVi:	input vector Vi
    *
    *	OUTPUT
    *		pRo:	output matrix Ro = RXZY(Vi)
    *
    *	RETURN VALUE
    *		pRo
    *
    *	REMARKS
    *		- Rotations are post-multiplied
    */
    K_INLINE double (*KmVXZYtoR(double (*const pRo)[4], const double *const pVi))[4]
    {
	    return KmXZYtoR(pRo, pVi[0], pVi[1], pVi[2]);
    }
     
    /*
    *	KmVYXZtoR : YXZ Euler Vector To Rotation Matrix
    *
    *	INPUT
    *		pVi:	input vector Vi
    *
    *	OUTPUT
    *		pRo:	output matrix Ro = RYXZ(Vi)
    *
    *	RETURN VALUE
    *		pRo
    *
    *	REMARKS
    *		- Rotations are post-multiplied
    */
    K_INLINE double (*KmVYXZtoR(double (*const pRo)[4], const double *const pVi))[4]
    {
	    return KmYXZtoR(pRo, pVi[0], pVi[1], pVi[2]);
    }

    /*
    *	KmVZYXtoR : ZYX Euler Vector To Rotation Matrix
    *
    *	INPUT
    *		pVi:	input vector Vi
    *
    *	OUTPUT
    *		pRo:	output matrix Ro = RZYX(Vi)
    *
    *	RETURN VALUE
    *		pRo
    *
    *	REMARKS
    *		- Rotations are post-multiplied
    */
    K_INLINE double (*KmVZYXtoR(double (*const pRo)[4], const double *const pVi))[4]
    {
	    return KmZYXtoR(pRo, pVi[0], pVi[1], pVi[2]);
    }

    /*
    *	KmVIJKtoR : IJK Euler Vector To Rotation Matrix
    *
    *	INPUT
    *		pVi:	input vector Vi
    *		pOrd:	order (Ord) of rotations
    *
    *	OUTPUT
    *		pRo:	output matrix Ro = R(Vi, Ord)
    *
    *	RETURN VALUE
    *		pRo
    *
    *	REMARKS
    *		- Rotations are post-multiplied
    */
    K_INLINE double (*KmVIJKtoR(double (*const pRo)[4], const double *const pVi, const int pOrd))[4]
    {
	    return KmIJKtoR(pRo, pVi[0], pVi[1], pVi[2], pOrd);
    }

    /*
    *	KmVtoR : Default Order Euler Vector To Rotation Matrix
    *
    *	INPUT
    *		pVi:	input vector Vi
    *
    *	OUTPUT
    *		pRo:	output matrix Ro = RXYZ(Vi)
    *
    *	RETURN VALUE
    *		pRo
    *
    *	REMARKS
    *		- Rotations are post-multiplied
    */
    K_INLINE double (*KmVtoR(double (*const pRo)[4], const double *const pVi))[4]
    {
	    return KmVXYZtoR(pRo, pVi);
    }

    /*
    *	KmXYZtoQ : XYZ Euler Angles To Quaternion
    *
    *	INPUT
    *		pX:		input angle X
    *		pY:		input angle Y
    *		pZ:		input angle Z
    *
    *	OUTPUT
    *		pQo:	output quaternion Qo = Q(RXYZ(X, Y, Z))
    *
    *	RETURN VALUE
    *		pQo
    *
    *	REMARKS
    *		- Rotations are post-multiplied
    */
    K_INLINE double *KmXYZtoQ(double *const pQo, double pX, double pY, double pZ)
    {
	    double R[4][4];

	    return KmXYZtoR(R, pX, pY, pZ), KmRtoQ(pQo, R);
    }
     
    /*
    *	KmYZXtoQ : YZX Euler Angles To Quaternion
    *
    *	INPUT
    *		pY:		input angle pY
    *		pZ:		input angle pZ
    *		pX:		input angle pX
    *
    *	OUTPUT
    *		pQo:	output quaternion Qo = Q(RYZX(Y, Z, X))
    *
    *	RETURN VALUE
    *		pQo
    */
    K_INLINE double *KmYZXtoQ(double *const pQo, double pY, double pZ, double pX)
    {
	    double R[4][4];

	    return KmYZXtoR(R, pY, pZ, pX), KmRtoQ(pQo, R);
    }

    /*
    *	KmZXYtoQ : ZXY Euler Angles To Quaternion
    *
    *	INPUT
    *		pZ:		input angle Z
    *		pX:		input angle X
    *		pY:		input angle Y
    *
    *	OUTPUT
    *		pQo:	output matrix Qo = Q(ZXY(Z, X, Y))
    *
    *	RETURN VALUE
    *		pQo
    *
    *	REMARKS
    *		- Rotations are post-multiplied
    */
    K_INLINE double *KmZXYtoQ(double *const pQo, double pZ, double pX, double pY)
    {
	    double R[4][4];

	    return KmZXYtoR(R, pZ, pX, pY), KmRtoQ(pQo, R);
    }

    /*
    *	KmXZYtoQ : XZY Euler Angles To Quaternion
    *
    *	INPUT
    *		pX:		input angle X
    *		pZ:		input angle Z
    *		pY:		input angle Y
    *
    *	OUTPUT
    *		pQo:	output quaternion Qo = Q(RXZY(X, Z, Y))
    *
    *	RETURN VALUE
    *		pQo
    *
    *	REMARKS
    *		- Rotations are post-multiplied
    */
    K_INLINE double *KmXZYtoQ(double *const pQo, double pX, double pZ, double pY)
    {
	    double R[4][4];

	    return KmXZYtoR(R, pX, pZ, pY), KmRtoQ(pQo, R);
    }
     
    /*
    *	KmYXZtoQ : YXZ Euler Angles To Quaternion
    *
    *	INPUT
    *		pY:		input angle Y
    *		pX:		input angle X
    *		pZ:		input angle Z
    *
    *	OUTPUT
    *		pQo:	output matrix Qo = Q(RYXZ(Y, X, Z))
    *
    *	RETURN VALUE
    *		pQo
    *
    *	REMARKS
    *		- Rotations are post-multiplied
    */
    K_INLINE double *KmYXZtoQ(double *const pQo, double pY, double pX, double pZ)
    {
	    double R[4][4];

	    return KmYXZtoR(R, pY, pX, pZ), KmRtoQ(pQo, R);
    }

    /*
    *	KmZYXtoQ : ZYX Euler Angle To Quaternion
    *
    *	INPUT
    *		pZ:		input angle Z
    *		pY:		input angle Y
    *		pX:		input angle X
    *
    *	OUTPUT
    *		pQo:	output quaternion Qo = Q(RZYX(Z, Y, X))
    *
    *	RETURN VALUE
    *		pQo
    *
    *	REMARKS
    *		- Rotations are post-multiplied
    */
    K_INLINE double *KmZYXtoQ(double *const pQo, double pZ, double pY, double pX)
    {
	    double R[4][4];

	    return KmZYXtoR(R, pZ, pY, pX), KmRtoQ(pQo, R);
    }

    /*
    *	KmIJKtoQ : IJK Euler Angles To Quaternion
    *
    *	INPUT
    *		pI:		input angle I
    *		pJ:		input angle J
    *		pK:		input angle K
    *		pOrd:	order of rotations Ord
    *
    *	OUTPUT
    *		pQo:	output quaternion Qo = Q(R(I, J, K, Ord))
    *
    *	RETURN VALUE
    *		pQo
    *
    *	REMARKS
    *		- Rotations are post-multiplied
    */
    K_INLINE double *KmIJKtoQ(double *const pQo, double pI, double pJ, double pK, const int pOrd)
    {
	    double R[4][4];

	    return KmIJKtoR(R, pI, pJ, pK, pOrd), KmRtoQ(pQo, R);
    }

    /*
    *	KmVYZXtoQ : YZX Euler Vector To Quaternion
    *
    *	INPUT
    *		pVi:	input vector Vi
    *
    *	OUTPUT
    *		pQo:	output quaternion Qo = Q(RYZX(Vi))
    *
    *	RETURN VALUE
    *		pQo
    */
    K_INLINE double *KmVYZXtoQ(double *const pQo, const double *const pVi)
    {
	    return KmYZXtoQ(pQo, pVi[0], pVi[1], pVi[2]);
    }

    /*
    *	KmVXYZtoQ : XYZ Euler Vector To Quaternion
    *
    *	INPUT
    *		pVi:	input vector Vi
    *
    *	OUTPUT
    *		pQo:	output quaternion Qo = Q(RXYZ(Vi))
    *
    *	RETURN VALUE
    *		pQo
    *
    *	REMARKS
    *		- Rotations are post-multiplied
    */
    K_INLINE double *KmVXYZtoQ(double *const pQo, const double *const pVi)
    {
	    return KmXYZtoQ(pQo, pVi[0], pVi[1], pVi[2]);
    }

    /*
    *	KmVZXYtoQ : ZXY Euler Vector To Quaternion
    *
    *	INPUT
    *		pVi:	input vector Vi
    *
    *	OUTPUT
    *		pQo:	output quaternion = Q(RZXY(Vi))
    *
    *	RETURN VALUE
    *		pQo
    *
    *	REMARKS
    *		- Rotations are post-multiplied
    */
    K_INLINE double *KmVZXYtoQ(double *const pQo, const double *const pVi)
    {
	    return KmZXYtoQ(pQo, pVi[0], pVi[1], pVi[2]);
    }

    /*
    *	KmVXZYtoQ : XZY Euler Vector To Quaternion
    *
    *	INPUT
    *		pVi:	input vector Vi
    *
    *	OUTPUT
    *		pQo:	output quaternion Qo = Q(RXZY(Vi))
    *
    *	RETURN VALUE
    *		pQo
    *
    *	REMARKS
    *		- Rotations are post-multiplied
    */
    K_INLINE double *KmVXZYtoQ(double *const pQo, const double *const pVi)
    {
	    return KmXZYtoQ(pQo, pVi[0], pVi[1], pVi[2]);
    }
     
    /*
    *	KmVYXZtoQ : YXZ Euler Vector To Quaternion
    *
    *	INPUT
    *		pVi:	input vector Vi
    *
    *	OUTPUT
    *		pQo:	output quaternion Qo = Q(RYXZ(Vi))
    *
    *	RETURN VALUE
    *		pQo
    *
    *	REMARKS
    *		- Rotations are post-multiplied
    */
    K_INLINE double *KmVYXZtoQ(double *const pQo, const double *const pVi)
    {
	    return KmYXZtoQ(pQo, pVi[0], pVi[1], pVi[2]);
    }

    /*
    *	KmVZYXtoQ : ZYX Euler Vector To Quaternion
    *
    *	INPUT
    *		pVi:	input vector Vi
    *
    *	OUTPUT
    *		pQo:	output quaternion Qo = Q(RZYX(Vi))
    *
    *	RETURN VALUE
    *		pQo
    *
    *	REMARKS
    *		- Rotations are post-multiplied
    */
    K_INLINE double *KmVZYXtoQ(double *const pQo, const double *const pVi)
    {
	    return KmZYXtoQ(pQo, pVi[0], pVi[1], pVi[2]);
    }

    /*
    *	KmVIJKtoQ : IJK Euler Vector To Quaternion
    *
    *	INPUT
    *		pVi:	input vector Vi
    *		pOrd:	order (Ord) of rotations
    *
    *	OUTPUT
    *		pQo:	output quaternion Qo = Q(R(Vi, Ord))
    *
    *	RETURN VALUE
    *		pQo
    *
    *	REMARKS
    *		- Rotations are post-multiplied
    */
    K_INLINE double *KmVIJKtoQ(double *const pQo, const double *const pVi, const int pOrd)
    {
	    return KmIJKtoQ(pQo, pVi[0], pVi[1], pVi[2], pOrd);
    }

    /*
    *	KmVtoQ : Default Euler Vector To Quaternion
    *
    *	INPUT
    *		pVi:	input vector Vi
    *
    *	OUTPUT
    *		pQo:	output quaternion Qo = Q(RXYZ(Vi))
    *
    *	RETURN VALUE
    *		pQo
    *
    *	REMARKS
    *		- Rotations are post-multiplied
    */
    K_INLINE double *KmVtoQ(double *const pQo, const double *const pVi)
    {
	    return KmVXYZtoQ(pQo, pVi);
    }

    /*
    *	KmQtoR : Quaternion to Rotation Matrix
    *
    *	INPUT
    *		pQi:	input quaternion Qi
    *
    *	OUTPUT
    *		pRo:	output vector Vo = R(Qi)
    *
    *	RETURN VALUE
    *		pRo
    *
    *	REMARKS
    */
    K_INLINE double (*KmQtoR(double (*const pRo)[4], const double *const pQi))[4]
    {
	    double S, XS, YS, ZS, WX, WY, WZ, XX, XY, XZ, YY, YZ, ZZ;

	    if ((S = pQi[0] * pQi[0] + pQi[1] * pQi[1] + pQi[2] * pQi[2] + pQi[3] * pQi[3])!=0.0) {
		    S = 2.0 / S;
	    }

	    XS = pQi[0] * S;	YS = pQi[1] * S;	ZS = pQi[2] * S;
	    WX = pQi[3] * XS;	WY = pQi[3] * YS;	WZ = pQi[3] * ZS;
	    XX = pQi[0] * XS;	XY = pQi[0] * YS;	XZ = pQi[0] * ZS;	
	    YY = pQi[1] * YS;	YZ = pQi[1] * ZS;	ZZ = pQi[2] * ZS;	

	    pRo[0][0] = 1.0 - YY - ZZ;
	    pRo[0][1] = XY + WZ;	
	    pRo[0][2] = XZ - WY;
	    pRo[1][0] = XY - WZ;
	    pRo[1][1] = 1.0 - XX - ZZ;
	    pRo[1][2] = YZ + WX;
	    pRo[2][0] = XZ + WY;
	    pRo[2][1] = YZ - WX;
	    pRo[2][2] = 1.0 - XX - YY;

	    return pRo;
    }

    /*
    *	KmQtoVXYZ : Quaternion To XYZ Euler Vector
    *
    *	INPUT
    *		pQi:	input matrix Qi
    *
    *	OUTPUT
    *		pVo:	output vector Vo = RXYZ(Qi)
    *
    *	RETURN VALUE
    *		pVo
    *
    *	REMARKS
    *		- Rotations are post-multiplied
    */
    K_INLINE double *KmQtoVXYZ(double *const pVo, const double *const pQi)
    {
	    double R[4][4];

	    (void) KmQtoR(R, pQi);

	    return KmRtoVXYZ(pVo, R);
    }

    /*
    *	KmQtoVZYX : Quaternion To ZYX Euler Vector
    *
    *	INPUT
    *		pQi:	input quaternion Qi
    *
    *	OUTPUT
    *		pVo:	output vector Vo = RZYX(Qi)
    *
    *	RETURN VALUE
    *		pVo
    *
    *	REMARKS
    *		- Rotations are post-multiplied
    */
    K_INLINE double *KmQtoVZYX(double *const pVo, const double *const pQi)
    {
	    double R[4][4];

	    (void) KmQtoR(R, pQi);

	    return KmRtoVZYX(pVo, R);
    }

    /*
    *	KmQtoVord : Quaternion To Ordered Euler Vector
    *
    *	INPUT
    *		pQi:	input quaternion Qi
    *		pOrd:	order (Ord) of rotations
    *
    *	OUTPUT
    *		pVo:	output vector Vo = R(Qi, Ord)
    *
    *	RETURN VALUE
    *		pVo
    *
    *	REMARKS
    *		- Rotations are post-multiplied
    */
    K_INLINE double *KmQtoVord(double *const pVo, const double *const pQi, const int pOrd)
    {
	    double R[4][4];

	    (void) KmQtoR(R, pQi);

	    return KmRtoVord(pVo, R, pOrd);
    }

    /*
    *	KmQtoV : Default Order Rotation Matrix To Quaternion
    *
    *	INPUT
    *		pQi:	input quaternion Qi
    *
    *	OUTPUT
    *		pVo:	output vector Vo = RXYZ(Qi)
    *
    *	RETURN VALUE
    *		pVo
    *
    *	REMARKS
    *		- Rotations are post-multiplied
    */
    K_INLINE double *KmQtoV(double *const pVo, const double *const pQi)
    {
	    return KmQtoVXYZ(pVo, pQi);
    }

    /*
    *	KmRS : Scaling Vector Times Rotation Matrix
    *
    *	INPUT
    *		pAi:	input rotation matrix Ri
    *		pSi:	input scaling vector Si
    *
    *	OUTPUT
    *		pAo:	output matrix Ao = Ri * S(Si)
    *
    *	RETURN VALUE
    *		pAo
    */
    K_INLINE double (*KmRS(
	    double (*const pAo)[4], 
	    const double (*const pRi)[4], const double *const pSi))[4]
    {
	    double	T;

	    T = pSi[0];

	    pAo[0][0] = pRi[0][0] * T;
	    pAo[0][1] = pRi[0][1] * T;
	    pAo[0][2] = pRi[0][2] * T;

	    T = pSi[1];

	    pAo[1][0] = pRi[1][0] * T;
	    pAo[1][1] = pRi[1][1] * T;
	    pAo[1][2] = pRi[1][2] * T;

	    T = pSi[2];

	    pAo[2][0] = pRi[2][0] * T;
	    pAo[2][1] = pRi[2][1] * T;
	    pAo[2][2] = pRi[2][2] * T;

	    return pAo;
    }

    /*
    *	KmVtoA : Vectors To Affine Matrix
    *
    *	INPUT
    *		pTi:	input translation vector Ti
    *		pRi:	input XYZ Euler rotation vector Ri
    *		pSi:	input scaling vector Si
    *
    *	OUTPUT
    *		pAo:	output matrix Ao = T(Ti) * RXYZ(Ri) * S(Si)
    *
    *	RETURN VALUE
    *		pAo
    */
    K_INLINE double (*KmVtoA(
	    double (*const pAo)[4], 
	    const double *const pTi, const double *const pRi, const double *const pSi))[4]
    {
	    (void) KmVtoR(pAo, pRi);
	    (void) KmRS(pAo, pAo, pSi);

	    pAo[3][0] = pTi[0];
	    pAo[3][1] = pTi[1];
	    pAo[3][2] = pTi[2];

	    return pAo;
    }

    /*
    *	KmVtoAord : Vectors To Affine Matrix
    *
    *	INPUT
    *		pTi:	input translation vector Ti
    *		pRi:	input XYZ Euler rotation vector Ri
    *		pSi:	input scaling vector Si
    *		pOrd:	order of rotation Ord
    *
    *	OUTPUT
    *		pAo:	output matrix Ao = T(Ti) * RIJK(Ri, Ord) * S(Si)
    *
    *	RETURN VALUE
    *		pAo
    */
    K_INLINE double (*KmVtoAord(
	    double (*const pAo)[4], 
	    const double *const pTi, const double *const pRi, const double *const pSi, const int pOrd))[4]
    {
	    double	T;

	    (void) KmIJKtoR(pAo, pRi[0], pRi[1], pRi[2], pOrd);

	    T = pSi[0];

	    pAo[0][0] *= T;
	    pAo[0][1] *= T;
	    pAo[0][2] *= T;

	    T = pSi[1];

	    pAo[1][0] *= T;
	    pAo[1][1] *= T;
	    pAo[1][2] *= T;

	    T = pSi[2];

	    pAo[2][0] *= T;
	    pAo[2][1] *= T;
	    pAo[2][2] *= T;

	    pAo[3][0] = pTi[0];
	    pAo[3][1] = pTi[1];
	    pAo[3][2] = pTi[2];

	    return pAo;
    }

    /*
    *	KmNtoS : Isotropic Scaling Matrix
    *
    *	INPUT
    *		pNi:	input value Ni
    *
    *	OUTPUT
    *		pSo:	output matrix So = S([Ni Ni Ni])
    *
    *	RETURN VALUE
    *		pSo
    */
    K_INLINE double (*KmNtoS(double (*const pSo)[4], const double pNi))[4]
    {
	    KM_ASSERT(pNi, "Zero scaling factor used in KmNtoS()");

	    pSo[0][0] = pSo[1][1] = pSo[2][2] = pNi;

	    return pSo;
    }

    /*
    *	KmVtoS : Vector To Scaling Matrix
    *
    *	INPUT
    *		pVi:	input vector Vi
    *
    *	OUTPUT
    *		pSo:	output matrix So = S(Vi)
    *
    *	RETURN VALUE
    *		pSo
    */
    K_INLINE double (*KmVtoS(double (*const pSo)[4], const double *const pVi))[4]
    {
	    KM_ASSERT(pVi[0] * pVi[1] * pVi[2] != 0.0, "Zero scaling factor used in KmVtoS()");

	    pSo[0][0] = pVi[0];
	    pSo[1][1] = pVi[1];
	    pSo[2][2] = pVi[2];

	    return pSo;
    }

    /*
    *	KmStoV : Scaling Matrix To Vector
    *
    *	INPUT
    *		pSi:	input matrix Si
    *
    *	OUTPUT
    *		pVo:	output vector Vo = S(Si)
    *
    *	RETURN VALUE
    *		pVo
    */
    K_INLINE double *KmStoV(double *const pVo, const double (*const pSi)[4])
    {
	    pVo[0] = pSi[0][0];
	    pVo[1] = pSi[1][1];
	    pVo[2] = pSi[2][2];

	    return pVo;
    }

    /*
    *	KmAtoS : Affine Matrix to Scaling Vector
    *
    *	INPUT
    *		pAi:	input matrix Ai
    *
    *	OUTPUT
    *		pSo:	output matrix So = S(Ai)
    *
    *	RETURN VALUE
    *		pSo
    */
    K_INLINE double *KmAtoS(double *const pSo, const double (*const pAi)[4])
    {
	    double S, T;

	    T = pAi[0][0];
	    S = T * T;
	    T = pAi[0][1];
	    S += T * T;
	    T = pAi[0][2];
	    pSo[0] = kSqrt(S + T * T);

	    T = pAi[1][0];
	    S = T * T;
	    T = pAi[1][1];
	    S += T * T;
	    T = pAi[1][2];
	    pSo[1] = kSqrt(S + T * T);

	    T = pAi[2][0];
	    S = T * T;
	    T = pAi[2][1];
	    S += T * T;
	    T = pAi[2][2];
	    pSo[2] = kSqrt(S + T * T);

	    return pSo;
    }

    K_INLINE double KmAdist(const double (*const pAiA)[4], const double (*const pAiB)[4])
    {
	    return kSqrt(
		    KmVdist2(pAiA[0], pAiB[0]) +
		    KmVdist2(pAiA[1], pAiB[1]) +
		    KmVdist2(pAiA[2], pAiB[2]) +
		    KmVdist2(pAiA[3], pAiB[3]));
    }

    K_INLINE double KmRdist(const double (*const pRiA)[4], const double (*const pRiB)[4])
    {
	    return kSqrt(
		    KmVdist2(pRiA[0], pRiB[0]) +
		    KmVdist2(pRiA[1], pRiB[1]) +
		    KmVdist2(pRiA[2], pRiB[2]));
    }

    K_INLINE double KmTdist(const double (*const pTiA)[4], const double (*const pTiB)[4])
    {
	    return KmVdist(pTiA[3], pTiB[3]);
    }

#include <fbxfilesdk/fbxfilesdk_nsend.h>

#endif // FBXFILESDK_COMPONENTS_KBASELIB_KMATH_KMATH_H

