#ifndef OBJECT_H
#define OBJECT_H

#include "Scene.h"
#include "Camera3.h"
#include "Mesh.h"
#include"MatrixStack.h"
#include "Light.h"

struct object
{
	object(){};
	object(double x,double y,double z): x(x), y(y), z(z)
	{}
	double x = 0.0;
	double y = 0.0;
	double z = 0.0;
	double w = 0.0;

	const double operator[](const int idx)const
	{
		if(idx ==0) return x;
		if(idx ==1) return y;
		if(idx ==2) return z;
		if(idx ==3) return w;

		assert(0);
	}
}

struct AABB
{
	AABB(): c(),r(){}
	AABB(const object & center,const object & halfwidths): c(center),r(halfwidths)
	{}
	object c;
	object r;
};

#endif