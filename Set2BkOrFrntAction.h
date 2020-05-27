#pragma once

class Set2BkOrFrntAction : public Action
{
	CFigure* fig;
	bool bol;
public:
	Set2BkOrFrntAction(ApplicationManager*, bool);
	void virtual ReadActionParameters();
	void virtual Execute();
};