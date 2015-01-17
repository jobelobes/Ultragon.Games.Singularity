#include "graphics\Singularity.Graphics.h"

namespace Singularity
{
	namespace Graphics
	{
		#pragma region Constructors and Finalizers
		LinearRenderIterator::LinearRenderIterator(LinearRenderGraph* graph, unsigned index, unsigned count)
			: m_pGraph(graph), m_iStart(index), m_iCurrent(index), m_pCount(count) {}
		#pragma endregion

		#pragma region Methods
		inline const unsigned LinearRenderIterator::Get_Size() const { return this->m_pCount; }

		inline Renderer* LinearRenderIterator::Get_Renderer() const { return NULL; }
		#pragma endregion

		#pragma region Methods
		void LinearRenderIterator::Reset()
		{
			this->m_iCurrent = this->m_iStart;
		}

		Renderer* LinearRenderIterator::Next()
		{
			Renderer* renderer;

			if((this->m_iCurrent) > this->m_pGraph->m_iCapacity)
				return NULL;
			if((this->m_iCurrent - this->m_iStart) >= this->m_pCount)
				return NULL;

			renderer = this->m_pGraph->m_pRenderers[this->m_iCurrent];
			::InterlockedIncrement((LONG*)&this->m_iCurrent);

			return renderer;
		}

		IRenderIterator& LinearRenderIterator::Split(int count)
		{
			if(count == -1)
				count = this->m_pCount / 2;

			this->m_pCount -= count;
			return LinearRenderIterator(this->m_pGraph, this->m_iStart + this->m_pCount, count);
		}
		#pragma endregion
	}
}
