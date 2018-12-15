#include "CLine.h"

CLine::CLine(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	p1= P1;
	p2 = P2;
}

void CLine::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawLine(p1, p2, FigGfxInfo, Selected);
}

//Fns for selection
double CLine::GetDim(Point P1, Point P2) {
	if ((P1.x - P2.x) == 0) return -1;
	double k = P1.x - P2.x;
	double h = P1.y - P2.y;
	return int(sqrt(h*h + k * k));
}

bool CLine::isin(Point p) {
	if (GetDim(p1,p2)==GetDim(p1,p)+GetDim(p,p2))
		return true;
	return false;
}

//Save & Load

void CLine::Save(ofstream &OutFile)
{
	OutFile << 'L' << '\n'
		<< ID << " "
		<< p1.x << " " << p1.y << " "
		<< p2.x << " " << p2.y << " "
		<< FigGfxInfo.DrawClr.ucRed << " "
		<< FigGfxInfo.DrawClr.ucGreen << " "
		<< FigGfxInfo.DrawClr.ucBlue << " "
		<< FigGfxInfo.FillClr.ucRed << " "
		<< FigGfxInfo.FillClr.ucGreen << " "
		<< FigGfxInfo.FillClr.ucBlue << " "
		<< FigGfxInfo.isFilled
		<< FigGfxInfo.BorderWdth
		<< '\n';
}
void CLine::Load(ifstream &Infile)
{

	Infile >> p1.x >> p1.y
		>> p2.x >> p2.y
		>> FigGfxInfo.DrawClr.ucRed
		>> FigGfxInfo.DrawClr.ucGreen
		>> FigGfxInfo.DrawClr.ucBlue
		>> FigGfxInfo.FillClr.ucRed
		>> FigGfxInfo.FillClr.ucGreen
		>> FigGfxInfo.FillClr.ucBlue
		>> FigGfxInfo.isFilled
		>> FigGfxInfo.BorderWdth;
}