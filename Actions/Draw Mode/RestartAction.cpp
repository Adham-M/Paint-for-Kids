#include "../../ApplicationManager.h"


RestartAction::RestartAction(ApplicationManager*pApp) :Action(pApp)
{
}


void RestartAction::ReadActionParameters()
{
}
void RestartAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Select a mode to play");
	pManager->RestoreTempFig();
}
