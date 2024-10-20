#pragma once

#include <vector>
#include "VectorsMath.h"
#include <string>

class Model
{
private:
	std::vector<Vector3<float>> vertices;
	std::vector<std::vector<int>> faces;

public:
	/// <summary>
	/// Constructor that parse OBJ content, and extract vertices and faces infromations
	/// </summary>
	/// <param name="filename"></param>
	Model(const std::string& filename);
	~Model()
	{

	}

	int VerticesAmount();
	int FacesAmount();
	Vector3<float> Vertex(int i);
	std::vector<int> Face(int i);


};
