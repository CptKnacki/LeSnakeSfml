#pragma once
#include "SFML/Graphics.hpp"
class DataBase
{
public:
	static inline sf::Font Font;
	DataBase();
	~DataBase();

private:
	void LoadFont();
};

