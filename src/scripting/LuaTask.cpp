#include "scripting\Singularity.Scripting.h"
 
using namespace Singularity;
using namespace Singularity::Components;
using namespace Singularity::Threading;
 
namespace Singularity
{
	namespace Scripting
	{
		IMPLEMENT_OBJECT_TYPE(Singularity.Scripting, LuaTask, Singularity::Threading::Task);

		#pragma region Static Variables
		LuaTask* LuaTask::g_pInstance = NULL; 
		#pragma endregion

		#pragma region Constructors and Finalizers
		LuaTask::LuaTask()
			: Task("Lua Task"), m_pRuntime(NULL)
		{
			unsigned index = 0;

			this->Set_Frequency(1 / 60.f);

			for(index = 0; index < SINGULARITY_SCRIPTING_MAX_SUBTASKS; ++index)
				this->m_pSubTasks[index] = new LuaSubTask();
		}
		#pragma endregion

		#pragma region Methods
		void LuaTask::RegisterComponent(Component* component)
		{
			if(component == NULL)
				throw SingularityException("\"component\" cannot be null or empty.");
			
			if(component->GetType().Equals(LuaBinder::Type))
				this->m_pBinders.insert((LuaBinder*)component);
		}

		void LuaTask::UnregisterComponent(Component* component)
		{
			if(component == NULL)
				throw SingularityException("\"component\" cannot be null or empty.");

			if(component->GetType().Equals(LuaBinder::Type))
				this->m_pBinders.erase((LuaBinder*)component);
		}

		void LuaTask::RegisterDelegate(ILuaDelegate* method)
		{
			if(method == NULL)
				throw SingularityException("\"method\" cannot be null or empty.");
			
			this->m_pDelegates.insert(method);
		}

		void LuaTask::UnregisterDelegate(ILuaDelegate* method)
		{
			if(method == NULL)
				throw SingularityException("\"method\" cannot be null or empty.");
			
			this->m_pDelegates.erase(method);
		}
		#pragma endregion
 
		#pragma region Overriden Methods
		void LuaTask::OnExecute()
		{
			DynamicSet<LuaBinder*>::iterator it0;
			DynamicSet<ILuaDelegate*>::iterator it1;
			#if _DEBUG
			//printf("Scripting Call Frequency = %3.1f\n", this->Get_ActualFrequency());
			#endif

			if(this->m_pRuntime == NULL)
				this->m_pRuntime = LuaRuntime::Create();

			for(it0 = this->m_pBinders.begin(); it0 != this->m_pBinders.end(); ++it0)
			{
				if((*it0)->Get_Enabled())
					(*it0)->OnExecute(this->m_pRuntime->Stack, this->Get_ElapsedTime());
			}

			for(it1 = this->m_pDelegates.begin(); it1 != this->m_pDelegates.end(); ++it1)
				(*it1)->InternalInvoke(this->m_pRuntime->Stack);

			this->Recycle();
		}
		#pragma endregion

		#pragma region Static Methods
		LuaTask* LuaTask::Instantiate()
		{
			if(!LuaTask::g_pInstance)
				LuaTask::g_pInstance = new LuaTask();
			return LuaTask::g_pInstance;
		}
		#pragma endregion
	}
}