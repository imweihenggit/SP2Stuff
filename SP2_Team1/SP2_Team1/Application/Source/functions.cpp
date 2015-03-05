#include "functions.h"
/******************************************************************************/
/*!
\file	functions.cpp
\author Lim Wei Heng
\par	
\brief
		Detect collision
*/
/******************************************************************************/
/******************************************************************************/
/*!
\brief
Collision positions
*/
/******************************************************************************/
bool Collision(Vector3 charPos, std::vector<CObjects> objList)
{
	float charRad = 5;

		for (int i = 0; i < objList.size(); ++i)
		{
			for (int j = 0; j < objList[i].collisionPos.size(); ++j)
			{
				if ((charPos-objList[i].collisionPos[j]).Length() <= (charRad + objList[i].collisionRad))
				{
					return true;
				}
			}
		}
	
	return false;
}
/******************************************************************************/
/*!
\brief
Collision detections
*/
/******************************************************************************/
bool Collision(Vector3 charPos, std::vector<CObjects> objList, int obj, int pos)
{
	float charRad = 5;

	if ((charPos-objList[obj].collisionPos[pos]).Length() <= (charRad + objList[obj].collisionRad))
		return true;
	else
		return false;
}