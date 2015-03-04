#ifndef CAMERA_3_H
#define CAMERA_3_H

#include "Camera.h"
#include <vector>

class Camera3 : public Camera
{
private:
	float cy;
public:
	Vector3 position;
	Vector3 target;
	Vector3 up;

	Vector3 defaultPosition;
	Vector3 defaultTarget;
	Vector3 defaultUp;

	Camera3();
	~Camera3();
	virtual void Init(const Vector3& pos, const Vector3& target, const Vector3& up);
	virtual void Update(double dt,std::vector<Vector3> sphere, std::vector<float> radius);
	virtual void Reset();

	bool collideW, collideS, collideA, collideD;
};

#endif