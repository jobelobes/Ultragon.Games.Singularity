#include "graphics\Singularity.Graphics.h"

namespace Singularity
{
	namespace Graphics
	{
		#pragma region Constructors and Finalizers
		VertexDeclaration::VertexDeclaration(D3D10_INPUT_ELEMENT_DESC* elements, unsigned elementCount, unsigned stride)
			: m_pVertexElements(NULL), m_iElementCount(elementCount), m_iStride(stride)
		{
			this->m_pVertexElements = (D3D10_INPUT_ELEMENT_DESC*)malloc(sizeof(D3D10_INPUT_ELEMENT_DESC) * elementCount);
			memcpy(this->m_pVertexElements, elements, sizeof(D3D10_INPUT_ELEMENT_DESC) * elementCount);
		}

		VertexDeclaration::~VertexDeclaration()
		{
			if(this->m_pVertexElements != NULL)
				delete [] this->m_pVertexElements;
		}
		#pragma endregion

		#pragma region methods
		const bool VertexDeclaration::Equals(VertexDeclaration* declaration)
		{
			unsigned i, j;
			unsigned count;

			count = declaration->m_iElementCount;

			if(declaration->m_iStride != this->m_iStride || count != this->m_iElementCount)
				return false;

			
			for(i = 0; i < count; i++)
			{
				for(j = 0; j < count; j++)
				{
					if(declaration->m_pVertexElements[i].SemanticIndex != this->m_pVertexElements[i].SemanticIndex)
						return false;
					if(declaration->m_pVertexElements[i].Format != this->m_pVertexElements[i].Format)
						return false;
					if(declaration->m_pVertexElements[i].InputSlot != this->m_pVertexElements[i].InputSlot)
						return false;
					if(declaration->m_pVertexElements[i].AlignedByteOffset != this->m_pVertexElements[i].AlignedByteOffset)
						return false;
				}
			}

			return true;
		}
		#pragma endregion
	}
}