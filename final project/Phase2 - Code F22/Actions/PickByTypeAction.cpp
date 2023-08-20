#include "PickByTypeAction.h"
#include "..\ApplicationManager.h"
#include<cstdlib>
#include<time.h>
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "SelectAction.h"

PickByTypeAction::PickByTypeAction(ApplicationManager* pApp):Action(pApp)
{
	pManager->setisundo(false);
	pManager->setisredo(false);
	counter=0;
	icounter=0;
}

void PickByTypeAction::ReadActionParameters()
{

}

void PickByTypeAction::Execute(bool w)
{
	int rfig,count[5],i=0,r,c,s,h,t;
	bool fr=true,fc=true,fs=true,fh=true,ft=true;
	string random[5],fig,msg,test;
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	Input* pIn=pOut->CreateInput();
	pOut->ClearDrawArea();
	pManager->deleteallfigure();
	Fin.open("PlayMode.txt");
	for(int j=0;j<5;j++)
		count[j]=0;
	while(Fin>>fig)
	{
		if(fig=="RECTANGLE")
		{
			CRectangle* rect=new CRectangle();
			rect->Load(Fin);
			pManager->AddFigure(rect);
			if(fr)
			{
				r=i;
				random[i++]=fig;
				fr=false;
			}
			count[r]++;
		}
		if(fig=="CIRCLE")
		{
			CCircle* circle=new CCircle();
			circle->Load(Fin);
			pManager->AddFigure(circle);
				if(fc)
			{
				c=i;
				random[i++]=fig;
				fc=false;
			}
			count[c]++;
		}
		if(fig=="SQUARE")
		{
			CSquare* square=new CSquare();
			square->Load(Fin);
			pManager->AddFigure(square);
			if(fs)
			{
				s=i;
				random[i++]=fig;
				fs=false;
			}
			count[s]++;
		}
		if(fig=="HEXAGON")
		{
			CHex* Hex=new CHex();
			Hex->Load(Fin);
			pManager->AddFigure(Hex);
			if(fh)
			{
				h=i;
				random[i++]=fig;	
				fh=false;
			}
			count[h]++;
		}
		if(fig=="TRIANGLE")
		{
			CTriangle* triangle=new CTriangle();
			triangle->Load(Fin);
			pManager->AddFigure(triangle);
			if(ft)
			{
				t=i;
				random[i++]=fig;
				ft=false;
			}
			count[t]++;
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
		pOut->PrintMessage("Pick all "+random[rfig]+'S');
		msg="      Number of Inorrect Picks is: ";
		while(counter<count[rfig])
		{
			pIn->GetPointClicked(p.x,p.y);
			Figure=pManager->GetFigure(p);
			if(Figure==NULL||Figure->figurename()!=random[rfig])
			{
				icounter++;
				pOut->PrintMessage("Number of Correct Picks is: "+to_string(counter)+msg+to_string(icounter));
				continue;
			}
			else 
			{
				counter++;
				pOut->ClearDrawArea();
				pManager->deletefigure(Figure);
				pManager->UpdateInterface();
				pOut->PrintMessage("Number of Correct Picks is: "+to_string(counter)+msg+to_string(icounter));
			}
		}
		pOut->PrintMessage("The Final Score is: Number of Correct Picks is: "+to_string(counter)+msg+to_string(icounter));
	}
}
bool PickByTypeAction::isrecord()
{
	return false;
}
void PickByTypeAction::undo()
{
}
void PickByTypeAction::redo()
{
}