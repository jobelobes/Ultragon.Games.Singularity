#include "core\Singularity.Core.h"

using namespace Singularity;

namespace Singularity
{
	namespace Components
	{
		IMPLEMENT_OBJECT_TYPE(Singularity.Components, GameObject, Object);

		#pragma region Properties
		void GameObject::Set_IsActive(const bool value) 
		{ 
			unsigned index, count;

			this->m_bActive = value; 
			count = this->m_pComponents.size();
			for(index = 0; index < count; ++index)
				this->m_pComponents[index]->Set_Enabled(value);
		};
		#pragma endregion

		#pragma region Constructors and Deconstructors
		GameObject::GameObject(String name)
			: m_pRoot(NULL), m_pParent(NULL), m_bActive(true), m_kName(name)
		{
			this->m_pTransform = new Transform();
			this->AddComponent(this->m_pTransform);
		}

		GameObject::~GameObject()
		{
			// destroy your children
			this->DetachChildren();
			this->ClearComponents();

			// remember to remove yourself from the parent object
			if(this->m_pParent != NULL)
				this->m_pParent->DetachChild(this);
		}
		#pragma endregion

		#pragma region Methods
		void GameObject::AttachChild(GameObject* node)
		{
			if(node == NULL)
				throw SingularityException("\"node\" cannot be null or empty.");
	
			node->m_pParent = this;
			this->m_pChildren.push_back(node);
			this->m_pTransform->m_bDirty = true;
		}

		void GameObject::DetachChild(GameObject* node)
		{
			unsigned index, size;

			Autolock(this->m_kLock)
			{
				size = this->m_pChildren.size();
				if(node == NULL || size == 0)
					return;

				for(index = 0; index < size; index++)
					if(node == this->m_pChildren[index])
						break;
				
				// a component was found
				if(index != size)
				{
					// notify both classes what has happened
					this->m_pChildren[index]->OnGameObjectRemoved();

					// remove the component
					if(size > 1)
						this->m_pChildren[index] = this->m_pChildren[size - 1];
					this->m_pChildren.pop_back();
				}	
			}
		}

		void GameObject::DetachChildren()
		{
			unsigned index, size;

			Autolock(this->m_kLock)
			{
				size = this->m_pChildren.size();

				// notify all of the game objects that they are being removed
				for(index = 0; index < size; index++)
					this->m_pChildren[index]->Destroy();

				this->m_pChildren.clear();
			}
		}

		GameObject* GameObject::Find(String name)
		{
			return NULL;
		}

		const bool GameObject::IsChildOf(const GameObject* parent) const
		{
			GameObject* gameobject = this->m_pParent;

			while(gameobject != parent && gameobject != this->m_pRoot)
				gameobject = gameobject->m_pParent;

			return gameobject == parent;
		}

		Component* GameObject::GetComponent(const ObjectType& type)
		{
			unsigned index, count;
			const ObjectType* componentType;

			count = this->m_pComponents.size();
			for(index = 0; index < count; ++index)
			{
				componentType = &this->m_pComponents[index]->GetType();
				if(componentType->IsSubClassOf(type) || componentType->Equals(type))
					return this->m_pComponents[index];
			}
			return NULL;
		}

		Component* GameObject::GetComponentByIndex(int index)
		{
			if(index < this->m_pComponents.size())
				return this->m_pComponents[index];
			return NULL;
		}

		Component* GameObject::GetComponent(String type)
		{
			unsigned index, count;

			count = this->m_pComponents.size();
			for(index = 0; index < count; ++index)
			{
				if(this->m_pComponents[index]->GetType().Get_FullName().compare(type) == 0)
					return this->m_pComponents[index];
			}
			return NULL;
		}
		
		void GameObject::AddComponent(Component* component) 
		{
			if(component == NULL)
				throw SingularityException("\"component\" cannot be null or empty.");

			//Autolock(this->m_kLock)
			{
				// set the game object to the instance
				component->m_pGameObject = this;
				
				// add the component...duhh!
				this->m_pComponents.push_back(component); 

				// notify the component that is being added to a GameObject
				component->OnComponentAdded(this);
			}
		}

		void GameObject::RemoveComponent(Component* component)
		{
			unsigned index, size;

			//Autolock(this->m_kLock)
			{
				size = this->m_pComponents.size();

				if(component == NULL || size == 0)
					return;

				// find the component index
				for(index = 0; index < size; index++)
					if(component == this->m_pComponents[index])
						break;
					
				// a component was found
				if(index != size)
				{
					// set the game object to NULL
					component->m_pGameObject = NULL;

					// remove the component
					if(size > 1)
						this->m_pComponents[index] = this->m_pComponents[size - 1];
					this->m_pComponents.pop_back();

					// notify the component its going to be removed
					this->m_pComponents[index]->OnComponentRemoved(this);
				}	
			}
		}

		void GameObject::ClearComponents()
		{
			unsigned index, size;

			Autolock(this->m_kLock)
			{
				size = this->m_pComponents.size();

				// notify all of the components that they are being removed
				for(index = 0; index < size; index++)
					this->m_pComponents[index]->OnComponentRemoved(this);

				// clear out the list
				this->m_pComponents.clear();
			}
		}

		void GameObject::Destroy()
		{
			// destroy your children
			this->DetachChildren();

			Autolock(this->m_kLock)
			{	
				this->ClearComponents();

				// remember to remove yourself from the parent object
				if(this->m_pParent != NULL)
					this->m_pParent->DetachChild(this);
			}

			this->m_pScene->DeallocateGameObject(this);
		}
		#pragma endregion

		#pragma region Event Methods
		void GameObject::OnGameObjectAdded(GameObject* parent)
		{
			this->m_pParent = parent;
		}

		void GameObject::OnGameObjectRemoved()
		{
			this->m_pParent = NULL;
		}
		#pragma endregion

		#pragma region Static Methods
		GameObject* GameObject::Create(String name, GameObject* parent, Scene* scene)
		{
			GameObject* obj;

			if(scene == NULL)
				scene = Scene::Get_Current();
			obj = scene->AllocateGameObject(name);
			if(parent)
				parent->AttachChild(obj);

			return obj;
		}
		#pragma endregion
	}
}