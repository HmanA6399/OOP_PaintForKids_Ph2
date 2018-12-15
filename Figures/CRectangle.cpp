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

	OutFile << 'R' << '\n'
		<< ID << " "
		<< p1.x << " " << p1.y << " "
		<< p2.x << " " << p2.y << " "
		<< FigGfxInfo.DrawClr.ucRed << " "
		<< FigGfxInfo.DrawClr.ucGreen << " "
		<< FigGfxInfo.DrawClr.ucBlue << " "
		<< FigGfxInfo.FillClr.ucRed << " "
		<< FigGfxInfo.FillClr.ucGreen << " "
		<< FigGfxInfo.FillClr.ucBlue << " "
		<< FigGfxInfo.isFilled << " "
		<< FigGfxInfo.BorderWdth << " "
		<< '\n';

}

void CRectangle::Load(ifstream &Infile)
{
	if (Infile.is_open())
	{
		int a, b, c, d;
		Infile >> a >> b >> c >> d; 
		cout << a << b << c << d;

		/*Infile  >> Corner1.x >> Corner1.y
				>> FigGfxInfo.DrawClr.ucRed
				>> FigGfxInfo.DrawClr.ucGreen
				>> FigGfxInfo.DrawClr.ucBlue
				>> FigGfxInfo.FillClr.ucRed
				>> FigGfxInfo.FillClr.ucGreen
				>> FigGfxInfo.FillClr.ucBlue
				>> FigGfxInfo.isFilled
				>> FigGfxInfo.BorderWdth ;  */
	}
}