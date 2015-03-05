#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <vector>
#include"MatrixStack.h"
#include "Objects.h"

/******************************************************************************/
/*!
\file	Functions.h
\author Lim Wei Heng
\par	
\brief
		Collision detection for application
*/
/******************************************************************************/

bool Collision(Vector3 charPos, std::vector<CObjects> objList);
bool Collision(Vector3 charPos, std::vector<CObjects> objList, int obj, int pos);


#endif