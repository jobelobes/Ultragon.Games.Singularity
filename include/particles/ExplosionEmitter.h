#include "particles\Singularity.Particles.h"

using namespace Singularity;
using namespace Singularity::Graphics;
using namespace Singularity::Components;

namespace Singularity
{
	namespace Particles
	{
		class ExplosionEmitter : public Singularity::Graphics::Renderer
		{
			DECLARE_OBJECT_TYPE;

			private:
				#pragma region Variables
				int											m_iParticleCount;
				float										m_fLifeTime;
				float										m_fStartTime;

				Singularity::Graphics::VertexBuffer*		m_pVertices;
				Singularity::Particles::ParticleVertex*		m_pParticles;
				Singularity::Timer*							m_kTimer;
				
				#pragma endregion

				#pragma region Methods
				void InitializeParticles();
				#pragma endregion

			protected:
				#pragma region Event Methods
				virtual void OnComponentAdded();
				virtual void OnComponentRemoved();
				virtual void OnRender(Singularity::Graphics::IDeviceContext* context, Singularity::Graphics::Camera* camera);
				#pragma endregion

			public:
				#pragma region Constructors and Deconstructors
				ExplosionEmitter(Singularity::Graphics::Material* material = NULL) : Renderer(material), m_pVertices(NULL), m_fStartTime(0.0f) { };
				ExplosionEmitter(String name, Singularity::Graphics::Material* material = NULL) : Renderer(name, material),  m_pVertices(NULL), m_fStartTime(0.0f) { };
				~ExplosionEmitter() { };
				#pragma endregion

				#pragma region Methods
				void Start();
				void Reset();
				#pragma endregion
		};
	}
}