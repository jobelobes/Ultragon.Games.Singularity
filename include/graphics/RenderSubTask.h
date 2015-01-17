#include "graphics\Singularity.Graphics.h"

using namespace Singularity::Graphics::Devices;

namespace Singularity
{
	namespace Graphics
	{
		class RenderSubTask : public Singularity::Threading::Task
		{
			DECLARE_OBJECT_TYPE;

			private:
				#pragma region Variables
				Camera*						m_pCamera;
				DrawingContext*				m_pDrawingContext;
				//BufferedDrawingContext*		m_pBufferedDrawingContext;
				DeferredDrawingContext*		m_pDeferredDrawingContext;
				OctreeIterator<Renderer*>*	m_pIterator;
				#pragma endregion

				#pragma region Constructors and Finalizers
				RenderSubTask();
				~RenderSubTask() { };
				#pragma endregion

				#pragma region Methods
				void Update(DrawingContext* context, Camera* camera);
				#pragma endregion

			protected:
				#pragma region Event Methods
				void OnExecute();
				void OnComplete() { };
				#pragma endregion

				friend class RenderTask;
		};
	}
}