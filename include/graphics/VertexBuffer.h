#include "graphics\Singularity.Graphics.h"

namespace Singularity
{
	namespace Graphics
	{
		class VertexBuffer : public Singularity::Object
		{
			DECLARE_OBJECT_TYPE

			private:
				#pragma region Variables
				unsigned				m_iStart;
				unsigned				m_iLength;
				void*					m_pBuffer;

				InternalVertexBuffer*	m_pInternal;
				#pragma endregion

			public:
				#pragma region Properties
				inline unsigned Get_Length() const { return this->m_iLength; }
				inline unsigned Get_Start() const { return this->m_iStart; }

				inline VertexDeclaration* Get_VertexDeclaration() const { return this->m_pInternal->m_pDeclaration; }
				#pragma endregion

				#pragma region Constructors and Finalizers
				VertexBuffer(VertexDeclaration* vertexDeclaration, unsigned length);
				~VertexBuffer();
				#pragma endregion

				#pragma region Methods
				void SetData(void* data);
				void* GetData(bool force = false);
				#pragma endregion

				friend class Singularity::Graphics::Devices::DrawingContext;
				friend class Singularity::Graphics::Devices::DeferredDrawingContext;
		};
	}
}