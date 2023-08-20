#include "RedoAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

RedoAction::RedoAction(ApplicationManager* pApp) :Action(pApp)
{
	pManager->setisundo(false);
	pManager->setisredo(false);
}

void RedoAction::ReadActionParameters()
{
	redoaction=pManager->getredoaction();
}

void RedoAction::Execute(bool w)
{
	Output* pOut = pManager->GetOutput();
	if(w)
	ReadActionParameters();
	if(!redoaction)
	{
		pOut->PrintMessage("No Actions To redo");
		return;
	}
	redoaction->redo();
	pManager->addtoundolist(redoaction);
	pManager->removefromredolist();
}

bool RedoAction::isrecord()
{
	return true;
}
void RedoAction::undo()
{
	redoaction->undo();
}
void RedoAction::redo()
{
	redoaction->redo();
}