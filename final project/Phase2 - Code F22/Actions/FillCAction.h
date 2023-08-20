#pragma once
#include "Action.h"

class FillCAction : public Action
{
private:
	color c;
	CFigure* cf1;
	CFigure* cf2;
	color oldc;
	bool isfill;
public:
	FillCAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute(bool w = true);
	bool isrecord();
	virtual void undo();
	virtual void redo();
};

