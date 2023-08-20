#ifndef CFIGURE_H
#define CFIGURE_H

#include <fstream>
#include "..\defs.h"
#include "..\GUI\Output.h"
#include <cmath>

//Base class for all figures
class CFigure
{
protected:
	int ID;		//Each figure has an ID
	bool Selected;	//true if the figure is selected.
	GfxInfo FigGfxInfo;	//Figure graphis info
	/// Add more parameters if needed.

public:
	CFigure(GfxInfo FigureGfxInfo);
	CFigure();

	void SetSelected(bool s);	//select/unselect the figure
	bool IsSelected() const;	//check whether fig is selected
	virtual bool isinside(Point p) = 0 ;
	virtual void move(Point p1) = 0;         //move figure 
	virtual void Draw(Output* pOut) const  = 0 ;   //Draw the figure
	void setID(int id) ;
	int getID();
	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	void ChngFillClr(color Fclr);	//changes the figure's filling color
	virtual void Save(ofstream&Fout)=0;
	string clrtostring(color clr);
	color stringtoclr(string s);
	virtual void Load(ifstream&Fin)=0;
	virtual string figurename()=0;
	GfxInfo getGfxInfo();
	virtual Point getpoint()=0;
	void setisfilled(bool f);

	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure

	///Decide the parameters that you should pass to each function	


	//virtual void Save(ofstream &OutFile) = 0;	//Save the figure parameters to the file
	//virtual void Load(ifstream &Infile) = 0;	//Load the figure parameters to the file

	//virtual void PrintInfo(Output* pOut) = 0;	//print all figure info on the status bar
};

#endif