#ifndef ADD_CIRCLE_ACTION_H
#define ADD_CIRCLE_ACTION_H

#include "Action.h"
#include "..\Figures\CCircle.h"
class AddCircleAction : public Action
{
private:
	Point P1, P2; //Rectangle Corners
	CCircle* R, *cpyR;
	GfxInfo RectGfxInfo;
public:
	AddCircleAction(ApplicationManager* pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute(bool w = true);
	bool isrecord();
	virtual void undo();
	virtual void redo();

};
#endif

