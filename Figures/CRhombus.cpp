#include "CRhombus.h"

CRhombus::CRhombus(Point P1, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	xx = 140;	//distance from the center to each point on the x-axis
	yy = 85;	//distance from the center to each point on the y-axis

	if (P1.y < UI.ToolBarHeight + yy + UI.ToolBarLineWidth)		Center.y = UI.ToolBarHeight + yy + UI.ToolBarLineWidth;
	else if (P1.y > UI.height - UI.StatusBarHeight - yy - 1)	Center.y = UI.height - UI.StatusBarHeight - yy - 1;
	else Center.y = P1.y;

	if (P1.x < xx)							Center.x = xx;
	else if (P1.x > UI.width - xx - 15)		Center.x = UI.width - xx - 15;
	else Center.x = P1.x;
}


void CRhombus::Draw(Output* pOut) const
{
	//Call Output::DrawRhomb to draw a rhombus on the screen	
	pOut->DrawRhomb(Center, xx, yy, FigGfxInfo, Selected);
}

float signR(Point p1, Point p2, Point p3)
{
	return (p1.x - p3.x) * (p2.y - p3.y) - (p2.x - p3.x) * (p1.y - p3.y);
}

bool PointinTriangle(Point pt, Point C1, Point C2, Point C3)
{
	float d1, d2, d3;
	bool has_neg, has_pos;

	d1 = signR(pt, C1, C2);
	d2 = signR(pt, C2, C3);
	d3 = signR(pt, C3, C1);

	has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
	has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

	return !(has_neg && has_pos);
}

bool CRhombus::Pointinorout(int x, int y)
{
	Point Pt;
	Pt.x = x;	Pt.y = y;


	Point C1, C2, C3, C4;	//coordinates of the rhombus
	C1.x = Center.x + xx;	C1.y = Center.y;
	C2.x = Center.x;		C2.y = Center.y + yy;
	C3.x = Center.x - xx;	C3.y = Center.y;
	C4.x = Center.x;		C4.y = Center.y - yy;

	//Dividing the rhombus into 2 triangles
	//Do the same check of triangles
	if (PointinTriangle(Pt, C1, C3, C4))
		return true;

	if (PointinTriangle(Pt, C1, C3, C2))
		return true;

	return false;
}

void CRhombus::PrintInfo(Output* pOut) const
{
	pOut->PrintMessage("Ellipse,   ID = " + to_string(GetID()) + ",   Center = (" + to_string(Center.x) + "," + to_string(Center.y) + "),   drawing color: " + GetDrawColor() + ",   filling color: " + GetFillColor() + ".");
}

string CRhombus::GetType() const
{
	return "Rhombus";
}
void CRhombus::Save(ofstream &OutFile)
{
	OutFile << "Rhombus" << "\t\t" << GetID() << "\t" << to_string(Center.x)
		<< "\t" << to_string(Center.y) << "\t" << GetDrawColor() << "\t" << GetFillColor() << endl;
}

void CRhombus::Copy(CFigure*&c, GfxInfo G, Point P)
{
	c = new CRhombus(P, G);
}
Point CRhombus::getCenter()
{
	return Center;
}

void CRhombus::Resize(float f)
{
	xx *= f;
	yy *= f;
}