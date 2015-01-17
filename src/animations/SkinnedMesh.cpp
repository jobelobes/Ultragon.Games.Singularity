#include "animations\Singularity.Animations.h"

using namespace Singularity::Animations;

namespace Singularity
{
	namespace Graphics
	{
		IMPLEMENT_OBJECT_TYPE(Singularity.Graphics, SkinnedMesh, Singularity::Graphics::Mesh);

		#pragma region Private Methods
		void SkinnedMesh::BuildJointTransforms()
		{	
			// Is this delete safe to do with our threaded system?
			// If ::Set_Joints() wasn't public, we wouldn't have to worry here.			
			delete this->m_pWorldTransforms;
			this->m_pWorldTransforms = new Matrix[this->m_iJointCount];
			delete this->m_pSkinTransforms;
			this->m_pSkinTransforms = new Matrix[this->m_iJointCount];			
			//delete this->m_pBindposes;
			//this->m_pBindposes = new Matrix[this->m_iJointCount];

			for(unsigned i = 0; i < this->m_iJointCount; ++i)
			{
				// Set each joint's initial transform to its bindpose:
				this->m_pJoints[i].Transform = Matrix::CreateTransform(NULL, NULL, &this->m_pJoints[i].Scale, NULL, &this->m_pJoints[i].Rotation, &this->m_pJoints[i].Translation);
				
				// WTF? When data is read straight from memory, it creates a row matrix. 
				// Matrix::CreateTransform seems to create a column matrix. So, we're going
				// to go with column matrices for now. Hence, we transpose the read-from-memory
				// InvBindpose here.
				//
				this->m_pJoints[i].InvBindpose = this->m_pJoints[i].InvBindpose.transpose();				
			}
		}
		#pragma endregion

		#pragma region Methods
		void SkinnedMesh::Set_Joints(Joint* joints, unsigned count)
		{
			this->m_pJoints = joints;
			this->m_iJointCount = count;
			this->BuildJointTransforms();
		}

		void SkinnedMesh::UpdateLocalTransform(unsigned index, Vector3 translation, Vector3 scale, Quaternion rotation)
		{
			Matrix transform = Matrix::CreateTransform(NULL, NULL, &scale, NULL, &rotation, &translation);

			this->m_pJoints[index].Translation = translation;
			this->m_pJoints[index].Rotation = rotation;
			this->m_pJoints[index].Scale = scale;
			this->m_pJoints[index].Transform = transform;
		}

		void SkinnedMesh::UpdateWorldTransforms()
		{
			if(m_pWorldTransforms)
			{
				this->m_pWorldTransforms[0] = this->m_pJoints[0].Transform;
				for(unsigned index = 1; index < this->m_iJointCount; ++index)	
					// WTF? We're expecting column matrices, yet the Matrix::operator * swaps the
					// matrices before the multiplication. Hence, we swap their order here. 
					// (Of course, we could just change the operator, but I'm assuming people
					// have already adapted to it in other places.)
					//
					this->m_pWorldTransforms[index] = this->m_pJoints[index].Transform * this->m_pWorldTransforms[this->m_pJoints[index].ParentIndex];
			}
		}

		void SkinnedMesh::UpdateSkinTransforms()
		{
			if(m_pSkinTransforms && m_pWorldTransforms)
			{
				for(unsigned index = 0; index < this->m_iJointCount; ++index)
					// Again, we swap the order before we multiply. See the note in
					// ::UpdateWorldTransforms() for details.
					// Coming out of this, skinTransforms will be column matrices.
					this->m_pSkinTransforms[index] = m_pJoints[index].InvBindpose * this->m_pWorldTransforms[index];
			}
			int a = 0;
		}
		#pragma endregion

		#pragma region Overriden Methods
		Mesh* SkinnedMesh::Clone()
		{
			SkinnedMesh* mesh = new SkinnedMesh();
			mesh->m_kBounds = this->m_kBounds;
			mesh->m_pVertices = this->m_pVertices;
			mesh->m_pIndices= this->m_pIndices;
			mesh->m_kTopology = this->m_kTopology;
			mesh->m_iJointCount = this->m_iJointCount;
			mesh->m_pJoints = this->m_pJoints;
			return mesh;
		}
		#pragma endregion
	}
}