#ifndef ACTION_H
#define ACTION_H

#include "..\DefS.h"
#include "..\Figures\CFigure.h"

class ApplicationManager; //forward class declaration


//Base class for all possible actions
class Action
{
protected:
	ApplicationManager* pManager;	//Actions needs AppMngr to do their job
	bool recorded;

public:

	Action(ApplicationManager* pApp)        //constructor
	{
		pManager = pApp;
		recorded = false;
	}

	//Reads parameters required for action to execute (code depends on action type)
	virtual void ReadActionParameters() = 0;

	//Execute action (code depends on action type)
	virtual void Execute(bool w = true) = 0;
	virtual bool isrecord() = 0;
	virtual void undo() = 0;
	virtual void redo() = 0;
	void setrecorded(bool s)
	{
		recorded = s;
	}
	bool recordeddd() 
	{
		return recorded;
	}

};

#endif