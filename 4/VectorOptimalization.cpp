#include <iostream>
#include <vector>

struct Vertex
{
	int x;
	int y;
	int z;

	Vertex(int x_, int y_, int z_)
		: x(x_), y(y_), z(z_) {}

	Vertex(const Vertex& rhs)
		: x(rhs.x), y(rhs.y), z(rhs.z)
	{
		std::cout << "Copied" << std::endl;
	}
};


int main(int argc, char const *argv[])
{
	std::vector<Vertex> vertexVector;
	vertexVector.reserve(3);

	std::cout << vertexVector.size() 
		<< " " << vertexVector.capacity() << std::endl;

	/*
	vertexVector.push_back({1,2,3});
	vertexVector.push_back({4,5,6});
	vertexVector.push_back({7,8,9});
	*/

	/*
	vertexVector.push_back(Vertex(1,2,3));
	vertexVector.push_back(Vertex(4,5,6));
	vertexVector.push_back(Vertex(7,8,9));
	*/
		
	vertexVector.emplace_back(1,2,3);
	vertexVector.emplace_back(4,5,6);
	vertexVector.emplace_back(7,8,9);


	std::cout << vertexVector.size() 
		<< " " << vertexVector.capacity() << std::endl;

	//vertexVector.shrink_to_fit(); // C++11
	//std::vector<Vertex>(vertexVector).swap(vertexVector); // < C++11

	std::cout << vertexVector.size() 
		<< " " << vertexVector.capacity() << std::endl;


	return 0;
}