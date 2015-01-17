#include "physics\Singularity.Physics.h"

namespace Singularity
{
	namespace Physics
	{
		class CollisionQuery : public Singularity::Object
		{
			DECLARE_OBJECT_TYPE

			private:
				#pragma region Variables
				unsigned m_iCount;
				#pragma endregion

				#pragma region Constructors and Finalizers
				CollisionQuery() : m_iCount(0) { };
				#pragma endregion

			public:
				#pragma region Properties
				//const float Get_Count() const;
				#pragma endregion

				#pragma region Methods
				//Collider* Next(ContactPoint& point);
				#pragma endregion
		};
	}
}