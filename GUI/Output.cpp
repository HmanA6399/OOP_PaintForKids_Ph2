#include "Output.h"

Output::Output()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;

	UI.width = 1250;
	UI.height = 650;
	UI.wx = 5;
	UI.wy = 5;


	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 60;
	UI.MenuItemWidth = 70;

	UI.DrawColor = BLUE;	//Drawing color
	UI.FillColor = GREEN;	//Filling color
	UI.MsgColor = RED;		//Messages color
	UI.BkGrndColor = LIGHTGOLDENRODYELLOW;	//Background color
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = TURQUOISE;
	UI.PenWidth = 5;	//width of the figures frames


	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project");

	CreateDrawToolBar();
	CreateStatusBar();
}

Input* Output::CreateInput() const
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int w, int h, int x, int y) const
{
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
/*void Output::CreateFillClrToolBar()const
{
	UI.InterfaceMode = MODE_FILL_COLOR;

	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);
	pWind->SetPen(RED, 3);


	string MenuItemImages[COLOR_ITM_COUNT];
	MenuItemImages[ITM_RED] = "images\\MenuItems\\RED.jpg";
	MenuItemImages[ITM_Blue] = "images\\MenuItems\\Blue.jpg";
	MenuItemImages[ITM_Green] = "images\\MenuItems\\Green.jpg";
	MenuItemImages[ITM_Black] = "images\\MenuItems\\Black.jpg";
	MenuItemImages[ITM_White] = "images\\MenuItems\\White.jpg";
	MenuItemImages[ITM_Paint] = "images\\MenuItems\\Paint.jpg";

	for (int i = 0; i < COLOR_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
}*/
void Output::CreateDrawToolBar() const
{
	UI.InterfaceMode = MODE_DRAW;

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way

	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[DRAW_ITM_COUNT];
	/////////////////////////////////////////////////////////
	MenuItemImages[ITM_SELECT] = "images\\MenuItems\\Menu_Select.jpg";
	MenuItemImages[ITM_LINE] = "images\\MenuItems\\Menu_line1.jpg";
	MenuItemImages[ITM_RECT] = "images\\MenuItems\\Menu_Rect.jpg";
	MenuItemImages[ITM_TRI] = "images\\MenuItems\\Menu_Triangle.jpg";
	MenuItemImages[ITM_RHOM] = "images\\MenuItems\\Menu_Rohmbus.jpg";
	MenuItemImages[ITM_ELLIPSE] = "images\\MenuItems\\Menu_Circ.jpg";
	MenuItemImages[ITM_CHNG_DRW_CLR] = "images\\MenuItems\\Menu_Draw_Color.jpg";
	MenuItemImages[ITM_CHNG_FILL_CLR] = "images\\MenuItems\\Menu_Fill_Color.jpg";
	MenuItemImages[ITM_COPY] = "images\\MenuItems\\Menu_Copy.jpg";
	MenuItemImages[ITM_CUT] = "images\\MenuItems\\Menu_CUT.jpg";
	MenuItemImages[ITM_PASTE] = "images\\MenuItems\\Menu_Paste.jpg";
	MenuItemImages[ITM_DELETE] = "images\\MenuItems\\Menu_Delete.jpg";
	MenuItemImages[ITM_SAVE] = "images\\MenuItems\\Menu_save.jpg";
	MenuItemImages[ITM_SAVETYPE] = "images\\MenuItems\\Menu_savetype.jpg";
	MenuItemImages[ITM_LOAD] = "images\\MenuItems\\Menu_Load.jpg";
	MenuItemImages[ITM_SWTOPLAY] = "images\\MenuItems\\Menu_Play.jpg";
	MenuItemImages[ITM_EXIT] = "images\\MenuItems\\Menu_Exit.jpg";

	//Draw menu item one image at a time
	for (int i = 0; i < DRAW_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreatePlayToolBar() const
{
	UI.InterfaceMode = MODE_PLAY;
	///TODO: write code to create Play mode menu
	string MenuItemImages[PLAY_ITM_COUNT];
	///////////////////////////////////////////////////////////
	////TODO ::: ADD PLAY MODE MENU IMAGES //////////////////////
	/////////////////////////////////////////////////////////////
	MenuItemImages[ITM_PICKCOLOR] = "images\\MenuItems\\Pick_By_Color.jpg";
	MenuItemImages[ITM_PICKTYPE] = "images\\MenuItems\\Pick_By_Type.jpg";
	MenuItemImages[ITM_SWTODRAW] = "images\\MenuItems\\To_Draw_2.jpg";
	//	MenuItemImages[ITM_circ1] = "images\\MenuItems\\Menu_circ.jpg";


	for (int i = 0; i < PLAY_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);
	////////////////////////////////////////////////////////////

		//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateColorToolBar(ActionType A, string& ActStr) const
{
	UI.InterfaceMode = MODE_COLOR;

	//Determining what action to do with the color, whether draw or fill

	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);
	pWind->SetPen(RED, 3);


	string MenuItemImages[COLOR_ITM_COUNT];
	MenuItemImages[ITM_RED] = "images\\MenuItems\\RED.jpg";
	MenuItemImages[ITM_BLUE] = "images\\MenuItems\\Blue.jpg";
	MenuItemImages[ITM_GREEN] = "images\\MenuItems\\Green.jpg";
	MenuItemImages[ITM_BLACK] = "images\\MenuItems\\Black.jpg";
	MenuItemImages[ITM_WHITE] = "images\\MenuItems\\White.jpg";
	//The icon of applying the chosen color depends on if it's fill or draw color
	if (A == CHNG_DRAW_CLR) {
		MenuItemImages[ITM_PAINT] = "images\\MenuItems\\Menu_Draw_Color.jpg";
		ActStr = "Draw";
	}
	else if (A == CHNG_FILL_CLR) {
		MenuItemImages[ITM_PAINT] = "images\\MenuItems\\Menu_Fill_Color.jpg";
		ActStr = "Fill";
	}
	else {
		MenuItemImages[ITM_PAINT] = "images\\MenuItems\\Menu_Draw_Color.jpg";
		ActStr = "";
	}

	for (int i = 0; i < COLOR_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearToolbar() const
{
	pWind->SetPen(WHITE, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar

	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight / 1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////
color Output::getCrntDrawColor() const	//get current drawing color
{
	return UI.DrawColor;
}
//////////////////////////////////////////////////////////////////////////////////////////
color Output::getCrntFillColor() const	//get current filling color
{
	return UI.FillColor;
}
//////////////////////////////////////////////////////////////////////////////////////////
int Output::getCrntPenWidth() const		//get current pen width
{
	return UI.PenWidth;
}

//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

void Output::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);

}

void Output::DrawLine(Point P1, Point P2, GfxInfo LINEGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = LINEGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	style = FRAME;
	pWind->DrawLine(P1.x, P1.y, P2.x, P2.y, style);
}

void Output::DrawTriangle(Point P1, Point P2, Point P3, GfxInfo TRIGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = TRIGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (TRIGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(TRIGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, style);

}

void Output::DrawRhombus(Point P, GfxInfo RhombusGfxInfo, bool selected) const
{
	if (P.y < 160)
	{
		P.y = 135;
	}
	else if (P.y > 500)
	{
		P.y = 524;
	}
	if (P.x < 100)
	{
		P.x = 50;
	}
	else if (P.x > 1150)
	{
		P.x = 1185;
	}

	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RhombusGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (RhombusGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RhombusGfxInfo.FillClr);
	}
	else
		style = FRAME;
	Point p1, p2, p3, p4;
	p1.x = P.x + 50;  p1.y = P.y;
	p2.x = P.x - 50;  p2.y = P.y;
	p3.x = P.x;     p3.y = P.y + 75;
	p4.x = P.x;     p4.y = P.y - 75;

	const int A[4] = { p1.x , p3.x , p2.x , p4.x };
	const int B[4] = { p1.y , p3.y , p2.y , p4.y };
	pWind->DrawPolygon(A, B, 4, style);
}

void Output::DrawEllipse(Point P1, GfxInfo EllipseGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = EllipseGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (EllipseGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(EllipseGfxInfo.FillClr);
	}
	else
		style = FRAME;
	pWind->DrawEllipse(P1.x - 100, P1.y - 50, P1.x + 100, P1.y + 50, style);
}

//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}

