#include "physics\Singularity.Physics.h"

namespace Singularity
{
	namespace Physics
	{
		namespace Core
		{
			class BoundingOBB
			{
				public:
					#pragma region Variables
					Vector3 Center;
					Vector3 Axis[3];
					Vector3 Extents;
					#pragma endregion

					#pragma region Constructors
					BoundingOBB();
					BoundingOBB(Vector3 center, Vector3 axis[3], Vector3 extents);
					BoundingOBB(Vector3 center, Quaternion orientation, Vector3 extents);
					#pragma endregion

					#pragma region Methods
					void GetMaxMin(Vector3& min, Vector3& max);

					void Project(const Vector3& axis, float& min, float& max);

					Vector3 FindClosestPoint(const Vector3& point);

					bool IsIntersecting(BoundingOBB& box);

					bool FindIntersection(BoundingOBB& box, Vector3& point, Vector3& normal);
					#pragma endregion
			};
		}
	}
}