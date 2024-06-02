#include "../../Application Manager/ApplicationManager.h"


LoadAction::LoadAction(ApplicationManager *pApp) : Action(pApp)
{
}
void LoadAction::ReadActionParameters()
{

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Enter the name of the file you want to load");


	fileName = pIn->GetSrting(pOut) + ".txt";

	InputFile.open(fileName);
	pOut->ClearDrawArea();

	if (InputFile.is_open())
	{
		pOut->PrintMessage("Your file has been successfully loaded");
	}
	else { pOut->PrintMessage("No file found with name: " + fileName); }
}

void LoadAction::Execute()
{
	ReadActionParameters();

	if (InputFile.is_open())
	{
		CFigure*pFig = NULL;
		int numberOfFiguers;
		string DrawClr;
		InputFile >> DrawClr;
		UI.DrawColor = pFig->getColorObject(DrawClr);
		string FillClr;
		InputFile >> FillClr;
		UI.FillColor = pFig->getColorObject(FillClr);
		InputFile >> numberOfFiguers;
		pManager->ClearFigList();
		int id;
		Point p1, p2, p3;
		string s1, s2;
		GfxInfo gfx;
		int sht;
		for (int i = 0; i < numberOfFiguers; i++)
		{
			string shapeType;
			InputFile >> shapeType;
			if (shapeType == "Line")
				sht = 0;
			else if (shapeType == "Rectangle")
				sht = 1;
			else if (shapeType == "Triangle")
				sht = 2;
			else if (shapeType == "Ellipse")
				sht = 3;
			else if (shapeType == "Rhombus")
				sht = 4;

			switch (sht)
			{
			case 0:
				InputFile >> id >> p1.x >> p1.y >> p2.x >> p2.y >> s1;
				gfx = pFig->getGfx(s1, "NotFilled");
				pFig = new CLine(p1,p2, gfx);
				break;

			case 1:
				InputFile >> id >> p1.x >> p1.y >> p2.x >> p2.y >> s1 >> s2;
				gfx = pFig->getGfx(s1, s2);
				pFig = new CRectangle(p1, p2, gfx);
				break;

			case 2:
				InputFile >> id >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y >> s1 >> s2;
				gfx = pFig->getGfx(s1, s2);
				pFig = new CTriangle(p1, p2, p3, gfx);
				break;

			case 3:
				InputFile >> id >> p1.x >> p1.y >> s1 >> s2;
				gfx = pFig->getGfx(s1, s2);
				pFig = new CEllipse(p1, gfx);
				break;

			case 4:
				InputFile >> id >> p1.x >> p1.y >> s1 >> s2;
				gfx = pFig->getGfx(s1, s2);
				pFig = new CRhombus(p1, gfx);
				break;

			default:
				pFig = NULL;
				break;
			}
			if (pFig != NULL)
			{
				//sending it to the application manager to add them
				pManager->AddFigure(pFig);
			}
		}
		//close the file after looping 
		InputFile.close();
	}
}

