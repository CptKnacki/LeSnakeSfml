#pragma once
#include "../BaseMenu.h"
#include "../../Label/Label.h"
#include "../../Button/Button.h"


class GameOverMenu : public BaseMenu
{
	Button* returnMenu = nullptr;
	Button* restartButton = nullptr;
	Label* gameOverText = nullptr;
	Label* scoreText = nullptr;
public:
	GameOverMenu();
	~GameOverMenu();

	void Update() override;

	void SetScore();
private:
	void InitReturnMenu();
	void InitRestartButton();
	void InitGameOverText();
	void InitScoreText();



};

