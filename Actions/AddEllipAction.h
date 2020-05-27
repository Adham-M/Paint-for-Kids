#ifndef ADD_ELLIP_ACTION_H
#define ADD_ELLIP_ACTION_H

#include "Action.h"

//Add ellipse Action class
class AddEllipAction : public Action
{
private:
	Point P1; //Ellipse Center
	GfxInfo EllipGfxInfo;
public:
	AddEllipAction(ApplicationManager *pApp);

	//Reads ellipse parameters
	virtual void ReadActionParameters();

	//Add ellipse to the ApplicationManager
	virtual void Execute();

};

#endif