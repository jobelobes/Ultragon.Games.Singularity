#include "core\Singularity.Core.h"

using namespace Singularity;

namespace Singularity
{
	namespace Components
	{
		IMPLEMENT_OBJECT_TYPE(Singularity.Components, Scene, Object);

		#pragma region Static Variables
		Scene* Scene::g_pCurrent = NULL;
		#pragma endregion

		#pragma region Constructors and Finalizers
		Scene::Scene(int capacity, bool active)
			: m_iCapacity(capacity), m_iCount(0)
		{
			if(this->m_iCapacity < 1)
				throw SingularityException("Unable to create a Scene with a capacity of zero or less");

			this->m_pObjects = new GameObject[this->m_iCapacity];
			this->m_pAllocationTable = (bool*)malloc(sizeof(bool) * this->m_iCapacity);
			memset(this->m_pAllocationTable, 0, sizeof(bool) * this->m_iCapacity);

			if(active)
				Scene::g_pCurrent = this;
		}

		Scene::~Scene() { }
		#pragma endregion

		#pragma region Methods
		GameObject* Scene::AllocateGameObject(String name)
		{
			unsigned index;
			GameObject* obj;

			if(this->m_iCount == this->m_iCapacity)
				throw SingularityException("Unable to create a new GameObject, Max limit has been reached");

			for(index = 0; index < this->m_iCapacity && this->m_pAllocationTable[index]; index++);

			::InterlockedIncrement((LONG*)&this->m_iCount);
			::InterlockedExchange((LONG*)&this->m_pAllocationTable[index], 1L);
			
			obj = &this->m_pObjects[index];
			UuidCreate(&obj->m_kId);
			obj->m_kName = name;
			obj->Set_IsActive(true);
			obj->Get_Transform()->Reset();
			obj->m_pRoot = NULL;
			obj->m_pParent = NULL;
			obj->m_pScene = this;
			return obj;
		}

		void Scene::DeallocateGameObject(GameObject* object)
		{
			unsigned index;

			for(index = 0; index < this->m_iCapacity && &this->m_pObjects[index] != object; ++index);

			if(index == this->m_iCapacity)
				return;

			::InterlockedExchange((LONG*)&this->m_pAllocationTable[index], 0L);
			::InterlockedDecrement((LONG*)&this->m_iCount);

			object->Get_Transform()->Reset();
		}

		void Scene::Activate()
		{
			Scene::g_pCurrent = this;
		}

		void Scene::Deactivate()
		{
			Scene::g_pCurrent = NULL;
		}

		void Scene::Clear()
		{

		}

		void Scene::Save(String path)
		{

		}

		void Scene::Open(String path)
		{

		}
		#pragma endregion

		#pragma region Static Methods
		Scene* Scene::Create(int capacity, bool active)
		{
			return new Scene(capacity, active);
		}

		Scene* Scene::Get_Current()
		{	
			return Scene::g_pCurrent;
		}
		#pragma endregion
	}
}