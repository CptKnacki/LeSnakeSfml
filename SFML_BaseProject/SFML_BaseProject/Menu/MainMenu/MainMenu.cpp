#include "MainMenu.h"
#include "../../Utils.h"
#include <iostream>
#include "../../BaseMenuManager/MenuManager.h"

MainMenu::MainMenu() : BaseMenu("Main")
{
	InitPlayButton();
	InitSnakeTitle();
	InitCreatorText();
	InitLogo();
	InitCase();
	InitSettingsButton();
}

MainMenu::~MainMenu()
{
}

void MainMenu::Update()
{

}

void MainMenu::InitPlayButton()
{
	playButton = new Button(Vector2f(GET_WINDOW->getSize().x / 2, GET_WINDOW->getSize().y / 2), Vector2f(400, 100), "Play", GET_WINDOW, 40);
	playButton->SetPosition(playButton->GetPosition() - Vector2f(playButton->GetSize().x / 2, 0));
	playButton->OnClicked().Bind(this, &MainMenu::PlayButtonClicked);
	elements.push_back(playButton);
}

void MainMenu::InitSettingsButton()
{
	settingsButton = new Button(Vector2f(GET_WINDOW->getSize().x / 2, GET_WINDOW->getSize().y / 1.5), Vector2f(400, 100), "Settings", GET_WINDOW, 40);
	settingsButton->SetPosition(settingsButton->GetPosition() - Vector2f(settingsButton->GetSize().x / 2, 0));
	settingsButton->OnClicked().Bind(this, &MainMenu::SettingsButtonClicked);
	elements.push_back(settingsButton);
}

void MainMenu::InitSnakeTitle()
{
	snakeTitle = new Label(Vector2f(GET_WINDOW->getSize().x / 2, GET_WINDOW->getSize().y / 4), "SNAKE SFML", 80);
	snakeTitle->SetPosition(Vector2f(snakeTitle->GetPosition() - Vector2f( 250, 0)));
	elements.push_back(snakeTitle);
}

void MainMenu::InitCreatorText()
{
	creatorText = new Label(Vector2f(20, GET_WINDOW->getSize().y / 1.2), "By les Boss: \n TyboBGdu34\n xX_darkEMERIK87_Xx", 20);
	elements.push_back(creatorText);
}

void MainMenu::InitLogo()
{
	Texture _texture = Texture();
	if (!_texture.loadFromFile("../Texture/O3D.png"))
		return;
	logo = new UImage(Vector2f(GET_WINDOW->getSize().x - 100, GET_WINDOW->getSize().y / 1.15), _texture);
	logo->SetScale(Vector2f(0.3, 0.3));
	elements.push_back(logo);
}

void MainMenu::InitCase()
{
	caseTest = new Case(Vector2f(100, 100), 50, GET_WINDOW, true);
	elements.push_back(caseTest);
}

void MainMenu::SettingsButtonClicked()
{
	MenuManager::Instance()->SetState(Menu::Settings);
}

void MainMenu::PlayButtonClicked()
{
	MenuManager::Instance()->SetState(Menu::Game);
	GET_VIEWPORT->GetSnakeHead()->Restart();
	GET_VIEWPORT->GetGrid()->Restart();
}
