#include "CFigure.h"

CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	//FigGfxInfo.isFilled = false;
	Selected = false;
	sID++;
	ID = sID;
}

int CFigure::sID=0;

void CFigure::SetSelected(bool s)
{	Selected = s; }

bool CFigure::IsSelected() const
{	return Selected; }

int CFigure::GetID() const
{	return ID;	}

void CFigure::SetGfx(GfxInfo f)
{
	FigGfxInfo = f;
}

string CFigure::GetDrawColor() const
{
	if (FigGfxInfo.DrawClr == BLACK)
		return "Black";
	if (FigGfxInfo.DrawClr == WHITE)
		return "White";
	if (FigGfxInfo.DrawClr == RED)
		return "Red";
	if (FigGfxInfo.DrawClr == GREEN)
		return "Green";
	if (FigGfxInfo.DrawClr == BLUE)
		return "Blue";
}

string CFigure::GetFillColor() const
{
	if (!FigGfxInfo.isFilled)
		return "NotFilled";
	if (FigGfxInfo.FillClr == BLACK)
		return "Black";
	if (FigGfxInfo.FillClr == WHITE)
		return "White";
	if (FigGfxInfo.FillClr == RED)
		return "Red";
	if (FigGfxInfo.FillClr == GREEN)
		return "Green";
	if (FigGfxInfo.FillClr == BLUE)
		return "Blue";
}

color CFigure::getColorObject(string name)const
{
	if (name == "NO" || name == "NotFilled")
		return LIGHTGOLDENRODYELLOW;
	else if (name == "RED" || name == "Red")
		return RED;
	else if (name == "BLACK" || name == "Black")
		return BLACK;
	else if (name == "BLUE" || name == "Blue")
		return BLUE;
	else if (name == "GREEN" || name == "Green")
		return GREEN;
	else if (name == "WHITE" || name == "White")
		return WHITE;
}

GfxInfo CFigure::getGfx(string dc, string fc)
{
	GfxInfo g;

	g.DrawClr = getColorObject(dc);
	g.FillClr = getColorObject(fc);

	if (fc == "NotFilled")
		g.isFilled = false;
	else
		g.isFilled = true;

	return g;
}

//void CFigure::SaveFigData()
//{
//	TempFigGfxInfo.BorderWdth = FigGfxInfo.BorderWdth;
//	TempFigGfxInfo.DrawClr = FigGfxInfo.DrawClr;
//	TempFigGfxInfo.FillClr = FigGfxInfo.FillClr;
//	TempFigGfxInfo.isFilled = FigGfxInfo.isFilled;
//	//TempID = ID;
//}
//
//void CFigure::RestoreFigdata()
//{
//	FigGfxInfo = TempFigGfxInfo;
//	ID = TempID;
//}

void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
}

GfxInfo CFigure::GetGfxInfo() const
{
	return FigGfxInfo;
}