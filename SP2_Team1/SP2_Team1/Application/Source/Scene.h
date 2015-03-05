#ifndef SCENE_H
#define SCENE_H
/******************************************************************************/
/*!
\file	Scene.h
\author Andy Chan
\par	
\brief
		Scene Renderer
*/
/******************************************************************************/
/******************************************************************************/
/*!
		Class Scene:
\brief Scene class
*/
/******************************************************************************/
class Scene
{
public:
	Scene() {}
	~Scene() {}

	virtual void Init() = 0;
	virtual void Update(double dt) = 0;
	virtual void Render() = 0;
	virtual void Exit() = 0;
};

#endif