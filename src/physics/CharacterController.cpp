#include "physics\Singularity.Physics.h"

namespace Singularity
{
	namespace Physics
	{
		IMPLEMENT_OBJECT_TYPE(Singularity.Physics, CharacterController, Singularity::Physics::Collider);

		#pragma region Static Variables
		Mesh* CharacterController::g_pBoundingBox = NULL;
		#pragma endregion

		#pragma region Static Methods
		Mesh* CharacterController::CreateBoundingBoxMesh()
		{
			Mesh* mesh = NULL;

			VertexPositionColor vertices[8];
			vertices[0].position = Vector3(-0.5, -0.5, -0.5); vertices[0].color = Color(1,1,1,1);
			vertices[1].position = Vector3( 0.5, -0.5, -0.5); vertices[1].color = Color(1,1,1,1);
			vertices[2].position = Vector3(-0.5,  0.5, -0.5); vertices[2].color = Color(1,1,1,1);
			vertices[3].position = Vector3( 0.5,  0.5, -0.5); vertices[3].color = Color(1,1,1,1);
			vertices[4].position = Vector3(-0.5, -0.5,  0.5); vertices[4].color = Color(1,1,1,1);
			vertices[5].position = Vector3( 0.5, -0.5,  0.5); vertices[5].color = Color(1,1,1,1);
			vertices[6].position = Vector3(-0.5,  0.5,  0.5); vertices[6].color = Color(1,1,1,1);
			vertices[7].position = Vector3( 0.5,  0.5,  0.5); vertices[7].color = Color(1,1,1,1);

			unsigned indices[17] = {0,1,3,2,0,4,6,2,3,7,5,1,0,4,5,7,6};

			mesh = new Mesh();
			mesh->SetVertices(VertexPositionColor::Declaration, &vertices[0], 8);
			mesh->SetIndices(&indices[0], 17);
			return mesh;
		}
		#pragma endregion

		#pragma region Overriden Methods
		void CharacterController::OnComponentAdded(Singularity::Components::GameObject* gameObject)
		{
			//GameObject* child;
			btVector3 intertia;
			btTransform centerOfMass;
			
			this->m_pCollisionShape = new btCapsuleShape(this->m_fRadius, this->m_fHeight - 2 * this->m_fRadius);
			this->m_pCollisionShape->setUserPointer(this);
			this->m_pCollisionShape->calculateLocalInertia(10.0f, intertia);

			this->m_pMotionState = new PhysicsMotionState(gameObject->Get_Transform(), Vector3(0,0,0), true);
			this->m_pRigidBody = new btRigidBody(10.0f, this->m_pMotionState, this->m_pCollisionShape, intertia);
			this->m_pRigidBody->setAngularFactor(btVector3(0, 0 ,0));
			//this->m_pRigidBody->setDamping(0.001f, 0.001f);
			this->m_pRigidBody->setGravity(btVector3(0, -1, 0));
			this->m_pRigidBody->setUserPointer(this);

			PhysicsTask::Instantiate()->RegisterComponent(this);

			/*Material* material = Material::CreateBasicMaterial();
			material->Set_Color(Color(1,0,0,1));
			material->Set_Pass(1);

			if(CharacterController::g_pBoundingBox == NULL)
				CharacterController::g_pBoundingBox = CharacterController::CreateBoundingBoxMesh();

			Mesh* mesh = CharacterController::g_pBoundingBox->Clone();
			mesh->Set_Topology(PrimitiveTopology::LineStrip);

			MeshRenderer* renderer = new MeshRenderer(mesh, material);
			renderer->Set_Layer(10);

			child = GameObject::Create("BoundingBox", gameObject);
			child->AddComponent(renderer);
			child->Get_Transform()->Set_LocalPosition(Vector3(0,0,0));
			child->Get_Transform()->Set_Scale(Vector3(this->m_fRadius * 2, this->m_fHeight, this->m_fRadius * 2) * 1.005f);*/
		}

		void CharacterController::OnComponentRemoved(Singularity::Components::GameObject* gameObject)
		{

		}
		#pragma endregion

		#pragma region Constructors and Finalizers
		CharacterController::CharacterController(String name)
			:Collider(name), m_fRadius(1.0f), m_fHeight(2.0f) { }
		#pragma endregion

		#pragma region Methods
		void CharacterController::Move(Vector3& direction, float amount)
		{
			btVector3 velocity = this->m_pRigidBody->getLinearVelocity();
			this->m_pRigidBody->setLinearVelocity(btVector3(direction.x * amount, velocity.y(), direction.z * amount));
			//this->m_pMotionState->setWorldTransform(xform);
			//this->m_pRigidBody->setCenterOfMassTransform(xform);
		}

		void CharacterController::Jump(float amount)
		{
			//btVector3 velocity = this->m_pRigidBody->getLinearVelocity();
 			this->m_pRigidBody->applyCentralImpulse(btVector3(0, amount, 0));
		}

		void CharacterController::Set_Gravity(float amount)
		{
			btVector3 grav = btVector3(0, amount, 0);
			this->m_pRigidBody->setGravity(grav);
		}

		void CharacterController::Set_Mass(float mass)
		{
			btVector3 inertia;
			this->m_pCollisionShape->calculateLocalInertia(mass, inertia);
			this->m_pRigidBody->setMassProps(mass, inertia);
		}

		void CharacterController::AddExplosiveForce(float force, Vector3 position, float radius)
		{
			Vector3 direction = this->Get_GameObject()->Get_Transform()->Get_Position() - position;
			float distance = direction.length();
			
			direction = direction.normalize() * force;
			this->m_pRigidBody->applyCentralImpulse(btVector3(direction.x*5, direction.y, direction.z*5));
			
		}

		#pragma endregion

	}
}