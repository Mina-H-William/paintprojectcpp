#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

//This file contains some global constants and definitions to be used in the project.
enum ActionType //The actions supported (you can add more if needed)
{
	FIG,
	DRAW_RECT,		//Draw Rectangle
	DRAW_SQUARE,	//Draw Square
	DRAW_HEXA,		//Draw Hexagon
	DRAW_CIRCLE,	//Draw Circle
	DRAW_TRIANGLE,  //Draw Triangle
	DRAW_COLOR,		//DRaw	Color
	FILL_COLOR,		// fill Color
	BLACK_COLOR,	//black Color
	YELLOW_COLOR,	//yellow Color
	ORANGE_COLOR,	//orange Color
	RED_COLOR,		//red Color
	GREEN_COLOR,	//green Color
	BLUE_COLOR,		//blue Color
	MOVE,			//move item
	SELECT,         //select item
	DELET,
	UNDO,			//undo
	REDO,			//redo
	CLEAR,			//clear draw
	STARTRECORDING,	//start recording
	STOPRECORDING,	//stop recording
	PLAYRECORDING,	//play recording draw
	SAVE,			//save
	LOAD,			//load
	EXIT,			//Exit
	TO_DRAW1,		//Switch interface to Draw mode
	TO_DRAW2,
	TO_PLAY,		//Switch interface to Play mode
	EMPTY,			//A click on empty place in the toolbar
	DRAWING_AREA,	//A click on the drawing area
	STATUS,		//A click on the status bar
	PICKWITHTYPE,
	PICKWITHCOLOR,
	PICKWITHTYPEANDCOLOR,
	SOUND

	///TODO: Add the other action types of the two modes
};

struct Point	//To be used for figures points
{ int x,y; };

struct GfxInfo	//Graphical info of each figure (you may add more members)
{
	color DrawClr;	//Draw color of the figure
	color FillClr;	//Fill color of the figure
	bool isFilled;	//Figure Filled or not
	int BorderWdth;	//Width of figure borders

};

#endif