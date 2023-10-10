#include "Engine.h"
#include "../GameEngineManager/GameEngineManager.h"

Engine::Engine()
{
	viewport = new Viewport(1280, 720, "SnakeGame");
	GameEngineManager::Instance()->Register(this);
}

Engine::Engine(const int& _width, const int& _height, const std::string& _title)
{
	viewport = new Viewport(_width, _height, _title);
	GameEngineManager::Instance()->Register(this);
}

Engine::~Engine()
{
	delete viewport;
	viewport = nullptr;
}

Viewport* Engine::GetViewport()
{
	return viewport;
}

void Engine::RunEngine()
{
	viewport->OpenWindow();
}

void Engine::StopEngine()
{
	// ???
}
