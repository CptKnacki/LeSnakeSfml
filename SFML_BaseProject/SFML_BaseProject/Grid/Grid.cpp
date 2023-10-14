#include "Grid.h"
#include "../Utils.h"
#include "../Apple/Apple.h"
#include <iostream>
#include <windows.h>
#include <random>   

Grid::Grid(sf::RenderWindow* _window, const int& _nodeDivideCount)
{

	//sf::RenderWindow* _windows = GET_ENGINE;

	nodeSizeX = _window->getSize().x / _nodeDivideCount;
	nodeSizeY = _window->getSize().y / _nodeDivideCount;
	int _indexX = 0;
	int _indexY = 0;

	for (size_t i = 0; i < _nodeDivideCount * _nodeDivideCount; i++)
	{
		if (_indexX == 20)
		{
			_indexX = 0;
			_indexY++;
		}

		nodeList.push_back(new Node(sf::Vector2f(nodeSizeX, nodeSizeY), sf::Vector2f(nodeSizeX * _indexX, nodeSizeY * _indexY)));

		_indexX++;
	}

	SetGridColor();
}

Grid::~Grid()
{
	for (size_t i = 0; i < nodeList.size(); i++)
		delete nodeList[i];
	nodeList.clear();
}

void Grid::SetGameIsOn(bool _value)
{
	gameIsOn = _value;
}

float Grid::GetNodeSizeX()
{
	return nodeSizeX;
}

float Grid::GetNodeSizeY()
{
	return nodeSizeY;
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

void Grid::CreateApple()
{

	int _gridSize = nodeList.size();
	std::random_device _rd;
	std::mt19937 _gen(_rd());
	std::uniform_int_distribution<> _distrib(0, _gridSize - 1);
	int _result = _distrib(_gen);
	
	float _size = (nodeSizeX >= nodeSizeY) ? nodeSizeY : nodeSizeX;

	sf::Vector2f _appleSize = nodeList[_result]->GetShape()->getPosition() + sf::Vector2f(nodeSizeX / 2, nodeSizeY / 2);
	nodeList[_result]->SetContainedObject(new Apple(_appleSize, _size));

	if (nodeList[_result]->GetShape()->getPosition() == GET_VIEWPORT->GetSnakeHead()->GetHeadShape()->getPosition())
		nodeList[_result]->DestroyContainedObject();


}

bool Grid::HasApple()
{
	bool _hasApple = false;

	for (size_t i = 0; i < nodeList.size(); i++)
	{
		Apple* _apple = dynamic_cast<Apple*>(nodeList[i]->GetContainedObject());

		if (_apple)
			_hasApple = true;
	}

	return _hasApple;
}

void Grid::Draw(sf::RenderWindow& _window)
{
	for (size_t i = 0; i < nodeList.size(); i++)
		_window.draw(*nodeList[i]->GetShape());
	
}

void Grid::Update()
{
	if (!gameIsOn)
		return;

	if (!HasApple())
		CreateApple();
}

void Grid::Restart()
{
	gameIsOn = true;
}
