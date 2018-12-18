#ifndef DEFS_H
#define DEFS_H

#include<map>
#include "CMUgraphicsLib\CMUgraphics.h"

//This file contains some global constants and definitions to be used in the project.
enum ActionType //The actions supported (you can add more if needed)
{
	SELECT,
	DRAW_LINE,		//Draw Line
	DRAW_RECT,		//Draw Rectangle
	DRAW_TRI,		//Draw Triangle
	DRAW_RHOMBUS,		//Draw Rhombus
	DRAW_ELLIPSE,		//Draw Ellipse
	CHNG_DRAW_CLR,	//Change the drawing color
	CHNG_FILL_CLR,	//Change the filling color
	COPY,
	CUT,
	PASTE,
	DEL,			//Delete a figure(s)
	SAVE,			//Save the whole graph to a file
	SAVE_BY_TYPE,	//Save the all the figures that have a specific type
	LOAD,			//Load a graph from a file
	TO_PLAY,		//Switch interface to Play mode
	EXIT,			//Exit the application

	DRAWING_AREA,	//A click on the drawing area
	STATUS,			//A click on the status bar
	EMPTY,			//A click on empty place in the toolbar


	//Play Mode Actions
	//cases of Pick n Hide
	PICK_BY_TYPE,
	PICK_BY_COLOR,
	TO_DRAW,		//Switch interface to Draw mode

	//Color Actions
	RED_ACT,
	BLUE_ACT,
	GREEN_ACT,
	BLACK_ACT,
	WHITE_ACT,
	PAINT
};

struct Point	//To be used for figures points
{
	int x, y;
};

struct GfxInfo	//Graphical info of each figure (you may add more members)
{
	color DrawClr;	//Draw color of the figure
	color FillClr;	//Fill color of the figure
	bool isFilled;	//Figure Filled or not
	int BorderWdth;	//Width of figure borders
};

#endif