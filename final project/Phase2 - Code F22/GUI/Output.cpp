#include "Output.h"


Output::Output()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;
	
	UI.width = 1250;
	UI.height = 650;
	UI.wx = 5;
	UI.wy =5;

	
	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 50;
	UI.DrawMenuItemWidth = 70;
	UI.PlayMenuItemWidth = 70;
	
	UI.DrawColor = BLUE;	//Drawing color
	UI.FillColor = GREEN;	//Filling color
	UI.MsgColor = WHITE;		//Messages color
	UI.BkGrndColor = LIGHTCYAN;	   //Background color
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = NAVYBLUE;
	UI.PenWidth = 3;	//width of the figures frames

	
	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project");
	
	CreateDrawToolBar();
	CreateStatusBar();
}


Input* Output::CreateInput() const
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int w, int h, int x, int y) const
{ 
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);	
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateDrawToolBar() const
{
	ClearToolBar();
	UI.InterfaceMode = MODE_DRAW;

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way
	
	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[DRAW_ITM_COUNT];
	MenuItemImages[ITM_FIG] = "images\\MenuItems\\Menu_Fig.jpg";
	MenuItemImages[ITM_DCLR] = "images\\MenuItems\\Menu_Dcolor.jpg";
	MenuItemImages[ITM_FCLR] = "images\\MenuItems\\Menu_Fcolor.jpg";
	MenuItemImages[ITM_MOVE] = "images\\MenuItems\\Menu_Move.jpg";
	MenuItemImages[ITM_SLCT] = "images\\MenuItems\\Menu_Select.jpg";
	MenuItemImages[ITM_UNDO] = "images\\MenuItems\\Menu_Undo.jpg";
	MenuItemImages[ITM_REDO] = "images\\MenuItems\\Menu_Redo.jpg";
	MenuItemImages[ITM_CLEAR] = "images\\MenuItems\\Menu_Clear.jpg";
	MenuItemImages[ITM_DELETE] = "images\\MenuItems\\Menu_delete.jpg";
	MenuItemImages[ITM_STARTREC] = "images\\MenuItems\\Menu_Srec.jpg";
	MenuItemImages[ITM_STOPREC] = "images\\MenuItems\\Menu_SPrec.jpg";
	MenuItemImages[ITM_PLAYREC] = "images\\MenuItems\\Menu_Prec.jpg";
	MenuItemImages[ITM_SAVE] = "images\\MenuItems\\Menu_Save.jpg";	
	MenuItemImages[ITM_LOAD] = "images\\MenuItems\\Menu_Load.jpg";
	MenuItemImages[ITM_SOUND] = "images\\MenuItems\\Menu_Sound.jpg";
	MenuItemImages[ITM_SWITCHP] = "images\\MenuItems\\Menu_Play.jpg";
	MenuItemImages[ITM_EXIT] = "images\\MenuItems\\Menu_Exit.jpg";

	//TODO: Prepare images for each menu item and add it to the list

	//Draw menu item one image at a time
	for(int i=0; i<DRAW_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.DrawMenuItemWidth, 0, UI.DrawMenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(BLACK, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::CreateFigureToolBar() const	//create the Figure Tool bar
{
	ClearToolBar();
	UI.InterfaceMode = MODE_FIG;
	string MenuItemImages[FIGURE_ITM_COUNT];
	MenuItemImages[ITM_RECT] = "images\\MenuItems\\Menu_Rect.jpg";
	MenuItemImages[ITM_SQUARE] = "images\\MenuItems\\Menu_Square.jpg";
	MenuItemImages[ITM_HEX] = "images\\MenuItems\\Menu_Hex.jpg";
	MenuItemImages[ITM_CIR] = "images\\MenuItems\\Menu_Circ.jpg";
	MenuItemImages[ITM_TRG] = "images\\MenuItems\\Menu_Triangle.jpg";
	MenuItemImages[ITM_SWTMD1] = "images\\MenuItems\\Menu_Draw.jpg";

	//Draw menu item one image at a time
	for (int i = 0; i < FIGURE_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.DrawMenuItemWidth, 0, UI.DrawMenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(BLACK, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
}

void Output::CreateDrawColorToolBar() const	//create the Draw color Tool bar
{
	ClearToolBar();
	UI.InterfaceMode = MODE_DRAWCOLOR;
	string MenuItemImages[DRAWCOLOR_ITM_COUNT];
	MenuItemImages[ITM_BLK1] = "images\\MenuItems\\Menu_Black.jpg";
	MenuItemImages[ITM_YEL1] = "images\\MenuItems\\Menu_Yellow.jpg";
	MenuItemImages[ITM_ORNG1] = "images\\MenuItems\\Menu_Orange.jpg";
	MenuItemImages[ITM_RED1] = "images\\MenuItems\\Menu_Red.jpg";
	MenuItemImages[ITM_GRN1] = "images\\MenuItems\\Menu_Green.jpg";
	MenuItemImages[ITM_BLUE1] = "images\\MenuItems\\Menu_Blue.jpg";
	MenuItemImages[ITM_SWTMD2] = "images\\MenuItems\\Menu_Draw.jpg";

	//Draw menu item one image at a time
	for (int i = 0; i < DRAWCOLOR_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.DrawMenuItemWidth, 0, UI.DrawMenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(BLACK, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
}

void Output::CreateFillColorToolBar() const	//create the Fill color Tool bar
{
	ClearToolBar();
	UI.InterfaceMode = MODE_FILLCOLOR;
	string MenuItemImages[FILLCOLOR_ITM_COUNT];
	MenuItemImages[ITM_BLK] = "images\\MenuItems\\Menu_Black.jpg";
	MenuItemImages[ITM_YEL] = "images\\MenuItems\\Menu_Yellow.jpg";
	MenuItemImages[ITM_ORNG] = "images\\MenuItems\\Menu_Orange.jpg";
	MenuItemImages[ITM_RED] = "images\\MenuItems\\Menu_Red.jpg";
	MenuItemImages[ITM_GRN] = "images\\MenuItems\\Menu_Green.jpg";
	MenuItemImages[ITM_BLUE] = "images\\MenuItems\\Menu_Blue.jpg";
	MenuItemImages[ITM_SWTMD3] = "images\\MenuItems\\Menu_Draw.jpg";

	//Draw menu item one image at a time
	for (int i = 0; i < FILLCOLOR_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.DrawMenuItemWidth, 0, UI.DrawMenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(BLACK, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
}

void Output::CreatePlayToolBar() const
{
	ClearToolBar();
	UI.InterfaceMode = MODE_PLAY;
	string MenuItemImages[PLAY_ITM_COUNT];
	MenuItemImages[ITM_PHT] = "images\\MenuItems\\Menu_PHT.jpg";
	MenuItemImages[ITM_PHC] = "images\\MenuItems\\Menu_PHC.jpg";
	MenuItemImages[ITM_PHB] = "images\\MenuItems\\Menu_Fig.jpg";
	MenuItemImages[ITM_SWITCHD] = "images\\MenuItems\\Menu_Draw.jpg";
	MenuItemImages[ITM_EXITb] = "images\\MenuItems\\Menu_Exit.jpg";
	///TODO: write code to create Play mode menu
	for(int i=0; i<PLAY_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.PlayMenuItemWidth, 0, UI.PlayMenuItemWidth, UI.ToolBarHeight);

	pWind->SetPen(BLACK, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 3);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);
	pWind->SetPen(BLACK, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearToolBar() const
{
	pWind->SetPen(WHITE, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);
}
void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar
	
	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD , BY_NAME, "Arial");   
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight/1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntDrawColor() const	//get current drawing color
{	return UI.DrawColor;	}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntFillColor() const	//get current filling color
{	return UI.FillColor;	}
//////////////////////////////////////////////////////////////////////////////////////////
	
int Output::getCrntPenWidth() const		//get current pen width
{	return UI.PenWidth;	}

//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

void Output::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if(selected)	
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else			
		DrawingClr = RectGfxInfo.DrawClr;
	
	pWind->SetPen(DrawingClr,1);
	drawstyle style;
	if (RectGfxInfo.isFilled)	
	{
		style = FILLED;		
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else	
		style = FRAME;

	
	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);
	
}

void Output::Drawsqr(Point P1, GfxInfo RectGfxInfo, bool selected) const
{
	Point p2, p3;
	p2.x = P1.x - 125;
	p2.y = P1.y - 125;
	p3.x = P1.x + 125;
	p3.y = P1.y + 125;
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawRectangle(p2.x, p2.y, p3.x, p3.y, style);
}

void Output::Drawtriangle(Point P1, Point P2, Point P3, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, style);
}

void Output::DrawHexagon(Point P1, GfxInfo RectGfxInfo, bool selected) const
{
	 int* px = new int [6];
	 int* py = new int [6];
	 px[0] = P1.x; px[1] = P1.x - (50 * sqrt(3));
	 py[0] = P1.y+100; py[1] = P1.y+50;
	 px[2] = P1.x-(50*sqrt(3)); px[3] = px[0];
	 py[2] = P1.y - 50; py[3] = P1.y -100;
	 px[4] = P1.x+(50*sqrt(3)); px[5] = px[4];
	 py[4] = P1.y - 50; py[5] = P1.y + 50;
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawPolygon(px, py,6, style);
}

void Output::Drawcircle(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	long long int w;
	w = sqrt(pow((P2.x - P1.x),2) + pow((P2.y - P1.y),2));
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawCircle(P1.x,P1.y , w, style);
}


//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}

