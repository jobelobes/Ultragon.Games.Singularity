// 3/21
// FontManager.h
// Manages and returns Fonts (aka fonts)

#include "gui\Singularity.Gui.h"

namespace Singularity
{
	namespace Gui
	{
		class FontManager
		{
			private:
				#pragma region Static Variables
				static FontManager*						g_pInstance;
				#pragma endregion

				#pragma region Variables
				int										m_iMaxFontNum;
				
				DynamicList<Font*>				m_pFontPool;
				#pragma endregion

				

			public:
				#pragma region Constructors and Deconstructors
				FontManager();
				~FontManager();
				#pragma endregion

				#pragma region Methods
				inline DynamicList<Font*> Get_FontPool() const { return this->m_pFontPool; }
				inline int Get_MaxFontNum() const { return this->m_iMaxFontNum; }
				#pragma endregion

				#pragma region Static Methods
				static void Add_Font(Font* font);
				static void Load_Font(String path, String name);
				static Font* Get_Font(String name);

				static FontManager* Instantiate();
				#pragma endregion
		};
	}
}