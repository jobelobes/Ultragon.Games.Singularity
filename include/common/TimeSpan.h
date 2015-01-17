#include "common\Singularity.Common.h"

namespace Singularity
{
	class TimeSpan
	{
		private:
			#pragma region Variables
			__int64 m_iTicks;
			#pragma endregion
		
		public:
			#pragma region Variables
			static __int64 TicksPerHour;
			static __int64 TicksPerMinute;
			static __int64 TicksPerSecond;
			static __int64 TicksPerMillisecond;
			#pragma endregion

			#pragma region Properties
			const int Get_Hours() const;
			const int Get_Minutes() const;
			const int Get_Seconds() const;
			const int Get_Milliseconds() const;
			inline const __int64 Get_Ticks() const { return this->m_iTicks; };
			inline const double Get_TotalHours() const { return (double)this->m_iTicks / (double)TimeSpan::TicksPerHour; };
			inline const double Get_TotalMinutes() const { return (double)this->m_iTicks / (double)TimeSpan::TicksPerHour; };
			inline const double Get_TotalSeconds() const { return (double)this->m_iTicks / (double)TimeSpan::TicksPerHour; };
			#pragma endregion

			#pragma region Constructors and Finalizers
			TimeSpan(__int64 ticks);
			TimeSpan(int hours, int minutes, int seconds);
			#pragma endregion

			#pragma region Methods
			TimeSpan Add(TimeSpan& span);
			TimeSpan Subtract(TimeSpan& span);
			#pragma endregion

			#pragma region Static Methods
			static TimeSpan FromHours(double value);
			static TimeSpan FromMinutes(double value);
			static TimeSpan FromSeconds(double value);
			static TimeSpan FromMilliseconds(double value);
			static TimeSpan FromTicks(__int64 value);
			#pragma endregion
	};
}