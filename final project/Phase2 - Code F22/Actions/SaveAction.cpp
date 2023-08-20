#include "SaveAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

SaveAction::SaveAction(ApplicationManager* pApp) : Action(pApp)
{
	pManager->setisundo(false);
	pManager->setisredo(false);
}



void SaveAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	crntdclr=pManager->clrtostring(pOut->getCrntDrawColor());
	crntfclr=pManager->clrtostring(pOut->getCrntFillColor());
	pOut->PrintMessage("Please Enter the name of the file you want to save in");

	//Read 1st corner and store in point P1
	s=pIn->GetSrting(pOut);

	pOut->ClearStatusBar();
}

void SaveAction::Execute(bool w)
{
	if(w)
	ReadActionParameters();
	Fout.open(s+".txt");
	Fout<<crntdclr<<"   "<<crntfclr<<endl; 
	pManager->SaveAll(Fout);
	Fout.close();

}

bool SaveAction::isrecord()
{
	return false;
}
void SaveAction::undo()
{
}
void SaveAction::redo()
{
}