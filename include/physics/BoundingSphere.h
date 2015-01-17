#include "physics\Singularity.Physics.h"

namespace Singularity
{
	namespace Physics
	{
		namespace Core
		{
			class BoundingSphere
			{
				public:
					#pragma region Variables
					Vector3 Center;
					float Radius;
					#pragma endregion

					#pragma region Constructors and Finalizers
					BoundingSphere(Vector3 center = Vector3(0,0,0), float radius = 0.5);
					#pragma endregion

					#pragma region Methods
					Vector3 FindIntersectionPoint(BoundingSphere& sphere);
					#pragma endregion

					#pragma region Static Methods
					static bool Intersects(BoundingSphere& sphere0, BoundingSphere& sphere1);
					#pragma endregion
			};
		}
	}
}