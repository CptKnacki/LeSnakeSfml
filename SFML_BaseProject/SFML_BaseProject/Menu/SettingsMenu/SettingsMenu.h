#pragma once
#include "../BaseMenu.h"
#include "../../Label/Label.h"
#include "../../Case/Case.h"


class SettingsMenu : public BaseMenu
{
	Label* title = nullptr;
	RectangleShape* background = nullptr;
	Case* caseTest = nullptr;

public:
	SettingsMenu();
	~SettingsMenu();

private:
	void InitTitle();
	void InitBackground();
	void InitCaseTest();
};


