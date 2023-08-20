#include "PlayRecordAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

PlayRecordAction::PlayRecordAction(ApplicationManager* pApp) :Action(pApp)
{
	pManager->setisundo(false);
	pManager->setisredo(false);
}

void PlayRecordAction::ReadActionParameters()
{
}

void PlayRecordAction::Execute(bool w)
{
	Output* pOut = pManager->GetOutput();
	bool pl = pManager->getstart();
	bool st = pManager->getstop();
	if (pl && st)
	{
		pManager->setplay(true);
		pOut->ClearDrawArea();
		pManager->deleteallfigure();
		pManager->excuteplayactions();
		pManager->setplay(false);
	}
	else if (pl && !st)
	{
		pOut->PrintMessage("you must stop recording first ");
	}
	else
		pOut->PrintMessage("ERROR  <you must start recording and stop it>");

}

bool PlayRecordAction::isrecord()
{
	return false;
}
void PlayRecordAction::undo()
{
}
void PlayRecordAction::redo()
{
}