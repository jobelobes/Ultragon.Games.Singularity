/*!  \file kfbxcontainertemplate.h
 */

#ifndef FBXFILESDK_KFBXCONTAINERTEMPLATE_H
#define FBXFILESDK_KFBXCONTAINERTEMPLATE_H

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
#include <fbxfilesdk/components/libxml2-2.6.4/include/libxml/globals.h>

#include <fbxfilesdk/kfbxplugins/kfbxobject.h>
#include <fbxfilesdk/fbxfilesdk_nsbegin.h>

//Container Template tokens
#define CONTAINER_TEMPLATE  "templates"
#define TEMPLATE            "template"
#define EXTENDS_TEMPLATE    "extends"

class KFbxSdkManager;

/** Class for Container Template files.
* \nosubgrouping
*/
class KFBX_DLL KFbxContainerTemplate : public KFbxObject
{
    KFBXOBJECT_DECLARE(KFbxContainerTemplate, KFbxObject);

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
    KArrayTemplate<KString> mExtendTemplateNames; //Call ParseTemplateFile() to fill this arrays.
    KArrayTemplate<KString> mExtendTemplatePaths;

protected:
    KString mTemplateName;
    KString mTemplatePath;
    KString mTemplatePackageName;

    //This constructor is mandatory, it must be put in the protected section
    //because all objects MUST be created via the Sdk Manager
    KFbxContainerTemplate(KFbxSdkManager& pManager, char const* pName);

    
public:
    KString	GetTypeName() const;

    bool SetTemplateName(const char* pFileName);
    char const* GetTemplateName () const;

    bool SetTemplatePath(const char* pFilePath);
    char const* GetTemplatePath () const;

    //Call SetTemplatePath() to set proper template path before call this parse function
    void ParseTemplateFile();

private:
    xmlDocPtr mXmlDoc;

    KString GetContent(xmlNode* pXmlNode);
    KString GetProperty(xmlNode* pXmlNode, const char* pProperty);
    void GetExtendTemplates(xmlNode* pXmlNode);

    friend class KFbxContainer;
#endif // #ifndef DOXYGEN_SHOULD_SKIP_THIS
};

#include <fbxfilesdk/fbxfilesdk_nsend.h>

#endif
