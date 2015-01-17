#include "physics\Singularity.Physics.h"

namespace Singularity
{
	namespace Physics
	{
		namespace Core
		{
			class BoundingCapsule
			{
				public:
					#pragma region Variables
					Vector3 Segment[2];
					float Radius;
					float Height;
					#pragma endregion

					#pragma region Constructors and Finalizers
					BoundingCapsule(Vector3 center = Vector3(0,0,0), Quaternion rotation = Quaternion(0,0,0,1), float radius = 0.5f, float height = 2.0f);
					#pragma endregion

					#pragma region Methods
					//Vector3 FindIntersectionPoint(BoundingSphere& sphere);
					#pragma endregion

					#pragma region Static Methods
					//static bool Intersects(BoundingSphere& sphere0, BoundingSphere& sphere1);
					#pragma endregion
			};
		}
	}
}