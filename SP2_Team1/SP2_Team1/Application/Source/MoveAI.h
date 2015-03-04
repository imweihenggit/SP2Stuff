#ifndef MOVEAI_H
#define MOVEAI_H
#include "MatrixStack.h"
#include "Vector3.h"
	
bool AImoveZ (MS &model, float &zero, float val, float speed = 1);
bool AImoveX (MS &model, float &zero, float val, float speed = 1);
bool AImoveY (MS &model, float &zero, float val, float speed = 1);
bool AIstop (float &zero, float val, float speed = 1);
bool AIrotate (MS &model, Vector3 &pos, float &zero, char axis, float val, float speed = 2);

#endif