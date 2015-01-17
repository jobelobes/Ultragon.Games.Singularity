/*!  \file kfbxnode.h
 */

#ifndef FBXFILESDK_KFBXPLUGINS_KFBXNODE_H
#define FBXFILESDK_KFBXPLUGINS_KFBXNODE_H

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

#include <fbxfilesdk/kfbxplugins/kfbxtakenodecontainer.h>
#include <fbxfilesdk/kfbxplugins/kfbxnodelimits.h>
#include <fbxfilesdk/kfbxplugins/kfbxgroupname.h>

#include <fbxfilesdk/kfbxmath/kfbxtransformation.h>
#include <fbxfilesdk/kfbxmath/kfbxvector4.h>
#include <fbxfilesdk/kfbxmath/kfbxmatrix.h>
#include <fbxfilesdk/kfbxmath/kfbxxmatrix.h>

#include <fbxfilesdk/components/kbaselib/klib/karrayul.h>
#include <fbxfilesdk/components/kbaselib/klib/kerror.h>
#include <fbxfilesdk/components/kbaselib/klib/kstring.h>
#include <fbxfilesdk/components/kbaselib/klib/ktime.h>

#include <fbxfilesdk/components/kbaselib/kbaselib_forward.h>

#include <fbxfilesdk/fbxfilesdk_nsbegin.h>

    class KFbxNodeAttribute;
    class KFbxScene;
    class KFbxSdkManager;
	class KFbxLodGroup;
    class KFbxNull;
    class KFbxMarker;
    class KFbxSkeleton;
    class KFbxGeometry;
    class KFbxMesh;
    class KFbxNurb;
    class KFbxNurbsCurve;
    class KFbxNurbsSurface;
    class KFbxTrimNurbsSurface;
    class KFbxPatch;
    class KFbxCamera;
    class KFbxCameraStereo;
    class KFbxCameraSwitcher;
    class KFbxLight;
    class KFbxOpticalReference;
    class KFbxCharacter;
    class KFbxNode_internal;
    class KFbxSurfaceMaterial;
    class KFbxSubdiv;

    /** This class provides the structure to build a node hierarchy.
      * \nosubgrouping
      * It is a composite class that contains node tree management services in itself.
      * Cyclic graphs are forbidden in a node hierarchy.
      *
      * The content of a node is in its node attribute, which is an instance of a
      * class derived from KFbxNodeAttribute. A node attribute can be shared among nodes.
      * By default, the node attribute pointer is \c NULL meaning it is a simple reference point.
      *
      * A node also contains an array of take nodes to hold animation data. See
      * KFbxTakeNodeContainer for more details.
      */
    class KFBX_DLL KFbxNode : public KFbxTakeNodeContainer
    {
        KFBXOBJECT_DECLARE(KFbxNode,KFbxTakeNodeContainer);
        public:
        /**
          * \name Node Tree Management
          * This class holds the node tree structure in itself.
          */
        //@{

            /** Get the parent node.
              * \return Pointer to parent node or \c NULL if the current node has no parent.
              */
            KFbxNode* GetParent();
            KFbxNode const* GetParent() const;

            /** Add a child node and its underlying node tree.
              * \param pNode Child node.
              * \return \c true on success, \c false otherwise.
              * In the last case, KFbxNode::GetLastErrorID() can return one of the following:
              *     - eCYCLIC_GRAPH: The child node is already in the current node tree, the operation fails to avoid a cyclic graph.
              *     - eNODE_NAME_CLASH: The child node has a name already owned by another node in the destination scene.
              *     - eTEXTURE_NAME_CLASH: A texture in the child node has a name already owned by another texture in the destination scene.
              *     - eVIDEO_NAME_CLASH: A video in the child node has a name already owned by another video in the destination scene.
              *     - eMATERIAL_NAME_CLASH: A material in the child node has a name already owned by another material in the destination scene.
              *
              * The operation will succeed in any case if the current node doesn't belong to a scene.
              * \remarks If the added node already has a parent, it is first removed from it.
              */
            bool AddChild(KFbxNode* pNode);

            /** Remove the child node.
              * \param pNode The given child node to be removed.
              * \return The removed child node.
              */
            KFbxNode* RemoveChild(KFbxNode* pNode);

            /** Get the number of children nodes.
              * \param pRecursive If \c true the method will also count all the descendant children.
              * \return Total number of children for this node.
              */
            int GetChildCount(bool pRecursive = false) const;

            /** Get child by index.
			  * \param pIndex The child index.
              * \return Child node or \c NULL if index is out of range.
              * In the last case, KFbxNode::GetLastErrorID() returns eINDEX_OUT_OF_RANGE.
              */
            KFbxNode* GetChild(int pIndex);

            /** Get child by index.
			  * \param pIndex The child index.
              * \return Child node or \c NULL if index is out of range.
              * In the last case, KFbxNode::GetLastErrorID() returns eINDEX_OUT_OF_RANGE.
              */
            KFbxNode const* GetChild(int pIndex) const;

            /** Finds a child node by name.
              * \param pName Name of the searched child node.
              * \param pRecursive Flag to request recursive calls.
              * \param pInitial Flag to a search in initial names.
              * \return Found child node or \c NULL if no child node with this name exists.
              */
            KFbxNode* FindChild(char const* pName, bool pRecursive = true, bool pInitial = false);

        //@}

        /**
          * \name Node Target Management
          * When set, the target defines the orientation of the node.
          *
          * By default, the node's X axis points towards the target. A rotation
          * offset can be added to change this behavior. While the default
          * relative orientation to target is right for cameras, this feature is
          * useful for lights because they require a 90-degree offset on the Z
          * axis.
          *
          * By default, the node's up vector points towards the Up node.
          * If an Up node is not specified, the node's Up vector points towards the Y axis. A
          * rotation offset can be added to change this behavior. While the default
          * relative orientation to target is right for cameras, this feature is
          * useful for lights because they require a 90-degree offset on the Z
          * axis.
          */
        //@{

            /** The target must be part of the same scene and it cannot be itself.
              * \param pNode The target.
              */
            void SetTarget(KFbxNode* pNode);

            /** Get the target for this node.
              * \returns \c NULL if target isn't set.
              */
            KFbxNode* GetTarget() const;

            /** Set rotation offset from default relative orientation to target.
              * \param pVector The rotation offset.
              */
            void SetPostTargetRotation(KFbxVector4 pVector);

            /** Get rotation offset from default relative orientation to target.
              * \return The rotation offset.
              */
            KFbxVector4 GetPostTargetRotation() const;

            /** The target up node must be part of the same scene and it cannot be itself.
              * \param pNode The target.
              */
            void SetTargetUp(KFbxNode* pNode);

            /** Get the target up node.
              * \return \c NULL if the target up model isn't set.
              */
            KFbxNode* GetTargetUp() const;

            /** Set up vector offset from default relative target up vector.
              * \param pVector The rotation offset.
              */
            void SetTargetUpVector(KFbxVector4 pVector);

            /** Get up vector offset from default relative target up vector.
              * \return The up vector offset.
              */
            KFbxVector4 GetTargetUpVector() const;

        //@}


        /**
          * \name UpdateId Management
          */
        //@{
        public:
            virtual kFbxUpdateId GetUpdateId(eFbxUpdateIdType pUpdateId=eUpdateId_Object) const;
        //@}

        /**
          * \name Node Display Parameters
          */
        //@{
            /** Set visibility.
              * \param pIsVisible Node is visible in the scene if set to \c true.
              */
            void SetVisibility(bool pIsVisible);

            /** Get visibility.
              * \return \c true if node is visible in the scene.
              */
            bool GetVisibility() const;

            /** \enum EShadingMode Shading modes.
              * - \e eHARD_SHADING
              * - \e eWIRE_FRAME
              * - \e eFLAT_SHADING
              * - \e eLIGHT_SHADING
              * - \e eTEXTURE_SHADING
              * - \e eLIGHT_TEXTURE_SHADING
              */
            typedef enum
            {
                eHARD_SHADING,
                eWIRE_FRAME,
                eFLAT_SHADING,
                eLIGHT_SHADING,
                eTEXTURE_SHADING,
                eLIGHT_TEXTURE_SHADING
            } EShadingMode;

            /** Set the shading mode.
              * \param pShadingMode The shading mode.
              */
            void SetShadingMode(EShadingMode pShadingMode);

            /** Get the shading mode.
              * \return The currently set shading mode.
              */
            EShadingMode GetShadingMode() const;

            /** Enable or disable the multilayer state.
              * \param pMultiLayer The new state of the multi-layer flag.
              */
            void SetMultiLayer(bool pMultiLayer);

            /** Get multilayer state.
              * \return The current state of the multi-layer flag.
              */
            bool GetMultiLayer() const;

            /** \enum EMultiTakeMode MultiTake states.
              * - \e eOLD_MULTI_TAKE
              * - \e eMULTI_TAKE
              * - \e eMONO_TAKE
              */
            typedef enum
            {
                eOLD_MULTI_TAKE,
                eMULTI_TAKE,
                eMONO_TAKE
            } EMultiTakeMode;

            /** Set the multitake mode.
              * \param pMultiTakeMode The multitake mode to set.
              */
            void SetMultiTakeMode(EMultiTakeMode pMultiTakeMode);

            /** Get multitake mode.
              * \return The currently set multitake mode.
              */
            EMultiTakeMode GetMultiTakeMode() const;
        //@}

        /**
          * \name Node Attribute Management
          */
        //@{

            /** Set the node attribute.
              * \param pNodeAttribute Node attribute object
              * \return Pointer to previous node attribute object.
              * \c NULL if the node didn't have a node attribute or if
              * the new node attribute is equal to the previous node attribute.
              * \remarks A node attribute can be shared between nodes.
              * \remarks If this node has more than one attribute, the deletion
              * of other attributes is done.
              */
            KFbxNodeAttribute* SetNodeAttribute(KFbxNodeAttribute* pNodeAttribute);

            /** Get the default node attribute.
              * \return Pointer to the default node attribute or \c NULL if the node doesn't
              * have a node attribute.
              */
            KFbxNodeAttribute* GetNodeAttribute();

            /** Get the default node attribute.
              * \return Pointer to the default node attribute or \c NULL if the node doesn't
              * have a node attribute.
              */
            KFbxNodeAttribute const* GetNodeAttribute() const;

            /** Get the count of node attribute(s).
              * \return Number of node attribute(s) connected to this node.
              */
            int GetNodeAttributeCount() const;

            /** Get index of the default node attribute.
              * \return index of the default node attribute or
              * \c -1 if there is no default node attribute
              */
            int GetDefaultNodeAttributeIndex() const;

            /** Set index of the default node attribute.
			  * \param pIndex 
              * \return true if the operation succeeds or
              * \c false in other case.
              * In the last case, KFbxNode::GetLastErrorID() returns eINDEX_OUT_OF_RANGE.
              */
            bool SetDefaultNodeAttributeIndex(int pIndex);

            /** Get node attribute by index.
			  * \param pIndex The index
              * \return Pointer to corresponding node attribute or
              * \c NULL if index is out of range.
              * In the last case, KFbxNode::GetLastErrorID() returns eINDEX_OUT_OF_RANGE.
              */
            KFbxNodeAttribute* GetNodeAttributeByIndex(int pIndex);

            /** Get node attribute by index.
			  * \param pIndex The index
              * \return Pointer to corresponding node attribute or
              * \c NULL if index is out of range.
              * In the last case, KFbxNode::GetLastErrorID() returns eINDEX_OUT_OF_RANGE.
              */
            KFbxNodeAttribute const* GetNodeAttributeByIndex(int pIndex) const;

            /** Get index corresponding to a given node attribute Pointer.
              * \param pNodeAttribute The pointer to a node attribute.
              * \return Index of the node attribute or
              * \c -1 if pNodeAttribute is NULL or not connected to this node.
              * In the last case, KFbxNode::GetLastErrorID() returns eATTRIBUTE_NOT_CONNECTED.
              */
            int GetNodeAttributeIndex(KFbxNodeAttribute* pNodeAttribute) const;

            /** Add a connection to a given node attribute Pointer.
              * \param pNodeAttribute The pointer to a node attribute.
              * \return true if the operation succeeded or
              * \c false if the operation failed.
              * \remarks If the parameter node attribute is already connected
              * to this node, false is returned
              */
            bool AddNodeAttribute(KFbxNodeAttribute* pNodeAttribute);

            /** Remove a connection from a given node attribute.
              * \param pNodeAttribute The pointer to a node attribute.
              * \return Pointer to the removed node attribute or
              * \c NULL if the operation failed.
              * In the last case, KFbxNode::GetLastErrorID() returns eATTRIBUTE_NOT_CONNECTED.
              */
            KFbxNodeAttribute* RemoveNodeAttribute(KFbxNodeAttribute* pNodeAttribute);

            /** Remove a connection to a given node attribute.
              * \param pIndex Index of the node attribute.
              * \return Pointer to the removed node attribute or
              * \c NULL if the operation failed.
              * In the last case, KFbxNode::GetLastErrorID() returns eINDEX_OUT_OF_RANGE.
              */
            KFbxNodeAttribute* RemoveNodeAttributeByIndex(int pIndex);

            /** Get the node attribute casted to a KFbxLodGroup pointer.
              * \return Pointer to the Lod group. \c NULL if the node doesn't have a node
              * attribute or if the node attribute type is not KFbxNodeAttribute::eLODGROUP.
              */
            KFbxLodGroup* GetLodGroup();

			/** Get the node attribute casted to a KFbxNull pointer.
              * \return Pointer to the null. \c NULL if the node doesn't have a node
              * attribute or if the node attribute type is not KFbxNodeAttribute::eNULL.
              */
            KFbxNull* GetNull();

            /** Get the node attribute casted to a KFbxMarker pointer.
              * \return Pointer to the marker. \c NULL if the node doesn't have a node
              * attribute or if the node attribute type is not KFbxNodeAttribute::eMARKER.
              */
            KFbxMarker* GetMarker();

            /** Get the node attribute casted to a KFbxSkeleton pointer.
              * \return Pointer to the skeleton. \c NULL if the node doesn't have a node
              * attribute or if the node attribute type is not KFbxNodeAttribute::eSKELETON.
              */
            KFbxSkeleton* GetSkeleton();

            /** Get the node attribute casted to a KFbxGeometry pointer.
              * \return Pointer to the geometry. \c NULL if the node doesn't have a node
              * attribute or if the node attribute type is not KFbxNodeAttribute::eMESH,
              * KFbxNodeAttribute::eNURB or KFbxNodeAttribute::ePATCH.
              */
            KFbxGeometry* GetGeometry();

            /** Get the node attribute casted to a KFbxMesh pointer.
              * \return Pointer to the mesh. \c NULL if the node doesn't have a node
              * attribute or if the node attribute type is not KFbxNodeAttribute::eMESH.
              */
            KFbxMesh* GetMesh();

            /** Get the node attribute casted to a KFbxNurb pointer.
              * \return Pointer to the nurb. \c NULL if the node doesn't have a node
              * attribute or if the node attribute type is not KFbxNodeAttribute::eNURB.
              */
            KFbxNurb* GetNurb();

            /** Get the node attribute casted to a KFbxNurbsSurface pointer.
              * \return Pointer to the nurbs surface. \c NULL if the node doesn't have a node
              * attribute or if the node attribute type is not KFbxNodeAttribute::eNURBS_SURFACE.
              */
            KFbxNurbsSurface* GetNurbsSurface();

            /** Get the node attribute casted to a KFbxNurbsCurve pointer.
              * \return Pointer to the nurbs curve. \c NULL if the node doesn't have a node
              * attribute or if the node attribute type is not KFbxNodeAttribute::eNURBS_CURVE.
              */
            KFbxNurbsCurve* GetNurbsCurve();

            /** Get the node attribute casted to a KFbxNurbsSurface pointer.
              * \return Pointer to the nurbs surface. \c NULL if the node doesn't have a node
              * attribute or if the node attribute type is not KFbxNodeAttribute::eNURBS_SURFACE.
              */
            KFbxTrimNurbsSurface* GetTrimNurbsSurface();

            /** Get the node attribute casted to a KFbxSubdiv pointer.
              * \return Pointer to the subdivision surface. \c NULL if the node doesn't have a node
              * attribute or if the node attribute type is not KFbxNodeAttribute::eSUBDIV.
              */
            KFbxSubdiv* GetSubdiv();

            /** Get the node attribute casted to a KFbxPatch pointer.
              * \return Pointer to the patch. \c NULL if the node doesn't have a node
              * attribute or if the node attribute type is not KFbxNodeAttribute::ePATCH.
              */
            KFbxPatch* GetPatch();

            /** Get the node attribute casted to a KFbxCamera pointer.
              * \return Pointer to the camera. \c NULL if the node doesn't have a node
              * attribute or if the node attribute type is not KFbxNodeAttribute::eCAMERA.
              */
            KFbxCamera* GetCamera();

            /** Get the node attribute casted to a KFbxCameraSwitcher pointer.
              * \return Pointer to the camera switcher. \c NULL if the node doesn't have
              * a node attribute or if the node attribute type is not
              * KFbxNodeAttribute::eCAMERA_SWITCHER.
              */
            KFbxCameraSwitcher* GetCameraSwitcher();

            /** Get the node attribute casted to a KFbxLight pointer.
              * \return Pointer to the light. \c NULL if the node doesn't have a node
              * attribute or if the node attribute type is not KFbxNodeAttribute::eLIGHT.
              */
            KFbxLight* GetLight();

            /** Get the node attribute casted to a KFbxOpticalReference pointer.
              * \return Pointer to the optical reference. \c NULL if the node doesn't
              * have a node attribute or if the node attribute type is not
              * KFbxNodeAttribute::eOPTICAL_REFERENCE.
              */
            KFbxOpticalReference* GetOpticalReference();
        //@}

        /**
          * \name Default Animation Values
          * This set of functions provides direct access to default
          * animation values in the default take node.
          */
        //@{

            /** Set default translation vector (in local space).
              * \param pT The translation vector.
              */
            void SetDefaultT(const KFbxVector4& pT);

            /** Get default translation vector (in local space).
              * \param pT The vector that will receive the default translation value.
              * \return Input parameter filled with appropriate data.
              */
            KFbxVector4& GetDefaultT(KFbxVector4& pT);

            /** Set default rotation vector (in local space).
              * \param pR The rotation vector.
              */
            void SetDefaultR(const KFbxVector4& pR);

            /** Get default rotation vector (in local space).
              * \param pR The vector that will receive the default rotation value.
              * \return Input parameter filled with appropriate data.
              */
            KFbxVector4& GetDefaultR(KFbxVector4& pR);

            /** Set default scale vector (in local space).
              * \param pS The rotation vector.
              */
            void SetDefaultS(const KFbxVector4& pS);

            /** Get default scale vector (in local space).
              * \param pS The vector that will receive the default translation value.
              * \return Input parameter filled with appropriate data.
              */
            KFbxVector4& GetDefaultS(KFbxVector4& pS);

            /** Set default visibility.
              * \param pVisibility A value on a scale from 0 to 1.
              * 0 means hidden and any higher value means visible.
              * \remarks This parameter is only effective if node visibility
              * is enabled. Function KFbxNode::SetVisibility() enables
              * node visibility.
              */
            void SetDefaultVisibility(double pVisibility);

            /** Get default visibility.
              * \return A value on a scale from 0 to 1.
              * 0 means hidden and any higher value means visible.
              * \remarks This parameter is only effective if node visibility
              * is enabled. Function KFbxNode::SetVisibility() enables
              * node visibility.
              */
            double GetDefaultVisibility();

        //@}

        /**
          * \name Transformation propagation
          * This set of functions provides direct access to
          * the transformation propagations settings of the KFbxNode.
          * Those settings determine how transformations must be applied
          * when evaluating a node's transformation matrix.
          */
        //@{
            /** Set transformation inherit type.
              * Set how the Translation/Rotation/Scaling transformations of a parent
              * node affect his children.
              * \param pInheritType One of the following values eINHERIT_RrSs, eINHERIT_RSrs or eINHERIT_Rrs
              */
            void SetTransformationInheritType(ETransformInheritType pInheritType);

            /** Get transformation inherit type.
              * \param pInheritType The returned value.
              */
            void GetTransformationInheritType(ETransformInheritType& pInheritType);
        //@}


        /**
          * \name Pivot Management
          * Pivots are used to specify translation, rotation and scaling centers
          * in coordinates relative to a node's origin. A node has two pivot
          * contexts defined by the EPivotSet enumeration. The node's animation
          * data can be converted from one pivot context to the other.
          */
        //@{

            /** \enum EPivotSet  Pivot sets.
              * - \e eSOURCE_SET
              * - \e eDESTINATION_SET
              */
            typedef enum
            {
                eSOURCE_SET,
                eDESTINATION_SET
            } EPivotSet;

            /** \enum EPivotState  Pivot state.
              * - \e ePIVOT_STATE_ACTIVE
              * - \e ePIVOT_STATE_REFERENCE
              */
            typedef enum
            {
                ePIVOT_STATE_ACTIVE,
                ePIVOT_STATE_REFERENCE
            } EPivotState;

            /** Set the pivot state.
              * Tell FBX to use the pivot for TRS computation (ACTIVE), or
              * just keep it as a reference.
              * \param pPivotSet Specify which pivot set to modify its state.
              * \param pPivotState The new state of the pivot set.
              */
            void SetPivotState(EPivotSet pPivotSet, EPivotState pPivotState);

            /** Get the pivot state.
              * Return the state of the pivot. If ACTIVE, we must take the pivot
              * TRS into account when computing the final transformation of a node.
              * \param pPivotSet Specify which pivot set to retrieve its state.
              * \param pPivotState The current state of the pivot set.
              */
            void GetPivotState(EPivotSet pPivotSet, EPivotState& pPivotState);

            /** Set rotation space
              * Determine the rotation space (Euler or Spheric) and the rotation order.
              * \param pPivotSet Specify which pivot set to modify its rotation order.
              * \param pRotationOrder The new state of the pivot rotation order.
              */
            void SetRotationOrder(EPivotSet pPivotSet, ERotationOrder pRotationOrder);

            /** Get rotation order
              * \param pPivotSet Specify which pivot set to retrieve its rotation order.
              * \param pRotationOrder The current rotation order of the pivot set.
              */
            void GetRotationOrder(EPivotSet pPivotSet, ERotationOrder& pRotationOrder);

            /** Set rotation space for limit only.
              * \param pPivotSet Specify which pivot set to set the rotation space limit flag.
              * \param pUseForLimitOnly
              * When set to \c true, the current rotation space (set with SetRotationOrder)
              * define the rotation space for the limit only; leaving the rotation animation
              * in Euler XYZ space. When set to \c false, the current rotation space defines
              * the rotation space for both the limits and the rotation animation data.
              */
            void SetUseRotationSpaceForLimitOnly(EPivotSet pPivotSet, bool pUseForLimitOnly);

            /** Get rotation space for limit only.
              * \param pPivotSet Specify which pivot set to query.
              * \return The rotation space limit flag current value.
              */
            bool GetUseRotationSpaceForLimitOnly(EPivotSet pPivotSet);

            /** Set the RotationActive state.
              * \param pVal The new state of the property.
              * \remark When this flag is set to false, the RotationOrder, the Pre/Post rotation values
              * and the rotation limits should be ignored.
              */
            void SetRotationActive(bool pVal);

            /** Get the RotationActive state.
              * \return The value of the RotationActive flag.
              */
            bool GetRotationActive();

            /** Set the Quaternion interpolation mode
              * \param pPivotSet Specify which pivot set to query.
              * \param pUseQuaternion The new value for the flag.
              */
            void SetUseQuaternionForInterpolation(EPivotSet pPivotSet, bool pUseQuaternion);

            /** Get the Quaternion interpolation mode
              * \param pPivotSet Specify which pivot set to query.
              * \return The currently state of the flag.
              */
            bool GetUseQuaternionForInterpolation(EPivotSet pPivotSet) const;

            /** Set the rotation stiffness.
              * The stiffness attribute is used by IK solvers to generate a resistance
              * to a joint motion. The higher the stiffness the less it will rotate.
              * Stiffness works in a relative sense: it determines the willingness of
              * this joint to rotate with respect to the other joint in the IK chain.
              * \param pRotationStiffness The rotation stiffness values are limited to
              * the range [0, 100].
              */
            void SetRotationStiffness(KFbxVector4 pRotationStiffness);

            /** Get the rotation stiffness
              * \return The currently set rotation stiffness values.
              */
            KFbxVector4 GetRotationStiffness();

            /** Set the minimum damp range angles.
              * This attributes apply resistance to a joint rotation as it approaches the
              * lower boundary of its rotation limits. This functionality allows joint
              * motion to slow down smoothly until the joint reaches its rotation limits
              * instead of stopping abruptly. The MinDampRange specifies when the
              * deceleration should start.
              * \param pMinDampRange : Angle in degrees where deceleration should start
              */
            void SetMinDampRange(KFbxVector4 pMinDampRange);

            /** Get the minimum damp range angles
              * \return The currently set minimum damp range angles.
              */
            KFbxVector4 GetMinDampRange();


            /** Set the maximum damp range angles.
              * This attributes apply resistance to a joint rotation as it approaches the
              * upper boundary of its rotation limits. This functionality allows joint
              * motion to slow down smoothly until the joint reaches its rotation limits
              * instead of stopping abruptly. The MaxDampRange specifies when the
              * deceleration should start.
              * \param pMaxDampRange : Angle in degrees where deceleration should start
              */
            void SetMaxDampRange(KFbxVector4 pMaxDampRange);

            /** Get the maximum damp range angles
              * \return The currently set maximum damp range angles.
              */
            KFbxVector4 GetMaxDampRange();


            /** Set the minimum damp strength.
              * This attributes apply resistance to a joint rotation as it approaches the
              * lower boundary of its rotation limits. This functionality allows joint
              * motion to slow down smoothly until the joint reaches its rotation limits
              * instead of stopping abruptly. The MinDampStrength defines the
              * rate of deceleration
              * \param pMinDampStrength Values are limited to the range [0, 100].
              */
            void SetMinDampStrength(KFbxVector4 pMinDampStrength);

            /** Get the miminum damp strength
              * \return The currently set minimum damp strength values.
              */
            KFbxVector4 GetMinDampStrength();


            /** Set the maximum damp strength.
              * This attributes apply resistance to a joint rotation as it approaches the
              * upper boundary of its rotation limits. This functionality allows joint
              * motion to slow down smoothly until the joint reaches its rotation limits
              * instead of stopping abruptly. The MaxDampStrength defines the
              * rate of deceleration
              * \param pMaxDampStrength Values are limited to the range [0, 100].
              */
            void SetMaxDampStrength(KFbxVector4 pMaxDampStrength);

            /** Get the maximum damp strength
              * \return The currently set maximum damp strength values.
              */
            KFbxVector4 GetMaxDampStrength();

            /** Set the preferred angle.
              * The preferredAngle attribute defines the initial joint configuration used
              * by a single chain ik solver to calculate the inverse kinematic solution.
              * \param pPreferedAngle Angle in degrees
              */
            void SetPreferedAngle(KFbxVector4 pPreferedAngle);

            /** Get the preferred angle
              * \return The currently set preferred angle.
              */
            KFbxVector4 GetPreferedAngle();

            /** Set a translation offset for the rotation pivot.
              * The translation offset is in coordinates relative to the node's origin.
              * \param pPivotSet Specify which pivot set to modify.
              * \param pVector The translation offset.
              */
            void SetRotationOffset(EPivotSet pPivotSet, KFbxVector4 pVector);

            /** Get the translation offset for the rotation pivot.
              * The translation offset is in coordinates relative to the node's origin.
              * \param pPivotSet Specify which pivot set to to query the value.
              * \return The currently set vector.
              */
            KFbxVector4& GetRotationOffset(EPivotSet pPivotSet) const;

            /** Set rotation pivot.
              * The rotation pivot is the center of rotation in coordinates relative to
              * the node's origin.
              * \param pPivotSet Specify which pivot set to modify.
              * \param pVector The new position of the rotation pivot.
              */
            void SetRotationPivot(EPivotSet pPivotSet, KFbxVector4 pVector);

            /** Get rotation pivot.
              * The rotation pivot is the center of rotation in coordinates relative to
              * the node's origin.
              * \param pPivotSet Specify which pivot set to query.
              * \return The current position of the rotation pivot.
              */
            KFbxVector4& GetRotationPivot(EPivotSet pPivotSet) const;

            /** Set pre-rotation in Euler angles.
              * The pre-rotation is the rotation applied to the node before
              * rotation animation data.
              * \param pPivotSet Specify which pivot set to modify.
              * \param pVector The X,Y,Z rotation values to set.
              */
            void SetPreRotation(EPivotSet pPivotSet, KFbxVector4 pVector);

            /** Get pre-rotation in Euler angles.
              * The pre-rotation is the rotation applied to the node before
              * rotation animation data.
              * \param pPivotSet Specify which pivot set to query.
              * \return The X,Y and Z rotation values.
              */
            KFbxVector4& GetPreRotation(EPivotSet pPivotSet) const;

            /** Set post-rotation in Euler angles.
              * The post-rotation is the rotation applied to the node after the
              * rotation animation data.
              * \param pPivotSet Specify which pivot set to modify.
              * \param pVector The X,Y,Z rotation values to set.
              */
            void SetPostRotation(EPivotSet pPivotSet, KFbxVector4 pVector);

            /** Get post-rotation in Euler angles.
              * The post-rotation is the rotation applied to the node after the
              * rotation animation data.
              * \param pPivotSet Specify which pivot set to query.
              * \return The X,Y and Z rotation values.
              */
            KFbxVector4& GetPostRotation(EPivotSet pPivotSet) const;

            /** Set a translation offset for the scaling pivot.
              * The translation offset is in coordinates relative to the node's origin.
              * \param pPivotSet Specify which pivot set to modify.
              * \param pVector The translation offset.
              */
            void SetScalingOffset(EPivotSet pPivotSet, KFbxVector4 pVector);

            /** Get the translation offset for the scaling pivot.
              * The translation offset is in coordinates relative to the node's origin.
              * \param pPivotSet Specify which pivot set to query the value.
              * \return The currently set vector.
              */
            KFbxVector4& GetScalingOffset(EPivotSet pPivotSet) const;

            /** Set scaling pivot.
              * The scaling pivot is the center of scaling in coordinates relative to
              * the node's origin.
              * \param pPivotSet Specify which pivot set to modify.
			  * \param pVector
              * \return The new position of the scaling pivot.
              */
            void SetScalingPivot(EPivotSet pPivotSet, KFbxVector4 pVector);

            /** Get scaling pivot.
              * The scaling pivot is the center of scaling in coordinates relative to
              * the node's origin.
              * \param pPivotSet Specify which pivot set to query.
              * \return The current position of the scaling pivot.
              */
            KFbxVector4& GetScalingPivot(EPivotSet pPivotSet) const;

            /** Set geometric translation
              * The geometric translation is a local translation that is applied
              * to a node attribute only. This translation is applied to the node attribute
              * after the node transformations. This translation is not inherited across the
              * node hierarchy.
              * \param pPivotSet Specify which pivot set to modify.
              * \param pVector The translation vector.
              */
            void SetGeometricTranslation(EPivotSet pPivotSet, KFbxVector4 pVector);

            /** Get geometric translation
              * \param pPivotSet Specify which pivot set to query.
              * \return The current geometric translation.
              */
            KFbxVector4 GetGeometricTranslation(EPivotSet pPivotSet) const;

            /** Set geometric rotation
              * The geometric rotation is a local rotation that is applied
              * to a node attribute only. This rotation is applied to the node attribute
              * after the node transformations. This rotation is not inherited across the
              * node hierarchy.
              * \param pPivotSet Specify which pivot set to modify.
              * \param pVector The X,Y and Z rotation values.
              */
            void SetGeometricRotation(EPivotSet pPivotSet, KFbxVector4 pVector);

            /** Get geometric rotation
              * \param pPivotSet Specify which pivot set to query.
              * \return The current geometric rotation.
              */
            KFbxVector4 GetGeometricRotation(EPivotSet pPivotSet);

            /** Set geometric scaling
              * The geometric scaling is a local scaling that is applied
              * to a node attribute only. This scaling is applied to the node attribute
              * after the node transformations. This scaling is not inherited across the
              * node hierarchy.
              * \param pPivotSet Specify which pivot set to modify.
              * \param pVector The X,Y and Z scale values.
              */
            void SetGeometricScaling(EPivotSet pPivotSet, KFbxVector4 pVector);

            /** Get geometric scaling
			  * \param pPivotSet Specify which pivot set to query.
              * \return The current geometric scaling.
              */
            KFbxVector4 GetGeometricScaling(EPivotSet pPivotSet);

            /** Recursively convert the animation data according to pivot settings.
              * \param pConversionTarget If set to EPivotSet::eDESTINATION_SET,
              * convert animation data from the EPivotSet::eSOURCE_SET pivot context
              * to the EPivotSet::eDESTINATION_SET pivot context. Otherwise, the
              * conversion is computed the other way around.
              * \param pFrameRate Resampling frame rate in frames per second.
              * \param pKeyReduce Apply or skip key reducing filter.
              */
            void ConvertPivotAnimation(EPivotSet pConversionTarget, double pFrameRate, bool pKeyReduce=true);

            /** Reset a pivot set to the default pivot context.
              * \param pPivotSet Pivot set to reset.
              * \remarks The default pivot context is with all the pivots disabled.
              */
            void ResetPivotSet( KFbxNode::EPivotSet pPivotSet );
            
            /** Second version of ConvertPivotAnimation.  This version now takes into account the new pivot set
            * \param pConversionTarget If set to EPivotSet::eDESTINATION_SET,
            * convert animation data from the EPivotSet::eSOURCE_SET pivot context
            * to the EPivotSet::eDESTINATION_SET pivot context. Otherwise, the
            * conversion is computed the other way around.
            * \param pFrameRate Resampling frame rate in frames per second.
            * \param pKeyReduce Apply or skip key reducing filter.
            */
            void ConvertPivotAnimationRecursive(EPivotSet pConversionTarget, double pFrameRate, bool pKeyReduce=true);

            /** Reset all the pivot sets to the default pivot context and convert the animation.
              * \param pFrameRate Resampling frame rate in frames per second.
              * \param pKeyReduce Apply or skip key reducing filter.
              * \param pToNodeCenter: Reset pivots to node center if true, or retain pivot places if false
              * \remarks The resulting animation will be visually equivalent and all the pivots will be cleared.
              * \remarks Will recursively convert the animation of all the children nodes.
              */
            void ResetPivotSetAndConvertAnimation( double pFrameRate=30., bool pKeyReduce=false, bool pToNodeCenter=true );

            /** Set rotation pivot as node center recursively
              * \param pParentGeometricOffset Offset vector to be applied.
              */
            void SetRotationPivotAsCenterRecursive(KFbxVector4 pParentGeometricOffset = KFbxVector4());            
        //@}

        /**
          * \name Access to TRS Local and Global Position
          */
        //@{

            /** Gets the Local Translation from the default take
              * \param pApplyLimits true if node limits are to be applied on result
              * \return             The Local Translation.
              */
            KFbxVector4& GetLocalTFromDefaultTake(bool pApplyLimits = false);

            /** Gets the Local Rotation from the default take
              * \param pApplyLimits true if node limits are to be applied on result
              * \return             The Local Rotation.
              */
            KFbxVector4& GetLocalRFromDefaultTake(bool pApplyLimits = false);

            /** Gets the Local Scale from the default take
              * \param pApplyLimits true if node limits are to be applied on result
              * \return             The Local Scale.
              */
            KFbxVector4& GetLocalSFromDefaultTake(bool pApplyLimits = false);

            /** Get the Global Transformation Matrix from the default take
              * \param  pPivotSet   The pivot set to take into account
              * \param pApplyTarget Applies the necessary transform to align into the target node
              * \return             The Global Transformation Matrix
              */
            KFbxXMatrix& GetGlobalFromDefaultTake(EPivotSet pPivotSet = eSOURCE_SET, bool pApplyTarget = false);

            /** Gets the Local Translation from the current take at a given time
              * \param  pTime       The time at which we want to evaluate
              * \param pApplyLimits true if node limits are to be applied on result
              * \return             The Local Translation.
              */
            KFbxVector4& GetLocalTFromCurrentTake(KTime pTime, bool pApplyLimits = false);

            /** Gets the Local Rotation from the current take at a given time
              * \param  pTime       The time at which we want to evaluate
              * \param pApplyLimits true if node limits are to be applied on result
              * \return             The Local Rotation.
              */
            KFbxVector4& GetLocalRFromCurrentTake(KTime pTime, bool pApplyLimits = false);

            /** Gets the Local Scale from the current take at a given time
              * \param  pTime       The time at which we want to evaluate
              * \param pApplyLimits true if node limits are to be applied on result
              * \return             The Local Scale.
              */
            KFbxVector4& GetLocalSFromCurrentTake(KTime pTime, bool pApplyLimits = false);

            /** Get the Global Transformation Matrix from the current take at a given time
              * \param  pTime       The time at which we want to evaluate
              * \param  pPivotSet   The pivot set to take into accounr
              * \param pApplyTarget Applies the necessary transform to align into the target node
              * \return             The Global Transformation Matrix
              */
            KFbxXMatrix& GetGlobalFromCurrentTake(KTime pTime, EPivotSet pPivotSet = eSOURCE_SET, bool pApplyTarget = false);
        //@}

        /**
          * \name Character Link
          */
        //@{

            /** Get number of character links.
              * \return The number of character links.
              */
            int GetCharacterLinkCount();

            /** Get character link at given index.
              * \param pIndex Index of character link.
              * \param pCharacter Pointer to receive linked character if function succeeds.
              * \param pCharacterLinkType Pointer to receive character link type if function succeeds,
              * cast to \c ECharacterLinkType.
              * \param pNodeId Pointer to receive node ID if function succeeds. Cast to \c ECharacterNodeId
              * if returned character link type is \c eCharacterLink or \c eControlSetLink. Cast to
              * \c EEffectorNodeId if returned character link type is \c eControlSetEffector or
              * \c eControlSetEffectorAux.
			  * \param pNodeSubId
              * \return \c true if function succeeds, \c false otherwise.
              */
            bool GetCharacterLink(int pIndex, KFbxCharacter** pCharacter, int* pCharacterLinkType, int* pNodeId, int *pNodeSubId);

            /** Find if a given character link exists.
              * \param pCharacter Character searched.
              * \param pCharacterLinkType Character link type searched, cast to \c ECharacterLinkType.
              * \param pNodeId Node ID searched. Cast from to \c ECharacterNodeId if searched
              * character link type is \c eCharacterLink or \c eControlSetLink. Cast from
              * \c EEffectorNodeId if searched character link type is \c eControlSetEffector or
              * \c eControlSetEffectorAux.
			  * \param pNodeSubId
              * \return Index of found character link if it exists, -1 otherwise.
              */
            int FindCharacterLink(KFbxCharacter* pCharacter, int pCharacterLinkType, int pNodeId, int pNodeSubId);
        //@}

        /** Find out start and end time of the current take.
          * Query a node and all its children recursively for the current take node
          * start and end time.
          * \param pStart Reference to store start time.
          * \c pStart is overwritten only if start time found is lower than \c pStart value.
          * Initialize to KTIME_INFINITE to make sure the start time is overwritten in any case.
          * \param pStop Reference to store end time.
          * \c pStop is overwritten only if stop time found is higher than \c pStop value.
          * Initialize to KTIME_MINUS_INFINITE to make sure the stop time is overwritten in any case.
          * \return \c true on success, \c false otherwise.
          */
        virtual bool GetAnimationInterval(KTime& pStart, KTime& pStop);


        /**
          * \name Material Management
          */
        //@{

            /** Add a material to this node.
              * \param pMaterial The material to add.
              * \return non-negative index of added material, or -1 on error.
              */
            int AddMaterial( KFbxSurfaceMaterial* pMaterial );

            /** Remove a material from this node.
              * \param pMaterial The material to remove.
              * \return true on success, false otherwise
              */
            bool RemoveMaterial( KFbxSurfaceMaterial* pMaterial );

            /**
              * \return The number of materials applied to this node
              */
            int GetMaterialCount() const;

            /** Access a material on this node.
              * \param pIndex Valid range is [0, GetMaterialCount() - 1]
              * \return The pIndex-th material, or NULL if pIndex is invalid.
              */
            KFbxSurfaceMaterial* GetMaterial( int pIndex ) const;

            /** Remove all materials applied to this node.
              */
            void RemoveAllMaterials();

            /** Find an applied material with the given name.
              * \param pName The requested name
              * \return an index to a material, or -1 if no applied material
              * has the requested name.
              */
            int GetMaterialIndex( char const* pName ) const;

        //@}

        /**
          * \name Error Management
          * The same error object is shared among instances of this class.
          */
        //@{

            /** Retrieve error object.
              * \return Reference to error object.
              */
            KError& GetError();

            /** \enum EError  Error identifiers.
              * Some of these are only used internally.
              * - \e eTAKE_NODE_ERROR
              * - \e eNODE_NAME_CLASH
              * - \e eMATERIAL_NAME_CLASH
              * - \e eTEXTURE_NAME_CLASH
              * - \e eVIDEO_NAME_CLASH
              * - \e eNOT_A_CHILD
              * - \e eCYCLIC_GRAPH
              * - \e eINDEX_OUT_OF_RANGE
              * - \e eATTRIBUTE_NOT_CONNECTED
              * - \e eERROR_COUNT
              */
            typedef enum
            {
                eTAKE_NODE_ERROR,
                eNODE_NAME_CLASH,
                eMATERIAL_NAME_CLASH,
                eTEXTURE_NAME_CLASH,
                eVIDEO_NAME_CLASH,
                eNOT_A_CHILD,
                eCYCLIC_GRAPH,
                eINDEX_OUT_OF_RANGE,
                eATTRIBUTE_NOT_CONNECTED,
                eERROR_COUNT
            } EError;

            /** Get last error code.
              * \return Last error code.
              */
            EError GetLastErrorID() const;

            /** Get last error string.
              * \return Textual description of the last error.
              */
            const char* GetLastErrorString() const;

        //@}


        /**
          * \name Public and fast access Properties
          */
        //@{

            /** This property contains the translation information of the node
            *
            * To access this property do: LclTranslation.Get().
            * To set this property do: LclTranslation.Set(fbxDouble3).
            *
            * Default value is 0.,0.,0.
            */
            KFbxTypedProperty<fbxDouble3>               LclTranslation;

            /** This property contains the rotation information of the node
            *
            * To access this property do: LclRotation.Get().
            * To set this property do: LclRotation.Set(fbxDouble3).
            *
            * Default value is 0.,0.,0.
            */
            KFbxTypedProperty<fbxDouble3>               LclRotation;

            /** This property contains the scaling information of the node
            *
            * To access this property do: LclScaling.Get().
            * To set this property do: LclScaling.Set(fbxDouble3).
            *
            * Default value is 1.,1.,1.
            */
            KFbxTypedProperty<fbxDouble3>               LclScaling;

            /** This property contains the global transform information of the node
            *
            * To access this property do: GlobalTransform.Get().
            * To set this property do: GlobalTransform.Set(KFbxXMatrix).
            *
            * Default value is identity matrix
            */
            KFbxTypedProperty<KFbxXMatrix>              GlobalTransform;

            /** This property contains the visibility information of the node
            *
            * To access this property do: Visibility.Get().
            * To set this property do: Visibility.Set(fbxDouble1).
            *
            * Default value is 1.
            */
            KFbxTypedProperty<fbxDouble1>               Visibility;
            
            /** This property contains the weight information of the node
            *
            * To access this property do: Weight.Get().
            * To set this property do: Weight.Set(fbxDouble1).
            *
            */
            KFbxTypedProperty<fbxDouble1>               Weight;

            /** This property contains the pole vector information of the node
            *
            * To access this property do: PoleVector.Get().
            * To set this property do: PoleVector.Set(fbxDouble3).
            *
            */
            KFbxTypedProperty<fbxDouble3>               PoleVector;

            /** This property contains the twist information of the node
            *
            * To access this property do: Twist.Get().
            * To set this property do: Twist.Set(fbxDouble1).
            *
            */
            KFbxTypedProperty<fbxDouble1>               Twist;

            /** This property contains the world up vector information of the node
            *
            * To access this property do: WorldUpVector.Get().
            * To set this property do: WorldUpVector.Set(fbxDouble3).
            *
            */
            KFbxTypedProperty<fbxDouble3>               WorldUpVector;

            /** This property contains the up vector information of the node
            *
            * To access this property do: UpVector.Get().
            * To set this property do: UpVector.Set(fbxDouble3).
            *
            */
            KFbxTypedProperty<fbxDouble3>               UpVector;

            /** This property contains the aim vector information of the node
            *
            * To access this property do: AimVector.Get().
            * To set this property do: AimVector.Set(fbxDouble3).
            *
            */
            KFbxTypedProperty<fbxDouble3>               AimVector;

            /** This property contains the quaternion interpolate flag of the node
            *
            * To access this property do: QuaternionInterpolate.Get().
            * To set this property do: QuaternionInterpolate.Set(fbxBool1).
			*
            * Default value is false.
            */
            KFbxTypedProperty<fbxBool1>                 QuaternionInterpolate;

            /** This property contains the rotation offset information of the node
            *
            * To access this property do: RotationOffset.Get().
            * To set this property do: RotationOffset.Set(fbxDouble3).
			*
            * Default value is 0.,0.,0.
            */
            KFbxTypedProperty<fbxDouble3>               RotationOffset;

            /** This property contains the rotation pivot information of the node
            *
            * To access this property do: RotationPivot.Get().
            * To set this property do: RotationPivot.Set(fbxDouble3).
			*
            * Default value is 0.,0.,0.
            */
            KFbxTypedProperty<fbxDouble3>               RotationPivot;
 
            /** This property contains the scaling offset information of the node
            *
            * To access this property do: ScalingOffset.Get().
            * To set this property do: ScalingOffset.Set(fbxDouble3).
			*
            * Default value is 0.,0.,0.
            */
            KFbxTypedProperty<fbxDouble3>               ScalingOffset;

            /** This property contains the scaling pivot information of the node
            *
            * To access this property do: ScalingPivot.Get().
            * To set this property do: ScalingPivot.Set(fbxDouble3).
			*
            * Default value is 0.,0.,0.
            */
            KFbxTypedProperty<fbxDouble3>               ScalingPivot;

            /** This property contains the translation active information of the node
            *
            * To access this property do: TranslationActive.Get().
            * To set this property do: TranslationActive.Set(fbxBool1).
			*
            * Default value is false.
            */
            KFbxTypedProperty<fbxBool1>                 TranslationActive;

            /** This property contains the translation information of the node
            *
            * To access this property do: Translation.Get().
            * To set this property do: Translation.Set(fbxDouble3).
			*
            */
            KFbxTypedProperty<fbxDouble3>               Translation;

            /** This property contains the min translation limit information of the node
            *
            * To access this property do: TranslationMin.Get().
            * To set this property do: TranslationMin.Set(fbxDouble3).
			* Default value is 0.,0.,0.
			*
            */
            KFbxTypedProperty<fbxDouble3>               TranslationMin;

            /** This property contains the max translation limit information of the node
            *
            * To access this property do: TranslationMax.Get().
            * To set this property do: TranslationMax.Set(fbxDouble3).
			* Default value is 0.,0.,0.
			*
            */
            KFbxTypedProperty<fbxDouble3>               TranslationMax;

            /** This property contains the flag which actives the x component of min translation limit of the node
            *
            * To access this property do: TranslationMinX.Get().
            * To set this property do: TranslationMinX.Set(fbxBool1).
			* 
			* Default value is false.
            */
            KFbxTypedProperty<fbxBool1>                 TranslationMinX;

            /** This property contains the flag which actives the y component of min translation limit of the node
            *
            * To access this property do: TranslationMinY.Get().
            * To set this property do: TranslationMinY.Set(fbxBool1).
			* 
			* Default value is false.
            */
            KFbxTypedProperty<fbxBool1>                 TranslationMinY;

            /** This property contains the flag which actives the z component of min translation limit of the node
            *
            * To access this property do: TranslationMinZ.Get().
            * To set this property do: TranslationMinZ.Set(fbxBool1).
			* 
			* Default value is false.
            */
            KFbxTypedProperty<fbxBool1>                 TranslationMinZ;

            /** This property contains the flag which actives the x component of max translation limit of the node
            *
            * To access this property do: TranslationMaxX.Get().
            * To set this property do: TranslationMaxX.Set(fbxBool1).
			* 
			* Default value is false.
            */
            KFbxTypedProperty<fbxBool1>                 TranslationMaxX;

            /** This property contains the flag which actives the y component of max translation limit of the node
            *
            * To access this property do: TranslationMaxY.Get().
            * To set this property do: TranslationMaxY.Set(fbxBool1).
			* 
			* Default value is false.
            */
            KFbxTypedProperty<fbxBool1>                 TranslationMaxY;

            /** This property contains the flag which actives the z component of max translation limit of the node
            *
            * To access this property do: TranslationMaxZ.Get().
            * To set this property do: TranslationMaxZ.Set(fbxBool1).
			* 
			* Default value is false.
            */
            KFbxTypedProperty<fbxBool1>                 TranslationMaxZ;

			/** This property contains the rotation order information of the node
            *
            * To access this property do: RotationOrder.Get().
            * To set this property do: RotationOrder.Set(ERotationOrder).
			* Default value is eEULER_XYZ.
			*
            */
            KFbxTypedProperty<ERotationOrder>           RotationOrder;

            /** This property contains the rotation space for limit only flag of the node
            *
            * To access this property do: RotationSpaceForLimitOnly.Get().
            * To set this property do: RotationSpaceForLimitOnly.Set(fbxBool1).
			* 
			* Default value is false.
            */
            KFbxTypedProperty<fbxBool1>                 RotationSpaceForLimitOnly;

            /** This property contains the x value of the rotation stiffness of the node
            *
            * To access this property do: RotationStiffnessX.Get().
            * To set this property do: RotationStiffnessX.Set(fbxDouble1).
			* 
			* Default value is 0.
            */
            KFbxTypedProperty<fbxDouble1>               RotationStiffnessX;

			/** This property contains the y value of the rotation stiffness of the node
            *
            * To access this property do: RotationStiffnessY.Get().
            * To set this property do: RotationStiffnessY.Set(fbxDouble1).
			* 
			* Default value is 0.
            */
            KFbxTypedProperty<fbxDouble1>               RotationStiffnessY;

			/** This property contains the z value of the rotation stiffness of the node
            *
            * To access this property do: RotationStiffnessZ.Get().
            * To set this property do: RotationStiffnessZ.Set(fbxDouble1).
			* 
			* Default value is 0.
            */
            KFbxTypedProperty<fbxDouble1>               RotationStiffnessZ;

            /** This property contains axis length information of the node
            *
            * To access this property do: AxisLen.Get().
            * To set this property do: AxisLen.Set(fbxDouble1).
			* 
			* Default value is 10.
            */
            KFbxTypedProperty<fbxDouble1>               AxisLen;
         
            /** This property contains pre-rotation information of the node
            *
            * To access this property do: PreRotation.Get().
            * To set this property do: PreRotation.Set(fbxDouble3).
			* 
			* Default value is 0.,0.,0.
            */
            KFbxTypedProperty<fbxDouble3>               PreRotation;

			/** This property contains post-rotation information of the node
            *
            * To access this property do: PostRotation.Get().
            * To set this property do: PostRotation.Set(fbxDouble3).
			* 
			* Default value is 0.,0.,0.
            */
            KFbxTypedProperty<fbxDouble3>               PostRotation;

            /** This property contains rotation active information of the node
            *
            * To access this property do: RotationActive.Get().
            * To set this property do: RotationActive.Set(fbxBool1).
			* 
			* Default value is false.
            */
            KFbxTypedProperty<fbxBool1>                 RotationActive;

            /** This property contains the min rotation limit information of the node
            *
            * To access this property do: RotationMin.Get().
            * To set this property do: RotationMin.Set(fbxDouble3).
			* 
			* Default value is 0.,0.,0.
            */
            KFbxTypedProperty<fbxDouble3>               RotationMin;

            /** This property contains the max rotation limit information of the node
            *
            * To access this property do: RotationMax.Get().
            * To set this property do: RotationMax.Set(fbxDouble3).
			* 
			* Default value is 0.,0.,0.
            */
            KFbxTypedProperty<fbxDouble3>               RotationMax;

            /** This property contains the flag which actives the x component of min rotation limit of the node
            *
            * To access this property do: RotationMinX.Get().
            * To set this property do: RotationMinX.Set(fbxBool1).
			* 
			* Default value is false.
            */
            KFbxTypedProperty<fbxBool1>                 RotationMinX;

            /** This property contains the flag which actives the y component of min rotation limit of the node
            *
            * To access this property do: RotationMinY.Get().
            * To set this property do: RotationMinY.Set(fbxBool1).
			* 
			* Default value is false.
            */
            KFbxTypedProperty<fbxBool1>                 RotationMinY;

            /** This property contains the flag which actives the z component of min rotation limit of the node
            *
            * To access this property do: RotationMinZ.Get().
            * To set this property do: RotationMinZ.Set(fbxBool1).
			* 
			* Default value is false.
            */
            KFbxTypedProperty<fbxBool1>                 RotationMinZ;

			/** This property contains the flag which actives the x component of max rotation limit of the node
            *
            * To access this property do: RotationMaxX.Get().
            * To set this property do: RotationMaxX.Set(fbxBool1).
			* 
			* Default value is false.
            */
            KFbxTypedProperty<fbxBool1>                 RotationMaxX;

            /** This property contains the flag which actives the y component of max rotation limit of the node
            *
            * To access this property do: RotationMaxY.Get().
            * To set this property do: RotationMaxY.Set(fbxBool1).
			* 
			* Default value is false.
            */
            KFbxTypedProperty<fbxBool1>                 RotationMaxY;

			/** This property contains the flag which actives the z component of max rotation limit of the node
            *
            * To access this property do: RotationMaxZ.Get().
            * To set this property do: RotationMaxZ.Set(fbxBool1).
			* 
			* Default value is false.
            */
            KFbxTypedProperty<fbxBool1>                 RotationMaxZ;

            /** This property contains inherit type information of the node
            *
            * To access this property do: InheritType.Get().
            * To set this property do: InheritType.Set(ETransformInheritType).
			* 
			* Default value is eINHERIT_RrSs.
            */
            KFbxTypedProperty<ETransformInheritType>    InheritType;

            /** This property contains scaling active information of the node
            *
            * To access this property do: ScalingActive.Get().
            * To set this property do: ScalingActive.Set(fbxBool1).
			* 
			* Default value is false.
            */
            KFbxTypedProperty<fbxBool1>                 ScalingActive;

            /** This property contains scaling information of the node
            *
            * To access this property do: Scaling.Get().
            * To set this property do: Scaling.Set(fbxDouble3).
			* 
            */
            KFbxTypedProperty<fbxDouble3>               Scaling;

            /** This property contains the min scaling limit information of the node
            *
            * To access this property do: ScalingMin.Get().
            * To set this property do: ScalingMin.Set(fbxDouble3).
			* 
			* Default value is 0.,0.,0.
            */
            KFbxTypedProperty<fbxDouble3>               ScalingMin;

            /** This property contains the max scaling limit information of the node
            *
            * To access this property do: ScalingMax.Get().
            * To set this property do: ScalingMax.Set(fbxDouble3).
			* 
			* Default value is 1.,1.,1.
            */
            KFbxTypedProperty<fbxDouble3>               ScalingMax;

            /** This property contains the flag which actives the x component of min scaling limit of the node
            *
            * To access this property do: ScalingMinX.Get().
            * To set this property do: ScalingMinX.Set(fbxBool1).
			* 
			* Default value is false.
            */
            KFbxTypedProperty<fbxBool1>                 ScalingMinX;

            /** This property contains the flag which actives the y component of min scaling limit of the node
            *
            * To access this property do: ScalingMinY.Get().
            * To set this property do: ScalingMinY.Set(fbxBool1).
			* 
			* Default value is false.
            */
            KFbxTypedProperty<fbxBool1>                 ScalingMinY;

            /** This property contains the flag which actives the z component of min scaling limit of the node
            *
            * To access this property do: ScalingMinZ.Get().
            * To set this property do: ScalingMinZ.Set(fbxBool1).
			* 
			* Default value is false.
            */
            KFbxTypedProperty<fbxBool1>                 ScalingMinZ;

            /** This property contains the flag which actives the x component of max scaling limit of the node
            *
            * To access this property do: ScalingMaxX.Get().
            * To set this property do: ScalingMaxX.Set(fbxBool1).
			* 
			* Default value is false.
            */
            KFbxTypedProperty<fbxBool1>                 ScalingMaxX;

            /** This property contains the flag which actives the y component of max scaling limit of the node
            *
            * To access this property do: ScalingMaxY.Get().
            * To set this property do: ScalingMaxY.Set(fbxBool1).
			* 
			* Default value is false.
            */
            KFbxTypedProperty<fbxBool1>                 ScalingMaxY;

            /** This property contains the flag which actives the z component of max scaling limit of the node
            *
            * To access this property do: ScalingMaxZ.Get().
            * To set this property do: ScalingMaxZ.Set(fbxBool1).
			* 
			* Default value is false.
            */
            KFbxTypedProperty<fbxBool1>                 ScalingMaxZ;

			/** This property contains geometric translation information of the node
            *
            * To access this property do: GeometricTranslation.Get().
            * To set this property do: GeometricTranslation.Set(fbxDouble3).
			* 
			* Default value is 0.,0.,0.
            */
            KFbxTypedProperty<fbxDouble3>               GeometricTranslation;

			/** This property contains geometric rotation information of the node
            *
            * To access this property do: GeometricRotation.Get().
            * To set this property do: GeometricRotation.Set(fbxDouble3).
			* 
			* Default value is 0.,0.,0.
            */
            KFbxTypedProperty<fbxDouble3>               GeometricRotation;
         
			/** This property contains geometric scaling information of the node
            *
            * To access this property do: GeometricScaling.Get().
            * To set this property do: GeometricScaling.Set(fbxDouble3).
			* 
			* Default value is 1.,1.,1.
            */
            KFbxTypedProperty<fbxDouble3>               GeometricScaling;

            // Ik Settings
            //////////////////////////////////////////////////////////

            /** This property contains the x component of the minimum damp range angles of the node
            *
            * To access this property do: MinDampRangeX.Get().
            * To set this property do: MinDampRangeX.Set(fbxDouble1).
			* 
			* Default value is 0.
            */
            KFbxTypedProperty<fbxDouble1>               MinDampRangeX;

			/** This property contains the y component of the minimum damp range angles of the node
            *
            * To access this property do: MinDampRangeY.Get().
            * To set this property do: MinDampRangeY.Set(fbxDouble1).
			* 
			* Default value is 0.
            */
            KFbxTypedProperty<fbxDouble1>               MinDampRangeY;

			/** This property contains the z component of the minimum damp range angles of the node
            *
            * To access this property do: MinDampRangeZ.Get().
            * To set this property do: MinDampRangeZ.Set(fbxDouble1).
			* 
			* Default value is 0.
            */
            KFbxTypedProperty<fbxDouble1>               MinDampRangeZ;

            /** This property contains the x component of the maximum damp range angles of the node
            *
            * To access this property do: MaxDampRangeX.Get().
            * To set this property do: MaxDampRangeX.Set(fbxDouble1).
			* 
			* Default value is 0.
            */
            KFbxTypedProperty<fbxDouble1>               MaxDampRangeX;

            /** This property contains the y component of the maximum damp range angles of the node
            *
            * To access this property do: MaxDampRangeY.Get().
            * To set this property do: MaxDampRangeY.Set(fbxDouble1).
			* 
			* Default value is 0.
            */
            KFbxTypedProperty<fbxDouble1>               MaxDampRangeY;

			/** This property contains the z component of the maximum damp range angles of the node
            *
            * To access this property do: MaxDampRangeZ.Get().
            * To set this property do: MaxDampRangeZ.Set(fbxDouble1).
			* 
			* Default value is 0.
            */
            KFbxTypedProperty<fbxDouble1>               MaxDampRangeZ;

			/** This property contains the x component of the minimum damp strength of the node
            *
            * To access this property do: MinDampStrengthX.Get().
            * To set this property do: MinDampStrengthX.Set(fbxDouble1).
			* 
			* Default value is 0.
            */
            KFbxTypedProperty<fbxDouble1>               MinDampStrengthX;

            /** This property contains the y component of the minimum damp strength of the node
            *
            * To access this property do: MinDampStrengthY.Get().
            * To set this property do: MinDampStrengthY.Set(fbxDouble1).
			* 
			* Default value is 0.
            */
            KFbxTypedProperty<fbxDouble1>               MinDampStrengthY;

            /** This property contains the z component of the minimum damp strength of the node
            *
            * To access this property do: MinDampStrengthZ.Get().
            * To set this property do: MinDampStrengthZ.Set(fbxDouble1).
			* 
			* Default value is 0.
            */
            KFbxTypedProperty<fbxDouble1>               MinDampStrengthZ;

            /** This property contains the x component of the maximum damp strength of the node
            *
            * To access this property do: MaxDampStrengthX.Get().
            * To set this property do: MaxDampStrengthX.Set(fbxDouble1).
			* 
			* Default value is 0.
            */
            KFbxTypedProperty<fbxDouble1>               MaxDampStrengthX;

            /** This property contains the y component of the maximum damp strength of the node
            *
            * To access this property do: MaxDampStrengthY.Get().
            * To set this property do: MaxDampStrengthY.Set(fbxDouble1).
			* 
			* Default value is 0.
            */
            KFbxTypedProperty<fbxDouble1>               MaxDampStrengthY;

            /** This property contains the z component of the maximum damp strength of the node
            *
            * To access this property do: MaxDampStrengthZ.Get().
            * To set this property do: MaxDampStrengthZ.Set(fbxDouble1).
			* 
			* Default value is 0.
            */
            KFbxTypedProperty<fbxDouble1>               MaxDampStrengthZ;

            /** This property contains the x component of the preferred angle of the node
            *
            * To access this property do: PreferedAngleX.Get().
            * To set this property do: PreferedAngleX.Set(fbxDouble1).
			* 
			* Default value is 0.
            */
            KFbxTypedProperty<fbxDouble1>               PreferedAngleX;

            /** This property contains the y component of the preferred angle of the node
            *
            * To access this property do: PreferedAngleY.Get().
            * To set this property do: PreferedAngleY.Set(fbxDouble1).
			* 
			* Default value is 0.
            */
            KFbxTypedProperty<fbxDouble1>               PreferedAngleY;

			/** This property contains the z component of the preferred angle of the node
            *
            * To access this property do: PreferedAngleZ.Get().
            * To set this property do: PreferedAngleZ.Set(fbxDouble1).
			* 
			* Default value is 0.
            */
            KFbxTypedProperty<fbxDouble1>               PreferedAngleZ;
            ///////////////////////////////////////////////////////

            /** This property contains look at property of the node
            *
            * To access this property do: LookAtProperty.Get().
            * To set this property do: LookAtProperty.Set(fbxReference*).
			* 
            */
            KFbxTypedProperty<fbxReference*>            LookAtProperty;

			/** This property contains the up vector property of the node
            *
            * To access this property do: UpVectorProperty.Get().
            * To set this property do: UpVectorProperty.Set(fbxReference*).
			* 
            */
            KFbxTypedProperty<fbxReference*>            UpVectorProperty;

            /** This property contains show information of the node
            *
            * To access this property do: Show.Get().
            * To set this property do: Show.Set(fbxBool1).
			* 
			* Default value is true.
            */
            KFbxTypedProperty<fbxBool1>                 Show;

            /** This property contains negative percent shape support information of the node
            *
            * To access this property do: NegativePercentShapeSupport.Get().
            * To set this property do: NegativePercentShapeSupport.Set(fbxBool1).
			* 
			* Default value is true.
            */
            KFbxTypedProperty<fbxBool1>                 NegativePercentShapeSupport;

            /** This property contains default attribute index information of the node
            *
            * To access this property do: DefaultAttributeIndex.Get().
            * To set this property do: DefaultAttributeIndex.Set(fbxInteger1).
            * 
            * Default value is -1.
            */
            KFbxTypedProperty<fbxInteger1>              DefaultAttributeIndex;

            /** This property contains manipulation state information of the node
            *
            * To access this property do: Freeze.Get().
            * To set this property do: Freeze.Set(fbxBool1).
            * 
            * Default value is false.
            */
            KFbxTypedProperty<fbxBool1>              Freeze;

            /** This property contains level of detail mode information of the node
            *
            * To access this property do: LODBox.Get().
            * To set this property do: LODBox.Set(fbxBool1).
            * 
            * True: Bounding box
            * False: Geometry object is displayed.
            * Default value is false.
            */
            KFbxTypedProperty<fbxBool1>              LODBox;
        //@}


        #ifndef DOXYGEN_SHOULD_SKIP_THIS
        ///////////////////////////////////////////////////////////////////////////////
        //  WARNING!
        //  Anything beyond these lines may not be documented accurately and is
        //  subject to change without notice.
        ///////////////////////////////////////////////////////////////////////////////
        public:
            /**
              * \name Local and Global States Management
              */
            //@{

                /** Load in local state the TRS position relative to parent at a given time.
                  * \param pRecursive Flag to call the function recursively to children nodes.
                  * \param pApplyLimits true if node limits are to be applied on result
                  * \remarks TRS position relative to parent is read from default take.
                  * \remarks Has to be the DoF values
                  */
                void SetLocalStateFromDefaultTake(bool pRecursive, bool pApplyLimits = false);

                /** Store local state as a TRS position relative to parent at a given time.
                  * \param pRecursive Flag to call the function recursively to children nodes.
                  * \remarks TRS position relative to parent is written in default take.
                  */
                void SetDefaultTakeFromLocalState(bool pRecursive);

                /** Load in local state the TRS position relative to parent at a given time.
                  * \param pTime Given time to evaluate TRS position.
                  * \param pRecursive Flag to call the function recursively to children nodes.
                  * \param pApplyLimits true if node limits are to be applied on result
                  * \remarks TRS position relative to parent is read from current take.
                  */
                void SetLocalStateFromCurrentTake(KTime pTime, bool pRecursive,bool pApplyLimits = false);

                /** Store local state as a TRS position relative to parent at a given time.
                  * \param pTime Given time to store TRS position.
                  * \param pRecursive Flag to call the function recursively to children nodes.
                  * \remarks TRS position relative to parent is written in current take.
                  */
                void SetCurrentTakeFromLocalState(KTime pTime, bool pRecursive);

                /** Compute global state from local state.
                  * \param pUpdateId Update ID to avoid useless recomputing.
                  * \param pRecursive Flag to call the function recursively to children nodes.
                  * \param pApplyTarget Applies the necessary transform to align into the target node
                  * \remarks Local states of current node and all upward nodes are assumed to be valid.
                  */
                void ComputeGlobalState(kUInt pUpdateId, bool pRecursive, EPivotSet pPivotSet = eSOURCE_SET, bool pApplyTarget = false);

                /** Compute local state from global state.
                  * \param pUpdateId Update ID to avoid useless recomputing.
                  * \param pRecursive Flag to call the function recursively to children nodes.
                  * \remarks Global states of current node and all upward nodes are assumed to be valid.
                  */
                void ComputeLocalState(kUInt pUpdateId, bool pRecursive);

                /** Set global state.
                  * \param pGX TRS global position.
                  */
                void SetGlobalState(const KFbxXMatrix& pGX);

                /**  Get global state.
                  * \return The global state matrix.
                  */
                KFbxXMatrix& GetGlobalState();

                /** Set local state.
                  * \param pLX TRS position relative to parent.
                  */
                void SetLocalState(const KFbxVector4& pLT,const KFbxVector4& pLR, const KFbxVector4& pLS);

				 /** Get local state.
                  * \param pLT The transform vector of local state.
				  * \param pLR The rotation vector of local state.
				  * \param pLS The scaling vector of local state.
                  */
                void GetLocalState(KFbxVector4& pLT, KFbxVector4& pLR, KFbxVector4& pLS);

                /** Set global state ID.
                  * \param pUpdateId Update ID to avoid useless recomputing.
                  * \param pRecursive Flag to call the function recursively to children nodes.
                  */
                void SetGlobalStateId(kUInt pUpdateId, bool pRecursive);

                /** Get global state ID.
                  * \return The global state ID.
                  */
                kUInt GetGlobalStateId();

                /** Set local state ID.
                  * \param pUpdateId Update ID to avoid useless recomputing.
                  * \param pRecursive Flag to call the function recursively to children nodes.
                  */
                void SetLocalStateId(kUInt pUpdateId, bool pRecursive);

               /** Get local state ID.
                 * \return The local state ID.
                 */
                kUInt GetLocalStateId();
            //@}

			/** Get node limits.
              * \return The node limits.
              */
            KFbxNodeLimits& GetLimits();


            /** Creates a clone of this object.
            *   \param pContainer The object, typically a document or scene, that will contain the new clone. Can be NULL.
            *   \param pCloneType The type of clone to create
            *   \return The new clone, or NULL if the specified clone type is not supported.
            *   \remarks  this does not clone the node's attribute.
            */
            virtual KFbxObject* Clone(KFbxObject* pContainer, KFbxObject::ECloneType pCloneType = eDEEP_CLONE) const;

            /** Notify that a KFbxNode property has changed. 
            *   \param pType Type of property notification
            *   \param pProperty The changed property
            *   \return \c true on success, \c false otherwise.
            */
            virtual bool PropertyNotify(eFbxPropertyNotify pType, KFbxProperty* pProperty);

        protected:
            KFbxNode(KFbxSdkManager& pManager, char const* pName);
            
            virtual void Construct(const KFbxNode* pFrom);
            virtual bool ConstructProperties(bool pForceSet);
            virtual void Destruct(bool pRecursive, bool pDependents);

            //! Assignment operator.
            KFbxNode& operator=(KFbxNode const& pNode);

            void    Reset();
            bool    GetAnimationIntervalRecursive(KTime& pStart, KTime& pStop);

        public:

			/** Just add child name to the children name list.
              * \param pChildName The added child name.
              */
            void    AddChildName(char* pChildName);

			 /** According the given index,get child name from the children name list.
               * \param pIndex The given index.
			   * \return The child name.
               */
            char*   GetChildName(kUInt pIndex);

			/** Get the count of child names in the children name list.
              * \return The count of child names.
              */
            kUInt   GetChildNameCount();

            /** Set current take node by index.
              * \param pIndex The given index.
			  * \return True if set successful, otherwise false.
              */
			virtual bool SetCurrentTakeNode(int pIndex);

			/** Set current take node by name.
              * \param pIndex The given name.
			  * \return True if set successful, otherwise false.
              */
            virtual bool SetCurrentTakeNode(char* pName);

			/** Update pivots and limits from properties.
              */
            void UpdatePivotsAndLimitsFromProperties();
			
			/** Update properties from pivots and limits.
              */
            void UpdatePropertiesFromPivotsAndLimits();

			/** Set rotation active property as given value.
              * \param pVal The given value of rotation active property.
              */
            void SetRotationActiveProperty(bool pVal);

			/** Set MBTransform according the given pivot set.
              * \param pPivotSet Specify according which pivot set to set MBTransform.
              */
            void PivotSetToMBTransform(EPivotSet pPivotSet);

            KFbxXMatrix         GetLXFromLocalState( bool pT, bool pR, bool pS, bool pSoff );

			/** Get type name from the default node attribute.
              * \return The type name.
              */
            virtual KString     GetTypeName() const;

			/** Get type flags from the default node attribute.
              * \return The type flags.
              */
            virtual KStringList GetTypeFlags() const;

        protected:
            KMBTransform*       GetMBTransform();
            void                ComputeTRSLocalFromDefaultTake(bool pApplyLimits = false);
            void                ComputeTRSLocalFromCurrentTake(KTime pTime, bool pApplyLimits = false);

            // begin character related members
            int AddCharacterLink(KFbxCharacter* pCharacter, int pCharacterLinkType, int pNodeId, int pNodeSubId);
            int RemoveCharacterLink(KFbxCharacter* pCharacter, int pCharacterLinkType, int pNodeId, int pNodeSubId);
            // This class must be declared public, otherwise gcc complains on typedef below.

        private:
            KFbxNode& DeepCopy( KFbxNode const& pNode, bool pCopyNodeAttribute );

        public:
            // Unsupported parameters in the FBX SDK
            // These are declared but not accessible
            // They are used to keep imported and exported data identical
            typedef enum { eCULLING_OFF, eCULLING_ON_CCW, eCULLING_ON_CW } ECullingType;
            ECullingType                mCullingType;

            bool                        mCorrectInheritType;

        protected:
            KFbxNode_internal*          mPH;
            mutable KError              mError;

            friend class KFbxScene;
            friend class KFbxGeometry;
            friend class KFbxLight;
            friend class KFbxNodeFinderDuplicateName;
            friend class KFbxCharacter;
            friend class KFbxControlSet;
            friend class KFbxNode_internal;
            friend class KFbxSurfaceMaterial_internal;
            friend class KFbxTexture_internal;
            friend class KFbxVideo_internal;

            friend class KFbxNodeLimits;
            friend class KFbxLimits;
        #endif // #ifndef DOXYGEN_SHOULD_SKIP_THIS
    };

    typedef KFbxNode* HKFbxNode;
    typedef class KFBX_DLL KArrayTemplate<KFbxNode*> KArrayKFbxNode;

    inline EFbxType FbxTypeOf( ERotationOrder const &pItem )            { return eENUM; }
    inline EFbxType FbxTypeOf( ETransformInheritType const &pItem )     { return eENUM; }

#include <fbxfilesdk/fbxfilesdk_nsend.h>

#endif // FBXFILESDK_KFBXPLUGINS_KFBXNODE_H

