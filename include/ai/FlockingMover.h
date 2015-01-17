#include "ai\Singularity.AI.h"

namespace Singularity
{
	namespace AI
	{
		class FlockingMover : public Singularity::Components::Component
		{
			DECLARE_OBJECT_TYPE;

			private:
				#pragma region Variables
				Vector3		m_kHeading;
				#pragma endregion

			protected:
				#pragma region Overriden Methods
				virtual void OnComponentAdded();
				virtual void OnComponentRemoved();
				#pragma endregion

			public:
				#pragma region Constructors and Finalizers
				FlockingMover() : m_kHeading(0.0f, 0.0f, 0.0f) { }
				~FlockingMover() { }
				#pragma endregion

				friend class FlockingSubTask;
		};
	}
}