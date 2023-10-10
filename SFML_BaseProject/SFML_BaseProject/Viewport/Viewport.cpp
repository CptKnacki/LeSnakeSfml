#include "Viewport.h"
#include "../GameObjectManager/GameObjectManager.h"

Viewport::Viewport(const int& _width, const int& _height, const std::string& _title)
{
	gameWindow = new sf::RenderWindow(sf::VideoMode(_width, _height), _title);

    newGrid = new Grid(gameWindow, 20);

    snakeHead = new SnakeHead(sf::Vector2f(newGrid->GetNodeSizeX(), newGrid->GetNodeSizeY()) , newGrid->GetNodeList()[165]->GetShape()->getPosition());

   snakeHead->AddBody(new SnakeBody(sf::Vector2f(newGrid->GetNodeSizeX(), newGrid->GetNodeSizeY()) , newGrid->GetNodeList()[164]->GetShape()->getPosition()));
   snakeHead->AddBody(new SnakeBody(sf::Vector2f(newGrid->GetNodeSizeX(), newGrid->GetNodeSizeY()) , newGrid->GetNodeList()[163]->GetShape()->getPosition()));
   snakeHead->AddBody(new SnakeBody(sf::Vector2f(newGrid->GetNodeSizeX(), newGrid->GetNodeSizeY()) , newGrid->GetNodeList()[162]->GetShape()->getPosition()));
   snakeHead->AddBody(new SnakeBody(sf::Vector2f(newGrid->GetNodeSizeX(), newGrid->GetNodeSizeY()) , newGrid->GetNodeList()[161]->GetShape()->getPosition()));
   snakeHead->AddBody(new SnakeBody(sf::Vector2f(newGrid->GetNodeSizeX(), newGrid->GetNodeSizeY()) , newGrid->GetNodeList()[160]->GetShape()->getPosition()));

   updateClock.restart();
}

Viewport::~Viewport()
{
    delete gameWindow;
    gameWindow = nullptr;

    delete newGrid;
    newGrid = nullptr;

    delete snakeHead;
    snakeHead = nullptr;

    delete snakeBody;
    snakeBody = nullptr;
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
        gameWindow->display();
    }
}

void Viewport::DrawAllObjects()
{
    GameObjectManager::Instance()->Draw(*gameWindow);
}

void Viewport::DetermineUpdate()
{
    if (updateClock.getElapsedTime().asSeconds() > 0.2)
    {
        GameObjectManager::Instance()->Update();
        updateClock.restart();
    }

}
