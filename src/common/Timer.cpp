#include "common\Singularity.Common.h"

namespace Singularity
{
	#pragma region Properties
	const float Timer::Get_ElapsedTime() const
	{
		if(this->m_bStopped)
			return 0.0f;

		__int64 currTime;
		::QueryPerformanceCounter((LARGE_INTEGER*)(&currTime));
		return (float)((currTime - this->m_iCurrTime) * this->m_dSecondsPerCount);
	}

	const float Timer::Get_TotalTime() const
	{
		if(this->m_bStopped)
			return 0.0f;

		__int64 currTime;
		::QueryPerformanceCounter((LARGE_INTEGER*)(&currTime));
		return (float)((currTime - this->m_iStartTime) * this->m_dSecondsPerCount);
	}
	#pragma endregion

	#pragma region Constructors and Finalizers
	Timer::Timer()
	{
		this->m_iCurrTime = 0;
		this->m_iStartTime = 0;
		this->m_bStopped = false;

		this->Reset();
	}
	#pragma endregion

	#pragma region Methods
	void Timer::Start()
	{
		if(!this->m_bStopped)
			return;

		::QueryPerformanceCounter((LARGE_INTEGER*)(&this->m_iStartTime));
	}

	void Timer::Tick()
	{
		if(this->m_bStopped)
			return;

		::QueryPerformanceCounter((LARGE_INTEGER*)(&this->m_iCurrTime));
	}
	void Timer::Stop()
	{
		this->Tick();
		this->m_bStopped = true;
	}

	void Timer::Reset()
	{
		__int64 countsPerSec;
		::QueryPerformanceFrequency((LARGE_INTEGER*)&countsPerSec);
		::QueryPerformanceCounter((LARGE_INTEGER*)(&this->m_iStartTime));
		this->m_dSecondsPerCount = 1.0 / countsPerSec;
		this->m_iCurrTime = this->m_iStartTime;
		this->m_bStopped = false;
	}
	#pragma endregion
}