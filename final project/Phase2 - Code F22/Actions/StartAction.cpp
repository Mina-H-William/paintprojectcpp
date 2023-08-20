#include "StartAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

StartAction::StartAction(ApplicationManager* pApp) :Action(pApp)
{
	pManager->setisundo(false);
	pManager->setisredo(false);
}

void StartAction::ReadActionParameters()
{}

void StartAction::Execute(bool w)
{
	Output* pOut = pManager->GetOutput();
	Action* acttype = pManager->getlastaction();
	int fn, num;
	bool rec;
	num = pManager->getactnum();
	fn = pManager->getfigcount();
	rec = pManager->getrecording();
	if (w)
	{
		if (num != 0)
		{
			pOut->PrintMessage(" ERROR   <CantRecord>");
			return;
		}
	}
	if (fn == 0 || rec )
	{
		pOut->PrintMessage(" recording......");
		pManager->setrecording(true);
		pManager->setstart(true);
		if ((acttype->isrecord()))
			pManager->setlastaction(acttype);
	}
	else 
		pOut->PrintMessage(" ERROR   <CantRecord>");
}

bool StartAction::isrecord()
{
	return false;
}
void StartAction::undo()
{
}
void StartAction::redo()
{
}