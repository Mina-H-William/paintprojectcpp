#include "StopAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

StopAction::StopAction(ApplicationManager* pApp) :Action(pApp)
{
	pManager->setisundo(false);
	pManager->setisredo(false);
}

void StopAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();

	bool rec = pManager->getrecording();
	if (rec)
		pOut->PrintMessage("stop recording");
	else
		pOut->PrintMessage("you must turn on recording first");
}

void StopAction::Execute(bool w)
{
	if (w)
		ReadActionParameters();
	bool rec = pManager->getrecording();
	if (rec)
		pManager->setstop(true);
	pManager->setrecording(false);
}

bool StopAction::isrecord()
{
	return false;
}
void StopAction::undo()
{
}
void StopAction::redo()
{
}