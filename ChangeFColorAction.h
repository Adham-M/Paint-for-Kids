#pragma once



class ChangeFColorAction : public Action
{
	color SelectedColor;
	CFigure* SelectedFigure;
	bool IsSelected;
	int ClickedItemOrder;
public:
	ChangeFColorAction(ApplicationManager*);
	virtual void ReadActionParameters();
	virtual void Execute();
};

