#include "PickByColorAndTypeAction.h"
#include "..\ApplicationManager.h"
#include<cstdlib>
#include<time.h>
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "SelectAction.h"

PickByColorAndTypeAction::PickByColorAndTypeAction(ApplicationManager* pApp):Action(pApp)
{
	pManager->setisundo(false);
	pManager->setisredo(false);
	counter=0;
	icounter=0;
}

void PickByColorAndTypeAction::ReadActionParameters()
{

}

void PickByColorAndTypeAction::Execute(bool w)
{
	Output* pOut = pManager->GetOutput();
	Input* pIn=pOut->CreateInput();
	int rfig,count=0,i=0;
	bool fr=true,fc=true,fs=true,fh=true,ft=true;
	string random[200] ,fig,msg,test;
	ReadActionParameters();
	pOut->ClearDrawArea();
	pManager->deleteallfigure();
	Fin.open("PlayMode.txt");
	while(Fin>>fig)
	{
		if(fig=="RECTANGLE")
		{
			CRectangle* rect=new CRectangle();
			rect->Load(Fin);
			pManager->AddFigure(rect);
			if(rect->getGfxInfo().isFilled)
				random[i++]=rect->clrtostring((rect->getGfxInfo()).FillClr)+" RECTANGLE";
			else
				random[i++]="NO_FILL RECTANGLE";
		}
		if(fig=="CIRCLE")
		{ 
			CCircle* circle=new CCircle();
			circle->Load(Fin);
			pManager->AddFigure(circle);
			if(circle->getGfxInfo().isFilled)
			random[i++]=circle->clrtostring((circle->getGfxInfo()).FillClr)+" CIRCLE";
			else
				random[i++]="NO_FILL CIRCLE";
		}
		if(fig=="SQUARE")
		{
			CSquare* square=new CSquare();
			square->Load(Fin);
			pManager->AddFigure(square);
			if(square->getGfxInfo().isFilled)
			random[i++]=square->clrtostring((square->getGfxInfo()).FillClr)+" SQUARE";
			else
				random[i++]="NO_FILL SQUARE";
		}
		if(fig=="HEXAGON")
		{
			CHex* Hex=new CHex();
			Hex->Load(Fin);
			pManager->AddFigure(Hex);
			if(Hex->getGfxInfo().isFilled)
			random[i++]=Hex->clrtostring((Hex->getGfxInfo()).FillClr)+" HEXAGON";
			else
				random[i++]="NO_FILL HEXAGON";
		}
		if(fig=="TRIANGLE")
		{
			CTriangle* triangle=new CTriangle();
			triangle->Load(Fin);
			pManager->AddFigure(triangle);
			if(triangle->getGfxInfo().isFilled)
			random[i++]=triangle->clrtostring((triangle->getGfxInfo()).FillClr)+" TRIANGLE";
			else
				random[i++]="NO_FILL TRIANGLE";
		}
	}
	pManager->UpdateInterface();
	if(i==0)
	{
		pOut->PrintMessage("No Figures to Pick From");
	}
	else
	{
		srand(time(0));
		rfig=rand()%i;
		string figurecolor=random[rfig],figure="",color="";
		bool f=true;
		for(int j=0;j<figurecolor.size();j++)
		{
			if(figurecolor[j]!=' '&&f)
				color+=figurecolor[j];
			if(!f)
				figure+=figurecolor[j];
			if(figurecolor[j]==' ')
				f=false;
		}
		for(int j=0;j<pManager->getfigcount();j++)
			if(random[j]==random[rfig])
				count++;
		pOut->PrintMessage("Pick all "+random[rfig]+'S');
		msg="      Number of Inorrect Picks is: ";
		while(counter<count)
		{
			pIn->GetPointClicked(p.x,p.y);
			Figure=pManager->GetFigure(p);
			if(Figure&&(Figure->clrtostring(Figure->getGfxInfo().FillClr)==color&&Figure->getGfxInfo().isFilled&&Figure->figurename()==figure)||(Figure&&(color=="NO_FILL")&&!Figure->getGfxInfo().isFilled)&&Figure->figurename()==figure)
			{
				counter++;
				pOut->ClearDrawArea();
				pManager->deletefigure(Figure);
				pManager->UpdateInterface();
				pOut->PrintMessage("Number of Correct Picks is: "+to_string(counter)+msg+to_string(icounter));
			}
			else
			{
				icounter++;
				pOut->PrintMessage("Number of Correct Picks is: "+to_string(counter)+msg+to_string(icounter));
			}
		}
		pOut->PrintMessage("The Final Score is: Number of Correct Picks is: "+to_string(counter)+msg+to_string(icounter));
	}
}
bool PickByColorAndTypeAction::isrecord()
{
	return false;
}
void PickByColorAndTypeAction::undo()
{
}
void PickByColorAndTypeAction::redo()
{
}

