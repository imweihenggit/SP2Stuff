#pragma once
#include "Vector3.h"
#include <vector>
using std::vector;
/******************************************************************************/
/*!
\file	Objects.h
\author Lim Wei Heng
\par	
\brief
		Track objects in the application
*/
/******************************************************************************/
/******************************************************************************/
/*!
		Class Objects:
\brief Objects class
*/
/******************************************************************************/
class CObjects
{
public:
	CObjects(void);
	~CObjects(void);

	int ID;							
	vector<Vector3> translateVal;	
	vector<float> rotateVal;
	vector<Vector3> rotateAxis;
	vector<Vector3> scaleVal;
	vector<Vector3> collisionPos;
	int collisionRad;
	int getTotal(void);
};

