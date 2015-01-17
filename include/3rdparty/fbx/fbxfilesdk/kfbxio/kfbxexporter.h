/*!  \file kfbxexporter.h
 */
 
#ifndef FBXFILESDK_KFBXIO_KFBXEXPORTER_H
#define FBXFILESDK_KFBXIO_KFBXEXPORTER_H

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
#include <fbxfilesdk/kfbxio/kfbxio.h>

#include <fbxfilesdk/components/kbaselib/klib/kstring.h>
#include <fbxfilesdk/components/kbaselib/klib/karrayul.h>

#include <fbxfilesdk/components/kbaselib/kbaselib_forward.h>

#ifdef KARCH_DEV_MACOSX_CFM
	#include <CFURL.h>
	#include <Files.h>
#endif

#include <fbxfilesdk/kfbxplugins/kfbxrenamingstrategy.h>
#include <fbxfilesdk/kfbxevents/kfbxevents.h>

#include <fbxfilesdk/fbxfilesdk_nsbegin.h>

class KFbxDocument;
class KFbxExporterImp;
class KFbxStreamOptionsFbxWriter;
class KFbxStreamOptions;
class KFbxFileHeaderInfo;

//! Event that is emitted to plugins before a file is exported to the FBX format.
class KFBX_DLL KFbxEventPreExport : public KFbxEvent<KFbxEventPreExport>
{
    KFBXEVENT_DECLARE(KFbxEventPreExport);
public:
    inline KFbxEventPreExport( KFbxDocument* pDocument ) : mDocument(pDocument) {};

    //! The document to be exported
    KFbxDocument* mDocument;
};

//! Event that is emitted to plugins after a file is exported to the FBX format.
class KFBX_DLL KFbxEventPostExport : public KFbxEvent<KFbxEventPostExport>
{
    KFBXEVENT_DECLARE(KFbxEventPostExport);
public:
    inline KFbxEventPostExport( KFbxDocument* pDocument ) : mDocument(pDocument) {};

    //! The document to be exported
    KFbxDocument* mDocument;
};

/** \brief Class to export SDK objects into an FBX file.
  *
  * \nosubgrouping
  *	Typical workflow for using the KFbxExporter class:
  *		-# create an exporter
  *		-# initialize it with a file name
  *		-# set numerous states, take information, defining how the exporter will behave
  *		-# call KFbxExporter::Export() with the entity to export
  */
class KFBX_DLL KFbxExporter : public KFbxIO
{
	KFBXOBJECT_DECLARE(KFbxExporter, KFbxIO);

public:

	/** 
	  * \name Export Functions
	  */
	//@{

	/** Initialize object.
	  *	\param pFileName     Name of file to access.
      * \param pFileFormat   file format identifier User does not need to specify it by default.
                             if not specified, plugin will detect the file format according to file suffix automatically.
      *	\return              \c true on success, \c false otherwise.
	  * \remarks             To identify the error that occurred, call KFbxIO::GetLastErrorID().
	  */
	virtual bool Initialize(const char *pFileName, int pFileFormat = -1);

#ifdef KARCH_DEV_MACOSX_CFM
    virtual bool Initialize(const FSSpec &pMacFileSpec);
    virtual bool Initialize(const FSRef &pMacFileRef);
    virtual bool Initialize(const CFURLRef &pMacURL);
#endif

    /** Get file export options settings.
	  *	\return     Pointer to file export options or NULL on failure.
	  * \remarks    Caller gets ownership of the returned structure.
      */	
	KFbxStreamOptions* GetExportOptions();
    
	/** Export the document to the currently created file.
      * \param pDocument          Document to export.
	  * \param pStreamOptions     Pointer to file export options.
	  *	\return                   \c true on success, \c false otherwise.
	  * \remarks                  To identify the error, call KFbxIO::GetLastErrorID().
      */
    bool Export(KFbxDocument* pDocument, KFbxStreamOptions* pStreamOptions = NULL);

    /** Release the file export options. 
	  * \param pStreamOptions     Pointer to file export options.
	  */
	void ReleaseExportOptions(KFbxStreamOptions* pStreamOptions);

	//@}

	/** 
	  * \name File Format
	  */
	//@{

	/** Set the exported file format.
	  *	\param pFileFormat     File format identifier.
	  */
	K_DEPRECATED void SetFileFormat(int pFileFormat);

	/** Get the format of the exported file.
	  *	\return     File format identifier.
	  */
	int GetFileFormat();

	/** Return     \c true if the file format is a recognized FBX format.
	  */
	bool IsFBX();

	/** Get writable version for the current file format.
	  * \return     \c char**
	  */
	char const* const* GetCurrentWritableVersions();

	/** Set file version for a given file format.
	  * \param pVersion        String description of the file format.
	  * \param pRenamingMode   Renaming mode.
	  * \return                \c true if mode is set correctly
	  */
	bool SetFileExportVersion(KString pVersion, KFbxSceneRenamer::ERenamingMode pRenamingMode);

	/** Set the resampling rate (only used when exporting to FBX5.3 and lower)
	  * \param     pResamplingRate resampling rate
	  */
	inline void SetResamplingRate(double pResamplingRate){mResamplingRate = pResamplingRate;}

    /** Set the default rendering resolution.
    * \param pCamName            name of the camera.
    * \param pResolutionMode     resolution mode.
    * \param pW                  width.
    * \param pH                  height.
    */
    void SetDefaultRenderResolution(KString pCamName, KString pResolutionMode, double pW, double pH);

    /**	Get the complete file header information.
    * \return		valid pointer to the complete header information
    */
    KFbxFileHeaderInfo* GetFileHeaderInfo();

	//@}


///////////////////////////////////////////////////////////////////////////////
//
//  WARNING!
//
//	Anything beyond these lines may not be documented accurately and is 
// 	subject to change without notice.
//
///////////////////////////////////////////////////////////////////////////////

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    /** Get file export option settings.
      * \param pFbxObject     Target FBX file.
	  *	\return               Pointer to stream export options or NULL on failure.
	  * \remarks              Caller gets ownership of the returned structure.
      */	
	KFbxStreamOptions* GetExportOptions(KFbx* pFbxObject);

	//Internal use only, please use the other Export function to do your exports
	bool Export(KFbxDocument* pDocument, KFbxStreamOptions* pStreamOptions, KFbx* pFbxObject);

protected:
	KFbxExporter(KFbxSdkManager& pManager,char const *pName);
	virtual void Destruct(bool pRecursive, bool pDependents);

	void Reset();

	bool FileCreate();
	void FileClose();

	KFbxExporterImp* mImp;

	KString mStrFileVersion;
	double  mResamplingRate;
	KFbxSceneRenamer::ERenamingMode mRenamingMode;
    KFbxFileHeaderInfo*				mHeaderInfo;

#endif // #ifndef DOXYGEN_SHOULD_SKIP_THIS

};

#include <fbxfilesdk/fbxfilesdk_nsend.h>

#endif // FBXFILESDK_KFBXIO_KFBXEXPORTER_H

