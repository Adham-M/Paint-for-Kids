#include "Input.h"
#include "Output.h"


Input::Input(window* pW)
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(int &x, int &y) const
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string Input::GetSrting(Output *pO) const
{
	string Label;
	char Key;
	while (1)
	{
		pWind->WaitKeyPress(Key);
		if (Key == 27)	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if (Key == 13)	//ENTER key is pressed
			return Label;
		if ((Key == 8) && (Label.size() >= 1))	//BackSpace is pressed
			Label.resize(Label.size() - 1);
		else
			Label += Key;
		if (pO)
			pO->PrintMessage(Label);
	}
}

//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction() const
{
	int x, y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if (UI.InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_RECT:			return DRAW_RECT;
			case ITM_TRI:			return DRAW_TRI;
			case ITM_LINE:			return DRAW_LINE;
			case ITM_ELLIPSE:		return DRAW_ELLIPSE;
			case ITM_RHOMBUS:		return DRAW_RHOMBUS;

			case ITM_SELECT:		return SELECT;
			case ITM_DELETE:		return DEL;
			case ITM_COPY:			return COPY;
			case ITM_CUT:			return CUT;
			case ITM_PASTE:			return PASTE;

			//case ITM_Sound:			return SOUND;
			case ITM_SAVE:			return SAVE;
			case ITM_SAVEBYTYPE:	return SAVE_BY_TYPE;
			case ITM_LOAD:			return LOAD;
			case ITM_PLAYMODE:		return TO_PLAY;
			case ITM_EXIT:			return EXIT;


			case ITM_CHNGCLR:		if (x < ITM_CHNGCLR*UI.MenuItemWidth + UI.MenuItemWidth / 2)		 return CHNG_DRAW_CLR;
									else if (x < ITM_CHNGCLR*UI.MenuItemWidth + UI.MenuItemWidth)		 return CHNG_FILL_CLR;

			case ITM_Set2BkOrFrnt:	if (x < ITM_Set2BkOrFrnt*UI.MenuItemWidth + UI.MenuItemWidth / 2)	 return BRING_TO_FRONT;
									else if (x < ITM_Set2BkOrFrnt*UI.MenuItemWidth + UI.MenuItemWidth) 	 return BRING_TO_BACK;

			case ITM_Resize:		if (x < ITM_Resize*UI.MenuItemWidth + UI.MenuItemWidth / 4)			 return RESIZE_14;
									else if (x < ITM_Resize*UI.MenuItemWidth + UI.MenuItemWidth / 2)	 return RESIZE_12;
									else if (x < ITM_Resize*UI.MenuItemWidth + UI.MenuItemWidth / 4*3)	 return RESIZE_2;
									else if (x < ITM_Resize*UI.MenuItemWidth + UI.MenuItemWidth)		 return RESIZE_4;

			case ITM_PALETTE:		if (x < ITM_PALETTE*UI.MenuItemWidth + UI.MenuItemWidth / 5)		 return COLOR_BLACK;
									else if (x < ITM_PALETTE*UI.MenuItemWidth + UI.MenuItemWidth / 5*2)	 return COLOR_WHITE;
									else if (x < ITM_PALETTE*UI.MenuItemWidth + UI.MenuItemWidth / 5*3)	 return COLOR_RED;
									else if (x < ITM_PALETTE*UI.MenuItemWidth + UI.MenuItemWidth / 5*4)	 return COLOR_GREEN;
									else if (x < ITM_PALETTE*UI.MenuItemWidth + UI.MenuItemWidth)		 return COLOR_BLUE;

		
			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//else if (x >= UI.MenuItemWidth * ITM_EXIT && y <= 4 * UI.ToolBarHeight)
		//{
		//	if (y >= UI.ToolBarHeight && y <= 2 * UI.ToolBarHeight)
		//		return SOUND;
		//	else if (y >= 2 * UI.ToolBarHeight && y <= 3 * UI.ToolBarHeight)
		//	{
		//		if (x >= UI.MenuItemWidth * ITM_EXIT + UI.MenuItemWidth / 4)
		//			return RESIZE_14;
		//		else if (x >= UI.MenuItemWidth * ITM_EXIT + UI.MenuItemWidth / 2)
		//			return RESIZE_12;
		//		else if (x >= UI.MenuItemWidth * ITM_EXIT + UI.MenuItemWidth * 3 / 4)
		//			return RESIZE_2;
		//		else if (x >= UI.MenuItemWidth * ITM_EXIT + UI.MenuItemWidth)
		//			return RESIZE_4;
		//	}
		//	else if (y >= 3 * UI.ToolBarHeight && y < 4 * UI.ToolBarHeight)
		//	{
		//		if (x >= UI.MenuItemWidth * ITM_EXIT + UI.MenuItemWidth / 2)
		//			return BRING_TO_FRONT;
		//		else if (x >= UI.MenuItemWidth * ITM_EXIT + UI.MenuItemWidth)
		//			return BRING_TO_BACK;
		//	}
		//}

		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;
	}
	else	//GUI is in PLAY mode
	{
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_FIGURE:	return PICK_FIG;
			case ITM_COLOR:		return PICK_COLOR;
			case ITM_REST:		return RESTART;
			case ITM_DRAWMODE:	return TO_DRAW;
			case ITM_EXIT2:		return EXIT;

			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		return TO_PLAY;
	}

}


Input::~Input()
{
}