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

#ifndef FBXFILESDK_COMPONENTS_KBASELIB_KMATH_KGEOM_H
#define FBXFILESDK_COMPONENTS_KBASELIB_KMATH_KGEOM_H

#include <fbxfilesdk/components/kbaselib/kbaselib_h.h>

#ifndef KFBX_PLUGIN
    #include <fbxfilesdk/components/kbaselib/klib/kdebug.h>
#else
    // -- Since kdebug.h include kaydara.h and that many warning have been
    // -- disabled for practical reason. Include kaydara.h for disabling warning only.
    #include <fbxfilesdk/components/kbaselib/kaydara.h>
#endif

#include <fbxfilesdk/components/kbaselib/kmath/kmath.h>


#include <fbxfilesdk/fbxfilesdk_nsbegin.h>

    class KFBX_DLL KgeVertex;
    class KFBX_DLL KgeTVector;
    class KFBX_DLL KgeRGBVector;
    class KFBX_DLL KgeRGBAVector;
    class KFBX_DLL KgeRVector;
    class KFBX_DLL KgeSVector;
    class KFBX_DLL KgeQuaternion;
    class KFBX_DLL KgeMatrix;
    class KFBX_DLL KgeAMatrix;
    class KFBX_DLL KgeRMatrix;
    class KFBX_DLL KgeTMatrix;
    class KFBX_DLL KgeSMatrix;
    class KFBX_DLL KgeXForm;

    typedef KgeTVector KgeVector;

    class KFBX_DLL KgeVertex {
    public:
	    kOGLFloat	x;
	    kOGLFloat	y;
	    kOGLFloat	z;
	    kOGLFloat	w;
	    K_INLINE KgeVertex()
	    {
		    w = 1;
	    }
	    K_INLINE KgeVertex(kOGLFloat px, kOGLFloat py, kOGLFloat pz, kOGLFloat pw = 1)
	    {
		    x = px;
		    y = py;
		    z = pz;
		    w = pw;
	    }
    };

    class KFBX_DLL KgeTVector {

    public:
	    double	mData[4];

	    inline KgeTVector();
	    inline KgeTVector(const double pN0, const double pN1, const double pN2);
	    inline KgeTVector(const double *const pVi);
	    inline KgeTVector(const float *const pVi);
	    inline KgeTVector(const KgeTVector& pVi);
	    inline KgeTVector(const KgeAMatrix& pAi);
	    inline KgeTVector(const KgeTMatrix& pAi);
	    inline KgeTVector& Init();
	    inline KgeTVector& operator=(const double *const pVi);
	    inline KgeTVector& operator=(const float *const pVi);
	    inline KgeTVector& operator=(const KgeTVector& pVi);
	    inline operator const double *() const;

		inline bool operator==(const KgeTVector& pVi) const;
		inline bool operator!=(const KgeTVector& pVi) const;

    	double& operator[](int pIndex) { return mData[pIndex]; }

    private:
	    /*** The following methods are NOT functional
	        They're just there to detect coding errors at compilation time ***/
	    inline KgeTVector operator + (const KgeTVector &pVector) const; // Not functional; please use KgeAdd instead.
        inline KgeTVector operator - (const KgeTVector &pVector) const; // Not functional; please use KgeSub instead.
        inline KgeTVector operator * (const KgeTVector &pVector) const; // Not functional; please use KgeMult instead.
        inline double  operator ^ (const KgeTVector &pVector) const; // scalar product // Not functional; please use KgeDot instead.
        inline KgeTVector &operator += (const KgeTVector &pVector); // Not functional; please use KgeAdd instead.
        inline KgeTVector &operator -= (const KgeTVector &pVector); // Not functional; please use KgeSub instead.
        inline KgeTVector &operator *= (const KgeTVector &pVector); // Not functional; please use KgeMult instead.

        inline KgeTVector operator * (double pScalar) const; // Not functional; please use KgeMult instead.
        inline KgeTVector operator / (double pScalar) const; // Not functional; please use KgeMult instead.
        inline KgeTVector &operator *= (double pScalar); // Not functional; please use KgeMult instead.
        inline KgeTVector &operator /= (double pScalar); // Not functional; please use KgeMult instead.

    };


    class KFBX_DLL KgeRGBAVector {

    public:
	    double	mData[4];

	    inline KgeRGBAVector ();
	    inline KgeRGBAVector (const double pR, const double pG, const double pB, const double pA);
	    inline KgeRGBAVector (const double *const pVi);
	    inline KgeRGBAVector (const KgeRGBAVector& pVi);
	    inline KgeRGBAVector & Init();
	    inline KgeRGBAVector & operator=(const double *const pVi);
	    inline KgeRGBAVector & operator=(const KgeRGBAVector& pVi);
	    inline operator const double *() const;

		inline bool operator==(const KgeRGBAVector& pVi) const;
		inline bool operator!=(const KgeRGBAVector& pVi) const;

    private:
	    /*** The following methods are NOT functional
	        They're just there to detect coding errors at compilation time ***/
	    inline KgeRGBAVector operator + (const KgeRGBAVector &/*pVector*/) const {KgeRGBAVector lNullVector; return lNullVector;}
        inline KgeRGBAVector operator - (const KgeRGBAVector &/*pVector*/) const {KgeRGBAVector lNullVector; return lNullVector;}
        inline KgeRGBAVector operator * (const KgeRGBAVector &/*pVector*/) const {KgeRGBAVector lNullVector; return lNullVector;}
        inline double  operator ^ (const KgeRGBAVector &/*pVector*/) const {return 0.0;}
        inline KgeRGBAVector &operator += (const KgeRGBAVector &/*pVector*/) {return *this;}
        inline KgeRGBAVector &operator -= (const KgeRGBAVector &/*pVector*/) {return *this;}
        inline KgeRGBAVector &operator *= (const KgeRGBAVector &/*pVector*/) {return *this;}

        inline KgeRGBAVector operator * (double /*pScalar*/) const {KgeRGBAVector lNullVector; return lNullVector;}
        inline KgeRGBAVector operator / (double /*pScalar*/) const {KgeRGBAVector lNullVector; return lNullVector;}
        inline KgeRGBAVector &operator *= (double /*pScalar*/) {return *this;}
        inline KgeRGBAVector &operator /= (double /*pScalar*/) {return *this;}
    };

    class KFBX_DLL KgeRGBVector {

    public:
	    double	mData[4];

	    inline KgeRGBVector ();
	    inline KgeRGBVector (const double pR, const double pG, const double pB );
	    inline KgeRGBVector (const double *const pVi);
	    inline KgeRGBVector (const KgeRGBVector& pVi);
	    inline KgeRGBVector (const KgeRGBAVector& pVi);
	    inline KgeRGBVector & Init();
	    inline KgeRGBVector & operator=(const double *const pVi);
	    inline KgeRGBVector & operator=(const KgeRGBAVector& pVi);
	    inline KgeRGBVector & operator=(const KgeRGBVector& pVi);
	    inline operator const double *() const;

		inline bool operator==(const KgeRGBVector& pVi) const;
		inline bool operator!=(const KgeRGBVector& pVi) const;

    private:
	    /*** The following methods are NOT functional
	        They're just there to detect coding errors at compilation time ***/
	    inline KgeRGBVector operator + (const KgeRGBVector &/*pVector*/) const {KgeRGBVector lNullVector; return lNullVector;}
        inline KgeRGBVector operator - (const KgeRGBVector &/*pVector*/) const {KgeRGBVector lNullVector; return lNullVector;}
        inline KgeRGBVector operator * (const KgeRGBVector &/*pVector*/) const {KgeRGBVector lNullVector; return lNullVector;}
        inline double  operator ^ (const KgeRGBVector &/*pVector*/) const {return 0.0;}
        inline KgeRGBVector &operator += (const KgeRGBVector &/*pVector*/) {return *this;}
        inline KgeRGBVector &operator -= (const KgeRGBVector &/*pVector*/) {return *this;}
        inline KgeRGBVector &operator *= (const KgeRGBVector &/*pVector*/) {return *this;}

        inline KgeRGBVector operator * (double /*pScalar*/) const {KgeRGBVector lNullVector; return lNullVector;}
        inline KgeRGBVector operator / (double /*pScalar*/) const {KgeRGBVector lNullVector; return lNullVector;}
        inline KgeRGBVector &operator *= (double /*pScalar*/) {return *this;}
        inline KgeRGBVector &operator /= (double /*pScalar*/) {return *this;}
    };



    class KFBX_DLL KgeRVector {

    public:
	    double mData[3];

	    inline KgeRVector();
	    inline KgeRVector(const double pN0, const double pN1, const double pN2);
	    inline KgeRVector(const double *const pVi);
	    inline KgeRVector(const KgeRVector& pVi);
	    inline KgeRVector(const KgeAMatrix& pAi);
	    inline KgeRVector(const KgeRMatrix& pRi);
	    inline KgeRVector(const KgeRMatrix& pRi, const int pOrd);
	    inline KgeRVector(const KgeQuaternion& pQi);
	    inline KgeRVector(const KgeQuaternion& pQi, const int pOrd);
	    inline KgeRVector& Init();
	    inline KgeRVector& operator=(const double *const pVi);
	    inline KgeRVector& operator=(const KgeRVector& pVi);
	    inline operator const double *() const;
		inline bool operator==(const KgeRVector& pVi) const;
		inline bool operator!=(const KgeRVector& pVi) const;
    };

    class KFBX_DLL KgeSVector {

    public:
	    double mData[3];

	    inline KgeSVector();
	    inline KgeSVector(const double pN);
	    inline KgeSVector(const double pN0, const double pN1, const double pN2);
	    inline KgeSVector(const double *const pVi);
	    inline KgeSVector(const KgeSVector& pVi);
	    inline KgeSVector(const KgeAMatrix& pAi);
	    inline KgeSVector(const KgeSMatrix& pSi);
	    inline KgeSVector& Init();
	    inline KgeSVector& operator=(const double *const pVi);
	    inline KgeSVector& operator=(const KgeSVector& pVi);
	    inline operator const double *() const;
		inline bool operator==(const KgeSVector& pVi) const;
		inline bool operator!=(const KgeSVector& pVi) const;
    };

    class KFBX_DLL KgeQuaternion {

    public:
	    double mData[4];

	    inline KgeQuaternion();
	    inline KgeQuaternion(const double pX, const double pY, const double pZ, const double pW);
	    inline KgeQuaternion(const double *const pVi);
	    inline KgeQuaternion(const KgeQuaternion& pVi);
	    inline KgeQuaternion(const KgeRVector& pVi);
	    inline KgeQuaternion(const KgeRVector& pVi, const int pOrd);
	    inline KgeQuaternion(const KgeAMatrix& pAi);
	    inline KgeQuaternion(const KgeRMatrix& pRi);
	    inline KgeQuaternion& Init();
	    inline KgeQuaternion& operator=(const double *const pVi);
	    inline KgeQuaternion& operator=(const KgeQuaternion& pVi);
	    inline operator const double *() const;
    };

    class KFBX_DLL KgeMatrix {

    public:
	    double mData[4][4];

	    inline KgeMatrix();
	    inline KgeMatrix(const double (*const pMi)[4]);
	    inline KgeMatrix(const KgeMatrix& pMi);
	    inline KgeMatrix& Init();
	    inline KgeMatrix& operator=(const double (*const pMi)[4]);
	    inline KgeMatrix& operator=(const KgeMatrix& pMi);
	    inline operator const double *() const;
    };

    class KFBX_DLL KgeAMatrix {

    public:
	    double mData[4][4];

	    inline KgeAMatrix();
	    inline KgeAMatrix(const KgeTVector& pTi);
	    inline KgeAMatrix(const KgeRVector& pRi);
	    inline KgeAMatrix(const KgeRVector& pRi, const int pOrd);
	    inline KgeAMatrix(const KgeSVector& pSi);
	    inline KgeAMatrix(const KgeTVector& pTi, const KgeRVector& pRi);
	    inline KgeAMatrix(const KgeTVector& pTi, const KgeRVector& pRi, const int pOrd);
	    inline KgeAMatrix(const KgeTVector& pTi, const KgeQuaternion& pQi);
	    inline KgeAMatrix(const KgeTVector& pTi, const KgeRVector& pRi, const KgeSVector& pSi);
	    inline KgeAMatrix(const KgeTVector& pTi, const KgeRVector& pRi, const KgeSVector& pSi, const int pOrd);
	    inline KgeAMatrix(const KgeTVector& pTi, const KgeQuaternion& pQi, const KgeSVector& pSi);
	    inline KgeAMatrix(const double (*const pAi)[4]);
	    inline KgeAMatrix(const KgeAMatrix& pAi);
	    inline KgeAMatrix& Init();
	    inline KgeAMatrix& operator=(const double (*const pAi)[4]);
	    inline KgeAMatrix& operator=(const KgeAMatrix& pAi);
	    inline operator const double *() const;
    };

    class KFBX_DLL KgeTMatrix {

    public:
	    double mData[4][4];
    	
	    inline KgeTMatrix();
	    inline KgeTMatrix(const double pX, const double pY, const double pZ);
	    inline KgeTMatrix(const double (*const pTi)[4]);
	    inline KgeTMatrix(const KgeTMatrix& pTi);
	    inline KgeTMatrix& Init();
	    inline KgeTMatrix& operator=(const double (*const pTi)[4]);
	    inline KgeTMatrix& operator=(const KgeTMatrix& pTi);
	    inline operator const double *() const;
    };

    class KFBX_DLL KgeRMatrix {

    public:
	    double mData[4][4];

	    inline KgeRMatrix();
	    inline KgeRMatrix(const double pX, const double pY, const double pZ);
	    inline KgeRMatrix(const double pI, const double pJ, const double pK, const int pOrd);
	    inline KgeRMatrix(const KgeRVector& pVi);
	    inline KgeRMatrix(const KgeRVector& pVi, const int pOrd);
	    inline KgeRMatrix(const double (*const pRi)[4]);
	    inline KgeRMatrix(const KgeRMatrix& pRi);
	    inline KgeRMatrix(const KgeQuaternion& pQi);
	    inline KgeRMatrix& Init();
	    inline KgeRMatrix& operator=(const double (*const pRi)[4]);
	    inline KgeRMatrix& operator=(const KgeRMatrix& pRi);
	    inline operator const double *() const;
    };

    class KFBX_DLL KgeSMatrix {

    public:
	    double mData[4][4];

	    inline KgeSMatrix();
	    inline KgeSMatrix(const double pXYZ);
	    inline KgeSMatrix(const double pX, const double pY, const double pZ);
	    inline KgeSMatrix(const double (*const pSi)[4]);
	    inline KgeSMatrix(const KgeSMatrix& pSi);
	    inline KgeSMatrix& Init();
	    inline KgeSMatrix& operator=(const double (*const pSi)[4]);
	    inline KgeSMatrix& operator=(const KgeTMatrix& pSi);
	    inline operator const double *() const;
    };

    class KFBX_DLL KgeLUMatrix {

    public:
	    double mData[5][4];

	    inline KgeLUMatrix();
	    inline KgeLUMatrix(const KgeMatrix& pMi);
	    inline KgeLUMatrix& Init();
	    inline operator const double *() const;
    };

    class KFBX_DLL KgeXForm {

	    friend inline KgeXForm& KgeMult(KgeXForm& pTo, KgeXForm& pTiA, KgeXForm& pTiB);
	    friend inline KgeXForm& KgeInvMult(KgeXForm& pTo, KgeXForm& pTiA, KgeXForm& pTiB);

	    KgeAMatrix		mM;
	    KgeQuaternion	mQ;
	    KgeRVector		mR;

	    enum {

		    FLAG_M =	1,
		    FLAG_R =	2,
		    FLAG_Q =	4,
		    FLAG_A =	FLAG_M | FLAG_R | FLAG_Q
	    };
	    int		mF;

    public:
	    inline KgeXForm();

	    inline KgeXForm(const KgeTVector& pTi);
	    inline KgeXForm(const KgeRVector& pRi);
	    inline KgeXForm(const KgeRVector& pRi, const int pOrd);
	    inline KgeXForm(const KgeSVector& pSi);
	    inline KgeXForm(const KgeTVector& pTi, const KgeRVector& pRi);
	    inline KgeXForm(const KgeTVector& pTi, const KgeRVector& pRi, const int pOrd);
	    inline KgeXForm(const KgeTVector& pTi, const KgeQuaternion& pQi);
	    inline KgeXForm(const KgeTVector& pTi, const KgeRVector& pRi, const KgeSVector& pSi);
	    inline KgeXForm(const KgeTVector& pTi, const KgeRVector& pRi, const KgeSVector& pSi, const int pOrd);
	    inline KgeXForm(const KgeTVector& pTi, const KgeQuaternion& pQi, const KgeSVector& pSi);
	    inline KgeXForm(const double (*const pAi)[4]);
	    inline KgeXForm(const KgeAMatrix& pAi);
    	
	    inline KgeXForm(KgeXForm& pX);
	    inline ~KgeXForm();

	    inline KgeXForm& Init();

	    inline KgeXForm& operator=(const KgeXForm& pXi);
	    inline KgeXForm& operator=(const KgeAMatrix& pAi);
	    inline KgeXForm& operator=(const KgeRMatrix& pRi);
	    inline KgeXForm& operator=(const KgeTMatrix& pTi);
	    inline KgeXForm& operator=(const double (*const pMi)[4]);

	    inline const KgeAMatrix& GetM();
	    inline const KgeTVector& GetT() const;
	    inline const KgeTVector& GetI();
	    inline const KgeTVector& GetJ();
	    inline const KgeTVector& GetK();
	    inline double GetTX() const;
	    inline double GetTY() const;
	    inline double GetTZ() const;
	    inline const KgeRVector& GetR();
	    inline const KgeRVector& GetR(KgeRVector& pRo, const int pOrd);
	    inline double GetRX();
	    inline double GetRY();
	    inline double GetRZ();
	    inline const KgeQuaternion& GetQ();

	    inline const KgeAMatrix& SetM(const KgeAMatrix& pM);
	    inline const KgeTVector& SetT(const KgeTVector& pT);
	    inline const KgeTVector& SetT(const double pVx, const double pVy, const double pVz);
	    inline double SetTX(const double pVx);
	    inline double SetTY(const double pVy);
	    inline double SetTZ(const double pVz);
	    inline const KgeRVector& SetR(const KgeRVector& pR);
	    inline const KgeRVector& SetR(const KgeRVector& pR, const int pOrd);
	    inline const KgeRVector& SetR(const double pVx, const double pVy, const double pVz);
	    inline double SetRX(const double pVx);
	    inline double SetRY(const double pVy);
	    inline double SetRZ(const double pVz);
	    inline const KgeQuaternion& SetQ(const KgeQuaternion& pQ);

	    inline KgeXForm& operator*=(const KgeXForm& pXi);
	    inline KgeXForm& operator/=(const KgeXForm& pXi);
    };

    class KRect
    {
    public: 
	    int mX;
	    int mY;
	    int mW;
	    int mH;

	    KRect();
	    KRect(int pX, int pY, int pW, int pH);

	    //! Get Left coord of rect
    	int GetLeft()const;
	    //! Get Right coord of rect
	    int GetRight()const;
	    //! Get Bottom coord of rect
	    int GetBottom()const;
	    //! Get Top coord of rect
	    int GetTop()const;

	    //! Union of two rectangles.
	    void Union(const KRect& pRect);
	    //! Intersection between two rectangles.
	    void Intersection(const KRect& pRect);
	    //! Point inside rectangle.
	    bool PointInside(int pX, int pY);
	    //! Is intersection non-empty ?
	    bool HasAnIntersection(const KRect& pRect) const;
	    //! StrictlyContains: pRect is inside this Rect and does not touch any side.
	    bool StrictlyContains(const KRect& pRect) const;
	    // StrictlyIntersects: pRect crosses or overlaps one of the sides of this Rect.
	    bool StrictlyIntersects(const KRect& pRect) const; 
	    //! Translate rectangle.
	    void Translate(int pDeltaX, int pDeltaY);
    };


    // Use this to cast a double[4][4] to a KgeAMatrix
    #define KgeA_Cast(x) (*((KgeAMatrix*)(double*)x))

    // Use this to cast a double[4] to a KgeVector
    #define KgeV_Cast(x) (*((KgeVector*)(double*)x))

    ////////////////////////////////////////////////////////////////////////////////
    //
    //	Vector Utilities
    //
    ////////////////////////////////////////////////////////////////////////////////

    /*
    *	KgeLength : Vector Length
    */
    inline double KgeLength(const KgeVector& pVi)
    {
	    return KmVlength(pVi.mData);
    }

    /*
    *	KgeLength : Vector Length
    */
    inline double KgeLength(const KgeVertex& pVi)
    {
	    return Kmvlength( &(pVi.x) );
    }


    /*
    *	KgeLength2 : Vector Squared Length
    */
    inline double KgeLength2(const KgeVector& pVi)
    {
	    return KmVlength2(pVi.mData);
    }

    /*
    *	KgeDist : Vector Distance
    */
    inline double KgeDist(const KgeVector& pViA, const KgeVector& pViB)
    {
	    return KmVdist(pViA.mData, pViB.mData);
    }

    /*
    *	KgeDot : Vector Dot Product
    */
    inline double KgeDot(const KgeVector& pViA, const KgeVector& pViB)
    {
	    return KmVdotV(pViA.mData, pViB.mData);
    }

    /*
    *	KgeDot
    */
    inline float KgeDot( const KgeVertex& pViA, const KgeVertex& pViB )
    {
	    return KmVdotV( &(pViA.x), &(pViB.x));
    }

    /*
    *	KgeCompare : Translation Vector Compare
    */
    inline int KgeCompare(const KgeTVector& pViA, const KgeTVector& pViB, const double pThreshold = KM_TOLERANCE)
    {
	    return KmVcmp(pViA.mData, pViB.mData, pThreshold);
    }

    /*
    *	KgeCompare : Translation RGB Compare
    */
    inline int KgeCompare(const KgeRGBVector& pViA, const KgeRGBVector& pViB, const double pThreshold = KM_TOLERANCE)
    {
	    return KmVcmp(pViA.mData, pViB.mData, pThreshold);
    }

    /*
    *	KgeCompare : Vertex Compare
    */
    inline int KgeCompare(const KgeVertex& pViA, const KgeVertex& pViB, const kOGLFloat pThreshold = KM_TOLERANCE)
    {
	    return Kmvcmp( &(pViA.x), &(pViB.x), pThreshold);  
    }


    /*
    *	KgeCompare : Rotation Vector Compare
    */
    inline int KgeCompare(const KgeRVector& pViA, const KgeRVector& pViB, const double pThreshold = KM_TOLERANCE)
    {
	    return KmRVcmp(pViA.mData, pViB.mData, pThreshold);
    }

    /*
    *	KgeCompare : Scaling Vector Compare
    */
    inline int KgeCompare(const KgeSVector& pViA, const KgeSVector& pViB, const double pThreshold = KM_TOLERANCE)
    {
	    return KmVcmp(pViA.mData, pViB.mData, pThreshold);
    }

    ////////////////////////////////////////////////////////////////////////////////
    //
    //	Vector Initialization
    //
    ////////////////////////////////////////////////////////////////////////////////

    /*
    *	KgeSet : Set Vector
    */
    inline KgeTVector& KgeSet(KgeTVector& pVo, const double pN0, const double pN1, const double pN2)
    {
	    return *(KgeTVector *) KmV(pVo.mData, pN0, pN1, pN2);
    }

    /*
    *	KgeSet : Set Vector
    */
    inline KgeTVector& KgeSet(KgeTVector& pVo, const double pN)
    {
	    return *(KgeTVector *) KmV(pVo.mData, pN, pN, pN);
    }

    /*
    *	KgeSet : Set Vector
    */
    inline KgeTVector& KgeSet(KgeTVector& pVo, const KgeTVector& pVi)
    {
	    return *(KgeTVector *) KmVset(pVo.mData, pVi.mData);
    }

    /*
    *	KgeSet : Set Vector
    */
    inline KgeRVector& KgeSet(KgeRVector& pVo, const double pN0, const double pN1, const double pN2)
    {
	    return *(KgeRVector *) KmV(pVo.mData, pN0, pN1, pN2);
    }

    /*
    *	KgeSet : Set Vector
    */
    inline KgeRVector& KgeSet(KgeRVector& pVo, const double pN)
    {
	    return *(KgeRVector *) KmV(pVo.mData, pN, pN, pN);
    }

    /*
    *	KgeSet : Set Vector
    */
    inline KgeRVector& KgeSet(KgeRVector& pVo, const KgeRVector& pVi)
    {
	    return *(KgeRVector *) KmVset(pVo.mData, pVi.mData);
    }

    /*
    *	KgeSet : Set Vector
    */
    inline KgeSVector& KgeSet(KgeSVector& pVo, const double pN0, const double pN1, const double pN2)
    {
	    return *(KgeSVector *) KmV(pVo.mData, pN0, pN1, pN2);
    }

    /*
    *	KgeSet : Set Vector
    */
    inline KgeSVector& KgeSet(KgeSVector& pVo, const double pN)
    {
	    return *(KgeSVector *) KmV(pVo.mData, pN, pN, pN);
    }

    /*
    *	KgeSet : Set Vector
    */
    inline KgeSVector& KgeSet(KgeSVector& pVo, const KgeSVector& pVi)
    {
	    return *(KgeSVector *) KmVset(pVo.mData, pVi.mData);
    }


    /*
    *	KgeSet : Set Vertex
    */
    inline KgeVertex& KgeSet(KgeVertex& pVo, const KgeVertex& pVi)
    {
	    return *(KgeVertex *) KmVset( &(pVo.x), &(pVi.x));
    }

    /*
    *	KgeSet : Set Vertex from vector
    */
    inline KgeVertex& KgeSet(KgeVertex& pVo, const KgeVector& pVi)
    {
	    return *(KgeVertex *) KmVset( &(pVo.x), pVi.mData);
    }


    /*
    *	KgeSet : Set Vector from vertex
    */
    inline KgeTVector& KgeSet(KgeTVector& pVo, const KgeVertex& pVi)
    {
	    return *(KgeTVector *) KmVset( pVo.mData, &(pVi.x));
    }


    /*
    *	KgeSet : Set Vertex
    */
    inline KgeVertex& KgeSet(KgeVertex& pVo, const float x, const float y, const float z )
    {
	    return *(KgeVertex *) KmV( &(pVo.x), x, y, z); 
    }

    ////////////////////////////////////////////////////////////////////////////////
    //
    //	Vector Operations
    //
    ////////////////////////////////////////////////////////////////////////////////

    /*
    *	KgeNeg : Vector Negate
    */
    inline KgeVector& KgeNeg(KgeVector& pVo, KM_CONST KgeVector& pVi)
    {
	    return *(KgeVector *) KmVneg(pVo.mData, pVi.mData);
    }

    /*
    *	KgeAdd : Vector Add
    */
    inline KgeVector& KgeAdd(KgeVector& pVo, KM_CONST KgeVector& pViA, KM_CONST KgeVector& pViB)
    {
	    return *(KgeVector *) KmVadd(pVo.mData, pViA.mData, pViB.mData);
    }

    /*
    *	KgeAdd : Vertex Add
    */
    inline KgeVertex& KgeAdd(KgeVertex& pVo, KM_CONST KgeVertex& pViA, KM_CONST KgeVertex& pViB)
    {
	    return *(KgeVertex *) KmVadd( &(pVo.x), &(pViA.x), &(pViB.x) );
    }


    /*
    *	KgeSub : Vector Subtract
    */
    inline KgeVector& KgeSub(KgeVector& pVo, KM_CONST KgeVector& pViA, KM_CONST KgeVector& pViB)
    {
	    return *(KgeVector *) KmVsub(pVo.mData, pViA.mData, pViB.mData);
    }

    /*
    *	KgeSub : Vertex Subtract
    */
    inline KgeVector& KgeSub(KgeVector& pVo, KM_CONST KgeVertex& pViA, KM_CONST KgeVertex& pViB)
    {
	    return *(KgeVector *) KmVsub( pVo.mData, &(pViA.x), &(pViB.x) );
    }

    inline KgeVertex& KgeSub(KgeVertex& pVo, KM_CONST KgeVertex& pViA, KM_CONST KgeVertex& pViB)
    {
	    return *(KgeVertex *) KmVsub(&(pVo.x), &(pViA.x), &(pViB.x) );
    }

    /*
    *	KgeRev : Vector Reverse
    */
    inline KgeVector& KgeRev(KgeVector& pVo, KM_CONST KgeVector& pVi)
    {
	    return *(KgeVector *) KmVrev(pVo.mData, pVi.mData);
    }

    /*
    *	KgeVV : Vertex Cross Product
    */
    inline KgeVertex& KgeMult( KgeVertex& pVo, KM_CONST KgeVertex& pViA, KM_CONST KgeVertex& pViB )
    {
	    return *(KgeVertex*) Kmvv( &(pVo.x), &(pViA.x), &(pViB.x) );
    }


    /*
    *	KgeVV : Vector Cross Product
    */
    inline KgeVector& KgeMult(KgeVector& pVo, KM_CONST KgeVector& pViA, KM_CONST KgeVector& pViB)
    {
	    return *(KgeVector *) KmVV(pVo.mData, pViA.mData, pViB.mData);
    }


    /*
    *	KgeMult : Vertex Times Scalar
    */
    inline KgeVertex& KgeMult(KgeVertex& pVo, KM_CONST KgeVertex& pVi, const kOGLFloat pNi)
    {
	    return *(KgeVertex *) Kmvn( &(pVo.x), &(pVi.x), pNi);
    }


    /*
    *	KgeMult : Vector Times Scalar
    */
    inline KgeVector& KgeMult(KgeVector& pVo, KM_CONST KgeVector& pVi, const double pNi)
    {
	    return *(KgeVector *) KmVN(pVo.mData, pVi.mData, pNi);
    }


    /*
    *	KgeMult : RVector Times Scalar
    */
    inline KgeRVector& KgeMult(KgeRVector& pVo, KM_CONST KgeRVector& pVi, const double pNi)
    {
	    return *(KgeRVector *) KmVN(pVo.mData, pVi.mData, pNi);
    }


    /*
    *	KgeMult : SVector Times Scalar
    */
    inline KgeSVector& KgeMult(KgeSVector& pVo, KM_CONST KgeSVector& pVi, const double pNi)
    {
	    return *(KgeSVector *) KmVN(pVo.mData, pVi.mData, pNi);
    }




    /*
    *	KgeNorm : Vector Normalize
    */
    inline KgeVector& KgeNorm(KgeVector& pVo, KM_CONST KgeVector& pVi)
    {
	    return *(KgeVector *) KmVnorm(pVo.mData, pVi.mData);
    }

    /*
    *	KgeNorm : Vertex Normalize
    */
    inline KgeVertex& KgeNorm(KgeVertex& pVo, KM_CONST KgeVertex& pVi)
    {
	    return *(KgeVertex *) KmVnorm( &(pVo.x), &(pVi.x));
    }

    /*
    *	KgeMult : Matrix by Vector Product
    */
    inline KgeVector& KgeMult(KgeVector& pVo, const KgeMatrix& pMi, KM_CONST KgeVector& pVi)
    {
	    return *(KgeVector *) KmMV(pVo.mData, pMi.mData, pVi.mData);
    }

    /*
    *	KgeMult : Matrix by Vertex Product
    */
    inline KgeVertex& KgeMult(KgeVertex& pVo, const KgeMatrix& pMi, KM_CONST KgeVertex& pVi)
    {
	    return *(KgeVertex *) KmMv( &(pVo.x), pMi.mData, &(pVi.x) );
    }


    /*
    *	KgeMult : Affine Matrix by Vector Product
    */
    inline KgeVector& KgeMult(KgeVector& pVo, const KgeAMatrix& pAi, KM_CONST KgeVector& pVi)
    {
	    return *(KgeVector *) KmAV(pVo.mData, pAi.mData, pVi.mData);
    }

    /*
    *	KgeMult : Affine Matrix by Vertex Product
    */
    inline KgeVertex& KgeMult(KgeVertex& pvo, const KgeAMatrix& pAi, KM_CONST KgeVertex& pvi)
    {
	    return *(KgeVertex *) KmAv( &(pvo.x), pAi.mData, &(pvi.x) );
    }

    /*
    *	KgeMult : Translation Matrix by Vector Product
    */
    inline KgeVector& KgeMult(KgeVector& pVo, const KgeTMatrix& pTi, KM_CONST KgeVector& pVi)
    {
	    return *(KgeVector *) KmTV(pVo.mData, pTi.mData, pVi.mData);
    }

    /*
    *	KgeMult : Rotation Matrix by Vector Product
    */
    inline KgeVector& KgeMult(KgeVector& pVo, const KgeRMatrix& pRi, KM_CONST KgeVector& pVi)
    {
	    return *(KgeVector *) KmRV(pVo.mData, pRi.mData, pVi.mData);
    }

    /*
    *	KgeMult : Rotation Matrix by Vertex Product
    */
    inline KgeVertex& KgeMult(KgeVertex& pVo, const KgeRMatrix& pRi, KM_CONST KgeVertex& pVi)
    {
	    return *(KgeVertex *) KmRV( &(pVo.x), pRi.mData, &(pVi.x) );
    }


    /*
    *	KgeMult : Scaling Matrix by Vector Product
    */
    inline KgeVector& KgeMult(KgeVector& pVo, const KgeSMatrix& pSi, KM_CONST KgeVector& pVi)
    {
	    return *(KgeVector *) KmSV(pVo.mData, pSi.mData, pVi.mData);
    }

    ////////////////////////////////////////////////////////////////////////////////
    //
    //	Quaternion Utilities
    //
    ////////////////////////////////////////////////////////////////////////////////

    /*
    *	KgeCompare : Quaternion Length
    */
    inline double KgeLength(const KgeQuaternion& pQi)
    {
	    return KmQlength(pQi.mData);
    }

    /*
    *	KgeCompare : Quaternion Squared Length
    */
    inline double KgeLength2(const KgeQuaternion& pQi)
    {
	    return KmQlength2(pQi.mData);
    }

    /*
    *	KgeCompare : Quaternion Dot Product
    */
    inline double KgeDot(const KgeQuaternion& pQiA, const KgeQuaternion& pQiB)
    {
	    return KmQdotQ(pQiA.mData, pQiB.mData);
    }

    /*
    *	KgeCompare : Quaternion Compare
    */
    inline int KgeCompare(const KgeQuaternion& pQiA, const KgeQuaternion& pQiB, const double pThreshold = KM_TOLERANCE)
    {
	    return KmQcmp(pQiA.mData, pQiB.mData, pThreshold);
    }

    ////////////////////////////////////////////////////////////////////////////////
    //
    //	Quaternion Initialization
    //
    ////////////////////////////////////////////////////////////////////////////////

    /*
    *	KgeSet : Set Quaternion
    */
    inline KgeQuaternion& KgeSet(
	    KgeQuaternion& pQo,
	    const double pX, const double pY, const double pZ, const double pW)
    {
	    return *(KgeQuaternion *) KmQ(pQo.mData, pX, pY, pZ, pW);
    }

    /*
    *	KgeSet : Set Quaternion
    */
    inline KgeQuaternion& KgeSet(
	    KgeQuaternion& pQo, const KgeQuaternion& pQi)
    {
	    return *(KgeQuaternion *) KmQset(pQo.mData, pQi.mData);
    }

    /*
    *	KgeSet : Set Quaternion
    */
    inline KgeQuaternion& KgeSet(
	    KgeQuaternion& pQo, const KgeRMatrix& pRi)
    {
	    return *(KgeQuaternion *) KmRtoQ(pQo.mData, pRi.mData);
    }

    /*
    *	KgeUnRoll : Euler Angle Un-Roller
    */
    inline KgeRVector& KgeUnRoll(KgeRVector& pRo, KM_CONST KgeRVector& pVi, const KgeRVector& pRi)
    {
	    return *(KgeRVector *) KmRunroll(pRo.mData, pVi.mData, pRi.mData);
    }

    /*
    *	KgeSetXYZ : XYZ Euler Vector To Quaternion
    */
    inline KgeQuaternion& KgeSetXYZ(KgeQuaternion& pQo, const KgeRVector& pVi)
    {
	    return *(KgeQuaternion *) KmVXYZtoQ(pQo.mData, pVi.mData);
    }
     
    /*
    *	KgeSetYZX : YZX Euler Vector To Quaternion
    */
    inline KgeQuaternion& KgeSetYZX(KgeQuaternion& pQo, const KgeRVector& pVi)
    {
	    return *(KgeQuaternion *) KmVYZXtoQ(pQo.mData, pVi.mData);
    }

    /*
    *	KgeSetZXY : ZXY Euler Vector To Quaternion
    */
    inline KgeQuaternion& KgeSetZXY(KgeQuaternion& pQo, const KgeRVector& pVi)
    {
	    return *(KgeQuaternion *) KmVZXYtoQ(pQo.mData, pVi.mData);
    }

    /*
    *	KgeSetXZY : XZY Euler Vector To Quaternion
    */
    inline KgeQuaternion& KgeSetXZY(KgeQuaternion& pQo, const KgeRVector& pVi)
    {
	    return *(KgeQuaternion *) KmVXZYtoQ(pQo.mData, pVi.mData);
    }
     
    /*
    *	KgeSetYXZ : YXZ Euler Vector To Quaternion
    */
    inline KgeQuaternion& KgeSetYXZ(KgeQuaternion& pQo, const KgeRVector& pVi)
    {
	    return *(KgeQuaternion *) KmVYXZtoQ(pQo.mData, pVi.mData);
    }

    /*
    *	KgeSetZYX : ZYX Euler Vector To Quaternion
    */
    inline KgeQuaternion& KgeSetZYX(KgeQuaternion& pQo, const KgeRVector& pVi)
    {
	    return *(KgeQuaternion *) KmVZYXtoQ(pQo.mData, pVi.mData);
    }

    /*
    *	KgeSet : Ordered Euler Vector To Quaternion
    */
    inline KgeQuaternion& KgeSet(KgeQuaternion& pQo, const KgeRVector& pVi, const int pOrd)
    {
	    return *(KgeQuaternion *) KmVIJKtoQ(pQo.mData, pVi.mData, pOrd);
    }

    /*
    *	KgeSet : Default Order Euler Vector To Quaternion
    */
    inline KgeQuaternion& KgeSet(KgeQuaternion& pQo, const KgeRVector& pVi)
    {
	    return *(KgeQuaternion *) KmVtoQ(pQo.mData, pVi.mData);
    }

    ////////////////////////////////////////////////////////////////////////////////
    //
    //	Quaternion Operations
    //
    ////////////////////////////////////////////////////////////////////////////////

    inline KgeQuaternion& KgeConj(
	    KgeQuaternion& pQo, KM_CONST  KgeQuaternion& pQi)
    {
	    return *(KgeQuaternion *) KmQconj(pQo.mData, pQi.mData);
    }

    inline KgeQuaternion& KgeMult(
	    KgeQuaternion& pQo, KM_CONST  KgeQuaternion& pQi, const double pNi)
    {
	    return *(KgeQuaternion *) KmQN(pQo.mData, pQi.mData, pNi);
    }

    inline KgeQuaternion& KgeNorm(
	    KgeQuaternion& pQo, KM_CONST  KgeQuaternion& pQi)
    {
	    return *(KgeQuaternion *) KmQnorm(pQo.mData, pQi.mData);
    }

    inline KgeQuaternion& KgeAdd(
	    KgeQuaternion& pQo, KM_CONST KgeQuaternion& pQiA, KM_CONST KgeQuaternion& pQiB)
    {
	    return *(KgeQuaternion *) KmQadd(pQo.mData, pQiA.mData, pQiB.mData);
    }

    inline KgeQuaternion& KgeMult(
	    KgeQuaternion& pQo, KM_CONST KgeQuaternion& pQiA, KM_CONST KgeQuaternion& pQiB)
    {
	    return *(KgeQuaternion *) KmQQ(pQo.mData, pQiA.mData, pQiB.mData);
    }

    ////////////////////////////////////////////////////////////////////////////////
    //
    //	Matrix Utilities
    //
    ////////////////////////////////////////////////////////////////////////////////

    /*
    *	KgeDet : Affine Matrix Determinant
    */
    inline double KgeDet(const KgeAMatrix &pAi)
    {
	    return KmAdet(pAi.mData);
    }
    													
    /*
    *	KgeDet : Translation Matrix Determinant
    */
    inline double KgeDet(const KgeTMatrix& pTi)
    {
	    return KmTdet(pTi.mData);
    }

    /*
    *	KgeDet : Rotation Matrix Determinant
    */
    inline double KgeDet(const KgeRMatrix& pRi)
    {
	    return KmRdet(pRi.mData);
    }

    /*
    *	KgeDet : Scaling Matrix Determinant
    */
    inline double KgeDet(const KgeSMatrix& pSi)
    {
	    return KmSdet(pSi.mData);
    }

    /*
    *	KgeTrace : Affine Matrix Trace
    */
    inline double KgeTrace(const KgeAMatrix& pAi)
    {
	    return KmAtrace(pAi.mData);
    }

    /*
    *	KgeTrace : Translation Matrix Trace
    */
    inline double KgeTrace(const KgeTMatrix& pTi)
    {
	    return KmTtrace(pTi.mData);
    }

    /*
    *	KgeTrace : Rotation Matrix Trace
    */
    inline double KgeTrace(const KgeRMatrix& pRi)
    {
	    return KmRtrace(pRi.mData);
    }

    /*
    *	KgeTrace : Scaling Matrix Trace
    */
    inline double KgeTrace(const KgeSMatrix& pSi)
    {
	    return KmStrace(pSi.mData);
    }

    /*
    *	KgeCompare : Matrix Compare
    */
    inline int KgeCompare(const KgeMatrix& pMiA, const KgeMatrix& pMiB, const double pThreshold = KM_TOLERANCE)
    {
	    return KmMcmp(pMiA.mData, pMiB.mData, pThreshold);
    }

    /*
    *	KgeCompare : Affine Matrix Compare
    */
    inline int KgeCompare(const KgeAMatrix& pAiA, const KgeAMatrix& pAiB, const double pThreshold = KM_TOLERANCE)
    {
	    return KmAcmp(pAiA.mData, pAiB.mData, pThreshold);
    }

    /*
    *	KgeCompare : Translation Matrix Compare
    */
    inline int KgeCompare(const KgeTMatrix& pTiA, const KgeTMatrix& pTiB, const double pThreshold = KM_TOLERANCE)
    {
	    return KmTcmp(pTiA.mData, pTiB.mData, pThreshold);
    }

    /*
    *	KgeCompare : Rotation Matrix Compare
    */
    inline int KgeCompare(const KgeRMatrix& pRiA, const KgeRMatrix& pRiB, const double pThreshold = KM_TOLERANCE)
    {
	    return KmRcmp(pRiA.mData, pRiB.mData, pThreshold);
    }

    /*
    *	KgeCompare : Scaling Matrix Compare
    */
    inline int KgeCompare(const KgeSMatrix& pSiA, const KgeSMatrix& pSiB, const double pThreshold = KM_TOLERANCE)
    {
	    return KmScmp(pSiA.mData, pSiB.mData, pThreshold);
    }

    ////////////////////////////////////////////////////////////////////////////////
    //
    //	Matrix Initialization
    //
    ////////////////////////////////////////////////////////////////////////////////

    /*
    *	KgeIdentity : Matrix Identity
    */
    inline KgeMatrix& KgeIdentity(KgeMatrix &pMo)
    {
	    return *(KgeMatrix *) KmId(pMo.mData);
    }

    /*
    *	KgeSet : Set Matrix
    */
    inline KgeMatrix& KgeSet(KgeMatrix& pMo, const KgeMatrix& pMi)
    {
	    return *(KgeMatrix *) KmMset(pMo.mData, pMi.mData);
    }

    /*
    *	KgeSet : Set Affine Matrix
    */
    inline KgeAMatrix& KgeSet(KgeAMatrix& pAo, const KgeAMatrix& pAi)
    {
	    return *(KgeAMatrix *) KmAset(pAo.mData, pAi.mData);
    }

    /*
    *	KgeSet : Set Affine Matrix with Translation
    */
    inline KgeAMatrix& KgeSet(KgeAMatrix& pAo, const KgeTMatrix& pAi)
    {
	    return *(KgeAMatrix *) KmTset(pAo.mData, pAi.mData);
    }

    /*
    *	KgeSet : Set Translation Matrix
    */
    inline KgeTMatrix& KgeSet(KgeTMatrix& pTo, const KgeTMatrix& pTi)
    {
	    return *(KgeTMatrix *) KmTset(pTo.mData, pTi.mData);
    }

    /*
    *	KgeSet : Set Rotation Matrix
    */
    inline KgeRMatrix& KgeSet(KgeRMatrix& pRo, const KgeRMatrix& pRi)
    {
	    return *(KgeRMatrix *) KmRset(pRo.mData, pRi.mData);
    }

    /*
    *	KgeSet : Set Scaling Matrix
    */
    inline KgeSMatrix& KgeSet(KgeSMatrix& pSo, const KgeSMatrix& pSi)
    {
	    return *(KgeSMatrix *) KmSset(pSo.mData, pSi.mData);
    }

    ////////////////////////////////////////////////////////////////////////////////
    //
    //	Matrix Operations
    //
    ////////////////////////////////////////////////////////////////////////////////

    /*
    *	KgeTranspose : Matrix Transpose
    */
    inline KgeMatrix& KgeTranspose(KgeMatrix& pMo, KM_CONST KgeMatrix& pMi)
    {
	    return *(KgeMatrix *) KmMt(pMo.mData, pMi.mData);
    }

    /*
    *	KgeAdj : Matrix Adjoint
    */
    inline KgeMatrix& KgeAdj(KgeMatrix& pMo, const KgeMatrix& pMi)
    {
	    return *(KgeMatrix *) KmMadj(pMo.mData, (const double (*)[4]) pMi.mData);
    }

    /*
    *	KgeNeg : Matrix Negate
    */
    inline KgeMatrix& KgeNeg(KgeMatrix& pMo, KM_CONST KgeMatrix& pMi)
    {
	    return *(KgeMatrix *) KmMneg(pMo.mData, pMi.mData);
    }

    /*
    *	KgeInverse : Matrix Inverse
    */
    inline KgeMatrix& KgeInverse(KgeMatrix& pMo, KM_CONST KgeMatrix& pMi)
    {
	    return *(KgeMatrix *) KmMi(pMo.mData, pMi.mData);
    }

    /*
    *	KgeInverse : Affine Matrix Inverse
    */
    inline KgeAMatrix& KgeInverse(KgeAMatrix& pAo, KM_CONST KgeAMatrix& pAi)
    {
	    return *(KgeAMatrix *) KmAi(pAo.mData, pAi.mData);
    }

    /*
    *	KgeInverse : Translation Matrix Inverse
    */
    inline KgeTMatrix& KgeInverse(KgeTMatrix& pTo, KM_CONST KgeTMatrix& pTi)
    {
	    return *(KgeTMatrix *) KmTi(pTo.mData, pTi.mData);
    }

    /*
    *	KgeInverse : Rotation Matrix Inverse
    */
    inline KgeRMatrix& KgeInverse(KgeRMatrix& pRo, KM_CONST KgeRMatrix& pRi)
    {
	    return *(KgeRMatrix *) KmRi(pRo.mData, pRi.mData);
    }

    /*
    *	KgeInverse : Scaling Matrix Inverse
    */
    inline KgeSMatrix& KgeInverse(KgeSMatrix& pSo, KM_CONST KgeSMatrix& pSi)
    {
	    return *(KgeSMatrix *) KmSi(pSo.mData, pSi.mData);
    }

    /*
    *	KgeAdd : Matrix Add
    */
    inline KgeMatrix& KgeAdd(KgeMatrix& pMo, KM_CONST KgeMatrix& pMiA, KM_CONST KgeMatrix& pMiB)
    {
	    return *(KgeMatrix *) KmMadd(pMo.mData, pMiA.mData, pMiB.mData);
    }

    /*
    *	KgeSub : Matrix Subtract
    */
    inline KgeMatrix& KgeSub(KgeMatrix& pMo, KM_CONST KgeMatrix& pMiA, KM_CONST KgeMatrix& pMiB)
    {
	    return *(KgeMatrix *) KmMsub(pMo.mData, pMiA.mData, pMiB.mData);
    }

    /*
    *	KgeMult : Matrix Scale
    */
    inline KgeMatrix& KgeMult(KgeMatrix& pMo, KM_CONST KgeMatrix& pMiA, const double pNi)
    {
	    return *(KgeMatrix *) KmMN(pMo.mData, pMiA.mData, pNi);
    }

    /*
    *	KgeMult : Matrix Product
    */
    inline KgeMatrix& KgeMult(KgeMatrix& pMo, KM_CONST KgeMatrix& pMiA, KM_CONST KgeMatrix& pMiB)
    {
	    return *(KgeMatrix *) KmMM(pMo.mData, pMiA.mData, pMiB.mData);
    }

    /*
    *	KgeMult : Affine Matrix Product
    */
    inline KgeAMatrix& KgeMult(KgeAMatrix& pAo, KM_CONST KgeAMatrix& pAiA, KM_CONST KgeAMatrix& pAiB)
    {
	    return *(KgeAMatrix *) KmAA(pAo.mData, pAiA.mData, pAiB.mData);
    }

    /*
    *	KgeMult : Translation Matrix Product
    */
    inline KgeTMatrix& KgeMult(KgeTMatrix& pTo, KM_CONST KgeTMatrix& pTiA, KM_CONST KgeTMatrix& pTiB)
    {
	    return *(KgeTMatrix *) KmTT(pTo.mData, pTiA.mData, pTiB.mData);
    }

    /*
    *	KgeMult : Rotation Matrix Product
    */
    inline KgeRMatrix& KgeMult(KgeRMatrix& pRo, KM_CONST KgeRMatrix& pRiA, KM_CONST KgeRMatrix& pRiB)
    {
	    return *(KgeRMatrix *) KmRR(pRo.mData, pRiA.mData, pRiB.mData);
    }

    /*
    *	KgeMult : Scaling Matrix Product
    */
    inline KgeSMatrix& KgeMult(KgeSMatrix& pSo, KM_CONST KgeSMatrix& pSiA, KM_CONST KgeSMatrix& pSiB)
    {
	    return *(KgeSMatrix *) KmSS(pSo.mData, pSiA.mData, pSiB.mData);
    }

    /*
    *	KgeMult : T by R Matrix Product
    */
    inline KgeAMatrix& KgeMult(KgeAMatrix& pAo, const KgeTMatrix& pTi, const KgeRMatrix& pRi)
    {
	    return *(KgeAMatrix *) KmTR(pAo.mData, pTi.mData, pRi.mData);
    }

    /*
    *	KgeMult : T by R by S Matrix Product
    */
    inline KgeAMatrix& KgeMult(KgeAMatrix& pAo, const KgeTMatrix& pTi, const KgeRMatrix& pRi, const KgeSMatrix& pSi)
    {
	    return *(KgeAMatrix *) KmTRS(pAo.mData, pTi.mData, pRi.mData, pSi.mData);
    }

    /*
    *	KgeMult : S Matrix Product
    */
    inline KgeAMatrix& KgeMult(KgeAMatrix& pAo, KM_CONST KgeAMatrix& pAi, const KgeSVector& pVi)
    {
	    double T;

	    T = pVi.mData[0];

	    pAo.mData[0][0] = pAi.mData[0][0] * T;
	    pAo.mData[0][1] = pAi.mData[0][1] * T;
	    pAo.mData[0][2] = pAi.mData[0][2] * T;

	    T = pVi.mData[1];

	    pAo.mData[1][0] = pAi.mData[1][0] * T;
	    pAo.mData[1][1] = pAi.mData[1][1] * T;
	    pAo.mData[1][2] = pAi.mData[1][2] * T;

	    T = pVi.mData[2];

	    pAo.mData[2][0] = pAi.mData[2][0] * T;
	    pAo.mData[2][1] = pAi.mData[2][1] * T;
	    pAo.mData[2][2] = pAi.mData[2][2] * T;

	    return pAo;
    }

    /*
    *	KgeMult : T Vector Product
    */
    inline KgeAMatrix& KgeMult(KgeAMatrix& pAo, KM_CONST KgeAMatrix& pAi, const KgeTVector& pVi)
    {
	    pAo.mData[3][0] = pAi.mData[3][0] + pVi.mData[0];
	    pAo.mData[3][1] = pAi.mData[3][1] + pVi.mData[1];
	    pAo.mData[3][2] = pAi.mData[3][2] + pVi.mData[2];

        return pAo;
    }

    /*
    *	KgeInvMult : Matrix Inverse Product
    */
    inline KgeMatrix& KgeInvMult(KgeMatrix& pMo, KM_CONST KgeMatrix& pMiA, KM_CONST KgeMatrix& pMiB)
    {
	    return *(KgeMatrix *) KmMiM(pMo.mData, pMiA.mData, pMiB.mData);
    }

    /*
    *	KgeInvMult : Affine Matrix Inverse Product
    */
    inline KgeAMatrix& KgeInvMult(KgeAMatrix& pAo, KM_CONST KgeAMatrix& pAiA, KM_CONST KgeAMatrix& pAiB)
    {
	    return *(KgeAMatrix *) KmAiA(pAo.mData, pAiA.mData, pAiB.mData);
    }

    /*
    *	KgeInvMult : Translation Matrix Inverse Product
    */
    inline KgeTMatrix& KgeInvMult(KgeTMatrix& pTo, KM_CONST KgeTMatrix& pTiA, KM_CONST KgeTMatrix& pTiB)
    {
	    return *(KgeTMatrix *) KmTiT(pTo.mData, pTiA.mData, pTiB.mData);
    }

    /*
    *	KgeInvMult : Rotation Matrix Inverse Product
    */
    inline KgeRMatrix& KgeInvMult(KgeRMatrix& pRo, KM_CONST KgeRMatrix& pRiA, KM_CONST KgeRMatrix& pRiB)
    {
	    return *(KgeRMatrix *) KmRiR(pRo.mData, pRiA.mData, pRiB.mData);
    }

    /*
    *	KgeInvMult : Scaling Matrix Inverse Product
    */
    inline KgeSMatrix& KgeInvMult(KgeSMatrix& pSo, KM_CONST KgeSMatrix& pSiA, KM_CONST KgeSMatrix& pSiB)
    {
	    return *(KgeSMatrix *) KmSiS(pSo.mData, pSiA.mData, pSiB.mData);
    }

    ////////////////////////////////////////////////////////////////////////////////
    //
    //	Matrix To Vector Decompositions
    //
    ////////////////////////////////////////////////////////////////////////////////

    /*
    *	KgeSet : Translation Matrix To Vector
    */
    inline KgeTVector& KgeSet(KgeTVector& pVo, const KgeTMatrix& pTi)
    {
	    return *(KgeTVector *) KmTtoV(pVo.mData, pTi.mData);
    }

    /*
    *	KgeSetXYZ : Rotation Matrix to XYZ Euler Vector
    */
    inline KgeRVector& KgeSetXYZ(KgeRVector& pVo, const KgeRMatrix& pRi)
    {    
	    return *(KgeRVector *) KmRtoVXYZ(pVo.mData, pRi.mData);
    }

    /*
    *	KgeSetZYX : Rotation Matrix To ZYX Euler Vector
    */
    inline KgeRVector& KgeSetZYX(KgeRVector& pVo, const KgeRMatrix& pRi)
    {
	    return *(KgeRVector *) KmRtoVZYX(pVo.mData, pRi.mData);
    }

    /*
    *	KgeSet : Rotation Matrix To Ordered Euler Vector
    */
    inline KgeRVector& KgeSet(KgeRVector& pVo, const KgeRMatrix& pRi, int pOrd)
    {
	    return *(KgeRVector *) KmRtoVord(pVo.mData, pRi.mData, pOrd);
    }

    /*
    *	KgeSet : Rotation Matrix To Default Order Euler Vector
    */
    inline KgeRVector& KgeSet(KgeRVector& pVo, const KgeRMatrix& pRi)
    {
	    return *(KgeRVector *) KmRtoV(pVo.mData, pRi.mData);
    }

    /*
    *	KgeSetXYZ : Quaternion to XYZ Euler Vector
    */
    inline KgeRVector& KgeSetXYZ(KgeRVector& pVo, const KgeQuaternion& pQi)
    {    
	    return *(KgeRVector *) KmQtoVXYZ(pVo.mData, pQi.mData);
    }

    /*
    *	KgeSetZYX : Quaternion To ZYX Euler Vector
    */
    inline KgeRVector& KgeSetZYX(KgeRVector& pVo, const KgeQuaternion& pQi)
    {
	    return *(KgeRVector *) KmQtoVZYX(pVo.mData, pQi.mData);
    }

    /*
    *	KgeSet : Quaternion To Ordered Euler Vector
    */
    inline KgeRVector& KgeSet(KgeRVector& pVo, const KgeQuaternion& pQi, const int pOrd)
    {
	    return *(KgeRVector *) KmQtoVord(pVo.mData, pQi.mData, pOrd);
    }

    /*
    *	KgeSet : Quaternion To Default Order Euler Vector
    */
    inline KgeRVector& KgeSet(KgeRVector& pVo, const KgeQuaternion& pQi)
    {
	    return *(KgeRVector *) KmQtoV(pVo.mData, pQi.mData);
    }

    /*
    *	KgeSet : Affine Matrix To Vector
    */
    inline void KgeSet(KgeTVector& pTo, KgeRVector& pRo, KgeSVector& pSo, const KgeAMatrix& pAi)
    {
	    KmAtoV(pTo.mData, pRo.mData, pSo.mData, pAi.mData);
    }

    /*
    *	KgeSet : Affine Matrix To Ordered Vector
    */
    inline void KgeSet(KgeTVector& pTo, KgeRVector& pRo, KgeSVector& pSo, const KgeAMatrix& pAi, int pOrd)
    {
	    KmAtoVord(pTo.mData, pRo.mData, pSo.mData, pAi.mData, pOrd);
    }

    /*
    *	KgeSet : Affine Matrix To Translation Vector
    */
    inline KgeTVector& KgeSet(KgeTVector& pTo, const KgeAMatrix& pAi)
    {
	    return *(KgeTVector *) KmAtoVT(pTo.mData, pAi.mData);
    }

    /*
    *	KgeSet : Rotation Matrix To Direction Vector
    */
    inline KgeTVector& KgeSet(KgeTVector& pDo, const KgeRMatrix& pRi, const double pLength = 1.0)
    {
	    return *(KgeTVector *) KmRtoD(pDo.mData, pRi.mData, pLength);
    }

    /*
    *	KgeSet : Affine Matrix To Rotation Vector
    */
    inline KgeRVector& KgeSet(KgeRVector& pRo, const KgeAMatrix& pAi)
    {
	    return *(KgeRVector *) KmAtoVR(pRo.mData, pAi.mData);
    }

    /*
    *	KgeSet : Affine Matrix To Rotation Vector
    */
    inline KgeRVector& KgeSet(KgeRVector& pRo, const KgeAMatrix& pAi, int pOrd)
    {
	    return *(KgeRVector *) KmAtoVRord(pRo.mData, pAi.mData, pOrd);
    }

    /*
    *	KgeSet : Affine Matrix To Translation Vector
    */
    inline KgeSVector& KgeSet(KgeSVector& pSo, const KgeAMatrix& pAi)
    {
	    return *(KgeSVector *)KmAtoVS(pSo.mData, pAi.mData);
    }


    ////////////////////////////////////////////////////////////////////////////////
    //
    //	Matrix Compositions
    //
    ////////////////////////////////////////////////////////////////////////////////

    /*
    *	KgeSet : Translation Vector To Affine Matrix
    */
    inline KgeAMatrix& KgeSet(KgeAMatrix& pAo, const KgeTVector& pTi)
    {
	    return *(KgeAMatrix *) KmVtoT(pAo.mData, pTi.mData);
    }

    /*
    *	KgeSet : Rotation Vector To Affine Matrix
    */
    inline KgeAMatrix& KgeSet(KgeAMatrix& pAo, const KgeRVector& pRi)
    {
	    return *(KgeAMatrix *) KmVtoR(pAo.mData, pRi.mData);
    }

    /*
    *	KgeSet : Ordered Rotation Vector To Affine Matrix
    */
    inline KgeAMatrix& KgeSet(KgeAMatrix& pAo, const KgeRVector& pRi, const int pOrd)
    {
	    return *(KgeAMatrix *) KmVIJKtoR(pAo.mData, pRi.mData, pOrd);
    }

    /*
    *	KgeSet : Vector To Affine Matrix
    */
    inline KgeAMatrix& KgeSet(KgeAMatrix& pAo, const KgeTVector& pTi, const KgeRVector& pRi)
    {
	    (void) KmVtoT(pAo.mData, pTi.mData);
	    return *(KgeAMatrix *) KmVtoR(pAo.mData, pRi.mData);
    }

    /*
    *	KgeSet : Vector To Affine Matrix
    */
    inline KgeAMatrix& KgeSet(KgeAMatrix& pAo, const KgeTVector& pTi, const KgeRMatrix& pRMi)
    {
	    (void) KmRset(pAo.mData, pRMi.mData);
	    return *(KgeAMatrix *) KmVtoT(pAo.mData, pTi.mData);
    }

    /*
    *	KgeSet : Vector To Affine Matrix
    */
    inline KgeAMatrix& KgeSet(KgeAMatrix& pAo, const KgeTVector& pTi, const KgeQuaternion& pQi)
    {
	    (void) KmQtoR(pAo.mData, pQi.mData);
	    return *(KgeAMatrix *) KmVtoT(pAo.mData, pTi.mData);
    }


    /*
    *	KgeSet : Vector To Affine Matrix
    */
    inline KgeAMatrix& KgeSet(KgeAMatrix& pAo, const KgeTVector& pTi, const KgeRVector& pRi, const int pOrd)
    {
	    (void) KmVtoT(pAo.mData, pTi.mData);
	    return *(KgeAMatrix *) KmVIJKtoR(pAo.mData, pRi.mData, pOrd);
    }

    /*
    *	KgeSet : Vector To Affine Matrix
    */
    inline KgeAMatrix& KgeSet(KgeAMatrix& pAo, const KgeTVector& pTi, const KgeRMatrix& pRMi, const KgeSVector& pSi)
    {
	    (void) KmRS(pAo.mData, pRMi.mData, pSi.mData );
	    return *(KgeAMatrix *) KmVtoT(pAo.mData, pTi.mData);
    }

    /*
    *	KgeSet : Vector To Affine Matrix
    */
    inline KgeAMatrix& KgeSet(KgeAMatrix& pAo, const KgeTVector& pTi, const KgeQuaternion& pQi, const KgeSVector& pSi)
    {
	    (void) KmQtoR(pAo.mData, pQi.mData);
	    (void) KgeMult( pAo, pAo, pSi );
	    return *(KgeAMatrix *) KmVtoT(pAo.mData, pTi.mData);
    }

    /*
    *	KgeSet : Vector To Affine Matrix
    */
    inline KgeAMatrix& KgeSet(KgeAMatrix& pAo, const KgeTVector& pTi, const KgeRVector& pRi, const KgeSVector& pSi)
    {
	    return *(KgeAMatrix *) KmVtoA(pAo.mData, pTi.mData, pRi.mData, pSi.mData);
    }

    /*
    *	KgeSet : Vector To Affine Matrix
    */
    inline KgeAMatrix& KgeSet(KgeAMatrix& pAo, const KgeTVector& pTi, const KgeRVector& pRi, const KgeSVector& pSi, const int pOrd)
    {
	    return *(KgeAMatrix *) KmVtoAord(pAo.mData, pTi.mData, pRi.mData, pSi.mData, pOrd);
    }

    /*
    *	KgeSet : Vector To Translation Matrix
    */
    inline KgeTMatrix& KgeSet(KgeTMatrix& pTo, const KgeTVector& pVi)
    {
	    return *(KgeTMatrix *) KmVtoT(pTo.mData, pVi.mData);
    }

    /*
    *	KgeSetXYZ : XYZ Euler Vector To Rotation Matrix
    */
    inline KgeRMatrix& KgeSetXYZ(KgeRMatrix& pRo, const KgeRVector& pVi)
    {
	    return *(KgeRMatrix *) KmVXYZtoR(pRo.mData, pVi.mData);
    }
     
    /*
    *	KgeSetYZX : YZX Euler Vector To Rotation Matrix
    */
    inline KgeRMatrix& KgeSetYZX(KgeRMatrix& pRo, const KgeRVector& pVi)
    {
	    return *(KgeRMatrix *) KmVYZXtoR(pRo.mData, pVi.mData);
    }

    /*
    *	KgeSetZXY : ZXY Euler Vector To Rotation Matrix
    */
    inline KgeRMatrix& KgeSetZXY(KgeRMatrix& pRo, const KgeRVector& pVi)
    {
	    return *(KgeRMatrix *) KmVZXYtoR(pRo.mData, pVi.mData);
    }

    /*
    *	KgeSetXZY : XZY Euler Vector To Rotation Matrix
    */
    inline KgeRMatrix& KgeSetXZY(KgeRMatrix& pRo, const KgeRVector& pVi)
    {
	    return *(KgeRMatrix *) KmVXZYtoR(pRo.mData, pVi.mData);
    }
     
    /*
    *	KgeSetYXZ : YXZ Euler Vector To Rotation Matrix
    */
    inline KgeRMatrix& KgeSetYXZ(KgeRMatrix& pRo, const KgeRVector& pVi)
    {
	    return *(KgeRMatrix *) KmVYXZtoR(pRo.mData, pVi.mData);
    }

    /*
    *	KgeSetZYX : ZYX Euler Vector To Rotation Matrix
    */
    inline KgeRMatrix& KgeSetZYX(KgeRMatrix& pRo, const KgeRVector& pVi)
    {
	    return *(KgeRMatrix *) KmVZYXtoR(pRo.mData, pVi.mData);
    }

    /*
    *	KgeSet : Ordered Euler Vector To Rotation Matrix
    */
    inline KgeRMatrix& KgeSet(KgeRMatrix& pRo, const KgeRVector& pVi, const int pOrd)
    {
	    return *(KgeRMatrix *) KmVIJKtoR(pRo.mData, pVi.mData, pOrd);
    }

    /*
    *	KgeSet : Default Order Euler Vector To Rotation Matrix
    */
    inline KgeRMatrix& KgeSet(KgeRMatrix& pRo, const KgeRVector& pVi)
    {
	    return *(KgeRMatrix *) KmVtoR(pRo.mData, pVi.mData);
    }

    /*
    *	KgeSet : Direction Vector To Rotation Matrix
    */
    inline KgeRMatrix& KgeSet(KgeRMatrix& pRo, const KgeTVector& pDi, double pRoll = 0.0)
    {
	    return *(KgeRMatrix *) KmDtoR(pRo.mData, pDi.mData, pRoll);
    }


    /*
    *	KgeSet : Set Quaternion
    */
    inline KgeRMatrix& KgeSet(
	    KgeRMatrix& pRo, const KgeQuaternion& pQi)
    {
	    return *(KgeRMatrix *) KmQtoR(pRo.mData, pQi.mData);
    }

    /*
    *	KgeSet : Scalar to Scaling Matrix
    */
    inline KgeSMatrix& KgeSet(KgeSMatrix& pSo, const double pNi)
    {
	    return *(KgeSMatrix *) KmNtoS(pSo.mData, pNi);
    }

    /*
    *	KgeSet : Vector To Scaling Matrix
    */
    inline KgeSMatrix& KgeSet(KgeSMatrix& pSo, const KgeSVector& pVi)
    {
	    return *(KgeSMatrix *) KmVtoS(pSo.mData, pVi.mData);
    }

    ////////////////////////////////////////////////////////////////////////////////
    //
    //	Class KgeTVector
    //
    ////////////////////////////////////////////////////////////////////////////////

    inline KgeTVector::KgeTVector()
    {
	    (void) Init();
	    mData[3] = 1.0;
    }

    inline KgeTVector::KgeTVector(const double pN0, const double pN1, const double pN2)
    {
	    mData[0] = pN0;
	    mData[1] = pN1;
	    mData[2] = pN2;
	    mData[3] = 1.0;
    }

    inline KgeTVector::KgeTVector(const double *const pVi)
    {
	    (void) operator=(pVi);
	    mData[3] = 1.0;
    }

    inline KgeTVector::KgeTVector(const float *const pVi)
    {
	    (void) operator=(pVi);
	    mData[3] = 1.0;
    }

    inline KgeTVector::KgeTVector(const KgeTVector& pVi)
    {
	    (void) operator=(pVi.mData);
	    mData[3] = 1.0;
    }

    inline KgeTVector::KgeTVector(const KgeAMatrix& pAi)
    {
	    (void) KgeSet(*this, pAi);
	    mData[3] = 1.0;
    }

    inline KgeTVector::KgeTVector(const KgeTMatrix& pTi)
    {
	    (void) KgeSet(*this, pTi);
	    mData[3] = 1.0;
    }

    inline KgeTVector& KgeTVector::Init()
    {
	    return mData[0] = mData[1] = mData[2] = 0.0, *this;
    }

    inline KgeTVector& KgeTVector::operator=(const double *const pVi)
    {
	    mData[0] = pVi[0];
	    mData[1] = pVi[1];
	    mData[2] = pVi[2];

	    return *this;
    }

    inline KgeTVector& KgeTVector::operator=(const float *const pVi)
    {
	    mData[0] = pVi[0];
	    mData[1] = pVi[1];
	    mData[2] = pVi[2];

	    return *this;
    }


    inline KgeTVector& KgeTVector::operator=(const KgeTVector& pVi)
    {
	    return operator=(pVi.mData);
    }
    inline KgeTVector::operator const double *() const
    {
	    return &mData[0];
    }

	inline bool KgeTVector::operator==(const KgeTVector& pVi) const
	{
		return (KgeCompare(*this, pVi) == 0); 
	}

	inline bool KgeTVector::operator!=(const KgeTVector& pVi) const
	{
		return (KgeCompare(*this, pVi) != 0); 
	}

    ////////////////////////////////////////////////////////////////////////////////
    //
    //	Class KgeRGBAVector
    //
    ////////////////////////////////////////////////////////////////////////////////
    inline KgeRGBAVector::KgeRGBAVector()
    {
	    (void) Init();
    }

    inline KgeRGBAVector::KgeRGBAVector(const double pR, const double pG, const double pB, const double pA)
    {
	    mData[0] = pR;
	    mData[1] = pG;
	    mData[2] = pB;
	    mData[3] = pA;
    }

    inline KgeRGBAVector::KgeRGBAVector(const double *const pVi)
    {
	    (void) operator=(pVi);
    }

    inline KgeRGBAVector::KgeRGBAVector(const KgeRGBAVector & pVi)
    {
	    (void) operator=(pVi);
    }

    inline KgeRGBAVector& KgeRGBAVector::Init()
    {
	    return mData[0] = mData[1] = mData[2] = mData[3] = 0.0, *this;
    }

    inline KgeRGBAVector& KgeRGBAVector::operator=(const double *const pVi)
    {
	    mData[0] = pVi[0];
	    mData[1] = pVi[1];
	    mData[2] = pVi[2];
	    mData[3] = pVi[3];

	    return *this;
    }


    inline KgeRGBAVector & KgeRGBAVector::operator=(const KgeRGBAVector& pVi)
    {
	    return operator=(pVi.mData);
    }
    inline KgeRGBAVector::operator const double *() const
    {
	    return &mData[0];
    }

	inline bool KgeRGBAVector::operator==(const KgeRGBAVector& pVi) const
    {
	    //return (KmVcmp(this->mData, pVi.mData, 0.0/*pThreshold*/) == 0); // Problem: no comparison for Alpha
	    return (   (this->mData[0] == pVi.mData[0])
			    && (this->mData[1] == pVi.mData[1])
			    && (this->mData[2] == pVi.mData[2])
			    && (this->mData[3] == pVi.mData[3]));
    }

	inline bool KgeRGBAVector::operator!=(const KgeRGBAVector& pVi) const
    {
	    //return (KmVcmp(this->mData, pVi.mData, 0.0/*pThreshold*/) != 0); // Problem: no comparison for Alpha
	    return (   (this->mData[0] != pVi.mData[0])
			    || (this->mData[1] != pVi.mData[1])
			    || (this->mData[2] != pVi.mData[2])
			    || (this->mData[3] != pVi.mData[3]));
    }

    ////////////////////////////////////////////////////////////////////////////////
    //
    //	Class KgeRGBVector
    //
    ////////////////////////////////////////////////////////////////////////////////
    inline KgeRGBVector::KgeRGBVector()
    {
	    (void) Init();
    }

    inline KgeRGBVector::KgeRGBVector(const double pR, const double pG, const double pB )
    {
	    mData[0] = pR;
	    mData[1] = pG;
	    mData[2] = pB;
    }

    inline KgeRGBVector::KgeRGBVector(const double *const pVi)
    {
	    (void) operator=(pVi);
    }

    inline KgeRGBVector::KgeRGBVector(const KgeRGBVector & pVi)
    {
	    (void) operator=(pVi);
    }

    inline KgeRGBVector::KgeRGBVector(const KgeRGBAVector & pVi)
    {
	    (void) operator=(pVi);
    }


    inline KgeRGBVector& KgeRGBVector::Init()
    {
	    mData[0] = mData[1] = mData[2] = 0.0; mData[3] = 1.0;
	    return *this;
    }

    inline KgeRGBVector& KgeRGBVector::operator=(const double *const pVi)
    {
	    mData[0] = pVi[0];
	    mData[1] = pVi[1];
	    mData[2] = pVi[2];

	    return *this;
    }


    inline KgeRGBVector & KgeRGBVector::operator=(const KgeRGBAVector& pVi)
    {
	    return operator=(pVi.mData);
    }

    inline KgeRGBVector & KgeRGBVector::operator=(const KgeRGBVector& pVi)
    {
	    return operator=(pVi.mData);
    }


    inline KgeRGBVector::operator const double *() const
    {
	    return &mData[0];
    }


	inline bool KgeRGBVector::operator==(const KgeRGBVector& pVi) const
    {
	    return (KmVcmp(this->mData, pVi.mData, 0.0/*pThreshold*/) == 0);
    }

	inline bool KgeRGBVector::operator!=(const KgeRGBVector& pVi) const
    {
	    return (KmVcmp(this->mData, pVi.mData, 0.0/*pThreshold*/) != 0);
    }

    ////////////////////////////////////////////////////////////////////////////////
    //
    //	Class KgeRVector
    //
    ////////////////////////////////////////////////////////////////////////////////

    inline KgeRVector::KgeRVector()
    {
	    (void) Init();
    }

    inline KgeRVector::KgeRVector(const double pN0, const double pN1, const double pN2)
    {
	    (void) KmV(mData, pN0, pN1, pN2);
    }

    inline KgeRVector::KgeRVector(const double *const pVi)
    {
	    (void) operator=(pVi);
    }

    inline KgeRVector::KgeRVector(const KgeRVector& pVi)
    {
	    (void) operator=(pVi.mData);
    }

    inline KgeRVector::KgeRVector(const KgeAMatrix& pAi)
    {
	    (void) KgeSet(*this, pAi);
    }


    inline KgeRVector::KgeRVector(const KgeRMatrix& pRi)
    {
	    (void) KgeSet(*this, pRi);
    }

    inline KgeRVector::KgeRVector(const KgeRMatrix& pRi, const int pOrd)
    {
	    (void) KgeSet(*this, pRi, pOrd);
    }

    inline KgeRVector::KgeRVector(const KgeQuaternion& pQi)
    {
	    (void) KmQtoV(mData, pQi.mData);
    }

    inline KgeRVector::KgeRVector(const KgeQuaternion& pQi, const int pOrd)
    {
	    (void) KmQtoVord(mData, pQi.mData, pOrd);
    }

    inline KgeRVector& KgeRVector::Init()
    {
	    return mData[0] = mData[1] = mData[2] = 0.0, *this;
    }

    inline KgeRVector& KgeRVector::operator=(const double *const pVi)
    {
	    return *(KgeRVector *) KmVset(mData, pVi);
    }

    inline KgeRVector& KgeRVector::operator=(const KgeRVector& pVi)
    {
	    return operator=(pVi.mData);
    }

    inline KgeRVector::operator const double *() const
    {
	    return &mData[0];
    }

	inline bool KgeRVector::operator==(const KgeRVector& pVi) const
	{
		return (KgeCompare(*this, pVi) == 0); 
	}

	inline bool KgeRVector::operator!=(const KgeRVector& pVi) const
	{
		return (KgeCompare(*this, pVi) != 0); 
	}

    ////////////////////////////////////////////////////////////////////////////////
    //
    //	Class KgeSVector
    //
    ////////////////////////////////////////////////////////////////////////////////

    inline KgeSVector::KgeSVector()
    {
	    (void) Init();
    }

    inline KgeSVector::KgeSVector(const double pN)
    {
	    KM_ASSERT(pN != 0.0, "Zero scaling factor used in KgeSVector constructor");

	    (void) KmV(mData, pN, pN, pN);
    }

    inline KgeSVector::KgeSVector(const double pN0, const double pN1, const double pN2)
    {
	    KM_ASSERT((pN0 != 0.0) && (pN1 != 0.0) && (pN2 != 0.0), "Zero scaling factor used in KgeSVector constructor");

	    (void) KmV(mData, pN0, pN1, pN2);
    }

    inline KgeSVector::KgeSVector(const double *const pVi)
    {
	    (void) operator=(pVi);
    }

    inline KgeSVector::KgeSVector(const KgeSVector& pVi)
    {
	    (void) operator=(pVi.mData);
    }

    inline KgeSVector::KgeSVector(const KgeAMatrix& pAi)
    {
	    KgeSet(*this, pAi);
    }

    inline KgeSVector::KgeSVector(const KgeSMatrix& pSi)
    {
	    KmStoV(this->mData, pSi.mData);
    }

    inline KgeSVector& KgeSVector::Init()
    {
	    return mData[0] = mData[1] = mData[2] = 1.0, *this;
    }

    inline KgeSVector& KgeSVector::operator=(const double *const pVi)
    {
	    return *(KgeSVector *) KmVset(mData, pVi);
    }

    inline KgeSVector& KgeSVector::operator=(const KgeSVector& pVi)
    {
	    return operator=(pVi.mData);
    }

    inline KgeSVector::operator const double *() const
    {
	    return &mData[0];
    }

	inline bool KgeSVector::operator==(const KgeSVector& pVi) const
	{
		return (KgeCompare(*this, pVi) == 0); 
	}
	
	inline bool KgeSVector::operator!=(const KgeSVector& pVi) const
	{
		return (KgeCompare(*this, pVi) != 0); 
	}

    ////////////////////////////////////////////////////////////////////////////////
    //
    //	Class KgeQuaternion
    //
    ////////////////////////////////////////////////////////////////////////////////

    inline KgeQuaternion::KgeQuaternion()
    {
	    (void) Init();
    }

    inline KgeQuaternion::KgeQuaternion(const double pX, const double pY, const double pZ, const double pW)
    {
	    (void) KmQ(mData, pX, pY, pZ, pW);
    }

    inline KgeQuaternion::KgeQuaternion(const double *const pVi)
    {
	    (void) operator=(pVi);
    }

    inline KgeQuaternion::KgeQuaternion(const KgeQuaternion& pVi)
    {
	    (void) operator=(pVi.mData);
    }

    inline KgeQuaternion::KgeQuaternion(const KgeRVector& pVi)
    {
	    (void) KmVtoQ(mData, pVi.mData);
    }

    inline KgeQuaternion::KgeQuaternion(const KgeRVector& pVi, const int pOrd)
    {
	    (void) KmVIJKtoQ(mData, pVi.mData, pOrd);
    }

    inline KgeQuaternion::KgeQuaternion(const KgeAMatrix& pAi)
    {
	    (void) KmRtoQ(mData, pAi.mData);
    }

    inline KgeQuaternion::KgeQuaternion(const KgeRMatrix& pRi)
    {
	    (void) KmRtoQ(mData, pRi.mData);
    }

    inline KgeQuaternion& KgeQuaternion::Init()
    {
	    return mData[0] = mData[1] = mData[2] = 0.0, mData[3] = 1.0, *this;
    }

    inline KgeQuaternion& KgeQuaternion::operator=(const double *const pVi)
    {
	    return *(KgeQuaternion *) KmQset(mData, pVi);
    }

    inline KgeQuaternion& KgeQuaternion::operator=(const KgeQuaternion& pVi)
    {
	    return operator=(pVi.mData);
    }

    inline KgeQuaternion::operator const double *() const
    {
	    return &mData[0];
    }

    ////////////////////////////////////////////////////////////////////////////////
    //
    //	Class KgeMatrix
    //
    ////////////////////////////////////////////////////////////////////////////////

    inline KgeMatrix::KgeMatrix()
    {
	    (void) Init();
    }

    inline KgeMatrix::KgeMatrix(const double (*const pMi)[4])
    {
	    (void) operator=(pMi);
    }

    inline KgeMatrix::KgeMatrix(const KgeMatrix& pMi)
    {
	    (void) operator=(pMi.mData);
    }

    inline KgeMatrix& KgeMatrix::Init()
    {
	    return *(KgeMatrix *) KmId((double (*)[4]) mData);
    }

    inline KgeMatrix& KgeMatrix::operator=(const double (*const pMi)[4])
    {
	    return *(KgeMatrix *) KmMset((double (*)[4]) mData, pMi);
    }

    inline KgeMatrix& KgeMatrix::operator=(const KgeMatrix& pMi)
    {
	    return operator=(pMi.mData);
    }

    inline KgeMatrix::operator const double *() const
    {
	    return &mData[0][0];
    }

    ////////////////////////////////////////////////////////////////////////////////
    //
    //	Class KgeAMatrix
    //
    ////////////////////////////////////////////////////////////////////////////////

    inline KgeAMatrix::KgeAMatrix()
    {
	    (void) Init();
    }

    inline KgeAMatrix::KgeAMatrix(const KgeTVector& pTi)
    {
	    (void) KmId((double (*)[4]) mData);
	    (void) KmVtoT((double (*)[4]) mData, (const double *) pTi.mData);
    }

    inline KgeAMatrix::KgeAMatrix(const KgeRVector& pRi)
    {
	    (void) KmId((double (*)[4]) mData);
	    (void) KmVtoR((double (*)[4]) mData, (const double *) pRi.mData);
    }

    inline KgeAMatrix::KgeAMatrix(const KgeRVector& pRi, const int pOrd)
    {
	    (void) KmId((double (*)[4]) mData);
	    (void) KmVIJKtoR((double (*)[4]) mData, (const double *) pRi.mData, pOrd);
    }

    inline KgeAMatrix::KgeAMatrix(const KgeSVector& pSi)
    {
	    (void) KmId((double (*)[4]) mData);
	    (void) KmVtoS((double (*)[4]) mData, (const double *) pSi.mData);
    }

    inline KgeAMatrix::KgeAMatrix(const KgeTVector& pTi, const KgeRVector& pRi)
    {
	    (void) KmId((double (*)[4]) mData);
	    (void) KmVtoT((double (*)[4]) mData, (const double *) pTi.mData);
	    (void) KmVtoR((double (*)[4]) mData, (const double *) pRi.mData);
    }

    inline KgeAMatrix::KgeAMatrix(const KgeTVector& pTi, const KgeRVector& pRi, const int pOrd)
    {
	    (void) KmId((double (*)[4]) mData);
	    (void) KmVtoT((double (*)[4]) mData, (const double *) pTi.mData);
	    (void) KmVIJKtoR((double (*)[4]) mData, (const double *) pRi.mData, pOrd);
    }

    inline KgeAMatrix::KgeAMatrix(const KgeTVector& pTi, const KgeQuaternion& pQi)
    {
	    (void) KmId((double (*)[4]) mData);
	    (void) KmVtoT((double (*)[4]) mData, (const double *) pTi.mData);
	    (void) KmQtoR((double (*)[4]) mData, (const double *) pQi.mData);
    }

    inline KgeAMatrix::KgeAMatrix(const KgeTVector& pTi, const KgeRVector& pRi, const KgeSVector& pSi)
    {
	    (void) KmAinit((double (*)[4]) mData);
	    (void) KmVtoA((double (*)[4]) mData, (const double *) pTi.mData, (const double *) pRi.mData, (const double *) pSi.mData);
    }

    inline KgeAMatrix::KgeAMatrix(const KgeTVector& pTi, const KgeRVector& pRi, const KgeSVector& pSi, const int pOrd)
    {
	    (void) KmAinit((double (*)[4]) mData);
	    (void) KmVtoAord((double (*)[4]) mData, (const double *) pTi.mData, (const double *) pRi.mData, (const double *) pSi.mData, pOrd);
    }

    inline KgeAMatrix::KgeAMatrix(const KgeTVector& pTi, const KgeQuaternion& pQi, const KgeSVector& pSi)
    {
	    (void) KmId((double (*)[4]) mData);
	    (void) KmVtoT((double (*)[4]) mData, (const double *) pTi.mData);
	    (void) KmQtoR((double (*)[4]) mData, (const double *) pQi.mData);
	    (void) KmVN((double *) mData[0], (double *) mData[0], pSi.mData[0]);
	    (void) KmVN((double *) mData[1], (double *) mData[1], pSi.mData[1]);
	    (void) KmVN((double *) mData[2], (double *) mData[2], pSi.mData[2]);
    }

    inline KgeAMatrix::KgeAMatrix(const double (*const pAi)[4])
    {
	    (void) KmAinit((double (*)[4]) mData);
	    (void) operator=(pAi);
    }

    inline KgeAMatrix::KgeAMatrix(const KgeAMatrix& pAi)
    {
	    (void) KmMset((double (*)[4]) mData, pAi.mData);
    }

    inline KgeAMatrix& KgeAMatrix::Init()
    {
	    return *(KgeAMatrix *) KmId((double (*)[4]) mData);
    }

    inline KgeAMatrix& KgeAMatrix::operator=(const double (*const pAi)[4])
    {
	    return *(KgeAMatrix *) KmAset((double (*)[4]) mData, pAi);
    }

    inline KgeAMatrix& KgeAMatrix::operator=(const KgeAMatrix& pAi)
    {
	    return operator=(pAi.mData);
    }

    inline KgeAMatrix::operator const double *() const
    {
	    return &mData[0][0];
    }

    ////////////////////////////////////////////////////////////////////////////////
    //
    //	Class KgeTMatrix
    //
    ////////////////////////////////////////////////////////////////////////////////

    inline KgeTMatrix::KgeTMatrix()
    {
	    (void) Init();
    }

    inline KgeTMatrix::KgeTMatrix(const double pX, const double pY, const double pZ)
    {
	    (void) KmTinit(mData);
	    (void) KmXYZtoT((double (*)[4]) mData, pX, pY, pZ);
    }

    inline KgeTMatrix::KgeTMatrix(const double (*const pTi)[4])
    {
	    (void) KmTinit((double (*)[4]) mData);
	    (void) operator=(pTi);
    }

    inline KgeTMatrix::KgeTMatrix(const KgeTMatrix& pTi)
    {
	    (void) KmMset((double (*)[4]) mData, pTi.mData);
    }

    inline KgeTMatrix& KgeTMatrix::Init()
    {
	    return *(KgeTMatrix *) KmId((double (*)[4]) mData);
    }

    inline KgeTMatrix& KgeTMatrix::operator=(const double (*const pTi)[4])
    {
	    return *(KgeTMatrix *) KmTset((double (*)[4]) mData, pTi);
    }

    inline KgeTMatrix& KgeTMatrix::operator=(const KgeTMatrix& pTi)
    {
	    return operator=(pTi.mData);
    }

    inline KgeTMatrix::operator const double *() const
    {
	    return &mData[0][0];
    }

    ////////////////////////////////////////////////////////////////////////////////
    //
    //	Class KgeRMatrix
    //
    ////////////////////////////////////////////////////////////////////////////////

    inline KgeRMatrix::KgeRMatrix()
    {
	    (void) Init();
    }

    inline KgeRMatrix::KgeRMatrix(const double pX, const double pY, const double pZ)
    {
	    (void) KmRinit(mData);
	    (void) KmXYZtoR((double (*)[4]) mData, pX, pY, pZ);
    }

    inline KgeRMatrix::KgeRMatrix(const double pI, const double pJ, const double pK, const int pOrd)
    {
	    (void) KmRinit(mData);
	    (void) KmIJKtoR((double (*)[4]) mData, pI, pJ, pK, pOrd);
    }

    inline KgeRMatrix::KgeRMatrix(const KgeRVector& pVi)
    {
	    (void) KmRinit(mData);
	    (void) KmVXYZtoR((double (*)[4]) mData, pVi.mData);
    }

    inline KgeRMatrix::KgeRMatrix(const KgeRVector& pVi, const int pOrd)
    {
	    (void) KmRinit(mData);
	    (void) KmVIJKtoR((double (*)[4]) mData, pVi.mData, pOrd);
    }

    inline KgeRMatrix::KgeRMatrix(const double (*const pRi)[4])
    {
	    (void) KmRinit((double (*)[4]) mData);
	    (void) operator=(pRi);
    }

    inline KgeRMatrix::KgeRMatrix(const KgeRMatrix& pRi)
    {
	    (void) KmMset((double (*)[4]) mData, pRi.mData);
    }

    inline KgeRMatrix::KgeRMatrix(const KgeQuaternion& pQi)
    {
	    (void) KmQtoR((double (*)[4]) mData, pQi.mData);
	    (void) KmRinit((double (*)[4]) mData);
    }

    inline KgeRMatrix& KgeRMatrix::Init()
    {
	    return *(KgeRMatrix *) KmId((double (*)[4]) mData);
    }

    inline KgeRMatrix& KgeRMatrix::operator=(const double (*const pRi)[4])
    {
	    return *(KgeRMatrix *) KmRset((double (*)[4]) mData, pRi);
    }

    inline KgeRMatrix& KgeRMatrix::operator=(const KgeRMatrix& pRi)
    {
	    return operator=(pRi.mData);
    }

    inline KgeRMatrix::operator const double *() const
    {
	    return &mData[0][0];
    }

    ////////////////////////////////////////////////////////////////////////////////
    //
    //	Class KgeSMatrix
    //
    ////////////////////////////////////////////////////////////////////////////////

    inline KgeSMatrix::KgeSMatrix()
    {
	    (void) Init();
    }

    inline KgeSMatrix::KgeSMatrix(const double pXYZ)
    {
	    (void) KmSinit(mData);
	    mData[0][0] = mData[1][1] = mData[2][2] = pXYZ;
    }

    inline KgeSMatrix::KgeSMatrix(const double pX, const double pY, const double pZ)
    {
	    (void) KmSinit(mData);
	    mData[0][0] = pX;
	    mData[1][1] = pY;
	    mData[2][2] = pZ;
    }

    inline KgeSMatrix::KgeSMatrix(const double (*const pSi)[4])
    {
	    double S[3];

	    (void) KmId(mData);
	    (void) KmAtoS(S, pSi);

	    mData[0][0] = S[0];
	    mData[1][1] = S[1];
	    mData[2][2] = S[2];
    }

    inline KgeSMatrix::KgeSMatrix(const KgeSMatrix& pSi)
    {
	    (void) KmMset((double (*)[4]) mData, pSi.mData);
    }

    inline KgeSMatrix& KgeSMatrix::Init()
    {
	    return *(KgeSMatrix *) KmId((double (*)[4]) mData);
    }

    inline KgeSMatrix& KgeSMatrix::operator=(const double (*const pSi)[4])
    {
	    return *(KgeSMatrix *) KmSset((double (*)[4]) mData, pSi);
    }

    inline KgeSMatrix& KgeSMatrix::operator=(const KgeTMatrix& pSi)
    {
	    return operator=(pSi.mData);
    }

    inline KgeSMatrix::operator const double *() const
    {
	    return &mData[0][0];
    }

    ////////////////////////////////////////////////////////////////////////////////
    //
    //	Class KgeLUMatrix
    //
    ////////////////////////////////////////////////////////////////////////////////

    inline KgeLUMatrix::KgeLUMatrix()
    {
	    (void) Init();
    }

    inline KgeLUMatrix::KgeLUMatrix(const KgeMatrix& pMi)
    {
	    (void) KmMset((double (*)[4]) mData, (const double (*)[4]) pMi.mData);
	    (void) KmLU(mData);
    }

    inline KgeLUMatrix& KgeLUMatrix::Init()
    {
	    return *(KgeLUMatrix *) KmId((double (*)[4]) mData);
    }

    inline KgeLUMatrix::operator const double *() const
    {
	    return &mData[0][0];
    }

    ////////////////////////////////////////////////////////////////////////////////
    //
    //	Class KgeXForm
    //
    ////////////////////////////////////////////////////////////////////////////////

    inline KgeXForm::KgeXForm()
    {
	    mF = FLAG_A;
    }

    inline KgeXForm::KgeXForm(KgeXForm& pXi)
    {
	    (void) operator=(pXi);
    }

    inline KgeXForm::KgeXForm(const KgeTVector& pTi) : mM(pTi)
    {
	    mF = FLAG_A;
    }

    inline KgeXForm::KgeXForm(const KgeRVector& pRi) : mR(pRi)
    {
	    mF = FLAG_R;
    }

    inline KgeXForm::KgeXForm(const KgeRVector& pRi, const int pOrd) : mM(pRi, pOrd)
    {
	    mF = FLAG_M;
    }

    inline KgeXForm::KgeXForm(const KgeTVector& pTi, const KgeRVector& pRi) : mM(pTi, pRi), mR(pRi)
    {
	    mF = FLAG_M | FLAG_R;
    }

    inline KgeXForm::KgeXForm(const KgeTVector& pTi, const KgeRVector& pRi, const int pOrd) : mM(pTi, pRi, pOrd)
    {
	    mF = FLAG_M;
    }

    inline KgeXForm::KgeXForm(const KgeTVector& pTi, const KgeQuaternion& pQi) : mM(pTi, pQi), mQ(pQi)
    {
	    mF = FLAG_M | FLAG_Q;
    }

    inline KgeXForm::KgeXForm(const double (*const pMi)[4]) : mM(pMi)
    {
	    mF = FLAG_M;
    }

    inline KgeXForm::KgeXForm(const KgeAMatrix& pAi) : mM(pAi)
    {
	    mF = FLAG_M;
    }

    inline KgeXForm::~KgeXForm()
    {
    }

    inline KgeXForm& KgeXForm::Init()
    {
	    return mF = FLAG_A, mM.Init(), mR.Init(), mQ.Init(), *this;
    }

    inline KgeXForm& KgeXForm::operator=(const KgeXForm& pXi)
    {
	    return *(KgeXForm *) memcpy((void *) this, (void *) &pXi, sizeof(KgeXForm));
    }

    inline KgeXForm& KgeXForm::operator=(const KgeAMatrix& pAi)
    {
	    return SetM(pAi), *this;
    }

    inline KgeXForm& KgeXForm::operator=(const KgeRMatrix& pRi)
    {
	    return SetM((KgeAMatrix&) pRi), *this;
    }

    inline KgeXForm& KgeXForm::operator=(const KgeTMatrix& pTi)
    {
	    return SetM((KgeAMatrix&) pTi), *this;
    }

    inline KgeXForm& KgeXForm::operator=(const double (*const pM)[4])
    {
	    return SetM((KgeAMatrix&) pM), *this;
    }

    inline const KgeAMatrix& KgeXForm::GetM()
    {
	    if(mF & FLAG_M) {
		    return mM;
	    }
	    if(mF & FLAG_Q) {
		    (void) KgeSet((KgeRMatrix&) mM, mQ);
	    } else {
		    (void) KgeSet((KgeRMatrix&) mM, mR);
	    }
	    return mF |= FLAG_M, mM;
    }

    inline const KgeTVector& KgeXForm::GetT() const
    {
	    return *(KgeTVector *) mM.mData[3];
    }

    inline const KgeTVector& KgeXForm::GetI()
    {
	    return *(KgeTVector *) mM.mData[0];
    }

    inline const KgeTVector& KgeXForm::GetJ()
    {
	    return *(KgeTVector *) mM.mData[1];
    }

    inline const KgeTVector& KgeXForm::GetK()
    {
	    return *(KgeTVector *) mM.mData[2];
    }

    inline double KgeXForm::GetTX() const
    {
	    return mM.mData[3][0];
    }

    inline double KgeXForm::GetTY() const
    {
	    return mM.mData[3][1];
    }

    inline double KgeXForm::GetTZ() const
    {
	    return mM.mData[3][2];
    }

    inline const KgeRVector& KgeXForm::GetR()
    {
	    if(mF & FLAG_R) {
		    return mR;
	    }
	    if(mF & FLAG_M) {
		    (void) KgeSet(mR, (KgeRMatrix&) mM);
	    } else {
		    (void) KgeSet(mR, mQ);
	    }
	    return mF |= FLAG_R, mR;
    }

    inline const KgeRVector& KgeXForm::GetR(KgeRVector& pVo, const int pOrd)
    {
	    if(pOrd == KM_EULER_XYZ) {
		    return KgeSet(pVo, GetR());
	    } else {
		    return KgeSet(pVo, (KgeRMatrix&) GetM(), pOrd);
	    }
    }

    inline double KgeXForm::GetRX()
    {
	    if(mF & FLAG_R) {
		    return mR.mData[0];
	    }
	    if(mF & FLAG_M) {
		    (void) KgeSet(mR, (KgeRMatrix&) mM);
	    } else {
		    (void) KgeSet(mR, mQ);
	    }
	    return mF |= FLAG_R, mR.mData[0];
    }

    inline double KgeXForm::GetRY()
    {
	    if(mF & FLAG_R) {
		    return mR.mData[1];
	    }
	    if(mF & FLAG_M) {
		    (void) KgeSet(mR, (KgeRMatrix&) mM);
	    } else {
		    (void) KgeSet(mR, mQ);
	    }
	    return mF |= FLAG_R, mR.mData[1];
    }

    inline double KgeXForm::GetRZ()
    {
	    if(mF & FLAG_R) {
		    return mR.mData[2];
	    }
	    if(mF & FLAG_M) {
		    (void) KgeSet(mR, (KgeRMatrix&) mM);
	    } else {
		    (void) KgeSet(mR, mQ);
	    }
	    return mF |= FLAG_R, mR.mData[2];
    }

    inline const KgeQuaternion& KgeXForm::GetQ()
    {
	    if(mF & FLAG_Q) {
		    return mQ;
	    }
	    if(mF & FLAG_M) {
		    (void) KgeSet(mQ, (KgeRMatrix&) mM);
	    } else {
		    (void) KgeSet((KgeRMatrix&)mM, mR);
		    (void) KgeSet(mQ, (KgeRMatrix&) mM);
		    mF |= FLAG_M;
	    }
	    return mF |= FLAG_Q, mQ;
    }

    inline const KgeAMatrix& KgeXForm::SetM(const KgeAMatrix& pM)
    {
	    return mF = FLAG_M, &mM != &pM ? KgeSet(mM, pM), pM : pM;
    }

    inline const KgeTVector& KgeXForm::SetT(const KgeTVector& pT)
    {
	    return KgeSet(*(KgeTVector *) mM.mData[3], pT), pT;
    }


    // Function must be verified before it is use
    /*
    inline const KgeTVector& KgeXForm::SetT(const double pVx, const double pVy, const double pVz)
    {
	    return mM.mData[3][0] = pVx, mM.mData[3][1] = pVy, mM.mData[3][2] = pVz, mM.mData[3];
    }
    */

    inline double KgeXForm::SetTX(const double pVx)
    {
	    return mM.mData[3][0] = pVx;
    }

    inline double KgeXForm::SetTY(const double pVy)
    {
	    return mM.mData[3][1] = pVy;
    }

    inline double KgeXForm::SetTZ(const double pVz)
    {
	    return mM.mData[3][2] = pVz;
    }

    inline const KgeRVector& KgeXForm::SetR(const KgeRVector& pR)
    {
	    return mF = FLAG_R, KgeSet(mR, pR);
    }

    inline const KgeRVector& KgeXForm::SetR(const KgeRVector& pR, const int pOrd)
    {
	    return mF = FLAG_M, KgeSet((KgeRMatrix&) mM, pR, pOrd), pR;
    }

    inline const KgeRVector& KgeXForm::SetR(const double pVx, const double pVy, const double pVz)
    {
	    return mF = FLAG_R, mR.mData[0] = pVx, mR.mData[1] = pVy, mR.mData[2] = pVz, mR;
    }

    inline double KgeXForm::SetRX(const double pVx)
    {
	    return mF = FLAG_R, mR.mData[0] = pVx;
    }

    inline double KgeXForm::SetRY(const double pVy)
    {
	    return mF = FLAG_R, mR.mData[1] = pVy;
    }

    inline double KgeXForm::SetRZ(const double pVz)
    {
	    return mF = FLAG_R, mR.mData[2] = pVz;
    }

    inline const KgeQuaternion& KgeXForm::SetQ(const KgeQuaternion& pQ)
    {
	    return mF = FLAG_Q, KgeSet(mQ, pQ);
    }

    inline KgeXForm& KgeXForm::operator*=(const KgeXForm& pXi)
    {
	    return KgeMult(*this, (KgeXForm&) pXi, *this);
    }

    inline KgeXForm& KgeXForm::operator/=(const KgeXForm& pXi)
    {
	    return KgeInvMult(*this, (KgeXForm&) pXi, *this);
    }

    /*
    *	KgeId : Transform Set
    */
    inline KgeXForm& KgeIdentity(KgeXForm& pXo)
    {
	    return pXo.Init();
    }

    /*
    *	KgeSet : Transform Set
    */
    inline KgeXForm& KgeSet(KgeXForm& pXo, const KgeXForm& pXi)
    {
	    return pXo = pXi;
    }

    /*
    *	KgeSet : Transform Set
    */
    inline KgeXForm& KgeSet(KgeXForm& pXo, const KgeTVector& pTi, const KgeRVector& pRi)
    {
	    return pXo.SetT(pTi), pXo.SetR(pRi), pXo;
    }

    /*
    *	KgeMult : Transform Product
    */
    inline KgeXForm& KgeMult(KgeXForm& pTo, KgeXForm& pTiA, KgeXForm& pTiB)
    {
	    return pTo.mF = KgeXForm::FLAG_M, (KgeXForm&) KgeMult(pTo.mM, pTiA.GetM(), pTiB.GetM());
    }

    /*
    *	KgeInvMult : Transform Inverse Product
    */
    inline KgeXForm& KgeInvMult(KgeXForm& pTo, KgeXForm& pTiA, KgeXForm& pTiB)
    {
	    return pTo.mF = KgeXForm::FLAG_M, (KgeXForm&) KgeInvMult(pTo.mM, pTiA.GetM(), pTiB.GetM());
    }

    /*
    // Helpers for Number Validation
    */
    inline bool KgeValidate(double *pVector)
    {
        return  ( kValidate(pVector[0]) == pVector[0] ) &&
                ( kValidate(pVector[1]) == pVector[1] ) &&
                ( kValidate(pVector[2]) == pVector[2] ) &&
                ( kValidate(pVector[3]) == pVector[3] );
    }

    inline bool KgeValidate(KgeVector &pVectorToValidate)
    {
        return  KgeValidate(pVectorToValidate.mData);
    }

    inline bool KgeValidate(KgeMatrix &pMatrixToValidate)
    {
        return  KgeValidate(pMatrixToValidate.mData[0]) && KgeValidate(pMatrixToValidate.mData[1]) && 
                KgeValidate(pMatrixToValidate.mData[2]) && KgeValidate(pMatrixToValidate.mData[3]);
    }


    ////////////////////////////////////////////////////////////////////////////////
    //
    //	Class KRect
    //
    ////////////////////////////////////////////////////////////////////////////////

    inline KRect::KRect()
    : mX(0), mY(0), mW(0), mH(0)
    {
    }


    inline KRect::KRect(int pX, int pY, int pW, int pH)
    : mX(pX), mY(pY), mW(pW), mH(pH)
    {
    }

	inline int KRect::GetLeft()const
	{
	    return mX;
	}
	
	inline int KRect::GetRight()const
	{
	    return mX + mW;
	}
	
	inline int KRect::GetBottom()const
	{
	    return mY + mH;
	}
	
	inline int KRect::GetTop()const
	{
	    return mY;
	}

    inline void KRect::Union(const KRect& pRect)
    {
	    int lX2, lY2;
	    int lX3, lY3;

	    lX2 = mX + mW;
	    lY2 = mY + mH;

	    lX3 = pRect.mX + pRect.mW;
	    lY3 = pRect.mY + pRect.mH;

	    if (pRect.mX < mX)
		    mX = pRect.mX;

	    if (pRect.mY < mY)
		    mY = pRect.mY;

	    if (lX3 > lX2)
		    lX2 = lX3;

	    if (lY3 > lY2)
		    lY2 = lY3;

	    mW = lX2 - mX;
	    mH = lY2 - mY;

    }

    inline bool KRect::PointInside(int pX, int pY)
    {
	    if (pX >= mX && pX <= (mX + mW))
		    if (pY >= mY && pY <= (mY + mH))
		    {
			    return true;
		    }

	    return false;
    }

    inline bool KRect::HasAnIntersection(const KRect& pRect) const
    {
	    if ( ((mX + mW) > pRect.mX) && (mX < (pRect.mX + pRect.mW)) )
	    {
		    // rectanbles intersect on X, check Y
		    if ( ((mY + mH) > pRect.mY) && (mY < (pRect.mY + pRect.mH)) )
		    {
			    return true;
		    }
	    }

	    return false;
    }

    // StrictlyContains: pRect is inside this Rect and does not touch any side.
    inline bool KRect::StrictlyContains(const KRect& pRect) const
    {
	    if	(  ( mX < pRect.mX) && ((mX + mW) > (pRect.mX + pRect.mW))		// Contains in X
		    && ( mY < pRect.mY) && ((mY + mH) > (pRect.mY + pRect.mH)) )	// Contains in Y
	    {
		    return true;
	    }
	    return false;
    }

    // StrictlyIntersects: pRect crosses or overlaps one of the sides of this Rect.
    inline bool KRect::StrictlyIntersects(const KRect& pRect) const
    {
	    if ( ((mX + mW) >= pRect.mX) && (mX <= (pRect.mX + pRect.mW)) )		// Intersect in X
	    {
		    if ( ((mY + mH) >= pRect.mY) && (mY <= (pRect.mY + pRect.mH)) )	// Intersect in Y
		    {
			    if (!StrictlyContains(pRect) && !pRect.StrictlyContains(*this))
			    {
				    return true;
			    }
		    }
	    }
	    return false;
    }

    inline void KRect::Intersection(const KRect& pRect)
    {
        int lNx, lNy;
        int lNw, lNh;
        
	    // take the biggest left
	    if (pRect.mX > mX)
		    lNx = pRect.mX;
        else
            lNx = mX;

	    // take the smallest right
	    if ( (pRect.mX + pRect.mW) < (mX + mW))
		    lNw = pRect.mX + pRect.mW - lNx;
        else
            lNw = mX + mW - lNx;

	    // take the biggest top
	    if (pRect.mY > mY)
		    lNy = pRect.mY;
        else
            lNy = mY;

	    // take the smallest bottom
	    if ( (pRect.mY + pRect.mH) < (mY + mH))
		    lNh = pRect.mY + pRect.mH - lNy;
        else
            lNh = mY + mH - lNy;

        mX = lNx;
        mY = lNy;
        mW = lNw;
        mH = lNh;
    }


    inline void KRect::Translate(int pDeltaX, int pDeltaY)
    {
	    mX += pDeltaX;
	    mY += pDeltaY;
    }

#include <fbxfilesdk/fbxfilesdk_nsend.h>

#endif // FBXFILESDK_COMPONENTS_KBASELIB_KMATH_KGEOM_H

