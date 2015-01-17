/*!  \file kfbxreader.h
 */

#ifndef FBXFILESDK_KFBXIO_KFBXREADER_H
#define FBXFILESDK_KFBXIO_KFBXREADER_H

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
#include <fbxfilesdk/components/kbaselib/klib/kerror.h>

#include <fbxfilesdk/components/kbaselib/kbaselib_forward.h>
#include <fbxfilesdk/components/kfcurve/kfcurve_forward.h>

#include <fbxfilesdk/components/kbaselib/kfbx/kfbx.h>

#include <fbxfilesdk/fbxfilesdk_nsbegin.h>

class KFbxDocument;
class KFbxNode;
class KFbxSdkManager;
class KFbxImporter;
class KFbxStreamOptions;
class KFbxIOSettings;
class KFbxAxisSystem;
class KFbxSystemUnit;
class KFbxStatistics;
class KFile;
class KFbxObject;
class KFbxScene;


 /** This class provides the interface for reading files. It is the basis of other FBX readers.
      * \nosubgrouping
      */

class KFBX_DLL KFbxReader
{
public:
	/** Constructor
      *	\param pManager        The KFbxSdkManager Object
      * \param pID             Id for current reader
      */
    KFbxReader(KFbxSdkManager& pManager, int pID);

	 /** Destructor
      */
    virtual ~KFbxReader();

    
	/** \enum EError  Error identifiers.
              * - \e eFILE_CORRUPTED
              * - \e eFILE_VERSION_NOT_SUPPORTED_YET
              * - \e eFILE_VERSION_NOT_SUPPORTED_ANYMORE
              * - \e eFILE_NOT_OPENED
              * - \e eFILE_NOT_CREATED
              * - \e eWRONG_PASSWORD
              * - \e eSTREAM_OPTIONS_NOT_SET
              * - \e eINVALID_DOCUMENT_HANDLE
              * - \e eDOCUMENT_NOT_SUPPORTED
			  * - \e eUNRESOLVED_EXTERNAL_REFERENCES
			  * - \e eUNIDENTIFIED_ERROR
              * - \e eERROR_COUNT			  
              */
    typedef enum
    {
        eFILE_CORRUPTED,
        eFILE_VERSION_NOT_SUPPORTED_YET,
        eFILE_VERSION_NOT_SUPPORTED_ANYMORE,
        eFILE_NOT_OPENED,
        eFILE_NOT_CREATED,
        eWRONG_PASSWORD,
        eSTREAM_OPTIONS_NOT_SET,
        eINVALID_DOCUMENT_HANDLE,
        eDOCUMENT_NOT_SUPPORTED,
        eUNRESOLVED_EXTERNAL_REFERENCES, // this is a warning
        eUNIDENTIFIED_ERROR,
        eERROR_COUNT
    } EError;

    enum KInfoRequest {
        eInfoExtension, // return a null terminated char const* const*
        eInfoDescriptions, // return a null terminated char const* const*
        eReserved1 = 0xFBFB,
    };

    enum EFileOpenSpecialFlags {
		ParseForGlobalSettings = 1, 
		ParseForStatistics = 2
	};

    typedef KFbxReader*			(*CreateFuncType)(KFbxSdkManager& pManager, KFbxImporter& pImporter, int pSubID, int pPluginID);
    typedef void				(*IOSettingsFillerFuncType)(KFbxIOSettings& pIOS);
    typedef void*				(*GetInfoFuncType)(KInfoRequest pRequest, int pReaderTypeId);



	/** Returns the file version
      *	\param pMajor       Major version
      *	\param pMinor       Minor version
      *	\param pRevision    Revision version
      */
	virtual void				GetVersion(int& pMajor, int& pMinor, int& pRevision){ pMajor = pMinor = pRevision = 0; }

	/** Opens the file with default flag
      *	\param pFileName     Name of the File to open
      * \return  If the file opens successfully return \c true, otherwise return \c false.
      */
    virtual bool				FileOpen(char* pFileName) = 0;

	 /** Opens the file with KFile handle
      *	\param pFile     The KFile handle
      * \return          If the file opens successfully return \c true, otherwise return \c false.
      */
    virtual bool				FileOpen(KFile * pFile);

	/** Closes the file stream
      * \return  \c false
      */
    virtual bool				FileClose() = 0;

	 /** Checks if the file stream is open.
      *	\return  \c false.
      */
    virtual bool				IsFileOpen() = 0;

	/** Returns file stream options
      *	\param pParseFileAsNeeded       Sets whether to parse file as read options
      * \return \c NULL 
      */
    virtual KFbxStreamOptions*	GetReadOptions(bool pParseFileAsNeeded = true) = 0;

	/** Reads file with stream options
      *	\param pDocument        KFbxDocument to store the file data
      * \param pStreamOptions   Read options to read file
      *	\return \c false.
      */
    virtual bool				Read(KFbxDocument* pDocument, KFbxStreamOptions* pStreamOptions) = 0;




//----------------------------------------------------------------------------------------------------------------------
	/** Reads all properties and flags
      *	\param pParams        Settings for assigning properties and flags
      */
	virtual void				PluginReadParameters(KFbxObject& pParams){}
//----------------------------------------------------------------------------------------------------------------------

	/** Opens the file with specific EFileOpenSpecialFlags
      * \param pFileName     Name of the File to open
      * \param pFlags        The EFileOpenSpecialFlags to open with
      * \return If the file opens successfully return true, otherwise return false.
      */
    virtual bool				FileOpen(char* pFileName, EFileOpenSpecialFlags pFlags){ return FileOpen(pFileName); }

	/** Returns the system axis information from the file
      *	\param pAxisSystem      Axis system in file
      * \param pSystemUnits     System unit in file
      * \return \c false.
      */
    virtual bool				GetAxisInfo(KFbxAxisSystem* pAxisSystem, KFbxSystemUnit* pSystemUnits){ return false; }

	/** Returns statistics from the file 
      *	\param pStats Statistics in the file.
      *	\return \c false.
      */
    virtual bool				GetStatistics(KFbxStatistics* pStats){ return false; }

	/** If default camera resolution is OK, returns information about the resolution of the render.
      *	\param pCamName Default camera name.
	  *	\param pResolutionMode Default resolution mode.
	  *	\param pW Default resolution width.
	  *	\param pH Default resolution height.
      *	\return \c true If default camera resolution is OK, \c false  Otherwise.
      */
	bool						GetDefaultRenderResolution(KString& pCamName, KString& pResolutionMode, double& pW, double& pH);

	/** Judges if the format of the file is an internal plug-in .
      *	\return \c true If the file format is internal plug-in , \c false Otherwise .
      */
	bool						IsGenuine();

	/** Retrieves error objects.
      * \return Reference to error objects.
      */
    KError&						GetError();
	/** Returns the ID of the last error that  occurred when the file was read.
      * \return Last error ID.
      */
    EError						GetLastErrorID() const;

	/** Returns the error string that describes the last error that occurred when the file was read.
      * \return A text description of the last error.
      */
    const char*					GetLastErrorString() const;

	/** Returns a warning message that describes what occurred when the file was read.
      *	\param pMessage The returned warning message.
      */
    void						GetMessage(KString& pMessage) const;

	/** Returns a warning message that describes what occurred when the file was read.
      *	\return The warning message.
      */
    KString&					GetMessage();

	/** Empties the message string.
      */
    void						ClearMessage();

protected:
	void						SetDefaultRenderResolution(const char* pCamName, const char* pResolutionMode, double pW, double pH);
	
	void						PluginsReadBegin(KFbxScene& pScene);
	void						PluginsRead(char* pName, char* pVersion);
	void						PluginsReadEnd(KFbxScene& pScene);

    KFbxReader&					operator=(KFbxReader const&) { return *this; }
    virtual bool				CheckDuplicateNodeNames(KFbxNode* pRootNode, KString& pDuplicateNodeNameList);

    KFbxSdkManager&				mManager;
    KDefaultRenderResolution*	mData;

private:
    KError						mError;
    KString						mMessage;
	int							mInternalID;
};

#include <fbxfilesdk/fbxfilesdk_nsend.h>

#endif // FBXFILESDK_KFBXIO_KFBXREADER_H

