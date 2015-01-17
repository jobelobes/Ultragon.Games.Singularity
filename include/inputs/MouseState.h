#include "inputs\Singularity.Inputs.h"

namespace Singularity
{
	namespace Inputs
	{
		class MouseState
		{
			private:
				#pragma region Static Methods
				unsigned		m_iId;
				bool			m_bReset;
				Vector2			m_kPosition;
				DIMOUSESTATE	m_kState;
				#pragma endregion

			public:
				#pragma region Methods
				Vector2 GetMousePosition();
				bool GetMouseButton(int button);
				#pragma endregion

				#pragma region Overriden Operators
				bool operator==(const MouseState &other) const;
				bool operator!=(const MouseState &other) const;
				#pragma endregion

				friend class InputTask;
		};
	}
}