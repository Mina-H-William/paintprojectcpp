#include "CreatFigureAction.h"
#include "..\ApplicationManager.h"




CreatFigureAction::CreatFigureAction(ApplicationManager* pApp) :Action(pApp)
{
	pManager->setisundo(false);
	pManager->setisredo(false);
}



void CreatFigureAction::ReadActionParameters()
{}




void CreatFigureAction::Execute(bool w)
{
	if(pManager->getsound())
		PlaySound("Figures.wav",NULL,SND_SYNC);
	Output* pOut = pManager->GetOutput();
	pOut->CreateFigureToolBar();
}

bool CreatFigureAction::isrecord()
{
	return true;
}
void CreatFigureAction::undo()
{
}
void CreatFigureAction::redo()
{
}