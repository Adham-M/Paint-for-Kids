#pragma once


class PickFigAction : public Action
{
	Point P1;
	const string Figure;
	int right, wrong, N, NofAtt;
public:
	PickFigAction(ApplicationManager*);
	void virtual ReadActionParameters();
	void virtual Execute();
};