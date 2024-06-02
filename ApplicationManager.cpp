#include "ApplicationManager.h"


//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();

	FigCount = 0;
	TempFigcount = 0;
	OneIsSelected = false;
	OneIsCopied = false;
	OneIsCut = false;
	SelectedFig = NULL;
	Clipboard = NULL;

	//TempFig = NULL;

	//Create an array of figure pointers and set them to NULL		
	for (int i = 0; i < MaxFigCount; i++)
		FigList[i] = NULL;
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType)
{
	Action* pAct = NULL;

	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
	case DRAW_RECT:
		pAct = new AddRectAction(this);
		break;

	case DRAW_LINE:
		pAct = new AddLineAction(this);
		break;

	case DRAW_TRI:
		pAct = new AddTriAction(this);
		break;

	case DRAW_RHOMBUS:
		pAct = new AddRhombAction(this);
		break;

	case DRAW_ELLIPSE:
		pAct = new AddEllipAction(this);
		break;

	case SELECT:
		pAct = new SelectAction(this);
		break;

	case CHNG_FILL_CLR:
		pAct = new ChangeFColorAction(this);
		break;

	case CHNG_DRAW_CLR:
		pAct = new ChangeDColorAction(this);
		break;

	case PICK_FIG:
		pAct = new PickFigAction(this);
		break;

	case PICK_COLOR:
		pAct = new PickColorAction(this);
		break;

	case RESTART:
		pAct = new RestartAction(this);
		break;

	case SAVE:
		pAct = new SaveAction(this);
		break;

	case SAVE_BY_TYPE:
		pAct = new SaveByTypeAction(this);
		break;

	case LOAD:
		pAct = new LoadAction(this);
		break;

	case COPY:
		pAct = new CopyAction(this);
		break;

	case CUT:
		pAct = new CutAction(this);
		break;

	case PASTE:
		pAct = new PasteAction(this);
		break;

	case DEL:
		pAct = new DeleteAction(this);
		break;

	case RESIZE_14:
		pAct = new ResizeAction(this, 0.25);
		break;

	case RESIZE_12:
		pAct = new ResizeAction(this, 0.5);
		break;

	case RESIZE_2:
		pAct = new ResizeAction(this, 2);
		break;

	case RESIZE_4:
		pAct = new ResizeAction(this, 4);
		break;

	case BRING_TO_FRONT:
		pAct = new Set2BkOrFrntAction(this, 1);
		break;

	case BRING_TO_BACK:
		pAct = new Set2BkOrFrntAction(this, 0);
		break;

	case TO_PLAY:
		pAct = new ToPlayMode(this);
		break;

	case TO_DRAW:
		pAct = new ToDrawMode(this);
		break;

	case EXIT:
		pAct = new ExitAction(this);
		break;

	case STATUS:	//a click on the status bar ==> no action
		return;

	}

	//Execute the created action
	if (pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//Action is not needed any more ==> delete it
		pAct = NULL;
	}
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if (FigCount < MaxFigCount)
		FigList[FigCount++] = pFig;
}
////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(int x, int y) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL
	for (int i = FigCount - 1; i >= 0; i--)
	{
		if (FigList[i]->Pointinorout(x, y))
		{
			return FigList[i];
		}
	}

	//Add your code here to search for a figure given a point x,y	
	//Remember that ApplicationManager only calls functions do NOT implement it.

	return NULL;
}


bool ApplicationManager::AFigIsCopied()
{
	return OneIsCopied;
}
bool ApplicationManager::AFigIsCut()
{
	return OneIsCut;
}
bool ApplicationManager::AFigIsSelected()
{
	return OneIsSelected;
}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//
int ApplicationManager::GetFigCount() const { return FigCount; }
CFigure* ApplicationManager::GetSelectedFig() const { return SelectedFig; }
CFigure* ApplicationManager::GetClipBFig() const { return Clipboard; }
void ApplicationManager::CreateDrawToolBar() const { pOut->CreateDrawToolBar(); }
void ApplicationManager::SetSelectFig(CFigure* Fig)
{
	if (OneIsSelected)
	{
		SelectedFig->SetSelected(false);
		SelectedFig = Fig;
		SelectedFig->SetSelected(true);
	}
	else
	{
		SelectedFig = Fig;
		if (SelectedFig->IsSelected())
		{
			SelectedFig->SetSelected(false);
			OneIsSelected = false;
		}
		else if (SelectedFig != NULL)
		{
			SelectedFig->SetSelected(true);
			OneIsSelected = true;
		}
		else if (Fig == SelectedFig)
		{
			SelectedFig->SetSelected(false);
			SelectedFig = NULL;
		}
	}
}

void ApplicationManager::Setfree()
{
	SelectedFig->SetSelected(false);
	SelectedFig = NULL;
	OneIsSelected = false;
}

void ApplicationManager::ClearFigList()
{
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i] != NULL)
		{
			DeleteSelected(FigList[i]);
			FigList[i] = NULL;
		}
	}
	FigCount = 0;
	SelectedFig = NULL;
}

void ApplicationManager::SetTempFigList()
{
	TempFigcount = FigCount;
	for (int i = 0; i < FigCount; i++)
		TempFigList[i] = FigList[i];
}

void ApplicationManager::DeleteSelected(CFigure*fig)
{
	SelectedFig = fig;
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i] == fig)
		{
			for (int j = i; j < FigCount - 1; j++)
				FigList[j] = FigList[j + 1];
			FigList[FigCount] = NULL;
			FigCount--;
		}
	}
	pOut->ClearDrawArea();
}

void ApplicationManager::ResizeSelected(CFigure* fig, float f)
{
	fig->Resize(f);
	pOut->ClearDrawArea();
}

void ApplicationManager::BringToFront(CFigure* fig)
{
	int p;
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i] == fig)
		{
			p = i;
			break;
		}
	}
	for (int i = p; i < FigCount - 1; i++)
		FigList[i] = FigList[i + 1];

	FigList[FigCount - 1] = fig;
}

void ApplicationManager::BringToBack(CFigure* fig)
{
	int p;
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i] == fig)
		{
			p = i;
			break;
		}
	}
	for (int i = p; i > 0; i--)
		FigList[i] = FigList[i - 1];

	FigList[0] = fig;
}

void ApplicationManager::SaveFigData()
{
	GfxInfo G = SelectedFig->GetGfxInfo();
	TempFigGfxInfo.BorderWdth = G.BorderWdth;
	TempFigGfxInfo.DrawClr = G.DrawClr;
	TempFigGfxInfo.FillClr = G.FillClr;
	TempFigGfxInfo.isFilled = G.isFilled;
}

void ApplicationManager::SetClipB()
{
	Clipboard = SelectedFig;
	SaveFigData();
	//Clipboard->SaveFigData();
}

void ApplicationManager::FreeCutFig()
{
	Clipboard = NULL;
	OneIsCut = false;
}

void ApplicationManager::Copy()
{
	SetClipB();
	OneIsCopied = true;
	OneIsCut = false;
}

void ApplicationManager::Cut()
{
	SetClipB();
	Clipboard->ChngFillClr(GREY);
	OneIsCut = true;
	OneIsCopied = false;
}

void ApplicationManager::Paste(CFigure*a, Point P)
{
	Clipboard->SetGfx(TempFigGfxInfo);
	if (OneIsCopied)
	{
		Clipboard->Copy(a, TempFigGfxInfo, P);
		AddFigure(a);
	}
	else if (OneIsCut)
	{
		Clipboard->Copy(a, TempFigGfxInfo, P);
		AddFigure(a);
		DeleteSelected(Clipboard);
		pOut->ClearDrawArea();
		FreeCutFig();
	}
}

void ApplicationManager::SaveAll(ofstream&OutFile)
{
	for (int i = 0; i < FigCount; i++)
		FigList[i]->Save(OutFile);
}

void ApplicationManager::SaveByType(ofstream&OutFile, string ShapeType)
{
	for (int i = 0; i < FigCount; i++)
		if (FigList[i]->GetType() == ShapeType)
			FigList[i]->Save(OutFile);
}

int ApplicationManager::CountSpecificFigType(string ShapeType)
{
	SpecificFigType = 0;
	for (int i = 0; i < FigCount; i++)
		if (FigList[i]->GetType() == ShapeType)
			SpecificFigType++;

	return SpecificFigType;
}


void ApplicationManager::DeleteAllFig()
{
	for (int i = 0; i < FigCount; i++)
		if (FigList[i])
			delete FigList[i];

	for (int i = 0; i < TempFigcount; i++)
		if (TempFigList[i])
			delete TempFigList[i];

}
///////////////////////////////////////////////////////////////////
string ApplicationManager::GetRandFig() const
{
	int x;
	if (FigCount != 0)
	{
		x = rand() % (FigCount);
		return FigList[x]->GetType();
	}
	return ".";
}

int ApplicationManager::GetRandFigCount(string s) const
{ //This function get the count of the previously randomly generated figure
	int n = 0;
	for (int i = 0; i < FigCount; i++)
		if (s == FigList[i]->GetType())
			n++;
	return n;
}

string ApplicationManager::GetRandColor() const
{
	int x;
	if (FigCount != 0)
	{
		x = rand() % (FigCount);
		return FigList[x]->GetFillColor();
	}
	return ".";
}

int ApplicationManager::GetRandColorCount(string s) const
{ //This function get the count of the previously randomly generated color
	int n = 0;
	for (int i = 0; i < FigCount; i++)
		if (s == FigList[i]->GetFillColor())
			n++;
	return n;
}

///////////////////////////////////////////////////////////////////
//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{
	for (int i = 0; i < FigCount; i++)
		FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
}

void ApplicationManager::RestoreTempFig()
{
	//ClearFigList();
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i])
			FigList[i] = NULL;
	}
	FigCount = 0;
	pOut->ClearDrawArea();
	for (int i = 0; i < TempFigcount; i++)
		AddFigure(TempFigList[i]);
	pOut->ClearDrawArea();
}

////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{
	return pIn;
}
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{
	return pOut;
}
////////////////////////////////////////////////////////////////////////////////////


//Destructor
ApplicationManager::~ApplicationManager()
{
	DeleteAllFig();
	delete pIn;
	delete pOut;
}