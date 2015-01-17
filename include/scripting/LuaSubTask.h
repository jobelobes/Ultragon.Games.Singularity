#include "scripting\Singularity.Scripting.h"

using namespace Singularity::Components;

namespace Singularity
{
	namespace Scripting
	{
		class LuaSubTask : public Singularity::Threading::Task
		{
			DECLARE_OBJECT_TYPE;

			private:
				#pragma region Variables
				CriticalSection	m_kLock;
				unsigned		m_iStart;
				unsigned		m_iEnd;
				float			m_fElapsed;
				LuaRuntime*		m_pRuntime;
				#pragma endregion

				#pragma region Constructors and Finalizers
				LuaSubTask() : Task("Lua sub task"), m_pRuntime(NULL), m_iStart(0), m_iEnd(0) { };
				~LuaSubTask() { };
				#pragma endregion

			protected:
				#pragma region Methods
				void Update(LuaRuntime* runtime, unsigned start, unsigned end, float elapsed);
				#pragma endregion

				#pragma region Event Methods
				void OnExecute();
				void OnComplete() { };
				#pragma endregion

				friend class LuaTask;
		};
	}
}