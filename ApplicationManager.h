#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "GUI\output.h"
#include"Actions/AddRectAction.h"
#include"Actions/AddElipseAction.h"
#include"Actions/AddLineAction.h"
#include"Actions/AddTriAction.h"
#include"Actions/AddRhomAction.h"
#include"Actions/SelectAction.h"
#include"Actions/SaveAction.h"
#include"Actions/LoadAction.h"
#include"Figures/CFigure.h"


//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures
	ofstream saveFile;
	ifstream loadFile;

private:
	int FigCount;		//Actual number of figures
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)

	CFigure* SelectedFig; //Pointer to the selected figure
	CFigure* Clipboard;   //Pointer to the copied/cut figure

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
	
	void ClearFigureList();

	// -- Figures Management Functions
	void AddFigure(CFigure* pFig);
	void Load();
	//Adds a new figure to the FigList
	CFigure *GetFigure(int x, int y) const; //Search for a figure given a point inside the figure
	void SaveAll(ofstream& svFile) const;
	void PrintAll();
	void SaveType(ofstream& svFile, const CFigure& typ) const;
	void Load(ifstream& ldFile);
		
	// -- Interface Management Functions
	Input *GetInput() const; //Return pointer to the input
	Output *GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window	
};

#endif