#include "SettingsMenu.h"
#include "../../Utils.h"

SettingsMenu::SettingsMenu() : BaseMenu("Settings")
{
	InitTitle();
	InitBackground();
	InitCaseTest();
}

SettingsMenu::~SettingsMenu()
{
	delete title, background, caseTest;
}

void SettingsMenu::InitTitle()
{
	title = new Label(Vector2f(GET_WINDOW->getSize().x / 2, GET_WINDOW->getSize().y / 4), "SETTINGS", 80);
	title->SetPosition(Vector2f(title->GetPosition() - Vector2f(250, 0)));
	elements.push_back(title);
}

void SettingsMenu::InitBackground()
{
}

void SettingsMenu::InitCaseTest()
{
}
