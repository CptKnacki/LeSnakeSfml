#include "Viewport.h"
#include "../GameObjectManager/GameObjectManager.h"
#include "../BaseMenuManager/MenuManager.h"

Viewport::Viewport(const int& _width, const int& _height, const std::string& _title)
{
	gameWindow = new sf::RenderWindow(sf::VideoMode(_width, _height), _title);

    grid = new Grid(gameWindow, 20);

   snakeHead = new SnakeHead(sf::Vector2f(grid->GetNodeSizeX(), grid->GetNodeSizeY()) , grid->GetNodeList()[165]->GetShape()->getPosition());
   snakeHead->Kill();
   grid->SetGameIsOn(false);

   updateClock.restart();
}

Viewport::~Viewport()
{
    delete gameWindow;
    gameWindow = nullptr;

    delete grid;
    grid = nullptr;

    delete snakeHead;
    snakeHead = nullptr;
}

Grid* Viewport::GetGrid()
{
    return grid;
}

SnakeHead* Viewport::GetSnakeHead()
{
    return snakeHead;
}

sf::RenderWindow* Viewport::GetWindow()
{
    return gameWindow;
}

void Viewport::OpenWindow()
{
    while (gameWindow->isOpen())
    {
        sf::Event event;
        while (gameWindow->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                gameWindow->close();
        }

        gameWindow->clear();
        DrawAllObjects();
        DetermineUpdate();
        MenuManager::Instance()->Update();
        gameWindow->display();
    }
}

void Viewport::DrawAllObjects()
{
    GameObjectManager::Instance()->Draw(*gameWindow);
}

void Viewport::DetermineUpdate()
{
   
    DetermineAppleCollision();

    if (updateClock.getElapsedTime().asSeconds() > 0.1)
    {

        GameObjectManager::Instance()->Update();
        updateClock.restart();
    }

}

void Viewport::DetermineAppleCollision()
{
    for (size_t i = 0; i < grid->GetNodeList().size(); i++)
    {
        if (grid->GetNodeList()[i]->GetContainedObject() && grid->GetNodeList()[i]->GetShape()->getPosition() == snakeHead->GetHeadShape()->getPosition())
        {
            grid->GetNodeList()[i]->DestroyContainedObject();
            snakeHead->AddBody();
        }
    }
}
