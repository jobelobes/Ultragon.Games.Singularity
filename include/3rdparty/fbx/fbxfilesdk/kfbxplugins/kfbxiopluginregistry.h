/*!  \file kfbxiopluginregistry.h
 */

#ifndef FBXFILESDK_KFBXPLUGINS_KFBXIOPLUGINREGISTRY_H
#define FBXFILESDK_KFBXPLUGINS_KFBXIOPLUGINREGISTRY_H

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
#include <fbxfilesdk/components/kbaselib/kaydara.h>

#include <fbxfilesdk/kfbxio/kfbxreader.h>
#include <fbxfilesdk/kfbxio/kfbxwriter.h>

#include <fbxfilesdk/components/kbaselib/kbaselib_forward.h>

#include <fbxfilesdk/fbxfilesdk_nsbegin.h>

class KFbxSdkManager;
class KFbxIOPluginRegistry;
class KFbxExporter;
class KFbxImporter;
class KFbxIOSettings;

/**	\brief This class serves as the registrar for file formats.
  * A file format must be registered when it is used by the FBX SDK.
  *
  * This class also lets you create and read formats other than FBX SDK native formats
  */
class KFBX_DLL KFbxIOPluginRegistry
{
public:

    /** Constructor
      */
    KFbxIOPluginRegistry();

    /** Destructor
      */
	virtual ~KFbxIOPluginRegistry();

	/** Registers Reader from a plug-in path
	  *	\param pPluginPath          path of the plug-in
	  * \param pFirstPluginID       contains the ID of the first plug-in found
	  * \param pRegisteredCount     contains the number of registered Readers
	  */
	void RegisterReader(char const* pPluginPath,
						int& pFirstPluginID,
						int& pRegisteredCount);

	/** Registers Readers
	  *	\param pCreateF             Provide function information on file format
	  * \param pInfoF               Provide information about the file format
	  * \param pFirstPluginID       Contains the ID of the first plug-in found
	  * \param pRegisteredCount     Contains the number of registered Readers
	  * \param pIOSettingsFillerF
	  */
	void RegisterReader(KFbxReader::CreateFuncType pCreateF, 
						KFbxReader::GetInfoFuncType pInfoF,
						int& pFirstPluginID,
						int& pRegisteredCount,
						KFbxReader::IOSettingsFillerFuncType pIOSettingsFillerF = NULL
					   );


	/** Registers Writers from a plug-in path
	  *	\param pPluginPath          Path of the plug-in
	  * \param pFirstPluginID       Contains the ID of the first plug-in found
	  * \param pRegisteredCount     Contains the number of registered Writers
	  */
	void RegisterWriter(char const* pPluginPath,
						int& pFirstPluginID,
						int& pRegisteredCount);

	/** Registers Writers
	  *	\param pCreateF             Provide function information on file format
	  * \param pInfoF               Provide information about the file format 
	  * \param pFirstPluginID       Contains the ID of the first plug-in found
	  * \param pRegisteredCount     Contains the number of registered writers
	  * \param pIOSettingsFillerF
	  */
	void RegisterWriter(KFbxWriter::CreateFuncType pCreateF, 
						KFbxWriter::GetInfoFuncType pInfoF,
						int& pFirstPluginID,
						int& pRegisteredCount,
						KFbxWriter::IOSettingsFillerFuncType pIOSettingsFillerF = NULL);

	/** Creates a Reader in the Sdk Manager
	*	\param pManager      The Sdk Manager where the reader will be created
	  *	\param pImporter     Importer that will hold the created Reader
	  * \param pPluginID     Plug-in ID to create a Reader from
	  */
	KFbxReader* CreateReader(KFbxSdkManager& pManager, 
							 KFbxImporter& pImporter, 
							 int pPluginID) const;

	/** Creates a Writer in the Sdk Manager
	  * \param pManager      The Sdk Manager where the writer will be created
	  *	\param pExporter     Exporter that will hold the created Writer
	  * \param pPluginID     Plug-in ID to create a Writer from
	  */
	KFbxWriter* CreateWriter(KFbxSdkManager& pManager, 
							 KFbxExporter& pExporter,
							 int pPluginID) const;

	/** Search for the Reader ID by the extension of the file.
	  * \param pExt The file extension.
	  *	\return     The Reader ID if found, else returns -1
	  */
	int FindReaderIDByExtension(char const* pExt) const;

	/** Search for the Writer ID by the extension of the file.
	  * \param pExt The file extension.	  
	  *	\return     The Writer ID if found, else returns -1
	  */
	int FindWriterIDByExtension(char const* pExt) const;
	
	/** Search for the Reader ID by the description of the file format.
	  * \param pDesc The description of the file format.	  
	  *	\return     The Reader ID if found, else returns -1
	  */
	int FindReaderIDByDescription(char const* pDesc) const;

	/** Search for the Writer ID by the description of the file format.
	  * \param pDesc The description of the file format.	  
	  *	\return     The Writer ID if found, else returns -1
	  */
	int FindWriterIDByDescription(char const* pDesc) const;
	
	/** Verifies if the file format of the Reader is FBX.
	  * \param pFileFormat The file format.
	  *	\return     \c true if the file format of the Reader is FBX.
	  */
	bool ReaderIsFBX(int pFileFormat) const;

	/** Verifies if the file format of the Writer is FBX.
	  * \param pFileFormat The file format.
	  *	\return     \c true if the file format of the Writer is FBX.
	  */
	bool WriterIsFBX(int pFileFormat) const;

	/** Verifies if the file format of the Reader is genuine (internal).
      * \param pFileFormat The file format.
	  *	\return     \c true if the file format of the Reader is FBX.
	  */
	bool ReaderIsGenuine(int pFileFormat) const;

	/** Verifies if the file format of the Writer is genuine (internal).
      * \param pFileFormat The file format.
	  *	\return     \c true if the file format of the Writer is FBX.
	  */
	bool WriterIsGenuine(int pFileFormat) const;

	/** Get the number of importable file formats.
	  *	\return     Number of importable formats.
	  */
	int GetReaderFormatCount() const;

	/** Get the number of exportable file formats.
	  *	\return      Number of exportable formats.
	  * \remarks     Multiple identifiers for the same format are counted as 
	  *              file formats. For example, eFBX_BINARY, eFBX_ASCII and eFBX_ENCRYPTED
	  *              count as three file formats.
	  */
	int GetWriterFormatCount() const;

	/** Get the description of an importable file format.
	  *	\param pFileFormat     File format identifier.
	  *	\return                Pointer to the character representation of the description.
	  */
	char const* GetReaderFormatDescription(int pFileFormat) const;

	/** Get the description of an exportable file format.
	  *	\param pFileFormat     File format identifier.
	  *	\return                Pointer to the character representation of the description.
	  */
	char const* GetWriterFormatDescription(int pFileFormat) const;

	/** Get the file extension of an importable file format.
	  *	\param pFileFormat     File format identifier.
	  *	\return                Pointer to the character representation of the file extension.
	  */
	char const* GetReaderFormatExtension(int pFileFormat) const;
	
	/** Get the file extension of an exportable file format.
	  *	\param pFileFormat     File format identifier.
	  *	\return                Pointer to the character representation of the file extension.
	  */
	char const* GetWriterFormatExtension(int pFileFormat) const;

	/** Get a list of the writable file format versions.
	  *	\param pFileFormat     File format identifier.
	  *	\return                Pointer to a list of user-readable strings representing the versions.
	  */
	char const* const* GetWritableVersions(int pFileFormat) const;

	/** Detect the file format of the specified file.
	  * \param pFileName       The file to determine his file format.
	  * \param pFileFormat     The file format identifier if the function returns \c true. if the function returns \c false, unmodified otherwise.
	  * \return                Return \c true if the file has been determined successfully, 
	  *                        \c false otherwise.
	  * \remarks               This function attempts to detect the file format of pFileName based on the file extension and, 
	  *                        in some cases, its content. This function may not be able to determine all file formats.
	  *                        Use this function as a helper before calling \c SetFileFormat().
	  * \note                  The file must not be locked (already opened) for this function to succeed.
	  */
	bool DetectFileFormat(const char* pFileName, int& pFileFormat) const;
	
	/** Gets the native reader file format.
	  *	\return     The native reader file format ID.
	  */
	int GetNativeReaderFormat();

	/** Gets the native writer file format.
	  *	\return     The native writer file format ID.
	  */
	int GetNativeWriterFormat();

	/** Fills the IO Settings from all readers registered
	  *	\param pIOS			   The properties hierarchies to fill
	  */
	void FillIOSettingsForReadersRegistered(KFbxIOSettings & pIOS);

    /** Fills the IO Settings from all writers registered
	  *	\param pIOS			   The properties hierarchies to fill
	  */
	void FillIOSettingsForWritersRegistered(KFbxIOSettings & pIOS);


///////////////////////////////////////////////////////////////////////////////
//
//  WARNING!
//
//	Anything beyond these lines may not be documented accurately and is 
// 	subject to change without notice.
//
///////////////////////////////////////////////////////////////////////////////

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
	void RegisterInternalIOPlugins();

	struct ReaderPluginEntry
	{
		ReaderPluginEntry(char const* pExtension, char const* pDescription, KFbxReader::CreateFuncType pCreatorFunction, int pBaseID,
			KFbxReader::IOSettingsFillerFuncType pIOSettingsFillerFunction=NULL);
		
		char const*								mExtension;
		char const*								mDescription;
		KFbxReader::CreateFuncType				mCreatorFunction;
		KFbxReader::IOSettingsFillerFuncType	mIOSettingsFillerFunction;
		int										mBaseID;
		bool									mIsFBX;
		bool									mIsInternalPlugin;
	};
	
	struct WriterPluginEntry
	{
		WriterPluginEntry(char const* pExtension, char const* pDescription, char const* const* pVersions, KFbxWriter::CreateFuncType pCreatorFunction, int pBaseID,
			KFbxWriter::IOSettingsFillerFuncType pIOSettingsFillerFunction=NULL);
		
		char const*								mExtension;
		char const*								mDescription;
		char const* const*						mVersions;
		KFbxWriter::CreateFuncType				mCreatorFunction;
		KFbxWriter::IOSettingsFillerFuncType	mIOSettingsFillerFunction;
		int										mBaseID;
		bool									mIsFBX;
		bool									mIsInternalPlugin;
	};

	KArrayTemplate<ReaderPluginEntry*>	mReaders;
	KArrayTemplate<WriterPluginEntry*>	mWriters;
	int									mNativeReaderFormat;
	int									mNativeWriterFormat;
	bool								mInternalPluginMode;

#endif //DOXYGEN
};


#include <fbxfilesdk/fbxfilesdk_nsend.h>

#endif // FBXFILESDK_KFBXPLUGINS_KFBXIOPLUGINREGISTRY_H

