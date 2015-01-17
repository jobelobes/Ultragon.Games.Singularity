#include "core\Singularity.Core.h"

namespace Singularity
{
	namespace Components
	{
		class Extension : public Singularity::Threading::Task
		{
			DECLARE_OBJECT_TYPE;

			private:
				#pragma region Variables
				bool	m_bInitialized;
				#pragma endregion

			protected:
				#pragma region Constructors and Finalizers
				Extension(String name) : Singularity::Tasks::Task(name), m_bInitialized(false) { }
				~Extension() { }
				#pragma endregion

				#pragma region Methods
				virtual void OnInitialize() = 0;
				virtual void OnUninitialize() = 0;
				#pragma endregion

				#pragma region Overriden Methods
				void OnExecute();
				#pragma endregion
		};
	}
}