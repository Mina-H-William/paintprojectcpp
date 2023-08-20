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
	while(1)
	{
		pWind->WaitKeyPress(Key);
		if(Key == 27 )	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if(Key == 13 )	//ENTER key is pressed
			return Label;
		if((Key == 8) && (Label.size() >= 1))	//BackSpace is pressed
			Label.resize(Label.size() -1 );			
		else
			Label += Key;
		if (pO)
			pO->PrintMessage(Label);
	}
}

//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction() const
{	
	int x,y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if(UI.InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
	{
		//[1] If user clicks on the Toolbar
		if ( y >= 0 && y < UI.ToolBarHeight)
		{	
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.DrawMenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
				case ITM_FIG:		return FIG;
				case ITM_DCLR:		return DRAW_COLOR;
				case ITM_FCLR:		return FILL_COLOR;	
				case ITM_MOVE:		return MOVE;
				case ITM_SLCT:		return SELECT;
				case ITM_UNDO:		return UNDO;
				case ITM_REDO:		return REDO;
				case ITM_CLEAR:		return CLEAR;
				case ITM_DELETE:	return DELET;
				case ITM_STARTREC:	return STARTRECORDING;
				case ITM_STOPREC:	return STOPRECORDING;
				case ITM_PLAYREC:	return PLAYRECORDING;
				case ITM_SAVE:		return SAVE;
				case ITM_LOAD:		return LOAD;
				case ITM_SOUND:     return SOUND;
				case ITM_SWITCHP:	return TO_PLAY;
				case ITM_EXIT:		return EXIT;	
				default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if ( y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;	
		}
		
		//[3] User clicks on the status bar
		return STATUS;
	}
	else if(UI.InterfaceMode==MODE_PLAY)	//GUI is in PLAY mode
	{
		//[1] If user clicks on the Toolbar
		if ( y >= 0 && y < UI.ToolBarHeight)
		{	
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.PlayMenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
				case ITM_PHT:		return PICKWITHTYPE;
				case ITM_PHC:		return PICKWITHCOLOR;
				case ITM_PHB:		return PICKWITHTYPEANDCOLOR;
				case ITM_SWITCHD:	return TO_DRAW1;
				case ITM_EXITb:     return EXIT;
				default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if ( y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;	
		}
		
		//[3] User clicks on the status bar
		return STATUS;
		///TODO:
		//perform checks similar to Draw mode checks above
		//and return the correspoding action
	}	
	else if (UI.InterfaceMode == MODE_FIG)
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.DrawMenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_RECT:		return DRAW_RECT;
			case ITM_SQUARE:	return DRAW_SQUARE;
			case ITM_HEX:		return DRAW_HEXA;
			case ITM_CIR:		return DRAW_CIRCLE;
			case ITM_TRG:		return DRAW_TRIANGLE;
			case ITM_SWTMD1:	return TO_DRAW2;
			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;
	}
	else if (UI.InterfaceMode == MODE_DRAWCOLOR)
	{
	//[1] If user clicks on the Toolbar
	if (y >= 0 && y < UI.ToolBarHeight)
	{
		//Check whick Menu item was clicked
		//==> This assumes that menu items are lined up horizontally <==
		int ClickedItemOrder = (x / UI.DrawMenuItemWidth);
		//Divide x coord of the point clicked by the menu item width (int division)
		//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

		switch (ClickedItemOrder)
		{
		case ITM_BLK1:		return BLACK_COLOR;
		case ITM_YEL1:		return YELLOW_COLOR;
		case ITM_ORNG1:		return ORANGE_COLOR;
		case ITM_RED1:		return RED_COLOR;
		case ITM_GRN1:		return GREEN_COLOR;
		case ITM_BLUE1: 		return BLUE_COLOR;
		case ITM_SWTMD2:	return TO_DRAW2;
		default: return EMPTY;	//A click on empty place in desgin toolbar
		}
	}

	//[2] User clicks on the drawing area
	if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
	{
		return DRAWING_AREA;
	}

	//[3] User clicks on the status bar
	return STATUS;
	}
	else if (UI.InterfaceMode == MODE_FILLCOLOR)
	{
	//[1] If user clicks on the Toolbar
	if (y >= 0 && y < UI.ToolBarHeight)
	{
		//Check whick Menu item was clicked
		//==> This assumes that menu items are lined up horizontally <==
		int ClickedItemOrder = (x / UI.DrawMenuItemWidth);
		//Divide x coord of the point clicked by the menu item width (int division)
		//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

		switch (ClickedItemOrder)
		{
		case ITM_BLK:		return BLACK_COLOR;
		case ITM_YEL:		return YELLOW_COLOR;
		case ITM_ORNG:		return ORANGE_COLOR;
		case ITM_RED:		return RED_COLOR;
		case ITM_GRN:		return GREEN_COLOR;
		case ITM_BLUE: 		return BLUE_COLOR;
		case ITM_SWTMD3:	return TO_DRAW2;
		default: return EMPTY;	//A click on empty place in desgin toolbar
		}
	}

	//[2] User clicks on the drawing area
	if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
	{
		return DRAWING_AREA;
	}

	//[3] User clicks on the status bar
	return STATUS;
	}
}
/////////////////////////////////
	
Input::~Input()
{
}
