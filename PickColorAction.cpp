#include "ApplicationManager.h"


PickColorAction::PickColorAction(ApplicationManager *pApp) : Action(pApp) , Color(pManager->GetRandColor())
{
	right = 0;
	wrong = 0;
	N = pManager->GetRandColorCount(Color);
	NofAtt = 0;
}

void PickColorAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pIn->GetPointClicked(P1.x, P1.y);
	pOut->ClearStatusBar();
}

void PickColorAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Pick all " + Color + " Figures");
	if (pManager->GetFigCount() == 0)
		pOut->PrintMessage("No figures are left to play with");
	else
	{
		while (right != N)
		{
			Output* pOut = pManager->GetOutput();
			ReadActionParameters();
			CFigure* F = pManager->GetFigure(P1.x, P1.y);
			if (F == NULL || F->GetFillColor() != Color)
			{
				wrong++;
				pOut->PrintMessage("Incorrect, try again");
			}
			else if (F->GetFillColor() == Color)
			{
				right++;
				pOut->PrintMessage("Correct!!");
			}
			//else if(P1.x > 2 * UI.MenuItemWidth && P1.x < 3 * UI.MenuItemWidth && P1.y < UI.ToolBarHeight)
			//{
			//	 
			//}
			pManager->DeleteSelected(F);
			NofAtt++;
		}
		pOut->PrintMessage("Well Done!!, You have finished the game, you got (" + to_string(right) + ") correct tries and (" + to_string(wrong) + ") incorrect tries.   Your score is (" + to_string(N) + " out of " + to_string(NofAtt) + ")");
	}
}