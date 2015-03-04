#include "SceneAssignment.h"
#include "LoadTGA.h"
#include "GL\glew.h"
#include "shader.hpp"
#include "Mtx44.h"

#include "Application.h"
#include "MeshBuilder.h"
#include "Utility.h"
#include "functions.h"

//check X,Y,Z
#include <iostream>
using namespace std;

SceneAssignment::SceneAssignment()
{
}
SceneAssignment::~SceneAssignment()
{
}
void SceneAssignment::InitLevel1()
{
	//Level1 of the supermarket(too big so pls resize to the base on doorman 5,5,5 scaling)
	//Top
	meshList[GEO_TOP_L1] = MeshBuilder::GenerateQuad("top", Color(1, 1, 1), 1.f);
	meshList[GEO_TOP_L1]->textureID = LoadTGA("Image//lvl1_bt.tga");
	//Bottom
	meshList[GEO_BOTTOM_L1] = MeshBuilder::GenerateQuad("bottom", Color(1, 1, 1), 1.f);
	meshList[GEO_BOTTOM_L1]->textureID = LoadTGA("Image//lvl1_top.tga");

	//Left
	meshList[GEO_LEFT_L1] = MeshBuilder::GenerateQuad("left", Color(1, 1, 1), 1.f);
	meshList[GEO_LEFT_L1]->textureID = LoadTGA("Image//green_side_lift.tga");

	//right
	meshList[GEO_RIGHT_L1] = MeshBuilder::GenerateQuad("right", Color(1, 1, 1), 1.f);
	meshList[GEO_RIGHT_L1]->textureID = LoadTGA("Image//green_side.tga");

	//Front
	meshList[GEO_FRONT_L1] = MeshBuilder::GenerateQuad("front", Color(1, 1, 1), 1.f);
	meshList[GEO_FRONT_L1]->textureID = LoadTGA("Image//green_side.tga");

	//back
	meshList[GEO_BACK_L1] = MeshBuilder::GenerateQuad("back", Color(1, 1, 1), 1.f);
	meshList[GEO_BACK_L1]->textureID = LoadTGA("Image//supermarket texture_blue_front.tga");

	//Door
	meshList[GEO_DOOR] = MeshBuilder::GenerateQuad("Door", Color(1, 1, 1), 1.f);
	meshList[GEO_DOOR]->textureID = LoadTGA("Image//door.tga");
	meshList[GEO_DOOR]->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
	meshList[GEO_DOOR]->material.kDiffuse.Set(0.5f, 0.5f, 0.5f);
	meshList[GEO_DOOR]->material.kSpecular.Set(1.0f, 1.0f, 1.0f);
	meshList[GEO_DOOR]->material.kShininess = 50.f;
	//Lightball
	meshList[GEO_LIGHTBALL] = MeshBuilder::GenerateSphere("lightball", Color(1 ,1, 1), 10, 10, 1);
	
}
void SceneAssignment::InitLevel2()
{
	//Lv 2 of supermarket
	//Top
	meshList[GEO_TOP2] = MeshBuilder::GenerateQuad("top", Color(1, 1, 1), 1.f);
	meshList[GEO_TOP2]->textureID = LoadTGA("Image//blue_top.tga");
	//Bottom
	meshList[GEO_BOTTOM2] = MeshBuilder::GenerateQuad("bottom", Color(1, 1, 1), 1.f);
	meshList[GEO_BOTTOM2]->textureID = LoadTGA("Image//blue_floor.tga");

	//Left
	meshList[GEO_LEFT2] = MeshBuilder::GenerateQuad("left", Color(1, 1, 1), 1.f);
	meshList[GEO_LEFT2]->textureID = LoadTGA("Image//blue_dnup_lift.tga");
	
	//right
	meshList[GEO_RIGHT2] = MeshBuilder::GenerateQuad("right", Color(1, 1, 1), 1.f);
	meshList[GEO_RIGHT2]->textureID = LoadTGA("Image//blue_dnup.tga");
	
	//Front
	meshList[GEO_FRONT2] = MeshBuilder::GenerateQuad("front", Color(1, 1, 1), 1.f);
	meshList[GEO_FRONT2]->textureID = LoadTGA("Image//blue_updn.tga");

	//back
	meshList[GEO_BACK2] = MeshBuilder::GenerateQuad("back", Color(1, 1, 1), 1.f);
	meshList[GEO_BACK2]->textureID = LoadTGA("Image//blue_updn.tga");
}
void SceneAssignment::InitObjects()
{
	//lift
	meshList[GEO_TENT] = MeshBuilder::GenerateOBJ("tent", "OBJ//lift.obj");
	meshList[GEO_TENT]->textureID = LoadTGA("Image//lift_m.tga");
	meshList[GEO_TENT]->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
	meshList[GEO_TENT]->material.kDiffuse.Set(0.5f, 0.5f, 0.5f);
	meshList[GEO_TENT]->material.kSpecular.Set(1.0f, 1.0f, 1.0f);
	meshList[GEO_TENT]->material.kShininess = 50.f;

	meshList[GEO_DOORMAN] = MeshBuilder::GenerateOBJ("doorman", "OBJ//doorman.obj");
	meshList[GEO_DOORMAN]->textureID = LoadTGA("Image//doorman.tga");
	meshList[GEO_DOORMAN]->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
	meshList[GEO_DOORMAN]->material.kDiffuse.Set(0.5f, 0.5f, 0.5f);
	meshList[GEO_DOORMAN]->material.kSpecular.Set(1.0f, 1.0f, 1.0f);
	meshList[GEO_DOORMAN]->material.kShininess = 50.f;

	//apple
	meshList[GEO_APPLE] = MeshBuilder::GenerateOBJ("apple", "OBJ//apple.obj");
	meshList[GEO_APPLE]->textureID = LoadTGA("Image//apple.tga");
	meshList[GEO_APPLE]->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
	meshList[GEO_APPLE]->material.kDiffuse.Set(0.5f, 0.5f, 0.5f);
	meshList[GEO_APPLE]->material.kSpecular.Set(1.0f, 1.0f, 1.0f);
	meshList[GEO_APPLE]->material.kShininess = 50.f;

	//orange
	meshList[GEO_ORANGE] = MeshBuilder::GenerateOBJ("orange", "OBJ//orange_fruit.obj");
	meshList[GEO_ORANGE]->textureID = LoadTGA("Image//orange_fruit.tga");
	meshList[GEO_ORANGE]->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
	meshList[GEO_ORANGE]->material.kDiffuse.Set(0.5f, 0.5f, 0.5f);
	meshList[GEO_ORANGE]->material.kSpecular.Set(1.0f, 1.0f, 1.0f);
	meshList[GEO_ORANGE]->material.kShininess = 50.f;

	//watermelon
	meshList[GEO_WATERMELON] = MeshBuilder::GenerateOBJ("watermelon", "OBJ//watermelon.obj");
	meshList[GEO_WATERMELON]->textureID = LoadTGA("Image//watermelon.tga");
	meshList[GEO_WATERMELON]->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
	meshList[GEO_WATERMELON]->material.kDiffuse.Set(0.5f, 0.5f, 0.5f);
	meshList[GEO_WATERMELON]->material.kSpecular.Set(1.0f, 1.0f, 1.0f);
	meshList[GEO_WATERMELON]->material.kShininess = 50.f;

	//cabbage
	meshList[GEO_CABBAGE] = MeshBuilder::GenerateOBJ("cabbage", "OBJ//cabbage.obj");
	meshList[GEO_CABBAGE]->textureID = LoadTGA("Image//cabbage.tga");
	meshList[GEO_CABBAGE]->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
	meshList[GEO_CABBAGE]->material.kDiffuse.Set(0.5f, 0.5f, 0.5f);
	meshList[GEO_CABBAGE]->material.kSpecular.Set(1.0f, 1.0f, 1.0f);
	meshList[GEO_CABBAGE]->material.kShininess = 50.f;
	//fruit basket
	meshList[GEO_BASKET] = MeshBuilder::GenerateOBJ("friutbasket", "OBJ//fruitbasket.obj");
	meshList[GEO_BASKET]->textureID = LoadTGA("Image//fruitbasket.tga");
	meshList[GEO_BASKET]->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
	meshList[GEO_BASKET]->material.kDiffuse.Set(0.5f, 0.5f, 0.5f);
	meshList[GEO_BASKET]->material.kSpecular.Set(1.0f, 1.0f, 1.0f);
	meshList[GEO_BASKET]->material.kShininess = 50.f;
	//register
	meshList[GEO_REGISTER] = MeshBuilder::GenerateOBJ("register", "OBJ//cashregister.obj");
	meshList[GEO_REGISTER]->textureID = LoadTGA("Image//cashregister.tga");
	meshList[GEO_REGISTER]->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
	meshList[GEO_REGISTER]->material.kDiffuse.Set(0.5f, 0.5f, 0.5f);
	meshList[GEO_REGISTER]->material.kSpecular.Set(1.0f, 1.0f, 1.0f);
	meshList[GEO_REGISTER]->material.kShininess = 50.f;
	//cooler
	meshList[GEO_COOLER] = MeshBuilder::GenerateOBJ("cooler", "OBJ//cooler.obj");
	meshList[GEO_COOLER]->textureID = LoadTGA("Image//combine-cooler.tga");
	meshList[GEO_COOLER]->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
	meshList[GEO_COOLER]->material.kDiffuse.Set(0.5f, 0.5f, 0.5f);
	meshList[GEO_COOLER]->material.kSpecular.Set(1.0f, 1.0f, 1.0f);
	meshList[GEO_COOLER]->material.kShininess = 50.f;

	//coconut
	meshList[GEO_COCONUT] = MeshBuilder::GenerateOBJ("coconut", "OBJ//coconut.obj");
	meshList[GEO_COCONUT]->textureID = LoadTGA("Image//coconut.tga");
	meshList[GEO_COCONUT]->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
	meshList[GEO_COCONUT]->material.kDiffuse.Set(0.5f, 0.5f, 0.5f);
	meshList[GEO_COCONUT]->material.kSpecular.Set(1.0f, 1.0f, 1.0f);
	meshList[GEO_COCONUT]->material.kShininess = 50.f;

	//lodin packet
	meshList[GEO_LODIN] = MeshBuilder::GenerateOBJ("lodin", "OBJ//lodin.obj");
	meshList[GEO_LODIN]->textureID = LoadTGA("Image//lodin.tga");
	meshList[GEO_LODIN]->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
	meshList[GEO_LODIN]->material.kDiffuse.Set(0.5f, 0.5f, 0.5f);
	meshList[GEO_LODIN]->material.kSpecular.Set(1.0f, 1.0f, 1.0f);
	meshList[GEO_LODIN]->material.kShininess = 50.f;

	//ice cream
	meshList[GEO_ICECREAM] = MeshBuilder::GenerateOBJ("icecream", "OBJ//icecream.obj");
	meshList[GEO_ICECREAM]->textureID = LoadTGA("Image//icecream.tga");
	meshList[GEO_ICECREAM]->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
	meshList[GEO_ICECREAM]->material.kDiffuse.Set(0.5f, 0.5f, 0.5f);
	meshList[GEO_ICECREAM]->material.kSpecular.Set(1.0f, 1.0f, 1.0f);
	meshList[GEO_ICECREAM]->material.kShininess = 50.f;

	//shelf
	meshList[GEO_SHELF] = MeshBuilder::GenerateOBJ("shelf", "OBJ//shelf.obj");
	meshList[GEO_SHELF]->textureID = LoadTGA("Image//shelf.tga");
	meshList[GEO_SHELF]->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
	meshList[GEO_SHELF]->material.kDiffuse.Set(0.5f, 0.5f, 0.5f);
	meshList[GEO_SHELF]->material.kSpecular.Set(1.0f, 1.0f, 1.0f);
	meshList[GEO_SHELF]->material.kShininess = 50.f;

	//travelator up
	meshList[GEO_TRAVELATORUP] = MeshBuilder::GenerateOBJ("cooler", "OBJ//travelatorup.obj");
	meshList[GEO_TRAVELATORUP]->textureID = LoadTGA("Image//travelator.tga");
	meshList[GEO_TRAVELATORUP]->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
	meshList[GEO_TRAVELATORUP]->material.kDiffuse.Set(0.5f, 0.5f, 0.5f);
	meshList[GEO_TRAVELATORUP]->material.kSpecular.Set(1.0f, 1.0f, 1.0f);
	meshList[GEO_TRAVELATORUP]->material.kShininess = 50.f;
	//travelator down
	meshList[GEO_TRAVELATORDN] = MeshBuilder::GenerateOBJ("cooler", "OBJ//travelatordn.obj");
	meshList[GEO_TRAVELATORDN]->textureID = LoadTGA("Image//travelator.tga");
	meshList[GEO_TRAVELATORDN]->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
	meshList[GEO_TRAVELATORDN]->material.kDiffuse.Set(0.5f, 0.5f, 0.5f);
	meshList[GEO_TRAVELATORDN]->material.kSpecular.Set(1.0f, 1.0f, 1.0f);
	meshList[GEO_TRAVELATORDN]->material.kShininess = 50.f;

	//barrier
	meshList[GEO_BARRIER] = MeshBuilder::GenerateOBJ("cooler", "OBJ//barrier.obj");
	meshList[GEO_BARRIER]->textureID = LoadTGA("Image//combine-cooler.tga");
	meshList[GEO_BARRIER]->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
	meshList[GEO_BARRIER]->material.kDiffuse.Set(0.5f, 0.5f, 0.5f);
	meshList[GEO_BARRIER]->material.kSpecular.Set(1.0f, 1.0f, 1.0f);
	meshList[GEO_BARRIER]->material.kShininess = 50.f;
	//packet
	meshList[GEO_PACKET] = MeshBuilder::GenerateOBJ("packet", "OBJ//packet chips.obj");
	meshList[GEO_PACKET]->textureID = LoadTGA("Image//packet.tga");
	meshList[GEO_PACKET]->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
	meshList[GEO_PACKET]->material.kDiffuse.Set(0.5f, 0.5f, 0.5f);
	meshList[GEO_PACKET]->material.kSpecular.Set(1.0f, 1.0f, 1.0f);
	meshList[GEO_PACKET]->material.kShininess = 50.f;
	//cerel1
	meshList[GEO_BOX1] = MeshBuilder::GenerateOBJ("box1", "OBJ//box1.obj");
	meshList[GEO_BOX1]->textureID = LoadTGA("Image//box1.tga");
	meshList[GEO_BOX1]->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
	meshList[GEO_BOX1]->material.kDiffuse.Set(0.5f, 0.5f, 0.5f);
	meshList[GEO_BOX1]->material.kSpecular.Set(1.0f, 1.0f, 1.0f);
	meshList[GEO_BOX1]->material.kShininess = 50.f;
	//can1
	meshList[GEO_CAN1] = MeshBuilder::GenerateOBJ("can1", "OBJ//can1.obj");
	meshList[GEO_CAN1]->textureID = LoadTGA("Image//can1.tga");
	meshList[GEO_CAN1]->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
	meshList[GEO_CAN1]->material.kDiffuse.Set(0.5f, 0.5f, 0.5f);
	meshList[GEO_CAN1]->material.kSpecular.Set(1.0f, 1.0f, 1.0f);
	meshList[GEO_CAN1]->material.kShininess = 50.f;
	//FireAlarm
	meshList[GEO_ALARM] = MeshBuilder::GenerateOBJ("firealarm", "OBJ//Firealarm.obj");
	meshList[GEO_ALARM] ->textureID = LoadTGA("Image//firealarm_m.tga");
	meshList[GEO_ALARM]->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
	meshList[GEO_ALARM]->material.kDiffuse.Set(0.5f, 0.5f, 0.5f);
	meshList[GEO_ALARM]->material.kSpecular.Set(1.0f, 1.0f, 1.0f);
	meshList[GEO_ALARM]->material.kShininess = 50.f;

	meshList[GEO_BUILDING] = MeshBuilder::GenerateOBJ("house", "OBJ//house.obj");
	meshList[GEO_BUILDING] ->textureID = LoadTGA("Image//house.tga");
	meshList[GEO_BUILDING]->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
	meshList[GEO_BUILDING]->material.kDiffuse.Set(0.5f, 0.5f, 0.5f);
	meshList[GEO_BUILDING]->material.kSpecular.Set(1.0f, 1.0f, 1.0f);
	meshList[GEO_BUILDING]->material.kShininess = 50.f;

	//cashier
	meshList[GEO_CASHIER] = MeshBuilder::GenerateOBJ("tent", "OBJ//black.obj");
	meshList[GEO_CASHIER]->textureID = LoadTGA("Image//black.tga");
	meshList[GEO_CASHIER]->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
	meshList[GEO_CASHIER]->material.kDiffuse.Set(0.5f, 0.5f, 0.5f);
	meshList[GEO_CASHIER]->material.kSpecular.Set(1.0f, 1.0f, 1.0f);
	meshList[GEO_CASHIER]->material.kShininess = 50.f;

	/* ================= Glenn's work =============== */
	meshList[GEO_UI] = MeshBuilder::GenerateQuad("UI", Color(1, 1, 1), 1);
	meshList[GEO_UI] ->textureID = LoadTGA("Image//UI.tga");
	/* ================= Glenn's work =============== */
}
void SceneAssignment::InitModelBlue()
{
	//body
	modelList2[MODEL_BODY_BLUE] = MeshBuilder::GenerateOBJ("body", "OBJ//model_body.obj");
	modelList2[MODEL_BODY_BLUE] ->textureID = LoadTGA("Image//blue.tga");

	//left arm
	modelList2[MODEL_LEFTARM_BLUE] = MeshBuilder::GenerateOBJ("left arm", "OBJ//model_left_arm.obj");
	modelList2[MODEL_LEFTARM_BLUE] ->textureID = LoadTGA("Image//blue.tga");

	//left fist
	modelList2[MODEL_LEFTFIST_BLUE] = MeshBuilder::GenerateOBJ("left fist", "OBJ//model_left_fist.obj");
	modelList2[MODEL_LEFTFIST_BLUE] ->textureID = LoadTGA("Image//blue.tga");

	//left leg upper
	modelList2[MODEL_LEFT_LEG_UPPER_BLUE] = MeshBuilder::GenerateOBJ("blue", "OBJ//model_left_leg_upper.obj");
	modelList2[MODEL_LEFT_LEG_UPPER_BLUE] ->textureID = LoadTGA("Image//blue.tga");

	//left leg lower
	modelList2[MODEL_LEFT_LEG_LOWER_BLUE] = MeshBuilder::GenerateOBJ("blue", "OBJ//model_left_leg_lower.obj");
	modelList2[MODEL_LEFT_LEG_LOWER_BLUE] ->textureID = LoadTGA("Image//blue.tga");

	//right arm
	modelList2[MODEL_RIGHTARM_BLUE] = MeshBuilder::GenerateOBJ("blue", "OBJ//model_right_arm.obj");
	modelList2[MODEL_RIGHTARM_BLUE] ->textureID = LoadTGA("Image//blue.tga");

	//right fist
	modelList2[MODEL_RIGHTFIST_BLUE] = MeshBuilder::GenerateOBJ("blue", "OBJ//model_right_fist.obj");
	modelList2[MODEL_RIGHTFIST_BLUE] ->textureID = LoadTGA("Image//blue.tga");

	//right leg upper
	modelList2[MODEL_RIGHT_LEG_UPPER_BLUE] = MeshBuilder::GenerateOBJ("blue", "OBJ//model_right_leg_upper.obj");
	modelList2[MODEL_RIGHT_LEG_UPPER_BLUE] ->textureID = LoadTGA("Image//blue.tga");

	//right leg lower
	modelList2[MODEL_RIGHT_LEG_LOWER_BLUE] = MeshBuilder::GenerateOBJ("blue", "OBJ//model_right_leg_lower.obj");
	modelList2[MODEL_RIGHT_LEG_LOWER_BLUE] ->textureID = LoadTGA("Image//blue.tga");
}
/* ============= Glenn's work ============= */
void SceneAssignment::InitModelOrange()
{
	//body
	modelList6[MODEL_BODY_ORANGE] = MeshBuilder::GenerateOBJ("body", "OBJ//orange_body.obj");
	modelList6[MODEL_BODY_ORANGE] ->textureID = LoadTGA("Image//orange.tga");

	//left arm
	modelList6[MODEL_LEFTARM_ORANGE] = MeshBuilder::GenerateOBJ("left arm", "OBJ//orange_left_arm.obj");
	modelList6[MODEL_LEFTARM_ORANGE] ->textureID = LoadTGA("Image//orange.tga");

	//left fist
	modelList6[MODEL_LEFTFIST_ORANGE] = MeshBuilder::GenerateOBJ("left fist", "OBJ//orange_left_fist.obj");
	modelList6[MODEL_LEFTFIST_ORANGE] ->textureID = LoadTGA("Image//orange.tga");

	//left leg upper
	modelList6[MODEL_LEFT_LEG_UPPER_ORANGE] = MeshBuilder::GenerateOBJ("orange", "OBJ//orange_left_leg_upper.obj");
	modelList6[MODEL_LEFT_LEG_UPPER_ORANGE] ->textureID = LoadTGA("Image//orange.tga");

	//left leg lower
	modelList6[MODEL_LEFT_LEG_LOWER_ORANGE] = MeshBuilder::GenerateOBJ("orange", "OBJ//orange_left_leg_lower.obj");
	modelList6[MODEL_LEFT_LEG_LOWER_ORANGE] ->textureID = LoadTGA("Image//orange.tga");

	//right arm
	modelList6[MODEL_RIGHTARM_ORANGE] = MeshBuilder::GenerateOBJ("orange", "OBJ//orange_right_arm.obj");
	modelList6[MODEL_RIGHTARM_ORANGE] ->textureID = LoadTGA("Image//orange.tga");

	//right fist
	modelList6[MODEL_RIGHTFIST_ORANGE] = MeshBuilder::GenerateOBJ("orange", "OBJ//orange_right_fist.obj");
	modelList6[MODEL_RIGHTFIST_ORANGE] ->textureID = LoadTGA("Image//orange.tga");

	//right leg upper
	modelList6[MODEL_RIGHT_LEG_UPPER_ORANGE] = MeshBuilder::GenerateOBJ("orange", "OBJ//orange_right_leg_upper.obj");
	modelList6[MODEL_RIGHT_LEG_UPPER_ORANGE] ->textureID = LoadTGA("Image//orange.tga");

	//right leg lower
	modelList6[MODEL_RIGHT_LEG_LOWER_ORANGE] = MeshBuilder::GenerateOBJ("orange", "OBJ//orange_right_leg_lower.obj");
	modelList6[MODEL_RIGHT_LEG_LOWER_ORANGE] ->textureID = LoadTGA("Image//orange.tga");
}
/* ============= Glenn's work ============= */
void SceneAssignment::InitModelPink()
{
	//body
	modelList7[MODEL_BODY_PINK] = MeshBuilder::GenerateOBJ("body", "OBJ//model_body.obj");
	modelList7[MODEL_BODY_PINK] ->textureID = LoadTGA("Image//pink.tga");

	//left arm
	modelList7[MODEL_LEFTARM_PINK] = MeshBuilder::GenerateOBJ("left arm", "OBJ//model_left_arm.obj");
	modelList7[MODEL_LEFTARM_PINK] ->textureID = LoadTGA("Image//pink.tga");

	//left fist
	modelList7[MODEL_LEFTFIST_PINK] = MeshBuilder::GenerateOBJ("left fist", "OBJ//model_left_fist.obj");
	modelList7[MODEL_LEFTFIST_PINK] ->textureID = LoadTGA("Image//pink.tga");

	//left leg upper
	modelList7[MODEL_LEFT_LEG_UPPER_PINK] = MeshBuilder::GenerateOBJ("pink", "OBJ//model_left_leg_upper.obj");
	modelList7[MODEL_LEFT_LEG_UPPER_PINK] ->textureID = LoadTGA("Image//pink.tga");

	//left leg lower
	modelList7[MODEL_LEFT_LEG_LOWER_PINK] = MeshBuilder::GenerateOBJ("pink", "OBJ//model_left_leg_lower.obj");
	modelList7[MODEL_LEFT_LEG_LOWER_PINK] ->textureID = LoadTGA("Image//pink.tga");

	//right arm
	modelList7[MODEL_RIGHTARM_PINK] = MeshBuilder::GenerateOBJ("pink", "OBJ//model_right_arm.obj");
	modelList7[MODEL_RIGHTARM_PINK] ->textureID = LoadTGA("Image//pink.tga");

	//right fist
	modelList7[MODEL_RIGHTFIST_PINK] = MeshBuilder::GenerateOBJ("pink", "OBJ//model_right_fist.obj");
	modelList7[MODEL_RIGHTFIST_PINK] ->textureID = LoadTGA("Image//pink.tga");

	//right leg upper
	modelList7[MODEL_RIGHT_LEG_UPPER_PINK] = MeshBuilder::GenerateOBJ("pink", "OBJ//model_right_leg_upper.obj");
	modelList7[MODEL_RIGHT_LEG_UPPER_PINK] ->textureID = LoadTGA("Image//pink.tga");

	//right leg lower
	modelList7[MODEL_RIGHT_LEG_LOWER_PINK] = MeshBuilder::GenerateOBJ("pink", "OBJ//model_right_leg_lower.obj");
	modelList7[MODEL_RIGHT_LEG_LOWER_PINK] ->textureID = LoadTGA("Image//pink.tga");
}
void SceneAssignment::InitExtSkybox()
{
	//external skybox
	skyboxList[SKYBOX_FRONT] = MeshBuilder::GenerateQuad("skybox_front", Color(1, 1, 1), 1.f);
	skyboxList[SKYBOX_FRONT]->textureID = LoadTGA("Image//hills_ft.tga");

	skyboxList[SKYBOX_BACK] = MeshBuilder::GenerateQuad("skybox_back", Color(1, 1, 1), 1.f);
	skyboxList[SKYBOX_BACK]->textureID = LoadTGA("Image//hills_bk.tga");

	skyboxList[SKYBOX_LEFT] = MeshBuilder::GenerateQuad("skybox_left", Color(1, 1, 1), 1.f);
	skyboxList[SKYBOX_LEFT]->textureID = LoadTGA("Image//hills_lf.tga");

	skyboxList[SKYBOX_RIGHT] = MeshBuilder::GenerateQuad("skybox_right", Color(1, 1, 1), 1.f);
	skyboxList[SKYBOX_RIGHT]->textureID = LoadTGA("Image//hills_rt.tga");

	skyboxList[SKYBOX_UP] = MeshBuilder::GenerateQuad("skybox_up", Color(1, 1, 1), 1.f);
	skyboxList[SKYBOX_UP]->textureID = LoadTGA("Image//hills_up.tga");

	skyboxList[SKYBOX_DOWN] = MeshBuilder::GenerateQuad("skybox_down", Color(1, 1, 1), 1.f);
	skyboxList[SKYBOX_DOWN]->textureID = LoadTGA("Image//exterior_floor.tga");

	skyboxList[SKYBOX_EXTEBANNER] = MeshBuilder::GenerateQuad("ext_banner", Color(1, 1, 1), 1.f);
	skyboxList[SKYBOX_EXTEBANNER]->textureID = LoadTGA("Image//supermarket_banner_front.tga");

	skyboxList[SKYBOX_EXTESIDE] = MeshBuilder::GenerateQuad("ext_banner", Color(1, 1, 1), 1.f);
	skyboxList[SKYBOX_EXTESIDE]->textureID = LoadTGA("Image//supermarket_banner_side.tga");
}
void SceneAssignment::InitCollision()
{
	//Objects

	//Lv 1
	/*--TOP--*/
	Skybox1.translateVal.push_back(Vector3(0,148,0));
	Skybox1.rotateVal.push_back(90);
	Skybox1.rotateAxis.push_back(Vector3(1,0,0));
	Skybox1.scaleVal.push_back(Vector3(800, 655, 1000));
	/*--BOT--*/
	Skybox1.translateVal.push_back(Vector3(0, 1, 0));
	Skybox1.rotateVal.push_back(-90);
	Skybox1.rotateAxis.push_back(Vector3(1,0,0));
	Skybox1.scaleVal.push_back(Vector3(800, 650, 1000));
	/*--LEFT--*/
	Skybox1.translateVal.push_back(Vector3(399, 74, 0));
	Skybox1.rotateVal.push_back(-90);
	Skybox1.rotateAxis.push_back(Vector3(0,1,0));
	Skybox1.scaleVal.push_back(Vector3(650, 150, 1000));
	/*--RIGHT--*/
	Skybox1.translateVal.push_back(Vector3(-399,74, 0));
	Skybox1.rotateVal.push_back(90);
	Skybox1.rotateAxis.push_back(Vector3(0,1,0));
	Skybox1.scaleVal.push_back(Vector3(650, 150, 1000));
	/*--FRONT--*/
	Skybox1.translateVal.push_back(Vector3(0, 74, -324));
	Skybox1.rotateVal.push_back(0);
	Skybox1.rotateAxis.push_back(Vector3(1,0,0));
	Skybox1.scaleVal.push_back(Vector3(800, 150, 1000));
	/*--BACK--*/
	Skybox1.translateVal.push_back(Vector3(0, 74, 324));
	Skybox1.rotateVal.push_back(180);
	Skybox1.rotateAxis.push_back(Vector3(0,1,0));
	Skybox1.scaleVal.push_back(Vector3(800, 150, 1000));


	/* =================== Glenn's work ======================== */
	//from -200 to -500, the left side of supermarket
	for(int i = 0; i < 16; i++)
	{
		Skybox1.collisionPos.push_back(Vector3(-200 - (i*20), 30, 340));
	}
	//from 340 to -340, side of supermarket
	for(int i = 0; i < 34; i++)
	{
		Skybox1.collisionPos.push_back(Vector3(-500 + (i*30), 30, -350));
		Skybox1.collisionPos.push_back(Vector3(-500, 30, 340 - (i*20)));
		Skybox1.collisionPos.push_back(Vector3(500, 30, 340 - (i*20)));
	}

	//from 200 to 500, the right side of lv 1 supermarket
	for(int i = 0; i < 16; i++)
	{
		Skybox1.collisionPos.push_back(Vector3(200 + (i*20), 30, 340));
	}	
	//middle platform
	Skybox1.collisionPos.push_back(Vector3(0, 30, 340));

	Skybox1.collisionRad = 20;
	/* =================== Glenn's work ======================== */

	ObjectList.push_back(Skybox1);

	//firealarm
	firealarm.translateVal.push_back(Vector3(400,-41,-100));
	firealarm.rotateVal.push_back(270);
	firealarm.rotateAxis.push_back(Vector3(0,1,0));
	firealarm.scaleVal.push_back(Vector3(15,14,15));

	//Lv2
	/*--TOP--*/
	Skybox2.translateVal.push_back(Vector3(0,296,0));
	Skybox2.rotateVal.push_back(90);
	Skybox2.rotateAxis.push_back(Vector3(1,0,0));
	Skybox2.scaleVal.push_back(Vector3(800, 655, 1000));
	/*--BOT--*/
	Skybox2.translateVal.push_back(Vector3(0,150,0));
	Skybox2.rotateVal.push_back(-90);
	Skybox2.rotateAxis.push_back(Vector3(1,0,0));
	Skybox2.scaleVal.push_back(Vector3(800, 650, 1000));
	/*--LEFT--*/
	Skybox2.translateVal.push_back(Vector3(400,225,0));
	Skybox2.rotateVal.push_back(-90);
	Skybox2.rotateAxis.push_back(Vector3(0,1,0));
	Skybox2.scaleVal.push_back(Vector3(650, 150, 1000));
	/*--RIGHT--*/
	Skybox2.translateVal.push_back(Vector3(-400,225,0));
	Skybox2.rotateVal.push_back(90);
	Skybox2.rotateAxis.push_back(Vector3(0,1,0));
	Skybox2.scaleVal.push_back(Vector3(650, 150, 1000));
	/*--FRONT--*/
	Skybox2.translateVal.push_back(Vector3(0,225,-325));
	Skybox2.rotateVal.push_back(0);
	Skybox2.rotateAxis.push_back(Vector3(1,0,0));
	Skybox2.scaleVal.push_back(Vector3(800, 150, 1000));
	/*--BACK--*/
	Skybox2.translateVal.push_back(Vector3(0,225,325));
	Skybox2.rotateVal.push_back(180);
	Skybox2.rotateAxis.push_back(Vector3(0,1,0));
	Skybox2.scaleVal.push_back(Vector3(800, 150, 1000));

	/* =================== Glenn's work ======================== */
	//from 340 to -340, side of supermarket
	for(int i = 0; i < 34; i++)
	{
		Skybox2.collisionPos.push_back(Vector3(-500 + (i*30), 180, 340));
		Skybox2.collisionPos.push_back(Vector3(-500 + (i*30), 180, -350));
		Skybox2.collisionPos.push_back(Vector3(-410, 180, 340 - (i*20)));
	}
	
	for(int i = 0; i < 12; i++)
	{
		Skybox2.collisionPos.push_back(Vector3(410, 180, 70 + (i*20)));
		Skybox2.collisionPos.push_back(Vector3(410, 180, -70 - (i*20)));
	}
	
	Skybox2.collisionRad = 30;
	/* =================== Glenn's work ======================== */

	ObjectList.push_back(Skybox2);

	

	//Basket
	for (int i = 0; i < 6;i++)
	{
		Basket.translateVal.push_back(Vector3(-220 + (95*i), 0, -305.5));
		Basket.rotateVal.push_back(-90);
		Basket.rotateAxis.push_back(Vector3(0,1,0));
		Basket.scaleVal.push_back(Vector3(5, 5, 7));

		Basket.collisionPos.push_back(Vector3(Basket.translateVal[2*i].x,30,Basket.translateVal[2*i].z));
		Basket.collisionPos.push_back(Vector3(Basket.translateVal[2*i].x+25,30,Basket.translateVal[2*i].z));
		Basket.collisionPos.push_back(Vector3(Basket.translateVal[2*i].x-25,30,Basket.translateVal[2*i].z));

		if ( i < 5 )
		{
			Basket.translateVal.push_back(Vector3(-385, 0, -220 + (95*i)));
			Basket.rotateVal.push_back(0);
			Basket.rotateAxis.push_back(Vector3(1,0,0));
			Basket.scaleVal.push_back(Vector3(5, 5, 7));

			Basket.collisionPos.push_back(Vector3(Basket.translateVal[2*i+1].x,30,Basket.translateVal[2*i+1].z));
			Basket.collisionPos.push_back(Vector3(Basket.translateVal[2*i+1].x,30,Basket.translateVal[2*i+1].z+25));
			Basket.collisionPos.push_back(Vector3(Basket.translateVal[2*i+1].x,30,Basket.translateVal[2*i+1].z-25));
		}
	}

	Basket.collisionRad = 15;
	ObjectList.push_back(Basket);

	//Cooler
	for(int i = 0; i < 2; ++i)
	{
		Cooler.translateVal.push_back(Vector3(-200, 0, 115*i));
		Cooler.scaleVal.push_back(Vector3(5, 5, 12));

		Cooler.collisionPos.push_back(Vector3(Cooler.translateVal[i*2].x,30,Cooler.translateVal[i*2].z));
		Cooler.collisionPos.push_back(Vector3(Cooler.translateVal[i*2].x,30,Cooler.translateVal[i*2].z+35));
		Cooler.collisionPos.push_back(Vector3(Cooler.translateVal[i*2].x,30,Cooler.translateVal[i*2].z-35));

		Cooler.translateVal.push_back(Vector3(200, 0, 115*i));
		Cooler.scaleVal.push_back(Vector3(5, 5, 12));

		Cooler.collisionPos.push_back(Vector3(Cooler.translateVal[i*2+1].x,30,Cooler.translateVal[i*2+1].z));
		Cooler.collisionPos.push_back(Vector3(Cooler.translateVal[i*2+1].x,30,Cooler.translateVal[i*2+1].z+35));
		Cooler.collisionPos.push_back(Vector3(Cooler.translateVal[i*2+1].x,30,Cooler.translateVal[i*2+1].z-35));
	}

	Cooler.collisionRad = 20;
	ObjectList.push_back(Cooler);

	//Shelves
	//i = spheres
	for (int i = 0; i < 2; ++i)
	{
		int temp = -220;
		int temp1 = -220;
		Shelf.translateVal.push_back(Vector3(70*i-250, 0, -220));
		Shelf.scaleVal.push_back(Vector3(15,5,4));

		Shelf.collisionPos.push_back(Vector3(70*i-250 + 25,30,-220));
		Shelf.collisionPos.push_back(Vector3(70*i-250 - 25,30,-220));

		Shelf.translateVal.push_back(Vector3(70*i+200, 0, -220));
		Shelf.scaleVal.push_back(Vector3(15,5,4));

		Shelf.collisionPos.push_back(Vector3(70*i+200 + 25,30, -220));
		Shelf.collisionPos.push_back(Vector3(70*i+200 - 25,30,-220));
		
		//left shelves
		for (int j = 0; j < 6; j++)
		{
			Shelf.translateVal.push_back(Vector3(70*i+200, 150, temp));
			Shelf.scaleVal.push_back(Vector3(15,5,4));

			Shelf.collisionPos.push_back(Vector3(70*i+200 + 25,180,temp));
			Shelf.collisionPos.push_back(Vector3(70*i+200 - 25,180,temp));
			temp+=100;
		}
		//right shelves
		for (int j = 0; j < 6; j++)
		{
			Shelf.translateVal.push_back(Vector3(70*i-300, 150, temp1));
			Shelf.scaleVal.push_back(Vector3(15,5,4));

			Shelf.collisionPos.push_back(Vector3(70*i-300 + 25,180,temp1));
			Shelf.collisionPos.push_back(Vector3(70*i-300 - 25,180,temp1));
			temp1+=100;
		}
	}
	//for middle and box blocking travelator
	for (int i = 0; i < 3; ++i)
	{
		int temp1 = 200;
		Shelf.translateVal.push_back(Vector3(70*i-250, 0, -220));
		Shelf.scaleVal.push_back(Vector3(15,5,4));

		Shelf.collisionPos.push_back(Vector3(70*i-250 + 25,30,-220));
		Shelf.collisionPos.push_back(Vector3(70*i-250 - 25,30,-220));

		Shelf.translateVal.push_back(Vector3(70*i+200, 0, -220));
		Shelf.scaleVal.push_back(Vector3(15,5,4));

		Shelf.collisionPos.push_back(Vector3(70*i+200 + 25,30, -220));
		Shelf.collisionPos.push_back(Vector3(70*i+200 - 25,30,-220));

		
	
		//middle shelves
		for (int k = 0; k < 4; k++)
		{
			Shelf.translateVal.push_back(Vector3(70*i-70, 150, temp1));
			Shelf.scaleVal.push_back(Vector3(15,5,4));

			Shelf.collisionPos.push_back(Vector3(70*i-70 + 25,180,temp1));
			Shelf.collisionPos.push_back(Vector3(70*i-70 - 25,180,temp1));
			temp1 -=100;
		}
		
	}
	Shelf.collisionRad = 20;
	
	ObjectList.push_back(Shelf);

	//Register
	for(int i = 0; i < 4; i++)
	{
		Register.translateVal.push_back(Vector3(70*i-300, 0, 240));
		Register.scaleVal.push_back(Vector3(3.5, 3.6, 3));
		Register.collisionPos.push_back(Vector3(Register.translateVal[i].x,30,Register.translateVal[i].z-15));
		Register.collisionPos.push_back(Vector3(Register.translateVal[i].x,30,Register.translateVal[i].z));
		Register.collisionPos.push_back(Vector3(Register.translateVal[i].x,30,Register.translateVal[i].z+15));
		Register.collisionPos.push_back(Vector3(Register.translateVal[i].x-15,30,Register.translateVal[i].z+15));
	}

	Register.collisionRad = 8;
	ObjectList.push_back(Register);

	int tempT = 40;
	for (int i = 0; i < 2; ++i)
	{
		Travellator.translateVal.push_back(Vector3(tempT, -10, -60));
		Travellator.rotateVal.push_back(-90);
		Travellator.rotateAxis.push_back(Vector3(0, 1, 0));
		Travellator.scaleVal.push_back(Vector3(26, 18, 13));
		tempT -= 80;
	}


	int tempX = -80;
	for (int i = 0; i < 2; ++i)
	{
		int tempZ = 160;
		for (int j = 0; j < 5; ++j)
		{
			Travellator.collisionPos.push_back(Vector3(tempX,30,tempZ));
			tempZ -= 30;
		}
		tempX += 58;
	}

	int tempX2 = 8;
	for (int i = 0; i < 2; ++i)
	{
		int tempZ = 160;
		for (int j = 0; j < 5; ++j)
		{
			Travellator.collisionPos.push_back(Vector3(tempX2,30,tempZ));
			tempZ -= 30;
		}
		tempX2 += 58;
	}
	Travellator.collisionPos.push_back(Vector3(-47,30,100));

	Travellator.collisionRad = 10;
	ObjectList.push_back(Travellator);

	//Cashier
	for (int i = 0; i < 4; ++i)
	{
		Cashier.translateVal.push_back(Vector3(70*i-312,0,240));
		Cashier.rotateVal.push_back(90);
		Cashier.rotateAxis.push_back(Vector3(0,1,0));
		Cashier.scaleVal.push_back(Vector3(5, 5, 5));
	}

	ObjectList.push_back(Cashier);

	//Elevator
	Elevator.translateVal.push_back(Vector3(455,0,1));
	Elevator.rotateVal.push_back(270);
	Elevator.rotateAxis.push_back(Vector3(0,1,0));
	Elevator.scaleVal.push_back(Vector3(12.5,12,13));

	ObjectList.push_back(Elevator);

	Barrier.translateVal.push_back(Vector3(15,150,-230));
	Barrier.rotateVal.push_back(-90);
	Barrier.rotateAxis.push_back(Vector3(0,1,0));
	Barrier.scaleVal.push_back(Vector3(10, 7, 20));

	//left part of barrier
	Barrier.collisionPos.push_back(Vector3(80,180,-190));
	Barrier.collisionPos.push_back(Vector3(100,180,-190));

	Barrier.collisionPos.push_back(Vector3(80,180,-220));
	Barrier.collisionPos.push_back(Vector3(100,180,-220));
	
	Barrier.collisionPos.push_back(Vector3(80,180,-250));
	Barrier.collisionPos.push_back(Vector3(100,180,-250));

	//right part of barrier
	Barrier.collisionPos.push_back(Vector3(-80,180,-190));
	Barrier.collisionPos.push_back(Vector3(-100,180,-190));

	Barrier.collisionPos.push_back(Vector3(-80,180,-220));
	Barrier.collisionPos.push_back(Vector3(-100,180,-220));
	
	Barrier.collisionPos.push_back(Vector3(-80,180,-250));
	Barrier.collisionPos.push_back(Vector3(-100,180,-250));

	//middle part of barrier
	Barrier.collisionPos.push_back(Vector3(80,180, -170));
	Barrier.collisionPos.push_back(Vector3(100,180,-170));

	Barrier.collisionPos.push_back(Vector3(40,180, -170));
	Barrier.collisionPos.push_back(Vector3(20,180,-170));

	Barrier.collisionPos.push_back(Vector3(10,180, -170));
	Barrier.collisionPos.push_back(Vector3(-10,180,-170));

	Barrier.collisionPos.push_back(Vector3(-20,180, -170));
	Barrier.collisionPos.push_back(Vector3(-40,180,-170));

	Barrier.collisionPos.push_back(Vector3(-50,180, -170));
	Barrier.collisionPos.push_back(Vector3(-70,180,-170));
	//right
	Barrier.collisionPos.push_back(Vector3(-80,180, -170));
	Barrier.collisionPos.push_back(Vector3(-100,180,-170));
	
	Barrier.scaleVal.push_back(Vector3(10,7,20));
	
	Barrier.collisionRad = 25;
	ObjectList.push_back(Barrier);

	//Houses on left side
	for(int i = 0; i < 2; i++)
	{
		House.translateVal.push_back(Vector3(-920 + (200*i), 0, 321));
		House.rotateVal.push_back(90);
		House.rotateAxis.push_back(Vector3(0,1,0));
		House.scaleVal.push_back(Vector3(20, 20, 20));

		//collision on 1st house
		House.collisionPos.push_back(Vector3(House.translateVal[2*i].x, 30, House.translateVal[2*i].z));
		House.collisionPos.push_back(Vector3(House.translateVal[2*i].x+60, 30, House.translateVal[2*i].z));
		
		House.collisionPos.push_back(Vector3(House.translateVal[2*i].x, 30, House.translateVal[2*i].z-30));
		House.collisionPos.push_back(Vector3(House.translateVal[2*i].x+60, 30, House.translateVal[2*i].z-30));

		//collision on 2nd house
		House.collisionPos.push_back(Vector3(House.translateVal[2*i].x + 200, 30, House.translateVal[2*i].z));
		House.collisionPos.push_back(Vector3(House.translateVal[2*i].x+260, 30, House.translateVal[2*i].z));
		
		House.collisionPos.push_back(Vector3(House.translateVal[2*i].x + 200,30,House.translateVal[2*i].z-30));
		House.collisionPos.push_back(Vector3(House.translateVal[2*i].x+260,30,House.translateVal[2*i].z-30));

	}
	
	//Houses on right side
	for(int i = 0; i < 2; i++)
	{
		House.translateVal.push_back(Vector3(620 + (200*i), 0, 321));
		House.rotateVal.push_back(90);
		House.rotateAxis.push_back(Vector3(0,1,0));
		House.scaleVal.push_back(Vector3(20, 20, 20));

		//collision on 1st house
		House.collisionPos.push_back(Vector3(House.translateVal[2*i].x, 30, House.translateVal[2*i].z));
		House.collisionPos.push_back(Vector3(House.translateVal[2*i].x+60, 30, House.translateVal[2*i].z));
		
		House.collisionPos.push_back(Vector3(House.translateVal[2*i].x, 30, House.translateVal[2*i].z-30));
		House.collisionPos.push_back(Vector3(House.translateVal[2*i].x+60, 30, House.translateVal[2*i].z-30));

		//collision on 2nd house
		House.collisionPos.push_back(Vector3(House.translateVal[2*i].x + 200, 30, House.translateVal[2*i].z));
		House.collisionPos.push_back(Vector3(House.translateVal[2*i].x+260, 30, House.translateVal[2*i].z));
		
		House.collisionPos.push_back(Vector3(House.translateVal[2*i].x + 200,30,House.translateVal[2*i].z-30));
		House.collisionPos.push_back(Vector3(House.translateVal[2*i].x+260,30,House.translateVal[2*i].z-30));
	}
	
	House.collisionRad = 50;
	ObjectList.push_back(House);

	PickUp1.translateVal.push_back(Vector3(-151,13,-215));
	PickUp1.rotateVal.push_back(-180);
	PickUp1.rotateAxis.push_back(Vector3(0,1,0));
	PickUp1.scaleVal.push_back(Vector3(6,6,6));

	PickUp2.translateVal.push_back(Vector3(-380.5,16,135));
	PickUp2.scaleVal.push_back(Vector3(5,5,5));

	PickUp3.translateVal.push_back(Vector3(200,35.5,35.5));
	PickUp3.rotateVal.push_back(-90);
	PickUp3.rotateAxis.push_back(Vector3(0,1,0));
	PickUp3.scaleVal.push_back(Vector3(5,5,5));
}
void SceneAssignment::InitAI()
{
	/* ==================== UPDATE! Glenn's work ============= */
	InitModelPink();
	/* ==================== UPDATE! Glenn's work ============= */

	modelPink.translateVal.push_back(Vector3(90,0,500));
	modelPink.rotateVal.push_back(0);
	modelPink.rotateAxis.push_back(Vector3(0,1,0));
	modelPink.scaleVal.push_back(Vector3(5,5,5));
	pinkSize = 45;

	for(int i=0;i<pinkSize;++i) {pinkCheck.push_back(true); pinkMove.push_back(0);}

	/* ==================== UPDATE! Glenn's work ============= */
	InitModelBlue();
	/* ==================== UPDATE! Glenn's work ============= */
	modelBlue.translateVal.push_back(Vector3(160,0,550));
	modelBlue.rotateVal.push_back(0);
	modelBlue.rotateAxis.push_back(Vector3(0,1,0));
	modelBlue.scaleVal.push_back(Vector3(5,5,5));
	blueSize = 25;

	for(int i=0;i<blueSize;++i) {blueCheck.push_back(true); blueMove.push_back(0);}

	/* ==================== UPDATE! Glenn's work ============= */
	InitModelOrange();
	/* ==================== UPDATE! Glenn's work ============= */
	modelOrange.translateVal.push_back(Vector3(90,0,600));
	modelOrange.rotateVal.push_back(0);
	modelOrange.rotateAxis.push_back(Vector3(0,1,0));
	modelOrange.scaleVal.push_back(Vector3(5,5,5));
	orangeSize = 30;

	for(int i=0;i<orangeSize;++i) {orangeCheck.push_back(true); orangeMove.push_back(0);}
}
void SceneAssignment::Init()
{
	//travelator
	travel = false;
	travelDwn = false;

	//Character X,Y,Z
	charPos.Set(0,5,0);
	charDir.Set(0,0,1);

	//Door
	DX = -75;
	DX2 = -144;
	D2X = 142;
	D2X2 = 68 ;
	open = false;
	close = false;
	open2 = false;
	close2 = false;

	//ele
	eley =0;
	up = false;
	down = false;
	Lopen = false;
	Lclose = false;
	Lopen2 = false;
	Lclose2 = false;
	waitTime = waitTime2 = 0;
	buttonPress = buttonPress2 = false;

	//debug
	debug = false;
	render1 = render2 = render3 = true;

	LiftDoor = LiftDoor2 = 0;

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
	m_programID = LoadShaders( "Shader//Texture.vertexshader", "Shader//Text.fragmentshader" );

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
	m_parameters[U_TEXT_ENABLED] = glGetUniformLocation(m_programID, "textEnabled");
	m_parameters[U_TEXT_COLOR] = glGetUniformLocation(m_programID, "textColor");

	m_parameters[U_LIGHTENABLED] = glGetUniformLocation(m_programID, "lightEnabled");
	m_parameters[U_TEXT_ENABLED] = glGetUniformLocation(m_programID, "textEnabled");

	m_parameters[U_TEXT_COLOR] = glGetUniformLocation(m_programID, "textColor");
	m_parameters[U_NUMLIGHTS] = glGetUniformLocation(m_programID, "numLights"); //in case you missed out practical 7

	// Get a handle for our "colorTexture" uniform
	m_parameters[U_COLOR_TEXTURE_ENABLED] = glGetUniformLocation(m_programID, "colorTextureEnabled");
	m_parameters[U_COLOR_TEXTURE] = glGetUniformLocation(m_programID, "colorTexture");

	glUseProgram(m_programID);

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
	glUniform1f(m_parameters[U_LIGHT0_COSCUTOFF], light[0].cosCutoff);
	glUniform1f(m_parameters[U_LIGHT0_COSINNER], light[0].cosInner);
	glUniform1f(m_parameters[U_LIGHT0_EXPONENT], light[0].exponent);
	glUniform1i(m_parameters[U_NUMLIGHTS], 1);

	//Initialize camera settings
	camType = PLAYER_CAM;
	playerCamera.Init(Vector3(37, 30, 462), Vector3(0, 1, 0), Vector3(0, 1, 0));
	playerCamera.SetSensitivity(13, 13);
	playerCamera.SetSpeed(150, 800);
	noClipCamera.Init(Vector3(37, 30, 462), Vector3(0, 1,0 ), Vector3(0, 1, 0), true);
	noClipCamera.SetSensitivity(5, 5);
	noClipCamera.SetSpeed(100, 80);

	InitCollision();
	InitLevel1();
	InitLevel2();
	InitObjects();
	InitAI();
	InitExtSkybox();

	Mtx44 projection;
	projection.SetToPerspective(45.f, 4.f / 3.f, 0.1f, 100000.f);
	projectionStack.LoadMatrix(projection);

	collideT = collideG = false;

	FPS = ET = 0;

	meshList[GEO_TEXT] = MeshBuilder::GenerateText("text", 16, 16);
	meshList[GEO_TEXT]->textureID = LoadTGA("Image//Consolas.tga");
}
static float LSPEED = 20.f;
static float ROT_LIMIT = 45.f;
static float SCALE_LIMIT = 5.f;
static float CSPEED = 20.f;
static float RSPEED = 145.f;
static float ROTATE_SPEED = 30.f;
void SceneAssignment::UpdateViewMode(double dt)
{
	if(Application::IsKeyPressed('1')) //enable back face culling
		glEnable(GL_CULL_FACE);
	if(Application::IsKeyPressed('2')) //disable back face culling
		glDisable(GL_CULL_FACE);
	if(Application::IsKeyPressed('3'))
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); //default fill mode
	if(Application::IsKeyPressed('4'))
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); //wireframe mode
}
void SceneAssignment::UpdateLift(double dt)
{
	//Elevator codes============================================================================================================
	if(up)
	{
		eley +=(float)(60 * dt);
		playerCamera.position.y +=(float)(60 * dt);
		playerCamera.target.y +=(float)(60 * dt);
		playerCamera.move = false;
	}
	if(down)
	{
		eley -=(float)(60 * dt);
		playerCamera.position.y -=(float)(60 * dt);
		playerCamera.target.y -=(float)(60 * dt);
		playerCamera.move = false;
	}
	if(Lopen)
	{
		LiftDoor +=(float)(100* dt);
	}
	if(Lclose)
	{
		LiftDoor -=(float)(100* dt);
	}
	if(Lopen2)
	{
		LiftDoor2 +=(float)(100* dt);
	}
	if(Lclose2)
	{
		LiftDoor2 -=(float)(100* dt);
	}
	//Lift Door
	if(((playerCamera.position.z >=-65)&&(playerCamera.position.z <=45))&&((playerCamera.position.x >=280)&&(playerCamera.position.x <=390))&&(eley <=100))
	{
		Lopen = true;
	}
	if(((playerCamera.position.z >=-65)&&(playerCamera.position.z <=45))&&((playerCamera.position.x >=280)&&(playerCamera.position.x <=390))&&(eley >=100))
	{
		Lopen2 = true;
	}
	else if(!((playerCamera.position.z >=-65)&&(playerCamera.position.z <=45))&&((playerCamera.position.x >=280)&&(playerCamera.position.x <=390)))
	{
		Lopen = false;
		Lclose = true;
	}
	if(!((playerCamera.position.z >=-65)&&(playerCamera.position.z <=45))&&((playerCamera.position.x >=280)&&(playerCamera.position.x <=390)))
	{
		Lopen2 = false;
		Lclose2 = true;
	}


	if (LiftDoor <= 0)
		Lclose = false;

	if (LiftDoor >= 118) {
		Lopen = false;
	}

	if (LiftDoor2 >= 118)
	{
		Lopen2 = false;
	}
	if (LiftDoor2 <= 0)
	{
		Lclose2 = false;
	}
	

	//level1-2
	if (Application::IsKeyPressed('C')&&(playerCamera.position.y <= 180)&& playerCamera.position.x > 395 && (down == false))
	{ 
			Lclose = true;
			buttonPress = true;	
	}

	if (buttonPress == true)
	{
		if (waitTime < 75)
			waitTime+=1;
		else if (playerCamera.position.y <= 179)
			up = true;

		if (up == true)
		{
			eley +=1;
			playerCamera.position.y +=1;
			playerCamera.target.y +=1;
			buttonPress = false;
			waitTime = 0;
		}
	}

	
	if ((playerCamera.position.y>=180)&&(up == true))
	{
		up = false;
		Lopen2 = true;
		eley +=1;
		charPos.y+=1;
		playerCamera.move = true;
	}

	//level2-1
	if (Application::IsKeyPressed('V')&&(playerCamera.position.y >= 30)&& playerCamera.position.x > 395 && up == false)
	{ 
			Lclose2 = true;
			buttonPress2 = true;
	}

	if (buttonPress2 == true)
	{
		if (waitTime2 < 75)
			waitTime2+=1;
		else if (playerCamera.position.y >= 31)
			down = true;

		if (down == true)
		{
			eley -=1;
			playerCamera.position.y -=1;
			playerCamera.target.y -=1;
			buttonPress2 = false;
			waitTime2 = 0;
		}
	}



	if ((playerCamera.position.y<=30)&&(down == true))
	{
		down = false;
		Lopen = true;
		eley -=1;
		charPos.y-=1;
		playerCamera.move = true;
		
	}
}
void SceneAssignment::UpdateDoor(double dt)
{
//==========================================================Door EXIT Start=====================================
	if(open)
	{
		DX +=(float)(30 * dt);
		DX2 -=(float)(30 * dt);
	}
	if(close)
	{
		DX -=(float)(30 * dt);
		DX2 +=(float)(30 * dt);
	}
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!THIS PART NEED UPDATE!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	if (((playerCamera.position.z >= 250)&&(playerCamera.position.z <= 300))&&((playerCamera.position.x >= -166)&&(playerCamera.position.x <= -60))&&(close == false))
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!THIS PART NEED UPDATE!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	{
		open = true;
	}
	if (((DX >=-8)&&(DX2 <=-210)))
	{
		open = false;
		close = true;
	}
	if(((DX <=-75)&&(DX2>=-144))&&(close == true))
	{
		close = false;
	}
//============================================================END========================

//==========================================================Door Entrance Start===================
	if(open2)
	{
		D2X +=(float)(30 * dt);
		D2X2 -=(float)(30 * dt);
	}
	if(close2)
	{
		D2X -=(float)(30 * dt);
		D2X2 +=(float)(30 * dt);
	}
	if (((playerCamera.position.z >= 350)&&(playerCamera.position.z <= 465))&&((playerCamera.position.x >= 70)&&(playerCamera.position.x <= 150))&&(close2 == false))
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!THIS PART NEED UPDATE!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	{
		open2 = true;
	}
	if(((D2X >=221) && (D2X2<=-11)))
	{
		open2 = false;
		close2 = true;
	}
	if(((D2X <=142)&&(D2X2 >=68))&&(close2 == true))
	{
		close2 = false;
	}
//============================================================END===============================================================================================

}
void SceneAssignment::UpdateLight(double dt)
{
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
}
void SceneAssignment::UpdateTravel(double dt)
{
	//========================================================Travelator Up========================================================================================

	if (travel)
	{
		playerCamera.position.z -=(float)(25 * dt * 3);
		playerCamera.position.y +=(float)(11 * dt* 3);
		playerCamera.target.z -=(float)(25 * dt* 3);
		playerCamera.target.y +=(float)(11 * dt* 3);
		playerCamera.move = false;
	}
	else if (playerCamera.position.x <= 395)
	{
		playerCamera.move = true;
	}
	if (travelDwn)
	{
		playerCamera.position.z +=(float)(25 * dt* 3);
		playerCamera.position.y -=(float)(11 * dt* 3);
		playerCamera.target.z +=(float)(25 * dt* 3);
		playerCamera.target.y -=(float)(11 * dt* 3);
		playerCamera.move = false;
	}

	//=========================================================Boolean End=========================================================================================
	if (((playerCamera.position.z >= 123)&&(playerCamera.position.z <=130)) && ((playerCamera.position.x >=22) && (playerCamera.position.x <=44)))
	{
		travel = true;
	}
	if(playerCamera.position.y >= 180)
	{
		travel = false;
	}
	//=========================================================UP END===============================================================================================
	
	/*-------------------------------------------------!! UPDATE NEEDED (WEI HENG) !!----------------------------------------------------*/
	if (((playerCamera.position.z >= -225)&&(playerCamera.position.z <=-210)) && ((playerCamera.position.x >= -60) && (playerCamera.position.x <=-36))&&(playerCamera.position.y >= 180))
	/*-------------------------------------------------!! UPDATE NEEDED (WEI HENG) !!----------------------------------------------------*/
	{
		travelDwn = true;
	}
	if(playerCamera.position.y <= 30)
	{
		travelDwn = false;
	}
	//============================================================END===============================================================================================

}
void SceneAssignment::UpdateModelGlenn(double dt)
{
	static int rotateDir = 1;

	if(rotateAngle * rotateDir > 10)
		rotateDir = -rotateDir;
	rotateAngle += (float)(rotateDir * ROTATE_SPEED * dt);
}
void SceneAssignment::Update(double dt)
{
	bool collideALL = Collision(charPos,ObjectList);

	FPS = 1/dt;
	ET += dt;

	UpdateModelGlenn(dt);
	UpdateViewMode(dt);
	UpdateDoor(dt);
	UpdateLift(dt);
	UpdateLift(dt);
	UpdateTravel(dt);

	if(Application::IsKeyPressed('Q'))
	{
		debug = true;
	}
	if(Application::IsKeyPressed('E'))
	{
		debug = false;
	}
	if (Application::IsKeyPressed('F') && Collision(playerCamera.position,ObjectList,4,28))
	{
		render1 = false;
	}

	if (Application::IsKeyPressed('F') && Collision(playerCamera.position,ObjectList,2,29))
	{
		render2 = false;
	}

	if (Application::IsKeyPressed('F') && Collision(playerCamera.position,ObjectList,3,4))
	{
		render3 = false;
	}

	if (Application::IsKeyPressed('F') && Collision(playerCamera.position,ObjectList,3,4))
	{
		renderscenerio3 = false;
	}
	
	//light ball controls
	if(Application::IsKeyPressed('I'))
		light[0].position.z -= (float)(LSPEED * dt);
	if(Application::IsKeyPressed('K'))
		light[0].position.z += (float)(LSPEED * dt);
	if(Application::IsKeyPressed('J'))
		light[0].position.x -= (float)(LSPEED * dt);
	if(Application::IsKeyPressed('L'))
		light[0].position.x += (float)(LSPEED * dt);
	if(Application::IsKeyPressed('N'))
		light[0].position.y -= (float)(LSPEED * dt);
	if(Application::IsKeyPressed('M'))
		light[0].position.y += (float)(LSPEED * dt);

	/*============================== Glenn's Work Begins ===============================
	//normal situation when flash = false
	if(flash == false)
	{
		//turn on light
		if(Application::IsKeyPressed('T'))
		{
			glUniform1f(m_parameters[U_LIGHT0_POWER], light[0].power);	
			glUniform1f(m_parameters[U_LIGHT0_KC], light[0].kC);
			glUniform1f(m_parameters[U_LIGHT0_KL], light[0].kL);
			glUniform1f(m_parameters[U_LIGHT0_KQ], light[0].kQ);
			glUniform1i(m_parameters[U_NUMLIGHTS], 1);
		}

		//turn off light
		if(Application::IsKeyPressed('Y'))
		{
			glUniform1f(m_parameters[U_LIGHT0_POWER], 0);
			glUniform1f(m_parameters[U_LIGHT0_KC], 0);
			glUniform1f(m_parameters[U_LIGHT0_KL], 0);
			glUniform1f(m_parameters[U_LIGHT0_KQ], 0);
			glUniform1i(m_parameters[U_NUMLIGHTS], 0);
		}

		if(ET > 4)
		{
			flash = true;
		}
	}

	if(flash == true)
	{
		//change light color to red
		if((int)ET%2 == 0)
		{
			light[0].color.Set(1, 0, 0);
			// Make sure you pass uniform parameters after glUseProgram()
			glUniform3fv(m_parameters[U_LIGHT0_COLOR], 1, &light[0].color.r);

		}
		//change light color to white
		if((int)ET%2 != 0)
		{
			light[0].color.Set(1.f, 0.5f, 0);
			// Make sure you pass uniform parameters after glUseProgram()
			glUniform3fv(m_parameters[U_LIGHT0_COLOR], 1, &light[0].color.r);

		}
	}
	============================== Glenn's Work Ends ===============================*/

	playerCamera.Update(dt,ObjectList);
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
	//Level 1 Skybox
	int temp = GEO_TOP_L1;
	for (int i = 0; i < Skybox1.getTotal(); ++i)
	{
		modelStack.PushMatrix();
		modelStack.Translate(Skybox1.translateVal[i].x,Skybox1.translateVal[i].y,Skybox1.translateVal[i].z);
		modelStack.Rotate(Skybox1.rotateVal[i],Skybox1.rotateAxis[i].x,Skybox1.rotateAxis[i].y,Skybox1.rotateAxis[i].z);
		modelStack.Scale(Skybox1.scaleVal[i].x, Skybox1.scaleVal[i].y, Skybox1.scaleVal[i].z);
		RenderMesh(meshList[temp], false);
		modelStack.PopMatrix();
		temp++;
	}
		//=============================================================RenderDoor=============================Credit:Andy===========================================
	//ExitLeft
	modelStack.PushMatrix();
	modelStack.Translate(DX, 53, 324.5);
	modelStack.Scale(70, 105, 0);
	RenderMesh(meshList[GEO_DOOR], false);
	modelStack.PopMatrix();

	//ExitRight
	modelStack.PushMatrix();
	modelStack.Translate(DX2, 53, 324.5);
	modelStack.Rotate(180,0,1,0);
	modelStack.Scale(70, 105, 0);
	RenderMesh(meshList[GEO_DOOR], false);
	modelStack.PopMatrix();
	//entrance right
	modelStack.PushMatrix();
	modelStack.Translate(D2X2, 53, 325.5);
	modelStack.Rotate(180,0,1,0);
	modelStack.Scale(74, 105, 0);
	RenderMesh(meshList[GEO_DOOR], false);
	modelStack.PopMatrix();
	//entranceleft
	modelStack.PushMatrix();
	modelStack.Translate(D2X, 53, 325.5);
	modelStack.Scale(74, 105, 0);
	RenderMesh(meshList[GEO_DOOR], false);
	modelStack.PopMatrix();

}
void SceneAssignment::RenderLevel2()
{
	//Level 2 Skybox
	int temp = GEO_TOP2;
	for (int i = 0; i < Skybox2.getTotal(); ++i)
	{
		modelStack.PushMatrix();
		modelStack.Translate(Skybox2.translateVal[i].x,Skybox2.translateVal[i].y,Skybox2.translateVal[i].z);
		modelStack.Rotate(Skybox2.rotateVal[i],Skybox2.rotateAxis[i].x,Skybox2.rotateAxis[i].y,Skybox2.rotateAxis[i].z);
		modelStack.Scale(Skybox2.scaleVal[i].x, Skybox2.scaleVal[i].y, Skybox2.scaleVal[i].z);
		RenderMesh(meshList[temp], false);
		modelStack.PopMatrix();
		temp++;
	}

	for (int i = 0; i < Barrier.getTotal(); ++i)
	{
		modelStack.PushMatrix();
		modelStack.Translate(Barrier.translateVal[i].x,Barrier.translateVal[i].y,Barrier.translateVal[i].z);
		modelStack.Rotate(Barrier.rotateVal[i],Barrier.rotateAxis[i].x,Barrier.rotateAxis[i].y,Barrier.rotateAxis[i].z);
		modelStack.Scale(Barrier.scaleVal[i].x, Barrier.scaleVal[i].y, Barrier.scaleVal[i].z);
		RenderMesh(meshList[GEO_BARRIER], false);
		modelStack.PopMatrix();
	}
}
void SceneAssignment::RenderLargeObjects()
{

	//basket for fruits and vegetables
	for (int i = 0; i < Basket.getTotal(); ++i)
	{
		modelStack.PushMatrix();
		modelStack.Translate(Basket.translateVal[i].x,Basket.translateVal[i].y,Basket.translateVal[i].z);
		modelStack.Rotate(Basket.rotateVal[i],Basket.rotateAxis[i].x,Basket.rotateAxis[i].y,Basket.rotateAxis[i].z);
		modelStack.Scale(Basket.scaleVal[i].x, Basket.scaleVal[i].y, Basket.scaleVal[i].z);
		RenderMesh(meshList[GEO_BASKET], false);
		modelStack.PopMatrix();
	}

	//cooler
	for (int i = 0; i < Cooler.getTotal(); ++i)
	{
		modelStack.PushMatrix();
		modelStack.Translate(Cooler.translateVal[i].x,Cooler.translateVal[i].y,Cooler.translateVal[i].z);
		modelStack.Scale(Cooler.scaleVal[i].x, Cooler.scaleVal[i].y, Cooler.scaleVal[i].z);
		RenderMesh(meshList[GEO_COOLER], false);
		modelStack.PopMatrix();
	}

	//Shelf
	for (int i = 0; i < Shelf.getTotal(); ++i)
	{
		modelStack.PushMatrix();
		modelStack.Translate(Shelf.translateVal[i].x,Shelf.translateVal[i].y,Shelf.translateVal[i].z);
		modelStack.Scale(Shelf.scaleVal[i].x, Shelf.scaleVal[i].y, Shelf.scaleVal[i].z);
		RenderMesh(meshList[GEO_SHELF], false);
		modelStack.PopMatrix();
	}

	int temp2 = GEO_TRAVELATORUP;
	for (int i = 0; i < Travellator.getTotal(); ++i)
	{
		modelStack.PushMatrix();
		modelStack.Translate(Travellator.translateVal[i].x,Travellator.translateVal[i].y,Travellator.translateVal[i].z);
		modelStack.Rotate(Travellator.rotateVal[i],Travellator.rotateAxis[i].x,Travellator.rotateAxis[i].y,Travellator.rotateAxis[i].z);
		modelStack.Scale(Travellator.scaleVal[i].x, Travellator.scaleVal[i].y, Travellator.scaleVal[i].z);
		RenderMesh(meshList[temp2], false);
		modelStack.PopMatrix();
		temp2++;
	}

	//4 cash register
	for (int i = 0; i < Register.getTotal(); ++i)
	{
		modelStack.PushMatrix();
		modelStack.Translate(Register.translateVal[i].x,Register.translateVal[i].y,Register.translateVal[i].z);
		modelStack.Scale(Register.scaleVal[i].x,Register.scaleVal[i].y,Register.scaleVal[i].z);
		RenderMesh(meshList[GEO_REGISTER], false);
		modelStack.PopMatrix();
	}

	//level1///////////////////////////////////
	//shelves

	for(int num = 0; num < 2; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(70*num-300, 150, -220);
		modelStack.Scale(15,5,4);
		RenderMesh(meshList[GEO_SHELF], false);
		modelStack.PopMatrix();
	}

	for(int num = 0; num < 2; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(70*num-300, 150, -120);
		modelStack.Scale(15,5,4);
		RenderMesh(meshList[GEO_SHELF], false);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 2; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(70*num-300, 150, -20);
		modelStack.Scale(15,5,4);
		RenderMesh(meshList[GEO_SHELF], false);
		modelStack.PopMatrix();
	}

	for(int num = 0; num < 2; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(70*num-300, 150, 80);
		modelStack.Scale(15,5,4);
		RenderMesh(meshList[GEO_SHELF], false);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 2; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(70*num-300, 150, 180);
		modelStack.Scale(15,5,4);
		RenderMesh(meshList[GEO_SHELF], false);
		modelStack.PopMatrix();
	}

	for(int num = 0; num < 2; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(70*num-300, 150, 280);
		modelStack.Scale(15,5,4);
		RenderMesh(meshList[GEO_SHELF], false);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 2; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(70*num-300, 150, 280);
		modelStack.Scale(15,5,4);
		RenderMesh(meshList[GEO_SHELF], false);
		modelStack.PopMatrix();
	}

	//first column
	for(int num = 0; num < 2; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(70*num+200, 150, -220);
		modelStack.Scale(15,5,4);
		RenderMesh(meshList[GEO_SHELF], false);
		modelStack.PopMatrix();
	}

	for(int num = 0; num < 2; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(70*num+200, 150, -120);
		modelStack.Scale(15,5,4);
		RenderMesh(meshList[GEO_SHELF], false);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 2; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(70*num+200, 150, -20);
		modelStack.Scale(15,5,4);
		RenderMesh(meshList[GEO_SHELF], false);
		modelStack.PopMatrix();
	}

	for(int num = 0; num < 2; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(70*num+200, 150, 80);
		modelStack.Scale(15,5,4);
		RenderMesh(meshList[GEO_SHELF], false);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 2; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(70*num+200, 150, 180);
		modelStack.Scale(15,5,4);
		RenderMesh(meshList[GEO_SHELF], false);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 2; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(70*num+200, 150, 280);
		modelStack.Scale(15,5,4);
		RenderMesh(meshList[GEO_SHELF], false);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 2; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(70*num+200, 150, 280);
		modelStack.Scale(15,5,4);
		RenderMesh(meshList[GEO_SHELF], false);
		modelStack.PopMatrix();
	}

	//shelf middle
	for(int num = 0; num < 3; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(70*num-75, 150, -100);
		modelStack.Scale(15,5,4);
		RenderMesh(meshList[GEO_SHELF], false);
		modelStack.PopMatrix();
	}

	for(int num = 0; num < 3; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(70*num-75, 150, 0);
		modelStack.Scale(15,5,4);
		RenderMesh(meshList[GEO_SHELF], false);
		modelStack.PopMatrix();
	}

	for(int num = 0; num < 3; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(70*num-75, 150, 100);
		modelStack.Scale(15,5,4);
		RenderMesh(meshList[GEO_SHELF], false);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 3; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(70*num-75, 150, 200);
		modelStack.Scale(15,5,4);
		RenderMesh(meshList[GEO_SHELF], false);
		modelStack.PopMatrix();
	}
	modelStack.PushMatrix();
	modelStack.Translate(15, 150, -230);
	modelStack.Rotate(-90, 0, 1, 0);
	modelStack.Scale(10,7,20);
	RenderMesh(meshList[GEO_BARRIER], false);
	modelStack.PopMatrix();
}
void SceneAssignment::RenderRightColumn()
{
	//right/last from back/bottom row//////////////////////////////////
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num+160, 141, -217);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], false);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num+160, 141, -221);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], false);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num+160, 141, -224);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], false);
		modelStack.PopMatrix();
	}
	//right/last from back/middle row///////////////////////////////////
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num+160, 153, -217);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], false);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num+160, 153, -221);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], false);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num+160, 153, -224);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], false);
		modelStack.PopMatrix();
	}
	//right/last from back/top row////////////////////////////////////////////////
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num+160, 165, -217);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], false);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num+160, 165, -221);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], false);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num+160, 165, -224);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], false);
		modelStack.PopMatrix();
	}
	//right/ 2 last from back/bottom row//////////////////////////////////
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num+160, 141, -117);//-217
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], false);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num+160, 141, -121);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], false);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num+160, 141, -124);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], false);
		modelStack.PopMatrix();
	}
	//right/2 last from back/middle row///////////////////////////////////
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num+160, 153, -117);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], false);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num+160, 153, -121);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], false);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num+160, 153, -124);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], false);
		modelStack.PopMatrix();
	}
	//right/2 last from back/top row////////////////////////////////////////////////
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num+160, 165, -117);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], false);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num+160, 165, -121);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], false);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num+160, 165, -124);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], false);
		modelStack.PopMatrix();
	}
	//right/3 last from back/bottom row//////////////////////////////////
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num+160, 141, -17);//-217
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], false);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num+160, 141, -21);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], false);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num+160, 141, -24);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], false);
		modelStack.PopMatrix();
	}
	//right/3 last from back/middle row///////////////////////////////////
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num+160, 153, -17);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], false);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num+160, 153, -21);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], false);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num+160, 153, -24);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], false);
		modelStack.PopMatrix();
	}
	//right/3 last from back/top row////////////////////////////////////////////////
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num+160, 165, -17);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], false);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num+160, 165, -21);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], false);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num+160, 165, -24);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], false);
		modelStack.PopMatrix();
	}
	//right/4 last from back/bottom row//////////////////////////////////
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num+160, 141, 83);//-217
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], false);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num+160, 141, 79);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], false);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num+160, 141, 76);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], false);
		modelStack.PopMatrix();
	}
	//right/4 last from back/middle row///////////////////////////////////
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num+160, 153, 83);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], false);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num+160, 153, 79);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], false);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num+160, 153, 76);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], false);
		modelStack.PopMatrix();
	}
	//right/4 last from back/top row////////////////////////////////////////////////
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num+160, 165, 83);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], false);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num+160, 165, 79);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], false);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num+160, 165, 76);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], false);
		modelStack.PopMatrix();
	}
	//right/5 last from back/bottom row//////////////////////////////////
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num+160, 141, 183);//-217
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], false);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num+160, 141, 179);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], false);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num+160, 141, 176);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], false);
		modelStack.PopMatrix();
	}
	//right/5 last from back/middle row///////////////////////////////////
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num+160, 153, 183);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], false);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num+160, 153, 179);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], false);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num+160, 153, 176);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], false);
		modelStack.PopMatrix();
	}
	//right/5 last from back/top row////////////////////////////////////////////////
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num+160, 165, 183);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], false);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num+160, 165, 179);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], false);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num+160, 165, 176);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], false);
		modelStack.PopMatrix();
	}
	//right/6 last from back/bottom row//////////////////////////////////
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num+160, 141, 283);//-217
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], false);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num+160, 141, 279);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], false);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num+160, 141, 276);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], false);
		modelStack.PopMatrix();
	}
	//right/6 last from back/middle row///////////////////////////////////
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num+160, 153, 283);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], false);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num+160, 153, 279);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], false);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num+160, 153, 276);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], false);
		modelStack.PopMatrix();
	}
	//right/6 last from back/top row////////////////////////////////////////////////
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num+160, 165, 283);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], false);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num+160, 165, 279);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], false);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num+160, 165, 276);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], false);
		modelStack.PopMatrix();
	}

}
void SceneAssignment::RenderLeftColumn()
{
	//left/last from back/bottom row//////////////////////////////////
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num-340, 141, -217);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], false);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num-340, 141, -221);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], false);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num-340, 141, -224);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], false);
		modelStack.PopMatrix();
	}
	//left/last from back/middle row///////////////////////////////////
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num-340, 153, -217);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], false);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num-340, 153, -221);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], false);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num-340, 153, -224);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], false);
		modelStack.PopMatrix();
	}
	//left/last from back/top row////////////////////////////////////////////////
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num-340, 165, -217);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], false);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num-340, 165, -221);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], false);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num-340, 165, -224);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], false);
		modelStack.PopMatrix();
	}
	//left/ 2 last from back/bottom row//////////////////////////////////
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num-340, 141, -117);//-217
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], false);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num-340, 141, -121);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], false);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num-340, 141, -124);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], false);
		modelStack.PopMatrix();
	}
	//left/2 last from back/middle row///////////////////////////////////
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num-340, 153, -117);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], false);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num-340, 153, -121);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], false);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num-340, 153, -124);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], false);
		modelStack.PopMatrix();
	}
	//left/2 last from back/top row////////////////////////////////////////////////
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num-340, 165, -117);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], false);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num-340, 165, -121);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], false);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num-340, 165, -124);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], false);
		modelStack.PopMatrix();
	}
	//left/3 last from back/bottom row//////////////////////////////////
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num-340, 141, -17);//-217
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], false);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num-340, 141, -21);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], false);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num-340, 141, -24);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], false);
		modelStack.PopMatrix();
	}
	//left/3 last from back/middle row///////////////////////////////////
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num-340, 153, -17);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], false);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num-340, 153, -21);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], false);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num-340, 153, -24);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], false);
		modelStack.PopMatrix();
	}
	//left/3 last from back/top row////////////////////////////////////////////////
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num-340, 165, -17);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], false);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num-340, 165, -21);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], false);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num-340, 165, -24);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], false);
		modelStack.PopMatrix();
	}
	//left/4 last from back/bottom row//////////////////////////////////
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num-340, 141, 83);//-217
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], false);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num-340, 141, 79);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], false);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num-340, 141, 76);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], false);
		modelStack.PopMatrix();
	}
	//left/4 last from back/middle row///////////////////////////////////
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num-340, 153, 83);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], false);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num-340, 153, 79);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], false);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num-340, 153, 76);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], false);
		modelStack.PopMatrix();
	}
	//left/4 last from back/top row////////////////////////////////////////////////
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num-340, 165, 83);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], false);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num-340, 165, 79);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], false);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num-340, 165, 76);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], false);
		modelStack.PopMatrix();
	}
	//left/5 last from back/bottom row//////////////////////////////////
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num-340, 141, 183);//-217
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], false);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num-340, 141, 179);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], false);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num-340, 141, 176);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], false);
		modelStack.PopMatrix();
	}
	//left/5 last from back/middle row///////////////////////////////////
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num-340, 153, 183);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], false);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num-340, 153, 179);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], false);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num-340, 153, 176);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], false);
		modelStack.PopMatrix();
	}
	//left/5 last from back/top row////////////////////////////////////////////////
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num-340, 165, 183);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], false);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num-340, 165, 179);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], false);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num-340, 165, 176);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], false);
		modelStack.PopMatrix();
	}
	//left/6 last from back/bottom row//////////////////////////////////
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num-340, 141, 283);//-217
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], false);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num-340, 141, 279);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], false);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num-340, 141, 276);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], false);
		modelStack.PopMatrix();
	}
	//left/6 last from back/middle row///////////////////////////////////
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num-340, 153, 283);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], false);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num-340, 153, 279);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], false);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num-340, 153, 276);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], false);
		modelStack.PopMatrix();
	}
	//left/6 last from back/top row////////////////////////////////////////////////
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num-340, 165, 283);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], false);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num-340, 165, 279);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], false);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num-340, 165, 276);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], false);
		modelStack.PopMatrix();
	}

}
void SceneAssignment::RenderMiddleColumn()
{
	//middle/ 2 last from back/bottom row//////////////////////////////////
	for(int num = 0; num < 40; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(5*num-105, 154, -97);//-217
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_CAN1], false);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 40; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(5*num-105, 154, -102);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_CAN1], false);
		modelStack.PopMatrix();
	}
	//middle/2 last from back/middle row///////////////////////////////////
	for(int num = 0; num < 40; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(5*num-105, 165, -97);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_CAN1], false);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 40; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(5*num-105, 165, -102);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_CAN1], false);
		modelStack.PopMatrix();
	}
	//middle/2 last from back/top row////////////////////////////////////////////////
	for(int num = 0; num < 40; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(5*num-105, 177, -97);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_CAN1], false);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 40; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(5*num-105, 177, -102);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_CAN1], false);
		modelStack.PopMatrix();
	}
	//middle/ 3 last from back/bottom row//////////////////////////////////
	for(int num = 0; num < 40; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(5*num-105, 154, 3);//-217
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_CAN1], false);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 40; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(5*num-105, 154, -2);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_CAN1], false);
		modelStack.PopMatrix();
	}
	//middle/3 last from back/middle row///////////////////////////////////
	for(int num = 0; num < 40; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(5*num-105, 165, 3);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_CAN1], false);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 40; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(5*num-105, 165, -2);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_CAN1], false);
		modelStack.PopMatrix();
	}
	//middle/3 last from back/top row////////////////////////////////////////////////
	for(int num = 0; num < 40; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(5*num-105, 177, 3);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_CAN1], false);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 40; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(5*num-105, 177, -2);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_CAN1], false);
		modelStack.PopMatrix();
	}
	//middle/4 last from back/bottom row//////////////////////////////////
	for(int num = 0; num < 40; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(5*num-105, 154, 103);//-217
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_CAN1], false);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 40; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(5*num-105, 154, 98);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_CAN1], false);
		modelStack.PopMatrix();
	}
	//middle/4 last from back/middle row///////////////////////////////////
	for(int num = 0; num < 40; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(5*num-105, 165, 103);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_CAN1], false);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 40; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(5*num-105, 165, 98);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_CAN1], false);
		modelStack.PopMatrix();
	}
	//middle/4 last from back/top row////////////////////////////////////////////////
	for(int num = 0; num < 40; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(5*num-105, 177, 103);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_CAN1], false);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 40; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(5*num-105, 177, 98);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_CAN1], false);
		modelStack.PopMatrix();
	}
	//middle/5 last from back/bottom row//////////////////////////////////
	for(int num = 0; num < 40; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(5*num-105, 154, 203);//-217
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_CAN1], false);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 40; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(5*num-105, 154, 198);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_CAN1], false);
		modelStack.PopMatrix();
	}
	//middle/5 last from back/middle row///////////////////////////////////
	for(int num = 0; num < 40; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(5*num-105, 165, 203);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_CAN1], false);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 40; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(5*num-105, 165, 198);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_CAN1], false);
		modelStack.PopMatrix();
	}
	//middle/5 last from back/top row////////////////////////////////////////////////
	for(int num = 0; num < 40; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(5*num-105, 177, 203);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_CAN1], false);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 40; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(5*num-105, 177, 198);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_CAN1], false);
		modelStack.PopMatrix();
	}
}
void SceneAssignment::RenderSmallObjects()
{
	//left column
	//apples on one basket..
	for(int numA = 0; numA < 36; numA++)
	{
		modelStack.PushMatrix();
		if(numA >= 0 && numA < 12)
		{
			modelStack.Translate(-390, 20, -190 + (-5*numA));
		}
		if(numA >= 12 && numA < 24)
		{
			modelStack.Translate(-385, 18, -130 + (-5*numA));
		}
		if(numA >= 24 && numA < 36)
		{
			modelStack.Translate(-380, 16, -70 + (-5*numA));
		}
		modelStack.Scale(10, 10, 10);
		RenderMesh(meshList[GEO_APPLE], false);
		modelStack.PopMatrix();
	}

	//cabbages
	for(int numA = 0; numA < 27; numA++)
	{
		modelStack.PushMatrix();
		if(numA >= 0 && numA < 9)
		{
			modelStack.Translate(-390, 20, -95 + (-7*numA));
		}
		if(numA >= 9 && numA < 18)
		{
			modelStack.Translate(-385, 18, -32 + (-7*numA));
		}
		if(numA >= 18 && numA < 27)
		{
			modelStack.Translate(-380, 16, 31 + (-7*numA));
		}
		modelStack.Scale(5, 5, 5);
		RenderMesh(meshList[GEO_CABBAGE], false);
		modelStack.PopMatrix();
	}

	//oranges
	for(int numA = 0; numA < 27; numA++)
	{
		modelStack.PushMatrix();
		if(numA >= 0 && numA < 9)
		{
			modelStack.Translate(-390, 20, (-7*numA));
		}
		if(numA >= 9 && numA < 18)
		{
			modelStack.Translate(-385, 18, 65 + (-7*numA));
		}
		if(numA >= 18 && numA < 27)
		{
			modelStack.Translate(-380, 16, 125 + (-7*numA));
		}
		modelStack.Scale(6, 6, 6);
		RenderMesh(meshList[GEO_ORANGE], false);
		modelStack.PopMatrix();
	}

	//watermelon
	for(int numA = 0; numA < 30; numA++)
	{
		modelStack.PushMatrix();
		if(numA >= 0 && numA < 10)
		{
			modelStack.Translate(-390, 20, 90 + (-5*numA));
		}
		if(numA >= 10 && numA < 20)
		{
			modelStack.Translate(-385, 18, 140 + (-5*numA));
		}
		if(numA >= 20 && numA < 30)
		{
			modelStack.Translate(-380, 16, 190 + (-5*numA));
		}
		modelStack.Scale(5, 5, 5);
		RenderMesh(meshList[GEO_WATERMELON], false);
		modelStack.PopMatrix();
	}
	//coconut
	for(int numA = 0; numA < 30; numA++)
	{
		modelStack.PushMatrix();
		if(numA >= 0 && numA < 10)
		{
			modelStack.Translate(-390, 20, 190 + (-5*numA));
		}
		if(numA >= 10 && numA < 20)
		{
			modelStack.Translate(-385, 18, 240 + (-5*numA));
		}
		if(numA >= 20 && numA < 30)
		{
			modelStack.Translate(-380, 16, 290 + (-5*numA));
		}
		modelStack.Scale(5, 5, 5);
		RenderMesh(meshList[GEO_COCONUT], false);
		modelStack.PopMatrix();
	}

	//middle column
	//apples on one basket..
	for(int numA = 0; numA < 36; numA++)
	{
		modelStack.PushMatrix();
		if(numA >= 0 && numA < 12)
		{
			modelStack.Translate(-195 + (-5*numA), 18, -310);
		}
		if(numA >= 12 && numA < 24)
		{
			modelStack.Translate(-135 + (-5*numA), 16, -305);
		}
		if(numA >= 24 && numA < 36)
		{
			modelStack.Translate(-75 + (-5*numA), 14, -300);
		}
		modelStack.Scale(10, 10, 10);
		RenderMesh(meshList[GEO_APPLE], false);
		modelStack.PopMatrix();
	}

	//cabbages
	for(int numA = 0; numA < 27; numA++)
	{
		modelStack.PushMatrix();

		if(numA >= 0 && numA < 9)
		{
			modelStack.Translate(-100 + (-7*numA), 20, -310);
		}
		if(numA >= 9 && numA < 18)
		{
			modelStack.Translate(-37 + (-7*numA), 18, -305);
		}
		if(numA >= 18 && numA < 27)
		{
			modelStack.Translate(26 + (-7*numA), 16, -300);
		}
		modelStack.Scale(5, 5, 5);
		RenderMesh(meshList[GEO_CABBAGE], false);
		modelStack.PopMatrix();
	}
	//oranges
	for(int numA = 0; numA < 27; numA++)
	{
		modelStack.PushMatrix();
		if(numA >= 0 && numA < 9)
		{
			modelStack.Translate( -5 +(-7*numA), 20, -310);
		}
		if(numA >= 9 && numA < 18)
		{
			modelStack.Translate(60 +(-7*numA), 18, -305);
		}
		if(numA >= 18 && numA < 27)
		{
			modelStack.Translate(120 + (-7*numA), 16, -300);
		}
		modelStack.Scale(6, 6, 6);
		RenderMesh(meshList[GEO_ORANGE], false);
		modelStack.PopMatrix();
	}

	//watermelon
	for(int numA = 0; numA < 24; numA++)
	{
		modelStack.PushMatrix();
		if(numA >= 0 && numA < 8)
		{
			modelStack.Translate(90 + (-7*numA), 20, -310);
		}
		if(numA >= 8 && numA < 16)
		{
			modelStack.Translate(145 + (-7*numA), 18, -305);
		}
		if(numA >= 16 && numA < 24)
		{
			modelStack.Translate(200 + (-7*numA), 16, -300);
		}
		modelStack.Scale(5, 5, 5);
		RenderMesh(meshList[GEO_WATERMELON], false);
		modelStack.PopMatrix();
	}

	//coconut
	for(int numA = 0; numA < 30; numA++)
	{
		modelStack.PushMatrix();
		if(numA >= 0 && numA < 10)
		{
			modelStack.Translate(180 + (-5*numA), 20, -310);
		}
		if(numA >= 10 && numA < 20)
		{
			modelStack.Translate(230 + (-5*numA), 18, -305);
		}
		if(numA >= 20 && numA < 30)
		{
			modelStack.Translate(280 + (-5*numA), 16, -300);
		}
		modelStack.Scale(5, 5, 5);
		RenderMesh(meshList[GEO_COCONUT], false);
		modelStack.PopMatrix();
	}

	//coconut
	for(int numA = 0; numA < 30; numA++)
	{
		modelStack.PushMatrix();
		if(numA >= 0 && numA < 10)
		{
			modelStack.Translate(280 + (-5*numA), 20, -310);
		}
		if(numA >= 10 && numA < 20)
		{
			modelStack.Translate(330 + (-5*numA), 18, -305);
		}
		if(numA >= 20 && numA < 30)
		{
			modelStack.Translate(380 + (-5*numA), 16, -300);
		}
		modelStack.Scale(5, 5, 5);
		RenderMesh(meshList[GEO_COCONUT], false);
		modelStack.PopMatrix();
	}

	//lodin packet
	for(int numA = 0; numA < 120; numA++)
	{
		modelStack.PushMatrix();
		if(numA >= 0 && numA < 30)
		{
			modelStack.Translate(165 + (4*numA), 15, -225);
		}
		if(numA >= 30 && numA < 60)
		{
			modelStack.Translate(50 + (4*numA), 15, -220);
		}
		if(numA >= 60 && numA < 90)
		{
			modelStack.Translate(-60 + (4*numA), 3, -225);
		}
		if(numA >= 90 && numA < 120)
		{
			modelStack.Translate(-180 + (4*numA), 3, -220);
		}
		modelStack.Rotate(90, 0, 1, 0);
		modelStack.Scale(6, 6, 6);
		RenderMesh(meshList[GEO_LODIN], false);
		modelStack.PopMatrix();
	}
	//lodin packet
	for(int numA = 0; numA < 120; numA++)
	{
		modelStack.PushMatrix();
		if(numA >= 0 && numA < 30)
		{
			modelStack.Translate(-270 + (4*numA), 15, -225);
		}
		if(numA >= 30 && numA < 60)
		{
			modelStack.Translate(-400 + (4*numA), 15, -220);
		}
		if(numA >= 60 && numA < 90)
		{
			modelStack.Translate(-510 + (4*numA), 3, -225);
		}
		if(numA >= 90 && numA < 120)
		{
			modelStack.Translate(-630 + (4*numA), 3, -220);
		}
		modelStack.Rotate(90, 0, 1, 0);
		modelStack.Scale(6, 6, 6);
		RenderMesh(meshList[GEO_LODIN], false);
		modelStack.PopMatrix();
	}	

	//ice cream
	for(int numA = 0; numA < 40; numA++)
	{
		modelStack.PushMatrix();
		if(numA >= 0 && numA < 20)
		{
			modelStack.Translate(-200, 15, 47 + (-5*numA));	
		}
		if(numA >= 20 && numA < 40)
		{
			modelStack.Translate(-200, 15, 260 + (-5*numA));
		}
		modelStack.Scale(5, 5, 5);
		RenderMesh(meshList[GEO_ICECREAM], false);
		modelStack.PopMatrix();
	}

	//ice cream
	for(int numA = 0; numA < 40; numA++)
	{
		modelStack.PushMatrix();
		if(numA >= 0 && numA < 20)
		{
			modelStack.Translate(200, 15, 47 + (-5*numA));	
		}
		if(numA >= 20 && numA < 40)
		{
			modelStack.Translate(200, 15, 260 + (-5*numA));
		}
		modelStack.Scale(5, 5, 5);
		RenderMesh(meshList[GEO_ICECREAM], false);
		modelStack.PopMatrix();
	}

}
void SceneAssignment::RenderOut_Skybox()
{
	
	modelStack.PushMatrix();
	modelStack.Translate(0, 250, -1550);
	modelStack.Translate(playerCamera.position.x, 0, playerCamera.position.z);
	modelStack.Scale(3100, 3100, 3100);
	RenderMesh(skyboxList[SKYBOX_FRONT], false);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(0,250, 1550);
	modelStack.Translate(playerCamera.position.x, 0, playerCamera.position.z);
	modelStack.Rotate(180, -1, 0, 0);
	modelStack.Rotate(180, 0, 0, 1);
	modelStack.Scale(3100, 3100, 3100);
	RenderMesh(skyboxList[SKYBOX_BACK], false);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(-1550, 250, 0);
	modelStack.Translate(playerCamera.position.x, 0, playerCamera.position.z);
	modelStack.Rotate(90, 0, 1, 0);
	modelStack.Scale(3100, 3100, 3100);
	RenderMesh(skyboxList[SKYBOX_RIGHT], false);
	modelStack.PopMatrix();


	modelStack.PushMatrix();
	modelStack.Translate(1550,250, 0);
	modelStack.Translate(playerCamera.position.x, 0, playerCamera.position.z);
	modelStack.Rotate(-90, 0, 1, 0);
	modelStack.Scale(3100, 3100, 3100);
	RenderMesh(skyboxList[SKYBOX_LEFT], false);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(0, 1800, 0);
	modelStack.Translate(playerCamera.position.x, 0, playerCamera.position.z);
	modelStack.Rotate(90, 0, 1, 0);
	modelStack.Rotate(90, 1, 0, 0);
	modelStack.Scale(3100, 3100, 3100);
	RenderMesh(skyboxList[SKYBOX_UP], false);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(0, 0, 0);
	modelStack.Rotate(-90, 1, 0, 0);
	modelStack.Rotate(90, 0, 0, 1);
	modelStack.Scale(4100, 4100, 4100);
	RenderMesh(skyboxList[SKYBOX_DOWN], false);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(0, 210, 329);
	modelStack.Scale(1015, 205, 1000);
	RenderMesh(skyboxList[SKYBOX_EXTEBANNER], false);
	modelStack.PopMatrix();
	//left side
	modelStack.PushMatrix();
	modelStack.Translate(-507, 122, 0);
	modelStack.Rotate(90, 0, 1,0 );
	modelStack.Scale(658, 380, 1000);
	RenderMesh(skyboxList[SKYBOX_EXTESIDE], false);
	modelStack.PopMatrix();
	//ride side
	modelStack.PushMatrix();
	modelStack.Translate(507, 122, 0);
	modelStack.Rotate(90, 0, 1,0 );
	modelStack.Scale(658, 380, 1000);
	RenderMesh(skyboxList[SKYBOX_EXTESIDE], false);
	modelStack.PopMatrix();
	//back
	modelStack.PushMatrix();
	modelStack.Translate(0, 122, -329);
	modelStack.Scale(1015, 380, 1000);
	RenderMesh(skyboxList[SKYBOX_EXTESIDE], false);
	modelStack.PopMatrix();
	//small right
	modelStack.PushMatrix();
	modelStack.Translate(452.8, 0, 327);
	modelStack.Scale(108, 260, 1000);
	RenderMesh(skyboxList[SKYBOX_EXTESIDE], false);
	modelStack.PopMatrix();
	//small left
	modelStack.PushMatrix();
	modelStack.Translate(-452.8, 0, 327);
	modelStack.Scale(108, 260, 1000);
	RenderMesh(skyboxList[SKYBOX_EXTESIDE], false);
	modelStack.PopMatrix();
	
	//basket for fruits and vegetables
	for (int i = 0; i < House.getTotal(); ++i)
	{
		modelStack.PushMatrix();
		modelStack.Translate(House.translateVal[i].x,House.translateVal[i].y,House.translateVal[i].z);
		modelStack.Rotate(House.rotateVal[i],House.rotateAxis[i].x,House.rotateAxis[i].y,House.rotateAxis[i].z);
		modelStack.Scale(House.scaleVal[i].x, House.scaleVal[i].y, House.scaleVal[i].z);
		RenderMesh(meshList[GEO_BUILDING], false);
		modelStack.PopMatrix();
	}
	/*
	//house left
	modelStack.PushMatrix();
	modelStack.Translate(-700, 0, 227);
	modelStack.Rotate(90,0,1,0);
	modelStack.Scale(20,20,20);
	RenderMesh(meshList[GEO_BUILDING], false);
	modelStack.PopMatrix();

	//house left
	modelStack.PushMatrix();
	modelStack.Translate(-900, 0, 227);
	modelStack.Rotate(90,0,1,0);
	modelStack.Scale(20,20,20);
	RenderMesh(meshList[GEO_BUILDING], false);
	modelStack.PopMatrix();

	//house right
	modelStack.PushMatrix();
	modelStack.Translate(600, 0, 227);
	modelStack.Rotate(90,0,1,0);
	modelStack.Scale(20,20,20);
	RenderMesh(meshList[GEO_BUILDING], false);
	modelStack.PopMatrix();

	//house right
	modelStack.PushMatrix();
	modelStack.Translate(800, 0, 227);
	modelStack.Rotate(90,0,1,0);
	modelStack.Scale(20,20,20);
	RenderMesh(meshList[GEO_BUILDING], false);
	modelStack.PopMatrix();
	*/
}
void SceneAssignment::RenderChar()
{
	//cashier
	for(int num = 0; num < 4; num++)
	{
		modelStack.PushMatrix();
		modelStack.Translate(70*num-312,0,240);
		modelStack.Rotate(-90, 0, 1, 0);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_CASHIER], false);
		modelStack.PopMatrix();
	}
}
void SceneAssignment::RenderModelPink()
{
	modelStack.PushMatrix(); 

	if (pinkCheck[41] == false) for(int i=0;i<pinkSize;++i) {pinkCheck[i] = true; pinkMove[i] = 0;}
	if (pinkCheck[40]==false) pinkCheck[41]= AIrotate(modelStack,Vector3(90,0,500),pinkMove[41],'y',90);
	if (pinkCheck[39]==false) pinkCheck[40]= AImoveX(modelStack,pinkMove[40],200);
	if (pinkCheck[38]==false) pinkCheck[39]= AIrotate(modelStack,Vector3(-110,0,500),pinkMove[39],'y',90);
	if (pinkCheck[37]==false) pinkCheck[38]= AImoveZ(modelStack,pinkMove[38],215);
	if (pinkCheck[36]==false) pinkCheck[37]= AIrotate(modelStack,Vector3(-110,0,285),pinkMove[37],'y',90);
	if (pinkCheck[35]==false) pinkCheck[36]= AImoveX(modelStack,pinkMove[36],-110);
	if (pinkCheck[34]==false) pinkCheck[35]= AIrotate(modelStack,Vector3(0,0,285),pinkMove[35],'y',-90);
	if (pinkCheck[33]==false) pinkCheck[34]= AImoveZ(modelStack,pinkMove[34],385);
	if (pinkCheck[32]==false) pinkCheck[33]= AIrotate(modelStack,Vector3(0,0,-100),pinkMove[33],'y',-90);
	if (pinkCheck[31]==false) pinkCheck[32]= AImoveX(modelStack,pinkMove[32],250);
	if (pinkCheck[30]==false) pinkCheck[31]= AIrotate(modelStack,Vector3(-250,0,-100),pinkMove[31],'y',-90);
	if (pinkCheck[29]==false) pinkCheck[30]= AImoveZ(modelStack,pinkMove[30],-75);
	if (pinkCheck[28]==false) pinkCheck[29]= AIrotate(modelStack,Vector3(-250,0,-25),pinkMove[29],'y',90);
	if (pinkCheck[27]==false) pinkCheck[28]= AImoveX(modelStack,pinkMove[28],100);
	if (pinkCheck[26]==false) pinkCheck[27]= AIrotate(modelStack,Vector3(-350,0,-25),pinkMove[27],'y',180);
	if (pinkCheck[25]==false) pinkCheck[26]= AIstop(pinkMove[26],80);
	if (pinkCheck[24]==false) pinkCheck[25]= AIrotate(modelStack,Vector3(-350,0,-25),pinkMove[25],'y',-90);
	if (pinkCheck[23]==false) pinkCheck[24]= AImoveZ(modelStack,pinkMove[24],100);
	if (pinkCheck[22]==false) pinkCheck[23]= AIrotate(modelStack,Vector3(-350,0,-125),pinkMove[23],'y',90);
	if (pinkCheck[21]==false) pinkCheck[22]= AIstop(pinkMove[22],80);
	if (pinkCheck[20]==false) pinkCheck[21]= AIrotate(modelStack,Vector3(-350,0,-125),pinkMove[21],'y',-90);
	if (pinkCheck[19]==false) pinkCheck[20]= AImoveZ(modelStack,pinkMove[20],100);
	if (pinkCheck[18]==false) pinkCheck[19]= AIrotate(modelStack,Vector3(-350,0,-225),pinkMove[19],'y',90);
	if (pinkCheck[17]==false) pinkCheck[18]= AIstop(pinkMove[18],80);
	if (pinkCheck[16]==false) pinkCheck[17]= AIrotate(modelStack,Vector3(-350,0,-225),pinkMove[17],'y',-90);
	if (pinkCheck[15]==false) pinkCheck[16]= AImoveZ(modelStack,pinkMove[16],50);
	if (pinkCheck[14]==false) pinkCheck[15]= AIrotate(modelStack,Vector3(-350,0,-275),pinkMove[15],'y',90);
	if (pinkCheck[13]==false) pinkCheck[14]= AImoveX(modelStack,pinkMove[14],-140);
	if (pinkCheck[12]==false) pinkCheck[13]= AIrotate(modelStack,Vector3(-210,0,-275),pinkMove[13],'y',90);
	if (pinkCheck[11]==false) pinkCheck[12]= AIstop(pinkMove[12],80);
	if (pinkCheck[10]==false) pinkCheck[11]= AIrotate(modelStack,Vector3(-210,0,-275),pinkMove[11],'y',-90);
	if (pinkCheck[9]==false) pinkCheck[10]= AImoveX(modelStack,pinkMove[10],-90);
	if (pinkCheck[8]==false) pinkCheck[9]= AIrotate(modelStack,Vector3(-120,0,-275),pinkMove[9],'y',90);
	if (pinkCheck[7]==false) pinkCheck[8]= AIstop(pinkMove[8],80);
	if (pinkCheck[6]==false) pinkCheck[7]= AIrotate(modelStack,Vector3(-120,0,-275),pinkMove[7],'y',-90);
	if (pinkCheck[5]==false) pinkCheck[6]= AImoveX(modelStack,pinkMove[6],-90);
	if (pinkCheck[4]==false) pinkCheck[5]= AIrotate(modelStack,Vector3(-30,0,-275),pinkMove[5],'y',90);
	if (pinkCheck[3]==false) pinkCheck[4]= AIstop(pinkMove[4],80);
	if (pinkCheck[2]==false) pinkCheck[3]= AIrotate(modelStack,Vector3(-30,0,-275),pinkMove[3],'y',-90);
	if (pinkCheck[1]==false) pinkCheck[2]= AImoveX(modelStack,pinkMove[2],-120);
	if (pinkCheck[0]==false) pinkCheck[1]= AIrotate(modelStack,Vector3(90,0,-275),pinkMove[1],'y',90); 
	    pinkCheck[0] = AImoveZ(modelStack,pinkMove[0],-775);

	modelStack.Translate(modelPink.translateVal[0].x,modelPink.translateVal[0].y,modelPink.translateVal[0].z);
	modelStack.Rotate(modelPink.rotateVal[0],modelPink.rotateAxis[0].x,modelPink.rotateAxis[0].y,modelPink.rotateAxis[0].z);
	modelStack.Scale(modelPink.scaleVal[0].x,modelPink.scaleVal[0].y,modelPink.scaleVal[0].z);
	RenderMesh(modelList7[MODEL_BODY_PINK], false);

	//left arm
	modelStack.PushMatrix();
	RenderMesh(modelList7[MODEL_LEFTARM_PINK], false);

	//left fist
	modelStack.PushMatrix();
	modelStack.Rotate(rotateAngle, 1, 0, 0);
	RenderMesh(modelList7[MODEL_LEFTFIST_PINK], false);
	modelStack.PopMatrix();
	modelStack.PopMatrix();

	//right arm
	modelStack.PushMatrix();
	//modelStack.Rotate(30, 1, 0, 0);
	RenderMesh(modelList7[MODEL_RIGHTARM_PINK], false);

	//right fist
	modelStack.PushMatrix();
	modelStack.Rotate(-rotateAngle, 1, 0, 0);
	RenderMesh(modelList7[MODEL_RIGHTFIST_PINK], false);
	modelStack.PopMatrix();
	modelStack.PopMatrix();

	//left leg upper
	modelStack.PushMatrix();
	RenderMesh(modelList7[MODEL_LEFT_LEG_UPPER_PINK], false);

	//left leg lower
	modelStack.PushMatrix();
	modelStack.Translate(0, 1.5, 0);
	modelStack.Rotate(-rotateAngle + 180, 1, 0, 0);
	RenderMesh(modelList7[MODEL_LEFT_LEG_LOWER_PINK], false);
	modelStack.PopMatrix();
	modelStack.PopMatrix();

	//right leg upper
	modelStack.PushMatrix();
	RenderMesh(modelList7[MODEL_RIGHT_LEG_UPPER_PINK], false);

	//right leg lower
	modelStack.PushMatrix();
	modelStack.Translate(0, 1.5, 0);
	modelStack.Rotate(rotateAngle + 180, 1, 0, 0);
	RenderMesh(modelList7[MODEL_RIGHT_LEG_LOWER_PINK], false);
	modelStack.PopMatrix();
	modelStack.PopMatrix();
	modelStack.PopMatrix();
}
void SceneAssignment::RenderModelBlue()
{
	modelStack.PushMatrix();

	if (blueCheck[22] == false) for(int i=0;i<blueSize;++i) {blueCheck[i] = true; blueMove[i] = 0;}
	if (blueCheck[21]==false) blueCheck[22]= AIrotate(modelStack,Vector3(160,0,550),blueMove[22],'y',90); 
	if (blueCheck[20]==false) blueCheck[21]= AImoveX(modelStack,blueMove[21],290);
	if (blueCheck[19]==false) blueCheck[20]= AIrotate(modelStack,Vector3(-130,0,550),blueMove[20],'y',90); 
	if (blueCheck[18]==false) blueCheck[19]= AImoveZ(modelStack,blueMove[19],320);
	if (blueCheck[17]==false) blueCheck[18]= AIrotate(modelStack,Vector3(-130,0,230),blueMove[18],'y',90); 
	if (blueCheck[16]==false) blueCheck[17]= AIstop(blueMove[17],80);
	if (blueCheck[15]==false) blueCheck[16]= AIrotate(modelStack,Vector3(-130,0,230),blueMove[16],'y',-90); 
	if (blueCheck[14]==false) blueCheck[15]= AImoveZ(modelStack,blueMove[15],415);
	if (blueCheck[13]==false) blueCheck[14]= AIrotate(modelStack,Vector3(-130,0,-185),blueMove[14],'y',180); 
	if (blueCheck[12]==false) blueCheck[13]= AIstop(blueMove[13],80);
	if (blueCheck[11]==false) blueCheck[12]= AIrotate(modelStack,Vector3(-130,0,-185),blueMove[12],'y',-90); 
	if (blueCheck[10]==false) blueCheck[11]= AImoveX(modelStack,blueMove[11],-290);
	if (blueCheck[9]==false) blueCheck[10]= AIrotate(modelStack,Vector3(160,0,-185),blueMove[10],'y',90); 
	if (blueCheck[8]==false) blueCheck[9]= AIstop(blueMove[9],80);
	if (blueCheck[7]==false) blueCheck[8]= AImoveZ(modelStack,blueMove[8],-190);
	if (blueCheck[6]==false) blueCheck[7]= AIrotate(modelStack,Vector3(160,0,5),blueMove[7],'y',90); 
	if (blueCheck[5]==false) blueCheck[6]= AIstop(blueMove[6],80);
	if (blueCheck[4]==false) blueCheck[5]= AIrotate(modelStack,Vector3(160,0,5),blueMove[5],'y',-90); 
	if (blueCheck[3]==false) blueCheck[4]= AImoveZ(modelStack,blueMove[4],-105);
	if (blueCheck[2]==false) blueCheck[3]= AIrotate(modelStack,Vector3(160,0,110),blueMove[3],'y',90); 
	if (blueCheck[1]==false) blueCheck[2]= AIstop(blueMove[2],80);
	if (blueCheck[0]==false) blueCheck[1]= AIrotate(modelStack,Vector3(160,0,110),blueMove[1],'y',-90); 
	blueCheck[0] = AImoveZ(modelStack,blueMove[0],-440);

	modelStack.Translate(modelBlue.translateVal[0].x,modelBlue.translateVal[0].y,modelBlue.translateVal[0].z);
	modelStack.Rotate(modelBlue.rotateVal[0],modelBlue.rotateAxis[0].x,modelBlue.rotateAxis[0].y,modelBlue.rotateAxis[0].z);
	modelStack.Scale(modelBlue.scaleVal[0].x,modelBlue.scaleVal[0].y,modelBlue.scaleVal[0].z);
	RenderMesh(modelList2[MODEL_BODY_BLUE], false);

	//left arm
	modelStack.PushMatrix();
	RenderMesh(modelList2[MODEL_LEFTARM_BLUE], false);

	//left fist
	modelStack.PushMatrix();
	modelStack.Rotate(rotateAngle, 1, 0, 0);
	RenderMesh(modelList2[MODEL_LEFTFIST_BLUE], false);
	modelStack.PopMatrix();
	modelStack.PopMatrix();

	//right arm
	modelStack.PushMatrix();
	//modelStack.Rotate(30, 1, 0, 0);
	RenderMesh(modelList2[MODEL_RIGHTARM_BLUE], false);

	//right fist
	modelStack.PushMatrix();
	modelStack.Rotate(-rotateAngle, 1, 0, 0);
	RenderMesh(modelList2[MODEL_RIGHTFIST_BLUE], false);
	modelStack.PopMatrix();
	modelStack.PopMatrix();

	//left leg upper
	modelStack.PushMatrix();
	RenderMesh(modelList2[MODEL_LEFT_LEG_UPPER_BLUE], false);

	//left leg lower
	modelStack.PushMatrix();
	modelStack.Translate(0, 1.5, 0);
	modelStack.Rotate(-rotateAngle + 180, 1, 0, 0);
	RenderMesh(modelList2[MODEL_LEFT_LEG_LOWER_BLUE], false);
	modelStack.PopMatrix();
	modelStack.PopMatrix();

	//right leg upper
	modelStack.PushMatrix();
	RenderMesh(modelList2[MODEL_RIGHT_LEG_UPPER_BLUE], false);

	//right leg lower
	modelStack.PushMatrix();
	modelStack.Translate(0, 1.5, 0);
	modelStack.Rotate(rotateAngle + 180, 1, 0, 0);
	RenderMesh(modelList2[MODEL_RIGHT_LEG_LOWER_BLUE], false);
	modelStack.PopMatrix();
	modelStack.PopMatrix();
	modelStack.PopMatrix();
}
void SceneAssignment::RenderModelOrange()
{
	modelStack.PushMatrix();
	if (orangeCheck[25] == false) for(int i=0;i<orangeSize;++i) {orangeCheck[i] = true; orangeMove[i] = 0;}
	if (orangeCheck[24]==false) orangeCheck[25]= AIrotate(modelStack,Vector3(90,0,600),orangeMove[25],'y',90);
	if (orangeCheck[23]==false) orangeCheck[24]= AImoveX(modelStack,orangeMove[24],134);
	if (orangeCheck[22]==false) orangeCheck[23]= AIrotate(modelStack,Vector3(-44,0,600),orangeMove[23],'y',90);
	if (orangeCheck[20]==false) orangeCheck[22]= AImoveZ(modelStack,orangeMove[22],480);
	if (orangeCheck[19]==false) {
		orangeCheck[20]= AImoveY (modelStack,orangeMove[20],-150);
					     AImoveZ (modelStack,orangeMove[21],345);
	}
	if (orangeCheck[18]==false) orangeCheck[19]= AImoveZ(modelStack,orangeMove[19],75);
	if (orangeCheck[17]==false) orangeCheck[18]= AIrotate(modelStack,Vector3(-44,0,-300),orangeMove[18],'y',-90);
	if (orangeCheck[16]==false) orangeCheck[17]= AImoveX(modelStack,orangeMove[17],111);
	if (orangeCheck[15]==false) orangeCheck[16]= AIrotate(modelStack,Vector3(-155,0,-300),orangeMove[16],'y',-90);
	if (orangeCheck[14]==false) orangeCheck[15]= AImoveZ(modelStack,orangeMove[15],-230);
	if (orangeCheck[13]==false) orangeCheck[14]= AIrotate(modelStack,Vector3(-155,0,-70),orangeMove[14],'y',-90);
	if (orangeCheck[12]==false) orangeCheck[13]= AImoveX(modelStack,orangeMove[13],-505);
	if (orangeCheck[11]==false) orangeCheck[12]= AIrotate(modelStack,Vector3(350,0,-70),orangeMove[12],'y',-90);
	if (orangeCheck[10]==false) orangeCheck[11]= AImoveZ(modelStack,orangeMove[11],230);
	if (orangeCheck[9]==false) orangeCheck[10]= AIrotate(modelStack,Vector3(350,0,-300),orangeMove[10],'y',-90);
	if (orangeCheck[8]==false) orangeCheck[9]= AImoveX(modelStack,orangeMove[9],315);
	if (orangeCheck[7]==false) orangeCheck[8]= AIrotate(modelStack,Vector3(35,0,-300),orangeMove[8],'y',-90); 
	if (orangeCheck[5]==false) orangeCheck[7]= AImoveZ(modelStack,orangeMove[7],-85);
	if (orangeCheck[4]==false) {
		orangeCheck[5]= AImoveY (modelStack,orangeMove[5],150);
					    AImoveZ (modelStack,orangeMove[6],-345);
	}
	if (orangeCheck[3]==false) orangeCheck[4]= AImoveZ(modelStack,orangeMove[4],-90);
	if (orangeCheck[2]==false) orangeCheck[3]= AIrotate(modelStack,Vector3(35,0,220),orangeMove[3],'y',-90); 
	if (orangeCheck[1]==false) orangeCheck[2]= AImoveX(modelStack,orangeMove[2],-55);
	if (orangeCheck[0]==false) orangeCheck[1]= AIrotate(modelStack,Vector3(90,0,220),orangeMove[1],'y',90); 
	orangeCheck[0] = AImoveZ(modelStack,orangeMove[0],-380);

	modelStack.Translate(modelOrange.translateVal[0].x,modelOrange.translateVal[0].y,modelOrange.translateVal[0].z);
	modelStack.Rotate(modelOrange.rotateVal[0],modelOrange.rotateAxis[0].x,modelOrange.rotateAxis[0].y,modelOrange.rotateAxis[0].z);
	modelStack.Scale(modelOrange.scaleVal[0].x,modelOrange.scaleVal[0].y,modelOrange.scaleVal[0].z);
	RenderMesh(modelList6[MODEL_BODY_ORANGE], false);

	//left arm
	modelStack.PushMatrix();
	RenderMesh(modelList6[MODEL_LEFTARM_ORANGE], false);

	//left fist
	modelStack.PushMatrix();
	modelStack.Rotate(rotateAngle, 1, 0, 0);
	RenderMesh(modelList6[MODEL_LEFTFIST_ORANGE], false);
	modelStack.PopMatrix();
	modelStack.PopMatrix();

	//right arm
	modelStack.PushMatrix();
	//modelStack.Rotate(30, 1, 0, 0);
	RenderMesh(modelList6[MODEL_RIGHTARM_ORANGE], false);

	//right fist
	modelStack.PushMatrix();
	modelStack.Rotate(-rotateAngle, 1, 0, 0);
	RenderMesh(modelList6[MODEL_RIGHTFIST_ORANGE], false);
	modelStack.PopMatrix();
	modelStack.PopMatrix();

	//left leg upper
	modelStack.PushMatrix();
	RenderMesh(modelList6[MODEL_LEFT_LEG_UPPER_ORANGE], false);

	//left leg lower
	modelStack.PushMatrix();
	modelStack.Translate(0, 1.5, 0);
	modelStack.Rotate(-rotateAngle + 180, 1, 0, 0);
	RenderMesh(modelList6[MODEL_LEFT_LEG_LOWER_ORANGE], false);
	modelStack.PopMatrix();
	modelStack.PopMatrix();

	//right leg upper
	modelStack.PushMatrix();
	RenderMesh(modelList6[MODEL_RIGHT_LEG_UPPER_ORANGE], false);

	//right leg lower
	modelStack.PushMatrix();
	modelStack.Translate(0, 1.5, 0);
	modelStack.Rotate(rotateAngle + 180, 1, 0, 0);
	RenderMesh(modelList6[MODEL_RIGHT_LEG_LOWER_ORANGE], false);
	modelStack.PopMatrix();
	modelStack.PopMatrix();
	modelStack.PopMatrix();
}
void SceneAssignment::RenderModels()
{
	RenderModelPink();
	RenderModelBlue();
	RenderModelOrange();
}
void SceneAssignment::ReadFromText()
{
	string line;
	ifstream myfile("Text//sample.txt");

	if(myfile.is_open())
	{
		while(getline(myfile, line, ' '))
		{
			std::ostringstream lines;
			lines << '\n' << line;
			modelStack.PushMatrix();
			
			for(int i = 0; i < 2; i++)
			{
				line.clear();
				//RenderTextOnScreen(meshList[GEO_TEXT], lines.str(), Color(0.7, 0, 1), 3, 0, 15);
			}
			modelStack.PopMatrix();	
		}
	}
	myfile.close();
}
void SceneAssignment::RenderText(Mesh* mesh, std::string text, Color color)
{
	if(!mesh || mesh->textureID <= 0) //Proper error check
		return;

	glDisable(GL_DEPTH_TEST);
	glUniform1i(m_parameters[U_TEXT_ENABLED], 1);
	glUniform3fv(m_parameters[U_TEXT_COLOR], 1, &color.r);
	glUniform1i(m_parameters[U_LIGHTENABLED], 0);
	glUniform1i(m_parameters[U_COLOR_TEXTURE_ENABLED], 1);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, mesh->textureID);
	glUniform1i(m_parameters[U_COLOR_TEXTURE], 0);
	for(unsigned i = 0; i < text.length(); ++i)
	{
		Mtx44 characterSpacing;
		characterSpacing.SetToTranslation(i * 0.5f, 0, 0); //1.0f is the spacing of each character, you may change this value
		Mtx44 MVP = projectionStack.Top() * viewStack.Top() * modelStack.Top() * characterSpacing;
		glUniformMatrix4fv(m_parameters[U_MVP], 1, GL_FALSE, &MVP.a[0]);

		mesh->Render((unsigned)text[i] * 6, 6);
	}
	glBindTexture(GL_TEXTURE_2D, 0);
	glUniform1i(m_parameters[U_TEXT_ENABLED], 0);
	glEnable(GL_DEPTH_TEST);
}
void SceneAssignment::RenderTextOnScreen(Mesh* mesh, std::string text, Color color, float size, float x, float y)
{
	if(!mesh || mesh->textureID <= 0) //Proper error check
		return;

	glDisable(GL_DEPTH_TEST);
	Mtx44 ortho;
	ortho.SetToOrtho(0, 80, 0, 60, -10, 10); //size of screen UI
	projectionStack.PushMatrix();
	projectionStack.LoadMatrix(ortho);
	viewStack.PushMatrix();
	viewStack.LoadIdentity(); //No need camera for ortho mode
	modelStack.PushMatrix();
	modelStack.LoadIdentity(); //Reset modelStack
	modelStack.Scale(size, size, size);
	modelStack.Translate(x, y, 0);

	glUniform1i(m_parameters[U_TEXT_ENABLED], 1);
	glUniform3fv(m_parameters[U_TEXT_COLOR], 1, &color.r);
	glUniform1i(m_parameters[U_LIGHTENABLED], 0);
	glUniform1i(m_parameters[U_COLOR_TEXTURE_ENABLED], 1);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, mesh->textureID);
	glUniform1i(m_parameters[U_COLOR_TEXTURE], 0);
	for(unsigned i = 0; i < text.length(); ++i)
	{
		Mtx44 characterSpacing;
		characterSpacing.SetToTranslation(i * 0.5f, 0, 0); //1.0f is the spacing of each character, you may change this value
		Mtx44 MVP = projectionStack.Top() * viewStack.Top() * modelStack.Top() * characterSpacing;
		glUniformMatrix4fv(m_parameters[U_MVP], 1, GL_FALSE, &MVP.a[0]);

		mesh->Render((unsigned)text[i] * 6, 6);
	}
	glBindTexture(GL_TEXTURE_2D, 0);
	glUniform1i(m_parameters[U_TEXT_ENABLED], 0);
	projectionStack.PopMatrix();
	viewStack.PopMatrix();
	modelStack.PopMatrix();
	glEnable(GL_DEPTH_TEST);
}
void SceneAssignment::RenderQuadOnScreen(Mesh* mesh, float x_size, float y_size, float x, float y)
{
	if(!mesh || mesh->textureID <= 0) //Proper error check
		return;

	glDisable(GL_DEPTH_TEST);
	Mtx44 ortho;
	ortho.SetToOrtho(0, 80, 0, 60, -10, 10); //size of screen UI
	projectionStack.PushMatrix();
	projectionStack.LoadMatrix(ortho);
	viewStack.PushMatrix();
	viewStack.LoadIdentity(); //No need camera for ortho mode
	modelStack.PushMatrix();
	modelStack.LoadIdentity(); //Reset modelStack
	modelStack.Scale(x_size, y_size, 1);
	modelStack.Translate(x, y, 0);

	glUniform1i(m_parameters[U_UI_ENABLED], 1);
	glUniform1i(m_parameters[U_LIGHTENABLED], 0);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, mesh->textureID);
	glUniform1i(m_parameters[U_COLOR_TEXTURE], 0);

	
	Mtx44 MVP = projectionStack.Top() * viewStack.Top() * modelStack.Top();
	glUniformMatrix4fv(m_parameters[U_MVP], 1, GL_FALSE, &MVP.a[0]);
	mesh->Render();
	
	glBindTexture(GL_TEXTURE_2D, 0);
	glUniform1i(m_parameters[U_UI_ENABLED], 0);


	projectionStack.PopMatrix();
	viewStack.PopMatrix();
	modelStack.PopMatrix();
	glEnable(GL_DEPTH_TEST);
}
void SceneAssignment::Render()
{
	// Render VBO here
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	viewStack.LoadIdentity();

	//Set view matrix using camera settings
	switch (camType)
	{
	case PLAYER_CAM:
		viewStack.LookAt(
			playerCamera.position.x, playerCamera.position.y, playerCamera.position.z,
			playerCamera.target.x, playerCamera.target.y, playerCamera.target.z,
			playerCamera.up.x, playerCamera.up.y, playerCamera.up.z
			);
		break;
	case NOCLIP_CAM:
		viewStack.LookAt(
			noClipCamera.position.x, noClipCamera.position.y, noClipCamera.position.z,
			noClipCamera.target.x, noClipCamera.target.y, noClipCamera.target.z,
			noClipCamera.up.x, noClipCamera.up.y, noClipCamera.up.z
			);
		break;
	}


	modelStack.LoadIdentity();

	Position lightPosition_cameraspace = viewStack.Top() * light[0].position;
	glUniform3fv(m_parameters[U_LIGHT0_POSITION], 1, &lightPosition_cameraspace.x);

	//Elevator
	modelStack.PushMatrix();
	modelStack.Translate(455,eley,1);
	modelStack.Rotate(270,0,1,0);
	modelStack.Scale(12.5,12,13);
	RenderMesh(meshList[GEO_TENT], false);
	modelStack.PopMatrix();
	//Lift door==================================================================
	modelStack.PushMatrix();
	modelStack.Translate(401,55,LiftDoor);
	modelStack.Rotate(270,0,1,0);
	modelStack.Scale(115,110,0);
	RenderMesh(meshList[GEO_DOOR], false);
	modelStack.PopMatrix();
	//LiftDoor2
	modelStack.PushMatrix();
	modelStack.Translate(401,205,LiftDoor2);
	modelStack.Rotate(270,0,1,0);
	modelStack.Scale(115,110,0);
	RenderMesh(meshList[GEO_DOOR], false);
	modelStack.PopMatrix();
	//=========================================Firealarm======================================================================
	for(int i = 0;i<firealarm.getTotal();++i)
	{
		modelStack.PushMatrix();
		modelStack.Translate(firealarm.translateVal[i].x,firealarm.translateVal[i].y,firealarm.translateVal[i].z);
		modelStack.Rotate(firealarm.rotateVal[i],firealarm.rotateAxis[i].x,firealarm.rotateAxis[i].y,firealarm.rotateAxis[i].z);
		modelStack.Scale(firealarm.scaleVal[i].x,firealarm.scaleVal[i].y,firealarm.scaleVal[i].z);
		RenderMesh(meshList[GEO_ALARM], false);
		modelStack.PopMatrix();
	}
	//========================================================================================================================
	//light
	modelStack.PushMatrix();
	modelStack.Translate(light[0].position.x, light[0].position.y, light[0].position.z);
	modelStack.Scale(3,3,3);
	RenderMesh(meshList[GEO_LIGHTBALL], false);
	modelStack.PopMatrix();
	RenderLargeObjects();
	RenderModels();
	RenderOut_Skybox();

	

	RenderRightColumn();
	RenderLeftColumn();
	RenderMiddleColumn();
	RenderSmallObjects();
	RenderLevel1();
	RenderLevel2();
	
	RenderChar();
	// FOR VISUAL DEBUGGING, IGNORE THE DOORMAN
	if (debug == true)
	{
		for (int i = 0; i < ObjectList.size(); ++i)
		{
			for (int j = 0; j < ObjectList[i].collisionPos.size(); ++j)
			{
				modelStack.PushMatrix();
				modelStack.Translate(ObjectList[i].collisionPos[j].x,ObjectList[i].collisionPos[j].y,ObjectList[i].collisionPos[j].z);
				modelStack.Scale(2, 2, 2);
				RenderMesh(meshList[GEO_DOORMAN], false);
				modelStack.PopMatrix();
			}
		}
	}

/*-------------------------------------------------!! UPDATE NEEDED (WEI HENG) !!----------------------------------------------------*/
	if (render1 == true)
	{
		modelStack.PushMatrix();
		modelStack.Translate(PickUp1.translateVal[0].x,PickUp1.translateVal[0].y,PickUp1.translateVal[0].z);
		modelStack.Rotate(PickUp1.rotateVal[0],PickUp1.rotateAxis[0].x,PickUp1.rotateAxis[0].y,PickUp1.rotateAxis[0].z);
		modelStack.Scale(PickUp1.scaleVal[0].x,PickUp1.scaleVal[0].y,PickUp1.scaleVal[0].z);
		RenderMesh(meshList[GEO_PACKET], false);
		modelStack.PopMatrix();
	}

	if (render2 == true)
	{
	modelStack.PushMatrix();
	modelStack.Translate(PickUp2.translateVal[0].x,PickUp2.translateVal[0].y,PickUp2.translateVal[0].z);
	modelStack.Scale(PickUp2.scaleVal[0].x,PickUp2.scaleVal[0].y,PickUp2.scaleVal[0].z);
	RenderMesh(meshList[GEO_COCONUT], false);
	modelStack.PopMatrix();
	}

	if (render3 == true)
	{
		modelStack.PushMatrix();
		modelStack.Translate(PickUp3.translateVal[0].x,PickUp3.translateVal[0].y,PickUp3.translateVal[0].z);
		modelStack.Rotate(PickUp3.rotateVal[0],PickUp3.rotateAxis[0].x,PickUp3.rotateAxis[0].y,PickUp3.rotateAxis[0].z);
		modelStack.Scale(PickUp3.scaleVal[0].x,PickUp3.scaleVal[0].y,PickUp3.scaleVal[0].z);
		RenderMesh(meshList[GEO_ICECREAM], false);
		modelStack.PopMatrix();
	}

	if (renderscenerio3 == true)
	{
		modelStack.PushMatrix();
		modelStack.Translate(scenerio3.translateVal[0].x,scenerio3.translateVal[0].y,scenerio3.translateVal[0].z);
		modelStack.Rotate(scenerio3.rotateVal[0],scenerio3.rotateAxis[0].x,scenerio3.rotateAxis[0].y,scenerio3.rotateAxis[0].z);
		modelStack.Scale(scenerio3.scaleVal[0].x,scenerio3.scaleVal[0].y,scenerio3.scaleVal[0].z);
		RenderMesh(meshList[GEO_CASHIER], false);
		modelStack.PopMatrix();
	}

	std::ostringstream ss, ss2, ss3, ss4, ss5, ss6;
	ss << "FPS:" << FPS;
	ss2 << "ET:" << ET;
	ss3 << "X:" << playerCamera.position.x;
	ss4 << "Y:" << playerCamera.position.y;
	ss5 << "Z:" << playerCamera.position.z;

	modelStack.PushMatrix();
	
	
	//upper right UI for checklist
		modelStack.PushMatrix();
		RenderQuadOnScreen(meshList[GEO_UI], 35, 30, 1.85, 2.2);
		modelStack.PopMatrix();
		
		//upper left screen UI
		modelStack.PushMatrix();
		RenderQuadOnScreen(meshList[GEO_UI], 20, 30, 0.5, 2.2);
		modelStack.PopMatrix();

		//bottom UI
		modelStack.PushMatrix();
		RenderQuadOnScreen(meshList[GEO_UI], 80, 30, 0.5, 0.5);
		modelStack.PopMatrix();
	
	RenderTextOnScreen(meshList[GEO_TEXT], ss.str(), Color(0.7, 0, 1), 3, 0.5, 19.5);
	RenderTextOnScreen(meshList[GEO_TEXT], ss2.str(), Color(0.7, 0, 1), 3, 0.5, 18.5);
	RenderTextOnScreen(meshList[GEO_TEXT], ss3.str(), Color(0.7, 0, 1), 3, 0.5, 2.5);
	RenderTextOnScreen(meshList[GEO_TEXT], ss4.str(), Color(0.7, 0, 1), 3, 0.5, 1.5);
	RenderTextOnScreen(meshList[GEO_TEXT], ss5.str(), Color(0.7, 0, 1), 3, 0.5, 0.5);
	if (render1 == false && render2 == false && render3 == false)
		RenderTextOnScreen(meshList[GEO_TEXT], "Checklist:", Color(0, 1 ,0), 3, 17.8, 19.5);
	else
		RenderTextOnScreen(meshList[GEO_TEXT], "Checklist:", Color(1, 0 ,0), 3, 17.8, 19.5);

	if (render1 == true)
		RenderTextOnScreen(meshList[GEO_TEXT], "yaL's", Color(1, 0, 0), 2.5, 27.8, 22.4);
	if (render1 == false)
		RenderTextOnScreen(meshList[GEO_TEXT], "yaL's", Color(0, 1, 0), 2.5, 27.8, 22.4);
	if (render2 == true)
		RenderTextOnScreen(meshList[GEO_TEXT], "Coconut", Color(1, 0, 0), 2.5, 27.8, 23.4);
	if (render2 == false)
		RenderTextOnScreen(meshList[GEO_TEXT], "Coconut", Color(0, 1, 0), 2.5, 27.8, 23.4);
	if (render3 == true)
		RenderTextOnScreen(meshList[GEO_TEXT], "Ice cream", Color(1, 0, 0), 2.5, 27.8, 21.4);
	if (render3 == false)
		RenderTextOnScreen(meshList[GEO_TEXT], "Ice cream", Color(0, 1, 0), 2.5, 27.8, 21.4);
	modelStack.PopMatrix();

	if (Collision(playerCamera.position,ObjectList,4,28))
	{
		if (render1 == true)
		{
			//template for 'F' function triggers
			modelStack.PushMatrix();
			RenderQuadOnScreen(meshList[GEO_UI], 70, 30, 0.6, 1.05);
			modelStack.PopMatrix();
			RenderTextOnScreen(meshList[GEO_TEXT], "Press 'F' to pick up the item." , Color(0, 0.7, 1), 4, 3.6, 5.2);	
		}
	}

	if (Collision(playerCamera.position,ObjectList,2,29))
	{
		if (render2 == true)
		{
			//template for 'F' function triggers
			modelStack.PushMatrix();
			RenderQuadOnScreen(meshList[GEO_UI], 70, 30, 0.6, 1.05);
			modelStack.PopMatrix();
			RenderTextOnScreen(meshList[GEO_TEXT], "Press 'F' to pick up the item." , Color(0, 0.7, 1), 4, 3.6, 5.2);
		}
	}
	if (Collision(playerCamera.position,ObjectList,3,4))
	{
		if (render3 == true)
		{
			//template for 'F' function triggers
			modelStack.PushMatrix();
			RenderQuadOnScreen(meshList[GEO_UI], 70, 30, 0.6, 1.05);
			modelStack.PopMatrix();
			RenderTextOnScreen(meshList[GEO_TEXT], "Press 'F' to pick up the item." , Color(0, 0.7, 1), 4, 3.6, 5.2);
		}
	}

	/*-------------------------------------------------!! UPDATE NEEDED (WEI HENG) !!----------------------------------------------------*/
	
	ReadFromText();
}
void SceneAssignment::Exit()
{
	glDeleteVertexArrays(1, &m_vertexArrayID);
	glDeleteProgram(m_programID);
}