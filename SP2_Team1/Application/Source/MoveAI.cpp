#include "MoveAI.h"

bool AImoveZ (MS &model, float &zero, float val, float speed)
{
	model.Translate(0,0,zero);

	if (val > 0)
	{
		if (zero < val)
		{
			zero+=speed;
			return true;
		}
		else
			return false;
	}
	else
	{
		if (zero > val)
		{
			zero-=speed;
			return true;
		}
		else
			return false;
	}
}

bool AImoveX (MS &model, float &zero, float val, float speed)
{
	model.Translate(zero,0,0);

	if (val > 0)
	{
		if (zero < val)
		{
			zero+=speed;
			return true;
		}
		else
			return false;
	}
	else
	{
		if (zero > val)
		{
			zero-=speed;
			return true;
		}
		else
			return false;
	}
}

bool AImoveY (MS &model, float &zero, float val, float speed)
{

	model.Translate(0,zero,0);

	if (val > 0)
	{
		if (zero < val)
		{
			zero+= (speed*((float)11/25));
			return true;
		}
		else
			return false;
	}
	else
	{
		if (zero > val)
		{
			zero-= (speed*((float)11/25));
			return true;
		}
		else
			return false;
	}
}

bool AIstop (float &zero, float val, float speed)
{
	if (zero < val)
	{
		zero += speed;
		return true;
	}
	else
		return false;
}

bool AIrotate (MS &model, Vector3 &pos, float &zero, char axis, float val, float speed)
{
	model.Translate(pos.x,pos.y,pos.z);

	if (axis == 'x')
		model.Rotate(zero,1,0,0);
	else if (axis == 'y')
		model.Rotate(zero,0,1,0);
	else if (axis == 'z')
		model.Rotate(zero,0,0,1);

	model.Translate(-pos.x,-pos.y,-pos.z);

	if (val > 0)
	{
		if (zero < val)
		{
			zero+=speed;
			return true;
		}
		else
			return false;
	}
	else
	{
		if (zero > val)
		{
			zero-=speed;
			return true;
		}
		else
			return false;
	}
}
