#pragma once
#include"Action.h"
#include"../Figures/CElipse.h"
#include"../ApplicationManager.h"
#include"../GUI\input.h"
#include"../GUI\Output.h"

class AddElipseAction:public Action
{
	Point p1;
	GfxInfo ElipseGfxInfo;
public:
	AddElipseAction(ApplicationManager*);
	
	void ReadActionParameters();

	void Execute();

	
};

