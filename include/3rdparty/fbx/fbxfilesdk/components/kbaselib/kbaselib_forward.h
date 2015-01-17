/*!  \file kbaselib_forward.h
 */

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

#ifndef FBXFILESDK_COMPONENTS_KBASELIB_KBASELIB_FORWARD_H
#define FBXFILESDK_COMPONENTS_KBASELIB_KBASELIB_FORWARD_H

#include <fbxfilesdk/components/kbaselib/kbaselib_h.h>

KFBX_FORWARD(IError)

#include <fbxfilesdk/fbxfilesdk_nsbegin.h> // namespace 

    class KgeTVector;
    class KgeRVector;
    class KgeSVector;
    class KgeRGBVector;
    class KgeRGBAVector;
    class KgeRMatrix;
    class KgeQuaternion;
    class KgeAMatrix;
    
    typedef KgeTVector KgeVector;
    
    struct KMergeInfo;

    // Forward
    KFBX_FORWARD(KBitSet)
    KFBX_FORWARD(KTime)

    KFBX_FORWARD(KMpMutex)
    KFBX_FORWARD(KMpFastMutex)
    KFBX_FORWARD(KMpTrigger)
    KFBX_FORWARD(KMpGate)
    KFBX_FORWARD(KMpFastLock)
    KFBX_FORWARD(KMpThread)
    KFBX_FORWARD(KMpFifo)
    KFBX_FORWARD(KMpStack)

    KFBX_FORWARD(KError)
    KFBX_FORWARD(KObject)
    KFBX_FORWARD(KProperty)
    KFBX_FORWARD(HdlKObject)
    KFBX_FORWARD(KStateMember)
    KFBX_FORWARD(IRegister)
    KFBX_FORWARD(KPlug)
    KFBX_FORWARD(KEvaluateInfo)
    KFBX_FORWARD(KEventEntity)
    KFBX_FORWARD(KEvaluationState)
    KFBX_FORWARD(IApplyManager)
    KFBX_FORWARD(IMergeManager)
    KFBX_FORWARD(KDataType)
    KFBX_FORWARD(IKObject)

    KFBX_FORWARD(KRenamingStrategy)    
    KFBX_FORWARD(KObjectList)
    KFBX_FORWARD(KMBTransform)

    KFBX_FORWARD(KChainedFile)

    KFBX_FORWARD(KFbxField)
    KFBX_FORWARD(KFbxFieldList)
    KFBX_FORWARD(KUniqueNameObjectList)
    KFBX_FORWARD(KConfigFile)
    KFBX_FORWARD(KFbx)

    KFBX_FORWARD(KSet)    
    
    KFBX_FORWARD(Ktcpip)

    KFBX_FORWARD(KStringList)

    KFBX_FORWARD(KCharPtrSet)
    
#include <fbxfilesdk/fbxfilesdk_nsend.h> // namespace 

#endif // FBXFILESDK_COMPONENTS_KBASELIB_KBASELIB_FORWARD_H

