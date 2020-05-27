#ifndef OUPTUT_H
#define OUPTUT_H
#include "Input.h"

class Output	//The application manager should have a pointer to this class
{
private:
	window* pWind;	//Pointer to the Graphics Window
public:
	Output();

	window* CreateWind(int, int, int, int) const; //creates the application window
	void CreateDrawToolBar() const;	//creates Draw mode toolbar & menu
	void CreatePlayToolBar() const;	//creates Play mode toolbar & menu
	void CreateStatusBar() const;	//create the status bar

	Input* CreateInput() const;		//Creates a pointer to the Input object	
	void ClearStatusBar() const;	//Clears the status bar
	void ClearDrawArea() const;		//Clears the drawing area
	void ClearToolBar() const;		//Clears the Tool Bar

	// -- Figures Drawing functions
	void DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected = false) const;  //Draw a rectangle
	void DrawTri(Point P1, Point P2, Point P3, GfxInfo TRIGfxInfo, bool selected = false) const;
	void DrawLine(Point P1, Point P2, GfxInfo LINEGfxInfo, bool selected = false) const;
	void DrawRhomb(Point P1, int xx, int yy, GfxInfo RHOMBGfxInfo, bool selected) const;
	void DrawEllip(Point P1, int xx, int yy, GfxInfo ELLIPfxInfo, bool selected) const;
	


	void PrintMessage(string msg) const;	//Print a message on Status bar

	color getCrntDrawColor() const;	//get current drwawing color
	color getCrntFillColor() const;	//get current filling color
	int getCrntPenWidth() const;	//get current pen width


	~Output();
};

#endif