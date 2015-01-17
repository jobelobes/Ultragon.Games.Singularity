#include "inputs\Singularity.Inputs.h"

namespace Singularity
{
	namespace Inputs
	{
		#pragma region Constructors and Finalizers
		KeyboardState::KeyboardState()
		{
			memset(&this->m_kKeys, 0, sizeof(unsigned char) * 256);
		}
		#pragma endregion

		#pragma region Methods
		bool KeyboardState::IsKeyDown(int key)
		{
			return this->m_kKeys[key];
		}

		bool KeyboardState::IsKeyUp(int key)
		{
			return !this->m_kKeys[key];
		}
		#pragma endregion

		#pragma region Overriden Operators
		bool KeyboardState::operator==(const KeyboardState &other) const
		{
			return this->m_iId == other.m_iId;
		}

		bool KeyboardState::operator!=(const KeyboardState &other) const
		{
			return this->m_iId != other.m_iId;
		}
		#pragma endregion
	}
}