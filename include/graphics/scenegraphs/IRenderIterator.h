#include "graphics\Singularity.Graphics.h"

namespace Singularity
{
	namespace Graphics
	{
		class IRenderIterator
		{
			public:
				#pragma region Properties
				virtual const unsigned Get_Size() const = 0;
				virtual Renderer* Get_Renderer() const = 0;
				#pragma endregion

				#pragma region Methods
				virtual void Reset() = 0;
				virtual Renderer* Next() = 0;

				virtual IRenderIterator& Split(int count = -1) = 0;
				#pragma endregion
		};
	}
}
