#include "ApplicationManager.h"


//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	
	FigCount = 0;
		
	//Create an array of figure pointers and set them to NULL		
	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;	
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
		case DRAW_RECT:
			pAct = new AddRectAction(this);
			break;

		case SELECT:
			pAct = new SelectAction(this);
			break;

		case DRAW_LINE:
			pAct = new AddLineAction(this);
			break;

		case DRAW_ELLIPSE:
			pAct = new AddElipseAction(this);
			break;

		case DRAW_RHOMBUS:
			pAct = new AddRhomAction(this);
			break;

		case DRAW_TRI:
			pAct = new AddTriAction(this);
			break;
		
		case SAVE : 
			pAct = new SaveAction(this);
			break;

		case LOAD :
			pAct = new LoadAction(this);
			break;

		case EXIT:
			///create ExitAction here
			
			break;

		case DRAWING_AREA:
			for (int i = 0;i < FigCount;i++) {
				FigList[i]->SetSelected(false);
			}
			break;
		
		case STATUS:	//a click on the status bar ==> no action
			return;
	}
	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//Action is not needed any more ==> delete it
		pAct = NULL;
	}
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if(FigCount < MaxFigCount )
		FigList[FigCount++] = pFig;
}

//Saving all Figures into a file
void ApplicationManager::SaveAll(ofstream& svFile) const
{
	svFile << FigCount << '\n';
	for (int i = 0; i < FigCount; ++i) {
		FigList[i]->Save(svFile);
	}
}

//void ApplicationManager()
////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(int x, int y) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL


	//Add your code here to search for a figure given a point x,y	
	//Remember that ApplicationManager only calls functions do NOT implement it.
	CFigure*pFig = NULL;
	Point UserPoint;

	UserPoint.x = x;   UserPoint.y = y;
	for (int i = 0;i < FigCount;i++) {
		FigList[i]->SetSelected(false);
	}

	for (int i = 0;i < FigCount;i++) {
		if (FigList[i]->isin(UserPoint))
		pFig = FigList[i];
	}
	return pFig;
}

//Clear the figure list
void ApplicationManager::ClearFigureList()
{
	for (int i = 0; i < FigCount; i++)
		delete FigList[i];
	FigCount = 0;
	this->UpdateInterface();
}

//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
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
