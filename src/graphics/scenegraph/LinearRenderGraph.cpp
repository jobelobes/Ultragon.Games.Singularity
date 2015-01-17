#include "graphics\Singularity.Graphics.h"

namespace Singularity
{
	namespace Graphics
	{
		#pragma region Constructors and Deconstructors
		LinearRenderGraph::LinearRenderGraph(int capacity)
			:m_iCapacity(capacity), m_iCount(0), m_pRenderers(NULL)
		{
			this->m_pRenderers = (Renderer**)calloc(this->m_iCapacity, sizeof(Renderer*));
		}

		LinearRenderGraph::~LinearRenderGraph()
		{
			if(this->m_pRenderers)
				free(this->m_pRenderers);
		}
		#pragma endregion

		#pragma region Overriden Methods
		void LinearRenderGraph::Add(Renderer* renderer)
		{
			unsigned index;

			if(this->m_iCount == this->m_iCapacity)
				throw SingularityException("Unable to add \"renderer\"; Max capacity has been reached.");

			index = ::InterlockedIncrement((LONG*)&this->m_iCount);
			this->m_pRenderers[index - 1] = renderer;
		}

		void LinearRenderGraph::Remove(Renderer* renderer)
		{

		}

		void LinearRenderGraph::OnUpdate(bool force)
		{

		}

		IRenderIterator* LinearRenderGraph::Contains(const Bounds& box)
		{
			return new LinearRenderIterator(this, 0, this->m_iCount);
		}
		#pragma endregion

		
	}
}