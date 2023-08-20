#pragma once
#include "Action.h"
class CreatDAction : public Action
{
private:
public:
	CreatDAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute(bool w = true);
	bool isrecord();
	virtual void undo();
	virtual void redo();
};

