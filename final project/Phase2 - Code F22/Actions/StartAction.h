#pragma once
#include "Action.h"
class StartAction :public Action
{
private:
public:
	StartAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute(bool w=true);
	bool isrecord();
	virtual void undo();
	virtual void redo();
};

