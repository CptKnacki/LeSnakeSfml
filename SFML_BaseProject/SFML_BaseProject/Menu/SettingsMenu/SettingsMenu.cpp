#include "SettingsMenu.h"
#include "../../Utils.h"
#include "../../BaseMenuManager/MenuManager.h"

SettingsMenu::SettingsMenu() : BaseMenu("Settings")
{
	InitBackground();
	InitTitle();
	InitCaseTest();
	InitReturnButton();
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
	background = new RectangleShape(Vector2f(GET_WINDOW->getSize().x, GET_WINDOW->getSize().y));
}

void SettingsMenu::InitCaseTest()
{
}

void SettingsMenu::InitReturnButton()
{
	returnButton = new Button(Vector2f(10, 10), Vector2f(120, 40), "Return", GET_WINDOW, 20);
	returnButton->OnClicked().Bind(this, &SettingsMenu::ReturnButtonClicked);
	elements.push_back(returnButton);
}

void SettingsMenu::ReturnButtonClicked()
{
	MenuManager::Instance()->SetState(Menu::Main);
}
