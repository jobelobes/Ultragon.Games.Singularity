#include "graphics\Singularity.Graphics.h"

namespace Singularity
{
	namespace Graphics
	{
		#pragma region Constructors and Finalizers
		MaterialParameterSet::MaterialParameterSet(InternalMaterial* material)
			: m_pInternal(material), m_pBuffer(NULL)
		{
			this->m_pBuffer = (char*)malloc(this->m_pInternal->m_iCacheSize);
		}


		MaterialParameterSet::~MaterialParameterSet()
		{

		}
		#pragma endregion

		#pragma region Methods
		void MaterialParameterSet::Apply();
		#pragma endregion

			public:
				#pragma region Methods
				void MaterialParameterSet::SetVariable(String key, Texture2D* value);
				void MaterialParameterSet::SetVariable(String key, Color value);
				void MaterialParameterSet::SetVariable(String key, float value);
				void MaterialParameterSet::SetVariable(String key, int value);
				void MaterialParameterSet::SetVariable(String key, Vector2 value);
				void MaterialParameterSet::SetVariable(String key, Vector3 value);
				void MaterialParameterSet::SetVariable(String key, Vector4 value);
				void MaterialParameterSet::SetVariable(String key, Matrix value);
				#pragma endregion

	}
}