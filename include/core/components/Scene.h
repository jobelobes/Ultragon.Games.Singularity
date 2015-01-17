#include "core\Singularity.Core.h"

namespace Singularity
{
	namespace Components
	{
		class Scene : public Singularity::Object
		{
			DECLARE_OBJECT_TYPE

			private:
				#pragma region Static Variables
				static Scene* g_pCurrent;
				#pragma endregion

				#pragma region Variables
				unsigned		m_iCapacity;
				unsigned		m_iCount;
				GameObject*		m_pObjects;
				bool*			m_pAllocationTable;
				#pragma endregion

				#pragma region Constructors and Finalizers
				Scene(int capacity, bool active);
				#pragma endregion

				#pragma region Methods
				GameObject* AllocateGameObject(String name);
				void DeallocateGameObject(GameObject* object);
				#pragma endregion

			public:
				#pragma region Properties
				inline const bool Get_IsActive() const { return Scene::g_pCurrent == this; };
				#pragma endregion

				#pragma region Constructors and Finalizers
				~Scene();
				#pragma endregion

				#pragma region Methods
				void Activate();
				void Deactivate();

				void Clear();

				void Save(String path);
				void Open(String path);
				#pragma endregion

				#pragma region Static Methods
				static Scene* Create(int capacity = SINGULARITY_MAX_GAMEOBJECTS, bool active = true);
				static Scene* Get_Current();
				#pragma endregion

				friend class GameObject;
		};
	}
}