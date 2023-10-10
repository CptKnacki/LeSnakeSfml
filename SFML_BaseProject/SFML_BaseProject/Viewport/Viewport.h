#pragma once
#include "SFML/Graphics.hpp"

class Viewport
{
	sf::RenderWindow* gameWindow = nullptr;


public:
	Viewport(const int& _width, const int& _height, const std::string& _title);
	~Viewport();
	void OpenWindow();
	void DrawAllObjects();
};

