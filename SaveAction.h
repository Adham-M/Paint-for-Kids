#pragma once
#include<fstream>


class SaveAction :public Action
{
	ofstream OutFile;
	string fileName;
	string getColorName(color)const;

public:
	SaveAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();

	virtual void Execute();
};
