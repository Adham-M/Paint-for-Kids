#include "../../ApplicationManager.h"


PickFigAction::PickFigAction(ApplicationManager *pApp):Action(pApp) , Figure(pManager->GetRandFig())
{
	//Figure = pManager->GetRandFig();
	right = 0;
	wrong = 0;
	N = pManager->GetRandFigCount(Figure);
	NofAtt = 0;
}

void PickFigAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pIn->GetPointClicked(P1.x, P1.y);
	pOut->ClearStatusBar();
}

void PickFigAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Pick all " + Figure);
	if (pManager->GetFigCount() == 0)
		pOut->PrintMessage("No figures are left to play with");
	else
	{
		while (right != N)
		{
			Output* pOut = pManager->GetOutput();
			ReadActionParameters();
			CFigure* F = pManager->GetFigure(P1.x, P1.y);
			if (F == NULL)
			{
				wrong++;
				pOut->PrintMessage("Incorrect, try again");
			}
			else if (F->GetType() == Figure)
			{
				right++;
				pOut->PrintMessage("Correct!!");
				pManager->DeleteSelected(F);
				pManager->UpdateInterface();
			}
			else
			{
				wrong++;
				pOut->PrintMessage("Incorrect, try again");
			}
			NofAtt++;
		}
		pOut->PrintMessage("Well Done!!  You have finished the game, you got (" + to_string(right) + ") correct tries and (" + to_string(wrong) + ") incorrect tries.   Your score is (" + to_string(N) + " out of " + to_string(NofAtt) + ")");
	}
}

