/*!  \file kfbxutilities.h
 */

#ifndef FBXFILESDK_KFBXPLUGINS_KFBXUTILITIES_H
#define FBXFILESDK_KFBXPLUGINS_KFBXUTILITIES_H

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

#include <fbxfilesdk/kfbxplugins/kfbxscene.h>

#include <fbxfilesdk/fbxfilesdk_nsbegin.h>

class KFbxTexture;

/** 
	* \name Scene cleaning
	*/
//@{

/** Clean bad meshes in the scene by removing bad polygons.
	* \param pScene     Pointer to the scene object.
	* \return           Array of nodes containing modified meshes.
	*/
KFBX_DLL KArrayTemplate<KFbxNode*> RemoveBadPolygonsFromMeshes(KFbxScene *pScene);
//@}


/** 
  * \name File utilities
  */
//@{

/** Get the content of a file from an hyper link
  * \param url The hyper link to the file. The URL must start with < http:// > ex: http://www.autodesk.com.
  * \return An allocated <char *buffer> containing the source text. You must use FBXFree_Internet_Buffer() to 
  * free the allocated memory.
  */
KFBX_DLL char* FBXGet_Internet_Source_File(const char *url);

/** Free the memory allocated by FBXGet_Internet_Source_File()
  * \param pBuf Pointer previously returned by a call to FBXGet_Internet_Source_File().
  */
KFBX_DLL void FBXFree_Internet_Buffer(char* pBuf);

/** Get the full path of given path (if the given path is relative path,
  * it will take current directory as default root path.)
  * \param pRelativePath  The relative path.
  * \return Full path
  */
KFBX_DLL KString KFbxFullPath(const char* pRelativePath);

/** Extract Directory from the given file path.
  * \param pFilePath The given file path.
  * \return The directory without file name.If there isn't any '\\' or '/' in  the given
  * file path, it will directly return the given file path.
  */
KFBX_DLL KString KFbxExtractDirectory(const char* pFilePath);

/** Extract file name from the given file path.
  * \param pFilePath The given file path.
  * \param pWithExtension Decide the file name with extension or without extension.
  * If it is true, return the file name with extension,if it is false, return the file name without extension.
  * \return The file name.
  */
KFBX_DLL KString KFbxExtractFileName(const char* pFilePath, bool pWithExtension=true);

/** Extract the given file's extension.
  * \param pFilePath The given file path.
  * \return The file extension.
  */
KFBX_DLL KString KFbxExtractFileExtension(const char* pFilePath);

/** This function is used to change the given file's extension with given new extension,
  * if the given file haven't extension,it will directly add the new extension at the end of given file.
  * The given new extension must add "." before the extension name.
  * \param pFilePath The old file path.
  * \param pNewExtension  The given new extension, it must add "." before the extension name
  * \return New file path with new extension name.
  */
KFBX_DLL KString KFbxChangeFileExtension(const char* pFilePath, const char* pNewExtension);

 /** Clean the redundant and useless denotations in given path name.
   * \param pFilePath The file path.
   * \return Cleaned path.
   */
KFBX_DLL KString KFbxCleanPath(const char* pFilePath);

/** Get the given new path's relative path to the given root path.
  * \param pRootPath  The root path.
  * \param pNewFilePath The given new path.
  * \return The relative path.
  */
KFBX_DLL KString KFbxGetRelativeFilePath(const char* pRootPath, const char* pNewFilePath);

/** Test if the given path is relative path, if it is return true.
  * \param pFilePath  The given file path.  
  * \return \c True if it is a relative path, \c false otherwise.
  */
KFBX_DLL bool KFbxIsRelativePath(const char* pFilePath);

/** Find if the given file exist.If the given file without directory,
  * it will find the file in the work directory.
  * \param pFilePath The given file path.
  * \return \c True if the file exists, \c false otherwise.
  */
KFBX_DLL bool KFbxFileExist(const char* pFilePath);

/** Test if the given directory exists, if the directory does not exist, it will create this directory.
  * \param pFilePath The given file path
  * \return \c True if the directory exists or is created successfully, \c False if the directory does not exist nor isn't created successfully.
  */
KFBX_DLL bool KFbxEnsureDirectoryExistance(const char* pFilePath);

/** Get the application directory
  * \return The application directory.  
  */
KFBX_DLL KString KFbxGetApplicationDirectory();

/** Get the full path
  * \param pRootPath The root path.
  * \param pFilePath The file path.
  */
KFBX_DLL KString KFbxMakeFullPath(const char* pRootPath, const char* pFilePath);

/** Get the current path
* \return The current directory.  
*/
KFBX_DLL KString KFbxGetCurrentDirectory();

/** Returns the amount of virtual memory available to the process; will take into account
  * swap file, and the process address space if there are such limits (ie: Win32 process
  * can access 2, 3 or 4gb depending on the OS they're running on, Win64 has a much
  * larger limit, limited possibly by the swap file)
  */
KFBX_DLL size_t KGetProcessVirtualMemoryAvailSize ();
//@}



class KFile;

/** \enum eFileMode File open mode.
* - \e KFBX_READ  
* - \e KFBX_WRITE 
* - \e KFBX_READWRITE
* - \e KFBX_APPEND
*/
enum eFileMode {KFBX_READ, KFBX_WRITE, KFBX_READWRITE, KFBX_APPEND};

/** \enum eSeekPos File seek mode.
* - \e KFBX_BEGIN  
* - \e KFBX_CURRENT 
* - \e KFBX_END
*/
enum eSeekPos {KFBX_BEGIN, KFBX_CURRENT, KFBX_END};

/** Utility class to manipulate file.
* \nosubgrouping */
class KFBX_DLL KFbxFile
{
public:
    //! Default constructor.
    KFbxFile();
    //! Destructor.
    virtual ~KFbxFile();

    /** Open file.
    * \param pFileName The file name.
    * \param pMode The file open mode.
    * \param pText The file is text or binary.
    * \return Open status.
    */
    bool			Open(const char* pFileName, eFileMode pMode, bool pText);

    /** Open file.
    * \param pFileName The file name.
    * \param pMode The file open mode.
    * \return Open status.
    */
    bool			Open(const char* pFileName, const char* pMode);

    //! Return the status that if the file is opened. 
    bool			IsOpened();

    //! Close the file. 
    void			Close();

    /** Read bytes.
    * \param pBuffer The buffer to store content read.
    * \param pSize Bytes count to read.
    * \return The bytes read.
    */
    size_t			Read(void* pBuffer, size_t pSize);

    /** Read string.
    * \param pBuffer
    * \param pMaxSize
    * \return The string. 
    */
    char*			ReadString(char* pBuffer, int pMaxSize);

    /** Read 32-bit integer.
    * \param pBuffer
    * \param pSwab
    * \return The integer read.
    */
    kInt32			ReadInt32(kInt32* pBuffer, bool pSwab=false);

    /** Read unsigned 32-bit integer.
    * \param pBuffer
    * \param pSwab
    * \return The integer read.
    */
    kUInt32			ReadUInt32(kUInt32* pBuffer, bool pSwab=false);

    /** Read 16-bit integer.
    * \param pBuffer
    * \param pSwab
    * \return The integer read.
    */
    kInt16			ReadInt16(kInt16* pBuffer, bool pSwab=false);
    /** Read unsigned 16-bit integer.
    * \param pBuffer
    * \param pSwab
    * \return The integer read.
    */
    kUInt16			ReadUInt16(kUInt16* pBuffer, bool pSwab=false);
    /** Read a char.
    * \param pBuffer
    * \return The char read.
    */
    char			ReadChar(char* pBuffer);
    /** Read unsigned char.
    * \param pBuffer
    * \return The char read.
    */
    kUChar			ReadUChar(kUChar* pBuffer);

    /** Write file.
    * \param pBuffer
    * \param pSize
    * \return The byte count written.
    */
    size_t			Write(const void* pBuffer, size_t pSize);

    /** Set the file pointer.
    * \param pSeekPosition 
    * \param pOffset 
    */
    void			Seek(eSeekPos pSeekPosition, long pOffset);
    //! Get file pointer's position.

    long			GetPosition();

    /** Set file pointer's position. 
      * \param pPosition
      */
    void			SetPosition(long pPosition);

    //! Return if reach the end of the file.
    bool			EndOfFile();

    //! Return full file name. 
    char*			GetFullFileName();

    //! Return the file mode.
    eFileMode		GetFileMode();

    //! Get last error.
    int				GetError();
    //! Clear error.
    void			ClearError();

    /** Print content according to format. 
      * \param pFormat
      * \param ... 
      */
    void			Format(const char* pFormat, ...);

    /** Truncate file to pSize.  
      * \param pSize
      * \return 
      */
    int				Truncate(size_t pSize);

    /** Remove file. 
      * \param pFileName
      * \return 
      */
    static int		Remove(const char* pFileName);

    /**  Rename file.
               * \param pFileName Current file to rename
               * \param pNewName New name of the file.
               * \return an error code or 0 if successful.
               */
    static int		Rename(const char* pFileName, const char* pNewName);

private:
	KFile*			mPrivateData;
};

#include <fbxfilesdk/fbxfilesdk_nsend.h>

#endif // FBXFILESDK_KFBXPLUGINS_KFBXUTILITIES_H

