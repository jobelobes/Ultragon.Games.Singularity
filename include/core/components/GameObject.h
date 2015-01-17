#include "core\Singularity.Core.h"

namespace Singularity
{
	namespace Components
	{
		class GameObject : public Singularity::Object
		{
			DECLARE_OBJECT_TYPE

			private:
				#pragma region Variables
				Singularity::Threading::CriticalSection				m_kLock;

				UUID												m_kId;
				String												m_kName;
				bool												m_bActive;
				Transform*											m_pTransform;

				Scene*												m_pScene;
				GameObject*											m_pRoot;
				GameObject*											m_pParent;
				DynamicList<GameObject*>							m_pChildren;
				DynamicList<Component*>								m_pComponents;
				#pragma endregion

			protected:
				#pragma region Constructors and Deconstructors
				GameObject(String name = "");
				#pragma endregion

				#pragma region Event Methods
				virtual void OnGameObjectAdded(GameObject* parent);
				virtual void OnGameObjectRemoved();
				#pragma endregion

			public:
				#pragma region Properties
				const UUID Get_Id() const;

				const String Get_Name() const;

				const bool Get_IsActive() const;
				void Set_IsActive(const bool value);

				Transform* Get_Transform();

				GameObject* Get_Root();
				
				GameObject* Get_Parent() const;
				void Set_Parent(GameObject* parent);
				#pragma endregion

				#pragma region Constructors and Deconstructors
				~GameObject();
				#pragma endregion

				#pragma region Methods
				void AttachChild(GameObject* node);
				void DetachChild(GameObject* node);
				void DetachChildren();

				Component* GetComponent(const Singularity::ObjectType& type);
				Component* GetComponent(String type);
				Component* GetComponentByIndex(int index);

				void AddComponent(Component* component);
				void RemoveComponent(Component* component);
				void ClearComponents();

				void Destroy();

				GameObject* Find(String name);
				const bool IsChildOf(const GameObject* parent) const;
				#pragma endregion

				#pragma region Static Methods
				static GameObject* Create(String name = "", GameObject* parent = NULL, Scene* scene = NULL);
				#pragma endregion

				friend class Scene;
				friend class Transform;
		};

		#include "core\components\GameObject.inc"
	}
}