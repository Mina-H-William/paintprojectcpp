#include "FillCAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

FillCAction::FillCAction(ApplicationManager* pApp) :Action(pApp)
{
	pManager->setisundo(true);
	pManager->setisredo(false);
}


void FillCAction::ReadActionParameters()
{
	c = pManager->getcolor();
}

void FillCAction::Execute(bool w)
{
	if (w)
		ReadActionParameters();
	cf1 = pManager->getselectedfigure();
	if (cf1)
	{
		isfill = cf1->getGfxInfo().isFilled;
		oldc = cf1->getGfxInfo().FillClr;
		cf1->ChngFillClr(c);
	}
}

bool FillCAction::isrecord()
{
	return true;
}
void FillCAction::undo()
{
	if(isfill)
		cf1->ChngFillClr(oldc);
	else 
		cf1->setisfilled(false);
}
void FillCAction::redo()
{
	if(isfill)
		cf1->ChngFillClr(c);
	else 
		cf1->ChngFillClr(c);
}