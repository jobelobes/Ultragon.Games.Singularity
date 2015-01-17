#include "animations\Singularity.Animations.h"

namespace Singularity
{
	namespace Animations
	{
		class AnimationClip
		{
			private:
				#pragma region Variables
				float						m_fDuration;
				DynamicList<Frame>			m_pFrames;
				String						m_sName;
				#pragma endregion

			public:
				#pragma region Constructors and Deconstructors
				AnimationClip(String name = "") : m_sName(name), m_fDuration(0.0f) { }
				#pragma endregion

				#pragma region Properties
				float Get_Duration() const;
				void Set_Duration(float value);

				DynamicList<Frame> Get_Frames();

				unsigned Get_FrameCount() const;

				String Get_Name() const;
				#pragma endregion

				#pragma region Methods
				void AddKeyframe(Frame value);
				#pragma endregion
		};

		#include "animations\AnimationClip.inc"
	}
}