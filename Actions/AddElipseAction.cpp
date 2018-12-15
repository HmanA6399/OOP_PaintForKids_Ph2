#include "AddElipseAction.h"

AddElipseAction::AddElipseAction(ApplicationManager*p):Action(p)
{
}

void AddElipseAction::ReadActionParameters() {
	Input*pIn = pManager->GetInput();
	Output*pOut = pManager->GetOutput();

	pOut->PrintMessage("New Elipse: Click at the centre");
	pIn->GetPointClicked(p1.x, p1.y);

	ElipseGfxInfo.isFilled = false;
	ElipseGfxInfo.DrawClr = pOut->getCrntDrawColor();
	ElipseGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->CreateStatusBar();
}

void AddElipseAction::Execute() {
	ReadActionParameters();

	CElipse*e = new CElipse(p1,ElipseGfxInfo);

	pManager->AddFigure(e);
}
