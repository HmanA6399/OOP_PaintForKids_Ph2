#ifndef CFIGURE_H
#define CFIGURE_H
#include<iostream>
#include<fstream>
#include "..\defs.h"
#include "..\GUI\Output.h"
//Base class for all figures
class CFigure
{
protected:
	int ID;		//Each figure has an ID
	bool Selected;	//true if the figure is selected.
	GfxInfo FigGfxInfo;	//Figure graphis info
	/// Add more parameters if needed.
	map<color, string> ColorString = {
	{RED, "RED"},
	{BLUE, "BLUE"},
	{GREEN, "GREEN"},
	{BLACK, "BLACK"},
	{WHITE, "WHITE"},
	{LIGHTGOLDENRODYELLOW, "NO_FILL"},
	{ {}, "NO_FILL"}
	};

	map<string, color> StringColor = {
	{"RED", RED},
	{"BLUE", BLUE},
	{"GREEN", GREEN},
	{"BLACK", BLACK},
	{"WHITE", WHITE},
	{"NO_FILL", LIGHTGOLDENRODYELLOW}
	};

public:
	CFigure(GfxInfo FigureGfxInfo);
	static int figCnt;

	void SetSelected(bool s);	//select/unselect the figure
	bool IsSelected() const;	//check whether fig is selected

	virtual void Draw(Output* pOut) const  = 0 ;		//Draw the figure
	
	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	void ChngFillClr(color Fclr);	//changes the figure's filling color

	virtual bool isin(Point) = 0;
	
	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure

	///Decide the parameters that you should pass to each function	


	virtual void Save(ofstream &OutFile) = 0;	//Save the figure parameters to the file
	virtual void Load(ifstream &Infile) = 0;	//Load the figure parameters to the file

	virtual void PrintInfo(Output* pOut) = 0;	//print all figure info on the status bar
	
	friend ostream& operator<< (ostream& o, const CFigure* f); //TODO :: REMOVE THIS!!

	~CFigure();
};

#endif