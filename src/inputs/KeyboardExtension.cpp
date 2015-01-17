#include "inputs\Singularity.Inputs.h"

namespace Singularity
{
	namespace Inputs
	{
		IMPLEMENT_OBJECT_TYPE(Singularity.Inputs, KeyboardExtension, Extension);

		#pragma region Constructors and Finalizers
		KeyboardExtension::KeyboardExtension(HWND handle, IDirectInput8* inputContext)
			: Extension("Keyboard Extension"), m_pInputContext(inputContext), m_pKeyboardDevice(NULL), m_iBufferIndex(0)
		{
			if(FAILED(this->m_pInputContext->CreateDevice(GUID_SysKeyboard, &this->m_pKeyboardDevice, NULL)))
				throw SingularityException("Unable to find keyboard device.");
			if(FAILED(this->m_pKeyboardDevice->SetDataFormat(&c_dfDIKeyboard)))
				throw SingularityException("Unable to find keyboard device.");
			if(FAILED(this->m_pKeyboardDevice->SetCooperativeLevel(handle, DISCL_BACKGROUND | DISCL_NONEXCLUSIVE)))
				throw SingularityException("Unable to find keyboard device.");
			if(FAILED(this->m_pKeyboardDevice->Acquire()))
				throw SingularityException("Unable to find keyboard device.");
		}

		KeyboardExtension::~KeyboardExtension()
		{
			if(this->m_pKeyboardDevice)
			{
				this->m_pKeyboardDevice->Unacquire();
				this->m_pKeyboardDevice->Release();
				this->m_pKeyboardDevice = NULL;
			}
		}
		#pragma endregion

		#pragma region Event Methods
		void KeyboardExtension::OnExecute()
		{
			InputBuffer* inputbuffer;
			HRESULT hr;
			HWND hwnd;
			unsigned index;
			unsigned char buffer[256];

			inputbuffer = &((InputExtension*)this->Get_ParentTask())->m_kInputBuffer[this->m_iBufferIndex];
			
			if(this->m_pKeyboardDevice)
			{
				// get the input state
				hr = this->m_pKeyboardDevice->GetDeviceState(sizeof(buffer), (void**)&buffer);
				if( FAILED(hr) && (hr == DIERR_INPUTLOST || hr == DIERR_NOTACQUIRED) )
				{
					if(SUCCEEDED(this->m_pKeyboardDevice->Acquire()))
						this->m_pKeyboardDevice->GetDeviceState(sizeof(buffer), (void**)&buffer);
					else
						ZeroMemory(&buffer, sizeof(buffer));
				}

				for(index = 0; index < 256; ++index)
				{
					//inputbuffer->KeyStates[index] = (KeyState)(buffer[index] | (inputbuffer->KeyStates[index] ^ (buffer[index] >> 7)));
					inputbuffer->KeyStates[index] = (KeyState)buffer[index];
				}
			}
		}
		#pragma endregion
	}
}