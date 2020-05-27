#pragma once


class DeleteAction : public Action
{
	CFigure* fig2del;
public:
	DeleteAction(ApplicationManager*);
	void virtual ReadActionParameters();
	void virtual Execute();
};
