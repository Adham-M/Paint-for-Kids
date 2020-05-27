#include"ApplicationManager.h"


PasteAction::PasteAction(ApplicationManager *pApp) :Action(pApp)
{
}
void PasteAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Select paste point");
	pIn->GetPointClicked(Past_Point.x, Past_Point.y);

	pOut->ClearStatusBar();
}
void PasteAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	if (pManager->GetClipBFig() != NULL)
	{
		ReadActionParameters();
		CFigure*fig;
		fig = pManager->GetClipBFig();

		original = fig->getCenter();
		Point diff;
		diff.x = Past_Point.x - original.x;
		diff.y = Past_Point.y - original.y;


		pManager->Paste(fig, Past_Point);

		pOut->PrintMessage("Figure pasted");
	}
	else
		pOut->PrintMessage("No figure is cut or copied to paste");
}