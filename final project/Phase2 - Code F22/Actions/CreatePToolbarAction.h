#pragma once
#include "Action.h"
class CreatePToolbarAction :  public Action
{
private:
	ofstream Fout;
public:
	CreatePToolbarAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute(bool w = true);
	bool isrecord();
	virtual void undo();
	virtual void redo();
};

