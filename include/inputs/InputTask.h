#include "inputs\Singularity.Inputs.h"

namespace Singularity
{
	namespace Inputs
	{
		class InputTask : public Singularity::Threading::Task
		{
			DECLARE_OBJECT_TYPE;

			private:
				#pragma region Static Variables
				static InputTask* g_pInstance;
				#pragma endregion

				#pragma region Variables
				HWND					m_kHwnd;
				IDirectInput8*			m_pInputContext;

				bool					m_bResetMouse;
				volatile unsigned		m_iBufferIndex;
				MouseState				m_kMouseState[2];
				KeyboardState			m_kKeyboardState[2];

				IDirectInputDevice8*	m_pKeyboardDevice;
				IDirectInputDevice8*	m_pMouseDevice;
				#pragma endregion

				#pragma region Constructors and Finalizers
				InputTask();
				#pragma endregion

				#pragma region Methods
				IDirectInputDevice8* InitializeKeyboard(IDirectInput8* inputContext);
				IDirectInputDevice8* InitializeMouse(IDirectInput8* inputContext);

				void UpdateKeyboardState(KeyboardState* state);
				void UpdateMouseState(MouseState* state);
				#pragma endregion

				#pragma region Static Methods
				static HWND GetWindowHandle(DWORD instance);
				#pragma endregion

			protected:
				#pragma region Event Methods
				virtual void OnInitialize() { }
				virtual void OnUninitialize() { }

				virtual void OnExecute();
				virtual void OnComplete() { };
				#pragma endregion

			public:
				#pragma region Constructors and Finalizers
				~InputTask();
				#pragma endregion

				#pragma region Static Methods
				static InputTask* Instantiate();
				#pragma endregion

				friend class Input;
				friend class KeyboardExtension;
		};
	}
}