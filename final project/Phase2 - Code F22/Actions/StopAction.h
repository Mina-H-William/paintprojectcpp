#pragma once
#include "Action.h"
class StopAction : public Action
{
private:
public:
	StopAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute(bool w = true);
	bool isrecord();
	virtual void undo();
	virtual void redo();
};

