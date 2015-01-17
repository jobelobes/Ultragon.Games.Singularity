#include "core\Singularity.Core.h"

namespace Singularity
{
	class GameTask : public Singularity::Threading::Task
	{
		DECLARE_OBJECT_TYPE;

		private:
			#pragma region Static Variables
			static GameTask* g_pInstance;
			#pragma endregion

			#pragma region Constructors and Finalizers
			GameTask();
			~GameTask();
			#pragma endregion

		protected:
			#pragma region Event Methods
			virtual void OnExecute();
			virtual void OnComplete() { };
			#pragma endregion

			#pragma region Methods
			void Release();
			#pragma endregion

		public:
			#pragma region Static Methods
			static GameTask* Instantiate();
			#pragma endregion
	};
}