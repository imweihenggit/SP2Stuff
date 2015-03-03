#include "functions.h"

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
bool Collision(Vector3 charPos, std::vector<CObjects> objList, int obj, int pos)
{
	float charRad = 5;

	if ((charPos-objList[obj].collisionPos[pos]).Length() <= (charRad + objList[obj].collisionRad))
		return true;
	else
		return false;
}