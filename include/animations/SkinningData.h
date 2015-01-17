#include "Singularity.Animations.h"

namespace Singularity
{
	namespace Animations
	{
		class SkinningData
		{
			public:
				#pragma region Variables
				DynamicList<AnimationClip*>		AnimationClips;
				DynamicList<Matrix*>			BindPose;
				DynamicList<Matrix*>			InverseBindPose;
				int*							SkeletonHierarchy;
				int								BoneCount;
				#pragma endregion

				#pragma region Properties
				AnimationClip* Get_AnimationClip(String Name)
				{
					for(unsigned i = 0; i < AnimationClips.size(); i++)
						if(AnimationClips[i]->Get_Name() == Name)
							return AnimationClips[i];

					return NULL;
				}
				#pragma endregion

				#pragma region Constructors and Finalizers
				SkinningData(DynamicList<AnimationClip*> clips, DynamicList<Matrix*> bindPose, DynamicList<Matrix*> inverseBindPose, int* hierarchy, int boneCount)
					: AnimationClips(clips), BindPose(bindPose), InverseBindPose(inverseBindPose), SkeletonHierarchy(hierarchy), BoneCount(boneCount) { }
				~SkinningData() {}
				#pragma endregion
		};
	}
}