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

#ifndef FBXFILESDK_COMPONENTS_KBASELIB_KMATH_CONST_H
#define FBXFILESDK_COMPONENTS_KBASELIB_KMATH_CONST_H

//*****************************************************************************************************************
//	 mathematical constants
//*****************************************************************************************************************

#include <fbxfilesdk/components/kbaselib/karch/types.h>

//*****************************************************************************************************************
//	common constants
//*****************************************************************************************************************

#ifndef K_ZERO
#define K_ZERO			0														// 0
#endif
#ifndef K_ONE
#define K_ONE			1														// 1
#endif

#define K_1_3			.33333333333333333333333333333333333333333333333333		// 1/3
#define K_2_3			.66666666666666666666666666666666666666666666666667		// 2/3
#define K_1_9			.11111111111111111111111111111111111111111111111111		// 1/9
#define K_1_54			.01851851851851851851851851851851851851851851851852		// 1/54

#ifndef K_E
#define K_E				2.7182818284590452353602874713526624977572470936000		// e (natural logarithm base)
#endif

#define K_PI_180		.017453292519943295769236907684886127134428718885417	// pi/180
#define K_PI_8			.39269908169872415480783042290993786052464617492188		// pi/8
#define K_PI_4			.78539816339744830961566084581987572104929234984377		// pi/4
#define K_PI_2			1.5707963267948966192313216916397514420985846996875		// pi/2
#ifndef K_PI
#define K_PI			3.1415926535897932384626433832795028841971693993751		// pi
#endif
#define K_2PI_3			2.0943951023931954923084289221863352561314462662501		// 2pi/3
#define K_2PI			6.2831853071795864769252867665590057683943387987502		// 2pi
#define K_3PI			9.4247779607693797153879301498385086525915081981252		// 3pi
#define K_4PI			12.566370614359172953850573533118011536788677597500		// 4pi
#define K_5PI			15.707963267948966192313216916397514420985846996875		// 5pi
#define K_6PI			18.849555921538759430775860299677017305183016396250		// 6pi
#define K_7PI			21.991148575128552669238503682956520189380185795626		// 7pi
#define K_1_PI			.31830988618379067153776752674502872406891929148091		// 1/pi
#define K_1_4PI			.079577471545947667884441881686257181017229822870228	// 1/4pi
#define K_180_PI		57.295779513082320876798154814105170332405472466565		// 180/pi

#define K_GAMMA			.57721566490153286060651209008240243104215933593992		// Euler-Mascheroni constant
#define K_ZETA3			1.2020569031595942853997381615114499907649862923405		// Apery's constant
#define K_G				.91596559417721901505460351493238411077414937428167		// Catalan's constant
#define K_KDB			2.6854520010653064453097148354817956938203822939945		// Khintchine's constant
#define K_C				1.2267420107203532444176302304553616558714096904403		// Fibonacci's factorial constant
#define K_GOLDEN_RATIO	1.6180339887498948482045868343656381177203091798058		// golden ratio
#define K_GOLDEN_SECT	.38196601125010515179541316563436188227969082019424		// 2 - golden ratio
#define K_F1			4.6692016091029906718532038204662016172581855774758		// Feigenbaum's F1
#define K_F2			2.5029078750958928222839028732182157863812713767271		// Feigenbaum's F2
#define K_L				.11000100000000000000000100000000000000000000000000		// Liouville's number
#ifndef K_TEN
#define K_TEN			10														// 10
#endif

#define K_GOMPERTZ		.5963473623231940										// Gompertz constant (-e*ei(-1))
#define K_EI_LN2		1.0451637801174927847465120900824024310421593359399		// ei(ln(2))

#define K_EXPGAMMA		1.7810724179901979852365041031071795491696452143034		// exp(gamma)
#define K_EXPE			15.154262241479264189760430272629911905528548536856		// exp(e)
#define K_EXPPI			23.140692632779269005729086367948547380266106242600		// exp(pi)
#define K_PIEXP			22.459157718361045473427152204543735027589315133997		// pi^^e

#define K_SQRT2_4		.35355339059327376220042218105242451964241796884424		// sqrt(2)/4
#define K_SQRT3_3		.57735026918962576450914878050195745564760175127013		// sqrt(3)/3
#define K_SQRT6_3		.81649658092772603273242802490196379732198249355222		// sqrt(6)/3
#define K_SQRT6_4		.61237243569579452454932101867647284799148687016417		// sqrt(6)/4
#define K_SQRT6_6		.40824829046386301636621401245098189866099124677611		// sqrt(6)/6
#define K_SQRT2_2		.70710678118654752440084436210484903928483593768847		// sqrt(2)/2
#define K_SQRT3_2		.86602540378443864676372317075293618347140262690519		// sqrt(3)/2
#define K_SQRT2			1.4142135623730950488016887242096980785696718753769		// sqrt(2)
#define K_SQRTE			1.6487212707001281468486507878141635716537761007101		// sqrt(e)
#define K_SQRT3			1.7320508075688772935274463415058723669428052538104		// sqrt(3)
#define K_SQRTPI		1.7724538509055160272981674833411451827975494561224		// sqrt(pi) = gamma(1/2)
#define K_SQRT5			2.2360679774997896964091736687312762354406183596115		// sqrt(5)
#define K_SQRT6			2.4494897427831780981972840747058913919659474806567		// sqrt(6)

#define K_1_SQRTPI		.56418958354775628694807945156077258584405062932900		// 1/sqrt(pi)

#define K_CBRT2			1.2599210498948731647672106072782283505702514647015		// cbrt(2)
#define K_CBRT3			1.4422495703074083823216383107801095883918692534994		// cbrt(3)
#define K_CBRT5			1.7099759466766969893531088725438601098680551105431		// cbrt(5)

#define K_FTRT2			1.1486983549970350067986269467779275894438508890978		// 2^(1/5)
#define K_FTRT3			1.2457309396155173259666803366403050809393099930688		// 3^(1/5)

#ifndef K_LN2
#define K_LN2			.69314718055994530941723212145817656807550013436026		// ln(2)
#endif
#define K_LN3			1.0986122886681096913952452369225257046474905578227		// ln(3)
#ifndef K_LN10
#define K_LN10			2.3025850929940456840179914546843642076011014886288		// ln(10)
#endif

#define K_1_LN2			1.4426950408889634073599246810018921374266459541530		// 1/ln(2)
#define K_1_LN3			.91023922662683739361424016573610700061263605725521		// 1/ln(3)
#define K_1_LN10		.43429448190325182765112891891660508229439700580367		// 1/ln(10)

#ifndef K_L2E
#define K_L2E			1.4426950408889634073599246810018921374266459541530		// log2(e)
#endif
#define K_L23			1.5849625007211561814537389439478165087598144076925		// log2(3)
#ifndef K_L2T
#define K_L2T			.30102999566398119521373889472449302676818988146210		// log2(10)
#endif

#define K_1_L2E			.69314718055994530941723212145817656807550013436025		// 1/log2(e)
#define K_1_L23			.63092975357145743709952711434276085429958564013188		// 1/log2(3)
#define K_1_L2T			1.4426950408889634073599246810018921374266459541530		// 1/log2(10)

#ifndef K_LOG2
#define K_LOG2			.30102999566398119521373889472449302676818988146211		// log10(2)
#endif
#ifndef K_LOGE
#define K_LOGE			.43429448190325182765112891891660508229439700580367		// log10(e)
#endif
#define K_LOG3			.47712125471966243729502790325511530920012886419070		// log10(3)
#define K_LOGPI			.49714987269413385435126828829089887365167832438044		// log10(pi)

#define K_DDRT2			1.0594630943592952645618252949463417007792043174942		// 2^(1/12)
#define K_1_DDRT2		.94387431268169349664191315666753437600756830333874		// 1/(2^(1/12))

#define K_20LOG128		42.144199392957367329923445261429023747546583404695		// 20log10(128)
#define K_20LOG32768	90.308998699194358564121668417347908030456964438633		// 20log10(32768)
#define K_20LOG8388608	138.47379800543134979831989157326679231336734547257		// 20log10(8388608)

#define K_1E0			K_ONE
#define K_1E1			K_TEN

#ifndef K_1E2
#define K_1E2			E+2														// 10^2
#endif
#ifndef K_1E4
#define K_1E4			E+4														// 10^4
#endif
#ifndef K_1E8
#define K_1E8			E+8														// 10^8
#endif
#ifndef K_1E16
#define K_1E16			E+16													// 10^16
#endif
#ifndef K_1E32
#define K_1E32			E+32													// 10^32
#endif
#ifndef K_1E64
#define K_1E64			E+64													// 10^64
#endif
#ifndef K_1E128
#define K_1E128			E+128													// 10^128
#endif
#ifndef K_1E256
#define K_1E256			E+256													// 10^256
#endif
#ifndef K_1E512
#define K_1E512			E+512													// 10^512
#endif
#ifndef	K_1E1024
#define K_1E1024		E+1024													// 10^1024
#endif
#ifndef K_1E2048
#define K_1E2048		E+2048													// 10^2048
#endif
#ifndef K_1E4096
#define K_1E4096		E+4096													// 10^4096
#endif

//*****************************************************************************************************************
//	unit scales
//*****************************************************************************************************************

#define K_YOCTO			E-24	// y
#define K_ZEPTO			E-21	// z
#define K_ATTO			E-18	// a
#define K_FEMTO			E-15	// f
#define K_PICO			E-12	// p
#define K_NANO			E-9		// n
#define K_MICRO			E-6		// u
#define K_MILLI			E-3		// m
#define K_CENTI			E-2		// c
#define K_DECI			E-1		// d
#define K_DECA			E+1		// da, dk (DEKA)
#define K_HECTO			E+2		// h
#define K_KILO			E+3		// k
#define K_MEGA			E+6		// M
#define K_GIGA			E+9		// G
#define K_TERA			E+12	// T
#define K_PETA			E+15	// P
#define K_EXA			E+18	// E
#define K_ZETTA			E+21	// Z
#define K_YOTTA			E+24	// Y

//*****************************************************************************************************************
//	angular units
//*****************************************************************************************************************

#define K_DEG_TO_RAD	K_PI_180												// pi/180
#define K_DEG_TO_CIRC	.0027777777777777777777777777777777777777777777777778	// 1/360
#define K_RAD_TO_DEG	K_180_PI												// 180/pi
#define K_RAD_TO_CIRC	K_PI_2													// pi/2
#define K_CIRC_TO_DEG	360														// 360

#define K_STERADIAN		K_1_4PI													// sphere/st

//*****************************************************************************************************************
//	distance units
//*****************************************************************************************************************

#define K_IN_TO_CM		2.5400000000000000000000000000000000000000000000000		// cm/in
#define K_CM_TO_IN		.39370078740157480314960629921259842519685039370079		// in/cm

#define K_FT_TO_M		.30480000000000000000000000000000000000000000000000		// m/ft
#define K_M_TO_FT		3.2808398950131233595800524934383202099737532808399		// ft/m

#define K_MILE_TO_KM	1.6093440000000000000000000000000000000000000000000		// km/mile
#define K_KM_TO_MILE	.62137119223733396961743418436331822158593812137119		// mile/km

#define K_KNOT_TO_KM	1.8531840												// km/knot
#define K_KM_TO_KNOT	.53961182483768476308882442326288161348252521066446		// knot/km

#define K_FEET_TO_INCHES		12
#define K_YARDS_TO_FEET			3
#define K_CHAINS_TO_YARDS		22
#define K_FURLONGS_TO_CHAINS	10
#define K_MILES_TO_FURLONG		8

//*****************************************************************************************************************
//	surface units
//*****************************************************************************************************************

#define K_FT2_TO_M2		.09290304000000000000000000000000000000000000000000		// m^2/ft^2
#define K_M2_TO_FT2		10.763910416709722308333505555900000688890266669422		// ft^2/m^2
#define K_ACRE_TO_M2	4046.86													// acre/m^2
#define K_HECTARE_TO_M2	10000													// hectare/m^2

//*****************************************************************************************************************
//	volume units
//*****************************************************************************************************************

#define K_UKGAL_TO_M3	4.546e-3												// gal/m^3
#define K_USGAL_TO_M3	3.785e-3												// gal/m^3

//*****************************************************************************************************************
//	capacity units
//*****************************************************************************************************************

#define K_US_PINTS_TO_OUNCES	16
#define K_UK_PINTS_TO_OUNCES	20
#define K_PINTS_TO_GILLS		4
#define K_QUART_TO_PINTS		2
#define K_GALLONS_TO_QUARTS		4
#define K_PECKS_TO_QUARTS		8
#define K_BUSHELS_TO_PECKS		4

//*****************************************************************************************************************
//	speed units
//*****************************************************************************************************************

#define K_MPH_TO_KMH	K_MILE_TO_KM											// kmh / mph
#define K_KMH_TO_MPH	K_KM_TO_MILE											// mph / kmh

//*****************************************************************************************************************
//	mass (Troy and Avoirdupois) units
//*****************************************************************************************************************

#define K_OZ_TO_G		.028349523125											// g/oz

#define K_LB_TO_KG		.45359237												// kg/lb
#define K_KG_TO_LB		2.20462262												// lb/kg

#define K_OUNCES_TO_GRAINS			437.5
#define K_POUNDS_TO_OUNCES			16
#define K_STONES_TO_POUNDS			14
#define K_CWT_TO_STONES				8		// (cwt = hundredweight)
#define K_UKTONS_TO_CWT				20

#define K_UKTONS_TO_POUNDS			2240
#define K_USTON_TO_POUNDS			2000

#define K_PENNYWEIGHTS_TO_GRAINS	24
#define K_OUNCES_TO_PENNYWEIGHTS	20

//*****************************************************************************************************************
//	temperature units
//*****************************************************************************************************************

#define K_F_TO_C(f)		(1.8 * f + 32)											// 'F -> 'C
#define K_C_TO_K(c)		(c + 273.16)											// 'C -> 'K
#define K_C_TO_F(c)		((c - 32) * (.55555555555555555555555555555555555555555555555556)) // 'C -> 'F

//*****************************************************************************************************************
//	force units
//*****************************************************************************************************************

#define K_HP_TO_W		745.71216												// w/hp
#define K_W_TO_HP		.0013410												// hp/w

//*****************************************************************************************************************
//	pressure units
//*****************************************************************************************************************

#define K_ATM_TO_PA		101325													// Pa/atm

//*****************************************************************************************************************
//	ratio units
//*****************************************************************************************************************

#define K_BELL(r)		(20*kLog10(r))											// B(r)
#define K_DECIBEL(r)	(2*kLog10(r))											// dB(r)

//*****************************************************************************************************************
//	physical constants
//*****************************************************************************************************************

#define K_LSPEED		299792458												// speed of light in vacuum (m/s)

#define K_AIR_SSPEED21	344 /*340.29205*/										// air speed of sound at 21'C (m/s)
#define K_WATER_SSPEED	1480													// water speed of sound (m/s)
#define K_AIR_SSPEED(t)	((20.0330)*kSqrt(t))									// speed of sound at t'K (331*sqrt(t/273))

#define K_GRAV_CONST	9.80665													// terrestrial gravitational constant g

//*****************************************************************************************************************
//	material constants
//*****************************************************************************************************************

#define K_REFRAC_AIR		1.000298											// air refraction index
#define K_REFRAC_DIAMOND	2.42												// diamond refraction index
#define K_REFRAC_GLASS		1.50												// glass refraction index
#define K_REFRAC_ICE		1.31												// ice refraction index
#define K_REFRAC_PARAFFIN	1.42												// paraffin refraction index
#define K_REFRAC_RUBY		1.76												// ruby refraction index
#define K_REFRAC_WATER		1.33												// water refraction index

//*****************************************************************************************************************
//	media constants
//*****************************************************************************************************************

/*
 * Never Twice the Same Colour
 */
#define K_NTSC_RATE			30
#define K_NTSC_LINES		525
#define K_NTSC_GAMMA		2.2

#define K_MNTSC_RATE		29.97002617
#define K_MNTSC_LINES		525
#define K_MNTSC_GAMMA		2.2

/*
 * Pay for Added Luxury
 */
#define K_PAL_RATE			25
#define K_PAL_LINES			625
#define K_PAL_GAMMA			2.8

#define K_MPAL_RATE			K_MNTSC_RATE
#define K_MPAL_LINES		K_MNTSC_LINES
#define K_MPAL_GAMMA		K_PAL_GAMMA

/*
 * System Essentially Contrary to American Method
 */
#define K_SECAM_RATE		25
#define K_SECAM_LINES		625
#define K_SECAM_GAMMA		2.8

#define K_MSECAM_RATE		K_MNTSC_RATE
#define K_MSECAM_LINES		K_MNTSC_LINES
#define K_MSECAM_GAMMA		K_MPAL_GAMMA

#define K_FILM_RATE			24

#define K_HIVISION_RATE		60
#define K_HIVISION_LINES	1125

//*****************************************************************************************************************
//	primes up to 65535
//*****************************************************************************************************************

extern const kUInt16 kPrimes[6542];

#endif // FBXFILESDK_COMPONENTS_KBASELIB_KMATH_CONST_H

