#ifndef UTILITY_H
#define UTILITY_H

#include "Mtx44.h"
#include "Vertex.h"
 /******************************************************************************/
/*!
\file	Utility.h
\author Andy Chan
\par	
\brief
		Calculate matrices
*/
/******************************************************************************/
	Position operator*(const Mtx44& lhs, const Position& rhs);

#endif