#include "graphics\Singularity.Graphics.h"

using namespace Singularity;
using namespace Singularity::Components;

namespace Singularity
{
	namespace Graphics
	{
		IMPLEMENT_OBJECT_TYPE(Singularity.Graphics, Light, Component);

		#pragma region Constructors and Finalizers
		Light::Light(LightType type, Color color) 
			: Component("")
		{
			memset(&this->m_kDescription, 0, sizeof(LIGHT_DESC));
			this->m_kDescription.Color = color;
			this->m_kDescription.Type = type;
			this->m_kDescription.Range = 30.0f;
			this->m_kDescription.Falloff = 2.0f;
			this->m_kDescription.Intensity = 1.0f;

		}

		Light::Light(String name, LightType type, Color color) 
			: Component(name)
		{
			memset(&this->m_kDescription, 0, sizeof(LIGHT_DESC));
			this->m_kDescription.Color = color;
			this->m_kDescription.Type = type;
			this->m_kDescription.Range = 30.0f;
			this->m_kDescription.Falloff = 2.0f;
			this->m_kDescription.Intensity = 1.0f;
		}
		
		Light::~Light() { }
		#pragma endregion

		#pragma region Overriden Methods
		void Light::OnComponentAdded(GameObject* gameObject)
		{
			RenderTask::Instantiate()->RegisterComponent(this);

			/*gameObject = GameObject::Create("light.mesh", gameObject);
			gameObject->AddComponent(new MeshRenderer(Mesh::CreatePrimitive(PrimitiveType::Sphere), Material::CreateBasicMaterial()));
			gameObject->Get_Transform()->Set_Scale(Vector3(0.1f, 0.1f, 0.1f));*/
		}

		void Light::OnComponentRemoved(GameObject* gameObject)
		{
			RenderTask::Instantiate()->UnregisterComponent(this);
		}
		#pragma endregion
	}
}