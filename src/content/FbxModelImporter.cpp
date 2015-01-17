#include "content\Singularity.Content.h"

using namespace Singularity;
using namespace Singularity::Animations;
using namespace Singularity::Graphics;

namespace Singularity
{
	namespace Content
	{
		#pragma region Static Methods
		//Converts FBX's Double3 data format to our Vector3 (D3DX) format
		void FbxModelImporter::FbxDoubleToVector3(const fbxDouble3& data, Vector3* outVector)
		{
			outVector->x = (float)data[0];
			outVector->y = (float)data[1];
			outVector->z = (float)data[2];
		}

		//Converts FBX's Double3 data format to our Quaternion (D3DX) format
		void FbxModelImporter::FbxRotationToQuaternion(const float dataX, const float dataY, const float dataZ, ERotationOrder rotOrder, Quaternion *outQuat)
		{
			Quaternion x, y, z;
			Vector3 right, up, forward;

			right = Vector3(1.0f, 0.0f, 0.0f);
			up = Vector3(0.0f, 1.0f, 0.0f);
			forward = Vector3(0.0f, 0.0f, -1.0f);

			//X axis
			D3DXQuaternionRotationAxis(&x, &right, (D3DX_PI * (float)dataX) / 180);
			D3DXQuaternionNormalize(&x, &x);

			//y axis
			D3DXQuaternionRotationAxis(&y, &up, (D3DX_PI * (float)dataY) / 180);
			D3DXQuaternionNormalize(&y, &y);

			//z axis
			D3DXQuaternionRotationAxis(&z, &forward, (D3DX_PI * (float)dataZ) / 180);
			D3DXQuaternionNormalize(&z, &z);

			switch(rotOrder)
			{
			case eEULER_XYZ:
				(*outQuat) = x * y * z;
				break;
			case eEULER_XZY: 
				(*outQuat) = x * z * y;
				break;
			case eEULER_YZX:
				(*outQuat) = y * z * x;
				break;
			case eEULER_YXZ:
				(*outQuat) = x * z * y;
				break;
			case eEULER_ZXY:
				(*outQuat) = z * x * y;
				 break;
			case eEULER_ZYX: 
				(*outQuat) = z * y * x;
				break;
			case eSPHERIC_XYZ: 
				throw SingularityException("Singularity::Content::FbxModelImporter - FbxRotationToQuaternion() - eSPHERIC_XYZ not supported.");
				break;
			}

			D3DXQuaternionNormalize(outQuat, outQuat);
		}

		//Overloaded method that converts FBX's Double3 data format to our Quaternion (D3DX) format
		void FbxModelImporter::FbxRotationToQuaternion(fbxDouble3 data, ERotationOrder rotOrder, Quaternion* outQuat)
		{
			FbxModelImporter::FbxRotationToQuaternion((float)data[0], (float)data[1], (float)data[2], rotOrder, outQuat);
		}
		#pragma endregion

		#pragma region Constructors and Finalizers
		FbxModelImporter::FbxModelImporter()
			: m_pSDKManager(NULL), m_pImporter(NULL), m_pScene(NULL), m_iMeshCount(0)
		{
			this->m_pSDKManager = KFbxSdkManager::Create();
			this->m_pImporter = KFbxImporter::Create(this->m_pSDKManager, "MeshLoader.Importer");
		}

		FbxModelImporter::~FbxModelImporter()
		{
			if(this->m_pScene)
				this->m_pScene->Destroy();

			if(this->m_pImporter)
				this->m_pImporter->Destroy();

			if(this->m_pSDKManager)
				this->m_pSDKManager->Destroy();
		}
		#pragma endregion

		#pragma region Methods
		//Comparison Function that will allow us to sort the keyframes within an animation clip
		bool FbxModelImporter::SortKeyFrames(Keyframe key1, Keyframe key2)
		{
			//return key1.TimeOffset < key2.TimeOffset;
			return true;
		}

		//Extracts the mesh from the KFbxMesh object and converts it to our native Mesh object format
		Mesh* FbxModelImporter::ExtractStaticMesh(KFbxMesh* mesh)
		{
			unsigned i, j;
			KFbxVector4 position;
			KFbxVector4 normal;
			KFbxVector2 uv;
			DynamicList<VertexPositionNormalTexture> vertices;
			DynamicList<VertexPositionNormalTexture>::iterator it;
			DynamicList<unsigned> indices;
			VertexPositionNormalTexture* vertBuff;
			unsigned* indexBuff;
			Mesh* newMesh;

			//Get teh UVs.
			KFbxLayerElementUV* uvs = mesh->GetLayer(0, KFbxLayerElement::eUV)->GetUVs();

			//Extract the vertex data
			for(i = 0; i < mesh->GetPolygonCount(); i++)
			{
				for(j = 0; j < mesh->GetPolygonSize(i); j++)
				{
					position = mesh->GetControlPoints()[mesh->GetPolygonVertex(i, j)];
					mesh->GetPolygonVertexNormal(i, j, normal);
					uv = uvs->GetDirectArray()[mesh->GetTextureUVIndex(i, j)];
					
					VertexPositionNormalTexture newVert;
					newVert.position.x = position.GetAt(0);
					newVert.position.y = position.GetAt(1);
					newVert.position.z = position.GetAt(2);

					newVert.normal.x = normal.GetAt(0);
					newVert.normal.y = normal.GetAt(1);
					newVert.normal.z = normal.GetAt(2);
			
					newVert.texCoord.x = uv.GetAt(0);
					newVert.texCoord.y = 1.0f - uv.GetAt(1);

					D3DXVec3Normalize(&newVert.normal, &newVert.normal);

					it = std::find(vertices.begin(), vertices.end(), newVert);
					if(it == vertices.end())
					{
						vertices.push_back(newVert);
						indices.push_back(vertices.size() - 1);
					}
					else
					{
						indices.push_back(it - vertices.begin());
					}
				}
			}

			//ofstream myfile;
			//myfile.open ("C:\\Users\\GDDAdmin\\Desktop\\gdd_capstone\\Code\\Singularity_Engine\\resources\\vertices.txt", ios::out | ios::trunc | ios::binary);
			//Create buffers.
			vertBuff = new VertexPositionNormalTexture[vertices.size()];
			for(i = 0; i < vertices.size(); i++)
			{
				//myfile.write((char*)&vertices[i], sizeof(VertexPositionNormalTexture));
				vertBuff[i] = vertices[i];
			}
			//myfile.close();

			//myfile.open ("C:\\Users\\GDDAdmin\\Desktop\\gdd_capstone\\Code\\Singularity_Engine\\resources\\indices.txt", ios::out | ios::trunc | ios::binary);
			indexBuff = new unsigned[indices.size()];
			for(i = 0; i < indices.size(); i++)
			{
				//myfile.write((char*)&indices[i], sizeof(unsigned));
				indexBuff[i] = indices[i];
			}
			//myfile.close();

			newMesh = new Mesh();
			newMesh->SetVertices(VertexPositionNormalTexture::Declaration, vertBuff, vertices.size());
			newMesh->SetIndices(indexBuff, indices.size());

			//bind the skeleton to the mesh
			

			delete [] vertBuff;
			delete [] indexBuff;

			return newMesh;
		}

		//Mesh* FbxModelImporter::ExtractAnimatedMesh(KFbxMesh *mesh)
		//{
		//	unsigned i, j, k, l, count;
		//	KFbxVector4 position;
		//	KFbxVector4 normal;
		//	KFbxVector2 uv;
		//	DynamicList<VertexPositionNormalTextureBone> vertices;
		//	DynamicList<VertexPositionNormalTextureBone>::iterator it;
		//	DynamicList<unsigned> indices;
		//	VertexPositionNormalTextureBone* vertBuff;
		//	unsigned* indexBuff;
		//	Mesh* newMesh;

		//	//Get teh UVs.
		//	KFbxLayerElementUV* uvs = mesh->GetLayer(0, KFbxLayerElement::eUV)->GetUVs();

		//	if(mesh->GetTakeNodeCount() == 0)
		//		throw SingularityException("There is no animation in this mesh, cannot load animated mesh");

		//	count = mesh->GetTakeNodeCount();

		//	mesh->SetCurrentTakeNode(1);
		//	KFbxSkin* skin = dynamic_cast<KFbxSkin*>(mesh->GetDeformer(0));
		//	if(!skin)
		//		throw SingularityException("First deformer is not a skin object");

		//	//Extract the vertex data
		//	count = mesh->GetPolygonCount();

		//	for(i = 0; i < mesh->GetPolygonCount(); i++)
		//	{
		//		std::cout << "Index: " << i << std::endl;

		//		for(j = 0; j < mesh->GetPolygonSize(i); j++)
		//		{
		//			position = mesh->GetControlPoints()[mesh->GetPolygonVertex(i, j)];
		//			mesh->GetPolygonVertexNormal(i, j, normal);
		//			uv = uvs->GetDirectArray()[mesh->GetTextureUVIndex(i, j)];
		//			
		//			VertexPositionNormalTextureBone newVert;
		//			newVert.position.x = position.GetAt(0);
		//			newVert.position.y = position.GetAt(1);
		//			newVert.position.z = position.GetAt(2);

		//			newVert.normal.x = normal.GetAt(0);
		//			newVert.normal.y = normal.GetAt(1);
		//			newVert.normal.z = normal.GetAt(2);
		//	
		//			newVert.textureCoord.x = uv.GetAt(0);
		//			newVert.textureCoord.y = 1.0f - uv.GetAt(1);

		//			D3DXVec3Normalize(&newVert.normal, &newVert.normal);

		//			newVert.boneIndex = 0;

		//			newVert.boneWeights.x = 0.0f;
		//			newVert.boneWeights.y = 0.0f;
		//			newVert.boneWeights.z = 0.0f;
		//			newVert.boneWeights.w = 0.0f;

		//			unsigned int existanceCount = 0;

		//			KFbxCluster* cluster;

		//			for(k = 0; k < skin->GetClusterCount(); k++)
		//			{
		//				if(existanceCount > 3)
		//					break;

		//				count = skin->GetCluster(k)->GetControlPointIndicesCount();

		//				for(l = 0; l < skin->GetCluster(k)->GetControlPointIndicesCount(); l++)
		//				{
		//					cluster = skin->GetCluster(k);
		//					if(skin->GetCluster(k)->GetControlPointIndices()[l] == mesh->GetPolygonVertex(i, j))
		//					{
		//						//update bone indices with fun math
		//						//set appropriate weight
		//						if(existanceCount > 3)
		//							break;

		//						switch(existanceCount)
		//						{
		//							case 0:
		//								newVert.boneWeights.x = skin->GetCluster(k)->GetControlPointWeights()[l];
		//								newVert.boneIndex = (unsigned int)k;
		//								break;
		//							case 1:
		//								newVert.boneWeights.y = skin->GetCluster(k)->GetControlPointWeights()[l];
		//								newVert.boneIndex = newVert.boneIndex | (((unsigned int)k) << 8);
		//								break;
		//							case 2:
		//								newVert.boneWeights.z = skin->GetCluster(k)->GetControlPointWeights()[l];
		//								newVert.boneIndex = newVert.boneIndex | (((unsigned int)k) << 16);
		//								break;
		//							case 3:
		//								newVert.boneWeights.w = skin->GetCluster(k)->GetControlPointWeights()[l];
		//								newVert.boneIndex = newVert.boneIndex | (((unsigned int)k) << 24);
		//								break;
		//						}

		//						existanceCount++;
		//					}
		//				}
		//			}

		//			it = std::find(vertices.begin(), vertices.end(), newVert);
		//			if(it == vertices.end())
		//			{
		//				vertices.push_back(newVert);
		//				indices.push_back(vertices.size() - 1);
		//			}
		//			else
		//			{
		//				indices.push_back(it - vertices.begin());
		//			}
		//		}
		//	}

		//	//ofstream myfile;
		//	//myfile.open ("C:\\Users\\GDDAdmin\\Desktop\\gdd_capstone\\Code\\Singularity_Engine\\resources\\vertices.txt", ios::out | ios::trunc | ios::binary);
		//	//Create buffers.
		//	vertBuff = new VertexPositionNormalTextureBone[vertices.size()];
		//	for(i = 0; i < vertices.size(); i++)
		//	{
		//		//myfile.write((char*)&vertices[i], sizeof(VertexPositionNormalTexture));
		//		vertBuff[i] = vertices[i];
		//	}
		//	//myfile.close();

		//	//myfile.open ("C:\\Users\\GDDAdmin\\Desktop\\gdd_capstone\\Code\\Singularity_Engine\\resources\\indices.txt", ios::out | ios::trunc | ios::binary);
		//	indexBuff = new unsigned[indices.size()];
		//	for(i = 0; i < indices.size(); i++)
		//	{
		//		//myfile.write((char*)&indices[i], sizeof(unsigned));
		//		indexBuff[i] = indices[i];
		//	}
		//	//myfile.close();

		//	newMesh = new Mesh();
		//	newMesh->SetVertices(VertexPositionNormalTextureBone::Declaration, vertBuff, vertices.size());
		//	newMesh->SetIndices(indexBuff, indices.size());

		//	//bind the skeleton to the mesh
		//	

		//	delete [] vertBuff;
		//	delete [] indexBuff;

		//	return newMesh;
		//}

		//ModelSkeleton* FbxModelImporter::ProcessSkeleton(KFbxNode* node, Animation* animation)
		//{
		//	//Initialization
		//	unsigned i, j, keyCount, count;
		//	//create a temporary bones and animation clips
		//	DynamicList<ModelBone*> bones;
		//	DynamicList<AnimationClip*> clips;
		//	ModelSkeleton* skeleton;
		//	Vector3 position, scale, tmp1, tmp2;
		//	Quaternion rotation, tmpQuat;
		//	Matrix transform, invTransform;

		//	KFCurve* tx;
		//	KFCurve* ty;
		//	KFCurve* tz;

		//	KFCurve* rx;
		//	KFCurve* ry;
		//	KFCurve* rz;

		//	KFCurve* sx;
		//	KFCurve* sy;
		//	KFCurve* sz;

		//	//process the root bone starting with its transform
		//	FbxModelImporter::FbxDoubleToVector3(node->LclTranslation.Get(), &position);
		//	FbxModelImporter::FbxRotationToQuaternion(node->LclRotation.Get(), node->RotationOrder.Get(), &rotation);
		//	FbxModelImporter::FbxDoubleToVector3(node->LclScaling.Get(), &scale);

		//	tmp1, tmp2 = Vector3(0, 0, 0);
		//	tmpQuat = Quaternion(0, 0, 0, 1);
		//	D3DXMatrixTransformation(&transform, &tmp1, &tmpQuat, &scale, &tmp2, &rotation, &position);

		//	float det = D3DXMatrixDeterminant(&transform);
		//	D3DXMatrixInverse(&invTransform, &det, &transform);

		//	//Create the new bone
		//	ModelBone* bone = new ModelBone(0, (String)node->GetName());
		//	bone->SetBindPoses(transform, invTransform);
		//	bones.push_back(bone);

		//	
		//	//process the animation data for this bone
		//	//Origin variables used to compute transform information for the keyframes
		//	tmp1 = Vector3(0, 0, 0);
		//	tmpQuat = Quaternion(0, 0, 0, 1);

		//	//setting up the animation clips. First we'll process the keyframes in the root clip to find instances of clips begin and end
		//	clips.push_back(new AnimationClip("Test Clip"));

		//	//grabbing the take node count from the node. The node will represent the bone node that is coming in from the 
		//	if(node->GetTakeNodeCount())
		//	{
		//	
		//		node->SetCurrentTakeNode("Take 001");
		//		tx = node->LclTranslation.GetKFCurve(KFCURVENODE_T_X);
		//		ty = node->LclTranslation.GetKFCurve(KFCURVENODE_T_Y);
		//		tz = node->LclTranslation.GetKFCurve(KFCURVENODE_T_Z);

		//		rx = node->LclRotation.GetKFCurve(KFCURVENODE_R_X);
		//		ry = node->LclRotation.GetKFCurve(KFCURVENODE_R_Y);
		//		rz = node->LclRotation.GetKFCurve(KFCURVENODE_R_Z);

		//		sx = node->LclScaling.GetKFCurve(KFCURVENODE_S_X);
		//		sy = node->LclScaling.GetKFCurve(KFCURVENODE_S_Y);
		//		sz = node->LclScaling.GetKFCurve(KFCURVENODE_S_Z);

		//		keyCount = tx->KeyGetCount();

		//		if(	(ty->KeyGetCount() != keyCount) || 
		//			(tz->KeyGetCount() != keyCount) ||
		//			(rx->KeyGetCount() != keyCount) ||
		//			(ry->KeyGetCount() != keyCount) ||
		//			(rz->KeyGetCount() != keyCount) ||
		//			(sx->KeyGetCount() != keyCount) ||
		//			(sy->KeyGetCount() != keyCount) ||
		//			(sz->KeyGetCount() != keyCount))
		//		{
		//			throw SingularityException("Number of keyframes does not match across all nine transformation curves.");
		//		}

		//		clips[0]->Get_Keyframes().reserve(keyCount);

		//		//cycling through all the keyframes for the current take node
		//		for(j = 0; j < keyCount; j++)
		//		{
		//			position = Vector3((float)(tx->KeyGet(j).GetValue()),
		//								  (float)(ty->KeyGet(j).GetValue()),
		//								  (float)(tz->KeyGet(j).GetValue()));

		//			
		//			FbxModelImporter::FbxRotationToQuaternion(
		//				rx->KeyGet(j).GetValue(),
		//				ry->KeyGet(j).GetValue() + 90.0f,
		//				rz->KeyGet(j).GetValue(),
		//				node->RotationOrder.Get(),
		//				&rotation);

		//			D3DXQuaternionNormalize(&rotation, &rotation);

		//			scale = Vector3((float)(sx->KeyGet(j).GetValue()),
		//							(float)(sy->KeyGet(j).GetValue()),
		//							(float)(sz->KeyGet(j).GetValue()));

		//			D3DXMatrixTransformation(&transform, &tmp1, &tmpQuat, &scale, &tmp1, &rotation, &position);

		//			Keyframe keyframe;

		//			keyframe.TimeOffset = (float)tx->KeyGetTime(j).GetSecondDouble();
		//			keyframe.Transform = transform;
		//			keyframe.BoneIndex = 0;

		//			clips[0]->AddKeyframe(keyframe);
		//		}
		//	}

		//	//cycle through the KfbxNode's children
		//	//checking to see if there are any children in this node, if there are, continue processing the skeleton
		//	if(node->GetChildCount() > 0)
		//	{			
		//		for(unsigned i = 0; i < node->GetChildCount(); i++)
		//		{
		//			//run recursively through the skeleton tree until all bones have been processed
		//			//because we're starting at the top, the root node is NULL
		//			this->ProcessBone(node->GetChild(i), bone, bones, clips);	
		//		}
		//	}

		//	
		//	//After all the animation clips have been populated, go through them one more time to sort the keyframes based on time offset
		//	count = clips.size();

		//	for(i = 0; i < count; i++) 
		//		std::sort(clips[i]->Get_Keyframes().begin(), clips[i]->Get_Keyframes().end());
		//	
		//	//initialize the skeleton
		//	skeleton = new ModelSkeleton(bones.size());

		//	return skeleton;
		//}
		//
		////Processes the skeleton 
		//void FbxModelImporter::ProcessBone(KFbxNode* node, ModelBone* parent, DynamicList<ModelBone*> bones, DynamicList<AnimationClip*> clips)
		//{
		//	//Initialization
		//	unsigned count, i, j, keyCount;
		//	Vector3 position, scale, tmp1;
		//	Quaternion rotation, tmpQuat;
		//	Matrix transform, invTransform;

		//	//Curves for the animation transform
		//	KFCurve* tx;
		//	KFCurve* ty;
		//	KFCurve* tz;

		//	KFCurve* rx;
		//	KFCurve* ry;
		//	KFCurve* rz;

		//	KFCurve* sx;
		//	KFCurve* sy;
		//	KFCurve* sz;

		//	FbxModelImporter::FbxDoubleToVector3(node->LclTranslation.Get(), &position);
		//	FbxModelImporter::FbxRotationToQuaternion(node->LclRotation.Get(), node->RotationOrder.Get(), &rotation);
		//	FbxModelImporter::FbxDoubleToVector3(node->LclScaling.Get(), &scale);

		//	tmp1 = Vector3(0, 0, 0);
		//	tmpQuat = Quaternion(0, 0, 0, 1);
		//	D3DXMatrixTransformation(&transform, &tmp1, &tmpQuat, &scale, &tmp1, &rotation, &position);

		//	float det = D3DXMatrixDeterminant(&transform);
		//	D3DXMatrixInverse(&invTransform, &det, &transform);

		//	//Create the new bone
		//	ModelBone* bone = new ModelBone(bones.size(), (String)node->GetName());
		//	bone->SetBindPoses(transform, invTransform);
		//	bones.push_back(bone);

		//	//Add this node to the parent if this bone is not the root bone
		//	if(parent != NULL)
		//		parent->AddChild(bone);

		//	//process the animation data for this bone
		//	//Origin variables used to compute transform information for the keyframes
		//	tmp1 = Vector3(0, 0, 0);
		//	tmpQuat = Quaternion(0, 0, 0, 1);

		//	//grabbing the take node count from the node. The node will represent the bone node that is coming in from the 
		//	if(node->GetTakeNodeCount())
		//	{
		//	
		//		node->SetCurrentTakeNode(1);
		//		tx = node->LclTranslation.GetKFCurve(KFCURVENODE_T_X);
		//		ty = node->LclTranslation.GetKFCurve(KFCURVENODE_T_Y);
		//		tz = node->LclTranslation.GetKFCurve(KFCURVENODE_T_Z);

		//		rx = node->LclRotation.GetKFCurve(KFCURVENODE_R_X);
		//		ry = node->LclRotation.GetKFCurve(KFCURVENODE_R_Y);
		//		rz = node->LclRotation.GetKFCurve(KFCURVENODE_R_Z);

		//		sx = node->LclScaling.GetKFCurve(KFCURVENODE_S_X);
		//		sy = node->LclScaling.GetKFCurve(KFCURVENODE_S_Y);
		//		sz = node->LclScaling.GetKFCurve(KFCURVENODE_S_Z);

		//		keyCount = tx->KeyGetCount();

		//		if(	(ty->KeyGetCount() != keyCount) || 
		//			(tz->KeyGetCount() != keyCount) ||
		//			(rx->KeyGetCount() != keyCount) ||
		//			(ry->KeyGetCount() != keyCount) ||
		//			(rz->KeyGetCount() != keyCount) ||
		//			(sx->KeyGetCount() != keyCount) ||
		//			(sy->KeyGetCount() != keyCount) ||
		//			(sz->KeyGetCount() != keyCount))
		//		{
		//			throw SingularityException("Number of keyframes does not match across all nine transformation curves.");
		//		}

		//		clips[0]->Get_Keyframes().reserve(keyCount);

		//		//cycling through all the keyframes for the current take node
		//		for(j = 0; j < keyCount; j++)
		//		{
		//			position = Vector3((float)(tx->KeyGet(j).GetValue()),
		//								  (float)(ty->KeyGet(j).GetValue()),
		//								  (float)(tz->KeyGet(j).GetValue()));

		//			
		//			FbxModelImporter::FbxRotationToQuaternion(
		//				rx->KeyGet(j).GetValue(),
		//				ry->KeyGet(j).GetValue() + 90.0f,
		//				rz->KeyGet(j).GetValue(),
		//				node->RotationOrder.Get(),
		//				&rotation);

		//			D3DXQuaternionNormalize(&rotation, &rotation);

		//			scale = Vector3((float)(sx->KeyGet(j).GetValue()),
		//							(float)(sy->KeyGet(j).GetValue()),
		//							(float)(sz->KeyGet(j).GetValue()));

		//			D3DXMatrixTransformation(&transform, &tmp1, &tmpQuat, &scale, &tmp1, &rotation, &position);

		//			Keyframe keyframe;

		//			keyframe.TimeOffset = (float)tx->KeyGetTime(j).GetSecondDouble();
		//			keyframe.Transform = transform;
		//			keyframe.BoneIndex = 0;

		//			clips[0]->AddKeyframe(keyframe);
		//		}
		//	}

		//	//cycle through the KfbxNode's children
		//	
		//	count = node->GetChildCount();
		//	
		//	//checking to see if there are any children in this node, if there are, continue processing the skeleton
		//	if(count > 0)
		//		for(i = 0; i < node->GetChildCount(); i++)
		//		{
		//			//run recursively through the skeleton tree until all bones have been processed
		//			//because we're starting at the top, the root node is NULL
		//			this->ProcessBone(node->GetChild(i), bone, bones, clips);	
		//		}
		//}

		//ModelSkeleton* FbxModelImporter::GetSkeleton(KFbxScene* scene, GameObject* obj)
		//{
		//	unsigned index, count;
		//	ModelSkeleton* skeleton;

		//	if(scene == NULL)
		//		return NULL;

		//	count = scene->GetNodeCount();
		//	for(index = 0; index < count; ++index)
		//	{
		//		if(skeleton = this->GetSkeleton(scene->GetNode(index), obj))
		//			return skeleton;
		//	}
		//	return NULL;
		//}

		//ModelSkeleton* FbxModelImporter::GetSkeleton(KFbxNode* node, GameObject* obj)
		//{
		//	unsigned index, count;
		//	KFbxNodeAttribute* attribute;
		//	ModelSkeleton* skeleton;
		//	Animation* animation = NULL;

		//	if(node == NULL)
		//		return NULL;

		//	attribute = node->GetNodeAttribute();
		//	if(attribute != NULL && attribute->GetAttributeType() == KFbxNodeAttribute::eSKELETON)
		//	{
		//		obj->AddComponent(animation = new Animation("Animation Component", NULL));
		//		return this->ProcessSkeleton(node, animation);
		//	}
		//	
		//	count = node->GetChildCount();
		//	for(index = 0; index < count; ++index)
		//	{
		//		if(skeleton = this->GetSkeleton(node->GetChild(index), obj))
		//			return skeleton;
		//	}
		//	return NULL;
		//}
		#pragma endregion

		#pragma region IContentImporter Methods
		void FbxModelImporter::LoadFile(String path)
		{
			this->m_pScene = KFbxScene::Create(this->m_pSDKManager, "");

			if(!this->m_pImporter->Initialize(path.c_str()))
				throw SingularityException(this->m_pImporter->GetLastErrorString(), this->m_pImporter->GetLastErrorID());
			
			if(!this->m_pImporter->Import(this->m_pScene))
				throw SingularityException("Unable to load FBX scene.");

			this->m_iMeshCount = this->m_pScene->GetGeometryCount();
		}
		#pragma endregion

		#pragma region IModelImporter Methods
		GameObject* FbxModelImporter::LoadModel(int index)
		{
			KFbxNodeAttribute* attribute;
			KFbxGeometry* geometry;
			GameObject* obj = NULL;
			Mesh* objMesh;
			//ModelSkeleton* objSkeleton;
			//Animation* animation;

			if(this->m_pScene == NULL)
				throw SingularityException("Either the file has not been loaded or there is an issue with the file format.");
			
			if(this->m_pScene->GetGeometryCount() == 0)
				throw SingularityException("No mesh information is found in the file.");

			obj = GameObject::Create("fbx.loaded");

#ifdef _DEBUG
			KArrayTemplate<KString*> lTakeNameArray;
		
			this->m_pScene->FillTakeNameArray(lTakeNameArray);

			for(int i = 0; i < lTakeNameArray.GetCount(); i++)
			{
				this->m_pScene->SetCurrentTake(lTakeNameArray.GetAt(i)->Buffer());
				std::cout << "Take: " << i << " " <<  this->m_pScene->GetCurrentTakeName() << std::endl;

			}
#endif

			//check to see if the kfbxscene has a mesh (should have only 1)
			if(objMesh = this->GetMesh(this->m_pScene))
				obj->AddComponent(new MeshRenderer(objMesh));

			//check to see if the kbxscene has a skeleton. If it does, we add it to the mesh
			//if(objSkeleton = this->GetSkeleton(this->m_pScene, obj))
			//	objMesh->AddSkeleton(objSkeleton);
			
			return obj;
		}

		//Retrieve the mesh loaded from the file
		Mesh* FbxModelImporter::GetMesh(KFbxScene* scene)
		{
			unsigned index, count;
			Mesh* mesh = NULL;

			if(scene == NULL)
				return NULL;

			count = scene->GetNodeCount();
			for(index = 0; index < count; ++index)
				if(mesh = this->GetMesh(scene->GetNode(index), mesh))
					return mesh;

			return NULL;
		}

		//extracting the mesh data from the node if a mesh is found
		Mesh* FbxModelImporter::GetMesh(KFbxNode* node, Mesh* mesh)
		{
			unsigned index, count;
			KFbxNodeAttribute* attribute;

			if(node == NULL)
				return NULL;

			attribute = node->GetNodeAttribute();
			if(attribute != NULL && attribute->GetAttributeType() == KFbxNodeAttribute::eMESH)
			{
				KFbxMesh* kMesh = (KFbxMesh*)node->GetNodeAttribute();
				unsigned deformerCount;

				/*if(kMesh->GetDeformerCount())
					mesh = this->ExtractAnimatedMesh(kMesh);
				else*/
					mesh = this->ExtractStaticMesh(kMesh);

				return mesh;
			}
			
			count = node->GetChildCount();
			for(index = 0; index < count; ++index)
			{
				if(mesh = this->GetMesh(node->GetChild(index), mesh))
					return mesh;
			}
			return NULL;
		}

		//Retrieving the animations from this mesh
		/*Animation* FbxModelImporter::GetAnimation(KFbxScene* scene)
		{
			unsigned index, count;
			Animation* animation = NULL;

			if(scene == NULL)
				return NULL;

			count = scene->GetNodeCount();
			for(index = 0; index < count; ++index)
				if(animation = this->GetAnimation(scene->GetNode(index), animation))
					return animation;

			return NULL;
		}*/

		/*Animation* FbxModelImporter::GetAnimation(KFbxNode* node, Animation* animation)
		{
			unsigned index, count;
			KFbxNodeAttribute* attribute;

			if(node == NULL)
				return NULL;

			attribute = node->GetNodeAttribute();
			if(attribute != NULL && attribute->GetAttributeType() == KFbxNodeAttribute::eSKELETON && node->GetTakeNodeCount() > 0)
			{
				animation = this->ProcessAnimation(node);
				return animation;
			}
			
			count = node->GetChildCount();
			for(index = 0; index < count; ++index)
			{
				if(animation = this->GetAnimation(node->GetChild(index), animation))
					return animation;
			}
			return NULL;
		}*/

		//Animation* FbxModelImporter::ProcessAnimation(KFbxNode* node)
		//{
		//	//Initialize animation and clip list
		//	Animation* animation;
		//	animation = new Animation((String)"Animation Component", NULL);
		//	DynamicList<AnimationClip*> clips;
		//	unsigned count, index, boneIndex;

		//	//Create animation object and register empty animation clips
		//	//getting the clip counts
		//	count = node->GetTakeNodeCount();

		//	//create list of empty clips to iterate through later
		//	for(index = 0; index < count; index++)
		//	{
		//		String name = node->GetTakeNodeName(index);
		//		clips.push_back(new AnimationClip(name));
		//	}
		//	
		//	//process the bones based on the skeleton
		//	boneIndex = 0;
		//	count = node->GetChildCount();
		//	for(index = 0; index < count; index++)
		//		this->ProcessAnimatedBone(node->GetChild(index), boneIndex, clips);

		//	//After all the animation clips have been populated, go through them one more time to sort the keyframes based on time offset
		//	count = clips.size();
		//	DynamicList<Keyframe> keyframes;

		//	for(index = 0; index < count; index++)
		//	{
		//		keyframes = clips[index]->Get_Keyframes();
		//		std::sort(keyframes.begin(), keyframes.end());
		//	}
		//	return animation;
		//}

		//void FbxModelImporter::ProcessAnimatedBone(KFbxNode* node, int boneIndex, DynamicList<AnimationClip*> clips)
		//{
		//	
		//	//initializing transform variables
		//	unsigned count, i, j;
		//	int keyCount;
		//	Vector3 translation, scale, tmp1;
		//	Quaternion rotation, tmpQuat;
		//	Matrix transform;

		//	//Process the errors in the fbx node
		//	count = node->GetError().GetErrorCount();
		//	for(i = 0; i < count; i++)
		//	{
		//		std::cout << "Error: " << i << node->GetError().GetErrorString(i) << std::endl;
		//	}

		//	//Origin variables used to compute transform information for the keyframes
		//	tmp1 = Vector3(0, 0, 0);
		//	tmpQuat = Quaternion(0, 0, 0, 1);

		//	KFCurve* tx;
		//	KFCurve* ty;
		//	KFCurve* tz;

		//	KFCurve* rx;
		//	KFCurve* ry;
		//	KFCurve* rz;

		//	KFCurve* sx;
		//	KFCurve* sy;
		//	KFCurve* sz;

		//	//grabbing the take node count from the node. The node will represent the bone node that is coming in from the 
		//	if(node->GetTakeNodeCount())
		//	{
		//	
		//		node->SetCurrentTakeNode(1);
		//		tx = node->LclTranslation.GetKFCurve(KFCURVENODE_T_X);
		//		ty = node->LclTranslation.GetKFCurve(KFCURVENODE_T_Y);
		//		tz = node->LclTranslation.GetKFCurve(KFCURVENODE_T_Z);

		//		rx = node->LclRotation.GetKFCurve(KFCURVENODE_R_X);
		//		ry = node->LclRotation.GetKFCurve(KFCURVENODE_R_Y);
		//		rz = node->LclRotation.GetKFCurve(KFCURVENODE_R_Z);

		//		sx = node->LclScaling.GetKFCurve(KFCURVENODE_S_X);
		//		sy = node->LclScaling.GetKFCurve(KFCURVENODE_S_Y);
		//		sz = node->LclScaling.GetKFCurve(KFCURVENODE_S_Z);

		//		keyCount = tx->KeyGetCount();

		//		if(	(ty->KeyGetCount() != keyCount) || 
		//			(tz->KeyGetCount() != keyCount) ||
		//			(rx->KeyGetCount() != keyCount) ||
		//			(ry->KeyGetCount() != keyCount) ||
		//			(rz->KeyGetCount() != keyCount) ||
		//			(sx->KeyGetCount() != keyCount) ||
		//			(sy->KeyGetCount() != keyCount) ||
		//			(sz->KeyGetCount() != keyCount))
		//		{
		//			throw SingularityException("Number of keyframes does not match across all nine transformation curves.");
		//		}

		//		clips[1]->Get_Keyframes().reserve(keyCount);

		//		//cycling through all the keyframes for the current take node
		//		for(j = 0; j < keyCount; j++)
		//		{
		//			translation = Vector3((float)(tx->KeyGet(j).GetValue()),
		//								  (float)(ty->KeyGet(j).GetValue()),
		//								  (float)(tz->KeyGet(j).GetValue()));

		//			FbxModelImporter::FbxRotationToQuaternion(
		//				rx->KeyGet(j).GetValue(),
		//				ry->KeyGet(j).GetValue() + 90.0f,
		//				rz->KeyGet(j).GetValue(),
		//				node->RotationOrder.Get(),
		//				&rotation);

		//			D3DXQuaternionNormalize(&rotation, &rotation);

		//			scale = Vector3((float)(sx->KeyGet(j).GetValue()),
		//							(float)(sy->KeyGet(j).GetValue()),
		//							(float)(sz->KeyGet(j).GetValue()));

		//			D3DXMatrixTransformation(&transform, &tmp1, &tmpQuat, &scale, &tmp1, &rotation, &translation);

		//			Keyframe keyframe;

		//			keyframe.TimeOffset = (float)tx->KeyGetTime(j).GetSecondDouble();
		//			keyframe.Transform = transform;
		//			keyframe.BoneIndex = boneIndex;

		//			clips[1]->AddKeyframe(keyframe);
		//		}
		//	}

		//	//cycle through the children of this node
		//	count = node->GetChildCount();
		//	for(i = 0; i < count; i++)
		//		this->ProcessAnimatedBone(node->GetChild(i), boneIndex++, clips);

		//}

		#pragma endregion
	}
}