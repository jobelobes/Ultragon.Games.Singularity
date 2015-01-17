#include "particles\Singularity.Particles.h"

namespace Singularity
{
	namespace Particles
	{
		class InverseGravityEmitter : public Singularity::Graphics::Renderer
		{
			DECLARE_OBJECT_TYPE;

			private:
				#pragma region Variables
				int										m_iParticleCount;
				float									m_fLifeTime;
				float									m_fStartTime;

				Singularity::Graphics::VertexBuffer*	m_pVertices;
				Singularity::Particles::ParticleVertex*	m_pParticles;

				Singularity::Timer*						m_kTimer;
				#pragma endregion

				#pragma region Methods
				void InitializeParticles();
				#pragma endregion

			protected:
				#pragma region Event Methods
				virtual void OnComponentAdded();
				virtual void OnComponentRemoved();
				virtual void OnRender(Singularity::Graphics::IDeviceContext* contect, Singularity::Graphics::Camera* camera);
				#pragma endregion

			public:
				#pragma region Constructors and Deconstructors
				InverseGravityEmitter(Singularity::Graphics::Material* material = NULL) : Renderer(material), m_pVertices(NULL), m_fStartTime(0.0f) { };
				InverseGravityEmitter(String name, Singularity::Graphics::Material* material = NULL) : Renderer(name, material),  m_pVertices(NULL), m_fStartTime(0.0f) { };
				~InverseGravityEmitter() { };
				#pragma endregion

				#pragma region Methods
				void Start();
				void Reset();
				#pragma endregion
		};
	}
}