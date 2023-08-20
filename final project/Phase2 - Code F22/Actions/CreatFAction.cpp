#include "CreatFAction.h"
#include "..\ApplicationManager.h"




CreatFAction::CreatFAction(ApplicationManager* pApp) :Action(pApp)
{
	pManager->setisundo(false);
	pManager->setisredo(false);
}



void CreatFAction::ReadActionParameters()
{}




void CreatFAction::Execute(bool w)
{
	Output* pOut = pManager->GetOutput();
	pOut->CreateFillColorToolBar();
}

bool CreatFAction::isrecord()
{
	return true;
}
void CreatFAction::undo()
{
}
void CreatFAction::redo()
{
}