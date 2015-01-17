#include "inputs\Singularity.Inputs.h"

namespace Singularity
{
	namespace Inputs
	{
		class KeyboardState
		{
			private:
				#pragma region Static Methods
				unsigned		m_iId;
				unsigned char	m_kKeys[256];
				#pragma endregion

			public:
				#pragma region Constructors and Finalizers
				KeyboardState();
				#pragma endregion

				#pragma region Methods
				bool IsKeyDown(int key);
				bool IsKeyUp(int key);
				#pragma endregion

				#pragma region Overriden Operators
				bool operator==(const KeyboardState &other) const;
				bool operator!=(const KeyboardState &other) const;
				#pragma endregion

				friend class InputTask;
		};
	}
}