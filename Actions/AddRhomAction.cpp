#include "AddRhomAction.h"

AddRhomAction::AddRhomAction(ApplicationManager*p):Action(p)
{
}

void AddRhomAction::ReadActionParameters() {
	Input*pIn = pManager->GetInput();
	Output*pOut = pManager->GetOutput();

	pOut->PrintMessage("New Line: Click at the middle");
	pIn->GetPointClicked(p1.x, p1.y);

	RhomGfxInfo.isFilled = false;
	RhomGfxInfo.DrawClr = pOut->getCrntDrawColor();
	RhomGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();
}

void AddRhomAction::Execute() {
	ReadActionParameters();

	CRhom*R = new CRhom(p1,RhomGfxInfo);

	pManager->AddFigure(R);
}

