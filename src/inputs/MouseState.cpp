#include "inputs\Singularity.Inputs.h"

namespace Singularity
{
	namespace Inputs
	{
		#pragma region Methods
		Vector2 MouseState::GetMousePosition()
		{
			return this->m_kPosition;
		}

		bool MouseState::GetMouseButton(int button)
		{
			return this->m_kState.rgbButtons[button];
		}
		#pragma endregion

		#pragma region Overriden Operators
		bool MouseState::operator==(const MouseState &other) const
		{
			return this->m_iId == other.m_iId;
		}

		bool MouseState::operator!=(const MouseState &other) const
		{
			return this->m_iId != other.m_iId;
		}
		#pragma endregion
	}
}