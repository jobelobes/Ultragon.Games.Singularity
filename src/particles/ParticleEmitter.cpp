#include "particles\Singularity.Particles.h"

using namespace Singularity;
using namespace Singularity::Graphics;
using namespace Singularity::Graphics::Devices;
using namespace Singularity::Components;

namespace Singularity
{
	namespace Particles
	{
		IMPLEMENT_OBJECT_TYPE(Singularity.Particles, ParticleEmitter, Renderer);

		#pragma region Static Variables
		Material* ParticleEmitter::g_pBasicMaterial = NULL;
		#pragma endregion

		#pragma region Constructors and Deconstructors
		ParticleEmitter::ParticleEmitter(EmitterType type, float lifeTime)
			: Renderer("") 
		{
			this->m_pVertices = NULL;
			this->m_eType = type;
			this->m_fLifeTime = lifeTime;
			//this->m_pEmitterManager = manager;

			this->m_iParticleRepeats = 1;
			this->m_iEmitterRepeats = 0;
			this->m_iParticleSize = 0.0006f;

			this->m_pMainTexture = NULL;
			this->m_pSecondaryTexture = NULL;
			this->m_pTertiaryTexture = NULL;
			
			this->m_bRandomizeColor = false;
			this->m_kColorLimit = Color(0, 0, 0, 0);
			
			this->m_kTranslation = Vector3(0, 0, 0);
			this->m_kDirection = Vector3(1, 1, 1);

			this->Set_Material(ParticleEmitter::CreateParticleMaterial());
			this->m_kTimer = new Timer();
			this->m_bReuse = false;
		}

		ParticleEmitter::ParticleEmitter(String name, EmitterType type, float lifeTime) 
		: Renderer(name)
		{
			this->m_pVertices = NULL;
			this->m_eType = type;
			this->m_fLifeTime = lifeTime;
			//this->m_pEmitterManager = manager;

			this->m_iParticleRepeats = 0;
			this->m_iEmitterRepeats = 0;
			this->m_iParticleSize = 1.0f;

			this->m_pMainTexture = NULL;
			this->m_pSecondaryTexture = NULL;
			this->m_pTertiaryTexture = NULL;
			
			this->m_bRandomizeColor = false;
			this->m_kColorLimit = Color(0, 0, 0, 0);
			
			this->m_kTranslation = Vector3(0, 0, 0);
			this->m_kDirection = Vector3(1, 1, 1);

			this->Set_Material(ParticleEmitter::CreateParticleMaterial());
			this->m_kTimer = new Timer();
			this->m_bReuse = false;
		}
		#pragma endregion

		#pragma region Event Methods
		void ParticleEmitter::OnComponentAdded(GameObject* gameObject)
		{
			RenderTask::Instantiate()->RegisterComponent(this);
			this->Start();
		}

		void ParticleEmitter::OnComponentRemoved(GameObject* gameObject)
		{
			this->m_kTimer->Stop();
			RenderTask::Instantiate()->UnregisterComponent(this);
		}

		void ParticleEmitter::OnRender(DrawingContext* context, Camera* camera)
		{
			/*if(this->m_kTimer->Get_TotalTime() > this->m_fLifeTime)
				this->OnComponentRemoved(this->Get_GameObject());*/

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

			if(!this->m_pMainTexture)
				throw SingularityException("Main texture is not set in particle emitter. Make sure to set it before proceeding");

			material->SetVariable("_MainTex", this->m_pMainTexture);

			//if the emitter requires more than one texture, we set them to the shader
			if(this->m_pSecondaryTexture)
				material->SetVariable("_SecondaryTex", this->m_pSecondaryTexture);

			if(this->m_pTertiaryTexture)
				material->SetVariable("_TertiaryTex", this->m_pTertiaryTexture);

			if(this->m_eType == EmitterType::QuadStretch)
				material->Set_Pass(1);
			else
				material->Set_Pass(0);
			
			material->SetVariable("_Repeats", this->m_iParticleRepeats);
			material->SetVariable("_StartTime", this->m_fStartTime);
			material->SetVariable("_ElapsedTime", this->m_kTimer->Get_TotalTime());
			material->SetVariable("_Orientation", this->Get_GameObject()->Get_Transform()->Get_Rotation());
			material->SetVariable("_ControlPoint", this->Get_GameObject()->Get_Transform()->Get_Position());

			context->SetLayer(98);
			context->SetRenderState(renderState);
			context->Draw(camera, material, gameObject->Get_Transform()->Get_LocalToWorldMatrix(), this->m_pVertices);
			this->m_kTimer->Tick();

			//if there are repeats 
			if(this->m_iEmitterRepeats != 0 && this->m_kTimer->Get_TotalTime() > this->m_fLifeTime)
			{
				this->Reset();
				if(this->m_iEmitterRepeats > 0)
					this->m_iEmitterRepeats--;
			}
			
		}
		#pragma endregion

		#pragma region Private Methods
		void ParticleEmitter::InitializeParticles()
		{
			if(!this->m_pMainTexture)
				throw SingularityException("Particle emitters require at the very least a main texture to render.");

			if(this->m_fLifeTime == NULL)
				throw SingularityException("Particle emitter requires a radius to stretch to. Make sure to set it before adding to game object.");
			
			switch(this->m_eType)
			{
				case EmitterType::Explosion :
					if(this->m_fRadius <= 0)
						throw SingularityException("Explosion Particle Emitter requires a maximum radius greater than 0 in order to function.");

					if(!this->m_pSecondaryTexture)
						throw SingularityException("Explosion Particle Emitter requires a secondary texture in order to function. Load a secondary texture before proceeding.");

					if(this->m_bRandomizeColor && this->m_kColorLimit.a <= 0.0f)
						throw SingularityException("A color limit must be set if you wish to randomize colors for the particle emitter.");

					if(this->m_iParticleCount <= 0)
						this->m_iParticleCount = 50;

					this->m_pParticles = new ParticleVertex[this->m_iParticleCount];
					this->InitializeExplosion();
					break;
				case EmitterType::Directional :
					if(this->m_iParticleCount <= 0)
						this->m_iParticleCount = 500;

					this->m_pParticles = new ParticleVertex[this->m_iParticleCount];
					this->InitializeDirectional();
					break;
				case EmitterType::Linear :
					if(this->m_iParticleCount <= 0)
						this->m_iParticleCount = 500;

					this->m_pParticles = new ParticleVertex[this->m_iParticleCount];
					this->InitializeLinear();
					break;
				case EmitterType::Fountain :
					if(this->m_iParticleCount <= 0)
						this->m_iParticleCount = 500;

					this->m_pParticles = new ParticleVertex[this->m_iParticleCount];
					this->InitializeFountain();
					break;
				case EmitterType::Orbital :
					if(this->m_iParticleCount <= 0)
						this->m_iParticleCount = 10;

					this->m_pParticles = new ParticleVertex[this->m_iParticleCount];
					this->InitializeOrbital();
					break;
				case EmitterType::Spiral :
					if(this->m_iParticleCount <= 0)
						this->m_iParticleCount = 500;

					this->m_pParticles = new ParticleVertex[this->m_iParticleCount];
					this->InitializeSpiral();
					break;
				case EmitterType::Sphere :
					if(this->m_iParticleCount <= 0)
						this->m_iParticleCount = 500;

					this->m_pParticles = new ParticleVertex[this->m_iParticleCount];
					this->InitializeSphere();
					break;
				case EmitterType::Radial :
					if(this->m_fRadius <= 0)
						throw SingularityException("Radial Emitter requires that the radius be set greater than 0 in order to function properly.");

					if(this->m_iParticleCount <= 0)
						this->m_iParticleCount = 500;

					this->m_pParticles = new ParticleVertex[this->m_iParticleCount];
					this->InitializeRadial();
					break;
				case EmitterType::QuadStretch :
					if(this->m_fRadius <= 0)
						throw SingularityException("Quad Stretch Emitter requires that the radius be set greater than 0 in order to function properly.");

					if(this->m_iParticleCount <= 0)
						this->m_iParticleCount = 1;

					this->m_pParticles = new ParticleVertex[this->m_iParticleCount];
					this->InitializeQuadStretch();
					break;
			}

			if(this->m_fDelay > 0)
				for(int i = 0; i < this->m_iParticleCount;i++)
					this->m_pParticles[i].timestamp += this->m_fDelay;

			//if this run through is the first time the emitter has been used, then we need to create a new vertex buffer
			if(!this->m_bReuse)
				// MAJOR PROBLEM: once we're greater than 256, we crash...as long as it's not the first VertexBuffer we make here. (wtf?)
				this->m_pVertices = new VertexBuffer(ParticleVertex::GetVertexDeclaration(), this->m_iParticleCount);

			this->m_pVertices->SetData(&this->m_pParticles[0]);
			
		}
		#pragma endregion

		#pragma region Methods
		void ParticleEmitter::Start()
		{
			this->InitializeParticles();
			this->m_kTimer->Start();
			this->m_fStartTime = this->m_kTimer->Get_TotalTime();
		}

		void ParticleEmitter::Stop()
		{
			if(!this->m_bReuse)
				this->m_bReuse = true;
		}

		void ParticleEmitter::Reset()
		{
			this->m_kTimer->Reset();
			this->Start();
		}
		#pragma endregion

		#pragma region Static Methods
		Material* ParticleEmitter::CreateParticleMaterial()
		{
			HRSRC src;
			HANDLE bytes;
			String basicmaterial;
			char id[5];

			if(ParticleEmitter::g_pBasicMaterial == NULL)
			{
				id[0] = '#';
				_itoa_s(IDR_PARTICLE_EFFECT1, &id[1], 4, 10);
				src = ::FindResource(NULL, id, "PARTICLE_EFFECT");
				bytes = ::LoadResource(NULL, src);
				basicmaterial = String((char*)::LockResource(bytes), ::SizeofResource(NULL, src));
				ParticleEmitter::g_pBasicMaterial = Singularity::Graphics::Material::LoadMaterialFromMemory(String("BasicParticleMaterial"),  basicmaterial);
				::FreeResource(bytes);
				return ParticleEmitter::g_pBasicMaterial;
			}

			return ParticleEmitter::g_pBasicMaterial->Clone();
		}
		#pragma endregion
	}
}