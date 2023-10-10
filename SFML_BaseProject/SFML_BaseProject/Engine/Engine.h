#pragma once
#include <string>
#include "../Viewport/Viewport.h"
#include "../DataBase/DataBase.h"


class Engine
{
private:
	DataBase* dataBase = nullptr;
	Viewport* viewport = nullptr;


public:
	Engine();
	Engine(const int& _width, const int& _height, const std::string& _title);
	~Engine();

	Viewport* GetViewport();
	void RunEngine();
	void StopEngine();
};

