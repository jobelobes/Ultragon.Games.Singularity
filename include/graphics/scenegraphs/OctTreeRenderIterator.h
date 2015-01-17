#include "graphics\Singularity.Graphics.h"

namespace Singularity
{
	namespace Graphics
	{
		class OctTreeRenderIterator : public Singularity::Graphics::IRenderIterator
		{
			private:
				#pragma region Variables
				OctTreeRenderGraph*			m_pGraph;
				OctTreeRenderGraph::OctNode*	m_pStart;
				#pragma endregion

				#pragma region Constructors and Finalizers
				OctTreeRenderIterator(OctTreeRenderGraph* graph, OctTreeRenderGraph::OctNode* node);
				~OctTreeRenderIterator() { }
				#pragma endregion

			public:
				#pragma region Methods
				const unsigned Get_Size() const;
				Renderer* Get_Renderer() const;
				#pragma endregion

				#pragma region Methods
				void Reset();
				Renderer* Next();

				IRenderIterator& Split(int count = -1);
				#pragma endregion

				friend class OctTreeRenderGraph;
		};
	}
}