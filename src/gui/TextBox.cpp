#include "gui\Singularity.Gui.h"

using namespace Singularity::Inputs;

int scan2ascii(DWORD scancode, char& result)
{
	WORD value;
	HKL layout = ::GetKeyboardLayout(0);
	unsigned char state[256];

	if (GetKeyboardState(state) == false)
		return 0;
	UINT vk = MapVirtualKeyEx(scancode, 1, layout);
	bool good = ToAsciiEx(vk, scancode, state, &value, 0, layout);
	result = value;
	return good;
}

namespace Singularity
{
	namespace Gui
	{				
		void TextBox::OnKeyPress(bool shift, bool control, int keyIndex)
		{
			char value;
			bool good = scan2ascii(keyIndex, value);
			if (good && (value >=97 && value <= 122))
			{
				if (shift)
					value -= 32;
					//this->Set_Text(m_pText + (value-32)); // make it upper-case
				this->Set_Text(m_pText + value);
			}
			/*if (keyIndex == DIK_A)
			{
				this->Set_Text(m_pText + (shift ? "A" : "a"));
				return;
			}

			if (keyIndex == DIK_B)
			{
				this->Set_Text(m_pText + (shift ? "B" : "B"));
				return;
			}

			if (keyIndex == DIK_C)
			{
				this->Set_Text(m_pText + (shift ? "C" : "c"));
				return;
			}

			if (keyIndex == DIK_D)
			{
				if (shift)
					this->Set_Text(m_pText + "D");
				else
					this->Set_Text(m_pText + "d");
			}

			if (keyIndex == DIK_E)
			{
				if (shift)
					this->Set_Text(m_pText + "E");
				else
					this->Set_Text(m_pText + "e");
			}

			if (keyIndex == DIK_F)
			{
				if (shift)
					this->Set_Text(m_pText + "F");
				else
					this->Set_Text(m_pText + "f");
			}

			if (keyIndex == DIK_G)
			{
				if (shift)
					this->Set_Text(m_pText + "G");
				else
					this->Set_Text(m_pText + "g");
			}

			if (keyIndex == DIK_H)
			{
				if (shift)
					this->Set_Text(m_pText + "H");
				else
					this->Set_Text(m_pText + "h");
			}
			
			if (keyIndex == DIK_I)
			{
				if (shift)
					this->Set_Text(m_pText + "I");
				else
					this->Set_Text(m_pText + "i");
			}

			if (keyIndex == DIK_J)
			{
				if (shift)
					this->Set_Text(m_pText + "J");
				else
					this->Set_Text(m_pText + "j");
			}

			if (keyIndex == DIK_K)
			{
				if (shift)
					this->Set_Text(m_pText + "K");
				else
					this->Set_Text(m_pText + "k");
			}

			if (keyIndex == DIK_L)
			{
				if (shift)
					this->Set_Text(m_pText + "L");
				else
					this->Set_Text(m_pText + "l");
			}
			
			if (keyIndex == DIK_M)
			{
				if (shift)
					this->Set_Text(m_pText + "M");
				else
					this->Set_Text(m_pText + "m");
			}

			if (keyIndex == DIK_N)
			{					
				if (shift)
					this->Set_Text(m_pText + "N");
				else
					this->Set_Text(m_pText + "n");
			}
			
			if (keyIndex == DIK_O)
			{
				if (shift)
					this->Set_Text(m_pText + "O");
				else
					this->Set_Text(m_pText + "o");
			}

			if (keyIndex == DIK_P)
			{
				if (shift)
					this->Set_Text(m_pText + "P");
				else
					this->Set_Text(m_pText + "p");
			}

			if (keyIndex == DIK_Q)
			{
				if (shift)
					this->Set_Text(m_pText + "Q");
				else
					this->Set_Text(m_pText + "q");
			}

			if (keyIndex == DIK_R)
			{
				if (shift)
					this->Set_Text(m_pText + "R");
				else
					this->Set_Text(m_pText + "r");
			}
			
			if (keyIndex == DIK_S)
			{
				if (shift)
					this->Set_Text(m_pText + "S");
				else
					this->Set_Text(m_pText + "s");
			}

			if (keyIndex == DIK_T)
			{
				if (shift)
					this->Set_Text(m_pText + "T");
				else
					this->Set_Text(m_pText + "t");
			}
			
			if (keyIndex == DIK_U)
			{
				if (shift)
					this->Set_Text(m_pText + "U");
				else
					this->Set_Text(m_pText + "u");
			}

			if (keyIndex == DIK_V)
			{
				if (shift)
					this->Set_Text(m_pText + "V");
				else
					this->Set_Text(m_pText + "v");
			}
			
			if (keyIndex == DIK_W)
			{
				if (shift)
					this->Set_Text(m_pText + "W");
				else
					this->Set_Text(m_pText + "w");
			}

			if (keyIndex == DIK_X)
			{
				if (shift)
					this->Set_Text(m_pText + "X");
				else
					this->Set_Text(m_pText + "x");
			}
			
			if (keyIndex == DIK_Y)
			{
				if (shift)
					this->Set_Text(m_pText + "Y");
				else
					this->Set_Text(m_pText + "y");
			}

			if (keyIndex == DIK_Z)
			{
				if (shift)
					this->Set_Text(m_pText + "Z");
				else
					this->Set_Text(m_pText + "z");
			}*/

			// numbers

			if (keyIndex == DIK_1)
			{
				if (shift)
					this->Set_Text(m_pText + "!");
				else
					this->Set_Text(m_pText + "1");
			}

			if (keyIndex == DIK_2)
			{
				if (shift)
					this->Set_Text(m_pText + "@");
				else
					this->Set_Text(m_pText + "2");
			}

			if (keyIndex == DIK_3)
			{
				if (shift)
					this->Set_Text(m_pText + "#");
				else
					this->Set_Text(m_pText + "3");
			}

			if (keyIndex == DIK_4)
			{
				if (shift)
					this->Set_Text(m_pText + "$");
				else
					this->Set_Text(m_pText + "4");
			}

			if (keyIndex == DIK_5)
			{
				if (shift)
					this->Set_Text(m_pText + "%");
				else
					this->Set_Text(m_pText + "5");
			}

			if (keyIndex == DIK_6)
			{
				if (shift)
					this->Set_Text(m_pText + "^");
				else
					this->Set_Text(m_pText + "6");
			}

			if (keyIndex == DIK_7)
			{
				if (shift)
					this->Set_Text(m_pText + "&");
				else
					this->Set_Text(m_pText + "7");
			}

			if (keyIndex == DIK_8)
			{
				if (shift)
					this->Set_Text(m_pText + "*");
				else
					this->Set_Text(m_pText + "8");
			}

			if (keyIndex == DIK_9)
			{
				if (shift)
					this->Set_Text(m_pText + "(");
				else
					this->Set_Text(m_pText + "9");
			}

			if (keyIndex == DIK_0)
			{
				if (shift)
					this->Set_Text(m_pText + ")");
				else
					this->Set_Text(m_pText + "0");
			}

			/*

			if (keyIndex == DIK_COMMA)
			{
				if (shift)
					this->Set_Text(m_pText + "<");
				else
					this->Set_Text(m_pText + ",");
			}
			
			if (keyIndex == DIK_PERIOD)
			{
				if (shift)
					this->Set_Text(m_pText + ">");
				else
					this->Set_Text(m_pText + ".");
			}
			
			if (keyIndex == DIK_SLASH)
			{
				if (shift)
					this->Set_Text(m_pText + "?");
				else
					this->Set_Text(m_pText + "/");
			}

			if (keyIndex == DIK_SEMICOLON)
			{
				if (shift)
					this->Set_Text(m_pText + ";");
				else
					this->Set_Text(m_pText + ":");
			}

			if (keyIndex == DIK_APOSTROPHE)
			{
				if (shift)
					this->Set_Text(m_pText + "\"");
				else
					this->Set_Text(m_pText + "'");
			}

			if (keyIndex == DIK_LBRACKET)
			{
				if (shift)
					this->Set_Text(m_pText + "{");
				else
					this->Set_Text(m_pText + "[");
			}

			if (keyIndex == DIK_RBRACKET)
			{
				if (shift)
					this->Set_Text(m_pText + "}");
				else
					this->Set_Text(m_pText + "]");
			}

			if (keyIndex == DIK_BACKSLASH)
			{
				if (shift)
					this->Set_Text(m_pText + "|");
				else
					this->Set_Text(m_pText + "\\");
			}

			if (keyIndex == DIK_MINUS)
			{
				if (shift)
					this->Set_Text(m_pText + "_");
				else
					this->Set_Text(m_pText + "-");
			}

			if (keyIndex == DIK_EQUALS)
			{
				if (shift)
					this->Set_Text(m_pText + "+");
				else
					this->Set_Text(m_pText + "=");
			}
			*/

			// special cases

			if (keyIndex == DIK_SPACE)
			{
				this->Set_Text(m_pText + " ");
			}

			if (keyIndex == DIK_BACK)
			{
				if (this->Get_Text() != "")
				this->Set_Text(m_pText.substr(0, m_pText.size() - 1));
			}
		}

	}
}