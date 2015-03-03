#ifndef APPLICATION_H
#define APPLICATION_H

#include "timer.h"

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