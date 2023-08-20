#include "CHex.h"
#include <iostream>
using namespace std;

CHex::CHex(Point P1, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	midd = P1;
}
CHex::CHex()
{
}


void CHex::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawHexagon(midd, FigGfxInfo, Selected);
}

bool CHex::isinside(Point p)
{
	 double a, a1, a2, a3, a4, a5, a6;
	 double* px = new  double [6];
	 double* py = new  double [6];
	px[0] = midd.x; px[1] = midd.x - (50 * sqrt(3));
	py[0] = midd.y + 100; py[1] = midd.y + 50;
	px[2] = midd.x - (50 * sqrt(3)); px[3] = px[0];
	py[2] = midd.y - 50; py[3] = midd.y - 100;
	px[4] = midd.x + (50 * sqrt(3)); px[5] = px[4];
	py[4] = midd.y - 50; py[5] = midd.y + 50;
	a = (3 * sqrt(3) * pow(100,2)) / 2.0;
	a1 = abs((p.x * (py[0] - py[1]) + px[0] * (py[1] - p.y) + px[1] * (p.y - py[0])) / 2.0);
	a2 = abs((p.x * (py[1] - py[2]) + px[1] * (py[2] - p.y) + px[2] * (p.y - py[1])) / 2.0);
	a3 = abs((p.x * (py[2] - py[3]) + px[2] * (py[3] - p.y) + px[3] * (p.y - py[2])) / 2.0);
	a4 = abs((p.x * (py[3] - py[4]) + px[3] * (py[4] - p.y) + px[4] * (p.y - py[3])) / 2.0);
	a5 = abs((p.x * (py[4] - py[5]) + px[4] * (py[5] - p.y) + px[5] * (p.y - py[4])) / 2.0);
	a6 = abs((p.x * (py[5] - py[0]) + px[5] * (py[0] - p.y) + px[0] * (p.y - py[5])) / 2.0);
	if (abs(a - (a1 + a2 + a3 + a4 + a5 + a6))<=0.1 )
		return true;
	else
		return false;
}

void CHex::move(Point p1)
{
	midd = p1;
}
void CHex::Save(ofstream&Fout)
{
		Fout<<"HEXAGON"<<"   ";
	CFigure::Save(Fout);
	Fout<<midd.x<<"   "<<midd.y<<"   "<<clrtostring(FigGfxInfo.DrawClr)<<" ";
	if(FigGfxInfo.isFilled==true)
		Fout<<clrtostring(FigGfxInfo.FillClr)<<endl;
	else Fout<<"NO_FILL"<<endl;
}
void CHex::Load(ifstream&Fin)
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
string CHex::figurename()
{
	return "HEXAGON";
}
Point CHex::getpoint()
{
	return midd;
}