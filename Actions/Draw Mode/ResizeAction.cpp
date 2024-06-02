#include "../../Application Manager/ApplicationManager.h"

ResizeAction::ResizeAction(ApplicationManager* pApp, float f) :Action(pApp)
{
	factor = f;
}

void ResizeAction::ReadActionParameters()
{
}
void ResizeAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	fig2resize = pManager->GetSelectedFig();
	if (fig2resize && fig2resize->IsSelected())
	{
		pManager->ResizeSelected(fig2resize, factor);
		pOut->PrintMessage("Figure has been resized");
	}
	else
		pOut->PrintMessage("Selecte a figure to resize first");
}

