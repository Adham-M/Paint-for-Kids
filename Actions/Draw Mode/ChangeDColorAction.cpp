#include "../../ApplicationManager.h"


ChangeDColorAction::ChangeDColorAction(ApplicationManager * pApp) :Action(pApp)
{}

void ChangeDColorAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	SelectedFigure = pManager->GetSelectedFig();
	if (SelectedFigure == NULL)
	{
		pOut->PrintMessage("No figure selected to change its draw color");
	}
	else
	{
		pOut->PrintMessage("Select Color to Change Draw Color of Selected Figure");
	}
	ClickedItemOrder = pManager->GetUserAction();
	pOut->ClearStatusBar();
}

void ChangeDColorAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();

	if (SelectedFigure != NULL)
	{
		if (ClickedItemOrder == COLOR_BLACK)
		{
			SelectedColor = BLACK;
			IsSelected = true;
			pOut->PrintMessage("Draw Color changed to BLACK");
			SelectedFigure->ChngDrawClr(SelectedColor);
			UI.DrawColor = BLACK;
		}
		else if (ClickedItemOrder == COLOR_WHITE)
		{
			SelectedColor = WHITE;
			IsSelected = true;
			pOut->PrintMessage("Draw Color changed to WHITE");
			SelectedFigure->ChngDrawClr(SelectedColor);
			UI.DrawColor = WHITE;
		
		}
		else if (ClickedItemOrder == COLOR_RED)
		{
			SelectedColor = RED;
			IsSelected = true;
			pOut->PrintMessage("Draw Color changed to RED");
			SelectedFigure->ChngDrawClr(SelectedColor);
			UI.DrawColor = RED;
		}
		else if (ClickedItemOrder == COLOR_GREEN)
		{
			SelectedColor = GREEN;
			IsSelected = true;
			pOut->PrintMessage("Draw Color changed to GREEN");
			SelectedFigure->ChngDrawClr(SelectedColor);
			UI.DrawColor = GREEN;
		}
		else if (ClickedItemOrder == COLOR_BLUE)
		{
			SelectedColor = BLUE;
			IsSelected = true;
			pOut->PrintMessage("Draw Color changed to BLUE");
			SelectedFigure->ChngDrawClr(SelectedColor);
			UI.DrawColor = BLUE;
		}
		else
		{
			pOut->PrintMessage("No Color has been selected");
		}
	}
	else if (SelectedFigure == NULL) 
	{
		pOut->PrintMessage("Select a figure first");
	}
}