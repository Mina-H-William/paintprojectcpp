#ifndef ADD_TRIANGLE_ACTION_H
#define ADD_TRIANGLE_ACTION_H

#include "Action.h"
#include "..\Figures\CTriangle.h"
class AddTriangleAction : public Action
{
private:
	Point P1, P2, P3; //Rectangle Corners
	GfxInfo RectGfxInfo;
	CTriangle*R,*cpyR;
public:
	AddTriangleAction(ApplicationManager* pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute(bool w = true);
	bool isrecord();
	virtual void undo();
	virtual void redo();
};
#endif

