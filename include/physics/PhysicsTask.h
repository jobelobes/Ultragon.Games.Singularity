#include "physics\Singularity.Physics.h"

using namespace Singularity::Threading;
using namespace Singularity::Components;

namespace Singularity
{
	namespace Physics
	{
		class PhysicsTask : public Singularity::Threading::Task
		{
			DECLARE_OBJECT_TYPE;

			private:
				#pragma region Static Variables
				static PhysicsTask*	g_pInstance;
				#pragma endregion

				#pragma region Variables
				CriticalSection								m_kLock;

				btDiscreteDynamicsWorld*					m_pDynamicsWorld;
				btBroadphaseInterface*						m_pBroadphase;
				btCollisionDispatcher*						m_pDispatcher;
				btConstraintSolver*							m_pSolver;
				btDefaultCollisionConfiguration*			m_pCollisionConfiguration;
				DynamicSet<Collider*>						m_pColliders;

				PhysicsSubTask*								m_pSubTasks[SINGULARITY_PHYSICS_MAX_SUBTASKS];

				static void NearCallback(btBroadphasePair& collisionPair, btCollisionDispatcher& dispatcher, const btDispatcherInfo& dispatchInfo);
 
				#pragma endregion

			protected:
				#pragma region Event Methods
				virtual void OnExecute();
				virtual void OnComplete() { };
				#pragma endregion

			public:
				#pragma region Constructors and Finalizers
				PhysicsTask();
				~PhysicsTask();
				#pragma endregion

				#pragma region Methods
				void RegisterComponent(Component* body);
				void UnregisterComponent(Component* body);
				#pragma endregion

				#pragma region Static Methods
				static PhysicsTask* Instantiate();
				#pragma endregion

				friend class PhysicsSubTask;
				friend class PhysicsBody;
				friend class Collider;
				friend class BruteForceCollider;
		};
	}
}