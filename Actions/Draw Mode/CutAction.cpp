#include "../../ApplicationManager.h"


CutAction::CutAction(ApplicationManager * pApp) :Action(pApp)
{}

void CutAction::ReadActionParameters()
{}

void CutAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	if (pManager->AFigIsSelected())
	{
		pOut->PrintMessage("Figure has been cut");
		pManager->Cut();
	}
	else
		pOut->PrintMessage("No Figure Selected");
}