#pragma once

class ChangeDColorAction : public Action
{
public:
	color SelectedColor;
	CFigure* SelectedFigure;
	bool IsSelected;
	int ClickedItemOrder;
	ChangeDColorAction(ApplicationManager*pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};

