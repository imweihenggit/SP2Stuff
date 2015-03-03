#ifndef FPC_H
#define FPC_H

#include "Camera.h"
#include <vector>
#include "Objects.h"
using std::vector;

class FPC : public Camera
{
public:
	FPC();
	~FPC();

	bool move;
	
	virtual void Init(const Vector3& pos, const Vector3& target, const Vector3& up, bool _allowFlight = false);
	virtual void Set(const Vector3& pos, const Vector3& target, const Vector3& up, bool _allowFlight = false);
	virtual void SetSensitivity(float _mouseSensX, float _mouseSensY);
	virtual void SetSpeed(float _moveSpeed, float _rotSpeed);
	virtual void SetFlight(bool _allowFlight = true);
	virtual void Update(double dt, vector<CObjects> list);
	virtual void Reset();

private:
	// For resetting camera
	Vector3 defaultPosition;
	Vector3 defaultTarget;
	Vector3 defaultUp;
	float defaultMoveSpeed;
	float defaultRotSpeed;

	// Controls max pitch
	float pitchDist;

	// Toggles
	bool allowFlight;
	
	// Mouse sensitivity
	float mouseSensX;
	float mouseSensY;

	bool collideW, collideS, collideA, collideD;
};

#endif