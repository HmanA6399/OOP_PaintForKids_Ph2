#pragma once
#include"CFigure.h"

class CElipse : public CFigure
{
private:
	Point p;
public:
	CElipse(Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;

	bool isin(Point);

	virtual void Save(ofstream &OutFile);
	virtual void Load(ifstream &Infile);
};
