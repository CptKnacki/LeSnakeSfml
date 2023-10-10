#pragma once
#include "../BaseMenu.h"
#include "../../Button/Button.h"
#include "../../Label/Label.h"
#include "../../Image/Image.h"

class MainMenu : public BaseMenu
{
	Button* playButton = nullptr;
	Label* snakeTitle = nullptr;
	Label* creatorText = nullptr;
	UImage* logo = nullptr;
public:
	MainMenu();
	~MainMenu();

private:
	void InitPlayButton();
	void InitSnakeTitle();
	void InitCreatorText();
	void InitLogo();
};

