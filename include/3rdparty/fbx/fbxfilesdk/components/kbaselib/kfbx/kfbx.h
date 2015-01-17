/*!  \file kfbx.h
 */

#ifndef FBXFILESDK_COMPONENTS_KBASELIB_KFBX_KFBX_H
#define FBXFILESDK_COMPONENTS_KBASELIB_KFBX_KFBX_H

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

#include <fbxfilesdk/components/kbaselib/kbaselib_h.h>

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include <fbxfilesdk/components/kbaselib/klib/kstring.h>
#include <fbxfilesdk/components/kbaselib/klib/ktime.h>
#include <fbxfilesdk/components/kbaselib/klib/kerror.h>
#include <fbxfilesdk/components/kbaselib/klib/karrayul.h>
#include <fbxfilesdk/components/kbaselib/klib/ksystemtime.h>
#include <fbxfilesdk/components/kbaselib/klib/kcharptrset.h>

#include <fbxfilesdk/fbxfilesdk_nsbegin.h>

class KFBX_DLL KFbxXRefManager;
class KFile;
class KFbxReader;
class KFbxWriter;

#include <fbxfilesdk/fbxfilesdk_nsend.h>

#include <fbxfilesdk/components/kbaselib/kbaselib_forward.h>
#include <fbxfilesdk/fbxfilesdk_nsbegin.h>

    // Defines the current version number.
    // Please keep this version journal updated.


    #define FBX_DEFAULT_VERSION_NUMBER 6100

    #define FBX7_DEFAULT_VERSION_NUMBER 7000


    // Defines the current version number.
    // Please keep this version journal updated.

    // Version 2000
    // New Bob KFCurve and embedded FBX.; no FCurve/FCurve node storing
    // No more .takf must has been created in an earlier version, no history
    // Ben's data is saved and retrieve

    // Version 2001
    // Version incremented to support KTime save in native (integer, not double!) format.

    // Version 3000
    // FiLMBOX 3.0 version, nothing changed in current class since version 2001.
    // FBX SDK 3.0 and 3.6
    // Ben's data is retrieve only to keep compatibility

    // Version 3001
    // FiLMBOX 3.0 encrypted version, only a trial.
    // Encrypted files could only be written in debug versions.

    // Gross big fat mistake! Cannot switch to a higher version number now because any
    // file with a version number >= 3001 is read as encrypted.
    // Hence, this value now only gives file type. (3000 or less -> binary, 3001 or more -> encrypted)

    // FiLMBOX 3.2, FiLMBOX 3.5 and Online 3.51 have been released with version 3000.

    // Version 4000
    // MotionBuilder 4.0, new type in KFCurve tangents, supported in FiLMBOX 3.5 but not by earlier versions.
    // Version number is now stored in section footer.
    // Before September 3rd 2002, the version number was always 3000 in main section footer.
    // Now the main section footer has version number 4000.
    // The minimum version number in footer of an extension section is 4000.

    // Version 4001
    // ASCII Header is 4.1 !!!!
    // MotionBuilder 4.01, to fix FCurveNode problem with layertypes in version 4000
    // Now the main section footer has version number 4001.
    // Now the footer for extension sections has version number 4001.

    // Version 4050
    // ASCII Header is 4.5 !!!!
    // MotionBuilder 4.1 or 4.5 (we dont know yet) before January 22nd 2003
    // This is because EvaluationProperties now have color.
    // Now the main section footer has version number 4050.
    // Now the footer for extension sections has version number 4050.

    // Version 5000
    // ASCII Header is not compatible anymore with MotionBuilder 4.0, 4.01 and 4.02 and FBX SDK 3.6 and 3.7
    // MotionBuilder 4.03 and 4.1 or 4.5 (we dont know yet) from January 22nd 2003
    // FBX SDK 3.6.1
    // New extended header to improve FBX file version management.
    // Now the extended header and the main section footer have version number 5000.
    // Now the footer for extension sections has version number 5000.

    // ************************************************************************************************
    // ************************************************************************************************
    // ***********************                                                    *********************
    // Version 5800
    // THIS IS A TEMPORARY VERSION WHILE WAITING FOR THE VERSION 6000 which will render the previous
    // versions incompatible with MotionBuilder 6.0. For now, however, this format is needed to allow
    // some tools/plugins (ex:maya) to correctly detect that the file has some features that are not
    // totally backward compatible (ex: pivots defined with _pre/_post nodes which require a special
    // processing). By incrementing only the minor version we do not compromise the integrity of the
    // files.
    // ***********************                                                    *********************
    // ************************************************************************************************
    // ************************************************************************************************

    // Version 6000
    // Header version is now 6.0
    // Extended header now contain a creation time stamp that can be retrieve without parsing the
    // main section of the file.
    // A creator tag (string) is now stored in the Extended header. This contain the originator (MB/FBXSDK)
    // of the file and the build number of the originator.
    // First release of the file format using the KProperties to store/retrieve information.


    // Version 6100
    // Add support for multiple attributes (mainly multiple geometry) at the node level.
    // The pointer to the node attribute have been replaced by a connection between the node and its attribute(s).

    // Version 7000
    // First version of the 7.0 series; most likely very short-lived, developped for Protein, before ADP.
    // Supports reference cloning, external documents, blobs, unique IDs (per file), property templates.
    // So many changes that it was decided to break from 6.0 to keep Motion Builder intact.

    enum
    {
        FBX_NO_SECTION = -1,
        FBX_MAIN_SECTION,
        FBX_EXTENSION_SECTION_0,
        // FBX_EXTENSION_SECTION_1,
        // FBX_EXTENSION_SECTION_2,
        // ...
    };

    /** Render and Resolution Info.
    * \nosubgrouping 
    */
    class KFBX_DLL KDefaultRenderResolution
    {
    public:
        /** If the resolution data is ready. */
        bool    mIsOK;
        /** camera name. */
        KString mCameraName;
        KString mResolutionMode;
        /** resolution width. */
        double mResolutionW;
        /** resolution height. */
        double mResolutionH;

        /**
        * \name Constructors and Destructor
        */
        //@{
        //! Default constructor.
        KDefaultRenderResolution();
        //@}

        /**
        * \name Member Access
        */
        //@{
        //! Reset.
        void Reset();
        //@}
    };

    /** FBX header info for head section.
    * \nosubgrouping */
    class KFBX_DLL KFbxFileHeaderInfo
    {
    public:
        /**
        * \name Constructors and Destructor
        */
        //@{
        //! Default constructor.
        KFbxFileHeaderInfo();

        //! Destructor.
        virtual ~KFbxFileHeaderInfo();
        //@}

        /**
        * \name Public Member
        */
        //@{
		virtual void				Reset();

        // Derived classes can get funky and read more info out of the header.
        // Return false in case of failure that should stop loading the file.
        virtual bool				ReadExtendedHeaderInformation(KFbx*);
        //@}

        KDefaultRenderResolution    mDefaultRenderResolution;

		//Read only properties (not used for file write)

		/** file version */
        int                         mFileVersion;

		/** creation time stamp preset flag */
        bool                        mCreationTimeStampPresent;

		/** creation time stamp */
        kLocalTime                  mCreationTimeStamp;

        /** file creator */
        KString                     mCreator;				

		/** IO Plugin flag */
		bool						mIOPlugin;


        bool                        mPLE;
    };

    /** FBX physical file I/O class.
    */
    class KFBX_DLL KFbx
    {
    public:
        // Exception-safe way of setting/resetting the xref manager in a KFbx object.
        struct KFbxAutoResetXRefManager
        {
            KFbx*                   mFbx;
            const KFbxXRefManager*  mXRefManager;

            KFbxAutoResetXRefManager(KFbx* pFbx, KFbxXRefManager& pXRefManager)
            : mFbx(pFbx)
            , mXRefManager(NULL)
            {
                if( mFbx )
                {
                    mXRefManager = mFbx->ProjectGetXRefManager();
                    mFbx->ProjectSetXRefManager(&pXRefManager);
                }
            }

            ~KFbxAutoResetXRefManager()
            {
                if( mFbx )
                {
                    mFbx->ProjectSetXRefManager(mXRefManager);
                }
            }
        };


        static KFbx* KFbxObjectCreate(){ return new KFbx; }

        KFbx();
        virtual ~KFbx();

        /**
        * \name Project Global
        */
        //@{

        /** Open a project already in Memory 
          * \param pAddress
          * \param pMaxLength
          * \param pReader
          * \param pCheckCRC
          * \param pOpenMainSection
          * \param pFileHeaderInfo
          * \return \c true on success, \c false otherwise.
          */
        bool ProjectOpen(void* pAddress, kULong pMaxLength, KFbxReader* pReader, bool pCheckCRC = false, bool pOpenMainSection = true, KFbxFileHeaderInfo* pFileHeaderInfo = NULL);

        /** Open a project. 
          * \param pName
          * \param pReader
          * \param pCheckCRC
          * \param pOpenMainSection
          * \param pFileHeaderInfo
          * \return \c true on success, \c false otherwise.
          */
        bool ProjectOpen(const char* pName, KFbxReader* pReader, bool pCheckCRC = false, bool pOpenMainSection = true, KFbxFileHeaderInfo* pFileHeaderInfo = NULL);

        /** Open a project on the specified KFile. The KFile object must exists until closed.
          * \param pFile
          * \param pReader
          * \param pCheckCRC
          * \param pOpenMainSection
          * \param pFileHeaderInfo
          * \return \c true on success, \c false otherwise.
          */
        bool ProjectOpen (KFile * pFile, KFbxReader* pReader, bool pCheckCRC = false, bool pOpenMainSection = true, KFbxFileHeaderInfo* pFileHeaderInfo = NULL);

        /** Open project file without necessarily an .fbx extension. 
          * \param pName
          * \param pReader
          * \param pCheckCRC
          * \param pOpenMainSection
          * \param pFileHeaderInfo
          * \return \c true on success, \c false otherwise.
          */
        bool ProjectOpenDirect(const char* pName, KFbxReader* pReader, bool pCheckCRC = false, bool pOpenMainSection = true, KFbxFileHeaderInfo* pFileHeaderInfo = NULL);

        /** Create a project in Memory 
          * \param pAddress
          * \param pSize
          * \param pWriter
          * \param pBinary
          * \param pEncrypted
          * \param pFileHeaderInfo
          * \return \c true on success, \c false otherwise.
          */
        bool ProjectCreate(void* pAddress, kUInt pSize, KFbxWriter* pWriter, bool pBinary, bool pEncrypted, KFbxFileHeaderInfo* pFileHeaderInfo = NULL);

        /** Create a project. 
          * \param pName
          * \param pWriter
          * \param pBinary
          * \param pEncrypted
          * \param pFileHeaderInfo
          * \return \c true on success, \c false otherwise.
          */
        bool ProjectCreate(const char* pName, KFbxWriter* pWriter, bool pBinary, bool pEncrypted, KFbxFileHeaderInfo* pFileHeaderInfo = NULL);

        /** Create a project without necessary an .fbx extension.
          * \param pName
          * \param pWriter
          * \param pBinary
          * \param pEncrypted
          * \param pFileHeaderInfo
          * \return \c true on success, \c false otherwise.
          */
        bool ProjectCreateDirect(const char* pName, KFbxWriter* pWriter, bool pBinary, bool pEncrypted, KFbxFileHeaderInfo* pFileHeaderInfo = NULL);

        /** Create a project, without writing out the header (yet)
          * \param pName
          * \param pWriter
          * \param pVersion
          * \param pBinary
          * \param pEncrypted
          * \return \c true on success, \c false otherwise.
          */
        bool ProjectCreateEmpty(const char* pName, KFbxWriter* pWriter, int pVersion, bool pBinary, bool pEncrypted);

        /** Write FBX signature at the top of the file, prepare file for writing header information 
          * \return \c true on success, \c false otherwise.
          */
        bool ProjectWrite_BeginFileHeader();

        /** Open up the 'extended header' 
          * \return \c true on success, \c false otherwise.
          */
        bool ProjectWrite_BeginExtendedHeader();

        /** Write the contents of the extended header 
          * \param pExtendedHeader
          * \return \c true on success, \c false otherwise.
          */
        bool ProjectWrite_WriteExtendedHeader(const KFbxFileHeaderInfo* pExtendedHeader);

        /** Close the extended header 
          * \return \c true on success, \c false otherwise.
          */
        bool ProjectWrite_EndExtendedHeader();

        /** Close up the header, prepare file for payload write. 
          * \return \c true on success, \c false otherwise.
          */
        bool ProjectWrite_EndFileHeader();

        /** Close the project. 
          * \param pData
          * \param pSize
          * \return \c true on success, \c false otherwise.
          */
        bool ProjectClose(void** pData=0,kULong *pSize=0);

        /** Provide the XRef Manager to use to create the .fbm folder. 
         * \remarks If NULL is used, the old behavior (using the .fbx's folder) is used instead. 
         */
        void ProjectSetXRefManager(const KFbxXRefManager*);

        /** Get the XRef Manager to use. 
         * \return NULL if no XRef manager has been set. 
         */
        const KFbxXRefManager* ProjectGetXRefManager() const;

        /** Select (and create) a folder to store embedded files (the .fbm 
        *   file folder).  Takes into account the settings from the XRef Manager.
          * \param pXRefManager
          * \param pCreatedFolder
          * \return \c true on success, \c false otherwise.
          * \remarks If this already been called successfully, uses the path
        *   previously created.
        *  
        *   Client application is responsible for cleaning up this folder.
        *  
        *   This will be automatically called if ProjectSetXRefManager()
        *   has been called before the .fbm folder needs to be created. 
        */ 
        bool ProjectCreateEmbeddedFolder(const KFbxXRefManager& pXRefManager, KString& pCreatedFolder); 

        /** On store event, use this function to tell if we are embedding. 
          * \param pValue
          */
        void SetEmbedded(bool pValue);

        /** Check if file is embedded or not. 
          * \return \c true if file is embedded, false otherwise.
          */
        bool IsEmbedded() const;

        /** Check if file is binary or ASCII 
          * \return \c true if file is binary, false otherwise.
          */
        bool IsBinary() const;

        /** Return if binary file is encrypted 
          * \return \c true if file is encrypted, false otherwise.
          */
        bool IsEncrypted () const;

        /** Check CRC code. File must be open, binary and encrypted.
        *   \return \c true if CRC code is valid or file is not open, binary and encrypted.
        */
        bool CheckCRC();

        /** Return the file version number 
          * \return the file version number
          */
        kUInt32 GetFileVersionNumber() const; 

        //@}

        /**
          * \name FBX 7 Format specific.

           This is only used for FBX7 files; should we compress arrays if possible?
           The writer may decide not to compress all arrays, or it may even decide
           not to compress anyway.  Flags are written in the file to help the reader
           out, on a per-array basis.
          */
        //@{

        //! \return Current state of the flag.
        bool Fbx7Support() const;

        /** Set the flag state to tell the parser to handle FBX7 files.
          * \param pSupport New flag state.
          */
        void Fbx7Support(bool pSupport);

        //! \return Current State of the flag.
        bool CompressArrays() const;

        /** Set the flag state. 
          * \param pCompress New flag state.
          */
        void CompressArrays(bool pCompress);

        //! \return Current compression minimum size.
        int  CompressMinimumSize() const;

        /** Set the compression minimum size.
          * \param pSize Threshold at wich compression may embark.
          */
        void CompressMinimumSize(int pSize);

        //! \return Current compression level.
        int  CompressLevel() const;

        /** Set the compression level.
          * \param pLevel Value of the desired compression.
          * \remarks The allowed range for pLevel is [0-9] where 0 equals no compression and
          * 9 is as-much-as-we-can.
          */
        void CompressLevel(int pLevel);
        //@}

        /**
        * \name Project Section
        */
        //@{

        /** Open the main section of a project. 
          * \return \c true on success, \c false otherwise.
          */
        bool ProjectOpenMainSection();

        /** Get the number of extension sections of a project.
          * \return the number of extension sections of a project.
          */
        int ProjectGetExtensionSectionCount();

        /** Open an extension section of a project. 
          * \param pExtensionSectionIndex
          * \return \c true on success, \c false otherwise.
          */
        bool ProjectOpenExtensionSection(int pExtensionSectionIndex);

        /** Create an extension section in a project, not allowed in ASCII and encrypted modes.
          * \param pOverwriteLastExtensionSection
          * \return \c true on success, \c false otherwise.
          */
        bool ProjectCreateExtensionSection(bool pOverwriteLastExtensionSection = false);

        /** Close current section. 
          */
        void ProjectCloseSection();

        /** Remove last extension section used. 
          * \return \c true on success, \c false otherwise.
          */
        bool ProjectRemoveLastExtensionSection();

        /** Get current section. 
          * \return the current section.
          */
        int ProjectGetCurrentSection();

        /** Get current section mode. 
          * \return the current section mode. 
          */
        int ProjectGetCurrentSectionMode();

        /** Get current section version. 
          * \return the current section version. 
          */
        int ProjectGetCurrentSectionVersion();

        /** Get the version number of a section.
        * \param pSection
        * \return the version number of a section.
        * \remarks For main section it can be either 1000, 2000, 2001, 3000, 3001, 4000, 4001 or 4050.
        *  For the extension section it can be either 4000, 4001 or 4050.
        *  Returns 0 if section number does not exist.
        */
        int ProjectGetSectionVersion(int pSection);

        /** Split a version number into major, minor and revision numbers.
        * \param pVersion Version number to split.
        * \param pMajor Integer to receive major version number.
        * \param pMinor Integer to receive minor version number.
        * \param pRevision Integer to receive revision version number.
        */
        static void ProjectConvertVersionNumber(int pVersion, int& pMajor, int& pMinor, int& pRevision);

        /** Check the password protection flag.
        * \return \c true if the current section has a password, \c false otherwise.
        */
        bool IsPasswordProtected() const;

        /** Set password protection flag to \c false if the argument matches the password stored in the section.
        * \param pPassword
        * \return \c true if the argument matches the password stored in the section, \c false otherwise.
        * \remarks This function only works in read mode.
        */
        bool CheckPassword(const char* pPassword);

        /** Encrypt and store password in a section.
        * \param pPassword
        * \return \c true on success, \c false otherwise.
        * \remarks This function only works in write mode and out of any enclosing block.
        * \remarks This function must not be called more than once per section.
        */
        bool WritePassword(const char* pPassword);

        //@}

        /**
        * \name Directory
        */
        //@{

        /** Get project file name. 
          * \return project file name.
          */
        const char* GetFilename() const;

        /** Get project data directory name. 
          * \param pAutoCreate
          * \return project data directory name.
          */
        KString GetDataDirectory(bool pAutoCreate = true);

        /** Get the current embedded folder used by this object.  
          * \param pCreate
          * \return the current embedded folder used by this object.
          * \remarks If ProjectCreateEmbeddedFolder has never been called this will
          *  return an empty string, unless we're explicitly asked to
         *  create it.
         */
        KString GetMediaDirectory(bool pCreate = false);

        /** Get the full path of the directory to extract the template file. 
          * \param pTemplateName
          * \param pCreate
          * \return the full path of the directory to extract the template file.
          */
        KString GetContainerTemplateDirectory(const char* pTemplateName, bool pCreate);

        /** Get the path relative to project directory. 
          * \param pPath
          * \return the path relative to project directory.
          */
        char* GetRelativePath(const char* pPath);

        /** Get the file path relative to project directory. 
          * \param pFilePath
          * \return the file path relative to project directory.
          */
        char* GetRelativeFilePath(const char* pFilePath);

        /** Get the full path of path relative to project directory. 
          * \param pRelativePath
          * \return the full path of path relative to project directory.
          */
        char* GetFullPath(const char* pRelativePath);

        /** Get the full file path of path relative to project directory. 
          * \param pRelativeFilePath
          * \return the full file path of path relative to project directory.
          */
        char* GetFullFilePath(const char* pRelativeFilePath);

        /** Get the temporary project name. 
          * \param pName
          * \return the temporary project name.
          */
        char* GetTmpProjectName(const char* pName);

        /** Swap from temporary project. 
          * \param pName
          * \param pError
          * \return \c true on success, \c false otherwise.
          */
        bool SwapFromTmpProject(const char* pName, char* pError=NULL);

        //@}

        /**
        * \name Read
        */
        //@{

        /** Reset the field read position. 
          */
        void FieldReadResetPosition();

        /** Get the number of fields. 
          * \return the number of fields.
          */
        int FieldGetCount();

        /** Get the name of field indexed pFieldIndex. 
          * \param pFieldIndex
          * \return the name of field indexed pFieldIndex.
          */
        const char* FieldGetName(int pFieldIndex);

        /** Get number of instance field pFieldName has. 
          * \param pFieldName
          * \return the number of instance field pFieldName has.
          */
        int FieldGetInstanceCount(const char* pFieldName);

        /** Start to read field instance referred by field indexed pFieldIndex, instance indexed pInstance. 
          * \param pFieldIndex
          * \param pInstance
          * \return \c true on success, \c false otherwise.
          */
        bool FieldReadBegin(int pFieldIndex, int pInstance);

        /** Start to read field pFieldName. 
          * \param pFieldName
          * \return \c true on success, \c false otherwise.
          */
        bool FieldReadBegin(const char* pFieldName);

        /** Start to read field instance referred field pFieldName, instance indexed pInstance. 
          * \param pFieldName
          * \param pInstance
          * \return \c true on success, \c false otherwise.
          */
        bool FieldReadBegin(const char* pFieldName, int pInstance);

        //! Stop to read the current field.
        void FieldReadEnd();

        //! Return if current field is a block.
        bool FieldReadIsBlock();

        //! Start to read a field block.
        bool FieldReadBlockBegin();

        //! Stop to read a field block.
        void FieldReadBlockEnd();

        //! Return the number of read field.
        int FieldReadGetCount();

        //! Return the number of field remaining to be read.
        int FieldReadGetRemain();

        //! Return current field value type.
        char FieldReadGetType();

        //! Return current field value as a char.
        char FieldReadCH();

        /** Return field pFieldName's value as a char. 
          * \param pFieldName
          * \param pDefault
          */
        char FieldReadCH(const char* pFieldName, char pDefault=0);

        //! Return current field value as a char pointer.
        const char* FieldReadC();

        /** Return field pFieldName's value as a char pointer. 
          * \param pFieldName
          * \param pDefault
          */
        const char* FieldReadC(const char* pFieldName, const char* pDefault="");

        //! Return current field value as a string (a char pointer).
        const char* FieldReadS();

        /** Return field pFieldName's value as a char pointer. 
          * \param pFieldName
          * \param pDefault
          */
        const char* FieldReadS(const char* pFieldName, const char* pDefault="");

        //! Return current field value as an bool.
        bool FieldReadB();

        /** Return field pFieldName's value as an integer. 
          * \param pFieldName
          * \param pDefault
          */
        bool FieldReadB(const char* pFieldName, bool pDefault = false);

        //! Return current field value as an integer.
        int FieldReadI();

        /** Return field pFieldName's value as an integer. 
          * \param pFieldName
          * \param pDefault
          */int FieldReadI(const char* pFieldName, int pDefault=0);

        //! Return current field value as an integer.
        kLongLong FieldReadLL();

        /** Return field pFieldName's value as an integer. 
          * \param pFieldName
          * \param pDefault
          */
        kLongLong FieldReadLL(const char* pFieldName, kLongLong pDefault=0);

        //! Return current field value as a float.
        float FieldReadF();

        /** Return field pFieldName's value as a float. 
          * \param pFieldName
          * \param pDefault
          */
        float FieldReadF(const char* pFieldName, float pDefault=0);

        //! Return current field value as a double.
        double FieldReadD();

        /** Return field pFieldName's value as a double. 
          * \param pFieldName
          * \param pDefault
          */
        double FieldReadD(const char* pFieldName, double pDefault=0);

        /** Return field pFieldName's value as a time value. 
          * \param pFieldName
          */
        KTime FieldReadT(const char* pFieldName);

        //! Return field pFieldName's value as a time value.
        KTime FieldReadT();

        /** Return field pFieldName's value as a timespan value. 
          * \param pFieldName
          */
        KTimeSpan FieldReadTS(const char* pFieldName);

        //! Return field pFieldName's value as a timespan value.
        KTimeSpan FieldReadTS();

        /** Return current field value as a n floats array. 
          * \param pValue
          * \param pn
          */
        void FieldReadFn(float* pValue, kUInt pn);

        /** Return current field value as a 3 floats array. 
          * \param pValue
          */
        void FieldRead3F(float* pValue);

        /** Return current field value as a 4 floats array. 
          * \param pValue
          */
        void FieldRead4F(float* pValue);

        /** Return field pFieldName's value as n floats array. 
          * \param pFieldName
          * \param pValue
          * \param pDefault
          * \param pn
          */
        void FieldReadFn(const char* pFieldName, float* pValue, const float *pDefault, kUInt pn);

        /** Return field pFieldName's value as 4 floats array. 
          * \param pFieldName
          * \param pValue
          * \param pDefault
          */
        void FieldRead3F(const char* pFieldName, float* pValue, const float* pDefault=NULL);

        /** Return field pFieldName's value as 3 floats array. 
          * \param pFieldName
          * \param pValue
          * \param pDefault
          */
        void FieldRead4F(const char* pFieldName, float* pValue, const float* pDefault=NULL);

        /** Return current field value as a n doubles array. 
          * \param pValue
          * \param pn
          */
        void FieldReadDn(double* pValue, kUInt pn);

        /** Return current field value as a 3 doubles array. 
          * \param pValue
          */
        void FieldRead3D(double* pValue);

        /** Return current field value as a 4 doubles array. 
          * \param pValue
          */
        void FieldRead4D(double* pValue);

        /** Return field pFieldName's value as n doubles array. 
          * \param pFieldName
          * \param pValue
          * \param pDefault
          * \param pn
          */
        void FieldReadDn(const char* pFieldName, double* pValue, const double *pDefault, kUInt pn);

        /** Return field pFieldName's value as 4 doubles array. 
          * \param pFieldName
          * \param pValue
          * \param pDefault
          */
        void FieldRead3D(const char* pFieldName, double* pValue, const double* pDefault=NULL);

        /** Return field pFieldName's value as 3 doubles array. 
          * \param pFieldName
          * \param pValue
          * \param pDefault
          */
        void FieldRead4D(const char* pFieldName, double* pValue, const double* pDefault=NULL);

        /** Return current field value as raw data. 
          * \param pByteSize
          */
        void* FieldReadR(int* pByteSize);

        /** Return field pFieldName's value as raw data. 
          * \param pFieldName
          * \param pByteSize
          */
        void* FieldReadR(const char* pFieldName,int* pByteSize);

		/**
		  * \name FBX SDK 2009.3 and later
		  */
		//@{
        //! Return field pFieldName's value as byte.
        kByte FieldReadByte();

        /** Return field pFieldName's value as a byte value. 
          * \param pFieldName
          * \param pDefault
          */
        kByte FieldReadByte(const char* pFieldName, kByte pDefault=0);

        //! Return field pFieldName's value as unsigned byte.
        kUByte FieldReadUByte();

        /** Return field pFieldName's value as an unsigned byte value. 
          * \param pFieldName
          * \param pDefault
          */
        kUByte FieldReadUByte(const char* pFieldName, kUByte pDefault=0);

        //! Return field pFieldName's value as short.
        kShort FieldReadShort();

        /** Return field pFieldName's value as a short value. 
          * \param pFieldName
          * \param pDefault
          */
        kShort FieldReadShort(const char* pFieldName, kShort pDefault=0);

        //! Return field pFieldName's value as unsigned short.
        kUShort FieldReadUShort();

        /** Return field pFieldName's value as an unsigned short value. 
          * \param pFieldName
          * \param pDefault
          */
        kUShort FieldReadUShort(const char* pFieldName, kUShort pDefault=0);

		//! Return field pFieldName's value as unsigned integer.
        unsigned int FieldReadUI();
		
        /** Return field pFieldName's value as an unsigned int as a value. 
          * \param pFieldName
          * \param pDefault
          */
        unsigned int FieldReadUI(const char* pFieldName, unsigned int pDefault=0);

        //! Return field pFieldName's value as 64 bit unsigned integer.
        kULongLong FieldReadULL();

        /** Return field pFieldName's value as an 64 bit unsigned int as a value. 
          * \param pFieldName
          * \param pDefault
          */
        kULongLong FieldReadULL(const char* pFieldName, kULongLong pDefault=0);

        /** Read the whole array and return the pointer to it.
          * \param pCount Nb of items in the array.
          */
		const kByte*		FieldReadArraySBytes( int &pCount );
        /** Read the whole array and return the pointer to it.
          * \param pCount Nb of items in the array.
          */
		const kShort*		FieldReadArrayShort	( int &pCount );
        /** Read the whole array and return the pointer to it.
          * \param pCount Nb of items in the array.
          */
		const kUShort*		FieldReadArrayUShort( int &pCount );
        /** Read the whole array and return the pointer to it.
          * \param pCount Nb of items in the array.
          */
		const unsigned int*	FieldReadArrayUI	( int &pCount );
        /** Read the whole array and return the pointer to it.
          * \param pCount Nb of items in the array.
          */
		const kULongLong*	FieldReadArrayULL	( int &pCount );

        /** Read the whole array and return the pointer to it.
          * \param pCount Nb of items in the array.
          */
		const kByte*        FieldReadArray(int &pCount, const kByte*);
        /** Read the whole array and return the pointer to it.
          * \param pCount Nb of items in the array.
          */
        /** Read the whole array and return the pointer to it.
          * \param pCount Nb of items in the array.
          */
		const kShort*		FieldReadArray(int &pCount, const kShort*);
        /** Read the whole array and return the pointer to it.
          * \param pCount Nb of items in the array.
          */
		const kUShort*		FieldReadArray(int &pCount, const kUShort*);
        /** Read the whole array and return the pointer to it.
          * \param pCount Nb of items in the array.
          */
		const unsigned int* FieldReadArray(int &pCount, const unsigned int*);
        /** Read the whole array and return the pointer to it.
          * \param pCount Nb of items in the array.
          */
		const kULongLong*	FieldReadArray(int &pCount, const kULongLong*);
		//@}

        /** Read field and copy it into a file.
        * \param pFileName Embedded file full path+name.
        *\param pRelativeFileName Relative path+name of the embedded file.
        * \param pEmbeddedMediaDirectory Directory of the embedded media.
        * \param pIsFileCreated Status of the extraction of the embedded data. Set to \c true if the embedded media is correctly extracted in the media directory.
        * \remarks Only works when file is binary. This function is not related to flag mEmbedded.
        * \return \c false if operation failed.
        */
        virtual bool FieldReadEmbeddedFile (KString& pFileName, KString& pRelativeFileName, const char* pEmbeddedMediaDirectory = "", bool *pIsFileCreated=NULL);

        /** Read the whole array and return the pointer to it.
          * \param pCount Nb of items in the array.
          */
        const double*   FieldReadArrayD( int &pCount );
        /** Read the whole array and return the pointer to it.
          * \param pCount Nb of items in the array.
          */
        const float*    FieldReadArrayF( int &pCount );
        /** Read the whole array and return the pointer to it.
          * \param pCount Nb of items in the array.
          */
        const int*      FieldReadArrayI( int &pCount );
        /** Read the whole array and return the pointer to it.
          * \param pCount Nb of items in the array.
          */
        const kLongLong*FieldReadArrayLL(int &pCount );
        /** Read the whole array and return the pointer to it.
          * \param pCount Nb of items in the array.
          */
        const bool*     FieldReadArrayB( int &pCount );
        /** Read the whole array and return the pointer to it.
          * \param pCount Nb of items in the array.
          */
        const kUByte*   FieldReadArrayBytes( int &pCount );

        /** Read the whole array and return the pointer to it.
          * \param pCount Nb of items in the array.
          */
        const int*    FieldReadArray(int& pCount, const int*);
        /** Read the whole array and return the pointer to it.
          * \param pCount Nb of items in the array.
          */
        const float*  FieldReadArray(int& pCount, const float*);
        /** Read the whole array and return the pointer to it.
          * \param pCount Nb of items in the array.
          */
        const double* FieldReadArray(int& pCount, const double*);
        /** Read the whole array and return the pointer to it.
          * \param pCount Nb of items in the array.
          */
        const kLongLong* FieldReadArray(int& pCount, const kLongLong*);
        /** Read the whole array and return the pointer to it.
          * \param pCount Nb of items in the array.
          */
        const bool* FieldReadArray(int& pCount, const bool*);
        /** Read the whole array and return the pointer to it.
          * \param pCount Nb of items in the array.
          */
        const kUByte* FieldReadArray(int& pCount, const kUByte*);

        //@}

        /**
        * \name Write
        */
        //@{

        /** Start to write a field called pFieldName. 
          * \param pFieldName
          */
        void FieldWriteBegin(const char* pFieldName);

        //! Stop to write the current field.
        void FieldWriteEnd();

        //! Start to write a field block.
        void FieldWriteBlockBegin();

        /** Start to write an object reference field. 
          * \param pObjectType
          * \param pName
          * \param pSubType
          */
        void FieldWriteObjectBegin(const char* pObjectType, const char* pName, const char* pSubType=NULL);

        //! Stop to write an object reference field.
        void FieldWriteObjectEnd();

        /** Start to write a field block in file pFileName.
          * \param pFileName
          * \remarks This function is disabled but kept accessible for the FBX SDK.
        */
        void FieldWriteBlockBegin(const char* pFileName);

        //! Stop to write a block of field.
        void FieldWriteBlockEnd ();

        /** Write field value as a char. 
          * \param pValue
          */
        void FieldWriteCH(char pValue);

        /** Write field pFieldName field with a char as a value. 
          * \param pFieldName
          * \param pValue
          */
        void FieldWriteCH(const char* pFieldName, char pValue);

        /** Write field value as char pointer pValue. 
          * \param pValue
          */
        void FieldWriteC(const char* pValue);

        /** Write field pFieldName with a char pointer as a value. 
          * \param pFieldName
          * \param pValue
          */
        void FieldWriteC(const char* pFieldName, const char* pValue);

        /** Write field value as KString pValue. 
          * \param pValue
          */
        void FieldWriteS(const char* pValue);

        /** Write field value as KString pValue. 
          * \param pValue
          */
        void FieldWriteS(const KString& pValue);

        /** Write field pFieldName field with a KString as a value. 
          * \param pFieldName
          * \param pValue
          */
        void FieldWriteS(const char* pFieldName, const char* pValue);

        /** Write field pFieldName field with a KString as a value. 
          * \param pFieldName
          * \param pValue
          */
        void FieldWriteS(const char* pFieldName, const KString& pValue);

        /** Write field value as bool. 
          * \param pValue
          */
        void FieldWriteB(bool pValue);

        /** Write field pFieldName field with a bool value. 
          * \param pFieldName
          * \param pValue
          */
        void FieldWriteB(const char* pFieldName, bool pValue);

        /** Write field value as integer. 
          * \param pValue
          */
        void FieldWriteI(int pValue);

        /** Write field pFieldName field with an int as a value. 
          * \param pFieldName
          * \param pValue
          */
        void FieldWriteI(const char* pFieldName, int pValue);

        /** Write field value as 64 bit integer. 
          * \param pValue
          */
        void FieldWriteLL(kLongLong pValue);

        /** Write field pFieldName field with an 64 bit int as a value.
                         * \param pFieldName 
                         * \param pValue
                         */
        void FieldWriteLL(const char* pFieldName, kLongLong pValue);

        /** Write field value as float.
        * \param pValue
        * \remarks Only compatible with 1) MotionBuilder 4.0 and later 2) FBX SDK 3.6.1 and later.
        */
        void FieldWriteF(float pValue);

        /** Write field pFieldName field with a float as a value.
        * \param pFieldName
        * \param pValue
        * \remarks Only compatible with 1) MotionBuilder 4.0 and later 2) FBX SDK 3.6.1 and later.
        */
        void FieldWriteF(const char* pFieldName, float pValue);

        /** Write field value as double. 
          * \param pValue
          */
        void FieldWriteD(double  pValue);

        /** Write field pFieldName field with a double as a value. 
          * \param pFieldName
          * \param pValue
          */
        void FieldWriteD(const char* pFieldName, double pValue);

        /** Write field value as time value. 
          * \param pTime
          */
        void FieldWriteT(KTime pTime);

        /** Write field pFieldName field with a time as a value. 
          * \param pFieldName
          * \param pValue
          */
        void FieldWriteT(const char* pFieldName,KTime pValue);

        /** Write field value as timespan value. 
          * \param pTimeSpan
          */
        void FieldWriteTS(KTimeSpan pTimeSpan);

        /** Write field pFieldName field with a timespan as a value. 
          * \param pFieldName
          * \param pValue
          */
        void FieldWriteTS(const char* pFieldName,KTimeSpan pValue);

        /** Write field value as an array of n floats (nF vector). 
          * \param pValue
          * \param pn
          */
        void FieldWriteFn(const float* pValue, kUInt pn);

        /** Write field pFieldName field with a array of n floats as a value. 
          * \param pFieldName
          * \param pValue
          * \param pn
          */
        void FieldWriteFn(const char* pFieldName, const float* pValue, kUInt pn);

        /** Write field value as an array of 3 floats (3F vector). 
          * \param pValue
          */
        void FieldWrite3F(const float* pValue);

        /** Write field pFieldName field with a array of 3 floats as a value. 
          * \param pFieldName
          * \param pValue
          */
        void FieldWrite3F(const char* pFieldName, const float* pValue);

        /** Write field value as an array of 4 floats (4F vector). 
          * \param pValue
          */
        void FieldWrite4F(const float* pValue);

        /** Write field pFieldName field with a array of 4 floats as a value. 
          * \param pFieldName
          * \param pValue
          */
        void FieldWrite4F(const char* pFieldName, const float* pValue);

        /** Write field value as an array of n doubles (nD vector). 
          * \param pValue
          * \param pn
          */
        void FieldWriteDn(const double* pValue, kUInt pn);

        /** Write field pFieldName field with a array of n doubles as a value. 
          * \param pFieldName
          * \param pValue
          * \param pn
          */
        void FieldWriteDn(const char* pFieldName, const double* pValue, kUInt pn);

        /** Write field value as an array of 3 doubles (3D vector). 
          * \param pValue
          */
        void FieldWrite3D(const double* pValue);

        /** Write field pFieldName field with a array of 3 doubles as a value. 
          * \param pFieldName
          * \param pValue
          */
        void FieldWrite3D(const char* pFieldName, const double* pValue);

        /** Write field value as an array of 4 doubles (4D vector). 
          * \param pValue
          */
        void FieldWrite4D(const double* pValue);

        /** Write field pFieldName field with a array of 4 doubles as a value. 
          * \param pFieldName
          * \param pValue
          */
        void FieldWrite4D(const char* pFieldName, const double* pValue);

        // The maximum number of value entries is, in theory, 2**32.  In practice it should be a lot less than that.
        // pSize is the number of values to write from each pointer location, and stride is how much we 
        // advance to get to the next value; if the stride is zero, values are tighly packed together.
        // So in total we'll write n * pSize items.

        /** Write array to file.
          * \param n Nb of items in the array.
          * \param pValue Pointer to the data.
          * \param pSize Size of each item in the array.
          * \param pStride Array stride.
          */
        void FieldWriteArrayD( int n, const double*     pValue, int pSize = 1, int pStride = 0 );
        /** Write array to file.
          * \param n Nb of items in the array.
          * \param pValue Pointer to the data.
          * \param pSize Size of each item in the array.
          * \param pStride Array stride.
          */
        void FieldWriteArrayF( int n, const float*      pValue, int pSize = 1, int pStride = 0 );
        /** Write array to file.
          * \param n Nb of items in the array.
          * \param pValue Pointer to the data.
          * \param pSize Size of each item in the array.
          * \param pStride Array stride.
          */
        void FieldWriteArrayI( int n, const int*        pValue, int pSize = 1, int pStride = 0 );
        /** Write array to file.
          * \param n Nb of items in the array.
          * \param pValue Pointer to the data.
          * \param pSize Size of each item in the array.
          * \param pStride Array stride.
          */
        void FieldWriteArrayLL(int n, const kLongLong*  pValue, int pSize = 1, int pStride = 0 );
        /** Write array to file.
          * \param n Nb of items in the array.
          * \param pValue Pointer to the data.
          * \param pSize Size of each item in the array.
          * \param pStride Array stride.
          */
        void FieldWriteArrayB( int n, const bool*       pValue, int pSize = 1, int pStride = 0 );
        /** Write array to file.
          * \param n Nb of items in the array.
          * \param pValue Pointer to the data.
          * \param pSize Size of each item in the array.
          * \param pStride Array stride.
          */
        void FieldWriteArrayBytes( int n, const kUByte* pValue, int pSize = 1, int pStride = 0 );

        /** Write field value as a raw data.
          * \param pRawData
          * \param pByteSize
        */
        void FieldWriteR(const void* pRawData, int pByteSize);

        /** Write field pFieldName field with raw data as a value.
          * \param pFieldName
          * \param pRawData
          * \param pByteSize
        */
        void FieldWriteR(const char* pFieldName, const void* pRawData, int pByteSize);

		/**
		  * \name FBX SDK 2009.3 and later
		  */
		//@{

        /** Write field value as byte. 
          * \param pValue
          */
        void FieldWriteByte(kByte pValue);

        /** Write field pFieldName field with a byte value. 
          * \param pFieldName
          * \param pValue
          */
        void FieldWriteByte(const char* pFieldName, kByte pValue);

        /** Write field value as unsigned byte. 
          * \param pValue
          */
        void FieldWriteUByte(kUByte pValue);

        /** Write field pFieldName field with an unsigned byte value. 
          * \param pFieldName
          * \param pValue
          */
        void FieldWriteUByte(const char* pFieldName, kUByte pValue);

        /** Write field value as short. 
          * \param pValue
          */
        void FieldWriteShort(kShort pValue);

        /** Write field pFieldName field with a short value. 
          * \param pFieldName
          * \param pValue
          */
        void FieldWriteShort(const char* pFieldName, kShort pValue);

        /** Write field value as unsigned short. 
          * \param pValue
          */
        void FieldWriteUShort(kUShort pValue);

        /** Write field pFieldName field with an unsigned short value. 
          * \param pFieldName
          * \param pValue
          */
        void FieldWriteUShort(const char* pFieldName, kUShort pValue);

        /** Write field value as an unsigned integer. 
          * \param pValue
          */
        void FieldWriteUI(unsigned int pValue);

        /** Write field pFieldName field with an unsigned int as a value. 
          * \param pFieldName
          * \param pValue
          */
        void FieldWriteUI(const char* pFieldName, unsigned int pValue);

        /** Write field value as 64 bit unsigned integer. 
          * \param pValue
          */
        void FieldWriteULL(kULongLong pValue);

        /** Write field pFieldName field with an 64 bit unsigned int as a value. 
          * \param pFieldName
          * \param pValue
          * \return void
          */
        void FieldWriteULL(const char* pFieldName, kULongLong pValue);

        /** Write array to file.
          * \param n Nb of items in the array.
          * \param pValue Pointer to the data.
          * \param pSize Size of each item in the array.
          * \param pStride Array stride.
          */
		void FieldWriteArraySBytes( int n, const kByte* pValue, int pSize = 1, int pStride = 0 );
        /** Write array to file.
          * \param n Nb of items in the array.
          * \param pValue Pointer to the data.
          * \param pSize Size of each item in the array.
          * \param pStride Array stride.
          */
		void FieldWriteArrayShort( int n, const kShort* pValue, int pSize = 1, int pStride = 0 );
        /** Write array to file.
          * \param n Nb of items in the array.
          * \param pValue Pointer to the data.
          * \param pSize Size of each item in the array.
          * \param pStride Array stride.
          */
		void FieldWriteArrayUShort( int n, const kUShort* pValue, int pSize = 1, int pStride = 0 );
        /** Write array to file.
          * \param n Nb of items in the array.
          * \param pValue Pointer to the data.
          * \param pSize Size of each item in the array.
          * \param pStride Array stride.
          */
        void FieldWriteArrayUI( int n, const unsigned int*        pValue, int pSize = 1, int pStride = 0 );
        /** Write array to file.
          * \param n Nb of items in the array.
          * \param pValue Pointer to the data.
          * \param pSize Size of each item in the array.
          * \param pStride Array stride.
          */
        void FieldWriteArrayULL(int n, const kULongLong*  pValue, int pSize = 1, int pStride = 0 );
		//@}

        /** ASCII files may limit how big you can write your raw data, forcing you to break it down into chunks. 
          * \return int
          */
        int GetFieldRMaxChunkSize() const;

        /** Write object reference pName in the current field. 
          * \param pName
          */
        void FieldWriteObjectReference(const char* pName);

        /** Write object reference pName in field pFieldName. 
          * \param pFieldName
          * \param pName
          */
        void FieldWriteObjectReference(const char* pFieldName, const char* pName);

        /** Write field with file content as a value.
        * \param pFileName
        * \param pRelativeFileName
        * \remarks Only works when file is binary. This function is not related to flag mEmbedded.
        * \return \c false if operation failed.
        */
        bool FieldWriteEmbeddedFile (KString pFileName, KString pRelativeFileName);

        /** Write comments, only effective in ASCII mode. 
          * \param pFieldName
          */
        void WriteComments(const char* pFieldName);

        //@}

        /**
        * \name Error
        */
        //@{

        //! Error code
        enum EError
        {
            eFileCorrupted,
            eFileVersionNotSupportedYet,
            eFileVersionNotSupportedAnymore,
            eFileNotOpened,
            eFileNotCreated,
            eDirectoryNotCreated,
            eCrcCheckFailed,
            eNonExistingSection,
            eOperationCanceled,
            eCountError,
            eInvalidData,
            eWriteError,
            eReadError,
            eErrorCount
        };

        /** Retrieve error object.
        *  \return error object.
        */
        KError& GetError();

        /** Get last error code.
        *  \return last error code.
        */
        EError GetLastErrorID() const;

        /** Get last error code.
        *  \return last error code.
        */
        const char* GetLastErrorString() const;

        //@}

    #ifdef _DEBUG
        // Dump function for debugging purpose only
        void StdoutDump();
    #endif

        bool GetHaveLoadedEmbededFile() const;

        void* GetMemoryFileInfo(kULong& pSize);

    public:
        bool    IsBeforeVersion6() const;
        void    SetIsBeforeVersion6(bool pIsBeforeVersion6);

    private:
        struct KFbxImpl;
        KFbxImpl* mImpl;

        //! Project Global

        void ProjectClear();
        void ProjectReset();

        bool ProjectReadHeader(bool pCheckASCIIHeader, bool pCheckCRC, bool pOpenMainSection, KFbxFileHeaderInfo* pFileHeaderInfo);
        bool ProjectReadExtendedHeader(int& pExtendedHeaderEnd, KFbxFileHeaderInfo* pFileHeaderInfo);
        bool BinaryReadHeader();
        bool BinaryReadSectionPosition();
        bool ASCIIReadHeader();
        bool ASCIIReadSectionPosition();

        bool ProjectWriteHeader(KFbxFileHeaderInfo* pFileHeaderInfo);
        bool ProjectWriteExtendedHeader(KFbxFileHeaderInfo* pFileHeaderInfo);
        void BinaryWriteHeader();
        void ASCIIWriteHeader();

        void ReadEncryptionKey(char* pEncryptionKey);
        void WriteEncryptionKey(char* pEncryptionKey);

        //! Project Section

        bool ProjectClearSection();
        bool ProjectOpenSection(int pSection);
        bool BinaryReadSectionHeader();
        int BinaryReadSectionFooter(char* pSourceCheck);
        bool BinaryReadExtensionCode(kUInt32 pFollowingSectionStart, kUInt32& pSectionStart, kUInt32& pSectionVersion);
        void BinaryReadSectionPassword();

        bool ProjectWriteSectionHeader();
        void BinaryWriteSectionFooter();
        bool BinaryWriteExtensionCode(kUInt32 pSectionStart, kUInt32 pSectionVersion);

        KString GetCreationTime();
        void SetCreationTime(KString pCreationTime);
        void CreateSourceCheck(char* lSourceCheck);
        bool TestSourceCheck(char* pSourceCheck, char* pSourceCompany);
        KString GetMangledCreationTime();
        void EncryptSourceCheck(char* pSourceCheck, char* pEncryptionData);
        void DecryptSourceCheck(char* pSourceCheck, const char* pEncryptionData);

        void EncryptPasswordV1(KString pOriginalPassword, KString &pEncryptedPassword);
        void DecryptPasswordV1(KString pEncryptedPassword, KString &pDecryptedPassword);

        //! Read

        void CheckValidityOfFieldName(const char* pFieldName);
        void GetUnusedEmbeddedName(const KString& pDirectory, const KString& pName, KString& pResult, bool pCreateSubdirectory);

        //! Get project media directory name
        KString GetDirectory(bool pAutoCreate, const char* pExtension);
    };

#include <fbxfilesdk/fbxfilesdk_nsend.h>

#endif // FBXFILESDK_COMPONENTS_KBASELIB_KFBX_KFBX_H

