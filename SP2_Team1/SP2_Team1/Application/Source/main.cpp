#include "Application.h"
/******************************************************************************/
/*!
\file	main.cpp
\author Wen Sheng Tang
\par	email: tang_wen_sheng\@nyp.edu.sg
\brief
		Run program based on application
*/
/******************************************************************************/
int main( void )
{
	Application app;
	app.Init();
	app.Run();
	app.Exit();
}