#ifndef FBXFILESDK_KFBXIO_KFBXSTREAMOPTIONSMOTION_H
#define FBXFILESDK_KFBXIO_KFBXSTREAMOPTIONSMOTION_H

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




#define KFBXSTREAMOPT_MOTION_TRANSLATION "TRANSLATION"
#define KFBXSTREAMOPT_MOTION_ROTATION "ROTATION"
#define KFBXSTREAMOPT_MOTION_SCALING "SCALING"
#define KFBXSTREAMOPT_MOTION_UNUSED_SEGMENTS "UNUSED SEGMENTS"
#define KFBXSTREAMOPT_MOTION_AS_OPTICAL_SEGMENTS "AS OPTICAL SEGMENTS"
#define KFBXSTREAMOPT_MOTION_EXACT_ZERO_AS_OCCLUDED "EXACT ZERO AS OCCLUDED"
#define KFBXSTREAMOPT_MOTION_SET_OCCLUDED_TO_LAST_VALID_POSITION "SET OCCLUDED TO LAST VALID POSITION"
#define KFBXSTREAMOPT_MOTION_ACTOR_PREFIX "ACTOR PREFIX"
#define KFBXSTREAMOPT_MOTION_CREATE_REFERENCE_NODE "CREATE REFERENCE NODE"
#define KFBXSTREAMOPT_MOTION_DUMMY_NODES "DUMMY NODES"
#define KFBXSTREAMOPT_MOTION_LIMITS "LIMITS"
#define KFBXSTREAMOPT_MOTION_RENAME_DUPLICATE_NAMES "RENAME DUPLICATE NAMES"
#define KFBXSTREAMOPT_MOTION_BASE_T_IN_OFFSET "BASE T IN OFFSET"
#define KFBXSTREAMOPT_MOTION_BASE_R_IN_PREROTATION "BASE R IN PREROTATION"
#define KFBXSTREAMOPT_MOTION_START "START"
#define KFBXSTREAMOPT_MOTION_FRAME_RATE "FRAME RATE"
#define KFBXSTREAMOPT_MOTION_ASF_SCENE_OWNED "ASF SCENE OWNED"
#define KFBXSTREAMOPT_MOTION_GAPS_AS_VALID_DATA "GAPS AS VALID DATA"
#define KFBXSTREAMOPT_MOTION_C3D_REAL_FORMAT "C3D REAL FORMAT"
#define KFBXSTREAMOPT_MOTION_FROM_GLOBAL_POSITION "FROM GLOBAL POSITION"
#define KFBXSTREAMOPT_MOTION_REQUIRE_SINGLE_ROOT_NODE "REQUIRE SINGLE ROOT NODE"
#define KFBXSTREAMOPT_MOTION_FRAME_RATE_USED "FRAME RATE USED"
#define KFBXSTREAMOPT_MOTION_FRAME_RANGE "FRAME RANGE"
#define KFBXSTREAMOPT_MOTION_FRAME_COUNT "FRAME COUNT"
#define KFBXSTREAMOPT_MOTION_TAKE_NAME "TAKE NAME"



#include <fbxfilesdk/components/kbaselib/kaydaradef_h.h>
#include <fbxfilesdk/kfbxio/kfbxstreamoptions.h>

#include <fbxfilesdk/fbxfilesdk_nsbegin.h>

class KFBX_DLL KFbxAsfSceneInterface
{
public:
    virtual void Destroy() = 0;

protected:  // Force going through Destroy()
    virtual ~KFbxAsfSceneInterface() {}
};

/**	This class is used for the Import options of Motion files.
  * \par 
  * The content of a KfbxStreamOptionsMotion is stored in the inherited Property of its parent (KFbxStreamOptions).
  */
class KFBX_DLL KFbxStreamOptionsMotionReader : public KFbxStreamOptions
{
	KFBXOBJECT_DECLARE(KFbxStreamOptionsMotionReader,KFbxStreamOptions);
public:

	/** Reset all the options to default value
	*/
	void Reset();

	/** Sets the Time Mode
	* \param pTimeMode the time mode to be used.
	* \param pCustomFrameRate the value of the frame rate. 
	*/
	void SetTimeMode(KTime::ETimeMode pTimeMode, double pCustomFrameRate = 0.0);

	/** Sets the Time Mode
	* \return the time mode.
	*/
	inline KTime::ETimeMode GetTimeMode(){return mTimeMode;}

	/** Gets the Start Time
	* \return the Start Time (KTime)
	*/
	inline KTime GetStart() {return (KFbxGet <KTime> (this->GetOption(KFBXSTREAMOPT_MOTION_START)));}
	
	/** Gets the Frame Count
	* \return the Total Frame Count
	*/
	inline int GetFrameCount() {return (KFbxGet <int> (this->GetOption(KFBXSTREAMOPT_MOTION_FRAME_COUNT)));}

	/** Gets the Frame Rate
	* \return the Frame Rate
	*/
	inline double GetFrameRate() {return (KFbxGet <int> (this->GetOption(KFBXSTREAMOPT_MOTION_FRAME_RATE)));}

	/** Sets the Start Time
	* \param pStartTime the start time to be set.
	*/
	inline void SetStart(KTime pStartTime) {this->GetOption(KFBXSTREAMOPT_MOTION_START).Set(pStartTime);}

	/** Sets the Frame Count
	* \param pFrameCount the frame count to be set.
	*/
	inline void SetFrameCount(int pFrameCount){this->GetOption(KFBXSTREAMOPT_MOTION_FRAME_COUNT).Set(pFrameCount);}

	/** Gets the Frame Period
	* \return the Frame Period (KTime).
	*/
	KTime GetFramePeriod();
	

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
	virtual KFbxObject* Clone(KFbxObject* pContainer, KFbxObject::ECloneType pCloneType) const;

	/** Sets the ASF Scene
	* \param pASFScene the ASF Scene to be set.
	* \param pASFSceneOwned boolean representing if the scene is owned or not.
	*/
	void SetASFScene(KFbxAsfSceneInterface *pASFScene, bool pASFSceneOwned = false);

	/** Gets the ASF Scene
	* \return the ASF Scene.
	*/
	inline KFbxAsfSceneInterface* GetASFScene(){return mASFScene;}

protected:
	KFbxStreamOptionsMotionReader(KFbxSdkManager& pManager, char const* pName);
	virtual void Construct(const KFbxStreamOptionsMotionReader* pFrom);
	virtual bool ConstructProperties( bool pForceSet );
private:
	KFbxAsfSceneInterface*	 mASFScene;
	KTime::ETimeMode mTimeMode;

#endif  // DOXYGEN_SHOULD_SKIP_THIS
};




/**	This class is used for the Export options of Motion files.
  * \par 
  * The content of a KfbxStreamOptionsMotion is stored in the inherited Property of its parent (KFbxStreamOptions).
  */
class KFBX_DLL KFbxStreamOptionsMotionWriter : public KFbxStreamOptions
{
	KFBXOBJECT_DECLARE(KFbxStreamOptionsMotionWriter,KFbxStreamOptions);
public:

	/** Reset all the options to default value
	*/
	void Reset();


	/** Sets the Time Mode
	* \param pTimeMode the time mode to be used.
	* \param pCustomFrameRate the value of the frame rate. 
	*/
	void SetTimeMode(KTime::ETimeMode pTimeMode, double pCustomFrameRate = 0.0);

	/** Sets the Time Mode
	* \return the time mode.
	*/
	KTime::ETimeMode GetTimeMode(){return mTimeMode;}

	/** Gets the Start Time
	* \return the Start Time (KTime)
	*/
	KTime GetStart() {return (KFbxGet <KTime> (this->GetOption(KFBXSTREAMOPT_MOTION_START)));}

	/** Gets the Frame Count
	* \return the Total Frame Count
	*/
	int GetFrameCount() {return (KFbxGet <int> (this->GetOption(KFBXSTREAMOPT_MOTION_FRAME_COUNT)));}

	/** Gets the Frame Rate
	* \return the Frame Rate
	*/
	double GetFrameRate() {return (KFbxGet <int> (this->GetOption(KFBXSTREAMOPT_MOTION_FRAME_RATE)));}

	/** Sets the Start Time
	* \param pStartTime the start time to be set.
	*/
	void SetStart(KTime pStartTime) {this->GetOption(KFBXSTREAMOPT_MOTION_START).Set(pStartTime);}
	
	/** Sets the Frame Count
	* \param pFrameCount the frame count to be set.
	*/
	void SetFrameCount(int pFrameCount){this->GetOption(KFBXSTREAMOPT_MOTION_FRAME_COUNT).Set(pFrameCount);}

	/** Gets the Frame Period
	* \return the Frame Period (KTime).
	*/
	KTime GetFramePeriod();


#ifndef DOXYGEN_SHOULD_SKIP_THIS
public:
	virtual KFbxObject* Clone(KFbxObject* pContainer, KFbxObject::ECloneType pCloneType) const;

	/** Sets the ASF Scene
	* \param pASFScene the ASF Scene to be set.
	* \param pASFSceneOwned boolean representing if the scene is owned or not.
	*/
	void SetASFScene(KFbxAsfSceneInterface *pASFScene, bool pASFSceneOwned = false);

	/** Gets the ASF Scene
	* \return the ASF Scene.
	*/
	inline KFbxAsfSceneInterface *GetASFScene(){return mASFScene;}

protected:
	KFbxStreamOptionsMotionWriter(KFbxSdkManager& pManager, char const* pName);
	virtual void Construct(const KFbxStreamOptionsMotionWriter* pFrom);
	virtual bool ConstructProperties( bool pForceSet );

private:
	KFbxAsfSceneInterface *mASFScene;
	KTime::ETimeMode mTimeMode;

#endif  // DOXYGEN_SHOULD_SKIP_THIS
};


#include <fbxfilesdk/fbxfilesdk_nsend.h>

#endif // FBXFILESDK_KFBXIO_KFBXSTREAMOPTIONSMOTION_H

