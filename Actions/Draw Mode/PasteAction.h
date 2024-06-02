#pragma once



class PasteAction : public Action
{
private:
	Point original;
	Point Past_Point ;
public:
	PasteAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};
