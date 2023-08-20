#include "MoveAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"



MoveAction::MoveAction(ApplicationManager* pApp) : Action(pApp)
{
	pManager->setisundo(true);
	pManager->setisredo(false);
}



void MoveAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("please Click a point you want to move there");
	Figure=pManager->getselectedfigure();
	OldP=Figure->getpoint();
	//Read 1st corner and store in point P1
	pIn->GetPointClicked(p.x, p.y);

	pOut->ClearStatusBar();
	pOut->ClearDrawArea();
}

void MoveAction::Execute(bool w)
{
	if(w)
	ReadActionParameters();
	pManager->MOVEE(p);
}

bool MoveAction::isrecord()
{
	return true;
}

void MoveAction::undo()
{
	Figure->move(OldP);
}

void MoveAction::redo()
{
	Figure->move(p);
}
