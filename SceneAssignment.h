#ifndef SCENEASSIGNMENT_H
#define SCENEASSIGNMENT_H

#include "Scene.h"
#include "Camera3.h"
#include "Mesh.h"
#include"MatrixStack.h"
#include "Light.h"

class SceneAssignment : public Scene
{
	enum UNIFORM_TYPE
	{
		U_MVP = 0,
		U_MODELVIEW,
		U_MODELVIEW_INVERSE_TRANSPOSE,
		U_MATERIAL_AMBIENT,
		U_MATERIAL_DIFFUSE,
		U_MATERIAL_SPECULAR,
		U_MATERIAL_SHININESS,
		U_LIGHT0_POSITION,
		U_LIGHT0_COLOR,
		U_LIGHT0_POWER,
		U_LIGHT0_KC,
		U_LIGHT0_KL,
		U_LIGHT0_KQ,
		U_LIGHTENABLED,
		U_NUMLIGHTS,
		U_COLOR_TEXTURE_ENABLED,
		U_COLOR_TEXTURE,

		U_TOTAL,
	};
	enum GEOMETRY_TYPE
	{
		GEO_AXES,
		GEO_QUAD,
		GEO_LIGHTBALL,

		
		//level 1 for the supermarket
		GEO_TOP_L1,
		GEO_BOTTOM_L1,
		GEO_LEFT_L1,
		GEO_RIGHT_L1,
		GEO_FRONT_L1,
		GEO_BACK_L1,

		//level 2 for the supermarket
		GEO_TOP2,
		GEO_BOTTOM2,
		GEO_LEFT2,
		GEO_RIGHT2,
		GEO_FRONT2,
		GEO_BACK2,
	
		//model
		GEO_CHAR,
		GEO_TENT,
		GEO_LIFT,
		GEO_DOORMAN,
		NUM_GEOMETRY,
	};

public:
	SceneAssignment();
	~SceneAssignment();

	void RenderSkybox();
	void RenderLevel1();
	void RenderLevel2();
	
	void RenderChar();

	virtual void Init();
	virtual void Update(double dt);
	virtual void Render();
	virtual void Exit();
private:
	Mesh* meshList[NUM_GEOMETRY];
	unsigned m_vertexArrayID;
	unsigned m_programID;
	unsigned m_parameters[U_TOTAL];
	
	//camera
	float cy;
	float cx;
	float cz;
	//Char movement
	float Y;
	float Z;
	float X;
	//Door movement
	bool open;
	bool close;
	bool KeyBindC;
	float DX;

	//ele
	float eley;
	bool up;
	bool down;




	Camera3	camera;
	Light light[1];

	void RenderMesh(Mesh *mesh, bool enableLight);

	MS modelStack, viewStack, projectionStack;
};

#endif