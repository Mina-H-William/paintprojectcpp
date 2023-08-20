#include "CSquare.h"

CSquare::CSquare(Point P1, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	midd = P1;
	
}
CSquare::CSquare()
{
	
}

void CSquare::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->Drawsqr(midd , FigGfxInfo, Selected);
}

bool CSquare::isinside(Point p)
{
	Point Corner1, Corner2;
	Corner1.x = midd.x - 125;
	Corner1.y = midd.y - 125;
	Corner2.x = midd.x + 125;
	Corner2.y = midd.y + 125;
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

void CSquare::move(Point p1)
{
	midd = p1;
}
void CSquare::Save(ofstream&Fout)
{
		Fout<<"SQUARE"<<"   ";
	CFigure::Save(Fout);
	Fout<<midd.x<<"   "<<midd.y<<"   "<<clrtostring(FigGfxInfo.DrawClr)<<" ";
		if(FigGfxInfo.isFilled==true)
		Fout<<clrtostring(FigGfxInfo.FillClr)<<endl;
	else Fout<<"NO_FILL"<<endl;
}
void CSquare::Load(ifstream&Fin)
{
	string dclr,fclr;
	Fin>>ID;
	Fin>>midd.x>>midd.y>>dclr>>fclr;
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
string CSquare::figurename()
{
	return "SQUARE";
}
Point CSquare::getpoint()
{
	return midd;
}