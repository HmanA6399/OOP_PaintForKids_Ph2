#include "SaveAction.h"

SaveAction::SaveAction(ApplicationManager *pApp):Action(pApp)
{}

void SaveAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Saving .. Please enter file name for saving then click an empty area");
	fileName = pIn->GetSrting(pOut);
	//pOut->PrintMessage("Saving A Graph, Click on an empty area");	
}

void SaveAction::Execute()
{
	ReadActionParameters();
	
	saveFile.open(fileName, ios::out);
	pManager->SaveAll(saveFile);
}