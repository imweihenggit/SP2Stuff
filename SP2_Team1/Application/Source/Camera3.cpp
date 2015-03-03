#include "Camera3.h"
#include "Application.h"
#include "Mtx44.h"
#include "functions.h"

Camera3::Camera3()
{
}

Camera3::~Camera3()
{
}

void Camera3::Init(const Vector3& pos, const Vector3& target, const Vector3& up)
{
	this->position = defaultPosition = pos;
	this->target = defaultTarget = target;
	Vector3 view = (target - position).Normalized();
	Vector3 right = view.Cross(up);
	right.y = 0;
	right.Normalize();
	this->up = defaultUp = right.Cross(view).Normalized();
	cy = 0;
	collideW = collideS = collideD = collideA = false;
}


void Camera3::Update(double dt, std::vector<Vector3> sphere, std::vector<float> radius)
{
	static const float CAMERA_SPEED = 150.f;
	static const float RCAMERA_SPEED = 100.f;
	//forward 
	if(Application::IsKeyPressed('W'))
	{
		if (Application::IsKeyPressed('S') == 0)
		{
		

			Vector3 view = (target - position).Normalized();
			view.y = 0;
			view.Normalize();
			position += view * CAMERA_SPEED * dt;
			target += view * CAMERA_SPEED * dt;

			if (collideW == true && collideS == false)
			{
				position -= view * CAMERA_SPEED * dt;
				target -= view * CAMERA_SPEED * dt;
			}
		}

	}
	//back
	if(Application::IsKeyPressed('S'))
	{
		if (Application::IsKeyPressed('W') == 0)
		{
			

			Vector3 view = (target - position).Normalized();
			view.y = 0;
			view.Normalize();

			position -= view * CAMERA_SPEED * dt;
			target -= view * CAMERA_SPEED * dt;

			if (collideS == true && collideW == false)
			{
				position += view * CAMERA_SPEED * dt;
				target += view * CAMERA_SPEED * dt;
			}
		}
	}
	//left
	if(Application::IsKeyPressed('A'))
	{
		if (Application::IsKeyPressed('D') == 0)
		{
		

			Vector3 view = (target - position).Normalized();
			Vector3 right = view.Cross(up);
			right.y = 0;
			right.Normalize();
			position -= right *CAMERA_SPEED *dt;
			target -= right * CAMERA_SPEED * dt;

			if (collideA == true && collideD == false)
			{
				position += right *CAMERA_SPEED *dt;
				target += right * CAMERA_SPEED * dt;
			}
		}
	}

	//right
	if(Application::IsKeyPressed('D'))
	{
		if (Application::IsKeyPressed('A') == 0)
		{
		

			Vector3 view = (target - position).Normalized();
			Vector3 left = view.Cross(up);
			left.y = 0;
			left.Normalize();
			position += left *CAMERA_SPEED *dt;
			target += left * CAMERA_SPEED * dt;

			if (collideD == true && collideA == false)
			{
				position -= left *CAMERA_SPEED *dt;
				target -= left * CAMERA_SPEED * dt;
			}
		}
	}

	//camera rotation
	//left
	if(Application::IsKeyPressed(VK_LEFT))
	{
		Vector3 view = (target - position).Normalized();
		float yaw = (float)(RCAMERA_SPEED * dt);
		Mtx44 rotation;
		rotation.SetToRotation(yaw, 0, 1, 0);
		view = rotation * view;
		target = view + position;
		Vector3 left = view.Cross(up);
		left.y = 0;
		left.Normalize();
		up = left.Cross(view).Normalized();
	}
	//right
	if(Application::IsKeyPressed(VK_RIGHT))
	{
		Vector3 view = (target - position).Normalized();
		float yaw = (float)(-RCAMERA_SPEED * dt);
		Mtx44 rotation;
		rotation.SetToRotation(yaw, 0, 1, 0);
		view = rotation * view;
		target = view + position;
		Vector3 right = view.Cross(up);
		right.y = 0;
		right.Normalize();
		up = right.Cross(view).Normalized();
	}
	//Up
	if(Application::IsKeyPressed(VK_UP))
	{
	
		//cy += pitch;
		
			float pitch = (float)(RCAMERA_SPEED * dt);
			cy += pitch;
			Vector3 view = (target - position).Normalized();
			Vector3 right = view.Cross(up);
			right.y = 0;
			right.Normalize();
			up = right.Cross(view).Normalized();
			Mtx44 rotation;
			rotation.SetToRotation(pitch, right.x, right.y, right.z);
			view = rotation * view;
			target = view + position;
			 
		
	}
	//down
	if(Application::IsKeyPressed(VK_DOWN))
	{
	
			float pitch = (float)(-RCAMERA_SPEED * dt);
			Vector3 view = (target - position).Normalized();
			Vector3 right = view.Cross(up);
			right.y = 0;
			right.Normalize();
			up = right.Cross(view).Normalized();
			Mtx44 rotation;
			rotation.SetToRotation(pitch, right.x, right.y, right.z);
			view = rotation * view;
			target = view + position;

		
	}
	



	
	if(Application::IsKeyPressed('N'))
	{
		Vector3 direction = target - position;
		if(direction.Length() > 5)
		{
			Vector3 view = (target - position).Normalized();
			position += view * (float)(20.f * dt);
		}
	}
	if(Application::IsKeyPressed('M')&&(position.y < 50))
	{
		Vector3 view = (target - position).Normalized();
		position -= view * (float)(100.f * dt);
	}
	if(Application::IsKeyPressed('R'))
	{
		Reset();
	}
}

void Camera3::Reset()
{
	position = defaultPosition;
	target = defaultTarget;
	up = defaultUp;
}