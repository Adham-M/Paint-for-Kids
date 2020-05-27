#ifndef CLINE_H
#define CLINE_H

#include "CFigure.h"

class CLine : public CFigure
{
	Point start;
	Point end;
public:
	CLine(Point, Point, GfxInfo FigureGfxInfo);
	CLine() {};
	void virtual Draw(Output* pOut) const;
	void virtual Copy(CFigure*&c, GfxInfo, Point p);
	//void virtual Paste(CFigure*&c);
	bool virtual Pointinorout(int a,int b);
	virtual Point getCenter();
	float GetLength() const;
	void virtual PrintInfo(Output* pOut) const;
	string virtual GetType() const;
	void virtual Resize(float);
	void virtual Save(ofstream &OutFile);
};

#endif