#include "AddTriAction.h"

AddTriAction::AddTriAction(ApplicationManager*p):Action(p)
{
}

void AddTriAction::ReadActionParameters() {
	Input*pIn = pManager->GetInput();
	Output*pOut = pManager->GetOutput();

	pOut->PrintMessage("New Triangle: Click at first corner");
	pIn->GetPointClicked(p1.x, p1.y);

	pOut->PrintMessage("New Triangle: Click at second corner");
	pIn->GetPointClicked(p2.x, p2.y);

	pOut->PrintMessage("New Triangle: Click at third corner");
	pIn->GetPointClicked(p3.x, p3.y);

	TriGfxInfo.isFilled = false;
	TriGfxInfo.DrawClr = pOut->getCrntDrawColor();
	TriGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->CreateStatusBar();
}

void AddTriAction::Execute() {
	ReadActionParameters();

	CTri*t = new CTri(p1, p2, p3, TriGfxInfo);

	pManager->AddFigure(t);
}

