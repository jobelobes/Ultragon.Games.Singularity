#include "animations\Singularity.Animations.h"

using namespace Singularity::Animations;

namespace Singularity
{
	namespace Graphics
	{
		class SkinnedMesh : public Singularity::Graphics::Mesh
		{
			DECLARE_OBJECT_TYPE
			
			private:
				#pragma region Variables
				unsigned	m_iJointCount;
				Joint*		m_pJoints;				
				Matrix*		m_pWorldTransforms;
				Matrix*		m_pSkinTransforms;
				Matrix*		m_pBindposes;
				#pragma endregion

				#pragma region Methods
				void BuildJointTransforms(void);				
				#pragma endregion

			public:
				#pragma region Constructors and Finalizers
				SkinnedMesh() : Mesh(), m_pJoints(0), m_pWorldTransforms(0), m_pSkinTransforms(0), m_pBindposes(0) { };
				SkinnedMesh(VertexBuffer* vertices, IndexBuffer* indices = NULL) : Mesh(vertices, indices), m_iJointCount(0), m_pJoints(NULL), m_pWorldTransforms(0), m_pSkinTransforms(0), m_pBindposes(0) { };
				virtual ~SkinnedMesh() { delete m_pWorldTransforms; delete m_pSkinTransforms; delete m_pBindposes; };
				#pragma endregion

				#pragma region Methods
				void Set_Joints(Joint* joints, unsigned count);
				void UpdateLocalTransform(unsigned index, Vector3 translation, Vector3 scale, Quaternion rotation);
				void UpdateWorldTransforms(void);
				void UpdateSkinTransforms(void);

				//Joint Get_Joint(unsigned index);
				
				//void Set_LocalTransform(unsigned index, Vector3 translation, Vector3 scale, Quaternion rotation);
				//Matrix* Get_LocalTransforms();
				//Matrix Get_LocalTransform(unsigned index);
				
				inline Matrix* Get_SkinTransforms(void) const { return this->m_pSkinTransforms; }
				inline unsigned Get_JointCount() const { return this->m_iJointCount; }
				#pragma endregion

				#pragma region Overriden Methods
				Mesh* Clone();
				#pragma endregion

				friend class SkinnedMeshRenderer;
		};
	}
}