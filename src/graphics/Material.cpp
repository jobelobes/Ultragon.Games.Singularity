#include "graphics\Singularity.Graphics.h"

namespace Singularity
{
	namespace Graphics
	{		
		#pragma region Static Variables
		Material* Material::g_pBasicMaterial = NULL;
		#pragma endregion

		#pragma region Constructors and Finalizers
		Material::Material(InternalMaterial* material)
			: m_pShader(material), m_pBuffer(NULL), m_iPass(0), m_pTexture(NULL)
		{
			this->m_kDescription.Color = Color(1,1,1,1);
			this->m_kDescription.Ambient = 0.2f;
			this->m_kDescription.Diffuse = 0.8f;
			this->m_kDescription.Specular = 1.0f;
			this->m_kDescription.Shininess = 200.0f;
			this->m_kDescription.IlluminationType = 1;
			
			this->m_pBuffer = (char*)malloc(this->m_pShader->m_iCacheSize);
			memset(this->m_pBuffer, 0, this->m_pShader->m_iCacheSize);
		}

		Material::~Material()
		{
			if(this->m_pBuffer)
			{
				delete [] this->m_pBuffer;
				this->m_pBuffer = NULL;
			}
		}
		#pragma endregion

		#pragma region Methods
		void Material::Apply()
		{
			unsigned* ptr;
			InternalMaterial::ParameterCache *index, *end;
			end = &this->m_pShader->m_pCache[this->m_pShader->m_iVariableCount];

			this->SetVariable("_Material", &this->m_kDescription, sizeof(MATERIAL_DESC));
			if(this->m_pTexture)
				this->SetVariable("_MainTex", this->m_pTexture);
			for(index = &this->m_pShader->m_pCache[0]; index < end; index++)
			{
				if(index->IsResource)
				{
					ptr = (unsigned*)&this->m_pBuffer[index->start];
					index->variable->AsShaderResource()->SetResource((ID3D10ShaderResourceView*)*ptr);
				}
				else
					index->variable->SetRawValue(&this->m_pBuffer[index->start], 0, index->size);
			}
		}

		ID3D10EffectPass* Material::GetPassByIndex(unsigned index)
		{
			return this->m_pShader->m_pTechnique->GetPassByIndex(index);
		}

		void Material::SetVariable(String key, Texture2D* value)
		{
			unsigned ptr;
			ID3D10EffectVariable* variable;
			InternalMaterial::ParameterCache *index, *end;

			if(key.size() == 0)
				return;

			variable = this->m_pShader->m_pEffect->GetVariableByName(key.c_str());
			end = &this->m_pShader->m_pCache[this->m_pShader->m_iVariableCount];

			for(index = &this->m_pShader->m_pCache[0]; index < end; index++)
			{
				if(variable == index->variable)
				{
					ptr = (unsigned)value->m_pShaderResView;
					memcpy(&this->m_pBuffer[index->start], &ptr , sizeof(ID3D10ShaderResourceView*));
					return;
				}
			}
		}

		void Material::SetVariable(String key, Color value)
		{
			ID3D10EffectVariable* variable;
			InternalMaterial::ParameterCache *index, *end;

			if(key.size() == 0)
				return;

			variable = this->m_pShader->m_pEffect->GetVariableByName(key.c_str());
			end = &this->m_pShader->m_pCache[this->m_pShader->m_iVariableCount];

			for(index = &this->m_pShader->m_pCache[0]; index < end; index++)
			{
				if(variable == index->variable)
				{
					memcpy(&this->m_pBuffer[index->start], (float*)value, sizeof(Color));
					return;
				}
			}
		}

		void Material::SetVariable(String key, float value)
		{
			ID3D10EffectVariable* variable;
			InternalMaterial::ParameterCache *index, *end;

			if(key.size() == 0)
				return;

			variable = this->m_pShader->m_pEffect->GetVariableByName(key.c_str());
			end = &this->m_pShader->m_pCache[this->m_pShader->m_iVariableCount];

			for(index = &this->m_pShader->m_pCache[0]; index < end; index++)
			{
				if(variable == index->variable)
				{
					memcpy(&this->m_pBuffer[index->start], &value, sizeof(float));
					return;
				}
			}
		}

		void Material::SetVariable(String key, int value)
		{
			ID3D10EffectVariable* variable;
			InternalMaterial::ParameterCache *index, *end;

			if(key.size() == 0)
				return;

			variable = this->m_pShader->m_pEffect->GetVariableByName(key.c_str());
			end = &this->m_pShader->m_pCache[this->m_pShader->m_iVariableCount];

			for(index = &this->m_pShader->m_pCache[0]; index < end; index++)
			{
				if(variable == index->variable)
				{
					memcpy(&this->m_pBuffer[index->start], &value, sizeof(int));
					return;
				}
			}
		}

		void Material::SetVariable(String key, Vector2 value)
		{
			ID3D10EffectVariable* variable;
			InternalMaterial::ParameterCache *index, *end;

			if(key.size() == 0)
				return;

			variable = this->m_pShader->m_pEffect->GetVariableByName(key.c_str());
			end = &this->m_pShader->m_pCache[this->m_pShader->m_iVariableCount];

			for(index = &this->m_pShader->m_pCache[0]; index < end; index++)
			{
				if(variable == index->variable)
				{
					memcpy(&this->m_pBuffer[index->start], (float*)value, sizeof(Vector2));
					return;
				}
			}
		}

		void Material::SetVariable(String key, Vector3 value)
		{
			ID3D10EffectVariable* variable;
			InternalMaterial::ParameterCache *index, *end;

			if(key.size() == 0)
				return;

			variable = this->m_pShader->m_pEffect->GetVariableByName(key.c_str());
			end = &this->m_pShader->m_pCache[this->m_pShader->m_iVariableCount];

			for(index = &this->m_pShader->m_pCache[0]; index < end; index++)
			{
				if(variable == index->variable)
				{
					memcpy(&this->m_pBuffer[index->start], (float*)value, sizeof(Vector3));
					return;
				}
			}
		}

		void Material::SetVariable(String key, Vector4 value)
		{
			ID3D10EffectVariable* variable;
			InternalMaterial::ParameterCache *index, *end;

			if(key.size() == 0)
				return;

			variable = this->m_pShader->m_pEffect->GetVariableByName(key.c_str());
			end = &this->m_pShader->m_pCache[this->m_pShader->m_iVariableCount];

			for(index = &this->m_pShader->m_pCache[0]; index < end; index++)
			{
				if(variable == index->variable)
				{
					memcpy(&this->m_pBuffer[index->start], (float*)value, sizeof(Vector4));
					return;
				}
			}
		}

		void Material::SetVariable(String key, Quaternion value)
		{
			ID3D10EffectVariable* variable;
			InternalMaterial::ParameterCache *index, *end;

			if(key.size() == 0)
				return;

			Vector4 vec = Vector4(value.x, value.y, value.z, value.w);
			variable = this->m_pShader->m_pEffect->GetVariableByName(key.c_str());
			end = &this->m_pShader->m_pCache[this->m_pShader->m_iVariableCount];

			for(index = &this->m_pShader->m_pCache[0]; index < end; index++)
			{
				if(variable == index->variable)
				{
					memcpy(&this->m_pBuffer[index->start], (float*)value, sizeof(Vector4));
					return;
				}
			}
			
		}

		void Material::SetVariable(String key, Matrix value)
		{
			ID3D10EffectVariable* variable;
			InternalMaterial::ParameterCache *index, *end;

			if(key.size() == 0)
				return;

			variable = this->m_pShader->m_pEffect->GetVariableByName(key.c_str());
			end = &this->m_pShader->m_pCache[this->m_pShader->m_iVariableCount];

			for(index = &this->m_pShader->m_pCache[0]; index < end; index++)
			{
				if(variable == index->variable)
				{
					memcpy(&this->m_pBuffer[index->start], (float*)value.transpose().m, sizeof(Matrix));
					return;
				}
			}
		}

		void Material::SetVariable(String key, void* data, unsigned count)
		{
			ID3D10EffectVariable* variable;
			InternalMaterial::ParameterCache *index, *end;

			if(key.size() == 0)
				return;

			variable = this->m_pShader->m_pEffect->GetVariableByName(key.c_str());
			end = &this->m_pShader->m_pCache[this->m_pShader->m_iVariableCount];

			for(index = &this->m_pShader->m_pCache[0]; index < end; index++)
			{
				if(variable == index->variable)
				{
					memcpy(&this->m_pBuffer[index->start], data, count);
					return;
				}
			}
		}

		Material* Material::Clone()
		{
			Material* material = new Material(this->m_pShader);
			memcpy(material->m_pBuffer, this->m_pBuffer, this->m_pShader->m_iCacheSize);
			material->m_iPass = this->m_iPass;
			material->m_kDescription = this->m_kDescription;
			material->m_pTexture = this->m_pTexture;
			return material;
		}

		void Material::Destroy()
		{
			
		}
		#pragma endregion

		#pragma region Static Methods
		Material* Material::CreateBasicMaterial()
		{
			HRSRC src;
			HANDLE bytes;
			String basicmaterial;
			char id[5];

			if(Material::g_pBasicMaterial == NULL)
			{
				id[0] = '#';
				_itoa_s(IDR_BINARY11, &id[1], 4, 10);
				src = ::FindResource(NULL, id, "BINARY");
				bytes = ::LoadResource(NULL, src);
				basicmaterial = String((char*)::LockResource(bytes), ::SizeofResource(NULL, src));
				Material::g_pBasicMaterial = Material::LoadMaterialFromMemory(String("BasicMaterial"),  basicmaterial);
				::FreeResource(bytes);
				return Material::g_pBasicMaterial;
			}

			return Material::g_pBasicMaterial->Clone();
		}

		Material* Material::LoadMaterialFromMemory(String name, String data, bool compile)
		{
			return new Material(InternalMaterial::LoadMaterialFromMemory(name, data, compile));
		}

		Material* Material::LoadMaterialFromFile(String path)
		{
			return new Material(InternalMaterial::LoadMaterialFromFile(path));
		}
		#pragma endregion
	}
}