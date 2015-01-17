#include "inputs\Singularity.Inputs.h"

namespace Singularity
{
	namespace Inputs
	{
		#pragma region Static Methods
		MouseState Input::GetMouseState()
		{
			return InputTask::Instantiate()->m_kMouseState[InputTask::Instantiate()->m_iBufferIndex];
		}

		KeyboardState Input::GetKeyboardState()
		{
			return InputTask::Instantiate()->m_kKeyboardState[InputTask::Instantiate()->m_iBufferIndex];
		}

		void Input::ResetMousePosition()
		{
			InputTask::Instantiate()->m_bResetMouse = true;
		}

		void Input::SetMousePosition(int x, int y)
		{
			WINDOWINFO info;
			::GetWindowInfo(InputTask::Instantiate()->m_kHwnd, &info);
			::SetCursorPos(info.rcClient.left + x, info.rcClient.top + y);
		}

		Vector2 Input::GetMousePosition()
		{
			return InputTask::Instantiate()->m_kMouseState[InputTask::Instantiate()->m_iBufferIndex].GetMousePosition();
		}

		bool Input::GetMouseButton(int button)
		{
			return InputTask::Instantiate()->m_kMouseState[InputTask::Instantiate()->m_iBufferIndex].GetMouseButton(button);
		}

		bool Input::IsKeyDown(int key)
		{
			return InputTask::Instantiate()->m_kKeyboardState[InputTask::Instantiate()->m_iBufferIndex].IsKeyDown(key);
		}

		bool Input::IsKeyUp(int key)
		{
			return InputTask::Instantiate()->m_kKeyboardState[InputTask::Instantiate()->m_iBufferIndex].IsKeyUp(key);
		}
		#pragma endregion
	}
}