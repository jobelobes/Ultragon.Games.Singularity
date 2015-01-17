#include "physics\Singularity.Physics.h"

namespace Singularity
{
	namespace Physics
	{
		namespace Core
		{
			struct PhysicsObject
			{
				float		InverseMass;
				float		InverseTensor;

				float		LinearDrag;
				float		AngularDrag;

				Vector3		CenterOfMass;
				Vector3		Gravity;
			};

			class ISolver : public Singularity::Object
			{
				DECLARE_OBJECT_TYPE;

				public:
					#pragma region Methods
					virtual void Update(float elapsedTime, PhysicsObject& object, PhysicsState& state) = 0;
					#pragma endregion
			};
		}
	}
}