#include "DrawCAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

DrawCAction::DrawCAction(ApplicationManager* pApp) :Action(pApp)
{
	pManager->setisundo(true);
	pManager->setisredo(false);
}


void DrawCAction::ReadActionParameters()
{
	c = pManager->getcolor();
}

void DrawCAction::Execute(bool w)
{
	if(w)
	ReadActionParameters();
	cf1 = pManager->getselectedfigure();
	if (cf1)
	{
		oldc = cf1->getGfxInfo().DrawClr;
		cf1->ChngDrawClr(c);
	}
}

bool DrawCAction::isrecord()
{
	return true;
}
void DrawCAction::undo()
{
	cf1->ChngDrawClr(oldc);
}
void DrawCAction::redo()
{
	cf1->ChngDrawClr(c);
}