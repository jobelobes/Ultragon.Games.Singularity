#include "graphics\Singularity.Graphics.h"

namespace Singularity
{
	namespace Graphics
	{
		class Screen
		{
			public:
				#pragma region Static Methods
				static void SetResolution(const unsigned width, const unsigned height, const bool fullscreen);
				static void GetResolution(unsigned& width, unsigned& height);

				static void SetSize(const unsigned x, const unsigned y, const unsigned width, const unsigned height);
				static void GetSize(unsigned& x, unsigned& y, unsigned& width, unsigned& height);

				static void SetTitle(String title);
				#pragma endregion
		};
	}
}