#pragma once
#include <fstream>
#include "Action.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
class CFigure;

class SaveAction: public Action
{
	private:
		ofstream saveFile;
		string fileName;

		map<color, string> ColorString = {
			{RED, "RED"},
			{BLUE, "BLUE"},
			{GREEN, "GREEN"},
			{BLACK, "BLACK"},
			{WHITE, "WHITE"},
			{LIGHTGOLDENRODYELLOW, "NO_FILL"},
			{ {}, "NO_FILL"}
		};

    public:

	SaveAction(ApplicationManager *pApp);

	virtual void ReadActionParameters();

	virtual void Execute();
};