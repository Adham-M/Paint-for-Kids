#pragma once

#include<fstream>


class SaveByTypeAction :public Action
{
	ofstream OutFile;
	string fileName;
	string ShapeType;
	string getColorName(color)const;
	int ClickedItemOrder;

public:
	SaveByTypeAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};

