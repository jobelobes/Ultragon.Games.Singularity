#include "graphics\Singularity.Graphics.h"

namespace Singularity
{
	namespace Graphics
	{
		class IndexBuffer : public Singularity::Object
		{
			DECLARE_OBJECT_TYPE

			private:
				#pragma region Variables
				unsigned				m_iStart;
				unsigned				m_iLength;
				void*					m_pBuffer;

				InternalIndexBuffer*	m_pInternal;
				#pragma endregion

			public:
				#pragma region Properties
				unsigned Get_Length() { return this->m_iLength; }
				#pragma endregion

				#pragma region Constructors and Finalizers
				IndexBuffer(unsigned length);
				~IndexBuffer();
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