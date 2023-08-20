#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include <Windows.h>
#include<MMSystem.h>
#include "DEFS.h"
#include "Figures\CFigure.h"
#include "Actions\Action.h"
#include "GUI\input.h"
#include "GUI\output.h"
#include "Actions\AddRectAction.h"
#include "Actions\AddSqrAction.h"
#include "Actions\AddTriangleAction.h"
#include "Actions\AddCircleAction.h"
#include "Actions\AddHexAction.h"
#include "Actions\SelectAction.h"
#include "Actions\DrawCAction.h"
#include "Actions\FillCAction.h"
#include "Actions\ClearAllAction.h"
#include "Actions\CreatDAction.h"
#include "Actions\CreatFAction.h"
#include "Actions\CreateDToolbarAction.h"
#include "Actions\CreateDToolbar2Action.h"
#include "Actions\CreatePToolbarAction.h"
#include "Actions\CreatFigureAction.h"
#include "Actions\DeleteFigureAction.h"
#include "Actions\MoveAction.h"
#include "Actions\SaveAction.h"
#include "Actions\LoadAction.h"
#include "Actions\PickByTypeAction.h"
#include "Actions\PickByColorAction.h"
#include "Actions\PickByColorAndTypeAction.h"
#include "Actions\StartAction.h"
#include "Actions\StopAction.h"
#include "Actions\PlayRecordAction.h"
#include "Actions\SoundAction.h"
#include "Actions\UndoAction.h"
#include "Actions\RedoAction.h"
#include "Actions\ExitAction.h"

//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures

private:
	color c1;

	int FigCount, f, ID, actnum , undoact , redoact;		//(figcount) Actual number of figures // (f)  which color user press //(id) number of figure // (actnum) number of action recorded //(undocount) number of undo action  //(redocount)number of redo action 
	bool recording, play, stop, start, sound, isundo, isredo;  //(recording) if i recorde now or not  //(play) am i press play action?  //(stop) am i press stop action? //(start) am i press start action? // (sound) is this action has sound //(isundo && isredo)is this action undo or redo 

	        //All Pointers To Action Class
	Action* act[20];       //pointer to actions recorded
	Action* undolist[5];  //array of undo actions
	Action* redolist[5];  //array of redo actions
	Action* lastaction;   //last action i press  
	Action* startrecord;  // pointer to recording action


	       //All Pointers To CFigure Class
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)
	CFigure* SelectedFig;   //Pointer to the selected figure
	CFigure* lastfigure;   //Pointer to the last figure drawen

	//Pointers to Input and Output classes
	Input *pIn;
	Output *pOut;
public:	
	ApplicationManager(); 
	~ApplicationManager();
	
	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType) ; //Creates an action and executes it
	//`````````````````````````````````//


	// -- Figures Management Functions
	void clearall();
	void excuteplayactions();
	void deleteallfigure();
	void deletefigure(CFigure* cf1);
	void MOVEE(Point p) const;
	void SaveAll(ofstream& Fout);
	string clrtostring(color clr);
	void addtoundolist(Action* pAct);
	void removefromundolist();
	void addtoredolist(Action* pAct);
	void removefromredolist();
	//`````````````````````````````````//


	// <setters and getters>
	void AddFigure(CFigure* pFig);          //Adds a new figure to the FigList
	CFigure* GetFigure(Point p) const; //Search for a figure given a point inside the figure
	CFigure* getselectedfigure();
	void setselectedfigure(CFigure* cf);
	void setlastaction(Action* act);
	color getcolor();
	void setrecording(bool rec);
	bool getrecording();
	void setplay(bool rec);
	void setstart(bool s);
	bool getstart();
	void setstop(bool rec);
	bool getstop();
	int getactnum();
	int getfigcount();
	bool getsound();
	void setsound(bool f);
	void setisundo(bool s);
	void setisredo(bool s);
	Action* getredoaction();
	Action* getundoaction();
	Action* getlastaction();
	//`````````````````````````````````//
	

	// -- Interface Management Functions
	Input* GetInput() const; //Return pointer to the input
	Output* GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window


};

#endif