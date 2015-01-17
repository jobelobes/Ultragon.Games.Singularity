#include "graphics\Singularity.Graphics.h"

namespace Singularity
{
	namespace Graphics
	{
		class RenderTask : public Singularity::Threading::Task
		{
			DECLARE_OBJECT_TYPE;

			private:
				#pragma region Static Variables
				static RenderTask* g_pInstance;
				#pragma endregion

				#pragma region Variables
				CriticalSection				m_kLock;

				DrawingContext*				m_pDrawingContext;

				DynamicSet<Camera*>			m_pCamera;
				DynamicSet<Light*>			m_pLights;

				DynamicSet<Renderer*>		m_pRenderersTiedToCamera;

				Octree<Renderer*>*			m_pRenderers;
				
				RenderSubTask*				m_pSubTasks[SINGULARITY_RENDERER_MAX_SUBTASKS];
				#pragma endregion

				#pragma region Constructors and Finalizers
				RenderTask(DrawingContext* context);
				~RenderTask();
				#pragma endregion
				
				#pragma region Methods
				void OnExecuteCamera(Camera* camera);
				#pragma endregion

			protected:
				#pragma region Event Methods
				virtual void OnExecute();
				virtual void OnComplete() { };
				#pragma endregion

			public:
				#pragma region Methods
				void RegisterComponent(Singularity::Components::Component* component);
				void UnregisterComponent(Singularity::Components::Component* component);
				void RegisterTiedRenderer(Renderer* renderer);
				void UnregisterTiedRenderer(Renderer* renderer);
				#pragma endregion

				#pragma region Static Methods
				static RenderTask* Instantiate();
				#pragma endregion

				friend class Renderer;
				friend class RenderSubTask;
		};
	}
}