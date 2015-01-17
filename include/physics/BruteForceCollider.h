#include "physics\Singularity.Physics.h"

namespace Singularity
{
	namespace Physics
	{
		class BruteForceCollider : public IBroadPhaseCollider
		{
			private:
				#pragma region Variables
				PhysicsTask*				m_pSimulator;
				DynamicSet<Collider*>		m_pColliders;
				#pragma endregion

				#pragma region Methods
				bool IsIntersecting(Bounds& bounds0, Bounds& bounds1);
				bool IsIntersecting(Bounds& bounds0, Vector3& velocity0, Bounds& bounds1, Vector3& velocity1, float& t0, float& t1);
				#pragma endregion
				
			public:
				#pragma region Methods
				BruteForceCollider(PhysicsTask* simulator);
				~BruteForceCollider();
				#pragma endregion

				#pragma region Methods
				void AddCollider(Collider* collider);
				void RemoveCollider(Collider* collider);
				void Update(float elapsedTime);
				#pragma endregion
		};
	}
}