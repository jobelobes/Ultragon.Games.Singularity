#include "physics\Singularity.Physics.h"

using namespace Singularity::Threading;
using namespace Singularity::Components;

namespace Singularity
{
	namespace Physics
	{
		class CollisionExtension : public Singularity::Components::Extension
		{
			private:
				#pragma region Static Variables
				static CollisionExtension*	g_pInstance;
				#pragma endregion

				#pragma region Variables
				CriticalSection				m_kLock;
				Timer						m_kTimer;

				DynamicList<Collider*>		m_pColliders;
				Octree<Collider*>*			m_pOctree;
				#pragma endregion

				#pragma region Methods
				void RegisterCollider(Collider* collider);
				void UnregisterCollider(Collider* collider);
				#pragma endregion

			protected:
				#pragma region Event Methods
				virtual void OnInitialize();
				virtual void OnExecute();
				virtual void OnComplete() { };
				virtual void OnUninitialize() { };
				#pragma endregion

			public:
				#pragma region Constructors and Finalizers
				CollisionExtension();
				~CollisionExtension();
				#pragma endregion

				#pragma region Static Methods
				static CollisionExtension* Instantiate();
				#pragma endregion

				friend class Collider;
		};
	}
}