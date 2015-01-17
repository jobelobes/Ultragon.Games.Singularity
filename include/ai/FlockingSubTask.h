#include "ai\Singularity.AI.h"

using namespace Singularity::Threading;
using namespace Singularity::Components;

namespace Singularity
{
	namespace AI
	{
		class FlockingSubTask : public Singularity::Components::Extension
		{
			DECLARE_OBJECT_TYPE;

			private:
				#pragma region Variables
				float						m_fElapsedTime;
				unsigned					m_iStart;
				unsigned					m_iEnd;
				#pragma endregion

			protected:
				#pragma region Event Methods
				virtual void OnInitialize() { }
				virtual void OnExecute();
				virtual void OnComplete() { };
				virtual void OnUninitialize() { };
				#pragma endregion

			public:
				#pragma region Constructors and Finalizers
				FlockingSubTask();
				~FlockingSubTask();
				#pragma endregion

				#pragma region Methods
				void Update(float elapsedTime, unsigned start, unsigned end);
				#pragma endregion
		};
	}
}