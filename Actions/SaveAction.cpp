#include "SaveAction.h"

SaveAction::SaveAction(ApplicationManager *pApp):Action(pApp)
{}

void SaveAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Saving .. Please enter file name for saving then press enter");
	fileName = pIn->GetSrting(pOut);
	pOut->ClearStatusBar();
	if (fileName.find(".txt") == -1) fileName += ".txt";
}

void SaveAction::Execute()
{
	ReadActionParameters();
	
	saveFile.open(fileName, ios::out);
	if ( saveFile.is_open() ) {
		saveFile << ColorString[UI.DrawColor] << " " << ColorString[UI.FillColor] << '\n';
		pManager->SaveAll(saveFile);
		saveFile.close();
	}
	else {
		cout << "Problem Opening the file\n";
	}
}