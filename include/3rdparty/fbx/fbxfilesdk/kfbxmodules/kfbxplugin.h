/*!  \file kfbxplugin.h
 */

#ifndef FBXFILESDK_KFBXMODULES_KFBXPLUGIN_H
#define FBXFILESDK_KFBXMODULES_KFBXPLUGIN_H

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
// FBX includes
#include <fbxfilesdk/kfbxplugins/kfbxobject.h>

#include <fbxfilesdk/components/kbaselib/klib/kstring.h>
#include <fbxfilesdk/components/kbaselib/klib/kintrusivelist.h>
#include <fbxfilesdk/components/kbaselib/object/klibrary.h>

#include <fbxfilesdk/kfbxevents/kfbxemitter.h>
#include <fbxfilesdk/kfbxevents/kfbxlistener.h>

// FBX begin namespace
#include <fbxfilesdk/fbxfilesdk_nsbegin.h>

// Forward declaration
class KFbxSdkManager;

    // Forward declaration
    class KFbxLoadingStrategy;
    class KFbxPluginContainer;

#define KFBXPLUGIN_DECLARE(Plugin)\
	public:\
		static Plugin* Create( const KFbxPluginDefinition& pDefinition, kLibHandle pLibHandle );\
		void Destroy();

#define KFBXPLUGIN_IMPLEMENT(Plugin)\
	Plugin* Plugin::Create( const KFbxPluginDefinition& pDefinition, kLibHandle pLibHandle )\
	{\
		return new Plugin( pDefinition, pLibHandle );\
	}\
	void Plugin::Destroy()\
	{\
		delete this;\
	}


    /** \class KFbxPluginDefinition
    *
    * \brief Plug-in defines itself by filling this structure
    * 
    */
    struct KFBX_DLL KFbxPluginDefinition
    {
        KFbxPluginDefinition():mName("Unknown Name"),mVersion("Unknown Version"){}
        KString mName;
        KString mVersion;
    };

    /** \class KFbxPluginData
    *
    * \brief Data used to communicate information between an application and a plug-in 
    * 
    */
    struct KFBX_DLL KFbxPluginData
    {
        KFbxPluginData():mQueryEmitter(0),mSDKManager(0),mPluginContainer(0){}
        explicit					KFbxPluginData(const KFbxPluginData& r):mQueryEmitter(r.mQueryEmitter),mSDKManager(r.mSDKManager),mPluginContainer(r.mPluginContainer){}
        KFbxSdkManager*				mSDKManager;             // (Optional) SDK manager to which the plug-in can register custom types
        KFbxPluginContainer*		mPluginContainer;   // (Optional) Container which will have the ownership of the plug-in
        kfbxevents::KFbxEmitter*	mQueryEmitter;  // (Optional) The plug-in can listen to this query emitter
    };

    /** \class KFbxPlugin
    *
    * \brief Abstract class used to implement plug-ins.
    * 
    */
    class KFBX_DLL KFbxPlugin : public kfbxevents::KFbxListener
    {
        KFBX_LISTNODE(KFbxPlugin,1);

    public:
        /**
        *\name Public interface
        */
        //@{

		/** const accessor to the plug-in definition.  Plug-in definition contains basic information on the plug-in like its name or version. 
         * \return The definition for the current plug-in
        */
        inline const KFbxPluginDefinition& GetDefinition()const;

		virtual void Destroy() = 0;

        inline KFbxObject& GetPluginSettings() { return *(mPluginSettings.Get()); }

        inline const KFbxObject& GetPluginSettings() const { return *(mPluginSettings.Get()); }

        //@}

    protected:
		/** Constructor
		  * Use the Create() and Destroy() methods declared and implemented in the
		  * KFBXPLUGIN_DECLARE and KFBXPLUGIN_IMPLEMENT macros to construct and destroy
		  * KFbxPlugin objects.
		  * \param pDefinition
          * \param pLibHandle
        */
        explicit KFbxPlugin(const KFbxPluginDefinition& pDefinition, kLibHandle pLibHandle);
		
		/** Accessor to the plug-in data.
        * \return The data for the current plug-in
        */
        inline KFbxPluginData& GetData();

        /** const accessor to the plug-in data.
        * \return The const data for the current plug-in
        */
        inline const KFbxPluginData& GetData()const;

    private:
        bool mInitialized;
        KFbxPluginData mData;
        KFbxPluginDefinition mDefinition;
		kLibHandle mLibraryHandle;

	public:
        /**
        *\name User implementation
        */
        //@{

        /** Method called after plug-in construction. At that moment, plug-in data have been properly 
        *   initialized. This is where the user implementation do their initialization routines
        */
        virtual bool SpecificInitialize() = 0;

        /** Method called before plug-in destruction.
        *   This is where the user implementation do their uninitialization routines
        */
        virtual bool SpecificTerminate() = 0;
         //@}

		virtual void WriteBegin(KFbxScene& pScene){}
		virtual void WriteParameters(KFbxObject& pParams){}
		virtual void WriteEnd(KFbxScene& pScene){}
		virtual void ReadBegin(KFbxScene& pScene){}
		virtual void ReadParameters(KFbxObject& pParams){}
		virtual void ReadEnd(KFbxScene& pScene){}

		/**
        *\name Event registration
        */
        //@{
        template <typename EventType,typename ListernerType> inline KFbxEventHandler* Bind(void (ListernerType::*pFunc)(const EventType*))
        {
			return KFbxListener::Bind<EventType,ListernerType>(*(GetData().mQueryEmitter), pFunc );
        }

        /** Retrieve module instance handle.
        *   With the instance handle, someone can query proc addresses for example, allowing more complex interactions
        */
		kLibHandle GetLibraryHandle();

    private:
        ///////////////////////////////////////////////////////////////////////////////
        //
        //  WARNING!
        //
        //	Anything beyond these lines may not be documented accurately and is 
        // 	subject to change without notice.
        //
        ///////////////////////////////////////////////////////////////////////////////
        #ifndef DOXYGEN_SHOULD_SKIP_THIS

        friend class KFbxLoadingStrategy;
        bool Initialize(const KFbxPluginData& pData);
        bool Terminate();

        KFBXObjectScopedPtr<KFbxObject> mPluginSettings;

        #endif
    };

    /////////////////////////////////////////////////////////////////////////////////////////////
    inline const KFbxPluginDefinition& KFbxPlugin::GetDefinition()const{ return mDefinition; }
    /////////////////////////////////////////////////////////////////////////////////////////////
    inline KFbxPluginData& KFbxPlugin::GetData(){ return mData; }
    /////////////////////////////////////////////////////////////////////////////////////////////
    inline const KFbxPluginData& KFbxPlugin::GetData()const{ return mData; }

// FBX end namespace
#include <fbxfilesdk/fbxfilesdk_nsend.h>

#endif // FBXFILESDK_KFBXMODULES_KFBXPLUGIN_H
