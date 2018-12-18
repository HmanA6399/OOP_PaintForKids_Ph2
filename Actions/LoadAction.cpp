#include"LoadAction.h"

LoadAction::LoadAction(ApplicationManager *pApp):Action(pApp)
{}

void LoadAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Please enter the path of the file to load, press enter to start  writing");
	pIn->WaitEnter();
	loadFileName = pIn->GetSrting(pOut);
	if (loadFileName.find(".txt") == -1) loadFileName += ".txt";
	pOut->ClearDrawArea();
}

void LoadAction::Execute()
{
	int nFig;
	string dClr, fClr;

	//Default point and GfxInfo as dummy input to construct new figures
	Point defP = { 0, 0 };
	GfxInfo defGfx = {
		BLUE,
		BLUE,
		false,
		0
	};

	while ( true ) {
		ReadActionParameters();
		pManager->ClearFigureList();
		LoadFile = new ifstream(loadFileName, ios::in);
		if (LoadFile->is_open()) {
			*LoadFile >> dClr; UI.DrawColor = StringColor[dClr];
			*LoadFile >> fClr; UI.FillColor = StringColor[fClr];
			*LoadFile >> nFig;

			for (int i = 0; i < nFig && !(LoadFile->eof()); ++i) {
				*LoadFile >> figType;
				switch (figType)
				{
				case 'R':
					figTOLoad = new CRectangle(defP, defP, defGfx);
				    figTOLoad->Load(*LoadFile);
					pManager->AddFigure(figTOLoad);
					break;

				case 'L':
					figTOLoad = new CLine(defP, defP, defGfx);
					figTOLoad->Load(*LoadFile);
					pManager->AddFigure(figTOLoad);
					break;

				case 'E':
					figTOLoad = new CElipse(defP, defGfx);
					figTOLoad->Load(*LoadFile);
					pManager->AddFigure(figTOLoad);
					break;

				case 'T':
					figTOLoad = new CTri(defP, defP, defP, defGfx);
					figTOLoad->Load(*LoadFile);
					pManager->AddFigure(figTOLoad);
					break;

				case 'H':
					figTOLoad = new CRhom(defP, defGfx);
					figTOLoad->Load(*LoadFile);
					pManager->AddFigure(figTOLoad);
					break;

				default :
					cout << "There's an error in the saved file loading coordination";
					break;
				}
			}
			break;
		}
		else {
			pManager->GetOutput()->PrintMessage("An Error Occured while opening the file, press start to re-enter a valid path");
			pManager->GetInput()->WaitEnter();
		}
	}
}