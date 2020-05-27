#ifndef CELLIP_H
#define CELLIP_H

#include "CFigure.h"

class CEllipse : public CFigure
{
private:
	Point Center;
	int xx;
	int yy;
public:
	CEllipse(Point, GfxInfo FigureGfxInfo);
	CEllipse() { };
	void virtual Draw(Output* pOut) const;
	virtual void Copy(CFigure*&c,GfxInfo, Point p);
	virtual Point getCenter();
	//void virtual Paste(Output*,CFigure*&,Point);
	bool virtual Pointinorout(int a,int b);
	void virtual PrintInfo(Output* pOut) const;
	string virtual GetType() const;
	void virtual Resize(float);
	void virtual Save(ofstream &OutFile);
};

#endif