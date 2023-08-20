#pragma once
#include "Action.h"
class MoveAction : public Action
{
private:
	Point p;
	Point OldP;
	CFigure* Figure;
public:
	MoveAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute(bool w = true);
	bool isrecord();
	virtual void undo();
	virtual void redo();
};

