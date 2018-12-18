#pragma once
#include"Action.h"
#include"../Figures/CFigure.h"
#include "../ApplicationManager.h"
#include "../GUI\input.h"
#include "../GUI\Output.h"

class SelectAction:public Action
{
	Point p;
	CFigure*a;
public:
	SelectAction(ApplicationManager*);
	void ReadActionParameters();

	void Execute();
};
