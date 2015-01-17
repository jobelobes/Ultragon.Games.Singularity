#include "inputs\Singularity.Inputs.h"

namespace Singularity
{
	namespace Inputs
	{
		IMPLEMENT_OBJECT_TYPE(Singularity.Inputs, MouseExtension, Extension);

		#pragma region Constructors and Finalizers
		MouseExtension::MouseExtension(HWND handle, IDirectInput8* inputContext)
			: Extension("Input Extension"), m_pInputContext(inputContext), m_pMouseDevice(NULL), m_pBuffer(NULL)
		{
			this->m_pInputContext->CreateDevice(GUID_SysMouse, &this->m_pMouseDevice, NULL);
			this->m_pMouseDevice->SetDataFormat(&c_dfDIMouse);
			//this->m_pMouseDevice->SetCooperativeLevel(handle, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE);
			this->m_pMouseDevice->Acquire();
		}

		MouseExtension::~MouseExtension()
		{
			if(this->m_pMouseDevice)
			{
				this->m_pMouseDevice->Unacquire();
				this->m_pMouseDevice->Release();
				this->m_pMouseDevice = NULL;
			}
		}
		#pragma endregion

		#pragma region Event Methods
		void MouseExtension::OnExecute()
		{
			HRESULT hr;
			HWND hwnd;

			// if you don't have what you need, just quit!
			if(this->m_pBuffer == NULL)
				return;

			if(this->m_pMouseDevice)
			{
				hr = this->m_pMouseDevice->GetDeviceState(sizeof(DIMOUSESTATE), (void**)&this->m_pBuffer->MouseState);
				if( FAILED(hr) && (hr == DIERR_INPUTLOST || hr == DIERR_NOTACQUIRED) )
				{
					if(SUCCEEDED(this->m_pMouseDevice->Acquire()))
						this->m_pMouseDevice->GetDeviceState(sizeof(DIMOUSESTATE), (void**)&this->m_pBuffer->MouseState);
					else
						return;
				}
				::GetCursorPos(&this->m_pBuffer->MousePosition);
			}
		}
		#pragma endregion
	}
}