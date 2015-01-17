#include "gui\Singularity.Gui.h"

namespace Singularity
{
	namespace Gui
	{

		#pragma	region Static Methods

		void FontManager::Load_Font(String path, String name)
		{
			//Font* font = new Font(path, name, weight, false, false);
			Font* font = new Font(path, name);
			FontManager::Instantiate()->m_pFontPool.push_back(font);
		}

		void FontManager::Add_Font(Font* font)
		{
			
		}


		#pragma endregion
	}
}