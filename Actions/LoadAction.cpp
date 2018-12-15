#include"LoadAction.h"

string temp;
char Type;


CRectangle *Rect;
CLine *Line;
CTri *Tri;
CRhom *Rhom;

LoadAction::LoadAction(ApplicationManager *pApp,ifstream& LF):Action(pApp)
{
	LoadFile = &LF;
}

void LoadAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
}

void LoadAction::Execute()
{
	ReadActionParameters();
	cout<<"a";
	int i ;
	while(!LoadFile->eof())
	{
	   getline(*LoadFile,temp);

	   *LoadFile>>Type;cout<<Type;

	   if(Type == 'R')
	   {
		   *LoadFile>>i;cout<<" i"<<i;
		   
		   Rect->Load(*LoadFile);
	   }
	  /* else if(Type=='L')
	   {
		   FigPtr->Load(*LoadFile);
	   }
	   else if(Type == 'T')
	   {
		   FigPtr->Load(*LoadFile);
	   }
	   else if(Type == 'H')
	   {
		   FigPtr->Load(*LoadFile);
	   }
	   else 
	   {
		   FigPtr->Load(*LoadFile);
	   }*/
	}
}