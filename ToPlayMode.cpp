#include "ApplicationManager.h"


ToPlayMode::ToPlayMode(ApplicationManager*pApp) :Action(pApp)
{
}


void ToPlayMode::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	if (pManager->GetFigCount() != 0)
		pOut->PrintMessage("Switch to play mode");
	else 
		pOut->PrintMessage("No Figures to play with");
}

void ToPlayMode::Execute()
{
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();
	if (pManager->GetFigCount() != 0)
	{
		pManager->SetTempFigList();
		pOut->ClearToolBar();
		pOut->CreatePlayToolBar();
		if(pManager->AFigIsSelected())
			pManager->Setfree();
	}
}
