#include "audio\Singularity.Audio.h"

namespace Singularity
{
	namespace Audio
	{
		#pragma region Constructors and Finalizers

			AdaptiveParameter::AdaptiveParameter(String name, float min, float max) : m_pName(name), m_fMin(min), m_fMax(max), m_fCurrent(min)
			{

			}

			AdaptiveParameter::~AdaptiveParameter()
			{

			}

			String AdaptiveParameter::GetName()
			{
				return m_pName;
			}

			float AdaptiveParameter::GetMin()
			{
				return m_fMin;
			}

			float AdaptiveParameter::GetMax()
			{
				return m_fMax;
			}

			float AdaptiveParameter::GetCurrentValue()
			{
				return m_fCurrent;
			}

			void AdaptiveParameter::SetName(String name)
			{
				this->m_pName = name;
			}

			void AdaptiveParameter::SetMin(float min)
			{
				this->m_fMin = min;
				this->m_fCurrent = min;
			}

			void AdaptiveParameter::SetMax(float max)
			{
				this->m_fMax = max;
			}

			void AdaptiveParameter::SetCurrentValue(float value)
			{
				this->m_fCurrent = value;
				if (m_fCurrent > m_fMax)
				{
					m_fCurrent = m_fMax;
				}
				if (m_fCurrent < m_fMin)
				{
					m_fCurrent = m_fMin;
				}
			}

		#pragma endregion
	}
}