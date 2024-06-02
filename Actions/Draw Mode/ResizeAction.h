#pragma once

class ResizeAction : public Action
{
	CFigure* fig2resize;
	float factor;
public:
	ResizeAction(ApplicationManager*, float);
	void virtual ReadActionParameters();
	void virtual Execute();
};