#include "core\Singularity.Core.h"

namespace Singularity // tolua_export
{
	namespace Components // tolua_export
	{
		class Component : public Singularity::Object // tolua_export
		{
			DECLARE_OBJECT_TYPE

			private:
				#pragma region Variables
				bool				m_bEnabled;
				String				m_pName;
				GameObject*			m_pGameObject;
				#pragma endregion

			protected:
				#pragma region Constructors and Finalizers
				Component(String tag = "");
				#pragma endregion
				
				#pragma region Methods
				virtual void OnInitialize() { }
				virtual void OnUninitialize() { }

				virtual void OnComponentAdded(GameObject* gameObject) { }
				virtual void OnComponentRemoved(GameObject* gameObject) { }
				#pragma endregion

			public:
				#pragma region Properties
				String Get_Name() const;

				GameObject* Get_GameObject() const;

				const bool Get_Enabled() const;
				void Set_Enabled(const bool value);
				#pragma endregion

				friend class GameObject;
		};

		#include "core\components\Component.inc"
	}
}