#ifndef CFIGURE_H
#define CFIGURE_H

#include "..\defs.h"
#include "..\GUI\Output.h"
#include <fstream>

//Base class for all figures
class CFigure
{
protected:
	int ID;		//Each figure has an ID
	bool Selected;	//true if the figure is selected.
	GfxInfo FigGfxInfo;	//Figure graphis info
	static int sID;
	/// Add more parameters if needed.

public:
	CFigure(GfxInfo FigureGfxInfo);
	CFigure() {};

	void SetSelected(bool s);	//select/unselect the figure
	bool IsSelected() const;	//check whether fig is selected
	int GetID() const;		//gets the ID
	string GetDrawColor() const;
	string GetFillColor() const;
	GfxInfo GetGfxInfo() const;

	/*void SaveFigData();
	void RestoreFigdata();*/

	void virtual Draw(Output* pOut) const  = 0 ;		//Draw the figure
	void virtual Copy(CFigure*&, GfxInfo, Point p) = 0;
	bool virtual Pointinorout(int a, int b) = 0;
	virtual Point getCenter()=0;
	void virtual PrintInfo(Output* pOut) const = 0 ;
	string virtual GetType() const = 0;
	void virtual Resize(float) = 0;
	void SetGfx(GfxInfo);
	GfxInfo getGfx(string, string);
	color getColorObject(string name)const;

	//void virtual Paste (CFigure*&c) = 0;
	
	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	void ChngFillClr(color Fclr);	//changes the figure's filling color

	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure

	///Decide the parameters that you should pass to each function	


	virtual void Save(ofstream &OutFile) = 0;	//Save the figure parameters to the file

	//virtual void PrintInfo(Output* pOut) = 0;	//print all figure info on the status bar
};

#endif