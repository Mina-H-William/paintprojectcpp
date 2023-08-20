#pragma once
#include "Action.h"

class DrawCAction : public Action
{
private:
	color c;
	CFigure* cf1;
	color oldc;
public:
	DrawCAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute(bool w = true);
	bool isrecord();
	virtual void undo();
	virtual void redo();
};

