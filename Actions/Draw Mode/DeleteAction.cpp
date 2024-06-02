#include "../../ApplicationManager.h"


DeleteAction::DeleteAction(ApplicationManager* pApp) :Action(pApp)
{
}
void DeleteAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	fig2del = pManager->GetSelectedFig();
	pOut->PrintMessage("Delete selected figure");
}
void DeleteAction::Execute()
{

	Output* pOut = pManager->GetOutput();
	ReadActionParameters();
	if (fig2del && fig2del->IsSelected())
	{
		pManager->DeleteSelected(fig2del);
		//pOut->ClearDrawArea();
		//pManager->UpdateInterface();
		pOut->PrintMessage("Figure has been deleted");
	}
	else
		pOut->PrintMessage(" No figure selected ");
}

