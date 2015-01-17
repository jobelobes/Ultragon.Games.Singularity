#include "animations\Singularity.Animations.h"

namespace Singularity
{
	namespace Graphics
	{
		#pragma region Constructors and Finalizers
		void ModelSkeleton::InitializeSkeleton()
		{
			this->m_pSkeleton = new ModelBone*[this->m_iBoneCount];

			this->m_pBoneTransforms = new Matrix[this->m_iBoneCount];
			this->m_pWorldTransforms = new Matrix[this->m_iBoneCount];
			this->m_pSkinTransforms = new Matrix[this->m_iBoneCount];
		}
		#pragma endregion

		#pragma region Methods
		void ModelSkeleton::UpdateWorldSkinTransforms(Matrix rootTransform)
		{
			unsigned i = 0;
			Matrix output;

			//Updating the root bone before everything else

			//multiplying the root node by the root matrix passed in
			output = this->m_pRootBone->Get_BindPose() * rootTransform;
			this->m_pWorldTransforms[0] = output;

			//Updating the skin transform
			output = this->m_pSkeleton[i]->Get_InvBindPose() * this->m_pWorldTransforms[i];
			this->m_pSkinTransforms[i] = output;
			//update the bone transforms
			for(i = 1; i < this->m_iBoneCount; i++)
			{	
				//retrieve the parent's bone transform and multiply it by the current bone's transform
				output = this->m_pSkeleton[i]->Get_BindPose() * rootTransform;
				this->m_pWorldTransforms[i] = output;

				output = this->m_pSkeleton[i]->Get_InvBindPose() * this->m_pWorldTransforms[i];
				this->m_pSkinTransforms[i] = output;
			}
		}
		#pragma endregion
	}
}