#ifndef CRECT_H
#define CRECT_H
#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point p1;	
	Point p2;
public:
	CRectangle(Point , Point, GfxInfo FigureGfxInfo );
	virtual void Draw(Output* pOut) const;

	double GetMaxy(Point, Point);
	double GetMiny(Point, Point);
	double GetMaxx(Point, Point);
	double GetMinx(Point, Point);
	bool isin(Point p);

	virtual void Save(ofstream &OutFile);
	void CRectangle::Load(ifstream &Infile);
	virtual void PrintInfo(Output* pOut);
};

#endif