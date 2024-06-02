#include "../../Application Manager/ApplicationManager.h"


ToDrawMode::ToDrawMode(ApplicationManager*pApp) :Action(pApp)
{
}


void ToDrawMode::ReadActionParameters()
{
}
void ToDrawMode::Execute()
{
	Output* pOut = pManager->GetOutput();
	pOut->CreateDrawToolBar();
	pOut->CreateStatusBar();
	pOut->ClearDrawArea();
	pManager->RestoreTempFig();
	pOut->PrintMessage("Switched to draw mode");
}
