// SFML_BaseProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Engine/Engine.h"
#include "GameModes/TeleportGM/TeleportGM.h"
#include "Test.h"

int main()
{
	Engine _engine(800, 800, "SnakeSFML", new TeleportGM());
	_engine.RunEngine();

	//Test _test = Test();
	//_test.TestRandom();

	return 0;


	
}

