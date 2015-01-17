#include "scripting\Singularity.Scripting.h"

namespace Singularity
{
	namespace Scripting
	{
		class LuaBinder : public Singularity::Components::Component
		{
			DECLARE_OBJECT_TYPE;

			private:
				#pragma region Variables
				bool			m_bLoaded;
				unsigned		m_pFunctionIndex;
				String			m_pPath;
				String			m_pFunctionCallback;
				#pragma endregion

			protected:
				#pragma region Overriden Methods
				virtual void OnComponentAdded(Singularity::Components::GameObject* gameObject);
				virtual void OnComponentRemoved(Singularity::Components::GameObject* gameObject);
				virtual void OnExecute(lua_State* state, float elapsedTime);
				#pragma endregion

			public:
				#pragma region Constructors and Finalizers
				String Get_Path() const;
				void Set_Path(String value);

				String Get_FunctionName() const;
				void Set_FunctionName(String value);
				#pragma endregion

				#pragma region Constructors and Finalizers
				LuaBinder(String name = "") : Component(name), m_bLoaded(false), m_pFunctionCallback("OnUpdate") { };
				~LuaBinder() { };
				#pragma endregion

				friend class LuaTask;
				friend class LuaSubTask;
		};

		#include "scripting\LuaBinder.inc"
	}
}