#include "particles\Singularity.Particles.h"

using namespace Singularity;
using namespace Singularity::Graphics;
using namespace Singularity::Components;

namespace Singularity
{
	namespace Particles
	{
		IMPLEMENT_OBJECT_TYPE(Singularity.Particles, BarrierEmitter, Renderer);

		#pragma region Event Methods
		void BarrierEmitter::OnComponentAdded()
		{
			RenderTask::Instantiate()->RegisterRenderer(this);
			this->m_kTimer = new Timer();

			this->Start();
		}

		void BarrierEmitter::OnComponentRemoved()
		{
			this->m_kTimer->Stop();
			RenderTask::Instantiate()->UnregisterRenderer(this);
		}

		void BarrierEmitter::OnRender(IDeviceContext* context, Camera* camera)
		{
			if(this->m_kTimer->Get_TotalTime() > this->m_fLifeTime)
				this->OnComponentRemoved();

			Material* material;
			GameObject* gameObject;
			RenderState renderState;
			renderState.Set_PrimitiveType(PrimitiveTopology::PointList);

			material = this->Get_Material();
			if(!material)
				return;

			gameObject = this->Get_GameObject();
			if(!gameObject)
				return;

			material->SetVariable("StartTime", this->m_fStartTime);
			material->SetVariable("ElapsedTime", this->m_kTimer->Get_TotalTime());

			context->SetLayer(10);
			context->SetRenderState(renderState);
			context->Draw(material, gameObject->Get_WorldTransformation().Get_TransformMatrix(), this->m_pVertices);
			this->m_kTimer->Tick();
		}
		#pragma endregion

		#pragma region Private Methods
		void BarrierEmitter::InitializeParticles()
		{
			this->m_iParticleCount = 1000;
			float randVelX, randVelY, randVelZ = 0;

			this->m_pParticles = new ParticleVertex[this->m_iParticleCount];
			for(int i = 0; i < this->m_iParticleCount; i++)
			{
				randVelX = (((float)rand()/((float)(RAND_MAX) + 1.0f)) * 2 - 1);
				randVelY = (float)rand()/((float)(RAND_MAX) + 1.0f);
				randVelZ = (((float)rand()/((float)(RAND_MAX) + 1.0f)) * 2 - 1);

				this->m_pParticles[i].position = this->Get_GameObject()->Get_WorldTransformation().Get_Position();
				this->m_pParticles[i].color = Color(1.0f, 0.0f, 0.0f, 1.0f);
				this->m_pParticles[i].velocity = Vector3(0, randVelY, 0);
				this->m_pParticles[i].acceleration = Vector3(0.0f, 0.0f, 0.0f);
				//this->m_pParticles[i].timestamp = (((float)rand()/((float)(RAND_MAX) + 1.0f)) * 2 - 1);
				this->m_pParticles[i].timestamp = 0.0f;
				this->m_pParticles[i].lifetime = 10.0f;
				this->m_pParticles[i].type = 3;
			}

			this->m_pVertices = new VertexBuffer(ParticleVertex::GetVertexDeclaration(), this->m_iParticleCount);
			this->m_pVertices->SetData(&this->m_pParticles[0]);
		}
		#pragma endregion

		#pragma region Methods
		void BarrierEmitter::Start()
		{
			this->InitializeParticles();
			this->m_kTimer->Start();
			this->m_fStartTime = this->m_kTimer->Get_TotalTime();
			this->m_fLifeTime = 10.0f;	//ten seconds
		}

		void BarrierEmitter::Reset()
		{
			this->m_kTimer->Reset();
		}
		#pragma endregion
	}
}