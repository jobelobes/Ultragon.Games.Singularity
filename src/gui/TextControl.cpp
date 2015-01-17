#include "gui\Singularity.Gui.h"

namespace Singularity
{
	namespace Gui
	{							
		IMPLEMENT_OBJECT_TYPE(Singularity.Gui, TextControl, Singularity::Gui::Control);

		#pragma region Static Variables
		Material* TextControl::g_pMaterial = NULL;
		#pragma endregion

		#pragma region Properties
		int TextControl::Get_TextCenter()
		{
			return (Font::GetStringWidth(this->m_pFont, this->m_pText) / 2);
		}

		void TextControl::Set_Font(Font* font)
		{
			this->m_pFont = font;
			this->m_pFontMaterial->Set_MainTexture(this->m_pFont->Get_FontSpriteSheet());
			this->m_bNeedToRecalc = true;
		}

		void TextControl::Set_Texture(NinePatch* value)
		{ 
			Control::Set_Texture(value);
			if (this->m_sPadding.x <= value->Get_Padding().x)
				m_sPadding.x = value->Get_Padding().x + 1; // move it one over

			if (this->m_sPadding.y <= value->Get_Padding().y)
				m_sPadding.y = value->Get_Padding().y + 1;

			this->RebuildControl();
		}
		#pragma endregion

		#pragma region Constructors and Deconstructors
		TextControl::TextControl(String name, String text) 
			: Control(name), m_pFont(NULL), m_pText(text), m_pFontMaterial(TextControl::CreateFontMaterial()), m_sPadding(Vector2(0,0)), m_iPreviousLength(0)
		{
			this->m_pFontVertices = new VertexBuffer(GuiFontVertexDeclaration::Declaration, SINGULARITY_GUI_TEXT_CHAR_LIMIT);
			this->m_bNeedToRecalc = true;
			this->Set_Font(Font::Create(SINGULARITY_GUI_DEFAULT_FONT_NAME, SINGULARITY_GUI_DEFAULT_FONT_FILEPATH));
		}
		
		TextControl::TextControl(String name, Material* material, Material* fontMaterial, String text) 
			: Control(name, material), m_pText(text), m_pFont(NULL), m_pFontMaterial(fontMaterial), m_sPadding(Vector2(0,0)), m_iPreviousLength(0)
		{
			this->m_pFontVertices = new VertexBuffer(GuiFontVertexDeclaration::Declaration, SINGULARITY_GUI_TEXT_CHAR_LIMIT);
			this->m_bNeedToRecalc = true;
			this->Set_Font(Font::Create(SINGULARITY_GUI_DEFAULT_FONT_NAME, SINGULARITY_GUI_DEFAULT_FONT_FILEPATH));
		}
		#pragma endregion

		#pragma region Methods
		void TextControl::InternalRebuildFont()
		{
			if (this->m_pFont == NULL)
			{
				throw SingularityException("Font must be defined in order to draw text.");
			}
			Vector2 parentPosition = Vector2(0,0);
			Vector2 position = this->Get_Position();
			Vector2 size = this->Get_Size();
			const char* s = this->m_pText.c_str();
			int offset = (int)this->m_sPadding.x;

			if(this->m_pFont != NULL)
				this->m_sPadding.y = (this->Get_Size().y / 2) - (this->m_pFont->GetCharacterHeight('F') / 2);

			if(this->Get_Parent() != NULL)
				parentPosition = this->Get_Parent()->Get_Position();

			for (unsigned i = 0; i < this->m_pText.length(); i++)
			{
				// there's a few pixels of transparency at the top. this is currently built into our
				// font-builder and should be removed.
				if(offset + this->m_pFont->GetCharacterWidth(s[i]) + m_sPadding.x < size.x) // offset and padding plus the width of the character. if it's too far, don't draw.
				{
					this->m_pFontVertexDeclaration[i].position = Vector3(this->Get_AbsolutePosition().x + offset,  this->Get_AbsolutePosition().y + this->m_sPadding.y, this->Get_Depth() - 0.01f);
					this->m_pFontVertexDeclaration[i].scale = Vector2(1.0f, 1.0f);
					this->m_pFontVertexDeclaration[i].texSize = Vector2((float)this->m_pFont->GetCharacterPosition(s[i]).x+1, (float)this->m_pFont->GetCharacterPosition(s[i]).y+1);
					this->m_pFontVertexDeclaration[i].texOffset = Vector2((float)this->m_pFont->GetCharacterWidth(s[i])-2, (float)this->m_pFont->GetCharacterHeight(s[i])-2);
				}
				
				offset += (this->m_pFont->GetCharacterWidth(s[i]) + this->m_pFont->Get_Kerning());
			}

			this->m_pFontVertices->SetData(&this->m_pFontVertexDeclaration[0]);
			//this->m_bNeedToRecalcFont = false; // done in Control::InternalRebuldFont
		}
		#pragma endregion

		#pragma region Overriden Methods

		void TextControl::OnPaint(DrawingContext* context, Camera* camera)
		{
			if (this->m_bNeedToRecalc)
				this->InternalRebuildFont();

			Matrix world = Matrix::CreateIdentity();
			context->Draw(camera, this->m_pFontMaterial, world, this->m_pFontVertices, 0, this->m_pText.length());			
			Control::OnPaint(context, camera);
		}
		#pragma endregion

		#pragma region Static Methods
		Material* TextControl::CreateFontMaterial()
		{
			HRSRC src;
			HANDLE bytes;
			String material;
			char id[5];

			if(TextControl::g_pMaterial == NULL)
			{
				id[0] = '#';
				_itoa_s(IDR_GUI_BINARY2, &id[1], 4, 10);
				src = ::FindResource(NULL, id, "GUI_BINARY");
				bytes = ::LoadResource(NULL, src);
				material = String((char*)::LockResource(bytes), ::SizeofResource(NULL, src));
				TextControl::g_pMaterial = Material::LoadMaterialFromMemory(String("FontMaterial"),  material);
				::FreeResource(bytes);
				return TextControl::g_pMaterial;
			}
			return TextControl::g_pMaterial->Clone();
		}
		#pragma endregion

	}
}