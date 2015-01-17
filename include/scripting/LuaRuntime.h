#include "scripting\Singularity.Scripting.h"

using namespace Singularity::Components;

namespace Singularity
{
	namespace Scripting
	{
		class LuaRuntime : public Singularity::Object
		{
			DECLARE_OBJECT_TYPE;

			private:
				#pragma region Static Variables
				static LuaRuntime* g_pInstance;
				#pragma endregion

				#pragma region Constructors and Finalizers
				LuaRuntime();
				~LuaRuntime();
				#pragma endregion

			public:
				#pragma region Variables
				lua_State*		Stack;
				#pragma endregion

				#pragma region Methods
				static void LoadFile(String name);
				static void RegisterFunction(String name, lua_CFunction function);
				static void ExecuteFunction(String name, float value);
				static void Dump();

				static LuaRuntime* Create();
				#pragma endregion
		};
	}
}