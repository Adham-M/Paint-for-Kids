#include "ApplicationManager.h"


SelectAction::SelectAction(ApplicationManager * pApp):Action(pApp)
{
	//ReadActionParameters();
	//CFigure * p= NULL;
}
void SelectAction::ReadActionParameters() 
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Select a figure.");
	pIn->GetPointClicked(P1.x, P1.y);
	pOut->ClearStatusBar();
}

void SelectAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();
	CFigure* c = pManager->GetFigure(P1.x, P1.y);
	if(c!=NULL && !(c->IsSelected()))
	{
		pManager->SetSelectFig(c);
		c->PrintInfo(pOut);
	}
	else if (c == NULL && pManager->AFigIsSelected() || c!=NULL && c->IsSelected())
	{
		pManager->Setfree();
		pOut->PrintMessage("Selected figure is now deselected.");
	}
	else
		pOut->PrintMessage("No new figure has been selected.");
}
