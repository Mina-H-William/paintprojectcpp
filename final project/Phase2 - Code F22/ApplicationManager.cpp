#include "ApplicationManager.h"


//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	SelectedFig = NULL;
	startrecord = NULL;
	lastaction = NULL;
	actnum = 0;
	FigCount = 0;
	undoact = 0;
	redoact = 0;
	f = 0;
	ID = 1;
	recording = false;
	play = false;
	stop = false;
	start = false;
	sound=false;
	isundo=false;
	isredo=false;
	
		
	//Create an array of figure pointers and set them to NULL		
	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;	
	for (int i = 0; i < 20; i++)
		act[i] = NULL;
	for (int i = 0; i < 5; i++)
		undolist[i] = NULL;
	for (int i = 0; i < 5; i++)
		redolist[i] = NULL;
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;
	
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
	   case FIG:
		   pAct = new CreatFigureAction(this);  
		   break;
		case DRAW_RECT:
			pAct = new AddRectAction(this);
			break;
		case DRAW_SQUARE:
			pAct = new AddSqrAction(this);
			break;
		case DRAW_HEXA:
			pAct = new AddHexAction(this);
			break;
		case DRAW_CIRCLE:
			pAct = new AddCircleAction(this);
			break;
		case DRAW_TRIANGLE:
			pAct = new AddTriangleAction(this);
			break;
		case SELECT:
			pAct = new SelectAction(this);
			break;
		case TO_DRAW1:
			pAct = new CreateDToolbarAction(this);
			break;
		case TO_DRAW2:
			pAct = new CreateDToolbar2Action(this);
			break;
		case DRAW_COLOR:
			pAct = new CreatDAction(this);
			f = 1;
			break;
		case FILL_COLOR:
			pAct = new CreatFAction(this);
			f = 2;
			break;
		case BLACK_COLOR:
			c1 = BLACK;
			if (f == 1)
				pAct = new DrawCAction(this);
			else if(f==2)
				pAct = new FillCAction(this);
			break;
		case YELLOW_COLOR:
			c1 = YELLOW;
			if (f == 1)
				pAct = new DrawCAction(this);
			else if (f == 2)
				pAct = new FillCAction(this);
			break;
		case ORANGE_COLOR:
			c1 = ORANGE;
			if (f == 1)
				pAct = new DrawCAction(this);
			else if (f == 2)
				pAct = new FillCAction(this);
			break;
		case RED_COLOR:
			c1 = RED;
			if (f == 1)
				pAct = new DrawCAction(this);
			else if (f == 2)
				pAct = new FillCAction(this);
			break;
		case GREEN_COLOR:
			c1 = GREEN;
			if (f == 1)
				pAct = new DrawCAction(this);
			else if (f == 2)
				pAct = new FillCAction(this);
			break;
		case BLUE_COLOR:
			c1 = BLUE;
			if (f == 1)
				pAct = new DrawCAction(this);
			else if (f == 2)
				pAct = new FillCAction(this);
			break;
		case TO_PLAY:
			pAct = new CreatePToolbarAction(this);
			break;
		case MOVE:
			pAct = new MoveAction(this);
			break;
		case SAVE:
			pAct=new SaveAction(this);
			break;
		case LOAD:
			pAct=new LoadAction(this);
			break;
		case PICKWITHTYPE:
			pAct=new PickByTypeAction(this);
			break;
		case PICKWITHCOLOR:
			pAct=new PickByColorAction(this);
			break;
		case PICKWITHTYPEANDCOLOR:
			pAct=new PickByColorAndTypeAction(this);
			break;
		case CLEAR:
			pAct = new ClearAllAction(this);
			break;
		case STARTRECORDING:
			pAct = new StartAction(this);
			startrecord = pAct;
			break;
		case STOPRECORDING:
			pAct = new StopAction(this);
			break;
		case PLAYRECORDING:
			pAct = new PlayRecordAction(this);
			break;
		case SOUND:
			pAct = new SoundAction(this);
			break;
		case DELET:
			pAct = new DeleteFigureAction(this);
			break;
		case UNDO:
			pAct = new UndoAction(this);
			break;
		case REDO:
			pAct = new RedoAction(this);
			break;
		case EXIT:
			///create ExitAction here
			pAct=new ExitAction(this);
			break;
		
		case STATUS:	//a click on the status bar ==> no action
			return;
	}
	pOut->ClearStatusBar();
	//Execute the created action
	if (pAct != NULL)
	{
		lastaction=pAct;
		if (isredo && getundoaction())
			addtoredolist(lastaction);
		pAct->Execute(true);//Execute
		if(isundo)
			addtoundolist(lastaction);
		if(!isredo&&ActType!=REDO&&isundo)
		{
		for (int i = 0; i < 5; i++)
		redolist[i] = NULL;
		redoact=0;
		}
		if (recording && ActType != STARTRECORDING)
			startrecord->Execute(false);
		pAct = NULL;
	}
}
//==================================================================================//
//						        Delete Functions 							        //
//==================================================================================//

void ApplicationManager::clearall()
{
	for (int i = 0; i < FigCount; i++)
	{
		delete FigList[i];
		FigList[i] = NULL;
	}
	if (!recording && !play)
	{
		for (int i = 0; i < undoact; i++)
		{
			if (!undolist[i]->recordeddd())
			delete undolist[i];
			undolist[i] = NULL;
		}
		for (int i = 0; i < redoact; i++)
		{
			if (!redolist[i]->recordeddd())
			delete redolist[i];
			redolist[i] = NULL;
		}
		for (int i = 0; i < actnum; i++)
		{
			if (act[i]->recordeddd())
			{
				delete act[i];
			}
			act[i] = NULL;
		}
		startrecord = NULL;
		lastaction = NULL;
		actnum = 0;
		undoact = 0;
		redoact = 0;
		f = 0;
		ID = 1;
		recording = false;
		play = false;
		stop = false;
		start = false;
		sound = false;
		isundo = false;
		isredo = false;
		c1 = GREEN;
	}
	FigCount = 0;
	SelectedFig = NULL;
}

void ApplicationManager::deletefigure(CFigure* cf1)
{
	CFigure* temp;
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i] == cf1 && i < (FigCount - 1))
		{
			temp = FigList[i];
			FigList[i] = FigList[i + 1];
			FigList[i + 1] = temp;
		}
		if (FigList[i] == cf1 && i == (FigCount - 1))
		{
			FigList[i] = NULL;
			FigCount = FigCount - 1;
			SelectedFig = NULL;
		}
	}
}

void ApplicationManager::deleteallfigure()
{
	for (int i = 0; i < FigCount; i++)
	{
		delete FigList[i];
		FigList[i] = NULL;
	}
	FigCount = 0;
	SelectedFig = NULL;
}

////////////////////////////////////////////////////////////////////////////////////

//==================================================================================//
//						      setters and getters 							        //
//==================================================================================//

void ApplicationManager::setrecording(bool rec)
{
	recording = rec;
}

bool ApplicationManager::getrecording()
{
	return recording;
}

void ApplicationManager::setplay(bool rec)
{
	play = rec;
}

void ApplicationManager::setstart(bool s)
{
	start = s;
}

bool ApplicationManager::getstart()
{
	return start;
}

int ApplicationManager::getactnum()
{
	return actnum;
}

void ApplicationManager::setstop(bool rec)
{
	stop = rec;
}

bool ApplicationManager::getstop()
{
	return stop;
}
Action* ApplicationManager::getlastaction()
{
	return lastaction;
}

int ApplicationManager::getfigcount()
{
	return FigCount;
}

color ApplicationManager::getcolor()
{
	return c1;
}
bool ApplicationManager::getsound()
{
	return sound;
}
void ApplicationManager::setsound(bool f)
{
	sound = f;
}

void ApplicationManager::setselectedfigure(CFigure* cf)
{
	SelectedFig = cf;
}

CFigure* ApplicationManager::getselectedfigure()
{
	return SelectedFig;
}

void ApplicationManager::setlastaction(Action* Act)
{
	if (actnum < 20)
	{
		act[actnum++] = Act;
		Act->setrecorded(true);
	}
}

CFigure* ApplicationManager::GetFigure(Point p) const
{
	for (int i = FigCount - 1; i >= 0; i--)
	{
		if (FigList[i]->isinside(p))
		{
			return FigList[i];
		}
	}
	return NULL;
}

Action* ApplicationManager::getundoaction()
{
	Action* undoaction;
	if (!undolist[0])
		return NULL;
	for (int i = 0; i < 5; i++)
	{
		if (undolist[i])
			undoaction = undolist[i];
		else
			return undoaction;
	}
	return undoaction;
}
Action* ApplicationManager::getredoaction()
{
	Action* redoaction;
	if (!redolist[0])
		return NULL;
	for (int i = 0; i < 5; i++)
	{
		if (redolist[i])
			redoaction = redolist[i];
		else
			return redoaction;
	}
	return redoaction;
}

void ApplicationManager::setisundo(bool s)
{
	isundo = s;
}

void ApplicationManager::setisredo(bool s)
{
	isredo = s;
}

////////////////////////////////////////////////////////////////////////////////////

//==================================================================================//
//						       Other functions							            //
//==================================================================================//

string ApplicationManager::clrtostring(color clr)
{	
	string s;
	if(clr==BLUE)
	s="BLUE";
	if(clr==GREEN)
	s="GREEN";
	if(clr==RED)
	s="RED";
	if(clr==ORANGE)
	s="ORANGE";
	if(clr==YELLOW)
	s="YELLOW";
	if(clr==BLACK)
	s="BLACK";
	return s;
}

void ApplicationManager::MOVEE(Point p) const
{
	if(SelectedFig!=NULL)
	SelectedFig->move(p);
}

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if(pFig->getID()!=0)
	pFig->setID(ID++);
	if(FigCount < MaxFigCount )
		FigList[FigCount++] = pFig;	
		
}

void ApplicationManager::excuteplayactions()
{
	for (int i = 0; i < actnum; i++)
	{
		Sleep(1000);
		act[i]->Execute(false);
		pOut->ClearDrawArea();
		UpdateInterface();
	}
}

void ApplicationManager::addtoundolist(Action* pAct)
{
	Action* temp1, * temp2;
	if (undoact < 5)
	{
		undolist[undoact] = pAct;
		undoact++;
	}
	else
	{
		temp1 = undolist[3];
		undolist[3] = undolist[4];
		for (int i = 3; i > 0; i--)
		{
			temp2 = undolist[i - 1];
			undolist[i - 1] = temp1;
			temp1 = temp2;
		}
		undolist[4] = pAct;
	}
}
void ApplicationManager::addtoredolist(Action* pAct)
{
	Action* temp1, * temp2;
	if (redoact < 5)
	{
		redolist[redoact] = pAct;
		redoact++;
	}
	else
	{
		temp1 = redolist[3];
		redolist[3] = redolist[4];
		for (int i = 3; i > 0; i--)
		{
			temp2 = redolist[i - 1];
			redolist[i - 1] = temp1;
			temp1 = temp2;
		}
		redolist[4] = pAct;
	}
}
void ApplicationManager::removefromundolist()
{
	int remove;
	if (!undolist[0])
		return;
	for (int i = 0; i < 5; i++)
	{
		if (undolist[i])
			remove = i;
	}
	undolist[remove] = NULL;
	undoact--;
}
void ApplicationManager::removefromredolist()
{
	int remove;
	if (!redolist[0])
		return;
	for (int i = 0; i < 5; i++)
	{
		if (redolist[i])
			remove = i;
	}
	redolist[remove] = NULL;
	redoact--;
}

void ApplicationManager::SaveAll(ofstream& Fout)
{
	Fout << FigCount << endl;
	for (int i = 0; i < FigCount; i++)
		FigList[i]->Save(Fout);
}

////////////////////////////////////////////////////////////////////////////////////


//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	Output*pOut=GetOutput();
	pOut->ClearDrawArea();
	for(int i=0; i<FigCount; i++)
		FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }


////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;
	
}
