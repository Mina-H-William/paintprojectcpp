#include "CFigure.h"

class CSquare : public CFigure
{
private:
	Point midd;
	
public:
	CSquare(Point, GfxInfo FigureGfxInfo);
	CSquare();
	virtual void Draw(Output* pOut) const;
	bool isinside(Point p);
	void move(Point p1);
	virtual void Save(ofstream&Fout);
	virtual void Load(ifstream&Fin);
	virtual string figurename();
	virtual Point getpoint();
};