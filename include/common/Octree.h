#include "common\Singularity.Common.h"

namespace Singularity
{
	template<class T>
	struct ListItem;

	template<class T>
	struct OctNode { OctNode* Parent; OctNode* Next; OctNode* Children; unsigned Depth; Bounds Bounds; unsigned Count; ListItem<T>* Values; };

	template<class T>
	struct ListItem { OctNode<T>* Parent; ListItem<T>* Next; Bounds Bounds; T Value; };

	template<class T>
	class OctreeIterator;

	template<class T>
	class Octree
	{
		private:
			#pragma region Variables
			unsigned		m_iMaxDepth;
			unsigned		m_iLimit;

			unsigned		m_iNodeCapacity;
			unsigned		m_iNodeCount;
			OctNode<T>*		m_pNodes;
			
			unsigned		m_iCapacity;
			unsigned		m_iCount;
			ListItem<T>*	m_pValues;
			#pragma endregion

			#pragma region Methods
			void _update(OctNode<T>* node);
			void _split(OctNode<T>* node);
			void _join(OctNode<T>* node);
			OctNode<T>* _find(OctNode<T>* node, const Bounds& bounds);

			void _insert(ListItem<T>* item);
			#pragma endregion

		public:
			#pragma region Properties
			inline const OctNode<T>* root() const{ return &this->m_pNodes[0]; };
			inline const unsigned size() const{ return this->m_iNodeCount; };
			#pragma endregion

			#pragma region Constructors and Finalizers
			Octree(const Bounds& bounds = Bounds(0, 0, 0, FLT_MAX, FLT_MAX, FLT_MAX), unsigned maxDepth = 8, unsigned nodeLimit = 8, unsigned capacity = 2048);
			~Octree();
			#pragma endregion

			#pragma region Methods
			void insert(const Bounds& bounds, T value);
			void erase(T value);
			#pragma endregion

			friend class OctreeIterator<T>;
	};

	#include "common\Octree.inc"
}