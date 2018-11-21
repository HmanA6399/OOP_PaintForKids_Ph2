#ifndef OUPTUT_H
#define OUPTUT_H
#include "Input.h"

class Output	//The application manager should have a pointer to this class
{
private:
	window* pWind;	//Pointer to the Graphics Window
public:
	Output();

	window* CreateWind(int, int, int, int) const;
	void CreateDrawColorToolBar() const;
	void CreateFillClrToolBar() const;
	//creates the application window
	void CreateDrawToolBar() const;	//creates Draw mode toolbar & menu
	void CreatePlayToolBar() const;	//creates Play mode toolbar & menu
	void CreateStatusBar() const;	//create the status bar

	Input* CreateInput() const; //creates a pointer to the Input object	
	void ClearStatusBar() const;	//Clears the status bar
	void CreateColorToolBar(ActionType A, string& ActStr) const;
	void ClearDrawArea() const;	//Clears the drawing area
	void ClearToolbar() const;
	//void ClearPlayToolbar() const;
	// -- Figures Drawing functions
	void DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected = false) const;  //Draw a rectangle

	///Make similar functions for drawing all other figure types.
	void DrawLine(Point P1, Point P2, GfxInfo LINEGfxInfo, bool selected = false) const;
	void DrawTriangle(Point P1, Point P2, Point p3, GfxInfo TRIGfxInfo, bool selected = false) const;
	void Output::DrawRhombus(Point P, GfxInfo RhombusGfxInfo, bool selected) const;
	void DrawEllipse(Point P1, Point P2, GfxInfo EllipseGfxInfo, bool selected = false) const;



	void PrintMessage(string msg) const;	//Print a message on Status bar

	color getCrntDrawColor() const;	//get current drwawing color
	color getCrntFillColor() const;	//get current filling color
	int getCrntPenWidth() const;		//get current pen width

	~Output();
};

#endif