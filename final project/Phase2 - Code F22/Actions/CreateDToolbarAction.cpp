#include "CreateDToolbarAction.h"
#include "..\ApplicationManager.h"




CreateDToolbarAction::CreateDToolbarAction(ApplicationManager* pApp) :Action(pApp)
{
	pManager->setisundo(false);
	pManager->setisredo(false);
}



void CreateDToolbarAction::ReadActionParameters()
{}




void CreateDToolbarAction::Execute(bool w)
{
	Output* pOut = pManager->GetOutput();
	pOut->CreateDrawToolBar();
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

bool CreateDToolbarAction::isrecord()
{
	return false;
}
void CreateDToolbarAction::undo()
{
}
void CreateDToolbarAction::redo()
{
}