#include"Action.h"
#include "../Figures/CLine.h"
#include "../ApplicationManager.h"
#include "../GUI\input.h"
#include "../GUI\Output.h"

class AddLineAction:public Action
{
private:
	Point p1, p2;
	GfxInfo LineGfxInfo;
public:
	AddLineAction(ApplicationManager*);

	virtual void ReadActionParameters();

	virtual void Execute();

	
};
