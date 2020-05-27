#ifndef SELECT_ACTION_H
#define SELECT_ACTION_H
 

class SelectAction: public Action
{
private:
	Point P1;
public:
	SelectAction(ApplicationManager *pApp);
	void virtual ReadActionParameters();
	void virtual Execute() ;
};

#endif