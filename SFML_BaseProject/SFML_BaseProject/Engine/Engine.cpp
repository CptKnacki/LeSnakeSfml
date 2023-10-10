#include "Engine.h"
#include "../GameEngineManager/GameEngineManager.h"
#include "../BaseMenuManager/MenuManager.h"

Engine::Engine()
{
	dataBase = new DataBase();
	viewport = new Viewport(1280, 720, "SnakeGame");
	GameEngineManager::Instance()->Register(this);
	main = new MainMenu();
	over = new GameOverMenu();
}

Engine::Engine(const int& _width, const int& _height, const std::string& _title)
{
	dataBase = new DataBase();
	viewport = new Viewport(_width, _height, _title);
	GameEngineManager::Instance()->Register(this);
	main = new MainMenu();
	over = new GameOverMenu();
}

Engine::~Engine()
{
	delete viewport;
	viewport = nullptr;
	delete dataBase;
	dataBase = nullptr;
	delete main;
	main = nullptr;
}

Viewport* Engine::GetViewport()
{
	return viewport;
}

void Engine::RunEngine()
{
	MenuManager::Instance()->SetState(Menu::Main);
	viewport->OpenWindow();
}

void Engine::StopEngine()
{
	// ???
}
