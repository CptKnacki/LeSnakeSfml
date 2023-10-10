#pragma once
#include "../GameObject/GameObject.h"
#include "../Node/Node.h"
#include <vector>

class Grid : public GameObject
{
private:
	std::vector<Node*> nodeList;

public:
	Grid(sf::RenderWindow* _window, const int& _nodeDivideCount = 20);
	~Grid();
	std::vector<Node*> GetNodeList();
};

