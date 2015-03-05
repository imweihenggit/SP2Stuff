#include "Objects.h"

/******************************************************************************/
/*!
\file	Objects.cpp
\author Lim Wei Heng
\par	
\brief
		Based on object class
*/
/******************************************************************************/
CObjects::CObjects(void)
{
}


CObjects::~CObjects(void)
{
}
/******************************************************************************/
/*!
\brief
	Objects translation, rotation and scaling here
*/
/******************************************************************************/
int CObjects::getTotal(void)
{
	return translateVal.size();
}
