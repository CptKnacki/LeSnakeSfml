#pragma once
#include "../BaseMenu.h"
#include "../../Label/Label.h"
#include "../../Button/Button.h"


class GameOverMenu : public BaseMenu
{
	Button* returnMenu = nullptr;
	Button* restartButton = nullptr;
	Label* gameOverText = nullptr;
public:
	GameOverMenu();
	~GameOverMenu();

	void Update() override;

private:
	void InitReturnMenu();
	void InitRestartButton();
	void InitGameOverText();

};

