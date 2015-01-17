#include "graphics\Singularity.Graphics.h"

namespace Singularity
{
	namespace Graphics
	{
		class Texture2D
		{
			protected:
				#pragma region Variables
				ID3D10Device*				m_pDevice;
				ID3D10Texture2D*			m_pTexture;
				ID3D10ShaderResourceView*	m_pShaderResView;
				D3D10_TEXTURE2D_DESC		m_kDescription;

				bool						m_bDirty;
				unsigned					m_iRowSpan;
				unsigned char*				m_pTextureBuffer;
				#pragma endregion
				
			public:
				#pragma region Properties
				const unsigned Get_Width() const;
				const unsigned Get_Height() const;
				const unsigned Get_MipLevels() const;

				#pragma endregion
 
				#pragma region Constructors and Finalizers
				Texture2D(unsigned width, unsigned height, bool mipmap = true);
				~Texture2D();
				#pragma endregion
				
				#pragma region Methods
				void SetPixel(unsigned x, unsigned y, Color color);
				void SetPixels(void* buffer, int size, int level = 1);
				Color GetPixel(unsigned x, unsigned y, bool force = false);
				void Apply();
				#pragma endregion
 
				#pragma region Static Methods
				static Texture2D* LoadTextureFromFile(String path);
				#pragma endregion

				friend class Material;
				friend class Singularity::Graphics::Devices::DrawingContext;
				friend class Singularity::Graphics::Devices::DeferredDrawingContext;

			protected:
				#pragma region Constructors and Finalizers
				Texture2D(ID3D10Device* device, ID3D10Texture2D* texture);
				#pragma endregion
		};

		#include "graphics\Texture2d.inc"
	}
}