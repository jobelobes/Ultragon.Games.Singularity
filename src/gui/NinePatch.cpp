#include "gui\Singularity.Gui.h"

namespace Singularity
{
	namespace Gui
	{
		#pragma region Constructors and Finalizers
		NinePatch::NinePatch(Singularity::Graphics::Texture2D* image, Vector4 padding)
			: m_pTexture(image), m_kSize((float)image->Get_Width(), (float)image->Get_Height()), m_kPadding(padding) { }

		NinePatch::NinePatch(Singularity::Graphics::Texture2D* image, Vector2 size, Vector4 padding)
			: m_pTexture(image), m_kSize(size), m_kPadding(padding) { }

		NinePatch::~NinePatch() { }
		#pragma endregion

		#pragma region Methods
		Singularity::Graphics::Texture2D* NinePatch::GetTexture()
		{
			return m_pTexture;
		}
		#pragma endregion
	}
}
