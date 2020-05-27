#include "ApplicationManager.h"


CopyAction::CopyAction(ApplicationManager * pApp):Action(pApp)
{}
void CopyAction::ReadActionParameters() 
{	
}

void CopyAction:: Execute()
{	Output* pOut = pManager->GetOutput();
	if(pManager->AFigIsSelected())
	{
		pOut->PrintMessage("Copy figure") ;
		pManager->Copy();
	}
	else
		pOut->PrintMessage("Please Select Figure First") ;
}