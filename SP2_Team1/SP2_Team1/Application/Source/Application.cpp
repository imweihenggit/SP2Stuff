
#include "Application.h"

//Include GLEW
#include <GL/glew.h>

//Include GLFW
#include <GLFW/glfw3.h>

//Include the standard C++ headers
#include <stdio.h>
#include <stdlib.h>

#include "SceneAssignment.h"

GLFWwindow* m_window;
const unsigned char FPS = 120; // FPS of this game
const unsigned int frameTime = 1000 / FPS; // time for each frame

/******************************************************************************/
/*!
\file	Application.cpp
\author Wen Sheng Tang
\par	email: tang_wen_sheng\@nyp.edu.sg
\brief
		Run Application here
*/
/******************************************************************************/


/******************************************************************************/
/*!
\brief
Define an error callback
*/
/******************************************************************************/
static void error_callback(int error, const char* description)
{
	fputs(description, stderr);
	_fgetchar();
}

/******************************************************************************/
/*!
\brief
//Define the key input callback
*/
/******************************************************************************/

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}
/******************************************************************************/
/*!
\brief
// update openg1 the new window size
*/
/******************************************************************************/
void resize_callback(GLFWwindow* window, int w, int h)
{
	glViewport(0, 0, w, h); 
}
/******************************************************************************/
/*!
\brief
React to key pressed by user
*/
/******************************************************************************/
bool Application::IsKeyPressed(unsigned short key)
{
    return ((GetAsyncKeyState(key) & 0x8001) != 0);
}
/******************************************************************************/
/*!
\brief
React to mouse input by user
*/
/******************************************************************************/
double Application::GetMouseinput(bool X)
{
	double POS;
	if(X == true)
	{
		glfwGetCursorPos(m_window, &POS, NULL);
	}

	else
	{
		glfwGetCursorPos(m_window, NULL, &POS);
	}
	return POS;
}
/******************************************************************************/
/*!
\brief
Define initial Mouse input
*/
/******************************************************************************/
void Application::SetMouseinput(double X, double Y)
{
	glfwSetCursorPos(m_window, X, Y);
}
/******************************************************************************/
/*!
\brief
Define initial cursor
*/
/******************************************************************************/
void Application::SetCursor(int i)
{
	if(i == 1)
	{
		glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	}
	if(i == 2)
	{
		glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
	}
}
/******************************************************************************/
/*!
\brief
Return Window size
*/
/******************************************************************************/
int Application::returnWindowSize(bool X)
{
	int returnInt;
	if(X == true)
	{
		glfwGetWindowSize(m_window, &returnInt, NULL);
	}
	else
	{
		glfwGetWindowSize(m_window, NULL, &returnInt);
	}
	return returnInt;
}

Application::Application()
{
}

Application::~Application()
{
}
/******************************************************************************/
/*!
\brief
Logic for Application to work
*/
/******************************************************************************/
void Application::Init()
{
	//Set the error callback
	glfwSetErrorCallback(error_callback);

	//Initialize GLFW
	if (!glfwInit())
	{
		exit(EXIT_FAILURE);
	}

	//Set the GLFW window creation hints - these are optional
	glfwWindowHint(GLFW_SAMPLES, 4); //Request 4x antialiasing
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); //Request a specific OpenGL version
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); //Request a specific OpenGL version
	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //We don't want the old OpenGL 


	//Create a window and create its OpenGL context
	m_window = glfwCreateWindow(800, 600, "Computer Graphics", glfwGetPrimaryMonitor(), NULL);

	//If the window couldn't be created
	if (!m_window)
	{
		fprintf( stderr, "Failed to open GLFW window.\n" );
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	//This function makes the context of the specified window current on the calling thread. 
	glfwMakeContextCurrent(m_window);

	//Sets the key callback
	//glfwSetKeyCallback(m_window, key_callback);
	glfwSetWindowSizeCallback(m_window, resize_callback);

	glewExperimental = true; // Needed for core profile
	//Initialize GLEW
	GLenum err = glewInit();

	//If GLEW hasn't initialized
	if (err != GLEW_OK) 
	{
		fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
		//return -1;
	}

	/*-------------------------------------------------!! UPDATE NEEDED (WEI HENG) !!----------------------------------------------------*/
	glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
	/*-------------------------------------------------!! UPDATE NEEDED (WEI HENG) !!----------------------------------------------------*/
}
/******************************************************************************/
/*!
\brief
Run these codes when Application is running
*/
/******************************************************************************/
void Application::Run()
{
	//Main Loop
	Scene *scene = new SceneAssignment();
	ShowCursor(FALSE);
	scene->Init();

	m_timer.startTimer();    // Start timer to calculate how long it takes to render this frame
	while (!glfwWindowShouldClose(m_window))
	{
		scene->Update(m_timer.getElapsedTime());
		scene->Render();
		//Swap buffers
		glfwSwapBuffers(m_window);
		glfwSwapInterval(1);
		//Get and organize events, like keyboard and mouse input, window resizing, etc...
		glfwPollEvents();
        m_timer.waitUntil(frameTime);       // Frame rate limiter. Limits each frame to a specified time in ms.   

		if (SceneAssignment::bReset)
		{
			scene->Exit();
			delete scene;
			scene = new SceneAssignment();
			scene->Init();
		}

	} //Check if the ESC key had been pressed or if the window had been closed
	scene->Exit();
	delete scene;
}
/******************************************************************************/
/*!
\brief
Destroy everything before exiting
*/
/******************************************************************************/
void Application::Exit()
{
	//Close OpenGL window and terminate GLFW
	glfwDestroyWindow(m_window);
	//Finalize and clean up GLFW
	glfwTerminate();
}
