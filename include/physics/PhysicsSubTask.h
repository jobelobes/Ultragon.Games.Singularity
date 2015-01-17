#include "physics\Singularity.Physics.h"

using namespace Singularity::Threading;
using namespace Singularity::Components;

namespace Singularity
{
	namespace Physics
	{
		class PhysicsSubTask : public Singularity::Threading::Task
		{
			DECLARE_OBJECT_TYPE;

			private:
				#pragma region Variables
				PhysicsTask*				m_pParent;
				float						m_fElapsedTime;
				unsigned					m_iStart;
				unsigned					m_iEnd;
				#pragma endregion

				#pragma region Constructors and Finalizers
				PhysicsSubTask();
				~PhysicsSubTask();
				#pragma endregion

				#pragma region Methods
				void Update(const float elapsedTime, unsigned start, unsigned end);
				#pragma endregion

			protected:
				#pragma region Event Methods
				void OnExecute();
				void OnComplete() { };
				#pragma endregion

				friend class PhysicsTask;
		};
	}
}