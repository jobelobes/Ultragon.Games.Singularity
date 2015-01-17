// 4/06
// TextControl.h
// Control with text.

#include "gui\Singularity.Gui.h"

namespace Singularity
{
	namespace Gui
	{
		class TextControl : public Singularity::Gui::Control
		{
			DECLARE_OBJECT_TYPE
			private:
				#pragma region Static Variables
				static Material* g_pMaterial;
				#pragma endregion

				#pragma region Static Methods
				static Material* CreateFontMaterial();
				#pragma endregion

				#pragma region Methods
				void InternalRebuildFont();
				#pragma endregion

			protected:
				#pragma region Variables
				Font*								m_pFont;
				Material*							m_pFontMaterial;
				VertexBuffer*						m_pFontVertices;
				
				Vector2								m_sPadding;
				GuiFontVertexDeclaration			m_pFontVertexDeclaration[SINGULARITY_GUI_TEXT_CHAR_LIMIT];

				String								m_pText;
				int									m_iPreviousLength;	// previous length of the string
				#pragma endregion

				#pragma region Overriden Methods
				virtual void OnPaint(DrawingContext* context, Camera* camera);
				#pragma endregion

			public:

				#pragma region Properties
				inline String Get_Text() const { return this->m_pText; };
				inline void Set_Text(String value) { m_iPreviousLength = m_pText.size(); this->m_pText = value; m_bNeedToRecalc = true;};

				int Get_TextCenter();

				inline Vector2 Get_Padding() const { return this->m_sPadding; };
				inline void Set_Padding(Vector2 value) { this->m_sPadding = value; };

				inline Font* Get_Font() const { return this->m_pFont; };
				void Set_Font(Font* font);

				inline Material* Get_FontMaterial() const { return this->m_pFontMaterial; };
				inline void Set_FontMaterial(Material* value) { this->m_pFontMaterial = value; };

				inline void Set_FontColor(Color color) { this->m_pFontMaterial->Set_Color(color); };

				virtual void Set_Texture(NinePatch* value);
				#pragma region Variables

				#pragma region Constructors and Deconstructors
				TextControl(String name, String text = "");
				//TextControl(String name, NinePatch* texture, Vector2 position, Vector2 size) : Control(name, texture, position, size), m_pClickCallback(NULL), m_pMouseoverCallback(NULL), m_bIsMouseOver(false) {}
				TextControl(String name, Material* material, Material* fontMaterial, String text = "");
				~TextControl() {} ;
				#pragma endregion
		};
	}
}