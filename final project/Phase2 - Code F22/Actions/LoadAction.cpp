#include "LoadAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

LoadAction::LoadAction(ApplicationManager* pApp) :Action(pApp)
{
	pManager->setisundo(false);
	pManager->setisredo(false);
}


void LoadAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input*pIn=pOut->CreateInput();
	pOut->PrintMessage("Please Enter the name of the file you want to load from");
	name=pIn->GetSrting(pOut);
	pOut->ClearStatusBar();
}

void LoadAction::Execute(bool w)
{
	if(w)
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	pOut->ClearDrawArea();
	pManager->deleteallfigure();
	Fin.open(name+".txt");
	while(Fin>>fig)
	{
		if(fig=="RECTANGLE")
		{
			CRectangle* rect=new CRectangle();
			rect->Load(Fin);
			pManager->AddFigure(rect);
		}
		if(fig=="CIRCLE")
		{
			CCircle* circle=new CCircle();
			circle->Load(Fin);
			pManager->AddFigure(circle);
		}
		if(fig=="SQUARE")
		{
			CSquare* square=new CSquare();
			square->Load(Fin);
			pManager->AddFigure(square);
		}
		if(fig=="HEXAGON")
		{
			CHex* Hex=new CHex();
			Hex->Load(Fin);
			pManager->AddFigure(Hex);
		}
		if(fig=="TRIANGLE")
		{
			CTriangle* triangle=new CTriangle();
			triangle->Load(Fin);
			pManager->AddFigure(triangle);
		}
	}
}

bool LoadAction::isrecord()
{
	return false;
}
void LoadAction::undo()
{
}
void LoadAction::redo()
{
}