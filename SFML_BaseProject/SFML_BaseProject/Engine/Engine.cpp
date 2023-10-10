#include "Engine.h"

Engine::Engine()
{
	viewport = new Viewport(1280, 720, "SnakeGame");

}

Engine::Engine(const int& _width, const int& _height, const std::string& _title)
{
	viewport = new Viewport(_width, _height, _title);
}

Engine::~Engine()
{
	delete viewport;
	viewport = nullptr;
}

void Engine::RunEngine()
{
	viewport->OpenWindow();
}

void Engine::StopEngine()
{
	// ???
}
