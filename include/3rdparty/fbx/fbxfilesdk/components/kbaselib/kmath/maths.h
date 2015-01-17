#ifndef FBXFILESDK_COMPONENTS_KBASELIB_KMATH_MATHS_H
#define FBXFILESDK_COMPONENTS_KBASELIB_KMATH_MATHS_H

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

#include <fbxfilesdk/components/kbaselib/klib/itype.h>
#include <fbxfilesdk/components/kbaselib/kmath/types.h>
#include <fbxfilesdk/components/kbaselib/kmath/const.h>

#include <math.h>

#ifdef KARCH_ENV_WIN32
	#ifndef logb
		#define logb	_logb
	#endif
	#ifndef isnan
		#define isnan	_isnan
	#endif
#endif


//******************************************************************************
//
//	integer only templates
//
//******************************************************************************

template<class T> K_INLINE T kIsOdd(T i)
{
	return i & 1;
}

template<class T> K_INLINE T kIsEven(T i)
{
	return !kIsOdd(i);
}

// -1^^i
template<class T> K_INLINE T kAlt(T i)
{
	return -(i & 1) | 1;
}

// factorial
template<class T> K_INLINE T kFact(T x)
{
	T y = 1; 
	
	while(x > 1) { 
		y *= x;
		x--;
	}
	
	return y;
}

// binomial coefficient
template<class T> K_INLINE T kBC(T n, T k)
{
	return kFact(n) / (kFact(k) * kFact(n - k));
}

// k-permutation
template<class T> K_INLINE T kPerm(T n, T k)
{
	return kFact(n) / kFact(n - k);
}

// k-combination
template<class T> K_INLINE T kComb(T n, T k)
{
	return kBCoef(n, k);
}

// greatest common divisor
template<class T> K_INLINE T kGCD(T x, T y)
{
	T r; while(y) { r = x % y; x = y; y = r; } return x;
}

// least common multiple
template<class T> K_INLINE T kLCM(T x, T y)
{ 
	return x * (y / kGCD(x, y));
}

// r = x % y, x / y
template<class T> K_INLINE T kDiv(T x, T y, T *r)
{
	T q = x / y; return *r = x - y * q, q;
}

//******************************************************************************
//
//	floating-point number classification
//
//******************************************************************************

// is not a number
template<class T> K_INLINE bool kIsNan(T x);

// is a finite number
template<class T> K_INLINE bool kIsFinite(T x)
{
	return (x != K_INF) && (x != -K_INF);
}

// is an infinite number
template<class T> K_INLINE bool kIsInfinite(T x)
{
	return !kIsFinite(x);
}

// is normalized
template<class T> K_INLINE bool kIsNormalized(T x);

template<class T> K_INLINE T kHuge(T);
template<class T> K_INLINE T kTiny(T);

//******************************************************************************
//
//	floating-point number manipulation
//
//******************************************************************************

// mantissa of x
template<class T> K_INLINE T kMantissa(T x);

// exponent of x
template<class T> K_INLINE int kExponent(T x);

// mantissa and exponent of x
template<class T> K_INLINE T kManExp(T x, int *y);

// x * 2^y
template<class T> K_INLINE T kScalb(T x, int y);

// fractional part
template<class T> K_INLINE T kMod(T x)
{
	return kMod(x, T(1));
}

template<class T> K_INLINE T kMod(T x, T *y);

// next representable value
template<class T> K_INLINE T kNextAfter(T x, T y)
{
	return x + kPolarity(y - x);
}

// validate value
template<class T> K_INLINE T kValidate(T x)
{
	return x;
}

//******************************************************************************
//
//	floating-point number sign
//
//******************************************************************************

// sign(x) (-1,1)
template<class T> K_INLINE T kSign(T x)
{
	return (x < 0) ? T(-1) : T(1);
}

// polarity(x) (-1,0,1)
template<class T> K_INLINE T kPolarity(T x)
{
	return (x < 0) ? T(-1) : T(x > 0);
}

// |x|*sign(y)
template<class T> K_INLINE T kCopysign(T x, T y)
{
	return (x < 0) ? ((y < 0) ? x : -x) : ((y < 0) ? -x : x);
}

template<class T, class S> K_INLINE S kConvert(T x, S)
{
	return S(x);
}


//******************************************************************************
//
//	integer rounding
//
//******************************************************************************

// round toward -inf

// floor to multiple
// template<class T> K_INLINE T kFloor(T x, T y);

// ceil to multiple
// template<class T> K_INLINE T kCeil(T x, T y);

// round to nearest
template<class T> K_INLINE T kRound(T x)
{
	T y = kFloor(x); return (x - y < T(0.5)) ? y : y + T(1);
}

// round to multiple
template<class T> K_INLINE T kRound(T x, T y)
{
	return y * kRound(x / y);
}

// round toward zero
template<class T> K_INLINE T kTrunc(T x)
{
	return (x < 0) ? kCeil(x) : kFloor(x);
}

// trunc to multiple
template<class T> K_INLINE T kTrunc(T x, T y)
{
	return y * kTrunc(x / y);
}

//******************************************************************************
//
//	moduli
//
//******************************************************************************

// signed modulo
// template<class T> K_INLINE T kMod(T x, T y);

K_TEMPLATE_SPEC(float) K_INLINE float kMod(float x, float y)
{
	return float(fmod(x, y));
}
K_TEMPLATE_SPEC(double) K_INLINE double kMod(double x, double y)
{
	return fmod(x, y);
}

// remainder of closest
template<class T> K_INLINE T kRem(T x, T y)
{
	return x - kRound(x, y);
}

// unsigned modulo
template<class T> K_INLINE T kRoll(T x, T y)
{
	return x - kFloor(x, y);
}

// unroll
template<class T> K_INLINE T kUnroll(T x, T y, T z)
{
	return x + kRound(z - x, y);
}

// fold
template<class T> K_INLINE T kFold(T x, T y)
{
	kLong n = kLong(x / y); 
	
	return n ? (((n < 0) ^ (n & 1)) ? y - kRoll(x, y) : kRoll(x, y)) : kAbs(x);
}

//******************************************************************************
//
//	floating-point number comparison
//
//******************************************************************************

K_TEMPLATE_SPEC(float) K_INLINE float kMin(float)
{
	return K_FLOAT_MIN;
}
K_TEMPLATE_SPEC(double) K_INLINE double kMin(double)
{
	return K_DOUBLE_MIN;
}
K_TEMPLATE_SPEC(float) K_INLINE float kMax(float)
{
	return K_FLOAT_MAX;
}
K_TEMPLATE_SPEC(double) K_INLINE double kMax(double)
{
	return K_DOUBLE_MAX;
}
// x == y within epsilon
template<class T> K_INLINE bool kEq(T x, T y, T e)
{
	return kAbs(x - y) <= e;
}

//******************************************************************************
//
//	squares and cubes
//
//******************************************************************************

// reciprocal
template<class T> K_INLINE T kRecip(T x)
{
	return T(1) / x;
}

// square root
template<class T> K_INLINE T kSqrt(T x)
{
	if(x > 1) {
		T z, y = x >> 1; 
		do 
		{ 
			z = y; 
			y = (y + (x / y)) >> 1; 
		} while(y < z); 
		return z;
	} else {
		return x;
	}
}

// square root of non-zero argument
template<class T> K_INLINE T kSqrtnz(T x)
{
	return kSqrt(x);
}

// square root reciprocal
template<class T> K_INLINE T kRsqrt(T x)
{
	return 1.0 / kSqrtnz(x);
}

// cubic root
template<class T> K_INLINE T kCbrt(T x);

// square
template<class T> K_INLINE T kSq(T x)
{
	return x * x;
}

// cube
template<class T> K_INLINE T kCb(T x)
{
	return x * x * x;
}

//******************************************************************************
//
//	exponential functions
//
//******************************************************************************

// e^x
template<class T> K_INLINE T kExp(T x);

// 2^x
template<class T> K_INLINE T kExp2(T x)
{
	return kExp(x * T(K_LN2));
}

// 10^x
template<class T> K_INLINE T kExp10(T x)
{
	return kExp(x * T(K_LN10));
}

// e^x - 1
template<class T> K_INLINE T kExpm1(T x)
{
	return kExp(x) - T(1);
}

// 2^x - 1
template<class T> K_INLINE T kExp2m1(T x)
{
	return kExpm1(x * T(K_LN2));
}

// 10^x - 1
template<class T> K_INLINE T kExp10m1(T x)
{
	return kExpm1(x * T(K_LN10));
}

// x^y
template<class T> K_INLINE T kPow(T x, T y)
{
	return kExp(y * kLog(x));
}

//******************************************************************************
//
//	logarithm functions
//
//******************************************************************************

// log(x)
template<class T> K_INLINE T kLog(T x);

// log2(x)
template<class T> K_INLINE T kLog2(T x)
{
	return kLog(x) * T(K_1_LN2);
}

// log10(x)
template<class T> K_INLINE T kLog10(T x)
{
	return kLog(x) * T(K_1_LN10);
}

// log(x + 1)
template<class T> K_INLINE T kLogp1(T x)
{
	return kLog(x + T(1));
}

// log2(x + 1)
template<class T> K_INLINE T kLog2p1(T x)
{
	return kLog2(x + T(1));
}

// log10(x + 1)
template<class T> K_INLINE T kLog10p1(T x)
{
	return kLog10(x + T(1));
}


//******************************************************************************
//
//	trigonometric functions
//
//******************************************************************************

// sin(x)
template<class T> K_INLINE T kSin(T x);

// sin(x * pi)
template<class T> K_INLINE T kSinpi(T x)
{
	return kSin(x * K_PI);
}

// sin(x * pi/180)
template<class T> K_INLINE T kSind(T x)
{
	return kSin(x * K_PI_180);
}

// cos(x)
template<class T> K_INLINE T kCos(T x);

// cos(x * pi)
template<class T> K_INLINE T kCospi(T x)
{
	return kCos(x * K_PI);
}

// cos(x * pi/180)
template<class T> K_INLINE T kCosd(T x)
{
	return kCos(x * K_PI_180);
}

// *y = cos(x), sin(x)
template<class T> K_INLINE T kSinCos(T x, T *y)
{
	return *y = kCos(x), kSin(x);
}

// *y = cos(x * pi), sin(x * pi)
template<class T> K_INLINE T kSinCospi(T x, T *y)
{
	return kSinCos(T(x * K_PI), y);
}

// *y = cos(x * pi/180), sin(x * pi/180)
template<class T> K_INLINE T kSinCosd(T x, T *y)
{
	return kSinCos(T(x * K_PI_180), y);
}

// tan(x)
template<class T> K_INLINE T kTan(T x)
{
	return kSin(x) / kCos(x);
}

// tan(x * pi)
template<class T> K_INLINE T kTanpi(T x)
{
	return kTan(x * K_PI);
}

// tan(x * pi/180)
template<class T> K_INLINE T kTand(T x)
{
	return kTan(x * K_PI_180);
}

// sec(x)
template<class T> K_INLINE T kSec(T x)
{
	return kRecip(kSin(x));
}

// cosec(x)
template<class T> K_INLINE T kCosec(T x)
{
	return kRecip(kCos(x));
}

// cotan(x)
template<class T> K_INLINE T kCotan(T x)
{
	return kRecip(kTan(x));
}

// asin(x)
template<class T> K_INLINE T kAsin(T x);

// asin(x) / pi
template<class T> K_INLINE T kAsinpi(T x)
{
	return kAsin(x) * K_1_PI;
}

// asin(x) * 180/pi
template<class T> K_INLINE T kAsind(T x)
{
	return kAsin(x) * K_180_PI;
}

// acos(x)
template<class T> K_INLINE T kAcos(T x);

// acos(x) / pi
template<class T> K_INLINE T kAcospi(T x)
{
	return kAcos(x) * K_1_PI;
}

// acos(x) * 180/pi
template<class T> K_INLINE T kAcosd(T x)
{
	return kAcos(x) * K_180_PI;
}

// atan(x)
template<class T> K_INLINE T kAtan(T x);

// atan(x) / pi
template<class T> K_INLINE T kAtanpi(T x)
{
	return kAtan(x) * K_1_PI;
}

// atan(x) * 180/pi
template<class T> K_INLINE T kAtand(T x)
{
	return kAtan(x) * K_180_PI;
}

// atan(y/x)
template<class T> K_INLINE T kAtan(T y, T x);

// atan(y/x) / pi
template<class T> K_INLINE T kAtanpi(T y, T x)
{
	return kAtan(y, x) * K_1_PI;
}

// atan(y/x) * 180/pi
template<class T> K_INLINE T kAtand(T y, T x)
{
	return kAtan(y, x) * K_180_PI;
}

// arc tangent approximation
template<class T> K_INLINE T kAtanq(T y, T x)
{
	if(x >= 0) {
		if(y > 0) {
			return (x > y) ? (y / x) * T(K_PI_4) : (T(2) - (x / y)) * T(K_PI_4);
		} else if(y < 0) {
			return (x > -y) ? (y / x) * T(K_PI_4) : ((x / y) + T(2)) * T(-K_PI_4);
		} else {
			return 0;
		}
	} else {
		if(y > 0) {
			return (-x > y) ? (T(4) + (y / x)) * T(K_PI_4) : (T(2) - (x / y)) * T(K_PI_4);
		} else if(y < 0) {
			return (x < y) ? ((y / x) - T(4)) * T(K_PI_4) : ((x / y) + T(2)) * T(-K_PI_4);
		} else {
			return T(-K_PI);
		}
	}
}

// haversine(x)
template<class T> K_INLINE T kHaversin(T x)
{
	return T(0.5) * (T(1) - kCos(x));
}

// haversine(x)
template<class T> K_INLINE T kHavercos(T x)
{
	return T(0.5) * (T(1) - kSin(x));
}

// eucledian norm
template<class T> K_INLINE T kNorm(T x, T y)
{
	return kSqrt(x * x + y * y);
}

// eucledian norm
template<class T> K_INLINE T kNorm(T x, T y, T z)
{
	return kSqrt(x * x + y * y + z * z);
}

// eucledian norm
template<class T> K_INLINE T kNorm(T w, T x, T y, T z)
{
	return kSqrt(w * w + x * x + y * y + z * z);
}

// hypothenuse length
template<class T> K_INLINE T kHypot(T x, T y)
{
	return kSqrtnz(x * x + y * y);
}

template<class T> K_INLINE T kHypot(T x, T y, T z)
{
	return kSqrtnz(x * x + y * y + z * z);
}

template<class T> K_INLINE T kHypot(T w, T x, T y, T z)
{
	return kSqrtnz(w * w + x * x + y * y + z * z);
}

//******************************************************************************
//
//	complex number functions
//
//******************************************************************************

template<class T> K_INLINE T kRe(T x)
{
	return x;
}

template<class T> K_INLINE T kIm(T x)
{
	return 0;
}

// abs(x + iy)
template<class T> K_INLINE T kAbs(T x, T y)
{
	T ax, ay;

	if(x) {
		if(ax = kAbs(x), y) {
			return (ax > (ay = kAbs(y))) ? ay * kSqrtnz(T(1) + kSq(x / y)) : ax * kSqrtnz(T(1) + kSq(y / x));
		} else {
			return ax;
		}
	} else {
		return kAbs(y);
	}
}

// arg(x + iy)
template<class T> K_INLINE T kArg(T x, T y)
{
	return kAtan(y, x);
}

// e + if = (a + ib) + (c + id)
#define kComplexAdd(e, f, a, b, c, d) \
	(e) = (a)+(c); (f) = (b)+(d)

// e + if = (a + ib) - (c + id)
#define kComplexSub(e, f, a, b, c, d) \
	(e) = (a)-(c); (f) = (b)-(d)

// c + id = (a + ib)(a + ib)
#ifdef KARCH_SLOW_MULT
#define kComplexSq(c, d, a, b, t) \
	(e) = (a)*(a); (t) = (a)+(b); (f) = (t)*(t)-(e); (t) = (b)*(b); (f) -= (t); (e) -= (t)
#else
#define kComplexSq(c, d, a, b, t) \
	(c) = (a)*(a)-(b)*(b); (d) = 2*(a)*(b)
#endif

// e + if = (a + ib)(c + id)
#ifdef KARCH_SLOW_MULT
#define kComplexMult(e, f, a, b, c, d, t) \
	(e) = (a)*(c); (t) = (b)*(d); (f) = ((a)+(b))*((c)+(d))-(e)-(t); (e) -= (t)
#else
#define kComplexMult(e, f, a, b, c, d, t) \
	(e) = (a)*(c)-(b)*(d); (f) = (b)*(c)+(a)*(d)
#endif

// e + if = (a + ib)(c - id)
#ifdef KARCH_SLOW_MULT
#define kComplexConjMult(e, f, a, b, c, d, t) \
	(e) = (a)*(c); (t) = (b)*(d); (f) = ((a)+(b))*((c)-(d))-(e)+(t); (e) += (t)
#else
#define kComplexConjMult(e, f, a, b, c, d, t) \
	(e) = (a)*(c)+(b)*(d); (f) = (b)*(c)-(a)*(d)
#endif

// e + if = (a + ib)/(c + id)
#ifdef KARCH_SLOW_MULT
#define kComplexDiv(e, f, a, b, c, d, t) \
	(e) = (a)*(c); (t) = (b)*(d); (f) = ((a)+(b))*((c)-(d))-(e)+(t); (e) += (t); (t) = 1/((c)*(c)+(d)*(d)); (e) *= (t); (f) *= (t)
#else
#define kComplexDiv(e, f, a, b, c, d, t) \
	(t) = 1/((c)*(c) + (d)*(d)); (e) = (t)*((a)*(c)+(b)*(d)); (f) = (t)*((b)*(c)-(a)*(d))
#endif

//******************************************************************************
//
//	hyperbolic functions
//
//******************************************************************************

// sinh(x)
template<class T> K_INLINE T kSinh(T x);

// sech(x)
template<class T> K_INLINE T kSech(T x)
{
	return kRecip(kSinh(x));
}

// cosh(x)
template<class T> K_INLINE T kCosh(T x);

// cosech(x)
template<class T> K_INLINE T kCosech(T x)
{
	return kRecip(kCosh(x));
}
/*
// y = cosh(x), sinh(x)
template<class T> K_INLINE T kSinhCosh(T x, T *y)
{
	return *y = kCosh(), kSinh();
}
*/
// tanh(x)
template<class T> K_INLINE T kTanh(T x);

// cotanh(x)
template<class T> K_INLINE T kCotanh(T x)
{
	return kRecip(kTanh(x));
}

// asinh(x)
template<class T> K_INLINE T kAsinh(T x)
{
	return kLog(x + kSqrtnz(x * x + T(1)));
}

// acosh(x)
template<class T> K_INLINE T kAcosh(T x)
{
	return kLog(x + kSqrtnz(x * x));
}

// atanh(z)
template<class T> K_INLINE T kAtanh(T x)
{
	return 0.5 * kLog((T(1) + x) / (T(1) - x));
}

//******************************************************************************
//
//	polynomial roots
//
//******************************************************************************

// quadratic
template<class T> K_INLINE int kQuadRoots(T a, T b, T c, T *x1, T *x2)
{
	T t, q;

	if((t = b * b - a * c * T(4)) > 0) {
		q = (b + kSign(b) * kSqrtnz(t)) * T(-0.5);
		*x1 = q / a;
		*x2 = c / q;
		return 2;
	} else if(t == 0) {
		*x1 = *x2 = -b / (a + a);
		return 1;
	} else {
		return 0;
	}
}

// cubic
template<class T> K_INLINE int kCubicRoots(T a, T b, T c, T *x1, T *x2, T *x3)
{
	T A, B, Q, R, D, theta;

	Q = (kSq(a) - b * T(3)) * T(K_1_9);
	R = (kCb(a) * T(2) - a * b * T(9) + c * T(27)) * T(K_1_54);
	a *= T(K_1_3);

	D = R * R - Q * Q * Q;
	if(D < 0) {
		theta = kAcos(R / kSqrt(Q * Q * Q)) * T(K_1_3);
		Q = kSqrt(Q) * T(-2);
		*x1 = Q * kCos(theta) - a;
		*x2 = Q * kCos(theta + T(K_2PI_3)) - a;
		*x3 = Q * kCos(theta - T(K_2PI_3)) - a;
		return 3;
	} else {
		A = -kSign(R)*kCbrt(kAbs(R) + kSqrt(D));
		B = A ? Q / A : 0;
		*x1 = (A + B) - a;
		*x2 = *x3 = T(-0.5) * (A + B) - a;
		return 2 - (*x1 == *x2);
	}
}

K_TEMPLATE_SPEC(double) K_INLINE bool kIsNan(double x)
{
	return !!isnan(x);
}

K_TEMPLATE_SPEC(double) K_INLINE double kSqrt(double x)
{
	return sqrt(x);
}

K_TEMPLATE_SPEC(float) K_INLINE float kSqrt(float x)
{
	return sqrtf(x);
}


//******************************************************************************
//
//	exponential functions
//
//******************************************************************************

K_TEMPLATE_SPEC(float) K_INLINE float kExp(float x)
{
	return expf(x);
}
K_TEMPLATE_SPEC(double) K_INLINE double kExp(double x)
{
	return exp(x);
}
//******************************************************************************
//
//	logarithm functions
//
//******************************************************************************

K_TEMPLATE_SPEC(float) K_INLINE float kLog(float x)
{
	return float(log(x));
}
K_TEMPLATE_SPEC(double) K_INLINE double kLog(double x)
{
	return log(x);
}

K_TEMPLATE_SPEC(float) K_INLINE float kLog10(float x)
{
	return float(log10(x));
}
K_TEMPLATE_SPEC(double) K_INLINE double kLog10(double x)
{
	return log10(x);
}

K_TEMPLATE_SPEC(float) K_INLINE int kExponent(float x)
{
	return int(logb(x));
}
K_TEMPLATE_SPEC(double) K_INLINE int kExponent(double x)
{
	return int(logb(x));
}

//******************************************************************************
//
//	trigonometric functions
//
//******************************************************************************

K_TEMPLATE_SPEC(float) K_INLINE float kSin(float x)
{
	return sinf(x);
}
K_TEMPLATE_SPEC(double) K_INLINE double kSin(double x)
{
	return sin(x);
}
K_TEMPLATE_SPEC(float) K_INLINE float kCos(float x)
{
	return cosf(x);
}
K_TEMPLATE_SPEC(double) K_INLINE double kCos(double x)
{
	return cos(x);
}
K_TEMPLATE_SPEC(float) K_INLINE float kTan(float x)
{
	return tanf(x);
}
K_TEMPLATE_SPEC(double) K_INLINE double kTan(double x)
{
	return tan(x);
}
K_TEMPLATE_SPEC(float) K_INLINE float kAsin(float x)
{
	return asinf(x);
}
K_TEMPLATE_SPEC(double) K_INLINE double kAsin(double x)
{
	return asin(x);
}
K_TEMPLATE_SPEC(float) K_INLINE float kAcos(float x)
{
	return acosf(x);
}
K_TEMPLATE_SPEC(double) K_INLINE double kAcos(double x)
{
	return acos(x);
}
K_TEMPLATE_SPEC(float) K_INLINE float kAtan(float x)
{
	return atanf(x);
}
K_TEMPLATE_SPEC(double) K_INLINE double kAtan(double x)
{
	return atan(x);
}
K_TEMPLATE_SPEC(float) K_INLINE float kAtan(float y, float x)
{
	return atan2f(y, x);
}
K_TEMPLATE_SPEC(double) K_INLINE double kAtan(double y, double x)
{
	return atan2(y, x);
}

// template<class T> K_INLINE T kAbs(T x)
K_TEMPLATE_SPEC(float) K_INLINE float kAbs(float x)
{
	return fabs(x);
}

K_TEMPLATE_SPEC(double) K_INLINE double kAbs(double x)
{
	return fabs(x);
}

// template<class T> K_INLINE T kFloor(T x);
K_TEMPLATE_SPEC(float) K_INLINE float kFloor(float x)
{
	return float(floor(x));
}
K_TEMPLATE_SPEC(double) K_INLINE double kFloor(double x)
{
	return floor(x);
}

// template<class T> K_INLINE T kCeil(T x);
K_TEMPLATE_SPEC(float) K_INLINE float kCeil(float x)
{
	return float(ceil(x));
}
K_TEMPLATE_SPEC(double) K_INLINE double kCeil(double x)
{
	return ceil(x);
}

// template<class T> K_INLINE T kCeil(T x, T y)
K_TEMPLATE_SPEC(float) K_INLINE float kCeil(float x, float y)
{
	return y * (kCeil(x / y));
}

K_TEMPLATE_SPEC(double) K_INLINE double kCeil(double x, double y)
{
	return y * (kCeil(x / y));
}

#endif // FBXFILESDK_COMPONENTS_KBASELIB_KMATH_MATHS_H

