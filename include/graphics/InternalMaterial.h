#include "graphics\Singularity.Graphics.h"

namespace Singularity
{
	namespace Graphics
	{
		class InternalMaterial
		{
			private:
				#pragma region Nested Classes
				struct ParameterCache
				{
					String name;
					ID3D10EffectVariable* variable;
					unsigned start;
					unsigned size;
					bool IsResource;
				};

				struct D3D10_PASS_DESC_COMP {
				  bool operator() (const D3D10_PASS_DESC& lhs, const D3D10_PASS_DESC& rhs) const 
				  { return memcmp(&lhs, &rhs, sizeof(D3D10_PASS_DESC)) < 0; };
				};
				#pragma endregion

				#pragma region Static Variables
				static DynamicList<InternalMaterial*> g_pBuffers;
				#pragma endregion

				#pragma region Variables
				String						m_pPath;
				ID3D10Effect*				m_pEffect;
				ID3D10EffectTechnique*		m_pTechnique;
				D3D10_EFFECT_DESC			m_sEffectDesc;
				D3D10_TECHNIQUE_DESC		m_sTechniqueDesc;

				unsigned					m_iVariableCount;
				unsigned					m_iCacheSize;
				ParameterCache*				m_pCache;

				DynamicMap<D3D10_PASS_DESC, ID3D10InputLayout*, D3D10_PASS_DESC_COMP> m_pLayouts;
				#pragma endregion

				#pragma region Constructors and Finalizers
				InternalMaterial(ID3D10Effect* effect);
				~InternalMaterial();
				#pragma endregion

				#pragma region Methods
				ID3D10InputLayout* GetInputLayout(ID3D10Device* device, VertexDeclaration* declaration, const unsigned pass = 0);
				#pragma endregion

				#pragma region Static Methods
				static InternalMaterial* LoadMaterialFromMemory(String name, String data, bool compile = false);
				static InternalMaterial* LoadMaterialFromFile(String path);
				#pragma endregion

				friend class Material;
				friend class Singularity::Graphics::Devices::DrawingContext;
				friend class Singularity::Graphics::Devices::DeferredDrawingContext;
		};
	}
}