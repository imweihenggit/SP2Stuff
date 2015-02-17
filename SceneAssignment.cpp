#include "SceneAssignment.h"
#include "LoadTGA.h"
#include "GL\glew.h"
#include "shader.hpp"
#include "Mtx44.h"

#include "Application.h"
#include "MeshBuilder.h"
#include "Utility.h"

//check X,Y,Z
#include <iostream>
using namespace std;

SceneAssignment::SceneAssignment()
{
}

SceneAssignment::~SceneAssignment()
{
}

void SceneAssignment::Init()
{
	// Init VBO here
	
	//Character X,Y,Z
	X = 0;
	Y = -45;
	Z = 0;
	//camera
	cx = 1;
	cy = -43;
	cz = 1;
	//Door
	DX = 0;
	open = false;
	close = false;
	KeyBindC = false;
	//ele
	eley =0;
	up = false;
	down = false;
	
	
	
	// Set background color to dark blue
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	//Enable depth buffer and depth testing
	glEnable(GL_DEPTH_TEST);

	//Enable back face culling
	glEnable(GL_CULL_FACE);

	// Enable blending(Practical 9)
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	//Default to fill mode
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	// Generate a default VAO for now
	glGenVertexArrays(1, &m_vertexArrayID);
	glBindVertexArray(m_vertexArrayID);
	
	//Load vertex and fragment shaders
	//new shaders(Practical 9)
	m_programID = LoadShaders( "Shader//Texture.vertexshader", "Shader//Blending.fragmentshader" );

	// Use our shader
	glUseProgram(m_programID);
	// Get a handle for our "MVP" uniform
	m_parameters[U_MVP] = glGetUniformLocation(m_programID, "MVP");
	m_parameters[U_MODELVIEW] = glGetUniformLocation(m_programID, "MV");
	m_parameters[U_MODELVIEW_INVERSE_TRANSPOSE] = glGetUniformLocation(m_programID, "MV_inverse_transpose");
	m_parameters[U_MATERIAL_AMBIENT] = glGetUniformLocation(m_programID, "material.kAmbient");
	m_parameters[U_MATERIAL_DIFFUSE] = glGetUniformLocation(m_programID, "material.kDiffuse");
	m_parameters[U_MATERIAL_SPECULAR] = glGetUniformLocation(m_programID, "material.kSpecular");
	m_parameters[U_MATERIAL_SHININESS] = glGetUniformLocation(m_programID, "material.kShininess");
	m_parameters[U_LIGHT0_POSITION] = glGetUniformLocation(m_programID, "lights[0].position_cameraspace");
	m_parameters[U_LIGHT0_COLOR] = glGetUniformLocation(m_programID, "lights[0].color");
	m_parameters[U_LIGHT0_POWER] = glGetUniformLocation(m_programID, "lights[0].power");
	m_parameters[U_LIGHT0_KC] = glGetUniformLocation(m_programID, "lights[0].kC");
	m_parameters[U_LIGHT0_KL] = glGetUniformLocation(m_programID, "lights[0].kL");
	m_parameters[U_LIGHT0_KQ] = glGetUniformLocation(m_programID, "lights[0].kQ");
	m_parameters[U_LIGHTENABLED] = glGetUniformLocation(m_programID, "lightEnabled");
	
	m_parameters[U_NUMLIGHTS] = glGetUniformLocation(m_programID, "numLights"); //in case you missed out practical 7

	// Get a handle for our "colorTexture" uniform
	m_parameters[U_COLOR_TEXTURE_ENABLED] = glGetUniformLocation(m_programID, "colorTextureEnabled");
	m_parameters[U_COLOR_TEXTURE] = glGetUniformLocation(m_programID, "colorTexture");

	glUseProgram(m_programID);

	light[0].position.Set(0, 20, 0);
	light[0].color.Set(1, 1, 1);
	light[0].power = 1;
	light[0].kC = 1.f;
	light[0].kL = 0.01f;
	light[0].kQ = 0.001f;

	// Make sure you pass uniform parameters after glUseProgram()
	glUniform3fv(m_parameters[U_LIGHT0_COLOR], 1, &light[0].color.r);
	glUniform1f(m_parameters[U_LIGHT0_POWER], light[0].power);
	glUniform1f(m_parameters[U_LIGHT0_KC], light[0].kC);
	glUniform1f(m_parameters[U_LIGHT0_KL], light[0].kL);
	glUniform1f(m_parameters[U_LIGHT0_KQ], light[0].kQ);
	glUniform1i(m_parameters[U_NUMLIGHTS], 1);

	//Initialize camera settings
	camera.Init(Vector3(5, 5, 0), Vector3(0, 0, 0), Vector3(0, 1, 0));

	//remove all glGenBuffers, glBindBuffer, glBufferData code
	meshList[GEO_AXES] = MeshBuilder::GenerateAxes("reference", 1000, 1000, 1000);
	//meshList[GEO_QUAD] = MeshBuilder::GenerateQuad("quad", 1, 1)

	//light
	meshList[GEO_LIGHTBALL] = MeshBuilder::GenerateSphere("lightball", Color(1 ,1, 1), 10, 10, 1);
	
	//Level1 of the supermarket(too big so pls resize to the base on doorman 5,5,5 scaling)
	//Top
	meshList[GEO_TOP_L1] = MeshBuilder::GenerateQuad("top", Color(1, 1, 1), 1.f);
	meshList[GEO_TOP_L1]->textureID = LoadTGA("Image//supermarket texture_blue.tga");
	//Bottom
	meshList[GEO_BOTTOM_L1] = MeshBuilder::GenerateQuad("bottom", Color(1, 1, 1), 1.f);
	meshList[GEO_BOTTOM_L1]->textureID = LoadTGA("Image//supermarket texture_floor.tga");

	//Left
	meshList[GEO_LEFT_L1] = MeshBuilder::GenerateQuad("left", Color(1, 1, 1), 1.f);
	meshList[GEO_LEFT_L1]->textureID = LoadTGA("Image//supermarket texture_blue.tga");
	
	//right
	meshList[GEO_RIGHT_L1] = MeshBuilder::GenerateQuad("right", Color(1, 1, 1), 1.f);
	meshList[GEO_RIGHT_L1]->textureID = LoadTGA("Image//supermarket texture_green.tga");

	//Front
	meshList[GEO_FRONT_L1] = MeshBuilder::GenerateQuad("front", Color(1, 1, 1), 1.f);
	meshList[GEO_FRONT_L1]->textureID = LoadTGA("Image//supermarket texture_blue.tga");
	
	//back
	meshList[GEO_BACK_L1] = MeshBuilder::GenerateQuad("back", Color(1, 1, 1), 1.f);
	meshList[GEO_BACK_L1]->textureID = LoadTGA("Image//supermarket texture_blue.tga");
	
	//Lv 2 of supermarket
	//Top
	meshList[GEO_TOP2] = MeshBuilder::GenerateQuad("top", Color(1, 1, 1), 1.f);
	meshList[GEO_TOP2]->textureID = LoadTGA("Image//supermarket texture_blue.tga");
	//Bottom
	meshList[GEO_BOTTOM2] = MeshBuilder::GenerateQuad("bottom", Color(1, 1, 1), 1.f);
	meshList[GEO_BOTTOM2]->textureID = LoadTGA("Image//supermarket texture_floor.tga");

	//Left
	meshList[GEO_LEFT2] = MeshBuilder::GenerateQuad("left", Color(1, 1, 1), 1.f);
	meshList[GEO_LEFT2]->textureID = LoadTGA("Image//supermarket texture_blue.tga");
	
	//right
	meshList[GEO_RIGHT2] = MeshBuilder::GenerateQuad("right", Color(1, 1, 1), 1.f);
	meshList[GEO_RIGHT2]->textureID = LoadTGA("Image//supermarket texture_green.tga");

	//Front
	meshList[GEO_FRONT2] = MeshBuilder::GenerateQuad("front", Color(1, 1, 1), 1.f);
	meshList[GEO_FRONT2]->textureID = LoadTGA("Image//supermarket texture_blue.tga");
	
	//back
	meshList[GEO_BACK2] = MeshBuilder::GenerateQuad("back", Color(1, 1, 1), 1.f);
	meshList[GEO_BACK2]->textureID = LoadTGA("Image//supermarket texture_blue.tga");

	//Character
	meshList[GEO_CHAR] = MeshBuilder::GenerateSphere("fho", Color(0, 1, 3), 36, 180, 10.f);

	//lift
	meshList[GEO_TENT] = MeshBuilder::GenerateOBJ("tent", "OBJ//lift.obj");
	meshList[GEO_TENT]->textureID = LoadTGA("Image//lift_m.tga");
	meshList[GEO_TENT]->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
	meshList[GEO_TENT]->material.kDiffuse.Set(0.5f, 0.5f, 0.5f);
	meshList[GEO_TENT]->material.kSpecular.Set(1.0f, 1.0f, 1.0f);
	meshList[GEO_TENT]->material.kShininess = 50.f;

	meshList[GEO_DOORMAN] = MeshBuilder::GenerateOBJ("man", "OBJ//doorman.obj");
	meshList[GEO_DOORMAN]->textureID = LoadTGA("Image//doorman.tga");
	meshList[GEO_DOORMAN]->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
	meshList[GEO_DOORMAN]->material.kDiffuse.Set(0.5f, 0.5f, 0.5f);
	meshList[GEO_DOORMAN]->material.kSpecular.Set(1.0f, 1.0f, 1.0f);
	meshList[GEO_DOORMAN]->material.kShininess = 50.f;

	Mtx44 projection;
	projection.SetToPerspective(45.f, 4.f / 3.f, 0.1f, 100000.f);
	projectionStack.LoadMatrix(projection);
}

static float LSPEED = 20.f;
static float ROT_LIMIT = 45.f;
static float SCALE_LIMIT = 5.f;

void SceneAssignment::Update(double dt)
{
	if(Application::IsKeyPressed('1')) //enable back face culling
		glEnable(GL_CULL_FACE);
	if(Application::IsKeyPressed('2')) //disable back face culling
		glDisable(GL_CULL_FACE);
	if(Application::IsKeyPressed('3'))
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); //default fill mode
	if(Application::IsKeyPressed('4'))
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); //wireframe mode

	if(Application::IsKeyPressed('I'))
		light[0].position.z -= (float)(LSPEED * dt);
	if(Application::IsKeyPressed('K'))
		light[0].position.z += (float)(LSPEED * dt);
	if(Application::IsKeyPressed('J'))
		light[0].position.x -= (float)(LSPEED * dt);
	if(Application::IsKeyPressed('L'))
		light[0].position.x += (float)(LSPEED * dt);
	if(Application::IsKeyPressed('O'))
		light[0].position.y -= (float)(LSPEED * dt);
	if(Application::IsKeyPressed('P'))
		light[0].position.y += (float)(LSPEED * dt);
	
	
	if(Application::IsKeyPressed('T'))
	{
		Z -=(float)(10 * dt);
		
		
	}
	if(Application::IsKeyPressed('G'))
	{
		Z +=(float)(10 * dt);
		
	}
	if(Application::IsKeyPressed('F'))
	{
		X -=(float)(10 * dt);
		
		
	}
	if(Application::IsKeyPressed('H'))
	{
		X +=(float)(10 * dt);
	}
	//Door bool
	if(open)
	{
		DX +=(float)(5 * dt);
	}
	if(close)
	{
		DX -=(float)(5 * dt);
	}
	if(KeyBindC)
	{
		Application::IsKeyPressed('C');
	}
	if (Application::IsKeyPressed('C')&&(DX <1))
	{
		open = true;
	}
	else if (Application::IsKeyPressed('C')&&(DX >=10))
	{
		open = false;
		close = true;
	}
	//INTERACTION 1
	if(Z < -35)
	{
		KeyBindC = true;
		
	}
	else if(Z > -35)
	{
		KeyBindC= false;
		open = false;
	}

	if(DX > 10)
	{
		open = false;
	}
	else if (DX < 0)
	{
		close = false;
	}
	
	//Interation2
	if(up)
	{
		eley +=(float)(10 * dt);
		
		cy +=(float)(10 * dt);
		camera.position.y +=(float)(10 * dt);
		camera.target.y +=(float)(10 * dt);
		
	}
	if(down)
	{
		eley -=(float)(10 * dt);
		cy -=(float)(10 * dt);
		camera.position.y -=(float)(10 * dt);
		camera.target.y -=(float)(10 * dt);
	}

	//level1-2
	if (Application::IsKeyPressed('C')&&(eley < -20)&&((camera.position.z >= -5)&&(camera.position.z <= 5)) && ((camera.position.x >= -48)&&(camera.position.x <= -38)))
	{
		up = true;
	}
	if ((eley <= -20) && (eley >= -22)&&(up == true))
	{
		up = false;
		eley +=1;
		Y+=1;
	}
	//level2-3
	if (Application::IsKeyPressed('C')&&((eley >= -22)&&(eley <= 10)))
	{
		up = true;
	}
	if (eley >= 10 )
	{
		up = false;
	}
	//down
	//level3-2
	if (Application::IsKeyPressed('V')&&(eley >= 10))
	{
		down = true;
	}
	if ((eley <= -20) && (eley >= -22) &&(down == true))
	{
		down = false;
		eley -=1;
		Y -=1;
		
	}
	//level2-1
	if (Application::IsKeyPressed('V')&&((eley <= -21)&&(eley >= -49.5))&&(down == false))
	{
		down = true;
	}
	
	if (eley <= -49.5 )
	{
		down = false;
	}

	//Lv 2 supermarket codes
	if(camera.position.x >= 396)
	{
		camera.position.x = 396;
	}
	if(camera.position.x <= -396)
	{
		camera.position.x = -396;
	}
	if(camera.position.y >= 700)
	{
		camera.position.y = 700;
	}
	if(camera.position.y <= -700)
	{
		camera.position.y = -700;
	}
	if(camera.position.z >= 323)
	{
		camera.position.z = 323;
	}
	if(camera.position.z <= -323)
	{
		camera.position.z = -323;
	}


	camera.Update(dt);

}
void SceneAssignment::RenderMesh(Mesh *mesh, bool enableLight)
{
	Mtx44 MVP, modelView, modelView_inverse_transpose;

	MVP = projectionStack.Top() * viewStack.Top() * modelStack.Top();
	glUniformMatrix4fv(m_parameters[U_MVP], 1, GL_FALSE, &MVP.a[0]);
	if(enableLight)
	{
		glUniform1i(m_parameters[U_LIGHTENABLED], 1);
		modelView = viewStack.Top() * modelStack.Top();
		glUniformMatrix4fv(m_parameters[U_MODELVIEW], 1, GL_FALSE, &modelView.a[0]);
		modelView_inverse_transpose = modelView.GetInverse().GetTranspose();
		glUniformMatrix4fv(m_parameters[U_MODELVIEW_INVERSE_TRANSPOSE], 1, GL_FALSE, &modelView_inverse_transpose.a[0]);

		//load material
		glUniform3fv(m_parameters[U_MATERIAL_AMBIENT], 1, &mesh->material.kAmbient.r);
		glUniform3fv(m_parameters[U_MATERIAL_DIFFUSE], 1, &mesh->material.kDiffuse.r);
		glUniform3fv(m_parameters[U_MATERIAL_SPECULAR], 1, &mesh->material.kSpecular.r);
		glUniform1f(m_parameters[U_MATERIAL_SHININESS], mesh->material.kShininess);
	}
	else
	{	
		glUniform1i(m_parameters[U_LIGHTENABLED], 0);
	}

	if(mesh->textureID > 0)
	{
		glUniform1i(m_parameters[U_COLOR_TEXTURE_ENABLED], 1);
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, mesh->textureID);
		glUniform1i(m_parameters[U_COLOR_TEXTURE], 0);
	}
	else
	{
		glUniform1i(m_parameters[U_COLOR_TEXTURE_ENABLED], 0);
	}
	mesh->Render(); //this line should only be called once 
	if(mesh->textureID > 0)
	{
		glBindTexture(GL_TEXTURE_2D, 0);
	}

}
void SceneAssignment::RenderLevel1()
{
	//Level1
	//top is a rectangle
	modelStack.PushMatrix();
	modelStack.Translate(0,148,0);
	modelStack.Rotate(90,1,0,0);
	modelStack.Scale(800, 655, 1000);
	RenderMesh(meshList[GEO_TOP_L1], false);
	modelStack.PopMatrix();

	//BOTTOM is a rectangle
	modelStack.PushMatrix();
	modelStack.Translate(0, 1, 0);	
	modelStack.Rotate(-90,1,0,0);
	modelStack.Scale(800, 650, 1000);
	RenderMesh(meshList[GEO_BOTTOM_L1], false);
	modelStack.PopMatrix();

	//Left is a square
	modelStack.PushMatrix();
	modelStack.Translate(400, 75, 0);
	modelStack.Translate(-1, -1, 0);
	modelStack.Rotate(-90,0,1,0);
	modelStack.Scale(650, 150, 1000);
	RenderMesh(meshList[GEO_LEFT_L1], false);
	modelStack.PopMatrix();

	//right
	modelStack.PushMatrix();
	modelStack.Translate(-400,75, 0);
	modelStack.Translate(1, -1, 0);
	modelStack.Rotate(90,0,1,0);
	modelStack.Scale(650, 150, 1000);
	RenderMesh(meshList[GEO_RIGHT_L1], false);
	modelStack.PopMatrix();

	//front
	modelStack.PushMatrix();
	modelStack.Translate(0, 75, -325);
	modelStack.Translate(0, -1, 1);
	modelStack.Scale(800, 150, 1000);
	RenderMesh(meshList[GEO_FRONT_L1], false);
	modelStack.PopMatrix();
	
	//Back
	modelStack.PushMatrix();
	modelStack.Translate(0, 75, 325);
	modelStack.Translate(0, -1, -1);
	modelStack.Rotate(180,0,1,0);
	modelStack.Scale(800, 150, 1000);
	RenderMesh(meshList[GEO_BACK_L1], false);
	modelStack.PopMatrix();	
}
void SceneAssignment::RenderLevel2()
{
	//Level2
	//top
	modelStack.PushMatrix();
	modelStack.Translate(0,296,0);
	modelStack.Rotate(90,1,0,0);
	modelStack.Scale(800,655,1000);
	RenderMesh(meshList[GEO_TOP2], false);
	modelStack.PopMatrix();

	//BOTTOM
	modelStack.PushMatrix();
	modelStack.Translate(0,150,0);
	modelStack.Rotate(-90,1,0,0);
	modelStack.Scale(800,650,1000);
	RenderMesh(meshList[GEO_BOTTOM2], false);
	modelStack.PopMatrix();

	//Left
	modelStack.PushMatrix();
	modelStack.Translate(400,225,0);
	modelStack.Rotate(-90,0,1,0);
	modelStack.Scale(650,150,1000);
	RenderMesh(meshList[GEO_LEFT2], false);
	modelStack.PopMatrix();

	//right
	modelStack.PushMatrix();
	modelStack.Translate(-400,225,0);
	modelStack.Rotate(90,0,1,0);
	modelStack.Scale(650,150,1000);
	RenderMesh(meshList[GEO_RIGHT2], false);
	modelStack.PopMatrix();

	//front
	modelStack.PushMatrix();
	modelStack.Translate(0,225,-325);
	modelStack.Scale(800,150,1000);
	RenderMesh(meshList[GEO_FRONT2], false);
	modelStack.PopMatrix();
	
	//Back
	modelStack.PushMatrix();
	modelStack.Translate(0,225,325);
	modelStack.Rotate(180,0,1,0);
	modelStack.Scale(800,150,1000);
	RenderMesh(meshList[GEO_BACK2], false);
	modelStack.PopMatrix();	
}
void SceneAssignment::RenderSkybox()
{
}
void SceneAssignment::RenderChar()
{
	modelStack.PushMatrix();
	modelStack.Translate(X,Y,Z);
	modelStack.Scale(0.3,0.3,0.3);
	RenderMesh(meshList[GEO_CHAR], false);
	modelStack.PopMatrix();
}

void SceneAssignment::Render()
{
	// Render VBO here
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	viewStack.LoadIdentity();

	//Set view matrix using camera settings
	viewStack.LookAt(
		camera.position.x, camera.position.y, camera.position.z,
		camera.target.x, camera.target.y, camera.target.z,
		camera.up.x, camera.up.y, camera.up.z
					);

	viewStack.LoadIdentity();
	viewStack.LookAt(camera.position.x, camera.position.y, camera.position.z, camera.target.x, camera.target.y, camera.target.z, camera.up.x, camera.up.y, camera.up.z);

	modelStack.LoadIdentity();
	
	Position lightPosition_cameraspace = viewStack.Top() * light[0].position;
	glUniform3fv(m_parameters[U_LIGHT0_POSITION], 1, &lightPosition_cameraspace.x);

	//light
	modelStack.PushMatrix();
	modelStack.Translate(light[0].position.x, light[0].position.y, light[0].position.z);
	RenderMesh(meshList[GEO_LIGHTBALL], false);
	modelStack.PopMatrix();
	
	//Elevator
	modelStack.PushMatrix();
	modelStack.Translate(-42,eley,5);
	modelStack.Rotate(-90,0,1,0);
	modelStack.Scale(12.5,12,13);
	RenderMesh(meshList[GEO_TENT], true);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(0, 0, 0);
	modelStack.Scale(5, 5, 5);
	RenderMesh(meshList[GEO_DOORMAN], false);
	modelStack.PopMatrix();
	
	RenderSkybox();
	RenderLevel1();
	RenderChar();

}

void SceneAssignment::Exit()
{
	glDeleteVertexArrays(1, &m_vertexArrayID);
	glDeleteProgram(m_programID);
}
