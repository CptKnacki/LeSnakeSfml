// SFML_BaseProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Engine/Engine.h"

int main()
{
	Engine _engine(1000, 1000, "SnakeSFML");
	_engine.RunEngine();


	return 0;
}

