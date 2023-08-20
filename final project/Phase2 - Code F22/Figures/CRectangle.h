#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
public:
	CRectangle(Point , Point, GfxInfo FigureGfxInfo );
	CRectangle();
	virtual void Draw(Output* pOut) const;
	bool isinside(Point p);
	void move(Point p1);
	virtual void Save(ofstream&Fout);
	virtual void Load(ifstream&Fin);
	virtual string figurename();
	virtual Point getpoint();
};

#endif