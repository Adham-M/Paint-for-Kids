#ifndef ADD_RHOMB_ACTION_H
#define ADD_RHOMB_ACTION_H


//Add Rectangle Action class
class AddRhombAction : public Action
{
private:
	Point P1; //Rhombus Center
	GfxInfo RhombGfxInfo;
public:
	AddRhombAction(ApplicationManager *pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();

};

#endif