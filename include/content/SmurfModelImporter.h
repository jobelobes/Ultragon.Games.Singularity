#include "content\Singularity.Content.h"

namespace Singularity
{
	namespace Content
	{
		class SmurfModelImporter : public Singularity::Content::IModelImporter
		{
			private: 
				#pragma region Nested Classes
				struct FileHeader
				{
					char		FileId[5];
					unsigned	Version;
					unsigned	MeshCount;
					unsigned	ColliderCount;
				};

				struct StaticMeshHeader
				{
					unsigned	Type;
					unsigned	MeshType;
					char		MeshId[255];
					unsigned	VertexCount;
					unsigned	IndexCount;
					unsigned	MaterialCount;
				};

				struct AnimatedMeshHeader
				{
					unsigned	Type;
					unsigned	MeshType;
					char		MeshId[255];
					unsigned	VertexCount;
					unsigned	IndexCount;
					unsigned	MaterialCount;
					unsigned	JointCount;
					unsigned	FrameCount;
					unsigned	KeyFrameCount;
				};

				struct CollisionHeader
				{
					unsigned	Type;
					unsigned	ColliderCount;
					unsigned	BoxColliderCount;
					unsigned	SphereColliderCount;
					unsigned	CapsuleColliderCount;
				};

				struct FrameDescription
				{				
					unsigned int	JointIndex;
					unsigned int	FrameNumber;
					Vector3			Translation[3];
					Vector3			Rotation[3];
					Vector3			Scale[3];
					float			RotationTangentX[4];
					float			RotationTangentY[4];
					float			RotationTangentZ[4];
					float			TranslationTangentX[4];
					float			TranslationTangentY[4];
					float			TranslationTangentZ[4];			
				};

				struct MaterialDescription
				{
					unsigned	Type;
					char		TextureName[255];
					float		MainColor[4];
					float		AmbientColor[4];
					float		Diffuse;
					float		Eccentricity;
				};

				struct JointData
				{
					unsigned	FrameId;
					unsigned	JointCount;
					unsigned	Joints;
				};

				struct BoxColliderDescription
				{
					Vector3		Center;
					Vector3		HalfWidth;
					Quaternion	Orientation;
				};
				#pragma endregion

				#pragma region Variables
				String			m_kDefaultPath;
				unsigned		m_pBufferLength;
				char*			m_pBuffer;
				#pragma endregion

				#pragma region Methods
				unsigned MoveToNextMesh(unsigned offset);
				Singularity::Graphics::Mesh* ExtractStaticMesh(StaticMeshHeader* header);
				Singularity::Graphics::SkinnedMesh* ExtractAnimatedMesh(AnimatedMeshHeader* header);
				Singularity::Graphics::Material* ExtractMaterial(AnimatedMeshHeader* header);
				Singularity::Animations::Animation* ExtractAnimation(AnimatedMeshHeader* header);
				Singularity::Components::GameObject* ExtractCollider(Singularity::Components::GameObject* parent, CollisionHeader* header, unsigned index, unsigned type);
				#pragma endregion

			protected:
				#pragma region Overriden Properties
				inline const int Get_ModelCount() { return ((FileHeader*)m_pBuffer)->MeshCount; };
				#pragma endregion

				#pragma region IContentImporter Methods
				virtual void LoadFile(String path);
				#pragma endregion

				#pragma region IModelImporter Methods
				Singularity::Components::GameObject* LoadModel(unsigned index);
				Singularity::Graphics::Mesh* LoadMesh(unsigned index);
				Singularity::Graphics::Material* LoadMaterial(unsigned index);
				#pragma endregion

			public:
				#pragma region Constructors and Finalizers
				SmurfModelImporter(String defaultPath = "") : m_pBufferLength(0), m_pBuffer(NULL), m_kDefaultPath(defaultPath) { };
				~SmurfModelImporter();
				#pragma endregion

				void LoadCollisionData(Singularity::Components::GameObject* object);
		};
	}
}