#include "scripting\Singularity.Scripting.h"

using namespace Singularity::Components;

namespace Singularity
{
	namespace Scripting
	{
		class LuaTask : public Singularity::Threading::Task
		{
			DECLARE_OBJECT_TYPE;

			private:
				#pragma region Static Variables
				static LuaTask* g_pInstance;
				#pragma endregion

				#pragma region Variables
				LuaRuntime*					m_pRuntime;
				DynamicSet<LuaBinder*>		m_pBinders;
				DynamicSet<ILuaDelegate*>		m_pDelegates;

				LuaSubTask*					m_pSubTasks[SINGULARITY_SCRIPTING_MAX_SUBTASKS];
				#pragma endregion

				#pragma region Constructors and Finalizers
				LuaTask();
				~LuaTask() { };
				#pragma endregion

			protected:
				#pragma region Event Methods
				virtual void OnExecute();
				virtual void OnComplete() { };
				#pragma endregion

			public:
				#pragma region Methods
				void RegisterComponent(Component* component);
				void UnregisterComponent(Component* component);
				void RegisterDelegate(ILuaDelegate* method);
				void UnregisterDelegate(ILuaDelegate* method);
				#pragma endregion

				#pragma region Static Methods
				static LuaTask* Instantiate();
				#pragma endregion

				friend class LuaBinder;
				friend class LuaSubTask;
		};
	}
}