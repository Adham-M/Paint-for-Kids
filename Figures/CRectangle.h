#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point Corner1;
	Point Corner2;
public:
	CRectangle(Point , Point, GfxInfo);
	CRectangle() {};
	void virtual Draw(Output*) const;
	void virtual Copy(CFigure*&c, GfxInfo, Point p);
	//void virtual Paste (CFigure*&c);
	bool virtual Pointinorout(int,int);
	void virtual PrintInfo(Output*) const;
	void virtual Resize(float);
	Point virtual getCenter();
	int getlen() const;
	int getwidth() const;
	string virtual GetType() const;
	void virtual Save(ofstream &OutFile);
};

#endif