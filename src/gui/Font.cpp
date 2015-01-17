#include "gui\Singularity.Gui.h"

namespace Singularity
{
	namespace Gui
	{
		#pragma region Static Variables
		DynamicList<Font*> Font::g_pFontPool;
		#pragma endregion

		#pragma region Constructors and Deconstructors
		Font::Font(String name, String path) 
			: m_cName(name), m_iKerning(SINGULARITY_GUI_DEFAULT_KERNING), m_iMinChar(0x20), m_iMaxChar(0x7f)
		{
			this->m_pSprite = Singularity::Graphics::Texture2D::LoadTextureFromFile(path);
			this->m_positions = new RECT[m_iMaxChar - m_iMinChar]; // same.
			this->CalculateRegions(); // There's probably a better way to do this, but it works.
		}
		#pragma endregion

		#pragma	region Methods
		//RECT Font::GetCharacterSize(char character)
		//{
		//	if (character > this->m_iMaxChar)
		//		return RECT();
		//	return this->m_positions[character - this->m_iMinChar];
		//}

		int Font::GetCharacterWidth(char character)
		{
			if (character > this->m_iMaxChar)
				return -1; // FAILURE, throw an exception
			return this->m_positions[character - this->m_iMinChar].right - this->m_positions[character - this->m_iMinChar].left;
		}

		int Font::GetCharacterHeight(char character)
		{
			if (character > this->m_iMaxChar)
				return -1; // FAILURE, throw an exception
			return this->m_positions[character - this->m_iMinChar].bottom - this->m_positions[character - this->m_iMinChar].top;
		}

		Vector2 Font::GetCharacterPosition(char character) //x,y
		{
			if (character > this->m_iMaxChar)
				return Vector2(-1, -1); // FAILURE, throw an exception
			return Vector2((float)this->m_positions[character - this->m_iMinChar].left, (float)this->m_positions[character - this->m_iMinChar].top);
		}
		
		void Font::CalculateRegions()
		{
			// figure out the offsets for each. Stored as a RECT.
			if (!m_pSprite)
			{
				throw SingularityException("Unable to find font texture file.");
			}

			if (m_pSprite != NULL)
			{
				// CURRENT ASSUMPTIONS THAT SHOULD BE HANDLED SOMEWHERE ELSE:
				// CONSTANT PADDING
				// PADDING BEFORE FIRST CHAR
				// HEIGHTS ARE CONSTANT

				Color color = m_pSprite->GetPixel(0,0); // start from the beginning
				unsigned x = 0;
				unsigned y = 0;
				while ( color == Color(1, 0, 1, 1)) // our nasty-ass background color
				{

					x++;
					if (x >= m_pSprite->Get_Width())
					{
						x = 0;
						y++;
						if (y >= m_pSprite->Get_Height())
						{
							throw SingularityException("Failed to load in font properly. Is it in the correct format?");
						}
					}
					color = m_pSprite->GetPixel(x,y);
				}
				// we've found out first pixel
				m_verticalPadding = y;
				m_horizontalPadding = x;

				// now let's find the height of a character

				int charHeight = 0;

				while (color != Color(1, 0, 1, 1))
				{
					charHeight++;
					y++;
					color = m_pSprite->GetPixel(x,y);
				}

				y -= charHeight; // reset back to the upper-left char

				for (int i = 0; i < this->m_iMaxChar - m_iMinChar; i++) // everything is offset by m_iMinChar
				{
					m_positions[i].left = x;
					m_positions[i].top = y;
					m_positions[i].bottom = y+charHeight;
					x++;
					color = m_pSprite->GetPixel(x,y);
					while (color != Color(1, 0, 1, 1))
					{

						x++;
						color = m_pSprite->GetPixel(x,y);
					}
					m_positions[i].right = x;
					x += m_horizontalPadding; // we're at the first non-letter spot, so increment to the next letter spot
					color = m_pSprite->GetPixel(x,y);
					if (x >= m_pSprite->Get_Width() || color == Color(1, 0, 1, 1))
					{
						int i = m_pSprite->Get_Width();
						x = m_horizontalPadding + 1;
						y += (m_verticalPadding + charHeight);
						if (y >= m_pSprite->Get_Height())
						{
							//throw SingularityException("Failed to load in font properly. Is it in the correct format?");
							return;
						}
					}

				}
				
			}
		}

		#pragma endregion

		#pragma region Static Methods
		Font* Font::Create(String name, String path)
		{
			unsigned index, count;
			Font* font;

			count = Font::g_pFontPool.size();
			for(index = 0; index < count; ++index)
			{
				if(Font::g_pFontPool[index]->Get_FontName() == name)
					return Font::g_pFontPool[index];
			}
	
			font = new Font(name, path);
			Font::g_pFontPool.push_back(font);
			return font;
		}

		int Font::GetStringWidth(Font* font, String value)
		{
			int dx = 0;
			for (unsigned i = 0; i < value.length(); i++)
				dx += font->GetCharacterWidth(value[i]) + font->m_iKerning;
			return dx;
		}

		Font* Font::Get_Font(String name)
		{
			unsigned i, count;

			count = Font::g_pFontPool.size();
			for(i = 0; i < count; i++)
				if(Font::g_pFontPool[i]->Get_FontName() == name)
					return Font::g_pFontPool[i];
			
			throw SingularityException("Cannot load file. Was the font loaded into the system prior to making this call?");
		}
		#pragma endregion
	}
}