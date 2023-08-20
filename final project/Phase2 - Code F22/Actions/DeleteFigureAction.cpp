#include "DeleteFigureAction.h"
#include "..\ApplicationManager.h"




DeleteFigureAction::DeleteFigureAction(ApplicationManager* pApp) :Action(pApp)
{
	pManager->setisundo(true);
	pManager->setisredo(false);
}



void DeleteFigureAction::ReadActionParameters()
{
	cf= pManager->getselectedfigure();
}




void DeleteFigureAction::Execute(bool w)
{
	ReadActionParameters();
	cpycf=cf;
	pManager->deletefigure(cf);
}

bool DeleteFigureAction::isrecord()
{
	return true;
}
void DeleteFigureAction::undo()
{
	pManager->AddFigure(cpycf);
}
void DeleteFigureAction::redo()
{
	pManager->deletefigure(cf);
}