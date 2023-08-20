#pragma once
#include "Action.h"
class CreateDToolbar2Action :   public Action
{
private:
public:
	CreateDToolbar2Action(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute(bool w = true);
	bool isrecord();
	virtual void undo();
	virtual void redo();

};

