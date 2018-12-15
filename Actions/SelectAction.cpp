#include "SelectAction.h"

SelectAction::SelectAction(ApplicationManager*p):Action(p)
{
}

void SelectAction::ReadActionParameters() {
	Input*pIn = pManager->GetInput();
	Output*pOut = pManager->GetOutput();

	pOut->PrintMessage("New select action: Click at any figure or empty area");
	pIn->GetPointClicked(p.x, p.y);
	pOut->ClearStatusBar();
}

void SelectAction::Execute() {
	ReadActionParameters();

	a = pManager->GetFigure(p.x, p.y);
	if(a!=NULL)
		a->SetSelected(true);

}