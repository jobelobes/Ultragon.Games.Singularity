#include "graphics\Singularity.Graphics.h"

namespace Singularity
{
	namespace Graphics
	{
		#pragma region Constructors and Deconstructors
		OctTreeRenderGraph::OctTreeRenderGraph(const Bounds& bounds, int capacity, int depth)
			: m_iMaxDepth(depth), m_iNodeCapacity(0), m_iNodeCount(0) , m_pNodes(NULL), m_iCapacity(0), m_iCount(0), m_pRenderers(NULL)
		{
			while(depth-- > 0) this->m_iNodeCapacity += (unsigned)ceil(pow(8.0, depth - 1));

			this->m_pNodes = (OctNode*)calloc(this->m_iNodeCapacity, sizeof(OctNode));
			this->m_pRenderers = (Renderer**)calloc(this->m_iCapacity, sizeof(Renderer*));

			this->m_pNodes[0].Bounds = bounds;
		}

		OctTreeRenderGraph::~OctTreeRenderGraph()
		{
			if(this->m_pNodes)
				free(this->m_pNodes);

			if(this->m_pRenderers)
				free(this->m_pRenderers);
		}
		#pragma endregion

		#pragma region Methods
		void OctTreeRenderGraph::InternalAdd(Renderer* renderer)
		{
			/*unsigned index, count;
			Vector3 min, max;
			OctNode* node;
			
			min = renderer->Get_Bounds().Get_Min();
			max = renderer->Get_Bounds().Get_Max();
			node = &this->m_pNodes[0];
			if(!node->Bounds.Contains(min) || !node->Bounds.Contains(max))
				return;

			do
			{
				if(node->Count > 8)
					this->Split(node);

				if(node->Children != NULL)
				{
					count = 0;
					for(index = 0; index < 8; ++index)
					{
						if(node->Children[index].Bounds.Contains(min))
						{
							if(node->Children[index].Bounds.Contains(max))
							{
								count++;
								node = node->Children[index];
								break;
							}
							else
								count++;
						}
						else if(node->Children[index].Bounds.Contains(max))
							count++;
					}

					if(count > 1)
					{

					}
				}
			}
			while(true);*/
		}

		void OctTreeRenderGraph::Join(OctNode* node)
		{
			
		}

		void OctTreeRenderGraph::Split(OctNode* parent)
		{
			unsigned index;
			OctNode* node;
			Vector3 halfSize, quarterSize, centerpoint;

			if((this->m_iNodeCount + 8) > this->m_iNodeCapacity)
				throw SingularityException("Unable to add nodes to scene graph; no more space available.");

			index = ::InterlockedExchangeAdd((LONG*)&this->m_iNodeCount, 8L) - 8;
			centerpoint = node->Bounds.Center;
			halfSize = node->Bounds.Size * 0.5f;
			quarterSize = halfSize * 0.5f;

			memset(&this->m_pNodes[index], 0, sizeof(OctNode) * 8);

			node = &this->m_pNodes[index];
			node->Parent = node;
			node->Bounds = Bounds(Vector3(centerpoint.x + quarterSize.x, centerpoint.y + quarterSize.y, centerpoint.z + quarterSize.z), halfSize);

			node = &this->m_pNodes[++index];
			node->Parent = node;
			node->Bounds = Bounds(Vector3(centerpoint.x + quarterSize.x, centerpoint.y + quarterSize.y, centerpoint.z - quarterSize.z), halfSize);

			node = &this->m_pNodes[++index];
			node->Parent = node;
			node->Bounds = Bounds(Vector3(centerpoint.x + quarterSize.x, centerpoint.y - quarterSize.y, centerpoint.z + quarterSize.z), halfSize);

			node = &this->m_pNodes[++index];
			node->Parent = node;
			node->Bounds = Bounds(Vector3(centerpoint.x + quarterSize.x, centerpoint.y - quarterSize.y, centerpoint.z - quarterSize.z), halfSize);

			node = &this->m_pNodes[++index];
			node->Parent = node;
			node->Bounds = Bounds(Vector3(centerpoint.x - quarterSize.x, centerpoint.y + quarterSize.y, centerpoint.z + quarterSize.z), halfSize);

			node = &this->m_pNodes[++index];
			node->Parent = node;
			node->Bounds = Bounds(Vector3(centerpoint.x - quarterSize.x, centerpoint.y + quarterSize.y, centerpoint.z - quarterSize.z), halfSize);

			node = &this->m_pNodes[++index];
			node->Parent = node;
			node->Bounds = Bounds(Vector3(centerpoint.x - quarterSize.x, centerpoint.y - quarterSize.y, centerpoint.z + quarterSize.z), halfSize);

			node = &this->m_pNodes[++index];
			node->Parent = node;
			node->Bounds = Bounds(Vector3(centerpoint.x - quarterSize.x, centerpoint.y - quarterSize.y, centerpoint.z - quarterSize.z), halfSize);
		}
		#pragma endregion

		#pragma region Overriden Methods
		void OctTreeRenderGraph::Add(Renderer* renderer)
		{
			unsigned index;

			if(this->m_iCount == this->m_iCapacity)
				throw SingularityException("Unable to add \"renderer\"; Max capacity has been reached.");

			index = ::InterlockedIncrement((LONG*)&this->m_iCount);
			this->m_pRenderers[index - 1] = renderer;

			this->InternalAdd(renderer);
		}

		void OctTreeRenderGraph::Remove(Renderer* renderer)
		{

		}

		void OctTreeRenderGraph::OnUpdate(bool force)
		{

		}

		IRenderIterator* OctTreeRenderGraph::Contains(const Bounds& box)
		{
			return NULL;// new OctTreeRenderIterator(this, 0, this->m_iCount);
		}
		#pragma endregion
	}
}