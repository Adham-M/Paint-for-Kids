#include "ApplicationManager.h"


ExitAction::ExitAction(ApplicationManager*pApp) :Action(pApp)
{
}

void ExitAction::ReadActionParameters()
{

}

void ExitAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	//pManager->DeleteAllFig();
}