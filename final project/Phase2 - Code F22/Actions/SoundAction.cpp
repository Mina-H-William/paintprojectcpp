#include "SoundAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

SoundAction::SoundAction(ApplicationManager* pApp):Action(pApp)
{
	pManager->setisundo(false);
	pManager->setisredo(false);
}

void SoundAction::ReadActionParameters()
{
}

void SoundAction::Execute(bool w)
{
	if(pManager->getsound())
		pManager->setsound(false);
	else
		pManager->setsound(true);
}

bool SoundAction::isrecord()
{
	return false;
}
void SoundAction::undo()
{
}
void SoundAction::redo()
{
}