#pragma once
#include"CFigure.h"

class CTri : public CFigure
{
private:
	Point p1;
	Point p2;
	Point p3;
public:
	CTri(Point,Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;

	double TriArea(Point, Point, Point);
	bool isin(Point );

	virtual void Save(ofstream &OutFile);
	virtual void Load(ifstream &Infile);
	virtual void PrintInfo(Output* pOut);
};

