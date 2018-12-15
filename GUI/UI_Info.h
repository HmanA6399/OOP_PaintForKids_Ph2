#ifndef UI_INFO_H
#define UI_INFO_H

#include "..\CMUgraphicsLib\CMUgraphics.h"

//User Interface information file.
//This file contains info that is needed by Input and Output classes to
//handle the user interface

enum GUI_MODE	//Graphical user interface mode
{
	MODE_DRAW,	//Drawing mode (startup mode)
	MODE_PLAY,	//Playing mode
	MODE_DRAW_COLOR,
	MODE_FILL_COLOR,
	MODE_COLOR
};

enum DrawMenuItem //The items of the Draw menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here
	ITM_SELECT,
	//Figures
	ITM_LINE,
	ITM_RECT,
	ITM_TRI,
	ITM_RHOM,
	ITM_ELLIPSE,
	//Color Controls
	ITM_CHNG_DRW_CLR,
	ITM_CHNG_FILL_CLR,
	//Other Controls
	ITM_COPY,
	ITM_CUT,
	ITM_PASTE,
	ITM_DELETE,
	ITM_SAVE,
	ITM_SAVETYPE,
	ITM_LOAD,
	ITM_SWTOPLAY,
	ITM_EXIT,		//Exit item

	//Play Mode Items
	DRAW_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum
};

enum PlayMenuItem //The items of the Play menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here

	//TODO: Add more items names here
	ITM_PICKTYPE,
	ITM_PICKCOLOR,
	ITM_SWTODRAW,

	PLAY_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum

};

enum ColorMenuItems //The items of the Draw/Fill Color menu
{
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here

	ITM_RED,
	ITM_BLUE,
	ITM_GREEN,
	ITM_BLACK,
	ITM_WHITE,
	ITM_PAINT,

	COLOR_ITM_COUNT ////no. of menu items ==> This should be the last line in this enum

};

enum TypeMenuItems //The items of the Type menu
{
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here

	ITM_REC_TYP,
	ITM_LINE_TYP,
	ITM_ELIP_TYP,
	ITM_TRI_TYP,
	ITM_RHOM_TYP,

	TYPE_ITM_COUNT ////no. of menu items ==> This should be the last line in this enum

};

__declspec(selectany) //This line to prevent "redefinition error"

struct UI_Info	//User Interface Info.
{
	GUI_MODE InterfaceMode;

	int	width, height,	    //Window width and height
		wx, wy,			//Window starting coordinates
		StatusBarHeight,	//Status Bar Height
		ToolBarHeight,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		MenuItemWidth;		//Width of each item in toolbar menu


	color DrawColor;		//Drawing color
	color FillColor;		//Filling color
	color HighlightColor;	//Highlighting color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Background color
	color StatusBarColor;	//Status bar color
	int PenWidth;			//width of the pen that draws shapes

	/// Add more members if needed

}UI;	//create a global object UI

#endif
