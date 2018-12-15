#pragma once
#include"Action.h"
#include "..\Figures\CRhom.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

class AddRhomAction:public Action
{
private:
	Point p1;
	GfxInfo RhomGfxInfo;
public:
	AddRhomAction(ApplicationManager*);

	void ReadActionParameters();

	void Execute();

	
};

