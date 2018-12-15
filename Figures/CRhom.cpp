#include "CRhom.h"

CRhom::CRhom(Point P, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	p = P;
}

void CRhom::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRhombus(p,FigGfxInfo, Selected);
}

//Fns for selection
bool CRhom::isin(Point p0) {
	if ((p0.x >= p.x - 50) && (p0.x <= p.x + 50) && (p0.y >= p.y - 75) && (p0.y <= p.y + 75))
		return true;
	return false;
}

//Save & Load
void CRhom::Save(ofstream &OutFile)
{
	OutFile << 'H' << '\n'
		<< ID << " "
		<< p.x << " " << p.y << " "
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

void CRhom::Load(ifstream &Infile)
{
	Infile.open("sv.figu");
}