#include "graphics\Singularity.Graphics.h"

namespace Singularity
{
	namespace Graphics
	{
		#pragma region Constructors and Finalizers
		OctTreeRenderIterator::OctTreeRenderIterator(OctTreeRenderGraph* graph, OctTreeRenderGraph::OctNode* node){}
		#pragma endregion

		#pragma region Methods
		inline const unsigned OctTreeRenderIterator::Get_Size() const { return 0; }

		inline Renderer* OctTreeRenderIterator::Get_Renderer() const { return NULL; }
		#pragma endregion

		#pragma region Methods
		void OctTreeRenderIterator::Reset()
		{
			
		}

		Renderer* OctTreeRenderIterator::Next()
		{
			return NULL;
		}

		IRenderIterator& OctTreeRenderIterator::Split(int count)
		{
			return OctTreeRenderIterator(NULL, NULL);
		}
		#pragma endregion
	}
}
