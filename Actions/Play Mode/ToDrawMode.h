#pragma once


class ToDrawMode : public Action
{
public:
	ToDrawMode(ApplicationManager*);
	virtual void ReadActionParameters();
	virtual void Execute();
};