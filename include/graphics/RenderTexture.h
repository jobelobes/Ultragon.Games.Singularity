#include "graphics\Singularity.Graphics.h"

namespace Singularity
{
	namespace Graphics
	{
		class RenderTexture : public Singularity::Graphics::Texture2D
		{
			private:
				#pragma region Variables
				ID3D10RenderTargetView*		m_pRenderTarget;
				#pragma endregion

				#pragma region Methods
				void CreateResource(unsigned width, unsigned height, DXGI_FORMAT format);
				#pragma endregion
			public:
				#pragma region Constructors and Deconstructors
				RenderTexture(unsigned width, unsigned height, DXGI_FORMAT format);
				~RenderTexture();
				#pragma endregion

				#pragma region Methods
				inline ID3D10RenderTargetView* Get_RenderTargetView() const { return this->m_pRenderTarget; }
				#pragma endregion
		};
	}
}