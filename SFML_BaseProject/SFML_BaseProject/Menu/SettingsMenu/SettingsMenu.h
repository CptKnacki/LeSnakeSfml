#pragma once
#include "../BaseMenu.h"
#include "../../Label/Label.h"
#include "../../Case/Case.h"
#include "../../Button/Button.h"


class SettingsMenu : public BaseMenu
{
	Label* title = nullptr;
	RectangleShape* background = nullptr;
	Case* caseTest = nullptr;
	Button* returnButton = nullptr;

public:
	SettingsMenu();
	~SettingsMenu();

private:
	void InitTitle();
	void InitBackground();
	void InitCaseTest();
	void InitReturnButton();

	void ReturnButtonClicked();
};


