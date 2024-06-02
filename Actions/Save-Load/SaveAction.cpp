#include "../../ApplicationManager.h"


SaveAction::SaveAction(ApplicationManager *pApp) : Action(pApp)
{
}

void SaveAction::ReadActionParameters()
{

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Enter the name of the file without spaces ");


	fileName = pIn->GetSrting(pOut) + ".txt";

	OutFile.open(fileName);
	if (OutFile.is_open())
	{
		pOut->PrintMessage("Your file has been Successfully Saved");
	}
	else {
		pOut->PrintMessage("Unable to save file");
	}
}

void SaveAction::Execute()
{
	ReadActionParameters();

	if (OutFile.is_open())
	{
		int numberOfFiguers = pManager->GetFigCount();
		string DrawClr = getColorName(UI.DrawColor);
		OutFile << DrawClr;
		string FillClr = getColorName(UI.FillColor);
		OutFile << '\t' << FillClr << endl;
		OutFile << numberOfFiguers << endl;
		pManager->SaveAll(OutFile);
		OutFile.close();
	}
}
string SaveAction::getColorName(color a)const
{
	if (a == RED)
		return "RED";
	else if (a == BLACK)
		return "BLACK";	
	else if (a == BLUE)
		return "BLUE";
	else if (a == GREEN)
		return "GREEN";
	else if (a == WHITE)
		return "WHITE";
	return "NO";
}
