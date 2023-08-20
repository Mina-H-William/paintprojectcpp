#include "CCircle.h"

CCircle::CCircle(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	midd = P1;
	radius = P2;
}
CCircle::CCircle()
{
	
}


void CCircle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->Drawcircle(midd, radius, FigGfxInfo, Selected);
}

bool CCircle::isinside(Point p)
{
	long long int d1, d2;
	d1 = sqrt(pow((midd.x - radius.x), 2) + pow((midd.y - radius.y), 2));
	d2 = sqrt(pow((midd.x - p.x), 2) + pow((midd.y - p.y), 2));
	if (d1 >= d2)
		return true;
	else
		return false;
}

void CCircle::move(Point p1)
{
	long long int w;
	w = sqrt(pow((radius.x - midd.x), 2) + pow((radius.y - midd.y), 2));
	midd = p1;
	radius.x = midd.x + w;
	radius.y = midd.y;
}
void CCircle::Save(ofstream&Fout)
{
		Fout<<"CIRCLE"<<"   ";
	CFigure::Save(Fout);
	Fout<<midd.x<<"   "<<midd.y<<"   "<<radius.x<<"   "<<radius.y<<"   "<<clrtostring(FigGfxInfo.DrawClr)<<" ";
	if(FigGfxInfo.isFilled==true)
		Fout<<clrtostring(FigGfxInfo.FillClr)<<endl;
	else Fout<<"NO_FILL"<<endl;
}
void CCircle::Load(ifstream&Fin)
{
	Fin>>ID;
	string dclr,fclr;
	Fin>>midd.x>>midd.y>>radius.x>>radius.y>>dclr>>fclr;
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
string CCircle::figurename()
{
	return "CIRCLE";
}
Point CCircle::getpoint()
{
	return midd;
}