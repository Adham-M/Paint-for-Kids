#include "Output.h"


Output::Output()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;

	UI.width = 1440;
	UI.height = 750;
	UI.wx = 5;
	UI.wy = 5;

	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 50;
	UI.MenuItemWidth = 75;

	UI.DrawColor = BLUE;	//Drawing color
	UI.FillColor = LIGHTGOLDENRODYELLOW;	//Filling color
	UI.MsgColor = RED;		//Messages color
	UI.BkGrndColor = LIGHTGOLDENRODYELLOW;	//Background color
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = TURQUOISE;
	UI.PenWidth = 3;	//width of the figures frames
	UI.ToolBarLineWidth = 3;	//width of the line under the tool bar

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

void Output::ClearToolBar() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateDrawToolBar() const
{
	UI.InterfaceMode = MODE_DRAW;
	ClearToolBar();
	//You can draw the tool bar icons in any way you want.
	//Below is one possible way

	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[DRAW_ITM_COUNT];

	////////
	MenuItemImages[ITM_RECT] = "images\\MenuItems\\Menu_Rectangle.jpg";
	MenuItemImages[ITM_LINE] = "images\\MenuItems\\Menu_Line.jpg";
	MenuItemImages[ITM_TRI] = "images\\MenuItems\\Menu_Triangle.jpg";
	MenuItemImages[ITM_RHOMBUS] = "images\\MenuItems\\Menu_Rhombus.jpg";
	MenuItemImages[ITM_ELLIPSE] = "images\\MenuItems\\Menu_Ellipse.jpg";

	MenuItemImages[ITM_PALETTE] = "images\\MenuItems\\Menu_Palette.jpg";
	MenuItemImages[ITM_CHNGCLR] = "images\\MenuItems\\Menu_ChangeColor.jpg";
	//MenuItemImages[ITM_CHNGFILLCLR] = "images\\MenuItems\\Menu_ChangeFillingColor.jpg";
	MenuItemImages[ITM_SELECT] = "images\\MenuItems\\Menu_Select.jpg";
	MenuItemImages[ITM_COPY] = "images\\MenuItems\\Menu_Copy.jpg";

	MenuItemImages[ITM_CUT] = "images\\MenuItems\\Menu_Cut.jpg";
	MenuItemImages[ITM_PASTE] = "images\\MenuItems\\Menu_Paste.jpg";
	MenuItemImages[ITM_DELETE] = "images\\MenuItems\\Menu_Delete.jpg";
	//MenuItemImages[ITM_Sound] = "images\\MenuItems\\Menu_Sound.jpg";
	MenuItemImages[ITM_Resize] = "images\\MenuItems\\Menu_Resize.jpg";

	MenuItemImages[ITM_Set2BkOrFrnt] = "images\\MenuItems\\Menu_SetToBackOrFront.jpg";
	MenuItemImages[ITM_SAVE] = "images\\MenuItems\\Menu_Save.jpg";
	MenuItemImages[ITM_SAVEBYTYPE] = "images\\MenuItems\\Menu_SaveByType.jpg";
	MenuItemImages[ITM_LOAD] = "images\\MenuItems\\Menu_Load.jpg";
	MenuItemImages[ITM_PLAYMODE] = "images\\MenuItems\\Menu_PlayMode.jpg";

	MenuItemImages[ITM_EXIT] = "images\\MenuItems\\Menu_Exit.jpg";



	
	//TODO: Prepare images for each menu item and add it to the list

	//Draw menu item one image at a time
	//int f = 1, d = 0;	bool l = true;
	for (int i = 0; i < DRAW_ITM_COUNT; i++)
	//{
		//if ((i + 1)*UI.MenuItemWidth > UI.width)
		//{
		//	pWind->DrawImage(MenuItemImages[i], d, f * UI.ToolBarHeight, UI.MenuItemWidth, UI.ToolBarHeight);
		//	f++;
		//	l = false;
		//}
		//else
		//{
			pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);
	//		d = i * UI.MenuItemWidth;
	//	}
	//}


	//Draw a line under the toolbar
	
	pWind->SetPen(BLUE, UI.ToolBarLineWidth);
	//if (l)
		pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
	//else
	//{
	//	pWind->DrawLine(0, UI.ToolBarHeight, d - 3, UI.ToolBarHeight);
	//	pWind->SetPen(BLUE, UI.ToolBarLineWidth);
	//	pWind->DrawLine(d - 3, UI.ToolBarHeight, d - 3, f * UI.ToolBarHeight);
	//	pWind->SetPen(BLUE, UI.ToolBarLineWidth);
	//	pWind->DrawLine(d - 3, f * UI.ToolBarHeight, UI.width, f * UI.ToolBarHeight);
	//}
	pWind->SetPen(GREEN, UI.ToolBarLineWidth);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width * 2 / 3, UI.ToolBarHeight);
	pWind->SetPen(RED, UI.ToolBarLineWidth);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width / 3, UI.ToolBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::CreatePlayToolBar() const
{
	UI.InterfaceMode = MODE_PLAY;

	////////		
	ClearToolBar();
	string MenuItemImages2[PLAY_ITM_COUNT];

	MenuItemImages2[ITM_FIGURE] = "images\\MenuItems\\ITM_FIGURE.jpg";
	MenuItemImages2[ITM_COLOR] = "images\\MenuItems\\ITM_COLOR.jpg";
	MenuItemImages2[ITM_REST] = "images\\MenuItems\\ITM_REST.jpg";
	MenuItemImages2[ITM_DRAWMODE] = "images\\MenuItems\\ITM_DRAWMODE.jpg";
	MenuItemImages2[ITM_EXIT2] = "images\\MenuItems\\Menu_Exit.jpg";

	//Draw a line under the toolbar
	pWind->SetPen(LIGHTGOLDENRODYELLOW, UI.ToolBarLineWidth);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
	pWind->SetPen(BLUE, UI.ToolBarLineWidth);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.MenuItemWidth*PLAY_ITM_COUNT, UI.ToolBarHeight);
	pWind->SetPen(GREEN, UI.ToolBarLineWidth);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.MenuItemWidth*PLAY_ITM_COUNT * 2 / 3, UI.ToolBarHeight);
	pWind->SetPen(RED, UI.ToolBarLineWidth);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.MenuItemWidth*PLAY_ITM_COUNT / 3, UI.ToolBarHeight);

	for (int i = 0; i < PLAY_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages2[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

	

	///TODO: write code to create Play mode menu
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight + 2, UI.width, UI.height - UI.StatusBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar

	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight / 1.2), msg);
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

	pWind->SetPen(DrawingClr, UI.PenWidth);
	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;

	//To Place the Rectangle in the Drawing Area
	if (P1.y < UI.ToolBarHeight + UI.ToolBarLineWidth)		P1.y = UI.ToolBarHeight + UI.ToolBarLineWidth;
	if (P1.y > UI.height - UI.StatusBarHeight - 1)			P1.y = UI.height - UI.StatusBarHeight - 1;
	if (P2.y < UI.ToolBarHeight + UI.ToolBarLineWidth)		P2.y = UI.ToolBarHeight + UI.ToolBarLineWidth;
	if (P2.y > UI.height - UI.StatusBarHeight - 1)			P2.y = UI.height - UI.StatusBarHeight - 1;
	//

	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);

}

void Output::DrawTri(Point P1, Point P2, Point P3, GfxInfo TRIGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = TRIGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, UI.PenWidth);
	drawstyle style;
	if (TRIGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(TRIGfxInfo.FillClr);
	}
	else
		style = FRAME;

	//To Place the Triangle in the Drawing Area
	if (P1.y < UI.ToolBarHeight + UI.ToolBarLineWidth)		P1.y = UI.ToolBarHeight + UI.ToolBarLineWidth;
	if (P1.y > UI.height - UI.StatusBarHeight - 1)			P1.y = UI.height - UI.StatusBarHeight - 1;
	if (P2.y < UI.ToolBarHeight + UI.ToolBarLineWidth)		P2.y = UI.ToolBarHeight + UI.ToolBarLineWidth;
	if (P2.y > UI.height - UI.StatusBarHeight - 1)			P2.y = UI.height - UI.StatusBarHeight - 1;
	if (P3.y < UI.ToolBarHeight + UI.ToolBarLineWidth)		P3.y = UI.ToolBarHeight + UI.ToolBarLineWidth;
	if (P3.y > UI.height - UI.StatusBarHeight - 1)			P3.y = UI.height - UI.StatusBarHeight - 1;
	//

	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, style);
}

void Output::DrawLine(Point P1, Point P2, GfxInfo LINEGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = LINEGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, UI.PenWidth);
	drawstyle style;
	style = FRAME;

	//To Place the Line in the Drawing Area
	if (P1.y < UI.ToolBarHeight + UI.ToolBarLineWidth)		P1.y = UI.ToolBarHeight + UI.ToolBarLineWidth;
	if (P1.y > UI.height - UI.StatusBarHeight - 1)			P1.y = UI.height - UI.StatusBarHeight - 1;
	if (P2.y < UI.ToolBarHeight + UI.ToolBarLineWidth)		P2.y = UI.ToolBarHeight + UI.ToolBarLineWidth;
	if (P2.y > UI.height - UI.StatusBarHeight - 1)			P2.y = UI.height - UI.StatusBarHeight - 1;
	//

	pWind->DrawLine(P1.x, P1.y, P2.x, P2.y, style);
}

void Output::DrawRhomb(Point P1, int xx, int yy, GfxInfo RHOMBGfxInfo, bool selected) const
{
	int *PPx = new int[4];
	int *PPy = new int[4];
	color DrawingClr;

	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RHOMBGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, UI.PenWidth);
	drawstyle style;
	style = FRAME;

	if (RHOMBGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RHOMBGfxInfo.FillClr);
	}
	else
		style = FRAME;

	//To Place the Rhombus in the Drawing Area
	if (P1.y < UI.ToolBarHeight + yy + UI.ToolBarLineWidth)		P1.y = UI.ToolBarHeight + yy + UI.ToolBarLineWidth;
	if (P1.y > UI.height - UI.StatusBarHeight - yy - 1)			P1.y = UI.height - UI.StatusBarHeight - yy - 1;
	if (P1.x < xx)												P1.x = xx;
	if (P1.x > UI.width - xx - 15)								P1.x = UI.width - xx - 15;
	//

	PPx[0] = P1.x;			PPy[0] = P1.y + yy;
	PPx[1] = P1.x + xx;		PPy[1] = P1.y;
	PPx[2] = P1.x;			PPy[2] = P1.y - yy;
	PPx[3] = P1.x - xx;		PPy[3] = P1.y;

	pWind->DrawPolygon(PPx, PPy, 4, style);

	delete[] PPx;
	delete[] PPy;
}

void Output::DrawEllip(Point P1, int xx, int yy, GfxInfo ELLIPfxInfo, bool selected) const
{
	int PEx1, PEx2, PEy1, PEy2;
	color DrawingClr;

	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = ELLIPfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, UI.PenWidth);
	drawstyle style;
	if (ELLIPfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(ELLIPfxInfo.FillClr);
	}
	else
		style = FRAME;


	//To Place the Ellipse in the Drawing Area
	if (P1.y < UI.ToolBarHeight + yy + UI.ToolBarLineWidth)		P1.y = UI.ToolBarHeight + yy + UI.ToolBarLineWidth;
	if (P1.y > UI.height - UI.StatusBarHeight - yy - 1)			P1.y = UI.height - UI.StatusBarHeight - yy - 1;
	if (P1.x < xx)												P1.x = xx;
	if (P1.x > UI.width - xx - 15)								P1.x = UI.width - xx - 15;
	//

	PEx1 = P1.x + xx;
	PEx2 = P1.x - xx;
	PEy1 = P1.y + yy;
	PEy2 = P1.y - yy;

	pWind->DrawEllipse(PEx1, PEy1, PEx2, PEy2, style);
}

//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}