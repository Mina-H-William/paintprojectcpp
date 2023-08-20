#pragma once
#include "Action.h"
class DeleteFigureAction : public Action
{
private:
	CFigure* cf;
	CFigure* cpycf;
public:
	DeleteFigureAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute(bool w = true);
	bool isrecord();
	virtual void undo();
	virtual void redo();
};

