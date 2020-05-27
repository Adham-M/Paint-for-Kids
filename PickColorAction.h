#pragma once



class PickColorAction : public Action
{
	Point P1;
	const string Color;
	int right, wrong, N, NofAtt;
public:
	PickColorAction(ApplicationManager*);
	void virtual ReadActionParameters();
	void virtual Execute();
};