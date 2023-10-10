#pragma once
#include <string>

class Engine
{
public:
	Engine();
	Engine(const int& _width, const int& _height, const std::string& _title);
	~Engine();

	void RunEngine();
	void StopEngine();
};

