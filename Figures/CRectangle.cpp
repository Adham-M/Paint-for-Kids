#include "CRectangle.h"

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;

	// Push the corners to the drawing area if it's in the toolbar or the statusbar areas
	if (P1.y < UI.ToolBarHeight + UI.ToolBarLineWidth)		Corner1.y = UI.ToolBarHeight + UI.ToolBarLineWidth;
	else if (P1.y > UI.height - UI.StatusBarHeight - 1)		Corner1.y = UI.height - UI.StatusBarHeight - 1;
	if (P2.y < UI.ToolBarHeight + UI.ToolBarLineWidth)		Corner2.y = UI.ToolBarHeight + UI.ToolBarLineWidth;
	else if (P2.y > UI.height - UI.StatusBarHeight - 1)		Corner2.y = UI.height - UI.StatusBarHeight - 1;
}
	

void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}
bool CRectangle::Pointinorout(int a,int b)
{
	float minx,maxx,miny,maxy ;
	if(Corner1.x>Corner2.x)
	{
		maxx = Corner1.x;
		minx = Corner2.x;
	}
	else
	{
		maxx = Corner2.x;
		minx = Corner1.x;
	}
	if(Corner1.y>Corner2.y)
	{
		maxy = Corner1.y;
		miny = Corner2.y;
	 }
	 else
	 {
		 maxy = Corner2.y;
		 miny = Corner1.y;
	 }
	 if(a>=minx && a<=maxx && b>=miny && b<=maxy )
	 {
		 return true;
	 }
	 return false;
 }
int CRectangle::getwidth() const
{
	int w=Corner1.x-Corner2.x ;
	if (w<0)
	{w=-1*w ;}
	return w ;
}
int CRectangle::getlen() const
{
	int l = Corner1.y-Corner2.y;
	return abs(l);
}

void  CRectangle::PrintInfo(Output* pOut) const
{
	pOut->PrintMessage("Rectange,   ID = " + to_string(GetID()) + ",   1st corner: (" + to_string(Corner1.x) + "," + to_string(Corner1.y) + "),   2nd corner: (" + to_string(Corner2.x) + "," + to_string(Corner2.y) + "),   length = " + to_string(getlen()) + ",   width = " + to_string(getwidth()) + ",   drawing color : " + GetDrawColor() + ",   filling color : " + GetFillColor() + ".");
}

string CRectangle::GetType() const
{
	return "Rectangle";
}
void CRectangle::Save(ofstream &OutFile)
{
	OutFile << "Rectangle" << "\t" << GetID() << "\t" << to_string(Corner1.x)
			<< "\t" << to_string(Corner1.y) << "\t" << to_string(Corner2.x) << "\t" << to_string(Corner2.y)
			<< "\t" << GetDrawColor() << "\t" << GetFillColor() << endl;
}

void CRectangle::Copy(CFigure*&c, GfxInfo G, Point P)
{
	Point corner1, corner2;
	corner1.x = P.x - getwidth() / 2;
	corner1.y = P.y - getlen()/2;
	corner2.x = P.x + getwidth() / 2;
	corner2.y = P.y + getlen() / 2;
	c = new CRectangle(corner1, corner2, G);
}
Point CRectangle::getCenter()
{
	Point p ;
	p.x= (Corner2.x+Corner1.x)/2 ;
	p.y= (Corner2.y+Corner1.y)/2 ;
	 return p ;
}

void CRectangle::Resize(float f)
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
}