#include "../../Application Manager/ApplicationManager.h"


AddEllipAction::AddEllipAction(ApplicationManager * pApp) :Action(pApp)
{}

void AddEllipAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Ellipse: Click at the center");

	//Read center and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);


	if (UI.FillColor == LIGHTGOLDENRODYELLOW)
		EllipGfxInfo.isFilled = false;	//default is not filled
	else
		EllipGfxInfo.isFilled = true;

	//get drawing, filling colors and pen width from the interface
	EllipGfxInfo.DrawClr = pOut->getCrntDrawColor();
	EllipGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddEllipAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a ellipse with the parameters read from the user
	CEllipse *R = new CEllipse(P1, EllipGfxInfo);

	//Add the ellipse to the list of figures
	pManager->AddFigure(R);
}
