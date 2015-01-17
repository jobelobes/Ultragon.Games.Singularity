// 3/21
// Font.h
// Wrapper for a DX10 font.

#include "gui\Singularity.Gui.h"
//#include "graphics/Texture2D.h"


namespace Singularity
{
	namespace Gui
	{
		class Font
		{
			//sheet creator tool uses the following order:
			//0x20 - 0x7f by default  (32-127)
			//
			// !"#$%&'()*+,-./		//begins with a space
			//0123456789:;<=>?
			//@ABCEDFGHIJKLMNO
			//PQRSTUVWXYZ[\]^_
			//`abcdefghijklmno
			//pqrstuvwxyz{|}~		//yes, this is one short.

			private:
				#pragma region Static Variables
				static DynamicList<Font*>			g_pFontPool;
				#pragma endregion

				#pragma region Variables
				Singularity::Graphics::Texture2D*	m_pSprite;
				RECT*								m_positions;
				int									m_verticalPadding;			//creation tool defaults to 8
				int									m_horizontalPadding;		//creation tool defaults to 8
				int									m_iKerning;
				int									m_iMinChar;
				int									m_iMaxChar;
				String								m_cName;
				#pragma endregion

				#pragma region Properties
				Texture2D* Get_FontSpriteSheet();
				#pragma endregion

				#pragma region Constructors and Deconstructors
				Font(String name, String path); // recommended names: "Arial12", "Bauhaus24", etc.
				#pragma endregion

				#pragma region Methods
				void CalculateRegions();

				//RECT GetCharacterSize(char character);
				int GetCharacterHeight(char character);
				int GetCharacterWidth(char character);
				Vector2 GetCharacterPosition(char character);
				#pragma endregion

			public:
				#pragma region Constructors and Deconstructors
				~Font() { };
				#pragma endregion

				#pragma region Properties
				String Get_FontName();

				int Get_Kerning() const;
				void Set_Kerning(int value);
				#pragma endregion

				#pragma region Static Methods
				static Font* Create(String name, String path);
				static Font* Get_Font(String name);
				static int GetStringWidth(Font* font, String value);
				#pragma endregion

				friend class TextControl;
		};
		
		#include "gui\Font.inc"
	}
}