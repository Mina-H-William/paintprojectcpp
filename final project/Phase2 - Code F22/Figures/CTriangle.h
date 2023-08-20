#include "CFigure.h"

class CTriangle : public CFigure
{
private:
	Point Corner1;
	Point Corner2;
	Point Corner3;
public:
	CTriangle(Point, Point , Point , GfxInfo FigureGfxInfo);
	CTriangle();
	virtual void Draw(Output* pOut) const;
	bool isinside(Point p);
	void move(Point p1);
	virtual void Save(ofstream&Fout);
	virtual void Load(ifstream&Fin);
	virtual string figurename();
	virtual Point getpoint();
};
