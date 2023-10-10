#pragma once
#include "SFML/Graphics.hpp"

#include "../Grid/Grid.h"
#include "../Snake/SnakeHead/SnakeHead.h"
#include "../Snake/SnakeBody/SnakeBody.h"

class Viewport
{
private:
	sf::RenderWindow* gameWindow = nullptr;
	Grid* grid = nullptr;
	SnakeHead* snakeHead = nullptr;
	sf::Clock updateClock;


public:
	Viewport(const int& _width, const int& _height, const std::string& _title);
	~Viewport();

	Grid* GetGrid();
	SnakeHead* GetSnakeHead();

	sf::RenderWindow* GetWindow();
	void OpenWindow();
	void DrawAllObjects();
	void DetermineUpdate();
	void DetermineAppleCollision();
};

