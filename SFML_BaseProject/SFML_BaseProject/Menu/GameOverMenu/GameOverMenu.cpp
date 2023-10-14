#include "GameOverMenu.h"
#include "../../Utils.h"
#include "../../BaseMenuManager/MenuManager.h"
#include <format>

GameOverMenu::GameOverMenu() : BaseMenu("Over")
{
	InitReturnMenu();
	InitRestartButton();
	InitGameOverText();
	InitScoreText();
}

GameOverMenu::~GameOverMenu()
{
	delete returnMenu, restartButton, gameOverText;
}

void GameOverMenu::Update()
{
	if (returnMenu->IsClicked())
		MenuManager::Instance()->SetState(Menu::Main);
	if (restartButton->IsClicked())
	{
		MenuManager::Instance()->SetState(Menu::Game);
		GET_VIEWPORT->GetSnakeHead()->Restart();
		GET_VIEWPORT->GetGrid()->Restart();
	}
}

void GameOverMenu::SetScore()
{
	scoreText->SetText("Score :" + std::format("{}", GET_VIEWPORT->GetSnakeHead()->GetBodyList().size()));
}

void GameOverMenu::InitReturnMenu()
{
	returnMenu = new Button(Vector2f(GET_WINDOW->getSize().x / 2, GET_WINDOW->getSize().y / 1.5), Vector2f(400, 100), "MENU", GET_WINDOW, 40);
	returnMenu->SetPosition(returnMenu->GetPosition() - Vector2f(returnMenu->GetSize().x / 2, 0));
	returnMenu->SetPosition(returnMenu->GetPosition() + Vector2f(200, 0));
	elements.push_back(returnMenu);
}

void GameOverMenu::InitRestartButton()
{
	restartButton = new Button(Vector2f(GET_WINDOW->getSize().x / 2, GET_WINDOW->getSize().y / 1.5), Vector2f(400, 100), "RESTART", GET_WINDOW, 40);
	restartButton->SetPosition(restartButton->GetPosition() - Vector2f(restartButton->GetSize().x / 2, 0));
	restartButton->SetPosition(restartButton->GetPosition() - Vector2f(200, 0));
	elements.push_back(restartButton);
}

void GameOverMenu::InitGameOverText()
{
	gameOverText = new Label(Vector2f(GET_WINDOW->getSize().x / 2, GET_WINDOW->getSize().y / 4), "GAME OVER", 80);
	gameOverText->SetPosition(Vector2f(gameOverText->GetPosition() - Vector2f(250, 0)));
	elements.push_back(gameOverText);
}

void GameOverMenu::InitScoreText()
{
	scoreText = new Label(Vector2f(GET_WINDOW->getSize().x / 2, GET_WINDOW->getSize().y / 3), "Score : ", 40);
	scoreText->SetPosition(Vector2f(scoreText->GetPosition() - Vector2f(250, 0)));
	GET_VIEWPORT->GetSnakeHead()->OnDie().Bind(this, &GameOverMenu::SetScore);
	elements.push_back(scoreText);
}
