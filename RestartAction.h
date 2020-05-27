#pragma once


class RestartAction : public Action
{
public:
	RestartAction(ApplicationManager*);
	void virtual ReadActionParameters();
	void virtual Execute();
};