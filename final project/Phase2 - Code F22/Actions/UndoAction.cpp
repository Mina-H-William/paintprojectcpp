#include "UndoAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

UndoAction::UndoAction(ApplicationManager* pApp) :Action(pApp)
{
	pManager->setisundo(false);
	pManager->setisredo(true);
}

void UndoAction::ReadActionParameters()
{
	undoaction=pManager->getundoaction();
}

void UndoAction::Execute(bool w)
{
	Output*pOut=pManager->GetOutput();
	if(w)
	ReadActionParameters();
	if(!undoaction)
	{
		pOut->PrintMessage("No Actions To Undo");
		return;
	}
	undoaction->undo();
	pManager->removefromundolist();
}

bool UndoAction::isrecord()
{
	return true;
}
void UndoAction::undo()
{
	undoaction->undo();
}
void UndoAction::redo()
{
	undoaction->redo();
}