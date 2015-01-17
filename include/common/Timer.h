#include "common\Singularity.Common.h"

namespace Singularity
{
	class Timer
	{
		private:
			#pragma region Variables
			double m_dSecondsPerCount;
			__int64 m_iStartTime;
			__int64 m_iCurrTime;

			bool m_bStopped;
			#pragma endregion
		
		public:
			#pragma region Properties
			const float Get_ElapsedTime() const;
			const float Get_TotalTime() const;
			#pragma endregion

			#pragma region Constructors and Finalizers
			Timer();
			#pragma endregion

			#pragma region Methods
			void Start();
			void Stop();
			void Tick();
			void Reset();
			#pragma endregion
	};
}