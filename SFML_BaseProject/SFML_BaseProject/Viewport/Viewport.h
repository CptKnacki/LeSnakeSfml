#pragma once
#include "SFML/Graphics.hpp"

#include "../Grid/Grid.h"

class Viewport
{
private:
	sf::RenderWindow* gameWindow = nullptr;

	Grid* newGrid = nullptr;
	
public:
	Viewport(const int& _width, const int& _height, const std::string& _title);
	~Viewport();
	sf::RenderWindow* GetWindow();
	void OpenWindow();
	void DrawAllObjects();
};

