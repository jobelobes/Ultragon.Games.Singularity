#include "particles\Singularity.Particles.h"

namespace Singularity
{
	namespace Particles
	{
		class ParticleSubTask : public Singularity::Graphics::RenderExtension
		{
			DECLARE_OBJECT_TYPE;

			private:
				#pragma region Variables
				ParticleState*		m_pState;
				unsigned			m_iStart;
				unsigned			m_iEnd;
				#pragma endregion

			protected:
				#pragma region Event Methods
				virtual void OnRenderExecute(Singularity::Graphics::GraphicsDevice* device);
				#pragma endregion

			public:
				#pragma region Constructors and Deconstructors
				ParticleSubTask();
				~ParticleSubTask();
				#pragma endregion

				#pragma region Methods
				void Update(ParticleState* state, unsigned start, unsigned end);
				#pragma endregion
		};
	}
}