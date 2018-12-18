#pragma once
#include<fstream>
#include"Action.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

class SaveTypeAction : public Action
{
	ofstream saveFile;

public:
	SaveTypeAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();
	virtual void Execute();
};