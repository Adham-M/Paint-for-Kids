#include "ApplicationManager.h"


ChangeFColorAction::ChangeFColorAction(ApplicationManager*pApp) :Action(pApp)
{
}
void ChangeFColorAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	SelectedFigure = pManager->GetSelectedFig();
	if (!(pManager->AFigIsSelected()))
	{
		pOut->PrintMessage("Select Color to Change Current Fill Color");
	}
	else
	{
		pOut->PrintMessage("Select Color to Change Fill Color of Selected Figure");
	}
	ClickedItemOrder = pManager->GetUserAction();
	pOut->ClearStatusBar();
}

void ChangeFColorAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();

	if (SelectedFigure != NULL)
	{
		if (ClickedItemOrder == COLOR_BLACK)
		{
			pManager->GetSelectedFig()->ChngFillClr(BLACK);
			IsSelected = true;
			pOut->PrintMessage("Fill Color changed to BLACK");
			UI.FillColor = BLACK;
		}
		else if (ClickedItemOrder == COLOR_WHITE)
		{
			pManager->GetSelectedFig()->ChngFillClr(WHITE);
			IsSelected = true;
			pOut->PrintMessage("Fill Color changed to WHITE");
			UI.FillColor = WHITE;
		}
		else if (ClickedItemOrder == COLOR_RED)
		{
			pManager->GetSelectedFig()->ChngFillClr(RED);
			IsSelected = true;
			pOut->PrintMessage("Fill Color changed to RED");
			UI.FillColor = RED;
		}
		else if (ClickedItemOrder == COLOR_GREEN)
		{
			pManager->GetSelectedFig()->ChngFillClr(GREEN);
			IsSelected = true;
			pOut->PrintMessage("Fill Color changed to GREEN");
			UI.FillColor = GREEN;
		}
		else if (ClickedItemOrder == COLOR_BLUE)
		{
			pManager->GetSelectedFig()->ChngFillClr(BLUE);
			IsSelected = true;
			pOut->PrintMessage("Fill Color changed to BLUE");
			UI.FillColor = BLUE;
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
