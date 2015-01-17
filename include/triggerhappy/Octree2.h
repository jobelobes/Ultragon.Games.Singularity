#include "triggerHappy\TriggerHappy.h"

namespace std
{
	struct DefaultOctreeContains
	{
		bool operator() (const Bounds& bounds0, const Bounds& bounds1)
		{
			Vector3 extents[2];

			extents[0] = bounds0.Get_Min();
			extents[1] = bounds1.Get_Min();
			if(extents[0].x < extents[1].x || extents[0].y < extents[1].y || extents[0].z < extents[1].z)
				return false;

			extents[1] = bounds0.Get_Max();
			extents[1] = bounds1.Get_Max();
			if(extents[0].x > extents[1].x || extents[0].y > extents[1].y || extents[0].z > extents[1].z)
				return false;

			return true;		
		}
	};

	template<class T, int MaxNodeItemCount = 8, class Contains = DefaultOctreeContains>
	class Octree2
	{
		public:
			#pragma region Nested Classes
			struct ListItem
			{ 
				ListItem*		Next;
				T				Value;
			};

			struct OctNode 
			{ 
				OctNode*		Parent;
				OctNode*		Children[8];
				Bounds			Bounds;
				unsigned		Count;
				ListItem*		Data;
			};
			#pragma endregion

		public:
			#pragma region Variables
			OctNode*		m_pRoot;

			unsigned		m_iCapacity;
			unsigned		m_iCount;
			T*				m_pValues;
			#pragma endregion

			#pragma region Methods
			OctNode* _addnode(Bounds& bounds, OctNode* parent)
			{
				OctNode* node = new OctNode();
				node->Bounds = bounds;
				node->Parent = parent;
				memset(&node->Children[0], 0, sizeof(OctNode*) * 8);
				node->Count = 0;
				node->Data = NULL;
				return node;
			};

			void _removenode(OctNode* node)
			{
				for(int i = 0; i < 8; ++i)
				{
					if(node->Parent->Children[i] == node)
					{
						node->Parent->Children[i] = NULL;
						delete node;
						return;
					}
				}
			};

			ListItem* _additem(T value)
			{
				ListItem* item = &this->m_pValues[::InterlockedIncrement((LONG*)&this->m_iCount) - 1];
				item->Next = NULL;
				item->Value = value;
				return;
			};

			void _removeitem(ListItem* item)
			{
				
				
			};

			bool _insert(ListItem* item, OctNode* node)
			{
				ListItem* previous = NULL;

				if(!Contains(bounds, node->Bounds))
					return false;

				if(node->Children[0] != NULL)
				{
					if(node->Count >= MaxNodeItemCount)
						this->_split(node);

					// search through children to find containing node
					for(int i = 0; i < 8; ++i)
						if(this->_insert(item, node->Children[i])) return true;
				}

				while(previous != NULL && previous->Next != NULL)
					previous = previous->Next;

				if(previous == NULL)
					node->Data = item;
				else
					previous->Next = item;

				node->Count++;
				return true;
			};

			void _erase(T value)
			{

			};

			void _split(OctNode* node)
			{
				Vector3 center = node->Bounds.Center;
				Vector3 size = node->Bounds.Size * 0.5f;
				Vector3 offset = node->Bounds.Size * 0.25f;
				node->Children[0] = this->_addnode(Bounds(center.x + offset.x, center.y + offset.y, center.z + offset.z, size.x, size.y, size.z), node); 
				node->Children[1] = this->_addnode(Bounds(center.x + offset.x, center.y + offset.y, center.z - offset.z, size.x, size.y, size.z), node);
				node->Children[2] = this->_addnode(Bounds(center.x + offset.x, center.y - offset.y, center.z + offset.z, size.x, size.y, size.z), node);
				node->Children[3] = this->_addnode(Bounds(center.x + offset.x, center.y - offset.y, center.z - offset.z, size.x, size.y, size.z), node);
				node->Children[4] = this->_addnode(Bounds(center.x - offset.x, center.y + offset.y, center.z + offset.z, size.x, size.y, size.z), node);
				node->Children[5] = this->_addnode(Bounds(center.x - offset.x, center.y + offset.y, center.z - offset.z, size.x, size.y, size.z), node);
				node->Children[6] = this->_addnode(Bounds(center.x - offset.x, center.y - offset.y, center.z + offset.z, size.x, size.y, size.z), node);
				node->Children[7] = this->_addnode(Bounds(center.x - offset.x, center.y - offset.y, center.z - offset.z, size.x, size.y, size.z), node);
			};

			void _join(OctNode* node)
			{
				for(int i = 0; i < 8; ++i)
				{
					this->_removenode(node->Children[i]);
					node->Children[i] = NULL;
				}
			};
			#pragma endregion

		public:			
			#pragma region Constructors and Finalizers
			Octree2(const Bounds& world = Bounds(0, 0, 0, FLT_MAX, FLT_MAX, FLT_MAX), unsigned capacity = 1024)
				:m_iCount(0), m_iCapacity(capacity)
			{
				this->m_pRoot = this->_addnode(Bounds(world), NULL);
				this->m_pValues = (T*)calloc(this->m_iCapacity, sizeof(T));
			}

			~Octree2()
			{

			}
			#pragma endregion

			#pragma region Properties
			inline const OctNode* root() const{ return this->m_pRoot; };
			inline const unsigned size() const{ return this->m_iCount; };
			#pragma endregion
			
			#pragma region Methods
			void insert(const Bounds& bounds, T value)
			{
				_ASSERT_EXPR(Contains(bounds, this->m_pRoot->Bounds), "Value outside of tree bounds.");
				
				ListItem* item = this->_additem(value);
				this->_insert(item, this->m_pRoot);
			};

			void erase(T value)
			{

			};
			#pragma endregion
	};

	//#include "common\Octree.inc"
}