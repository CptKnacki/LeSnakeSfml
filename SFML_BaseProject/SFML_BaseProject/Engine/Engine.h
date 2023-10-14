#pragma once
#include <string>
#include "../Viewport/Viewport.h"
#include "../DataBase/DataBase.h"
#include "../Menu/MainMenu/MainMenu.h"
#include "../Menu/GameOverMenu/GameOverMenu.h"
#include "../Menu/SettingsMenu/SettingsMenu.h"
#include "../GameModes/GameModes.h"

class Engine
{
private:
	DataBase* dataBase = nullptr;
	Viewport* viewport = nullptr;

	MainMenu* main = nullptr;
	GameOverMenu* over = nullptr;
	SettingsMenu* settings = nullptr;
	GameModes* gameModes = nullptr;

public:
	Engine();
	Engine(const int& _width, const int& _height, const std::string& _title, GameModes* _gameModes);
	~Engine();

	Viewport* GetViewport();
	void RunEngine();
	void StopEngine();
	bool IsInTeleportGameMode();
};

