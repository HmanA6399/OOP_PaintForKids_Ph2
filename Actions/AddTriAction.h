#pragma once
#include"Action.h"
#include "..\Figures\CTri.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

class AddTriAction:public Action
{
	Point p1, p2, p3;
	GfxInfo TriGfxInfo;
public:
	AddTriAction(ApplicationManager*);
	
	void ReadActionParameters();

	void Execute();

	

	bool isin(Point p);
};

