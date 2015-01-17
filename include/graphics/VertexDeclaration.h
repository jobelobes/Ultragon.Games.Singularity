#include "graphics\Singularity.Graphics.h"

namespace Singularity
{
	namespace Graphics
	{
		class VertexDeclaration
		{
			private:
				#pragma region Variables
				unsigned					m_iStride;
				unsigned					m_iElementCount;
				D3D10_INPUT_ELEMENT_DESC*	m_pVertexElements;
				#pragma endregion

			public:
				#pragma region Properties
				inline const unsigned Get_SizeInBytes() const { return this->m_iStride; };

				inline const unsigned Get_ElementCount() const { return this->m_iElementCount; };

				inline const D3D10_INPUT_ELEMENT_DESC* Get_Elements() const { return this->m_pVertexElements; };
				#pragma endregion

				#pragma region Constructors and Finalizers
				VertexDeclaration(D3D10_INPUT_ELEMENT_DESC* elements, unsigned elementCount, unsigned stride);
				~VertexDeclaration();
				#pragma endregion

				#pragma region methods
				const bool Equals(VertexDeclaration* vertexDeclaration);
				#pragma endregion

				friend class Singularity::Graphics::Devices::DrawingContext;
				friend class Singularity::Graphics::Devices::DeferredDrawingContext;
		};
	}
}