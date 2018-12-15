#include "AddLineAction.h"

AddLineAction::AddLineAction(ApplicationManager*p):Action(p)
{
}

void AddLineAction::ReadActionParameters() {
	Input*pIn = pManager->GetInput();
	Output*pOut = pManager->GetOutput();

	pOut->PrintMessage("New Line: Click at first corner");
	pIn->GetPointClicked(p1.x, p1.y);

	pOut->PrintMessage("New Line: Click at second corner");
	pIn->GetPointClicked(p2.x, p2.y);

	LineGfxInfo.isFilled = false;
	LineGfxInfo.DrawClr = pOut->getCrntDrawColor();
	LineGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();
}

void AddLineAction::Execute() {
	ReadActionParameters();

	CLine *l = new CLine(p1, p2, LineGfxInfo);

	pManager->AddFigure(l);
}

