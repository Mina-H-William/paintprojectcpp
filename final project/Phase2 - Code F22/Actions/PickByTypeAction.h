#pragma once
#include "Action.h"
#include <string>
class PickByTypeAction:public Action
{
private:
	ifstream Fin;
	ofstream Fout;
	Point p;  //point clicked
	int counter,icounter;  //number of correct picks
	CFigure* Figure;
public:
	PickByTypeAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute(bool w = true);
	bool isrecord();
	virtual void undo();
	virtual void redo();
};