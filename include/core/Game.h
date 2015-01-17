#include "core\Singularity.Core.h"

namespace Singularity
{
	class  Game
	{
		protected:
			#pragma region Methods
			virtual void BeginRun() { };
			virtual void EndRun() { };
			#pragma endregion

		public:
			#pragma region Constructors and Finalizers
			Game();
			~Game();
			#pragma endregion

			#pragma region Methods
			void Run();
			#pragma endregion

			#pragma region Static Methods
			static void Exit();
			#pragma endregion
	};
}