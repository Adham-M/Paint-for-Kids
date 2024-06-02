#pragma once
#include <iostream>
using namespace std;

#include "fstream"


class LoadAction :public Action
{
private:
	ifstream InputFile;
	string fileName;
public:
	LoadAction(ApplicationManager *pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

};
