#ifndef LOAD_ACTION_H
#define LOAD_ACTION_H

#include <iostream>
#include <fstream>
#include "Action.h"
#include "..\Figures\CRectangle.h"
#include "..\Figures\CTri.h"
#include "..\Figures\CLine.h"
#include "..\Figures\CRhom.h"
#include "..\Figures\CElipse.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

class CFigure;

class LoadAction: public Action
{
private:
	ifstream* LoadFile;
    
public:
	LoadAction(ApplicationManager *pApp,ifstream& LF );
	virtual void ReadActionParameters();
	virtual void Execute();
};
#endif