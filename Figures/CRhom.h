#pragma once
#include"CFigure.h"

class CRhom : public CFigure
{
private:
	Point p;
	
public:
	CRhom( Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	bool isin(Point);

	virtual void Save(ofstream &OutFile);
	virtual void Load(ifstream &Infile);
	virtual void PrintInfo(Output* pOut);
};
