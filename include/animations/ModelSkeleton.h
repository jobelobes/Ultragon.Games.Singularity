#include "animations\Singularity.Animations.h"

namespace Singularity
{
	namespace Graphics
	{
		class ModelSkeleton
		{
			private:	
				#pragma region Variables
				ModelBone*		m_pRootBone;
				ModelBone**		m_pSkeleton;
				int				m_iSkeletonHierarchy;		//list of bone's parent bone
				unsigned		m_iBoneCount;

				Matrix*			m_pBoneTransforms;
				Matrix*			m_pWorldTransforms;
				Matrix*			m_pSkinTransforms;
				#pragma endregion

			public:
				#pragma region Constructors and Finalizers
				ModelSkeleton() : m_iBoneCount(3) { }
				ModelSkeleton(int boneCount) : m_iBoneCount(boneCount) { }
				~ModelSkeleton() {}
				#pragma endregion

				#pragma region Methods
				void InitializeSkeleton();

				//Resets the skeleton back to its bone's original bind poses
				inline void ResetSkeleton()
				{
					for(unsigned i = 0; i < this->m_iBoneCount; i++)
						this->m_pBoneTransforms[i] = this->m_pSkeleton[i]->Get_BindPose();
				}

				inline void SetBoneTransform(Matrix value, int index) { this->m_pBoneTransforms[index] = value; }
				void UpdateWorldSkinTransforms(Matrix rootTransform);
				#pragma region

		};
	}
}