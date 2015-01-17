#include "content\Singularity.Content.h"

using namespace Singularity;
using namespace Singularity::Components;
using namespace Singularity::Graphics;
using namespace Singularity::Physics;

#define STATICMESHHEADERBLOCK 1
#define ANIMATEDMESHHEADERBLOCK 2
#define COLLIDERSHEADERBLOCK 3
#define STATICMESHBLOCK 4
#define ANIMATEDMESHBLOCK 5
#define MATERIALBLOCK 6
#define COLLIDERSBLOCK 7

namespace Singularity
{
	namespace Content
	{
		#pragma region Constructors and Finalizers
		SmurfModelImporter::~SmurfModelImporter()
		{
			if(this->m_pBuffer)
				free(this->m_pBuffer);
		}
		#pragma endregion

		#pragma region Methods
		unsigned SmurfModelImporter::MoveToNextMesh(unsigned offset)
		{
			AnimatedMeshHeader* header = (AnimatedMeshHeader*)(this->m_pBuffer + offset);
			
			switch(header->Type)
			{
				case STATICMESHHEADERBLOCK:
					offset += sizeof(StaticMeshHeader);
					offset += header->VertexCount * sizeof(VertexPositionNormalTexture);
					offset += header->IndexCount * sizeof(unsigned);
					offset += header->MaterialCount * sizeof(MaterialDescription);
					return offset;
				case ANIMATEDMESHHEADERBLOCK:
					offset += sizeof(AnimatedMeshHeader);
					offset += header->VertexCount * sizeof(AnimationVertex);
					offset += header->IndexCount * sizeof(unsigned);
					offset += header->MaterialCount * sizeof(MaterialDescription);
					offset += header->JointCount * sizeof(Joint);
					offset += header->KeyFrameCount * sizeof(FrameDescription);
					return offset;
			}			
			return -1;
		}

		Mesh* SmurfModelImporter::ExtractStaticMesh(SmurfModelImporter::StaticMeshHeader* header)
		{
			char* buffer = (char*)header;
			Mesh* mesh = new Mesh();

			buffer += sizeof(StaticMeshHeader);
			mesh->SetVertices(VertexPositionNormalTexture::Declaration, (void*)buffer, header->VertexCount);

			buffer += header->VertexCount * sizeof(VertexPositionNormalTexture);
			mesh->SetIndices((unsigned*)buffer, header->IndexCount);

			return mesh;
		}

		SkinnedMesh* SmurfModelImporter::ExtractAnimatedMesh(SmurfModelImporter::AnimatedMeshHeader* header)
		{
			char* buffer = (char*)header;
			SkinnedMesh* mesh = new SkinnedMesh();

			buffer += sizeof(AnimatedMeshHeader);
			mesh->SetVertices(AnimationVertex::Declaration, (void*)buffer, header->VertexCount);

			buffer += header->VertexCount * sizeof(AnimationVertex);
			mesh->SetIndices((unsigned*)buffer, header->IndexCount);

			buffer += header->IndexCount * sizeof(unsigned);
			buffer += sizeof(MaterialDescription);
			buffer += sizeof(int); // handles the joint block header
			mesh->Set_Joints((Joint*)buffer, header->JointCount);
			return mesh;
		}

		Material* SmurfModelImporter::ExtractMaterial(SmurfModelImporter::AnimatedMeshHeader* header)
		{
			size_t d = sizeof(AnimationVertex);

			Material* material;
			MaterialDescription* materialDesc;
			unsigned offset = 0;
			char* buffer = (char*)header;
			offset += header->Type == STATICMESHHEADERBLOCK ? sizeof(StaticMeshHeader) : sizeof(AnimatedMeshHeader);
			offset += header->VertexCount * (header->Type == STATICMESHHEADERBLOCK ? sizeof(VertexPositionNormalTexture) : sizeof(AnimationVertex));
			offset += header->IndexCount * sizeof(unsigned);
			materialDesc = (MaterialDescription*)(buffer + offset);

			material = Material::CreateBasicMaterial();
			
			if(strlen(&materialDesc->TextureName[0]) > 0)
			{
				String texturePath = this->m_kDefaultPath;
				texturePath.append(String(&materialDesc->TextureName[0]));
				material->Set_MainTexture(Texture2D::LoadTextureFromFile(texturePath));
			}
			
			//material->Set_Color(Color(&materialDesc->MainColor[0]));
			
			return material;
		}

		Animation* SmurfModelImporter::ExtractAnimation(SmurfModelImporter::AnimatedMeshHeader* header)
		{
			Keyframe* keyframe;
			Animation* animation = new Animation();		// where does this get deleted?
			AnimationClip* clip = new AnimationClip();	// where does this get deleted?
			
			unsigned offset = 0;
			char* buffer = (char*)header;
			offset += sizeof(AnimatedMeshHeader);
			offset += header->VertexCount * sizeof(AnimationVertex);
			offset += header->IndexCount * sizeof(unsigned);
			offset += sizeof(MaterialDescription);
			offset += sizeof(int) + sizeof(Joint) * header->JointCount;
			offset += sizeof(int);

			Singularity::Animations::Frame* frames = new Singularity::Animations::Frame[header->FrameCount];

			int count = header->KeyFrameCount;
			for(int i = 0; i < count; ++i)
			{
				keyframe = (Keyframe*)(buffer + offset);
				frames[keyframe->FrameNumber - 1].Index = keyframe->FrameNumber - 1;
				frames[keyframe->FrameNumber - 1].Keyframes.push_back(*keyframe);
				offset += sizeof(Keyframe);
			}	

			for(unsigned i = 0; i < header->FrameCount; ++i)
				clip->AddKeyframe(frames[i]);

			animation->SetClip(clip);
			return animation;
		}

		GameObject* SmurfModelImporter::ExtractCollider(GameObject* parent, SmurfModelImporter::CollisionHeader* header, unsigned index, unsigned type)
		{
			char indexString[10];
			String name = "Collider-";
			Quaternion orientation;
			char* buffer = (char*)header;
			buffer += sizeof(CollisionHeader) + index * sizeof(BoxColliderDescription);
			BoxColliderDescription* desc = (BoxColliderDescription*)buffer;

			_itoa_s(index, &indexString[0], 10, 10);
			name.append(indexString);
			//D3DXQuaternionNormalize(&orientation, &desc->Orientation);
			GameObject* object = GameObject::Create(name, parent);
			object->Get_Transform()->Set_Position(desc->Center);
			object->Get_Transform()->Set_Rotation(desc->Orientation);
			BoxCollider* col = new BoxCollider(name, Vector3(0,0,0), desc->HalfWidth * 2.0f);
			object->AddComponent(col);
			//col->Rotate(desc->Orientation);
			//object->Get_Transform()->Set_Rotation(desc->Orientation);
			

			return object;
		}
		#pragma endregion

		#pragma region IContentImporter Methods
		void SmurfModelImporter::LoadFile(String path)
		{
			FILE* file = fopen(path.c_str(), "rb");
			if (!file)
			{
				fprintf(stderr, "Unable to open file %s", path.c_str());
				return;
			}
			
			//Get file length
			fseek(file, 0, SEEK_END);
			this->m_pBufferLength = ftell(file);
			fseek(file, 0, SEEK_SET);

			//Deallocate memory if needed
			if(this->m_pBuffer)
				free(this->m_pBuffer);

			//Allocate memory
			this->m_pBuffer = (char*)malloc(this->m_pBufferLength + 1);
			if (!this->m_pBuffer)
			{
				fprintf(stderr, "Memory error!"); 
				fclose(file);
				return;
			}

			//Read file contents into buffer
			fread(this->m_pBuffer, this->m_pBufferLength, 1, file);
			fclose(file);

			char fileId[5] = {'s','m','u','r','f'};
			SmurfModelImporter::FileHeader* header = (SmurfModelImporter::FileHeader*)this->m_pBuffer;
			if(memcmp(header->FileId, &fileId[0], sizeof(char) * 5) != 0)
				throw SingularityException("Unknown file format; unable to read SMURF model definitions.");
		}
		#pragma endregion

		#pragma region IModelImporter Methods
		Singularity::Graphics::Mesh* SmurfModelImporter::LoadMesh(unsigned index)
		{
			Mesh* mesh;
			AnimatedMeshHeader* header;
			unsigned offset = sizeof(SmurfModelImporter::FileHeader);
			unsigned currentIndex = 0;

			while(currentIndex < index && offset < this->m_pBufferLength)
			{
				offset = this->MoveToNextMesh(offset);
				currentIndex++;
			}

			if(offset >= this->m_pBufferLength)
				return NULL;

			header = (AnimatedMeshHeader*)(this->m_pBuffer + offset);
			switch(header->Type)
			{
				case STATICMESHHEADERBLOCK:
					mesh = this->ExtractStaticMesh((StaticMeshHeader*)header);
					if(mesh == NULL)
						throw SingularityException("Failed to extract mesh object.");
					return mesh;
				case ANIMATEDMESHHEADERBLOCK:
					mesh = this->ExtractAnimatedMesh(header);
					if(mesh == NULL)
						throw SingularityException("Failed to extract mesh object.");
					return mesh;
			}

			return NULL;
		}

		Singularity::Graphics::Material* SmurfModelImporter::LoadMaterial(unsigned index)
		{
			Material* material;
			AnimatedMeshHeader* header;
			unsigned offset = sizeof(SmurfModelImporter::FileHeader);
			unsigned currentIndex = 0;

			while(currentIndex < index && offset < this->m_pBufferLength)
			{
				offset = this->MoveToNextMesh(offset);
				currentIndex++;
			}

			if(offset >= this->m_pBufferLength)
				return NULL;

			header = (AnimatedMeshHeader*)(this->m_pBuffer + offset);
			switch(header->Type)
			{
				case STATICMESHHEADERBLOCK:
					material = this->ExtractMaterial(header);
					if(material == NULL)
						throw SingularityException("Failed to extract material description.");
					return material;
				case ANIMATEDMESHHEADERBLOCK:
					material = this->ExtractMaterial(header);
					if(material == NULL)
						throw SingularityException("Failed to extract material description.");
					return material;
			}

			return NULL;
		}

		Singularity::Components::GameObject* SmurfModelImporter::LoadModel(unsigned index)
		{
			Animation* animation;
			Material* material;
			Mesh* mesh;
			AnimatedMeshHeader* header;
			GameObject* object = NULL;
			unsigned offset = sizeof(SmurfModelImporter::FileHeader);
			unsigned currentIndex = 0;

			while(currentIndex < index && offset < this->m_pBufferLength)
			{
				offset = this->MoveToNextMesh(offset);
				currentIndex++;
			}

			if(offset >= this->m_pBufferLength)
				return NULL;

			header = (AnimatedMeshHeader*)(this->m_pBuffer + offset);
			switch(header->Type)
			{
				case STATICMESHHEADERBLOCK:
					mesh = this->ExtractStaticMesh((StaticMeshHeader*)header);
					if(mesh == NULL)
						throw SingularityException("Failed to extract mesh object.");

					material = this->ExtractMaterial(header);
					if(material == NULL)
						throw SingularityException("Failed to extract material description.");

					object = GameObject::Create("");
					object->AddComponent(new MeshRenderer(mesh, material));
					break;
				case ANIMATEDMESHHEADERBLOCK:
					mesh = this->ExtractAnimatedMesh(header);
					if(mesh == NULL)
						throw SingularityException("Failed to extract mesh object.");

					material = this->ExtractMaterial(header);
					if(material == NULL)
						throw SingularityException("Failed to extract material description.");

					animation = this->ExtractAnimation(header);
					animation->Set_Mesh((SkinnedMesh*)mesh);

					if(animation == NULL)
						throw SingularityException("Failed to extract animation description.");

					object = GameObject::Create("");
					object->AddComponent(new SkinnedMeshRenderer(mesh));
					object->AddComponent(animation);
					break;
			}

			return object;
		}

		void SmurfModelImporter::LoadCollisionData(GameObject* object)
		{
			GameObject* child;
			CollisionHeader* header;
			unsigned offset = sizeof(SmurfModelImporter::FileHeader);
			unsigned currentIndex = 0;

			while(currentIndex < this->Get_ModelCount() && offset < this->m_pBufferLength)
			{
				offset = this->MoveToNextMesh(offset);
				currentIndex++;
			}

			if(offset >= this->m_pBufferLength)
				return;

			header = (CollisionHeader*)(this->m_pBuffer + offset);
			for(offset = 0; offset < header->BoxColliderCount; ++offset)
				child = this->ExtractCollider(object, header, offset, 0);
			return;
		}
		#pragma endregion
	}
}