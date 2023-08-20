#pragma once
#include "Action.h"
#include <string>
class PickByColorAndTypeAction:public Action
{
private:
	ifstream Fin;
	ofstream Fout;
	Point p;  //point clicked
	int counter,icounter;  //number of correct picks
	CFigure* Figure;
public:
	PickByColorAndTypeAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute(bool w = true);
	bool isrecord();
	virtual void undo();
	virtual void redo();
};