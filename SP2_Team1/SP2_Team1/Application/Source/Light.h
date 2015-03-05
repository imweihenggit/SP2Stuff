#ifndef LIGHT_H
#define LIGHT_H

#include "Vertex.h"

/******************************************************************************/
/*!
\file	Light.h
\author Lim Wei Heng / Andy Chan
\par	
\brief
		Light behaviour, refined by Wei Heng
*/
/******************************************************************************/
/******************************************************************************/
/*!
		Struct Light:
\brief Structure Light for application
*/
/******************************************************************************/

struct Light
{
	Position position;
	Color color;
	float power;
	float kC, kL, kQ;

	enum LIGHT_TYPE
	{
		LIGHT_POINT = 0,
		LIGHT_DIRECTIONAL,
		LIGHT_SPOT,

	};
	LIGHT_TYPE type;
	Vector3 spotDirection;
	float cosCutoff;
	float cosInner;
	float exponent;
	
};


#endif
