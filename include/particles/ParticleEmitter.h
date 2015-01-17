#include "particles\Singularity.Particles.h"

namespace Singularity
{
	namespace Particles
	{
		enum EmitterType {	Explosion = 0, 
							Directional = 1, 
							Linear = 2, 
							Fountain = 3,  
							Orbital = 4,
							Spiral = 5,
							Sphere = 6,
							Radial = 7,
							QuadStretch = 8};

		class ParticleEmitter : public Singularity::Graphics::Renderer
		{
			DECLARE_OBJECT_TYPE;

			private:
				#pragma region Static Variables
				static Singularity::Graphics::Material*		g_pBasicMaterial;
				#pragma endregion

				#pragma region Variables
				int											m_iParticleCount;
				int											m_iEmitterRepeats;
				int											m_iParticleRepeats;
				
				float										m_iParticleSize;
				float										m_fLifeTime;
				float										m_fStartTime;
				float										m_fRadius;
				float										m_fRadius2;
				float										m_fDelay;
				
				bool										m_bRandomizeColor;

				Vector3										m_kDirection;
				Vector3										m_kDimensions;
				Vector3										m_kTranslation;
				Color										m_kColorLimit;

				Singularity::Graphics::VertexBuffer*		m_pVertices;
				Singularity::Particles::ParticleVertex*		m_pParticles;

				Singularity::Graphics::Texture2D*			m_pMainTexture;
				Singularity::Graphics::Texture2D*			m_pSecondaryTexture;
				Singularity::Graphics::Texture2D*			m_pTertiaryTexture;

				Singularity::Timer*							m_kTimer;

				EmitterType									m_eType;
				bool										m_bReuse;

				//Singularity::Particles::EmitterManager*		m_pEmitterManager;
				#pragma endregion

				#pragma region Methods
				void InitializeParticles();
				#pragma endregion

				#pragma region Static Methods
				//Emitter functions
				void InitializeDirectional();
				void InitializeLinear();
				void InitializeFountain();
				void InitializeOrbital();
				void InitializeSpiral();
				void InitializeSphere();
				void InitializeExplosion();
				void InitializeRadial();
				void InitializeQuadStretch();

				//position functions
				static Vector3 RandomPositionByDistance(Vector3 origin, Vector3 ceiling);
				
				//velocity functions
				static Vector3 RandomRadialVelocity(Vector3 ceiling);
				static Vector3 RandomRadialPosition(bool xAxis, bool yAxis, bool zAxis, Vector3 position, float radius);
				static Vector3 RandomDirectionalVelocity(bool xAxis, bool yAxis, bool zAxis, Vector3 ceiling);
				static Vector3 PositionAlongSphere(bool xAxis, bool yAxis, bool zAxis, Vector3 position, float radius);
				static Color RandomColor(Color colorLimit);
				#pragma endregion

			protected:
				#pragma region Event Methods
				virtual void OnComponentAdded(Singularity::Components::GameObject* gameObject);
				virtual void OnComponentRemoved(Singularity::Components::GameObject* gameObject);
				virtual void OnRender(DrawingContext* context, Singularity::Graphics::Camera* camera);
				#pragma endregion

			public:
				#pragma region Constructors and Deconstructors
				ParticleEmitter(EmitterType type, float lifeTime);
				ParticleEmitter(String name, EmitterType type, float lifeTime);
				#pragma endregion

				#pragma region Properties
				void Set_LifeTime(float lifeTime);

				void Set_MainTexture(Singularity::Graphics::Texture2D* value);
				void Set_SecondaryTexture(Singularity::Graphics::Texture2D* value);
				void Set_TertiaryTexture(Singularity::Graphics::Texture2D* value);

				void Set_ParticleCount(int value);
				void Set_PositionOffset(Vector3 offset);

				void Set_Radius(float value);
				void Set_Radius2(float value);
				void Set_EmitterRepeats(int value);
				void Set_ParticleRepeats(int value);
				void Set_ParticleSize(float value);
				
				void Set_Dimensions(Vector3 value);
				void Set_Direction(Vector3 value);
				
				void Set_Delay(float value);
				
				void Set_RandomizeColor(bool value);
				void Set_ColorLimit(Color value);

				EmitterType Get_EmitterType();
				void Set_EmitterType(const EmitterType value);
				#pragma endregion


				#pragma region Methods
				//Starts the particle emitter once its been added to the game object's component list. Goes through all initialization needed
				void Start();
				void Stop();
				void Reset();
				#pragma endregion

				#pragma region Static Methods
				Material* CreateParticleMaterial();
				#pragma endregion
		};

		#include "particles\ParticleEmitter.inc"
		
	}
}