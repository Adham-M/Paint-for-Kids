#include "ApplicationManager.h"

Set2BkOrFrntAction::Set2BkOrFrntAction(ApplicationManager* pApp, bool b) :Action(pApp)
{
	bol = b;
}

void Set2BkOrFrntAction::ReadActionParameters()
{
}

void Set2BkOrFrntAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	fig = pManager->GetSelectedFig();
	if (fig && fig->IsSelected())
	{
		if (bol)
			pManager->BringToFront(fig);
		else
			pManager->BringToBack(fig);
		pOut->PrintMessage("Figure has been moved");
	}
	else
		pOut->PrintMessage("Selecte a figure to move first");
}

