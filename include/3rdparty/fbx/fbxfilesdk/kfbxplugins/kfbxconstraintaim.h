/*!  \file kfbxconstraintaim.h
 */

#ifndef FBXFILESDK_KFBXPLUGINS_KFBXCONSTRAINTAIM_H
#define FBXFILESDK_KFBXPLUGINS_KFBXCONSTRAINTAIM_H

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

#include <fbxfilesdk/kfbxplugins/kfbxconstraint.h>
#include <fbxfilesdk/kfbxplugins/kfbxgroupname.h>
#include <fbxfilesdk/kfbxmath/kfbxvector4.h>

#include <fbxfilesdk/components/kbaselib/klib/kerror.h>

#include <fbxfilesdk/fbxfilesdk_nsbegin.h>

class KFbxSdkManager;

/** \brief This constraint class contains methods for accessing the properties of an aim constraint.
  * A aim constraint lets you constrain an object based on the properties of one or more aim objects.
  * \nosubgrouping
  */
class KFBX_DLL KFbxConstraintAim : public KFbxConstraint
{
    KFBXOBJECT_DECLARE(KFbxConstraintAim,KFbxConstraint);

    /**
      * \name Properties
      */
    //@{
        /** This property handles the lock state.
          *
          * Default value is false.
          */
        KFbxTypedProperty<fbxBool1>        Lock;
			KFbxTypedProperty<fbxBool1>		Active;

			KFbxTypedProperty<fbxDouble1>	Weight;
        KFbxTypedProperty<fbxDouble3>    RotationOffset;

        /** This property handles the aim at objects.
          */
        KFbxTypedProperty<fbxReference> AimAtObjects;

        /** This property handles constrainted object.
          */
        KFbxTypedProperty<fbxReference> ConstrainedObject;

        /** This property handles world up type.
          */
        KFbxTypedProperty<fbxEnum>        WorldUpType;

        /** This property handles world up object.
          */
        KFbxTypedProperty<fbxReference> WorldUpObject;

        /** This property handles world up vector.
          *
          * Default value is (0, 1, 0).
          */
        KFbxTypedProperty<fbxDouble3>    WorldUpVector;

        /** This property handles up vector.
          *
          * Default value is (0, 1, 0).
          */
        KFbxTypedProperty<fbxDouble3>    UpVector;

        /** This property handles aim vector.
          *
          * Default value is (1, 0, 0).
          */
        KFbxTypedProperty<fbxDouble3>    AimVector;
        
        /** This property handles whether to affect x axis.
          *
          * Default value is true.
          */
        KFbxTypedProperty<fbxBool1>        AffectX;

        /** This property handles whether to affect y axis.
          *
          * Default value is true.
          */
        KFbxTypedProperty<fbxBool1>        AffectY;

        /** This property handles whether to affect z axis.
          *
          * Default value is true.
          */
        KFbxTypedProperty<fbxBool1>        AffectZ;
    //@}
    

public:
    /** \enum EAimConstraintWoldUpType  Contraint world up type.
      * -  \e eAimAtSceneUp
      * -  \e eAimAtObjectUp
      * -  \e eAimAtObjectRotationUp
      * -  \e eAimAtVector
      * -  \e eAimAtNone
      * -  \e eAimAtCount
      */
    typedef enum 
    {
        eAimAtSceneUp,
        eAimAtObjectUp,
        eAimAtObjectRotationUp,
        eAimAtVector,
        eAimAtNone,
        eAimAtCount
    } EAimConstraintWoldUpType;

    /** Set the constraint lock.
      * \param pLock State of the lock flag.
      */
    inline void SetLock(bool pLock) { Lock.Set(pLock); }

    /** Retrieve the constraint lock state.
      * \return Current lock flag.
      */
    inline bool GetLock()            { return Lock.Get(); }

		/** Set the constraint active.
		  * \param pActive State of the active flag.
		  */
		inline void SetActive(bool pActive) { Active.Set(pActive); }

		/** Retrieve the constraint active state.
		  * \return Current active flag.
		  */
		inline bool GetActive() { return Active.Get(); }

    /** Set the weight of the constraint.
      * \param pWeight New weight value.
      */
    void SetWeight(double pWeight);

    /** Set the rotation offset.
      * \param pRotation New offset vector.
      */
    virtual void SetOffset(KFbxVector4 pRotation);

    /** Retrieve the constraint rotation offset.
      * \return Current rotation offset.
      */
		KFbxVector4 GetOffset();

    /** Get the weight of a source.
      * \param pObject Source object.
      */
		double GetSourceWeight(KFbxObject* pObject);

    /** Add a source to the constraint.
      * \param pObject New source object.
      * \param pWeight Weight of the source object.
      */
    void AddConstraintSource(KFbxObject* pObject, double pWeight = 100);

    /** Retrieve the constraint source count.
      * \return Current constraint source count.
      */
		int GetConstraintSourceCount();

    /** Retrieve a constraint source object.
      * \param pIndex The specified index.
      * \return Current source at the specified index.
      */
		KFbxObject* GetConstraintSource(int pIndex);

		/** Set the constrained object.
      * \param pObject The constrained object.
      */
    void SetConstrainedObject(KFbxObject* pObject);

		/** Retrieve the constrained object.
      * \return Current constrained object.
      */
    KFbxObject* GetConstrainedObject();

    /** Set the world up type.
      * \param pType The world up type.
      */
    void SetWorldUpType(EAimConstraintWoldUpType pType);

    /** Retrieve the world up type.
      * \return Current world up type.
      */
		EAimConstraintWoldUpType GetWorldUpType();

    /** Set the world up object.
      * \param pObject The world up object.
      */
    void SetWorldUpObject(KFbxObject* pObject);

    /** Retrieve the world up object.
      * \return Current world up object.
      */
		KFbxObject* GetWorldUpObject();

    /** Set the world up vector.
      * \param pVector The world up vector.
      */
    void SetWorldUpVector(KFbxVector4 pVector);

    /** Retrieve the world up vector.
      * \return Current world up vector.
      */
		KFbxVector4 GetWorldUpVector();

    /** Set the up vector.
      * \param pVector The up vector.
      */
    void SetUpVector(KFbxVector4 pVector);

    /** Retrieve the up vector.
      * \return Current up vector.
      */
		KFbxVector4 GetUpVector();

    /** Set the aim vector.
      * \param pVector The up vector.
      */
    void SetAimVector(KFbxVector4 pVector);

    /** Retrieve the aim vector.
      * \return Current up vector.
      */
		KFbxVector4 GetAimVector();

		/** Set the constraint X-axis effectiveness.
		  * \param pAffect State of the effectiveness on the X axis.
      */
    inline void SetAffectX(bool pAffect) { AffectX.Set(pAffect); }

		/** Retrieve the constraint X-axis effectiveness.
      * \return Current state flag.
      */
    inline bool GetAffectX() { return AffectX.Get(); }

		/** Set the constraint Y-axis effectiveness.
		  * \param pAffect State of the effectiveness on the X axis.
      */
    inline void SetAffectY(bool pAffect){ AffectY.Set(pAffect); }

		/** Retrieve the constraint Y-axis effectiveness.
      * \return Current state flag.
      */
		inline bool GetAffectY() { return AffectY.Get(); }

		/** Set the constraint Z-axis effectiveness.
		  * \param pAffect State of the effectiveness on the X axis.
      */
    inline void SetAffectZ(bool pAffect) { AffectZ.Set(pAffect); }

		/** Retrieve the constraint Z-axis effectiveness.
      * \return Current state flag.
      */
		inline bool GetAffectZ() { return AffectZ.Get(); }

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    // Clone
virtual KFbxObject* Clone(KFbxObject* pContainer, KFbxObject::ECloneType pCloneType) const;

protected:

    KFbxConstraintAim(KFbxSdkManager& pManager, char const* pName);

    virtual bool ConstructProperties(bool pForceSet);

    virtual EConstraintType GetConstraintType();
    virtual    KString    GetTypeName() const;
#endif // #ifndef DOXYGEN_SHOULD_SKIP_THIS
};

inline EFbxType FbxTypeOf( KFbxConstraintAim::EAimConstraintWoldUpType const &pItem )                { return eENUM; }

#include <fbxfilesdk/fbxfilesdk_nsend.h>

#endif // FBXFILESDK_KFBXPLUGINS_KFBXCONSTRAINTAIM_H

