#include"SaveTypeAction.h"

SaveTypeAction::SaveTypeAction(ApplicationManager* pApp) : Action(pApp)
{}

void SaveTypeAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Please Enter 0 for Rectangle, 1 for Line, 2 for Ellipse, 3 for Triangle and 4 for Rhombus");
	//pIn->GetSrting();
	pOut->PrintMessage("Saving .. Please enter file name for saving then click an empty area");
	//pOut->PrintMessage("Saving A Graph, Click on an empty area");	
}

void SaveTypeAction::Execute()
{}