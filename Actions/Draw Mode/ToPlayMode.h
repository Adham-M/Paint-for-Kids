#pragma once



class ToPlayMode : public Action
{
public:
	ToPlayMode(ApplicationManager*pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};

