#include "graphics\Singularity.Graphics.h"

namespace Singularity
{
	namespace Graphics
	{
		class Material
		{
			private:
				#pragma region Nested Classes
				struct MATERIAL_DESC
				{
					Color		Color;
					float		Ambient;
					float		Diffuse;
					float		Specular;
					float		Shininess;
					int			IlluminationType;
				};
				#pragma endregion

				#pragma region Static Variables
				static Material* g_pBasicMaterial;
				#pragma endregion

				#pragma region Variables
				InternalMaterial*			m_pShader;
				MATERIAL_DESC				m_kDescription;
				Texture2D*					m_pTexture;
				unsigned					m_iPass;
				char*						m_pBuffer;
				#pragma endregion

				#pragma region Constructors and Finalizers
				Material(InternalMaterial* material);
				#pragma endregion

				#pragma region Methods
				ID3D10EffectPass* GetPassByIndex(unsigned index);
				#pragma endregion

			public:
				#pragma region Properties
				const unsigned Get_PassCount() const;

				void Set_Pass(const unsigned value);

				const Color Get_Color() const;
				void Set_Color(const Color value);

				const Texture2D* Get_MainTexture() const;
				void Set_MainTexture(Texture2D* value);
				#pragma endregion

				#pragma region Constructors and Finalizers
				~Material();
				#pragma endregion

				#pragma region Methods
				void SetVariable(String key, Texture2D* value);
				void SetVariable(String key, Color value);
				void SetVariable(String key, float value);
				void SetVariable(String key, int value);
				void SetVariable(String key, Vector2 value);
				void SetVariable(String key, Vector3 value);
				void SetVariable(String key, Vector4 value);
				void SetVariable(String key, Quaternion value);
				void SetVariable(String key, Matrix value);
				void SetVariable(String key, void* data, unsigned count);

				Material* Clone();
				void Destroy();

				void Apply();
				#pragma endregion

				#pragma region Static Methods
				static Material* CreateBasicMaterial();
				static Material* LoadMaterialFromMemory(String name, String data, bool compile = false);
				static Material* LoadMaterialFromFile(String path);
				#pragma endregion

				friend class Singularity::Graphics::Devices::DrawingContext;
				friend class Singularity::Graphics::Devices::DeferredDrawingContext;
		};

		#include "graphics\Material.inc"
	}
}