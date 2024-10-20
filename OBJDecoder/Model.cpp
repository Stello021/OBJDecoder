#include "Model.h"
#include <fstream>
#include <string>
#include <sstream>
#include "VectorsMath.h"
#include <vector>

Model::Model(const std::string& filename) : vertices(), faces() //Init vertices and faces empty vectors
{
	//Opening file
	std::ifstream input;
	input.open(filename, std::ifstream::in);

	if (input.fail())
	{
		return;
	}

	std::string line;

	while (!input.eof())
	{
		std::getline(input, line); //reads file line by line and store each line 

		std::istringstream iss(line); //process contents of that line easily
		char trash; //used to discard unnecessary characters for parsing ("v", "f", "\")

		//Processing Vertices
		if (!line.compare(0, 2, "v ")) //Check if line starts with "v ", wich indentifies vertex data 
		{
			iss >> trash; //"v" char is discarded
			Vector3<float> v;

			for (int i = 0; i < 3; i++)
			{ //reads next 3 float and stores into a Vector3
				iss >> v.Raw[i];
			}

			vertices.push_back(v); //parsed vertex is added to vertices container
		}

		//processing Faces
		else if (!line.compare(0, 2, "f ")) //Check if line starts with "f ", wich indentifies face data
		{
			//A face in OBJ is represented by aseries of vertex indeces

			std::vector<int> f; //temporary, to store vertex indeces for the current face

			//The indeces refer to the positions of vertices in the model vector,
			//and they are decremented by 1 because OBJ files use 1-based indexing
			int indexTrash, index;
			iss >> trash;

			while (iss >> index >> trash >> indexTrash >> trash >> indexTrash)
			{
				index--;
				f.push_back(index);
			}
			faces.push_back(f);
		}
	}

	std::cerr << "vertices " << vertices.size() << ", faces " << faces.size() << std::endl;
}

int Model::VerticesAmount()
{
	return static_cast<int>(vertices.size());
}

int Model::FacesAmount()
{
	return static_cast<int>(faces.size());
}

Vector3<float> Model::Vertex(int i)
{
	return vertices[i];
}

std::vector<int> Model::Face(int i)
{
	return faces[i];
}
