/*!  \file iobject.h
 */

#ifndef FBXFILESDK_COMPONENTS_KBASELIB_OBJECT_I_IOBJECT_H
#define FBXFILESDK_COMPONENTS_KBASELIB_OBJECT_I_IOBJECT_H

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

#include <fbxfilesdk/fbxfilesdk_nsbegin.h>

    #ifdef KFBX_PLUGIN
	    #define IObject                 IKObject
	    #define HIObject                HIKObject
	    #define IObjectID               IKObjectID
	    #define IKObjectID              0
	    #define IObjectDerived     public IKObject
    #else
	    #define IObjectID          0
	    #define IObjectDerived     public IObject
    #endif

    /** forwarding **/
    KFBX_FORWARD( IObject )

    /** other types **/
    typedef unsigned long kInterfaceID;

    /** MACRO Base definitions **/
    #define KFBX_FncDefine(PFNC,ISPURE) virtual PFNC##ISPURE
    #define KFBX_Pure           =0;
    #define KFBX_Implementation ;
    #define KFBX_IObjectImplement(ClassName,KFBX_IObjectOwner) \
        HIObject ClassName##::IQuery(kInterfaceID pInterfaceID,int IsLocal) {\
            if ((KFBX_IObjectOwner!=NULL) && (!IsLocal)) {\
                return KFBX_IObjectOwner->IQuery(pInterfaceID);\
            }\
            switch (pInterfaceID) 
    #define KFBX_IObjectEnd return NULL; }
    #define KFBX_ILOCAL          1

    #define KFBX_IQUERY(Object,Interface) ((H##Interface)((Object)->IQuery(Interface##ID,0)))
    #define KFBX_IQUERYLOCAL(Object,Interface) ( (H##Interface)((Object)->IQuery(Interface##ID,KFBX_ILOCAL)))

    #define KFBX_IQ(Object,Interface) KFBX_IQUERY(Object,Interface)
    #define KFBX_IQL(Object,Interface) KFBX_IQUERYLOCAL(Object,Interface)

    /*********************************************************************
    *  Class IObject
    *    This is the base class of all Important interfaces of the system 
    *********************************************************************/

    #define KFBX_IObject_Declare(IsPure)\
    public:\
        virtual HIObject	IQuery(kInterfaceID pInterfaceID, int IsLocal=0)IsPure\
        virtual void		Destroy(int IsLocal=0)IsPure\

    #define KFBX_IQuery_Declare(IsPure)\
    public:\
        virtual HIObject IQuery (kInterfaceID pInterfaceID, int IsLocal=0)IsPure\
        
    class IObject {
        KFBX_IObject_Declare(KFBX_Pure)
    };

    typedef HIObject (* kObjectCreatorFnc)(HIObject pOwner,char *pName,void *pData);

    #ifdef KARCH_DEV_MSC
	    #define KFBX_INTERFACE_SPECIAL  __declspec(novtable)
	    #define NO_DLL				    __declspec()		// Use for the Module parameter if the interface is not exported
    #else 
	    #define KFBX_INTERFACE_SPECIAL 
	    #define NO_DLL									// Use for the Module parameter if the interface is not exported
    #endif

    #define KFBX_INTERFACE( Name,Id ) \
    KFBX_FORWARD( Name ) \
    const int Name##ID = Id; \
    class KFBX_INTERFACE_SPECIAL Name : IObjectDerived { \
        Name##_Declare(KFBX_Pure) \
    } 

#include <fbxfilesdk/fbxfilesdk_nsend.h>

#endif // FBXFILESDK_COMPONENTS_KBASELIB_OBJECT_I_IOBJECT_H

