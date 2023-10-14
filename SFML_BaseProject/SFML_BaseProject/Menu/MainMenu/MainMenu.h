#pragma once
#include "../BaseMenu.h"
#include "../../Button/Button.h"
#include "../../Label/Label.h"
#include "../../Image/Image.h"
#include "../../Case/Case.h"

class MainMenu : public BaseMenu
{
	Button* playButton = nullptr;
	Button* settingsButton = nullptr;
	Label* snakeTitle = nullptr;
	Label* creatorText = nullptr;
	UImage* logo = nullptr;
	Case* caseTest = nullptr;

public:
	MainMenu();
	~MainMenu();

	void Update() override;

private:
	void InitPlayButton();
	void InitSettingsButton();
	void InitSnakeTitle();
	void InitCreatorText();
	void InitLogo();
	void InitCase();
};

