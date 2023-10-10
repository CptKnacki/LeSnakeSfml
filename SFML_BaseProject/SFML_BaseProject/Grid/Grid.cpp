#include "Grid.h"
#include "../Utils.h"
#include "../Apple/Apple.h"
#include <iostream>
#include <stdio.h>      
#include <stdlib.h>     
#include <time.h>       

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
	{
		delete nodeList[i];
	}
	nodeList.clear();
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
	srand(time(0));

	int _gridSize = nodeList.size();
	int _result = rand() % _gridSize;


	//for (size_t i = 0; i < GET_VIEWPORT->GetSnakeHead()->GetBodyList().size(); i++)
	//{
	//	while (nodeList[_result]->GetContainedObject() && nodeList[_result]->GetShape()->getPosition() == GET_VIEWPORT->GetSnakeHead()->GetBodyList()[i]->GetShape()->getPosition())
	//	{
	//		_result = rand() % _gridSize;
	//	}
	//}
	
	float _size = (nodeSizeX >= nodeSizeY) ? nodeSizeY : nodeSizeX;

	sf::Vector2f _appleSize = nodeList[_result]->GetShape()->getPosition() + sf::Vector2f(nodeSizeX / 2, nodeSizeY / 2);
	nodeList[_result]->SetContainedObject(new Apple(_appleSize, _size));
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
	{
		_window.draw(*nodeList[i]->GetShape());
	}
}

void Grid::Update()
{

	if (!HasApple())
		CreateApple();
}
