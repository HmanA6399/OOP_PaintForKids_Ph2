#ifndef SSAVE_ACTION_H
#define SSAVE_ACTION_H

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
    public:

	SaveAction(ApplicationManager *pApp);

	virtual void ReadActionParameters();

	virtual void Execute();
};
#endif