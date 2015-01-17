/*!  \file kfbxwriter.h
 */

#ifndef FBXFILESDK_KFBXIO_KFBXWRITER_H
#define FBXFILESDK_KFBXIO_KFBXWRITER_H

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
#include <fbxfilesdk/components/kbaselib/klib/kstring.h>
#include <fbxfilesdk/components/kbaselib/klib/karrayul.h>

#include <fbxfilesdk/components/kbaselib/kbaselib_forward.h>
#include <fbxfilesdk/kfbxplugins/kfbxrenamingstrategy.h>

#include <fbxfilesdk/fbxfilesdk_nsbegin.h>

class KFbxNode;
class KFbxDocument;
class KFbxScene;
class KFbxSdkManager;
class KFbxExporter;
class KFbxStreamOptions;
class KFbxIOSettings;
class KFbxObject;

 /** This class provides the interface for writing files. It is the basis for the other FBX writers.
      * \nosubgrouping
      */
class KFBX_DLL KFbxWriter
{
public:
	/** Constructor
      *	\param pManager        The KFbxSdkManager Object
      * \param pID             Id for current writer
      */
    KFbxWriter(KFbxSdkManager& pManager, int pID);
	/** Destructor
      */
    virtual ~KFbxWriter();

   	/** \enum EError  Error identifiers.
              * - \e eFILE_CORRUPTED
              * - \e eFILE_NOT_OPENED
              * - \e eFILE_NOT_CREATED
              * - \e eOUT_OF_DISK_SPACE
              * - \e eSTREAM_OPTIONS_NOT_SET
              * - \e eINVALID_DOCUMENT_HANDLE
              * - \e eDOCUMENT_NOT_SUPPORTED
			  * - \e eUNIDENTIFIED_ERROR
			  * - \e eEMBEDDED_OUT_OF_SPACE
              * - \e eERROR_COUNT			  
              */
    typedef enum
    {
        eFILE_CORRUPTED,
        eFILE_NOT_OPENED,
        eFILE_NOT_CREATED,
        eOUT_OF_DISK_SPACE,
        eSTREAM_OPTIONS_NOT_SET,
        eINVALID_DOCUMENT_HANDLE,
        eDOCUMENT_NOT_SUPPORTED,
        eUNIDENTIFIED_ERROR,
        eEMBEDDED_OUT_OF_SPACE,
        eERROR_COUNT
    } EError;

    enum KInfoRequest {
        eInfoExtension, // return a null terminated char const* const*
        eInfoDescriptions, // return a null terminated char const* const*
        eInfoVersions, // return a null terminated char const* const*
        eReserved1 = 0xFBFB,
    };

    typedef KFbxWriter*				(*CreateFuncType)(KFbxSdkManager& pManager, KFbxExporter& pExporter, int pSubID, int pPluginID);
    typedef void					(*IOSettingsFillerFuncType)(KFbxIOSettings& pIOS);
    typedef void*					(*GetInfoFuncType)(KInfoRequest pRequest, int pWriterTypeId);

    /** Creates a new file.
      * \param pFileName The name of the newly created file.
      */
    virtual bool					FileCreate(char* pFileName) = 0;
	//! Closes the file.
    virtual bool					FileClose() = 0;
	//! Judges if the file is open.
    virtual bool					IsFileOpen() = 0;
    //! Returns the write stream options.
    virtual KFbxStreamOptions*		GetWriteOptions() = 0;

	 /** Writes content to the specified file with given stream options
      *	\param pDocument        KFbxDocument to write file data to.
      * \param pStreamOptions   The given write stream options.
	  */
    virtual bool					Write(KFbxDocument* pDocument, KFbxStreamOptions* pStreamOptions) = 0;

	/** Pre-processes the scene.
      * \param pScene The scene needs to be pre-processed.
      */
    virtual bool					PreprocessScene(KFbxScene &pScene) = 0;

	/** Post-processes the scene.
      * \param pScene The scene needs to be post-processed.
      */
    virtual bool					PostprocessScene(KFbxScene &pScene) = 0;

	/** Finds the selected root node in the specified scene.
      * \param pScene The scene in which the selected root node is found.
	  *	\return The located root node.\c NULL if the selected root node cannot be found.
      */
    virtual KFbxNode*				FindRootNode(KFbxScene& pScene);

	/** Checks if there are spaces in the names of specified node (and its children nodes),
	  * and writes the returned node's name in the specified string list.
      * \param pNode Specifies the node to check.
	  * \param pNodeNameList Specifies the string list where the node name that has spaces in it is recorded.
	  *	\return \c true If there are no spaces in the name of specified node (and its children nodes), 
	  * \c false  If spaces are found.
      */
    virtual bool					CheckSpaceInNodeNameRecursive(KFbxNode* pNode, KString& pNodeNameList);

	/** Writes settings according the specified object's settings.
      * \param pParams The specified object.
      */
	virtual void					PluginWriteParameters(KFbxObject& pParams){}

	/** Sets the file export version as specified.
      * \param pVersion The specified file export version.
      */
    bool							SetFileExportVersion(KString pVersion);
 
	/** Sets the renaming mode as specified.
      * \param pRenamingMode The specified renaming mode.
      */
    void							SetRenamingMode(KFbxSceneRenamer::ERenamingMode pRenamingMode){mRenamingMode = pRenamingMode;}

	/** Sets the resampling rate as specified.
      * \param pResamplingRate The specified resampling rate.
      */
    inline void						SetResamplingRate(double pResamplingRate){mResamplingRate = pResamplingRate;}

	/** Judges if file format is an internal plug-in .
      *	\return \c true If the file format is an internal plug-in ,\c false Otherwise .
      */
	bool							IsGenuine();

	/** Returns error object(s).
      * \return References to the error object(s).
      */
    KError&							GetError();

	/** Returns the ID of the last error that occurred when the file was written.
      * \return The last error ID.
      */
    EError							GetLastErrorID() const;

	/** Returns the error string that describes the last error that occurred when the file was written.
      * \return A textual description of the last error.
      */
    const char*						GetLastErrorString() const;

	/** Returns a warning message that describes what occurred when the file was written.
      *	\param pMessage The returned warning message.
      */
    void							GetMessage(KString &pMessage) const;

	/** Returns a warning message that describes what occurred when the file was written.
      *	\return The returned warning message.
      */
    KString&						GetMessage();

	/** Empties the message string.
      */
    void							ClearMessage();

protected:
	void							PluginsWriteBegin(KFbxScene& pScene);
	void							PluginsWrite(KFbx& pFbx);
	void							PluginsWriteEnd(KFbxScene& pScene);

    KFbxWriter&						operator=(KFbxWriter const&) { return *this; }

    KFbxSdkManager& 				mManager;
    KString							mFileVersion;
    double							mResamplingRate;
    KFbxSceneRenamer::ERenamingMode	mRenamingMode;

private:
    KError							mError;
    KString         				mMessage;
	int								mInternalID;
};

#include <fbxfilesdk/fbxfilesdk_nsend.h>

#endif // FBXFILESDK_KFBXIO_KFBXWRITER_H

