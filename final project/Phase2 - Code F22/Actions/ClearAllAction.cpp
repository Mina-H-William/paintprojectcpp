#include "ClearAllAction.h"
#include "..\ApplicationManager.h"




ClearAllAction::ClearAllAction(ApplicationManager* pApp) :Action(pApp)
{
	pManager->setisundo(false);
	pManager->setisredo(false);
}



void ClearAllAction::ReadActionParameters()
{}




void ClearAllAction::Execute(bool w)
{
	Output* pOut = pManager->GetOutput();
	pOut->ClearDrawArea();
	pManager->clearall();
}

bool ClearAllAction::isrecord()
{
	return true;
}
void ClearAllAction::undo()
{
}
void ClearAllAction::redo()
{
}