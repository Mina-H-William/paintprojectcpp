#ifndef UI_INFO_H
#define UI_INFO_H

#include "..\CMUgraphicsLib\CMUgraphics.h"

//User Interface information file.
//This file contains info that is needed by Input and Output classes to
//handle the user interface

enum GUI_MODE	//Graphical user interface mode
{
	MODE_DRAW, 	        //Drawing mode (startup mode)
	MODE_PLAY,         //Playing mode
	MODE_FIG,         //FIGURE mode
	MODE_DRAWCOLOR,   //DRAW COLOR mode
	MODE_FILLCOLOR,   //FILL COLOR mode
};

enum FigureMenuItem
{
	ITM_RECT,          //Recangle item in menu
	ITM_SQUARE,
	ITM_TRG,
	ITM_HEX,
	ITM_CIR,
	ITM_SWTMD1,
	FIGURE_ITM_COUNT
};

enum DrawColorMenuItem
{
	ITM_BLK1,
	ITM_YEL1,
	ITM_ORNG1,
	ITM_RED1,
	ITM_GRN1,
	ITM_BLUE1,
	ITM_SWTMD2,
	DRAWCOLOR_ITM_COUNT
};

enum FillColorMenuItem
{
	ITM_BLK,
	ITM_YEL,
	ITM_ORNG,
	ITM_RED,
	ITM_GRN,
	ITM_BLUE,
	ITM_SWTMD3,
	FILLCOLOR_ITM_COUNT
};

enum DrawMenuItem //The items of the Draw menu (you should add more items)
{
	//Note: Items are **(ordered)** here as they appear in menu
	//If you want to change the menu items order, change the order here
	ITM_FIG,
	ITM_DCLR,
	ITM_FCLR,
	ITM_MOVE,
	ITM_SLCT,
	ITM_UNDO,
	ITM_REDO,
	ITM_CLEAR,
	ITM_DELETE,
	ITM_STARTREC,
	ITM_STOPREC,
	ITM_PLAYREC,
	ITM_SAVE,
	ITM_LOAD,
	ITM_SOUND,
	ITM_SWITCHP,
	//TODO: Add more items names here

	ITM_EXIT,		//Exit item
	DRAW_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum
	
};

enum PlayMenuItem //The items of the Play menu (you should add more items)
{
	//Note: Items are **(ordered)** here as they appear in menu
	//If you want to change the menu items order, change the order here
	
	//TODO: Add more items names here
	ITM_PHT,
	ITM_PHC,
	ITM_PHB,
	ITM_SWITCHD,
	ITM_EXITb,
	PLAY_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum
	
};





__declspec(selectany) //This line to prevent "redefinition error"

struct UI_Info	//User Interface Info.
{
	GUI_MODE InterfaceMode;
	
	int	width, height,	    //Window width and height
		wx , wy,			//Window starting coordinates
		StatusBarHeight,	//Status Bar Height
		ToolBarHeight,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		DrawMenuItemWidth,		//Width of each item in toolbar menu
		PlayMenuItemWidth;

	color DrawColor;		//Drawing color
	color FillColor;		//Filling color
	color HighlightColor;	//Highlighting color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Background color
	color StatusBarColor;	//Status bar color
	int PenWidth;			//width of the pen that draws shapes

	/// Add more members if needed
	
}UI;	//create a global object UI

#endif