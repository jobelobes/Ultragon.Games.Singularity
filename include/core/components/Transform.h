#include "core\Singularity.Core.h"

namespace Singularity
{
	namespace Components
	{
		enum Space { Self, World };

		class Transform : public Singularity::Components::Component
		{
			DECLARE_OBJECT_TYPE

			private:
				#pragma region Variables
				bool									m_bDirty;

				Vector3									m_kPosition;
				Quaternion								m_kRotation;
				Vector3									m_kScale;
				Matrix									m_kTransform;
				#pragma endregion

				#pragma region Properties
				Vector3 Get_ParentPosition();

				Quaternion Get_ParentRotation();

				Vector3 Get_ParentScale();

				Matrix Get_ParentLocalToWorldMatrix();

				void SetDirty();
				#pragma endregion

			public:
				#pragma region Properties
				Vector3 Get_Position();
				void Set_Position(Vector3& value);

				Quaternion Get_Rotation();
				void Set_Rotation(Quaternion& value);
				void Set_Rotation(Vector3& value);

				Vector3 Get_Scale();
				void Set_Scale(Vector3& value);

				Vector3& Get_LocalPosition();
				void Set_LocalPosition(Vector3& value);

				Quaternion& Get_LocalRotation();
				void Set_LocalRotation(Quaternion& value);

				Vector3& Get_LocalScale();
				void Set_LocalScale(Vector3& value);

				Matrix Get_LocalToWorldMatrix();

				//Matrix Get_WorldToLocalMatrix();
				#pragma endregion

				#pragma region Constructors and Finalizers
				Transform();
				~Transform();
				#pragma endregion

				#pragma region Methods
				void Reset();

				void Scale(const Vector3& value, Space space = Space::Self);
				void Scale(const float x, const float y, const float z, Space space = Space::Self);

				void Translate(const Vector3& value, Space space = Space::Self);
				void Translate(const float x, const float y, const float z, Space space = Space::Self);
				//void Translate(Vector3 value, Transform* transform);
				//void Translate(float x, float y, float z, Transform* transform);

				void Rotate(const Vector3& value, Space space = Space::Self);
				void Rotate(const float xAngle, const float yAngle, float zAngle, Space space = Space::Self);				
				void Rotate(const Vector3& axis, const float angle, Space space = Space::Self);
				void Rotate(const Quaternion& angle, Space space = Space::Self);

				void RotateAround(const Vector3& point, const Vector3& axis, const float angle);
				void RotateAround(const Vector3& point, const Quaternion& rotation);
				

				void LookAt(const Vector3& target, Vector3 worldUp = Vector3(0,1,0));
				void LookAt(Transform* target, Vector3 worldUp = Vector3(0,1,0));

				//Vector3 TransformDirection(Vector3 direction);
				//Vector3 TransformDirection(float x, float y, float z);
				//Vector3 InverseTransformDirection(Vector3 direction);
				//Vector3 InverseTransformDirection(float x, float y, float z);

				//Vector3 TransformPoint(Vector3 direction);
				//Vector3 TransformPoint(float x, float y, float z);
				//Vector3 InverseTransformPoint(Vector3 direction);
				//Vector3 InverseTransformPoint(float x, float y, float z);
				#pragma endregion

				#pragma region Events
				DelegateHandler		Changed;
				#pragma endregion

				#pragma region Static Methods
				static Vector3 RotationToEuler(Quaternion rotation);
				static Quaternion EulerToRotation(Vector3 euler);
				static Vector3 AngleTo(const Vector3 from, const Vector3 location);
				#pragma endregion

				friend class GameObject;
		};

		#include "core\components\Transform.inc"
	}
}