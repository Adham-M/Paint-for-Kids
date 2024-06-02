#include "../../Application Manager/ApplicationManager.h"


SaveByTypeAction::SaveByTypeAction(ApplicationManager *pApp) : Action(pApp)
{
}

void SaveByTypeAction::ReadActionParameters()
{

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Select a figure icon");

	ClickedItemOrder = pManager->GetUserAction();
	pOut->ClearStatusBar();

	pOut->PrintMessage("Enter the name of the file without spaces ");

	fileName = pIn->GetSrting(pOut) + ".txt";

	OutFile.open(fileName);

	if (OutFile.is_open())
		pOut->PrintMessage("Your file has been Successfully Saved");
	else
		pOut->PrintMessage("Unable to save file");

}

void SaveByTypeAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();

	if (ClickedItemOrder == 1)
	{
		ShapeType = "Rectangle";
		pOut->PrintMessage("You choosed Rectangel, and Your file has been Successfully Saved");
	}
	else if (ClickedItemOrder == 0)
	{
		ShapeType = "Line";
		pOut->PrintMessage("You choosed Line, and Your file has been Successfully Saved");
	}
	else if (ClickedItemOrder == 2)
	{
		ShapeType = "Triangle";
		pOut->PrintMessage("You choosed Triangle, and Your file has been Successfully Saved");
	}
	else if (ClickedItemOrder == 3)
	{
		ShapeType = "Rhombus";
		pOut->PrintMessage("You choosed Rhombus, and Your file has been Successfully Saved");
	}
	else if (ClickedItemOrder == 4)
	{
		ShapeType = "Ellipse";
		pOut->PrintMessage("You choosed Ellipse, and Your file has been Successfully Saved");
	}
	else
	{
		pOut->PrintMessage("No Figure icon has been selected");
	}



	if (OutFile.is_open())
	{
		int numberOfFiguers = pManager->CountSpecificFigType(ShapeType);
		string DrawClr = getColorName(UI.DrawColor);
		OutFile << DrawClr;
		string FillClr = getColorName(UI.FillColor);
		OutFile << '\t' << FillClr << endl;
		OutFile << numberOfFiguers << endl;
	}
	pManager->SaveByType(OutFile, ShapeType);
	OutFile.close();
}
string SaveByTypeAction::getColorName(color a)const
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
	else
		return "NO";
}