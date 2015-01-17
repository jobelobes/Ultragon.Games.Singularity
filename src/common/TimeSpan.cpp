#include "common\Singularity.Common.h"

namespace Singularity
{
	#pragma region Variables
	__int64 TimeSpan::TicksPerHour;
	__int64 TimeSpan::TicksPerMinute;
	__int64 TimeSpan::TicksPerSecond;
	__int64 TimeSpan::TicksPerMillisecond;
	#pragma endregion

	#pragma region Properties
	const int TimeSpan::Get_Hours() const 
	{ 
		return (int)floor((double)this->m_iTicks / (double)TimeSpan::TicksPerMinute); 
	}

	const int TimeSpan::Get_Minutes() const 
	{ 
		return (int)floor((double)(this->m_iTicks % TimeSpan::TicksPerHour) / TimeSpan::TicksPerMinute); 
	}

	const int TimeSpan::Get_Seconds() const 
	{ 
		return (int)floor((double)(this->m_iTicks % TimeSpan::TicksPerMinute) / TimeSpan::TicksPerSecond); 
	}
	const int TimeSpan::Get_Milliseconds() const 
	{ 
		return (int)floor((double)(this->m_iTicks % TimeSpan::TicksPerSecond) / TimeSpan::TicksPerMillisecond); 
	}
	#pragma endregion

	#pragma region Constructors and Finalizers
	TimeSpan::TimeSpan(__int64 ticks)
	{
		if(TimeSpan::TicksPerSecond == 0)
		{
			::QueryPerformanceFrequency((LARGE_INTEGER*)&TimeSpan::TicksPerSecond);
			TimeSpan::TicksPerMinute = TimeSpan::TicksPerSecond / 60;
			TimeSpan::TicksPerHour = TimeSpan::TicksPerMinute / 60;
			TimeSpan::TicksPerMillisecond = TimeSpan::TicksPerSecond * 1000;
		}

		this->m_iTicks = ticks;
	}

	TimeSpan::TimeSpan(int hours, int minutes, int seconds)
	{
		if(TimeSpan::TicksPerSecond == 0)
		{
			::QueryPerformanceFrequency((LARGE_INTEGER*)&TimeSpan::TicksPerSecond);
			TimeSpan::TicksPerMinute = TimeSpan::TicksPerSecond / 60;
			TimeSpan::TicksPerHour = TimeSpan::TicksPerMinute / 60;
			TimeSpan::TicksPerMillisecond = TimeSpan::TicksPerSecond * 1000;
		}

		this->m_iTicks = TimeSpan::TicksPerHour * hours + TimeSpan::TicksPerMinute * minutes + TimeSpan::TicksPerSecond * seconds;
	}
	#pragma endregion

	#pragma region Static Methods
	TimeSpan TimeSpan::FromHours(double value)
	{
		int hours, minutes, seconds, milliseconds;

		hours = (int)floor(value);
		value = (value - hours) * 60;
		minutes = (int)floor(value);
		value = (value - minutes) * 60;
		seconds = (int)floor(value);
		value = (value - seconds) * 1000;
		milliseconds = (int)floor(value);

		return TimeSpan(TimeSpan::TicksPerHour * hours + TimeSpan::TicksPerMinute * minutes + TimeSpan::TicksPerSecond * seconds + TimeSpan::TicksPerMillisecond * milliseconds);
	}

	TimeSpan TimeSpan::FromMinutes(double value)
	{
		int minutes, seconds, milliseconds;

		minutes = (int)floor(value);
		value = (value - minutes) * 60;
		seconds = (int)floor(value);
		value = (value - seconds) * 1000;
		milliseconds = (int)floor(value);

		return TimeSpan(TimeSpan::TicksPerMinute * minutes + TimeSpan::TicksPerSecond * seconds + TimeSpan::TicksPerMillisecond * milliseconds);
	}

	TimeSpan TimeSpan::FromSeconds(double value)
	{
		int seconds, milliseconds;

		seconds = (int)floor(value);
		value = (value - seconds) * 1000;
		milliseconds = (int)floor(value);

		return TimeSpan(TimeSpan::TicksPerSecond * seconds + TimeSpan::TicksPerMillisecond * milliseconds);
	}

	TimeSpan TimeSpan::FromMilliseconds(double value)
	{
		return TimeSpan(TimeSpan::TicksPerMillisecond * (int)floor(value));
	}

	TimeSpan TimeSpan::FromTicks(__int64 value)
	{
		return TimeSpan(value);
	}
	#pragma endregion
}