#pragma once
#include "Action.h"

class LoadAction : public Action
{
private:
	string name,fig;
	ifstream Fin;
public:
	LoadAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute(bool w = true);
	bool isrecord();
	virtual void undo();
	virtual void redo();
};

