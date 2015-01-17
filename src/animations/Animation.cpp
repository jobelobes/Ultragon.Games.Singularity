#include "animations\Singularity.Animations.h"

namespace Singularity
{
	namespace Animations
	{
		IMPLEMENT_OBJECT_TYPE(Singularity.Animations, Animation, Singularity::Components::Component);
		
		#pragma region Event Methods
		void Animation::OnStep(const AnimationState* state, float elapsedTime)
		{
			//if(this->m_pCallback != NULL)
			//	this->m_pCallback(this, state);

			//if(this->m_bIsAnimating)
				this->UpdateAnimation(elapsedTime);			
		}
		#pragma endregion

		#pragma region Properties
		AnimationClip* Animation::Get_Clip()
		{ 
			return this->m_pClip; 
		}

		SkinnedMesh* Animation::Get_Mesh()
		{
			return this->m_pMesh;
		}

		void Animation::Set_Mesh(SkinnedMesh* value)
		{
			this->m_pMesh = value;
		}
		#pragma endregion

		#pragma region Overriden Methods
		void Animation::OnComponentAdded(GameObject* gameObject)
		{
			AnimationTask::Instantiate()->RegisterAnimation(this);
			this->m_pTimer = new Timer();

			//temp
			this->m_iCurrentFrame = 0;
			this->m_fFrameTimer = 0.0f;
		}

		void Animation::OnComponentRemoved(GameObject* gameObject)
		{
			AnimationTask::Instantiate()->UnregisterAnimation(this);
		}
		#pragma endregion

		#pragma region Methods
		void Animation::SetClip(AnimationClip* value)
		{ 
			this->m_pClip = value; 
		}

		void Animation::PlayClip(unsigned start, unsigned count, bool repeat)
		{
			this->m_iFrameStart = start;
			this->m_iFramePlayCount = count;
			this->m_iCurrentFrame = start;
			this->m_fFrameTimer = 0.0;
			
			this->m_bRepeatPlayback = repeat;
		}

		void Animation::UpdateAnimation(float elapsedTime)
		{		
			if(this->m_pClip == NULL)
				throw SingularityException("Animation : the clip you tried to update is null");	

			this->m_fFrameTimer += elapsedTime;			
			this->m_iFramePlayCount = 800; // TEMP
			float frameDuration = 1.0f / 1.0f; // TEMP
			
			DynamicList<Frame> frames = this->m_pClip->Get_Frames(); // slow
			if(this->m_fFrameTimer > frameDuration)
			{				
				Frame frame = frames[this->m_iCurrentFrame];
				unsigned keyframeCount = frame.Keyframes.size();

				if(keyframeCount > 0 && m_iFramePlayCount > 0)
				{										
					for(unsigned keyframeIndex = 0; keyframeIndex < keyframeCount; ++keyframeIndex)
					{		
						this->m_pMesh->UpdateLocalTransform(frame.Keyframes[keyframeIndex].JointIndex, 
															frame.Keyframes[keyframeIndex].Translation, 
															frame.Keyframes[keyframeIndex].Scale, 
															frame.Keyframes[keyframeIndex].Rotation );
					}	

					this->m_pMesh->UpdateWorldTransforms();
					this->m_pMesh->UpdateSkinTransforms();

					this->m_fFrameTimer = 0.0f;			
					this->m_iCurrentFrame = (this->m_iCurrentFrame + 1) % this->m_iFramePlayCount;
				}
			}	
		}		
		#pragma endregion
	}
}