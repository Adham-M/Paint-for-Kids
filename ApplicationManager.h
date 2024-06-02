#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures/CFigure.h"
#include "GUI/input.h"

#include "Actions/Action.h"

#include "Figures/CLine.h"
#include "Figures/CRectangle.h"
#include "Figures/CTriangle.h"
#include "Figures/CEllipse.h"
#include "Figures/CRhombus.h"

#include "Actions/Add Figure/AddRectAction.h"
#include "Actions/Add Figure/AddLineAction.h"
#include "Actions/Add Figure/AddTriAction.h"
#include "Actions/Add Figure/AddRhombAction.h"
#include "Actions/Add Figure/AddEllipAction.h"

#include "Actions/Draw Mode/SelectAction.h"
#include "Actions/Draw Mode/ChangeFColorAction.h"
#include "Actions/Draw Mode/ChangeDColorAction.h"
#include "Actions/Draw Mode/CopyAction.h"
#include "Actions/Draw Mode/PasteAction.h"
#include "Actions/Draw Mode/DeleteAction.h"
#include "Actions/Draw Mode/ToPlayMode.h"
#include "Actions/Draw Mode/RestartAction.h"
#include "Actions/Draw Mode/CutAction.h"
#include "Actions/Draw Mode/ResizeAction.h"
#include "Actions/Draw Mode/Set2BkOrFrntAction.h"
#include "Actions/Draw Mode/ExitAction.h"

#include "Actions/Save-Load/SaveAction.h"
#include "Actions/Save-Load/SaveByTypeAction.h"
#include "Actions/Save-Load/LoadAction.h"

#include "Actions/Play Mode/PickFigAction.h"
#include "Actions/Play Mode/PickColorAction.h"
#include "Actions/Play Mode/ToDrawMode.h"


//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures

private:
	int FigCount;		//Actual number of figures
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)
	int TempFigcount;
	CFigure* TempFigList[MaxFigCount];	//temprorary list of drawn figures

	GfxInfo TempFigGfxInfo;
	CFigure* SelectedFig; //Pointer to the selected figure
	CFigure* Clipboard;   //Pointer to the copied/cut figure
	bool OneIsSelected;
	bool OneIsCopied;
	bool OneIsCut;
	CFigure* FigureTypePTR;
	int SpecificFigType;

	//Pointers to Input and Output classes
	Input *pIn;
	Output *pOut;

public:	
	ApplicationManager(); 
	~ApplicationManager();
	

	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType) ; //Creates an action and executes it
	

	// -- Figures Management Functions
	void AddFigure(CFigure* pFig);          //Adds a new figure to the FigList
	CFigure *GetFigure(int x, int y) const; //Search for a figure given a point inside the figure
	void SetTempFigList();


	// -- Interface Management Functions
	Input *GetInput() const; //Return pointer to the input
	Output *GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window
	void CreateDrawToolBar() const;
	void RestoreTempFig();	//Redraws all the drawing window when switching to draw mode
	int GetFigCount() const;
	void SetSelectFig(CFigure*);
	void SetClipB();
	void Setfree();
	void FreeCutFig();
	bool AFigIsSelected();
	bool AFigIsCopied();
	bool AFigIsCut();
	void SaveFigData();
	void Copy();
	void Cut();
	void  Paste(CFigure*a, Point p);
	CFigure* GetSelectedFig() const;
	CFigure* GetClipBFig() const;
	
	void SaveAll(ofstream&OutFile);
	void ClearFigList();
	void DeleteSelected(CFigure*);
	void ResizeSelected(CFigure*, float);
	void BringToFront(CFigure*);
	void BringToBack(CFigure*);
	string GetRandFig() const;
	int GetRandFigCount(string) const;
	string GetRandColor() const;
	int GetRandColorCount(string) const;
	void DeleteAllFig();
	void SaveByType(ofstream&OutFile, string ShapeType);
	int CountSpecificFigType(string s);
	/*enum shape
	{
		line,
		rectangle,
		triangle,
		rhombus,
		ellipse,
	};*/
	
};
#endif