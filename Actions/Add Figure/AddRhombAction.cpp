#include "../../ApplicationManager.h"


AddRhombAction::AddRhombAction(ApplicationManager * pApp) :Action(pApp)
{}

void AddRhombAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Rhombus: Click at center");

	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	if (UI.FillColor == LIGHTGOLDENRODYELLOW)
		RhombGfxInfo.isFilled = false;	//default is not filled
	else
		RhombGfxInfo.isFilled = true;

	//get drawing, filling colors and pen width from the interface
	RhombGfxInfo.DrawClr = pOut->getCrntDrawColor();
	RhombGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();
}

//Execute the action
void AddRhombAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a rectangle with the parameters read from the user
	CRhombus *R = new CRhombus(P1, RhombGfxInfo);

	//Add the rectangle to the list of figures
	pManager->AddFigure(R);
}
