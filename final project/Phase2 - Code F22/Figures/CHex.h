#include "CFigure.h"

class CHex : public CFigure
{
private:
	Point midd;
public:
	CHex(Point, GfxInfo FigureGfxInfo);
	CHex();
	virtual void Draw(Output* pOut) const;
	bool isinside(Point p);
	void move(Point p1);
	virtual void Save(ofstream&Fout);
	virtual void Load(ifstream&Fin);
	virtual string figurename();
	virtual Point getpoint();
};