#include "CFigure.h"

CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
	ID=-1;
}
CFigure::CFigure()
{ 
	ID=0;
	Selected=false;
}


void CFigure::SetSelected(bool s)
{	Selected = s; }
void CFigure::setID(int id) 
{ID=id;}
int CFigure::getID() 
{return ID;}
bool CFigure::IsSelected() const
{	return Selected; }

void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
}
void CFigure::Save(ofstream&Fout)
{
	Fout<<ID<<"   ";
}
string CFigure::clrtostring(color clr)
{	
	string s;
	if(clr==BLUE)
	s="BLUE";
	else if(clr==GREEN)
	s="GREEN";
	else if(clr==RED)
	s="RED";
	else if(clr==ORANGE)
	s="ORANGE";
	else if(clr==YELLOW)
	s="YELLOW";
	else if(clr==BLACK)
	s="BLACK";
	return s;
}
color CFigure::stringtoclr(string s)
{
	color clr;
	if(s=="RED")
	clr=RED;
	if(s=="BLUE")
	clr=BLUE;
	if(s=="GREEN")
	clr=GREEN;
	if(s=="YELLOW")
	clr=YELLOW;
	if(s=="ORANGE")
	clr=ORANGE;
	if(s=="BLACK")
	clr=BLACK;
	if(s=="NO_FILL")
	{
	FigGfxInfo.isFilled=false;
	clr=UI.FillColor;
	}
	return clr;
}
GfxInfo CFigure::getGfxInfo()
{
	return FigGfxInfo;
}
void CFigure::setisfilled(bool f)
{
	FigGfxInfo.isFilled=f;
}