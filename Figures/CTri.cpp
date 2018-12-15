#include "CTri.h"

CTri::CTri(Point P1, Point P2,Point P3, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	p1 = P1;
	p2 = P2;
	p3 = P3;
}

void CTri::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawTriangle(p1, p2,p3, FigGfxInfo, Selected);
}

//Fns for selection
double CTri::TriArea(Point P1, Point P2, Point P3) {
	return fabs(P1.x*(P2.y - P3.y) - P2.x*(P1.y - P3.y) + P3.x*(P1.y - P2.y));
}

bool CTri::isin(Point p) {
	if (TriArea(p1, p2, p3) == TriArea(p, p2, p3) + TriArea(p1, p, p3) + TriArea(p1, p2, p))
		return true;
		return false;
}

//Save & Load
void CTri::Save(ofstream &OutFile)
{
	OutFile << 'T' << '\n'
		<< ID << " "
		<< p1.x << " " << p1.y << " "
		<< p2.x << " " << p2.y << " "
		<< p3.x << " " << p3.y << " "
		<< FigGfxInfo.DrawClr.ucRed << " "
		<< FigGfxInfo.DrawClr.ucGreen << " "
		<< FigGfxInfo.DrawClr.ucBlue << " "
		<< FigGfxInfo.FillClr.ucRed << " "
		<< FigGfxInfo.FillClr.ucGreen << " "
		<< FigGfxInfo.FillClr.ucBlue << " "
		<< FigGfxInfo.isFilled << " "
		<< FigGfxInfo.BorderWdth
		<< '\n';
}

void CTri::Load(ifstream &Infile)
{
	Infile.open("sv.figu");
}