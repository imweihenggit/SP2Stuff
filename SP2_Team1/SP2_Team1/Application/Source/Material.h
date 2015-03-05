#ifndef MATERIAL_H
#define MATERIAL_H

/******************************************************************************/
/*!
\file	Material.h
\author Andy Chan
\par	
\brief
		Material codes to calculate light behavior
*/
/******************************************************************************/
/******************************************************************************/
/*!
		Struct Component and Material:
\brief Component and Material structures
*/
/******************************************************************************/

struct Component
	{
	float r, g, b;
	Component(float r = 0.1f, float g = 0.1f, float b = 0.1f) 
	{Set(r, g, b);}
	void Set(float r, float g, float b) 
	{this->r = r; this->g = g; this->b = b;}
};
struct Material
{
	Component kAmbient;
	Component kDiffuse;
	Component kSpecular;
	float kShininess;
	//to do: add a constructor
};

#endif
