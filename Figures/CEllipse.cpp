#include "CEllipse.h"

CEllipse::CEllipse(Point P1, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	xx = 140;
	yy = 85;

	if (P1.y < UI.ToolBarHeight + yy + UI.ToolBarLineWidth)		Center.y = UI.ToolBarHeight + yy + UI.ToolBarLineWidth;
	else if (P1.y > UI.height - UI.StatusBarHeight - yy - 1)	Center.y = UI.height - UI.StatusBarHeight - yy - 1;
	else Center.y = P1.y;

	if (P1.x < xx)							Center.x = xx;
	else if (P1.x > UI.width - xx - 15)		Center.x = UI.width - xx - 15;
	else Center.x = P1.x;
}

void CEllipse::Draw(Output* pOut) const
{
	//Call Output::DrawEllip to draw a ellipse on the screen	
	pOut->DrawEllip(Center, xx, yy, FigGfxInfo, Selected);
}

int pow(int num, int p)
{
	int n = 1;
	for (int i = 0; i < p; i++)
		n *= num;
	return n;
}

bool CEllipse::Pointinorout(int a, int b)
{
	if ((pow((a - Center.x), 2) / pow(xx, 2)) + (pow((b - Center.y), 2) / pow(yy, 2)) <= 1)
		return true;

	return false;
}


void CEllipse::Copy(CFigure*&c, GfxInfo G, Point P)
{
	c = new CEllipse(P, G);
}


void CEllipse::PrintInfo(Output* pOut) const
{
	pOut->PrintMessage("Ellipse,   ID = " + to_string(GetID()) + ",   Center = (" + to_string(Center.x) + "," + to_string(Center.y) + "),   drawing color: " + GetDrawColor() + ",   filling color: " + GetFillColor() + ".");
}

string CEllipse::GetType() const
{
	return "Ellipse";
}
void CEllipse::Save(ofstream &OutFile)
{
	OutFile << "Ellipse" << "\t\t" << GetID() << "\t" << to_string(Center.x)
		<< "\t" << to_string(Center.y) << "\t" << GetDrawColor() << "\t" << GetFillColor() << endl;
}

Point CEllipse::getCenter()
{
	return Center;
}

void CEllipse::Resize(float f)
{
	xx *= f;
	yy *= f;
}