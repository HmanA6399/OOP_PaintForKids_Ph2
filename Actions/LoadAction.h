#pragma once
#include <iostream>
#include <fstream>
#include "Action.h"
#include "../Figures/CFigure.h"
#include "..\Figures\CRectangle.h"
#include "..\Figures\CTri.h"
#include "..\Figures\CLine.h"
#include "..\Figures\CRhom.h"
#include "..\Figures\CElipse.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"


class LoadAction: public Action
{
private:
	ifstream* LoadFile;
	string loadFileName;
	char figType;
	CFigure* figTOLoad;

	map<string, color> StringColor = {
		{"RED", RED},
		{"BLUE", BLUE},
		{"GREEN", GREEN},
		{"BLACK", BLACK},
		{"WHITE", WHITE},
		{"NO_FILL", {}}
	};

public:
	LoadAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};
