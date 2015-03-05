#ifndef MESH_BUILDER_H
#define MESH_BUILDER_H

#include "Mesh.h"
#include "Vertex.h"

/******************************************************************************/
/*!
\file	MeshBuilder.h
\author Andy Chan
\par	
\brief
		Build meshes for rendering
*/
/******************************************************************************/
/******************************************************************************/
/*!
		Class MeshBuilder:
\brief	Provides methods to generate mesh of different shapes
*/
/******************************************************************************/
class MeshBuilder
{
public:
	static Mesh* GenerateAxes(const std::string &meshName, float lengthX, float lengthY, float lengthZ);
	static Mesh* GenerateQuad(const std::string &meshName, Color color ,float length);
	static Mesh* GenerateCube(const std::string &meshName, Color color, float length = 1.f);
	static Mesh* GenerateCircle(const std::string &meshname, Color color, unsigned numSlice, float radius);
	static Mesh* GenerateRing(const std::string &meshname, Color color, unsigned numSlice, float outerR, float innerR);
	static Mesh* GenerateSphere(const std::string &meshName, Color color,unsigned numStack, unsigned numSlice, float radius);
	static Mesh* GenerateHemisSphere(const std::string &meshName, Color color,unsigned numStackh, unsigned numSliceh, float radiush);
	static Mesh* GenerateCylinder(const std::string &meshname, Color color,unsigned numstack, unsigned numSlice, float radius, float height);
	static Mesh* MeshBuilder::GenerateOBJ(const std::string &meshName, const std::string &file_path);
	static Mesh* MeshBuilder::GenerateText(const std::string &meshName, unsigned numRow, unsigned numCol);
};

#endif