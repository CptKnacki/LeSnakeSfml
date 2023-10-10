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

	SetGridColor();
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

void Grid::SetGridColor()
{

	bool isSecondLine = false;
	int _index = 0;

	for (size_t i = 0; i < nodeList.size(); i++)
	{
		if (_index == 20)
		{
			_index = 0;
			isSecondLine = !isSecondLine;
		}

		if (isSecondLine)
		{
			if(i % 2 == 0)
				nodeList[i]->SetFillColor(sf::Color(45, 210, 0));
			else
				nodeList[i]->SetFillColor(sf::Color(30, 160, 0));
		}
		else
		{
			if (i % 2 == 0)
				nodeList[i]->SetFillColor(sf::Color(30, 160, 0));
			else
				nodeList[i]->SetFillColor(sf::Color(45, 210, 0));
		}


		_index++;
	}
}

void Grid::Draw(sf::RenderWindow& _window)
{
	for (size_t i = 0; i < nodeList.size(); i++)
	{
		_window.draw(*nodeList[i]->GetShape());
	}
}

void Grid::Update()
{
}
