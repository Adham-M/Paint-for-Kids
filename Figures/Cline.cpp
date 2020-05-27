#include "CLine.h"

CLine::CLine(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	start = P1;
	end = P2;

	if (P1.y < UI.ToolBarHeight + UI.ToolBarLineWidth)		start.y = UI.ToolBarHeight + UI.ToolBarLineWidth;
	else if (P1.y > UI.height - UI.StatusBarHeight - 1)		start.y = UI.height - UI.StatusBarHeight - 1;
	if (P2.y < UI.ToolBarHeight + UI.ToolBarLineWidth)		end.y = UI.ToolBarHeight + UI.ToolBarLineWidth;
	else if (P2.y > UI.height - UI.StatusBarHeight - 1)		end.y = UI.height - UI.StatusBarHeight - 1;
}


void CLine::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawLine(start, end, FigGfxInfo, Selected);
}
bool CLine::Pointinorout(int a, int b)
{
	float maxx, maxy, minx, miny;
	if (start.x > end.x)
	{
		maxx = start.x;
		minx = end.x;
	}
	else
	{
		maxx = end.x;
		minx = start.x;
	}
	if (start.y > end.y)
	{
		maxy = start.x;
		miny = end.x;
	}
	else
	{
		maxy = end.x;
		miny = start.x;
	}
	if (start.x == end.x)
	{
		if (maxy >= b && b >= miny && a > start.x - 5 && a < start.x + 5)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	if (start.y == end.y)
	{
		if (maxx >= a && a >= minx && b > start.x - 5 && b < start.x + 5)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	if (start.x != end.x && start.y != end.y)
	{
		float m = (end.y - start.y) / (end.x - start.x);
		float c = start.y - (start.x *m);
		if ((b - end.y) / (a - end.x) == ((maxy - miny) / (maxx - minx)))	////////////////////////////////if(c+5>=b-(m*a) && b-(m*a)>-c-5 && maxx>=a && a>=minx && maxy>=b && b>=miny )
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

float CLine::GetLength() const
{
	int l1 = start.x - end.x;
	int l2 = start.y - end.y;
	return sqrt((l1 ^ 2) + (l2 ^ 2));
}

void CLine::PrintInfo(Output* pOut) const
{
	pOut->PrintMessage("Line,   ID = " + to_string(GetID()) + ",   start point: (" + to_string(start.x) + "," + to_string(start.y) + "),   end point: (" + to_string(end.x) + "," + to_string(end.y) + "),   drawing color: " + GetDrawColor() + ".");
}

string CLine::GetType() const
{
	return "Line";
}
void CLine::Save(ofstream &OutFile)
{
	OutFile << "Line" << "\t\t" << GetID() << "\t" << to_string(start.x)
		<< "\t" << to_string(start.y) << "\t" << to_string(end.x) << "\t" << to_string(end.y)
		<< "\t" << GetDrawColor() << endl;
}

void CLine::Copy(CFigure*&c, GfxInfo G, Point P)
{
	Point diff;
	diff.x = P.x - getCenter().x;
	diff.y = P.y - getCenter().y;

	Point Start, End;
	Start.x = start.x + diff.x;
	Start.y = start.y + diff.y;
	End.x = end.x + diff.x;
	End.y = end.y + diff.y;
	c = new CLine(Start, End, G);
}
Point CLine::getCenter()
{
	Point p;
	p.x = (start.x + end.x) / 2;
	p.y = (start.y + end.y) / 2;
	return p;
}

void CLine::Resize(float f)
{
	Point c = getCenter();
	int d;
	d = start.x - c.x;
	start.x = c.x + d * f;
	d = start.y - c.y;
	start.y = c.y + d * f;
	d = end.x - c.x;
	end.x = c.x + d * f;
	d = end.y - c.y;
	end.y = c.y + d * f;
}