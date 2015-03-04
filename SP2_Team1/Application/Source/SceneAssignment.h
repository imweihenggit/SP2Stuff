#ifndef SCENEASSIGNMENT_H
#define SCENEASSIGNMENT_H

#include "Scene.h"
#include "Camera3.h"
#include "Mesh.h"
#include"MatrixStack.h"
#include "Light.h"
#include "global.h"
#include "FPC.h"
#include "Objects.h"
#include "MoveAI.h"
#include <sstream>
#include <fstream>

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
		/* ================================ Glenn's work =====================*/
		U_LIGHT0_TYPE,
		U_LIGHT0_SPOTDIRECTION,
		U_LIGHT0_COSCUTOFF,
		U_LIGHT0_COSINNER,
		U_LIGHT0_EXPONENT,
		U_UI_ENABLED,
		U_UI_COLOR,
		/* ================================ Glenn's work =====================*/
		U_LIGHTENABLED,
		U_NUMLIGHTS,
		U_COLOR_TEXTURE_ENABLED,
		U_COLOR_TEXTURE,
		U_TEXT_ENABLED,
		U_TEXT_COLOR,

		U_TOTAL
	};

	/* ================================ Glenn's work =====================*/
	//for the model blue
	enum MODEL_TYPE_BLUE
	{
		MODEL_BODY_BLUE = 0,
		MODEL_LEFTARM_BLUE,
		MODEL_LEFTFIST_BLUE,
		MODEL_LEFT_LEG_UPPER_BLUE,
		MODEL_LEFT_LEG_LOWER_BLUE,
		MODEL_RIGHTARM_BLUE,
		MODEL_RIGHTFIST_BLUE,
		MODEL_RIGHT_LEG_UPPER_BLUE,
		MODEL_RIGHT_LEG_LOWER_BLUE,
		NUM_MODEL_BLUE,
	};

	//for the model orange
	enum MODEL_TYPE_ORANGE
	{
		MODEL_BODY_ORANGE = 0,
		MODEL_LEFTARM_ORANGE,
		MODEL_LEFTFIST_ORANGE,
		MODEL_LEFT_LEG_UPPER_ORANGE,
		MODEL_LEFT_LEG_LOWER_ORANGE,
		MODEL_RIGHTARM_ORANGE,
		MODEL_RIGHTFIST_ORANGE,
		MODEL_RIGHT_LEG_UPPER_ORANGE,
		MODEL_RIGHT_LEG_LOWER_ORANGE,
		NUM_MODEL_ORANGE,
	};

	//for the model
	enum MODEL_TYPE_PINK
	{
		MODEL_BODY_PINK = 0,
		MODEL_LEFTARM_PINK,
		MODEL_LEFTFIST_PINK,
		MODEL_LEFT_LEG_UPPER_PINK,
		MODEL_LEFT_LEG_LOWER_PINK,
		MODEL_RIGHTARM_PINK,
		MODEL_RIGHTFIST_PINK,
		MODEL_RIGHT_LEG_UPPER_PINK,
		MODEL_RIGHT_LEG_LOWER_PINK,
		NUM_MODEL_PINK,
	};

	/* ================================ Glenn's work =====================*/
	enum GEOMETRY_TYPE
	{
		//level 1 for the supermarket
		GEO_TOP_L1,
		GEO_BOTTOM_L1,
		GEO_LEFT_L1,
		GEO_RIGHT_L1,
		GEO_FRONT_L1,
		GEO_BACK_L1,

		//objects
		GEO_APPLE,
		GEO_ORANGE,
		GEO_WATERMELON,
		GEO_CABBAGE,
		GEO_COCONUT,
		GEO_LODIN,
		GEO_ICECREAM,
		GEO_REGISTER,
		GEO_BASKET,
		GEO_COOLER,
		GEO_CHAR,
		GEO_TENT,	
		GEO_DOORMAN,
		GEO_SHELF,
		GEO_TRAVELATORUP,
		GEO_TRAVELATORDN,
		GEO_BARRIER,
		GEO_PACKET,
		GEO_BOX1,
		GEO_CAN1,
		GEO_BUILDING,

		/* ======================================= Glenn's work ================================== */
		GEO_CASHIER,
		GEO_UI,
		/* ======================================= Glenn's work ================================== */

		//level 2 for the supermarket - Rayner's work
		GEO_TOP2,
		GEO_BOTTOM2,
		GEO_LEFT2,
		GEO_RIGHT2,
		GEO_FRONT2,
		GEO_BACK2,
		

		//Andy's work		
		GEO_LIFT,
		GEO_DOOR,
		GEO_ALARM,
		GEO_LIGHTBALL,
		GEO_TEXT,

		NUM_GEOMETRY
	};

	enum SKYBOX_TYPE
	{
		SKYBOX_FRONT,
		SKYBOX_BACK,
		SKYBOX_LEFT,
		SKYBOX_RIGHT,
		SKYBOX_UP,
		SKYBOX_DOWN,
		SKYBOX_EXTEBANNER,
		SKYBOX_EXTESIDE,
		NUM_SKYBOX
	};

	enum CAMERA_TYPE
	{
		PLAYER_CAM,
		NOCLIP_CAM,
		NUM_CAMERA
	};

public:
	SceneAssignment();
	~SceneAssignment();

	//Init functions
	void InitLevel1();
	void InitLevel2();
	void InitObjects();
	void InitExtSkybox();
	void InitCollision();
	void InitAI();

	/* ================================== Glenn's work ===================*/
	void InitModelBlue();
	void InitModelOrange();
	void InitModelPink();

	void UpdateModelGlenn(double dt);
	void RenderModelGlenn();
	void RenderQuadOnScreen(Mesh* mesh, float x_size, float y_size, float x, float y);
	void ReadFromText();	//this should be linked to RenderTextOnScreen function
	
	//slot in all AI movements here and call to RenderModels();
	void RenderModelBlue();
	void RenderModelOrange();
	void RenderModelPink();
	
	/* ================================== Glenn's work ===================*/

	//Update functions
	void UpdateViewMode(double dt);
	void UpdateDoor(double dt);
	void UpdateLift(double dt);
	void UpdateLight(double dt);
	void UpdateModel(double dt);
	void UpdateTravel(double dt);

	//Render functions
	void RenderLevel1();
	void RenderLevel2();
	void RenderChar();
	void RenderLargeObjects();
	void RenderRightColumn();
	void RenderLeftColumn();
	void RenderMiddleColumn();
	void RenderSmallObjects();
	void RenderModels();
	void RenderOut_Skybox();
	void RenderText(Mesh* mesh, std::string text, Color color);
	void RenderTextOnScreen(Mesh* mesh, std::string text, Color color, float size, float x, float y);

	virtual void Init();
	virtual void Update(double dt);
	virtual void Render();
	virtual void Exit();
private:
	Mesh* meshList[NUM_GEOMETRY];
	Mesh* skyboxList[NUM_SKYBOX];		//for the skybox

	/* =================== Glenn's work ==================== */
	Mesh* modelList2[NUM_MODEL_BLUE];	//blue model animation
	Mesh* modelList6[NUM_MODEL_ORANGE];	//orange model animation
	Mesh* modelList7[NUM_MODEL_PINK];	//pink model animation
	/* =================== Glenn's work ==================== */

	unsigned m_vertexArrayID;
	unsigned m_programID;
	unsigned m_parameters[U_TOTAL];

	//Char movement
	Vector3 charPos;
	Vector3 charDir;
	float yaw, yaw2;
	Mtx44 rot;

	//Door movement
	bool open;
	bool close;
	float DX;
	float DX2;

	//elevator 
	float eley;
	float LiftDoor;
	float LiftDoor2;
	float waitTime, waitTime2;
	bool up;
	bool down;
	bool Lopen;
	bool Lclose;
	bool Lopen2;
	bool Lclose2;
	bool buttonPress, buttonPress2;

	//travelator
	bool travel;
	bool travelDwn;
	bool RenderOn;

	//light
	bool flash;

	//model-related variables
	float rotateAngle;
	float translateX;
	float translateY;
	float translateZ;

	//entrance
	bool open2;
	bool close2;
	float D2X;
	float D2X2;

	//collision
	vector<Vector3> sphere;
	vector<float> radius;
	bool collideT, collideG;

	CAMERA_TYPE camType;
	FPC noClipCamera;
	FPC playerCamera;
	Light light[1];

	void RenderMesh(Mesh *mesh, bool enableLight);

	MS modelStack, viewStack, projectionStack;

	vector<CObjects> ObjectList;
	
	CObjects Skybox1, Skybox2, Basket, Cooler, Shelf, Travellator, Cashier, Elevator, Register, Barrier,firealarm, House,
		     PickUp1, PickUp2, PickUp3,scenerio3;

	float FPS, ET;

	//debug
	bool debug;

	bool render1, render2, render3,renderscenerio3;
	
	CObjects modelPink;
	int pinkSize; // size of  vector
	vector <bool> pinkCheck; //Give each transformation a bool, and set it to true
	vector <float> pinkMove; //Give each transformation a value, and set it to 0

	CObjects modelBlue;
	int blueSize; 
	vector <bool> blueCheck; 
	vector <float> blueMove; 

	CObjects modelOrange;
	int orangeSize; 
	vector <bool> orangeCheck; 
	vector <float> orangeMove; 


};

#endif