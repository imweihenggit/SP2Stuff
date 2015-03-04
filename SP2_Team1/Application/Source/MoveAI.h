#ifndef MOVEAI_H
#define MOVEAI_H
#include "MatrixStack.h"
#include "Vector3.h"
	
bool AImoveZ (MS &model, float &zero, float val);
bool AImoveX (MS &model, float &zero, float val);
bool AImoveY (MS &model, float &zero, float val);
bool AIstop (float &zero, float val);
bool AIrotate (MS &model, Vector3 &pos, float &zero, char axis, float val);

#endif