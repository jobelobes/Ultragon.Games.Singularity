#include "content\Singularity.Content.h"

namespace Singularity
{
	namespace Content
	{
		class FbxModelImporter : public Singularity::Content::IModelImporter
		{
			private: 
				#pragma region Variables
				KFbxSdkManager* m_pSDKManager;
				KFbxImporter*	m_pImporter;
				KFbxScene*		m_pScene;

				unsigned		m_iMeshCount;
				#pragma endregion

				#pragma region Methods
				Singularity::Graphics::Mesh* ExtractStaticMesh(KFbxMesh* mesh);
				//Singularity::Graphics::Mesh* ExtractAnimatedMesh(KFbxMesh* mesh);

				//Singularity::Graphics::ModelSkeleton* ProcessSkeleton(KFbxNode* node, Singularity::Animations::Animation* animation);
				//void ProcessBone(KFbxNode* node, ModelBone* parent, DynamicList<ModelBone*> bones, DynamicList<Singularity::Animations::AnimationClip*> clips);
				
				Singularity::Graphics::Mesh* GetMesh(KFbxScene* scene);
				Singularity::Graphics::Mesh* GetMesh(KFbxNode* node, Singularity::Graphics::Mesh* mesh);

				//Singularity::Graphics::ModelSkeleton* GetSkeleton(KFbxScene* scene, Singularity::Components::GameObject* gameObject);
				//Singularity::Graphics::ModelSkeleton* GetSkeleton(KFbxNode* node, Singularity::Components::GameObject* gameObject);
				#pragma endregion

			protected:
				#pragma region Overriden Properties
				inline const int Get_ModelCount() { return this->m_iMeshCount; };
				#pragma endregion

				#pragma region IContentImporter Methods
				virtual void LoadFile(String path);
				#pragma endregion

				#pragma region IModelImporter Methods
				Singularity::Components::GameObject* LoadModel(int index);
				#pragma endregion

			public:
				#pragma region Constructors and Finalizers
				FbxModelImporter();
				~FbxModelImporter();
				#pragma endregion

				#pragma region Methods
				Singularity::Animations::Animation* ProcessAnimation(KFbxNode* node);
				void ProcessAnimatedBone(KFbxNode* node, int boneIndex, DynamicList<Singularity::Animations::AnimationClip*> clips);
				bool SortKeyFrames(Singularity::Animations::Keyframe key1, Singularity::Animations::Keyframe key2);
				#pragma endregion

				#pragma region Static Methods
				static void FbxDoubleToVector3(const fbxDouble3& data, Vector3* outVector);
				static void FbxRotationToQuaternion(const fbxDouble3 data, ERotationOrder rotOrder, Quaternion* outQuat);
				static void FbxRotationToQuaternion(const float dataX, const float dataY, const float dataZ, ERotationOrder rotOrder, Quaternion* outQuat);
				#pragma endregion
		};
	}
}