#include "CRectangle.h"

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	p1 = P1;
	p2 = P2;
}
	
void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(p1, p2, FigGfxInfo, Selected);
}

//Functions for selection
double CRectangle::GetMaxy(Point P1, Point P2) {
	if (P1.y >= P2.y) return P1.y;
	return P2.y;
}

double CRectangle::GetMiny(Point P1, Point P2) {
	if (P1.y >= P2.y) return P2.y;
	return P1.y;
}

double CRectangle::GetMaxx(Point P1, Point P2) {
	if (P1.y >= P2.y) return P1.x;
	return P2.x;
}

double CRectangle::GetMinx(Point P1, Point P2) {
	if (P1.x >= P2.x) return P2.x;
	return P1.x;
}

bool CRectangle::isin(Point p) {
	if (p.x >= GetMinx(p1, p2) && p.x < GetMaxx(p1, p2) && p.y >= GetMiny(p1, p2) && p.y < GetMaxy(p1, p2))
		return true;
	return false;
}

//Save & Load
void CRectangle::Save(ofstream &OutFile)
{

	OutFile << "R "
		<< ID << " "
		<< p1.x << " " << p1.y << " "
		<< p2.x << " " << p2.y << " "
/*
		<< FigGf-xInfo.DrawClr.ucRed << " "
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

void CRectangle::Load(ifstream &InFile)
{
	// Read data from file and update object properties
	// data are : ID, P1.x, p1.y, p2.x, p2.y, DrawClr, FillClr, BorderWdth
	InFile >> this->ID >> this->p1.x >> this->p1.y >> this->p2.x >> this->p2.y;
	string dCol, fCol;
	InFile >> dCol >> fCol;
	this->FigGfxInfo.DrawClr = StringColor[dCol]; //A map defined in DEFS.h that maps each string to the corresponding color
	this->FigGfxInfo.FillClr = StringColor[fCol];
	this->FigGfxInfo.isFilled = (fCol == "NO_FILL");
	InFile >> this->FigGfxInfo.BorderWdth;
}
void CRectangle::PrintInfo(Output* pOut)
{
	//Prints main info of a figure
	string InfoString = "ID : " + to_string(ID) + " , Corner1 : (" + to_string(p1.x) + "," + to_string(p1.y) + " ) " + " , Corner2 : (" + to_string(p2.x) + "," + to_string(p2.y) + ")";
	pOut->PrintMessage(InfoString);
}