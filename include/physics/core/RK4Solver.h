#include "physics\Singularity.Physics.h"

namespace Singularity
{
	namespace Physics
	{
		namespace Core
		{
			

			class RK4Solver : public Singularity::Physics::Core::ISolver
			{
				DECLARE_OBJECT_TYPE;

				private:
					#pragma region Methods
					PhysicsDerivative Evaluate(float elapsedTime, PhysicsObject& object, PhysicsState& state, const PhysicsDerivative &d);
					#pragma endregion

				protected:
					#pragma region Methods
					void Update(float elapsedTime, PhysicsObject& object, PhysicsState& state);
					#pragma endregion

				public:
					#pragma region Constructors and Finalizers
					RK4Solver();
					#pragma endregion
			};
		}
	}
}