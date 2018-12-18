#include "CElipse.h"

CElipse::CElipse(Point P1,  GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	p = P1;
}


void CElipse::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawEllipse(p, FigGfxInfo, Selected);
}

bool CElipse::isin(Point P)
{
	//Substitute the point in the ellipse fn which is x^2/a^2 + y^2/b^2 = 1
	double t1 = ((P.x - p.x) * (P.x - p.x)) / (100 * 100); 
	double t2 = ((P.y - p.y, 2) * (P.y - p.y, 2)) / (50 * 50);
	double f =t1 + t2;

	//The point lies on or inside the function for f <= 1
	if (f <= 1) return true;
	return false;
}

void CElipse::Save(ofstream &OutFile)
{
	OutFile << "E "
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

void CElipse::Load(ifstream &InFile)
{
	// Read data from file and update object properties
	// data are : ID, P.x, p.y, DrawClr, FillClr, BorderWdth
	InFile >> this->ID >> this->p.x >> this->p.y;
	string dCol, fCol;
	InFile >> dCol >> fCol;
	this->FigGfxInfo.DrawClr = StringColor[dCol]; //A map that maps each string to the corresponding color
	this->FigGfxInfo.FillClr = StringColor[fCol];
	this->FigGfxInfo.isFilled = (fCol == "NO_FILL");
	InFile >> this->FigGfxInfo.BorderWdth;

}
void CElipse::PrintInfo(Output* pOut)
{
	//Prints main info of a figure
	string InfoString = "ID : " + to_string(ID) + " , Point of Center : (" + to_string(p.x) + "," + to_string(p.y) + ")";
	pOut->PrintMessage(InfoString);
}
