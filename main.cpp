#include "Application Manager/ApplicationManager.h"


int main()
{
	//Hiding the console window
	HWND hwnd = GetConsoleWindow();
	ShowWindow(hwnd, 0);


	ActionType ActType = TO_DRAW;
	//Create an object of ApplicationManager
	ApplicationManager AppManager;

	do
	{
		//Update the interface
		AppManager.UpdateInterface();

		if (ActType == RESIZE_14 || ActType == RESIZE_12 || ActType == RESIZE_2 || ActType == RESIZE_4)
			AppManager.CreateDrawToolBar();		//To make sure that no drawings will be on the toolbar after resizing

		//Read user action
		ActType = AppManager.GetUserAction();

		//Exexute the action
		AppManager.ExecuteAction(ActType);	

	} while (ActType != EXIT);
	

	
	return 0;
}

