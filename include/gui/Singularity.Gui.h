#pragma once

//just to make the compiling go down easier
namespace Singularity
{
	namespace Gui
	{
		class GuiExtension;

		class Control;
		class GuiScreen;
		class TextControl;

		class Button;
		class Checkbox;
		class Image;
		class Label;
		class List;
		class NinePatch; // for stretchable backgrounds
		class Panel; // for grouping things
		class Window;
		//class ProgressBar // for loading, health, etc. background (ninepatch?), gradient, bar
		class ListBox;
		class ListPanel;
		class ListBoxElement;

		class Font;

		class GuiControlVertexDeclaration;
		class GuiFontVertexDeclaration;
	}
}

#include "gui\Singularity.Gui.Defines.h"
#include "..\resources\Singularity.Gui.Resources.h"

//Common includes
#include "common\Singularity.Common.h"
#include "core\Singularity.Core.h"
#include "graphics\Singularity.Graphics.h"
#include "inputs\Singularity.Inputs.h"

//Vertex Declarations
#include "gui\GuiControlVertexDeclaration.h"
#include "gui\GuiFontVertexDeclaration.h"

//Extension
#include "gui\GuiExtension.h"

//Main component includes
#include "gui\ControlDelegate.h"
#include "gui\ControlMouseDelegate.h"
#include "gui\ControlKeyboardDelegate.h"
#include "gui\ListBoxDelegate.h"
#include "gui\Control.h"
#include "gui\TextControl.h"
#include "gui\GuiScreen.h"

//Interactable objects
#include "gui\Button.h"
#include "gui\Checkbox.h"
#include "gui\ListBox.h"
#include "gui\ListPanel.h"
#include "gui\ListBoxElement.h"
#include "gui\TextBox.h"

//font objects
#include "gui\Font.h"

//window objects
#include "gui\Label.h"
#include "gui\Panel.h"
#include "gui\Window.h"

//visual objects
#include "gui\Image.h"
#include "gui\NinePatch.h"