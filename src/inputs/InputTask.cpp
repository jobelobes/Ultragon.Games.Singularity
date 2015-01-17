#include "inputs\Singularity.Inputs.h"

using namespace Singularity::Threading;
using namespace Singularity::Graphics;

namespace Singularity
{
	namespace Inputs
	{
		IMPLEMENT_OBJECT_TYPE(Singularity.Inputs, InputTask, Singularity::Threading::Task);

		#pragma region Static Variables
		InputTask* InputTask::g_pInstance = NULL;
		#pragma endregion

		#pragma region Constructors and Finalizers
		InputTask::InputTask()
			: Task("Input Extension"), m_iBufferIndex(0), m_pInputContext(NULL), m_pKeyboardDevice(NULL), m_pMouseDevice(NULL), m_bResetMouse(false)
		{
			this->Set_Frequency(1 / 60.0f);

			this->m_kKeyboardState[0].m_iId = 0;
			this->m_kKeyboardState[1].m_iId = 1;
			this->m_kMouseState[0].m_iId = 0;
			this->m_kMouseState[1].m_iId = 1;
		}

		InputTask::~InputTask()
		{
			if(this->m_pMouseDevice)
			{
				this->m_pMouseDevice->Unacquire();
				this->m_pMouseDevice->Release();
				this->m_pMouseDevice = NULL;
			}

			if(this->m_pKeyboardDevice)
			{
				this->m_pKeyboardDevice->Unacquire();
				this->m_pKeyboardDevice->Release();
				this->m_pKeyboardDevice = NULL;
			}

			if(this->m_pInputContext)
			{
				this->m_pInputContext->Release();
				this->m_pInputContext = NULL;
			}
		}
		#pragma endregion

		#pragma region Methods
		IDirectInputDevice8* InputTask::InitializeKeyboard(IDirectInput8* inputContext)
		{
			IDirectInputDevice8* device;

			if(FAILED(this->m_pInputContext->CreateDevice(GUID_SysKeyboard, &device, NULL)))
				throw SingularityException("Unable to find keyboard device.");
			if(FAILED(device->SetDataFormat(&c_dfDIKeyboard)))
				throw SingularityException("Unable to find keyboard device.");
			if(FAILED(device->SetCooperativeLevel(this->m_kHwnd, DISCL_FOREGROUND | DISCL_EXCLUSIVE | DISCL_NOWINKEY)))
				throw SingularityException("Unable to find keyboard device.");

			return device;
		}

		IDirectInputDevice8* InputTask::InitializeMouse(IDirectInput8* inputContext)
		{
			IDirectInputDevice8* device;

			if(FAILED(this->m_pInputContext->CreateDevice(GUID_SysMouse, &device, NULL)))
				throw SingularityException("Unable to find mouse device.");
			if(FAILED(device->SetDataFormat(&c_dfDIMouse)))
				throw SingularityException("Unable to find mouse device.");
		
			return device;
		}

		void InputTask::UpdateKeyboardState(KeyboardState* state)
		{
			HRESULT hr;

			if(this->m_pKeyboardDevice)
			{
				// get the input state
				hr = this->m_pKeyboardDevice->GetDeviceState(sizeof(state->m_kKeys), (void**)&state->m_kKeys);
				if( FAILED(hr) && (hr == DIERR_INPUTLOST || hr == DIERR_NOTACQUIRED) )
				{
					if(SUCCEEDED(this->m_pKeyboardDevice->Acquire()))
						this->m_pKeyboardDevice->GetDeviceState(sizeof(state->m_kKeys), (void**)&state->m_kKeys);
					else
						ZeroMemory(&state->m_kKeys, sizeof(state->m_kKeys));
				}
			}
		}

		void InputTask::UpdateMouseState(MouseState* state)
		{
			HRESULT hr;
			POINT mousePosition;
			WINDOWINFO info;

			if(this->m_pMouseDevice)
			{
				hr = this->m_pMouseDevice->GetDeviceState(sizeof(DIMOUSESTATE), (void**)&state->m_kState);
				if(FAILED(hr) && (hr == DIERR_INPUTLOST || hr == DIERR_NOTACQUIRED) )
				{
					if(FAILED(this->m_pMouseDevice->Acquire()))
						return;
					
					this->m_pMouseDevice->GetDeviceState(sizeof(DIMOUSESTATE), (void**)&state->m_kState);
				}

				::GetWindowInfo(this->m_kHwnd, &info);
				::GetCursorPos(&mousePosition);
				mousePosition.x -= info.rcClient.left;
				mousePosition.y -= info.rcClient.top;
				state->m_kPosition = Vector2((float)mousePosition.x, (float)mousePosition.y);

				if(this->m_bResetMouse)
				{
					::SetCursorPos(info.rcClient.left + (info.rcClient.right - info.rcClient.left) / 2, info.rcClient.top + (info.rcClient.bottom - info.rcClient.top) / 2);
					this->m_bResetMouse = false;
				}
			}
		}
		#pragma endregion

		#pragma region Event Methods
		void InputTask::OnExecute()
		{
			InputBuffer* buffer = NULL;

			#if _DEBUG
			//printf("Input Call Frequency = %3.1f\n", this->Get_ActualFrequency());
			#endif

			if(this->m_pInputContext == NULL)
			{
				this->m_kHwnd = GetWindowHandle((DWORD)::GetCurrentProcessId());
				::DirectInput8Create(::GetModuleHandle(NULL), DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&this->m_pInputContext, NULL);
			}

			if(this->m_pKeyboardDevice == NULL)
				this->m_pKeyboardDevice = this->InitializeKeyboard(this->m_pInputContext);

			if(this->m_pMouseDevice == NULL)
				this->m_pMouseDevice = this->InitializeMouse(this->m_pInputContext);

			_InterlockedXor((LONG*)&this->m_iBufferIndex, 1); // swap between 0 and 1

			this->UpdateKeyboardState(&this->m_kKeyboardState[this->m_iBufferIndex]);
			this->UpdateMouseState(&this->m_kMouseState[this->m_iBufferIndex]);

			// bad fix
			if(this->m_kKeyboardState[this->m_iBufferIndex].IsKeyDown(DIK_ESCAPE))
				Game::Exit();

			this->Recycle();
		}
		#pragma endregion

		#pragma region Static Methods
		HWND InputTask::GetWindowHandle(DWORD instance)
		{
			HWND hwnd;
			DWORD procId;

			hwnd = ::FindWindow(NULL, NULL);
			while(hwnd != NULL)
			{
				if(::GetParent(hwnd) == NULL)
				{
					::GetWindowThreadProcessId(hwnd, &procId);
					if(procId == instance)
						return hwnd;
				}
				hwnd = GetWindow(hwnd, GW_HWNDNEXT);
			}
			return hwnd;
		}

		InputTask* InputTask::Instantiate()
		{
			if(!InputTask::g_pInstance)
				InputTask::g_pInstance = new InputTask();
			return InputTask::g_pInstance;
		}
		#pragma endregion
	}
}