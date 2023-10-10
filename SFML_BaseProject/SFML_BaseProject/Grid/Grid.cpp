#include "Grid.h"
#include "../Utils.h"


Grid::Grid(sf::RenderWindow* _window, const int& _nodeDivideCount)
{

	//sf::RenderWindow* _windows = GET_ENGINE;

	float _nodeSizeX = _window->getSize().x / _nodeDivideCount;
	float _nodeSizeY = _window->getSize().y / _nodeDivideCount;
	int _indexX = 0;
	int _indexY = 0;

	for (size_t i = 0; i < _nodeDivideCount * _nodeDivideCount; i++)
	{
		if (_indexX == 20)
		{
			_indexX = 0;
			_indexY++;
		}

		nodeList.push_back(new Node(sf::Vector2f(_nodeSizeX, _nodeSizeY), sf::Vector2f(_nodeSizeX * _indexX, _nodeSizeY * _indexY)));

		_indexX++;
	}
}

Grid::~Grid()
{
	for (size_t i = 0; i < nodeList.size(); i++)
	{
		delete nodeList[i];
	}
	nodeList.clear();
}

std::vector<Node*> Grid::GetNodeList()
{
	return nodeList;
}
