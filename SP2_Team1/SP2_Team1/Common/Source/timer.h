#ifndef _TIMER_H
#define _TIMER_H

#include <windows.h>

/******************************************************************************/
/*!
\file	timer.h
\author Andy Chan
\par	
\brief
		Timer-related codes
*/
/******************************************************************************/
/******************************************************************************/
/*!
		Class StopWatch:
\brief Stopwatch class to track time
*/
/******************************************************************************/

class StopWatch
{
 
 private:
     
    LARGE_INTEGER frequency;
    LARGE_INTEGER prevTime, currTime;
    double LIToSecs( LARGE_INTEGER & L) ;
    UINT     wTimerRes;

 public:
     StopWatch() ;
     ~StopWatch();
     void startTimer();
     double getElapsedTime(); // get time in seconds since the last call to this function
     void waitUntil(long long time);  // wait until this time in milliseconds has passed
 };


#endif // _TIMER_H