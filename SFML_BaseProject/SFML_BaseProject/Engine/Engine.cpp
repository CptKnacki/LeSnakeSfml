#include "Engine.h"
#include "../GameEngineManager/GameEngineManager.h"
#include "../BaseMenuManager/MenuManager.h"
#include "../GameModes/TeleportGM/TeleportGM.h"

Engine::Engine()
{
	dataBase = new DataBase();
	viewport = new Viewport(1280, 720, "SnakeGame");
	GameEngineManager::Instance()->Register(this);
	main = new MainMenu();
	over = new GameOverMenu();
	settings = new SettingsMenu();
}

Engine::Engine(const int& _width, const int& _height, const std::string& _title, GameModes* _gameModes)
{
	gameModes = _gameModes;
	dataBase = new DataBase();
	viewport = new Viewport(_width, _height, _title);
	GameEngineManager::Instance()->Register(this);
	main = new MainMenu();
	over = new GameOverMenu();
	settings = new SettingsMenu();
}

Engine::~Engine()
{
	delete viewport;
	viewport = nullptr;
	delete dataBase;
	dataBase = nullptr;
	delete main, over, settings;
	main = nullptr;
	over = nullptr;
	settings = nullptr;
	delete gameModes;
	gameModes = nullptr;
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

bool Engine::IsInTeleportGameMode()
{
	if (!gameModes)
		return false;

	TeleportGM* _gm = reinterpret_cast<TeleportGM*>(gameModes);

	if (_gm)
		return true;
	return false;
}
