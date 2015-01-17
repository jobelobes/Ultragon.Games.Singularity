#include "graphics\Singularity.Graphics.h"

namespace Singularity
{
	namespace Graphics
	{		
		#pragma region Static Variables
		DynamicList<InternalMaterial*> InternalMaterial::g_pBuffers;
		#pragma endregion

		#pragma region Constructors and Finalizers
		InternalMaterial::InternalMaterial(ID3D10Effect* effect)
			: m_pEffect(effect), m_pTechnique(NULL), m_iVariableCount(0), m_iCacheSize(0), m_pCache(NULL)
		{
			unsigned index;
			D3D10_EFFECT_VARIABLE_DESC varDesc;
			D3D10_EFFECT_TYPE_DESC effectTypeDesc;
			ID3D10EffectVariable* effectVar;

			if(!this->m_pEffect)
				throw SingularityException("\"effect\" cannot be null or empty");

			if(FAILED(this->m_pEffect->GetDesc(&this->m_sEffectDesc)))
				throw SingularityException("Unable to get the effect description.");

			this->m_pTechnique = this->m_pEffect->GetTechniqueByIndex(0);
			if(FAILED(this->m_pTechnique->GetDesc(&this->m_sTechniqueDesc)))
				throw SingularityException("Unable to get the effect description.");

			this->m_iVariableCount = this->m_sEffectDesc.GlobalVariables + this->m_sEffectDesc.SharedGlobalVariables;
			this->m_pCache = new ParameterCache[this->m_iVariableCount];

			for(index = 0; index < this->m_iVariableCount; ++index)
			{
				effectVar = this->m_pEffect->GetVariableByIndex(index);
				effectVar->GetDesc(&varDesc);
				effectVar->GetType()->GetDesc(&effectTypeDesc);

				this->m_pCache[index].name = String(varDesc.Name);
				this->m_pCache[index].variable = effectVar;
				this->m_pCache[index].start = this->m_iCacheSize;
				this->m_pCache[index].size = (effectTypeDesc.UnpackedSize == 0 ? sizeof(void*) : effectTypeDesc.UnpackedSize);
				this->m_pCache[index].IsResource = effectTypeDesc.Type == D3D10_SHADER_VARIABLE_TYPE::D3D10_SVT_TEXTURE2D;
				this->m_iCacheSize += this->m_pCache[index].size;
			}
		}

		InternalMaterial::~InternalMaterial()
		{
			if(this->m_pEffect)
			{
				this->m_pEffect->Release();
				this->m_pEffect = NULL;
			}

			if(this->m_pCache)
			{
				delete [] this->m_pCache;
				this->m_pCache = NULL;
			}
		}
		#pragma endregion
		
		#pragma region Methods
		ID3D10InputLayout* InternalMaterial::GetInputLayout(ID3D10Device* device, VertexDeclaration* declaration, const unsigned pass)
		{
			HRESULT hr;
			D3D10_PASS_DESC passDesc;
			ID3D10InputLayout* inputlayout;
			DynamicMap<D3D10_PASS_DESC, ID3D10InputLayout*, D3D10_PASS_DESC_COMP>::iterator it;

			if(FAILED(hr = this->m_pTechnique->GetPassByIndex(pass)->GetDesc(&passDesc)))
				throw SingularityException("Unable to get effect pass description.", hr);

			it = this->m_pLayouts.find(passDesc);
			if(it != this->m_pLayouts.end())
				return it->second;

			hr = device->CreateInputLayout(declaration->Get_Elements(), declaration->Get_ElementCount(), passDesc.pIAInputSignature, passDesc.IAInputSignatureSize, &inputlayout);
			if(FAILED(hr))
				throw SingularityException("Unable to create material input layout.", hr);

			this->m_pLayouts.insert(std::pair<D3D10_PASS_DESC, ID3D10InputLayout*>(passDesc, inputlayout));
			return inputlayout;
		}
		#pragma endregion

		#pragma region Static Methods
		InternalMaterial* InternalMaterial::LoadMaterialFromMemory(String name, String data, bool compile)
		{
			HRESULT hr;
			unsigned index, size;
			ID3D10Blob* compiledEffect, *errors;
			ID3D10Effect* effect;
			InternalMaterial* material;
			void* buffer;
			
			name = String("memory/") + name;
			size = InternalMaterial::g_pBuffers.size();
			for(index = 0; index < size; index++)
			{
				if(InternalMaterial::g_pBuffers[index]->m_pPath.compare(name) == 0)
					return InternalMaterial::g_pBuffers[index];
			}

			if(compile)
			{
				hr = D3D10CompileEffectFromMemory((void*)data.c_str(), data.size(), name.c_str(),
					NULL, NULL, D3D10_SHADER_ENABLE_STRICTNESS, NULL, &compiledEffect, &errors);
				if(FAILED(hr))
					throw SingularityException(String((char*)errors[0].GetBufferPointer()).c_str(), hr);
				buffer = compiledEffect[0].GetBufferPointer();
				size = compiledEffect[0].GetBufferSize();
			}
			else
			{
				buffer = (void*)data.c_str();
				size = data.size();
			}

			hr = D3D10CreateEffectFromMemory(buffer, size , 0, Singularity::Graphics::Devices::HardwareDevice::Instance->m_pDevice, NULL, &effect);
			if(FAILED(hr))
				throw SingularityException("Unable to load material from memory.", hr);
				
			material = new InternalMaterial(effect);
			material->m_pPath = name;
			InternalMaterial::g_pBuffers.push_back(material);
			return material;
		}

		InternalMaterial* InternalMaterial::LoadMaterialFromFile(String path)
		{
			unsigned index, size;
			ID3D10Effect* effect;
			InternalMaterial* material;
			HRESULT hr;

			size = InternalMaterial::g_pBuffers.size();
			for(index = 0; index < size; index++)
			{
				if(InternalMaterial::g_pBuffers[index]->m_pPath.compare(path) == 0)
					return InternalMaterial::g_pBuffers[index];
			}

			hr = D3DX10CreateEffectFromFile(path.c_str(), NULL, NULL, "fx_4_0", D3D10_SHADER_ENABLE_STRICTNESS, 0, Singularity::Graphics::Devices::HardwareDevice::Instance->m_pDevice, NULL, NULL, &effect, NULL, NULL);
			if(FAILED(hr))
				throw SingularityException("Unable to load material from file.", hr) << filepath_info(path);

			material = new InternalMaterial(effect);
			material->m_pPath = path;
			InternalMaterial::g_pBuffers.push_back(material);
			return material;
		}
		#pragma endregion
	}
}