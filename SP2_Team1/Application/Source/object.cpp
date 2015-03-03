#include "object.h"

ItemObject::ItemObject(int _id/* = -1*/, string _name/* = ""*/, float _mass/* = 0.0f*/)
{
	id = _id;
	name = _name;
	mass = _mass;
}


ItemObject::~ItemObject(void)
{
}

bool ItemObject ::SetID(int _id)
{
	if (id < 0)
	{
		return false;
	}
	else
	{
		id = _id;
		return true;
	}
}

bool ItemObject::SetName(string _name)
{
	if (_name != "")
	{
		name = _name;
		return true;
	}
	return false;
}

bool ItemObject::SetMass(float _mass)
{
	if (_mass <= 0)
	{
		return false;
	}
	else
	{
		mass = _mass;
		return true;
	}
}

int ItemObject::GetID() const
{
	return id;
}

string ItemObject::GetName() const
{
	return name;
}

float ItemObject::GetMass() const
{
	return mass;
}