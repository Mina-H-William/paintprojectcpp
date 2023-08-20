#include "AddHexAction.h"


#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddHexAction::AddHexAction(ApplicationManager* pApp) :Action(pApp)
{
	pManager->setisundo(true);
	pManager->setisredo(false);
}

void AddHexAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Hexagon: Click at midd");

	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);


	RectGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	RectGfxInfo.DrawClr = pOut->getCrntDrawColor();
	RectGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddHexAction::Execute(bool w)
{
	if(pManager->getsound())
		PlaySound("Hexagon.wav",NULL,SND_SYNC);
	//This action needs to read some parameters first
	if(w)
	ReadActionParameters();

	//Create a rectangle with the parameters read from the user
	R = new CHex(P1, RectGfxInfo);

	//Add the rectangle to the list of figures
	pManager->AddFigure(R);
}

bool AddHexAction::isrecord()
{
	return true;
}
void AddHexAction::undo()
{
	cpyR=R;
	pManager->deletefigure(R);
}
void AddHexAction::redo()
{
	pManager->AddFigure(cpyR);
}