#pragma once
#include<fstream>
#include"Action.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

class SaveTypeAction : public Action
{
	ofstream saveFile;
	enum figure {
		REC,
		LINE,
		ELIPSE,
		TRI,
		RHOM
	};

public:
	SaveTypeAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();
	virtual void Execute();
};