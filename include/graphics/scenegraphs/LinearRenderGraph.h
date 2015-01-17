#include "graphics\Singularity.Graphics.h"

namespace Singularity
{
	namespace Graphics
	{
		class LinearRenderGraph : public Singularity::Graphics::IRenderGraph
		{
			private:
				#pragma region Variables
				unsigned			m_iCapacity;
				unsigned			m_iCount;
				Renderer**			m_pRenderers;
				#pragma endregion
			
			public:
				#pragma region Constructors and Deconstructors
				LinearRenderGraph(int capacity = 4096);
				~LinearRenderGraph();
				#pragma endregion

				#pragma region Overriden Methods
				void Add(Renderer* renderer);
				void Remove(Renderer* renderer);

				void OnUpdate(bool force);

				IRenderIterator* Contains(const Bounds& box);
				#pragma endregion

				friend class LinearRenderIterator;
		};
	}
}