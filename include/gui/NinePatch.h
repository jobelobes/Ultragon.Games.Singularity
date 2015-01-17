// 3/21
// NinePatch.h
// An image split into nine pieces so it can be resized at will.
// Corners: do not scale
// Edges: scale in one direction
// Center: scales in both directions

#include "gui\Singularity.Gui.h"

namespace Singularity
{
	namespace Gui
	{
		class NinePatch
		{

			// o-o-------o-o
			// | |       | |
			// o-o-------o-o
			// | |       | |
			// | |       | |    if we know the inner four points, we're good to go
			// | |       | |    we can calculate the others from there
			// o-o-------o-o
			// | |       | |
			// o-o-------o-o

		private:
			#pragma region Variables
			Singularity::Graphics::Texture2D*	m_pTexture;
			Vector4								m_kPadding;
			Vector2								m_kSize;
			#pragma endregion

		public:
			#pragma region Constructors and Finalizers
			NinePatch(Singularity::Graphics::Texture2D* image, Vector4 padding);
			NinePatch(Singularity::Graphics::Texture2D* image, Vector2 size, Vector4 padding);
			~NinePatch();
			#pragma endregion

			#pragma region Properties
			//IMPLEMENT_CAST_PROPERTY(const int, Height, float, this->m_kSize.y);

			//IMPLEMENT_CAST_PROPERTY(const int, Width, float, this->m_kSize.x);

			//IMPLEMENT_PROPERTY(const Vector4, Padding, this->m_kPadding);

			int Get_Height() const;
			void Set_Height(int value);

			int Get_Width() const;
			void Set_Width(int value);


			Vector4 Get_Padding() const;
			void Set_Padding(Vector4 value);

			#pragma endregion

			#pragma region Methods
			Texture2D* GetTexture();
			#pragma region Methods
		};

		#include "gui\NinePatch.inc"
	}
}