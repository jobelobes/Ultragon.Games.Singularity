#include "particles\Singularity.Particles.h"

using namespace Singularity;
using namespace Singularity::Components;

namespace Singularity
{
	namespace Particles
	{
		#pragma region Emitter Initialization Functions
		void ParticleEmitter::InitializeExplosion()
		{
			Transform* transform = this->Get_GameObject()->Get_Transform();
			Vector3 position = transform->Get_Position();

			if(abs(this->m_kTranslation.x) > 0 || abs(this->m_kTranslation.y) > 0 || abs(this->m_kTranslation.z) > 0)
				position += this->m_kTranslation;

			float randVal;

			for(int i = 0; i < this->m_iParticleCount; i++)
			{
				randVal = (float)rand()/(float)(RAND_MAX);

				this->m_pParticles[i].position = position;
				this->m_pParticles[i].color = Color(randVal, 0.0f, 0.0f, 1.0f);	//in this instance, color is being used to determine a random switch point between the fire and smoke textures
				this->m_pParticles[i].velocity = ParticleEmitter::RandomRadialVelocity(this->m_kDirection); //using direction to calculate how far the particles will travel
				this->m_pParticles[i].acceleration = Vector3(0.0f, 0.0f, 0.0f);
				this->m_pParticles[i].size = this->m_iParticleSize;
				this->m_pParticles[i].timestamp = (float)rand()/(float)(RAND_MAX) * this->m_fLifeTime;
				this->m_pParticles[i].lifetime = this->m_fLifeTime;
				this->m_pParticles[i].rotation = ((float)rand() / (float)(RAND_MAX)) * 2 - 1;	//getting a random rotation speed between -1 and 1
				this->m_pParticles[i].type = EmitterType::Explosion;
			}
		}

		void ParticleEmitter::InitializeDirectional()
		{
			Transform* transform = this->Get_GameObject()->Get_Transform();
			Vector3 position = transform->Get_Position();

			if(abs(this->m_kTranslation.x) > 0 || abs(this->m_kTranslation.y) > 0 || abs(this->m_kTranslation.z) > 0)
				position += this->m_kTranslation;

			for(int i = 0; i < this->m_iParticleCount; i++)
			{
				this->m_pParticles[i].position = position;
				if(this->m_bRandomizeColor)
					this->m_pParticles[i].color = ParticleEmitter::RandomColor(this->m_kColorLimit);
				else
					this->m_pParticles[i].color = Color(0.0f, 0.0f, 0.0f, 0.0f);
				this->m_pParticles[i].velocity = ParticleEmitter::RandomDirectionalVelocity(false, true, false, this->m_kDirection);
				this->m_pParticles[i].acceleration = Vector3(0.0f, 0.0f, 0.0f);
				this->m_pParticles[i].size = this->m_iParticleSize;
				this->m_pParticles[i].timestamp = (float)rand()/(float)(RAND_MAX) * this->m_fLifeTime;
				this->m_pParticles[i].lifetime = this->m_fLifeTime;
				this->m_pParticles[i].type = EmitterType::Directional;
			}
		}

		void ParticleEmitter::InitializeLinear()
		{
			//if(this->m_kDimensions == NULL)
			//	throw SingularityException("dimensions for the linear emitter must be set prior to initializing a linear particle emitter");

			Transform* transform = this->Get_GameObject()->Get_Transform();

			Vector3 position = transform->Get_Position();

			if(abs(this->m_kTranslation.x) > 0 || abs(this->m_kTranslation.y) > 0 || abs(this->m_kTranslation.z) > 0)
				position += this->m_kTranslation;

			Matrix particleTranslation, particleRotation, particleWorld;
			Vector3 translation, velocity;

			particleRotation = Matrix(transform->Get_Rotation());
			particleWorld = transform->Get_LocalToWorldMatrix();
			Quaternion rotation;

			for(int i = 0; i < this->m_iParticleCount; i++)
			{
				particleWorld = transform->Get_LocalToWorldMatrix();
				rotation = transform->Get_Rotation();
				translation = ParticleEmitter::RandomPositionByDistance(position, this->m_kDimensions);
				
				particleTranslation = Matrix::CreateTranslation(translation);
				particleWorld *= particleTranslation;
				particleWorld *= particleRotation;

				this->m_pParticles[i].position = Vector3(particleWorld._41, particleWorld._42, particleWorld._43);;
				if(this->m_bRandomizeColor)
					this->m_pParticles[i].color = ParticleEmitter::RandomColor(this->m_kColorLimit);
				else
					this->m_pParticles[i].color = Color(1.0f, 0.0f, 0.0f, 1.0f);

				rotation = rotation + Quaternion(RandomDirectionalVelocity(true, false, true, Vector3(1, 1, 1)));
				this->m_pParticles[i].velocity = Vector3(rotation.x, rotation.y, rotation.z);
				this->m_pParticles[i].acceleration = Vector3(0.0f, 0.0f, 0.0f);
				this->m_pParticles[i].size = this->m_iParticleSize;
				this->m_pParticles[i].timestamp = (float)rand()/(float)(RAND_MAX) * this->m_fLifeTime;
				this->m_pParticles[i].lifetime = this->m_fLifeTime;
				this->m_pParticles[i].type = EmitterType::Linear;
			}
		}

		void ParticleEmitter::InitializeFountain()
		{
			//getting the orientation so we can 
			Transform* transform = this->Get_GameObject()->Get_Transform();

			Vector3 position = transform->Get_Position();

			if(abs(this->m_kTranslation.x) > 0 || abs(this->m_kTranslation.y) > 0 || abs(this->m_kTranslation.z) > 0)
				position += this->m_kTranslation;

			Matrix particleTranslation, particleRotation, particleWorld;
			Vector3 translation, velocity;

			particleRotation = Matrix(transform->Get_Rotation());
			particleWorld = transform->Get_LocalToWorldMatrix();
			Quaternion rotation;


			for(int i = 0; i < this->m_iParticleCount; i++)
			{
				particleWorld = transform->Get_LocalToWorldMatrix();
				rotation = transform->Get_Rotation();
				particleTranslation = Matrix::CreateTranslation(position);
				particleWorld *= particleTranslation;
				particleWorld *= particleRotation;
				
				this->m_pParticles[i].position = Vector3(particleWorld._41, particleWorld._42, particleWorld._43);;
				
				if(this->m_bRandomizeColor)
					this->m_pParticles[i].color = ParticleEmitter::RandomColor(this->m_kColorLimit);
				else
					this->m_pParticles[i].color = Color(1.0f, 1.0f, 1.0f, 1.0f);
				this->m_pParticles[i].velocity = ParticleEmitter::RandomDirectionalVelocity(true, false, true, this->m_kDirection);
				this->m_pParticles[i].acceleration = Vector3(0.0f, this->m_fRadius, this->m_fRadius2);
				this->m_pParticles[i].size = this->m_iParticleSize;
				this->m_pParticles[i].timestamp = (float)rand()/(float)(RAND_MAX) * this->m_fLifeTime;
				this->m_pParticles[i].lifetime = this->m_fLifeTime;
				this->m_pParticles[i].rotation = ((float)rand() / (float)(RAND_MAX)) * 2 - 1;	//getting a random rotation speed between -1 and 1
				this->m_pParticles[i].type = EmitterType::Fountain;
			}
		}

		void ParticleEmitter::InitializeOrbital()
		{
			if(this->m_fRadius <= 0.0f || this->m_fRadius2 <= 0.0f)
				throw SingularityException("Orbital Particle Emitters require a radius greater than");

			Transform* transform = this->Get_GameObject()->Get_Transform();

			Vector3 position = transform->Get_Position();

			if(abs(this->m_kTranslation.x) > 0 || abs(this->m_kTranslation.y) > 0 || abs(this->m_kTranslation.z) > 0)
				position += this->m_kTranslation;

			//setting up the orbital texture flags
			this->m_pParticles[0].position = position;
			if(this->m_bRandomizeColor)
				this->m_pParticles[0].color = ParticleEmitter::RandomColor(this->m_kColorLimit);
			else
				this->m_pParticles[0].color = Color(1.0f, 0.0f, 0.0f, 1.0f);
			//this->m_pParticles[i].velocity = Vector3(randX, randY, randZ);
			
			this->m_pParticles[0].acceleration = Vector3(0.0f, this->m_fRadius, this->m_fRadius2);
			this->m_pParticles[0].size = 1.0f;
			this->m_pParticles[0].timestamp = (float)rand()/(float)(RAND_MAX) * this->m_fLifeTime;
			this->m_pParticles[0].lifetime = this->m_fLifeTime;
			this->m_pParticles[0].type = EmitterType::Orbital;

			for(int i = 1; i < this->m_iParticleCount; i++)
			{
				this->m_pParticles[i].position = position;
				if(this->m_bRandomizeColor)
					this->m_pParticles[i].color = ParticleEmitter::RandomColor(this->m_kColorLimit);
				else
					this->m_pParticles[i].color = Color(1.0f, 0.0f, 0.0f, 1.0f);
				//this->m_pParticles[i].velocity = Vector3(randX, randY, randZ);
				
				this->m_pParticles[i].acceleration = Vector3(1.0f, this->m_fRadius, this->m_fRadius2);
				this->m_pParticles[i].size = this->m_iParticleSize;
				this->m_pParticles[i].timestamp = (float)rand()/(float)(RAND_MAX) * this->m_fLifeTime;
				this->m_pParticles[i].lifetime = this->m_fLifeTime;
				this->m_pParticles[i].type = EmitterType::Orbital;
			}
		}

		void ParticleEmitter::InitializeSpiral()
		{
			Transform* transform = this->Get_GameObject()->Get_Transform();

			Vector3 position = transform->Get_Position();

			if(abs(this->m_kTranslation.x) > 0 || abs(this->m_kTranslation.y) > 0 || abs(this->m_kTranslation.z) > 0)
				position += this->m_kTranslation;

			Quaternion rotation,upRotation;
			upRotation = upRotation = Quaternion(Vector3(0, 1, 0));
			for(int i = 0; i < this->m_iParticleCount; i++)
			{
				this->m_pParticles[i].position = position;
				if(this->m_bRandomizeColor)
					this->m_pParticles[i].color = ParticleEmitter::RandomColor(this->m_kColorLimit);
				else
					this->m_pParticles[i].color = Color(1.0f, 0.0f, 0.0f, 1.0f);
				
				rotation = transform->Get_Rotation() + upRotation;
				this->m_pParticles[i].velocity = Vector3(rotation.x, rotation.y, rotation.z);
				this->m_pParticles[i].acceleration = Vector3(0.0f, 0.0f, 0.0f);
				this->m_pParticles[i].size = this->m_iParticleSize;
				this->m_pParticles[i].timestamp = (float)rand()/(float)(RAND_MAX) * this->m_fLifeTime;
				this->m_pParticles[i].lifetime = this->m_fLifeTime;
				this->m_pParticles[i].type = EmitterType::Spiral;
			}
		}

		void ParticleEmitter::InitializeSphere()
		{
			Transform* transform = this->Get_GameObject()->Get_Transform();

			Vector3 position = transform->Get_Position();

			if(abs(this->m_kTranslation.x) > 0 || abs(this->m_kTranslation.y) > 0 || abs(this->m_kTranslation.z) > 0)
				position += this->m_kTranslation;

			for(int i = 0; i < this->m_iParticleCount; i++)
			{
				this->m_pParticles[i].position = position;
				if(this->m_bRandomizeColor)
					this->m_pParticles[i].color = ParticleEmitter::RandomColor(this->m_kColorLimit);
				else
					this->m_pParticles[i].color = Color(1.0f, 0.0f, 0.0f, 1.0f);
				this->m_pParticles[i].velocity = ParticleEmitter::RandomRadialVelocity(Vector3(1.0f, 1.0f, 1.0f));
				this->m_pParticles[i].acceleration = Vector3(0.0f, 0.0f, 0.0f);
				this->m_pParticles[i].size = this->m_iParticleSize;
				this->m_pParticles[i].timestamp = 0;
				this->m_pParticles[i].lifetime = this->m_fLifeTime;
				this->m_pParticles[i].type = EmitterType::Sphere;
			}
		}

		void ParticleEmitter::InitializeRadial()
		{
			if(this->m_fRadius <= 0)
				throw SingularityException("Radial Emitter requires a radius that is greater than 0 in order to function properly.");
			Transform* transform = this->Get_GameObject()->Get_Transform();

			Vector3 position = transform->Get_Position();

			if(abs(this->m_kTranslation.x) > 0 || abs(this->m_kTranslation.y) > 0 || abs(this->m_kTranslation.z) > 0)
				position += this->m_kTranslation;

			Vector3 translation;
			double randRadianAngle;
			float randDiff, posX, posZ;

			for(int i = 0; i < this->m_iParticleCount; i++)
			{
				//grab the random angle to put the point along the circle. Converted to radians
				//grab the random angle to put the point along the circle. Converted to radians
				randRadianAngle = (rand() % 360) * D3DX_PI / 180;
				randDiff = (float)(rand() % 4);

				//calculate the x and z point along the circle
				posX = this->m_fRadius * (float)cos(randRadianAngle);
				posZ = this->m_fRadius * (float)sin(randRadianAngle);

				this->m_pParticles[i].position = Vector3(posX + position.x, position.y, posZ + position.z);
				if(this->m_bRandomizeColor)
					this->m_pParticles[i].color = ParticleEmitter::RandomColor(this->m_kColorLimit);
				else
					this->m_pParticles[i].color = Color(1.0f, 0.0f, 0.0f, 1.0f);
				this->m_pParticles[i].velocity = Vector3(0, 1, 0);
				this->m_pParticles[i].acceleration = Vector3(0.0f, 0.0f, 0.0f);
				this->m_pParticles[i].size = this->m_iParticleSize;
				this->m_pParticles[i].timestamp = (float)rand()/(float)(RAND_MAX) * (this->m_fLifeTime / 10.0f);
				this->m_pParticles[i].lifetime = this->m_fLifeTime;
				this->m_pParticles[i].type = EmitterType::Radial;
			}
		}

		void ParticleEmitter::InitializeQuadStretch()
		{
			Transform* transform = this->Get_GameObject()->Get_Transform();

			Vector3 position = transform->Get_Position();

			if(abs(this->m_kTranslation.x) > 0 || abs(this->m_kTranslation.y) > 0 || abs(this->m_kTranslation.z) > 0)
				position += this->m_kTranslation;

			for(int i = 0; i < this->m_iParticleCount; i++)
			{
				this->m_pParticles[i].position = position;
				if(this->m_bRandomizeColor)
					this->m_pParticles[i].color = ParticleEmitter::RandomColor(this->m_kColorLimit);
				else
					this->m_pParticles[i].color = Color(1.0f, 0.0f, 0.0f, 1.0f);
				this->m_pParticles[i].velocity = Vector3(0.0f, 0.0f, 0.0f);
				this->m_pParticles[i].acceleration = Vector3(0.0f, 0.0f, 0.0f);
				this->m_pParticles[i].size = this->m_iParticleSize;
				this->m_pParticles[i].timestamp = 0;
				this->m_pParticles[i].lifetime = this->m_fLifeTime;
				this->m_pParticles[i].type = EmitterType::QuadStretch;
			}
		}
		#pragma endregion

		#pragma region Static Methods
		Vector3 ParticleEmitter::RandomPositionByDistance(Vector3 origin, Vector3 ceiling)
		{
			float randX, randY, randZ;

			randX = (((float)rand()/((float)(RAND_MAX) + 1.0f)) * 2 - 1) * ceiling.x;
			randY = (((float)rand()/((float)(RAND_MAX) + 1.0f)) * 2 - 1) * ceiling.y;
			randZ = (((float)rand()/((float)(RAND_MAX) + 1.0f)) * 2 - 1) * ceiling.z;
			
			return Vector3(randX, randY, randZ) + origin;
		}

		Vector3 ParticleEmitter::RandomRadialVelocity(Vector3 ceiling)
		{
			float theta, rho, phi, randX, randY, randZ;

			theta = ((float)rand()) / (float)RAND_MAX;
			rho   = ((float)rand()) / (float)RAND_MAX;

			// theta and rho now between 0 and 1
			theta *= 2.0f * 3.14159265359f;
			rho   *= 2.0f;


			if (rho < 1.0f)
				phi   = sqrtf(rho) * 3.14159265359f * 0.5f;
			else
				phi   = (2.0f - sqrtf(2.0f - rho)) * 3.14159265359f * 0.5f;


			// spherical to cartesian
			randX = sinf(phi) * cosf(theta) * ceiling.x;
			randY = cosf(phi) * ceiling.y;
			randZ = sinf(phi) * sinf(theta) * ceiling.z;

			return Vector3(randX, randY, randZ);
		}

		Vector3 ParticleEmitter::RandomDirectionalVelocity(bool xAxis, bool yAxis, bool zAxis, Vector3 ceiling)
		{
			float theta, rho, phi;
			Vector3 randVec = ceiling;

			theta = ((float)rand()) / (float)RAND_MAX;
			rho   = ((float)rand()) / (float)RAND_MAX;

			// theta and rho now between 0 and 1
			theta *= 2.0f * 3.14159265359f;
			rho   *= 2.0f;


			if (rho < 1.0f)
				phi   = sqrtf(rho) * 3.14159265359f * 0.5f;
			else
				phi   = (2.0f - sqrtf(2.0f - rho)) * 3.14159265359f * 0.5f;


			// spherical to cartesian
			if(xAxis)
				randVec.x = sinf(phi) * cosf(theta) * ceiling.x;
			if(yAxis)
				randVec.y = cosf(phi) * ceiling.y;
			if(zAxis)
				randVec.z = sinf(phi) * sinf(theta) * ceiling.z;

			return randVec;
		}

		Vector3 ParticleEmitter::RandomRadialPosition(bool xAxis, bool yAxis, bool zAxis, Vector3 position, float radius)
		{
			float theta, rho, phi;
			radius = (((float)rand()) / ((float)RAND_MAX)) * radius;
			Vector3 randVec = Vector3(0, 0, 0);

			theta = ((float)rand()) / (float)RAND_MAX;
			rho   = ((float)rand()) / (float)RAND_MAX;

			// theta and rho now between 0 and 1
			theta *= 2.0f * 3.14159265359f;
			rho   *= 2.0f;

			if (rho < 1.0f)
				phi   = sqrtf(rho) * 3.14159265359f * 0.5f;
			else
				phi   = (2.0f - sqrtf(2.0f - rho)) * 3.14159265359f * 0.5f;


			// spherical to cartesian
			if(xAxis)
				randVec.x = sinf(phi) * cosf(theta) * radius;
			if(yAxis)
				randVec.y = cosf(phi) * radius;
			if(zAxis)
				randVec.z = sinf(phi) * sinf(theta) * radius;

			return Vector3(position.x + randVec.x, position.y + randVec.y, position.z + randVec.z);
		}

		Vector3 ParticleEmitter::PositionAlongSphere(bool xAxis, bool yAxis, bool zAxis, Vector3 position, float radius)
		{
			float theta, rho, phi;
			Vector3 randVec = Vector3(0, 0, 0);

			theta = ((float)rand()) / (float)RAND_MAX;
			rho   = ((float)rand()) / (float)RAND_MAX;

			// theta and rho now between 0 and 1
			theta *= 2.0f * 3.14159265359f;
			rho   *= 2.0f;

			if (rho < 1.0f)
				phi   = sqrtf(rho) * 3.14159265359f * 0.5f;
			else
				phi   = (2.0f - sqrtf(2.0f - rho)) * 3.14159265359f * 0.5f;


			// spherical to cartesian
			if(xAxis)
				randVec.x = sinf(phi) * cosf(theta) * radius;
			if(yAxis)
				randVec.y = cosf(phi) * radius;
			if(zAxis)
				randVec.z = sinf(phi) * sinf(theta) * radius;

			return Vector3(position.x + randVec.x, position.y + randVec.y, position.z + randVec.z);
		}

		Color ParticleEmitter::RandomColor(Color colorLimit)
		{
			float randR, randG, randB;

			randR = (float)rand() / (float)(RAND_MAX) * colorLimit.r / 256;
			randG = (float)rand() / (float)(RAND_MAX) * colorLimit.g / 256;
			randB = (float)rand() / (float)(RAND_MAX) * colorLimit.b / 256;
			//randA = (float)rand() / (float)(RAND_MAX) * colorLimit.a / 256;

			return Color(randR, randG, randB, 1.0f);
		}
		#pragma endregion
	}
}