#ifndef FBXFILESDK_COMPONENTS_KFCURVE_I_IFCURVEETI_H
#define FBXFILESDK_COMPONENTS_KFCURVE_I_IFCURVEETI_H

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

#include <fbxfilesdk/components/kfcurve/kfcurve_h.h>

#include <fbxfilesdk/components/kbaselib/object/i/iobject.h>
#include <fbxfilesdk/components/kbaselib/klib/ktime.h>
#include <fbxfilesdk/components/kbaselib/kmath/kgeom.h>

#include <fbxfilesdk/fbxfilesdk_nsbegin.h>

	class KFCurveNode;

	/**
	* IKFCurveETI provides external time information related to a fcurve node.
	* This is used by the timelinex to provide information about the clip
	* to which a given fcurve node belongs.
	*/
	#define IKFCurveETI_Declare(IsPure)\
	public:\
		/* Instance sharing */\
		virtual void IncrementRefcount() IsPure\
		virtual void DecrementRefcount() IsPure\
		/* Update id */\
		virtual int GetUpdateId() IsPure\
		/* Access to the values */\
		virtual KTime GetLclOffset() IsPure /*! The local time offset of this node in its parent (in the global scope when no parent). */\
		virtual KTime GetDuration() IsPure /*! The relevant duration of data, in the parent scale. */\
		virtual KTime GetTrimOffset() IsPure /*! The time offset of the material in the clip, in the parent scale. */\
		virtual KTime GetEaseIn() IsPure /*! The time offset of the ease-in point (additive to LclOffset), in the parent scale. */\
		virtual KTime GetEaseOut() IsPure /*! The time offset of the ease-out point (subtractive to LclOffset+Duration) */\
		virtual double GetScaleFactor() IsPure /*! The timing scale factor for this node. */\
		virtual bool IsSelectedDuration() IsPure /*! A special selection state for the whole duration. */\
		virtual KgeRGBVector GetColor() IsPure /*! The color of this node. */\
		virtual void GetIds(KFCurveNode *, void* & pConnector, void* & pClip, void* & pTrack) IsPure /*!< Additional ids for future use.> */\
		/* Editing (optional) */\
		virtual bool CanEdit() IsPure\
		virtual bool SetLclOffset(KTime const &) IsPure\
		virtual bool SetDuration(KTime const &) IsPure\
		virtual bool SetTrimOffset(KTime const &) IsPure\
		virtual bool SetEaseIn(KTime const &) IsPure\
		virtual bool SetEaseOut(KTime const &) IsPure\
		virtual bool SetScaleFactor(double) IsPure\
		virtual bool SelectDuration() IsPure\

	KFBX_INTERFACE(IKFCurveETI, 0xfce1fce1);

#include <fbxfilesdk/fbxfilesdk_nsend.h>

#endif // FBXFILESDK_COMPONENTS_KFCURVE_I_IFCURVEETI_H

