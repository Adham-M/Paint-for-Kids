#ifndef CTRI_H
#define CTRI_H

#include "CFigure.h"

class CTriangle : public CFigure
{
private:
	Point Corner1;
	Point Corner2;
	Point Corner3;
public:
	CTriangle(Point, Point, Point, GfxInfo FigureGfxInfo);
	CTriangle() {};
	void virtual Draw(Output* pOut) const;
	void virtual Copy(CFigure*&c, GfxInfo, Point p);
	bool virtual Pointinorout(int a,int b);
	int TriArea() const;
    void virtual PrintInfo(Output* pOut) const;
	virtual Point getCenter();
	virtual string GetType() const;
	void virtual Resize(float);
	void virtual Save(ofstream &OutFile);
};

#endif
