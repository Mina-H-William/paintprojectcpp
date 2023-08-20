#pragma once
#include "Action.h"

class SoundAction: public Action
{
private:
public:
	SoundAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute(bool w = true);
	bool isrecord();
	virtual void undo();
	virtual void redo();
};

