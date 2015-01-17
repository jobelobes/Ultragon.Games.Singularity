#include "graphics\Singularity.Graphics.h"

namespace Singularity
{
	namespace Graphics
	{
		class OctTreeRenderGraph : public Singularity::Graphics::IRenderGraph
		{
			private:
				#pragma region Variables
				struct OctNode
				{
					#pragma region Variables
					OctNode*	Parent;
					OctNode*	Children;
					Bounds		Bounds;
					unsigned	Count;
					#pragma endregion
				};
				#pragma endregion

				#pragma region Variables
				unsigned					m_iMaxDepth;
				unsigned					m_iNodeCapacity;
				unsigned					m_iNodeCount;
				OctNode*					m_pNodes;

				unsigned					m_iCapacity;
				unsigned					m_iCount;
				Renderer**					m_pRenderers;
				#pragma endregion

				#pragma region Methods
				void InternalAdd(Renderer* renderer);
				void Join(OctNode* node);
				void Split(OctNode* node);
				#pragma endregion
			
			public:
				#pragma region Constructors and Deconstructors
				OctTreeRenderGraph(const Bounds& bounds, int capacity = 4096, int depth = 8);
				~OctTreeRenderGraph();
				#pragma endregion

				#pragma region Overriden Methods
				virtual void Add(Renderer* renderer);
				virtual void Remove(Renderer* renderer);

				virtual void OnUpdate(bool force);

				IRenderIterator* Contains(const Bounds& box);
				#pragma endregion

				friend class OctTreeRenderIterator;
		};
	}
}