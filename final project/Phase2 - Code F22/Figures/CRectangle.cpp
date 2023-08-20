#include "CRectangle.h"

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}
CRectangle::CRectangle()
{

}
		

void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}


bool CRectangle::isinside(Point p)
{
	if (p.x <= (Corner1.x > Corner2.x ? Corner1.x : Corner2.x) && p.x >= (Corner1.x < Corner2.x ? Corner1.x : Corner2.x))
	{
		if (p.y <= (Corner1.y > Corner2.y ? Corner1.y : Corner2.y) && p.y >= (Corner1.y < Corner2.y ? Corner1.y : Corner2.y))
		{
			return true;
		}
		else return false;
	}
	else return false;
}

void CRectangle::move(Point p1)
{
	Point midd1;
	midd1.x = ((Corner1.x+Corner2.x)/2);
	midd1.y = ((Corner1.y + Corner2.y) / 2);
	int xlen, ylen;
	xlen = (p1.x - midd1.x);
	ylen = (p1.y - midd1.y);
	Corner1.x += xlen;
	Corner1.y += ylen;
	Corner2.x += xlen;
	Corner2.y += ylen;
}
void CRectangle::Save(ofstream&Fout)
{
	Fout<<"RECTANGLE"<<"   ";
	CFigure::Save(Fout);
	Fout<<Corner1.x<<"   "<<Corner1.y<<"   "<<Corner2.x<<"   "<<Corner2.y<<"   "<<clrtostring(FigGfxInfo.DrawClr)<<" ";
		if(FigGfxInfo.isFilled==true)
		Fout<<clrtostring(FigGfxInfo.FillClr)<<endl;
	else Fout<<"NO_FILL"<<endl;
}
void CRectangle::Load(ifstream&Fin)
{
	string dclr,fclr;
	Fin>>ID;
	Fin>>Corner1.x>>Corner1.y>>Corner2.x>>Corner2.y>>dclr>>fclr;
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
string CRectangle::figurename()
{
	return "RECTANGLE";
}
Point CRectangle::getpoint()
{
	Point midd1;
	midd1.x = ((Corner1.x+Corner2.x)/2);
	midd1.y = ((Corner1.y + Corner2.y) / 2);
	return midd1;
}

