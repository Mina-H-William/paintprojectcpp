#include "CFigure.h"

class CCircle : public CFigure
{
private:
	Point midd;
	Point radius;
public:
	CCircle(Point, Point, GfxInfo FigureGfxInfo);
	CCircle();
	virtual void Draw(Output* pOut) const;
	bool isinside(Point p);
	void move(Point p1);
	virtual void Save(ofstream&Fout);
	virtual void Load(ifstream&Fin);
	virtual string figurename();
	virtual Point getpoint();
};