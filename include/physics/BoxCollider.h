#include "physics\Singularity.Physics.h"

namespace Singularity
{
	namespace Physics
	{
		class BoxCollider : public Collider
		{
			DECLARE_OBJECT_TYPE;

			private:
				#pragma region Static Variables
				static Mesh* g_pBoundingBox;
				#pragma endregion

				#pragma region Variables
				Vector3 m_kSize;
				#pragma endregion

				#pragma region Static Methods
				Mesh* CreateBoundingBoxMesh();
				#pragma endregion

			protected:
				#pragma region Overriden Methods
				void OnComponentAdded(Singularity::Components::GameObject* gameObject);
				#pragma endregion

			public:
				#pragma region Properties
				Vector3& Get_Size();
				void Set_Size(const Vector3& value);
				#pragma endregion

				#pragma region Constructors and Finalizers
				BoxCollider(String name = "", Vector3 center = Vector3(0,0,0), Vector3 size = Vector3(1,1,1))
					: Collider(name, center), m_kSize(size) { }

				~BoxCollider() { }
				#pragma endregion
		};
		
		#include "physics\BoxCollider.inc"
	}
}