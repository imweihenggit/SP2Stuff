#ifndef APPLICATION_H
#define APPLICATION_H

#include "timer.h"
/******************************************************************************/
/*!
\file	Application.h
\author Lim Wei Heng
\par	
\brief
Run the application here. Modified by Wei Heng
*/
/******************************************************************************/
/******************************************************************************/
/*!
		Class Application:
\brief Application class
*/
/******************************************************************************/

class Application
{
public:
	Application();
	~Application();
	void Init();
	void Run();
	void Exit();
	static bool IsKeyPressed(unsigned short key);
	static int returnWindowSize(bool X);
	static double GetMouseinput(bool X);
	static void SetMouseinput(double X, double Y);
	static void SetCursor(int i);

private:

	//Declare a window object
	StopWatch m_timer;
};

#endif