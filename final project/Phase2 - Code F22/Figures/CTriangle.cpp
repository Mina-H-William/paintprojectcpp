#include "CTriangle.h"

CTriangle::CTriangle(Point P1, Point P2, Point p3 , GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Corner3 = p3;
}
CTriangle::CTriangle()
{

}

void CTriangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->Drawtriangle(Corner1, Corner2, Corner3 , FigGfxInfo, Selected);
}

bool CTriangle::isinside(Point p)
{
	long double a, a1,a2,a3;
	a = abs((Corner1.x * (Corner2.y - Corner3.y) + Corner2.x * (Corner3.y - Corner1.y) + Corner3.x * (Corner1.y - Corner2.y)) / 2.0);
	a1= abs((p.x * (Corner2.y - Corner3.y) + Corner2.x * (Corner3.y - p.y) + Corner3.x * (p.y - Corner2.y)) / 2.0);
	a2= abs((Corner1.x * (p.y - Corner3.y) + p.x * (Corner3.y - Corner1.y) + Corner3.x * (Corner1.y - p.y)) / 2.0);
	a3= abs((Corner1.x * (Corner2.y - p.y) + Corner2.x * (p.y - Corner1.y) + p.x * (Corner1.y - Corner2.y)) / 2.0);
	if (a == (a1 + a2 + a3))
		return true;
	else return false;
}

void CTriangle::move(Point p1)
{
	Point midd1;
	int xlen, ylen;
	midd1.x = (Corner1.x + Corner2.x + Corner3.x) / 3;
	midd1.y = (Corner1.y + Corner2.y + Corner3.y) / 3;
	xlen = (p1.x - midd1.x);
	ylen = (p1.y - midd1.y);
	Corner1.x += xlen;
	Corner2.x += xlen;
	Corner3.x += xlen;
	Corner1.y += ylen;
	Corner2.y += ylen;
	Corner3.y += ylen;
}
void CTriangle::Save(ofstream&Fout)
{
		Fout<<"TRIANGLE"<<"   ";
	CFigure::Save(Fout);
	Fout<<Corner1.x<<"   "<<Corner1.y<<"   "<<Corner2.x<<"   "<<Corner2.y<<"   "<<Corner3.x<<"   "<<Corner3.y<<"   "<<clrtostring(FigGfxInfo.DrawClr)<<" ";
		if(FigGfxInfo.isFilled==true)
		Fout<<clrtostring(FigGfxInfo.FillClr)<<endl;
	else Fout<<"NO_FILL"<<endl;
}
void CTriangle::Load(ifstream&Fin)
{
	string dclr,fclr;
	Fin>>ID;
	Fin>>Corner1.x>>Corner1.y>>Corner2.x>>Corner2.y>>Corner3.x>>Corner3.y>>dclr>>fclr;
	FigGfxInfo.DrawClr=stringtoclr(dclr);
	if(fclr=="NO_FILL")
	{
		FigGfxInfo.FillClr=UI.FillColor;
		FigGfxInfo.isFilled=false;
	}
	else
	{
		FigGfxInfo.FillClr=stringtoclr(fclr);
		FigGfxInfo.isFilled=true;
	}
}
string CTriangle::figurename()
{
	return "TRIANGLE";
}
Point CTriangle::getpoint()
{
	Point midd1;
	midd1.x = (Corner1.x + Corner2.x + Corner3.x) / 3;
	midd1.y = (Corner1.y + Corner2.y + Corner3.y) / 3;
	return midd1;
}