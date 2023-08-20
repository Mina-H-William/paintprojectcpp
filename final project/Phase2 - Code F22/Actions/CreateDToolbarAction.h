#pragma once
#include "Action.h"
class CreateDToolbarAction :   public Action
{
private:
	ifstream Fin;
	string fig;
public:
	CreateDToolbarAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute(bool w = true);
	bool isrecord();
	virtual void undo();
	virtual void redo();

};

