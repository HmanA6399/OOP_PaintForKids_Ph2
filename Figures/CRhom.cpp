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
	OutFile << "H "
		<< ID << " "
		<< p.x << " " << p.y << " "
/*
		<< FigGfxInfo.DrawClr.ucRed << " "
		<< FigGfxInfo.DrawClr.ucGreen << " "
		<< FigGfxInfo.DrawClr.ucBlue << " "
		<< FigGfxInfo.FillClr.ucRed << " "
		<< FigGfxInfo.FillClr.ucGreen << " "
		<< FigGfxInfo.FillClr.ucBlue << " "
*/
		<< ColorString[(color)FigGfxInfo.DrawClr] << " "
		<< (FigGfxInfo.isFilled ? ColorString[(color)FigGfxInfo.FillClr] : "NO_FILL") << " "
		<< FigGfxInfo.BorderWdth
		<< '\n';
}

void CRhom::Load(ifstream &InFile)
{
	// Read data from file and update object properties
	// data are : ID, P.x, p.y, DrawClr, FillClr, BorderWdth
	InFile >> this->ID >> this->p.x >> this->p.y;
	string dCol, fCol;
	InFile >> dCol >> fCol;
	this->FigGfxInfo.DrawClr = StringColor[dCol]; //A map defined in DEFS.h that maps each string to the corresponding color
	this->FigGfxInfo.FillClr = StringColor[fCol];
	this->FigGfxInfo.isFilled = (fCol == "NO_FILL");
	InFile >> this->FigGfxInfo.BorderWdth;
}

void CRhom::PrintInfo(Output* pOut)
{
	//Prints main info of a figure
	string InfoString = "ID : " + to_string(ID) + " , Point of Center : (" + to_string(p.x) + "," + to_string(p.y) + ")";
	pOut->PrintMessage(InfoString);
}
