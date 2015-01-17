#include "content\Singularity.Content.h"

namespace Singularity
{
	namespace Content
	{
		class IContentImporter
		{
			protected:
				#pragma region Methods
				virtual void LoadFile(String path) = 0;
				#pragma endregion

				friend class ModelLoader;
		};
	}
}