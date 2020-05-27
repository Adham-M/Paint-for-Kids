#include "CTriangle.h"
#include <fstream>

CTriangle::CTriangle(Point P1, Point P2, Point P3, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Corner3 = P3;

	if (P1.y < UI.ToolBarHeight + UI.ToolBarLineWidth)		Corner1.y = UI.ToolBarHeight + UI.ToolBarLineWidth;
	else if (P1.y > UI.height - UI.StatusBarHeight - 1)		Corner1.y = UI.height - UI.StatusBarHeight - 1;
	if (P2.y < UI.ToolBarHeight + UI.ToolBarLineWidth)		Corner2.y = UI.ToolBarHeight + UI.ToolBarLineWidth;
	else if (P2.y > UI.height - UI.StatusBarHeight - 1)		Corner2.y = UI.height - UI.StatusBarHeight - 1;
	if (P3.y < UI.ToolBarHeight + UI.ToolBarLineWidth)		Corner3.y = UI.ToolBarHeight + UI.ToolBarLineWidth;
	else if (P3.y > UI.height - UI.StatusBarHeight - 1)		Corner3.y = UI.height - UI.StatusBarHeight - 1;
}


void CTriangle::Draw(Output* pOut) const
{
	//Call Output::DrawTri to draw a triangle on the screen	
	pOut->DrawTri(Corner1, Corner2, Corner3, FigGfxInfo, Selected);
}

int CTriangle::TriArea() const
{
	return abs((Corner1.x *(Corner2.y - Corner3.y) + Corner2.x *(Corner3.y - Corner1.y) + Corner3.x * (Corner1.y - Corner2.y)) / 2);
}

float sign(Point p1, Point p2, Point p3)
{
	return (p1.x - p3.x) * (p2.y - p3.y) - (p2.x - p3.x) * (p1.y - p3.y);
}

bool CTriangle::Pointinorout(int x, int y)
{
	float d1, d2, d3;
	bool has_neg, has_pos;
	Point pt;
	pt.x = x;
	pt.y = y;

	d1 = sign(pt, Corner1, Corner2);
	d2 = sign(pt, Corner2, Corner3);
	d3 = sign(pt, Corner3, Corner1);

	has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
	has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

	return !(has_neg && has_pos);
}

void CTriangle::PrintInfo(Output* pOut) const
{
	pOut->PrintMessage("Triangle,   ID = " + to_string(GetID()) + ",   1st corner: (" + to_string(Corner1.x) + "," + to_string(Corner1.y) + "),   2nd corner: (" + to_string(Corner2.x) + "," + to_string(Corner2.y) + "),   3rd corner: (" + to_string(Corner3.x) + "," + to_string(Corner3.y) + "),   area = " + to_string(TriArea()) + ",   drawing color: " + GetDrawColor() + ",   filling color: " + GetFillColor() + ".");
}

string CTriangle::GetType() const
{
	return "Triangle";
}

void CTriangle::Save(ofstream &OutFile)
{
	OutFile << "Triangle" << "\t" << GetID() << "\t" << to_string(Corner1.x)
		<< "\t" << to_string(Corner1.y) << "\t" << to_string(Corner2.x) << "\t" << to_string(Corner2.y)
		<< "\t" << to_string(Corner3.x) << "\t" << to_string(Corner3.y) << "\t" << GetDrawColor() << "\t" << GetFillColor() << endl;
}

void CTriangle::Copy(CFigure*&c, GfxInfo G, Point P)
{
	Point diff;
	diff.x = P.x - getCenter().x;
	diff.y = P.y - getCenter().y;

	Point corner1, corner2, corner3;
	corner1.x = Corner1.x + diff.x;
	corner1.y = Corner1.y + diff.y;
	corner2.x = Corner2.x + diff.x;
	corner2.y = Corner2.y + diff.y;
	corner3.x = Corner3.x + diff.x;
	corner3.y = Corner3.y + diff.y;
	c = new CTriangle(corner1, corner2, corner3, G);
}

Point  CTriangle::getCenter()
{
	Point p;
	p.x = (Corner1.x + Corner2.x + Corner3.x) / 3;
	p.y = (Corner1.y + Corner2.y + Corner3.y) / 3;
	return p;
}

void CTriangle::Resize(float f)
{
	Point c = getCenter();
	int d;
	d = Corner1.x - c.x;
	Corner1.x = c.x + d * f;
	d = Corner1.y - c.y;
	Corner1.y = c.y + d * f;
	d = Corner2.x - c.x;
	Corner2.x = c.x + d * f;
	d = Corner2.y - c.y;
	Corner2.y = c.y + d * f;
	d = Corner3.x - c.x;
	Corner3.x = c.x + d * f;
	d = Corner3.y - c.y;
	Corner3.y = c.y + d * f;
}