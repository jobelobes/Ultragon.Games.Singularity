#include "graphics\Singularity.Graphics.h"

namespace Singularity
{
	namespace Graphics
	{
		class LinearRenderIterator : public Singularity::Graphics::IRenderIterator
		{
			private:
				#pragma region Variables
				LinearRenderGraph*	m_pGraph;
				unsigned			m_iStart;
				unsigned			m_iCurrent;
				unsigned			m_pCount;
				#pragma endregion

				#pragma region Constructors and Finalizers
				LinearRenderIterator(LinearRenderGraph* graph, unsigned index, unsigned count);
				~LinearRenderIterator() { }
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

				friend class LinearRenderGraph;
		};
	}
}