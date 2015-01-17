#include "core\Singularity.Core.h"

namespace Singularity
{
	namespace Components
	{
		IMPLEMENT_OBJECT_TYPE(Singularity.Components, Component, Object);

		#pragma region Constructors and Finalizers
		Component::Component(String tag) 
			: m_bEnabled(true), m_pGameObject(NULL), m_pName(tag) { }
		#pragma endregion
	}
}