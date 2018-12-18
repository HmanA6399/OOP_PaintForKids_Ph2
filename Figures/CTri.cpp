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
	OutFile << "T "
		<< ID << " "
		<< p1.x << " " << p1.y << " "
		<< p2.x << " " << p2.y << " "
		<< p3.x << " " << p3.y << " "
/*
		<< FigGfxInfo.DrawClr.ucRed << " "
		<< FigGfxInfo.DrawClr.ucGreen << " "
		<< FigGfxInfo.DrawClr.ucBlue << " "
		<< FigGfxInfo.FillClr.ucRed << " "
		<< FigGfxInfo.FillClr.ucGreen << " "
		<< FigGfxInfo.FillClr.ucBlue << " "
*/
		<< ColorString[FigGfxInfo.DrawClr] << " "
		<< (FigGfxInfo.isFilled ? ColorString[FigGfxInfo.FillClr] : "NO_FILL") << " "
		<< FigGfxInfo.BorderWdth
		<< '\n';
}

void CTri::Load(ifstream &InFile)
{
	// Read data from file and update object properties
	// data are : ID, P1.x, p1.y, p2.x, p2.y, p3.x, p3.y, DrawClr, FillClr, BorderWdth
	InFile >> this->ID >> this->p1.x >> this->p1.y >> this->p2.x >> this->p2.y >> this->p3.x >> this->p3.y;
	string dCol, fCol;
	InFile >> dCol >> fCol;
	cout << dCol << " " << fCol << '\n';
	this->FigGfxInfo.DrawClr = StringColor[dCol]; //A map defined in DEFS.h that maps each string to the corresponding color
	this->FigGfxInfo.FillClr = StringColor[fCol];
	this->FigGfxInfo.isFilled = (fCol == "NO_FILL");
	InFile >> this->FigGfxInfo.BorderWdth;
}

void CTri::PrintInfo(Output* pOut)
{
	//Prints main info of a figure
	string InfoString = "ID : " + to_string(ID) + " , Corner1 : (" + to_string(p1.x) + "," + to_string(p1.y) + " ) " + " , Corner2 : (" + to_string(p2.x) + "," + to_string(p2.y) + " )" + " , Corner3 : (" + to_string(p3.x) + "," + to_string(p3.y) + ")";
	pOut->PrintMessage(InfoString);
}
