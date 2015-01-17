#include "animations\Singularity.Animations.h"

namespace Singularity
{
	namespace Animations
	{
		//typedef void (*AnimationCallback)(Animation* sender, const AnimationState* state);

		class Animation : public Singularity::Components::Component
		{
			DECLARE_OBJECT_TYPE;

			private:
				#pragma region Variables
				Singularity::Animations::AnimationClip*	m_pClip;

				Singularity::Graphics::SkinnedMesh*		m_pMesh;
				Singularity::Timer*						m_pTimer;

				unsigned								m_iClipIndex;
				unsigned								m_iCurrentFrame;
				unsigned								m_iFrameStart;
				unsigned								m_iFramePlayCount;
				float									m_fFrameTimer;
				
				bool									m_bRepeatPlayback;
				bool									m_bIsAnimating;
				#pragma endregion

			protected:
				#pragma region Event Methods
				virtual void OnStep(const AnimationState* state, float elapsedTime);
				#pragma endregion

				#pragma region Overriden Methods
				virtual void OnComponentAdded(Singularity::Components::GameObject* gameObject);
				virtual void OnComponentRemoved(Singularity::Components::GameObject* gameObject);
				#pragma endregion

			public:
				#pragma region Constructors and Finalizers
				Animation(String name = "") : Singularity::Components::Component(name){ }
				~Animation() { }
				#pragma endregion

				#pragma region Properties
				Singularity::Animations::AnimationClip* Get_Clip();

				Singularity::Graphics::SkinnedMesh* Get_Mesh();
				void Set_Mesh(Singularity::Graphics::SkinnedMesh* mesh);
				#pragma endregion

				#pragma region Methods			
				void PlayClip(unsigned start, unsigned count, bool repeat);
				
				void UpdateAnimation(float elapsedTime);

				void SetClip(Singularity::Animations::AnimationClip* value);
				#pragma endregion

				friend class AnimationSubTask;
		};
	}
}