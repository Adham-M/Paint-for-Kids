#ifndef CRHOMB_H
#define CRHOMB_H

#include "CFigure.h"

class CRhombus : public CFigure
{
private:
	Point Center;
	int xx, yy;
public:
	CRhombus(Point, GfxInfo FigureGfxInfo);
	CRhombus() {};
	void virtual Draw(Output* pOut) const;
	void virtual Copy(CFigure*&c, GfxInfo, Point p);
	bool virtual Pointinorout(int a,int b);
	void virtual PrintInfo(Output* pOut) const;
	Point virtual getCenter();
	string virtual GetType() const;
	void virtual Resize(float);
	void virtual Save(ofstream &OutFile);
};

#endif